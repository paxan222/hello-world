#ifndef _ALARMOUTSTATISTIC_H_
#define _ALARMOUTSTATISTIC_H_

#include "SNPlatOS.h"

#ifndef byte
typedef unsigned char byte;
#endif

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

class SN_DLL_API AlarmOutStatistic
{
public:
	enum AlarmOutStatus
	{
		ALARMOUT_NO_ALARMOUT				= 0,		//无报警输出
		ALARMOUT_ALARMOUT					= 1			//有报警输出
	};

public:
	AlarmOutStatistic(void);
	~AlarmOutStatistic(void);

	//拷贝构造函数
	AlarmOutStatistic(const AlarmOutStatistic& p_objAlarmOutStatistic);

public:
	/************************************************************************
	**概述：
	*		设置报警输出通道id号
	**输入：
	*		p_nAlarmOutId：报警输出通道id号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setAlarmOutId(const int p_nAlarmOutId);

	/************************************************************************
	*概述：
	*		获取报警输出通道id号
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		报警输出通道id号
	*功能：       
	*************************************************************************/
	const int getAlarmOutId() const;


	/************************************************************************
	**概述：
	*		设置报警输出通道状态
	**输入：
	*		p_btAlarmOutStatus：报警输出通道状态
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setAlarmOutStatus(const byte p_btAlarmOutStatus);

	/************************************************************************
	*概述：
	*		获取报警输出通道状态
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		报警输出通道状态
	*功能：       
	*************************************************************************/
	const byte getAlarmOutStatus() const;


	/************************************************************************
	**概述：
	*		设置最后报警输出时间
	**输入：
	*		p_nLastAlarmTime：最后报警输出时间
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setLastAlarmTime(const long p_nLastAlarmTime);

	/************************************************************************
	*概述：
	*		获取最后报警输出时间
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		最后报警输出时间
	*功能：       
	*************************************************************************/
	const long getLastAlarmTime() const;

	/************************************************************************
	*概述：
	*		赋值函数
	**输入：
	*		p_objAlarmOutStatistic：报警输出通道信息
	**输出：
	*		无
	**返回值：
	*		DDNS信息
	**功能：
	*
	*************************************************************************/
	AlarmOutStatistic& operator =(const AlarmOutStatistic& p_objAlarmOutStatistic);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objAlarmOutStatistic：AlarmOutStatistic类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个AlarmOutStatistic类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const AlarmOutStatistic& p_objAlarmOutStatistic) const;

	bool operator < (const AlarmOutStatistic& p_objAlarmOutStatistic) const;


private:

	int		m_nAlarmOutId;				//报警输出通道id号

	byte	m_btAlarmOutStatus;			//报警输出通道状态

	long	m_nLastAlarmTime;			//最后报警时间
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_ALARMOUTSTATISTIC_H_
