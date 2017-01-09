#ifndef _SUNELLDDNSABILITY_H_
#define _SUNELLDDNSABILITY_H_

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

class SN_DLL_API SunellDDNSAbility
{
public:
	SunellDDNSAbility(void);
	~SunellDDNSAbility(void);

	SunellDDNSAbility(const SunellDDNSAbility& p_objSunellDDNSAbility);

	/************************************************************************
	**概述：
	*		设置是否支持景阳DDNS
	*输入：
	*		无
	*输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	*************************************************************************/
	void setSunellDDNSAbility(bool p_bIsSupportSunellDDNS);

	/************************************************************************
	**概述：
	*		获取是否支持景阳DDNS
	*输入：
	*		无
	*输出：
	*		无
	**返回值：
	*		true:支持景阳DDNS
	*		false:不支持景阳DDNS
	**功能：
	*
	*************************************************************************/
	const bool getSunellDDNSAbility(void) const;


	/************************************************************************
	**概述：
	*		设置景阳DDNS的服务器域名参数
	*输入：
	*		p_szSunellDDNSHost：景阳DDNS服务器域名
	*输出：
	*		无
	**返回值：
	*		true:设置成功
	*		false:设置失败
	**功能：
	*
	*************************************************************************/
	bool setSunellDDNSHostName(const char *p_szSunellDDNSHostName);

	/************************************************************************
	**概述：
	*		获取景阳DDNS的服务器域名参数
	*输入：
	*		无
	*输出：
	*		无
	**返回值：
	*		p_szSunellDDNSHost：获取景阳DDNS服务器域名缓存区
	**功能：
	*
	*************************************************************************/
	const char *getSunellDDNSHostName(void) const;

	/************************************************************************
	*概述：
	*		赋值函数
	**输入：
	*		p_objSunellDDNSAbility：是否支持景阳DDNS参数
	**输出：
	*		无
	**返回值：
	*		是否支持景阳DDNS参数
	**功能：
	*
	*************************************************************************/
	SunellDDNSAbility& operator =(const SunellDDNSAbility& p_objSunellDDNSAbility);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objSunellDDNSAbility：SunellDDNSAbility类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个SunellDDNSAbility类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const SunellDDNSAbility& p_objSunellDDNSAbility);

private:

	bool m_bIsSupportSunellDDNS;							//是否支持景阳DDNS
	char m_szSunellDDNSHostName[CONST_MAXLENGTH_DDNS_DOMAINNAME + 1];		//景阳DDNS服务器域名

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_SUNELLDDNSABILITY_H_
