#include "BaseRecorder.h"

class CFileRecorder : public CBaseRecorder
{
	std::string m_outputFilename;
public:
	CFileRecorder(PCHAR rtspStream, int connectionTimeout, PCHAR outputFilename, FErrorCallback fErrorCallback = nullptr);
	~CFileRecorder();
	BOOL Open() override;
private:
	/**
	*	Abstract function WriteHeaderTo is allocate output
	*	format context for File output;
	*	Create video and audio output streams;
	*	@param *&dstFmtCtx	- output format context
	*	return FALSE in next cases:
	*		guessing output format failed;
	*		avio format alloc failed;
	*/
	BOOL WriteHeaderTo(AVFormatContext *&dstFmtCtx) override;
};

