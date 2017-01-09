#ifndef _REMOTEZXWPROTOCOLCONFIGURE_H_
#define _REMOTEZXWPROTOCOLCONFIGURE_H_

#include "DeviceInfoEx.h"
#include "SNPlatOS.h"

#include "CWMPParam.h"
#include "AlcatelSIPParam.h"
#include "Viss3XParam.h"
#include "Viss2XParam.h"

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

class SN_DLL_API RemoteZXWProtocolConfigure
{
public:
	RemoteZXWProtocolConfigure(void);
	~RemoteZXWProtocolConfigure(void);

	int open(const DeviceInfoEx &p_DeviceInfo);

	//设置网管协议
	int setCWMPParam(const CWMPParam& p_objCWMPParam);
	int getCWMPParam(CWMPParam& p_objCWMPParam);

	//设置SIP协议
	int setAlcatelSIPParam(const AlcatelSIPParam& p_objAlcatelSIPParam);
	int getAlcatelSIPParam(AlcatelSIPParam& p_objAlcatelSIPParam);

	//Viss3x协议
	int setViss3XParam(const Viss3XParam& p_objViss3XParam);
	int getViss3XParam(Viss3XParam& p_objViss3XParam);

	//Viss2x协议
	int setViss2XParam(const Viss2XParam& p_objViss2XParam);
	int getViss2XParam(Viss2XParam& p_objViss2XParam);


	void close();

private:
	DeviceInfoEx m_objDeviceInfo;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTEZXWPROTOCOLCONFIGURE_H_
