#ifndef _REMOTEDECODER_H_
#define _REMOTEDECODER_H_

#include "DeviceInfoEx.h"
#include "AVFrameData.h"
#include "SNError.h"
#include "SNPlatOS.h"

class IAVStreamConnector;

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
/**********************************************************************//**********************************************************************/

class SN_DLL_API RemoteDecoder
{
public:
	RemoteDecoder();

	RemoteDecoder(const DeviceInfoEx &p_objDeviceInfoEx, const int p_nWindowID);

	~RemoteDecoder(void);

public:
	/************************************************************************
	**������
	*		����DeviceInfoEx
	**���룺
	*		DeviceInfoEx �豸��Ϣ
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
	*		����Ҫ�򿪵Ĵ���ID
	**���룺
	*		p_nWindowID ����ID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		���ò��������Ĺ��캯��������ʱ����open֮ǰ������ø÷���
	*************************************************************************/
	void	setWindowID(const int p_nWindowID);

	/************************************************************************
	**������
	*		��Զ�̽�����
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
	*		��������Ƶ����
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
	int		decode(AVFrameData &p_objAVFrameData);

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
private:
	DeviceInfoEx			m_objDeviceInfoEx;
	int						m_nWindowID;
	bool					m_bConnectSuccessFlag;
	IAVStreamConnector *	m_pobjAVStreamConnector;
	int						m_nSocketBufSize;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif