#ifndef _REMOTEAUDIOBROADCAST_H_
#define _REMOTEAUDIOBROADCAST_H_

#include "SNPlatOS.h"
#include "DeviceInfoEx.h"
#include "EncoderType.h"

class AudioBroadcastHelper;

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

class SN_DLL_API RemoteAudioBroadcast
{
public:

	RemoteAudioBroadcast();

	~RemoteAudioBroadcast();

public:

	/************************************************************************
	**������
	*		������Ƶ����
	**���룺
	*		p_nEncoderType: ��Ƶ����
	*						G711_ALAW	= 102,			//G711A�ɱ���
	*						G711_ULAW	= 103,			//G711U�ɱ���
	*						AMR			= 107,			//AMR����
	*						RAW_PCM		= 108,			//PCM���룬��������
	**�����
	*		��
	**����ֵ��
	*		����ӳɹ�������true
	*		���Ѿ���ӹ����豸���������ʧ�ܣ�����false
	**���ܣ�
	*		
	*ע����������ô˽ӿڣ�Ĭ��ΪG711_ALAW����
	*************************************************************************/
	void	setEncoderType(int p_nEncoderType = EncoderType::G711_ALAW);

	/************************************************************************
	**������
	*		��ӹ㲥�豸�����Զ�ε��ô˷��������Ҫ�㲥���豸
	**���룺
	*		DeviceInfo �豸��Ϣ
	**�����
	*		��
	**����ֵ��
	*		����ӳɹ�������true
	*		���Ѿ���ӹ����豸���������ʧ�ܣ�����false
	**���ܣ�
	*		
	*************************************************************************/
	bool addBroadcastDevice(const DeviceInfoEx& p_objDeviceInfo, const int p_nAudioChannel = 1);


	/************************************************************************
	**������
	*		���������㲥��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��start�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ���û�����ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		���������㲥���ɹ��򷵻�SN_SUCCESS��
	*		���򿪲��ɹ�������ݴ���������ز�ͬ����ֵ
	*************************************************************************/
	int			start();

	/************************************************************************
	**������
	*		�رչ㲥��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void		stop();


	/************************************************************************
	**������
	*		�ӹ㲥�б����Ƴ��豸
	**���룺
	*		DeviceInfo �豸��Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void removeBroadcastDevice(const char* p_pszDeviceId, const int p_nAudioChannel = 1);

private:
	//�������캯��
	RemoteAudioBroadcast(const RemoteAudioBroadcast& p_objObject)
	{
	}

	//��ֵ����
	RemoteAudioBroadcast& operator = (const RemoteAudioBroadcast& p_objObject)
	{
		return *this;
	}

private:

	AudioBroadcastHelper*		m_pobjAudioBroadcastHelper;				//

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTEAUDIOBROADCAST_H_
