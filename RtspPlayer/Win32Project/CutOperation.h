#include "BaseOperation.h"

class CCutOperation : public CBaseOperation
{
public:
	//Constructor
	CCutOperation(PCHAR inputFilename, PCHAR outputFilename,
		int startCutTime, int endCutTime/*,
		FProgressCallback fProgressCallback = nullptr,
		FEndOfOperationCallback fEofCallback = nullptr,
		FErrorCallback fErrorCallback = nullptr*/);
	//Destructor
	~CCutOperation();
private:
	// Open input file => Fill input streams => Check time conditions => Open output file
	BOOL Init(PCHAR inputFilename, PCHAR outputFilename, int startTimeMilliseconds, int endTimeMilliseconds);
	// Calculate duration and deltaPts => Check start and end time is bigger than 0, less than duration and different between it is bigger than deltaPts
	BOOL CheckTimeConditions(int startTime, int endTime);
};
