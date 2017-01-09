#ifndef PTZ_SPEED_PARAM_V2_h__
#define PTZ_SPEED_PARAM_V2_h__



#include <vector>
#include "SNPlatOS.h"
#include "PTZStageToSpeedParam.h"
#include "IPTZModuleAbilityParam.h"

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


/***************************************************************************//**
 @brief 速度设置参数实体类
******************************************************************************/

class SN_DLL_API PTZSpeedParamV2 : public IPTZModuleAbilityParam
{
public:
	PTZSpeedParamV2();
	~PTZSpeedParamV2();

	// 获取pan步数周期
	const int getPanStepPeriod() const { return m_nPanStepPeriod; }

	// 设置pan步数周期
	void setPanStepPeriod(const int p_nPeriod);

	// 获取tilt步数周期
	const int getTiltStepPeriod() const { return m_nTiltStepPeriod; }

	// 设置tilt步数周期
	void setTiltStepPeriod(const int p_nPeriod);

	// 获取速度参数列表
	const std::vector<PTZStageToSpeedParam>& getSpeedList() const { return m_objSpeedParamList; }

	// 设置速度参数列表
	void setSpeedList(const std::vector<PTZStageToSpeedParam>& p_objSpeedParamlist);

	// 获取Pan最大goto速度
	const int getPanGotoMaxSpeed() const { return m_nPanGotoMaxSpeed; }

	// 设置Pan最大goto速度
	void setPanGotoMaxSpeed(const int p_nMaxSpeed);

	// 获取Tilt最大goto速度
	const int getTiltGotoMaxSpeed() const { return m_nTiltGotoMaxSpeed; }

	// 设置Tilt最大goto速度
	void setTiltGotoMaxSpeed(const int p_nMaxSpeed);

	//赋值函数
	PTZSpeedParamV2& operator=(const PTZSpeedParamV2 &objPTZSpeedParamV2);

	void setSpeedRange(const int & p_nSpeedRangeFrom , const int & p_nSpeedRangeTo);

	bool getSpeedRange(int & p_nSpeedRangeFrom , int & p_nSpeedRangeTo) const;

private:
	int m_nPanStepPeriod;		// pan步数周期
	int m_nTiltStepPeriod;		// tilt步数周期
	std::vector<PTZStageToSpeedParam> m_objSpeedParamList;		// 速度参数列表
	int m_nPanGotoMaxSpeed;		// pan最大goto速度
	int m_nTiltGotoMaxSpeed;	// tilt最大goto速度

	int		m_nMinSpeed;
	int		m_nMaxSpeed;	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/


#endif // PTZ_SPEED_PARAM_V2_h__