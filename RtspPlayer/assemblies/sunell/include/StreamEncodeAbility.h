#ifndef _STREAMENCODEABILITY_H_
#define _STREAMENCODEABILITY_H_

#include <vector>
#include "VideoResolution.h"
#include "SNPlatOS.h"

using namespace std;

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

class SN_DLL_API StreamEncodeAbility
{
public:
	StreamEncodeAbility(void);
	~StreamEncodeAbility(void);

public:
	/************************************************************************
	*	概述：设置编码器类型
	*	输入：
	*		p_nEncoderType：	编码器类型
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setEncoderType(int p_nEncoderType);

	/************************************************************************
	*	概述：获取编码器类型
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		编码器类型
	*************************************************************************/
	int getEncoderType() const;

	/************************************************************************
	*	概述：设置支持的分辨率列表
	*	输入：
	*		p_objVideoResolutionList：	分辨率列表
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setVideoResolutionList(const vector<VideoResolution> & p_objVideoResolutionList);

	/************************************************************************
	*	概述：获取支持的分辨率列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		分辨率列表
	*************************************************************************/
	const vector<VideoResolution> & getVideoResolutionList() const;

private:
	int						m_nEncoderType;					//码流ID
	vector<VideoResolution>	m_objVideoResolutionList;		//分辨率列表
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_StreamEncodeAbility_H_
