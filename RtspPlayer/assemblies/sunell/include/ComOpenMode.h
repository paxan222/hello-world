#ifndef _COMOPENMODE_H_
#define _COMOPENMODE_H_

class ComOpenMode
{
public:
	enum OpenMode
	{
		OPENMODE_SHARE		= 0,		//共享模式打开
		OPENMODE_EXCLUSIVE	= 1			//独占模式打开
	};
};

#endif //_COMOPENMODE_H_
