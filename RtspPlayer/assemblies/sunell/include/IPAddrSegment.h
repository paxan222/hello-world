#ifndef  _IPADDR_SEGMENT_H
#define  _IPADDR_SEGMENT_H

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

class SN_DLL_API IPAddrSegment
{

public:
	IPAddrSegment(void);
	IPAddrSegment(const IPAddrSegment& p_objIPAddrSegment);
	~IPAddrSegment(void);


	/************************************************************************
	**概述：
	*		设置IP类型
	**输入：
	*		IP类型
	*输出：
	*	  无
	**返回值：
	*	  
	**功能：
	*	  
	************************************************************************/
	void setIPProVer(const int& p_IPProVer);

	/************************************************************************
	**概述：
	*		设置IP类型
	**输入：
	*		
	*输出：
	*	  无
	**返回值：
	*	  IP类型
	**功能：
	*	  
	************************************************************************/
	const int& getIPProVer(void)const;

	/************************************************************************
	**概述：
	*		设置开始IP地址  
	**输入：
	*		开始IP地址  格式如：xxx.xxx.xxx.xxx的点分十进制IP地址字符串
	*输出：
	*	  无
	**返回值：
	*	  true：设置成功
	*	  false：设置失败
	**功能：
	*	  
	************************************************************************/
	bool setBeginIP(const char* p_szBeginIP);


	/************************************************************************
	**概述：
	*		获取开始IP地址
	**输入：
	*		无
	*输出：
	*	  
	**返回值：
	*	  开始IP地址  格式如：xxx.xxx.xxx.xxx的点分十进制IP地址字符串
	**功能：
	*	  
	************************************************************************/
	const char* getBeginIP()const;


	/************************************************************************
	**概述：
	*		设置结束IP地址
	**输入：
	*		结束IP地址  格式如：xxx.xxx.xxx.xxx的点分十进制IP地址字符串
	*输出：
	*	  无
	**返回值：
	*	  true：设置成功
	*	  false：设置失败
	**功能：
	*	  
	************************************************************************/
	bool setEndIP(const char* p_szEndIP);

	/************************************************************************
	**概述：
	*		获取结束IP地址
	**输入：
	*		无
	*输出：
	*	  结束IP地址  格式如：xxx.xxx.xxx.xxx的点分十进制IP地址字符串
	**返回值：
	*	  无
	**功能：
	*	  
	************************************************************************/
	const char* getEndIP()const;


	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		IPAddrSegment类对象
	*输出：
	*	  无
	**返回值：
	*	  IPAddrSegment对象
	**功能：
	*	  
	************************************************************************/
	IPAddrSegment& operator=(const IPAddrSegment& IPAddrSegment);

	/************************************************************************
	**概述：
	*		比较两个地址段对象是否相等
    **输入：
	*		IPAddrSegment类对象
	*输出：
	*	  无
	**返回值：
	*	  true：两个地址相等
	*	  false：两个地址不相等
	**功能：
	*	  若两个地址段中的IP段和IPProVer均相等，则返回true
	*	  若两个地址段中的IP段和IPProVer有一项或多项不相等，返回false。
    ************************************************************************/
	bool operator ==(IPAddrSegment & p_objIPAddrSegment) ;

private:
	int m_nIPProVer ;                         //IP类型
	char m_szBeginIP[CONST_MAXLENGTH_IP + 1];	//起始ip
	char m_szEndIP[CONST_MAXLENGTH_IP + 1];		//结束ip



}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/

#endif //_IPADDR_SEGMENT_H