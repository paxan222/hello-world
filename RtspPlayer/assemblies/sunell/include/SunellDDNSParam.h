#ifndef _SUNELLDDNSPARAM_H_
#define _SUNELLDDNSPARAM_H_

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

class SN_DLL_API SunellDDNSParam 
{
public:
	SunellDDNSParam(void);
	~SunellDDNSParam(void);

	//拷贝构造函数
	SunellDDNSParam(const SunellDDNSParam& p_objSunellDDNSParam);

public:
	/************************************************************************
	**概述：
	*		设置是否启用DDNS
	**输入：
	*		p_bFlag ：启用DDNS标识
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setDDNSEnableFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取启用DDNS标识
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		启用DDNS表示
	**功能：
	*		
	*************************************************************************/
	const bool getDDNSEnableFlag(void) const;

	/************************************************************************
	**概述：
	*		设置DDNS域名
	**输入：
	*		p_pszDDNSDomainName：网络视频设备DDNS域名，一个以‘\0’结尾的字符串，
	**输出：
	*		无
	**返回值：
	*		ture ：	设置成功
	*		false： 设置失败
	*功能：
	*		当p_pszDDNSDomainName为空时，返回false
	*		当设置DDNS域名成功时，返回true
	************************************************************************/
	bool setDDNSDomainName(const char *p_pszDDNSDomainName);

	/************************************************************************
	*概述：
	*		获取DDNS域名
	**输入：
	*		无
	**输出：
	*	无
	**返回值：
	*		DDNS的域名
	**功能：
	*
	*************************************************************************/
	const char *getDDNSDomainName(void) const;

	/************************************************************************
	**概述：
	*		设置DDNS绑定的网卡名
	*输入：
	*		p_pszDDNSNetworkCardName：网络视频设备DDNS绑定的网卡名，一个以‘\0’结尾的字符串，
	**输出：
	*		无
	**返回值：
	*		ture ：	设置成功
	*		false： 设置失败
	*功能：
	*		当p_pszDDNSNetworkCardName为空时，返回false
	*		当设置DDNS密码成功时，返回true
	************************************************************************/
	bool setDDNSNetWorkCardName(const char *p_pszDDNSNetworkCardName);

	/************************************************************************
	**概述：
	*		获取DDNS绑定的网卡名
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		DDNS绑定的网卡名
	*功能：
	*
	*************************************************************************/
	const char *getDDNSNetWorkCardName(void) const;

	/************************************************************************
	*概述：
	*		赋值函数
	**输入：
	*		p_objSunellDDNSParam：DDNS信息
	**输出：
	*		无
	**返回值：
	*		DDNS信息
	**功能：
	*
	*************************************************************************/
	SunellDDNSParam& operator =(const SunellDDNSParam& p_objSunellDDNSParam);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objSunellDDNSParam：SunellDDNSParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个SunellDDNSParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const SunellDDNSParam& p_objSunellDDNSParam);

	/****************************************************************************
	**概述：
	*		复位，将成员变量恢复初始默认值
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		将成员变量恢复初始默认值
	*****************************************************************************/
	void reset(void);

private:

	bool			m_bDDNSEnableFlag;											//是否启用DDNS的状态（true：启用，false：不启用）

	char			m_szDDNSDomainName[CONST_MAXLENGTH_DDNS_DOMAINNAME + 1];	//DDNS域名	

	char			m_szNetWorkCardName[CONST_NETWORK_CARD_NAME + 1];			//绑定的网卡名

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_SUNELLDDNSPARAM_H_