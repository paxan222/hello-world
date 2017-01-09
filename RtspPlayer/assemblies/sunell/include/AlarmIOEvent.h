#ifndef _ALARMIOEVENT_H_
#define _ALARMIOEVENT_H_

#include "DomainConst.h"
#include "AlarmOutAction.h"
#include "AlarmRecordAction.h"
#include "AlarmPTZAction.h"
#include "AlarmOverlayAction.h"
#include "ScheduleTimeParam.h"
#include <vector>
#include "SNPlatOS.h"

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

class SN_DLL_API AlarmIOEvent
{
public:
	AlarmIOEvent();
	~AlarmIOEvent();

	//拷贝构造函数
	AlarmIOEvent(const AlarmIOEvent &p_objAlarmIOEvent);

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
	*	设置报警输入ID号
    **输入：
	*		p_nAlarmInId ：报警输入ID号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*      
	**************************************************************************/
	void setAlarmInId(int p_nAlarmInId);

	/************************************************************************
	**概述：
	*		获取报警输入ID号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警输入ID号
	**功能：
	*      
	**************************************************************************/
	int getAlarmInId() const;

	/************************************************************************
	**概述：
	*		设置是否启动IO报警标志
	**输入：
	*		p_bFlag：是否启动IO报警标志
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	设置是否启动IO报警标志
	************************************************************************/
	void setAlarmIOEnableFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取是否启动IO报警标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		是否启动IO报警标志
	**功能：
	*	获取是否启IO报警标志
	************************************************************************/
	const bool getAlarmIOEnableFlag() const ;

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
	const ScheduleTimeParam& getScheduleTimeParam() const;

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


	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objAlarmIOEvent：IO报警事件对象
	**输出：
	*		无
	**返回值：
	*		赋值后的IO报警事件对象
	**功能：
	*		
	*****************************************************************************/
	AlarmIOEvent& operator = (const AlarmIOEvent &p_objAlarmIOEvent);

	bool operator == (const AlarmIOEvent &p_objAlarmIOEvent) const;

	bool operator < (const AlarmIOEvent &p_objAlarmIOEvent) const;

private:
	
	int		m_nEventId;												//报警事件ID

	int		m_nPolicyId;											//报警策略ID
	
	int		m_nAlarmInId;											//报警输入ID号

	bool	m_bAlarmIOEnableFlag;									//是否启动IO报警(false：不启动， true：启动)

	char	m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//设备ID
	
	ScheduleTimeParam			m_objScheduleTimeParam;				//布防时间参数

	vector<AlarmOutAction>		m_objAlarmOutActionList;			//报警输出行为对象列表
	vector<AlarmRecordAction>	m_objAlarmRecordActionList;			//报警录像行为对象列表
	vector<AlarmPTZAction>		m_objAlarmPTZActionList;			//报警云台行为对象列表
	vector<AlarmOverlayAction>	m_objAlarmOverlayActionList;		//报警水印行为对象列表
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
	
#endif //_ALARMINPUTEVENT_H_
