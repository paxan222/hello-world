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
//�˴����ڿ����ļ������ֽڶ��룬����ʱ����ע�ͼ�������һ�𿽱���
//�������ġ�#ifdef PRAGMA_PACK������ҲҪһ�𿽱�������pragma pack��ջ��ջ��ƥ��
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
 @brief PTZ�������ò���ʵ����
******************************************************************************/

class SN_DLL_API PTZAbilityParam
{
public:
	PTZAbilityParam(void);
	~PTZAbilityParam(void);

	//��ȡ�ٶȲ���
	const PTZSpeedParamV2& getPTZSpeedParam() const {return m_objPTZSpeedParamV2;}
	//�����ٶȲ���
	void setPTZSpeedParam(const PTZSpeedParamV2 &p_objPTZSpeedParam);
	//��ȡ�켣��������
	const TraceAbilityParamV2& getTraceAbilityParam() const {return m_objTraceAbilityParamV2;}
	//���ù켣��������
	void setTraceAbilityParam(const TraceAbilityParamV2 &p_objTraceAbilityParam);
	//��ȡ��ѧ��������
	const MaxOpticalMagnificationParamV2& getOpticalMagnificationParam() const {return m_objMaxOpticalMagnificationParamV2;}
	//���ù�ѧ��������
	void setOpticalMagnificationParam(const MaxOpticalMagnificationParamV2 &p_objOpticalMagnificationParam);
	//����OSD����
	void setPTZOSDParamList(const std::vector<PTZOSDParam>& p_vecPTZOSDParamList);
	//��ȡOSD����
	const std::vector<PTZOSDParam>& getPTZOSDParamList()const;
	//����Ѳ����������
	void setTourAbilityParam(const TourAbilityParamV2 &p_objTourAbilityParamV2);
	//��ȡѲ����������
	const TourAbilityParamV2 &getTourAbilityParam()const;
	//����ɨ����������
	void setScanAbilityParam(const ScanAbilityParamV2 &p_objScanAbilityParamV2);
	//��ȡɨ����������
	const ScanAbilityParamV2 &getScanAbilityParam()const;
	//���õ�λ��
	void setPTSpeedTable(const PTSpeedTable &p_objPTSpeedTable);
	//��ȡ��λ��
	const PTSpeedTable &getPTSpeedTable() const;
	//��ȡ��ֱ���ǶȲ���
	const VerticalMaxPositionParamV2& getVerticalMaxPositionParam() const {return m_objVerticalMaxPositionParamV2;}
	//���ô�ֱ���ǶȲ���
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
	MaxOpticalMagnificationParamV2	m_objMaxOpticalMagnificationParamV2;//����ѧ��������
	std::vector<PTZOSDParam>		m_vecPTZOSDParamList;				//PTZ��ʾ����

	PTZSpeedParamV2					m_objPTZSpeedParamV2;				//PTZ�ٶȲ���	
	TraceAbilityParamV2				m_objTraceAbilityParamV2;			//�켣��������
	TourAbilityParamV2				m_objTourAbilityParamV2;			//Ѳ����������
	ScanAbilityParamV2				m_objScanAbilityParamV2;			//ɨ����������
	PTSpeedTable m_objPTSpeedTable;									//����,��λ���ٶȶ��յ�λ��,Ϊ���Ʊ��ٶ��ع�2015.06.17
	TiltAngleDisplayParamV2			m_objTiltAngleDisplayParamV2;		//��ֱ�Ƕ���ʾ��������
	VerticalMaxPositionParamV2		m_objVerticalMaxPositionParamV2;	//��ֱ���ǶȲ���
	
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
