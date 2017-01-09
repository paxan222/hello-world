#ifndef _VIDEOCHANNELSTATISTIC_H_
#define _VIDEOCHANNELSTATISTIC_H_

#include "SNPlatOS.h"

#ifndef byte
typedef unsigned char byte;
#endif

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

class SN_DLL_API VideoChannelStatistic
{
public:
	enum RecordStatus
	{
		RECORDSTATUS_NO_RECORD				= 0,		//��¼��
		RECORDSTATUS_RECORD					= 1			//��¼��
	};

	enum CaptureStatus
	{
		CAPTURESTATUS_NO_CAPTURE			= 0,		//û����ץ��
		CAPTURESTATUS_CAPTURE				= 1			//����ץ��
	};

	enum SignalStatus
	{
		SIGNALSTATUS_HAS_SIGNAL				= 0,		//�ź�����
		SIGNALSTATUS_LOSS_SIGNAL			= 1			//�źŶ�ʧ
	};

	enum HardwareStatus
	{
		HARDWARESTATUS_NORMAL				= 0,		//Ӳ������
		HARDWARESTATUS_ABNORMAL				= 1			//Ӳ������
	};

public:
	VideoChannelStatistic(void);
	~VideoChannelStatistic(void);

	//�������캯��
	VideoChannelStatistic(const VideoChannelStatistic& p_objVideoChannelStatistic);

public:
	/************************************************************************
	**������
	*		������������
	**���룺
	*		p_nCameraId����������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setCameraId(const int p_nCameraId);
	
	/************************************************************************
	*������
	*		��ȡ��������
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		��������
	*���ܣ�       
	*************************************************************************/
	const int getCameraId() const;

	
	/************************************************************************
	**������
	*		����¼��״̬
	**���룺
	*		p_btRecordStatus��¼��״̬
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setRecordStatus(const byte p_btRecordStatus);
	
	/************************************************************************
	*������
	*		��ȡ¼��״̬
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		¼��״̬
	*���ܣ�       
	*************************************************************************/
	const byte getRecordStatus() const;

	
	/************************************************************************
	**������
	*		����ץ��״̬
	**���룺
	*		p_btCaptureStatus��ץ��״̬
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setCaptureStatus(const byte p_btCaptureStatus);
	
	/************************************************************************
	*������
	*		��ȡץ��״̬
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		���̱��
	*���ܣ�       
	*************************************************************************/
	const byte getCaptureStatus() const;

	
	/************************************************************************
	**������
	*		�����ź�����״̬
	**���룺
	*		p_btSignalStatus���ź�����״̬
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setSignalStatus(const byte p_btSignalStatus);
	
	/************************************************************************
	*������
	*		��ȡ�ź�����״̬
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		�ź�����״̬
	*���ܣ�       
	*************************************************************************/
	const byte getSignalStatus() const;

	
	/************************************************************************
	**������
	*		����Ӳ��״̬
	**���룺
	*		p_btHardwareStatus��Ӳ��״̬
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setHardwareStatus(const byte p_btHardwareStatus);
	
	/************************************************************************
	*������
	*		��ȡӲ��״̬
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		Ӳ��״̬
	*���ܣ�       
	*************************************************************************/
	const byte getHardwareStatus() const;

	
	/************************************************************************
	**������
	*		���ñ�����
	**���룺
	*		p_nBitRate��������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setBitRate(const int p_nBitRate);
	
	/************************************************************************
	*������
	*		��ȡ������
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		������
	*���ܣ�       
	*************************************************************************/
	const int getBitRate() const;


	/************************************************************************
	*������
	*		��ֵ����
	**���룺
	*		p_objVideoChannelStatistic����Ƶͨ��״̬��Ϣ
	**�����
	*		��
	**����ֵ��
	*		��Ƶͨ��״̬��Ϣ
	**���ܣ�
	*
	*************************************************************************/
	VideoChannelStatistic& operator =(const VideoChannelStatistic& p_objVideoChannelStatistic);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objVideoChannelStatistic��VideoChannelStatistic���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����VideoChannelStatistic��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const VideoChannelStatistic& p_objVideoChannelStatistic)  const;

	bool operator < (const VideoChannelStatistic& p_objVideoChannelStatistic) const;

private:

	int		m_nCameraId;				//��������

	byte	m_btRecordStatus;			//¼��״̬

	byte	m_btCaptureStatus;			//ץ��״̬

	byte	m_btSignalStatus;			//�����ź�״̬

	byte	m_btHardwareStatus;			//Ӳ��״̬

	int		m_nBitRate;					//������
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_VIDEOCHANNELSTATISTIC_H_
