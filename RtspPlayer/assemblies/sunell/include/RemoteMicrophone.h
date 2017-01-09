#ifndef _REMOTEMICROPHONE_H_
#define _REMOTEMICROPHONE_H_

#include "DeviceInfoEx.h"
#include "AVFrameData.h"
#include "SNError.h"
#include "SNPlatOS.h"
#include "AVData.h"
#include "AudioInfo.h"
#include "AudioEncodeQuality.h"


namespace MPEG_TS
{
	class MPEG_TS_Unpackager;
	class MPEG_TS_Packager;
}

class SNMutex;
class ITSAudioConnector;

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

class SN_DLL_API RemoteMicrophone
{
public:
	RemoteMicrophone();

	RemoteMicrophone(const DeviceInfo &p_objDeviceInfo, const int p_nCameraID);

	RemoteMicrophone(const DeviceInfoEx &p_objDeviceInfoEx, const int p_nCameraID);

	~RemoteMicrophone(void);

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

	/************************************************************************
	**������
	*		����Ҫ�򿪵���˷��Ӧ���������
	**���룺
	*		p_nCameraID �������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		���ò��������Ĺ��캯��������ʱ����open֮ǰ������ø÷���
	*************************************************************************/
	void	setCameraID(const int p_nCameraID);

public:
	/************************************************************************
	**������
	*		���ô���Э��
	**���룺
	*		p_nTransferProtocolҪ���õĴ���Э�飬������3������
	*		TransferProtocol::UDP = 0X01,
	*		TransferProtocol::TCP = 0X02,
	*		TransferProtocol::RTP = 0X04
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		ΪԶ����˷����ô���Э��
	*************************************************************************/
	void	setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**������
	*		�����������Ӧ�������豸��������RemoteMicrophone��������Ƶ�豸֮��Ĵ���Ự��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��open�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ���û�����ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��Զ����˷粢��������˷�֮������ӣ��ɹ��򷵻�SN_SUCCESS��
	*		���򿪲��ɹ�������ݴ���������ز�ͬ����ֵ
	*************************************************************************/
	int		open();

	/************************************************************************
	**������
	*		��ȡ��˷����Ƶ����
	**���룺
	*		��
	**�����
	*		p_objAVFrameData��AVFrameData��������ã����ն�ȡ����Ƶ���ݡ�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		����ȡ���ݳ�ʱ������SN_ERROR_NETWORKIO_RECEIVE_TIMEOUT��
	*		����������ʧ�ܣ�����������С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ��˷����Ƶ����
	*************************************************************************/
	int		read(AVFrameData &p_objAVFrameData);

	/************************************************************************
	**������
	*		��ȡ��˷����ƵTS������
	**���룺
	*		��
	**�����
	*		p_objAVFrameData��AVFrameData��������ã����ն�ȡ����ƵTS�����ݡ�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		����ȡ���ݳ�ʱ������SN_ERROR_NETWORKIO_RECEIVE_TIMEOUT��
	*		����������ʧ�ܣ�����������С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int		readTS(AVFrameData &p_objAVFrameData);

	/************************************************************************
	**������
	*		�ر�����˷�Ĵ���Ự
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�ر�����˷�Ĵ���Ự
	*************************************************************************/
	void	close();

	/************************************************************************
	**������
	*		��ȡ��ǰ��Ƶ֡��������Ϣ
	**���룺
	*		��
	**�����
	*		p_objAudioInfo��AudioInfo���������á�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ��ǰ��Ƶ֡��������Ϣ
	*************************************************************************/
	int		getAudioInfo(AudioInfo & p_objAudioInfo);

private:
	void initPacket();

	int unpacketTS(AVData &p_objTSAVdata, AVFrameData &p_objAVFrameData);

	//�������캯��
	RemoteMicrophone(const RemoteMicrophone& p_objObject)
	{
	}

	//��ֵ����
	RemoteMicrophone& operator = (const RemoteMicrophone& p_objObject)
	{
		return *this;
	}

private:

	DeviceInfoEx			m_objDeviceInfoEx;

	int						m_nCameraID;

	AudioEncodeQuality		m_objAudioEncodeQuality;

	int						m_nTransferProtocol;

	ITSAudioConnector *		m_pobjAudioConnector;

	MPEG_TS::MPEG_TS_Unpackager*	m_pobjMPEGTSUnpackager;

	MPEG_TS::MPEG_TS_Packager	*	m_pobjPackager;
	unsigned short		m_naudioID;
	unsigned char		*m_szPacketBuf ;

	SNMutex *				m_pobjReadMutex;
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
