#ifdef RECORD_INTERFACE
#ifndef _CMSRECORDCENTERV2_H_
#define _CMSRECORDCENTERV2_H_

#include "SNPlatOS.h"
#include "RecordDirInfo.h"
#include "DeviceInfoEx.h"
#include <vector>

class Recorder;
class CMSRecordCenter;
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

class SN_DLL_API CMSRecordCenterV2
{
public:
	CMSRecordCenterV2();

	~CMSRecordCenterV2();

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
	int openRecord(const DeviceInfoEx &p_objDeviceInfoEx, const int p_nCameraId, const int p_nStreamId, const int p_nDiskGroupId = 1, const int p_nSaveDays = -1);

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
	void closeRecord(const char* p_pszDeviceId, const char* p_pszDeviceIp, const int p_nCameraId);

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

	//����¼����
	Recorder* findRecorder(const char* p_pszDeviceId, const char * p_pszDeviceIp, const int p_nCameraId);

	//�������캯��
	CMSRecordCenterV2(const CMSRecordCenterV2& p_objObject)
	{
	}

	//��ֵ����
	CMSRecordCenterV2& operator = (const CMSRecordCenterV2& p_objObject)
	{
		return *this;
	}
private:
	SNMutex*					m_pobjSNMutex;				//��
	std::vector<Recorder*>		m_objRecorderList;		//¼�����б�
	CMSRecordCenter*			m_pobjCMSRecordCenter;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSRECORDCENTERV2_H_
#endif