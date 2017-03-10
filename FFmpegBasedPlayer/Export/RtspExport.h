#ifdef RTSPEXPORT_EXPORTS
#define RTSPEXPORT_API __declspec(dllexport) 
#else
#define RTSPEXPORT_API __declspec(dllimport) 
#endif

enum class ErrorCode :INT{
	UnknownError = -1,				// Unknow error
	OpenInputFileError,				// Error occured while opening input file
	OpenOutputFileError,			// Error occured while opening output file
	EmptyFilename,					// Filename is empty
	ArgumentOutOfRange,				// Error occured while checking start cut time and end cut time
	OutputFormatNotMatchFormat,		// Output format is no match in the list of registered output formats	
	VideoStreamNotExist				// Error occured while checking for input video stream
};

#ifdef __cplusplus
extern "C"
{
#endif
	//Progress callback
	typedef void(CALLBACK *FProgressCallback)(INT duration, INT currentPts);
	//End of operation callback
	typedef void(CALLBACK *FEndOfOperationCallback)();
	//Error callback
	typedef void(CALLBACK *FErrorCallback)(ErrorCode errorCode);
	
	/*
	*	Cut operation
	*	Return taskId
	*/
	RTSPEXPORT_API PVOID WINAPI Cut(PCHAR inputFilename, PCHAR outputFilename,
		int startCutTime, int endCutTime,
		FProgressCallback fProgressCallback = nullptr,
		FEndOfOperationCallback fEofCallback = nullptr,
		FErrorCallback fErrorCallback = nullptr);

	/*
	/*	Concatenate operation
	*	Return taskId
	*/
	RTSPEXPORT_API PVOID WINAPI Concatenate(PCHAR firstInputFilename, PCHAR secondInputFilename, PCHAR outputFilename,
		FProgressCallback fProgressCallback = nullptr,
		FEndOfOperationCallback fEofCallback = nullptr,
		FErrorCallback fErrorCallback = nullptr);

	// return mediafile duration
	RTSPEXPORT_API int WINAPI GetMediaFileDuration(PCHAR filename);

	// return byte array to buffer with jpeg frame or errNumber
	RTSPEXPORT_API int WINAPI GetFrame(PCHAR pchInputPath, char *buffer, int bufferSize, int width, int height, int64_t timestamp);

	// Cancel operation 
	RTSPEXPORT_API BOOL WINAPI Cancel(PVOID taskId);
#ifdef __cplusplus
}
#endif