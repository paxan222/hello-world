#ifndef _CAMERATAMPERABILITY_H_
#define _CAMERATAMPERABILITY_H_

#include "SNPlatOS.h"
#include "DomainConst.h"
#include <string>

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

class SN_DLL_API CameraTamperAbility
{
public:
	CameraTamperAbility();
	~CameraTamperAbility();
	CameraTamperAbility& operator=(const CameraTamperAbility& p_objCameraTamperAbility);
    /***********************************************************************
	*	概述：设置提供视频遮挡（CameraTamper）功能的智能库的ID
	*	输入：
	*		p_nLibId ：智能库ID
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       输入的智能库ID需要跟能力列表的库ID匹配，不然将视为非法的ID，
	*       功能无法正常启用。
	************************************************************************/
	void setLibId(const int p_nLibId);

    /***********************************************************************
	*	概述：获取提供视频遮挡（CameraTamper）功能的智能库的ID
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		const int : 当前提供该功能的智能库ID
	*   功能正文：
	*       返回的库ID是当前设备提供该智能分析功能的库ID
	************************************************************************/
	const int getLibId() const;

    /***********************************************************************
	*	概述：设置视频遮挡（CameraTamper）能力是否支持
	*	输入：
	*		p_bEnable ：是否支持该项能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       输入为true : 支持该项能力；
	*       输入为false : 不支持该项能力。
	************************************************************************/
	void setEnable(const bool p_bEnable);

    /***********************************************************************
	*	概述：获取视频遮挡（CameraTamper）能力是否支持
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		bool : 如果支持，返回true；
	*              如果不支持，返回false。
	*   功能正文：
	*       无
	************************************************************************/
	const bool getEnable() const;

    /***********************************************************************
	*	概述：设置是否支持最小时间的能力
	*	输入：
	*		p_bMinTimeEnable ：是否支持该项能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       输入为true : 支持该项能力；
	*       输入为false : 不支持该项能力。
	************************************************************************/
	void setMinTimeEnable(const bool p_bMinTimeEnable);

    /***********************************************************************
	*	概述：获取是否支持最小时间的能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		bool : 如果支持，返回true；
	*              如果不支持，返回false。
	*   功能正文：
	*       无
	************************************************************************/
	const bool getMinTimeEnable() const;

    /***********************************************************************
	*	概述：设置最小时间的最大值
	*	输入：
	*		p_nMinTimeMax ：最小时间的最大值
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       输入为true : 支持该项能力；
	*       输入为false : 不支持该项能力。
	************************************************************************/
	void setMinTimeMax(const int p_nMinTimeMax);

    /***********************************************************************
	*	概述：获取最小时间的最大值
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int : 最小时间的最大值
	*   功能正文：
	*       无
	************************************************************************/
	const int getMinTimeMax() const;

    /***********************************************************************
	*	概述：设置最小时间的最小值
	*	输入：
	*		p_nMinTimeMax ：最小时间的最小值
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       输入为true : 支持该项能力；
	*       输入为false : 不支持该项能力。
	************************************************************************/
	void setMinTimeMin(const int p_nMinTimeMin);

    /***********************************************************************
	*	概述：获取最小时间的最小值
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int : 最小时间的最小值
	*   功能正文：
	*       无
	************************************************************************/
	const int getMinTimeMin() const;

    /***********************************************************************
	*	概述：设置最小时间的单位
	*	输入：
	*		p_pMinTimeUnit ：最小时间的单位
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       输入为true : 支持该项能力；
	*       输入为false : 不支持该项能力。
	************************************************************************/
	bool setMinTimeUnit(const char* p_pMinTimeUnit);

    /***********************************************************************
	*	概述：获取最小时间的单位
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		string : 最小时间的单位
	*   功能正文：
	*       无
	************************************************************************/
	const char* getMinTimeUnit() const;

private:
	bool m_bEnable;
	int m_nLibId;
	bool m_bMinTimeEnable;
	int m_nMinTimeMax;
	int m_nMinTimeMin;
	char m_pMinTimeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif   //_CAMERATAMPERABILITY_H_
