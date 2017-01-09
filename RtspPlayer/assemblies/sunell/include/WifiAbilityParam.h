#ifndef _WIFIABILITYPARAM_H_
#define _WIFIABILITYPARAM_H_

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

class SN_DLL_API WifiAbilityParam
{
public:
	WifiAbilityParam(void);
	~WifiAbilityParam(void);

public:

	/************************************************************************
	*	�����������Ƿ�֧�ֱ�־
	*	���룺
	*		p_nSupportFlag���Ƿ�֧�ֱ�־
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	void setSupportFlag(const bool p_nSupportFlag);

	/************************************************************************
	*	��������ȡ�Ƿ�֧�ֱ�־
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		m_nLCPTimeout
	************************************************************************/
	const bool getSupportFlag() const;


	/************************************************************************
	*	����������Wifi�豸��
	*	���룺
	*		p_pszWifiDeviceName��Wifi�豸��
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	bool setWifiDeviceName(const char* p_pszWifiDeviceName);

	/************************************************************************
	*	��������ȡWifi�豸��
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		Wifi�豸��
	************************************************************************/
	const char* getWifiDeviceName() const ;

private:
	bool			m_bSupportFlag;														//�Ƿ�֧�ֱ�־
	char			m_szWifiDeviceName[CONST_MAXLENGTH_WIFI_DEVICE_NAME+1];				//Wifi�豸��

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_WIFIABILITYPARAM_H_
