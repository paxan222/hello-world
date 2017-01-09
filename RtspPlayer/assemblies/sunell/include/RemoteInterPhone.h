#ifndef _REMOTEINTERPHONE_H_
#define _REMOTEINTERPHONE_H_


#include "DeviceInfoEx.h"
#include "SNPlatOS.h"

class RemoteInterPhoneIpml;

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

class SN_DLL_API RemoteInterPhone
{
public:

	RemoteInterPhone();
	/************************************************************************
	**������
	*		���캯��
	**���룺
	*		p_objDeviceInfo���豸��Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	RemoteInterPhone(const DeviceInfo &p_objDeviceInfo);

	RemoteInterPhone(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteInterPhone();

public:
	/************************************************************************
	**������
	*		����DeviceInfo
	**���룺
	*		DeviceInfo �豸��Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		���ò��������Ĺ��캯��������ʱ����open֮ǰ������ø÷���
	*************************************************************************/
	void	setDeviceInfo(const DeviceInfo &p_objDeviceInfo);

	void	setDeviceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

public:

	/************************************************************************
	**������
	*		���ú�������Ƶ�豸֮������紫��Э��
	**���룺
	*		p_nTransferProtocol��Ҫ���õĴ���Э�飬������3������
	*		TransferProtocol::UDP = 0X01,
	*		TransferProtocol::TCP = 0X02,
	*		TransferProtocol::RTP = 0X04
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void		setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**������
	*		������������Ƶ�豸�������Խ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��open�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ���û�����ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��Զ�̶Խ�����������Խ���֮������ӣ��ɹ��򷵻�SN_SUCCESS��
	*		���򿪲��ɹ�������ݴ���������ز�ͬ����ֵ
	*************************************************************************/
	int			start();

	/************************************************************************
	**������
	*		�ر���������Ƶ�豸�������Խ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�ر���������Ƶ�豸�������Խ���
	*************************************************************************/
	void		stop();

private:

	//�������캯��
	RemoteInterPhone(const RemoteInterPhone& p_objObject)
	{
	}

	//��ֵ����
	RemoteInterPhone& operator = (const RemoteInterPhone& p_objObject)
	{
		return *this;
	}
	
private:

	RemoteInterPhoneIpml*	m_pobjRemoteInterPhoneIpml;		//Զ�̶Խ�ʵ��

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTEINTERPHONE_H_
