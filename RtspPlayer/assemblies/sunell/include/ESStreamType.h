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
		UNKNOWN				=	0,		//未知流
		VIDEO				=	1,		//视频流
		AUDIO				=	2,		//音频流
		MOTION_DETECTION	=	3,		//移动侦测数据流
		INTELLIGENCEANALYSE =	4,		//智能分析流
		BOUNDARY			=	10		//边界检测
	};
};
#endif //_ESSTREAMTYPE_H_

