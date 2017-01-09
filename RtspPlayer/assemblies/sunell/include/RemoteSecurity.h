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
//�˴����ڿ����ļ������ֽڶ��룬����ʱ����ע�ͼ�������һ�𿽱���
//�������ġ�#ifdef PRAGMA_PACK������ҲҪһ�𿽱�������pragma pack��ջ��ջ��ƥ��
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
	**������
	*		�����豸��Ϣ
	**���룺
	*		p_objDeviceInfo���豸��Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setDeivceInfo(const DeviceInfo &p_objDeviceInfo);

	void setDeivceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

	/************************************************************************
	**������
	*		������������Ƶ�豸֮������紫��Э��
	**���룺
	*		p_nTransferProtocolҪ���õĴ���Э�飬������2������
	*		TransferProtocol::UDP = 0X01,
	*		TransferProtocol::TCP = 0X02,
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		������������Ƶ�豸֮������紫��Э��
	*************************************************************************/
	void setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**������
	*		������������Ƶ�豸֮������ûỰ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��open�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		������������Ƶ�豸֮������ûỰ
	*************************************************************************/
	int open();

	/************************************************************************
	**������
	*		�ر���������Ƶ�豸�����ûỰ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�ر���������Ƶ�豸�����ûỰ
	*************************************************************************/
	void close();

public:
	/************************************************************************
	**������
	*		���ĵ�ǰ�û�������
	**���룺
	*		p_pszOldPassword��������
	*		p_pszNewPassword��������
	**�����
	*		��
	**����ֵ��
	*		�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		�ر���������Ƶ�豸�����ûỰ
	*************************************************************************/
	int changePassword(const char * p_pszOldPassword, const  char * p_pszNewPassword);

	/************************************************************************
	**������
	*		���Ȩ���û�
	**���룺
	*		p_objUser���û�Ȩ��
	**�����
	*		��
	**����ֵ��
	*		�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int addUser(const PrivilegeUser & p_objUser);

	/************************************************************************
	**������
	*		ɾ��Ȩ���û�
	**���룺
	*		p_objUser���û�Ȩ��
	**�����
	*		��
	**����ֵ��
	*		�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int deleteUser(const PrivilegeUser & p_objUser);

	/************************************************************************
	**������
	*		�޸�Ȩ���û�
	**���룺
	*		p_objUser���û�Ȩ��
	**�����
	*		��
	**����ֵ��
	*		�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int updateUser(const PrivilegeUser & p_objUser);

	/************************************************************************
	**������
	*		��ȡ����Ȩ���û�
	**���룺
	*		��
	**�����
	*		p_objUserList���û�Ȩ���б�
	**����ֵ��
	*		�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAllUsers(std::vector<PrivilegeUser> & p_objUserList);

	/************************************************************************
	**������
	*		�����û�
	**���룺
	*		p_pszUserName�����������û���
	**�����
	*		��
	**����ֵ��
	*		�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int lockUser(const char * p_pszUserName);

	/************************************************************************
	**������
	*		�����û�
	**���룺
	*		p_pszUserName�����������û���
	**�����
	*		��
	**����ֵ��
	*		�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int unlockUser(const char * p_pszUserName);

	/************************************************************************
	**������
	*		���Ȩ����
	**���룺
	*		p_objGroup��Ȩ����
	**�����
	*		��
	**����ֵ��
	*		�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int addGroup(const PrivilegeGroup & p_objGroup);

	/************************************************************************
	**������
	*		ɾ��Ȩ����
	**���룺
	*		p_objGroup��Ȩ����
	**�����
	*		��
	**����ֵ��
	*		�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int deleteGroup(const PrivilegeGroup & p_objGroup);

	/************************************************************************
	**������
	*		�޸�Ȩ����
	**���룺
	*		p_objGroup��Ȩ����
	**�����
	*		��
	**����ֵ��
	*		�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int updateGroup(const PrivilegeGroup & p_objGroup);

	/************************************************************************
	**������
	*		��ȡ����Ȩ����
	**���룺
	*		��
	**�����
	*		p_objGroupList��Ȩ�����б�
	**����ֵ��
	*		�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAllGroups(std::vector<PrivilegeGroup> & p_objGroupList);

	/************************************************************************
	**������
	*		������Ȩ��
	**���룺
	*		p_nGroupId��Ȩ����ID
	*		p_objPrivilege��Ȩ�޲���
	**�����
	*		��
	**����ֵ��
	*		�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setGroupPrivileges(const int p_nGroupId, const Privilege & p_objPrivilege);

	/************************************************************************
	**������
	*		��ȡ��Ȩ��
	**���룺
	*		p_nGroupId��Ȩ����ID	
	**�����
	*		p_objPrivilege��Ȩ�޲���
	**����ֵ��
	*		�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getGroupPrivileges(const int p_nGroupId, Privilege & p_objPrivilege);
	

	/************************************************************************
	**������
	*		�����µ�ϵͳ�û�����
	**���룺
	*		p_strNewPassword��Զ��ץ�Ĳ���
	*		p_objSystemUser�����������ϵͳ�û�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������ĵ���Ӧϵͳ�û��еľ����롣�����ϵͳ�û��������û����;����롣
	*************************************************************************/
	int setSystemUserNewPassword(const std::string& p_strNewPassword, const SystemUser& p_objSystemUser);


	/************************************************************************
	**������
	*		��ȡ�û�Ȩ��
	**���룺
	*		p_pszName���û���
	**�����
	*		p_objPrivilege���û�Ȩ��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ�û�Ȩ��
	*************************************************************************/
	int getUserPrivileges(const char * p_pszName, Privilege &p_objPrivilege);

public:
	/************************************************************************
	**������
	*		��ȡ�Լ����û�Ȩ��
	**���룺
	*		p_pszName���û���
	**�����
	*		p_objPrivilege���û�Ȩ��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ�Լ����û�Ȩ��
	*************************************************************************/
	int getSelfPrivileges(Privilege &p_objPrivilege);

	/************************************************************************
	**������
	*		��ȡ�Լ���Ȩ���û���Ϣ
	**���룺
	*		��
	**�����
	*		p_objPrivilegeUser�����û���Ϣ
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ�Լ���Ȩ���û���Ϣ
	*************************************************************************/
	int getSelfPrivilegeUser(PrivilegeUser &p_objPrivilegeUser);

	/************************************************************************
	**������
	*		��ȡ�Լ���Ȩ����
	**���룺
	*		��
	**�����
	*		p_objPrivilegeGroup��Ȩ����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ�Լ���Ȩ����
	*************************************************************************/
	int getSelfPrivilegeGroup(PrivilegeGroup &p_objPrivilegeGroup);


public:
	/************************************************************************
	**������
	*		���ô�������
	**���룺
	*		p_pobjTransfer��������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setTransfer(ITransfer*	p_pobjTransfer);

	/************************************************************************
	**������
	*		����ͨѶ�ĳ�ʱʱ�䡣
	**���룺
	*		p_nTimeout����ʱʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setTimeout(int p_nTimeout);

private:
	//�������캯��
	RemoteSecurity(const RemoteSecurity& p_objObject)
	{
	}

	//��ֵ����
	RemoteSecurity& operator = (const RemoteSecurity& p_objObject)
	{
		return *this;
	}

	bool findUserByName(const char * p_pszName, const std::vector<PrivilegeUser> &p_objUserList, PrivilegeUser& p_objPrivilegeUser);


private:
	ITransfer*			m_pobjTransfer;					//������

	int					m_nTransferProtocol;			//����Э��

	DeviceInfoEx		m_objDeviceInfoEx;				//�豸��Ϣ

	int					m_nSessionId;					//�Ự����

	int					m_nTimeout;						//��ʱʱ�䣬�Ժ���Ϊ��λ

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
