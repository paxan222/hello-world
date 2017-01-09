#ifndef _ALARMINFOEXQUERYPARAM_H_
#define _ALARMINFOEXQUERYPARAM_H_

#include "DomainConst.h"
#include "SNPlatOS.h"
#include "TimeStruct.h"

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

class SN_DLL_API AlarmInfoExQueryParam
{
public:
	AlarmInfoExQueryParam(void);
	
	~AlarmInfoExQueryParam(void);

	AlarmInfoExQueryParam(const AlarmInfoExQueryParam &p_AlarmInfoExQueryParam);

public:
	/***********************************************************************
	**概述：
	*		设置设备Id。
	**输入：
	*		p_pszDeviceId：设备Id
	**输出：
	*		无
	**返回值：
	*		true	：设置成功
	*		false   ：设置失败
	**功能：
	************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**概述：
	*		获取设备Id
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

	/***********************************************************************
	**概述：
	*		设置设备IP地址，该接口已经废弃
	**输入：
	*		p_strDeviceIP：设备IP地址
	**输出：
	*		无
	**返回值：
	*		true	：设置成功
	*		false   ：设置失败
	**功能：
	************************************************************************/
	bool setDeviceIP(const char* p_pszDeviceIP);

	/***********************************************************************
	**概述：
	*		获取设备IP地址，该接口已经废弃
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		设备IP地址
	**功能：
	************************************************************************/
	const char* getDeviceIP() const;

	/***********************************************************************
	**概述：
	*		设置源ID
	**输入：
	*		p_pszSourceId：源ID
	**输出：
	*		无
	**返回值：
	*		true	：设置成功
	*		false   ：设置失败
	**功能：
	************************************************************************/
	bool setSourceId(const char* p_pszSourceId);

	/***********************************************************************
	**概述：
	*		获取源ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		源ID
	**功能：
	************************************************************************/
	const char* getSourceId() const;

	/***********************************************************************
	**概述：
	*		设置源名称
	**输入：
	*		p_strSourceName：源名称
	**输出：
	*		无
	**返回值：
	*		true	：设置成功
	*		false   ：设置失败
	**功能：
	************************************************************************/
	bool setSourceName(const char* p_pszSourceName);

	/***********************************************************************
	**概述：
	*		获取源名称
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		源名称
	**功能：
	************************************************************************/
	const char* getSourceName() const;

	/***********************************************************************
	**概述：
	*		设置报警主类型
	**输入：
	*		p_nMajorType：主类型
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void  setMajorType(int p_nMajorType);

	/***********************************************************************
	**概述：
	*		获取报警主类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警主类型
	**功能：
	************************************************************************/
	int getMajorType() const;

	/***********************************************************************
	**概述：
	*		设置报警子类型
	**输入：
	*		p_nMinorType：子类型
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void  setMinorType(int p_nMinorType);

	/***********************************************************************
	**概述：
	*		获取报警子类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警子类型
	**功能：
	************************************************************************/
	int getMinorType() const;

	/***********************************************************************
	**概述：
	*		设置开始时间
	**输入：
	*		p_objTimeStruct：开始时间
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void setAlarmBeginTime(unsigned long p_nAlarmBeginTime);
	void setStructAlarmBeginTime(const TimeStruct& p_objTime);

	/***********************************************************************
	**概述：
	*		获取开始时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		开始时间
	**功能：
	************************************************************************/
	const unsigned long getAlarmBeginTime()const;
	const TimeStruct& getStructAlarmBeginTime() const;

	/***********************************************************************
	**概述：
	*		设置结束时间
	**输入：
	*		p_objTimeStruct：结束时间
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void setAlarmEndTime(unsigned long p_nAlarmEndTime);
	void setStructAlarmEndTime(const TimeStruct& p_objTime);

	/***********************************************************************
	**概述：
	*		获取结束时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		结束时间
	**功能：
	************************************************************************/
	const unsigned long getAlarmEndTime() const;
	const TimeStruct& getStructAlarmEndTime() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objAlarmInfoExQueryParam ：报警查询信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	AlarmInfoExQueryParam& operator = (const AlarmInfoExQueryParam &p_objAlarmInfoExQueryParam);
	
private:
	char				m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//设备编号
	char				m_szDeviceIP[CONST_MAXLENGTH_IP + 1];					//设备IP地址（此参数已经废弃，建议不使用）
	char				m_szSourceId[CONST_MAXLENGTH_ALARM_SOURCE_ID + 1];		//报警源Id
	char				m_szSourceName[CONST_MAXLENGTH_ALARMSOURCENAME + 1];	//源名称
	int					m_nMajorType;											//报警主类型
	int					m_nMinorType;											//报警子类型
	unsigned long		m_nAlarmBeginTime;										//查询开始时间
	TimeStruct			m_objAlarmBeginTime;									//
	unsigned long		m_nAlarmEndTime;										//查询结束时间
	TimeStruct			m_objAlarmEndTime;										//
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif

