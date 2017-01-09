#ifndef _OCCLUSIONDETECTIONPARAM_H_
#define _OCCLUSIONDETECTIONPARAM_H_

#include "SNPlatOS.h"
#include "DetectionArea.h"
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

class SN_DLL_API OcclusionDetectionParam
{
public:
	OcclusionDetectionParam(void);
	~OcclusionDetectionParam(void);

	//拷贝构造函数
	OcclusionDetectionParam (const OcclusionDetectionParam &p_objOcclusionDetectionParam);

	/****************************************************************************
	**概述：
	*		设置灵敏度
	**输入：
	*		p_nSensitivity：灵敏度(1-100)，指占总侦测区域的百分比，百分比越小，侦测灵敏度越高
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setSensitivity(const int p_nSensitivity);

	/****************************************************************************
	**概述：
	*		获得灵敏度
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		灵敏度
	**功能：
	*
	*******************************************************************************/
	const int getSensitivity() const;

	/************************************************************************
	**概述：
	*		设置侦测区域对象列表
	**输入：
	*		p_objDetectionAreaList	侦测区域对象列表
	**输出：
	*		无
	**返回值：
	*		无
	**************************************************************************/
	void setDetectionArea(const std::vector<DetectionArea> &p_objDetectionAreaList);

	/************************************************************************
	**概述：
	*		获取侦测区域对象列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		侦测区域对象列表
	**功能：
	*      
	**************************************************************************/
	const std::vector<DetectionArea> &getDetectionArea() const;

	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objOcclusionDetectionParam：移动侦测规则对象
	**输出：
	*		无
	**返回值：
	*		赋值后的移动侦测规则对象
	**功能：
	*		
	*****************************************************************************/
	OcclusionDetectionParam& operator = (const OcclusionDetectionParam &p_objOcclusionDetectionParam);

private:
	int									m_nSensitivity;						//灵敏度(1-100)，指占总侦测区域的百分比，百分比越小，侦测灵敏度越高
	std::vector<DetectionArea>			m_objDetectionAreaList;				//侦测区域列表
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_OCCLUSIONDETECTIONPARAM_H_
