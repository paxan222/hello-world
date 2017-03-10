#include "CallbackRecorder.h"

/*public*/
CCallbackRecorder::CCallbackRecorder(PCHAR rtspPath, int connectionTimeout,
	FFRecieveDataCallback fReceiveDataCallback, FFRecieveHeaderCallback fReceiveHeaderCallback, FErrorCallback fErrorCallback)
	:CBaseRecorder(fErrorCallback),
	m_RcvDtCb(fReceiveDataCallback),
	m_RcvHdCb(fReceiveHeaderCallback)
{
	m_rtspPath = rtspPath;
	m_connectionTimeout = connectionTimeout;
}

CCallbackRecorder::~CCallbackRecorder()
{
}

BOOL CCallbackRecorder::Open(){
	if (m_RcvDtCb == nullptr)
	{
		if (m_ErrCb)
			std::thread([this]{m_ErrCb(ErrorCode::RecievedCallbackIsNull); }).detach();
		return FALSE;
	}
	if (!OpenInputStream((PCHAR)m_rtspPath.c_str(), m_connectionTimeout)){
		if (m_ErrCb)
			std::thread([this]{m_ErrCb(m_errorCode); }).detach();
		return FALSE;
	}
	return TRUE;
}

BOOL CCallbackRecorder::WriteHeader(){
	return m_writeHeader = true;
}

BOOL CCallbackRecorder::SendHeader(){
	if (m_RcvHdCb){
		auto buf = new BYTE[BUFFER_SIZE];

		//Guess output format
		auto outputFmt = av_guess_format("matroska", nullptr, nullptr);

		AVFormatContext *dstFmtCtx = avformat_alloc_context();
		dstFmtCtx->oformat = outputFmt;
		//Alloc AVIO format context for callback
		auto receivedCtx = avio_alloc_context(buf, BUFFER_SIZE, 1, this, nullptr, ReceiveHeaderCallback, nullptr);
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

		avformat_write_header(dstFmtCtx, nullptr);
		av_free(receivedCtx);
		av_free(dstFmtCtx);
		delete[] buf;
	}
	else{
		if (m_ErrCb)
			std::thread([this]{m_ErrCb(ErrorCode::RecievedCallbackIsNull); }).detach();
		return FALSE;
	}
	return TRUE;
}

/*private*/

BOOL CCallbackRecorder::WriteHeaderTo(AVFormatContext *&dstFmtCtx){
	delete[] m_buffer;
	m_buffer = new BYTE[BUFFER_SIZE];

	//Guess output format
	auto outputFmt = av_guess_format("matroska", nullptr, nullptr);
	if (!outputFmt){
		m_errorCode = ErrorCode::OutputFormatNotMatchFormat;
		return FALSE;
	}
	dstFmtCtx = avformat_alloc_context();
	dstFmtCtx->oformat = outputFmt;
	//Alloc AVIO format context for callback
	auto receivedCtx = avio_alloc_context(m_buffer, BUFFER_SIZE, 1, this, nullptr, ReceiveDataCallback, nullptr);
	if (!receivedCtx){
		m_errorCode = ErrorCode::AllocCallbackError;
		return FALSE;
	}
	receivedCtx->seekable = 0;
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
	recorder->m_RcvDtCb(buf, buf_size, recorder->m_isHeaderData);
	return 0;
}

int CCallbackRecorder::ReceiveHeaderCallback(void* opaque, uint8_t *buf, int buf_size){
	CCallbackRecorder* recorder = static_cast<CCallbackRecorder*>(opaque);
	recorder->m_RcvHdCb(buf, buf_size);
	return 0;
}
