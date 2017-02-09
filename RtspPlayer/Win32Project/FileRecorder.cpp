#include "stdafx.h"
#include "FileRecorder.h"

CFileRecorder::CFileRecorder(PCHAR rtspStream, int connectionTimeout, PCHAR outputFilename/*, FErrorCallback fErrorCallback, FStartRecordCallback fStartCallback*/)
	:CBaseRecorder(/*fErrorCallback, fStartCallback*/)
{
	m_outputFilename = outputFilename;
}

CFileRecorder::~CFileRecorder()
{
}

BOOL CFileRecorder::Open(int counter){
	if (m_outputFilename == ""){
		return FALSE;
	}
	if (!OpenInputStream((PCHAR)m_rtspPath.c_str(), m_connectionTimeout, counter)){
		return FALSE;
	}
	return TRUE;
}
BOOL CFileRecorder::WriteHeaderTo(AVFormatContext *&dstFmtCtx){
	auto outputFmt = av_guess_format(nullptr, m_outputFilename.c_str(), nullptr);
	if (outputFmt == nullptr){
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
		return FALSE;
	}
	avformat_write_header(dstFmtCtx, nullptr);
	return TRUE;
}

void CFileRecorder::WriteTrailer(AVFormatContext *&outputFmtCtx){
	av_write_trailer(outputFmtCtx);
	avio_close(outputFmtCtx->pb);
}
