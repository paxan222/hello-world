#ifndef _ROIABILITY_H_
#define _ROIABILITY_H_

#include <vector>
#include <map>
#include "SNPlatOS.h"

using namespace std;

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

class SN_DLL_API ROIAbility
{
public:
	ROIAbility(void);
	~ROIAbility(void);

	//拷贝构造函数
	ROIAbility(const ROIAbility &p_objROIAbility);

public:
	/************************************************************************
	*	概述：设置ROI区域最大值
	*	输入：
	*		p_nROIMaxNum：	ROI区域最大值
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setROIMaxNum(const int p_nROIMaxNum);
	
	/************************************************************************
	*	概述：获取ROI区域最大值
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int(ROI区域最大值)
	*************************************************************************/
	const int getROIMaxNum() const;

	/************************************************************************
	*	概述：设置ROI区域最大比例
	*	输入：
	*		p_nROIScale：	ROI区域最大比例
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setROIMaxScale(const int p_nROIScale);

	/************************************************************************
	*	概述：获取ROI区域ROI区域最大比例
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int(ROI区域最大比例值)
	*************************************************************************/
	const int getROIMaxScale() const;

	/************************************************************************
	*	概述：设置ROI区域最大提升等级
	*	输入：
	*		p_nROILevel：	ROI区域最大比例
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setROIMaxLevel(const int p_nROILevel);

	/************************************************************************
	*	概述：获取ROI区域最大提升等级
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int(ROI区域最大提升等级)
	*************************************************************************/
	const int getROIMaxLevel() const;

	/************************************************************************
	*	概述：设置ROI区域提升等级与QP值对应表
	*	输入：
	*		p_objLevelQPMap：ROI区域提升等级与QP值对应表
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setLevelQPMap(const std::map<int,int>& p_objLevelQPMap);


	/************************************************************************
	*	概述：获取ROI区域提升等级与QP值对应表
	*	输入：
	*		p_objLevelQPMap：ROI区域提升等级与QP值对应表
	*	输出：
	*		无
	*	返回值：
	*		ROI区域提升等级与QP值对应表
	*************************************************************************/
	const std::map<int,int>& getLevelQPMap() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objROIAbility ：感兴趣区域能力
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	**************************************************************************/
	ROIAbility& operator = (const ROIAbility& p_objROIAbility);

	bool operator == (const ROIAbility& p_objROIAbility) const;
private:
	int			m_nROIMaxNum;//最大数目

	int			m_nROIMaxScale;//最大比例

	int			m_nROIMaxLevel;//最大提升等级

	std::map<int,int>	m_objLevelQPMap;	  //提升等级与QP值的对应表

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_ROIAbility_H_
