#ifndef _CMSEXTERNCONFIGPARAMV2_H_
#define _CMSEXTERNCONFIGPARAMV2_H_

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

class SN_DLL_API CMSExternConfigParamV2
{
public:
	CMSExternConfigParamV2();

	~CMSExternConfigParamV2();

	CMSExternConfigParamV2(const CMSExternConfigParamV2 &p_objCMSExternConfigParamV2);

public:
	/****************************************************************************
	**概述：
	*		设置扩展配置名字
	**输入：
	*	p_pszExternConfigName ：字符串，最大长度为CONST_MAXLENGTH_EXTERN_CONFIG_NAME字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszExternConfigName长度<=CONST_MAXLENGTH_EXTERN_CONFIG_NAME，返回true，
	*	并保存到m_szExternConfigName;
	*	若输入p_pszExternConfigName长度>CONST_MAXLENGTH_EXTERN_CONFIG_NAME，返回false
	*****************************************************************************/	
	bool setExternConfigName(const char *p_pszExternConfigName);

	/****************************************************************************
	**概述：
	*		获取扩展配置名字
	**输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存扩展配置的m_szExternConfigName字符串指针。 
	*功能：
	*	获取保存有扩展配置的字符串指针
	*****************************************************************************/
	const char *getExternConfigName() const;

	/****************************************************************************
	**概述：
	*		设置扩展配置
	**输入：
	*	p_pszExternConfigValue ：字符串，最大长度为CONST_MAXLENGTH_EXTERN_CONFIG字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszExternConfigValue长度<=CONST_MAXLENGTH_EXTERN_CONFIG，返回true，
	*	并保存到m_szExternConfigValue;
	*	若输入p_pszExternConfigValue长度>CONST_MAXLENGTH_EXTERN_CONFIG，返回false
	*****************************************************************************/	
	bool setExternConfigValue(const char *p_pszExternConfigValue);

	/****************************************************************************
	**概述：
	*		获取扩展配置
	**输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存扩展配置的m_szExternConfigValue字符串指针。 
	*功能：
	*	获取保存有扩展配置的字符串指针
	*****************************************************************************/
	const char *getExternConfigValue() const;

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
	CMSExternConfigParamV2 &operator =(const CMSExternConfigParamV2 &p_objCMSExternConfigParamV2);

private:
	char			m_szExternConfigName[CONST_MAXLENGTH_EXTERN_CONFIG_NAME + 1];	//扩展配置名字
	char			m_szExternConfigValue[CONST_MAXLENGTH_EXTERN_CONFIG + 1];		//扩展配置1
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/


#endif //_CMSExternConfigParamV2_H_
