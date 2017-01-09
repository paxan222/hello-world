#ifndef  _RECORD_QUERY_CONTION_
#define  _RECORD_QUERY_CONTION_


#include "SNPlatOS.h"
#include "DomainConst.h"
#include "TimeStruct.h"
#include "AlarmExType.h"
#include <vector>
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

class SN_DLL_API RecordQueryCondition
{
public:
	RecordQueryCondition(void);
	~RecordQueryCondition(void);

	RecordQueryCondition(const RecordQueryCondition &p_RecordQueryCondition);

public:
	/***********************************************************************
	**������
	*		�����豸Id��
	**���룺
	*		p_pszDeviceId���豸Id
	**�����
	*		��
	**����ֵ��
	*		true	�����óɹ�
	*		false   ������ʧ��
	**���ܣ�
	************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**������
	*		��ȡ�豸Id
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸ID
	**���ܣ�
	*
	***************************************************************************/
	const char* getDeviceId() const;


	/***********************************************************************
	**������
	*		�����豸IP��ַ
	**���룺
	*		p_strDeviceIP���豸IP��ַ
	**�����
	*		��
	**����ֵ��
	*		true	�����óɹ�
	*		false   ������ʧ��
	**���ܣ�
	************************************************************************/
	bool setDeviceIP(const char* p_pszDeviceIP);

	/***********************************************************************
	**������
	*		��ȡ�豸IP��ַ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸IP��ַ
	**���ܣ�
	************************************************************************/
	const char* getDeviceIP() const;


	/************************************************************************
	**������
	*		�����豸ͨ����
	**���룺
	*		p_nCameraId	�豸ͨ����
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setCameraId(int p_nCameraId);

	/************************************************************************
	**������
	*		��ȡ�豸ͨ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸ͨ����
	************************************************************************/
	const int getCameraId() const;


	/************************************************************************
	**������
	*		��ȡ¼��εĿ�ʼʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		¼��ο�ʼʱ��
	************************************************************************/
	const unsigned long getRecordBeginTime() const;
	const TimeStruct& getStructRecordBeginTime() const;

	/************************************************************************
	**������
	*		����¼��εĿ�ʼʱ��
	**���룺
	*		p_nRecordBeginTime :¼��ο�ʼʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setRecordBeginTime(unsigned long p_nRecordBeginTime);
	void setStructRecordBeginTime(const TimeStruct& p_objTime);


	/************************************************************************
	**������
	*		��ȡ¼��εĽ���ʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		¼��ν���ʱ��
	************************************************************************/
	const unsigned long getRecordEndTime() const;
	const TimeStruct& getStructRecordEndTime() const;

	/************************************************************************
	**������
	*		����¼��εĽ���ʱ��
	**���룺
	*		p_nRecordEndTime :¼��ν���ʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setRecordEndTime(unsigned long p_nRecordEndTime);
	void setStructRecordEndTime(const TimeStruct& p_objTime);


	/************************************************************************
	**������
	*		����¼���ļ�����־
	**���룺
	*		p_bLockFile:  true:�����ļ���false�������
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setLockFlag(bool p_bLockFile);

	/************************************************************************
	**������
	*		��ȡ�ļ�����־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		true:�ļ�����
	*		false:�ļ�û�б�����
	************************************************************************/
	const bool getLockFlag() const;


	/************************************************************************
	**������
	*		����¼���ļ�������־
	**���룺
	*		p_bAlarmFile:  true:ֻ��ѯ�����ļ���false�����ļ�
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setAlarmFlag(bool p_bAlarmFile);

	/************************************************************************
	**������
	*		��ȡ�Ƿ񱨾���־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		true:��ѯ����¼��
	*		false:��ѯ����¼��
	************************************************************************/
	const bool getAlarmFlag() const;


	/************************************************************************
	**������
	*		��ȡ¼���ѯ�ֶμ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		¼���ѯ�ֶμ��ʱ��
	************************************************************************/
	const unsigned long getRecordSegmentInterval() const;

	/************************************************************************
	**������
	*		����¼���ѯ����ֶμ��
	**���룺
	*		p_nRecordSegmentInterval :¼�����ֶ�ʱ��������λ��s
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setRecordSegmentInterval(unsigned long p_nRecordSegmentInterval);


	/************************************************************************
	**������
	*		��ȡ¼���ѯʱ�侫��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		¼���ѯʱ�侫��
	************************************************************************/
	const int getRecordQueryTimePrecision() const;

	/************************************************************************
	**������
	*		����¼���ѯʱ�侫��
	**���룺
	*		p_nRecordQueryTimePrecision :¼���ѯʱ�侫�ȣ���λ��s
	*		��С������3s�����1Сʱ
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setRecordQueryTimePrecision(int p_nRecordQueryTimePrecision);

	/************************************************************************
	**������
	*		����¼���ѯ���������б�
	**���룺
	*		p_objAlarmExTypeList :¼���ѯ���������б�
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setAlarmExTypeList(const std::vector<AlarmExType>& p_objAlarmExTypeList);

	/************************************************************************
	**������
	*		��ȡ¼���ѯ���������б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		¼���ѯ���������б�
	************************************************************************/
	const std::vector<AlarmExType>& getAlarmExTypeList() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objRecordQueryCondition ��¼���ѯ������Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	RecordQueryCondition& operator = (const RecordQueryCondition &p_objRecordQueryCondition);

private:
	char				m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];					//�豸id
	char				m_szDeviceIp[CONST_MAXLENGTH_IP + 1];						//�豸IP��ַ
	int					m_nCameraId;												//�豸ͨ����
	unsigned long		m_nRecordBeginTime;											//¼��ο�ʼʱ��
	TimeStruct			m_objRecordBeginTime;										//
	unsigned long		m_nRecordEndTime;											//¼��ν���ʱ��
	TimeStruct			m_objRecordEndTime;											//
	unsigned long		m_nQuerySegmentInterval;									//��ѯ�ֶμ��,�����ʱ���һ�Σ���λs��0:��ʾ���ֶ�
	int					m_nQueryTimePrecision;										//¼���ѯʱ�侫��
	bool				m_bIsLockFile;
	bool				m_bIsAlarm;													//�Ƿ񱨾�
	std::vector<AlarmExType> m_objAlarmExTypeList;										//��������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif  //_RECORD_QUERY_CONTION_

