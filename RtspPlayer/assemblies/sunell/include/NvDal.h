#ifndef _NVDAL_H_
#define _NVDAL_H_

#include "SNError.h"
#include "ErrorInfo.h"
#include "NvdSdkVersion.h"
#include "RemoteCamera.h"
#include "RemoteCamera2.h"
#include "RemoteSystem.h"
#include "RemotePTZ.h"
#include "RemotePTZEx.h"
#include "RemotePTZConfigure.h"
#include "RemoteRS485.h"
#include "RemoteRS485Ex.h"
#include "CMSService.h"
#include "CMSAlarmCenter.h"
#include "CMSAlarmCenter2.h"
#include "CMSDeviceSearcher.h"
#include "CMSDeviceSearcherEx.h"
#include "CMSBroadcastCenter.h"
#include "RemoteMicrophone.h"
#include "RemoteMicrophone2.h"
#include "RemoteVideoFile.h"
#include "RemoteAudioPlayer.h"
#include "RemoteAudioPlayer2.h"
#include "RemoteSensor.h"
#include "RemoteSensor2.h"
#include "ManualRecorder.h"
#include "RemoteCamera3.h"
#include "RemoteSnapshot.h"
#include "RemotePTZContainer.h"
#include "CharSet.h"
#include "TransferProtocol.h"
#include "RemoteDecoder.h"
#include "G7231Codec.h"
#include "G711_ALAW_Codec.h"
#include "G711_ULAW_Codec.h"
#include "AMRCodec.h"
#include "TSUnpackager.h"
#include "PSUnpackager.h"
#include "PSUnpackagerV2.h"
#include "PSUnpackagerV3.h"
#include "PTZAbilityParam.h"
#include "PresetPosAbilityParam.h"
#include "ExternDeviceAbility.h"



#if (defined(WIN32) || defined(_WIN32_WCE))
	#ifdef RECORD_INTERFACE
		//#ifdef (_MSC_VER < 1300) //VC++ 6.0  
		#include "CMSRecordCenter.h"
		#include "CMSRecordCenterV2.h"
		#include "CMSRecordRetriever.h"
		#include "CMSRecordSearcher.h"
#endif 
#endif //end win32

#ifdef RECORD_INTERFACE
#include "RemoteVideoFileV2.h"
#endif 


#endif
