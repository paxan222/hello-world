#ifndef _REMOTERS485_H_
#define _REMOTERS485_H_

#include "DeviceInfoEx.h"
#include "SNPlatOS.h"
#include "ComOpenMode.h"

#ifndef byte
typedef unsigned char byte;
#endif

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

class SN_DLL_API RemoteRS485
{
public:
	RemoteRS485();

	RemoteRS485(const DeviceInfo &p_objDeviceInfo);

	RemoteRS485(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteRS485(void);
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
	*		������������Ƶ�豸֮������紫��ĳ�ʱʱ��
	**���룺
	*		p_nTimeout����ʱʱ�䣬�Ժ��루ms��Ϊ��λ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setTimeout(const int p_nTimeout);

	/************************************************************************
	**������
	*		������������Ƶ�豸֮������紫��Э��
	**���룺
	*		p_nTransferProtocol��Ҫ���õĴ���Э�飬������2������
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
	*		���ô��ڱ��
	**���룺
	*		p_nComId�����ڱ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setComId(const int p_nComId);

	/************************************************************************
	**������
	*		���ô��ڴ�ģʽ
	**���룺
	*		p_nComId�����ڴ�ģʽ��������2������
	*		ComOpenMode::OPENMODE_SHARE		������ʽ��	
	*		ComOpenMode::OPENMODE_EXCLUSIVE ����ռ��ʽ��	
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setOpenMode(const byte p_btComOpenMode);

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
	*		p_pszWriteDate����Ҫд��Ĵ�������,ÿ��д����󳤶�ΪCONST_MAXLENGTH_COMDATA
	*		p_nDateLen    ����Ҫд��Ĵ������ݳ���
	**�����
	*		��
	**����ֵ��
	*		��д�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int write(const char* p_pszWriteDate, const int p_nDateLen);

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
	int openCOM();

	int closeCOM();

	//�������캯��
	RemoteRS485(const RemoteRS485& p_objObject)
	{
	}

	//��ֵ����
	RemoteRS485& operator = (const RemoteRS485& p_objObject)
	{
		return *this;
	}

private:

	DeviceInfoEx	m_objDeviceInfoEx;			//�豸��Ϣ

	int				m_nComId;					//����id

	byte			m_btOpenMode;				//���ڴ�ģʽ

	ITransfer *		m_pobjTransfer;				//������

	InetAddr		m_objServerAddr;			//��ַ

	int				m_nTimeout;					//��ʱʱ�䣬�Ժ���Ϊ��λ��ms��

	int				m_nTransferProtocol;		//����Э��

	int				m_nSessionId;

	bool			m_bIsOpen;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif
