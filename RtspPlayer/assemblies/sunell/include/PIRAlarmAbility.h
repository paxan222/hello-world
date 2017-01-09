#ifndef _PIR_ALARM_ABILITY_H_
#define _PIR_ALARM_ABILITY_H_


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

/************************************************************************/
/* add: weihuiquam
/* why: for PIR Alarm
/* date:2014.09.04
/************************************************************************/

class SN_DLL_API PIRAlarmAbility
{
public:
	PIRAlarmAbility(void);
	~PIRAlarmAbility(void);

public:
	//����PIR����֧�ֱ�־
	void setPIRAlarmSupportFlag(const bool p_bSupportFlag);
	//��ȡPIR����֧�ֱ�־
	const bool getPIRAlarmSupportFlag() const;

private:
	bool m_bPIRSupportFlag;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/

#endif //_PIR_ALARM_ABILITY_H_
