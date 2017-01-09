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
		UnknownFrame	=	0, //Î´ÖªÖ¡ÀàÐÍ
		IFrame			=	1, //IÖ¡
		PFrame			=	2, //PÖ¡
		BFrame			=	3, //BÖ¡
		BOUNDARY		=	10 //±ß½ç¼ì²â
	};
};

#endif //_FRAMETYPE_H_

