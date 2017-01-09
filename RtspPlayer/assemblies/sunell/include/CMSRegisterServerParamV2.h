#ifndef _CMSRegisterServerParamV2_H_
#define _CMSRegisterServerParamV2_H_

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

class SN_DLL_API CMSRegisterServerParamV2
{
public:
	CMSRegisterServerParamV2();

	~CMSRegisterServerParamV2();

	CMSRegisterServerParamV2(const CMSRegisterServerParamV2 &p_objCMSRegisterServerParamV2);

public:
	/****************************************************************************
	**概述：
	*		设置注册服务器名字
	**输入：
	*	p_pszName ：字符串，最大长度为CONST_MAXLENGTH_CMS_REGISTER_SRV_NAME字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszName长度<=CONST_MAXLENGTH_CMS_REGISTER_SRV_NAME，返回true，
	*	并保存到m_szRegisterSrvName;
	*	若输入p_pszName长度>CONST_MAXLENGTH_CMS_REGISTER_SRV_NAME，返回false
	*****************************************************************************/	
	bool setRegisterSrvName(const char *p_pszName);

	/****************************************************************************
	**概述：
	*		获取注册服务器名字
	**输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存注册服务器名字的m_szRegisterSrvName字符串指针。 
	*功能：
	*	获取保存有注册服务器名字的字符串指针
	*****************************************************************************/
	const char *getRegisterSrvName() const;

	/****************************************************************************
	**概述：
	*		设置注册服务器IP
	**输入：
	*	p_pszIP ：字符串，最大长度为CONST_MAXLENGTH_IP字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszIP长度<=CONST_MAXLENGTH_IP，返回true，
	*	并保存到m_szRegisterSrvIP1;
	*	若输入p_pszIP长度>CONST_MAXLENGTH_IP，返回false
	*****************************************************************************/	
	bool setRegisterSrvIP(const char *p_pszIP);

	/****************************************************************************
	**概述：
	*		获取注册服务器IP
	**输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存注册服务器IP的m_szRegisterSrvIP字符串指针。 
	*功能：
	*	获取保存有注册服务器IP的字符串指针
	*****************************************************************************/
	const char *getRegisterSrvIP() const;

	/****************************************************************************
	**概述：
	*		设置注册服务器端口
	**输入：
	*		p_nPort ：注册服务器端口
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*****************************************************************************/	
	void setRegisterSrvPort(const int p_nPort);

	/****************************************************************************
	**概述：
	*		获取注册服务器端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		返回注册服务器端口。 
	**功能：
	*****************************************************************************/
	const int getRegisterSrvPort() const;

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
	CMSRegisterServerParamV2 &operator =(const CMSRegisterServerParamV2 &p_objCMSRegisterServerParamV2);

private:
	char			m_szRegisterSrvName[CONST_MAXLENGTH_CMS_REGISTER_SRV_NAME + 1];		//注册服务区名字
	char			m_szRegisterSrvIP[CONST_MAXLENGTH_IP + 1];			//注册服务器IP地址
	unsigned short	m_nRegisterSrvPort;								//注册服务器的端口
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/


#endif //_CMSRegisterServerParamV2_H_
