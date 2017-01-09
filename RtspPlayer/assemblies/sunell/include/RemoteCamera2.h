#ifndef _REMOTECAMERA2_H_
#define _REMOTECAMERA2_H_

#include "DeviceInfoEx.h"
#include "AVFrameData.h"
#include "AVData.h"
#include "SNError.h"
#include "SNPlatOS.h"
#include "AVDataStruct.h"

#include <vector>

namespace MPEG_TS
{
	class MPEG_TS_Unpackager;
	class MPEG_TS_Packager;
}

class SNMutex;
class IAVStreamConnector;
class Mpeg2PSEncoderEX;

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

class SN_DLL_API RemoteCamera2
{
public:
	RemoteCamera2();

	RemoteCamera2(const DeviceInfoEx &p_objDeviceInfoEx, const int p_nCameraId, const int p_nStreamId);

	~RemoteCamera2(void);

public:
	//��AVStreamTCPConnetor�����ⲿbuffer
	void setExternalRecvBuffer(char *p_szExternalRevcBuffer);

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
	void setDeviceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

	/************************************************************************
	**������
	*		����ͨѶ�ĳ�ʱʱ�䡣
	**���룺
	*		p_nTimeOut����ʱʱ��,�Ժ���Ϊ��λ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setTimeout(int p_nTimeout);

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
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**������
	*		����Ĭ��������Ƶ������ID
	**���룺
	*		p_nStreamId ������ID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		���ò��������Ĺ��캯��������ʱ����open֮ǰ������ø÷���
	*************************************************************************/
	void setDefaultStreamId(const int p_nStreamId);

	/************************************************************************
	**������
	*		����ʹ�öಥ����
	**���룺
	*		p_bFlag ��true��ʾ���öಥ���䣬flase��ʾ�����öಥ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		ע����ʹ�öಥ����ǰ������ͨ��RemotSystem���öಥ�����ַ��
	*************************************************************************/
	void setMulticastFlag(bool p_bFlag);

	/************************************************************************
	**������
	*		��ȡ��ǰ�Ķಥ�����ʶ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		true��ʾ���öಥ���䣬flase��ʾ�����öಥ
	**���ܣ�
	*		
	*************************************************************************/
	bool getMulticastFlag();

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
	*		��ȡ�����������ƵPS������
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
	int		readPS(AVFrameData &p_objAVFrameData);
	
	int     readData(std::vector<AVDataStruct>& p_objAVDataStructList);

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
	*		��ͣ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ�ܣ�����������С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int		pause();

	/************************************************************************
	**������
	*		�ָ�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ�ܣ�����������С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int		resume();

	/************************************************************************
	**������
	*		��������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ�ܣ�����������С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int		keepAlive();

	/************************************************************************
	**������
	*		ֹͣ����P֡
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ�ܣ�����������С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		�ڵ��ø÷����󣬶�������Ƶ���ݾ�ֻ��I֡��������P֡��
	*************************************************************************/
	int		stopPFrame();

	/************************************************************************
	**������
	*		�ָ�����P֡
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ�ܣ�����������С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		�ڵ��ø÷����󣬶�������Ƶ���ݾͻ���P֡��
	*************************************************************************/
	int		resumePFrame();

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

	/************************************************************************
	**������
	*		�������ܷ�����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ�ܣ�����������С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		�������ܷ������ݣ�������Ƶ���С�
	*************************************************************************/
	int startIntelligenceAnalyse();
	/************************************************************************
	**������
	*		�ر����ܷ�����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ�ܣ�����������С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		�ر����ܷ������ݡ�
	*************************************************************************/
	int stopIntelligenceAnalyse();
public:
	/************************************************************************
	**������
	*		���õ�ǰ����ID
	**���룺
	*		p_nStreamId������ID
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*	
	*************************************************************************/
	int setCurrentStreamId(int p_nStreamId);

	/************************************************************************
	**������
	*		��ȡ��ǰ����ID
	**���룺
	*		��
	**�����
	*		p_nStreamId������ID
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*	
	*************************************************************************/
	int getCurrentStreamId(int & p_nStreamId);

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

	//���·���������˾�ڲ�ʹ��
public:
//#ifdef WIN32
#if (defined(WIN32) || defined(_WIN32_WCE))
	int getSocketHandle(unsigned int & p_socketHandle);
#else
	int getSocketHandle(int & p_socketHandle);
#endif
	//��ȡ����Ƶ���ݣ�����epoll��ʽ��ȡʱ��p_bUseEpoll����Ϊtrue����һ�ζ�ȡʱp_bIsFirstΪtrue��ֻ����ʹ��epoll��ʽ��ȡʱp_bIsFirst����Ч��
	int	readEx(AVFrameData &p_objAVFrameData, bool p_bUseEpoll = false, bool p_bIsFirst = true);
	int	readTSEx(AVFrameData &p_objAVFrameData);
	int	readPSEx(AVFrameData &p_objAVFrameData);
	void setSocketBufSize(int p_nSize);

private:

	void initPacket();

	int unpacketTS(AVData &p_objTSAVdata, AVFrameData &p_objEsAVdata, bool p_bCopyFlag = true);

	//�������캯��
	RemoteCamera2(const RemoteCamera2& p_objObject)
	{
	}

	//��ֵ����
	RemoteCamera2& operator = (const RemoteCamera2& p_objObject)
	{
		return *this;
	}

private:
	DeviceInfoEx			m_objDeviceInfoEx;
	int						m_nTimeout;						//��ʱʱ�䣬�Ժ���Ϊ��λ
	int						m_nCameraId;
	int						m_nStreamId;
	int						m_nTransferProtocol;
	IAVStreamConnector *	m_pobjAVStreamConnector;
	bool					m_bConnectSuccessFlag;
	bool					m_bFirstConsume;
	MPEG_TS::MPEG_TS_Unpackager * m_pobjMPEGTSUnpackager;
	MPEG_TS::MPEG_TS_Packager *	m_pobjPackager;
	Mpeg2PSEncoderEX*		m_pobjMpeg2PSEncoder;
	unsigned short			m_nvideoID ;
	unsigned short			m_naudioID;
	unsigned char		*	m_szPacketBuf ;
	char*				m_szPrivateDataBuffer;	
	char*					m_pszExternalRecvBuffer;
	SNMutex *				m_pobjReadMutex;
	SNMutex *				m_pobjSetParamMutex;
	bool					m_bMulticastFlag;
	int						m_nSocketBufSize;	
	bool					m_bIsUsedExternalRecvBuffer;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_RemoteCamera2_H_
