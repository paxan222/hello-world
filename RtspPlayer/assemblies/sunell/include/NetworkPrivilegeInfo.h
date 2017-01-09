#ifndef _NETWORK_PRIVILEGE_INFO_H_
#define _NETWORK_PRIVILEGE_INFO_H_

#include "IpRangeInfo.h"
#include  <vector>

class NetworkPrivilegeInfo
{
public:
	enum IpConfigType
	{
		CONFIG_NOT_SUPPORRT	= -1,	//不支持
		CONFIG_NOT_SET		= 0,	//未配置
		CONFIG_DROP_IP		= 1,	//配置黑名单
		CONFIG_ACCEPT_IP	= 2		//配置白名单
	};

public:
	NetworkPrivilegeInfo();
	~NetworkPrivilegeInfo();

	void setIpConfigType(const int p_nIpConfigType);
	void setIpRangeInfo(const std::vector<IpRangeInfo>& p_objIpRangeInfoList);

	int getIpConfigType() const;
	void getIpRangeInfo(std::vector<IpRangeInfo>& p_objIpRangeInfoList) const;

private:
	std::vector<IpRangeInfo>	m_objIpRangeInfoList;
	int							m_nIpConfigType;
};

#endif

