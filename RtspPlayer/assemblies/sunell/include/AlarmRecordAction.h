#ifndef _ALARMRECORDACTION_H_
#define _ALARMRECORDACTION_H_

#include "DomainConst.h"
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

class SN_DLL_API AlarmRecordAction
{
public:

	AlarmRecordAction();
	~AlarmRecordAction();

	//拷贝构造函数
	AlarmRecordAction(const AlarmRecordAction &p_objAlarmRecordAction);

public:	
	/************************************************************************
	*概述：
	*		设置网络视频设备的设备ID
    *输入：
	*		p_pszDeviceId ：字符串，最大长度为CONST_MAXLENGTH_DEVICEID字节,
	*		结尾以‘\0’结束。
	*输出：
	*		无
	*返回值：
	*		true ： 成功
	*		false：失败 
	*功能：
	*		若输入p_pszDeviceId长度<=CONST_MAXLENGTH_DEVICEID，返回true，
	*		并保存到m_szDeviceId;
	*		若输入p_pszDeviceId为NULL或其长度>CONST_MAXLENGTH_DEVICEID，返回false
	*************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);
	
	/************************************************************************
	**概述：
	*		获取网络设备的设备ID
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		网络视频设备的设备ID
	**功能：
	* 	
	*************************************************************************/
	const char* getDeviceId() const;
	

	/************************************************************************
	**概述：
	*		设置摄像机的ID号
	**输入：
	*		p_nCameraId : 摄像机的ID号
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
	*		获取摄像机的ID号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		摄像机的ID号
	**功能：
	*       
	************************************************************************/
	int getCameraId() const;
	
	
	/************************************************************************
	**概述：
	*		设置预录时长
	**输入：
	*		p_nPreRecordTime ： 预录时长，以秒为单位。
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*       
	************************************************************************/
	void setPreRecordTime(int p_nPreRecordTime);
		
	/************************************************************************
	**概述：
	*		获取预录时长
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		预录时长，以秒为单位。
	**功能：
	*       
	************************************************************************/
	int getPreRecordTime() const;
	
	
	/************************************************************************
	**概述：
	*		设置录制时长
	**输入：
	*		p_nRecordTime ：录制时长，以秒为单位。
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*       
	************************************************************************/
	void setRecordTime(int p_nRecordTime);
	
	/************************************************************************
	**概述：
	*		获取录制时长
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录制时长，以秒为单位。
	**功能：
	*       
	************************************************************************/
	int getRecordTime() const;


	/************************************************************************
	**概述：
	*		设置报警事件类型
	**输入：
	*		p_nEventTypeId ：报警事件类型
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	* 
	************************************************************************/
	void setEventTypeId(int p_nEventTypeId);

	/************************************************************************
	**概述：
	*		获取报警事件类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警事件类型
	**功能：
	* 
	************************************************************************/
	int getEventTypeId() const;


	/************************************************************************
	**概述：
	*		设置是否录制音频
	**输入：
	*		p_bIsRecordAudio：录制音频的标志，true表示录制音频，false表示不录制音频
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setEnableRecordAudio(const bool p_bIsRecordAudio);

	/************************************************************************
	**概述：
	*		获取是否录制音频
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录制音频的标志，true表示录制音频，false表示不录制音频
	**功能：       
	*		
	************************************************************************/
	const bool getEnableRecordAudio() const ;


	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objAlarmRecordAction：报警录制行为对象
	**输出：
	*		无
	**返回值：
	*		赋值后的报警录制行为对象
	**功能：
	*		
	*****************************************************************************/
	AlarmRecordAction& operator = (const AlarmRecordAction& p_objAlarmRecordAction);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objAlarmOutAction：AlarmOutAction类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true ：相等
	*		false：不相等
	**功能：
	*		两个AlarmOutAction类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const AlarmRecordAction& p_objAlarmRecordAction) const;

	bool operator < (const AlarmRecordAction& p_objAlarmRecordAction) const;

private:
   
	char	m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];			//设备ID

	int		m_nCameraId;										//摄像机的ID号

	int		m_nPreRecordTime;									//预录时长

	int		m_nRecordTime;										//录制时长

	int		m_nEventTypeId;										//报警事件类型

	bool	m_bIsEnableRecordAudio;								//是否录制音频
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_ALARMRECORDACTION_H_
