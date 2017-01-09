#ifndef _MONITOR_PARAM_
#define _MONITOR_PARAM_

#include "SNPlatOS.h"
#include "DomainConst.h"

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

class SN_DLL_API MonitorParam
{
public:
	MonitorParam(void);
	~MonitorParam(void);

public:
	/************************************************************************
	*	概述：设置监视器编号
	*	输入：
	*		p_nMonitorId	监视器编号
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setMonitorId(int p_nMonitorId);

	/************************************************************************
	*	概述：获取监视器编号
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		监视器编号
	*************************************************************************/
	const int getMonitorId() const;

	/************************************************************************
	*	概述：设置监视器类型
	*	输入：
	*		p_nMonitorType	监视器类型
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setMonitorType(int p_nMonitorType);

	/************************************************************************
	*	概述：获取监视器类型
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		监视器类型
	*************************************************************************/
	const int getMonitorType() const;

	/************************************************************************
	*	概述：设置输出类型
	*	输入：
	*		p_nMonitorResolution 输出类型
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setMonitorResolutionID(int p_nMonitorResolutionID);

	/************************************************************************
	*	概述：获取输出类型
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		输出类型
	*************************************************************************/
	const int getMonitorResolutionID() const;

	MonitorParam& operator = (const MonitorParam& p_MonitorParam);
	bool operator == (const MonitorParam &p_objMonitorParam);

private:
	int		m_nMonitorId;
	int		m_nMonitorType;
	int		m_nMonitorResolutionID;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_MONITORTYPE_
