#ifndef _NETWORK_ABILITY_
#define _NETWORK_ABILITY_

#include "SNPlatOS.h"
#include "DomainConst.h"
#include "NetworkCardAbility.h"
#include <vector>

/**********************************************************************/
//�˴����ڿ����ļ������ֽڶ��룬����ʱ����ע�ͼ�������һ�𿽱���
//�������ġ�#ifdef PRAGMA_PACK������ҲҪһ�𿽱�������pragma pack��ջ��ջ��ƥ��
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

class SN_DLL_API NetworkAbility
{
public:
	NetworkAbility(void);
	~NetworkAbility(void);

public:
	
	void setNetworkCardNum(int p_nNetworkCardNum);

	const int getNetworkCardNum() const;

	void setNetworkCardAbilityList(const std::vector<NetworkCardAbility>& p_objNetworkCardAbilityList);
	const std::vector<NetworkCardAbility>& getNetworkCardAbilityList() const;

	NetworkAbility& operator = (const NetworkAbility& p_objNetworkAbility);
	bool operator == (const NetworkAbility &p_objNetworkAbility);

private:
	int									m_nNetworkCardNum;
	std::vector<NetworkCardAbility>		m_objNetworkCardAbilityList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/


#endif //_MONITORTYPE_
