#ifndef _CPUSTATISTIC_H_
#define _CPUSTATISTIC_H_

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

class SN_DLL_API CpuStatistic
{
public:
	enum CpuStatus
	{
		CPUSTATUS_NORMAL				= 0,	//正常
		CPUSTATUS_HIGH					= 1		//CPU占用率太高
	};
public:
	CpuStatistic(void);
	~CpuStatistic(void);
	
	//拷贝构造函数
	CpuStatistic(const CpuStatistic& p_objCpuStatistic);

public:

	/************************************************************************
	**概述：
	*		设置cpu使用率
	**输入：
	*		p_fCpuPercent：cpu使用率,如：CPU使用率为45.5%，则此入参为45.5
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setCpuPercent(const float p_fCpuPercent);

	/************************************************************************
	*概述：
	*		获取cpu使用率
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		cpu使用率
	*功能：       
	*************************************************************************/
	const float getCpuPercent() const;


	/************************************************************************
	**概述：
	*		设置cpu工作状态
	**输入：
	*		p_btCpuStatus：cpu工作状态
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setCpuStatus(const byte p_btCpuStatus);

	/************************************************************************
	*概述：
	*		获取cpu工作状态
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		cpu工作状态
	*功能：       
	*************************************************************************/
	const byte getCpuStatus() const;

	/************************************************************************
	*概述：
	*		赋值函数
	**输入：
	*		p_objCpuStatistic：CPU统计信息
	**输出：
	*		无
	**返回值：
	*		CPU统计信息
	**功能：
	*
	*************************************************************************/
	CpuStatistic& operator =(const CpuStatistic& p_objCpuStatistic);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objCpuStatistic：CpuStatistic类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个CpuStatistic类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const CpuStatistic& p_objCpuStatistic);


private:
	float		m_fCpuPercent;				//设备cpu百分比
	byte		m_btCpuStatus;				//设备cpu工作状态
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_CPUSTATISTIC_H_
