#ifndef _AVDATA_H_
#define _AVDATA_H_
/*
#ifdef __cplusplus
extern "C" {
#endif
*/ 
#include "DomainConst.h"
#include "SNPlatOS.h"

#if defined( WIN32 )
	typedef __int64				INT64;
#else
	typedef long long			INT64;
#endif

#if (defined(WIN32) || defined(_WIN32_WCE))
	#ifdef SN_DLL_EXPORTS
		#define AVDATA_API __declspec(dllexport)
	#else
		#define AVDATA_API __declspec(dllimport)
	#endif
#else
	#define AVDATA_API
#endif

/*
enum ES_STREAM_TYPE
{
	MPEG4=0,
	H264,
	MJPEG,
	SVC,
	G7231=101,
	G711,
	G722,
	G726,
	G729,
	MPEG2TS = 201,
	NA = 0xFF
};
*/

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

class AVDATA_API AVData
{

public:
	AVData();
	~AVData();

public:
	/***********************************************************************
	**������
	*		�����豸Id��
	**���룺
	*		p_pszDeviceId���豸Id
	**�����
	*		��
	**����ֵ��
	*		true	�����óɹ�
	*		false   ������ʧ��
	**���ܣ�
	************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**������
	*		��ȡ�豸Id
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸ID
	**���ܣ�
	*
	***************************************************************************/
	const char* getDeviceId() const;

	/************************************************************************
	**������
	*		����Я����֡���ݵ���������
	**���룺
	*		p_nStreamFormat : ֡���ݵ���������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		����Я����֡���ݵ���������
	************************************************************************/
	void setStreamFormat(const int p_nStreamFormat);

	/************************************************************************
	**������
	*		��ȡЯ����֡���ݵ���������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		֡���ݵ���������
	**���ܣ�
	*		��ȡЯ����֡���ݵ���������
	**************************************************************************/
	const int getStreamFormat() const;

	void setESStreamType(const int p_nESStreamType);

	const int getESStreamType() const;

	/************************************************************************
	**������
	*		���ò�������Ƶ���ݵ�������ı��
	**���룺
	*		p_nCameraNo : Ӱ��Ĵ���Ƶ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		���ò�������Ƶ���ݵ�������ı��
	************************************************************************/
	void setCameraNo(const int p_nCameraNo);

	/************************************************************************
	**������
	*		��ȡ��������Ƶ���ݵ�������ı��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��������Ƶ���ݵ�������ı��
	**���ܣ�
	*		��ȡ��������Ƶ���ݵ�������ı��
	**************************************************************************/
	const int getCameraNo() const;

	/************************************************************************
	**������
	*		�������ݵı����ʽ
	**���룺
	*		p_nEncoderType	: �����ʽ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�������ݵı����ʽ
	**************************************************************************/
	void setEncoderType(int p_nEncoderType);

	/************************************************************************
	**������
	*		��ȡ���ݵı����ʽ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�����ʽ
	**���ܣ�
	*		��ȡ���ݵı����ʽ
	**************************************************************************/
	int getEncoderType() const;

	/************************************************************************
	**������
	*		��������Ƶ���ݵ�֡���к�
	**���룺
	*		p_nSequenceId : ֡���к�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		��������Ƶ���ݵ�֡���к�
	**************************************************************************/
	void setSequenceId(const unsigned int p_nSequenceId);

	/************************************************************************
	**������
	*		��ȡ����Ƶ���ݵ�֡���к�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		֡���к�
	**���ܣ�
	*		��ȡ����Ƶ���ݵ�֡���кţ�����������Ƶ���ݽ�������
	**************************************************************************/
	const unsigned int getSequenceId() const;

	/************************************************************************
	**������
	*		������Ƶ֡����
	**���룺
	*		p_nFrameType : ��Ƶ֡����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		����Ӱ�������֡���͡�
	**************************************************************************/
	void setFrameType(const int p_nFrameType);

	/************************************************************************
	**������
	*		��ȡ��Ƶ֡����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ֡����
	**���ܣ�
	*		��ȡ��Ƶ֡����
	**************************************************************************/
	const int getFrameType() const;

	/************************************************************************
	**������
	*		����֡���ݵ�ʱ���
	**���룺
	*		p_nTimeStamp ��֡���ݵ�ʱ���,��λΪ΢��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		����֡���ݵ�ʱ�����
	**************************************************************************/
	void setTimeStamp(const INT64 p_nTimeStamp);

	/************************************************************************
	**������
	*		��ȡ֡���ݵ�ʱ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		֡���ݵ�ʱ���
	**���ܣ�
	*		���֡���ݵ�ʱ�����
	**************************************************************************/
	const INT64 getTimeStamp() const;

	/************************************************************************
	**������
	*		����֡���ݵķ�������־,��һ·����ʼ����ʱ,��һ֡����Ϊtrue
	**���룺
	*		p_Indicator��֡���ݵķ�������־,trueΪ��������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		����֡���ݵķ�������־��һ·�����ܻ���ͣ���룬�����������ʱ����Ҫ����discontinuity indicatorָʾ������������Ǹ�ES��һ
	*       �����.
	**************************************************************************/
	void setDiscontinuityIndicator(bool p_Indicator);

	/************************************************************************
	**������
	*		��ȡ֡���ݵķ�������־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		֡���ݵķ�������־
	**���ܣ�
	*		��ȡ֡���ݵķ�������־��
	**************************************************************************/
	bool getDiscontinuityIndicator() const;


	/************************************************************************
	**������
	*		����֡����
	**���룺
	*		p_pszData     ��֡����
	*		p_nDataLength ��֡���ݳ���
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		����֡���ݡ�
	**************************************************************************/
	bool setData(const char *p_pszData, const unsigned int p_nDataLength);


	/************************************************************************
	**������
	*		����֡����
	**���룺
	*		p_pszData     ��֡����
	*		p_nDataLength ��֡���ݳ���
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		����֡���ݡ�
	**************************************************************************/
	bool copyData(const char *p_pszData, const unsigned int p_nDataLength);

	/************************************************************************
	**������
	*		��ȡ֡����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		֡����
	**���ܣ�
	*		���֡���ݡ�
	**************************************************************************/
	const char* getData() const;

	/************************************************************************
	**������
	*		��ȡ֡���ݳ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		֡���ݳ���
	**���ܣ�
	*		���֡���ݳ��ȡ�
	**************************************************************************/
	const int getDataLength() const;

	/************************************************************************
	**������
	*		��������Ƶ���ݱ�����
	**���룺
	*		p_nBitRate������Ƶ���ݱ�����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		��������Ƶ���ݱ����ʡ�
	**************************************************************************/
	void setBitRate(const int p_nBitRate);

	/************************************************************************
	**������
	*		��ȡ����Ƶ���ݱ�����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����Ƶ���ݱ�����
	**���ܣ�
	*		��ȡ����Ƶ���ݱ����ʡ�
	**************************************************************************/
	const int getBitRate() const;

	/************************************************************************
	**������
	*		������Ƶ��ʽ
	**���룺
	*		p_nImageFormatId����Ƶ��ʽ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		������Ƶ��ʽ��
	**************************************************************************/
	void setImageFormatId(const int p_nImageFormatId);

	/************************************************************************
	**������
	*		��ȡ��Ƶ��ʽ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ��ʽ
	**���ܣ�
	*		�����Ƶ��ʽ��
	**************************************************************************/
	const int getImageFormatId() const;


	/************************************************************************
	**������
	*		������Ƶͼ�����
	**���룺
	*		p_nImageWidth����Ƶ����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		������Ƶ���ȡ�
	**************************************************************************/
	void setImageWidth(const int p_nWidth);

	/************************************************************************
	**������
	*		��ȡ��Ƶ�߶�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ�߶�
	**���ܣ�
	*		�����Ƶ�߶ȡ�
	**************************************************************************/
	const int getImageWidth() const;

	/************************************************************************
	**������
	*		������Ƶͼ��߶�
	**���룺
	*		p_nImageWidth����Ƶ�߶�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		������Ƶ���ȡ�
	**************************************************************************/
	void setImageHeight(const int p_nHeight);

	/************************************************************************
	**������
	*		��ȡ��Ƶ�߶�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ�߶�
	**���ܣ�
	*		�����Ƶ�߶ȡ�
	**************************************************************************/
	const int getImageHeight() const;

	/************************************************************************
	**������
	*		������Ƶ��ʽ
	**���룺
	*		p_nVideoSystem����Ƶ��ʽ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		������Ƶ��ʽ��
	**************************************************************************/
	void setVideoSystem(const int p_nVideoSystem);

	/************************************************************************
	**������
	*		��ȡ��Ƶ��ʽ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ��ʽ
	**���ܣ�
	*		�����Ƶ��ʽ��
	**************************************************************************/
	const int getVideoSystem() const;

	/************************************************************************
	**������
	*		����֡��
	**���룺
	*		p_nFrameRate��֡��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		����֡�ʡ�
	**************************************************************************/
	void setFrameRate(const int p_nFrameRate);

	/************************************************************************
	**������
	*		��ȡ֡��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		֡��
	**���ܣ�
	*		���֡�ʡ�
	**************************************************************************/
	const int getFrameRate() const;

	/************************************************************************
	**������
	*		����˽������
	**���룺
	*		data  ˽������ָ��
	*		len   ˽�����ݳ���
	**�����
	*		��
	**************************************************************************/
	void setPrivateData(char *data, unsigned char len);

		/************************************************************************
	**������
	*		��ȡ˽�����ݳ���
	**���룺
	**�����
	*		˽�����ݳ���
	**************************************************************************/
	unsigned int getPrivateDataLen() const;

	/************************************************************************
	**������
	*		��ȡ˽������
	**���룺
	**�����
	*		˽�����ݵ�ָ��
	**************************************************************************/
	char *getPrivateData() const;

	/************************************************************************
	**������
	*		������Ƶ����ID
	**���룺
	*		p_nStreamId����Ƶ����ID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		������Ƶ����ID��
	**************************************************************************/
	void setStreamId(int p_nStreamId);

	/************************************************************************
	**������
	*		��ȡ��Ƶ����ID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ����ID
	**���ܣ�
	*		��Ƶ����ID��
	**************************************************************************/
	int getStreamId() const;

	/************************************************************************
	**������
	*		����ʱ��
	**���룺
	*		p_nTimeZone��ʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		����ʱ����
	**************************************************************************/
	void setTimeZone(int p_nTimeZone);

	/************************************************************************
	**������
	*		��ȡʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ʱ��
	**���ܣ�
	*		��ȡʱ����
	**************************************************************************/
	int getTimeZone() const;

	/************************************************************************
	**������
	*		��������ʱ
	**���룺
	*		p_nDaylightSavingTime������ʱ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		��������ʱ��
	**************************************************************************/
	void setDaylightSavingTime(int p_nDaylightSavingTime);

	/************************************************************************
	**������
	*		��ȡ����ʱ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ʱ
	**���ܣ�
	*		��ȡ����ʱ��
	**************************************************************************/
	int getDaylightSavingTime() const;


public:
	/************************************************************************
	**������
	*		����֡���ݻ���
	**���룺
	*		p_nFrameLen����Ҫ�������֡����
	**�����
	*		��
	**����ֵ��
	*		true������ɹ�
	*		false������ʧ��
	**���ܣ�
	*		����֡���ݻ��塣
	**************************************************************************/
	bool alloc(const unsigned int p_nBufferSize);

	/************************************************************************
	**������
	*		�ͷ�֡���ݻ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�ͷ��Ѿ������֡���ݻ��塣
	**************************************************************************/
	void free();

	/************************************************************************
	**������
	*		��ȡ֡���ݻ���ĳ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		֡���ݻ���ĳ���
	**���ܣ�
	*		��ȡ֡���ݻ���ĳ��ȡ�
	**************************************************************************/
	const unsigned int  getBufferSize();
private:
	char m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1]; //�豸id
	int m_nStreamFormat;					//1��ʾԭʼ������, 2��ʾTS�����ݣ� 0��ʾN/A
	int m_nESStreamType;					//ԭʼ�����ͣ�1��ʾ��Ƶ��2��ʾ��Ƶ
	int m_nEncoderType;						//�����ʽ
	int m_nCameraNo;						//������ţ���ʾ�������Եڼ�·
	unsigned int m_nSequenceId;				//����֡���
	int m_nFrameType;						//����֡����,1��ʾI֡, 2��ʾP֡, 3��ʾB֡, 0��ʾδ֪����
	INT64 m_nTimeStamp;						//���ݲɼ�ʱ�������λΪ����
	int	m_nBitRate;							//��ǰ����
	int m_nImageFormatId;					//��ǰ��ʽ
	int m_nImageWidth;						//��Ƶ����
	int m_nImageHeight;						//��Ƶ�߶�
	int m_nVideoSystem;						//��ǰ��Ƶ��ʽ
	int m_nFrameRate;						//֡��
	bool m_nDiscontinuityIndicator;			//ES���ķ�������־.�ڴ�������У�
											//������������������û���ͣ�����ܻ���ͣ��ES���䣬
											//���´����ESʱ����ҪΪ��ES����discontinuity indicatorָʾ������������Ǹ�ES��һ
											//�������.

	char *m_pszData;						//����
	unsigned int m_nDataLength;				//������Ч����
	unsigned int m_nBufferSize;				//AVData����ռ䳤��
	unsigned int m_private_data_len;
	char * m_private_data;
	int m_nStreamId;		// ��ID
	int m_nTimezone;		// ʱ��
	int m_nDaylightSavingTime; //����ʱ
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_AVDATA_H_