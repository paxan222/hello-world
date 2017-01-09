#ifndef _ICODEC_H_
#define _ICODEC_H_

class ICodec
{
public:
	ICodec(void){};
	virtual ~ICodec(void){};
public:
	/************************************************************************
	**������
	*		����WAVE_PCM��ʽ��Ƶ����Ϊ�趨��������
	**���룺
	*		p_pszIn��  Wave��ʽ�����ݣ������ݸ�ʽ����Ϊ��
	*				SamplesPerSec = 8000;			//������
	*				BitPerSample = 16;				//��Ƶ�ֱ���
	*				FormatTag = WAVE_FORMAT_PCM;	//��Ƶ������ʽ
	*				Channels = 1;					//��Ƶͨ����
	*		p_nInLen��	�������Wave��ʽ�����ݳ���
	*		p_nOutLen��	p_szOut����ĳ���
	**�����
	*		p_szOut��	�û����ڴ�ű�������ݵĻ���
	*		p_nOutLen��	�����ĳ���
	**����ֵ��
	*		ִ�гɹ�����true�� false ����
	**���ܣ�
	*		ע������ʱ���û�Ӧ�ö����ñ������ݡ�
	************************************************************************/
	virtual	bool encode(const char * p_pszIn, const int p_nInLen, char * p_szOut, int & p_nOutLen ) = 0;
	
	/************************************************************************
	**������
	*		����������ΪWAVE_PCM��ʽ��Ƶ���ݡ�
	**���룺
	*	p_pszIn���ȴ��������ݻ���
	*	p_nInLen���ȴ��������ݵĳ���
	**�����
	*		p_szOut���û����ڴ��Wave��ʽ���ݵĻ���
	*		pszOutLen�� ��Ϊ�������ʱ��ָp_szOut���峤��
	*		���������ݸ�ʽΪ��
	*				SamplesPerSec = 8000;			//������
	*				BitPerSample = 16;				//��Ƶ�ֱ���
	*				FormatTag = WAVE_FORMAT_PCM;	//��Ƶ������ʽ
	*				Channels = 1;					//��Ƶͨ����
	**����ֵ��
	*		ִ�гɹ�����true�� false����
	**���ܣ�
	*	ע������ʱ���û�Ӧ�ö����ñ������ݡ�
	************************************************************************/
	virtual bool decode(const char * p_pszIn, const int p_nInLen, char * p_szOut, int & p_nOutLen ) = 0;
	

};

#endif //_ICODEC_H_

