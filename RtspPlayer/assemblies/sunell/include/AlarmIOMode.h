#ifndef _ALARM_IO_MODE_H_
#define _ALARM_IO_MODE_H_


#include "DomainConst.h"
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

class SN_DLL_API AlarmIOMode
{
public:
	enum AlarmIOModeType
	{
		ALARMIO_ELECTRIC_TYPE		= 1,   //开关量模式
		ALARMIO_SWITCH_TYPE 		= 2,   //高低电平模式
	};
public:
	AlarmIOMode(void);
	~AlarmIOMode(void);

	AlarmIOMode&  operator =(const AlarmIOMode& p_objAlarmIOMode);

	bool operator ==(const AlarmIOMode& p_objAlarmIOMode);


	/************************************************************************
	** 概述：
	*		设置开关能力集
	**输入：
	*		p_bAlarmIOSwitchMode：开关能力状态
	**输出：
	*	  无
	**返回值：
	*	  无
	************************************************************************/
	void setAlarmIOModeID(int p_nAlarmIOSwitchModeID);
	/************************************************************************
	** 概述：
	*		获取开关力状态
	**输入：
	*		无
	**输出：
	*	  无
	**返回值：
	*	  开关能力集
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