#ifdef RECORD_INTERFACE

#ifndef _REMOTEVIDEOFILEV2_H_
#define _REMOTEVIDEOFILEV2_H_

#include "DeviceInfoEx.h"
#include "SNPlatOS.h"
#include "RecordInfo.h"
#include "AVFrameData.h"

class SNRemoteRecordRetriever;
class AVData;
class SNMutex;

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

class SN_DLL_API RemoteVideoFileV2
{
public:
	RemoteVideoFileV2();

	RemoteVideoFileV2(DeviceInfoEx& p_objDeviceInfoEx);
	
	~RemoteVideoFileV2();
public:
	/************************************************************************
	**������
	*		�����豸��Ϣ
	**���룺
	*		p_objDeviceInfoEx: �豸��Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		���ò��������Ĺ��캯��������ʱ����open֮ǰ������ø÷���
	*************************************************************************/
	void setDeviceInfo(const DeviceInfoEx& p_objDeviceInfoEx);

public:

	/************************************************************************
	**������
	*		������������Ƶ�豸֮������ûỰ������Զ���豸��¼���ļ�
	**���룺
	*		p_objRecordInfo��¼����Ϣ
	*		p_IsNeedLocateIFrame���Ƿ���Ҫ��λI֡��true����Ҫ��false������Ҫ
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�    
	*
	************************************************************************/
	int open(const RecordInfo& p_objRecordInfo, bool p_bIsNeedLocateIFrame = true);
	

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
	int close();

	/************************************************************************
	**������
	*		��ȡ��һ֡����
	**���룺
	*		p_pobjAVFrameData��֡����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�    
	*
	************************************************************************/
	int readNextFrame(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**������
	*		��ȡ��һ֡��Ƶ����
	**���룺
	*		p_pobjAVFrameData��֡����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�    
	*
	************************************************************************/
	int readNextVideoFrame(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**������
	*		��ȡ��һ��I֡����
	**���룺
	*		p_pobjAVFrameData��֡����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�    
	*
	************************************************************************/
	int readNextIFrame(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**������
	*		��ȡ��һ��I֡��Ƶ����
	**���룺
	*		p_pobjAVFrameData��¼����Ϣ
	*		p_bCurPosFlag���Ƿ�ӵ�ǰλ�ÿ�ʼ
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�    
	*
	************************************************************************/
	int readPreviousVideoIFrame(AVFrameData& p_pobjAVFrameData, bool p_bCurPosFlag = false);

	/************************************************************************
	**������
	*		��ȡ��һ֡����
	**���룺
	*		p_pobjAVFrameData��֡����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�    
	*
	************************************************************************/
	int prevFrame(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**������
	*		��ȡĳʱ�̵���һ��I֡����
	**���룺
	*		p_nTime��¼��ʱ�䣨����ʱ�䣩
	*		p_pobjAVFrameData��֡����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�    
	*
	************************************************************************/
	int locatePreIFrame(const TimeStruct& p_objTime, AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**������
	*		��ȡĳʱ�̺�һ֡����
	**���룺
	*		p_nTime��¼��ʱ�䣨����ʱ�䣩
	*		p_pobjAVFrameData��֡����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�    
	*
	************************************************************************/
	int locateFrame(const TimeStruct& p_objTime, AVFrameData& p_pobjAVFrameData);

//private:
	/************************************************************************
	**������
	*		��ȡ��һ֡TS������
	**���룺
	*		p_pobjAVFrameData��֡����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�    
	*
	************************************************************************/
	int readNextFrameTS(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**������
	*		��ȡ��һ����Ƶ֡TS������
	**���룺
	*		p_pobjAVFrameData��֡����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�    
	*
	************************************************************************/
	int readNextVideoFrameTS(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**������
	*		��ȡ��һ��Ƶ֡TS������
	**���룺
	*		p_pobjAVFrameData��֡����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�    
	*
	************************************************************************/
	int readPreviousVideoIFrameTS(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**������
	*		����ʱ�䶨λ֡����
	**���룺
	*		p_nTime��¼��ʱ�䣨����ʱ�䣩
	*		p_pobjAVFrameData��֡����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�    
	*
	************************************************************************/
	int locateFrameTS(const TimeStruct& p_objTime, AVFrameData& p_pobjAVFrameData);

	//private:
	/************************************************************************
	**������
	*		��ȡ��һ֡PS������
	**���룺
	*		p_pobjAVFrameData��֡����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�    
	*
	************************************************************************/
	int readNextFramePS(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**������
	*		��ȡ��һ����Ƶ֡PS������
	**���룺
	*		p_pobjAVFrameData��֡����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�    
	*
	************************************************************************/
	int readNextVideoFramePS(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**������
	*		��ȡ��һ��Ƶ֡PS������
	**���룺
	*		p_pobjAVFrameData��֡����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�    
	*
	************************************************************************/
	int readPreviousVideoIFramePS(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**������
	*		����ʱ�䶨λ֡����
	**���룺
	*		p_nTime��¼��ʱ�䣨����ʱ�䣩
	*		p_pobjAVFrameData��֡����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�    
	*
	************************************************************************/
	int locateFramePS(const TimeStruct& p_objTime, AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**������
	*		�ض�д
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����true
	*		������ʧ���򷵻�false
	**���ܣ�    
	*
	************************************************************************/
	bool recallRead();

private:
	//�������캯��
	RemoteVideoFileV2(const RemoteVideoFileV2& p_objObject)
	{
	}

	//��ֵ����
	RemoteVideoFileV2& operator = (const RemoteVideoFileV2& p_objObject)
	{
		return *this;
	}

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
	
	//AVDataת��AVFrameData
	void changeAVDataToAVFrameData(AVData* p_pobjRecvAVData, AVFrameData* p_pobjAVFrameData);

private:

	DeviceInfoEx				m_objDeviceInfoEx;				//�豸��Ϣ

	int							m_nTransferProtocol;			//����Э��

	SNRemoteRecordRetriever*	m_pobjSNRemoteRecordRetriever;
	RecordInfo					m_objRecordInfo;
	SNMutex*					m_pobjMutex;  


}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTEVIDEOFILEV2_H_
#endif //RECORD_INTERFACE