#ifndef _ALARMINSTATISTIC_H_
#define _ALARMINSTATISTIC_H_

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

class SN_DLL_API AlarmInStatistic
{
public:
	enum AlarmInStatus
	{
		ALARMIN_NO_ALARM				= 0,		//�ޱ���
		ALARMIN_ALARM					= 1			//�б���
	};

public:
	AlarmInStatistic(void);
	~AlarmInStatistic(void);

	//�������캯��
	AlarmInStatistic(const AlarmInStatistic& p_objAlarmInStatistic);

public:
	/************************************************************************
	**������
	*		���ñ�������ͨ��id��
	**���룺
	*		p_nAlarmInId����������ͨ��id��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setAlarmInId(const int p_nAlarmInId);

	/************************************************************************
	*������
	*		��ȡ��������ͨ��id��
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		������
	*���ܣ�       
	*************************************************************************/
	const int getAlarmInId() const;


	/************************************************************************
	**������
	*		���ñ�������ͨ��״̬
	**���룺
	*		p_btAlarmInStatus����������ͨ��״̬
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setAlarmInStatus(const byte p_btAlarmInStatus);

	/************************************************************************
	*������
	*		��ȡ��������ͨ��״̬
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		��������ͨ��״̬
	*���ܣ�       
	*************************************************************************/
	const byte getAlarmInStatus() const;


	/************************************************************************
	**������
	*		������󱨾�����ʱ��
	**���룺
	*		p_nLastAlarmTime����󱨾�����ʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setLastAlarmTime(const long p_nLastAlarmTime);

	/************************************************************************
	*������
	*		��ȡ��󱨾�����ʱ��
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		��󱨾�����ʱ��
	*���ܣ�       
	*************************************************************************/
	const long getLastAlarmTime() const;

	/************************************************************************
	*������
	*		��ֵ����
	**���룺
	*		p_objAlarmInStatistic����������ͨ����Ϣ
	**�����
	*		��
	**����ֵ��
	*		DDNS��Ϣ
	**���ܣ�
	*
	*************************************************************************/
	AlarmInStatistic& operator =(const AlarmInStatistic& p_objAlarmInStatistic);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objAlarmInStatistic��AlarmInStatistic���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����AlarmInStatistic��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const AlarmInStatistic& p_objAlarmInStatistic) const;

	bool operator < (const AlarmInStatistic& p_objAlarmInStatistic) const;


private:

	int		m_nAlarmInId;				//��������ͨ��id��

	byte	m_btAlarmInStatus;			//��������ͨ��״̬

	long	m_nLastAlarmTime;			//��󱨾�����ʱ��
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_ALARMINSTATISTIC_H_
