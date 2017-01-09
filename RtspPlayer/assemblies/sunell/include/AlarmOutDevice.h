#ifndef _ALARMOUTDEVICE_H_
#define _ALARMOUTDEVICE_H_

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

class SN_DLL_API AlarmOutDevice
{
	
public:

	enum AlarmValidSignal
	{
		ALARM_VALID_SIGNAL_CLOSE			= 0,	//继电器闭合
		ALARM_VALID_SIGNAL_OPEN				= 1		//继电器断开
	};

	enum AlarmMode
	{
		ALARMMODE_SWITCH				= 1,		//开关模式
		ALARMMODE_MULTIPLE				= 2			//方波模式
	};

	AlarmOutDevice();

	~AlarmOutDevice();

	//拷贝构造函数
	AlarmOutDevice(const AlarmOutDevice& p_objAlarmOutDevice);

public:

	/************************************************************************
	**概述：
	*		设置报警输出ID号
    **输入：
	*		  p_nAlarmOutId ：报警输出ID号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*      
	************************************************************************/
	void setAlarmOutId(int p_nAlarmOutId);

	/************************************************************************
	**概述：
	*		获取报警输出ID号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警输出ID号
	**功能：
	*       
	**************************************************************************/
	int getAlarmOutId() const;


	/****************************************************************************
	**概述：
	*		设置网络视频设备报警输出名字
    **输入：
	*		p_pszAlarmOutName ：字符串，最大长度为CONST_MAXLENGTH_ALARMOUTPUTNAME字节,
	*		结尾以‘\0’结束。
	**输出：
	*		无
	**返回值：
	*		true： 成功
	* 		false：失败 
	**功能：
	*		若输入p_pszAlarmOutName长度<=CONST_MAXLENGTH_ALARMOUTPUTNAME，返回true，
	*		并保存到m_szAlarmOutName;
	*		若输入p_pszAlarmOutName为NULL或其长度>CONST_MAXLENGTH_ALARMOUTPUTNAME，
	*		返回false
	*****************************************************************************/
	bool setAlarmOutName(const char* p_pszAlarmOutName);
	
	/****************************************************************************
	**概述：
	*		获取DVR设备报警输出名字
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		返回保存DVR设备报警输出名字的m_szAlarmOutName字符串指针。 
	**功能：
	* 		获取保存有DVR设备报警输出名字的字符串指针
	*******************************************************************************/
	const char* getAlarmOutName() const;


	/************************************************************************
	**概述：
	*		设置报警有效信号
	**输入：
	*		p_nAlarmValidSignal：要设置的报警有效信号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setAlarmValidSignal(const int p_nAlarmValidSignal);

	/************************************************************************
	*概述：
	*		获取报警有效信号
	*输出：
	*		无
	*输出：
	*		无
	*返回值：
	*		报警有效信号
	*功能：       
	*************************************************************************/
	int getAlarmValidSignal() const;


	/************************************************************************
	**概述：
	*		设置报警模式
	**输入：
	*		m_nAlarmMode ：要设置的报警模式
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setAlarmMode(const int m_nAlarmMode);

	/************************************************************************
	*概述：
	*		获取报警模式
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		报警模式
	*功能：       
	*************************************************************************/
	int getAlarmMode() const;


	/************************************************************************
	**概述：
	*		设置报警输出频率
	**输入：
	*		p_nAlarmOutFrequency ：要设置的报警输出频率
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setAlarmOutFrequency(const float p_nAlarmOutFrequency);

	/************************************************************************
	*概述：
	*		获取报警输出频率
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		报报警输出频率
	*功能：       
	*************************************************************************/
	float getAlarmOutFrequency() const;


	/************************************************************************
	**概述：
	*		设置报警时长
	**输入：
	*		p_nAlarmTime ：报警时长，以毫秒（ms）为单位,0：一直输出；>0：输出毫秒数
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	**************************************************************************/
	void setAlarmTime(int p_nAlarmTime);


	/************************************************************************
	**概述：
	*		获取报警时长
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警时长
	**功能：
	*		
	**************************************************************************/
	int getAlarmTime() const;

	
	/************************************************************************
	**概述：
	*		设置报警激活开始时间
	**输入：
	*		p_nActivatedStartTime：报警激活开始时间
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setActivatedStartTime(const long p_nActivatedStartTime);

	/************************************************************************
	*概述：
	*		获取报警激活开始时间
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		报警激活开始时间
	*功能：       
	*************************************************************************/
	const long getActivatedStartTime() const;

	/************************************************************************
	**概述：
	*		设置报警激活结束时间
	**输入：
	*		p_nActivatedEndTime：要设置的报警激活结束时间
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setActivatedEndTime(const long p_nActivatedEndTime);

	/************************************************************************
	*概述：
	*		获取报警激活结束时间
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		报警激活结束时间
	*功能：       
	*************************************************************************/
	const long getActivatedEndTime() const ;

	/****************************************************************************
	**概述：
	*			赋值函数
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		true：赋值成功 
	*		true：赋值失败 
	** 功能：
	*		若赋值自身对象成功，返回true
	*		若赋值自身对象失败，返回false
	*****************************************************************************/
	AlarmOutDevice& operator =(const AlarmOutDevice& p_objAlarmOutDevice);

	bool operator == (const AlarmOutDevice& p_objAlarmOutDevice) const;

	bool operator < (const AlarmOutDevice& p_objAlarmOutDevice) const;

private:
	
	int		m_nAlarmOutId;											//报警输出ID号

	char	m_szAlarmOutName[CONST_MAXLENGTH_ALARMOUTNAME + 1];		//报警输出名称

	int		m_nAlarmValidSignal;									//报警有效信号

	int		m_nAlarmMode;											//报警模式
	float	m_nAlarmOutFrequency;									//报警输出频率

	int		m_nAlarmTime;											//报警时长，以毫秒（ms）为单位,0：一直输出；>0：输出毫秒数

	long	m_nActivatedStartTime;									//报警激活开始时间(从00：00到开始时间hh：mm的秒数)
	long	m_nActivatedEndTime;									//报警激活结束时间(从00：00到结束时间hh：mm的秒数)
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_ALARMOUTDEVICE_H_


