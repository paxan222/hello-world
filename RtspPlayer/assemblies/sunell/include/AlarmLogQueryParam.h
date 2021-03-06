#ifndef _ALARMLOGQUERYPARAM_H_
#define _ALARMLOGQUERYPARAM_H_

#include "DomainConst.h"
#include "const.h"
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

class SN_DLL_API AlarmLogQueryParam
{
public:
	AlarmLogQueryParam();
	~AlarmLogQueryParam();

	//拷贝构造函数
	AlarmLogQueryParam(const AlarmLogQueryParam& p_objAlarmLogQueryParam);

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
	bool setDeviceId(const char *p_pszDeviceId);

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
	*		设置设备IP地址
	**输入：
	*		p_nDeviceIp ：设备IP地址
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	bool setDeviceIp(const char * p_pszDeviceIp);

	/************************************************************************
	**概述：
	*		获取设备IP地址
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		设备IP地址
	**功能：
	*      
	**************************************************************************/
	const char * getDeviceIp() const;


	/**********************************************************************
	**概述：
	*		设置报警源ID
	**输入：
	*		p_pszSourceId ：报警源ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	bool setSourceId(const char * p_pszSourceId);

	/************************************************************************
	**概述：
	*		获取报警源ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警源ID
	**功能：
	*      
	**************************************************************************/
	const char * getSourceId() const;

	/**********************************************************************
	**概述：
	*		设置开始时间
	**输入：
	*		p_nStartTime：开始时间
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setStartTime(const unsigned long p_nStartTime);

	/************************************************************************
	**概述：
	*		获取开始时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		开始时间
	**功能：
	*      
	**************************************************************************/
	unsigned long getStartTime() const;


	/**********************************************************************
	**概述：
	*		设置结束时间
	**输入：
	*		p_nEndTime ：结束时间
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setEndTime(const unsigned long p_nEndTime);

	/************************************************************************
	**概述：
	*		获取结束时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		结束时间
	**功能：
	*      
	**************************************************************************/
	unsigned long getEndTime() const;


	/**********************************************************************
	**概述：
	*		设置报警类型
	**输入：
	*		p_nAlarmType ：报警类型
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setAlarmType(const int p_nAlarmType);

	/************************************************************************
	**概述：
	*		获取报警类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警类型
	**功能：
	*      
	**************************************************************************/
	int getAlarmType() const;


	/**********************************************************************
	**概述：
	*		设置报警主类型
	**输入：
	*		p_nAlarmMajorType ：报警主类型
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setAlarmMajorType(const int p_nAlarmMajorType);

	/************************************************************************
	**概述：
	*		获取报警主类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警主类型
	**功能：
	*      
	**************************************************************************/
	int getAlarmMajorType() const;

	/**********************************************************************
	**概述：
	*		设置报警子类型
	**输入：
	*		p_nAlarmMinorType ：报警子类型
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setAlarmMinorType(const int p_nAlarmMinorType);

	/************************************************************************
	**概述：
	*		获取报警子类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警子类型
	**功能：
	*      
	**************************************************************************/
	int getAlarmMinorType() const;

	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objAlarmLogQueryParam：报警日志查询参数对象
	**输出：
	*		无
	**返回值：
	*		赋值后的报警日志查询参数对象
	**功能：
	*		
	*****************************************************************************/
	AlarmLogQueryParam& operator = (const AlarmLogQueryParam &p_objAlarmLogQueryParam);

private:
	char			m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];		//设备ID

	char			m_szDeviceIp[CONST_MAXLENGTH_IP + 1];				//设备IP
	char			m_szSourceId[CONST_MAXLENGTH_ALARM_SOURCE_ID + 1];	//源ID

	long			m_nStartTime;									//开始时间

	long			m_nEndTime;										//结束时间

	int				m_nAlarmType;									//报警类型(old)
	int				m_nMajorType;									//报警主类型(new)
	int				m_nMinorType;									//报警子类型(new)
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_ALARMLOGQUERYPARAM_H_
