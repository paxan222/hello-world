#ifndef _PTZ_ABILITY_PARAM_H
#define _PTZ_ABILITY_PARAM_H

#include "SNPlatOS.h"
#include "PTZSpeedParamV2.h"
#include "TraceAbilityParamV2.h"
#include "TourAbilityParamV2.h"
#include "ScanAbilityParamV2.h"
#include "PTZStageToSpeedParam.h"
#include "MaxOpticalMagnificationParamV2.h"
#include "PTZOSDParam.h"
#include "PresetPosAbilityParam.h"
#include "TiltAngleDisplayParamV2.h"
#include "GuardPosAbilityParam.h"
#include "InfraredLampAbilityParam.h"
#include "DueNorthAbilityParam.h"
#include "TimerAbilityParam.h"
#include "PTSpeedTable.h"
#include "VerticalMaxPositionParamV2.h"
#include "ThreeDimensionalPositionAbilityParam.h"

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
/**********************************************************************/

/***************************************************************************//**
 @brief PTZ能力设置参数实体类
******************************************************************************/

class SN_DLL_API PTZAbilityParam
{
public:
	PTZAbilityParam(void);
	~PTZAbilityParam(void);

	//获取速度参数
	const PTZSpeedParamV2& getPTZSpeedParam() const {return m_objPTZSpeedParamV2;}
	//设置速度参数
	void setPTZSpeedParam(const PTZSpeedParamV2 &p_objPTZSpeedParam);
	//获取轨迹能力参数
	const TraceAbilityParamV2& getTraceAbilityParam() const {return m_objTraceAbilityParamV2;}
	//设置轨迹能力参数
	void setTraceAbilityParam(const TraceAbilityParamV2 &p_objTraceAbilityParam);
	//获取光学倍数参数
	const MaxOpticalMagnificationParamV2& getOpticalMagnificationParam() const {return m_objMaxOpticalMagnificationParamV2;}
	//设置光学倍数参数
	void setOpticalMagnificationParam(const MaxOpticalMagnificationParamV2 &p_objOpticalMagnificationParam);
	//设置OSD参数
	void setPTZOSDParamList(const std::vector<PTZOSDParam>& p_vecPTZOSDParamList);
	//获取OSD参数
	const std::vector<PTZOSDParam>& getPTZOSDParamList()const;
	//设置巡游能力参数
	void setTourAbilityParam(const TourAbilityParamV2 &p_objTourAbilityParamV2);
	//获取巡游能力参数
	const TourAbilityParamV2 &getTourAbilityParam()const;
	//设置扫描能力参数
	void setScanAbilityParam(const ScanAbilityParamV2 &p_objScanAbilityParamV2);
	//获取扫描能力参数
	const ScanAbilityParamV2 &getScanAbilityParam()const;
	//设置档位表
	void setPTSpeedTable(const PTSpeedTable &p_objPTSpeedTable);
	//获取档位表
	const PTSpeedTable &getPTSpeedTable() const;
	//获取垂直最大角度参数
	const VerticalMaxPositionParamV2& getVerticalMaxPositionParam() const {return m_objVerticalMaxPositionParamV2;}
	//设置垂直最大角度参数
	void setVerticalMaxPositionParam(const VerticalMaxPositionParamV2 &p_objVerticalMaxPositionParam);

	void setPresetPosAbilityParam(const PresetPosAbilityParam & p_objPresetPosAbilityParam);
	const PresetPosAbilityParam & getPresetPosAbilityParam() const;
	void setTiltAngleDisplayParam(const TiltAngleDisplayParamV2 &p_ojbTiltAngleDisplayParamV2);
	const TiltAngleDisplayParamV2& getTiltAngleDisplayParam()const;

	void setGuardPosAbilityParam(const GuardPosAbilityParam & p_objGuardPosAbilityParam);
	const GuardPosAbilityParam & getGuardPosAbilityParam() const;

	void setInfraredLampAbilityParam(const InfraredLampAbilityParam & p_objInfraredLampAbilityParam);
	const InfraredLampAbilityParam & getInfraredLampAbilityParam() const;

	void setDueNorthAbilityParam(const DueNorthAbilityParam & p_objDueNorthAbilityParam);
	const DueNorthAbilityParam & getDueNorthAbilityParam() const;

	void setTimerAbilityParam(const TimerAbilityParam & p_objTimerAbilityParam);
	const TimerAbilityParam & getTimerAbilityParam() const;

	void setThreeDimensionalPositionAbilityParam(const ThreeDimensionalPositionAbilityParam& p_objThreeDimensionalPositionAbilityParam);
	const ThreeDimensionalPositionAbilityParam& getThreeDimensionalPositionAbilityParam()const;

	void setVerticalMaxPositionNum(const int p_nVerticalMaxPositionNum);
	const int getVerticalMaxPositionNum()const;

	PTZAbilityParam& operator=(const PTZAbilityParam &p_objPTZAbilityParam);

private:	
	MaxOpticalMagnificationParamV2	m_objMaxOpticalMagnificationParamV2;//最大光学倍数参数
	std::vector<PTZOSDParam>		m_vecPTZOSDParamList;				//PTZ显示参数

	PTZSpeedParamV2					m_objPTZSpeedParamV2;				//PTZ速度参数	
	TraceAbilityParamV2				m_objTraceAbilityParamV2;			//轨迹能力参数
	TourAbilityParamV2				m_objTourAbilityParamV2;			//巡游能力参数
	ScanAbilityParamV2				m_objScanAbilityParamV2;			//扫描能力参数
	PTSpeedTable m_objPTSpeedTable;									//倍数,档位与速度对照档位表,为定制倍速而重构2015.06.17
	TiltAngleDisplayParamV2			m_objTiltAngleDisplayParamV2;		//垂直角度显示能力参数
	VerticalMaxPositionParamV2		m_objVerticalMaxPositionParamV2;	//垂直最大角度参数
	
	PresetPosAbilityParam			m_objPresetPosAbilityParam;			//PresetPosition Ability Parameter
	GuardPosAbilityParam			m_objGuardPosAbilityParam;			//Guard Position Ability Parameter
	InfraredLampAbilityParam		m_objInfraredLampAbilityParam;		//Infrared Lamp Ability Parameter
	DueNorthAbilityParam			m_objDueNorthAbilityParam;			//Due North Ability Parameter
	TimerAbilityParam				m_objTimerAbilityParam;				//Timer ability Parameter
	ThreeDimensionalPositionAbilityParam m_objThreeDimensionalPositionAbilityParam;
	int								m_nVerticalMaxPositionNum;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/

#endif
