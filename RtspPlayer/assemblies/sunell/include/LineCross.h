#ifndef  _DETECTION_LINE_H_
#define  _DETECTION_LINE_H_
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

class SN_DLL_API LineCross
{
public:
	LineCross();
	virtual ~LineCross();


public:

	void setLineCrossStartX(const float p_nLineCrossStartX);
    float getLineCrossStartX()const;

	void setLineCrossStartY(const float p_nLineCrossStartY);
	float getLineCrossStartY()const;


	void setLineCrossEndX(const float p_nLineCrossEndX);
	float getLineCrossEndX()const;

	void setLineCrossEndY(const float p_nLineCrossEndY);
	float getLineCrossEndY()const;


private:
	float m_fLineCrossStartX;       //��ʼ��X���꣨ռ��Ļ�İٷֱȣ�
	float m_fLineCrossStartY;       //��ʼ��Y����
	float m_fLineCrossEndX;		    //������X����
	float m_fLineCrossEndY;		    //������Y����

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif