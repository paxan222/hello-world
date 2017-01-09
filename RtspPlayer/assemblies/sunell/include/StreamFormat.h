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
		UNKNOWN_STREAM		=   0,			//未知流
		ES_STREAM			=   1,			//原始流	
		TS_STREAM			=   2,			//TS混合流
		ES_ENCRYPT_STREAM1	=   3,			//原始加密流，同方加密算法
		PS_STREAM			=   4,			//PS混合流
		BOUNDARY			=	10			//边界检测
	};
};
#endif //_STREAMTYPE_H_

