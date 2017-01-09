#ifndef _REMOTECAMERA_H_
#define _REMOTECAMERA_H_

#include "DeviceInfoEx.h"
#include "AVFrameData.h"
#include "AVData.h"
#include "VideoInfo.h"
#include "AudioInfo.h"
#include "SNError.h"
#include "SNPlatOS.h"

namespace MPEG_TS
{
	class MPEG_TS_Unpackager;
	class MPEG_TS_Packager;
}

class SNMutex;
class IAVConnector;

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

class SN_DLL_API RemoteCamera
{
public:
	RemoteCamera();

	RemoteCamera(const DeviceInfo &p_objDeviceInfo, const int p_nCameraID);

	RemoteCamera(const DeviceInfoEx &p_objDeviceInfoEx, const int p_nCameraID);

	~RemoteCamera(void);

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

	/************************************************************************
	**������
	*		����Ҫ�򿪵��������
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
	*		����Ĭ�ϵĸ�ʽ
	**���룺
	*		p_nImageFormatId:Ҫ���õĸ�ʽ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		��open ֮ǰ��ΪԶ�����������Ĭ�ϵĸ�ʽ
	*************************************************************************/
	void	setDefaultImageFormatId(const unsigned int p_nImageFormatId);

	/************************************************************************
	**������
	*		����Ĭ�ϵı���֡�ʡ�
	**���룺
	*		p_nFrameRateҪ�ı�ı���֡��,�� ֡/s Ϊ��λ��
	**�����
	*		��
	*************************************************************************/
	void setDefaultFrameRate(const unsigned int p_nFrameRate);

	/************************************************************************
	**������
	*		����Ĭ�ϵĵ�ǰ���ʡ�
	**���룺
	*		p_nBitRate��Ҫ�ı�����ʣ���bit/sΪ��λ��
	**�����
	*		��
	**���ܣ�
	*		��open ֮ǰ������Ĭ�ϵ�����
	*************************************************************************/
	void setDefaultBitRate(const unsigned int p_nBitRateType, const unsigned int p_nBitRate);

	/************************************************************************
	**������
	*		����Ĭ�ϵ�ͼ��������
	**���룺
	*		p_nQuality��Ҫ���õ�ͼ����������ΧΪ[1--7]��1Ϊ������ã��������
	**�����
	*		��
	*		��open ֮ǰ������Ĭ�ϵ�����
	*************************************************************************/
	void setDefaultQuality(const unsigned int p_nQuality);

	/************************************************************************
	**������
	*		����Ĭ�ϵ�I֡���ʱ�䡣
	**���룺
	*		p_nIFrameInterval��Ҫ���õ�I֡���ʱ�䣬��λΪ��
	**�����
	*		��
	*		��open ֮ǰ������Ĭ�ϵ�I֡���ʱ��
	*************************************************************************/
	void setDefaultIFrameInterval(const unsigned int p_nIFrameInterval);

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
	*		��open ֮ǰ��ΪԶ����������ô���Э��
	*************************************************************************/
	void	setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**������
	*		��Զ�������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��open�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ���û�����ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��Զ��������������������֮������ӣ��ɹ��򷵻�SN_SUCCESS��
	*		���򿪲��ɹ�������ݴ���������ز�ͬ����ֵ
	*************************************************************************/
	int		open();

	/************************************************************************
	**������
	*		��ȡ�����������Ƶ����
	**���룺
	*		��
	**�����
	*		p_objAVFrameData��AVFrameData��������ã����ն�ȡ����Ƶ���ݡ�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		����ȡ���ݳ�ʱ������SN_ERROR_NETWORKIO_RECEIVE_TIMEOUT��
	*		����������ʧ�ܣ�����������С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ���������Ƶ����
	*************************************************************************/
	int		read(AVFrameData &p_objAVFrameData);

	/************************************************************************
	**������
	*		��ȡ�����������ƵTS������
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
	*		�ر���������Ĵ���Ự
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�ر���������Ĵ���Ự
	*************************************************************************/
	void	close();

public:
	/************************************************************************
	**������
	*		������Ƶ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ�ܣ�����������С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ���������Ƶ����
	*************************************************************************/
	int startAudio();

	/************************************************************************
	**������
	*		�ر���Ƶ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ�ܣ�����������С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ���������Ƶ����
	*************************************************************************/
	int stopAudio();

public:
	/************************************************************************
	**������
	*		��ȡ��ǰ��Ƶ֡��������Ϣ
	**���룺
	*		��
	**�����
	*		p_objVideoInfo��VideoInfo���������á�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ��ǰ��Ƶ֡��������Ϣ
	*************************************************************************/
	int		getVideoInfo(VideoInfo & p_objVideoInfo);

	int		getAudioInfo(AudioInfo & p_objAudioInfo);

public:

	/************************************************************************
	**������
	*		ǿ��I֡��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int makeKeyFrame();

	/************************************************************************
	**������
	*		������������Ƶ��ʽ��
	**���룺
	*		��
	**�����
	*		p_nVideoSystem�����������Ƶ��ʽ��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		������������Ƶ��ʽ
	*************************************************************************/
	int getVideoSystem(int & p_nVideoSystem);

	/************************************************************************
	**������
	*		�ı䵱ǰ��Ƶ�ĸ�ʽ��
	**���룺
	*		p_nImageFormatId��Ҫ�ı����Ƶ��ʽ����������������
	*		ImageFormat::RESOLUTION_D1					= 1, //PAL 704*576,25frame�� NTSC 704*480 30framre
	*		ImageFormat::RESOLUTION_LOW_BITRATE_D1		= 2, //PAL 704*576 12.5frame��NTSC 704*480 15framre
	*		ImageFormat::RESOLUTION_CIF					= 4, //PAL 352*288 25frame��NTSC 352*240 30framre
	*		ImageFormat::RESOLUTION_QCIF				= 5, //PAL 176*144 25frame��NTSC 176*120 30framre
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		�ı䵱ǰ��Ƶ�ĸ�ʽ��
	*************************************************************************/
	int setCurrentImageFormatId(const unsigned int p_nImageFormatId);

	/************************************************************************
	**������
	*		��õ�ǰ��Ƶ�ĸ�ʽ��
	**���룺
	*		��
	**�����
	*		p_nImageFormatId����õ��ĵ�ǰ��Ƶ��ʽ��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��õ�ǰ��Ƶ�ĸ�ʽ
	*************************************************************************/
	int getCurrentImageFormatId(unsigned int & p_nImageFormatId);

	/************************************************************************
	**������
	*		�ı䵱ǰ��Ƶ�ı���֡�ʡ�
	**���룺
	*		p_nFrameRateҪ�ı�ı���֡��,�� ֡/s Ϊ��λ��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		�ı䵱ǰ��Ƶ�ı���֡��
	*************************************************************************/
	int setCurrentFrameRate(const unsigned int p_nFrameRate);

	/************************************************************************
	**������
	*		��������õı���֡�ʡ�
	**���룺
	*		��
	**�����
	*		p_nFrameRate�������ȡ���ĵ�ǰ����֡�ʣ��� ֡/s Ϊ��λ��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��������õı���֡��
	*************************************************************************/
	int getCurrentFrameRate(unsigned int & p_nFrameRate);

	/************************************************************************
	**������
	*		�ı䵱ǰ���ʡ�
	**���룺
	*		p_nBitRate��Ҫ�ı�����ʣ���bit/sΪ��λ��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		�ı䵱ǰ���ʡ�
	*************************************************************************/
	int setCurrentConfirmBitRate(const unsigned int p_nBitRateType, const unsigned int p_nConfirmBitRate);

	/************************************************************************
	**������
	*		��õ�ǰ���ʡ�
	**���룺
	*		��
	**�����
	*		p_nBitRate�����浱ǰ��ȡ�����ʣ� ��bit/sΪ��λ��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��õ�ǰ���ʡ�
	*************************************************************************/
	int getCurrentConfirmBitRate(unsigned int & p_nBitRateType, unsigned int & p_nConfirmBitRate);

	/************************************************************************
	**������
	*		���õ�ǰQֵ��
	**���룺
	*		p_nQuant��Ҫ���õ�Q����ֵ����������������ΧΪ��3��48��������3��48��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		���õ�ǰQֵ
	*************************************************************************/
	int setCurrentQuant(const unsigned int p_nQuant);

	/************************************************************************
	**������
	*		��õ�ǰQֵ��
	**���룺
	*		��
	**�����
	*		p_nQuant��Ҫ��õ��ĵĵ�ǰQ����ֵ����������������ΧΪ��3��48��������3��48��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��õ�ǰQֵ��
	*************************************************************************/
	int getCurrentQuant(unsigned int & p_nQuant);

	/************************************************************************
	**������
	*		���õ�ǰͼ��������
	**���룺
	*		p_nQuality��Ҫ���õ�ͼ����������ΧΪ[1--7]��1Ϊ������ã��������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		���õ�ǰͼ������
	*************************************************************************/
	int setCurrentQuality(const unsigned int p_nQuality);

	/************************************************************************
	**������
	*		��õ�ǰͼ��������
	**���룺
	*		��
	**�����
	*		p_nQuality��Ҫ��õ��ĵĵ�ǰͼ����������ΧΪ[1--7]��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��õ�ǰͼ��������
	*************************************************************************/
	int getCurrentQuality(unsigned int &p_nQuality);

	/************************************************************************
	**������
	*		����I֡���ʱ��
	**���룺
	*		p_nIFrameInterval��Ҫ���õ�I֡���ʱ�䣬��λΪ��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�       
	*
	************************************************************************/
	int setCurrentIFrameInterval(const unsigned int p_nIFrameInterval);

	/************************************************************************
	**������
	*		�õ������õ�I֡���ʱ��
	**���룺
	*		��
	**�����
	*		p_nIFrameInterval��I֡���ʱ��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�       
	*
	************************************************************************/
	int getCurrentIFrameInterval(unsigned int & p_nIFrameInterval);

private:

	void initPacket();

	int unpacketTS(AVData &p_objTSAVdata, AVFrameData &p_objEsAVdata);

	//�������캯��
	RemoteCamera(const RemoteCamera& p_objObject)
	{
	}

	//��ֵ����
	RemoteCamera& operator = (const RemoteCamera& p_objObject)
	{
		return *this;
	}

private:

	DeviceInfoEx			m_objDeviceInfoEx;

	int						m_nCameraID;

	int						m_nTransferProtocol;

	IAVConnector *			m_pobjVideoConnector;

	unsigned int			m_nDefaultImageFormatId;
	unsigned int			m_nDefaultFrameRate;
	unsigned int			m_nDefaultBitRateType;
	unsigned int			m_nDefaultBitRate;
	unsigned int			m_nDefaultQuality;
	unsigned int			m_nDefaultIFrameInterval;

	bool					m_bConnectSuccessFlag;

	bool					m_bFirstConsume;

	MPEG_TS::MPEG_TS_Unpackager		*m_pobjMPEGTSUnpackager;

	int						m_nErrorTime;

	int						m_nStreamFormat;

	int						m_nCurFrameRate;

	MPEG_TS::MPEG_TS_Packager	*	m_pobjPackager;
	unsigned short			m_nvideoID ;
	unsigned short			m_naudioID;
	unsigned char		*	m_szPacketBuf ;

	SNMutex *				m_pobjReadMutex;
	SNMutex *				m_pobjSetParamMutex;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTECAMERA_H_
