#pragma once

#include "resource.h"
#include "BasePlayer.h"
#include "FFmpegPlayer.h"

#include "BaseOperation.h"
#include "ConcatenateOperation.h"
#include "CutOperation.h"

#include "BaseRecorder.h"
#include "FileRecorder.h"
#include "CallbackRecorder.h"

#include <thread>
#include <map>

#include "MemLog.cpp"
#include "RtspRecorderApi.h"

PCHAR arr[56] = { 
	"rtsp://55555:55555@192.168.11.178:554/cam/realmonitor?channel=1&subtype=1",
	"rtsp://55555:55555@192.168.11.178:554/cam/realmonitor?channel=1&subtype=0",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=1&subtype=0",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=1&subtype=1",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=2&subtype=0",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=2&subtype=1",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=3&subtype=0",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=3&subtype=1",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=4&subtype=0",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=4&subtype=1",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=5&subtype=0",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=5&subtype=1",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=6&subtype=0",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=6&subtype=1",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=7&subtype=0",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=7&subtype=1",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=8&subtype=0",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=8&subtype=1",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=9&subtype=0",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=9&subtype=1",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=10&subtype=0",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=10&subtype=1",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=11&subtype=0",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=11&subtype=1",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=12&subtype=0",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=12&subtype=1",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=13&subtype=0",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=13&subtype=1",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=14&subtype=0",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=14&subtype=1",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=15&subtype=0",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=15&subtype=1",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=16&subtype=0",
	"rtsp://55555:55555@192.168.11.220:554/cam/realmonitor?channel=16&subtype=1",
	"rtsp://55555:55555@192.168.11.185:554/cam/realmonitor?channel=1&subtype=0",
	"rtsp://55555:55555@192.168.11.185:554/cam/realmonitor?channel=1&subtype=1",
	"rtsp://55555:55555@192.168.11.183:554/cam/realmonitor?channel=1&subtype=0",
	"rtsp://55555:55555@192.168.11.183:554/cam/realmonitor?channel=1&subtype=1",
	"rtsp://55555:55555@192.168.11.199:554/cam/realmonitor?channel=1&subtype=0",
	"rtsp://55555:55555@192.168.11.199:554/cam/realmonitor?channel=1&subtype=1",
	"rtsp://55555:55555@192.168.11.198:554/cam/realmonitor?channel=1&subtype=0",
	"rtsp://55555:55555@192.168.11.198:554/cam/realmonitor?channel=1&subtype=1",
	"rtsp://55555:55555@192.168.11.219:554/cam/realmonitor?channel=1&subtype=0",
	"rtsp://55555:55555@192.168.11.219:554/cam/realmonitor?channel=1&subtype=1",
	"rtsp://55555:55555@192.168.11.197:554/cam/realmonitor?channel=1&subtype=0",
	"rtsp://55555:55555@192.168.11.197:554/cam/realmonitor?channel=1&subtype=1",
	"rtsp://55555:55555@192.168.11.187:554/cam/realmonitor?channel=1&subtype=0",
	"rtsp://55555:55555@192.168.11.187:554/cam/realmonitor?channel=1&subtype=1",
	"rtsp://55555:55555@192.168.11.112:554/cam/realmonitor?channel=1&subtype=01",
	"rtsp://55555:55555@192.168.11.112:554/cam/realmonitor?channel=1&subtype=02",
	"rtsp://55555:Five55555@192.168.11.108:554/cam/realmonitor?channel=1&subtype=01",
	"rtsp://55555:Five55555@192.168.11.108:554/cam/realmonitor?channel=1&subtype=02",
	"rtsp://55555:Five55555@192.168.11.118:554/cam/realmonitor?channel=1&subtype=01",
	"rtsp://55555:Five55555@192.168.11.118:554/cam/realmonitor?channel=1&subtype=02",
	"rtsp://55555:Five55555@192.168.11.118:554/cam/realmonitor?channel=1&subtype=01",
	"rtsp://55555:Five55555@192.168.11.118:554/cam/realmonitor?channel=1&subtype=02"
	 };


static std::map < std::string, PVOID > g_rtsp_recorder_map;
static Container<std::string, PVOID> g_rtsp_recorder_container{ g_rtsp_recorder_map };
std::recursive_mutex _api_lock;

BOOL OpenAndStart(PCHAR pathIn, PCHAR nameOut, int count)
{
	std::lock_guard<std::recursive_mutex> locker(_api_lock);
	if (g_rtsp_recorder_container.hasItem(pathIn))
	{
		return FALSE;
	}
	CBaseRecorder *recorder;
	recorder = new CCallbackRecorder(pathIn, timeout, nameOut);
	g_rtsp_recorder_container.add(pathIn, recorder);
	if (recorder->Open(count) == FALSE){
		goto fail;
	}
	if (!recorder->StartRecord()){
		goto fail;
	}
	return TRUE;
fail:
	delete recorder;
	return FALSE;	
}

void StopAndDelete(PCHAR pchRtspPath)
{
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

void RecordStream(PCHAR pathIn, PCHAR nameOut, int count) {
	std::thread([=]{
		LOG("ThreadStart");
		LOG(pathIn);
		OpenAndStart(pathIn, nameOut, timeout);
		StopAndDelete(pathIn);
			LOG("ThreadEnd");
	}).detach();
}