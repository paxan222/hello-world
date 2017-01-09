#ifndef _RGB_COLOR_H_
#define _RGB_COLOR_H_


#include "SNPlatOS.h"
#include "DomainConst.h"

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

class SN_DLL_API RGBColor
{
public:
	RGBColor();
	~RGBColor();

	RGBColor(const RGBColor &p_objRGBColor);

public:


	void setRGBColor(int p_nR,int p_nG,int p_nB);
	void getRGBColor(int &p_nR,int &p_nG,int &p_nB) const;

	RGBColor& operator =(const RGBColor &p_objRGBColor);

private:
	int m_nR;
	int m_nG;
	int m_nB;
}_PACKED_1_;


/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/


#endif	//_RGB_COLOR_H_



