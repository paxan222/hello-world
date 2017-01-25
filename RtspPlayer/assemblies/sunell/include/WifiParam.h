#ifndef _WIFIPARAM_H_
#define _WIFIPARAM_H_

#include "DomainConst.h"
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

class SN_DLL_API WifiParam
{
public:
	WifiParam(void);
	~WifiParam(void);

public:

	/************************************************************************
	**������
	*		��������Wifi��
	**���룺
	*		p_bUseWifiFlag������Wifi��־
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setEnableFlag(const bool p_bEnableFlag);

	/************************************************************************
	**��������ȡ����Wifi��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		
	************************************************************************/
	const bool getEnableFlag() const;

	/************************************************************************
	**������
	*		����SSID
	**���룺
	*		p_pszSSID��SSID
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	bool setSSID(const char* p_pszSSID);

	/************************************************************************
	**������
	*		��ȡSSID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		SSID
	************************************************************************/
	const char* getSSID() const ;


	/************************************************************************
	**������
	*		��������
	**���룺
	*		p_strPassword������
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	bool setPassword(const char* p_pszPassword);

	/************************************************************************
	**������
	*		��ȡ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		m_strPassword
	************************************************************************/
	const char* getPassword() const ;


	/************************************************************************
	**������
	*		�����Ƿ������Զ���ȡIP
	**���룺
	*		p_bUseDynamicIPFlag:�����Զ���ȡIP��־
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setUseDynamicIPFlag(const bool p_bUseDynamicIPFlag);

	/************************************************************************
	**������
	*		��ȡ�Ƿ������Զ���ȡIP
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		
	************************************************************************/
	const bool getUseDynamicIPFlag() const;

	/************************************************************************
	**������
	*		���þ�̬IP��ַ
	**���룺
	*		p_nStaticIP ����̬IP��ַ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	bool setStaticIP(const char * p_pszStaticIP);

	/************************************************************************
	**������
	*		��ȡ��̬IP��ַ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��̬IP��ַ
	**���ܣ�
	*
	************************************************************************/
	const char * getStaticIP() const;

	/************************************************************************
	**������
	*		������������
	**���룺
	*		p_nSubnetMask ����������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	bool setSubnetMask(const char * p_pszSubnetMask);

	/************************************************************************
	**������
	*		��ȡ��������
	**���룺
	*		��
	**�����
	**		��
	**����ֵ��
	*		��������
	**���ܣ�
	*
	************************************************************************/
	const char * getSubnetMask() const;

	/************************************************************************
	**������
	*		����Ĭ�����ص�ַ
	**���룺
	*		p_pszGateway ��Ĭ�����ص�ַ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	bool setGateway(const char * p_pszGateway);

	/************************************************************************
	**������
	*		��ȡĬ�����ص�ַ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		Ĭ�����ص�ַ
	**���ܣ�
	*
	************************************************************************/
	const char * getGateway() const;

	/************************************************************************
	**������
	*		����DNS������IP��ַ
	**���룺
	*		p_nDNS��DNS������IP��ַ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	bool setDNS(const char * p_pszDNS);

	/************************************************************************
	**������
	*		��ȡDNS������IP��ַ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		DNS������IP��ַ
	**���ܣ�
	*
	************************************************************************/
	const char * getDNS() const;


private:
	bool			m_bEnableFlag;									//�Ƿ�����Wifi
	char			m_szSSID[CONST_MAXLENGTH_SSID+1];				//SSID
	char			m_szPassword[CONST_MAXLENGTH_SSID_PASSWORD+1];	//����
	
	bool			m_bUseDynamicIPFlag;							//�Ƿ����ö�̬IP

	char			m_szStaticIP[CONST_MAXLENGTH_IP + 1];			//��̬IP��ַ
	char			m_szSubnetMask[CONST_MAXLENGTH_IP + 1];			//��������
	char			m_szGateway[CONST_MAXLENGTH_IP + 1];			//����

	char			m_szDNS[CONST_MAXLENGTH_IP + 1];				//DNS������IP��ַ

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_WIFIPARAM_H_