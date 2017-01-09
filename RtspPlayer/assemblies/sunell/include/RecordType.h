#ifndef _RECORDTYPE_H_
#define _RECORDTYPE_H_

class RecordType
{
public:
	enum
	{
		RECORD_TYPE_ALWAYS					= 1,	//总是录像
		RECORD_TYPE_SCHEDULE				= 2,	//计划录像
		RECORD_TYPE_ALARM					= 3		//报警录像
	} ;
};

#endif //_RECORDTYPE_H_

