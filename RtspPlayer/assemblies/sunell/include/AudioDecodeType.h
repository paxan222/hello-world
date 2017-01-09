#ifndef _AUDIODECODETYPE_H_
#define _AUDIODECODETYPE_H_

#include "SNPlatOS.h"
#include "DomainConst.h"

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

class SN_DLL_API AudioDecodeType
{
public:
	AudioDecodeType(void);
	~AudioDecodeType(void);

	AudioDecodeType(const AudioDecodeType &p_AudioDecodeType);

public:
	/***********************************************************************
	**概述：
	*		设置音频解码类型ID
	**输入：
	*		p_nAudioDecodeTypeId：音频解码类型ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void setAudioDecodeTypeId(int p_nAudioDecodeTypeId);

	/************************************************************************
	**概述：
	*		获取音频解码类型ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		音频解码类型ID
	**功能：
	*
	***************************************************************************/
	int getAudioDecodeTypeId() const;


	/***********************************************************************
	**概述：
	*		设置音频解码类型名
	**输入：
	*		p_pszAudioDecodeTypeName：音频解码类型名
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	bool setAudioDecodeTypeName(const char* p_pszAudioDecodeTypeName);

	/************************************************************************
	**概述：
	*		获取音频解码类型名
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		音频解码类型名
	**功能：
	*
	***************************************************************************/
	const char* getAudioDecodeTypeName() const;
	
	/***********************************************************************
	**概述：
	*		设置音频解码模式
	**输入：
	*		p_nAudioDecodeTypeMode：音频解码模式，0为软件解码，1为硬件解码
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void setAudioDecodeTypeMode(int p_nAudioDecodeTypeMode);
	
	/***********************************************************************
	**概述：
	*		设置音频解码模式
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		音频解码模式
	**功能：
	************************************************************************/
	int getAudioDecodeTypeMode() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objAudioDecodeType ：音频解码类型对象
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	AudioDecodeType& operator = (const AudioDecodeType &p_objAudioDecodeType);

private:
	int		m_nAudioDecodeTypeId;													//音频解码类型Id
	int		m_nAudioDecodeTypeMode;												//音频解码模式
	char	m_szAudioDecodeTypeName[CONST_MAXLENTH_AUDIO_DECODE_TYPE_NAME + 1];		//音频解码类型名
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_AUDIODECODETYPE_H_
