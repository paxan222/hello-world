#ifndef _WIFIHOTSPOTPARAM_H_
#define _WIFIHOTSPOTPARAM_H_

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

class SN_DLL_API WifiHotspotParam
{
public:
	WifiHotspotParam(void);
	~WifiHotspotParam(void);

public:
	/************************************************************************
	**������
	*		����SSID
	**���룺
	*		p_pszSSID: SSID
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
	*		���ü�������
	**���룺
	*		p_pszEncryptionType����������
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	bool setEncryptionType(const char* p_pszEncryptionType);

	/************************************************************************
	**������
	*		��ȡ��������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		
	************************************************************************/
	const char* getEncryptionType() const ;


	/************************************************************************
	**������
	*		�����ź�����
	**���룺
	*		p_nSignalQuality���ź�����
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setSignalQuality(const int p_nSignalQuality);

	/************************************************************************
	**������
	*		��ȡ�ź�����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		
	************************************************************************/
	const int getSignalQuality() const;


private:
	char	m_szSSID[CONST_MAXLENGTH_SSID+1];
	char	m_szEncryptionType[CONST_MAXLENGTH_ENCRYPTION_TYPE+1];
	int		m_nSignalQuality;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_WIFIHOTSPOTPARAM_H_
