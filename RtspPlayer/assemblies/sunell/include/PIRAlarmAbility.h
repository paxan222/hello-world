#ifndef _PIR_ALARM_ABILITY_H_
#define _PIR_ALARM_ABILITY_H_


#include "SNPlatOS.h"

/**********************************************************************/
//此处用于控制文件编译字节对齐，拷贝时两行注释间内容需一起拷贝，
//结束处的“#ifdef PRAGMA_PACK”部分也要一起拷贝，否则pragma pack入栈出栈不匹配
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
	//设置PIR报警支持标志
	void setPIRAlarmSupportFlag(const bool p_bSupportFlag);
	//获取PIR报警支持标志
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
