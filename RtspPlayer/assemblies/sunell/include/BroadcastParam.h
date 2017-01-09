#ifndef _BROADCASTPARAM_H_
#define _BROADCASTPARAM_H_

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

class SN_DLL_API BroadcastParam
{

public:
	BroadcastParam(void);
	~BroadcastParam(void);

	//拷贝构造函数
	BroadcastParam(const BroadcastParam& p_objBroadcastParam);

public:


	/************************************************************************
	**概述：
	*		设置是否启用广播标志
	**输入：
	*		p_bFlag：是否启用广播标志
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	设置是否启用广播标志
	************************************************************************/
	void setBroadcastEnableFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取是否启用广播标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		是否启用广播标志
	**功能：
	*	获取是否启广播标志
	************************************************************************/
	const bool getBroadcastEnableFlag() const ;


	/************************************************************************
	**概述：
	*		设置广播端口
	**输入：
	*		p_nBroadcastPort ：广播端口
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setBroadcastPort(const unsigned short p_nBroadcastPort);

	/************************************************************************
	**概述：
	*		获取广播端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		广播端口
	**功能：
	*
	************************************************************************/
	const unsigned short getBroadcastPort() const;


	/************************************************************************
	**概述：
	*		设置发送广播间隔
	**输入：
	*		p_nBroadcastServerPort：广播间隔，以秒（s）为单位
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setBroadcastInterval(const int p_nBroadcastInterval);

	/************************************************************************
	**概述：
	*		获取发送广播间隔
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		广播间隔,以秒（s）为单位
	**功能：
	*
	************************************************************************/
	const int getBroadcastInterval() const;


	//设置数值保留位1
	void setReserveValue1(const int p_nReserveValue1);
	//获取数值保留位1
	const int getReserveValue1() const;


	//设置数值保留位2
	void setReserveValue2(const int p_nReserveValue2);
	//获取数值保留位2
	const int getReserveValue2() const;


	//设置数值保留位3
	void setReserveValue3(const int p_nReserveValue3);
	//获取数值保留位3
	const int getReserveValue3() const;

	
	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objBroadcastParam：广播参数信息
	**输出：
	*		无
	**返回值：
	*		广播参数信息
	*功能：
	*
	************************************************************************/
	BroadcastParam& operator =(const BroadcastParam& p_objBroadcastParam);

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
	*		两个BroadcastParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const BroadcastParam& p_objBroadcastParam);

private:

	bool				m_bBroadcastEnableFlag;							//是否启用广播(false：不启用， true：启用)

	unsigned short		m_nBroadcastPort;								//广播服务器的端口
	
	int					m_nBroadcastInterval;							//发送广播间隔，以秒为单位

	int					m_nReserveValue1;								//数值保留位1
	int					m_nReserveValue2;								//数值保留位2
	int					m_nReserveValue3;								//数值保留位3

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_BROADCASTPARAM_H_
