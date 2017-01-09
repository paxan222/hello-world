#ifndef IPFILTERPARAM_H_
#define IPFILTERPARAM_H_

#include <vector>
#include "SNPlatOS.h"
#include "IPAddrSegment.h"


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


/*****************************************************
*	概述：IP地址过滤信息类，用于存放IP过滤信息
*				
*	主要功能：
*		保存IP过滤的状态，类型和需要进行过滤的IP列表
************************************************************************/
namespace IPFilterType
{
	enum
	{
		 UNABLE_IP = 1, //禁止
		 ENABLE_IP = 2  //允许
	};
};


class SN_DLL_API IPFilterParam
{
public:
	IPFilterParam(void);
	IPFilterParam(const IPFilterParam &p_objIPFilterParam);
	~IPFilterParam();

public:
	/************************************************************************
	*	概述：设置过滤状态（true：启用过滤，false：不启用过滤）
	*	输入：
	*		p_bEnableFlag  过滤状态
	*	输出：
	*		无
	*	返回值：
	*		无
	*	注意：
	*		无
	*************************************************************************/
	void setEnableFlag(const bool p_bEnableFlag);
	/************************************************************************
	*	概述：获取过滤状态（true：启用过滤，false：不启用过滤）
	*	输入：
	*		无  
	*	输出：
	*		无
	*	返回值：
	*		true  启用过滤
	*		false 不启用过滤
	*	注意：
	*		无
	*************************************************************************/
	bool getEnableFlag()const;
	/************************************************************************
	*	概述：设置过滤类型类型（1：禁止，2：允许）
	*	输入：
	*		p_nFilterType  列表类型类型
	*	输出：
	*		无
	*	返回值：
	*		无
	*	注意：
	*		无
	*************************************************************************/
	void setFilterType(const int p_nFilterType);
	/************************************************************************
	*	概述：获取过滤类型类型（1：禁止，2：允许）
	*	输入：
	*		无  
	*	输出：
	*		无
	*	返回值：
	*		IP列表类型
	*	注意：
	*		无
	*************************************************************************/
	const int getFilterType()const;
	/************************************************************************
	*	概述：设置IP列表
	*	输入：
	*		p_vecIPAddrList  IP列表
	*	输出：
	*		无
	*	返回值：
	*		无
	*	注意：
	*		无
	*************************************************************************/
	void setIPAddrList(const std::vector<IPAddrSegment> &p_vecIPAddrSegmentList);
	/************************************************************************
	*	概述：获取IP列表
	*	输入：
	*		无  
	*	输出：
	*		无
	*	返回值：
	*		IP列表
	*	注意：
	*		无
	*************************************************************************/
	const std::vector<IPAddrSegment> &getIPAddrList() const;

	IPFilterParam& operator=(const IPFilterParam &p_objIPFilterParam);

	bool operator==(const IPFilterParam &p_objIPFilterParam);

private:
	bool m_bEnableFlag;						//是否启用过滤状态
	int m_nFilterType;						//IP列表类型
	std::vector<IPAddrSegment>  m_vecIPAddrSegmentList;  //IP列表
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif