#ifndef  _PTZTIMERTIMESEGMENT_
#define  _PTZTIMERTIMESEGMENT_

#include "DomainConst.h"
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

class SN_DLL_API PTZTimerTimeSegment
{
public:
	PTZTimerTimeSegment();
	~PTZTimerTimeSegment();
	
	//���ÿ�ʼʱ��
	void setBeginTime(const unsigned long p_nBeginTime);
	const unsigned long getBeginTime() const;

	//���ý���ʱ��
	void setEndTime(const unsigned long p_nEndTime);
	const unsigned long getEndTime() const;

	//������̨����
	bool setPTZOperation(const char* p_pszPTZOperation);
	const char* getPTZOperation() const;
	

	/***********************************************************************
	**������
	*		�еȺ���
	**���룺
	*		p_objPTZTimerTimeSegment��PTZTimerTimeSegment����
	**�����
	*		��
	**����ֵ��
	*		true����ȣ�false������ȡ�
	*���ܣ�
	************************************************************************/
	bool operator == (const PTZTimerTimeSegment &p_objPTZTimerTimeSegment) const;

	PTZTimerTimeSegment& operator=(const PTZTimerTimeSegment& p_objPTZTimerTimeSegment);
private:
	unsigned long	m_nBeginTime;									//��ʼʱ�䣬��00:00��ʼ����ǰʱ�����������01:30Ϊ5400
	unsigned long	m_nEndTime;										//����ʱ�䣬��00:00��ʼ����ǰʱ�����������01:30Ϊ5400
	char			m_szPTZOperation[CONST_MAXLENTH_PTZ_CMD + 1];	//��̨��������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/

#endif



