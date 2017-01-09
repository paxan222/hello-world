#ifndef _DEVICETYPE_H_
#define _DEVICETYPE_H_

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

class SN_DLL_API DeviceType
{
public:
	enum 
	{
		IPCAMERA		= 1,	//网络摄像机设备
		DVR				= 2,	//数字视频录像机设备
		DVS				= 3,	//数字视频服务器设备
		IPDOME			= 4,	//网络高速球
		NVR				= 5,	//NVR
		ONVIF_DEVICE	= 6,	//Onvif 设备
		DECODER			= 7,	//解码器
		HK_DVR			= 100,	//HK DVR
		RS_DVR			= 101,	//安联DVR
		DH_DVR			= 102,	//大华DVR
		VIRTUAL_NVR		= 103   //用于兼容NVR客户端所使用的本地Server
	};

	DeviceType();
	
	~DeviceType();

	DeviceType(const DeviceType& p_objDeviceType);

public:
	
	/************************************************************************
	**概述：
	*		设置设备类型ID
	**输入：
	*		p_nDeviceTypeId ：要设置的设备类型ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setDeviceTypeId(const int p_nDeviceTypeId);

	/************************************************************************
	*概述：
	*		获取设备类型ID
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		设备类型Id
	*功能：       
	*************************************************************************/
	const int getDeviceTypeId() const;


	/************************************************************************
	**概述：
	*		设置设备类型ID
	**输入：
	*		p_pszDeviceTypeName：要设置的设备类型名称
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	bool setDeviceTypeName(const char* p_pszDeviceTypeName);

	/************************************************************************
	*概述：
	*		获取设备类型名称
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		设备类型名称
	*功能：       
	*************************************************************************/
	const char* getDeviceTypeName() const;

	/************************************************************************
	*概述：
	*		赋值函数
	*输入：
	*		p_objDeviceType：DDNS信息
	*输出：
	*		无
	*返回值：
	*		DDNS信息
	*功能：
	*************************************************************************/
	DeviceType& operator =(const DeviceType& p_objDeviceType);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objDeviceType：DeviceType类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个DeviceType类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const DeviceType& p_objDeviceType);

public:

	/************************************************************************
	**概述：
	*		根据设备类型常量获取设备类型的名称
	**输入：
	*		p_nType : 设备类型
	**输出：
	*		p_pszName : 设备名称
	**返回值：
	*		无
	**功能：
	*		根据设备类型常量获取设备类型的名称
	************************************************************************/
	static void translateDeviceTypeName(const int p_nType, char* p_pszName);


private:

	int			m_nDeviceTypeId;										//设备类型id
	char		m_szDeviceTypeName[CONST_MAXLENGTH_DEVICETYPE_NAME];	//设备类型名称
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DEVICETYPE_H_
