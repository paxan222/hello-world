#ifndef _MANUALRECORDER_H_
#define _MANUALRECORDER_H_

#include "DeviceInfoEx.h"

#include "SNError.h"
#include "SNPlatOS.h"
#include "IMessageListener.h"


class ManualRecorderIpml;

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

class SN_DLL_API ManualRecorder
{
public:
	ManualRecorder();

	ManualRecorder(const DeviceInfoEx &p_objDeviceInfoEx, const int p_nCameraId, const int p_nStreamId);

	~ManualRecorder(void);

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
	void setStreamId(const int p_nStreamId);

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
	*		������Ϣ�����ߡ�
	**���룺
	*		p_pobjMessageListener��	��Ϣ������
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setMessageListener(IMessageListener* p_pobjMessageListener);

	/************************************************************************
	**������
	*		�Ƿ�¼����Ƶ
	**���룺
	*		p_bFlag���Ƿ�¼����Ƶ��true��¼�ƣ�false����¼��
	**�����
	*		��
	**����ֵ��
	*		
	**���ܣ�
	*		
	*************************************************************************/
	void setRecordAudioFlag(const bool p_bFlag);

	/************************************************************************
	**������
	*		����¼���ļ���
	**���룺
	*		p_pszRecordFileName��¼���ļ�����ȫ·�����磺D:\\record\\record1.ts
	**�����
	*		��
	**����ֵ��
	*		
	**���ܣ�
	*		
	*************************************************************************/
	void setRecordFileName(const char* p_pszRecordFileName);

	/************************************************************************
	**������
	*		��ʼ¼��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��open�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ���û�����ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int		startRecord();
	
	/************************************************************************
	**������
	*		ֹͣ¼��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void	stopRecord();

private:

	//�������캯��
	ManualRecorder(const ManualRecorder& p_objObject)
	{
	}

	//��ֵ����
	ManualRecorder& operator = (const ManualRecorder& p_objObject)
	{
		return *this;
	}

private:
	ManualRecorderIpml* m_pobjManualRecorderIpml;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_MANUALRECORDER_H_
