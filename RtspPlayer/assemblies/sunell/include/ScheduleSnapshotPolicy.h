#ifndef _SCHEDULE_SNAPSHOT_POLICY_
#define _SCHEDULE_SNAPSHOT_POLICY_

#include "ScheduleTimeParam.h"
#include "SnapshotParameter.h"
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

class SN_DLL_API ScheduleSnapshotPolicy
{
public:
	enum
	{
		ALWAYS = 1,		//7*24Сʱץ��
		SCHEDULE = 2,	//�ƻ�ץ��
	};

public:
	ScheduleSnapshotPolicy(void);
	~ScheduleSnapshotPolicy(void);

public:
	/************************************************************************
	**������
	*		���üƻ�ץͼ�Ƿ���
	**���룺
	*		p_bScheduleSnapshotOpenState���Ƿ�����ʶ�� true�� ������false��������
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setScheduleSnapshotOpenState(const bool p_bScheduleSnapshotOpenState);

	/************************************************************************
	**������
	*		�ж��Ƿ����˼ƻ�ץͼ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		true ��Ϊ����
	*		false��Ϊδ����
	************************************************************************/
	const bool isScheduleSnapshotOpened() const;

	/************************************************************************
	**������
	*		���üƻ�����
	**���룺
	*		p_nScheduleType �� �ƻ�����
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setScheduleType(const int p_nScheduleType);

	/************************************************************************
	**������
	*		��ȡ�ƻ�����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�ƻ�����
	************************************************************************/
	const int getScheduleType() const;

	/************************************************************************
	**������
	*		����ץ�Ĳ���
	**���룺
	*		p_SnapshotParameter ץ�Ĳ���
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setSnapshotParameter(const SnapshotParameter &p_SnapshotParameter);

	/************************************************************************
	**������
	*		��ȡץ�Ĳ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ץ�Ĳ���
	************************************************************************/
	const SnapshotParameter &getSnapshotParameter() const;

	/************************************************************************
	**������
	*		���üƻ�ʱ���ʱ�����
	**���룺
	*		p_objScheduleTimeParam �ƻ�ʱ���ʱ�����
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setScheduleTimeParam(const ScheduleTimeParam &p_objScheduleTimeParam);

	/************************************************************************
	**������
	*		��ȡ�ƻ�ʱ���ʱ�����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�ƻ�ʱ��Ĳ���
	************************************************************************/
	const ScheduleTimeParam &getScheduleTimeParam() const;

public:
	bool operator == (const ScheduleSnapshotPolicy &p_objScheduleSnapshotPolicy);

private:
	bool				m_bIsScheduleSnapshotOpened;			//�Ƿ���ץͼ
	int					m_nScheduleType;						//�ƻ�����
	SnapshotParameter	m_SnapshotParameter;					//ץ�Ĳ���
	ScheduleTimeParam	m_objScheduleTimeParam;					//ץͼʱ�����
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_SCHEDULE_Snapshot_POLICY_
