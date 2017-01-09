#ifndef _FISHEYE_ABILITY_H_
#define _FISHEYE_ABILITY_H_

#include <vector>
#include <string>
#include "FisheyeVideoAbility.h"
#include "FisheyeMountParam.h"
#include "FisheyeMountAbility.h"
#include "FisheyeConst.h"
#include "SNPlatOS.h"

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

class SN_DLL_API FisheyeAbility
{
public:
	FisheyeAbility();
	~FisheyeAbility();
public:
	/************************************************************************
	**概述：
	*		设置鱼眼安装方式能力
	**输入：
	*		p_objFisheyeMountAbility：鱼眼安装方式能力
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/	
	void setFisheyeMountAbility(const FisheyeMountAbility& p_objFisheyeMountAbility);
	/************************************************************************
	**概述：
	*		获取鱼眼安装方式能力
	**输入：无
	*		
	**输出：无
	*		
	**返回值：
	*		鱼眼安装方式能力
	*************************************************************************/	
	const FisheyeMountAbility& getFisheyeMountAbility()const;
	/************************************************************************
	**概述：设置鱼眼视频能力（包含矫正模式和流模式）
	**输入：
	*		p_objFisheyeVideoAbilityList：鱼眼视频能力列表
	*		
	**输出：无
	*		
	**返回值：
	*		无
	*************************************************************************/	
	void setFisheyeVideoAbilityList(const std::vector<FisheyeVideoAbility> &p_objFisheyeVideoAbilityList);
	/************************************************************************
	**概述：获取鱼眼视频能力（包含矫正模式和流模式）
	**输入：
	*		无
	*		
	**输出：
	*		p_objFisheyeVideoAbilityList：鱼眼视频能力列表
	**返回值：
	*		无
	*************************************************************************/	
	void getFisheyeVideoAbilityList(std::vector<FisheyeVideoAbility>& p_objFisheyeVideoAbilityList)const;
	
	/************************************************************************
	**概述：设置支持鱼眼能力标志
	**输入：
	*		p_bSupportFlag：支持鱼眼能力标志
	*		
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/	
	void setFisheyeSupportFlag(const bool p_bSupportFlag);
	/************************************************************************
	**概述：获取支持鱼眼能力标志
	**输入：
	*		无
	*		
	**输出：
	*		无
	**返回值：
	*		ture：支持鱼眼；false:不支持鱼眼
	*************************************************************************/	
	const bool getFisheyeSupportFlag(void) const;

	FisheyeAbility& operator=(const FisheyeAbility& p_objFisheyeAbility);

private:
	bool m_bFisheyeSupportFlag;
	FisheyeMountAbility   m_objFishMountAbility; 
	std::vector<FisheyeVideoAbility> m_objFisheyeVideoAbilityList; //鱼眼视频能力

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/
#endif //_FISHEYE_ABILITY_H_
