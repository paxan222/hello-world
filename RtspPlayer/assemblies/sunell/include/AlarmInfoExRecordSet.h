#ifndef _ALARMINFOEXRECORDSET_H_
#define _ALARMINFOEXRECORDSET_H_

#include "DomainConst.h"
#include "const.h"
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

class SN_DLL_API AlarmInfoExRecordSet
{
public:
	AlarmInfoExRecordSet();
	~AlarmInfoExRecordSet();
	AlarmInfoExRecordSet(const AlarmInfoExRecordSet& p_objAlarmInfoExRecordSet);

public:
	//设备ID
	bool setDeviceId(const char *p_pszDeviceId);
	const char* getDeviceId() const;
	//设备IP
	bool setDeviceIP(const char * p_pszDeviceIp);
	const char * getDeviceIP() const;

	//描述
	bool setDescription(const char * p_pszDescription);
	const char *getDescription() const;

	//报警源id
	bool setSourceId(const char * p_pszSourceId);
	const char * getSourceId() const;

	//源名称
	bool setSourceName(const char* p_pszSourceName);
	const char* getSourceName() const;

	//设备类型
	void setDeviceType(int p_nDeviceType);
	int getDeviceType() const;

	//触警开始时间
	void setAlarmBeginTime(unsigned long p_nAlarmStartTime);
	const unsigned long getAlarmBeginTime() const;
	void setStructAlarmBeginTime(const TimeStruct& p_objTime);
	const TimeStruct& getStructAlarmBeginTime() const;

	//触警结束时间
	void setAlarmEndTime(unsigned long p_nAlarmEndTime);
	const unsigned long getAlarmEndTime() const;
	void setStructAlarmEndTime(const TimeStruct& p_objTime);
	const TimeStruct& getStructAlarmEndTime() const;

	//报警主类型
	void setMajorType(int p_nAlarmMajorType);
	int getMajorType() const;

	//报警子类型
	void setMinorType(int p_nAlarmMinorType);
	int getMinorType() const;

	//赋值函数
	AlarmInfoExRecordSet& operator = (const AlarmInfoExRecordSet &p_objAlarmInfoExRecordSet);

private:
	char			m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];					//设备ID
	char			m_szDeviceIP[CONST_MAXLENGTH_IP + 1];						//设备IP
	char			m_szSourceId[CONST_MAXLENGTH_ALARM_SOURCE_ID + 1];			//报警源ID
	char			m_szSourceName[CONST_MAXLENGTH_ALARMSOURCENAME + 1];		//源名称
	char			m_szDescription[CONST_MAXLENGTH_ALARM_DESCRIPTION + 1];		//描述
	int				m_nDeviceType;												//设备类型
	int				m_nMajorType;												//报警主类型
	int				m_nMinorType;												//报警小类型

	long			m_nAlarmBeginTime;											//报警开始时间
	TimeStruct		m_objAlarmBeginTime;										//

	long			m_nAlarmEndTime;											//报警结束时间
	TimeStruct		m_objAlarmEndTime;											//
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif 
