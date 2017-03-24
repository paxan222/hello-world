#include "CallbackRecorder.h"

/*public*/
CCallbackRecorder::CCallbackRecorder(PCHAR rtspPath, int connectionTimeout,
	FFRecieveDataCallback fReceiveDataCallback, FFRecieveHeaderCallback fReceiveHeaderCallback, FErrorCallback fErrorCallback)
	:CBaseRecorder(fErrorCallback),
	m_RcvDtCb(fReceiveDataCallback),
	m_RcvHdCb(fReceiveHeaderCallback)
{
	m_rtspPath = rtspPath;
	m_timeout = connectionTimeout;
}

CCallbackRecorder::~CCallbackRecorder()
{
	delete[] m_buffer;
	m_buffer = new BYTE[BUFFER_SIZE];
	if (m_outputVideoStream)
		avcodec_close(m_outputVideoStream->codec);
	if (m_outputAudioStream)
		avcodec_close(m_outputAudioStream->codec);
	if (m_outputFmtCtx != nullptr)
		avformat_free_context(m_outputFmtCtx);
	if (m_outputFormat)
	{
		av_free(m_outputFormat);
	}
	if (m_receivedCtx){
		av_freep(&m_receivedCtx->buffer);
		av_free(m_receivedCtx);
	}
}

BOOL CCallbackRecorder::Open(){
	av_log_set_level(AV_LOG_DEBUG);
	if (m_RcvDtCb == nullptr)
	{
		if (m_ErrCb)
			std::thread([this]{m_ErrCb(ErrorCode::RecievedCallbackIsNull); }).detach();
		return FALSE;
	}
	if (!OpenInputStream((PCHAR)m_rtspPath.c_str(), m_timeout)){
		if (m_ErrCb)
			std::thread([this]{m_ErrCb(m_errorCode); }).detach();
		return FALSE;
	}
	//Guess output format
	m_outputFormat = av_guess_format("matroska", nullptr, nullptr);
	if (!m_outputFormat){
		m_errorCode = ErrorCode::OutputFormatNotMatchFormat;
		return FALSE;
	}
	//Alloc AVIO format context for callback
	m_receivedCtx = avio_alloc_context(m_buffer, BUFFER_SIZE, 1, this, nullptr, SendDataCallback, nullptr);
	if (!m_receivedCtx){
		m_errorCode = ErrorCode::AllocCallbackError;
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
		auto receivedCtx = avio_alloc_context(buf, BUFFER_SIZE, 1, this, nullptr, SendHeaderCallback, nullptr);
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
	if (dstFmtCtx != nullptr){
		if (m_outputVideoStream)
			avcodec_close(m_outputVideoStream->codec);
		if (m_outputAudioStream)
			avcodec_close(m_outputAudioStream->codec);
		av_write_trailer(dstFmtCtx);
		avformat_free_context(dstFmtCtx);
		dstFmtCtx = nullptr;
	}
	dstFmtCtx = avformat_alloc_context();
	dstFmtCtx->oformat = m_outputFormat;
	dstFmtCtx->pb = m_receivedCtx;
	//Set up flags
	dstFmtCtx->flags = AVFMT_FLAG_CUSTOM_IO;

	if (dstFmtCtx->oformat->flags & AVFMT_GLOBALHEADER)
	{
		dstFmtCtx->flags |= CODEC_FLAG_GLOBAL_HEADER;
	}

	FillOutputStreamIndex(dstFmtCtx);

	//Set up flag to true, to send to callback that it is new file	
	m_isHeaderData = true;
	auto ret = avformat_write_header(dstFmtCtx, nullptr);
	if (ret < 0){
		char err_buf[255];
		av_strerror(ret, err_buf, sizeof(err_buf));
		std::thread([=]{m_ErrCb(ErrorCode::UnknownError); }).detach();
		return FALSE;
	}
	m_isHeaderData = false;

	return TRUE;
}
clock_t start = clock();

int CCallbackRecorder::SendDataCallback(void* opaque, uint8_t *buf, int buf_size){
	CCallbackRecorder* recorder = reinterpret_cast<CCallbackRecorder*>(opaque);
	auto buffer = new BYTE[buf_size];
	memcpy(buffer, buf, buf_size);
	recorder->m_RcvDtCb(buffer, buf_size, recorder->m_isHeaderData);
	delete[] buffer;
	return buf_size;
}

int CCallbackRecorder::SendHeaderCallback(void* opaque, uint8_t *buf, int buf_size){
	CCallbackRecorder* recorder = static_cast<CCallbackRecorder*>(opaque);
	recorder->m_RcvHdCb(buf, buf_size);
	return 0;
}
