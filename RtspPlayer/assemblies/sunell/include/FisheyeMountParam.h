#ifndef _FISHEYE_MOUNT_PARAM_H_
#define _FISHEYE_MOUNT_PARAM_H_

#include "FisheyeConst.h"
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

class  SN_DLL_API FisheyeMountParam
{
public:
	FisheyeMountParam();
	~FisheyeMountParam();

public:
	/****************************************************************************
	**概述：
	*		设置鱼眼安装方式参数
	**输入：
	*		p_nFisheyeMountType：安装方式
	**输出：
	*		无
	**返回值：
	*		无
	**功能：设置鱼眼安装方式
	*****************************************************************************/
	void setFisheyeMountType(const int p_nFisheyeMountType);
	/****************************************************************************
	**概述：
	*		获取鱼眼安装方式
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		鱼眼安装方式
	**功能：获取鱼眼安装方式
	*****************************************************************************/
	int getFisheyeMountType(void)const;

	/****************************************************************************
	**概述：
	*	判等函数
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		相等返回true, 不等返回false
	**功能：
	*****************************************************************************/
	bool operator == (const FisheyeMountParam& p_objRhs);
private:
	int m_nFisheyeMountType;	//安装模式

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif//_FISHEYE_MOUNT_PARAM_H_
