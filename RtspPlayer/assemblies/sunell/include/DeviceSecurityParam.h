#ifndef	 _DEVICE_SECURITY_PARAM_H
#define  _DEVICE_SECURITY_PARAM_H

#include "SNPlatOS.h"
#include "CommunicationSecurityParam.h"


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

class SN_DLL_API DeviceSecurityParam
{
public:
 	DeviceSecurityParam(void);

	~DeviceSecurityParam(void);

	/*************************************************************
	*	概述：设置Web端与网络音视频设备通讯安全参数
	*	输入：
	*		p_objCommunicationSecurityParam:通讯安全参数
	*	输出：
	*		无
	*	返回值：
	*		无
	*	备注：
	*		
	**************************************************************/
	void setCommunicationSecurityParam(const CommunicationSecurityParam& p_objCommunicationSecurityParam);

	/*************************************************************
	*	概述：获取Web端与网络音视频设备通讯安全参数
	*	输入：
	*		
	*	输出：
	*		无
	*	返回值：
	*		通讯安全参数
	*	备注：
	*		
	**************************************************************/
	const CommunicationSecurityParam& getCommunicationSecurityParam()const; 

private:

	CommunicationSecurityParam 	m_objCommunicationSecurityParam;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/


#endif  //_DEVICE_SECURITY_PARAM_H