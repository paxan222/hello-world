#include "BaseRecorder.h"
#include "CallbackRecorder.h"
#include "FileRecorder.h"


static std::map < std::string, PVOID > g_rtsp_recorder_map;
static Container<std::string, PVOID> g_rtsp_recorder_container{ g_rtsp_recorder_map };
std::recursive_mutex _api_lock;

RTSPRECORDER_API PVOID WINAPI StartFileRecord(PCHAR pchInputFilename, PCHAR pchOutputFilename, int timeout, FErrorCallback fErrorCallback){
	CBaseRecorder *recorder;
	recorder = new CFileRecorder(pchInputFilename, timeout, pchOutputFilename, fErrorCallback);
	if (recorder->Open() == FALSE){
		goto fail;
	}
	if (!recorder->StartRecord()){
		goto fail;
	}
	return recorder;
fail:
	delete recorder;
	return nullptr;
}

RTSPRECORDER_API BOOL WINAPI StartCallbackRecord(PCHAR pchRtspPath, int timeout, FFRecieveDataCallback fReceiveDataCallback, FFRecieveHeaderCallback fReceiveHeaderCallback, FErrorCallback fErrorCallback){
	std::lock_guard<std::recursive_mutex> locker(_api_lock);
	if (g_rtsp_recorder_container.hasItem(pchRtspPath))
	{
		return FALSE;
	}
	CBaseRecorder *recorder;
	recorder = new CCallbackRecorder(pchRtspPath, timeout, fReceiveDataCallback, fReceiveHeaderCallback, fErrorCallback);
	if (recorder->Open() == FALSE){
		goto fail;
	}
	g_rtsp_recorder_container.add(pchRtspPath, recorder);
	if (!recorder->StartRecord()){
		goto fail;
	}
	return TRUE;
fail:
	delete recorder;
	return FALSE;
}

RTSPRECORDER_API void WINAPI Stop(PCHAR pchRtspPath){
	std::lock_guard<std::recursive_mutex> locker(_api_lock);
	if (pchRtspPath != nullptr){
		auto pRecorder = g_rtsp_recorder_container.getItem(pchRtspPath);
		if (pRecorder){
			CBaseRecorder *rec = static_cast<CBaseRecorder*>(pRecorder);
			rec->StopRecord();
			g_rtsp_recorder_container.remove(pchRtspPath);
			delete rec;
		}
	}
}

RTSPRECORDER_API BOOL WINAPI WriteHeader(PCHAR pchRtspPath){
	if (pchRtspPath == nullptr){
		return FALSE;
	}
	auto pRecorder = g_rtsp_recorder_container.getItem(pchRtspPath);
	if (pRecorder){
		CCallbackRecorder *rec = static_cast<CCallbackRecorder*>(pRecorder);
		if (typeid(*rec).name() != typeid(CCallbackRecorder).name()){
			return FALSE;
		}
		return rec->WriteHeader();
	}
	return FALSE;
}

RTSPRECORDER_API BOOL WINAPI GetHeader(PCHAR pchRtspPath){
	if (pchRtspPath == nullptr){
		return FALSE;
	}auto pRecorder = g_rtsp_recorder_container.getItem(pchRtspPath);
	if (pRecorder){
		CCallbackRecorder *rec = static_cast<CCallbackRecorder*>(pRecorder);
		if (typeid(*rec).name() != typeid(CCallbackRecorder).name()){
			return FALSE;
		}
		return rec->SendHeader();
	}
	return FALSE;
}