#ifndef _USERPARAM_H_
#define _USERPARAM_H_

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

class SN_DLL_API UserParam
{
public:
	UserParam(void);
	~UserParam(void);

	//拷贝构造函数
	UserParam(const UserParam& p_objUserParam);

public:

	/****************************************************************************
	**概述：
	*		设置用户名
	**输入：
	*		p_pszUserName ：用户名,结尾以‘\0’结束。
	**输出：
	*		无
	**返回值：
	*		true： 成功
	*		false：失败 
	**功能：
	*		若输入p_pszUserName长度<=CONST_MAXLENGTH_USERNAME，返回true.
	*		若输入p_pszUserName为NULL或其长度>CONST_MAXLENGTH_USERNAME，返回false.
	*****************************************************************************/
	bool setUserName(const char* p_pszUserName);

	/****************************************************************************
	**概述：
	*		获取用户名
	**输入：
	*		无
	**输出：
	*		无
	*返回值：
	*		用户名，字符串类型 
	**功能：
	*		
	*****************************************************************************/
	const char* getUserName() const;


	/****************************************************************************
	**概述：
	*		设置密码
	**输入：
	*		p_pszPassword ：密码,结尾以‘\0’结束。
	**输出：
	*		无
	**返回值：
	*		true： 成功
	*		false：失败 
	**功能：
	*		若输入p_pszPassword长度<=CONST_MAXLENGTH_USERPASSWORD，返回true.
	*		若输入p_pszPassword为NULL或其长度>CONST_MAXLENGTH_USERPASSWORD，返回false.
	*****************************************************************************/
	bool setPassword(const char* p_pszPassword);

	/****************************************************************************
	**概述：
	*		获取密码
	**输入：
	*		无
	**输出：
	*		无
	*返回值：
	*		密码，字符串类型 
	**功能：
	*		
	*****************************************************************************/
	const char* getPassword() const;


	/****************************************************************************
	**概述：设置用户描述
	*
	**输入：
	*		p_pszDesc：用户描述
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*****************************************************************************/
	bool setDesc(const char* p_pszDesc);

	/****************************************************************************
	**概述：获取用户描述
	*
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		描述
	**功能：
	*****************************************************************************/
	const char* getDesc() const;


	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objUserParam ：显示画面对象
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	**************************************************************************/
	UserParam& operator = (const UserParam& p_objUserParam);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objUserParam：UserParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个UserParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const UserParam& p_objUserParam);

private:

	char	m_szUserName[CONST_MAXLENGTH_USERNAME + 1];				//用户名
	char	m_szPassword[CONST_MAXLENGTH_USERPASSWORD + 1];			//密码
	char	m_szDesc[CONST_MAXLENGTH_USER_DESC + 1];				//描述

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_USERPARAM_H_
