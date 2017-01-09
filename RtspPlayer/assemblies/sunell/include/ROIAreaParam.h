#ifndef  _ROI_AREA_PARAM_H_
#define _ROI_AREA_PARAM_H_

#include "SNPlatOS.h"
#include "ROIInfoParam.h"
#include <vector>

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

class SN_DLL_API ROIAreaParam
{
public:
    ROIAreaParam(void);
    ~ROIAreaParam(void);

    ROIAreaParam(const ROIAreaParam& p_objROIAreaParam);
public:
    /************************************************************************
	**概述：
	*		设置感兴趣区域的流ID
    **输入：
	*		p_nStreamID ：感兴趣区域的流ID
	************************************************************************/
	void setStreamID(const int p_nStreamID);
    /************************************************************************
	**概述：
	*		获取感兴趣区域的流
	**返回值：
	*		感兴趣区域的流
	**************************************************************************/
	const int getStreamID() const ;
    /************************************************************************
	**概述：
	*		设置感兴趣区域的提升等级
	**输入：
	*		p_nROILevel：提升等级
	**************************************************************************/	
	void setROILevel(const int p_nROILevel);
    /************************************************************************
	**概述：
	*		获取感兴趣区域的提升等级
	**返回值：
	*		int（感兴趣区域的提升等级
	**************************************************************************/
	const int getROILevel() const ;
    //设置ROI区域坐标参数信息
    void setROIInfoList(const std::vector<ROIInfoParam> &p_objROIInfoParamList);
    //获取ROI区域坐标参数信息
    const std::vector<ROIInfoParam>& getROIInfoList()const;
    //赋值函数
    ROIAreaParam& operator = (const ROIAreaParam& p_objROIAreaParam);
    //等于比较函数
    bool operator == (const ROIAreaParam& p_objROIAreaParam)const;

private:
    int				m_nStreamID;										        //流ID
    int				m_nROILevel;										        //ROI区域的提升等级
    std::vector<ROIInfoParam> m_objROIInfoParamList;  //ROI区域列表信息
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/

#endif