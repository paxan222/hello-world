#ifndef _CMSDEVICEREGISTERINFOPARAM_H_
#define _CMSDEVICEREGISTERINFOPARAM_H_

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

class SN_DLL_API CMSDeviceRegisterInfoParam
{
public:
	CMSDeviceRegisterInfoParam();

	~CMSDeviceRegisterInfoParam();
	
	CMSDeviceRegisterInfoParam(const CMSDeviceRegisterInfoParam &p_objDeviceRegisterInfoParam);

public:
	/****************************************************************************
	**概述：
	*		设置设置注册ID
    **输入：
	*	p_pszDeviceRegisterInfo ：字符串，最大长度为CONST_MAXLENGTH_DEVICE_REGISTER_INFO字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszDeviceRegisterInfo长度<=CONST_MAXLENGTH_DEVICE_REGISTER_INFO，返回true，
	*	并保存到m_szDeviceRegisterInfo;
	*	若输入p_pszDeviceRegisterInfo长度>CONST_MAXLENGTH_DEVICE_REGISTER_INFO，返回false
	*****************************************************************************/	
	bool setDeviceRegisterID(const char *p_pszDeviceRegisterInfo);

	/****************************************************************************
	**概述：
	*		获取设置注册ID
    **输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存设置注册ID的m_szDeviceRegisterInfo字符串指针。 
	*功能：
	*	获取保存有设置注册ID的字符串指针
	*****************************************************************************/
	const char *getDeviceRegisterID() const;


	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*****************************************************************************/
	CMSDeviceRegisterInfoParam &operator =(const CMSDeviceRegisterInfoParam &p_objDeviceRegisterInfoParam);

private:

	char			m_szDeviceRegisterID[CONST_MAXLENGTH_DEVICE_REGISTER_ID + 1];	//设备注册ID

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSDEVICEREGISTERINFOPARAM_H_
