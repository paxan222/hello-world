#ifndef _STREAMTYPE_H_
#define _STREAMTYPE_H_
/*
#ifdef __cplusplus
extern "C" {
#endif
*/ 
class StreamFormat
{
public:
	enum 
	{
		UNKNOWN_STREAM		=   0,			//δ֪��
		ES_STREAM			=   1,			//ԭʼ��	
		TS_STREAM			=   2,			//TS�����
		ES_ENCRYPT_STREAM1	=   3,			//ԭʼ��������ͬ�������㷨
		PS_STREAM			=   4,			//PS�����
		BOUNDARY			=	10			//�߽���
	};
};
#endif //_STREAMTYPE_H_

