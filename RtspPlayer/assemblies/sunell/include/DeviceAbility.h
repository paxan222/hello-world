#ifndef _DEVICE_ABILITY_
#define _DEVICE_ABILITY_

#include "AudioAbility.h"
#include "VideoAbility.h"
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
*	概述：设备能力信息
*	主要包含以下信息：音频能力信息，视频能力信息
************************************************************************/
class SN_DLL_API DeviceAbility
{
public:
	DeviceAbility(void);
	~DeviceAbility(void);

public:
	/************************************************************************
	**概述：
	*		设置音频能力
	**输入：
	*		p_objAudioAbility：	音频能力
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setAudioAbility(AudioAbility& p_objAudioAbility);

	/************************************************************************
	**概述：
	*		获取音频能力
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		音频能力
	**功能：
	*	
	*************************************************************************/
	const AudioAbility& getAudioAbility() const;


	/************************************************************************
	**概述：
	*		设置视频能力
	**输入：
	*		p_objAudioAbility：	视频能力
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setVideoAbility(VideoAbility& p_objVideoAbility);

	/************************************************************************
	**概述：
	*		获取视频能力
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		视频能力
	**功能：
	*	
	*************************************************************************/
	const VideoAbility& getVideoAbility() const;


	/************************************************************************
	**概述：
	*		查找编码能力
	**输入：
	*		p_nCameraId：		摄像机编号
	*		p_nImageFormatId：	图像格式
	*		p_nVideoSystem：	视频制式
	**输出：
	*		p_objEncoderAbility：编码能力
	**返回值：
	*		true ：查找成功
	*		false：查找失败
	**功能：
	*	
	************************************************************************/
	bool findEncoderAbility(const int p_nCameraId, const int p_nImageFormatId, 
							const int p_nVideoSystem, EncoderAbility& p_objEncoderAbility);
private:
	AudioAbility	m_objAudioAbility;			//音频能力
	VideoAbility	m_objVideoAbility;			//视频能力
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DEVICE_ABILITY_
