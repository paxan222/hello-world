#ifndef _CMSDEVICEMODIFYER_H_
#define _CMSDEVICEMODIFYER_H_

//#if (defined(WIN32) || defined(_WIN32_WCE))

#include "SNError.h"
#include "SNPlatOS.h"
#include "HostNetwork.h"
#include "InetAddr.h"

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

class SN_DLL_API CMSDeviceModifyer
{

public:

	CMSDeviceModifyer();

	~CMSDeviceModifyer(void);

public:

	/************************************************************************
	**������
	*		�����豸�����ַ
	**���룺
	*		p_objDeviceAddr ��������ַ
	*		p_objHostNetwork��Ҫ���õ��豸������Ϣ
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setHostNetwork(InetAddr& p_objLocalAddr, HostNetwork& p_objHostNetwork);
	int setHostNetwork(InetAddr& p_objLocalAddr, HostNetwork& p_objHostNetwork, const char* p_szBindNetworkCardName);

private:

	int sendHostNetworkCommand(ITransfer* p_pobjTransfer, HostNetwork& p_objHostNetwork);
	int recvResponeCommand(ITransfer* p_pobjTransfer);

	int openMultiTranfser(const InetAddr& p_objBindAddr, ITransfer*& p_pobjTransfer);
	int openMultiTranfser(const InetAddr& p_objBindAddr, ITransfer*& p_pobjTransfer, const char* p_szBindNetworkCardName);

	int openIPv6Tranfser(const InetAddr& p_objBindAddr, ITransfer*& p_pobjTransfer);
	bool initIPv6Socket(char* p_szMultiIp, unsigned short p_nPort, const InetAddr& p_objDeviceAddr, unsigned int& p_nSocket);

	int openIPv4Tranfser(const InetAddr& p_objBindAddr, ITransfer*& p_pobjTransfer);
	int openIPv4Tranfser(const InetAddr& p_objBindAddr, ITransfer*& p_pobjTransfer, const char* p_szBindNetworkCardName);

	/************************************************************************
	**������
	*		�رմ�����
	**���룺
	*		p_pobjTransfer��������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	void closeMultiTransfer(ITransfer*& p_pobjTransfer);
	void closeTransfer(ITransfer*& p_pobjTransfer);

	void dropMulticast(ITransfer* p_pobjTransfer);

	//�������캯��
	CMSDeviceModifyer(const CMSDeviceModifyer& p_objObject)
	{
	}

	//��ֵ����
	CMSDeviceModifyer& operator = (const CMSDeviceModifyer& p_objObject)
	{
		return *this;
	}

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


//#endif //defined(WIN32) || defined(_WIN32_WCE)
#endif //_CMSDEVICEMODIFYER_H_
