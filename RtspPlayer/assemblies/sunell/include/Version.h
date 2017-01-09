#ifndef _VERSION_H_
#define _VERSION_H_

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

class SN_DLL_API Version
{
public:
	Version();

	~Version();
	
	Version(const Version &p_objVersion);

public:
	/****************************************************************************
	**概述：
	*		设置DVR设备硬件版本号
    **输入：
	*	p_pszHardwareVer ：字符串，最大长度为CONST_MAXLENGTH_HARDWAREVERSION字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszHardwareVer长度<=CONST_MAXLENGTH_HARDWAREVERSION，返回true，
	*	并保存到m_szHardwareVer;
	*	若输入p_pszHardwareVer长度>CONST_MAXLENGTH_HARDWAREVERSION，返回false
	*****************************************************************************/	
	bool setHardwareVer(const char *p_pszHardwareVer);

	/****************************************************************************
	**概述：
	*		获取DVR设备硬件版本号
    **输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存DVR设备硬件版本号的m_szHardwareVer字符串指针。 
	*功能：
	*	获取保存有DVR设备硬件版本号的字符串指针
	*****************************************************************************/
	const char *getHardwareVer() const;

	/****************************************************************************
	**概述：
	*		设置DVR设备软件版本号
    **输入：
	*	p_pszSoftwareVer ：字符串，最大长度为CONST_MAXLENGTH_SOFTWAREVERSION字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszSoftwareVer长度<=CONST_MAXLENGTH_SOFTWAREVERSION，返回true，
	*	并保存到m_szSoftwareVer;
	*	若输入p_pszSoftwareVer长度>CONST_MAXLENGTH_SOFTWAREVERSION，返回false
	*****************************************************************************/	
	bool setSoftwareVer(const char *p_pszSoftwareVer);

	/****************************************************************************
	**概述：
	*		获取DVR设备软件版本号
    **输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存DVR设备软件版本号的m_szSoftwareVer字符串指针。 
	**功能：
	*	获取保存有DVR设备软件版本号的字符串指针
	*****************************************************************************/
	const char *getSoftwareVer() const;

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
	Version &operator =(const Version &p_objVersion);

private:
	char m_szHardwareVer[CONST_MAXLENGTH_HARDWAREVERSION_EXPAND + 1];
	char m_szSoftwareVer[CONST_MAXLENGTH_SOFTWAREVERSION_EXPAND + 1];
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_VERSION_H_
