#ifndef _VERTICAL_MAX_POSITION_PARAM_V2_H
#define _VERTICAL_MAX_POSITION_PARAM_V2_H

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
 @brief ��ֱ���Ƕ����ò���ʵ����
******************************************************************************/

class VerticalMaxPositionParamV2
{
public:
	VerticalMaxPositionParamV2(void);
	~VerticalMaxPositionParamV2(void);

	//��ȡ��ֱ���ǶȽϴ��ֵ
	const int getVerticalMaxPositionMost() const {return m_nVerticalMaxPositionMost;}
	//���ô�ֱ���ǶȽϴ��ֵ
	void setVerticalMaxPositionMost(const int &p_nVerticalMaxPositionMost);
	//��ȡ��ֱ���ǶȽ�С��ֵ
	const int getVerticalMaxPositionMore() const {return m_nVerticalMaxPositionMore;}
	//���ô�ֱ���ǶȽ�С��ֵ
	void setVerticalMaxPositionMore(const int &p_nVerticalMaxPositionMore);

	//��ֵ����
	VerticalMaxPositionParamV2& operator=(const VerticalMaxPositionParamV2 &p_objVerticalMaxPositionParamV2);
private:
	int m_nVerticalMaxPositionMost;					// ��ֱ���ǶȽϴ��ֵ
	int m_nVerticalMaxPositionMore;					// ��ֱ���ǶȽ�С��ֵ
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/

#endif