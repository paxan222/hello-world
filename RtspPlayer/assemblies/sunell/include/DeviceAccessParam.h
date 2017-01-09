#ifndef _DEVICEACCESSCONFIG_H_
#define _DEVICEACCESSCONFIG_H_

#include "DomainConst.h"
#include "const.h"
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

class SN_DLL_API DeviceAccessParam
{

public:
	DeviceAccessParam(void);
	~DeviceAccessParam(void);

	//拷贝构造函数
	DeviceAccessParam(const DeviceAccessParam& p_objDeviceAccessParam);
public:

	/************************************************************************
	**概述：
	*		设置网络视频设备的主机IP地址
	**输入：
	*		p_pszLocalIp ：网络视频设备的主机IP地址
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	bool setLocalIp(const char * p_pszLocalIp);

	/************************************************************************
	**概述：
	*		获取网络视频设备的主机IP地址
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		网络视频设备的主机IP地址
	**功能：
	*
	************************************************************************/
	const char * getLocalIp() const;

	/************************************************************************
	**概述：
	*		设置网络视频设备的控制端口
	**输入：
	*		p_nControlPort ：网络视频设备的控制端口
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setControlPort(unsigned short p_nControlPort);

	/************************************************************************
	**概述：
	*		获取络视频设备的控制端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		络视频设备的控制端口
	*功能：
	*
	************************************************************************/
	unsigned short getControlPort() const;


	/************************************************************************
	**概述：
	*		设置网络视频设备的视频传输端口
	**输入：
	*		p_nVideoTransferPort ：网络视频设备的视频传输端口
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setVideoTransferPort(unsigned short p_nVideoTransferPort);

	/************************************************************************
	**概述：
	*		获取网络视频设备的视频传输端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		网络视频设备的视频传输端口
	**功能：
	*
	************************************************************************/
	unsigned short getVideoTransferPort() const;


	/************************************************************************
	**概述：
	*		设置网络视频设备的视频传输端口
	**输入：
	*		p_nAudioTransferPort ：网络视频设备的视频传输端口
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setAudioTransferPort(unsigned short p_nAudioTransferPort);

	/************************************************************************
	**概述：
	*		获取网络视频设备的视频传输端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		网络视频设备的视频传输端口
	**功能：
	*
	************************************************************************/
	unsigned short getAudioTransferPort() const;


	/************************************************************************
	**概述：
	*		设置网络视频设备的HTTP端口
	**输入：
	*		p_nHTTPPort ：网络视频设备的HTTP端口
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setHttpPort(unsigned short p_nHttpPort);

	/************************************************************************
	**概述：
	*		获取网络视频设备的HTTP端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		网络视频设备的HTTP端口
	*功能：
	*
	************************************************************************/
	unsigned short getHttpPort() const;


	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objDeviceAccessParam：网络视频设备的主机网络信息
	**输出：
	*		无
	**返回值：
	*		网络视频设备的主机网络信息
	**功能：
	************************************************************************/
	DeviceAccessParam& operator =(const DeviceAccessParam& p_objDeviceAccessParam);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objDeviceAccessParam：DeviceAccessParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个DeviceAccessParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const DeviceAccessParam& p_objDeviceAccessParam);

private:

		char			m_szLocalIp[CONST_MAXLENGTH_IP + 1];					//本地IP地址

		unsigned short	m_nControlPort;											//网络视频设备的设备网络控制端口
		unsigned short	m_nVideoTransferPort;									//网络视频设备的设备视频传输端口
		unsigned short	m_nAudioTransferPort;									//网络视频设备的设备音频传输端口
		unsigned short	m_nHttpPort;											//网络视频设备的设备HTTP端口
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DEVICEACCESSCONFIG_H_

