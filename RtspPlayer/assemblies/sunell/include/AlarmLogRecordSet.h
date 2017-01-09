#ifndef _AlarmLogRecordSet_H_
#define _AlarmLogRecordSet_H_

#include "DomainConst.h"
#include "const.h"
#include "SNPlatOS.h"

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

class SN_DLL_API AlarmLogRecordSet
{
public:
	AlarmLogRecordSet();
	~AlarmLogRecordSet();
	AlarmLogRecordSet(const AlarmLogRecordSet& p_objAlarmLogRecordSet);

public:
	//�豸ID
	bool setDeviceId(const char *p_pszDeviceId);
	const char* getDeviceId() const;

	//�豸����
	void setDeviceType(const int p_nDeviceType);
	const int getDeviceType() const;

	//�豸IP
	bool setDeviceIp(const char * p_pszDeviceIp);
	const char * getDeviceIp() const;

	//����ʱ��
	void setAlarmTime(const unsigned long p_nAlarmTime);
	unsigned long getAlarmTime() const;

	//������ʼʱ��
	void setAlarmStartTime(const unsigned long p_nAlarmStartTime);
	unsigned long getAlarmStartTime() const;

	//��������ʱ��
	void setAlarmEndTime(const unsigned long p_nAlarmEndTime);
	unsigned long getAlarmEndTime() const;

	//��������
	void setAlarmType(const int p_nAlarmType);
	int getAlarmType() const;

	//����������
	void setAlarmMajorType(const int p_nAlarmMajorType);
	int getAlarmMajorType() const;

	//����������
	void setAlarmMinorType(const int p_nAlarmMinorType);
	int getAlarmMinorType() const;

	//����Դid
	void setAlarmSourceId(const int p_nAlarmSourceId);
	int getAlarmSourceId() const;

	//����Դ����
	bool setAlarmSourceName(const char* p_pszAlarmSourceName);
	const char* getAlarmSourceName() const;

	//����
	bool setAlarmDescription(const char * p_pszDescription);
	const char *getAlarmDescription() const;

	//����Դid
	bool setAlarmSrcId(const char * p_pszDeviceIp);
	const char * getAlarmSrcId() const;

	/************************************************************************
	**������
	*		���û�������
	**���룺
	*		  p_nEventType ����������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*      
	************************************************************************/
	void setEventType(const int p_nEventType);

	/************************************************************************
	**������
	*		��ȡ��������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��������
	**���ܣ�
	*       
	**************************************************************************/
	const int getEventType() const;


	/************************************************************************
	**������
	*		���ñ�������
	**���룺
	*		  p_nAlarmCode ����������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*      
	************************************************************************/
	void setAlarmCode(const int p_nAlarmCode);

	/************************************************************************
	**������
	*		��ȡ��������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��������
	**���ܣ�
	*       
	**************************************************************************/
	const int getAlarmCode() const;


	/************************************************************************
	**������
	*		���ñ�����־
	**���룺
	*		  p_nAlarmSourceId ��������־
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*      
	************************************************************************/
	void setAlarmFlag(const int p_nAlarmFlag);

	/************************************************************************
	**������
	*		��ȡ������־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������־
	**���ܣ�
	*       
	**************************************************************************/
	const int getAlarmFlag() const;

	//��ֵ����
	AlarmLogRecordSet& operator = (const AlarmLogRecordSet &p_objAlarmLogRecordSet);

private:
	char	m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];					//�豸ID

	char	m_szDeviceIp[CONST_MAXLENGTH_IP + 1];						//�豸IP
	
	char	m_szSourceId[CONST_MAXLENGTH_ALARM_SOURCE_ID + 1];			//����ԴID(new)
	char	m_szDescription[CONST_MAXLENGTH_ALARM_DESCRIPTION + 1];		//����

	int		m_nAlarmType;												//��������
	int		m_nMajorType;												//����������(new)
	int		m_nMinorType;												//����С����(new)

	int		m_nAlarmSourceId;											//����ԴID

	char	m_szAlarmSourceName[CONST_MAXLENGTH_ALARMINPUTNAME + 1];	//����Դ����

	long	m_nAlarmTime;												//����ʱ��
	long	m_nStartTime;												//������ʼʱ��(new)
	long	m_nEndTime;													//��������ʱ��(new)


	//////////////////////////////////////////////////////////////////////////
	int		m_nDeviceType;												//�豸����

	int		m_nEventType;												//��������

	int		m_nAlarmCode;												//��������

	int		m_nAlarmFlag;												//������־��1������������0������������

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_AlarmLogRecordSet_H_
