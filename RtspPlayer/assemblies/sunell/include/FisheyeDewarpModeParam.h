#ifndef _FISHEYE_DEWARP_MODE_PARAM_H_
#define _FISHEYE_DEWARP_MODE_PARAM_H_

#include "FisheyeConst.h"
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

/************************************************************************
**概述：鱼眼矫正模式信息
*	主要包含以下信息：
*		设置获取通道号，设置获取鱼眼视频模式，设置获取。
************************************************************************/

class  SN_DLL_API FisheyeDewarpModeParam
{
public:
	FisheyeDewarpModeParam();
	~FisheyeDewarpModeParam();

public:

	/************************************************************************
	**概述：设置通道号
	**输入：
	*		p_nCameraId 通道号
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setCameraId(const int p_nCameraId);
	
	/************************************************************************
	**概述：获取通道号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		通道号
	*************************************************************************/
	int getCameraId()const;

	
	/************************************************************************
	**概述：设置鱼眼视频模式
	**输入：
	*		p_nFisheyeVideoMode 鱼眼视频模式
	*		FISHEYE_SINGLE_STREAM 单流模式  FISHEYE_MULTIPLE_STREAM 多流模式
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setFisheyeVideoMode(const int p_nFisheyeVideoMode);

	/************************************************************************
	**概述：获取鱼眼视频模式
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		鱼眼视频模式值
	*************************************************************************/
	int getFisheyeVideoMode() const;

	/************************************************************************
	**概述：设置矫正模式
	**输入：
	*	p_nDewarpMode 鱼眼矫正模式
	*	FISHEYE_DEWRAP_FISHEYE	= 0,	//鱼眼模式
	*	FISHEYE_DEWRAP_PANORAMA	= 2,	//全景模式
	*	FISHEYE_DEWARP_1F_3P	= 4,	//1鱼眼+3PTZ模式
	*	FISHEYE_DEWARP_1F_5P	= 5,	//1鱼眼+5PTZ模式
	*	FISHEYE_DEWARP_1F_7P	= 6,	//1鱼眼+7PTZ模式
	*	FISHEYE_DEWARP_1F_8P	= 7,	//1鱼眼+8PTZ模式
	*	FISHEYE_DEWARP_4PTZ		= 8		//4PTZ模式
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setDewarpMode(const int p_nDewarpMode);
	
	/************************************************************************
	**概述：获取鱼眼矫正模式
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		鱼眼矫正模式值
	*************************************************************************/
	int getDewarpMode()const;
	
	/************************************************************************
	**概述：两个对象判等操作
	*
	**输入：
	*		p_objRhs：判等操作右操作符
	**输出：
	*		无
	**返回值：
	*		相等返回true， 不等返回false
	*************************************************************************/
	bool operator == (const FisheyeDewarpModeParam& p_objRhs);
	FisheyeDewarpModeParam& operator = (const FisheyeDewarpModeParam& p_objRhs);
private:
	int m_nCameraId;		//通道号
	int m_nFisheyeVideoMode;	//鱼眼视频模式,具体定义可查看FisheyeConst.h中FISHEYE_VIDEO_MODE枚举定义
	int m_nDewarpMode;	//矫正模式,具体定义可查看FisheyeConst.h中FISHEYE_DEWARP_MODE枚举定义
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif //_FISHEYE_DEWARP_MODE_PARAM_H_

