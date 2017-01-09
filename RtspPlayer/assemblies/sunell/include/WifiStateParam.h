#ifndef _WIFISTATEPARAM_H_
#define _WIFISTATEPARAM_H_

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

class SN_DLL_API WifiStateParam
{
public:
	enum WifiState
	{
		WIFI_STATE_DISCONNECT				= 0,	//未连接
		WIFI_STATE_CONNECTED				= 1,	//已经连接
		WIFI_STATE_CONNECT_FAILED_AND_TRY	= 2,	//连接失败并尝试重新连接
		WIFI_STATE_CONNECT_FAILED			= 3		//连接失败
	};

public:
	WifiStateParam(void);
	~WifiStateParam(void);

public:
	/************************************************************************
	**概述：
	*		设置连接状态
	**输入：
	*		p_nConnectState：连接状态
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setConnectState(const int p_nConnectState);

	/************************************************************************
	**概述：
	*		获取连接状态
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		
	************************************************************************/
	const int getConnectState() const;


	/************************************************************************
	**概述：
	*		设置信号质量
	**输入：
	*		p_nSignalQuality
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setSignalQuality(const int p_nSignalQuality);

	/************************************************************************
	**概述：
	*		获取信号质量
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		
	************************************************************************/
	const int getSignalQuality() const;

private:
	int		m_nConnectState;			//连接状态
	int		m_nSignalQuality;			//信号状态
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_WIFISTATEPARAM_H_
