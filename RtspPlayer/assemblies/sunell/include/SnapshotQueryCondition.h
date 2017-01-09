#ifndef  _SNAPSHOT_QUERY_CONDITION_
#define  _SNAPSHOT_QUERY_CONDITION_

#include "SNPlatOS.h"
#include "DomainConst.h"
#include "os_define.h"
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

class  SN_DLL_API  SnapshotQueryCondition
{
public:
	SnapshotQueryCondition(void);
	~SnapshotQueryCondition(void);

	SnapshotQueryCondition(const SnapshotQueryCondition &p_RecordQueryCondition);

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
	*		��ȡץ�ĵĿ�ʼʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ץ�ĵĿ�ʼʱ�䣬��λ��ms
	************************************************************************/
	const INT64 getQueryBeginTime() const;
	const TimeStruct& getStructQueryBeginTime() const;

	/************************************************************************
	**������
	*		����ץ�Ĳ�ѯ�Ŀ�ʼʱ��
	**���룺
	*		p_nRecordBeginTime :ץ�Ĳ�ѯ�Ŀ�ʼʱ�䣬��λ��ms
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setQueryBeginTime(INT64 p_nQueryBeginTime);
	void setStructQueryBeginTime(const TimeStruct& p_objTime);


	/************************************************************************
	**������
	*		��ȡץ�Ĳ�ѯ�Ľ���ʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ץ�Ĳ�ѯ����ʱ�䣬��λ��ms
	************************************************************************/
	const INT64 getQueryEndTime() const;
	const TimeStruct& getStructQueryEndTime() const;

	/************************************************************************
	**������
	*		����ץ�ĵĽ���ʱ��
	**���룺
	*		p_nQueryEndTime :ץ�ĵĽ���ʱ��,��λ��ms
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setQueryEndTime(INT64 p_nQueryEndTime);
	void setStructQueryEndTime(const TimeStruct& p_objTime);


	/************************************************************************
	**������
	*		����ץ������
	**���룺
	*		p_nSnapshotType:  ץ������
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setSnapshotType(int p_nSnapshotType);

	/************************************************************************
	**������
	*		��ȡץ������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ץ������
	************************************************************************/
	const int getSnapshotType() const;

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
	*		����ץ�������
	**���룺
	*		p_nSnapshotFlag:  true:������false������
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setLockFlag(bool p_nSnapshotFlag);

	/************************************************************************
	**������
	*		��ȡץ���Ƿ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		true���ļ���
	*		false:û������־
	************************************************************************/
	const bool getLockFlag() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objSnapshotQueryCondition ��ץ�Ĳ�ѯ������Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	SnapshotQueryCondition& operator = (const SnapshotQueryCondition &p_objSnapshotQueryCondition);

private:
	char				m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];					//�豸id
	char				m_szDeviceIp[CONST_MAXLENGTH_IP + 1];						//�豸IP��ַ
	int					m_nCameraId;												//�豸ͨ����
	INT64				m_nQueryBeginTime;											//¼��ο�ʼʱ��
	TimeStruct			m_objQueryBeginTime;										//
	INT64				m_nQueryEndTime;											//¼��ν���ʱ��
	TimeStruct			m_objQueryEndTime;											//
	int					m_nSnapshotType;											//ץ������
	bool				m_bIsLockFile;												//�Ƿ����
    std::vector<AlarmExType> m_objAlarmExTypeList;	                                //��������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_SNAPSHOT_QUERY_CONDITION_
