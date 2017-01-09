#ifndef _CAMERAEXABILITY_H_
#define _CAMERAEXABILITY_H_

#include <vector>
#include "VideoResolution.h"
#include "AVStreamAbility.h"
#include "MotionDetectionExAbility.h"
#include "BlindAbility.h"
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

class SN_DLL_API CameraExAbility
{
public:
	CameraExAbility(void);
	~CameraExAbility(void);

public:
	/************************************************************************
	*	概述：设置摄像头编号
	*	输入：
	*		p_nCameraId：	摄像头编号
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setCameraId(int p_nCameraId);

	/************************************************************************
	*	概述：获取摄像头编号
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		摄像头编号
	*************************************************************************/
	int getCameraId() const;

	/************************************************************************
	*	概述：设置摄像头支持的最大分辨率
	*	输入：
	*		p_objVideoResolution：	最大分辨率
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setMaxVideoResolution(const VideoResolution & p_objVideoResolution);

	/************************************************************************
	*	概述：获取摄像头支持的最大分辨率
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		最大分辨率
	*************************************************************************/
	const VideoResolution & getMaxVideoResolution() const;

	/************************************************************************
	*	概述：设置源分辨率列表
	*	输入：
	*		p_objSourceResolutionList：	源分辨率列表
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

	/************************************************************************
	*	概述：设置支持的分辨率列表
	*	输入：
	*		p_objVideoResolutionList	支持的分辨率列表
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setVideoResolutionList(const std::vector<VideoResolution> & p_objVideoResolutionList);

	/************************************************************************
	*	概述：获取该摄像头的移动侦测能力信息
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		移动侦测能力信息
	*************************************************************************/
	const MotionDetectionExAbility& getMotionDetectionExAbility() const;

	/************************************************************************
	*	概述：设置移动侦测能力信息
	*	输入：
	*		p_objMotionDetectionExAbility	支持的移动侦测能力信息
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setMotionDetectionExAbility(const MotionDetectionExAbility & p_objMotionDetectionExAbility);

	/************************************************************************
	*	概述：获取支持的分辨率列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		支持的分辨率列表
	*************************************************************************/
	const std::vector<VideoResolution>& getVideoResolutionList() const;

	/************************************************************************
	*	概述：设置码流能力列表
	*	输入：
	*		p_objAVStreamAbilityList：	码流能力列表
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setAVStreamAbilityList(const std::vector<AVStreamAbility> & p_objAVStreamAbilityList);

	/************************************************************************
	*	概述：获取码流能力列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		码流能力列表
	*************************************************************************/
	const std::vector<AVStreamAbility>& getAVStreamAbilityList() const;

	bool findAVStreamAbility(int p_nStreamId, AVStreamAbility & p_objAVStreamAbility) const;
	
	/************************************************************************
	*	概述：设置摄像头遮挡能力
	*	输入：
	*		p_objBlindAbility：	遮挡能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setBlindAbility(const BlindAbility &p_objBlindAbility);

	/************************************************************************
	*	概述：获取摄像头遮挡能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		摄像头遮挡能力
	*************************************************************************/
	const BlindAbility &getBlindAbility() const;


private:
	int									m_nCameraId;						//摄像头编号
	VideoResolution						m_objMaxVideoResolution;			//支持的最大分辨率
	std::vector<VideoResolution>		m_objSourceResolutionList;			//源分辨率列表
	std::vector<VideoResolution>		m_objVideoResolutionList;			//支持的分辨率列表
	std::vector<AVStreamAbility>		m_objAVStreamAbilityList;			
	BlindAbility						m_objBlindAbility;					//遮挡能力	
	MotionDetectionExAbility			m_objMotionDetectionExAbility;		//移动侦测能力列表

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CAMERA_ABILITY_
