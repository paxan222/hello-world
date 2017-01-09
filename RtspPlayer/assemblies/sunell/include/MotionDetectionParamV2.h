#ifndef _MOTIONDETECTIONPARAMV2_H_
#define _MOTIONDETECTIONPARAMV2_H_

#include "SNPlatOS.h"
#include "DetectionAreaV2.h"
#include <vector>
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

class SN_DLL_API MotionDetectionParamV2
{
public:

	MotionDetectionParamV2(void);
	virtual ~MotionDetectionParamV2(void);

	MotionDetectionParamV2(const MotionDetectionParamV2& p_objMotionDetectionParamV2);
	MotionDetectionParamV2& operator=(const MotionDetectionParamV2& p_objMotionDetectionParamV2);

public:


	/****************************************************************************
	**概述：
	*		设置灵敏度
	**输入：
	*		p_nSensitivity：灵敏度
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
	*		设置侦测区域的检测块数
	**输入：
	*		p_nCheckBlockNum：侦测区域的检测块数
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setCheckBlockNum(const int p_nCheckBlockNum);

	/************************************************************************
	**概述：
	*		获取侦测区域的检测块数
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		侦测区域的检测块数
	**功能：
	*
	************************************************************************/
	const int getCheckBlockNum() const ;

	/************************************************************************
	**概述：
	*		设置侦测区域
	**输入：
	*		p_pobjDetectionAreaV2：侦测区域
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	设置侦测区域
	************************************************************************/
	void setDetectionArea(const DetectionAreaV2& p_objDetectionAreaV2);

	/************************************************************************
	**概述：
	*		获取侦测区域对象
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		侦测区域对象
	**功能：
	*      
	**************************************************************************/
	const DetectionAreaV2& getDetectionArea() const;

private:

	int						m_nCheckBlockNum;										//检测块数
	int						m_nSensitivity;											//灵敏度
	DetectionAreaV2			m_objDetectionAreaV2;									//移动侦测区域

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_MOTIONDETECTIONPARAMV2_H_
