#ifndef _MULTICASTPARAM_H_
#define _MULTICASTPARAM_H_

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

class SN_DLL_API MulticastParam
{
public:
	MulticastParam(void);

	~MulticastParam(void);

public:
	/************************************************************************
	**概述：
	*		设置多播启用标志
	**输入：
	*		p_bMulticastEnableFlag：多播启用标志
	**输出：
	*		无
	**返回值：
	*		无
	*功能：
	*
	************************************************************************/
	void setMulticastEnableFlag(const bool p_bMulticastEnableFlag);

	/************************************************************************
	**概述：
	*		获取多播启用标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		多播启用标志
	*功能：
	*
	************************************************************************/
	const bool getMulticastEnableFlag() const;

	/************************************************************************
	**概述：
	*		设置多播端口
	**输入：
	*		p_nMulticastPort：多播端口
	**输出：
	*		无
	**返回值：
	*		无
	*功能：
	*
	************************************************************************/
	void setMulticastPort(const unsigned short p_nMulticastPort);

	/************************************************************************
	**概述：
	*		获取多播端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		多播端口
	*功能：
	*
	************************************************************************/
	const unsigned short getMulticastPort() const;

	/************************************************************************
	**概述：
	*		设置多播发送间隔
	**输入：
	*		p_nMulticastInterval：多播发送时间间隔参数
	**输出：
	*		无
	**返回值：
	*		无
	*功能：
	*
	************************************************************************/
	void setMulticastInterval(const int p_nMulticastInterval);

	/************************************************************************
	**概述：
	*		获取多播发送间隔
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		多播发送时间间隔
	*功能：
	*
	************************************************************************/
	const int getMulticastInterval() const;

	/************************************************************************
	**概述：
	*		设置多播IP
	**输入：
	*		p_pMulticastHostIP：多播IP参数
	**输出：
	*		无
	**返回值：
	*		true,设置成功
	*		false，设置失败
	*功能：
	*
	************************************************************************/
	bool setMulticastHostIP(const char * p_pMulticastHostIP);

	/************************************************************************
	**概述：
	*		获取多播IP
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		多播IP
	*功能：
	*
	************************************************************************/
	const char * getMulticastHostIP() const;

	/************************************************************************
	**概述：
	*		设置多播IP协议类型
	**输入：
	*		多播协议类型
	**输出：
	*		无
	**返回值：
	*		无
	*功能：
	*
	************************************************************************/
	void setMulticastIPProtoVer(const int p_nIPProtoVer);

	/************************************************************************
	**概述：
	*		获取多播IP协议类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		多播IP协议类型
	*功能：
	*
	************************************************************************/
	const int getMulticastIPProtoVer() const;

public:
	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objBroadcastParam：多播参数信息
	**输出：
	*		无
	**返回值：
	*		多播参数信息
	*功能：
	*
	************************************************************************/
	MulticastParam& operator =(const MulticastParam& p_objMulticastParam);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objBroadcastParam：BroadcastParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个MulticastParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const MulticastParam& p_objMulticastParam);

private:
	bool				m_bMulticastEnableFlag;									//是否启用多播(false：不启用， true：启用)

	unsigned short		m_nMulticastPort;										//多播服务器的端口

	int					m_nMulticastInterval;									//发送多播间隔，以秒为单位

	char				m_szMulticastHostIP[CONST_MAXLENGTH_IP + 1];			//发送多播的IP

	int					m_nMulticastIPProtoVer;											//IP协议类型
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif
