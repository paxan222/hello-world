#ifndef _WIFIHOTSPOTPARAM_H_
#define _WIFIHOTSPOTPARAM_H_

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

class SN_DLL_API WifiHotspotParam
{
public:
	WifiHotspotParam(void);
	~WifiHotspotParam(void);

public:
	/************************************************************************
	**概述：
	*		设置SSID
	**输入：
	*		p_pszSSID: SSID
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	bool setSSID(const char* p_pszSSID);

	/************************************************************************
	**概述：
	*		获取SSID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		SSID
	************************************************************************/
	const char* getSSID() const ;


	/************************************************************************
	**概述：
	*		设置加密类型
	**输入：
	*		p_pszEncryptionType：加密类型
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	bool setEncryptionType(const char* p_pszEncryptionType);

	/************************************************************************
	**概述：
	*		获取加密类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		
	************************************************************************/
	const char* getEncryptionType() const ;


	/************************************************************************
	**概述：
	*		设置信号质量
	**输入：
	*		p_nSignalQuality：信号质量
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
	char	m_szSSID[CONST_MAXLENGTH_SSID+1];
	char	m_szEncryptionType[CONST_MAXLENGTH_ENCRYPTION_TYPE+1];
	int		m_nSignalQuality;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_WIFIHOTSPOTPARAM_H_
