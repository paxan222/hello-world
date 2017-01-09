#ifndef _SNAPSHOTPARAMETER_H_
#define _SNAPSHOTPARAMETER_H_
#include "VideoResolution.h"
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

class SN_DLL_API SnapshotParameter
{
public:
	SnapshotParameter();

	SnapshotParameter(const int p_Duration,const VideoResolution &p_VideoResolution,const unsigned int p_Quality,
		const int p_Interval,const int p_ShootTimes);

	~SnapshotParameter();

public:
	/************************************************************************
	**	概述：
	*		设置抓拍持续时间
	**	输入：
	*		p_Duration	抓拍持续时间，单位s
	**	输出：
	*		无
	**	返回值：
	*		无
	************************************************************************/
	void setDuration(const int p_Duration);

	/************************************************************************
	**概述：
	*		获取抓拍持续时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		抓拍持续时间，单位s
	************************************************************************/
	int getDuration() const;

	/************************************************************************
	*	概述：
	*		设置图像分辨率
	*	输入：
	*		p_VideoResolution	图像分辨率
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setVideoResolution(const VideoResolution &p_VideoResolution);

	/************************************************************************
	*	概述：
	*		获取图像分辨率
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		图像分辨率
	************************************************************************/
	const VideoResolution &getVideoResolution() const;

	/************************************************************************
	**概述：
	*		设置抓拍质量
	**输入：
	*		p_Quality	抓拍质量(1-9)
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setQuality(const unsigned int p_Quality);

	/************************************************************************
	**概述：
	*		获取抓拍质量
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		抓拍质量
	**功能：       
	************************************************************************/
	const unsigned int getQuality() const;

	/************************************************************************
	*	概述：
	*		设置抓拍时间间隔
	*	输入：
	*		p_Interval	抓拍时间间隔(单位为秒)
	*	输出：
	*		无
	*	返回值：
	*		无     
	************************************************************************/
	void setInterval(const int p_Interval);

	/************************************************************************
	*	概述：
	*		获取抓拍时间间隔
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		抓拍时间间隔
	************************************************************************/
	const int getInterval() const;

	/************************************************************************
	*	概述：
	*		设置每次抓拍张数
	*	输入：
	*		p_ShootTimes	每次抓拍张数
	*	输出：
	*		无
	*	返回值：
	*		无     
	************************************************************************/
	void setShootTimes(const int p_ShootTimes);

	/************************************************************************
	*	概述：
	*		获取每次抓拍张数
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		每次抓拍张数
	************************************************************************/
	const int getShootTimes() const;

	/************************************************************************
	**概述：
	*		判等函数
	**输入：
	*		p_SnapshotParameter	SnapshotParameter对象
	**输出：
	*		无
	**返回值：
	*		true ：相等
	*		false：不相等
	************************************************************************/
	bool operator == (const SnapshotParameter& p_SnapshotParameter);
private:
	int		m_Duration;					//抓拍持续时间，0表示不停抓拍。单位：s

	VideoResolution m_VideoResolution;		//分辨率

	unsigned int m_Quality;					//抓拍质量(1-9)

	unsigned int m_Interval;				//抓拍时间间隔
	
	unsigned int m_ShootTimes;				//每次抓拍张数
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_SNAPSHOTPARAMETER_H_
