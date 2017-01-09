#ifndef _DDNSPROVIDER_H_
#define _DDNSPROVIDER_H_

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

class SN_DLL_API DDNSProvider
{
public:
	DDNSProvider(void);
	~DDNSProvider(void);

	DDNSProvider(const DDNSProvider& p_objDDNSProvider);

public:

	/************************************************************************
	**概述：
	*		设置提供者id
	**输入：
	*		p_nProviderId：提供者id，一个以‘\0’结尾的字符串，
	**输出：
	*		无
	**返回值：
	*		无
	*功能：
	*	
	************************************************************************/
	void setProviderId(const int p_nProviderId);

	/************************************************************************
	**概述：
	*		获取提供者id
	*输入：
	*		无
	*输出：
	*		无
	**返回值：
	*		提供者id
	**功能：
	*
	*************************************************************************/
	const int getProviderId() const;


	/************************************************************************
	**概述：
	*		设置提供者名称
	**输入：
	*		p_pszProviderName：提供者名称，一个以‘\0’结尾的字符串，
	**输出：
	*		无
	**返回值：
	*		ture ：	设置成功
	*		false ：设备只是
	*功能：
	*		当p_pszProviderName为空时，返回false；
	*		当设置提供者名称成功时，返回true；
	************************************************************************/
	bool setProviderName(const char* p_pszProviderName);

	/************************************************************************
	**概述：
	*		获取提供者名称
	*输入：
	*		无
	*输出：
	*		无
	**返回值：
	*		提供者名称
	**功能：
	*
	*************************************************************************/
	const char* getProviderName() const;

	/************************************************************************
	*概述：
	*		赋值函数
	**输入：
	*		p_objDDNSProvider：提供者信息
	**输出：
	*		无
	**返回值：
	*		提供者信息
	**功能：
	*
	*************************************************************************/
	DDNSProvider& operator =(const DDNSProvider& p_objDDNSProvider);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objDDNSProvider：DDNSProvider类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个DDNSProvider类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const DDNSProvider& p_objDDNSProvider);

private:
	int			m_nProviderId;										//提供者id

	char		m_szProviderName[CONST_MAXLENGTH_DDNS_PROVIDER + 1];	//提供者名称
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DDNSPROVIDER_H_
