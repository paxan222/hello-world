#ifndef _NETWORK_PRIVILEGE_INFO_H_
#define _NETWORK_PRIVILEGE_INFO_H_

#include "IpRangeInfo.h"
#include  <vector>

class NetworkPrivilegeInfo
{
public:
	enum IpConfigType
	{
		CONFIG_NOT_SUPPORRT	= -1,	//��֧��
		CONFIG_NOT_SET		= 0,	//δ����
		CONFIG_DROP_IP		= 1,	//���ú�����
		CONFIG_ACCEPT_IP	= 2		//���ð�����
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

