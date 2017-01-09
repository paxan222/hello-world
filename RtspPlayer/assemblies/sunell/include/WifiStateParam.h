#ifndef _WIFISTATEPARAM_H_
#define _WIFISTATEPARAM_H_

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

class SN_DLL_API WifiStateParam
{
public:
	enum WifiState
	{
		WIFI_STATE_DISCONNECT				= 0,	//δ����
		WIFI_STATE_CONNECTED				= 1,	//�Ѿ�����
		WIFI_STATE_CONNECT_FAILED_AND_TRY	= 2,	//����ʧ�ܲ�������������
		WIFI_STATE_CONNECT_FAILED			= 3		//����ʧ��
	};

public:
	WifiStateParam(void);
	~WifiStateParam(void);

public:
	/************************************************************************
	**������
	*		��������״̬
	**���룺
	*		p_nConnectState������״̬
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setConnectState(const int p_nConnectState);

	/************************************************************************
	**������
	*		��ȡ����״̬
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		
	************************************************************************/
	const int getConnectState() const;


	/************************************************************************
	**������
	*		�����ź�����
	**���룺
	*		p_nSignalQuality
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
	int		m_nConnectState;			//����״̬
	int		m_nSignalQuality;			//�ź�״̬
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_WIFISTATEPARAM_H_
