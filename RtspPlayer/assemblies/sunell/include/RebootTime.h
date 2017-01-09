#ifndef REBOOTTIME_H
#define REBOOTTIME_H
#include <vector>
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

/*************************************************************
*重启时间类使用说明：
*	目前支持按年重启，按月重启，按周重启，按天重启
*按年重启：
*	需要设置月份、日期和秒数
*按月重启：
*	需要设置日期和秒数，不能设置月份
*按周重启：
*	需要设置星期几重启和秒数，是否设置月份和日期不影响按周重启
*按天重启：
*	需要设置秒数，且不能设置月份、日期和星期几重启
*备注：
*	按周重启和按年、按月重启是互补影响的。即，如果重启时间的4个参数均有设置且有效
*那么设备即会按年重启，也会按周重启。即到了设置的每年的几月几号几点，设备会重启；
*到了设置的每周几的几点，社会也会重启。
**************************************************************/

using std::vector;

class SN_DLL_API RebootTime
{
public:
	RebootTime(void);
	~RebootTime(void);

public:
	/*************************************************************
	*	概述：设置在哪一月重启
	*	输入：
	*		p_nMonth				重启月份
	*	输出：
	*		无
	*	返回值：
	*		0		设置成功
	*		-1		设置失败
	*	功能：
	*		1、重启月份的值的有效范围为1~12，不设置默认值为0
	*		2、按年重启时，需要设置该项
	**************************************************************/
	int setMonth(const int p_nMonth);
	const int getMonth() const;

	/*************************************************************
	*	概述：设置在哪一天重启
	*	输入：
	*		p_nDay				重启日期
	*	输出：
	*		无
	*	返回值：
	*		0		设置成功
	*		-1		设置失败
	*	功能：
	*		1、重启日期的值的有效范围为1~31，不设置默认值为0
	*		2、按年、按月重启时，需要设置该项
	**************************************************************/
	int setDay(const int p_nDay);
	const int getDay() const;

	/*************************************************************
	*	概述：设置星期几重启
	*	输入：
	*		p_nWeekday				星期几重启
	*	输出：
	*		无
	*	返回值：
	*		0		设置成功
	*		-1		设置失败
	*	功能：
	*		1、星期几重启的值的有效范围为0~6，0为星期天，不设置默认值为-1
	*		2、按周重启时，需要设置该项
	**************************************************************/
	int setWeekday(const int p_nWeekday);
	const int getWeekday() const;

	/*************************************************************
	*	概述：设置在该天的第几秒重启
	*	输入：
	*		p_nWeekday				重启秒数
	*	输出：
	*		无
	*	返回值：
	*		0		设置成功
	*		-1		设置失败
	*	功能：
	*		1、重启秒数的值的有效范围为0~86399，不设置默认值为-1
	*		2、定时重启生效，该项必须设置
	**************************************************************/
	int setSecond(const int p_nSecond);
	const int getSecond() const;

	RebootTime& operator = (const RebootTime& p_other);
	bool operator == (const RebootTime& p_other);
private:
	int m_nMonth;
	int m_nDay;
	int m_nWeekday;
	int m_nSecond;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/

#endif