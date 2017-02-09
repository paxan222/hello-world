#include "BaseRecorder.h"

class CFileRecorder : public CBaseRecorder
{
	std::string m_outputFilename;
public:
	CFileRecorder(PCHAR rtspStream, int connectionTimeout, PCHAR outputFilename/*, FErrorCallback fErrorCallback = nullptr, FStartRecordCallback fStartCallback = nullptr*/);
	~CFileRecorder();
	BOOL Open(int counter) override;
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

	/**
	*	Write trailer and close file
	*/
	void WriteTrailer(AVFormatContext *&outputFmtCtx) override;
};

