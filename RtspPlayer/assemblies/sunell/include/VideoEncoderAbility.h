#ifndef _VIDEOENCODERABILITY_H_
#define _VIDEOENCODERABILITY_H_

#include "SNPlatOS.h"
#include "VideoResolutionAbility.h"
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

/************************************************************************
**概述：编码器能力信息类
*	包含：视频格式,最大码率,最小码率,最大码率,最小码率,最大视频质量值,最小视频质量值,码率类型列表
************************************************************************/

class SN_DLL_API VideoEncoderAbility
{
public:
	VideoEncoderAbility(void);
	~VideoEncoderAbility(void);

	VideoEncoderAbility(const VideoEncoderAbility &p_VideoEncoderAbility);

public:
	/************************************************************************
	*	概述：设置编码器类型
	*	输入：
	*		p_nEncoderType：编码器类型
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setEncoderType(int p_nEncoderType);

	/************************************************************************
	*	概述：获取编码器类型
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		编码器类型
	*************************************************************************/
	int getEncoderType() const;

	/************************************************************************
	*	概述：设置编码器名称
	*	输入：
	*		p_pszEncoderName：编码器名称
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	bool setEncoderName(const char* p_pszEncoderName);

	/************************************************************************
	*	概述：获取编码器名称
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		编码器名称
	*************************************************************************/
	const char* getEncoderName() const;

	/************************************************************************
	*	概述：设置视频编码总能力
	*	输入：
	*		p_nVideoEncodeTotleAbility：视频编码总能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setVideoEncodeTotleAbility(int p_nVideoEncodeTotleAbility);

	/************************************************************************
	*	概述：获取视频编码总能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		视频编码总能力
	*************************************************************************/
	int getVideoEncodeTotleAbility() const;

	/************************************************************************
	*	概述：设置分辨率能列表
	*	输入：
	*		p_objVideoResolutionAbilityList：分辨率能列表
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setVideoResolutionAbilityList(const std::vector<VideoResolutionAbility> & p_objVideoResolutionAbilityList);

	/************************************************************************
	*	概述：获取分辨率能列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		分辨率能列表
	*************************************************************************/
	const std::vector<VideoResolutionAbility> & getVideoResolutionAbilityList() const;

	bool findVideoResolutionAbility(const VideoResolution & p_objVideoResolution, VideoResolutionAbility & p_objVideoResolutionAbility) const;

	/************************************************************************
	*	概述：
	*		赋值函数
	*	输入：
	*		p_objVideoEncoderAbility ：视频编码能力对象
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	VideoEncoderAbility& operator = (const VideoEncoderAbility &p_objVideoEncoderAbility);

private:
	int									m_nEncoderType;										//编码器类型
	char								m_szEncoderName[CONST_MAXLENGTH_ENCODER_NAME + 1];	//编码器名称
	int									m_nVideoEncodeTotleAbility;							//视频编码总能力 
	std::vector<VideoResolutionAbility> m_objVideoResolutionAbilityList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_ENCODER_ABILITY_
