#ifndef _REMOTE_SECURITY_H_
#define _REMOTE_SECURITY_H_


#include "SNError.h"
#include "DeviceInfoEx.h"
#include "SNPlatOS.h"

#include "SystemUser.h"
#include "PrivilegeGroup.h"
#include "PrivilegeUser.h"
#include "Privilege.h"

class ITransfer;


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

class SN_DLL_API  RemoteSecurity
{

public:

	RemoteSecurity();

	RemoteSecurity(const DeviceInfo &p_objDeviceInfo);

	RemoteSecurity(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteSecurity(void);

public:

	/************************************************************************
	**概述：
	*		设置设备信息
	**输入：
	*		p_objDeviceInfo：设备信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setDeivceInfo(const DeviceInfo &p_objDeviceInfo);

	void setDeivceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

	/************************************************************************
	**概述：
	*		设置与网络视频设备之间的网络传输协议
	**输入：
	*		p_nTransferProtocol要设置的传输协议，有以下2种类型
	*		TransferProtocol::UDP = 0X01,
	*		TransferProtocol::TCP = 0X02,
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		设置与网络视频设备之间的网络传输协议
	*************************************************************************/
	void setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**概述：
	*		建立和网络视频设备之间的配置会话
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若open方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		建立和网络视频设备之间的配置会话
	*************************************************************************/
	int open();

	/************************************************************************
	**概述：
	*		关闭与网络视频设备的配置会话
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		关闭与网络视频设备的配置会话
	*************************************************************************/
	void close();

public:
	/************************************************************************
	**概述：
	*		更改当前用户的密码
	**输入：
	*		p_pszOldPassword：旧密码
	*		p_pszNewPassword：新密码
	**输出：
	*		无
	**返回值：
	*		方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		关闭与网络视频设备的配置会话
	*************************************************************************/
	int changePassword(const char * p_pszOldPassword, const  char * p_pszNewPassword);

	/************************************************************************
	**概述：
	*		添加权限用户
	**输入：
	*		p_objUser：用户权限
	**输出：
	*		无
	**返回值：
	*		方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int addUser(const PrivilegeUser & p_objUser);

	/************************************************************************
	**概述：
	*		删除权限用户
	**输入：
	*		p_objUser：用户权限
	**输出：
	*		无
	**返回值：
	*		方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int deleteUser(const PrivilegeUser & p_objUser);

	/************************************************************************
	**概述：
	*		修改权限用户
	**输入：
	*		p_objUser：用户权限
	**输出：
	*		无
	**返回值：
	*		方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int updateUser(const PrivilegeUser & p_objUser);

	/************************************************************************
	**概述：
	*		获取所有权限用户
	**输入：
	*		无
	**输出：
	*		p_objUserList：用户权限列表
	**返回值：
	*		方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAllUsers(std::vector<PrivilegeUser> & p_objUserList);

	/************************************************************************
	**概述：
	*		锁定用户
	**输入：
	*		p_pszUserName：待锁定的用户名
	**输出：
	*		无
	**返回值：
	*		方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int lockUser(const char * p_pszUserName);

	/************************************************************************
	**概述：
	*		解锁用户
	**输入：
	*		p_pszUserName：待解锁的用户名
	**输出：
	*		无
	**返回值：
	*		方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int unlockUser(const char * p_pszUserName);

	/************************************************************************
	**概述：
	*		添加权限组
	**输入：
	*		p_objGroup：权限组
	**输出：
	*		无
	**返回值：
	*		方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int addGroup(const PrivilegeGroup & p_objGroup);

	/************************************************************************
	**概述：
	*		删除权限组
	**输入：
	*		p_objGroup：权限组
	**输出：
	*		无
	**返回值：
	*		方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int deleteGroup(const PrivilegeGroup & p_objGroup);

	/************************************************************************
	**概述：
	*		修改权限组
	**输入：
	*		p_objGroup：权限组
	**输出：
	*		无
	**返回值：
	*		方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int updateGroup(const PrivilegeGroup & p_objGroup);

	/************************************************************************
	**概述：
	*		获取所有权限组
	**输入：
	*		无
	**输出：
	*		p_objGroupList：权限组列表
	**返回值：
	*		方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAllGroups(std::vector<PrivilegeGroup> & p_objGroupList);

	/************************************************************************
	**概述：
	*		设置组权限
	**输入：
	*		p_nGroupId：权限组ID
	*		p_objPrivilege：权限参数
	**输出：
	*		无
	**返回值：
	*		方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setGroupPrivileges(const int p_nGroupId, const Privilege & p_objPrivilege);

	/************************************************************************
	**概述：
	*		获取组权限
	**输入：
	*		p_nGroupId：权限组ID	
	**输出：
	*		p_objPrivilege：权限参数
	**返回值：
	*		方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getGroupPrivileges(const int p_nGroupId, Privilege & p_objPrivilege);
	

	/************************************************************************
	**概述：
	*		设置新的系统用户密码
	**输入：
	*		p_strNewPassword：远程抓拍参数
	*		p_objSystemUser：更改密码的系统用户
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		用新密码更改掉对应系统用户中的旧密码。输入的系统用户包含有用户名和旧密码。
	*************************************************************************/
	int setSystemUserNewPassword(const std::string& p_strNewPassword, const SystemUser& p_objSystemUser);


	/************************************************************************
	**概述：
	*		获取用户权限
	**输入：
	*		p_pszName：用户名
	**输出：
	*		p_objPrivilege：用户权限
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取用户权限
	*************************************************************************/
	int getUserPrivileges(const char * p_pszName, Privilege &p_objPrivilege);

public:
	/************************************************************************
	**概述：
	*		获取自己的用户权限
	**输入：
	*		p_pszName：用户名
	**输出：
	*		p_objPrivilege：用户权限
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取自己的用户权限
	*************************************************************************/
	int getSelfPrivileges(Privilege &p_objPrivilege);

	/************************************************************************
	**概述：
	*		获取自己的权限用户信息
	**输入：
	*		无
	**输出：
	*		p_objPrivilegeUser：限用户信息
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取自己的权限用户信息
	*************************************************************************/
	int getSelfPrivilegeUser(PrivilegeUser &p_objPrivilegeUser);

	/************************************************************************
	**概述：
	*		获取自己的权限组
	**输入：
	*		无
	**输出：
	*		p_objPrivilegeGroup：权限组
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取自己的权限组
	*************************************************************************/
	int getSelfPrivilegeGroup(PrivilegeGroup &p_objPrivilegeGroup);


public:
	/************************************************************************
	**概述：
	*		设置传输器。
	**输入：
	*		p_pobjTransfer：传输器
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setTransfer(ITransfer*	p_pobjTransfer);

	/************************************************************************
	**概述：
	*		设置通讯的超时时间。
	**输入：
	*		p_nTimeout：超时时间
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setTimeout(int p_nTimeout);

private:
	//拷贝构造函数
	RemoteSecurity(const RemoteSecurity& p_objObject)
	{
	}

	//赋值函数
	RemoteSecurity& operator = (const RemoteSecurity& p_objObject)
	{
		return *this;
	}

	bool findUserByName(const char * p_pszName, const std::vector<PrivilegeUser> &p_objUserList, PrivilegeUser& p_objPrivilegeUser);


private:
	ITransfer*			m_pobjTransfer;					//传输器

	int					m_nTransferProtocol;			//传输协议

	DeviceInfoEx		m_objDeviceInfoEx;				//设备信息

	int					m_nSessionId;					//会话对象

	int					m_nTimeout;						//超时时间，以毫秒为单位

	bool				m_bIsOpen;


}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_REMOTE_SECURITY_H_
