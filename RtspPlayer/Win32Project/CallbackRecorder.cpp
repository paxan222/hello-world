#include "stdafx.h"
#include "CallbackRecorder.h"


CCallbackRecorder::CCallbackRecorder(PCHAR rtspPath, int connectionTimeout, PCHAR outputFile/*,
	FFRecieveDataCallback fReceiveDataCallback, FErrorCallback fErrorCallback, FStartRecordCallback fStartCallback*/)
	:CBaseRecorder(/*fErrorCallback, fStartCallback*/)/*,
	m_RcvDtCb(fReceiveDataCallback)*/
{
	m_rtspPath = rtspPath;
	m_connectionTimeout = connectionTimeout;
	m_outputFilename = outputFile;
}

CCallbackRecorder::~CCallbackRecorder()
{
}
BOOL CCallbackRecorder::Open(int counter){
	if (!OpenInputStream((PCHAR)m_rtspPath.c_str(), m_connectionTimeout, counter))
		return FALSE;
	return TRUE;
}

BOOL CCallbackRecorder::WriteHeader(){
	return m_writeHeader = true;
}

int CCallbackRecorder::ReceiveHeaderCallback(void *opaque, uint8_t *buf, int buf_size){
	_RPT1(0, "BuffSize\:%i\n", buf_size);
	return 0;
}
void CCallbackRecorder::SendHeader(){
	auto buf = new BYTE[BUFFER_SIZE];

	//Guess output format
	auto outputFmt = av_guess_format("matroska", nullptr, nullptr);
	
	AVFormatContext *dstFmtCtx = avformat_alloc_context();
	dstFmtCtx->oformat = outputFmt;
	//Alloc AVIO format context for callback
	auto receivedCtx = avio_alloc_context(buf, BUFFER_SIZE, 1, this, nullptr, ReceiveHeaderCallback, nullptr);
	if (!receivedCtx){
	}
	dstFmtCtx->pb = receivedCtx;
	//Set up flags
	dstFmtCtx->flags = AVFMT_FLAG_CUSTOM_IO;

	if (dstFmtCtx->oformat->flags & AVFMT_GLOBALHEADER)
	{
		dstFmtCtx->flags |= CODEC_FLAG_GLOBAL_HEADER;
	}

	FillOutputStreamIndex(dstFmtCtx);

	avformat_write_header(dstFmtCtx, nullptr);
	av_free(receivedCtx);
	av_free(dstFmtCtx);
	/*AVPacket packet;
	av_init_packet(&packet);
	av_read_frame(m_inputFmtCtx,&packet);
	av_write_frame(dstFmtCtx,&packet);
	av_free_packet(&packet);	*/
}

std::mutex mutex2;

void CCallbackRecorder::writeFile2(uint8_t *buf, int buf_size, bool isHeaderData, std::string m_outputFilename){	
	
	if (isHeaderData){
		//_RPT1(0, "BuffSize\:%i\n", buf_size);

		if (outputFile2 != nullptr)
			fclose(outputFile2);
		_RPT0(0, "NewFile\n");
		auto filename = "D:\\TestVideo\\Record\\"+m_outputFilename + std::to_string(count2) + ".mkv";
		outputFile2 = fopen(filename.c_str(), "wb");
		count2++;
	}
	fwrite(buf, 1, buf_size, outputFile2);
	//_RPT1(0, "BufSize:%i\n", buf_size);
}

BOOL CCallbackRecorder::WriteHeaderTo(AVFormatContext *&dstFmtCtx){
	delete[] m_buffer;
	m_buffer = new BYTE[BUFFER_SIZE];

	//Guess output format
	auto outputFmt = av_guess_format("matroska", nullptr, nullptr);
	if (!outputFmt){
		return FALSE;
	}
	dstFmtCtx = avformat_alloc_context();
	dstFmtCtx->oformat = outputFmt;
	//Alloc AVIO format context for callback
	auto receivedCtx = avio_alloc_context(m_buffer, BUFFER_SIZE, 1, this, nullptr, ReceiveDataCallback, nullptr);
	if (!receivedCtx){
		return FALSE;
	}
	dstFmtCtx->pb = receivedCtx;
	//Set up flags
	dstFmtCtx->flags = AVFMT_FLAG_CUSTOM_IO;

	if (dstFmtCtx->oformat->flags & AVFMT_GLOBALHEADER)
	{
		dstFmtCtx->flags |= CODEC_FLAG_GLOBAL_HEADER;
	}

	FillOutputStreamIndex(dstFmtCtx);

	//Set up flag to true, to send to callback that it is new file
	m_isHeaderData = true;
	avformat_write_header(dstFmtCtx, nullptr);
	m_isHeaderData = false;

	return TRUE;
}

int CCallbackRecorder::ReceiveDataCallback(void* opaque, uint8_t *buf, int buf_size){
	CCallbackRecorder* recorder = static_cast<CCallbackRecorder*>(opaque);
	recorder->writeFile2(buf, buf_size, recorder->m_isHeaderData, recorder->m_outputFilename);
	//recorder->m_RcvDtCb(buf, buf_size, recorder->m_isHeaderData);
	return 0;
}

void CCallbackRecorder::WriteTrailer(AVFormatContext *&outputFmtCtx){
	av_write_trailer(m_outputFmtCtx);
}
