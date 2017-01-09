#ifndef _INTELLIGENCEANALYSEABILITY_H
#define _INTELLIGENCEANALYSEABILITY_H

#include "LibCommonAbility.h"
#include "MotionDetectionAbilityV2.h"
#include "PerimeterAbility.h"
#include "TripWireAbility.h"
#include "MultiTripWireAbility.h"
#include "LoiterAbility.h"
#include "MultiLoiterAbility.h"
#include "ObjLeftAbility.h"
#include "ObjMoveAbility.h"
#include "AbnormalSpeedAbility.h"
#include "ConverseAbility.h"
#include "NoParkingAbility.h"
#include "CameraTamperAbility.h"
#include "CameraMoveAbility.h"
#include "AdvancedAbility.h"
#include "SignalBadAbility.h"

#include <string>
#include <vector>

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

class SN_DLL_API IntelligenceAnalyseAbility
{
public:
	IntelligenceAnalyseAbility();
	~IntelligenceAnalyseAbility();

    /***********************************************************************
	*	概述：设置智能分析能力的版本
	*	输入：
	*		p_nVersion ：智能分析能力的版本
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       版本用于标志当前能力是否最新的
	************************************************************************/
	void setVersion(const int p_nVersion);

    /***********************************************************************
	*	概述：获取智能分析能力的版本
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int ：智能分析能力的版本
	*   功能正文：
	*       版本用于标志当前能力是否最新的
	************************************************************************/
	const int getVersion() const;

    /***********************************************************************
	*	概述：设置智能分析的公共能力列表
	*	输入：
	*		p_objLibCommonAbilityList ：智能分析的公共能力列表
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       p_objLibCommonAbilityList列表中为当前设备可以支持的智能分析库的个数，
	*       以及需要的配置参数。
	************************************************************************/
	void setLibCommonAbilityList(const std::vector<LibCommonAbility> &p_objLibCommonAbilityList);

    /***********************************************************************
	*	概述：获取智能分析的公共能力列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		vector<LibCommonAbility> ：智能分析的公共能力列表
	*   功能正文：
	*       p_objLibCommonAbilityList列表中为当前设备可以支持的智能分析库的个数，
	*       以及需要的配置参数。
	************************************************************************/
	const std::vector<LibCommonAbility>& getLibCommonAbilityList() const;

    /***********************************************************************
	*	概述：设置智能分析的移动侦测的能力
	*	输入：
	*		p_objMotionDetectionAbilityV2 ：智能分析的智能分析的移动侦测的能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setMotionDetectionAbilityV2(const MotionDetectionAbilityV2 &p_objMotionDetectionAbilityV2);

    /***********************************************************************
	*	概述：获取智能分析的移动侦测的能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		MotionDetectionAbilityV2 ：智能分析的移动侦测的能力
	*   功能正文：
	*       无
	************************************************************************/
	const MotionDetectionAbilityV2& getMotionDetectionAbilityV2() const;

    /***********************************************************************
	*	概述：设置智能分析的周界入侵的能力
	*	输入：
	*		p_objPerimeterAbility ：智能分析的周界入侵的能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setPerimeterAbility(const PerimeterAbility &p_objPerimeterAbility);

    /***********************************************************************
	*	概述：获取智能分析的周界入侵的能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		PerimeterAbility ：智能分析的周界入侵的能力
	*   功能正文：
	*       无
	************************************************************************/
	const PerimeterAbility& getPerimeterAbility() const;

    /***********************************************************************
	*	概述：设置智能分析的绊线的能力
	*	输入：
	*		p_objTripWireAbility ：智能分析的绊线的能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setTripWireAbility(const TripWireAbility &p_objTripWireAbility);

    /***********************************************************************
	*	概述：获取智能分析的绊线的能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		TripWireAbility ：智能分析的绊线的能力
	*   功能正文：
	*       无
	************************************************************************/
	const TripWireAbility& getTripWireAbility() const;

    /***********************************************************************
	*	概述：设置智能分析的双绊线的能力
	*	输入：
	*		p_objMultiTripWireAbility ：智能分析的双绊线的能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setMultiTripWireAbility(const MultiTripWireAbility &p_objMultiTripWireAbility);

    /***********************************************************************
	*	概述：获取智能分析的绊线的能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		MultiTripWireAbility ：智能分析的双绊线的能力
	*   功能正文：
	*       无
	************************************************************************/
	const MultiTripWireAbility& getMultiTripWireAbility() const;

    /***********************************************************************
	*	概述：设置智能分析的徘徊的能力
	*	输入：
	*		p_objLoiterAbility ：智能分析的徘徊的能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setLoiterAbility(const LoiterAbility &p_objLoiterAbility);

    /***********************************************************************
	*	概述：获取智能分析的徘徊的能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		LoiterAbility ：智能分析的徘徊的能力
	*   功能正文：
	*       无
	************************************************************************/
	const LoiterAbility& getLoiterAbility() const;

    /***********************************************************************
	*	概述：设置智能分析的多人徘徊的能力
	*	输入：
	*		p_objMultiLoiterAbility ：智能分析的多人徘徊的能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setMultiLoiterAbility(const MultiLoiterAbility &p_objMultiLoiterAbility);

    /***********************************************************************
	*	概述：获取智能分析的多人徘徊的能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		MultiLoiterAbility ：智能分析的多人徘徊的能力
	*   功能正文：
	*       无
	************************************************************************/
	const MultiLoiterAbility& getMultiLoiterAbility() const;

    /***********************************************************************
	*	概述：设置智能分析的物体遗留的能力
	*	输入：
	*		p_objObjLeftAbility ：智能分析的物体遗留的能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setObjLeftAbility(const ObjLeftAbility &p_objObjLeftAbility);

    /***********************************************************************
	*	概述：获取智能分析的物体遗留的能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		ObjLeftAbility ：智能分析的物体遗留的能力
	*   功能正文：
	*       无
	************************************************************************/
	const ObjLeftAbility& getObjLeftAbility() const;

    /***********************************************************************
	*	概述：设置智能分析的物体移动的能力
	*	输入：
	*		p_objObjMoveAbility ：智能分析的物体移动的能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setObjMoveAbility(const ObjMoveAbility &p_objObjMoveAbility);

    /***********************************************************************
	*	概述：获取智能分析的物体移动的能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		ObjMoveAbility ：智能分析的物体移动的能力
	*   功能正文：
	*       无
	************************************************************************/
	const ObjMoveAbility& getObjMoveAbility() const;

    /***********************************************************************
	*	概述：设置智能分析的非正常速度的能力
	*	输入：
	*		p_objAbnormalSpeedAbility ：智能分析的非正常速度的能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setAbnormalSpeedAbility(const AbnormalSpeedAbility &p_objAbnormalSpeedAbility);

    /***********************************************************************
	*	概述：获取智能分析的非正常速度的能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		AbnormalSpeedAbility ：智能分析的非正常速度的能力
	*   功能正文：
	*       无
	************************************************************************/
	const AbnormalSpeedAbility& getAbnormalSpeedAbility() const;

    /***********************************************************************
	*	概述：设置智能分析的逆行的能力
	*	输入：
	*		p_objConverseAbility ：智能分析的逆行的能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setConverseAbility(const ConverseAbility &p_objConverseAbility);

    /***********************************************************************
	*	概述：获取智能分析的逆行的能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		ConverseAbility ：智能分析的逆行的能力
	*   功能正文：
	*       无
	************************************************************************/
	const ConverseAbility& getConverseAbility() const;

    /***********************************************************************
	*	概述：设置智能分析的非法停车的能力
	*	输入：
	*		p_objNoParkingAbility ：智能分析的非法停车的能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setNoParkingAbility(const NoParkingAbility &p_objNoParkingAbility);

    /***********************************************************************
	*	概述：获取智能分析的非法停车的能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		NoParkingAbility ：智能分析的非法停车的能力
	*   功能正文：
	*       无
	************************************************************************/
	const NoParkingAbility& getNoParkingAbility() const;

    /***********************************************************************
	*	概述：设置智能分析的信号异常的能力
	*	输入：
	*		p_objSignalBadAbility ：智能分析的信号异常的能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setSignalBadAbility(const SignalBadAbility &p_objSignalBadAbility);

    /***********************************************************************
	*	概述：获取智能分析的信号异常的能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		SignalBadAbility ：智能分析的信号异常的能力
	*   功能正文：
	*       无
	************************************************************************/
	const SignalBadAbility& getSignalBadAbility() const;

    /***********************************************************************
	*	概述：设置智能分析的视频遮挡的能力
	*	输入：
	*		p_objCameraTamperAbility ：智能分析的视频遮挡的能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setCameraTamperAbility(const CameraTamperAbility &p_objCameraTamperAbility);

    /***********************************************************************
	*	概述：获取智能分析的视频遮挡的能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		CameraTamperAbility ：智能分析的视频遮挡的能力
	*   功能正文：
	*       无
	************************************************************************/
	const CameraTamperAbility& getCameraTamperAbility() const;

    /***********************************************************************
	*	概述：设置智能分析的摄像机移动的能力
	*	输入：
	*		p_objCameraMoveAbility ：智能分析的摄像机移动的能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setCameraMoveAbility(const CameraMoveAbility &p_objCameraMoveAbility);

    /***********************************************************************
	*	概述：获取智能分析的摄像机移动的能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		CameraMoveAbility ：智能分析的摄像机移动的能力
	*   功能正文：
	*       无
	************************************************************************/
	const CameraMoveAbility& getCameraMoveAbility() const;

    /***********************************************************************
	*	概述：设置智能分析的高级参数的能力
	*	输入：
	*		p_objAdvancedAbility ：智能分析的高级参数的能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setAdvancedAbility(const AdvancedAbility &p_objAdvancedAbility);

    /***********************************************************************
	*	概述：获取智能分析的高级参数的能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		AdvancedAbility ：智能分析的高级参数的能力
	*   功能正文：
	*       无
	************************************************************************/
	const AdvancedAbility& getAdvancedAbility() const;

	IntelligenceAnalyseAbility& operator=(const IntelligenceAnalyseAbility& p_objIntelligenceAnalyseAbility);

private:
	int    	                       m_nVersion;                            //版本
	std::vector<LibCommonAbility>  m_objLibCommonAbilityList;             //各个智能分析库必备的能力值

	MotionDetectionAbilityV2       m_objMotionDetectionAbilityV2;         //移动侦测对应的能力
	PerimeterAbility               m_objPerimeterAbility;                 //入侵能力
	TripWireAbility                m_objTripWireAbility;                  //绊线能力
	MultiTripWireAbility           m_objMultiTripWireAbility;             //双绊线能力
	LoiterAbility                  m_objLoiterAbility;                    //徘徊能力
	MultiLoiterAbility             m_objMultiLoiterAbility;               //多人徘徊对应的能力
	ObjLeftAbility                 m_objObjLeftAbility;                   //物品遗留对应的能力
	ObjMoveAbility                 m_objObjMoveAbility;                   //物体移走对应的能力
	AbnormalSpeedAbility           m_objAbnormalSpeedAbility;             //非正常速度对应的能力
	ConverseAbility                m_objConverseAbility;                  //逆行对应的能力
	NoParkingAbility               m_objNoParkingAbility;                 //非法停车对应的能力
	SignalBadAbility               m_objSignalBadAbility;                 //信号异常对应的能力
	CameraTamperAbility            m_objCameraTamperAbility;              //视频遮挡对应的能力
	CameraMoveAbility              m_objCameraMoveAbility;                //摄像机移动对应的能力
	AdvancedAbility                m_objAdvancedAbility;                  //高级参数对应的能力
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif //_INTELLIGENCEANALYSEABILITY_H
