#ifndef _NETWORK_CARD_STATUS_H
#define _NETWORK_CARD_STATUS_H

#include "SNPlatOS.h"
#include "DomainConst.h"

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

class SN_DLL_API NetworkCardStatus
{
public:
	enum ChangedState
	{
		CONNECT_STATUS_CHANGE				=0x00000001,				//连接状态改变
		SPEED_CHANGE						=0x00000002,				//网卡速度改变
		IP_CONFLICT_CHANGE					=0x00000004					//IP冲突状态改变
	};

	enum ConnectState
	{
		LINK_ON							=1,				//连接正常
		LINK_OFF						=2				//网线拔出
	};

	enum NetCardSpeed
	{
		SPEED_10M						=1,					//十兆
		SPEED_100M						=2,					//百兆
		SPEED_1G						=3					//千兆
	};

	NetworkCardStatus(void);
	~NetworkCardStatus(void);

public:
	/************************************************************************
	*	概述：设置网卡编号
	*	输入：
	*		p_nNetworkCardId	网卡编号
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setNetworkCardId(int p_nNetworkCardId);

	/************************************************************************
	*	概述：获取网卡编号
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		网卡编号
	*************************************************************************/
	const int getNetworkCardId() const;

	/************************************************************************
	*	概述：设置网卡连接状态
	*	输入：
	*		p_nConnectStatus	网卡连接状态
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setConnectStatus(int p_nConnectStatus);

	/************************************************************************
	*	概述：获取网卡连接状态
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		网卡连接状态
	*************************************************************************/
	const int getConnectStatus() const;


	/************************************************************************
	*	概述：设置网卡速度
	*	输入：
	*		p_nSpeed	网卡速度
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setSpeed(int p_nSpeed);

	/************************************************************************
	*	概述：获取网卡速度
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		网卡速度
	*************************************************************************/
	const int getSpeed() const;


	/************************************************************************
	*	概述：设置IP冲突标志
	*	输入：
	*		p_bIPConflictedFlag	IP冲突标志
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setIPConflictedFlag(bool p_bIPConflictedFlag);

	/************************************************************************
	*	概述：获取IP冲突标志
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		IP冲突标志
	*************************************************************************/
	const bool getIPConflictedFlag() const;

	void setState(int p_nState);
	const int getState() const;

	NetworkCardStatus& operator = (const NetworkCardStatus& p_objNetworkCardStatus);
	bool operator == (const NetworkCardStatus &p_objNetworkCardStatus);

private:
	int		m_nNetworkCardId;
	int		m_nConnectStatus;	//连接状态：1连接正常、2网线被拔出
	int		m_nSpeed;			//网卡速度：1百兆、2千兆
	bool	m_bIPConflictedFlag;
	int		m_nState;			//每一位记录一个状态的改变
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/


#endif //_MONITORTYPE_
