#ifndef _CWMPPARAM_H_
#define _CWMPPARAM_H_

#include "SNPlatOS.h"
#include "DomainConst.h"

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

class SN_DLL_API CWMPParam
{
public:
		CWMPParam();
		~CWMPParam();


		//�������캯��
		CWMPParam(const CWMPParam &p_objCWMPParam);

public:
		//��������URL
		bool setACSUrl(const char* p_pszACSUrl);
		const char* getACSUrl() const;

		//�������ܷ���IP
		bool setACSIP(const char* p_pszACSIP);
		const char* getACSIP() const;

		//�������ܷ���˿�
		void setACSPort(const int p_nACSPort);
		const int getACSPort() const;
	
		//��������ע���û���
		bool setACSUserName(const char* p_pszACSUserName);
		const char* getACSUserName() const;

		//��������ע������
		bool setACSPassword(const char* p_pszACSPassword);
		const char* getACSPassword() const;

		//���ñ��ؼ�Ȩ�û���
		bool setCPEUserName(const char* p_pszCPEUserName);
		const char* getCPEUserName() const;

		//���ñ��ؼ�Ȩ����
		bool setCPEPassword(const char* p_pszCPEPassword);
		const char* getCPEPassword() const;

		//���ñ��������˿ں�
		void setCPEListenPort(const int p_nCPEListenPort);
		const int getCPEListenPort() const;

		//�������ܽ���ID
		bool setCPERegisterID(const char* p_pszCPERegisterID);
		const char* getCPERegisterID() const;

		//���ñ��������˿ں�
		void setInformPeriodic(const int p_nInformPeriodic);
		const int getInformPeriodic() const;

		CWMPParam& operator = (const CWMPParam &p_objProtocolConfigParam);

private:

	char	m_szACSUrl[CONST_MAXLENGTH_PROTOCOL_PARAM];				//����URL

	char	m_szACSIP[CONST_MAXLENGTH_PROTOCOL_PARAM];				//���ܷ�����IP
	
	int		m_nACSPort;												//���ܷ������˿�

	char	m_szACSUserName[CONST_MAXLENGTH_PROTOCOL_PARAM];		//����ע���û���
	
	char	m_szACSPassword[CONST_MAXLENGTH_PROTOCOL_PARAM];		//����ע������


	char	m_szCPEUserName[CONST_MAXLENGTH_PROTOCOL_PARAM];		//���ؼ�Ȩ�û���

	char	m_szCPEPassword[CONST_MAXLENGTH_PROTOCOL_PARAM];		//���ؼ�Ȩ����
	
	int		m_nCPEListenPort;										//���������˿ں�

	char	m_szCPERegisterID[CONST_MAXLENGTH_PROTOCOL_PARAM];		//���ܽ���ID

	int		m_nInformPeriodic;										//����ƽ̨��������

	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_CWMPPARAM_H_
