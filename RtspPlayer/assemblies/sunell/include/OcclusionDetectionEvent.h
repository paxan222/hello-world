#ifndef _OCCLUSIONDETECTIONEVENT_H_
#define _OCCLUSIONDETECTIONEVENT_H_

#include "DomainConst.h"
#include "AlarmOutAction.h"
#include "AlarmRecordAction.h"
#include "AlarmPTZAction.h"
#include "AlarmOverlayAction.h"
#include "DetectionArea.h"
#include "OcclusionDetectionParam.h"
#include "ScheduleTimeParam.h"
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

class SN_DLL_API OcclusionDetectionEvent
{
public:
	OcclusionDetectionEvent();
	~OcclusionDetectionEvent();

	//拷贝构造函数
	OcclusionDetectionEvent (const OcclusionDetectionEvent &p_objOcclusionDetectionEvent);

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
	*		false：失败 
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
	void setOcclusionDetectionEnableFlag(const bool p_bFlag);

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
	const bool getOcclusionDetectionEnableFlag() const ;

	/************************************************************************
	**概述：
	*		设置报警布防时间
	**输入：
	*		p_objScheduleTimeParam：报警布防时间
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	设置报警布防时间
	************************************************************************/
	void setScheduleTimeParam(const ScheduleTimeParam &p_objScheduleTimeParam);

	/************************************************************************
	**概述：
	*		获取报警布防时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警布防时间
	**功能：
	*	获取报警布防时间
	************************************************************************/
	const ScheduleTimeParam & getScheduleTimeParam() const;

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
	const vector<AlarmOutAction>& getAlarmOutAction() const;

	/************************************************************************
	**概述：
	*		设置报警云台行为对象列表
	**输入：
	*		p_objAlarmPTZActionList：报警云台行为对象列表
	**输出：
	*		无
	**返回值：
	*		
	**功能：
	*      
	**************************************************************************/
	void setAlarmPTZAction(const vector<AlarmPTZAction>& p_objAlarmPTZActionList);

	/************************************************************************
	**概述：
	*		获取报警云台行为对象列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警云台行为对象列表
	**功能：
	*      
	**************************************************************************/
	const vector<AlarmPTZAction>& getAlarmPTZAction() const;

	/************************************************************************
	**概述：
	*		设置遮挡侦测参数
	**输入：
	*		p_objOcclusionDetectionParam：遮挡侦测参数
	**输出：
	*		无
	**返回值：
	*		
	**功能：
	*      
	**************************************************************************/
	void setOcclusionDetectionParam(const OcclusionDetectionParam& p_objOcclusionDetectionParam); 

	/************************************************************************
	**概述：
	*		获取移动侦测规则对象
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		获取移动侦测规则对象
	**功能：
	*      
	**************************************************************************/
	const OcclusionDetectionParam& getOcclusionDetectionParam() const; 


	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objOcclusionDetectionEvent：移到侦测报警事件对象
	**输出：
	*		无
	**返回值：
	*		赋值后的移到侦测报警事件对象
	**功能：
	*		
	*****************************************************************************/
	OcclusionDetectionEvent& operator = (const OcclusionDetectionEvent& p_objOcclusionDetectionEvent);

private:
	
	char							m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//DVR设备的设备ID
	int								m_nCameraId;											//DVR设备摄像头ID号
	bool							m_bOcclusionDetectionEnableFlag;						//是否启动
	
	OcclusionDetectionParam         m_objOcclusionDetectionParam;							//侦测规则对象

	ScheduleTimeParam				m_objScheduleTimeParam;									//布防时间参数

	std::vector<AlarmOutAction>			m_objAlarmOutActionList;								//报警输出行为对象列表
	std::vector<AlarmPTZAction>			m_objAlarmPTZActionList;								//报警云台行为对象列表
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_OCCLUSIONDETECTIONEVENT_H_
