#ifndef _FRAMETYPE_H_
#define _FRAMETYPE_H_
/*
#ifdef __cplusplus
extern "C" {
#endif
*/ 
class FrameType
{
public:
	enum
	{
		UnknownFrame	=	0, //δ֪֡����
		IFrame			=	1, //I֡
		PFrame			=	2, //P֡
		BFrame			=	3, //B֡
		BOUNDARY		=	10 //�߽���
	};
};

#endif //_FRAMETYPE_H_

