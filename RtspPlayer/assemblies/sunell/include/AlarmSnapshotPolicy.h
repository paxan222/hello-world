#ifndef _ALARMSNAPSHOTPOLICY_H_
#define _ALARMSNAPSHOTPOLICY_H_

#include "AlarmEvent.h"
#include "SnapshotParameter.h"
#include <vector>
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

class SN_DLL_API AlarmSnapshotPolicy
{
public:
	AlarmSnapshotPolicy(void);
	~AlarmSnapshotPolicy(void);

public:
	/************************************************************************
	**������
	*		���ñ���ץͼ�Ƿ�����
	**���룺
	*		p_bIsAlarmSnapshotOpen �� �Ƿ����ñ�ʾ��true�����ã�false��������
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setAlarmSnapshotOpenState(const bool p_bIsAlarmSnapshotOpen);

	/************************************************************************
	**������
	*		��ȡ�жϱ���ץͼ�Ƿ�����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		true ������
	*		false��������
	************************************************************************/
	const bool isAlarmSnapshotOpened() const;

	/************************************************************************
	**������
	*		���ñ���ץͼ�Ƿ�����
	**���룺
	*		p_bAlarmSnapshotFileLockedState �� true���������ڴ����������Զ�����
	*		¼�Ƶ��ļ���false��������
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setAlarmSnapshotFileLockedState(const bool p_bAlarmSnapshotFileLockedState);

	/************************************************************************
	**������
	*		��ȡ����ץͼ�ļ��Ƿ�������ʶ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		true ������
	*		false��������
	************************************************************************/
	const bool isAlarmSnapshotFileLocked() const;

	/************************************************************************
	**������
	*		���ñ���ץͼ��Ԥץʱ����ӳ�ʱ�䣨��λΪ�룩
	**���룺
	*		p_nAlarmPreSnapshotTime �� Ԥץʱ�䣬����������ǰץͼ��ʱ��
	*		p_nAlarmDelaySnapshotTime����ץʱ�䣬��ֹͣ���������ץͼ��ʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setAlarmSnapshotTime(const int p_nAlarmPreSnapshotTime,const int p_nAlarmDelaySnapshotTime);

	/************************************************************************
	**������
	*		��ñ���ץͼԤץ��ʱ�䣨��λΪ�룩
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ץͼԤץ��ʱ��
	************************************************************************/
	const int getAlarmPreSnapshotTime() const;

	/************************************************************************
	**������
	*		��ñ���ץͼ������ʱ�䣨��λΪ�룩
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ץͼ������ʱ��
	************************************************************************/
	const int getAlarmDelaySnapshotTime() const;

	/************************************************************************
	**������
	*		���ñ���ץ�Ĳ���
	**���룺
	*		p_SnapshotParameter	����ץ�Ĳ���
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setSnapshotParameter(const SnapshotParameter &p_SnapshotParameter);

	/************************************************************************
	**������
	*		��ñ���ץ�Ĳ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ץ�Ĳ���
	************************************************************************/
	const SnapshotParameter &getSnapshotParameter() const;

	/************************************************************************
	**������
	*		���ñ����¼��б�
	**���룺
	*		p_objAlarmEventList �������¼��б�
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setAlarmEventList(std::vector<AlarmEvent>& p_objAlarmEventList);

	/************************************************************************
	**������
	*		��ӱ����¼�
	**���룺
	*		p_objAlarmEvent �� �����¼�
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void addAlarmEvent(const AlarmEvent& p_objAlarmEvent);

	/************************************************************************
	**������
	*		��ȡ�����¼��б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�����¼��б�
	************************************************************************/
	const std::vector<AlarmEvent>& getAlarmEventList() const;

public:
	/************************************************************************
	**������
	*		�еȺ���
	**���룺
	*		p_objAlarmSnapshotPolicy��AlarmSnapshotPolicy����
	**�����
	*		��
	**����ֵ��
	*		true �����
	*		false�������
	************************************************************************/
	bool operator == (const AlarmSnapshotPolicy& p_objAlarmSnapshotPolicy);

private:
	int						 m_nDelaySnapshotTime;				//ץ������ʱ�� ��λΪ��
	int						 m_nPreSnapshotTime;				//ץ��Ԥץʱ�� ��λΪ��
	bool					 m_bIsAlarmSnapshotFileLocked;		//����ץ���ļ��Ƿ�����
	bool					 m_bIsAlarmSnapshotOpened;			//����ץ���Ƿ���
	SnapshotParameter		 m_SnapshotParameter;				//����ץ�Ĳ���
	std::vector<AlarmEvent>	 m_objAlarmEventList;				//�����¼�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_ALARM_RECORD_POLICY_
