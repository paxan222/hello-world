#ifndef _MOTIONDETECTIONABILITY_H_
#define _MOTIONDETECTIONABILITY_H_

#include "SNPlatOS.h"
#include <vector>
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

/************************************************************************
**概述：移动侦测能力信息类
*	包含：视频格式,最大灵敏度,最小帧间隔
************************************************************************/

class SN_DLL_API MotionDetectionAbility
{
public:
	MotionDetectionAbility(void);
	~MotionDetectionAbility(void);

public:
	/************************************************************************
	**概述：
	*		设置视频格式编号
	**输入：
	*		p_nImageFormatId：	视频格式编号
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setImageFormatId(const int p_nImageFormatId);

	/************************************************************************
	**概述：
	*		获取视频格式编号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		视频格式编号
	*************************************************************************/
	const int getImageFormatId() const;


	/****************************************************************************
	**概述：
	*		设置最大灵敏度
	**输入：
	*		p_nMaxSensitivity：最大灵敏度
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setMaxSensitivity(const int p_nMaxSensitivity);

	/****************************************************************************
	**概述：
	*		获得最大灵敏度
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		最大灵敏度
	**功能：
	*
	*******************************************************************************/
	const int getMaxSensitivity() const;


	/****************************************************************************
	**概述：
	*		设置最小帧间隔
	**输入：
	*		p_nMinFrameInterval：最小帧间隔
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setMinFrameInterval(const int p_nMinFrameInterval);

	/****************************************************************************
	**概述：
	*		获得最小帧间隔
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		最小帧间隔
	**功能：
	*
	*******************************************************************************/
	const int getMinFrameInterval() const;

	bool operator < (const MotionDetectionAbility& p_objMotionDetectionAbility) const;

	bool operator == (const MotionDetectionAbility& p_objMotionDetectionAbility) const;

private:
	int			m_nImageFormatId;				//视频格式
	int			m_nMaxSensitivity;				//最大灵敏度
	int			m_nMinFrameInterval;			//最小帧间隔

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_MOTIONDETECTIONABILITY_H_
