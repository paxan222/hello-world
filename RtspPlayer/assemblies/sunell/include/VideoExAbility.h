#ifndef _VIDEOEXABILITY_H_
#define _VIDEOEXABILITY_H_

#include "CameraExAbility.h"
#include "VideoEncoderAbility.h"
#include "VideoSystem.h"
#include "SourceResolutionAbility.h"
#include "VideoOutAbility.h"
#include "SNPlatOS.h"
#include <vector>

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




class SN_DLL_API VideoExAbility
{
public:
	VideoExAbility(void);
	~VideoExAbility(void);

public:
	/************************************************************************
	*	概述：设置视频制式可配标志
	*	输入：
	*		p_bFlag：视频制式可配标志
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setVideoSystemConfigurableFlag(bool p_bFlag);

	/************************************************************************
	*	概述：获取视频制式可配标志
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		视频制式可配标志
	*************************************************************************/
	bool getVideoSystemConfigurableFlag() const;

	/************************************************************************
	*	概述：设置视频制式
	*	输入：
	*		p_VideoSystemList：视频制式列表
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setVideoSystemList(const std::vector<VideoSystem> &p_VideoSystemList);

	/************************************************************************
	*	概述：获取视频制式
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		视频制式
	*************************************************************************/
	const std::vector<VideoSystem> & getVideoSystemList() const;

	/************************************************************************
	*	概述：设置源分辨率能力列表
	*	输入：
	*		p_objSourceResolutionAbilityList	源分辨率能力列表
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setSourceResolutionAbilityList(const std::vector<SourceResolutionAbility> &p_objSourceResolutionAbilityList);

	/************************************************************************
	*	概述：获取源分辨率能力列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		源分辨率能力列表
	*************************************************************************/
	const std::vector<SourceResolutionAbility> &getSourceResolutionAbilityList() const;

	/************************************************************************
	*	概述：设置视频分辨率能力列表
	*	输入：
	*		p_objVideoResolutionAbilityList：视频分辨率能力列表
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setVideoEncoderAbilityList(const std::vector<VideoEncoderAbility> & p_objVideoEncoderAbilityList);

	/************************************************************************
	*	概述：获取视频分辨率能力列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		视频分辨率能力列表
	*************************************************************************/
	const std::vector<VideoEncoderAbility> & getVideoEncoderAbilityList() const;

	/************************************************************************
	*	概述：设置摄像机能力列表
	*	输入：
	*		p_objCameraExAbilityList：摄像机能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setCameraExAbilityList(const std::vector<CameraExAbility> & p_objCameraExAbilityList);
	
	/************************************************************************
	*	概述：获取摄像机能力列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		摄像机能力列表
	*************************************************************************/
	const std::vector<CameraExAbility> &getCameraExAbilityList() const;


	/************************************************************************
	*	概述：设置设备模拟模出能力
	*	输入：
	*		p_objVideoOutAbility：模拟模出能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setVideoOutAbility(const VideoOutAbility & p_objVideoOutAbility);

	/************************************************************************
	*	概述：获取设备模拟模出能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		模拟模出能力
	*************************************************************************/
	const VideoOutAbility &getVideoOutAbility() const;
public:

	VideoExAbility &operator =(const VideoExAbility &p_VideoExAbility);

public:
	bool findCameraExAbility(int p_nCameraId, CameraExAbility & p_objCameraExAbility) const;
	
	bool findVideoEncoderAbility(int p_nEncoderType, VideoEncoderAbility & p_objVideoEncoderAbility) const;

	bool findSourceResolutionAbility(const int p_VideoSystemId,SourceResolutionAbility &p_SourceResolutionAbility) const;

private:
	std::vector<CameraExAbility>			m_objCameraExAbilityList;			//摄像机能力列表
	std::vector<VideoEncoderAbility>		m_objVideoEncoderAbilityList;		//视频编码能力列表

	bool									m_bIsVideoSystemConfigurable;		//视频制是否可配置
	std::vector<VideoSystem>				m_objVideoSystemList;				//视频制式能力列表
	std::vector<SourceResolutionAbility>	m_objSourceResolutionAbilityList;	//源分辨率能力列表

	VideoOutAbility							m_objVideoOutAbility;				//模拟输出能力	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_VIDEO_ABILITY_
