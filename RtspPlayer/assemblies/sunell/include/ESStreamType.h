#ifndef _ESSTREAMTYPE_H_
#define _ESSTREAMTYPE_H_
/*
#ifdef __cplusplus
extern "C" {
#endif
*/ 
class ESStreamType
{
public:
	enum ES_STREAM_FORMAT
	{
		UNKNOWN				=	0,		//δ֪��
		VIDEO				=	1,		//��Ƶ��
		AUDIO				=	2,		//��Ƶ��
		MOTION_DETECTION	=	3,		//�ƶ����������
		INTELLIGENCEANALYSE =	4,		//���ܷ�����
		BOUNDARY			=	10		//�߽���
	};
};
#endif //_ESSTREAMTYPE_H_

