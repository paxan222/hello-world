#ifndef _FISHEYE_VIDEO_ABILITY_H_
#define _FISHEYE_VIDEO_ABILITY_H_

#include <vector>
#include "FisheyeDewarpMode.h"
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

class  SN_DLL_API FisheyeVideoAbility
{
public:
	FisheyeVideoAbility();
	~FisheyeVideoAbility();

public:
	/************************************************************************
	**概述：设置鱼眼视频模式参数
	**输入：
	*		p_nFisheyeVideoMode：视频模式：单流模式和多流模式
	*		
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/	
	void setFisheyeVideoMode(const int &p_nFisheyeVideoMode);
	/************************************************************************
	**概述：获取鱼眼视频模式参数
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		p_nFisheyeVideoMode：视频模式：单流模式和多流模式
	*************************************************************************/	
	const int getFisheyeVideoMode()const;

	/************************************************************************
	**概述：设置鱼眼矫正模式列表
	**输入：
	*		p_nDewarpModeList：鱼眼矫正模式列表	
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/	
	void setDewardModeList(const std::vector<FisheyeDewarpMode> &p_nDewarpModeList);
	/************************************************************************
	**概述：获取鱼眼矫正模式列表
	**输入：
	*		无
	**输出：
	*		p_nDewarpModeList：鱼眼矫正模式列表	
	**返回值：
	*		无
	*************************************************************************/	
	void getDewardModeList(std::vector<FisheyeDewarpMode> &p_nDewarpModeList)const;

	bool operator==(const FisheyeVideoAbility& p_objFisheyeVideoAbility)const;
private:
	int m_nFisheyeVideoMode;	//鱼眼视频模式,具体定义可查看FisheyeConst.h中FISHEYE_VIDEO_MODE枚举定义
	std::vector<FisheyeDewarpMode> m_objDewarpModeList; //鱼眼矫正模式
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/
#endif //_FISHEYE_VIDEO_ABILITY_H_
