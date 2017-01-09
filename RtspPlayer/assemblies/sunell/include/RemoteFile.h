#ifndef _REMOTEFILE_H_
#define _REMOTEFILE_H_

#include "DeviceInfoEx.h"
#include "SNError.h"
#include "SNPlatOS.h"

class  IFileConnector;

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

class SN_DLL_API RemoteFile
{

public:
	RemoteFile(const DeviceInfo &p_objDeviceInfo);
	RemoteFile(const DeviceInfoEx &p_objDeviceInfoEx);
	RemoteFile();

	~RemoteFile(void);

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
	void	setTransferProtocol(const int p_nTransferProtocol);

	void	setDeviceInfo(const DeviceInfo & p_objDeviceInfo);

	void	setDeviceInfo(const DeviceInfoEx & p_objDeviceInfoEx);

	/************************************************************************
	**������
	*		������������Ƶ�豸֮������ûỰ������Զ���豸���ļ�
	**���룺
	*		p_pszFileName���ļ����֣�����Ŀ¼(�磺D:/test/test.dat)
	*		p_nMode		 �� ���ļ���ģʽ(0x01��ֻ����ʽ�� 0x02�� д��ʽ�� 0x04�����鷽ʽ�� 0x20��������ʽ)
	**�����
	*		��
	**����ֵ��
	*		��open�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�    
	*
	************************************************************************/
	int open(const char *p_pszFileName, const unsigned char p_nMode = 0x01);

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
	int close();

	/************************************************************************
	**������
	*		��ȡԶ��������Ƶ�豸���ļ�����
	**���룺
	*		p_pszBuf	�������ȡ�����ļ�����
	*		p_nBufSize  ����Ҫ��ȡ���ļ����ݳ���
	**�����
	*		��
	**����ֵ��
	*		���ɹ���ȡ�������ݣ� > 0
	        �������ļ���β��== 0;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int read(char* p_pszBuf, const unsigned int p_nBufSize);

	/************************************************************************
	**������
	*		������д��Զ��������Ƶ�豸���ļ�
	**���룺
	*		p_pszBuf	����Ҫд����ļ�����
	*		p_nBufSize  ���ļ����ݳ���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int write(const char* p_pszBuf, const unsigned int p_nBufSize);

	/************************************************************************
	**������
	*		���¶�λ�ļ��Ķ�дλ��
	**���룺
	*		p_nOffset	����Ҫƫ�Ƶĳ���
	*		p_nSeekMode ��ƫ�Ƶ���ʼλ��.ö������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int seek(const INT64 p_nOffset, const unsigned char p_nSeekMode);

	/************************************************************************
	**������
	*		�����ļ��ĳ��ȣ����ֽڼ�
	**���룺
	*		p_nLength	����Ҫ���õ��ļ�����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	virtual int setLength(const INT64 p_nLength); 

	/************************************************************************
	**������
	*		�����ļ��ĳ��ȣ����ֽڼ�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�ļ��ĳ���
	**���ܣ�
	*		
	*************************************************************************/
	virtual int getLength (INT64 & p_nLength) const;

	/************************************************************************
	**������
	*		�ж��Ƿ��ȡ�����ļ�ĩβ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		true���Ѷ����ļ�ĩβ
	*		true��δ�����ļ�ĩβ
	**���ܣ�
	*		
	*************************************************************************/
	bool getFileEndFlag() const;

	int	ftell(INT64 &p_nPos);

private:

	DeviceInfoEx			m_objDeviceInfoEx;		//�豸��Ϣ

	int						m_nTransferProtocol;	//����Э��

	IFileConnector*			m_pobjFileConnector;	//�ļ���д������

	int						m_nSessionId;			//��ȫ�Ự

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
