#ifndef PTZPointParamV2_H_
#define PTZPointParamV2_H_

#include "SNPlatOS.h"
#include "PTZOperationConst.h"
#include <string>
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
/**********************************************************************/


class SN_DLL_API PTZPointParamV2
{
public:
	PTZPointParamV2(void);
	~PTZPointParamV2(void);
public:
	/*********************************************************************
	*********说明设置水平坐标
	********************************************************************/
	void setPanPosion(const int p_nPanPosion);
	/*********************************************************************
	*********返回值：水平位置信息
	********************************************************************/
	const int getPanPosion()const;
	/*********************************************************************
	*********说明：设置垂直坐标
	********************************************************************/
	void setTiltPosion(const int p_nTiltPosion);
	/*********************************************************************
	*********返回值：垂直位置信息
	********************************************************************/
	const int getTiltPosion()const;

	//设置变倍的倍率值
	void setZoomValue(const int p_nZoomValue);
	const int getZoomValue()const;

	//设置数字变倍的倍率值
	void setDZoomValue(const int p_nDZoomValue);
	const int getDZoomValue()const;

	//设置聚焦的聚焦值
	void setDayFocusValue(const int p_nDayFocusValue);
	const int getDayFocusValue()const;

	void setNightFocusValue(const int p_nNightFocusValue);
	const int getNightFocusValue()const;

	PTZPointParamV2 &operator=(const PTZPointParamV2 &p_objPTZPointParamV2);

	bool operator!=(const PTZPointParamV2& p_objPTZPointParamV2) const;
	bool operator==(const PTZPointParamV2& p_objPTZPointParamV2) const;

private:
	int m_nPanPosion; //水平坐标
	int m_nTiltPosion; //垂直坐标
	int m_nZoomValue; //变倍倍数
	int m_nDZoomValue;	//数字变倍值
	int m_nDayFocusValue; //日聚焦值
	int m_nNightFocusValue; //夜聚焦值
}_PACKED_1_;
/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
#endif

