#include "FileRecorder.h"

CFileRecorder::CFileRecorder(PCHAR rtspStream, int connectionTimeout, PCHAR outputFilename, FErrorCallback fErrorCallback)
	:CBaseRecorder(fErrorCallback)
{
	m_rtspPath = rtspStream;
	m_outputFilename = outputFilename;
}

CFileRecorder::~CFileRecorder()
{
}

BOOL CFileRecorder::Open(){
	if (m_outputFilename == ""){
		if (m_ErrCb)
			std::thread([this]{m_ErrCb(ErrorCode::EmptyFilename); }).detach();
		return FALSE;
	}
	if (!OpenInputStream((PCHAR)m_rtspPath.c_str(), m_timeout)){
		if (m_ErrCb)
			std::thread([this]{m_ErrCb(m_errorCode); }).detach();
		return FALSE;
	}
	return TRUE;
}

BOOL CFileRecorder::WriteHeaderTo(AVFormatContext *&dstFmtCtx){
	auto outputFmt = av_guess_format(nullptr, m_outputFilename.c_str(), nullptr);
	if (outputFmt == nullptr){
		m_errorCode = ErrorCode::OutputFormatNotMatchFormat;
		return FALSE;
	}
	//Alloc OutputFormatContext
	dstFmtCtx = avformat_alloc_context();
	dstFmtCtx->oformat = outputFmt;
	//Copy outputfilename to outputCtx
	strcpy_s(dstFmtCtx->filename, sizeof(dstFmtCtx->filename), m_outputFilename.c_str());

	if (dstFmtCtx->oformat->flags & AVFMT_GLOBALHEADER)
	{
		dstFmtCtx->flags |= CODEC_FLAG_GLOBAL_HEADER;
	}

	FillOutputStreamIndex(dstFmtCtx);

	//Open outputfile, if return "<0" exit
	if (avio_open(&dstFmtCtx->pb, m_outputFilename.c_str(), AVIO_FLAG_WRITE) < 0){
		m_errorCode = ErrorCode::OpenOutputFileError;
		return FALSE;
	}
	avformat_write_header(dstFmtCtx, nullptr);
	return TRUE;
}
