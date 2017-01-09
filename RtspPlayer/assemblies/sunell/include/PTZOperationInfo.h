#ifndef PTZOPERATIONINFO_H_
#define PTZOPERATIONINFO_H_

#include "PTZOperationConst.h"
#include "PTZPointParamV2.h"
#include <string>
//PTZ控制信息类，主要记录水平和垂直转动的速度，水平位置和垂直位置的坐标等。
//注意：该类中包含速度数据的类型转换
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


class SN_DLL_API PTZOperationInfo
{
public:
	PTZOperationInfo(void);
	~PTZOperationInfo(void);

public:
	//设置通用ID
	void setCommonID(const int p_nCommonID);
	//获取通用ID
	const int getCommonID()const;
	/*********************************************************************
	*********说明：设置水平速度值
	********************************************************************/
	void setPanSpeed(const int p_nPanSpeed);
	/*********************************************************************
	*********返回值：水平速度信息
	********************************************************************/
	const int getPanSpeed()const;
	/*********************************************************************
	*********说明：设置垂直速度
	********************************************************************/
	void setTiltSpeed(const int p_nTiltSpeed);
	/*********************************************************************
	*********返回值：垂直速度
	********************************************************************/
	const int getTiltSpeed()const;
	/*********************************************************************
	*********说明设置水平坐标
	********************************************************************/
	void setPanPosion(const int p_nPanPosion);
	/*********************************************************************
	*********返回值：水平位置信息
	********************************************************************/
	const int getPanPosion()const;
	/*********************************************************************
	*********说明：设置垂直坐标
	********************************************************************/
	void setTiltPosion(const int p_nTiltPosion);
	/*********************************************************************
	*********返回值：垂直位置信息
	********************************************************************/
	const int getTiltPosion()const;

	//设置变倍的倍率值
	void setZoomValue(const int p_nZoomValue);
	const int getZoomValue()const;

	//设置数字变倍的倍率值
	void setDZoomValue(const int p_nDZoomValue);
	const int getDZoomValue()const;

	//设置聚焦的聚焦值
	void setDayFocusValue(const int p_nDayFocusValue);
	const int getDayFocusValue()const;

	void setNightFocusValue(const int p_nNightFocusValue);
	const int getNightFocusValue()const;

	//设置变倍速度值
	void setZoomSpeedValue(const int p_nZoomSpeedValue);
	const int getZoomSpeedValue()const;

	//设置聚焦速度值
	void setFocusSpeedValue(const int p_nFocusSpeedValue);
	const int getFocusSpeedValue()const;

	//设置转动方向
	void setDirectionValue(const int p_nDirectionValue);
	const int getDirectionValue()const;

	//设置坐标点信息
	void setPTZPointParamV2(const PTZPointParamV2 &p_objPTZPointParamV2);
	//获取坐标点信息
	const PTZPointParamV2 &getPTZPointParamV2()const;

    bool setAlarmIOState(const unsigned char* p_szAlarmIOState, unsigned int nSize);
    const unsigned char* getAlarmIOState() const;

	//设置停止时间
	void setStopTime(const int p_nStopTime);
	const int getStopTime()const;

	//设置PTZ版本号
	void setPTZVersion(const std::string& p_strPTZVersion);
	const std::string& getPTZVersion()const;

	//设置MCU温度
	void setMCUTemperature(const double p_dMCUTemperature);
	const double getMCUTemperature()const;

	//设置类型
	void setTypeValue(const int p_nVerticalMaxPosition);
	const int getTypeValue()const;

	//设置垂直方向最大角度
	void setVerticalMaxPosition(const int p_nStopTime);
	const int getVerticalMaxPosition()const;

	PTZOperationInfo &operator=(const PTZOperationInfo &p_objPTOperationInfo);

	bool operator!=(const PTZOperationInfo& p_objPTZOperationInfo) const;

    bool operator==(const PTZOperationInfo& p_objPTZOperationInfo) const;

private:
	int m_nCommonID;
	int m_nPanSpeed;  //水平速度
	int m_nTiltSpeed; //垂直速度
	int m_nZoomSpeedValue; //变倍速度
	int m_nFocusSpeedValue; //聚焦速度
	int m_nDirectionValue; //转动方向
	int m_nStopTime;	//停止时间
	int m_nType;		// 类型bit0=1表示设置PAN有效，0忽略PAN，同理的，bit1对应TILT，bit2对应ZOOM
	
	PTZPointParamV2 m_objPTZPointParamV2;//记录操作点位置信息
    unsigned char   m_szAlarmIOState[2]; //报警IO状态
	std::string     m_strPTZVersion;  //PTZ版本号
	double m_dMCUTemperature;//MCU温度
	int m_nVerticalMaxPosition;	//垂直方向最大角度
}_PACKED_1_;
/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
#endif

