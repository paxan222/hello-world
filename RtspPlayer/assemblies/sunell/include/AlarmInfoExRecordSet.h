#ifndef _ALARMINFOEXRECORDSET_H_
#define _ALARMINFOEXRECORDSET_H_

#include "DomainConst.h"
#include "const.h"
#include "SNPlatOS.h"
#include "TimeStruct.h"

/**********************************************************************/
//�˴����ڿ����ļ������ֽڶ��룬����ʱ����ע�ͼ�������һ�𿽱���
//�������ġ�#ifdef PRAGMA_PACK������ҲҪһ�𿽱�������pragma pack��ջ��ջ��ƥ��
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
	//�豸ID
	bool setDeviceId(const char *p_pszDeviceId);
	const char* getDeviceId() const;
	//�豸IP
	bool setDeviceIP(const char * p_pszDeviceIp);
	const char * getDeviceIP() const;

	//����
	bool setDescription(const char * p_pszDescription);
	const char *getDescription() const;

	//����Դid
	bool setSourceId(const char * p_pszSourceId);
	const char * getSourceId() const;

	//Դ����
	bool setSourceName(const char* p_pszSourceName);
	const char* getSourceName() const;

	//�豸����
	void setDeviceType(int p_nDeviceType);
	int getDeviceType() const;

	//������ʼʱ��
	void setAlarmBeginTime(unsigned long p_nAlarmStartTime);
	const unsigned long getAlarmBeginTime() const;
	void setStructAlarmBeginTime(const TimeStruct& p_objTime);
	const TimeStruct& getStructAlarmBeginTime() const;

	//��������ʱ��
	void setAlarmEndTime(unsigned long p_nAlarmEndTime);
	const unsigned long getAlarmEndTime() const;
	void setStructAlarmEndTime(const TimeStruct& p_objTime);
	const TimeStruct& getStructAlarmEndTime() const;

	//����������
	void setMajorType(int p_nAlarmMajorType);
	int getMajorType() const;

	//����������
	void setMinorType(int p_nAlarmMinorType);
	int getMinorType() const;

	//��ֵ����
	AlarmInfoExRecordSet& operator = (const AlarmInfoExRecordSet &p_objAlarmInfoExRecordSet);

private:
	char			m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];					//�豸ID
	char			m_szDeviceIP[CONST_MAXLENGTH_IP + 1];						//�豸IP
	char			m_szSourceId[CONST_MAXLENGTH_ALARM_SOURCE_ID + 1];			//����ԴID
	char			m_szSourceName[CONST_MAXLENGTH_ALARMSOURCENAME + 1];		//Դ����
	char			m_szDescription[CONST_MAXLENGTH_ALARM_DESCRIPTION + 1];		//����
	int				m_nDeviceType;												//�豸����
	int				m_nMajorType;												//����������
	int				m_nMinorType;												//����С����

	long			m_nAlarmBeginTime;											//������ʼʱ��
	TimeStruct		m_objAlarmBeginTime;										//

	long			m_nAlarmEndTime;											//��������ʱ��
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
