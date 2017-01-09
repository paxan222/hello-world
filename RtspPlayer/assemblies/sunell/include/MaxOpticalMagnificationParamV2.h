#ifndef _MAX_OPTICAL_MAGNIFICATION_PARAM_V2_H
#define _MAX_OPTICAL_MAGNIFICATION_PARAM_V2_H

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
 @brief ����ѧ�������ò���ʵ����
******************************************************************************/

class SN_DLL_API MaxOpticalMagnificationParamV2
{
public:
	MaxOpticalMagnificationParamV2(void);
	~MaxOpticalMagnificationParamV2(void);

	//��ȡ����ѧ����(����)
	const int getMaxOpticalMagnification() const {return m_nMaxOpticalMagnification;}
	//��������ѧ���������⣩
	void setMaxOpticalMagnification(const int &p_nMagnification);
	//��ȡ�����ʵ��ѧ����
	const int getMaxRealOpticalMagnification() const {return m_nMaxRealOpticalMagnification;}
	//���������ʵ��ѧ����
	void setMaxRealOpticalMagnification(const int &p_nMaxRealOpticalMagnification);

	//��ֵ����
	MaxOpticalMagnificationParamV2& operator=(const MaxOpticalMagnificationParamV2 &p_objMaxOpticalMagnificationParamV2);
private:
	int m_nMaxOpticalMagnification;						// ��������ѧ����
	int m_nMaxRealOpticalMagnification;					//�����ʵ��ѧ����
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/

#endif