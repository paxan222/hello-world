#ifndef _BLINDABILITY_H_
#define _BLINDABILITY_H_
#include "SNPlatOS.h"

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

class SN_DLL_API BlindAbility
{

public:
	BlindAbility();
	~BlindAbility();
	/************************************************************************
	**概述：设置支持遮挡区域块数量
	*
	**输入：
	*		p_nMaxBlindAreaNum   遮挡块数量
	**输出：
	*		无
	**功能：       
	*		设置支持遮挡区域数量
	************************************************************************/
	void setMaxBlindAreaNum(const int &p_nMaxBlindAreaNum);

	/************************************************************************
	**概述：获取支持遮挡区域块数量
	*
	**输入：
	*		无
	**返回：
	*		挡区域数量
	**功能：       
	*		获取支持遮挡区域数量
	************************************************************************/
	const int getMaxBlindAreaNum() const;

	/************************************************************************
	**概述：设置遮挡区域面积占源分辨率百分比值
	*
	**输入：
	*		p_nBlindArea   百分比值
	**输出：
	*		无
	**功能：       
	*		设置遮挡区域面积占源分辨率百分比值
	************************************************************************/
	void setBlindArea(const int &p_nBlindArea);	

	/************************************************************************
	**概述：获取遮挡区域面积占源分辨率百分比值
	*
	**输入：
	*		无
	**返回：
	*		区域面积占源分辨率百分比值
	**功能：       
	*		获取遮挡区域面积占源分辨率百分比值
	************************************************************************/
	const int getBlindArea() const;


	/************************************************************************
	**概述：设置遮挡类型
	*
	**输入：
	*		p_nBlindType   遮挡类型
	**输出：
	*		无
	**功能：       
	*		设置遮挡类型
	************************************************************************/
	void setBlindType(const int &p_nBlindType);	

	/************************************************************************
	**概述：获取遮挡类型
	*
	**输入：
	*		无
	**返回：
	*		遮挡类型
	**功能：       
	*		获取遮挡类型
	************************************************************************/
	const int getBlindType() const;

	//赋值函数
	BlindAbility& operator = (const BlindAbility& p_objBlindAbility);

	bool operator == (const BlindAbility& p_objBlindAbility) const;
private:
	int m_nMaxBlindAreaNum;	     //支持最大的遮挡区域数目
	int m_nBlindArea;			//遮挡区域面积占源分辨率百分比     					
	int m_nBlindType;			//遮挡类型
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif // _BLINDABILITY_H_