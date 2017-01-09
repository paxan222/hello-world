#ifndef PTZ_NORTH_V2_h__
#define PTZ_NORTH_V2_h__

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


/***************************************************************************//**
 @brief ������ʵ����
******************************************************************************/

class SN_DLL_API PTZNorthV2
{
public:
	PTZNorthV2(void);
	~PTZNorthV2(void);

	/************************************************************************
	**������
	*		����������λ��
	**���룺
	*		p_nPos ������λ��
	**�����
	*		��
	*����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void set(int p_nPos);

	/************************************************************************
	**������
	*		��ȡ������λ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������λ��
	**���ܣ�
	*    
	************************************************************************/
	const int get() const;

private:
	int m_nNorthPos;	/* ������λ�� */

}_PACKED_1_;


/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif


#endif // PTZ_NORTH_V2_h__