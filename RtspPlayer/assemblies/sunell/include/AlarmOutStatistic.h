#ifndef _ALARMOUTSTATISTIC_H_
#define _ALARMOUTSTATISTIC_H_

#include "SNPlatOS.h"

#ifndef byte
typedef unsigned char byte;
#endif

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

class SN_DLL_API AlarmOutStatistic
{
public:
	enum AlarmOutStatus
	{
		ALARMOUT_NO_ALARMOUT				= 0,		//�ޱ������
		ALARMOUT_ALARMOUT					= 1			//�б������
	};

public:
	AlarmOutStatistic(void);
	~AlarmOutStatistic(void);

	//�������캯��
	AlarmOutStatistic(const AlarmOutStatistic& p_objAlarmOutStatistic);

public:
	/************************************************************************
	**������
	*		���ñ������ͨ��id��
	**���룺
	*		p_nAlarmOutId���������ͨ��id��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setAlarmOutId(const int p_nAlarmOutId);

	/************************************************************************
	*������
	*		��ȡ�������ͨ��id��
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		�������ͨ��id��
	*���ܣ�       
	*************************************************************************/
	const int getAlarmOutId() const;


	/************************************************************************
	**������
	*		���ñ������ͨ��״̬
	**���룺
	*		p_btAlarmOutStatus���������ͨ��״̬
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setAlarmOutStatus(const byte p_btAlarmOutStatus);

	/************************************************************************
	*������
	*		��ȡ�������ͨ��״̬
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		�������ͨ��״̬
	*���ܣ�       
	*************************************************************************/
	const byte getAlarmOutStatus() const;


	/************************************************************************
	**������
	*		������󱨾����ʱ��
	**���룺
	*		p_nLastAlarmTime����󱨾����ʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setLastAlarmTime(const long p_nLastAlarmTime);

	/************************************************************************
	*������
	*		��ȡ��󱨾����ʱ��
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		��󱨾����ʱ��
	*���ܣ�       
	*************************************************************************/
	const long getLastAlarmTime() const;

	/************************************************************************
	*������
	*		��ֵ����
	**���룺
	*		p_objAlarmOutStatistic���������ͨ����Ϣ
	**�����
	*		��
	**����ֵ��
	*		DDNS��Ϣ
	**���ܣ�
	*
	*************************************************************************/
	AlarmOutStatistic& operator =(const AlarmOutStatistic& p_objAlarmOutStatistic);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objAlarmOutStatistic��AlarmOutStatistic���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����AlarmOutStatistic��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const AlarmOutStatistic& p_objAlarmOutStatistic) const;

	bool operator < (const AlarmOutStatistic& p_objAlarmOutStatistic) const;


private:

	int		m_nAlarmOutId;				//�������ͨ��id��

	byte	m_btAlarmOutStatus;			//�������ͨ��״̬

	long	m_nLastAlarmTime;			//��󱨾�ʱ��
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_ALARMOUTSTATISTIC_H_
