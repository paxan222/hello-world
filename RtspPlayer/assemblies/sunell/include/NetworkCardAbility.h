#ifndef _NETWORK_CARD_ABILITY_
#define _NETWORK_CARD_ABILITY_

#include "NetWorkingMode.h"
#include <vector>
#include "const.h"


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

class SN_DLL_API NetworkCardAbility
{
public:
	NetworkCardAbility(void);
	~NetworkCardAbility(void);

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

	void setNetWorkingModeList(const std::vector<NetWorkingMode>& p_objNetWorkingModeList);
	const std::vector<NetWorkingMode>& getNetworkingModeList() const;

	NetworkCardAbility& operator = (const NetworkCardAbility& p_objNetworkCardAbility);
	bool operator == (const NetworkCardAbility &p_objNetworkCardAbility);

private:
	int							m_nNetworkCardId;
	std::vector<NetWorkingMode> m_objNetworkingModeList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/


#endif //_MONITORTYPE_
