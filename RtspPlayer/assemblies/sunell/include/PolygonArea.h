#ifndef _POLYGON_AERA_H_
#define _POLYGON_AERA_H_
#include "DomainConst.h"
#include "SNPlatOS.h"
#include <vector>
#include "SNPoint.h"
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

/************************************************************************
**���ܣ�
*		˵����������ɶ���㹹�ɣ������������������γ�һ���պϵĶ����
*************************************************************************/
class SN_DLL_API PolygonArea
{
public:
	PolygonArea();
	~PolygonArea();

	//�������캯��
	PolygonArea(const PolygonArea &p_objPolygonArea);

public:
	
	/****************************************************************************
		**������
		*		���point�ڵ㵽����
		**���룺
		*		point�ڵ�ֵ
		**�����
		*		��
		**����ֵ��
		*		���������������
		**���ܣ�
		*		
		*******************************************************************************/
	void addPoint(const SNPoint &p_objPoint);
	void addPoint(const float x,const float y);
	void clear();

	/****************************************************************************
		**������
		*		��ȡ������ڵĵ��б�
		**���룺
		*		�б�
		**�����
		*		��
		**����ֵ��
		*		���������������
		**���ܣ�
		*		
		*******************************************************************************/
	const std::vector<SNPoint>& getVecPoints() const;

	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		PolygonArea���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		���������������
	**���ܣ�
	*		������������������Ը�ֵ������һ�����󣬽�����һ����������÷��ء�
	*******************************************************************************/
	PolygonArea & operator =(const PolygonArea& p_objPolygonArea) ;

private:
	std::vector<SNPoint> m_objPointsList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_POLYGON_AERA_H_

