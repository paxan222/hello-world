#ifndef _CHARSET_H_
#define _CHARSET_H_


#include "CharSetType.h"

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

class SN_DLL_API CharSet
{
public:
	CharSet();
	~CharSet();

public:

	/***********************************************************************
	**������
	*		�����ַ�����
	**���룺
	*		p_nCharSet���ַ���
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	************************************************************************/
	static void setCharSet(const int p_nCharSet);

	/************************************************************************
	**������
	*		��ȡ�ַ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�ַ���
	**���ܣ�
	*
	***************************************************************************/
	static const int getCharSet();

private:
	static int m_nCharSetType;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_CHARSET_H_

