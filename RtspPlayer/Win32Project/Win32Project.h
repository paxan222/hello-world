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

#include "MemLog.cpp"

PCHAR arr[2][54] = {
	{ "rtsp://55555:55555@192.168.11.178:554/cam/realmonitor?channel=1&subtype=1",
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
	"rtsp://55555:Five55555@192.168.11.118:554/cam/realmonitor?channel=1&subtype=02"
	 },
	{ "192.168.11.178_",
	"192.168.11.185_",
	"192.168.11.183_",
	"192.168.11.197_",
	"192.168.11.198_",
	"192.168.11.187_",
	"192.168.11.219_",
	"192.168.11.199_",
	"192.168.11.112_",
	"192.168.11.118_",
	"192.168.11.108_",
	"192.168.11.68_",
	"192.168.11.180_" } };


void RecordStream(PCHAR pathIn, PCHAR nameOut, int count) {
	std::thread([=]{
		LOG("ThreadStart");
		CBaseRecorder *record = new CCallbackRecorder(pathIn, 5000, "");
		if (record->Open(count)){
			/*record->StartRecord();
			Sleep(5000);
			CCallbackRecorder *rec = static_cast<CCallbackRecorder*>(record);

			if (typeid(*rec).hash_code() != typeid(CCallbackRecorder).hash_code()){
				LOG("Recorder is not CCallbackRecorder");
				LOG("StopRec");
				record->StopRecord();
			}
			else{
				rec->WriteHeader();
				Sleep(5000);
				LOG("StopRec");
				record->StopRecord();
			}*/
		}
		LOG("ThreadEnd");
	}).detach();
}

void RecordStreamArray(){
	//av_register_all();
	for (int i = 0; i < 5; i++){
		RecordStream(arr[0][i], arr[1][i], i);
	}

}