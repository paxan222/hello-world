#ifndef _CMSEXTERNCONFIGPARAM_H_
#define _CMSEXTERNCONFIGPARAM_H_

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

class SN_DLL_API CMSExternConfigParam
{
public:
	CMSExternConfigParam();

	~CMSExternConfigParam();
	
	CMSExternConfigParam(const CMSExternConfigParam &p_objCMSExternConfigParam);

public:
	/****************************************************************************
	**概述：
	*		设置扩展配置1
    **输入：
	*	p_pszExternConfig1 ：字符串，最大长度为CONST_MAXLENGTH_EXTERN_CONFIG字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszExternConfig1长度<=CONST_MAXLENGTH_EXTERN_CONFIG，返回true，
	*	并保存到m_szExternConfig1;
	*	若输入p_pszExternConfig1长度>CONST_MAXLENGTH_EXTERN_CONFIG，返回false
	*****************************************************************************/	
	bool setExternConfig1(const char *p_pszExternConfig1);

	/****************************************************************************
	**概述：
	*		获取扩展配置1
    **输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存扩展配置1的m_szExternConfig1字符串指针。 
	*功能：
	*	获取保存有扩展配置1的字符串指针
	*****************************************************************************/
	const char *getExternConfig1() const;


	/****************************************************************************
	**概述：
	*		设置扩展配置2
	**输入：
	*	p_pszExternConfig2 ：字符串，最大长度为CONST_MAXLENGTH_EXTERN_CONFIG字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszExternConfig2长度<=CONST_MAXLENGTH_EXTERN_CONFIG，返回true，
	*	并保存到m_szExternConfig2;
	*	若输入p_pszExternConfig2长度>CONST_MAXLENGTH_EXTERN_CONFIG，返回false
	*****************************************************************************/	
	bool setExternConfig2(const char *p_pszExternConfig2);

	/****************************************************************************
	**概述：
	*		获取扩展配置2
	**输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存扩展配置2的m_szExternConfig2字符串指针。 
	*功能：
	*	获取保存有扩展配置2的字符串指针
	*****************************************************************************/
	const char *getExternConfig2() const;

	
	/****************************************************************************
	**概述：
	*		设置扩展配置3
	**输入：
	*	p_pszExternConfig3 ：字符串，最大长度为CONST_MAXLENGTH_EXTERN_CONFIG字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszExternConfig3长度<=CONST_MAXLENGTH_EXTERN_CONFIG，返回true，
	*	并保存到m_szExternConfig3;
	*	若输入p_pszExternConfig3长度>CONST_MAXLENGTH_EXTERN_CONFIG，返回false
	*****************************************************************************/	
	bool setExternConfig3(const char *p_pszExternConfig3);

	/****************************************************************************
	**概述：
	*		获取扩展配置3
	**输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存扩展配置3的m_szExternConfig3字符串指针。 
	*功能：
	*	获取保存有扩展配置3的字符串指针
	*****************************************************************************/
	const char *getExternConfig3() const;


	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*****************************************************************************/
	CMSExternConfigParam &operator =(const CMSExternConfigParam &p_objCMSExternConfigParam);

private:

	char			m_szExternConfig1[CONST_MAXLENGTH_EXTERN_CONFIG + 1];		//扩展配置1

	char			m_szExternConfig2[CONST_MAXLENGTH_EXTERN_CONFIG + 1];		//扩展配置2

	char			m_szExternConfig3[CONST_MAXLENGTH_EXTERN_CONFIG + 1];		//扩展配置3
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSEXTERNCONFIGPARAM_H_
