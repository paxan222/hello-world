#ifndef _WIFIABILITYPARAM_H_
#define _WIFIABILITYPARAM_H_

#include "DomainConst.h"
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

class SN_DLL_API WifiAbilityParam
{
public:
	WifiAbilityParam(void);
	~WifiAbilityParam(void);

public:

	/************************************************************************
	*	概述：设置是否支持标志
	*	输入：
	*		p_nSupportFlag：是否支持标志
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setSupportFlag(const bool p_nSupportFlag);

	/************************************************************************
	*	概述：获取是否支持标志
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		m_nLCPTimeout
	************************************************************************/
	const bool getSupportFlag() const;


	/************************************************************************
	*	概述：设置Wifi设备名
	*	输入：
	*		p_pszWifiDeviceName：Wifi设备名
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	bool setWifiDeviceName(const char* p_pszWifiDeviceName);

	/************************************************************************
	*	概述：获取Wifi设备名
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		Wifi设备名
	************************************************************************/
	const char* getWifiDeviceName() const ;

private:
	bool			m_bSupportFlag;														//是否支持标志
	char			m_szWifiDeviceName[CONST_MAXLENGTH_WIFI_DEVICE_NAME+1];				//Wifi设备名

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_WIFIABILITYPARAM_H_
