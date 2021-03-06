#ifndef _VIDE_OOUT_ABILITY_H_
#define _VIDE_OOUT_ABILITY_H_
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



class SN_DLL_API VideoOutAbility
{

public:
	VideoOutAbility();
	~VideoOutAbility();
	/************************************************************************
	**概述：设置模拟输出是否可配标记
	*
	**输入：
	*		p_VideoOutConfigurable   可配标记
	**输出：
	*		无
	**功能：       
	*		设置模拟输出是否可配
	************************************************************************/
	void setVideoOutConfigurable(const bool p_VideoOutConfigurable);

	/************************************************************************
	**概述：获取模拟输出是否可配标记
	*
	**输入：
	*		无
	**返回：
	*		可配标记
	**功能：       
	*		获取模拟输出是否可配标记
	************************************************************************/
	const bool getVideoOutConfigurable() const;

	/************************************************************************
	**概述：设置是否支持视频模拟输出
	*
	**输入：
	*		p_Flag   支持标记
	**输出：
	*		无
	**功能：       
	*		设置是否支持视频模拟输出
	************************************************************************/
	void setIsSupportVideoOut(const bool p_Flag);

	/************************************************************************
	**概述：获取是否支持视频模拟输出
	*
	**输入：
	*		无
	**输出：
	*		无
	**功能：       
	*		获取是否支持视频模拟输出
	************************************************************************/
	const bool getIsSupportVideoOut() const;


private:
	bool m_VideoOutConfigurable;   
	bool m_IsSupportVideoOut;
	    					
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif 

