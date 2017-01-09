#ifndef _SNAPSHOTPOLICY_H_
#define _SNAPSHOTPOLICY_H_

#include "AlarmSnapshotPolicy.h"
#include "ScheduleSnapshotPolicy.h"
#include "UploadPolicy.h"
#include "VideoResolution.h"
#include "ScheduleTimeParam.h"
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

class SN_DLL_API SnapshotPolicy
{
public:
	enum
	{
		PHOTO_FORMAT_JPG = 1,
		PHOTO_FORMAT_BMP = 2
	};
public:
	SnapshotPolicy(void);
	~SnapshotPolicy(void);

public:
	/************************************************************************
	**�����������豸ID
	*
	**���룺
	*		p_pszDeviceId ���豸ID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		�����豸ID
	************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**��������ȡ�豸ID
	*
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸ID
	**���ܣ�       
	*		��ȡ�豸ID
	************************************************************************/
	const char* getDeviceId() const;

	/************************************************************************
	*	������
	*		������������
	*	���룺
	*		p_nCameraId����������
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	*	������
	*		��ȡ��������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		��������
	************************************************************************/
	const int getCameraId() const;

	/************************************************************************
	*	������
	*		¼�񱣴�����
	*	���룺
	*		p_nSaveDays ��������
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	void setSaveDays(const int p_nSaveDays);

	/************************************************************************
	*	������
	*		��ȡ¼�񱣴�����
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		¼�񱣴�����
	************************************************************************/
	const int getSaveDays() const;

	/************************************************************************
	*	������
	*		����ѭ��д��־
	*	���룺
	*		p_bCycleWriteFlag��ѭ��д��־
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	void setCycleWriteFlag(const bool p_bCycleWriteFlag);

	/************************************************************************
	*	������
	*		��ȡѭ��д��־
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		ѭ��д��־
	************************************************************************/
	const bool getCycleWriteFlag() const;

	/************************************************************************
	*	������
	*		���������־
	*	���룺
	*		p_bIsRedundancy�������־
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	void setIsRedundancy(const bool p_bIsRedundancy);

	/************************************************************************
	*	������
	*		��ȡ�����־
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		�����־
	************************************************************************/
	const bool getIsRedundancy() const;

	/************************************************************************
	*	������
	*		�����ϴ�����
	*	���룺
	*		p_objUploadPolicy���ϴ�����
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	void setUploadPolicy(const UploadPolicy & p_objUploadPolicy);

	/************************************************************************
	*	������
	*		��ȡ�ϴ�����
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		�ϴ�����
	************************************************************************/
	const UploadPolicy & getUploadPolicy() const;

	/************************************************************************
	*	������
	*		���ñ���ץͼ����
	*	���룺
	*		p_objAlarmSnapshotPolicy ����ץͼ����
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	void setAlarmSnapshotPolicy(const AlarmSnapshotPolicy &p_objAlarmSnapshotPolicy);

	/************************************************************************
	*	������
	*		��ȡ����ץͼ����
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		����ץͼ����
	************************************************************************/
	const AlarmSnapshotPolicy & getAlarmSnapshotPolicy() const;

	/************************************************************************
	*	������
	*		���üƻ�ץͼ����
	*	���룺
	*		p_objScheduleSnapshotPolicy �ƻ�ץͼ����
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	void setScheduleSnapshotPolicy(const ScheduleSnapshotPolicy &p_objScheduleSnapshotPolicy);

	/************************************************************************
	*	������
	*		��ȡ�ƻ�ץͼ����
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		�ƻ�ץͼ������
	************************************************************************/
	const ScheduleSnapshotPolicy &getScheduleSnapshotPolicy() const;

public:
	bool operator == (const SnapshotPolicy &p_objSnapshotPolicy);

private:
	char m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];		//�豸ID
	int m_nCameraId;										//��������
	int m_nSaveDays;										//��������
	bool m_bCycleWriteFlag;									//ѭ��д��־
	bool m_bIsRedundancy;									//�Ƿ�����
	AlarmSnapshotPolicy m_objAlarmSnapshotPolicy;			//����ץͼ����
	ScheduleSnapshotPolicy m_objScheduleSnapshotPolicy;		//�ƻ�ץͼ����
	UploadPolicy m_objUploadPolicy;							//�ϴ�����
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif
