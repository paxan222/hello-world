#ifndef _POLYGON_AERA_H_
#define _POLYGON_AERA_H_
#include "DomainConst.h"
#include "SNPlatOS.h"
#include <vector>
#include "SNPoint.h"
/**********************************************************************/
//此处用于控制文件编译字节对齐，拷贝时两行注释间内容需一起拷贝，
//结束处的“#ifdef PRAGMA_PACK”部分也要一起拷贝，否则pragma pack入栈出栈不匹配
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
**功能：
*		说明：多边形由多个点构成，将点序列依次连接形成一个闭合的多边形
*************************************************************************/
class SN_DLL_API PolygonArea
{
public:
	PolygonArea();
	~PolygonArea();

	//拷贝构造函数
	PolygonArea(const PolygonArea &p_objPolygonArea);

public:
	
	/****************************************************************************
		**概述：
		*		添加point节点到区域
		**输入：
		*		point节点值
		**输出：
		*		无
		**返回值：
		*		侦测区域对象的引用
		**功能：
		*		
		*******************************************************************************/
	void addPoint(const SNPoint &p_objPoint);
	void addPoint(const float x,const float y);
	void clear();

	/****************************************************************************
		**概述：
		*		获取多边形内的点列表
		**输入：
		*		列表
		**输出：
		*		无
		**返回值：
		*		侦测区域对象的引用
		**功能：
		*		
		*******************************************************************************/
	const std::vector<SNPoint>& getVecPoints() const;

	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		PolygonArea类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		侦测区域对象的引用
	**功能：
	*		将参数对象的所有属性赋值给另外一个对象，将另外一个对象的引用返回。
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

