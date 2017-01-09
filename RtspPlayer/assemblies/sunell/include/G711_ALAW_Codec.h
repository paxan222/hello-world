#ifndef _G711_ALAW_CODEC_H_
#define _G711_ALAW_CODEC_H_

#include "ICodec.h"
#include "SNPlatOS.h"

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

class SN_DLL_API G711_ALAW_Codec: public ICodec
{
public:
	G711_ALAW_Codec(void);
	~G711_ALAW_Codec(void);

public:
	/************************************************************************
	**概述：
	*		对线性 PCM 数据进行 G711a 编码
	**输入：
	*		p_pszIn  ：  线性 PCM 数据
	*		p_nInLen ：	线性 PCM 数据长度
	**输出：
	*		p_szOut  ：	编码后的 G711a 数据
	*		p_nOutLen：	编码后的 G711a 数据长度
	**返回值：
	*		执行成功返回true， false 错误
	**功能：
	*		注当错误时，用户应该丢弃该编码数据。
	************************************************************************/
	bool encode(const char * p_pszIn, const int p_nInLen, char * p_szOut, int & p_nOutLen);


	/************************************************************************
	**概述：
	*		将 G711a 数据解码为线性 PCM 数据。
	**输入：
	*		p_pszIn  ：G711a 数据
	*		p_nInLen ：G711a 数据长度
	**输出：
	*		p_szOut  ：解码后的 PCM 数据
	*		pszOutLen：解码后的 PCM 数据长度 
	**返回值：
	*		执行成功返回true， false错误
	**功能：
	*		注当错误时，用户应该丢弃该编码数据。
	************************************************************************/
	bool decode(const char * p_pszIn, const int p_nInLen, char * p_szOut, int & p_nOutLen);

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif  //_G711_ALAW_CODEC_H_

