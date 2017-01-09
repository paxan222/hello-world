#ifndef _AlarmLogRecordSet_H_
#define _AlarmLogRecordSet_H_

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

class SN_DLL_API AlarmLogRecordSet
{
public:
	AlarmLogRecordSet();
	~AlarmLogRecordSet();
	AlarmLogRecordSet(const AlarmLogRecordSet& p_objAlarmLogRecordSet);

public:
	//设备ID
	bool setDeviceId(const char *p_pszDeviceId);
	const char* getDeviceId() const;

	//设备类型
	void setDeviceType(const int p_nDeviceType);
	const int getDeviceType() const;

	//设备IP
	bool setDeviceIp(const char * p_pszDeviceIp);
	const char * getDeviceIp() const;

	//触警时间
	void setAlarmTime(const unsigned long p_nAlarmTime);
	unsigned long getAlarmTime() const;

	//触警开始时间
	void setAlarmStartTime(const unsigned long p_nAlarmStartTime);
	unsigned long getAlarmStartTime() const;

	//触警结束时间
	void setAlarmEndTime(const unsigned long p_nAlarmEndTime);
	unsigned long getAlarmEndTime() const;

	//报警类型
	void setAlarmType(const int p_nAlarmType);
	int getAlarmType() const;

	//报警主类型
	void setAlarmMajorType(const int p_nAlarmMajorType);
	int getAlarmMajorType() const;

	//报警子类型
	void setAlarmMinorType(const int p_nAlarmMinorType);
	int getAlarmMinorType() const;

	//报警源id
	void setAlarmSourceId(const int p_nAlarmSourceId);
	int getAlarmSourceId() const;

	//报警源名称
	bool setAlarmSourceName(const char* p_pszAlarmSourceName);
	const char* getAlarmSourceName() const;

	//描述
	bool setAlarmDescription(const char * p_pszDescription);
	const char *getAlarmDescription() const;

	//报警源id
	bool setAlarmSrcId(const char * p_pszDeviceIp);
	const char * getAlarmSrcId() const;

	/************************************************************************
	**概述：
	*		设置环境类型
	**输入：
	*		  p_nEventType ：环境类型
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*      
	************************************************************************/
	void setEventType(const int p_nEventType);

	/************************************************************************
	**概述：
	*		获取环境类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		环境类型
	**功能：
	*       
	**************************************************************************/
	const int getEventType() const;


	/************************************************************************
	**概述：
	*		设置报警代码
	**输入：
	*		  p_nAlarmCode ：报警代码
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*      
	************************************************************************/
	void setAlarmCode(const int p_nAlarmCode);

	/************************************************************************
	**概述：
	*		获取报警代码
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警代码
	**功能：
	*       
	**************************************************************************/
	const int getAlarmCode() const;


	/************************************************************************
	**概述：
	*		设置报警标志
	**输入：
	*		  p_nAlarmSourceId ：报警标志
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*      
	************************************************************************/
	void setAlarmFlag(const int p_nAlarmFlag);

	/************************************************************************
	**概述：
	*		获取报警标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警标志
	**功能：
	*       
	**************************************************************************/
	const int getAlarmFlag() const;

	//赋值函数
	AlarmLogRecordSet& operator = (const AlarmLogRecordSet &p_objAlarmLogRecordSet);

private:
	char	m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];					//设备ID

	char	m_szDeviceIp[CONST_MAXLENGTH_IP + 1];						//设备IP
	
	char	m_szSourceId[CONST_MAXLENGTH_ALARM_SOURCE_ID + 1];			//报警源ID(new)
	char	m_szDescription[CONST_MAXLENGTH_ALARM_DESCRIPTION + 1];		//描述

	int		m_nAlarmType;												//报警类型
	int		m_nMajorType;												//报警主类型(new)
	int		m_nMinorType;												//报警小类型(new)

	int		m_nAlarmSourceId;											//报警源ID

	char	m_szAlarmSourceName[CONST_MAXLENGTH_ALARMINPUTNAME + 1];	//报警源名称

	long	m_nAlarmTime;												//报警时间
	long	m_nStartTime;												//报警开始时间(new)
	long	m_nEndTime;													//报警结束时间(new)


	//////////////////////////////////////////////////////////////////////////
	int		m_nDeviceType;												//设备类型

	int		m_nEventType;												//环境类型

	int		m_nAlarmCode;												//报警代码

	int		m_nAlarmFlag;												//报警标志（1：报警产生，0：报警消除）

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_AlarmLogRecordSet_H_
