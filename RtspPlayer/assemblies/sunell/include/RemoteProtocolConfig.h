#ifndef _REMOTEPROTOCOLCONFIG_H_
#define _REMOTEPROTOCOLCONFIG_H_

#include "DeviceInfoEx.h"
#include "SNPlatOS.h"
#include "ProtocolConfigParam.h"
#include "ProtocolConfigAbility.h"

#define CONST_ALL	-1		//��ȡ������ȫ��

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

class SN_DLL_API RemoteProtocolConfig
{
public:
	RemoteProtocolConfig();

	RemoteProtocolConfig(DeviceInfo& p_objDeviceInfo);

	RemoteProtocolConfig(DeviceInfoEx& p_objDeviceInfoEx);

	~RemoteProtocolConfig();
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
	void setDeviceInfo(const DeviceInfo &p_objDeviceInfo);

	void setDeviceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

public:
	/************************************************************************
	**������
	*		���ô���Э��
	**���룺
	*		p_nTransferProtocol��Ҫ���õĴ���Э�飬������3������
	*		TransferProtocol::UDP = 0X01,
	*		TransferProtocol::TCP = 0X02,
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**������
	*		������������Ƶ�豸֮������ûỰ������Զ���豸���ļ�
	**���룺
	*		p_pszFileName���ļ����֣������¼���ļ���ָȫ�ƣ�����Ŀ¼(�磺D:/test/test.dat)
	*								 �����ͼƬ��ָͼƬ�ļ����֣�û��·����(�磺picture.bmp)
	**�����
	*		��
	**����ֵ��
	*		��open�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�    
	*
	************************************************************************/
	int open();

	/************************************************************************
	**������
	*		�ر���������Ƶ�豸�����ûỰ�����رմ򿪵��ļ�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�ر���������Ƶ�豸�����ûỰ
	*************************************************************************/
	void setTimeout(int p_nTimeout);
	void close();

	int setProtocolConfigParam(const ProtocolConfigParam &p_objProtocolConfigParam);

	int getProtocolConfigParam(ProtocolConfigParam &p_objProtocolConfigParam);

	int getProtocolConfigAbility(ProtocolConfigAbility &p_objProtocolConfigAbility);

private:
	//�������캯��
	RemoteProtocolConfig(const RemoteProtocolConfig& p_objObject)
	{
	}

	//��ֵ����
	RemoteProtocolConfig& operator = (const RemoteProtocolConfig& p_objObject)
	{
		return *this;
	}

private:

	DeviceInfoEx			m_objDeviceInfoEx;		//�豸��Ϣ

	int						m_nTransferProtocol;	//����Э��

	int						m_nSessionId;			//��ȫ�Ự

	ITransfer *				m_pobjTransfer;			//������

	int						m_nTimeout;				//��ʱʱ�䣬�Ժ���Ϊ��λ��ms��

	bool					m_bIsOpen;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif
