#ifndef _REMOTERS485EX_H_
#define _REMOTERS485EX_H_

#include "DeviceInfoEx.h"
#include "RS485Device.h"
#include "SNPlatOS.h"

#ifndef byte
typedef unsigned char byte;
#endif

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

class SN_DLL_API RemoteRS485Ex
{
public:
	RemoteRS485Ex();
	RemoteRS485Ex(const DeviceInfoEx &p_objDeviceInfoEx, const RS485Device & p_objRS485Device);
	~RemoteRS485Ex(void);

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
	void setDeviceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

	/************************************************************************
	**������
	*		���ô��ڲ���
	**���룺
	*		p_objRS485Device�����ڲ���
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setRS485Device(const RS485Device & p_objRS485Device);

	/************************************************************************
	**������
	*		������������Ƶ�豸֮���Զ�̴��ڻỰ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��open�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int open();

	/************************************************************************
	**������
	*		�Դ��ж˿ڽ���д����
	**���룺
	*		p_pszWriteDate����Ҫд��Ĵ������ݡ�
	*		p_nDateLen    ����Ҫд��Ĵ������ݳ���
	**�����
	*		��
	**����ֵ��
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*		���ɹ��򷵻ش���0��ֵ������ֵ��ʾ����д�ɹ������ݳ��ȡ�
	**���ܣ�
	*		
	*************************************************************************/
	int write(const char* p_pszWriteDate, const int p_nDateLen);

	/************************************************************************
	**������
	*		�Դ��ж˿ڽ��ж�����
	**���룺
	*		p_pszReadBuf�������ݵĽ��ջ��壬�������û��ȷ�����ڴ档
	*		p_nReadBufSize��������ȡ�����ݳ��ȣ��ó��Ȳ��ܴ��ڽ��ջ���ĳ��ȡ�
	**�����
	*		��
	**����ֵ��
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*		���ɹ��򷵻ش���0��ֵ������ֵ��ʾ���ζ��ɹ������ݳ��ȡ�
	**���ܣ�
	*		
	*************************************************************************/
	int read(char * p_pszReadBuf, int p_nReadBufSize);

	/************************************************************************
	**������
	*		�ر���������Ƶ�豸�����ûỰ�����رմ򿪵�Զ�̴���
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

private:
	int resquestAddress(InetAddr & p_objServerAVAddr);
	int createDataChannel(InetAddr & p_objServerAVAddr, ITransfer *& p_pobjTransfer, int & p_nDataChannelId);
	int requestRS485(int p_nDataChannelId);
	int parseCommand(Buffer* p_pobjRecvCommandBuffer, char* p_pszReadBuf);

private:
	DeviceInfoEx	m_objDeviceInfoEx;			//�豸��Ϣ
	RS485Device		m_objRS485Device;			//�����豸
	ITransfer *		m_pobjRS485ChannelTransfer;				//������
	int				m_nTimeout;					//��ʱʱ�䣬�Ժ���Ϊ��λ��ms��
	int				m_nSessionId;
	bool			m_bIsOpen;
	int				m_nConsumerId;
	int				m_nWriteSeq;
	int				m_nReadSeq;
	int				m_nErrorno;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif
