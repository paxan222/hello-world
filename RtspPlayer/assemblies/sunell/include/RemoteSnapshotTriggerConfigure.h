#ifndef _REMOTESNAPSHOTTRIGGERCONFIGURE_H_
#define _REMOTESNAPSHOTTRIGGERCONFIGURE_H_

#include "SNError.h"
#include "DeviceInfoEx.h"
#include "SnapshotTriggerParameter.h"
#include "SNPlatOS.h"
#include "AVData.h"

class AVPacketHead;
class ITransfer;
class Buffer;


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

class SN_DLL_API  RemoteSnapshotTriggerConfigure
{
public:
	enum _TrafficSnapshotMode
	{
		NORMAL_MODE		= 1,			//�ͻ�����ʹ��
		TEST_MODE		= 2				//����
	};

public:

	RemoteSnapshotTriggerConfigure();

	RemoteSnapshotTriggerConfigure(const DeviceInfo &p_objDeviceInfo);

	RemoteSnapshotTriggerConfigure(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteSnapshotTriggerConfigure(void);

public:

	/************************************************************************
	**������
	*		�����豸��Ϣ
	**���룺
	*		p_objDeviceInfo���豸��Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setDeivceInfo(const DeviceInfo &p_objDeviceInfo);

	void setDeivceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

	/************************************************************************
	**������
	*		������������Ƶ�豸֮������紫��Э��
	**���룺
	*		p_nTransferProtocolҪ���õĴ���Э�飬������2������
	*		TransferProtocol::UDP = 0X01,
	*		TransferProtocol::TCP = 0X02,
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		������������Ƶ�豸֮������紫��Э��
	*************************************************************************/
	void setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**������
	*		������������Ƶ�豸֮������ûỰ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��open�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		������������Ƶ�豸֮������ûỰ
	*************************************************************************/
	int open();

	/************************************************************************
	**������
	*		�ر���������Ƶ�豸�����ûỰ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�ر���������Ƶ�豸�����ûỰ
	*************************************************************************/
	void close();

	/************************************************************************
	**������
	*		����ץ��
	**���룺
	*		p_CameraId	�豸��ͨ����
	*		p_SnapshotMode	�������ͣ�NORMAL_MODE/TEST_MODE
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����ץ��
	*************************************************************************/
	int triggerSnapshot(int p_CameraId, int p_SnapshotMode);

	/************************************************************************
	**������
	*		��ȡץ��ͼ��
	**���룺
	*		p_CameraId	�豸��ͨ����
	**�����
	*		p_objAVData	��ȡ��ͼ������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡץ��ͼ��
	*************************************************************************/
	int getSnapshotPicture(int p_CameraId, AVData &p_objAVData);


public:
	/************************************************************************
	**������
	*		���ô�������
	**���룺
	*		p_pobjTransfer��������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setTransfer(ITransfer*	p_pobjTransfer);

	/************************************************************************
	**������
	*		����ͨѶ�ĳ�ʱʱ�䡣
	**���룺
	*		p_nTimeout����ʱʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setTimeout(int p_nTimeout);

private:
	int recvFrameData(AVData &p_objAVData, int p_nCameraId, int p_nTimeout);

	int recvAVPacketHead(AVPacketHead *p_pobjPacketHead, int p_nTimeout);

private:
	ITransfer*			m_pobjTransfer;					//������

	int					m_nTransferProtocol;			//����Э��

	DeviceInfoEx		m_objDeviceInfoEx;				//�豸��Ϣ

	int					m_nSessionId;					//�Ự����

	int					m_nTimeout;						//��ʱʱ�䣬�Ժ���Ϊ��λ

	bool				m_bIsOpen;

	//��������֡ͷ��ʶλ��trueΪû�н���֡ͷ��falseΪ�Ѿ�����֡ͷ
	bool				m_bNotRecvAVPacketHead;

	//��Ž��յ���֡ͷ�Ļ�����
	char				m_szAVPacketHead[CONST_LENGTH_AV_PACKET_HEAD];

	//AVPacketHead		m_objAVPacketHead;

	Buffer*				m_pobjFrameBuffer;

	int					m_nRecvLen;

	bool				m_bUsePrivateTransfer;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTESNAPSHOTTRIGGERCONFIGURE_H_
