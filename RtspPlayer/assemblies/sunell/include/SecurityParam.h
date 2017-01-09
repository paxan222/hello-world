#ifndef _SECURITY_PARAM_H_
#define _SECURITY_PARAM_H_


#include "SNPlatOS.h"

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

class SN_DLL_API SecurityParam
{
public:
	enum LoginMode
	{
		LOGIN_MODE_SINGLE		= 1,		//�����¼
		LOGIN_MODE_MULTIPLE		= 2			//����¼
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
	**������
	*		�����û���¼ģʽ
	**���룺
	*		p_nLoginMode���û���¼ģʽ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		LOGIN_MODE_SINGLE		//�����¼	
	*		LOGIN_MODE_MULTIPLE		//����¼
	************************************************************************/
	void setLoginMode(int p_nLoginMode);
	int getLoginMode() const;

	/************************************************************************
	**������
	*		����web���ʷ�ʽ
	**���룺
	*		p_nWebMode��web���ʷ�ʽ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		WEB_MODE_HTTP			//http
	*		WEB_MODE_HTTPS_HTTP		//https/http
	*		WEB_MODE_HTTPS			//https
	************************************************************************/
	void setWebMode(int p_nWebMode);
	int getWebMode() const;

	/************************************************************************
	**������
	*		����ͨѶ���ܱ�־
	**���룺
	*		p_bCommunicationEncryptFlag��ͨѶ���ܱ�־
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	************************************************************************/
	void setCommunicationEncryptFlag(bool p_bCommunicationEncryptFlag);
	bool getCommunicationEncryptFlag() const;

	/************************************************************************
	**������
	*		�����ʺ�����ʱ��
	**���룺
	*		p_nAccountsLockTime���ʺ�����ʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	************************************************************************/
	void setAccountsLockTime(int p_nAccountsLockTime);
	int getAccountsLockTime() const;

	/************************************************************************
	**������
	*		�����ʺŽ���ʱ��
	**���룺
	*		p_nAccountsUnlockTime���ʺŽ���ʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	************************************************************************/
	void setAccountsUnlockTime(int p_nAccountsUnlockTime);
	int getAccountsUnlockTime() const;

	/************************************************************************
	**������
	*		�����ʺ�������¼�������
	**���룺
	*		p_nMaxSeriesLoginErrorCount���ʺ�������¼�������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	************************************************************************/
	void setMaxSeriesLoginErrorCount(int p_nMaxSeriesLoginErrorCount);
	int getMaxSeriesLoginErrorCount() const;

	/************************************************************************
	**������
	*		�����ʺſ�������ʶ
	**���룺
	*		p_bAccountsLockEnableFlag���ʺſ�������ʶ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	************************************************************************/
	void setAccountsLockEnableFlag(bool p_bAccountsLockEnableFlag);
	bool getAccountsLockEnableFlag() const;

	/************************************************************************
	**������
	*		�������븴�Ӷ�У��ģʽ
	**���룺
	*		p_nPasswordVerifyMode�����븴�Ӷ�У��ģʽ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	************************************************************************/
	void setPasswordVerifyMode(int p_nPasswordVerifyMode);
	int getPasswordVerifyMode() const;


private:

	int		m_nLoginMode;					//�û���¼ģʽ
	int		m_nWebMode;						//web���ʷ�ʽ
	bool	m_bCommunicationEncryptFlag;	//ͨѶ���ܱ�־
	int		m_nAccountsLockTime;			//�ʺ�����ʱ��
	int		m_nAccountsUnlockTime;			//�ʺŽ���ʱ��
	int		m_nMaxSeriesLoginErrorCount;	//�ʺ�������¼�������
	bool	m_bAccountsLockEnableFlag;		//�ʺſ�������ʶ
	int		m_nPasswordVerifyMode;			//���븴�Ӷ�У��ģʽ


}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif	//_SECURITY_PARAM_H_

