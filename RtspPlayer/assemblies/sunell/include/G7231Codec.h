#ifndef _G7231CODEC_H_
#define _G7231CODEC_H_

#include "SNPlatOS.h"
#include "ICodec.h"
#define CONST_LENGTH_RAWFRAMEDATA 480
#define CONST_MAXLENGTH_ENCODEDATA 24
class G7231AudioCodec;

/**********************************************************************/
//�˴����ڿ����ļ������ֽڶ��룬����ʱ����ע�ͼ�������һ�𿽱���
//�������ġ�#ifdef PRAGMA_PACK������ҲҪһ�𿽱�������pragma pack��ջ��ջ��ƥ��
#if(PRAGMA_PACK_DEFINE != 10000)
	# error Not included "SNPlatOS.h".
#endif
 
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(push, PRAGMA_PACK_CHAR)
	#endif

	#ifndef WIN32  
		#ifndef _PACKED_1_  
		  
		#define _PACKED_1_ __attribute__((packed, aligned(PRAGMA_PACK_CHAR)))	// for gcc   
		#endif  
	#else  
		#ifndef _PACKED_1_  
		#define _PACKED_1_  
		#endif  
	#endif  
#else  
	#ifndef _PACKED_1_  
	#define _PACKED_1_  
	#endif  
#endif
/**********************************************************************/

class SN_DLL_API G7231Codec : public ICodec
{
public:
	G7231Codec(void);

	~G7231Codec(void);
public:
	/************************************************************************
	**������
	*		����WAVE_PCM��ʽ��Ƶ����ΪG723.1������
	**���룺
	*		p_pszIn��  Wave��ʽ�����ݣ������ݸ�ʽ����Ϊ��
	*				SamplesPerSec = 8000;			//������
	*				BitPerSample = 16;				//��Ƶ�ֱ���
	*				FormatTag = WAVE_FORMAT_PCM;	//��Ƶ������ʽ
	*				Channels = 1;					//��Ƶͨ����
	*		p_nInLen��	�������Wave��ʽ�����ݳ��ȣ�����Ҫ��480�ֽڵ�������
	*		p_nOutLen��	p_szOut����ĳ��ȣ�Ҫ�󻺳�ĳ��ȱ�����ڻ����(N+1)*24������N = p_nInLen/480
	**�����
	*		p_szOut��	�û����ڴ��G723.1�����Ļ���
	*		p_nOutLen��	�����ĳ��ȣ�С�ڻ����N*24�ֽ�
	**����ֵ��
	*		ִ�гɹ�����true�� false ����
	**���ܣ�
	*		ע������ʱ���û�Ӧ�ö����ñ������ݡ�
	************************************************************************/
	bool encode(const char * p_pszIn, const int p_nInLen, char * p_szOut, int & p_nOutLen );

	/************************************************************************
	**������
	*		����G723.1��������ΪWAVE_PCM��ʽ��Ƶ���ݡ�
	**���룺
	*	p_pszIn��G723.1��������
	*	p_nInLen��G723.1�������ݵĳ��ȣ�������N��G723.1����֡���ݳ���֮�ͣ�ÿ֡������������֡��һ����λ�ı���֡һ��С�ڵ���24�ֽڣ�
	**�����
	*		p_szOut���û����ڴ��Wave��ʽ���ݵĻ���
	*		pszOutLen�� ��Ϊ�������ʱ��ָp_szOut���峤�ȣ�p_szOut�����С����С��N* 480�ֽ�, N��������ı���֡����������Ӧ��p_pszIn�����б���֡������
						��Ϊ�������ʱ�����ؽ����ĳ��ȣ�N*480�ֽڡ� 
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
	bool decode(const char * p_pszIn, const int p_nInLen, char * p_szOut, int & p_nOutLen );

private:
	int computeFrameSize(int p_nInfo);
	
private:
	char			*m_LeftData;
	int				m_LeftDataLen;

	G7231AudioCodec * m_pobjEncoder;

	G7231AudioCodec * m_pobjDecoder;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif
