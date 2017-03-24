#include "BaseRecorder.h"

#define BUFFER_SIZE 32*1024

class CCallbackRecorder : public CBaseRecorder
{
	AVIOContext* m_receivedCtx{ nullptr };
	AVOutputFormat* m_outputFormat{ nullptr };
	//Buffer with byte data
	BYTE *m_buffer{ new BYTE[BUFFER_SIZE] };
	//Data with new header flag
	bool m_isHeaderData{ false };

	//Receive data callback
	FFRecieveDataCallback m_RcvDtCb;
	FFRecieveHeaderCallback m_RcvHdCb;
	int _filesize = 0;
public:
	/**
	*	If connectionTimeout = 0, then we work without timeout
	*/
	CCallbackRecorder(PCHAR rtspPath, int connectionTimeout, 
		FFRecieveDataCallback fReceiveDataCallback, FFRecieveHeaderCallback fReceiveHeaderCallback=nullptr, FErrorCallback fErrorCallback = nullptr);
	~CCallbackRecorder();
	BOOL Open() override;
	BOOL WriteHeader();
	BOOL SendHeader();
private:
	/**
	*	Abstract function WriteHeaderTo is allocate output
	*	format context for Callback output;
	*	Create video and audio output streams;
	*	@param *&dstFmtCtx	- output format context
	*	return FALSE in next cases:
	*		guessing output format failed;
	*		avio format alloc failed;
	*/
	BOOL WriteHeaderTo(AVFormatContext *&dstFmtCtx) override;

	/**
	*	Callback for receive data
	*	@param *opaque	- opaque
	*	@param *byf		- buffer with byte data
	*	@param buf_size	- buffer size
	*	Called an external callback
	*/
	static int SendDataCallback(void *opaque, uint8_t *buf, int buf_size);
	/**
	*	Callback for receive header
	*	@param *opaque	- opaque
	*	@param *byf		- buffer with byte header
	*	@param buf_size	- buffer size
	*	Called an external callback
	*/
	static int SendHeaderCallback(void *opaque, uint8_t *buf, int buf_size);
};