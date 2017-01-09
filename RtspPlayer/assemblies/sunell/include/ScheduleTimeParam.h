#ifndef _SCHEDULETIMEPARAM_H_
#define _SCHEDULETIMEPARAM_H_

#include "DomainConst.h"
#include "ScheduleTimeSegment.h"
#include <vector>
#include "SNPlatOS.h"

using namespace std;

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


class SN_DLL_API ScheduleTime
{
public:
	ScheduleTime();
	~ScheduleTime();
	
	//�������캯��
	ScheduleTime(const ScheduleTime& p_objScheduleTime);

public:
	/************************************************************************
	**������
	*		���ÿ�ʼʱ��
	**���룺
	*		p_nStartTime ����ʼʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setStartTime(const long p_nStartTime);

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
	const long getStartTime() const;


	/************************************************************************
	**������
	*		���ý���ʱ��
	**���룺
	*		p_nEndTime������ʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setEndTime(const long p_nEndTime);

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
	const long getEndTime() const;


	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objScheduleTime���ƻ�ʱ�����
	**�����
	*		��
	**����ֵ��
	*		��ֵ��ļƻ�ʱ�����
	**���ܣ�
	*		
	*****************************************************************************/
	ScheduleTime& operator =(const ScheduleTime& p_objScheduleTime);

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
	bool operator == (const ScheduleTime& p_objScheduleTime) const;

	bool operator < (const ScheduleTime& p_objScheduleTime) const;

private:
	long	m_nStartTime;		//��ʼʱ��
	long	m_nEndTime;			//����ʱ��
}_PACKED_1_;

class SN_DLL_API ScheduleWeek
{
public:
	enum WeekDay
	{
		SUNDAY		= 0,	//������
		MONDAY		= 1,	//����һ
		TUESDAY		= 2,	//���ڶ�
		WEDNESDAY	= 3,	//������
		THURSDAY	= 4,	//������
		FRIDAY		= 5,	//������
		SATURDAY	= 6		//������
	};

public:
	ScheduleWeek();
	~ScheduleWeek();

	//�������캯��
	ScheduleWeek(const ScheduleWeek& p_objScheduleWeek);

public:
	/************************************************************************
	**������
	*		�������ڼ�
	**���룺
	*		p_nWeekDay�����ڼ�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setWeekDay(const int p_nWeekDay);

	/************************************************************************
	**������
	*		��ȡ���ڼ�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���ڼ�
	**���ܣ�       
	*		
	************************************************************************/
	const int getWeekDay() const;


	/************************************************************************
	**������
	*		���üƻ�ʱ��
	**���룺
	*		p_objScheduleTimeList���ƻ�ʱ��
	**�����
	*		��
	**����ֵ��
	*		
	**���ܣ�       
	*		
	************************************************************************/
	void setScheduleTimeList(const vector<ScheduleTime>& p_objScheduleTimeList);

	/************************************************************************
	**������
	*		��ȡ�ƻ�ʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�ƻ�ʱ��
	**���ܣ�       
	*		
	************************************************************************/
	vector<ScheduleTime>* getScheduleTimeList() const;


	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objScheduleWeek��ÿ��ƻ�ʱ�����
	**�����
	*		��
	**����ֵ��
	*		��ֵ���ÿ��ƻ�ʱ�����
	**���ܣ�
	*		
	*****************************************************************************/
	ScheduleWeek& operator =(const ScheduleWeek& p_objScheduleWeek);

	bool operator == (const ScheduleWeek& p_objScheduleWeek) const;

	bool operator < (const ScheduleWeek& p_objScheduleWeek) const;

private:
	int							m_nWeekDay;						//���ڼ�
	vector<ScheduleTime>		m_objScheduleTimeList;			//¼��ʱ���б�
}_PACKED_1_;

class SN_DLL_API ScheduleTimeParam
{
public:
	ScheduleTimeParam();
	~ScheduleTimeParam();

	//�������캯��
	ScheduleTimeParam(const ScheduleTimeParam& p_objScheduleTimeParam);

public:
	/************************************************************************
	**������
	*		�����豸ID��
	**���룺
	*		p_pszDeviceId���豸ID��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**������
	*		��ȡ�豸ID��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸ID��
	**���ܣ�       
	*		
	************************************************************************/
	const char* getDeviceId() const;


	/************************************************************************
	**������
	*		���������ID��
	**���룺
	*		p_nCameraId�������ID��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**������
	*		��ȡ�����ID��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�����ID��
	**���ܣ�       
	*		
	************************************************************************/
	const int getCameraId() const;
	

	/************************************************************************
	**������
	*		���üƻ�ʱ��
	**���룺
	*		p_objScheduleWeekList���ƻ�ʱ��
	**�����
	*		��
	**����ֵ��
	*		
	**���ܣ�       
	*		
	************************************************************************/
	void setScheduleWeekList(const vector<ScheduleWeek>& p_objScheduleWeekList);

	/************************************************************************
	**������
	*		��ȡ�ƻ�ʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�ƻ�ʱ��
	**���ܣ�       
	*		
	************************************************************************/
	vector<ScheduleWeek>* getScheduleWeekList() const;


	/************************************************************************
	**������
	*		���üƻ�ʱ����б�
	**���룺
	*		p_objScheduleTimeSegmentList���ƻ�ʱ����б�
	**�����
	*		��
	**����ֵ��
	*		
	**���ܣ�       
	*		
	************************************************************************/
	void setScheduleTimeSegmentList(const vector<ScheduleTimeSegment>& p_objScheduleTimeSegmentList);

	/************************************************************************
	**������
	*		��ȡ�ƻ�ʱ����б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�ƻ�ʱ����б�
	**���ܣ�       
	*		
	************************************************************************/
	vector<ScheduleTimeSegment>* getScheduleTimeSegmentList() const;

	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objScheduleTimeParam���ƻ�¼��ʱ�����
	**�����
	*		��
	**����ֵ��
	*		��ֵ��ļƻ�¼��ʱ�����
	**���ܣ�
	*		
	*****************************************************************************/
	ScheduleTimeParam& operator =(const ScheduleTimeParam& p_objScheduleTimeParam);

	bool operator < (const ScheduleTimeParam& p_objScheduleTimeParam) const;

private:

	char						m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];		//�豸ID

	int							m_nCameraId;									//�����ID

	vector<ScheduleWeek>		m_objScheduleWeekList;							//ÿ��ƻ�ʱ������б�

	vector<ScheduleTimeSegment>	m_objScheduleTimeSegmentList;					//�ƻ�ʱ��ζ����б�(����ʱ��)
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_SCHEDULETIMEPARAM_H_
