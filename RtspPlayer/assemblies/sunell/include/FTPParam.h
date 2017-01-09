#ifndef _FTPPARAM_H_
#define _FTPPARAM_H_

#include "DomainConst.h"
#include "const.h"
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

class SN_DLL_API FTPParam
{

public:
	FTPParam(void);
	~FTPParam(void);

	//拷贝构造函数
	FTPParam(const FTPParam& p_objFTPParam);

public:

	/************************************************************************
	** 概述：
	*		设置IP协议类型
	**输入：
	*		p_nIPProtoVer：IP协议类型
	**输出：
	*	  无
	**返回值：
	*	  无
	************************************************************************/
	void setIPProtoVer(const int p_nIPProtoVer);

	/************************************************************************
	**概述：
	*		获取IP协议类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		IP协议类型
	************************************************************************/
	const int getIPProtoVer()  const;

	/************************************************************************
	**概述：
	*		设置是否启用FTP
	**输入：
	*		p_bEnableFTP ：启用FTP标识
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setFTPEnableFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取启用FTP标识
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		启用FTP表示
	**功能：
	*		
	*************************************************************************/
	const bool getFTPEnableFlag() const;

	/************************************************************************
	**概述：
	*		设置FTP服务器地址
	**输入：
	*		p_szFTPServerAddr：FTP服务器地址
	**输出：
	*		无
	**返回值：
	*		无
	*功能：
	*	
	************************************************************************/
	bool setFTPServerAddr(const char *p_szFTPServerAddr);

	/************************************************************************
	**概述：
	*		获取FTP服务器地址
	*输入：
	*		无
	*输出：
	*		无
	**返回值：
	*		FTP服务器地址
	**功能：
	*
	*************************************************************************/
	const char *getFTPServerAddr() const;

	/************************************************************************
	**概述：
	*		设置FTP服务器端口
	**输入：
	*		p_szFTPServerPort：FTP服务器端口
	**输出：
	*		无
	**返回值：
	*		无
	*功能：
	*	
	************************************************************************/
	void setFTPServerPort(const unsigned short p_nFTPServerPort);

	/************************************************************************
	**概述：
	*		获取FTP服务器端口
	*输入：
	*		无
	*输出：
	*		无
	**返回值：
	*		FTP服务器端口
	**功能：
	*
	*************************************************************************/
	const unsigned short getFTPServerPort() const;

	/************************************************************************
	**概述：
	*		设置FTP登录的用户名
	**输入：
	*		p_pszFTPUserName ：FTP的用户名，一个以‘\0’结尾的字符串，
	**输出：
	*		无
	**返回值：
	*		ture ：	设置成功
	*		false ：设置失败
	*功能：
	*		当p_pszFTPUserName为空时，返回false；
	*		当设置FTP用户名成功时，返回true；
	************************************************************************/
	bool setFTPUserName(const char *p_pszFTPUserName);

	/************************************************************************
	**概述：
	*		获取 FTP登录用户名
	*输入：
	*		无
	*输出：
	*		无
	**返回值：
	*		FTP用户名
	**功能：
	*
	*************************************************************************/
	const char *getFTPUserName() const;

	/************************************************************************
	**概述：
	*		设置FTP密码
	*输入：
	*		p_pszFTPPassword：FTP登录密码，一个以‘\0’结尾的字符串，
	**输出：
	*		无
	**返回值：
	*		ture ：	设置成功
	*		false： 设置失败
	*功能：
	*		当p_pszFTPPassword为空时，返回false
	*		当设置FTP密码成功时，返回true
	************************************************************************/
	bool setFTPPassword(const char *p_pszFTPPassword);

	/************************************************************************
	**概述：
	*		获取FTP登录密码
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		FTP的密码
	*功能：
	*
	*************************************************************************/
	const char *getFTPPassword() const;

	/************************************************************************
	**概述：
	*		设置FTP服务器的工作路径，绝对路径、相对均可
	*		该路径为FTP客户端自动上传和下载文件的路径
	*输入：
	*		p_pszFTPServerWorkPath：FTP服务器的工作路径，一个以‘\0’结尾的字符串，
	**输出：
	*		无
	**返回值：
	*		ture ：	设置成功
	*		false： 设置失败
	*功能：
	*		当p_pszFTPServerWorkPath为空时，返回false
	*		当设置FTP密码成功时，返回true
	************************************************************************/
	bool setFTPServerWorkPath(const char *p_pszFTPServerWorkPath);

	/************************************************************************
	**概述：
	*		获取FTP登录密码
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		FTP的密码
	*功能：
	*
	*************************************************************************/
	const char *getFTPServerWorkPath() const;

	/************************************************************************
	**概述：
	*		设置可用空间
	**输入：
	*		p_nUseableSpace		可用空间
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setUseableSpace(const unsigned int p_nUseableSpace);

	/************************************************************************
	**概述：
	*		获取可用空间
	*输入：
	*		无
	*输出：
	*		无
	**返回值：
	*		可用空间
	*************************************************************************/
	const unsigned int getUseableSpace() const;

	/************************************************************************
	*概述：
	*		赋值函数
	**输入：
	*		p_objFTPParam：FTP信息
	**输出：
	*		无
	**返回值：
	*		FTP信息
	**功能：
	*
	*************************************************************************/
	FTPParam& operator =(const FTPParam& p_objFTPParam);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objFTPParam：FTPParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个FTPParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const FTPParam& p_objFTPParam);

private:

	bool			m_bFTPEnableFlag;										//是否启用FTP标识(false：不启用，true：启用)

	char			m_szFTPServerAddr[CONST_MAXLENGTH_IP + 1];				//FTP服务器地址

	unsigned short  m_nFTPServerPort;										//FTP服务器端口

	char			m_szFTPUserName[CONST_MAXLENGTH_FTP_USERNAME + 1];		//FTP账户

	char			m_szFTPPassword[CONST_MAXLENGTH_FTP_PASSWORD + 1];		//FTP密码

	char			m_szFTPWorkPath[CONST_MAXLENGTH_FTP_WORKPATH + 1];		//FTP工作路径	

	int				m_nIPProtoVer;											//IP协议类型

	unsigned int	m_nUseableSpace;										//FTP目录可用空间
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_FTPParam_H_

