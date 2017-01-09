#ifndef _CMSREGISTERSERVERPARAM_H_
#define _CMSREGISTERSERVERPARAM_H_

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

class SN_DLL_API CMSRegisterServerParam
{
public:
	CMSRegisterServerParam();

	~CMSRegisterServerParam();
	
	CMSRegisterServerParam(const CMSRegisterServerParam &p_objCMSRegisterServerParam);

public:
	/****************************************************************************
	**概述：
	*		设置注册服务器1IP
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
	bool setRegisterSrvIP1(const char *p_pszIP);

	/****************************************************************************
	**概述：
	*		获取注册服务器1IP
    **输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存注册服务器1IP的m_szRegisterSrvIP1字符串指针。 
	*功能：
	*	获取保存有注册服务器1IP的字符串指针
	*****************************************************************************/
	const char *getRegisterSrvIP1() const;

	/****************************************************************************
	**概述：
	*		设置注册服务器1端口
	**输入：
	*		p_nPort ：注册服务器1端口
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*****************************************************************************/	
	void setRegisterSrvPort1(const int p_nPort);

	/****************************************************************************
	**概述：
	*		获取注册服务器1端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		返回注册服务器1端口。 
	**功能：
	*****************************************************************************/
	const int getRegisterSrvPort1() const;


	/****************************************************************************
	**概述：
	*		设置注册服务器2IP
	**输入：
	*	p_pszRegisterSrvIP2 ：字符串，最大长度为CONST_MAXLENGTH_IP字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszIP长度<=CONST_MAXLENGTH_IP，返回true，
	*	并保存到m_szRegisterSrvIP2;
	*	若输入p_pszIP长度>CONST_MAXLENGTH_IP，返回false
	*****************************************************************************/	
	bool setRegisterSrvIP2(const char *p_pszIP);

	/****************************************************************************
	**概述：
	*		获取注册服务器2IP
	**输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存注册服务器2IP的m_szRegisterSrvIP2字符串指针。 
	*功能：
	*	获取保存有注册服务器2IP的字符串指针
	*****************************************************************************/
	const char *getRegisterSrvIP2() const;

	/****************************************************************************
	**概述：
	*		设置注册服务器2端口
	**输入：
	*		p_nPort ：注册服务器2端口
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*****************************************************************************/	
	void setRegisterSrvPort2(const int p_nPort);

	/****************************************************************************
	**概述：
	*		获取注册服务器2端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		返回注册服务器2端口。 
	**功能：
	*****************************************************************************/
	const int getRegisterSrvPort2() const;


	/****************************************************************************
	**概述：
	*		设置注册服务器3IP
	**输入：
	*	p_pszRegisterSrvIP3 ：字符串，最大长度为CONST_MAXLENGTH_IP字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszIP长度<=CONST_MAXLENGTH_IP，返回true，
	*	并保存到m_szRegisterSrvIP3;
	*	若输入p_pszIP长度>CONST_MAXLENGTH_IP，返回false
	*****************************************************************************/	
	bool setRegisterSrvIP3(const char *p_pszIP);

	/****************************************************************************
	**概述：
	*		获取注册服务器3IP
	**输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存注册服务器3IP的m_szRegisterSrvIP3字符串指针。 
	*功能：
	*	获取保存有注册服务器3IP的字符串指针
	*****************************************************************************/
	const char *getRegisterSrvIP3() const;

	/****************************************************************************
	**概述：
	*		设置注册服务器3端口
	**输入：
	*		p_nPort ：注册服务器3端口
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*****************************************************************************/	
	void setRegisterSrvPort3(const int p_nPort);

	/****************************************************************************
	**概述：
	*		获取注册服务器3端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		返回注册服务器3端口。 
	**功能：
	*****************************************************************************/
	const int getRegisterSrvPort3() const;


	/****************************************************************************
	**概述：
	*		设置注册服务器4IP
	**输入：
	*	p_pszRegisterSrvIP4 ：字符串，最大长度为CONST_MAXLENGTH_IP字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszIP长度<=CONST_MAXLENGTH_IP，返回true，
	*	并保存到m_szRegisterSrvIP4;
	*	若输入p_pszIP长度>CONST_MAXLENGTH_IP，返回false
	*****************************************************************************/	
	bool setRegisterSrvIP4(const char *p_pszIP);

	/****************************************************************************
	**概述：
	*		获取注册服务器4IP
	**输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存注册服务器4IP的m_szRegisterSrvIP4字符串指针。 
	*功能：
	*	获取保存有注册服务器4IP的字符串指针
	*****************************************************************************/
	const char *getRegisterSrvIP4() const;

	/****************************************************************************
	**概述：
	*		设置注册服务器4端口
	**输入：
	*		p_nPort ：注册服务器4端口
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*****************************************************************************/	
	void setRegisterSrvPort4(const int p_nPort);

	/****************************************************************************
	**概述：
	*		获取注册服务器4端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		返回注册服务器4端口。 
	**功能：
	*****************************************************************************/
	const int getRegisterSrvPort4() const;

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
	CMSRegisterServerParam &operator =(const CMSRegisterServerParam &p_objCMSRegisterServerParam);

private:
	char			m_szRegisterSrvIP1[CONST_MAXLENGTH_IP + 1];			//注册服务器IP地址1
	unsigned short	m_nRegisterSrvPort1;								//注册服务器的端口1

	char			m_szRegisterSrvIP2[CONST_MAXLENGTH_IP + 1];			//注册服务器IP地址2
	unsigned short	m_nRegisterSrvPort2;								//注册服务器的端口2

	char			m_szRegisterSrvIP3[CONST_MAXLENGTH_IP + 1];			//注册服务器IP地址3
	unsigned short	m_nRegisterSrvPort3;								//注册服务器的端口3

	char			m_szRegisterSrvIP4[CONST_MAXLENGTH_IP + 1];			//注册服务器IP地址4
	unsigned short	m_nRegisterSrvPort4;								//注册服务器的端口4
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSREGISTERSERVERPARAM_H_
