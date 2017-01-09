#ifndef _SCHEDULE_RECORD_POLICY_
#define _SCHEDULE_RECORD_POLICY_
#include "RecordType.h"
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

class SN_DLL_API ScheduleRecordPolicy
{
public:
	ScheduleRecordPolicy(void);
	~ScheduleRecordPolicy(void);

public:
	/************************************************************************
	**������
	*		���üƻ�¼���Ƿ���
	**���룺
	*		p_bScheduleRecordOpenState���Ƿ�����ʶ�� true�� ������false��������
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setScheduleRecordOpenState(const bool p_bScheduleRecordOpenState);

	/************************************************************************
	**������
	*		�ж��Ƿ����˼ƻ�¼��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		true ��Ϊ����
	*		false��Ϊδ����
	************************************************************************/
	const bool isScheduleRecordOpened() const;


	/************************************************************************
	**������
	*		����¼������
	**���룺
	*		p_nRecordType �� ¼������
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setScheduleRecordType(const int p_nRecordType);

	/************************************************************************
	**������
	*		��ȡ¼������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		¼������
	************************************************************************/
	const int getScheduleRecordType() const;


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
	bool operator == (const ScheduleRecordPolicy &p_objScheduleRecordPolicy);

private:
	bool				m_bIsScheduleRecordOpened;			//�Ƿ���¼��
	int					m_nScheduleRecordType;				//¼������
	ScheduleTimeParam	m_objScheduleTimeParam;				//¼��ʱ�����
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_SCHEDULE_RECORD_POLICY_
