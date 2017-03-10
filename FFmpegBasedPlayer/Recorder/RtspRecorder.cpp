#include "BaseRecorder.h"
#include "CallbackRecorder.h"
#include "FileRecorder.h"

#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP

static std::map < std::string, PVOID > g_rtsp_recorder_map;
static Container<std::string, PVOID> g_rtsp_recorder_container{ g_rtsp_recorder_map };
std::recursive_mutex _api_lock;

RTSPRECORDER_API PVOID WINAPI StartFileRecord(PCHAR pchInputFilename, PCHAR pchOutputFilename, int timeout, FErrorCallback fErrorCallback){
	CBaseRecorder *recorder;
	LOG(INFO) << "GetFileRecorder";
	recorder = new CFileRecorder(pchInputFilename, timeout, pchOutputFilename, fErrorCallback);
	if (recorder->Open() == FALSE){
		goto fail;
	}
	LOG(INFO) << "FileRecorder:" << recorder;
	if (!recorder->StartRecord()){
		goto fail;
	}
	return recorder;
fail:
	delete recorder;
	LOG(INFO) << "FileRecorder is nullptr";
	return nullptr;
}

RTSPRECORDER_API BOOL WINAPI StartCallbackRecord(PCHAR pchRtspPath, int timeout, FFRecieveDataCallback fReceiveDataCallback, FFRecieveHeaderCallback fReceiveHeaderCallback, FErrorCallback fErrorCallback){
	std::lock_guard<std::recursive_mutex> locker(_api_lock);
	if (g_rtsp_recorder_container.hasItem(pchRtspPath))
	{
		return FALSE;
	}
	CBaseRecorder *recorder;
	LOG(INFO) << "GetCallbackRecorder";
	recorder = new CCallbackRecorder(pchRtspPath, timeout, fReceiveDataCallback, fReceiveHeaderCallback, fErrorCallback);
	if (recorder->Open() == FALSE){
		goto fail;
	}
	g_rtsp_recorder_container.add(pchRtspPath, recorder);
	LOG(INFO) << "CallbackRecorder:" << recorder;
	if (!recorder->StartRecord()){
		goto fail;
	}
	return TRUE;
fail:
	delete recorder;
	LOG(INFO) << "CallbackRecorder is nullptr";
	return FALSE;
}

RTSPRECORDER_API void WINAPI Stop(PCHAR pchRtspPath){
	std::lock_guard<std::recursive_mutex> locker(_api_lock);
	if (pchRtspPath != nullptr){
		auto pRecorder = g_rtsp_recorder_container.getItem(pchRtspPath);
		LOG(INFO) << "pRecorder:" << pRecorder;
		if (pRecorder){
			CBaseRecorder *rec = static_cast<CBaseRecorder*>(pRecorder);
			LOG(INFO) << "StopRecord";
			rec->StopRecord();
			g_rtsp_recorder_container.remove(pchRtspPath);
			delete rec;
		}
	}
	else
		LOG(INFO) << "Recorder is nullptr";
}

RTSPRECORDER_API BOOL WINAPI WriteHeader(PCHAR pchRtspPath){
	if (pchRtspPath == nullptr){
		LOG(INFO) << "Recorder is nullptr";
		return FALSE;
	}
	auto pRecorder = g_rtsp_recorder_container.getItem(pchRtspPath);
	if (pRecorder){
		CCallbackRecorder *rec = static_cast<CCallbackRecorder*>(pRecorder);
		LOG(INFO) << "TypeId(*rec):" << typeid(*rec).name();
		LOG(INFO) << "TypeId(*CCallbackRecorder):" << typeid(CCallbackRecorder).name();
		if (typeid(*rec).name() != typeid(CCallbackRecorder).name()){
			LOG(INFO) << "Recorder is not CCallbackRecorder";
			return FALSE;
		}
		LOG(INFO) << "WriteHeader";
		return rec->WriteHeader();
	}
	return FALSE;
}

RTSPRECORDER_API BOOL WINAPI GetHeader(PCHAR pchRtspPath){
	if (pchRtspPath == nullptr){
		LOG(INFO) << "Recorder is nullptr";
		return FALSE;
	}auto pRecorder = g_rtsp_recorder_container.getItem(pchRtspPath);
	if (pRecorder){
		CCallbackRecorder *rec = static_cast<CCallbackRecorder*>(pRecorder);
		LOG(INFO) << "TypeId(*rec):" << typeid(*rec).name();
		LOG(INFO) << "TypeId(*CCallbackRecorder):" << typeid(CCallbackRecorder).name();
		if (typeid(*rec).name() != typeid(CCallbackRecorder).name()){
			LOG(INFO) << "Recorder is not CCallbackRecorder";
			return FALSE;
		}
		LOG(INFO) << "SendHeader";
		return rec->SendHeader();
	}
	return FALSE;
}