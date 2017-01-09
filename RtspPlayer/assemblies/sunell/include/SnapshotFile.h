#ifndef  _SNAP_SHOT_FILE
#define  _SNAP_SHOT_FILE

#include "os_define.h"
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

class SN_DLL_API SnapshotFile
{
public:
	SnapshotFile(void);
	~SnapshotFile(void);

	SnapshotFile(const SnapshotFile &p_SnapshotFile);
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
	*		��ȡץ���ļ�ʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ץ���ļ�ʱ�䣬��λ��ms
	************************************************************************/
	const INT64 getSnapshotFileTime() const;
	const TimeStruct& getStructSnapshotFileTime() const;

	/************************************************************************
	**������
	*		����ץ���ļ�ʱ��
	**���룺
	*		p_nSnapshotFileTime :ץ���ļ�ʱ�䣬��λ��ms
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setSnapshotFileTime(INT64 p_nSnapshotFileTime);
	void setStructSnapshotFileTime(const TimeStruct& p_objTime);


	/************************************************************************
	**������
	*		����ץ������
	**���룺
	*		p_nSnapshotType:  ץ������(�μ�SnapshotType.h)
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setSnapshotPolicyType(int p_nSnapshotType);

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
	const int getSnapshotPolicyType() const;
	
	/************************************************************************
	**������
	*		����ץ���ļ���
	**���룺
	*		p_SnapshotFileName��ץ���ļ���
	**�����
	*		��
	**����ֵ��
	*		
	************************************************************************/
	bool setSnapshotFileName(const char *p_SnapshotFileName);

	/************************************************************************
	**������
	*		��ȡץ���ļ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ץ���ļ���
	************************************************************************/
	const char * getSnapshotFileName() const;

	/************************************************************************
	**������
	*		����ץ���ļ�����
	**���룺
	*		p_SnapshotFileLength	ץ���ļ�����
	**�����
	*		��
	**����ֵ��
	*		
	************************************************************************/
	void setSnapshotFileLength(int p_SnapshotFileLength);

	/************************************************************************
	**������
	*		��ȡץ���ļ�����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ץ���ļ�����
	************************************************************************/
	int getSnapshotFileLength() const;

	/************************************************************************
	**������
	*		����ץ�����ļ���־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		
	************************************************************************/
	void  setLockFlag(bool p_LockFlag);

	/************************************************************************
	**������
	*		��ȡץ���ļ��Ƿ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ץ���ļ�����־
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
 	void setAlarmExTypeList(const std::vector<AlarmExType>& p_objAlarmExTypeList);
 	const std::vector<AlarmExType>& getAlarmExTypeList() const;

	SnapshotFile& operator = (const SnapshotFile &p_objSnapshotFile);

private:
	char				m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];					//�豸id
	char				m_szDeviceIp[CONST_MAXLENGTH_IP + 1];						//�豸IP��ַ
	int					m_nCameraId;												//�豸ͨ����
	INT64				m_nSnapshotFileTime;										//ץ��ʱ��
	TimeStruct			m_objSnapshotFileTime;										//
	unsigned long		m_nSnapshotFileLength;										//�ļ�����
	int					m_nSnapshotPolicyType;										//ץ���ļ�����
	char				m_szSnapshotFileName[CONST_MAXLENGTH_FILE_NAME+1];			//�ļ���
	bool				m_bIsLocked;												//�Ƿ����
	std::vector<AlarmExType> m_objAlarmExTypeList;	           //��������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
#endif//_SNAP_SHOT_FILE
