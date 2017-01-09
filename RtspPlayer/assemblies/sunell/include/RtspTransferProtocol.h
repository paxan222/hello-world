#ifndef _RTSPTRANSFERPROTOCOL_H_
#define _RTSPTRANSFERPROTOCOL_H_

namespace RtspTransferProtocol
{
	enum RtspTransferProtocol
	{
		RTP_UDP		= 0x1,		//UDP
		RTSP_TUNNEL = 0x2,		//RTSP���
		HTTP_TUNNEL = 0x3		//HTTP���
	};
} ;

#endif // _RTSPTRANSFERPROTOCOL_H_
