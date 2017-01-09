#ifndef _MOTIONDETECTIONEVENT_H_
#define _MOTIONDETECTIONEVENT_H_

#include "DomainConst.h"
#include "AlarmOutAction.h"
#include "AlarmRecordAction.h"
#include "AlarmPTZAction.h"
#include "AlarmOverlayAction.h"
#include "DetectionArea.h"
#include "MotionDetectionParam.h"
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

class SN_DLL_API MotionDetectionEvent
{
public:
	MotionDetectionEvent();
	~MotionDetectionEvent();

	//拷贝构造函数
	MotionDetectionEvent (const MotionDetectionEvent &p_objMotionDetectionEvent);

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
	*		设置是否启动运动检测标志
	**输入：
	*		p_bFlag：是否启动运动检测标志
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	设置是否启动运动检测标志
	************************************************************************/
	void setMotionDetectionEnableFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取是否启动运动检测标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		是否启动运动检测标志
	**功能：
	*	获取是否启动运动检测标志
	************************************************************************/
	const bool getMotionDetectionEnableFlag() const ;

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


		/************************************************************************
	**概述：
	*		设置移动侦测规则对象
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		设置移动侦测规则对象
	**功能：
	*      
	**************************************************************************/
	void setMotionDetectionParam(const MotionDetectionParam & p_MotionDetectionParam); 
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
	MotionDetectionParam* getMotionDetectionParam() const; 


	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objMotionDetectionEvent：移到侦测报警事件对象
	**输出：
	*		无
	**返回值：
	*		赋值后的移到侦测报警事件对象
	**功能：
	*		
	*****************************************************************************/
	MotionDetectionEvent& operator = (const MotionDetectionEvent &p_objMotionDetectionEvent);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objMotionDetectionEvent：MotionDetectionEvent类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true ：相等
	*		false：不相等
	**功能：
	*		两个MotionDetectionEvent类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	//bool operator == (const MotionDetectionEvent& p_objMotionDetectionEvent) const;

	//bool operator < (const MotionDetectionEvent& p_objMotionDetectionEvent) const;

private:
	
	int			m_nEventId;												//报警事件ID
	int			m_nPolicyId;											//报警策略ID
	char		m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//DVR设备的设备ID
	int			m_nCameraId;											//DVR设备摄像头ID号
	bool		m_bMotionDetectionEnableFlag;							//是否启动运动检测
	
	//bool		m_bToUpCheckFlag;										//向左检测（true：检测，false：不检测）
	//bool		m_bToDownCheckFlag;										//向下检测（true：检测，false：不检测）
	//bool		m_bToLeftCheckFlag;										//向左检测（true：检测，false：不检测）
	//bool		m_bToRightCheckFlag;									//向右检测（true：检测，false：不检测）
	//bool		m_bAreaMaskFlag;										//屏蔽标识（true：屏蔽，false：检测）
	//int			m_nCheckBlockNum;										//检测块数
	//int			m_nSensitivity;											//灵敏度
	//int			m_nImageFormatId;										//视频格式
	//int			m_nFrameInterval;										//帧间隔
	//vector<DetectionArea>			m_objDetectionAreaList;				//移动侦测区域对象列表
	
	MotionDetectionParam            m_objMotionDetectionParam;			//移动侦测规则对象

	ScheduleTimeParam				m_objScheduleTimeParam;				//布防时间参数

	vector<AlarmOutAction>			m_objAlarmOutActionList;			//报警输出行为对象列表
	vector<AlarmRecordAction>		m_objAlarmRecordActionList;			//报警录像行为对象列表
	vector<AlarmPTZAction>			m_objAlarmPTZActionList;			//报警云台行为对象列表
	vector<AlarmOverlayAction>		m_objAlarmOverlayActionList;		//报警水印行为对象列表

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_MOTIONDETECTIONEVENT_H_
