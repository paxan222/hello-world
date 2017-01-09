#ifndef _ALARM_EVENT_
#define _ALARM_EVENT_

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

class SN_DLL_API AlarmEvent
{
public:
	AlarmEvent(void);
	~AlarmEvent(void);

public:
	/************************************************************************
	**概述：
	*		设置报警主类型
	**输入：
	*		p_nMajorAlarmType 报警类型
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setMajorAlarmType(const int p_nMajorAlarmType);

	/************************************************************************
	**概述：
	*		获取报警主类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警类型
	************************************************************************/
	const int getMajorAlarmType() const;



	/************************************************************************
	**概述：
	*		设置报警子类型
	**输入：
	*		p_nAlarmType 报警类型
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setAlarmType(const int p_nAlarmType);

	/************************************************************************
	**概述：
	*		获取报警子类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警类型
	************************************************************************/
	const int getAlarmType() const;


	/************************************************************************
	**概述：
	*		设置报警ID号
	**输入：
	*		p_nAlarmId 报警ID号
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setAlarmId(const int p_nAlarmId);

	/************************************************************************
	**概述：
	*		获取报警ID号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警ID号
	************************************************************************/
	const int getAlarmId() const;


	/************************************************************************
	**概述：
	*		判等函数
	**输入：
	*		p_objAlarmEvent：对象
	**输出：
	*		无
	**返回值：
	*		true ：相等
	*		false：相等
	************************************************************************/
	bool operator==(const AlarmEvent& p_objAlarmEvent);

private:
	int			m_nMajorAlarmType;		//报警主类型
	int			m_nMinorAlarmType;		//报警子类型
	int			m_nAlarmId;			//报警ID
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif
