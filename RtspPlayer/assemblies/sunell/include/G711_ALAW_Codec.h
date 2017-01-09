#ifndef _G711_ALAW_CODEC_H_
#define _G711_ALAW_CODEC_H_

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

class SN_DLL_API G711_ALAW_Codec: public ICodec
{
public:
	G711_ALAW_Codec(void);
	~G711_ALAW_Codec(void);

public:
	/************************************************************************
	**������
	*		������ PCM ���ݽ��� G711a ����
	**���룺
	*		p_pszIn  ��  ���� PCM ����
	*		p_nInLen ��	���� PCM ���ݳ���
	**�����
	*		p_szOut  ��	������ G711a ����
	*		p_nOutLen��	������ G711a ���ݳ���
	**����ֵ��
	*		ִ�гɹ�����true�� false ����
	**���ܣ�
	*		ע������ʱ���û�Ӧ�ö����ñ������ݡ�
	************************************************************************/
	bool encode(const char * p_pszIn, const int p_nInLen, char * p_szOut, int & p_nOutLen);


	/************************************************************************
	**������
	*		�� G711a ���ݽ���Ϊ���� PCM ���ݡ�
	**���룺
	*		p_pszIn  ��G711a ����
	*		p_nInLen ��G711a ���ݳ���
	**�����
	*		p_szOut  �������� PCM ����
	*		pszOutLen�������� PCM ���ݳ��� 
	**����ֵ��
	*		ִ�гɹ�����true�� false����
	**���ܣ�
	*		ע������ʱ���û�Ӧ�ö����ñ������ݡ�
	************************************************************************/
	bool decode(const char * p_pszIn, const int p_nInLen, char * p_szOut, int & p_nOutLen);

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif  //_G711_ALAW_CODEC_H_

