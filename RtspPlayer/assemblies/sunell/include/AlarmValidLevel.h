#ifndef _ALARMVALIDLEVEL_H_
#define _ALARMVALIDLEVEL_H_
/*
#ifdef __cplusplus
extern "C" {
#endif
*/ 
class AlarmValidLevel
{
public:
	enum ValidLevel
	{
		VALIDLEVEL_HIGH		= 1,		//高电平有效
		VALIDLEVEL_LOW		= 0			//低电平有效
	};
};
#endif //_ALARMVALIDLEVEL_H_

