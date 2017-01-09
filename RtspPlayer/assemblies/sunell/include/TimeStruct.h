#ifndef _TIMESTRUCT_H_
#define _TIMESTRUCT_H_

#include "DomainConst.h"
#include "const.h"
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

class SN_DLL_API TimeStruct
{
public:
	TimeStruct(void);
	~TimeStruct(void);

	TimeStruct(const TimeStruct &p_TimeStruct);

public:
	/***********************************************************************
	**概述：
	*		设置时区。
	**输入：
	*		p_nTimeZone：时区
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void setTimeZone(int p_nTimeZone);

	/***********************************************************************
	**概述：
	*		获取时区。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		时区
	************************************************************************/
	const int getTimeZone() const;

	/***********************************************************************
	**概述：
	*		设置夏令营时间。
	**输入：
	*		p_nDaylightSavingTime：夏令营时间
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void setDaylightSavingTime(unsigned short p_nDaylightSavingTime);

	/***********************************************************************
	**概述：
	*		获取夏令时间。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		夏令营时间
	************************************************************************/
	const unsigned short getDaylightSavingTime() const;
	
	/***********************************************************************
	**概述：
	*		设置时间的年。
	**输入：
	*		p_nYear：第几年
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void setYear(unsigned short p_nYear);
	
	/***********************************************************************
	**概述：
	*		获取时间的年。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		年
	************************************************************************/
	const unsigned short getYear() const;
	

	/***********************************************************************
	**概述：
	*		设置时间的月。
	**输入：
	*		p_nMonth：第几月 (1-12)
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void setMonth(unsigned short p_nMonth);

	/***********************************************************************
	**概述：
	*		获取时间的月。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		月
	************************************************************************/
	const unsigned short getMonth() const;
	
	/***********************************************************************
	**概述：
	*		设置时间的日。
	**输入：
	*		p_nMonth：第几日 (1-31)
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void setDay(unsigned short p_nDay);

	/***********************************************************************
	**概述：
	*		获取时间的日。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		日
	************************************************************************/
	const unsigned short getDay() const;

	/***********************************************************************
	**概述：
	*		设置星期几。
	**输入：
	*		p_nDayOfWeek：星期几 (0-6)
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void setDayOfWeek(unsigned short p_nDayOfWeek);

	/***********************************************************************
	**概述：
	*		获取星期几。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		星期几
	************************************************************************/
	const unsigned short getDayOfWeek() const;
	
	/***********************************************************************
	**概述：
	*		设置小时。
	**输入：
	*		p_nHour：小时 (0-24)
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void setHour(unsigned short p_nHour);
	
	/***********************************************************************
	**概述：
	*		获取小时。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		小时
	************************************************************************/
	const unsigned short getHour() const;

	/***********************************************************************
	**概述：
	*		设置分钟。
	**输入：
	*		p_nMinute：分钟 (0-60)
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void setMinute(unsigned short p_nMinute);

	/***********************************************************************
	**概述：
	*		获取分钟。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		分钟
	************************************************************************/
	const unsigned short getMinute() const;

	/***********************************************************************
	**概述：
	*		设置秒。
	**输入：
	*		p_nSecond：秒 (0-60)
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void setSecond(unsigned short p_nSecond);

	/***********************************************************************
	**概述：
	*		获取秒。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		秒
	************************************************************************/
	const unsigned short getSecond() const;

	/***********************************************************************
	**概述：
	*		设置微秒。
	**输入：
	*		p_nMilliseconds：微秒 (0-1000000)
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void setMilliseconds(int p_nMilliseconds);

	/***********************************************************************
	**概述：
	*		获取微秒。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		微秒
	************************************************************************/
	const int getMilliseconds() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objTimeStruct ：时间信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	TimeStruct& operator = (const TimeStruct &p_objTimeStruct);

	//判等函数
	bool operator == (const TimeStruct& p_objTimeStruct) const;
	
	//判断小于函数
	bool operator< (const TimeStruct& p_objTimeStruct) const;
private:
	int				m_nTimeZone;			//时区
	unsigned short	m_nDaylightSavingTime;	//夏令营时
	unsigned short	m_nYear;				//年
	unsigned short 	m_nMonth;				//月[0,11]
	unsigned short 	m_nDay;					//日[1,31]
	unsigned short 	m_nDayOfWeek;			//星期几[0,6]
	unsigned short 	m_nHour;				//时[0,24]
	unsigned short 	m_nMinute;				//分[0,60]
	unsigned short 	m_nSecond;				//秒[0,60]
	int 			m_nMilliseconds;		//微妙[0,1000000]
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_TIMESTRUCT_H_
