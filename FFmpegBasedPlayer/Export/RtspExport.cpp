#include "BaseOperation.h"
#include "ConcatenateOperation.h"
#include "CutOperation.h"

RTSPEXPORT_API PVOID WINAPI Cut(PCHAR inputFilename, PCHAR outputFilename, int startCutTime, int endCutTime,
	FProgressCallback fProgressCallback, FEndOfOperationCallback fEofCallback, FErrorCallback fErrorCallback){
	CBaseOperation *pTask = new CCutOperation(inputFilename, outputFilename, startCutTime, endCutTime, fProgressCallback, fEofCallback, fErrorCallback);
	return pTask;
};

RTSPEXPORT_API PVOID WINAPI Concatenate(PVOID exporter, PCHAR inputFilename, PCHAR inputFilename2, PCHAR outputFilename,
	FProgressCallback fProgressCallback, FEndOfOperationCallback fEofCallback, FErrorCallback fErrorCallback){
	CBaseOperation *pTask = new CConcatenateOperation(inputFilename, inputFilename2, outputFilename, fProgressCallback, fEofCallback, fErrorCallback);
	return pTask;
};

RTSPEXPORT_API int WINAPI GetMediaFileDuration(PCHAR filename){
	CBaseOperation *pTask;
	return pTask->GetFileDuration(filename);
}

RTSPEXPORT_API int WINAPI GetFrame(PCHAR pchInputPath, char *buffer, int bufferSize, int width, int height, int64_t timestamp)
{
	CBaseOperation *pTask;
	return pTask->GetFrame(pchInputPath, buffer, bufferSize, width, height, timestamp);
}

RTSPEXPORT_API BOOL WINAPI Cancel(PVOID taskId){
	if (taskId == nullptr)
		return FALSE;
	CBaseOperation *task = static_cast<CBaseOperation*>(taskId);
	return task->CancelTask();
}