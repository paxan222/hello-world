#ifdef RECORD_INTERFACE
#ifndef _CMSRECORDCENTER_H_
#define _CMSRECORDCENTER_H_

#include "SNPlatOS.h"
#include "RecordDirInfo.h"
#include "AVFrameData.h"
#include "DomainConst.h"
#include <vector>

class TSFrameQueue;
class SNMutex;

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

class SN_DLL_API  CMSRecorder
{
public:
	/***********************************************************************
	*������
	*		���캯��
	*���룺
	*		p_pszDeviceId���豸ID
	*		p_pszDeviceIp���豸IP
	*		p_nCameraId	 ����������
	*�����
	*		��
	*����ֵ��
	*		��
	*���ܣ�
	*		
	************************************************************************/
	CMSRecorder(const char* p_pszDeviceId, const char* p_pszDeviceIp, int p_nCameraId);

	~CMSRecorder();	

public:
	/***********************************************************************
	*������
	*		д¼������
	*���룺
	*		p_objAVFrameData��AVFrameData��������ã���Ƶ���ݡ�
	*�����
	*		��
	*����ֵ��
	*		��
	*���ܣ�
	*		
	************************************************************************/
	int write(const AVFrameData& p_objAVFrameData);


	/***********************************************************************
	*������
	*		��ȡ�豸ID
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		�豸ID
	*���ܣ�
	*		
	************************************************************************/
	const char* getDeviceId();

	/***********************************************************************
	*������
	*		��ȡ�豸IP
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		�豸IP
	*���ܣ�
	*		
	************************************************************************/
	const char* getDeviceIp();

	/***********************************************************************
	*������
	*		��ȡ��������
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		��������
	*���ܣ�
	*		
	************************************************************************/
	int getCameraId();

	/***********************************************************************
	*������
	*		������Ƶ֡����
	*���룺
	*		p_pobjFrameQueue����Ƶ֡���С�
	*�����
	*		��
	*����ֵ��
	*		��
	*���ܣ�
	*		
	************************************************************************/
	void setFrameQueue(TSFrameQueue* p_pobjFrameQueue);

	AVFrameData	* getAVFrameData();

private:
	//�������캯��
	CMSRecorder(const CMSRecorder& p_objObject)
	{
	}

	//��ֵ����
	CMSRecorder& operator = (const CMSRecorder& p_objObject)
	{
		return *this;
	}

private:
	char			m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];		//�豸ID
	char			m_szDeviceIp[CONST_MAXLENGTH_IP + 1];			//�豸IP
	int				m_nCameraId;									//�������ţ���Ƶͨ���ţ�
	TSFrameQueue*		m_pobjFrameQueue;								//��Ƶ֡����
	AVFrameData		m_objAVFrameData;
}_PACKED_1_;

class SN_DLL_API CMSRecordCenter
{
public:
	CMSRecordCenter();

	~CMSRecordCenter();

public:
	/***********************************************************************
	*������
	*		����¼��Ŀ¼
	*���룺
	*		p_objRecordDirInfoList��¼��Ŀ¼�б�
	*�����
	*		��
	*����ֵ��
	*		��
	*���ܣ�
	*		
	************************************************************************/
	void setRecordDirInfoList(const std::vector<RecordDirInfo> &p_objRecordDirInfoList);

public:
	/************************************************************************
	*	������
	*		���һ·¼��ͨ��
	*	���룺
	*		p_pszDeviceId�� �豸ID
	*		p_pszDeviceIp�� �豸IP
	*		p_nCameraId	 �� ��������
	*		p_nSaveDays	 �� ����������-1��������ʱ��ѭ��д��0�����ñ��棬��������ֹͣ¼��>0����������������������������ļ�����ɾ��
	*	�����
	*		��
	*	����ֵ��
	*		�������ɹ���������Ч��¼����ָ�룻
	*		������ʧ�ܣ�����NULL��
	************************************************************************/
	CMSRecorder* openRecord(const char* p_pszDeviceId, const char* p_pszDeviceIp, int p_nCameraId, int p_nDiskGroupId = 1, int p_nSaveDays = -1);

	/************************************************************************
	*	������
	*		�ر�һ·¼��ͨ��
	*	���룺
	*		p_pszDeviceId�� �豸ID
	*		p_pszDeviceIp�� �豸IP
	*		p_nCameraId	 �� ��������
	*	�����
	*		��
	************************************************************************/
	void closeRecord(const char* p_pszDeviceId, const char* p_pszDeviceIp, int p_nCameraId);

	/************************************************************************
	*	������
	*			�ر�����¼��ͨ��
	*	���룺
	*			��
	*	�����
	*			��
	*	����ֵ:
	*			��
	************************************************************************/
	void closeAllRecord();

	/************************************************************************
	*	������
	*		�ж�ָ��ͨ���Ƿ���¼��
	*	���룺
	*		p_pszDeviceId�� �豸ID
	*		p_pszDeviceIp�� �豸IP
	*		p_nCameraId	 �� ��������
	*	�����
	*		��
	*	����ֵ:
	*		������¼�ƣ�����true 
	*		��û��¼�ƣ�����false
	************************************************************************/
	bool isRecording(const char* p_pszDeviceId, const char * p_pszDeviceIp, int p_nCameraId);

private:
	//�������캯��
	CMSRecordCenter(const CMSRecordCenter& p_objObject)
	{
	}

	//��ֵ����
	CMSRecordCenter& operator = (const CMSRecordCenter& p_objObject)
	{
		return *this;
	}
private:
	SNMutex*					m_pobjSNMutex;				//��
	std::vector<CMSRecorder*>	m_objCMSRecorderList;		//¼�����б�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSRECORDCENTER_H_
#endif