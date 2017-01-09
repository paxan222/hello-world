#ifndef PTZTourPointV2_H_
#define PTZTourPointV2_H_

#include "DomainConst.h"
#include <string.h>
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

class SN_DLL_API PTZTourPointV2
{
public:
	PTZTourPointV2(void);
	~PTZTourPointV2(void);
/************************************************************************
	**概述：
	*		设置云台预制点ID号
	**输入：
	*		p_nPresetId ：预制点的ID号
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setPresetId(const int p_nPresetId);

	/************************************************************************
	**概述：
	*		获取预制点的ID号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		预制点的ID号
	**功能：
	*    
	************************************************************************/
	const int getPresetId() const;

	/************************************************************************
	**概述：
	*		设置预置点转动速度
	**输入：
	*		p_nSpeedValue ：转动速度
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setSpeedValue(const int p_nSpeedValue);

	/************************************************************************
	**概述：
	*		获取预置点转动速度
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		预置点转动速度
	**功能：
	*    
	************************************************************************/
	const int getSpeedValue() const;

	/************************************************************************
	**概述：
	*		设置停止时间
	**输入：
	*		p_nStopTime ：停止时间
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setStopTime(const int p_nStopTime);

	/************************************************************************
	**概述：
	*		获取停止时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		停止时间
	**功能：
	*    
	************************************************************************/
	const int getStopTime() const;

	PTZTourPointV2 &operator=(const PTZTourPointV2 p_objPTZTourPointV2);
private:
	int m_nPresetId;
	int m_nSpeedValue;
	int m_nStopTime;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
#endif


