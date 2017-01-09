#ifndef _RECORD_SUMMARY_INFO_
#define _RECORD_SUMMARY_INFO_
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

class SN_DLL_API RecordSummaryInfo
{
public:
	RecordSummaryInfo(void);
	~RecordSummaryInfo(void);
	RecordSummaryInfo(const RecordSummaryInfo &p_objRecordSummaryInfo);
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
	*		��ȡ¼��ʼʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		¼��ʼʱ��
	************************************************************************/
	const unsigned long getRecordBeginTime() const;

	/************************************************************************
	**������
	*		����¼��ʼʱ��
	**���룺
	*		p_RecordBeginTime	����¼��ʼʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setRecordBeginTime(const unsigned long p_RecordBeginTime);

	/************************************************************************
	**������
	*		��ȡ¼�����ʱ��
	**���룺
	*		��
	**�����
	*		
	**����ֵ��
	*		¼�����ʱ��
	************************************************************************/
	const unsigned long getRecordEndTime() const;

	/************************************************************************
	**������
	*		����¼�����ʱ��
	**���룺
	*		p_nRecordBeginTime	����¼�����ʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setRecordEndTime(const unsigned long p_RecordEndTime);

	/************************************************************************
	**������
	*		��ȡ¼��ʼʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��ȡ¼��ʼʱ��
	************************************************************************/
	const TimeStruct &getRecordBeginTimeStruct() const;

	/************************************************************************
	**������
	*		����¼��ʼʱ��
	**���룺
	*		p_stRecordBeginTime	�豸¼��ʼʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setRecordBeginTimeStruct(const TimeStruct &p_stRecordBeginTime);
	
	/************************************************************************
	**������
	*		����¼�����ʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��ȡ¼�����ʱ��
	************************************************************************/
	const TimeStruct &getRecordEndTimeStruct() const;

	/************************************************************************
	**������
	*		����¼�����ʱ��
	**���룺
	*		p_stRecordEndTime	�豸¼�����ʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setRecordEndTimeStruct(const TimeStruct &p_stRecordEndTime);

	RecordSummaryInfo& operator = (const RecordSummaryInfo &p_objRecordSummaryInfo);

private:
	char						m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];					//�豸id
	char						m_szDeviceIp[CONST_MAXLENGTH_IP + 1];						//�豸IP��ַ
	int							m_nCameraId;												//�豸ͨ����
	unsigned long				m_RecordBeginTime;
	unsigned long				m_RecordEndTime;
	TimeStruct					m_stRecordBeginTime;
	TimeStruct					m_stRecordEndTime;
};
 
/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
 
#endif  //_RECORD_SUMMARY_INFO_
