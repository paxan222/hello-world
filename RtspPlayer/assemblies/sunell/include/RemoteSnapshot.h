#ifndef _REMOTE_SNAPSHOT_H_
#define _REMOTE_SNAPSHOT_H_


#include "SNError.h"
#include "DeviceInfoEx.h"
#include "SNPlatOS.h"
#include "AVData.h"
#include "RemoteSnapshotParam.h"
#include "SnapshotDownParam.h"
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

class SN_DLL_API  RemoteSnapshot
{

public:

	RemoteSnapshot();

	RemoteSnapshot(const DeviceInfo &p_objDeviceInfo);

	RemoteSnapshot(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteSnapshot(void);

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
	void setDeviceInfo(const DeviceInfo &p_objDeviceInfo);

	void setDeviceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

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
	*		ץ��һ��ͼ��
	**���룺
	*		p_objRemoteSnapshotParam��Զ��ץ�Ĳ���
	**�����
	*		p_objAVData����ȡ��ͼ������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		ץ��һ��ͼ��
	**ע�⣺
	*		�������ܿ��ǣ�p_objAVData������ڴ���sdk�ڲ����䣬�ڵ���close֮�������ڴ�ᱻ�ͷ�
	*		����close֮ǰ��ȷ��p_objAVData����ʹ��
	*************************************************************************/
	int getSnapshotPicture(const RemoteSnapshotParam& p_objRemoteSnapshotParam, AVData &p_objAVData);

	/************************************************************************
	**������
	*		ץ��һ��ͼ��
	**���룺
	*		p_objRemoteSnapshotParam��Զ��ץ�Ĳ���
	**�����
	*		p_objAVData����ȡ��ͼ������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		ץ��һ��ͼ��
	**ע�⣺
	*		�������ܿ��ǣ�p_objAVData������ڴ���sdk�ڲ����䣬�ڵ���close֮�������ڴ�ᱻ�ͷ�
	*		����close֮ǰ��ȷ��p_objAVData����ʹ��
	*************************************************************************/
	int getSnapshotPictureV2(const RemoteSnapshotParam& p_objRemoteSnapshotParam, AVData &p_objAVData);

	int getSnapshotFile(const SnapshotDownParam& p_objSnapshotParam, char* p_Data, int &nLen);

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

	//�������캯��
	RemoteSnapshot(const RemoteSnapshot& p_objObject)
	{
	}

	//��ֵ����
	RemoteSnapshot& operator = (const RemoteSnapshot& p_objObject)
	{
		return *this;
	}

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

	Buffer*				m_pobjFrameBuffer;

	int					m_nRecvLen;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTE_SNAPSHOT_H_
