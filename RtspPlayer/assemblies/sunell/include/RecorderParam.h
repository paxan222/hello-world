#ifndef _RECORDERPARAM_H_
#define _RECORDERPARAM_H_

class RecorderParam
{
public:

	/*enum
	{
		FILEFORMAT_AVI		= 1,	//¼�Ƶ��ļ���ʽΪAVI��ʽ

		FILEFORMAT_MEPG2PS	= 2,	//¼�Ƶ��ļ���ʽΪMpeg2PS����ʽ

		FILEFORMAT_MEPG2TS	= 3		//¼���ļ�ΪMpeg2TS��ʽ
	};
	*/

	enum
	{
		FILE_FORMAT_TS		= 1,	//¼���ļ�ΪMpeg2TS��ʽ
		FILE_FORMAT_SUNELL  = 2,	//¼���ļ�ΪSunell��ʽ
		FILE_FORMAT_AVI		= 3,	//¼�Ƶ��ļ���ʽΪAVI��ʽ
		FILE_FORMAT_PS		= 4		//¼�Ƶ��ļ���ʽΪMpeg2PS����ʽ

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

	int		m_nFileFormat;	//¼�Ƹ�ʽ

	char    m_szFileName[256];

};

#endif //_RECORDERPARAM_H_
