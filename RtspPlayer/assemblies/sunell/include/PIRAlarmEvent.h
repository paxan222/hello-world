#ifndef _PIR_ALARM_EVENT_H_
#define _PIR_ALARM_EVENT_H_

#include "DomainConst.h"
#include "AlarmOutAction.h"
#include "AlarmRecordAction.h"
#include "AlarmPTZAction.h"
#include "AlarmOverlayAction.h"
#include "ScheduleTimeParam.h"
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

/************************************************************************/
/* add: weihuiquam
/* why: for PIR Alarm
/* date:2014.09.04
/************************************************************************/

class PIRAlarmEvent
{
public:
	PIRAlarmEvent(void);
	~PIRAlarmEvent(void);
	//拷贝构造
	PIRAlarmEvent(const PIRAlarmEvent &p_objPIRAlarmEvent);
	//赋值构造
	PIRAlarmEvent& operator = (const PIRAlarmEvent &p_objPIRAlarmEvent);

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


	/**********************************************************************
	**概述：
	*		设置报警事件ID
	**输入：
	*		p_nEventId ：报警事件ID号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setEventId(int p_nEventId);

	/************************************************************************
	**概述：
	*		获取报警事件ID
	**输入：
	*		无
	**输出：
	*		
	**返回值：
	*		报警事件ID
	**功能：
	*	
	***************************************************************************/
	int getEventId() const;


	/**********************************************************************
	**概述：
	*		设置报警策略ID
	**输入：
	*		p_nPolicyId ：报警策略ID号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setPolicyId(int p_nPolicyId);

	/************************************************************************
	**概述：
	*		获取报警策略ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警策略ID
	**功能：
	*	
	***************************************************************************/
	int getPolicyId() const;


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
	*		设置是否启动PIR报警标志
	**输入：
	*		p_bFlag：是否启动运动检测标志
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	设置是否启动PIR报警标志
	************************************************************************/
	void setPIRAlarmEnableFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取是否启动PIR报警标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		是否启动PIR报警标志
	**功能：
	*	获取是否启动PIR报警标志
	************************************************************************/
	const bool getPIRAlarmEnableFlag() const ;

	/************************************************************************
	**概述：
	*		设置报警间隔
	**输入：
	*		p_nAlarmInterval：报警间隔
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		设置报警间隔
	************************************************************************/
	void setPIRAlarmInterval(const unsigned int p_nAlarmInterval);

	/************************************************************************
	**概述：
	*		获取报警间隔
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		设置报警间隔
	************************************************************************/
	const unsigned int getPIRAlarmInterval() const;

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
	void setAlarmOutAction(const vector<AlarmOutAction>& p_objAlarmOutActionList);

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
	vector<AlarmOutAction>* getAlarmOutAction() const;


	/************************************************************************
	**概述：
	*		设置报警录像行为对象列表
	**输入：
	*		p_objAlarmRecordActionList：报警录像行为对象列表
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*      
	**************************************************************************/
	void setAlarmRecordAction(const vector<AlarmRecordAction>& p_objAlarmRecordActionList);

	/************************************************************************
	**概述：
	*		获取报警录像行为对象列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警录像行为对象列表
	**功能：
	*      
	**************************************************************************/
	vector<AlarmRecordAction>* getAlarmRecordAction() const;


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
	vector<AlarmPTZAction>* getAlarmPTZAction() const;


	/************************************************************************
	**概述：
	*		设置报警水印行为对象列表
	**输入：
	*		p_objAlarmOverlayActionList：报警水印行为对象列表
	**输出：
	*		无
	**返回值：
	*		
	**功能：
	*      
	**************************************************************************/
	void setAlarmOverlayAction(const vector<AlarmOverlayAction>& p_objAlarmOverlayActionList);

	/************************************************************************
	**概述：
	*		获取报警水印行为对象列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警水印行为对象列表
	**功能：
	*      
	**************************************************************************/
	vector<AlarmOverlayAction>* getAlarmOverlayAction() const;

private:
	int				m_nEventId;												//报警事件ID
	int				m_nPolicyId;											//报警策略ID
	char			m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//DVR设备的设备ID
	int				m_nCameraId;											//DVR设备摄像头ID号
	bool			m_bPIRAlarmEnableFlag;									//是否启动PIR检测
	unsigned int	m_nAlarmInterval;										//报警，默认为10s

	ScheduleTimeParam				m_objScheduleTimeParam;				//布防时间参数
	vector<AlarmOutAction>			m_objAlarmOutActionList;			//报警输出行为对象列表
	vector<AlarmRecordAction>		m_objAlarmRecordActionList;			//报警录像行为对象列表
	vector<AlarmPTZAction>			m_objAlarmPTZActionList;			//报警云台行为对象列表
	vector<AlarmOverlayAction>		m_objAlarmOverlayActionList;		//报警水印行为对象列表

};

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/

#endif //_PIR_ALARM_EVENT_H_
