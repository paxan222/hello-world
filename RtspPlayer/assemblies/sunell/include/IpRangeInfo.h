#ifndef _IP_RANGE_INFO_H_
#define _IP_RANGE_INFO_H_

#include <string>

class IpRangeInfo
{
public:
	IpRangeInfo();
	~IpRangeInfo();

	void setBeginIpAddr(const std::string& p_strIpAddr);
	void setEndIpAddr(const std::string& p_strIpAddr);
	void setIpDescribeInfo(const std::string& p_strIpDescribeInfo);

	void getBeginIpAddr(std::string& p_strIpAddr) const;
	void getEndIpAddr(std::string& p_strIpAddr) const;
	void getIpDescribeInfo(std::string& p_strIpDescribeInfo) const;

private:
	std::string m_strBeginIpAddr;
	std::string m_strEndIpAddr;
	std::string m_strIpDescribeInfo;
};

#endif
