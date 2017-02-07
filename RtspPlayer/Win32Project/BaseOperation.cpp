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

//Return mediaFileDuration
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
BOOL CBaseOperation::OpenInputFile(AVFormatContext **fmtCtx, PCHAR filename){
	*fmtCtx = avformat_alloc_context();
	if (avformat_open_input(&*fmtCtx, filename, nullptr, nullptr) != 0){
		//if (m_fErrCb){
		//	std::thread([this]{
		//		ERROR_INFO ei;
		//		ei.errorCode = ErrorCode::EC_OPENINPUT;
		//		ei.message = ErrorMessage(ei.errorCode);
		//		m_fErrCb(ei); }).detach();
		//}
		return FALSE;
	}
	//Find stream info
	avformat_find_stream_info(*fmtCtx, nullptr);
	return TRUE;
}

//Open output file
BOOL CBaseOperation::OpenOutputFile(PCHAR outputFilename){
	// Write to file
	//Guess outputformat
	AVOutputFormat *outputFmt{ nullptr };
	if ((outputFmt = av_guess_format(nullptr, outputFilename, nullptr)) == nullptr) {
		//if (m_fErrCb){
		//	std::thread([this]{
		//		ERROR_INFO ei;
		//		ei.errorCode = ErrorCode::EC_GUESSOUTPUTFORMAT;
		//		ei.message = ErrorMessage(ei.errorCode);
		//		m_fErrCb(ei);
		//	}).detach();
		//}
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
	//Create output streams
	CreateOutputStream();

	//Open outputfile, if return "<0" exit
	if (avio_open(&m_outputFmtCtx->pb, outputFilename, AVIO_FLAG_WRITE) < 0){
		//if (m_fErrCb){
		//	std::thread([this]{
		//		ERROR_INFO ei;
		//		ei.errorCode = ErrorCode::EC_OPENOUTPUT;
		//		ei.message = ErrorMessage(ei.errorCode);
		//		m_fErrCb(ei); }).detach();
		//}
		return FALSE;
	}
	//Write header of output file
	avformat_write_header(m_outputFmtCtx, nullptr);

	return TRUE;
}

//Create output streams
void CBaseOperation::CreateOutputStream(){
	auto codec = avcodec_find_encoder(m_outputFmtCtx->oformat->video_codec);
	auto outVideoStream = avformat_new_stream(m_outputFmtCtx, codec);
	avcodec_copy_context(outVideoStream->codec, m_inputVideoStream->codec);
	m_outputVideoStreamIndex = outVideoStream->index;
	//Create Audio stream if we have input audio stream
	if (m_inputAudioStream != nullptr){
		codec = avcodec_find_encoder(m_outputFmtCtx->oformat->audio_codec);
		auto outAudioStream = avformat_new_stream(m_outputFmtCtx, codec);
		avcodec_copy_context(outAudioStream->codec, m_inputAudioStream->codec);
		m_outputAudioStreamIndex = outAudioStream->index;
	}
}

//Recalculate timestamps of the packet using timebase of input and output streams and offset if it necessary
void CBaseOperation::RecalculateTimeStamps(AVPacket *packet, AVRational inputTimeBase, AVRational outputTimeBase, int offset){
	packet->pts = av_rescale_q(packet->pts, inputTimeBase, outputTimeBase) + offset;
	packet->dts = packet->pts;
	packet->duration = av_rescale_q(packet->duration, inputTimeBase, outputTimeBase);
}