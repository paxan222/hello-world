#include "stdafx.h"
#include "BaseOperation.h"
/*-----------------Public----------------------------------------*/
//Constructor
CBaseOperation::CBaseOperation()
{

}

//Destructor
CBaseOperation::~CBaseOperation()
{
	avformat_close_input(&m_inputFmtCtx);
}

/*
* Return media file duration or return NULL if couldn't open file
*/
int CBaseOperation::GetFileDuration(PCHAR filename){
	av_register_all();
	AVFormatContext *fmtCtx = avformat_alloc_context();
	if (avformat_open_input(&fmtCtx, filename, nullptr, nullptr) != 0){
		return NULL;
	}
	auto duration = fmtCtx->duration * CONVERT_TIME_TO_MS / AV_TIME_BASE;
	avformat_close_input(&fmtCtx);
	return duration;
}

//Cancel task
BOOL CBaseOperation::CancelTask(){
	return m_cancel = true;
}

/*-----------------Protected-------------------------------------*/

//Open input file
BOOL CBaseOperation::OpenInputFile(AVFormatContext *&fmtCtx, PCHAR filename){
	fmtCtx = avformat_alloc_context();
	if (avformat_open_input(&fmtCtx, filename, nullptr, nullptr) != 0){
		//m_errorCode = ErrorCode::OpenInputFileError;
		return FALSE;
	}
	//Find stream info
	avformat_find_stream_info(fmtCtx, nullptr);
	return TRUE;
}

//Guess output format
BOOL CBaseOperation::GuessOutputFormat(AVFormatContext *outputFmtCtx, PCHAR outputFilename){
	/*
	*Return the output format in the list of registered output formats
	*which best matches the provided parameters, or return NULL if
	* there is no match.
	*/
	AVOutputFormat *outputFmt{ nullptr };
	if ((outputFmt = av_guess_format(nullptr, outputFilename, nullptr)) == nullptr) {
		//m_errorCode = ErrorCode::OutputFormatNotMatchFormat;
		return FALSE;
	}
	//Alloc OutputFormatContext
	m_outputFmtCtx = avformat_alloc_context();
	m_outputFmtCtx->oformat = outputFmt;
	//Copy outputfilename to outputCtx
	strcpy_s(m_outputFmtCtx->filename, sizeof(m_outputFmtCtx->filename), outputFilename);

	if (m_outputFmtCtx->oformat->flags & AVFMT_GLOBALHEADER)
	{
		m_outputFmtCtx->flags |= CODEC_FLAG_GLOBAL_HEADER;
	}
	return TRUE;
}

BOOL CBaseOperation::OpenOutputFile(PCHAR outputFilename)
{
	if (!GuessOutputFormat(m_outputFmtCtx, outputFilename))
		return FALSE;

	CreateOutputStreams(m_outputFmtCtx);

	//Open outputfile, if return "<0" exit
	if (avio_open(&m_outputFmtCtx->pb, outputFilename, AVIO_FLAG_WRITE) < 0){
		//m_errorCode = ErrorCode::OpenOutputFileError;
		return FALSE;
	}
	//Write header of output file
	avformat_write_header(m_outputFmtCtx, nullptr);

	return TRUE;
}

//CreateOutputStream
int CBaseOperation::CreateStream(AVCodecID codecId, AVStream *inputStream){
	auto tmpCodec = avcodec_find_encoder(codecId);
	auto outputStream = avformat_new_stream(m_outputFmtCtx, tmpCodec);
	avcodec_copy_context(outputStream->codec, inputStream->codec);
	return outputStream->index;
}

//Recalculate timestamps of the packet using timebase of input and output streams and offset if it necessary
void CBaseOperation::RecalculateTimeStamps(AVPacket *packet, AVRational inputTimeBase, AVRational outputTimeBase, int offset){
	packet->pts = av_rescale_q(packet->pts, inputTimeBase, outputTimeBase) + offset;
	packet->dts = packet->pts;
	packet->duration = av_rescale_q(packet->duration, inputTimeBase, outputTimeBase);
}