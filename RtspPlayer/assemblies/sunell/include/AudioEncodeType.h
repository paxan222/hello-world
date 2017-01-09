#ifndef _AUDIOENCODETYPE_H_
#define _AUDIOENCODETYPE_H_

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

class SN_DLL_API AudioEncodeType
{
public:
	AudioEncodeType(void);
	~AudioEncodeType(void);

	AudioEncodeType(const AudioEncodeType &p_AudioEncodeType);

public:
	/***********************************************************************
	**概述：
	*		设置音频编码类型ID
	**输入：
	*		p_nAudioEncodeTypeId：音频编码类型ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void setAudioEncodeTypeId(int p_nAudioEncodeTypeId);

	/************************************************************************
	**概述：
	*		获取音频编码类型ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		音频编码类型ID
	**功能：
	*
	***************************************************************************/
	int getAudioEncodeTypeId() const;


	/***********************************************************************
	**概述：
	*		设置音频编码类型名
	**输入：
	*		p_pszAudioEncodeTypeName：音频编码类型名
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	bool setAudioEncodeTypeName(const char* p_pszAudioEncodeTypeName);

	/************************************************************************
	**概述：
	*		获取音频编码类型名
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		音频编码类型名
	**功能：
	*
	***************************************************************************/
	const char* getAudioEncodeTypeName() const;
	
	/***********************************************************************
	**概述：
	*		设置音频编码模式
	**输入：
	*		p_nAudioEncodeTypeMode：音频编码模式，0为软件编码，1为硬件编码
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void setAudioEncodeTypeMode(int p_nAudioEncodeTypeMode);
	
	/***********************************************************************
	**概述：
	*		设置音频编码模式
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		音频编码模式
	**功能：
	************************************************************************/
	int getAudioEncodeTypeMode() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objAudioEncodeType ：音频编码类型对象
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	AudioEncodeType& operator = (const AudioEncodeType &p_objAudioEncodeType);

private:
	int		m_nAudioEncodeTypeId;													//音频编码类型Id
	int		m_nAudioEncodeTypeMode;    										//音频编码模式
	char	m_szAudioEncodeTypeName[CONST_MAXLENTH_AUDIO_ENCODE_TYPE_NAME + 1];     //音频编码类型名
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_AUDIOENCODETYPE_H_
