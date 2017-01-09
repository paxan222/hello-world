#ifndef _REMOTE_VIDEO_FILE_H_
#define _REMOTE_VIDEO_FILE_H_

#include "DeviceInfoEx.h"
#include "SNPlatOS.h"
#include "RecordInfo.h"

class IFileConnector;
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

class SN_DLL_API RemoteVideoFile
{
public:
	RemoteVideoFile();

	RemoteVideoFile(DeviceInfo& p_objDeviceInfo);

	RemoteVideoFile(DeviceInfoEx& p_objDeviceInfoEx);
	
	~RemoteVideoFile();
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
	int open(const char *p_pszFileName); //�˽ӿڷ���

	int open(const RecordInfo & p_objRecordInfo,bool p_IsNeedLocateIFrame = true);
	
	/************************************************************************
	**������
	*		Զ�̴�������¼���ļ�
	**���룺
	*		p_pszFileName���ļ����֣�û��·����
	**�����
	*		��
	**����ֵ��
	*		��open�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�    
	*
	************************************************************************/
	int	openFtpFile(const char *p_pszFileName);

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
	*		> 0�� �ɹ���ȡ���ֽ���
	*		= 0�� �����ļ�ĩβ
	*		< 0�� ��ȡʧ�ܣ�����ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int read(char* p_pszBuf, const unsigned int p_nBufSize);
	int readEx(char *p_pszBuf, unsigned int p_nBufSize);

	/************************************************************************
	**������
	*		���¸���ʱ�䶨λ¼��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int locateTime(const unsigned long p_nTime);

	/************************************************************************
	**������
	*		��λ����ǰλ�õ���һ��I֡����ʿ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int locateNextIFrame();

	/************************************************************************
	**������
	*		��λ����ǰλ�õ�ǰһ��I֡��λ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int locatePreIFrame();

	/************************************************************************
	**������
	*		��λ��ʱ���ǰһ��I֡��λ��
	**���룺
	*		p_nTimeStamp����Ҫ��λ����ʱ�������λΪ��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int locatePreIFrame(unsigned long p_nTimeStamp);

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
	int getLength (INT64 & p_nLength) const;

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
	int checkFileValidity(const char *p_pszFileName);

	//�������캯��
	RemoteVideoFile(const RemoteVideoFile& p_objObject)
	{
	}

	//��ֵ����
	RemoteVideoFile& operator = (const RemoteVideoFile& p_objObject)
	{
		return *this;
	}
	
private:

	DeviceInfoEx			m_objDeviceInfoEx;		//�豸��Ϣ

	int						m_nTransferProtocol;	//����Э��

	IFileConnector*			m_pobjFileConnector;	//�ļ���д������

	int						m_nSessionId;	//��ȫ�Ự

	ITransfer *				m_pobjTransfer;				//������

	int						m_nTimeout;					//��ʱʱ�䣬�Ժ���Ϊ��λ��ms��

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
