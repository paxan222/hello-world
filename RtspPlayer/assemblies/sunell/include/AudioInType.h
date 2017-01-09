#ifndef _AUDIOINTYPE_H_
#define _AUDIOINTYPE_H_

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

class SN_DLL_API AudioInType
{
public:
	AudioInType(void);
	~AudioInType(void);

	AudioInType(const AudioInType &p_AudioInType);

public:
	/***********************************************************************
	**概述：
	*		设置音频输入类型ID
	**输入：
	*		p_nAudioInTypeId：音频输入类型ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void setAudioInTypeId(int p_nAudioInTypeId);

	/************************************************************************
	**概述：
	*		获取音频输入类型ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		音频输入类型ID
	**功能：
	*
	***************************************************************************/
	int getAudioInTypeId() const;


	/***********************************************************************
	**概述：
	*		设置音频输入类型名
	**输入：
	*		p_pszAudioInTypeName：音频输入类型名
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	bool setAudioInTypeName(const char*	p_pszAudioInTypeName);

	/************************************************************************
	**概述：
	*		获取音频输入类型名
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		音频输入类型名
	**功能：
	*
	***************************************************************************/
	const char* getAudioInTypeName() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objAudioInType ：音频输入类型对象
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	AudioInType& operator = (const AudioInType &p_objAudioInType);


private:
	int		m_nAudioInTypeId;												//音频输入类型Id
	char	m_szAudioInTypeName[CONST_MAXLENTH_AUDIO_IN_TYPE_NAME + 1];		//音频输入类型名
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_AudioInType_H_
