#ifndef _RS485DEVICEINFO_H_
#define _RS485DEVICEINFO_H_

#include "DomainConst.h"
#include <string.h>
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

class SN_DLL_API RS485DeviceInfo
{
public:
	RS485DeviceInfo();
	~RS485DeviceInfo();

	RS485DeviceInfo(const RS485DeviceInfo& p_objRS485DeviceInfo);

public:
	bool setName(const char* p_pszName);
	const char* getName() const ;

	/************************************************************************
	**概述：
	*		设置串口ID
	**输入：
	*		p_nComId：串口ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	*************************************************************************/
	void setComId(const int p_nComId);

	/************************************************************************
	**概述：
	*		获取串口ID
	**输入：
	*		无
	**输出 ：
	*		无
	*返回值 ：
	*		串口ID
	**功能：
	*    
	*************************************************************************/
	const int getComId() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objRS485DeviceInfo：设备主机网络信息
	**输出：
	*		无
	**返回值：
	*		设备主机网络信息
	**功能：
	************************************************************************/
	RS485DeviceInfo& operator =(const RS485DeviceInfo& p_objRS485DeviceInfo);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objRS485DeviceInfo：RS485DeviceInfo类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个RS485DeviceInfo类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const RS485DeviceInfo& p_objRS485DeviceInfo);


private:
	char	m_szName[CONST_LENGTH_RS485_NAME + 1];				//串口自定义名称
	int		m_nComId;										//串口ID
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_RS485DEVICEINFO_H_
