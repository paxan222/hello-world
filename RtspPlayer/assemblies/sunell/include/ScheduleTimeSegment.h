#ifndef _SCHEDULETIMESEGMENT_H_
#define _SCHEDULETIMESEGMENT_H_

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


class SN_DLL_API ScheduleTimeSegment
{
public:
	ScheduleTimeSegment();
	ScheduleTimeSegment(unsigned long p_BeginTime,unsigned long p_EndTime);
	~ScheduleTimeSegment();

public:
	/************************************************************************
	**������
	*		���ÿ�ʼʱ��
	**���룺
	*		p_BeginTime ����ʼʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setBeginTime(const unsigned long p_BeginTime);

	/************************************************************************
	**������
	*		��ȡ��ʼʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��ʼʱ��
	**���ܣ�       
	*		
	************************************************************************/
	const unsigned long getBeginTime() const;


	/************************************************************************
	**������
	*		���ý���ʱ��
	**���룺
	*		p_EndTime������ʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setEndTime(const unsigned long p_EndTime);

	/************************************************************************
	**������
	*		��ȡ����ʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ʱ��
	**���ܣ�       
	*		
	************************************************************************/
	const unsigned long getEndTime() const;

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objScheduleTime��ScheduleTime���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true �����
	*		false�������
	**���ܣ�
	*		����ScheduleTime��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const ScheduleTimeSegment& p_objScheduleTime) const;

private:
	unsigned long	m_nBeginTime;		//��ʼʱ��
	unsigned long	m_nEndTime;			//����ʱ��
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_SCHEDULETIMESEGMENT_H_
