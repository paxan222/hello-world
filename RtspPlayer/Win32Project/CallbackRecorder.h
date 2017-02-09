#include "BaseRecorder.h"

#define BUFFER_SIZE 32*1024

class CCallbackRecorder : public CBaseRecorder
{
	//Buffer with byte data
	BYTE *m_buffer{ new BYTE[BUFFER_SIZE] };
	//Data with new header flag
	bool m_isHeaderData{ true };

	//Receive data callback
	//FFRecieveDataCallback m_RcvDtCb;

	FILE *outputFile2{ nullptr };
	int count2 = 0;

public:
	CCallbackRecorder(PCHAR rtspPath, int connectionTimeout, PCHAR outputFilename/*,
		FFRecieveDataCallback fReceiveDataCallback, FErrorCallback fErrorCallback = nullptr, FStartRecordCallback fStartCallback = nullptr*/);
	~CCallbackRecorder();

	BOOL Open(int counter) override;
	BOOL WriteHeader();

	void SendHeader();

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
	static int ReceiveDataCallback(void *opaque, uint8_t *buf, int buf_size);

	static int ReceiveHeaderCallback(void *opaque, uint8_t *buf, int buf_size);

	void WriteTrailer(AVFormatContext *&outputFmtCtx) override;
	
	void writeFile2(uint8_t *buf, int buf_size, bool isHeaderData, std::string m_outputFilename);
};

