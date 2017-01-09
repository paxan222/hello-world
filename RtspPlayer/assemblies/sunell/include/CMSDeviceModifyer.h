#ifndef _CMSDEVICEMODIFYER_H_
#define _CMSDEVICEMODIFYER_H_

//#if (defined(WIN32) || defined(_WIN32_WCE))

#include "SNError.h"
#include "SNPlatOS.h"
#include "HostNetwork.h"
#include "InetAddr.h"

class ITransfer;

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

class SN_DLL_API CMSDeviceModifyer
{

public:

	CMSDeviceModifyer();

	~CMSDeviceModifyer(void);

public:

	/************************************************************************
	**概述：
	*		设置设备网络地址
	**输入：
	*		p_objDeviceAddr ：本机地址
	*		p_objHostNetwork：要设置的设备网络信息
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setHostNetwork(InetAddr& p_objLocalAddr, HostNetwork& p_objHostNetwork);
	int setHostNetwork(InetAddr& p_objLocalAddr, HostNetwork& p_objHostNetwork, const char* p_szBindNetworkCardName);

private:

	int sendHostNetworkCommand(ITransfer* p_pobjTransfer, HostNetwork& p_objHostNetwork);
	int recvResponeCommand(ITransfer* p_pobjTransfer);

	int openMultiTranfser(const InetAddr& p_objBindAddr, ITransfer*& p_pobjTransfer);
	int openMultiTranfser(const InetAddr& p_objBindAddr, ITransfer*& p_pobjTransfer, const char* p_szBindNetworkCardName);

	int openIPv6Tranfser(const InetAddr& p_objBindAddr, ITransfer*& p_pobjTransfer);
	bool initIPv6Socket(char* p_szMultiIp, unsigned short p_nPort, const InetAddr& p_objDeviceAddr, unsigned int& p_nSocket);

	int openIPv4Tranfser(const InetAddr& p_objBindAddr, ITransfer*& p_pobjTransfer);
	int openIPv4Tranfser(const InetAddr& p_objBindAddr, ITransfer*& p_pobjTransfer, const char* p_szBindNetworkCardName);

	/************************************************************************
	**概述：
	*		关闭传输器
	**输入：
	*		p_pobjTransfer：传输器
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	void closeMultiTransfer(ITransfer*& p_pobjTransfer);
	void closeTransfer(ITransfer*& p_pobjTransfer);

	void dropMulticast(ITransfer* p_pobjTransfer);

	//拷贝构造函数
	CMSDeviceModifyer(const CMSDeviceModifyer& p_objObject)
	{
	}

	//赋值函数
	CMSDeviceModifyer& operator = (const CMSDeviceModifyer& p_objObject)
	{
		return *this;
	}

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


//#endif //defined(WIN32) || defined(_WIN32_WCE)
#endif //_CMSDEVICEMODIFYER_H_
