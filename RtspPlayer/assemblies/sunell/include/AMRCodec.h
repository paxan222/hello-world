#ifndef _AMRCODEC_H_
#define _AMRCODEC_H_

#include "ICodec.h"
#include "SNPlatOS.h"

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

class SN_DLL_API AMRCodec : public ICodec
{
public:
	AMRCodec(void);
	~AMRCodec(void);
public:
	/************************************************************************
	**������
	*		����WAVE_PCM��ʽ��Ƶ����ΪAMR������
	**���룺
	*		p_pszIn��  Wave��ʽ�����ݣ������ݸ�ʽ����Ϊ��
	*				SamplesPerSec = 8000;			//������
	*				BitPerSample = 16;				//��Ƶ�ֱ���
	*				FormatTag = WAVE_FORMAT_PCM;	//��Ƶ������ʽ
	*				Channels = 1;					//��Ƶͨ����
	*		p_nInLen��	�������Wave��ʽ�����ݳ���
	*		p_nOutLen��	p_szOut����ĳ��ȣ�Ҫ�󻺳�ĳ��ȱ�����ڻ����(N+1)*18������N = p_nInLen/320
	**�����
	*		p_szOut��	�û����ڴ��AMR�����Ļ���
	*		p_nOutLen��	�����ĳ��ȣ�С�ڻ����N*18�ֽ�
	**����ֵ��
	*		ִ�гɹ�����true�� false ����
	**���ܣ�
	*		ע������ʱ���û�Ӧ�ö����ñ������ݡ�
	************************************************************************/
	bool encode(const char * p_pszIn, const int p_nInLen, char * p_szOut, int & p_nOutLen );

	/************************************************************************
	**������
	*		����AMR��������ΪWAVE_PCM��ʽ��Ƶ���ݡ�
	**���룺
	*	p_pszIn��AMR��������
	*	p_nInLen��AMR�������ݵĳ��ȣ�������N��AMR����֡���ݳ���֮��
	**�����
	*		p_szOut���û����ڴ��Wave��ʽ���ݵĻ���
	*		pszOutLen�� ��Ϊ�������ʱ��ָp_szOut���峤�ȣ�p_szOut�����С����С��N* 320�ֽ�, N��������ı���֡����������Ӧ��p_pszIn�����б���֡������
	��Ϊ�������ʱ�����ؽ����ĳ��ȣ�N*320�ֽڡ� 
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
	void *m_pEncoderAmr;
	void *m_pDecoderAmr;
	char *m_pBuff;			
	int m_nSize;
	char *m_LeftData;
	int	m_LeftDataLen;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_AMRCODEC_H_
