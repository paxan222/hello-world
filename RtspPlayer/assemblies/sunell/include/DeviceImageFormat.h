#ifndef _DEVICEIMAGEFORMAT_H_
#define _DEVICEIMAGEFORMAT_H_

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

class SN_DLL_API DeviceImageFormat
{

public:
	DeviceImageFormat();
	~DeviceImageFormat();

	DeviceImageFormat(const DeviceImageFormat& p_objDeviceImageFormat);

public:

	/***********************************************************************
	**概述：
	*		设置网络视频设备的设备ID
	**输入：
	*		p_pszDeviceId ：字符串，最大长度为CONST_MAXLENGTH_DEVICEID字节,
	*		结尾以‘\0’结束。
	**输出：
	*		无
	**返回值：
	*		true ：成功
	*		false：失败 
	**功能：
	*		若输入p_pszDeviceId长度<=CONST_MAXLENGTH_DEVICEID，返回true，
	*		并保存到m_szDeviceId;
	*		若输入p_pszDeviceId为NULL或其长度>CONST_MAXLENGTH_DEVICEID，返回false
	************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**概述：
	*		获取网络视频设备的设备ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		网络视频设备的设备ID。 
	**功能：
	*	获取保存有DVR设备ID的字符串指针
	*************************************************************************/
	const char* getDeviceId() const;

	/************************************************************************
	**概述：
	*		设置摄像头ID号
    **输入：
	*		p_nCameraId ：摄像头的ID号
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**概述：
	*		获取摄像头的ID号
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		摄像头的ID号
	**功能：
	*    
	************************************************************************/
	const int getCameraId() const;

	/************************************************************************
	**概述：
	*		设置图像格式ID
	**输入：
	*		p_nImageFormatId ：要设置的图像格式ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setImageFormatId(const int p_nImageFormatId);

	/************************************************************************
	*概述：
	*		获取图像格式id
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		图像格式Id
	*功能：       
	*************************************************************************/
	const int getImageFormatId() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objDeviceImageFormat：云台预制点
	**输出：
	*		无
	**返回值：
	*		云台预制点
	**功能：
	************************************************************************/
	DeviceImageFormat& operator =(const DeviceImageFormat& p_objDeviceImageFormat);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objDeviceImageFormat：DeviceImageFormat类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个DeviceImageFormat类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const DeviceImageFormat& p_objDeviceImageFormat);

private:

	char		m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//设备ID

	int			m_nCameraId;											//摄像头ID号
	
	int			m_nImageFormatId;										//图像格式id
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DEVICEIMAGEFORMAT_H_

