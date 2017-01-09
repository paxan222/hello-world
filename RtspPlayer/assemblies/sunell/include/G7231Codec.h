#ifndef _G7231CODEC_H_
#define _G7231CODEC_H_

#include "SNPlatOS.h"
#include "ICodec.h"
#define CONST_LENGTH_RAWFRAMEDATA 480
#define CONST_MAXLENGTH_ENCODEDATA 24
class G7231AudioCodec;

/**********************************************************************/
//此处用于控制文件编译字节对齐，拷贝时两行注释间内容需一起拷贝，
//结束处的“#ifdef PRAGMA_PACK”部分也要一起拷贝，否则pragma pack入栈出栈不匹配
#if(PRAGMA_PACK_DEFINE != 10000)
	# error Not included "SNPlatOS.h".
#endif
 
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(push, PRAGMA_PACK_CHAR)
	#endif

	#ifndef WIN32  
		#ifndef _PACKED_1_  
		  
		#define _PACKED_1_ __attribute__((packed, aligned(PRAGMA_PACK_CHAR)))	// for gcc   
		#endif  
	#else  
		#ifndef _PACKED_1_  
		#define _PACKED_1_  
		#endif  
	#endif  
#else  
	#ifndef _PACKED_1_  
	#define _PACKED_1_  
	#endif  
#endif
/**********************************************************************/

class SN_DLL_API G7231Codec : public ICodec
{
public:
	G7231Codec(void);

	~G7231Codec(void);
public:
	/************************************************************************
	**概述：
	*		编码WAVE_PCM格式音频数据为G723.1码流。
	**输入：
	*		p_pszIn：  Wave格式的数据，其数据格式必须为：
	*				SamplesPerSec = 8000;			//采样率
	*				BitPerSample = 16;				//音频分辨率
	*				FormatTag = WAVE_FORMAT_PCM;	//音频采样格式
	*				Channels = 1;					//音频通道数
	*		p_nInLen：	被编码的Wave格式的数据长度，不需要是480字节的整数倍
	*		p_nOutLen：	p_szOut缓冲的长度，要求缓冲的长度必须大于或等于(N+1)*24，其中N = p_nInLen/480
	**输出：
	*		p_szOut：	用户用于存放G723.1码流的缓冲
	*		p_nOutLen：	编码后的长度，小于或等于N*24字节
	**返回值：
	*		执行成功返回true， false 错误
	**功能：
	*		注当错误时，用户应该丢弃该编码数据。
	************************************************************************/
	bool encode(const char * p_pszIn, const int p_nInLen, char * p_szOut, int & p_nOutLen );

	/************************************************************************
	**概述：
	*		解码G723.1码流数据为WAVE_PCM格式音频数据。
	**输入：
	*	p_pszIn：G723.1码流数据
	*	p_nInLen：G723.1码流数据的长度，可以是N个G723.1编码帧数据长度之和，每帧必须是完整的帧（一个单位的编码帧一般小于等于24字节）
	**输出：
	*		p_szOut：用户用于存放Wave格式数据的缓冲
	*		pszOutLen： 作为输入参数时，指p_szOut缓冲长度；p_szOut缓冲大小不能小于N* 480字节, N代表被解码的编码帧的数量，对应于p_pszIn参数中编码帧个数。
						作为输出参数时，返回解码后的长度，N*480字节。 
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
	bool decode(const char * p_pszIn, const int p_nInLen, char * p_szOut, int & p_nOutLen );

private:
	int computeFrameSize(int p_nInfo);
	
private:
	char			*m_LeftData;
	int				m_LeftDataLen;

	G7231AudioCodec * m_pobjEncoder;

	G7231AudioCodec * m_pobjDecoder;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif
