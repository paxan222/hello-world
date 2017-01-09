#ifndef _DEVICESERVICEPARAM_H_
#define _DEVICESERVICEPARAM_H_
/*
#ifdef __cplusplus
extern "C" {
#endif
*/ 

#include "DomainConst.h"
#include "SNPlatOS.h"

#ifndef byte
typedef unsigned char byte;
#endif

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

class DeviceServiceParam
{
public:

	DeviceServiceParam();
	DeviceServiceParam (const DeviceServiceParam &p_objDeviceServiceParam);
	~DeviceServiceParam();

public:
	
	//设置是否启用报警中心
	void setAlarmCenterStartFlag(const bool p_bFlag);
	//获取是否启用报警中心标志
	const bool getAlarmCenterStartFlag() const;


	DeviceServiceParam& operator = (const DeviceServiceParam &p_objDeviceServiceParam);
	
private:
	bool			m_bAlarmCenterStartFlag;										//是否启用报警中心标志,0：不启用，1：启用

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DEVICESERVICEPARAM_H_
