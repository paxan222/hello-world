#include "stdafx.h"
#include "DecoderBase.h"



CDecoderBase::CDecoderBase(FDecodeCallback decodeCallback,FEndInitCallback endInitCallback)
{
	m_decodeCallback = decodeCallback;
	m_endInitCallback = endInitCallback;

}

HRESULT CDecoderBase :: SetDecodedFrameSize(DWORD outWidth,DWORD outHeight) 
{
	m_dwDecodedWidth = outWidth;
	m_dwDecodedHeight = outHeight;
	return S_OK;
}


CDecoderBase::~CDecoderBase(void)
{
}
