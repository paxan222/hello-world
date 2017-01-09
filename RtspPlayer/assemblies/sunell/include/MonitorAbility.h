#ifndef _MONITORABILITY_
#define _MONITORABILITY_
#include "SNPlatOS.h"
#include "MonitorType.h"
#include <vector>

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

/************************************************************************
*	概述：监视器能力信息。
*	主要包含以下信息：监视器编号，监视器输出类型列表
************************************************************************/
class SN_DLL_API MonitorAbility
{
public:
	MonitorAbility(void);
	~MonitorAbility(void);

public:
	/************************************************************************
	*	概述：
	*		设置监视器编号
	*	输入：
	*		p_MonitorId	监视器编号
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setMonitorId(int p_MonitorId);

	/************************************************************************
	*	概述：
	*		获取监视器编号
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		监视器编号
	************************************************************************/
	int getMonitorId() const;

	/************************************************************************
	*	概述：
	*		设置监视器类型列表
	*	输入：
	*		p_MonitorTypeList	监视器类型列表
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setMonitorTypeList(const std::vector<MonitorType> &p_MonitorTypeList);

	/************************************************************************
	*	概述：
	*		获取监视器类型列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		监视器类型列表
	************************************************************************/
	const std::vector<MonitorType> &getMonitorTypeList() const;

	MonitorAbility& operator = (const MonitorAbility& p_objMonitorAbility);

private:
	int							m_MonitorId;
	std::vector<MonitorType>	m_MonitorTypeList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_MONITORABILITY_
