#ifndef _I3GPOLICYPARAM_H_
#define _I3GPOLICYPARAM_H_

#include "I3GMessageConnectPolicyParam.h"
#include "I3GTimeConnectPolicyParam.h"
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

class SN_DLL_API I3GPolicyParam
{
public:
	I3GPolicyParam(void);
	~I3GPolicyParam(void);

	//拷贝构造函数
	I3GPolicyParam(const I3GPolicyParam& p_objI3GPolicyParam);

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
	*		设置消息连接策略
	**输入：
	*		p_pobj3GMessageConnectPolicyParam:消息连接策略
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void set3GMessageConnectPolicyParam(const I3GMessageConnectPolicyParam& p_pobj3GMessageConnectPolicyParam);

	/************************************************************************
	**概述：
	*		获取消息连接策略
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		
	************************************************************************/
	const I3GMessageConnectPolicyParam& get3GMessageConnectPolicyParam() const;


	/************************************************************************
	**概述：
	*		设置时间连接策略
	**输入：
	*		p_obj3GTimeConnectPolicyParam：时间连接策略
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void set3GTimeConnectPolicyParam(const I3GTimeConnectPolicyParam& p_obj3GTimeConnectPolicyParam);

	/************************************************************************
	**概述：
	*		获取时间连接策略
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		
	************************************************************************/
	const I3GTimeConnectPolicyParam& get3GTimeConnectPolicyParam() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objI3GPolicyParam：3G策略
	**输出：
	*		无
	**返回值：
	*		3G策略
	**功能：
	************************************************************************/
	I3GPolicyParam& operator =(const I3GPolicyParam& p_objI3GPolicyParam);

private:
	bool								m_bEnableFlag;
	I3GMessageConnectPolicyParam		m_obj3GMessageConnectPolicyParam;	//消息连接策略
	I3GTimeConnectPolicyParam			m_obj3GTimeConnectPolicyParam;		//时间策略

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_I3GPOLICYPARAM_H_
