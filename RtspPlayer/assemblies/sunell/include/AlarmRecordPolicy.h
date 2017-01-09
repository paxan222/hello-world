#ifndef _ALARM_RECORD_POLICY_
#define _ALARM_RECORD_POLICY_

#include "AlarmEvent.h"
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

class SN_DLL_API AlarmRecordPolicy
{
public:
	AlarmRecordPolicy(void);
	~AlarmRecordPolicy(void);

public:
	/************************************************************************
	**������
	*		���ñ���¼���Ƿ�����
	**���룺
	*		p_bIsAlarmRecordOpen �� �Ƿ����ñ�ʾ��true�����ã�false��������
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setAlarmRecordOpenState(const bool p_bIsAlarmRecordOpen);

	/************************************************************************
	**������
	*		��ȡ�жϱ���¼���Ƿ�����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		true ������
	*		false��������
	************************************************************************/
	const bool isAlarmRecordOpened() const;


	/************************************************************************
	**������
	*		���ñ���¼���Ƿ�����
	**���룺
	*		p_bAlarmRecordFileLockedState �� true���������ڴ����������Զ�����
	*		¼�Ƶ��ļ���false��������
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setAlarmRecordFileLockedState(const bool p_bAlarmRecordFileLockedState);

	/************************************************************************
	**������
	*		��ȡ����¼���ļ��Ƿ�������ʶ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		true ������
	*		false��������
	************************************************************************/
	const bool isAlarmRecordFileLocked() const;


	/************************************************************************
	**������
	*		���ñ���¼���Ԥ¼ʱ����ӳ�ʱ�䣨��λΪ�룩
	**���룺
	*		p_nAlarmPreRecordTime �� Ԥ¼ʱ�䣬����������ǰ¼�Ƶ�ʱ��
	*		p_nAlarmDelayRecordTime����¼ʱ�䣬��ֹͣ���������¼�Ƶ�ʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setAlarmRecordTime(const int p_nAlarmPreRecordTime,const int p_nAlarmDelayRecordTime);

	/************************************************************************
	**������
	*		��ñ���¼��Ԥ¼��ʱ�䣨��λΪ�룩
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����¼��Ԥ¼��ʱ��
	************************************************************************/
	const int getAlarmPreRecordTime() const;

	/************************************************************************
	**������
	*		��ñ���¼����¼��ʱ�䣨��λΪ�룩
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����¼����¼��ʱ��
	************************************************************************/
	const int getAlarmDelayRecordTime() const;

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
	*		p_objAlarmRecordPolicy��AlarmRecordPolicy����
	**�����
	*		��
	**����ֵ��
	*		true �����
	*		false�������
	************************************************************************/
	bool operator == (const AlarmRecordPolicy& p_objAlarmRecordPolicy);

private:
	int						 m_nAlarmPreRecordTime;			//����Ԥ¼ʱ��
	int						 m_nAlarmDelayRecordTime;		//������¼ʱ��
	bool					 m_bIsAlarmRecordFileLocked;	//�����ļ��Ƿ�����
	bool					 m_bIsAlarmRecordOpened;		//����¼���Ƿ���
	std::vector<AlarmEvent>	 m_objAlarmEventList;			//�����¼�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_ALARM_RECORD_POLICY_
