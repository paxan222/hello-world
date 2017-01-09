#ifndef _TRANSFERPROTOCOL_H_
#define _TRANSFERPROTOCOL_H_

class TransferProtocol
{
public:

	enum
	{
		UDP = 0X01,			//UDPЭ��
		TCP = 0X02,			//TCPЭ��
		RTP = 0X04			//RTPЭ��
	};
	enum
	{
		IPPROTO_V4  = 1,

		IPPROTO_V6  = 2
	};
};

#endif	// _TRANSFERPROTOCOL_H_
