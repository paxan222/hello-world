#ifndef _ENCODERTYPE_H_
#define _ENCODERTYPE_H_

#include <string.h>
/*
#ifdef __cplusplus
extern "C" {
#endif
*/ 

class EncoderType
{
public:
	enum ES_STREAM_TYPE
	{
		MPEG4		= 0,			//MPEG4����
		H264		= 1,			//H264����
		MJPEG		= 2,			//MJPEG����
		SVC			= 3,			//SVC����
		H264_MAIN	= 4,			//H264 main profile
		H264_HIGH	= 5,			//H264 high profile
		JPEG		= 6,			//JPEG����
		H265		= 7,			//H265(base)
		H265_MAIN	= 8,			//H265(main)
		H265_HIGH	= 9,			//H265(high)
		G7231		= 101,			//G7231����
		G711_ALAW	= 102,			//G711A�ɱ���
		G711_ULAW	= 103,			//G711U�ɱ���
		G722		= 104,			//G722����
		G726		= 105,			//G726����
		G729		= 106,			//G729����
		AMR			= 107,			//AMR����
		RAW_PCM		= 108,			//PCM���룬��������
		NONE		= 109,			//û����Ƶ
		MOTION_DETECTION = 201,		//�ƶ��������
		CAMERATAMPER_DETECTION = 202, //�ڵ��������
		LINECOUNTING_DETECTION = 203, //Խ���������
		UNKNOWN		= 0xFF			//δ֪����
	};

	//��ȡ��������
	static void getEncodeTypeName(int p_nEncodeType, char* p_pszEncodeTypeName)
	{
		switch(p_nEncodeType)
		{
		case EncoderType::MPEG4:
			strcpy(p_pszEncodeTypeName, "Mpeg4");
			break;

		case EncoderType::H264:
			strcpy(p_pszEncodeTypeName, "H.264");
			break;

		case EncoderType::MJPEG:
			strcpy(p_pszEncodeTypeName, "MJpeg");
			break;

		case EncoderType::SVC:
			strcpy(p_pszEncodeTypeName, "Svc");
			break;

		case EncoderType::H264_MAIN:
			strcpy(p_pszEncodeTypeName, "H.264");
			break;

		case EncoderType::H264_HIGH:
			strcpy(p_pszEncodeTypeName, "H.264");
			break;

		case EncoderType::H265:
			strcpy(p_pszEncodeTypeName, "H.265");
			break;

		case EncoderType::H265_MAIN:
			strcpy(p_pszEncodeTypeName, "H.265");
			break;

		case EncoderType::H265_HIGH:
			strcpy(p_pszEncodeTypeName, "H.265");
			break;

		case EncoderType::G7231:
			strcpy(p_pszEncodeTypeName, "G7231");
			break;

		case EncoderType::G711_ALAW:
			strcpy(p_pszEncodeTypeName, "G711A");
			break;

		case EncoderType::G711_ULAW:
			strcpy(p_pszEncodeTypeName, "G711U");
			break;

		case EncoderType::G722:
			strcpy(p_pszEncodeTypeName, "G722");
			break;

		case EncoderType::G726:
			strcpy(p_pszEncodeTypeName, "G726");
			break;
		case EncoderType::G729:
			strcpy(p_pszEncodeTypeName, "G729");
			break;

		case EncoderType::AMR:
			strcpy(p_pszEncodeTypeName, "AMR");
			break;

		case EncoderType::RAW_PCM:
			strcpy(p_pszEncodeTypeName, "RAW_PCM");
			break;
			
		case EncoderType::NONE:
			strcpy(p_pszEncodeTypeName, "NONE");
			break;
			
		default:
			strcpy(p_pszEncodeTypeName, "UNKNOWN");
			break;
		}
	}
};

#endif //_ENCODERTYPE_H_

