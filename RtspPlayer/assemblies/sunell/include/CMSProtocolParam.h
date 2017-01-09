#ifndef _CMSPROTOCOLPARAM_H_
#define _CMSPROTOCOLPARAM_H_

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

class SN_DLL_API CMSProtocolParam
{
public:
	CMSProtocolParam();

	~CMSProtocolParam();
	
	CMSProtocolParam(const CMSProtocolParam &p_objCMSProtocolParam);

public:
	/****************************************************************************
	**概述：
	*		设置协议名称
    **输入：
	*	p_pszProtocolName ：字符串，最大长度为CONST_MAXLENTH_PROTOCOL_NAME字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszProtocolName长度<=CONST_MAXLENTH_PROTOCOL_NAME，返回true，
	*	并保存到m_szProtocolName;
	*	若输入p_pszProtocolName长度>CONST_MAXLENTH_PROTOCOL_NAME，返回false
	*****************************************************************************/	
	bool setProtocolName(const char *p_pszProtocolName);

	/****************************************************************************
	**概述：
	*		获取协议名称
    **输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存协议名称的m_szProtocolName字符串指针。 
	*功能：
	*	获取保存有协议名称的字符串指针
	*****************************************************************************/
	const char *getProtocolName() const;


	/****************************************************************************
	**概述：
	*		设置协议版本
    **输入：
	*	p_pszProtocolVersion ：字符串，最大长度为CONST_MAXLENTH_PROTOCOL_VERSION字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszProtocolVersion长度<=CONST_MAXLENTH_PROTOCOL_VERSION，返回true，
	*	并保存到m_szProtocolVersion;
	*	若输入p_pszProtocolVersion长度>CONST_MAXLENTH_PROTOCOL_VERSION，返回false
	*****************************************************************************/	
	bool setProtocolVersion(const char *p_pszProtocolVersion);

	/****************************************************************************
	**概述：
	*		获取协议版本
    **输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存协议版本的m_szProtocolVersion字符串指针。 
	**功能：
	*	获取保存有协议版本的字符串指针
	*****************************************************************************/
	const char *getProtocolVersion() const;


	/****************************************************************************
	**概述：
	*		设置协议软件版本
	**输入：
	*	p_pszProtocolSoftwareVersion ：字符串，最大长度为CONST_MAXLENTH_PROTOCOL_SOFTWARE_VERSION字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszProtocolSoftwareVersion长度<=CONST_MAXLENTH_PROTOCOL_SOFTWARE_VERSION，返回true，
	*	并保存到m_szProtocolSoftwareVersion;
	*	若输入p_pszProtocolSoftwareVersion长度>CONST_MAXLENTH_PROTOCOL_SOFTWARE_VERSION，返回false
	*****************************************************************************/	
	bool setProtocolSoftwareVersion(const char *p_pszProtocolSoftwareVersion);

	/****************************************************************************
	**概述：
	*		获取协议软件版本
	**输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存协议软件版本的m_szProtocolSoftwareVersion字符串指针。 
	**功能：
	*	获取保存有协议软件版本的字符串指针
	*****************************************************************************/
	const char *getProtocolSoftwareVersion() const;

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
	CMSProtocolParam &operator =(const CMSProtocolParam &p_objCMSProtocolParam);

private:
	char			m_szProtocolName[CONST_MAXLENTH_PROTOCOL_NAME + 1];							//协议名称

	char			m_szProtocolVersion[CONST_MAXLENTH_PROTOCOL_VERSION + 1];					//协议版本

	char			m_szProtocolSoftwareVersion[CONST_MAXLENTH_PROTOCOL_SOFTWARE_VERSION + 1];	//协议软件版本
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSPROTOCOLPARAM_H_
