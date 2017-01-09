#ifndef _TRANSFERPROTOCOL_H_
#define _TRANSFERPROTOCOL_H_

class TransferProtocol
{
public:

	enum
	{
		UDP = 0X01,			//UDP协议
		TCP = 0X02,			//TCP协议
		RTP = 0X04			//RTP协议
	};
	enum
	{
		IPPROTO_V4  = 1,

		IPPROTO_V6  = 2
	};
};

#endif	// _TRANSFERPROTOCOL_H_
