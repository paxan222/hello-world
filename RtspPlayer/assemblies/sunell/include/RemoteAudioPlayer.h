#ifndef _REMOTEAUDIOPLAER_H_
#define _REMOTEAUDIOPLAER_H_

#include "DeviceInfoEx.h"
#include "AVFrameData.h"
#include "SNPlatOS.h"
#include "AudioInfo.h"
#include "AVData.h"

class SNMutex;
class ITSAudioTransfer;

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

class SN_DLL_API RemoteAudioPlayer 
{
public:
	RemoteAudioPlayer();

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
	RemoteAudioPlayer(const DeviceInfo &p_objDeviceInfo);

	RemoteAudioPlayer(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteAudioPlayer();

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
	*		������������Ƶ�豸���������š�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��open�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ���û�����ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��Զ�̶Խ���������������������֮������ӣ��ɹ��򷵻�SN_SUCCESS��
	*		���򿪲��ɹ�������ݴ���������ز�ͬ����ֵ
	*************************************************************************/
	int			open();

	/************************************************************************
	**������
	*		�ر���������Ƶ�豸���������š�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�ر���������Ƶ�豸�������Խ���
	*************************************************************************/
	void		close();

	/***********************************************************************
	**������
	*		��Զ���豸�ﲥ��g723.1�������Ƶ����
	**���룺
	*		p_objAVFrameData�������Ǳ���G723.1����Ƶ����

			//���ݸ�ʽ����
			p_objAVFrameData.setStreamFormat(StreamFormat::ES_STREAM);
			p_objAVFrameData.setESStreamType(ESStreamType::AUDIO)
			p_objAVFrameData.setEncoderType(EncoderType::G7231) 
	**�����
	*		��
	**����ֵ��
	*			���������ݳɹ������� SN_SUCCESS;
	*			����������ʧ�ܣ����� < 0;
	**���ܣ�
	*
	************************************************************************/
	int write(AVFrameData &p_objAVFrameData);

	/***********************************************************************
	**������
	*		��Զ���豸�ﲥ�Ÿ�G723.1������TS��Ƶ����
	**���룺
	*		p_objAVFrameData��������G723.1������TS��Ƶ����
			
			//���ݸ�ʽ����
			p_objAVFrameData.setStreamFormat(StreamFormat::TS_STREAM)
			p_objAVFrameData.setESStreamType(ESStreamType::AUDIO)
			p_objAVFrameData.setEncoderType(EncoderType::G7231)
	**�����
	*		��
	**����ֵ��
	*			���������ݳɹ������� SN_SUCCESS;
	*			����������ʧ�ܣ����� < 0;
	**���ܣ�
	*
	************************************************************************/
	int writeTS(AVFrameData &p_objAVFrameData);

private:

	/***********************************************************************
	**������
	*		��ȡ��Ƶ��Ϣ
	**���룺
	*		��
	**�����
	*		p_objAudioInfo����Ƶ��Ϣ
	**����ֵ��
	*		����ȡ�ɹ�������CONSUME_SUCCESS
	*		����ȡʧ�ܣ�����SN_ERROR_DEVICE_NOT_OPEN
	**���ܣ�
	*
	************************************************************************/
	int			getAudioInfo(AudioInfo &p_objAudioInfo);

	int			write(AudioInfo &p_objAudioInfo, AVData &p_objAVData);

private:
	//�������캯��
	RemoteAudioPlayer(const RemoteAudioPlayer& p_objObject)
	{
	}

	//��ֵ����
	RemoteAudioPlayer& operator = (const RemoteAudioPlayer& p_objObject)
	{
		return *this;
	}

private:

	AudioInfo				m_objAudioInfo;					//��Ƶ��Ϣ

	int						m_nTransferProtocol;			//����Э��

	DeviceInfoEx			m_objDeviceInfoEx;

	ITSAudioTransfer		*m_pobjAudioTransfer;		//

	SNMutex *				m_pobjWriteMutex;

	bool					m_bIsOpen;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTEINTERPHONE_H_
