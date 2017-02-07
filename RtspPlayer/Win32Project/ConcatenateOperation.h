#include "BaseOperation.h"

class CConcatenateOperation : public CBaseOperation
{
	/*----------Input data--------------------------------------------*/
	// Format context for second input file
	AVFormatContext *m_secondInputFmtCtx{ nullptr };
	/*InputStreams*/
	//Video stream of second input file
	AVStream *m_secondInputVideoStream{ nullptr };
	//Audio stream of second input file
	AVStream *m_secondInputAudioStream{ nullptr };
public:
	//Constructor
	CConcatenateOperation(PCHAR firstInputFilename, PCHAR secondInputFilenam, PCHAR outputFilename
		/*, FProgressCallback fProgressCallback = nullptr,
		FEndOfOperationCallback fEofCallback = nullptr,
		FErrorCallback fErrorCallback = nullptr*/);
	//Destructor
	~CConcatenateOperation();

private:
	//Open input files -> Fill input streams => Open output file
	BOOL Init(PCHAR firstInputFilename, PCHAR secondInputFilenam, PCHAR outputFilename);

	void CreateOutputStream() override;
};

