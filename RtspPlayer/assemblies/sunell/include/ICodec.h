#ifndef _ICODEC_H_
#define _ICODEC_H_

class ICodec
{
public:
	ICodec(void){};
	virtual ~ICodec(void){};
public:
	/************************************************************************
	**概述：
	*		编码WAVE_PCM格式音频数据为设定的码流。
	**输入：
	*		p_pszIn：  Wave格式的数据，其数据格式必须为：
	*				SamplesPerSec = 8000;			//采样率
	*				BitPerSample = 16;				//音频分辨率
	*				FormatTag = WAVE_FORMAT_PCM;	//音频采样格式
	*				Channels = 1;					//音频通道数
	*		p_nInLen：	被编码的Wave格式的数据长度
	*		p_nOutLen：	p_szOut缓冲的长度
	**输出：
	*		p_szOut：	用户用于存放编码后数据的缓冲
	*		p_nOutLen：	编码后的长度
	**返回值：
	*		执行成功返回true， false 错误
	**功能：
	*		注当错误时，用户应该丢弃该编码数据。
	************************************************************************/
	virtual	bool encode(const char * p_pszIn, const int p_nInLen, char * p_szOut, int & p_nOutLen ) = 0;
	
	/************************************************************************
	**概述：
	*		解码流数据为WAVE_PCM格式音频数据。
	**输入：
	*	p_pszIn：等待解码数据缓冲
	*	p_nInLen：等待解码数据的长度
	**输出：
	*		p_szOut：用户用于存放Wave格式数据的缓冲
	*		pszOutLen： 作为输入参数时，指p_szOut缓冲长度
	*		解码后的数据格式为：
	*				SamplesPerSec = 8000;			//采样率
	*				BitPerSample = 16;				//音频分辨率
	*				FormatTag = WAVE_FORMAT_PCM;	//音频采样格式
	*				Channels = 1;					//音频通道数
	**返回值：
	*		执行成功返回true， false错误
	**功能：
	*	注当错误时，用户应该丢弃该编码数据。
	************************************************************************/
	virtual bool decode(const char * p_pszIn, const int p_nInLen, char * p_szOut, int & p_nOutLen ) = 0;
	

};

#endif //_ICODEC_H_

