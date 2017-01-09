#ifndef _RECORDERPARAM_H_
#define _RECORDERPARAM_H_

class RecorderParam
{
public:

	/*enum
	{
		FILEFORMAT_AVI		= 1,	//录制的文件格式为AVI格式

		FILEFORMAT_MEPG2PS	= 2,	//录制的文件格式为Mpeg2PS流格式

		FILEFORMAT_MEPG2TS	= 3		//录像文件为Mpeg2TS格式
	};
	*/

	enum
	{
		FILE_FORMAT_TS		= 1,	//录像文件为Mpeg2TS格式
		FILE_FORMAT_SUNELL  = 2,	//录像文件为Sunell格式
		FILE_FORMAT_AVI		= 3,	//录制的文件格式为AVI格式
		FILE_FORMAT_PS		= 4		//录制的文件格式为Mpeg2PS流格式

	};

public:

	RecorderParam(void);

	~RecorderParam(void);

public:

	void	setSaveFile(const char *p_pszFileName);

	char*   getSaveFile();

	void	setFileFormat(int p_nFileFormat);

	int		getFileFormat();

private:

	int		m_nFileFormat;	//录制格式

	char    m_szFileName[256];

};

#endif //_RECORDERPARAM_H_
