#ifndef _DEVICEPORT_H_
#define _DEVICEPORT_H_

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

class SN_DLL_API DevicePort
{
public:
	DevicePort(void);
	~DevicePort(void);

	//拷贝构造函数
	DevicePort(const DevicePort& p_objDevicePort);

public:
	/****************************************************************************
	**概述：
	*		设置网络视频设备的唯一标识符
	**输入：
	*		p_pszDeviceId ：网络视频设备的唯一标识符，字符串，最大长度为CONST_MAXLENGTH_DEVICEID字节,
	*						结尾以‘\0’结束。
	**输出：
	*		无
	**返回值：
	*		true： 成功
	*		false：失败 
	**功能：
	*		若输入p_pszDeviceId长度<=CONST_MAXLENGTH_DEVICEID，返回true.
	*		若输入p_pszDeviceId为NULL或其长度>CONST_MAXLENGTH_DEVICEID，返回false.
	*****************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/****************************************************************************
	**概述：
	*		获取网络设备的唯一标识符
	**输入：
	*		无
	**输出：
	*		无
	*返回值：
	*		网络设备的唯一标识符，字符串类型 
	**功能：
	*		
	*****************************************************************************/
	const char* getDeviceId() const;

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
	*		设置网络视频设备的TCP音视频端口
	**输入：
	*		p_nTCPAVPort ：网络视频设备的TCP音视频端口
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setTCPAVPort(unsigned short p_nTCPAVPort);

	/************************************************************************
	**概述：
	*		获取络视频设备的TCP音视频端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		络视频设备的TCP音视频端口
	*功能：
	*
	************************************************************************/
	unsigned short getTCPAVPort() const;

	/************************************************************************
	**概述：
	*		设置网络视频设备的RTSP端口
	**输入：
	*		p_nRTSPPort ：网络视频设备的RTSP端口
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setRTSPPort(unsigned short p_nRTSPPort);

	/************************************************************************
	**概述：
	*		获取络视频设备的RTSP端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		络视频设备的RTSP端口
	*功能：
	*
	************************************************************************/
	unsigned short getRTSPPort() const;

	/************************************************************************
	**概述：
	*		设置网络视频设备的RTP端口
	**输入：
	*		p_nRTPPort ：网络视频设备的RTP端口
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setRTPPort(unsigned short p_nRTPPort);

	/************************************************************************
	**概述：
	*		获取络视频设备的RTP端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		络视频设备的RTP端口
	*功能：
	*
	************************************************************************/
	unsigned short getRTPPort() const;

	/************************************************************************
	**概述：
	*		设置网络视频设备的RTCP端口
	**输入：
	*		p_nRTCPPort ：网络视频设备的RTCP端口
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setRTCPPort(unsigned short p_nRTCPPort);

	/************************************************************************
	**概述：
	*		获取络视频设备的RTCP端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		络视频设备的RTCSP端口
	*功能：
	*
	************************************************************************/
	unsigned short getRTCPPort() const;

	/************************************************************************
	**概述：
	*		设置网络视频设备的注册端口
	**输入：
	*		p_nRegisterPort ：网络视频设备的注册端口
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setRegisterPort(unsigned short p_nRegisterPort);

	/************************************************************************
	**概述：
	*		获取网络视频设备的注册端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		网络视频设备的注册端口
	**功能：
	*
	************************************************************************/
	unsigned short getRegisterPort() const;

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

	void setReservePort1(unsigned short p_nReservePort1);
	unsigned short getReservePort1() const;

	void setReservePort2(unsigned short p_nReservePort2);
	unsigned short getReservePort2() const;

	void setReservePort3(unsigned short p_nReservePort3);
	unsigned short getReservePort3() const;

	void setReservePort4(unsigned short p_nReservePort4);
	unsigned short getReservePort4() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objDevicePort：网络视频设备的主机网络信息
	**输出：
	*		无
	**返回值：
	*		网络视频设备的主机网络信息
	**功能：
	************************************************************************/
	DevicePort& operator =(const DevicePort& p_objDevicePort);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objDevicePort：DevicePort类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个DevicePort类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const DevicePort& p_objDevicePort);

	/****************************************************************************
	**概述：
	*		复位
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		将成员变量恢复默认值
	*****************************************************************************/
	void reset();

private:
		char			m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//网络视频设备的设备ID

		unsigned short	m_nControlPort;											//网络视频设备的设备网络控制端口
		unsigned short	m_nTCPAVPort;											//网络视频设备的TCP音视频端口
		unsigned short	m_nRTSPPort;											//网络视频设备的RTSP端口
		unsigned short	m_nRTPPort;												//网络视频设备的RTP端口
		unsigned short	m_nRTCPPort;											//网络视频设备的RTCP端口
		unsigned short	m_nRegisterPort;										//网络视频设备的设备注册端口
		unsigned short	m_nHttpPort;											//网络视频设备的设备HTTP端口
	
		unsigned short	m_nReservePort1;										//flash服务器端口
		unsigned short	m_nReservePort2;										
		unsigned short	m_nReservePort3;										
		unsigned short	m_nReservePort4;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DevicePort_H_

