#ifndef _IPC_NET_WORK_CARD_ABILITY_H
#define _IPC_NET_WORK_CARD_ABILITY_H

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

class SN_DLL_API IPCNetworkCardAbility
{
public:
	IPCNetworkCardAbility(void);
	~IPCNetworkCardAbility(void);

	/************************************************************************
	*	概述：设置网卡编号
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setNetWorkCardId(int p_nNetWorkCardId);

	/************************************************************************
	*	概述：获取网卡编号
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		网卡编号
	*************************************************************************/
	int getNetWorkCardId() const;

	/************************************************************************
	*	概述：设置网卡名称
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		true	：设置成功
	*		false   ：设置失败
	*************************************************************************/
	bool setNetWorkCardName(const char* p_pszNetWorkCardName);

	/************************************************************************
	*	概述：获取网卡名称
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		网卡名称
	*************************************************************************/
	const char* getNetWorkCardName()const;

	/************************************************************************
	*	概述：设置网卡描述
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		true	：设置成功
	*		false   ：设置失败
	*************************************************************************/
	bool setDescription(const char* p_pszDescription);
	
	/************************************************************************
	*	概述：获取网卡描述
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		网卡描述
	*************************************************************************/
	const char* getDescription()const;

	void setSupportAlarm(bool p_bSupportAlarm);
	bool getSupportAlarm() const;

private:
	
	int								m_nNetWorkCardId;									//网卡编号
	char							m_szNetWorkCardName[CONST_NETWORK_CARD_NAME + 1];	//网卡名称
	char							m_szDescription[CONST_NETWORK_CARD_DESCRIPTION + 1];//网卡描述							//
	bool							m_bSupportAlarm;									//支持断网报警

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif //_IPC_NET_WORK_CARD_ABILITY_H
