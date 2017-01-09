#ifndef _RECORDQUALITYPARAM_H_
#define _RECORDQUALITYPARAM_H_

#include "VideoEncodeQuality.h"
#include "AudioEncodeQuality.h"
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

class SN_DLL_API RecordQualityParam
{
public:

	RecordQualityParam();

	~RecordQualityParam();

	RecordQualityParam(const RecordQualityParam &p_objRecordQualityParam);

public:
	/************************************************************************
	**概述：
	*		设置摄像机的Id号
	**输入：
	*		p_nCameraId ：摄像机的Id号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	**************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**概述：
	*		获取摄像机的Id号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		摄像机的Id号
	**功能：
	*
	**************************************************************************/
	const int getCameraId() const ;


	/************************************************************************
	**概述：
	*		设置录像的视频编码质量
	**输入：
	*		p_objVideoEncodeQuality ：视频编码质量
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	**************************************************************************/
	void setVideoEncodeQuality(const VideoEncodeQuality & p_objVideoEncodeQuality);

	/************************************************************************
	**概述：
	*		获取录像的视频编码质量
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录像的视频编码质量
	**功能：
	*
	**************************************************************************/
	const VideoEncodeQuality & getVideoEncodeQuality() const;


	/************************************************************************
	**概述：
	*		设置录像的音频编码质量
	**输入：
	*		p_objAudioEncodeQuality ：音频编码质量
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	**************************************************************************/
	void setAudioEncodeQuality(const AudioEncodeQuality & p_objAudioEncodeQuality);

	/************************************************************************
	**概述：
	*		获取录像的音频编码质量
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录像的音频编码质量
	**功能：
	*
	**************************************************************************/
	const AudioEncodeQuality & getAudioEncodeQuality() const;


	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objRecordQualityParam：录制质量参数对象
	**输出：
	*		无
	**返回值：
	*		赋值后的录制质量参数对象
	**功能：
	*		
	*****************************************************************************/
	RecordQualityParam &operator =(const RecordQualityParam &p_objRecordQualityParam);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objRecordQualityParam：RecordQualityParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个RecordQualityParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const RecordQualityParam &p_objRecordQualityParam) const;

	bool operator < (const RecordQualityParam &p_objRecordQualityParam) const;
private:
	int		m_nCameraId;										//摄像机的ID号

	VideoEncodeQuality m_objVideoEncodeQuality;					//视频编码质量
	
	AudioEncodeQuality m_objAudioEncodeQuality;					//音频编码质量
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_RecordQualityParam_H_
