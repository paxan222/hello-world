#ifndef _POINT_H
#define _POINT_H
#include "DomainConst.h"
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
class SN_DLL_API SNPoint
{
public:
		SNPoint();
		SNPoint(const float p_nXval,const float p_nYval);
		bool operator==(const SNPoint &p_objPoint);
		//SNPoint(const SNPoint& p_objPoint);
		//SNPoint& operator =(const SNPoint& p_objPoint);
		//~SNPoint();
public:
		void setX(const float p_fXval);
		float getX() const;
		void setY(const float p_fYval);
		float getY() const;
private:
	float m_fXval;
	float m_fYval;
}_PACKED_1_;
/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
#endif