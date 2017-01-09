#ifndef _SMTPPARAM_H_
#define _SMTPPARAM_H_

#include "DomainConst.h"
#include "const.h"
#include "SNPlatOS.h"
#include <string>
#include <vector>

//using namespace std;

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

class SN_DLL_API SMTPParam
{

public:
	enum MailLanguage
	{
		MAIL_LANGUAGE_CHINESE				= 1,	//中文
		MAIL_LANGUAGE_ENGLISH				= 2		//英文
	};

	enum MailAttachmentImageQuality
	{
		HIGH = 1,	//高
		MID	= 2,	//中
		LOW = 3		//低
	};

	enum TransportMode
	{
		NO_ENCRYPT = 0,		//无加密
		SSL	= 1,			//SSL安全连接
		STARTTLS = 2		//Starttls命令传输
	};

public:
	SMTPParam(void);
	~SMTPParam(void);

	//拷贝构造函数
	SMTPParam(const SMTPParam& p_objSMTPParam);

public:
	/************************************************************************
	**概述：
	*		设置是否启用SMTP
	**输入：
	*		p_bEnableSMTP ：启用SMTP标识
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setSMTPEnableFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取启用SMTP标识
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		启用SMTP标识
	**功能：
	*		
	*************************************************************************/
	const bool getSMTPEnableFlag() const;

	/************************************************************************
	** 概述：
	*		设置是否使用默认邮箱标志，当使用默认邮箱时，则使用IPCamera自带的默认邮箱，
	*		只需设置邮件收件人地址；若使用自定义邮箱，则需要配置邮件服务器地址、用户名、
	*		密码和发件人地址。
	**输入：
	*		p_bUseDefaultAddresserFlag：是否使用默认邮箱的标志，true：使用默认邮箱，
	*														  false：使用自定义邮箱。
	**输出：
	*	  无
	**返回值：
	*	  无
	************************************************************************/
	void setUseDefaultSMTPServerFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取是否使用默认邮箱标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		是否使用默认邮箱的标志，true：使用默认邮箱，false：使用自定义邮箱。
	************************************************************************/
	const bool getUseDefaultSMTPServerFlag()  const;

	/************************************************************************
	**概述：
	*		设置SMTP服务器地址
	**输入：
	*		p_szSMTPServerAddr：SMTP邮件服务器地址
	**输出：
	*		无
	**返回值：
	*		无
	*功能：
	*	
	************************************************************************/
	bool setSMTPServerAddr(const char *p_szSMTPServerAddr);

	/************************************************************************
	**概述：
	*		获取SMTP服务器地址
	*输入：
	*		无
	*输出：
	*		无
	**返回值：
	*		SMTP邮件服务器地址
	**功能：
	*
	*************************************************************************/
	const char *getSMTPServerAddr() const;

	/************************************************************************
	**概述：
	*		设置SMTP邮件服务器端口
	**输入：
	*		p_szSMTPServerPort：SMTP邮件服务器端口
	**输出：
	*		无
	**返回值：
	*		无
	*功能：
	*	
	************************************************************************/
	void setSMTPServerPort(const unsigned short p_nSMTPServerPort);

	/************************************************************************
	**概述：
	*		获取SMTP邮件服务器端口
	*输入：
	*		无
	*输出：
	*		无
	**返回值：
	*		SMTP邮件服务器端口
	**功能：
	*
	*************************************************************************/
	const unsigned short getSMTPServerPort() const;

	/************************************************************************
	**概述：
	*		设置用户名
	**输入：
	*		p_pszUserName ：用户名，一个以‘\0’结尾的字符串，
	**输出：
	*		无
	**返回值：
	*		ture ：	设置成功
	*		false ：设置失败
	*功能：
	*		当p_pszUserName为空时，返回false；
	*		当设置用户名成功时，返回true；
	************************************************************************/
	bool setSMTPUserName(const char *p_pszSMTPUserName);

	/************************************************************************
	**概述：
	*		获取用户名
	*输入：
	*		无
	*输出：
	*		无
	**返回值：
	*		用户名
	**功能：
	*
	*************************************************************************/
	const char *getSMTPUserName() const;

	/************************************************************************
	**概述：
	*		设置密码
	*输入：
	*		p_pszPassword：登录密码，一个以‘\0’结尾的字符串，
	**输出：
	*		无
	**返回值：
	*		ture ：	设置成功
	*		false： 设置失败
	*功能：
	*		当p_pszPassword为空时，返回false
	*		当设置密码成功时，返回true
	************************************************************************/
	bool setSMTPPassword(const char *p_pszSMTPPassword);

	/************************************************************************
	**概述：
	*		获取登录密码
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		登录密码
	*功能：
	*
	*************************************************************************/
	const char *getSMTPPassword() const;

	/************************************************************************
	**概述：
	*		设置邮件发件人地址
	*输入：
	*		p_pszAddresser：邮件发件人地址，一个以‘\0’结尾的字符串，
	**输出：
	*		无
	**返回值：
	*		ture ：	设置成功
	*		false： 设置失败
	*功能：
	*		当p_pszAddresser为空时，返回false
	*		当设置邮件发件人地址成功时，返回true
	************************************************************************/
	bool setSenderEmailAddress(const char *p_pszSenderEmailAddress);

	/************************************************************************
	**概述：
	*		获取邮件发件人地址
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		邮件发件人地址
	*功能：
	*
	*************************************************************************/
	const char *getSenderEmailAddress() const;


	/************************************************************************
	**概述：
	*		设置邮件收件人地址列表
	**输入：
	*		p_objRecipientEmailAddressList：邮件收件人地址列表
	**输出：
	*		无
	**返回值：
	*		
	*功能：
	*
	*************************************************************************/
	void setRecipientEmailAddressList(std::vector<std::string>& p_objRecipientEmailAddressList);

	/************************************************************************
	**概述：
	*		获取邮件收件人地址列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		邮件收件人地址
	*功能：
	*
	*************************************************************************/
	std::vector<std::string> * getRecipientEmailAddressList() const;
	
	/************************************************************************
	**概述：
	*		设置邮件语言
	**输入：
	*		无
	**输出：
	*		p_nMailLanguage：邮件语言
	**返回值：
	*		无
	*功能：
	*
	*************************************************************************/
	void setMailLauguage(const int p_nMailLanguage);

	/************************************************************************
	**概述：
	*		获取邮件语言
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		邮件语言
	*功能：
	*
	*************************************************************************/
	const int getMailLanguage() const;

	/************************************************************************
	**概述：
	*		设置邮件附件图像质量
	**输入：
	*		无
	**输出：
	*		p_nAttachmentImageQuality：邮件附件图像质量
	**返回值：
	*		无
	*功能：
	*
	*************************************************************************/
	void setAttachmentImageQuality(const int p_nAttachmentImageQuality);

	/************************************************************************
	**概述：
	*		获取邮件附件图像质量
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		邮件附件图像质量
	*功能：
	*
	*************************************************************************/
	const int getAttachmentImageQuality() const;

	/************************************************************************
	**概述：
	*		设置传输模式
	**输入：
	*		无
	**输出：
	*		p_nTransportMode：传输模式，0：无加密 1：ssl连接 2：starttls方式
	**返回值：
	*		无
	*功能：
	*
	*************************************************************************/
	void setTransportMode(const int p_nTransportMode);

	/************************************************************************
	**概述：
	*		获取传输模式
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		传输模式
	*功能：
	*
	*************************************************************************/
	const int getTransportMode() const;

	/************************************************************************
	*概述：
	*		赋值函数
	**输入：
	*		p_objSMTPParam：FTP信息
	**输出：
	*		无
	**返回值：
	*		FTP信息
	**功能：
	*
	*************************************************************************/
	SMTPParam& operator =(const SMTPParam& p_objSMTPParam);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objSMTPParam：SMTPParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个SMTPParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const SMTPParam& p_objSMTPParam);

private:
	bool			m_bSMTPEnableFlag;										//SMTP启用标志

	bool			m_bUseDefaultSMTPServerFlag;							//是否使用默认邮箱标识(false：不启用，true：启用)

	char			m_szSMTPServerAddr[CONST_MAXLENGTH_IP + 1];				//SMTP服务器地址

	unsigned short  m_nSMTPServerPort;										//SMTP服务器端口

	char			m_szSMTPUserName[CONST_MAXLENGTH_USERNAME + 1];			//账户

	char			m_szSMTPPassword[CONST_MAXLENGTH_USERPASSWORD + 1];		//密码

	char			m_szSenderEmailAddress[CONST_MAXLENGTH_EMAIL_ADDRESS + 1];//发件人地址	

	std::vector<std::string>	m_objRecipientEmailAddressList;							//收件人地址列表
	
	int				m_nMailLanguage;										//邮件内容语言

	int				m_nAttachmentImageQuality;								//邮件附件的图像质量

	int				m_nTransportMode;										//传输模式，0：无加密 1：ssl连接 2：starttls方式
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_SMTPParam_H_

