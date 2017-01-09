#ifndef _VIDEO_RECT_H_
#define _VIDEO_RECT_H_

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

class SN_DLL_API VideoRect
{
public:
	VideoRect(void);
	~VideoRect(void);
public:
	void setId(const int p_nId);
	const int getId()const;

	void setStartX(const double p_nStartX);
	const double getStartX()const;

	void setStartY(const double p_nStartY);
	const double getStartY()const;

	void setWidth(const double p_nWidth);
	const double getWidth()const;

	void setHeight(const double p_nHeight);
	const double getHeight()const;

	bool operator != (const VideoRect& p_objRhs);
	VideoRect& operator = (const VideoRect& p_objRhs);
private:
	int m_nId;			//0��Զ�����ۻ���ȫ����Ƶ������Ϊptz

	double m_nStartX;	//�ٷֱȣ�0~1��x100������ΪС�����2λ
	double m_nStartY;	//�ٷֱȣ�0~1��x100������ΪС�����2λ
	double m_nWidth;	//�ٷֱȣ�0~1��x100������ΪС�����2λ
	double m_nHeight;	//�ٷֱȣ�0~1��x100������ΪС�����2λ
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/
#endif //_VIDEO_RECT_H_