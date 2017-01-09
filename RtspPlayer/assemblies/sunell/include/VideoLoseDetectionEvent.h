#ifndef _VIDEOLOSEDETECTIONEVENT_H_
#define _VIDEOLOSEDETECTIONEVENT_H_

#include "DomainConst.h"
#include "AlarmOutAction.h"
#include "AlarmPTZAction.h"
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

class SN_DLL_API VideoLoseDetectionEvent
{
public:
	VideoLoseDetectionEvent();
	~VideoLoseDetectionEvent();

	//拷贝构造函数
	VideoLoseDetectionEvent (const VideoLoseDetectionEvent& p_objVideoLoseDetectionEvent);

public:

	/**********************************************************************
	**概述：
	*		设置网络视频设备的设备ID
	**输入：
	*		p_pszDeviceId ：字符串，最大长度为CONST_MAXLENGTH_DEVICEID字节,
	*		结尾以‘\0’结束。
	**输出：
	*		无
	**返回值：
	*		true ： 成功
	*		false：	失败 
	**功能：
	*		若输入p_pszDeviceId长度<=CONST_MAXLENGTH_DEVICEID，返回true，
	*		并保存到m_szDeviceId;
	*		若输入p_pszDeviceId为NULL或其长度>CONST_MAXLENGTH_DEVICEID，返回false
	************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**概述：
	*		获取网络视频设备的设备ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		设备ID
	**功能：
	*
	***************************************************************************/
	const char* getDeviceId() const;

	/************************************************************************
	**概述：
	*		设置设备摄像头ID号
	**输入：
	*		p_nCameraId：设备摄像头ID号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setCameraId(int p_nCameraId);

	/************************************************************************
	**概述：
	*		获取设备摄像头ID号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		设备摄像头ID号
	**功能：
	*
	************************************************************************/
	int getCameraId() const;

	/************************************************************************
	**概述：
	*		设置是否启动标志
	**输入：
	*		p_bFlag		是否启动标志
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setVideoLoseDetectionEnableFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取是否启动标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		是否启动标志
	************************************************************************/
	const bool getVideoLoseDetectionEnableFlag() const ;

	/************************************************************************
	**概述：
	*		设置报警输出行为对象列表
	**输入：
	*		p_objAlarmOutActionList：报警输出行为对象列表
	**输出：
	*		无
	**返回值：
	*		
	**功能：
	*      
	**************************************************************************/
	void setAlarmOutAction(const std::vector<AlarmOutAction>& p_objAlarmOutActionList);

	/************************************************************************
	**概述：
	*		获取报警输出行为对象列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警输出行为对象列表
	**功能：
	*      
	**************************************************************************/
	const std::vector<AlarmOutAction>& getAlarmOutAction() const;

	/************************************************************************
	**概述：
	*		设置报警PTZ行为对像列表
	**输入：
	*		p_objAlarmOutActionList：报警PTZ行为对像列表
	**输出：
	*		无
	**返回值：
	*		
	**功能：
	*      
	**************************************************************************/
	void setAlarmPTZAction(const std::vector<AlarmPTZAction>& p_objAlarmPTZActionList);

	/************************************************************************
	**概述：
	*		获取报警PTZ行为对像列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警输出行为对象列表
	**功能：
	*      
	**************************************************************************/
	const  std::vector<AlarmPTZAction>& getAlarmPTZAction() const;

	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objVideoLoseDetectionEvent：视频丢失报警事件对象
	**输出：
	*		无
	**返回值：
	*		赋值后的视频丢失报警事件对象
	**功能：
	*		
	*****************************************************************************/
	VideoLoseDetectionEvent& operator = (const VideoLoseDetectionEvent& p_objVideoLoseDetectionEvent);



private:

	char							m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//设备ID

	int								m_nCameraId;											//摄像头ID号

	bool							m_bVideoLoseDetectionEnableFlag;						//是否启动侦测

	std::vector<AlarmOutAction>		m_objAlarmOutActionList;								//报警输出行为对象列表

	std::vector<AlarmPTZAction>		m_objAlarmPTZActionList;								//报警PTZ行为对像列表
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif	//_VIDEOLOSEDETECTIONEVENT_H_


