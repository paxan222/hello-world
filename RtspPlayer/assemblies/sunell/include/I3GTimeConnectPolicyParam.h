#ifndef _I3GTIMECONNECTPOLICYPARAM_H_
#define _I3GTIMECONNECTPOLICYPARAM_H_

#include "ScheduleTimeParam.h"
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

class SN_DLL_API I3GTimeConnectPolicyParam
{
public:
	//报警类型
	enum
	{
		ONLINE_MODE_ALWAYS						= 1,	//7*24小时
		ONLINE_MODE_SCHEDULE					= 2		//计划
	};

public:
	I3GTimeConnectPolicyParam(void);
	~I3GTimeConnectPolicyParam(void);

	//拷贝构造函数
	I3GTimeConnectPolicyParam(const I3GTimeConnectPolicyParam& p_objI3GTimeConnectPolicyParam);
public:

	
	/************************************************************************
	**概述：
	*		设置启用标志
	**输入：
	*		p_bEnableFlag:启用标志
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setEnableFlag(const bool p_bEnableFlag);

	/************************************************************************
	**概述：
	*		获取启用标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		
	************************************************************************/
	const bool getEnableFlag() const;

	/************************************************************************
	**概述：
	*		设置在线模式
	**输入：
	*		p_bEnableFlag：在线模式
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setOnlineMode(const int p_nOnlineMode);

	/************************************************************************
	**概述：
	*		获取在线模式
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		
	************************************************************************/
	const int getOnlineMode() const;

	/************************************************************************
	**概述：
	*		设置计划时间
	**输入：
	*		p_objScheduleTimeParam：计划时间
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setScheduleTimeParam(const ScheduleTimeParam& p_objScheduleTimeParam);

	/************************************************************************
	**概述：
	*		获取计划时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		计划时间
	************************************************************************/
	const ScheduleTimeParam& getScheduleTimeParam() const ;


	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objI3GTimeConnectPolicyParam：时间策略
	**输出：
	*		无
	**返回值：
	*		3G策略
	**功能：
	************************************************************************/
	I3GTimeConnectPolicyParam& operator =(const I3GTimeConnectPolicyParam& p_objI3GTimeConnectPolicyParam);

private:
	bool				m_bEnableFlag;								//启用标志

	int					m_nOnlineMode;								//在线模式
	ScheduleTimeParam	m_objScheduleTimeParam;						//计划时间
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_I3GTIMECONNECTPOLICYPARAM_H_
