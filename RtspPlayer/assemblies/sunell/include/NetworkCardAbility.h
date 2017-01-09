#ifndef _NETWORK_CARD_ABILITY_
#define _NETWORK_CARD_ABILITY_

#include "NetWorkingMode.h"
#include <vector>
#include "const.h"


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

class SN_DLL_API NetworkCardAbility
{
public:
	NetworkCardAbility(void);
	~NetworkCardAbility(void);

public:
	/************************************************************************
	*	�����������������
	*	���룺
	*		p_nNetworkCardId	�������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setNetworkCardId(int p_nNetworkCardId);

	/************************************************************************
	*	��������ȡ�������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		�������
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
