#ifndef _ALARMINSTATISTIC_H_
#define _ALARMINSTATISTIC_H_

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

class SN_DLL_API AlarmInStatistic
{
public:
	enum AlarmInStatus
	{
		ALARMIN_NO_ALARM				= 0,		//无报警
		ALARMIN_ALARM					= 1			//有报警
	};

public:
	AlarmInStatistic(void);
	~AlarmInStatistic(void);

	//拷贝构造函数
	AlarmInStatistic(const AlarmInStatistic& p_objAlarmInStatistic);

public:
	/************************************************************************
	**概述：
	*		设置报警输入通道id号
	**输入：
	*		p_nAlarmInId：报警输入通道id号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setAlarmInId(const int p_nAlarmInId);

	/************************************************************************
	*概述：
	*		获取报警输入通道id号
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		比特率
	*功能：       
	*************************************************************************/
	const int getAlarmInId() const;


	/************************************************************************
	**概述：
	*		设置报警输入通道状态
	**输入：
	*		p_btAlarmInStatus：报警输入通道状态
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setAlarmInStatus(const byte p_btAlarmInStatus);

	/************************************************************************
	*概述：
	*		获取报警输入通道状态
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		报警输入通道状态
	*功能：       
	*************************************************************************/
	const byte getAlarmInStatus() const;


	/************************************************************************
	**概述：
	*		设置最后报警输入时间
	**输入：
	*		p_nLastAlarmTime：最后报警输入时间
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setLastAlarmTime(const long p_nLastAlarmTime);

	/************************************************************************
	*概述：
	*		获取最后报警输入时间
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		最后报警输入时间
	*功能：       
	*************************************************************************/
	const long getLastAlarmTime() const;

	/************************************************************************
	*概述：
	*		赋值函数
	**输入：
	*		p_objAlarmInStatistic：报警输入通道信息
	**输出：
	*		无
	**返回值：
	*		DDNS信息
	**功能：
	*
	*************************************************************************/
	AlarmInStatistic& operator =(const AlarmInStatistic& p_objAlarmInStatistic);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objAlarmInStatistic：AlarmInStatistic类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个AlarmInStatistic类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const AlarmInStatistic& p_objAlarmInStatistic) const;

	bool operator < (const AlarmInStatistic& p_objAlarmInStatistic) const;


private:

	int		m_nAlarmInId;				//报警输入通道id号

	byte	m_btAlarmInStatus;			//报警输入通道状态

	long	m_nLastAlarmTime;			//最后报警输入时间
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_ALARMINSTATISTIC_H_
