#ifndef _SOURCERESOLUTIONABILITY_H_
#define _SOURCERESOLUTIONABILITY_H_

#include <vector>
#include "VideoResolution.h"
#include "VideoSystem.h"
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


class SN_DLL_API SourceResolutionAbility
{
public:
	SourceResolutionAbility(void);
	~SourceResolutionAbility(void);

public:
	/************************************************************************
	*	概述：设置摄像头的视频制式
	*	输入：
	*		p_objVideoSystem	摄像头的视频制式
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setVideoSystem(const VideoSystem & p_objVideoSystem);

	/************************************************************************
	*	概述：获取摄像头的视频制式
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		摄像头的视频制式
	*************************************************************************/
	const VideoSystem& getVideoSystem() const;

	/************************************************************************
	*	概述：设置源分辨率列表
	*	输入：
	*		p_objSourceResolutionList	源分辨率列表
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setSourceResolutionList(const std::vector<VideoResolution> & p_objSourceResolutionList);

	/************************************************************************
	*	概述：获取源分辨率列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		源分辨率列表
	*************************************************************************/
	const std::vector<VideoResolution>& getSourceResolutionList() const;

private:
	VideoSystem							m_objVideoSystem;			//视频制式
	std::vector<VideoResolution>		m_objSourceResolutionList;		//源分辨率列表
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_SOURCERESOLUTIONABILITY_H_
