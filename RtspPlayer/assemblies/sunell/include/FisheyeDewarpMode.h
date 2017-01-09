#ifndef _FISHEYE_DEWARP_MODE_H_
#define _FISHEYE_DEWARP_MODE_H_

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

class  SN_DLL_API FisheyeDewarpMode
{
public:
	FisheyeDewarpMode();
	~FisheyeDewarpMode();

public:
	/************************************************************************
	**概述：设置鱼眼矫正模式参数
	**输入：
	*		p_nDewarpMode：矫正模式参数
	*		
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/	
	void setDewarpMode(const int p_nDewarpMode);
	/************************************************************************
	**概述：获取鱼眼矫正模式参数
	**输入：
	*		无		
	**输出：
	*		无
	**返回值：
	*		矫正模式参数
	*************************************************************************/
	int getDewarpMode(void)const;

	/************************************************************************
	**概述：设置可移动PTZ标志
	**输入：
	*		p_bMovable：可移动PTZ标志
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setMoveable(const bool p_bMovable);
	/************************************************************************
	**概述：获取可移动PTZ标志
	**输入：
	*		无	
	**输出：
	*		无
	**返回值：
	*		可移动PTZ标志 true 可移动PTZ;
	*************************************************************************/
	bool getMoveable(void) const;
	
	bool operator==(const FisheyeDewarpMode& p_objFisheyeDewarpMode)const;
	bool operator!=(const FisheyeDewarpMode& p_objFisheyeDewarpMode)const;
private:
	int m_nDewarpMode;	//矫正模式,具体定义可查看FisheyeConst.h中FISHEYE_DEWARP_MODE枚举定义
	bool m_bMoveable;	//是否可移动标识
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif //_FISHEYE_DEWARP_MODE_H_
