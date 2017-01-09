#ifndef _ALARM_IO_MODE_H_
#define _ALARM_IO_MODE_H_


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

class SN_DLL_API AlarmIOMode
{
public:
	enum AlarmIOModeType
	{
		ALARMIO_ELECTRIC_TYPE		= 1,   //������ģʽ
		ALARMIO_SWITCH_TYPE 		= 2,   //�ߵ͵�ƽģʽ
	};
public:
	AlarmIOMode(void);
	~AlarmIOMode(void);

	AlarmIOMode&  operator =(const AlarmIOMode& p_objAlarmIOMode);

	bool operator ==(const AlarmIOMode& p_objAlarmIOMode);


	/************************************************************************
	** ������
	*		���ÿ���������
	**���룺
	*		p_bAlarmIOSwitchMode����������״̬
	**�����
	*	  ��
	**����ֵ��
	*	  ��
	************************************************************************/
	void setAlarmIOModeID(int p_nAlarmIOSwitchModeID);
	/************************************************************************
	** ������
	*		��ȡ������״̬
	**���룺
	*		��
	**�����
	*	  ��
	**����ֵ��
	*	  ����������
	************************************************************************/
	const int getAlarmIOModeID(void) const;

private:
	int m_nAlarmIOModeID;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/

#endif //_ALARM_IO_MODE_H_