#ifndef _SECURITY_PARAM_H_
#define _SECURITY_PARAM_H_


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

class SN_DLL_API SecurityParam
{
public:
	enum LoginMode
	{
		LOGIN_MODE_SINGLE		= 1,		//单点登录
		LOGIN_MODE_MULTIPLE		= 2			//多点登录
	};

	enum WebMode
	{
		WEB_MODE_HTTP			= 1,		//http
		WEB_MODE_HTTPS_HTTP		= 2,		//https/http
		WEB_MODE_HTTPS			= 3			//https
	};

	enum PasswordVerifyMode
	{
		PASSWORD_VERIFY_MODE_NOVERIFY	= 0,
		PASSWORD_VERIFY_MODE_REMIND		= 1,
		PASSWORD_VERIFY_MODE_REFUSE		= 2
	};


public:
	SecurityParam();
	~SecurityParam();
	
public:
	/************************************************************************
	**概述：
	*		设置用户登录模式
	**输入：
	*		p_nLoginMode：用户登录模式
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		LOGIN_MODE_SINGLE		//单点登录	
	*		LOGIN_MODE_MULTIPLE		//多点登录
	************************************************************************/
	void setLoginMode(int p_nLoginMode);
	int getLoginMode() const;

	/************************************************************************
	**概述：
	*		设置web访问方式
	**输入：
	*		p_nWebMode：web访问方式
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		WEB_MODE_HTTP			//http
	*		WEB_MODE_HTTPS_HTTP		//https/http
	*		WEB_MODE_HTTPS			//https
	************************************************************************/
	void setWebMode(int p_nWebMode);
	int getWebMode() const;

	/************************************************************************
	**概述：
	*		设置通讯加密标志
	**输入：
	*		p_bCommunicationEncryptFlag：通讯加密标志
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setCommunicationEncryptFlag(bool p_bCommunicationEncryptFlag);
	bool getCommunicationEncryptFlag() const;

	/************************************************************************
	**概述：
	*		设置帐号锁定时长
	**输入：
	*		p_nAccountsLockTime：帐号锁定时长
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setAccountsLockTime(int p_nAccountsLockTime);
	int getAccountsLockTime() const;

	/************************************************************************
	**概述：
	*		设置帐号解锁时长
	**输入：
	*		p_nAccountsUnlockTime：帐号解锁时长
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setAccountsUnlockTime(int p_nAccountsUnlockTime);
	int getAccountsUnlockTime() const;

	/************************************************************************
	**概述：
	*		设置帐号连续登录错误次数
	**输入：
	*		p_nMaxSeriesLoginErrorCount：帐号连续登录错误次数
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setMaxSeriesLoginErrorCount(int p_nMaxSeriesLoginErrorCount);
	int getMaxSeriesLoginErrorCount() const;

	/************************************************************************
	**概述：
	*		设置帐号可锁定标识
	**输入：
	*		p_bAccountsLockEnableFlag：帐号可锁定标识
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setAccountsLockEnableFlag(bool p_bAccountsLockEnableFlag);
	bool getAccountsLockEnableFlag() const;

	/************************************************************************
	**概述：
	*		设置密码复杂度校验模式
	**输入：
	*		p_nPasswordVerifyMode：密码复杂度校验模式
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setPasswordVerifyMode(int p_nPasswordVerifyMode);
	int getPasswordVerifyMode() const;


private:

	int		m_nLoginMode;					//用户登录模式
	int		m_nWebMode;						//web访问方式
	bool	m_bCommunicationEncryptFlag;	//通讯加密标志
	int		m_nAccountsLockTime;			//帐号锁定时长
	int		m_nAccountsUnlockTime;			//帐号解锁时长
	int		m_nMaxSeriesLoginErrorCount;	//帐号连续登录错误次数
	bool	m_bAccountsLockEnableFlag;		//帐号可锁定标识
	int		m_nPasswordVerifyMode;			//密码复杂度校验模式


}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif	//_SECURITY_PARAM_H_

