#ifndef  _SNAP_SHOT_FILE_EX_
#define  _SNAP_SHOT_FILE_EX_

#include "os_define.h"
#include "SNPlatOS.h"
#include "DomainConst.h"
#include "TimeStruct.h"
#include "AlarmExType.h"
#include <map>
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

class SN_DLL_API SnapshotFileEx
{
public:
	SnapshotFileEx(void);
	~SnapshotFileEx(void);

	SnapshotFileEx(const SnapshotFileEx &p_SnapshotFile);
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
	const INT64 getSnapshotFileBeginTime() const;
	const INT64 getSnapshotFileEndTime() const;
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
	void setSnapshotFileBeginTime(INT64 p_nSnapshotFileTime);
	void setSnapshotFileEndTime(INT64 p_nSnapshotFileTime);
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
	void setSnapshotAlarmExType(const AlarmExType& p_nSnapshotType);

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
	const AlarmExType& getSnapshotAlarmExType() const;
	
	void setSnapshotCount(int p_nSnapshotCount);
	const int getSnapshotCount() const;
	
	void addSnapshotIndexTime(int p_nIndex,  INT64 p_nTime)
	{
		m_nSnapshotFileTime[p_nIndex]	= p_nTime;
	}

	void clearSnapshotIndexTime()
	{
		m_nSnapshotFileTime.clear();
	}

	const std::map<int, INT64>& getSnapshotIndexTime() const
	{
		return m_nSnapshotFileTime;
	}

	void setSnapshotIndexTime(const std::map<int, INT64>& p_nIndexTime)
	{
		m_nSnapshotFileTime = p_nIndexTime;
	}

	SnapshotFileEx& operator = (const SnapshotFileEx &p_objSnapshotFile);

	friend bool operator<(const SnapshotFileEx &  a, const SnapshotFileEx & b)
	{
		return a.m_nSnapshotFileBeginTime < b.m_nSnapshotFileBeginTime;
	}
private:
	char				m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];					//�豸id
	char				m_szDeviceIp[CONST_MAXLENGTH_IP + 1];						//�豸IP��ַ
	int					m_nCameraId;												//�豸ͨ����
	std::map<int, INT64>	m_nSnapshotFileTime;										//ץ��ʱ��
	INT64				m_nSnapshotFileBeginTime;										//ץ��ʱ��
	INT64				m_nSnapshotFileEndTime;										//ץ��ʱ��
	int					m_nSnapshotPolicyType;										//ץ���ļ�����
	int              m_nSnapshotCount;
  AlarmExType      m_objAlarmType;
	TimeStruct		   m_objSnapshotFileTime;										//
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
#endif//_SNAP_SHOT_FILE_EX_
