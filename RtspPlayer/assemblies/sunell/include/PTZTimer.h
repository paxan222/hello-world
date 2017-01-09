#ifndef _PTZTIMER_H_
#define _PTZTIMER_H_

#include <string>
#include <vector>
#include "TimeStruct.h"
#include "SNPlatOS.h"
#include "PTZTimerTimeSegment.h"
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

class SN_DLL_API PTZTimer
{
public:
 	enum TIMER_MODE
 	{
 		TIMER_MODE_ONE_TIME			= 1,	//һ��
		TIMER_MODE_EVERDAY			= 2		//ÿ��ѭ��
 	};

	PTZTimer();
	~PTZTimer();

public:
	//�����Ƿ�����
	void setEnableFlag(const bool p_bFlag);
	const bool getEnableFlag() const;

	//����ͨ����
	void setCameraId(const int p_nCameraId);
	const int getCameraId() const;

	//����ʱ��ģʽ��ΪTIMER_MODE ö��֮һ
	void setTimerMode(const int p_nMode);
	const int getTimerMode() const;

	//���ö�ʱ�����ڡ�������ʱ��ģʽΪ��ֻһ��ʱ����Ҫ���ö�ʱ�������ڣ�
	void setTimerDate(const TimeStruct& p_objTimeStruct);
	const TimeStruct & getTimerDate() const;

	//���ö�ʱ��ʱ����б�
	void setTimeSegmentList(const std::vector<PTZTimerTimeSegment>& p_objTimeSegmentList);
	const std::vector<PTZTimerTimeSegment>& getTimeSegmentList() const;

private:
	bool								m_bEnableFlag;						//�Ƿ�����
	int									m_nCameraId;						//����ͷID��
	int									m_nTimerMode;						//ʱ��ģʽ��ΪTIMER_MODEö��֮һ
	TimeStruct							m_objTimerDate;						//����һ��ʱ��ģʽʱ��ʱ������
	std::vector<PTZTimerTimeSegment>	m_objTimeSegmentList;				//��ʱ��ʱ����б�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_PTZTimer_H_

