// NvdcDll.h : NvdcDll DLL 的主头文件
//

#ifndef _NVDCDLL_H_
#define _NVDCDLL_H_

#ifdef __cplusplus 
extern "C" { 
#endif 

#include "SNPlatOS.h"
#include "SN_Struct.h"
#include "SNError.h"
#if (defined(WIN32) || defined(_WIN32_WCE))
#include "EventConst.h"
#endif

#ifndef byte
	typedef unsigned char byte;
#endif
using namespace NVDC_STRUCT;
namespace NVDC_FUC
{
//获取SDK版本号
void		 SN_C_API NvdSdk_GetVersion(long* p_nVersion);
bool		 SN_C_API NvdSdk_Is_Handle_Valid(const long p_hHandle );
long		 SN_C_API NvdSdk_SetCharSet(const int p_nCharSet);//0:GB2312; 1:UTF8

//初始化接口，在使用Remote C接口之前必须调用Remote_Nvd_Init初始化函数，使用完后应当调用Remote_Nvd_UnInit释放环境
long		 SN_C_API Remote_Nvd_Init(long* p_handle, const ST_DeviceInfo* p_stDeviceInfo, const long p_nTransferProtocol);
long		 SN_C_API Remote_Nvd_InitEx(long* p_handle, const ST_DeviceInfoEx* p_stDeviceInfoEx, const long p_nTransferProtocol);
long		 SN_C_API Remote_Nvd_UnInit(long p_hHandle);
void		 SN_C_API Remote_Nvd_formatMessage(const int p_nErrorCode, char* p_pszErrorMessage, const long p_nMessageBufLen);

//RemoteCamera C Interface( 接口废弃，使用Remote_Camera2_***接口 )
long SN_C_API Remote_Camera_SetDefaultImageFormatId(long p_hHandle, const unsigned long p_nImageFormatId);
long SN_C_API Remote_Camera_SetDefaultFrameRate(long p_hHandle, const unsigned long p_nFrameRate);
long SN_C_API Remote_Camera_SetDefaultBitRate(long p_hHandle, const unsigned long p_nBitRateType, const unsigned long p_nBitRate);
long SN_C_API Remote_Camera_SetDefaultQuality(long p_hHandle, const unsigned long p_nQuality);
long SN_C_API Remote_Camera_Open(long p_hHandle, const long p_nCameraID);
long SN_C_API Remote_Camera_Close(long p_hHandle);
long SN_C_API Remote_Camera_Read(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_Camera_ReadTS(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_Camera_StartAudio(long p_hHandle);
long SN_C_API Remote_Camera_StopAudio(long p_hHandle);
long SN_C_API Remote_Camera_GetVideoInfo(long p_hHandle, ST_VideoInfo* p_stVideoInfo);
long SN_C_API Remote_Camera_GetAudioInfo(long p_hHandle, ST_AudioInfo* p_stAudioInfo);
long SN_C_API Remote_Camera_GetVideoSystem(long p_hHandle, long* p_nVideoSystem);
long SN_C_API Remote_Camera_MakeKeyFrame(long p_hHandle);
long SN_C_API Remote_Camera_SetCurrentImageFormatId(long p_hHandle, const unsigned long p_nImageFormatId);
long SN_C_API Remote_Camera_GetCurrentImageFormatId(long p_hHandle, unsigned long* p_nImageFormatId);
long SN_C_API Remote_Camera_SetCurrentFrameRate(long p_hHandle, const unsigned long p_nFrameRate);
long SN_C_API Remote_Camera_GetCurrentFrameRate(long p_hHandle, unsigned long* p_nFrameRate);
long SN_C_API Remote_Camera_SetCurrentConfirmBitRate(long p_hHandle, const unsigned long p_nBitRateType, const unsigned long p_nConfirmBitRate);
long SN_C_API Remote_Camera_GetCurrentConfirmBitRate(long p_hHandle, unsigned long* p_nBitRateType, unsigned long* p_nConfirmBitRate);
long SN_C_API Remote_Camera_SetCurrentQuant(long p_hHandle, const unsigned long p_nQuant);
long SN_C_API Remote_Camera_GetCurrentQuant(long p_hHandle, unsigned long* p_nQuant);
long SN_C_API Remote_Camera_SetCurrentQuality(long p_hHandle, const unsigned long p_nQuality);
long SN_C_API Remote_Camera_GetCurrentQuality(long p_hHandle, unsigned long* p_nQuality);

//RemoteCamera2 C Interface
long SN_C_API Remote_Camera2_SetDefaultStreamId(long p_hHandle, const unsigned long p_nStreamId);
long SN_C_API Remote_Camera2_SetMulticastFlag(long p_hHandle, const bool p_bFlag);
bool SN_C_API Remote_Camera2_GetMulticastFlag(long p_hHandle);
long SN_C_API Remote_Camera2_Open(long p_hHandle, const long p_nCameraID);
long SN_C_API Remote_Camera2_Close(long p_hHandle);
long SN_C_API Remote_Camera2_Read(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_Camera2_ReadTS(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_Camera2_ReadPS(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_Camera2_StartAudio(long p_hHandle);
long SN_C_API Remote_Camera2_StopAudio(long p_hHandle);
long SN_C_API Remote_Camera2_SetCurrentStreamId(long p_hHandle, const unsigned long p_nStreamId);
long SN_C_API Remote_Camera2_GetCurrentStreamId(long p_hHandle, unsigned long* p_nStreamId);
long SN_C_API Remote_Camera2_MakeKeyFrame(long p_hHandle);
long SN_C_API Remote_Camera2_Pause(long p_hHandle);
long SN_C_API Remote_Camera2_Resume(long p_hHandle);
long SN_C_API Remote_Camera2_KeepAlive(long p_hHandle);

long SN_C_API Remote_Camera2_StartIntelligenceAnalyse(long p_hHandle);
long SN_C_API Remote_Camera2_StopIntelligenceAnalyse(long p_hHandle);

//RemoteCamera3 C Interface
long SN_C_API Remote_Camera3_SetDefaultStreamId(long p_hHandle, const unsigned long p_nStreamId);
long SN_C_API Remote_Camera3_SetStreamFormat(long p_hHandle, const int p_nStreamFormat);
long SN_C_API Remote_Camera3_SetAutoConnectFlag(long p_hHandle, const bool p_bFlag);
long SN_C_API Remote_Camera3_SetMulticastFlag(long p_hHandle, const bool p_bFlag);
bool SN_C_API Remote_Camera3_GetMulticastFlag(long p_hHandle);
long SN_C_API Remote_Camera3_Open(long p_hHandle, const long p_nCameraID);
long SN_C_API Remote_Camera3_Close(long p_hHandle);


long SN_C_API Remote_Camera3_SetMessageCallback(long p_hHandle, 
												 long (CALLBACK* fMessageCallback)(long p_hHandle, const int p_nMessageID, void* pUserData), 
												 void* pUserData);
long SN_C_API Remote_Camera3_SetAVDateCallback(long p_hHandle, 
												 long (CALLBACK* fAVDateCallback)(long p_hHandle, ST_AVFrameData* p_pstAVFrameData, void* pUserData), 
												 void* pUserData);

long SN_C_API Remote_Camera3_StartAudio(long p_hHandle);
long SN_C_API Remote_Camera3_StopAudio(long p_hHandle);
long SN_C_API Remote_Camera3_SetCurrentStreamId(long p_hHandle, const unsigned long p_nStreamId);
long SN_C_API Remote_Camera3_GetCurrentStreamId(long p_hHandle, unsigned long* p_nStreamId);
long SN_C_API Remote_Camera3_MakeKeyFrame(long p_hHandle);
long SN_C_API Remote_Camera3_Pause(long p_hHandle);
long SN_C_API Remote_Camera3_Resume(long p_hHandle);
long SN_C_API Remote_Camera3_KeepAlive(long p_hHandle);


//RemoteMicrophone C Interface( 接口废弃，使用Remote_Microphone2_***接口 )
long SN_C_API Remote_Microphone_Open(long p_hHandle, const long p_nCameraID);
long SN_C_API Remote_Microphone_Close(long p_hHandle);
long SN_C_API Remote_Microphone_Read(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_Microphone_ReadTS(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_Microphone_GetAudioInfo(long p_hHandle, ST_AudioInfo* p_stAudioInfo);

//RemoteMicrophone2 C Interface
long SN_C_API Remote_Microphone2_SetEncodeType(long p_hHandle, const int p_nEncodeType);
long SN_C_API Remote_Microphone2_Open(long p_hHandle, const long p_nCameraID);
long SN_C_API Remote_Microphone2_Close(long p_hHandle);
long SN_C_API Remote_Microphone2_Read(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_Microphone2_ReadTS(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);

//RemoteAudioPlayer C Interface(在设备端播放音频）（接口废弃，使用Remote_AudioPlayer2_***接口）
long SN_C_API Remote_AudioPlayer_Open(long p_hHandle);
long SN_C_API Remote_AudioPlayer_Close(long p_hHandle);
long SN_C_API Remote_AudioPlayer_Write(long p_hHandle, const ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_AudioPlayer_WriteTS(long p_hHandle, const ST_AVFrameData* p_pstAVFrameData);

//RemoteAudioPlayer C Interface(在设备端播放音频）
long SN_C_API Remote_AudioPlayer2_SetEncodeType(long p_hHandle, const int p_nEncodeType);
long SN_C_API Remote_AudioPlayer2_Open(long p_hHandle);
long SN_C_API Remote_AudioPlayer2_Close(long p_hHandle);
long SN_C_API Remote_AudioPlayer2_Write(long p_hHandle, const ST_AVFrameData* p_pstAVFrameData);


//RemoteRS485 C Interface
long SN_C_API Remote_RS485_SetTimeout(long p_hHandle, const int p_nTimeout);
long SN_C_API Remote_RS485_Open(long p_hHandle);
long SN_C_API Remote_RS485_Close(long p_hHandle);
long SN_C_API Remote_RS485_SetComId(long p_hHandle, const int p_nComId);
long SN_C_API Remote_RS485_SetOpenMode(long p_hHandle, const char p_btComOpenMode);
long SN_C_API Remote_RS485_Write(long p_hHandle, const char* p_pszWriteDate, const int p_nDateLen);

long SN_C_API Remote_RS485Ex_Open(long p_hHandle);
long SN_C_API Remote_RS485Ex_Close(long p_hHandle);
long SN_C_API Remote_RS485Ex_SetRS485Device(long p_hHandle, const ST_RS485Param* p_pstRS485Device);
long SN_C_API Remote_RS485Ex_Read(long p_hHandle, char* p_pszReadBuf, const int p_nBufLen);
long SN_C_API Remote_RS485Ex_Write(long p_hHandle, const char* p_pszWriteDate, const int p_nDateLen);

//RemoteSensor C Interface
long SN_C_API Remote_Sensor_SetTimeout(long p_hHandle, const int p_nTimeout);
long SN_C_API Remote_Sensor_Open(long p_hHandle);
long SN_C_API Remote_Sensor_Close(long p_hHandle);
long SN_C_API Remote_Sensor_GetSensorType(long p_hHandle, int &p_nSensorType);
long SN_C_API Remote_Sensor_SetParameters(long p_hHandle, const char* p_pszParameters, const int p_nLength);
long SN_C_API Remote_Sensor_GetAllParameters(long p_hHandle, char *p_pszParameterBuffer,int p_nParameterBufferLen, int* p_nOutDataLen);
long SN_C_API Remote_Sensor_ResetParameters(long p_hHandle);
long SN_C_API Remote_Sensor_Save(long p_hHandle);
long SN_C_API Remote_Sensor_SetSecretArea(long p_hHandle, const char* p_pszSecretArea, const int p_nLength);

long SN_C_API Remote_Sensor2_SetTimeout(long p_hHandle, const int p_nTimeout);
long SN_C_API Remote_Sensor2_Open(long p_hHandle);
long SN_C_API Remote_Sensor2_Close(long p_hHandle);
long SN_C_API Remote_Sensor2_SetBrightness(long p_hHandle, const int p_nValue);
long SN_C_API Remote_Sensor2_GetBrightness(long p_hHandle, int* p_pnValue);
long SN_C_API Remote_Sensor2_SetSharpness(long p_hHandle, const int p_nValue);
long SN_C_API Remote_Sensor2_GetSharpness(long p_hHandle, int* p_pnValue);
long SN_C_API Remote_Sensor2_SetHue(long p_hHandle, const int p_nValue);
long SN_C_API Remote_Sensor2_GetHue(long p_hHandle, int* p_pnValue);
long SN_C_API Remote_Sensor2_SetContrast(long p_hHandle, const int p_nValue);
long SN_C_API Remote_Sensor2_GetContrast(long p_hHandle, int* p_pnValue);
long SN_C_API Remote_Sensor2_SetSaturation(long p_hHandle, const int p_nValue);
long SN_C_API Remote_Sensor2_GetSaturation(long p_hHandle, int* p_pnValue);
long SN_C_API Remote_Sensor2_ResetParameters(long p_hHandle);
long SN_C_API Remote_Sensor2_Save(long p_hHandle);


//RemoteSensorUI C Interface

#if (defined(WIN32)&&!defined(_WIN32_WCE))
	long SN_C_API Remote_SensorUI_show(long p_hHandle,int p_nLanguage);
#endif

//RemotePTZ C Interface( 接口废弃 ,使用Remote_PTZEx_***接口)
long SN_C_API Remote_PTZ_SetDeviceId(long p_hHandle, const long p_nPTZId);
long SN_C_API Remote_PTZ_SetProtocol(long p_hHandle, const long p_nPTZProtocol);
long SN_C_API Remote_PTZ_SetCOMId(long p_hHandle, const long p_nCOMId);
long SN_C_API Remote_PTZ_Open(long p_hHandle, const long p_nCameraID);
long SN_C_API Remote_PTZ_Close(long p_hHandle);
long SN_C_API Remote_PTZ_Stop(long p_hHandle);
long SN_C_API Remote_PTZ_RotateUp(long p_hHandle, const long p_nSpeedValue);
long SN_C_API Remote_PTZ_RotateDown(long p_hHandle, const long p_nSpeedValue);
long SN_C_API Remote_PTZ_RotateLeft(long p_hHandle, const long p_nSpeedValue);
long SN_C_API Remote_PTZ_RotateRight(long p_hHandle, const long p_nSpeedValue);
long SN_C_API Remote_PTZ_RotateLeftUp(long p_hHandle, const long p_nSpeedValue);
long SN_C_API Remote_PTZ_RotateLeftUpEx(long p_hHandle, const long p_nPanSpeedValue, const long p_nTiltSpeedValue);
long SN_C_API Remote_PTZ_RotateLeftDown(long p_hHandle, const long p_nSpeedValue);
long SN_C_API Remote_PTZ_RotateLeftDownEx(long p_hHandle, const long p_nPanSpeedValue, const long p_nTiltSpeedValue);
long SN_C_API Remote_PTZ_RotateRightUp(long p_hHandle, const long p_nSpeedValue);
long SN_C_API Remote_PTZ_RotateRightUpEx(long p_hHandle, const long p_nPanSpeedValue, const long p_nTiltSpeedValue);
long SN_C_API Remote_PTZ_RotateRightDown(long p_hHandle, const long p_nSpeedValue);
long SN_C_API Remote_PTZ_RotateRightDownEx(long p_hHandle, const long p_nPanSpeedValue, const long p_nTiltSpeedValue);
long SN_C_API Remote_PTZ_ZoomIn(long p_hHandle);
long SN_C_API Remote_PTZ_ZoomOut(long p_hHandle);
long SN_C_API Remote_PTZ_FocusFar(long p_hHandle);
long SN_C_API Remote_PTZ_FocusNear(long p_hHandle);
long SN_C_API Remote_PTZ_IrisIncrease(long p_hHandle);
long SN_C_API Remote_PTZ_IrisDecrease(long p_hHandle);
long SN_C_API Remote_PTZ_PresetSet(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZ_PresetInvoke(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZ_PresetRemove(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZ_Scan(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZ_ScanRemove(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZ_ScanSetStartPoint(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZ_ScanSetStopPoint(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZ_RunAutoFocus(long p_hHandle);
long SN_C_API Remote_PTZ_RunAutoIris(long p_hHandle);
long SN_C_API Remote_PTZ_SetAutoStudyStartPoint(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZ_SetAutoStudyEndPoint(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZ_RunAutoStudy(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZ_AutoStudyRemove(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZ_Reset(long p_hHandle);
long SN_C_API Remote_PTZ_SendOperation(long p_hHandle, const byte* p_bytePTZCommand, const long p_nCommandLen);

//RemotePTZEx C Interface
long SN_C_API Remote_PTZEx_Open(long p_hHandle, const long p_nCameraID);
long SN_C_API Remote_PTZEx_Close(long p_hHandle);
long SN_C_API Remote_PTZEx_Stop(long p_hHandle);
long SN_C_API Remote_PTZEx_RotateUp(long p_hHandle, const long p_nSpeedValue);
long SN_C_API Remote_PTZEx_RotateDown(long p_hHandle, const long p_nSpeedValue);
long SN_C_API Remote_PTZEx_RotateLeft(long p_hHandle, const long p_nSpeedValue);
long SN_C_API Remote_PTZEx_RotateRight(long p_hHandle, const long p_nSpeedValue);
long SN_C_API Remote_PTZEx_RotateLeftUp(long p_hHandle, const long p_nSpeedValue);
long SN_C_API Remote_PTZEx_RotateLeftUpEx(long p_hHandle, const long p_nPanSpeedValue, const long p_nTiltSpeedValue);
long SN_C_API Remote_PTZEx_RotateLeftDown(long p_hHandle, const long p_nSpeedValue);
long SN_C_API Remote_PTZEx_RotateLeftDownEx(long p_hHandle, const long p_nPanSpeedValue, const long p_nTiltSpeedValue);
long SN_C_API Remote_PTZEx_RotateRightUp(long p_hHandle, const long p_nSpeedValue);
long SN_C_API Remote_PTZEx_RotateRightUpEx(long p_hHandle, const long p_nPanSpeedValue, const long p_nTiltSpeedValue);
long SN_C_API Remote_PTZEx_RotateRightDown(long p_hHandle, const long p_nSpeedValue);
long SN_C_API Remote_PTZEx_RotateRightDownEx(long p_hHandle, const long p_nPanSpeedValue, const long p_nTiltSpeedValue);
long SN_C_API Remote_PTZEx_ZoomIn(long p_hHandle);
long SN_C_API Remote_PTZEx_ZoomOut(long p_hHandle);
long SN_C_API Remote_PTZEx_FocusFar(long p_hHandle);
long SN_C_API Remote_PTZEx_FocusNear(long p_hHandle);
long SN_C_API Remote_PTZEx_IrisIncrease(long p_hHandle);
long SN_C_API Remote_PTZEx_IrisDecrease(long p_hHandle);
long SN_C_API Remote_PTZEx_PresetSet(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZEx_PresetInvoke(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZEx_PresetRemove(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZEx_Scan(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZEx_ScanRemove(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZEx_ScanSetStartPoint(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZEx_ScanSetStopPoint(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZEx_RunAutoFocus(long p_hHandle);
long SN_C_API Remote_PTZEx_RunAutoIris(long p_hHandle);//(此接口废弃)
long SN_C_API Remote_PTZEx_setAutoStudyStartPoint(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZEx_setAutoStudyEndPoint(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZEx_RunAutoStudy(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZEx_AutoStudyRemove(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZEx_threeDimensionalPositioning(long p_hHandle, const long p_nX, const long p_nY, const long p_nZoomRate);
long SN_C_API Remote_PTZEx_SetTourStartPoint(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZEx_AddTourPoint(long p_hHandle, const long p_nPresetValue, const long p_nSpeedValue, const long p_nTimeValue);
long SN_C_API Remote_PTZEx_SetTourEndPoint(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZEx_RunTour(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZEx_StopTour(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZEx_DeleteTour(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZEx_SetKeeper(long p_hHandle, const long p_nTypeValue, const long p_nIdValue, const long p_nTimeValue);
long SN_C_API Remote_PTZEx_RunKeeper(long p_hHandle, const long p_nValue);
long SN_C_API Remote_PTZEx_Reset(long p_hHandle);
long SN_C_API Remote_PTZEx_RunBrush(long p_hHandle);
long SN_C_API Remote_PTZEx_OpenLight(long p_hHandle);
long SN_C_API Remote_PTZEx_CloseLight(long p_hHandle);

long SN_C_API Remote_PTZEx_SetInfrared(long p_hHandle, const int p_nMode, const int p_nNear, const int p_nMiddle, const int p_nFar);
long SN_C_API Remote_PTZEx_SetInfraredV2(long p_hHandle, const int p_nOpenMode, const int p_nBrightnessMode, const int p_nNear, const int p_nMiddle, const int p_nFar);
long SN_C_API Remote_PTZEx_SetNorthPostion(long p_hHandle);
long SN_C_API Remote_PTZEx_SetPostion(long p_hHandle, const int p_nType, const float p_nPan, const float p_nTilt, const float p_nZoom);
long SN_C_API Remote_PTZEx_GetPostion(long p_hHandle, float* p_nPan, float* p_nTilt, float* p_nZoom, int* p_nDirection);

long SN_C_API Remote_PTZEx_SendOperation(long p_hHandle, const char* p_bytePTZCommand, const long p_nCommandLen);

//RemotePTZConfigure
long SN_C_API Remote_PTZConfigure_Open(long p_hHandle,const int p_nCameraID);
long SN_C_API Remote_PTZConfigure_Close(long p_hHandle);
long SN_C_API Remote_PTZConfigure_SetPTZPresetName(long p_hHandle,const int p_nPresetID, const char* p_pszPresetName);
long SN_C_API Remote_PTZConfigure_GetPTZPreset(long p_hHandle, const int p_nPresetID, ST_PTZPreset* p_pstPTZPreset);
long SN_C_API Remote_PTZConfigure_GetAllPTZPreset(long p_hHandle,ST_PTZPresetList* p_pszPTZPresetList);
long SN_C_API Remote_PTZConfigure_DeletePTZPreset(long p_hHandle,const int p_nPresetID);
long SN_C_API Remote_PTZConfigure_DeleteAllPTZPreset(long p_hHandle);

long SN_C_API Remote_PTZConfigure_SetPTZKeeper(long p_hHandle,const int p_nKeeperType, const int p_nPTZKeeperID, const int p_nKeepTime);
long SN_C_API Remote_PTZConfigure_GetPTZKeeper(long p_hHandle,int* p_nKeeperType, int* p_nPTZKeeperID, int* p_nKeeperTime);
long SN_C_API Remote_PTZConfigure_DeletePTZKeeper(long p_hHandle);
long SN_C_API Remote_PTZConfigure_SetPTZKeeperState(long p_hHandle,const int p_nKeeperState);
long SN_C_API Remote_PTZConfigure_GetPTZKeeperState(long p_hHandle, int* p_nKeeperState);
long SN_C_API Remote_PTZConfigure_DeleteKeeperState(long p_hHandle);

long SN_C_API Remote_PTZConfigure_SetPTZTour(long p_hHandle,const int p_nTourID, const char* p_pszTourName, const ST_PTZTourPointList* p_pstPTZTourPointList);
long SN_C_API Remote_PTZConfigure_GetPTZTour(long p_hHandle,int p_nTourID, ST_PTZTourEx* p_stPTZTourEx);
long SN_C_API Remote_PTZConfigure_GetPTZAllTour(long p_hHandle,ST_PTZTourExList* p_pstPTZTourList);
long SN_C_API Remote_PTZConfigure_DeletePTZTour(long p_hHandle,const int p_nTourID);

long SN_C_API Remote_PTZConfigure_SetPTZScan(long p_hHandle,const int p_nScanID, const char* p_pszScanName);
long SN_C_API Remote_PTZConfigure_GetPTZScan(long p_hHandle,const int p_nScanID, ST_PTZScan* p_pstPTZScan);
long SN_C_API Remote_PTZConfigure_GetAllPTZScan(long p_hHandle,ST_PTZScanList* p_pstPTZScanList);
long SN_C_API Remote_PTZConfigure_DeletePTZScan(long p_hHandle,const int p_nScanID);

long SN_C_API Remote_PTZConfigure_SetPTZTrack(long p_hHandle,const int p_nTrackID, const char* p_pszTrackName);
long SN_C_API Remote_PTZConfigure_GetPTZTrack(long p_hHandle,const int p_nTrackID, ST_PTZTrack* p_pstPTZTrack);
long SN_C_API Remote_PTZConfigure_GetAllPTZTrack(long p_hHandle,ST_PTZTrackList* p_pstPTZTrackList);
long SN_C_API Remote_PTZConfigure_DeletePTZTrack(long p_hHandle,const int p_nTrackID);
//清空配置文件
long SN_C_API Remote_PTZConfigure_DeleteAllParam(long p_hHandle);

//RemoteVideoFile C Interface (文件下载）
long SN_C_API Remote_VideoFile_OpenEx(long p_hHandle, const ST_RecordInfo* p_stRecordInfo);
long SN_C_API Remote_VideoFile_OpenV2(long p_hHandle, const ST_RecordInfoV2* p_stRecordInfo);
long SN_C_API Remote_VideoFile_Close(long p_hHandle);
long SN_C_API Remote_VideoFile_Read(long p_hHandle, char* p_pszBuf, const unsigned int p_nBufSize);
long SN_C_API Remote_VideoFile_Seek(long p_hHandle, const INT64  p_nOffset, const unsigned char p_nSeekMode);
long SN_C_API Remote_VideoFile_GetFileLength(long p_hHandle, INT64 * p_nLength); 

#ifdef RECORD_INTERFACE
long SN_C_API Remote_VideoFileV2_Open(long p_hHandle, const ST_RecordInfoV2* p_stRecordInfo, bool p_bIsNeedLocateIFrame = true);
long SN_C_API Remote_VideoFileV2_Close(long p_hHandle);
bool SN_C_API Remote_VideoFileV2_RecallRead(long p_hHandle);
long SN_C_API Remote_VideoFileV2_ReadNextFrame(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_VideoFileV2_ReadNextVideoFrame(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_VideoFileV2_ReadNextIFrame(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_VideoFileV2_ReadPreviousVideoIFrame(long p_hHandle, ST_AVFrameData* p_pstAVFrameData, bool p_bCurPosFlag = false);
long SN_C_API Remote_VideoFileV2_PrevFrame(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_VideoFileV2_LocatePreIFrame(long p_hHandle, const ST_TimeStruct* p_pstTime, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_VideoFileV2_LocateFrame(long p_hHandle, const ST_TimeStruct* p_pstTime, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_VideoFileV2_ReadNextFrameTS(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_VideoFileV2_ReadNextVideoFrameTS(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_VideoFileV2_ReadPreviousVideoIFrameTS(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_VideoFileV2_LocateFrameTS(long p_hHandle, const ST_TimeStruct* p_pstTime, ST_AVFrameData* p_pstAVFrameData);

long SN_C_API Remote_VideoFileV2_ReadNextFramePS(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_VideoFileV2_ReadNextVideoFramePS(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_VideoFileV2_ReadPreviousVideoIFramePS(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_VideoFileV2_LocateFramePS(long p_hHandle, const ST_TimeStruct* p_pstTime, ST_AVFrameData* p_pstAVFrameData);

#endif

#if (defined(WIN32)&&!defined(_WIN32_WCE))

	//RemoteLivePlayer C Interface (实时预览）( 接口已废弃，使用Remote_LivePlayer2_***接口 )
	long SN_C_API Remote_LivePlayer_SetUseTimeStamp(long p_hHandle, const bool bUseFlag);
	long SN_C_API Remote_LivePlayer_SetPlayBufferSize(long p_hHandle, const unsigned long p_nSecSize);//p_nSecSize, 以毫秒(s)为单位 必须在0秒-最大5000毫秒缓冲。注：播放缓冲越大，播放越平滑，但延时将增大，当为0时，无论是否用时间戳，视频将立即被播放
	long SN_C_API Remote_LivePlayer_SetStretchMode(long p_hHandle, const bool p_bStretchMode);
	long SN_C_API Remote_LivePlayer_SetNotifyWindow(long p_hHandle, const unsigned long p_nNotifyWnd, const unsigned long p_nMessage, const void * p_pParam);
	long SN_C_API Remote_LivePlayer_SetTryConnectCount(long p_hHandle, const unsigned long p_nTryCount );
	long SN_C_API Remote_LivePlayer_SetAutoConnectFlag(long p_hHandle, const bool p_bAutoFlag );
	long SN_C_API Remote_LivePlayer_SetDefaultImageFormatId(long p_hHandle, const unsigned long p_nImageFormatId);
	long SN_C_API Remote_LivePlayer_SetDefaultFrameRate(long p_hHandle, const unsigned long p_nFrameRate);
	long SN_C_API Remote_LivePlayer_SetDefaultBitRate(long p_hHandle, const unsigned long p_nBitRateType, const unsigned long p_nBitRate);
	long SN_C_API Remote_LivePlayer_SetDefaultQuality(long p_hHandle, const unsigned long p_nQuality);
	long SN_C_API Remote_LivePlayer_SetAutoResizeFlag(long p_hHandle, const bool p_bAutoResizeFlag = true);
	long SN_C_API Remote_LivePlayer_SetVideoWindow(long p_hHandle, const unsigned long p_hDisplayWnd, const long x, const long y, const long width, const long height);
	long SN_C_API Remote_LivePlayer_SetVideoWindowEx(long p_hHandle, const unsigned long p_hDisplayWnd);
	long SN_C_API Remote_LivePlayer_SetDrawCallBack(long p_hHandle, long hHandle,long (CALLBACK *DrawCallBack)(long hHandle, HDC hDc, void *pUserData), void* pUserData);
	long SN_C_API Remote_LivePlayer_Open(long p_hHandle, const long p_nCameraID);
	long SN_C_API Remote_LivePlayer_Close(long p_hHandle);
	long SN_C_API Remote_LivePlayer_Play(long p_hHandle);
	long SN_C_API Remote_LivePlayer_Pause(long p_hHandle);
	long SN_C_API Remote_LivePlayer_GetPlayStatus(long p_hHandle, long* p_nPlayStatus);
	long SN_C_API Remote_LivePlayer_PlaySound(long p_hHandle);
	long SN_C_API Remote_LivePlayer_StopSound(long p_hHandle);
	long SN_C_API Remote_LivePlayer_IsOnSound(long p_hHandle, bool* p_bOnSound);
	long SN_C_API Remote_LivePlayer_ResizeWindow(long p_hHandle, const long x, const long y, const long width, const long height);
	long SN_C_API Remote_LivePlayer_Refresh(long p_hHandle);
	long SN_C_API Remote_LivePlayer_GetDeviceInfo(long p_hHandle, ST_DeviceInfo* p_stDeviceInfo);
	long SN_C_API Remote_LivePlayer_GetDeviceInfoEx(long p_hHandle, ST_DeviceInfoEx* p_stDeviceInfoEx);
	long SN_C_API Remote_LivePlayer_SetRecorderFile(long p_hHandle, const char* p_pszFileName);
	long SN_C_API Remote_LivePlayer_StartRecord(long p_hHandle);
	long SN_C_API Remote_LivePlayer_StopRecord(long p_hHandle);
	long SN_C_API Remote_LivePlayer_GetRecorderStatus(long p_hHandle, long* p_nStatus);
	long SN_C_API Remote_LivePlayer_SnapShot(long p_hHandle, const char* p_pszFileName);
	long SN_C_API Remote_LivePlayer_GetVideoSystem(long p_hHandle, long* p_nVideoSystem);
	long SN_C_API Remote_LivePlayer_SetCurrentFrameRate(long p_hHandle, const unsigned long p_nFrameRate);
	long SN_C_API Remote_LivePlayer_GetCurrentFrameRate(long p_hHandle, unsigned long* p_nFrameRate);
	long SN_C_API Remote_LivePlayer_SetCurrentImageFormatId(long p_hHandle, const unsigned long p_nCurrentImageFormatId);
	long SN_C_API Remote_LivePlayer_GetCurrentImageFormatId(long p_hHandle, unsigned long* p_nCurrentImageFormatId);
	long SN_C_API Remote_LivePlayer_SetCurrentConfirmBitRate(long p_hHandle, const unsigned long p_nBitRateType, const unsigned long p_nConfirmBitRate);
	long SN_C_API Remote_LivePlayer_GetCurrentConfirmBitRate(long p_hHandle, unsigned long* p_nBitRateType, unsigned long* p_nConfirmBitRate);
	long SN_C_API Remote_LivePlayer_SetCurrentQuant(long p_hHandle, const unsigned long p_nQuant);
	long SN_C_API Remote_LivePlayer_GetCurrentQuant(long p_hHandle, unsigned long* p_nQuant);
	long SN_C_API Remote_LivePlayer_SetCurrentQuality(long p_hHandle, const unsigned long p_nQuality);
	long SN_C_API Remote_LivePlayer_GetCurrentQuality(long p_hHandle, unsigned long* p_nQuality);
	long SN_C_API Remote_LivePlayer_SetCurrentBrightness(long p_hHandle, const unsigned long p_nValue);
	long SN_C_API Remote_LivePlayer_GetCurrentBrightness(long p_hHandle, unsigned long* p_nValue);
	long SN_C_API Remote_LivePlayer_SetCurrentContrast(long p_hHandle, const unsigned long p_nValue);
	long SN_C_API Remote_LivePlayer_GetCurrentContrast(long p_hHandle, unsigned long* p_nValue);
	long SN_C_API Remote_LivePlayer_SetCurrentHue(long p_hHandle, const unsigned long p_nValue);
	long SN_C_API Remote_LivePlayer_GetCurrentHue(long p_hHandle, unsigned long* p_nValue);
	long SN_C_API Remote_LivePlayer_SetCurrentSaturation(long p_hHandle, const unsigned long p_nValue);
	long SN_C_API Remote_LivePlayer_GetCurrentSaturation(long p_hHandle, unsigned long* p_nValue);
	long SN_C_API Remote_LivePlayer_ResetPictureAdjustFilter(long p_hHandle);
	long SN_C_API Remote_LivePlayer_GetCurrentBitRate(long p_hHandle, unsigned long* p_nBitRate);
	long SN_C_API Remote_LivePlayer_GetPictureSize(long p_hHandle, long* p_nWidth, long* p_nHeight);
	long SN_C_API Remote_LivePlayer_SetVolume(long p_hHandle, const long p_nVolume);
	long SN_C_API Remote_LivePlayer_GetVolume(long p_hHandle, long* p_nVolume);
	long SN_C_API Remote_LivePlayer_ZoomInVideoEx(long p_hHandle, const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height);
	long SN_C_API Remote_LivePlayer_ZoomInVideo(long p_hHandle);
	long SN_C_API Remote_LivePlayer_ZoomOutVideo(long p_hHandle);
	long SN_C_API Remote_LivePlayer_RestoreVideo(long p_hHandle);

	//RemoteLivePlayer2 C Interface (实时预览）
	long SN_C_API Remote_LivePlayer2_SetUseTimeStamp(long p_hHandle, const bool p_bUseFlag);
	long SN_C_API Remote_LivePlayer2_SetPlayBufferSize(long p_hHandle, const unsigned long p_nSecSize);//p_nSecSize, 以毫秒(s)为单位 必须在0秒-最大5000毫秒缓冲。注：播放缓冲越大，播放越平滑，但延时将增大，当为0时，无论是否用时间戳，视频将立即被播放
	long SN_C_API Remote_LivePlayer2_SetStretchMode(long p_hHandle, const bool p_bStretchMode);
	long SN_C_API Remote_LivePlayer2_SetNotifyWindow(long p_hHandle, const unsigned long p_nNotifyWnd, const unsigned long p_nMessage, const void * p_pParam);
	long SN_C_API Remote_LivePlayer2_SetTryConnectCount(long p_hHandle, const unsigned long p_nTryCount );
	long SN_C_API Remote_LivePlayer2_SetAutoConnectFlag(long p_hHandle, const bool p_bAutoFlag );
	long SN_C_API Remote_LivePlayer2_SetDefaultStreamId(long p_hHandle, const unsigned long p_nStreamId);
	long SN_C_API Remote_LivePlayer2_SetAutoResizeFlag(long p_hHandle, const bool p_bAutoResizeFlag = true);
	long SN_C_API Remote_LivePlayer2_SetVideoWindow(long p_hHandle, const unsigned long p_hDisplayWnd, const long x, const long y, const long width, const long height);
	long SN_C_API Remote_LivePlayer2_SetVideoWindowEx(long p_hHandle, const unsigned long p_hDisplayWnd);
	long SN_C_API Remote_LivePlayer2_SetDrawCallBack(long p_hHandle, long hHandle,long (CALLBACK *DrawCallBack)(long hHandle, HDC hDc, void *pUserData), void* pUserData);
	long SN_C_API Remote_LivePlayer2_Open(long p_hHandle, const long p_nCameraID);
	long SN_C_API Remote_LivePlayer2_Close(long p_hHandle);
	long SN_C_API Remote_LivePlayer2_Play(long p_hHandle);
	long SN_C_API Remote_LivePlayer2_Pause(long p_hHandle);
	long SN_C_API Remote_LivePlayer2_GetPlayStatus(long p_hHandle, long* p_nPlayStatus);
	long SN_C_API Remote_LivePlayer2_PlaySound(long p_hHandle);
	long SN_C_API Remote_LivePlayer2_StopSound(long p_hHandle);
	long SN_C_API Remote_LivePlayer2_IsOnSound(long p_hHandle, bool* p_bOnSound);
	long SN_C_API Remote_LivePlayer2_ResizeWindow(long p_hHandle, const long x, const long y, const long width, const long height);
	long SN_C_API Remote_LivePlayer2_Refresh(long p_hHandle);
	long SN_C_API Remote_LivePlayer2_GetDeviceInfoEx(long p_hHandle, ST_DeviceInfoEx* p_stDeviceInfoEx);
	long SN_C_API Remote_LivePlayer2_SetRecorderFile(long p_hHandle, const char* p_pszFileName);
	long SN_C_API Remote_LivePlayer2_SetRecordFileFormat(long p_hHandle, const int p_nFileFormat);
	long SN_C_API Remote_LivePlayer2_SetRecordFileHead(long p_hHandle, const char* p_pszRecordFileHead, const int p_nRecordFileLength);
	long SN_C_API Remote_LivePlayer2_StartRecord(long p_hHandle);
	long SN_C_API Remote_LivePlayer2_StopRecord(long p_hHandle);
	long SN_C_API Remote_LivePlayer2_GetRecorderStatus(long p_hHandle, long* p_nStatus);
	long SN_C_API Remote_LivePlayer2_SnapShot(long p_hHandle, const char* p_pszFileName);
	long SN_C_API Remote_LivePlayer2_SetCurrentStreamId(long p_hHandle, const unsigned long p_nCurrentStreamId);
	long SN_C_API Remote_LivePlayer2_GetCurrentStreamId(long p_hHandle, unsigned long* p_nCurrentStreamId);
	long SN_C_API Remote_LivePlayer2_SetCurrentBrightness(long p_hHandle, const unsigned long p_nValue);
	long SN_C_API Remote_LivePlayer2_GetCurrentBrightness(long p_hHandle, unsigned long* p_nValue);
	long SN_C_API Remote_LivePlayer2_SetCurrentContrast(long p_hHandle, const unsigned long p_nValue);
	long SN_C_API Remote_LivePlayer2_GetCurrentContrast(long p_hHandle, unsigned long* p_nValue);
	long SN_C_API Remote_LivePlayer2_SetCurrentHue(long p_hHandle, const unsigned long p_nValue);
	long SN_C_API Remote_LivePlayer2_GetCurrentHue(long p_hHandle, unsigned long* p_nValue);
	long SN_C_API Remote_LivePlayer2_SetCurrentSaturation(long p_hHandle, const unsigned long p_nValue);
	long SN_C_API Remote_LivePlayer2_GetCurrentSaturation(long p_hHandle, unsigned long* p_nValue);
	long SN_C_API Remote_LivePlayer2_ResetPictureAdjustFilter(long p_hHandle);
	long SN_C_API Remote_LivePlayer2_GetCurrentFrameRate(long p_hHandle, unsigned long* p_nFrameRate);
	long SN_C_API Remote_LivePlayer2_GetCurrentBitRate(long p_hHandle, unsigned long* p_nBitRate);
	long SN_C_API Remote_LivePlayer2_GetPictureSize(long p_hHandle, long* p_nWidth, long* p_nHeight);
	long SN_C_API Remote_LivePlayer2_SetVolume(long p_hHandle, const long p_nVolume);
	long SN_C_API Remote_LivePlayer2_GetVolume(long p_hHandle, long* p_nVolume);
	long SN_C_API Remote_LivePlayer2_ZoomInVideoEx(long p_hHandle, const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height);
	long SN_C_API Remote_LivePlayer2_ZoomInVideo(long p_hHandle);
	long SN_C_API Remote_LivePlayer2_ZoomOutVideo(long p_hHandle);
	long SN_C_API Remote_LivePlayer2_RestoreVideo(long p_hHandle);

	//RemoteInterphone C Interface (语音对讲）（接口废弃，使用Remote_Interphone2_***接口）
	long SN_C_API Remote_Interphone_Start(long p_hHandle);
	long SN_C_API Remote_Interphone_Stop(long p_hHandle);

	//RemoteInterphone2 C Interface (语音对讲）
	long SN_C_API Remote_Interphone2_SetEncodeType(long p_hHandle, const int p_nEncodeType);
	long SN_C_API Remote_Interphone2_Start(long p_hHandle);
	long SN_C_API Remote_Interphone2_Stop(long p_hHandle);

	////RemotePlayBack C Interface (远端文件回放）
	long SN_C_API Remote_PlayBack_SetStretchMode(long p_hHandle, const bool p_bStretchMode);
	long SN_C_API Remote_PlayBack_SetAutoResizeFlag(long p_hHandle, const bool p_bAutoFlag );
	long SN_C_API Remote_PlayBack_SetNotifyWindow(long p_hHandle, const unsigned long p_nNotifyWnd, const unsigned long p_nMessage, const void * p_pParam);
	long SN_C_API Remote_PlayBack_SetTryConnectCount(long p_hHandle, const unsigned long p_nTryCount );
	long SN_C_API Remote_PlayBack_SetAutoConnectFlag(long p_hHandle, const bool p_bAutoFlag );
	long SN_C_API Remote_PlayBack_SetVideoWindow(long p_hHandle, const unsigned long p_hDisplayWnd, const long x, const long y, const long width, const long height);
	long SN_C_API Remote_PlayBack_SetRecordInfo(long p_hHandle, const ST_RecordInfo* p_stRecordInfo); //此接口废弃
	long SN_C_API Remote_PlayBack_SetRecordInfoV2(long p_hHandle, const ST_RecordInfoV2* p_stRecordInfo);
	long SN_C_API Remote_PlayBack_Open(long p_hHandle);
	long SN_C_API Remote_PlayBack_Close(long p_hHandle);
	long SN_C_API Remote_PlayBack_Play(long p_hHandle);
	long SN_C_API Remote_PlayBack_Pause(long p_hHandle);
	long SN_C_API Remote_PlayBack_Stop(long p_hHandle);
	long SN_C_API Remote_PlayBack_ResizeWindow(long p_hHandle, const long x, const long y, const long width, const long height);
	long SN_C_API Remote_PlayBack_Refresh(long p_hHandle);
	long SN_C_API Remote_PlayBack_GetPlayStatus(long p_hHandle, long* p_nPlayStatus);
	long SN_C_API Remote_PlayBack_PlayNextFrame(long p_hHandle);
	long SN_C_API Remote_PlayBack_PlayPreviousFrame(long p_hHandle);
	long SN_C_API Remote_PlayBack_PlaySound(long p_hHandle);
	long SN_C_API Remote_PlayBack_StopSound(long p_hHandle);
	long SN_C_API Remote_PlayBack_IsOnSound(long p_hHandle, bool* p_bOnSound);
	long SN_C_API Remote_PlayBack_SetVolume(long p_hHandle, const long p_nVolume);
	long SN_C_API Remote_PlayBack_GetVolume(long p_hHandle, long* p_nVolume);
	long SN_C_API Remote_PlayBack_GetDuration(long p_hHandle, long* p_nDuration);
	long SN_C_API Remote_PlayBack_GetPlayPosByTime(long p_hHandle, long* p_nDuration);
	long SN_C_API Remote_PlayBack_SetPlayPosByTime(long p_hHandle, const long p_nDuration);
	long SN_C_API Remote_PlayBack_GetPlayPosByPercent(long p_hHandle, long* p_nPercent);
	long SN_C_API Remote_PlayBack_SetPlayPosByPercent(long p_hHandle, const long p_nPercent);
	long SN_C_API Remote_PlayBack_SetSpeed( long p_hHandle, float p_nSpeed );
	long SN_C_API Remote_PlayBack_GetSpeed( long p_hHandle,float* p_nSpeed );
	long SN_C_API Remote_PlayBack_GetFileTotalFrames(long p_hHandle, long* p_nTotalFrames);
	long SN_C_API Remote_PlayBack_GetPlayedFrames(long p_hHandle, long* p_nPlayedFrames);
	long SN_C_API Remote_PlayBack_SetCurrentFrameNum(long p_hHandle, const long p_nCurrentFrameNum);
	long SN_C_API Remote_PlayBack_SetBrightness(long p_hHandle, const unsigned long p_nValue);
	long SN_C_API Remote_PlayBack_GetBrightness(long p_hHandle, unsigned long* p_nValue);
	long SN_C_API Remote_PlayBack_SetContrast(long p_hHandle, const unsigned long p_nValue);
	long SN_C_API Remote_PlayBack_GetContrast(long p_hHandle, unsigned long* p_nValue);
	long SN_C_API Remote_PlayBack_SetHue(long p_hHandle, const unsigned long p_nValue);
	long SN_C_API Remote_PlayBack_GetHue(long p_hHandle, unsigned long* p_nValue);
	long SN_C_API Remote_PlayBack_SetSaturation(long p_hHandle, const unsigned long p_nValue);
	long SN_C_API Remote_PlayBack_GetSaturation(long p_hHandle, unsigned long* p_nValue);
	long SN_C_API Remote_PlayBack_ResetPictureAdjustFilter(long p_hHandle);
	long SN_C_API Remote_PlayBack_SnapShot(long p_hHandle, const char* p_pszFileName);
	long SN_C_API Remote_PlayBack_ZoomInVideoEx(long p_hHandle, const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height);
	long SN_C_API Remote_PlayBack_ZoomInVideo(long p_hHandle);
	long SN_C_API Remote_PlayBack_ZoomOutVideo(long p_hHandle);
	long SN_C_API Remote_PlayBack_RestoreVideo(long p_hHandle);

	long SN_C_API Remote_PlayBack_SetRecorderFile(long p_hHandle, const char* p_pszFileName);
	long SN_C_API Remote_PlayBack_SetRecordFileFormat(long p_hHandle, const int p_nFileFormat);
	long SN_C_API Remote_PlayBack_SetRecordFileHead(long p_hHandle, const char* p_pszRecordFileHead, const int p_nRecordFileLength);
	long SN_C_API Remote_PlayBack_StartRecord(long p_hHandle);
	long SN_C_API Remote_PlayBack_StopRecord(long p_hHandle);
	long SN_C_API Remote_PlayBack_GetRecorderStatus(long p_hHandle, long* p_nStatus);

#endif //end win32

//RemoteSystem C Interface(参数设置接口）
long SN_C_API Remote_System_SetTimeout(long p_hHandle, const int p_nTimeout);
long SN_C_API Remote_System_Open(long p_hHandle);
long SN_C_API Remote_System_Close(long p_hHandle);

//重启
long SN_C_API Remote_System_Restart(long p_hHandle);

//复位
long SN_C_API Remote_System_Reset(long p_hHandle);

//关机
long SN_C_API Remote_System_ShutDown(long p_hHandle);

//格式化磁盘
long SN_C_API Remote_System_FormatDisk(long p_hHandle);
long SN_C_API Remote_System_FormatDiskEx(long p_hHandle, const char* p_szDiskName, long p_nFileSystemType);

//设置设备ID
long SN_C_API Remote_System_SetDeviceId(long p_hHandle, const char* p_pszDeviceId);
//设置设备名
long SN_C_API Remote_System_SetDeviceName(long p_hHandle, const char* p_pszDeviceName);
//获取概要信息
long SN_C_API Remote_System_GetSystemInfo(long p_hHandle, const ST_InetAddr p_stAddr, ST_DeviceSummaryParam* p_pstDeviceSummaryInfo, long p_nTransferProtocol);

//获取设备能力
long SN_C_API Remote_System_GetDeviceAbility(long p_hHandle, ST_DeviceAbility* p_pstDeviceAbility);
long SN_C_API Remote_System_GetDeviceExAbility(long p_hHandle, ST_DeviceExAbility* p_pstDeviceExAbility);
long SN_C_API Remote_System_GetDeviceExAbilityV2(long p_hHandle, ST_DeviceExAbilityV2* p_pstDeviceExAbility);

long SN_C_API Remote_System_GetMotionDetectionExAbility(long p_hHandle, const long p_nCameraID,ST_MotionDetectionExAbility* p_pstMotionDetectionExAbility);

//获取工作状态
long SN_C_API Remote_System_GetDeviceWorkState(long p_hHandle, ST_DeviceWorkState* p_pstDeviceWorkState);
//获取磁盘信息
long SN_C_API Remote_System_GetDeviceDiskInfo(long p_hHandle, ST_AllDiskStatistic* p_pstDiskStatisticList);

//设置获取通道信息
long SN_C_API Remote_System_SetAllCameraDevice(long p_hHandle, const ST_AllCameraInfoParam* p_pstAllCameraInfoParam);
long SN_C_API Remote_System_GetAllCameraDevice(long p_hHandle, ST_AllCameraInfoParam* p_pstAllCameraInfoParam);
long SN_C_API Remote_System_SetCameraDevice(long p_hHandle, const long p_nCameraId, const ST_CameraInfoParam* p_pstCameraDevice);
long SN_C_API Remote_System_GetCameraDevice(long p_hHandle, const long p_nCameraId, ST_CameraInfoParam* p_pstCameraDevice);

//设置拾音器参数
long SN_C_API Remote_System_SetAllToneArmParam(long p_hHandle, const ST_AllToneArmParam* p_pstAllToneArmParam);
long SN_C_API Remote_System_GetAllToneArmParam(long p_hHandle, ST_AllToneArmParam* p_pstAllToneArmParam);
long SN_C_API Remote_System_SetToneArmParam(long p_hHandle, const long p_nCameraId, const ST_ToneArmParam* p_pstToneArmParam);
long SN_C_API Remote_System_GetToneArmParam(long p_hHandle, const long p_nCameraId, ST_ToneArmParam* p_pstToneArmParam);

//设置获取扬声器参数
long SN_C_API Remote_System_SetAllLoudhailerParam(long p_hHandle, const ST_AllLoudhailerParam* p_pstAllLoudhailerParam);
long SN_C_API Remote_System_GetAllLoudhailerParam(long p_hHandle, ST_AllLoudhailerParam* p_pstAllLoudhailerParam);
long SN_C_API Remote_System_SetLoudhailerParam(long p_hHandle, const long p_nCameraId, const ST_LoudhailerParam* p_stLoudhailerParam);
long SN_C_API Remote_System_GetLoudhailerParam(long p_hHandle, const long p_nCameraId, ST_LoudhailerParam* p_pstLoudhailerParam);

//获取指定通道制式
long SN_C_API Remote_System_GetCameraVideoSystem(long p_hHandle, const long p_nCameraId, long* p_nVideoSystem);

//设置获取RS485信息
long SN_C_API Remote_System_SetAllRS485Device(long p_hHandle, const ST_AllRS485Param* p_pstAllRS485DeviceParam);
long SN_C_API Remote_System_GetAllRS485Device(long p_hHandle, ST_AllRS485Param* p_pstAllRS485DeviceParam);
long SN_C_API Remote_System_SetRS485Device(long p_hHandle, const long p_nRS485ComId, const ST_RS485Param* p_pstRS485Device);
long SN_C_API Remote_System_GetRS485Device(long p_hHandle, const long p_nRS485ComId, ST_RS485Param* p_pstRS485Device);

//设置获取报警输入信息
long SN_C_API Remote_System_SetAllAlarmInDevice(long p_hHandle, const ST_AllAlarmInParam* p_pstAllAlarmInParam);
long SN_C_API Remote_System_GetAllAlarmInDevice(long p_hHandle, ST_AllAlarmInParam* p_pstAllAlarmInParam);
long SN_C_API Remote_System_SetAlarmInDevice(long p_hHandle, const long p_nAlarmInId, const ST_AlarmInParam* p_pstAlarmInParam);
long SN_C_API Remote_System_GetAlarmInDevice(long p_hHandle, const long p_nAlarmInId, ST_AlarmInParam* p_pstAlarmInParam);

//设备获取报警输出信息
long SN_C_API Remote_System_SetAllAlarmOutDevice(long p_hHandle, const ST_AllAlarmOutParam* p_pstAllAlarmOutParam);
long SN_C_API Remote_System_GetAllAlarmOutDevice(long p_hHandle, ST_AllAlarmOutParam* p_pstAllAlarmOutParam);
long SN_C_API Remote_System_SetAlarmOutDevice(long p_hHandle, const long p_nAlarmOutId, const ST_AlarmOutParam* p_pstAlarmOutParam);
long SN_C_API Remote_System_GetAlarmOutDevice(long p_hHandle, const long p_nAlarmOutId, ST_AlarmOutParam* p_pstAlarmOutParam);

//设置获取设备时间
long SN_C_API Remote_System_SetDeviceLongTime(long p_hHandle, const unsigned long p_nDeviceTime);
long SN_C_API Remote_System_SetDeviceTime(long p_hHandle, const unsigned short p_nYear, const unsigned short p_nMonth, 
											const unsigned short p_nDay, const unsigned short p_nHour, 
											const unsigned short p_nMinute, const unsigned short p_nSecond);
long SN_C_API Remote_System_GetDeviceLongTime(long p_hHandle, unsigned long* p_nDeviceTime);
long SN_C_API Remote_System_GetDeviceTime(long p_hHandle, unsigned short * p_nYear, unsigned short * p_nMonth, 
											unsigned short * p_nDay, unsigned short * p_nHour, 
											unsigned short * p_nMinute, unsigned short * p_nSecond);

//设置获取时区
long SN_C_API Remote_System_SetTimeZoneParam(long p_hHandle, const ST_TimeZoneParam* p_pstTimeZoneParam);
long SN_C_API Remote_System_GetTimeZoneParam(long p_hHandle, ST_TimeZoneParam* p_pstTimeZoneParam);
long SN_C_API Remote_System_GetDefaultTimeZoneParam(long p_hHandle, const long p_nTimeZone, ST_TimeZoneParam* p_pstTimeZoneParam);

//设置获取网络信息
long SN_C_API Remote_System_SetHostNetwork(long p_hHandle, const long p_nIPProtoVer, const ST_HostNetworkParam* p_pstHostNetworkParam);
long SN_C_API Remote_System_GetHostNetwork(long p_hHandle, const long p_nIPProtoVer, ST_HostNetworkParam* p_pstHostNetworkParam);

long SN_C_API Remote_System_GetAdslHostNetwork(long p_hHandle, const long p_nIPProtoVer, ST_HostNetworkParam* p_pstHostNetworkParam);

//设置获取端口参数
long SN_C_API Remote_System_SetDevicePort(long p_hHandle, const ST_DevicePortParam* p_pstDevicePortParam);
long SN_C_API Remote_System_GetDevicePort(long p_hHandle, ST_DevicePortParam* p_pstDeviceParam);

//设置获取NTP参数
long SN_C_API Remote_System_SetNTPParam(long p_hHandle, const long p_nIPProtoVer, const ST_NTPParam* p_pstNTPParam);
long SN_C_API Remote_System_GetNTPParam(long p_hHandle, const long p_nIPProtoVer, ST_NTPParam* p_pstNTPParam);

long SN_C_API Remote_System_SetPPPoEParam(long p_hHandle, const ST_PPPoEParam* p_pstPPPoEParam);
long SN_C_API Remote_System_GetPPPoEParam(long p_hHandle, ST_PPPoEParam* p_pstPPPoEParam);

//设置获取DDNS参数
long SN_C_API Remote_System_SetDDNSParam(long p_hHandle, const ST_DDNSParam* p_pstDDNSParam);
long SN_C_API Remote_System_GetDDNSParam(long p_hHandle, ST_DDNSParam* p_pstDDNSParam);

//设置获取FTP参数
long SN_C_API Remote_System_SetFTPParam(long p_hHandle, const long p_nIPProtoVer, const ST_FTPParam* p_pstFTPParam);
long SN_C_API Remote_System_GetFTPParam(long p_hHandle, const long p_nIPProtoVer, ST_FTPParam* p_pstFTPParam);

//设置获取FTP参数
long SN_C_API Remote_System_SetSMTPParam(long p_hHandle, const ST_SMTPParam* p_pstSMTPParam);
long SN_C_API Remote_System_GetSMTPParam(long p_hHandle, ST_SMTPParam* p_pstSMTPParam);

//设置获取OSD参数
long SN_C_API Remote_System_SetAllVideoOSD_V2(long p_hHandle, const ST_AllVideoOSDInfoParam * p_pstAllVideoOSDInfoParam);
long SN_C_API Remote_System_GetAllVideoOSD_V2(long p_hHandle, ST_AllVideoOSDInfoParam * p_pstAllVideoOSDInfoParam);
long SN_C_API Remote_System_SetVideoOSD_V2(long p_hHandle, const long p_nCameraId, const ST_VideoOSDInfoParam* p_pstVideoOSDInfoParam);
long SN_C_API Remote_System_GetVideoOSD_V2(long p_hHandle, const long p_nCameraId, ST_VideoOSDInfoParam* p_pstVideoOSDInfoParam);
long SN_C_API Remote_System_SetAllVideoOSD_V3(long p_hHandle, const ST_AllVideoOSDInfoExParam * p_pstAllVideoOSDInfoParam);
long SN_C_API Remote_System_GetAllVideoOSD_V3(long p_hHandle, ST_AllVideoOSDInfoExParam * p_pstAllVideoOSDInfoParam);
long SN_C_API Remote_System_SetVideoOSD_V3(long p_hHandle, const long p_nCameraId, const ST_VideoOSDInfoExParam* p_pstVideoOSDInfoParam);
long SN_C_API Remote_System_GetVideoOSD_V3(long p_hHandle, const long p_nCameraId, ST_VideoOSDInfoExParam* p_pstVideoOSDInfoParam);

long SN_C_API Remote_System_SetAllVideoOSDFont(long p_hHandle, const ST_AllVideoOSDFontParam* p_pstAllVideoOSDFontParam);
long SN_C_API Remote_System_GetAllVideoOSDFont(long p_hHandle, ST_AllVideoOSDFontParam* p_pstAllVideoOSDFontParam);
long SN_C_API Remote_System_SetVideoOSDFont(long p_hHandle, const long p_nCameraId, const ST_VideoOSDFontParam* p_pstVideoOSDFontParam);
long SN_C_API Remote_System_GetVideoOSDFont(long p_hHandle, const long p_nCameraId, ST_VideoOSDFontParam* p_pstVideoOSDFontParam);

long SN_C_API Remote_System_GetOSDFontAbility(long p_hHandle, ST_OSDFontAbilityParam* p_pstOSDFontAbilityParam);
long SN_C_API Remote_System_GetOSDFormatAbility(long p_hHandle,ST_OSDFormatAbility* p_pstOSDFormatAbility);

//设置通信参数
long SN_C_API Remote_System_SetCommunicationParam(long p_hHandle, const ST_CommunicationParam* p_pstCommunicationParam);
long SN_C_API Remote_System_GetCommunicationParam(long p_hHandle, ST_CommunicationParam* p_pstCommunicationParam);

//设置获取广播参数
long SN_C_API Remote_System_SetBroadcastParam(long p_hHandle, const ST_BroadcastParam* p_pstBroadcastParam);
long SN_C_API Remote_System_GetBroadcastParam(long p_hHandle, ST_BroadcastParam* p_pstBroadcastParam);

//设置获取PTZ参数
long SN_C_API Remote_System_SetAllPTZParam(long p_hHandle, const ST_AllPTZParam* p_pstAllPTZParam);
long SN_C_API Remote_System_GetAllPTZParam(long p_hHandle, ST_AllPTZParam* p_pstPTZParam);

long SN_C_API Remote_System_SetPTZParam(long p_hHandle, const long p_nCameraId, const ST_PTZParam* p_pstPTZParam);
long SN_C_API Remote_System_GetPTZParam(long p_hHandle, const long p_nCameraId, ST_PTZParam* p_pstPTZParam);

long SN_C_API Remote_System_SetIPDomePTZId(long p_hHandle, const int p_nPTZId);
long SN_C_API Remote_System_GetIPDomePTZId(long p_hHandle, int* p_nPTZId);

long SN_C_API Remote_System_GetExternDeviceAbility(long p_hHandle,ST_ExternDeviceAbility* p_stExternDeviceAbility);
long SN_C_API Remote_System_SetPTZKeyboardParam(long p_hHandle, const ST_PTZKeyboardParam* p_pobjPTZKeyboardParam);
long SN_C_API Remote_System_GetPTZKeyboardParam(long p_hHandle, ST_PTZKeyboardParam* p_pobjPTZKeyboardParam);

//设置获取点钞机参数
long SN_C_API Remote_System_SetCashRegistersParam(long p_hHandle, const ST_CashRegistersParam* p_pobjCashRegistersParam);
long SN_C_API Remote_System_GetCashRegistersParam(long p_hHandle, ST_CashRegistersParam* p_pobjCashRegistersParam);

//本地录像接口
long SN_C_API Remote_System_SetRecordFileHead(long p_hHandle, const char * p_pszHeadDate);
long SN_C_API Remote_System_GetRecordFileHead(long p_hHandle, char * p_pszHeadDate);

long SN_C_API Remote_System_SetRecordPolicy(long p_hHandle, const int p_nCameraId, const ST_RecordPolicyParam* p_pstRecordPolicyParam);
long SN_C_API Remote_System_GetRecordPolicy(long p_hHandle, const int p_nCameraId, ST_RecordPolicyParam* p_pstRecordPolicyParam);
long SN_C_API Remote_System_SetAllRecordPolicy(long p_hHandle, const ST_AllRecordPolicyParam* p_pstAllRecordPolicyParam);
long SN_C_API Remote_System_GetAllRecordPolicy(long p_hHandle, ST_AllRecordPolicyParam* p_pstAllRecordPolicyParam);
long SN_C_API Remote_System_SetRecordDirInfo(long p_hHandle, const ST_RecordDirInfoList* p_pstRecordDirInfoList);
long SN_C_API Remote_System_GetRecordDirInfo(long p_hHandle, ST_RecordDirInfoList* p_pstRecordDirInfoList);


//报警接口
//设置报警服务器参数
long SN_C_API Remote_System_SetAlarmServiceParam(long p_hHandle, const long p_nIPProtoVer, const ST_AlarmServiceParam* p_pstAlarmServiceParam);
long SN_C_API Remote_System_GetAlarmServiceParam(long p_hHandle, const long p_nIPProtoVer, ST_AlarmServiceParam* p_pstAlarmServiceParam);

//IO报警
long SN_C_API Remote_System_GetAlarmIOMode(long p_hHandle,ST_AlarmIOMode* p_stAlarmIOMode);
long SN_C_API Remote_System_SetAllAlarmIOEvent(long p_hHandle, const ST_AllAlarmIOEventParam* p_pstAllAlarmIOEventParam);
long SN_C_API Remote_System_GetAllAlarmIOEvent(long p_hHandle, ST_AllAlarmIOEventParam* p_pstAllAlarmIOEventParam);
long SN_C_API Remote_System_SetAlarmIOEvent(long p_hHandle, const long p_nAlarmInId, const ST_AlarmIOEventParam* p_pstAlarmIOEventParam);
long SN_C_API Remote_System_GetAlarmIOEvent(long p_hHandle, const long p_nAlarmInId, ST_AlarmIOEventParam* p_pstAlarmIOEventParam);

//移动侦测报警
long SN_C_API Remote_System_SetAllMotionDetectionEvent(long p_hHandle, const ST_AllMotionDetectionEventParam* p_pstAllMotionDetectionEventParam);   //该接口废弃
long SN_C_API Remote_System_GetAllMotionDetectionEvent(long p_hHandle, ST_AllMotionDetectionEventParam* p_pstAllMotionDetectionEventParam);			 //该接口废弃
long SN_C_API Remote_System_SetMotionDetectionEvent(long p_hHandle, const long p_nCameraId, const ST_MotionDetectionEventParam* p_pstMotionDetectionEventParam);	//该接口废弃 
long SN_C_API Remote_System_GetMotionDetectionEvent(long p_hHandle, const long p_nCameraId, ST_MotionDetectionEventParam* p_pstMotionDetectionEventParam);			//该接口废弃 

long SN_C_API Remote_System_GetAllMotionDetectionEventV2(long p_hHandle, ST_AllMotionDetectionEventParamV2* p_pszMotionDetectionEventV2Vector);
long SN_C_API Remote_System_SetAllMotionDetectionEventV2(long p_hHandle, ST_AllMotionDetectionEventParamV2* p_pszMotionDetectionEventV2Vector);
long SN_C_API Remote_System_SetMotionDetectionEventV2(long p_hHandle,const int p_nCameraId, ST_MotionDetectionEventParamV2* p_pstMotionDetectionEventV2);
long SN_C_API Remote_System_GetMotionDetectionEventV2(long p_hHandle,const int p_nCameraId, ST_MotionDetectionEventParamV2* p_pstMotionDetectionEventV2);

//遮挡报警
long SN_C_API Remote_System_SetAllOcclusionDetectionEvent(long p_hHandle, const ST_AllOcclusionDetectionEventParam* p_pstAllOcclusionDetectionEventParam);
long SN_C_API Remote_System_GetAllOcclusionDetectionEvent(long p_hHandle, ST_AllOcclusionDetectionEventParam* p_pstAllOcclusionDetectionEventParam);
long SN_C_API Remote_System_SetOcclusionDetectionEvent(long p_hHandle, const long p_nCameraId, const ST_OcclusionDetectionEventParam* p_pstOcclusionDetectionEventParam);
long SN_C_API Remote_System_GetOcclusionDetectionEvent(long p_hHandle, const long p_nCameraId, ST_OcclusionDetectionEventParam* p_pstOcclusionDetectionEventParam);

//视频丢失报警
long SN_C_API Remote_System_SetAllVideoLoseDetectionEvent(long p_hHandle, const ST_AllVideoLoseDetectionEventParam* p_pstAllVideoLoseDetectionEventParam);
long SN_C_API Remote_System_GetAllVideoLoseDetectionEvent(long p_hHandle, ST_AllVideoLoseDetectionEventParam* p_pstAllVideoLoseDetectionEventParam);
long SN_C_API Remote_System_SetVideoLoseDetectionEvent(long p_hHandle, const long p_nCameraId, const ST_VideoLoseDetectionEventParam* p_pstVideoLoseDetectionEventParam);
long SN_C_API Remote_System_GetVideoLoseDetectionEvent(long p_hHandle, const long p_nCameraId, ST_VideoLoseDetectionEventParam* p_pstVideoLoseDetectionEventParam);

//磁盘报警
long SN_C_API Remote_System_SetDiskAlarmParam(long p_hHandle, const ST_DiskAlarmParam* p_pstDiskAlarmParam);  //该接口废弃
long SN_C_API Remote_System_GetDiskAlarmParam(long p_hHandle, ST_DiskAlarmParam* p_pstDiskAlarmParam);		//该接口废弃

long SN_C_API Remote_System_SetDiskAlarmParamV2(long p_hHandle, const ST_DiskAlarmParamV2* p_pstDiskAlarmParam);  
long SN_C_API Remote_System_GetDiskAlarmParamv2(long p_hHandle, ST_DiskAlarmParamV2* p_pstDiskAlarmParam);		

long SN_C_API Remote_System_GetNetworkAlarmParam(long p_hHandle,ST_NetworkAlarmParam* p_pstNetworkAlarmParam);
long SN_C_API Remote_System_SetNetworkAlarmParam(long p_hHandle,const ST_NetworkAlarmParam* p_pstNetworkAlarmParam);
	
//手动报警
long SN_C_API Remote_System_ManualAlarm(long p_hHandle, const long p_nAlarmType, const long p_nAlarmSourceId, const ST_AlarmActionStrategy* p_pstAlarmActionStrategy);
long SN_C_API Remote_System_SetAlarmOut(long p_hHandle, const long p_nAlarmDeviceType, const long p_nAlarmOutId, const long p_nAlarmOutFlag);

//报警参数
long SN_C_API Remote_System_SetAlarmParam(long p_hHandle, const ST_AlarmParam* p_pstAlarmParam);
long SN_C_API Remote_System_GetAlarmParam(long p_hHandle, ST_AlarmParam* p_pstAlarmParam);

long SN_C_API Remote_System_SetSnapshotParam(long p_hHandle, const long p_nCameraId, const ST_SnapshotParam* p_pstSnapshotParam);
long SN_C_API Remote_System_GetSnapshotParam(long p_hHandle, const long p_nCameraId, ST_SnapshotParam* p_pstSnapshotParam);
long SN_C_API Remote_System_SetAllSnapshotParam(long p_hHandle, const ST_AllSnapshotParam* p_pstAllSnapshotParam);
long SN_C_API Remote_System_GetAllSnapshotParam(long p_hHandle, ST_AllSnapshotParam* p_pstAllSnapshotParam);

long SN_C_API Remote_System_SetAllAVStreamParam(long p_hHandle, const ST_AllAVStreamParam* p_pstAllStreamParam);
long SN_C_API Remote_System_GetAllAVStreamParam(long p_hHandle, ST_AllAVStreamParam* p_pstAllStreamParam);
long SN_C_API Remote_System_SetAllCameraAVStreamParam(long p_hHandle, const long p_nCameraId, const ST_AllAVStreamParam* p_pstAllStreamParam);
long SN_C_API Remote_System_GetAllCameraAVStreamParam(long p_hHandle, const long p_nCameraId, ST_AllAVStreamParam* p_pstAllStreamParam);
long SN_C_API Remote_System_SetAVStreamParam(long p_hHandle, const long p_nCameraId, const long p_nStreamId, const ST_AVStreamParam* p_pstAllStreamParam);
long SN_C_API Remote_System_GetAVStreamParam(long p_hHandle, const long p_nCameraId, const long p_nStreamId, ST_AVStreamParam* p_pstAllStreamParam);
long SN_C_API Remote_System_GetStreamURI(long p_hHandle, const long p_nCameraId, const long p_nStreamId, char* p_pszStreamURI, const long p_nInputLen, long* p_nOutputLen);
long SN_C_API Remote_System_GetStreamURIEx(long p_hHandle, const long p_nCameraId, const long p_nStreamId, const long p_nRtspTransferProtocol, char* p_pszStreamURI, const long p_nInputLen, long* p_nOutputLen);

//查询录像文件接口
long SN_C_API Remote_System_QueryRecord(long p_hHandle, const ST_RecordQueryCondition* p_pstRecordQueryCondition);
long SN_C_API Remote_System_GetRecordQueryResultCount(long p_hHandle, long* p_nRecordQueryResultCount);
long SN_C_API Remote_System_GetRecordQueryResult(long p_hHandle, const long p_nIndex,ST_RecordQueryResult* p_pstRecordQueryResult);
long SN_C_API Remote_System_ClearRecordQueryResult(long p_hHandle);

long SN_C_API Remote_System_QueryRecordV2(long p_hHandle, const ST_RecordQueryConditionV2* p_pstRecordQueryCondition);
long SN_C_API Remote_System_GetRecordQueryResultCountV2(long p_hHandle, long* p_nRecordQueryResultCount);
long SN_C_API Remote_System_GetRecordQueryResultV2(long p_hHandle, const long p_nIndex,ST_RecordQueryResultV2* p_pstRecordQueryResult);
long SN_C_API Remote_System_ClearRecordQueryResultV2(long p_hHandle);

//查询系统日志接口
long SN_C_API Remote_System_QuerySystemLog(long p_hHandle, const ST_LogRequestParam* p_pstLogRequestParam);
long SN_C_API Remote_System_GetSystemLogCount(long p_hHandle, long * p_nLogInfoCount);
long SN_C_API Remote_System_GetSystemLog(long p_hHandle, const long p_nIndex,ST_LogInfo* p_pstLogInfo);
long SN_C_API Remote_System_ClearSystemLogQueryResult(long p_hHandle);

long SN_C_API Remote_System_QuerySystemLogV2(long p_hHandle, const ST_LogRequestParamV2* p_pstLogRequestParam);
long SN_C_API Remote_System_GetSystemLogCountV2(long p_hHandle, long * p_nLogInfoCount);
long SN_C_API Remote_System_GetSystemLogV2(long p_hHandle, const long p_nIndex,ST_LogInfoV2* p_pstLogInfo);
long SN_C_API Remote_System_ClearSystemLogQueryResultV2(long p_hHandle);

//报警日志
long SN_C_API Remote_System_QueryAlarmLog(long p_hHandle, const ST_AlarmInfoExQueryParam* p_pstAlarmInfoQueryParam);
long SN_C_API Remote_System_GetAlarmLogCount(long p_hHandle, long* p_nAlarmInfoCount);
long SN_C_API Remote_System_GetAlarmLog(long p_hHandle, const long p_nIndex, ST_AlarmInfoExRecordSet* p_pstAlarmInfoRecordSet);
long SN_C_API Remote_System_ClearAlarmLogQueryResult(long p_hHandle);

//隐私遮蔽接口
long SN_C_API Remote_System_SetBlindAreaParam(long p_hHandle, const long p_nCameraId, const ST_BlindAreaParam* p_pstBlindAreaParam);
long SN_C_API Remote_System_GetBlindAreaParam(long p_hHandle, const long p_nCameraId, ST_BlindAreaParam* p_pstBlindAreaParam);
long SN_C_API Remote_System_SetAllBlindAreaParam(long p_hHandle, const ST_AllBlindAreaParam* p_pstAllBlindAreaParam);
long SN_C_API Remote_System_GetAllBlindAreaParam(long p_hHandle, ST_AllBlindAreaParam* p_pstAllBlindAreaParam);
long SN_C_API Remote_System_GetBlindAreaAbility(long p_hHandle, ST_BlindAbilityV2* p_pstBlindAbilityV2);

//Decoder
long SN_C_API Remote_System_GetWindowMode(long p_hHandle, int* p_pnWindowMode);
long SN_C_API Remote_System_SetWindowMode(long p_hHandle, const int p_nWindowMode);

//wifi
long SN_C_API Remote_System_GetWifiHotspotParam(long p_hHandle,ST_WifiHotspotParamList* p_pstWifiHotspotParamList);
long SN_C_API Remote_System_GetWifiParam(long p_hHandle,ST_WifiParam* p_pstWifiParam);
long SN_C_API Remote_System_SetWifiParam(long p_hHandle,const ST_WifiParam* p_pszWifiParam);
long SN_C_API Remote_System_GetWifiStateParam(long p_hHandle,ST_WifiStateParam* p_pstWifiStateParam);
long SN_C_API Remote_System_GetWifiAbilityParam(long p_hHandle,ST_WifiAbilityParam* p_pstWifiAbilityParam);
long SN_C_API Remote_System_GetWifiNetworkParam(long p_hHandle,ST_WifiNetworkParam* p_pstWifiNetworkParam);

//伴随流
long SN_C_API Remote_System_SetSVCStreamParam(long p_hHandle, const long p_nCameraID, const long p_nStreamId,const ST_SVCStreamParam* p_pstSVCStreamParam);
long SN_C_API Remote_System_GetSVCStreamParam(long p_hHandle, const long p_nCameraID, const long p_nStreamId,ST_SVCStreamParam* p_pstSVCStreamParam);

//Sensor 
long SN_C_API Remote_System_GetSensorAbility(long p_hHandle,ST_SensorAbility* p_pstSensorAbility);

long SN_C_API Remote_System_SetPTZTimer(long p_hHandle, const long p_nCameraID, ST_PTZTimer* p_stPTZTimer);
long SN_C_API Remote_System_GetPTZTimer(long p_hHandle, const long p_nCameraID, ST_PTZTimer* p_stPTZTimer);
long SN_C_API Remote_System_SetAllPTZTimer(long p_hHandle, const ST_PTZTimerList* p_stPTZTimerList);
long SN_C_API Remote_System_GetAllPTZTimer(long p_hHandle, ST_PTZTimerList* p_pstPTZTimerList);


long SN_C_API Remote_System_SetMTUParam(long p_hHandle,ST_MTUParam *p_pstMTUParam);
long SN_C_API Remote_System_GetMTUParam(long p_hHandle,ST_MTUParam *p_pstMTUParam);

//智能分析
long SN_C_API Remote_System_GetIntelligenceAnalyseAbility(long p_hHandle,ST_IntelligenceAnalyseAbility* p_pstIntelligenceAnalyseAbility);

long SN_C_API Remote_System_SetPerimeterParam(long p_hHandle,ST_PerimeterParam* p_pstPerimeterParam);
long SN_C_API Remote_System_GetPerimeterParam(long p_hHandle,ST_PerimeterParam* p_pstPerimeterParam);

long SN_C_API Remote_System_SetTripWireParam(long p_hHandle,ST_TripWireParam* p_pstTripWireParam);
long SN_C_API Remote_System_GetTripWireParam(long p_hHandle,ST_TripWireParam* p_pstTripWireParam);

long SN_C_API Remote_System_SetMultiTripWireParam(long p_hHandle,ST_MultiTripWireParam* p_pstMultiTripWireParam);
long SN_C_API Remote_System_GetMultiTripWireParam(long p_hHandle,ST_MultiTripWireParam* p_pstMultiTripWireParam);

long SN_C_API Remote_System_SetLoiterParam(long p_hHandle,ST_LoiterParam* p_objLoiterParam);
long SN_C_API Remote_System_GetLoiterParam(long p_hHandle,ST_LoiterParam* p_objLoiterParam);

long SN_C_API Remote_System_SetMultiLoiterParam(long p_hHandle,ST_MultiLoiterParam* p_pstMultiLoiterParam);
long SN_C_API Remote_System_GetMultiLoiterParam(long p_hHandle,ST_MultiLoiterParam* p_pstMultiLoiterParam);

long SN_C_API Remote_System_SetObjectLeftParam(long p_hHandle,ST_ObjectLeftParam* p_pstObjectLeftParam);
long SN_C_API Remote_System_GetObjectLeftParam(long p_hHandle,ST_ObjectLeftParam* p_pstObjectLeftParam);

long SN_C_API Remote_System_SetObjectMovedParam(long p_hHandle,ST_ObjectMovedParam* p_pstObjectMovedParam);
long SN_C_API Remote_System_GetObjectMovedParam(long p_hHandle,ST_ObjectMovedParam* p_pstObjectMovedParam);

long SN_C_API Remote_System_SetAbnormalSpeedParam(long p_hHandle,ST_AbnormalSpeedParam* p_pstAbnormalSpeedParam);
long SN_C_API Remote_System_GetAbnormalSpeedParam(long p_hHandle,ST_AbnormalSpeedParam* p_pstAbnormalSpeedParam);

long SN_C_API Remote_System_SetConverseParam(long p_hHandle,ST_ConverseParam* p_pstConverseParam);
long SN_C_API Remote_System_GetConverseParam(long p_hHandle,ST_ConverseParam* p_pstConverseParam);

long SN_C_API Remote_System_SetNoParkingParam(long p_hHandle,ST_NoParkingParam* p_pstNoParkingParam);
long SN_C_API Remote_System_GetNoParkingParam(long p_hHandle,ST_NoParkingParam* p_pstNoParkingParam);

long SN_C_API Remote_System_SetMotionDetectionParamV3(long p_hHandle,ST_MotionDetectionParamV3* p_pstMotionDetectionParamV3);
long SN_C_API Remote_System_GetMotionDetectionParamV3(long p_hHandle,ST_MotionDetectionParamV3* p_pstMotionDetectionParamV3);

long SN_C_API Remote_System_SetCameraTamperParam(long p_hHandle,ST_CameraTamperParam* p_pstCameraTamperParam);
long SN_C_API Remote_System_GetCameraTamperParam(long p_hHandle,ST_CameraTamperParam* p_pstCameraTamperParam);

long SN_C_API Remote_System_SetCameraMovedParam(long p_hHandle,ST_CameraMovedParam* p_pstCameraMoveParam);
long SN_C_API Remote_System_GetCameraMovedParam(long p_hHandle,ST_CameraMovedParam* p_pstCameraMoveParam);

long SN_C_API Remote_System_SetAdvancedParam(long p_hHandle,ST_AdvancedParam* p_pstAdvancedParam);
long SN_C_API Remote_System_GetAdvancedParam(long p_hHandle,ST_AdvancedParam* p_pstAdvancedParam);

long SN_C_API Remote_System_SetSignalBadParam(long p_hHandle,ST_SignalBadParam* p_pstSignalBadParam);
long SN_C_API Remote_System_GetSignalBadParam(long p_hHandle,ST_SignalBadParam* p_pstSignalBadParam);

long SN_C_API Remote_System_AddBlindAreaParamV2(long p_hHandle,const int p_nCameraId, ST_BlindAreaParamV2* p_stBlindAreaParamV2);
long SN_C_API Remote_System_ModifyBlindAreaParamV2(long p_hHandle,const int p_nCameraId, ST_BlindAreaParamV2* p_stBlindAreaParamV2);
long SN_C_API Remote_System_DeleteBlindAreaParamV2(long p_hHandle,const int p_nCameraId, ST_BlindAreaParamV2* p_stBlindAreaParamV2);
long SN_C_API Remote_System_GetAllBlindAreaParamV2(long p_hHandle,const int p_nCameraId, ST_AllBlindAreaParamV2* p_stBlindAreaParamV2List);
long SN_C_API Remote_System_DeleteAllBlindAreaParamV2(long p_hHandle,const int p_nCameraId);
long SN_C_API Remote_System_GetBlindAreaParamV2(long p_hHandle,const int p_nCameraId, const int p_nAreaParamV2ID, ST_BlindAreaParamV2* p_stBlindAreaParamV2);
long SN_C_API Remote_System_GotoBlindAreaParamV2(long p_hHandle,const int p_nCameraId, const int p_nAreaParamV2ID);

//鱼眼设备参数配置
//{
long SN_C_API Remote_System_SetFisheyeDewarpParam(long p_hHandle,const int p_nCameraID, ST_FisheyeDewarpModeParam* p_stFisheyeDewarpParam);
long SN_C_API Remote_System_GetFisheyeDewarpParam(long p_hHandle,const int p_nCameraID, ST_FisheyeDewarpModeParam* p_stFisheyeDewarpParam);
long SN_C_API Remote_System_GetFisheyeVideoLayout(long p_hHandle,const int p_nCameraId, ST_FisheyeVideoLayout* p_stFisheyeVideoLayout);
long SN_C_API Remote_System_SetFisheyeMountparam(long p_hHandle,ST_FisheyeMountParam* p_stFisheyeMountParam);
long SN_C_API Remote_System_GetFisheyeMountparam(long p_hHandle,ST_FisheyeMountParam* p_stFisheyeMountParam);
long SN_C_API Remote_System_GetFisheyeAbility(long p_hHandle,ST_FisheyeAbility* p_stFisheyeAbility);
//}

long SN_C_API Remote_Snapshot_SetTimeout(long p_hHandle, const int p_nTimeout);
long SN_C_API Remote_Snapshot_Open(long p_hHandle);
long SN_C_API Remote_Snapshot_Close(long p_hHandle);
long SN_C_API Remote_Snapshot_GetSnapshotPicture(long p_hHandle, ST_RemoteSnapshotParam* p_pstRemoteSnapshotParam, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_Snapshot_GetSnapshotPictureV2(long p_hHandle, ST_RemoteSnapshotParam* p_pstRemoteSnapshotParam, ST_AVFrameData* p_pstAVFrameData);


//CMS C Interface(CMS服务初始化和反初始化，调用CMS_*函数时需调用以下两个函数初始化和反初始化）
long SN_C_API CMS_Init(long* p_hHandle);
long SN_C_API CMS_UnInit(long p_hHandle);

//CMSAlarmCenter C Interface(报警接收）
long SN_C_API CMS_AlarmCenter_setListenAddr(long p_hHandle, const ST_InetAddr* p_stInetAddr);
long SN_C_API CMS_AlarmCenter_setAlarmCallback(long p_hHandle, long (CALLBACK* fAlarmCallback)(long p_hHandle, ST_AlarmInfo* p_stAlarmInfo, void* pUserData), void* pUserData); //接口废弃
long SN_C_API CMS_AlarmCenter_setAlarmCallbackEx(long p_hHandle, long (CALLBACK* fAlarmCallback)(long p_hHandle, ST_AlarmInfoEx* p_stAlarmInfo, void* pUserData), void* pUserData); //接口废弃
long SN_C_API CMS_AlarmCenter_setAlarmCallbackExV2(long p_hHandle, long (CALLBACK* fAlarmCallback)(long p_hHandle, ST_AlarmInfoExV2* p_stAlarmInfo, void* pUserData), void* pUserData);
long SN_C_API CMS_AlarmCenter_open(long p_hHandle);
long SN_C_API CMS_AlarmCenter_close(long p_hHandle);

long SN_C_API CMS_AlarmCenter2_setAlarmCallbackEx(long p_hHandle, long (CALLBACK* fAlarmCallback)(long p_hHandle, ST_AlarmInfoEx* p_stAlarmInfo, void* pUserData), void* pUserData); //接口废弃
long SN_C_API CMS_AlarmCenter2_setAlarmCallbackExV2(long p_hHandle, long (CALLBACK* fAlarmCallback)(long p_hHandle, ST_AlarmInfoExV2* p_stAlarmInfo, void* pUserData), void* pUserData);

long SN_C_API CMS_AlarmCenter2_setMessageCallback(long p_hHandle, long (CALLBACK* fMessageCallback)(long p_hHandle, const char * p_szDeviceIP ,
										  const char * p_szDeviceId,const int p_nMessageID,void* pUserData) ,void* pUserData);

long SN_C_API CMS_AlarmCenter2_AddDeviceInfo(long p_hHandle, const ST_DeviceInfoEx * p_stDeviceInfo);

//按设备id来删除接口废弃 
long SN_C_API CMS_AlarmCenter2_RemoveDeviceInfo(long p_hHandle, const char * p_szDeviceId);

long SN_C_API CMS_AlarmCenter2_RemoveDeviceInfoByInetAddr(long p_hHandle, const ST_InetAddr *p_stInetAddr);
long SN_C_API CMS_AlarmCenter2_RemoveAll(long p_hHandle);
long SN_C_API CMS_AlarmCenter2_open(long p_hHandle);
long SN_C_API CMS_AlarmCenter2_close(long p_hHandle);

//CMSDeviceSearcher C Interface(设备广播搜索）
long SN_C_API CMS_DeviceSearcher_SetListenAddr(long p_hHandle, const ST_InetAddr* p_stInetAddr);
long SN_C_API CMS_DeviceSearcher_SetDeviceFilterFlag(long p_hHandle,  const unsigned char bFlag);
long SN_C_API CMS_DeviceSearcher_SetDeviceInfoCallback(long p_hHandle, 
											  long (CALLBACK* fSearchCallback)(long p_hHandle, ST_NetVideoDeviceInfo* p_pstNetVideoDeviceInfo, void* pUserData), 
											  void* pUserData);
long SN_C_API CMS_DeviceSearcher_Start(long p_hHandle);
long SN_C_API CMS_DeviceSearcher_Stop(long p_hHandle);

//CMSDeviceSearcherEx C Interface(设备主动搜索）
long SN_C_API CMS_DeviceSearcherEx_SetDevicePort(long p_hHandle, const unsigned short p_nPort = 30001);
long SN_C_API CMS_DeviceSearcherEx_SetDeviceFilterFlag(long p_hHandle, const bool p_bFlag);
long SN_C_API CMS_DeviceSearcherEx_SetSearchCount(long p_hHandle, const int p_nSearchCount);
long SN_C_API CMS_DeviceSearcherEx_SetSearchInterval(long p_hHandle, const int p_nSearchInterval);
long SN_C_API CMS_DeviceSearcherEx_AddSearchDeviceIPRange(long p_hHandle, const char* p_szDeviceIPBegin, const char* p_szDeviceIPEnd);
long SN_C_API CMS_DeviceSearcherEx_ClearSearchDeviceIP(long p_hHandle);
long SN_C_API CMS_DeviceSearcherEx_SetDeviceInfoCallback(long p_hHandle, 
													   long (CALLBACK* fSearchCallback)(long p_hHandle, ST_NetVideoDeviceInfo* p_pstNetVideoDeviceInfo, void* pUserData), 
													   void* pUserData);
long SN_C_API CMS_DeviceSearcherEx_Start(long p_hHandle);
long SN_C_API CMS_DeviceSearcherEx_Stop(long p_hHandle);

//CMSDeviceOnlineService C Interface(设备在线服务）
//设置监听者
long SN_C_API CMS_DeviceOnlineService_SetDeviceInfoCallback(long p_hHandle, 
															long (CALLBACK* fDeviceInfoCallBack)(long p_hHandle, ST_DeviceBaseInfo* p_pstDeviceBaseInfo, void* pUserData), 
															void* pUserData);
long SN_C_API CMS_DeviceOnlineService_SetDeviceStateCallback(long p_hHandle, 
															 long (CALLBACK* fDeviceInfoCallBack)(long p_hHandle, ST_DeviceStateInfo* p_pstDeviceStateInfo, void* pUserData), 
															 void* pUserData);
void SN_C_API CMS_DeviceOnlineService_SetIPProtoVer(long p_hHandle, const int p_nIPProtoVer);

//广播需调用接口
//设置是否使用广播
void SN_C_API CMS_DeviceOnlineService_SetUseBroadcastFlag(long p_hHandle, const unsigned char p_bFlag);
void SN_C_API CMS_DeviceOnlineService_SetBroadcastListenAddr(long p_hHandle, const ST_InetAddr* p_pstListenAddr);

//主动搜索需调用接口
long SN_C_API CMS_DeviceOnlineService_AddSearchDeviceAddr1(long p_hHandle, const char* p_szDeviceIPBegin, const char* p_szDeviceIPEnd, const int p_nSearchPort);
long SN_C_API CMS_DeviceOnlineService_AddSearchDeviceAddr2(long p_hHandle, const char* p_szDeviceIP, const int p_nSearchPort);
long SN_C_API CMS_DeviceOnlineService_AddSearchDeviceAddr3(long p_hHandle, const ST_InetAddr* p_pstInetAddr);
long SN_C_API CMS_DeviceOnlineService_Start(long p_hHandle);
void SN_C_API CMS_DeviceOnlineService_Stop(long p_hHandle);
long SN_C_API CMS_DeviceOnlineService_FindDeviceStateInfo(long p_hHandle, const char* p_pszDeviceId, ST_DeviceStateInfo* p_pstDeviceStateInfo);



#if (defined(WIN32)&&!defined(_WIN32_WCE))
	//RemoteAudioBroadcast C Interface(远程语音广播服务初始化和反初始化，调用Remote_AudioBroadcast_*函数时需调用以下两个函数初始化和反初始化）
	long SN_C_API Remote_AudioBroadcast_Init(long* p_hHandle);
	long SN_C_API Remote_AudioBroadcast_UnInit(long p_hHandle);

	void SN_C_API Remote_AudioBroadcast_SetEncoderType(long p_hHandle, const int p_nEncoderType);
	long SN_C_API Remote_AudioBroadcast_AddBroadcastDevice(long p_hHandle, const ST_DeviceInfoEx* p_stDeviceInfo, const int p_nAudioChannel = 1);
	long SN_C_API Remote_AudioBroadcast_Start(long p_hHandle);
	void SN_C_API Remote_AudioBroadcast_Stop(long p_hHandle);
	void SN_C_API Remote_AudioBroadcast_RemoveBroadcastDevice(long p_hHandle, const char* p_pszDeviceId, const int p_nAudioChannel = 1);
#endif //end WIN32

#ifdef RECORD_INTERFACE
//CMS录像接口
long SN_C_API CMS_RecordCenter_Init(long* p_hHandle);
long SN_C_API CMS_RecordCenter_UnInit(long p_hHandle);
long SN_C_API CMS_RecordCenter_SetRecordDirInfoList(long p_hHandle, const ST_RecordDirInfoList* p_stRecordDirInfoList);
long SN_C_API CMS_RecordCenter_OpenRecord(long p_hHandle, const char* p_pszDeviceId, const char* p_pszDeviceIp, int p_nCameraId, int p_nDiskGroupId, int p_nSaveDays, long* p_hRecorderHandle);
long SN_C_API CMS_RecordCenter_CloseRecord(long p_hHandle, const char* p_pszDeviceId, const char* p_pszDeviceIp, int p_nCameraId);
long SN_C_API CMS_RecordCenter_CloseRecordEx(long p_hHandle, long p_hRecorderHandle);
long SN_C_API CMS_RecordCenter_CloseAllRecord(long p_hHandle);
bool SN_C_API CMS_RecordCenter_IsRecording(long p_hHandle, const char* p_pszDeviceId, const char* p_pszDeviceIp, int p_nCameraId);
//录像写接口，此次使用的p_hRecordHandle是调用CMS_RecordCenter_OpenRecord返回的p_hRecordHandle
long SN_C_API CMS_Recorder_Write(long p_hRecorderHandle, ST_AVFrameData* p_pstAVFrameData);

//CMS录像接口V2
long SN_C_API CMS_RecordCenterV2_Init(long* p_hHandle);
long SN_C_API CMS_RecordCenterV2_UnInit(long p_hHandle);
long SN_C_API CMS_RecordCenterV2_SetRecordDirInfoList(long p_hHandle, const ST_RecordDirInfoList* p_stRecordDirInfoList);
long SN_C_API CMS_RecordCenterV2_OpenRecord(long p_hHandle, const ST_DeviceInfoEx* p_stDeviceInfoEx, const int p_nCameraId, const int p_nStreamId, const int p_nDiskGroupId = 1, const int p_nSaveDays = -1);
long SN_C_API CMS_RecordCenterV2_CloseRecord(long p_hHandle, const char* p_pszDeviceId, const char* p_pszDeviceIp, int p_nCameraId);
long SN_C_API CMS_RecordCenterV2_CloseAllRecord(long p_hHandle);
bool SN_C_API CMS_RecordCenterV2_IsRecording(long p_hHandle, const char* p_pszDeviceId, const char* p_pszDeviceIp, int p_nCameraId);


//录像查询接口
long SN_C_API CMS_RecordSearcher_Init(long* p_hHandle);
long SN_C_API CMS_RecordSearcher_UnInit(long p_hHandle);
long SN_C_API CMS_RecordSearcher_SetRecordDirInfoList(long p_hHandle, const ST_RecordDirInfoList* p_stRecordDirInfoList);
long SN_C_API CMS_RecordSearcher_QueryRecord(long p_hHandle, const ST_RecordQueryCondition* p_pstRecordQueryCondition);
long SN_C_API CMS_RecordSearcher_GetRecordQueryResultCount(long p_hHandle, long* p_nRecordQueryResultCount);
long SN_C_API CMS_RecordSearcher_GetRecordQueryResult(long p_hHandle, const long p_nIndex,ST_RecordQueryResult* p_pstRecordQueryResult);
long SN_C_API CMS_RecordSearcher_ClearRecordQueryResult(long p_hHandle);
long SN_C_API CMS_RecordSearcher_QueryRecordV2(long p_hHandle, const ST_RecordQueryConditionV2* p_pstRecordQueryCondition);
long SN_C_API CMS_RecordSearcher_GetRecordQueryResultCountV2(long p_hHandle, long* p_nRecordQueryResultCount);
long SN_C_API CMS_RecordSearcher_GetRecordQueryResultV2(long p_hHandle, const long p_nIndex,ST_RecordQueryResultV2* p_pstRecordQueryResult);
long SN_C_API CMS_RecordSearcher_ClearRecordQueryResultV2(long p_hHandle);

//录像读取接口
long SN_C_API CMS_RecordRetriever_Init(long* p_hHandle);
long SN_C_API CMS_RecordRetriever_UnInit(long p_hHandle);
long SN_C_API CMS_RecordRetriever_SetRecordDirInfoList(long p_hHandle, const ST_RecordDirInfoList* p_stRecordDirInfoList);
long SN_C_API CMS_RecordRetriever_Open(long p_hHandle, const ST_RecordInfo* p_stRecordInfo);	//接口废弃
long SN_C_API CMS_RecordRetriever_OpenV2(long p_hHandle, const ST_RecordInfoV2* p_stRecordInfo);
long SN_C_API CMS_RecordRetriever_Close(long p_hHandle);
long SN_C_API CMS_RecordRetriever_Read(long p_hHandle, char *p_szAVData,int p_nDataLength);
long SN_C_API CMS_RecordRetriever_LocateTime(long p_hHandle, unsigned long p_nTime);
long SN_C_API CMS_RecordRetriever_LocateNextIFrame(long p_hHandle);
long SN_C_API CMS_RecordRetriever_LocatePreIFrame(long p_hHandle);
#endif

#if (defined(WIN32)&&!defined(_WIN32_WCE))
	//本地录像回放接口
	long SN_C_API Local_PlayBack_Init(long* p_hHandle);
	long SN_C_API Local_PlayBack_UnInit(long p_hHandle);
	long SN_C_API Local_PlayBack_SetRecordDirInfoList(long p_hHandle, const ST_RecordDirInfoList* p_stRecordDirInfoList);
	long SN_C_API Local_PlayBack_SetStretchMode(long p_hHandle, const bool p_bStretchMode);
	long SN_C_API Local_PlayBack_SetAutoResizeFlag(long p_hHandle, const bool p_bAutoResizeFlag = true);
	long SN_C_API Local_PlayBack_SetNotifyWindow(long p_hHandle, const unsigned long p_nNotifyWnd, const unsigned long p_nMessage, const void* p_pParam);
	long SN_C_API Local_PlayBack_SetVideoWindow(long p_hHandle, const unsigned long p_hDisplayWnd, const long x, const long y, const long width, const long height);
	long SN_C_API Local_PlayBack_Open(long p_hHandle, ST_RecordInfo* p_stRecordInfo);	//接口废弃
	long SN_C_API Local_PlayBack_OpenV2(long p_hHandle, ST_RecordInfoV2* p_stRecordInfo);
	long SN_C_API Local_PlayBack_Close(long p_hHandle);
	long SN_C_API Local_PlayBack_Play(long p_hHandle);
	long SN_C_API Local_PlayBack_Pause(long p_hHandle);
	long SN_C_API Local_PlayBack_Stop(long p_hHandle);
	long SN_C_API Local_PlayBack_ResizeWindow(long p_hHandle, const long x, const long y, const long width, const long height);
	long SN_C_API Local_PlayBack_Refresh(long p_hHandle);
	long SN_C_API Local_PlayBack_GetPlayStatus(long p_hHandle, long* p_nPlayStatus);
	long SN_C_API Local_PlayBack_PlayNextFrame(long p_hHandle);
	long SN_C_API Local_PlayBack_PlayPreviousFrame(long p_hHandle);
	long SN_C_API Local_PlayBack_PlaySound(long p_hHandle);
	long SN_C_API Local_PlayBack_StopSound(long p_hHandle);
	long SN_C_API Local_PlayBack_IsOnSound(long p_hHandle, bool* p_bOnSound);
	long SN_C_API Local_PlayBack_SetVolume(long p_hHandle, const long p_nVolume);
	long SN_C_API Local_PlayBack_GetVolume(long p_hHandle, long* p_nVolume);
	long SN_C_API Local_PlayBack_GetPlayPosByTime(long p_hHandle, unsigned long* p_nDuration);
	long SN_C_API Local_PlayBack_SetPlayPosByTime(long p_hHandle, const unsigned long p_nDuration);
	long SN_C_API Local_PlayBack_SetRate (long p_hHandle, const float p_nRate);
	long SN_C_API Local_PlayBack_GetRate(long p_hHandle, float& p_nRate );
	long SN_C_API Local_PlayBack_SetBrightness(long p_hHandle, const unsigned long p_nValue);
	long SN_C_API Local_PlayBack_GetBrightness(long p_hHandle, unsigned long* p_nValue);
	long SN_C_API Local_PlayBack_SetContrast(long p_hHandle, const unsigned long p_nValue);
	long SN_C_API Local_PlayBack_GetContrast(long p_hHandle, unsigned long* p_nValue);
	long SN_C_API Local_PlayBack_SetHue(long p_hHandle, const unsigned long p_nValue);
	long SN_C_API Local_PlayBack_GetHue(long p_hHandle, unsigned long* p_nValue);
	long SN_C_API Local_PlayBack_SetSaturation(long p_hHandle, const unsigned long p_nValue);
	long SN_C_API Local_PlayBack_GetSaturation(long p_hHandle, unsigned long* p_nValue);
	long SN_C_API Local_PlayBack_ResetPictureAdjustFilter(long p_hHandle);
	long SN_C_API Local_PlayBack_GetPictureSize(long p_hHandle, long* p_nWidth, long* p_nHeight);
	long SN_C_API Local_PlayBack_SnapShot(long p_hHandle, const char* p_pszFileName);
	long SN_C_API Local_PlayBack_ZoomInVideoEx(long p_hHandle, const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height);
	long SN_C_API Local_PlayBack_ZoomInVideo(long p_hHandle);
	long SN_C_API Local_PlayBack_ZoomOutVideo(long p_hHandle);
	long SN_C_API Local_PlayBack_RestoreVideo(long p_hHandle);

	long SN_C_API Local_PlayBack_SetRecorderFile(long p_hHandle, const char* p_pszFileName);
	long SN_C_API Local_PlayBack_SetRecordFileFormat(long p_hHandle, const int p_nFileFormat);
	long SN_C_API Local_PlayBack_SetRecordFileHead(long p_hHandle, const char* p_pszRecordFileHead, const int p_nRecordFileLength);
	long SN_C_API Local_PlayBack_StartRecord(long p_hHandle);
	long SN_C_API Local_PlayBack_StopRecord(long p_hHandle);
	long SN_C_API Local_PlayBack_GetRecorderStatus(long p_hHandle, long* p_nStatus);
#endif //end WIN32

//手动录像接口，在使用手动录像C接口之前必须调用Manual_Recorder_Init初始化函数，使用完后应当调用Manual_Recorder_UnInit释放环境
long SN_C_API Manual_Recorder_Init(long* p_handle, const ST_DeviceInfoEx* p_stDeviceInfo, const int p_nCameraId, const int p_nStreamId, const int p_nTransferProtocol);
long SN_C_API Manual_Recorder_SetRecordAudioFlag(long p_hHandle, const bool p_bFlag);
long SN_C_API Manual_Recorder_SetRecordFileName(long p_hHandle, const char* p_pszRecordFileName);
long SN_C_API Manual_Recorder_SetMessageCallback(long p_hHandle, 
														 long (CALLBACK* fRecordMessageCallback)(long p_hHandle, const int p_nMessageID, void* pUserData), 
														 void* pUserData);
long SN_C_API Manual_Recorder_StartRecord(long p_hHandle);
long SN_C_API Manual_Recorder_StopRecord(long p_hHandle);
long SN_C_API Manual_Recorder_UnInit(long p_hHandle);

//解码器接口
long SN_C_API Remote_Decoder_Init(long* p_handle, const ST_DeviceInfoEx* p_stDeviceInfo, const int p_nWindowID);
long SN_C_API Remote_Decoder_UnInit(long p_hHandle);
long SN_C_API Remote_Decoder_Open(long p_hHandle);
long SN_C_API Remote_Decoder_Decode(long p_hHandle, ST_AVFrameData* p_pstAVFrameData);
long SN_C_API Remote_Decoder_Close(long p_hHandle);

//////////////////////////////////TS解包器////////////////////////////////////////
	/************************************************************************
	**概述：
	*		初始化TS解包器。
	**输入：
	*		
	**输出：
	*		hHandle：解包器句柄。
	**返回值：
	*		执行成功返回0，输出句柄； 错误时返回错误码。
	**功能：
	*		
	************************************************************************/
	long SN_C_API TSUnpackager_Init( long* p_hHandle );

	/************************************************************************
	**概述：
	*		释放TS解包器环境。
	**输入：
	*		hHandle：解包器句柄。
	**输出：
	*		无。
	**返回值：
	*		执行成功返回0，错误时返回错误码。
	**功能：
	*		在使用完TS解包器后，必须调用该函数释放编解码器
	************************************************************************/
	long SN_C_API TSUnpackager_Uninit(long p_hHandle);

	/************************************************************************
	**概述：
	*		输入TS音视频流
	**输入：
	*		p_objTSAVData：TS数据流。
	*		p_nDataLen：流数据大小，单位为字节。
	**输出：
	*		
	**返回值：
	*		SN_SUCCESS：成功。
	*		SN_ERROR_QUEUE_FULL：缓冲队列满，需要重新调用接口塞入数据。
	**功能：
	*
	************************************************************************/
	long SN_C_API TSUnpackager_InputTSData(long p_hHandle, const char* p_szTSData, const unsigned int p_nDataLen);

	/************************************************************************
	**概述：
	*		设置解包回调函数,当UnpackageCallBack设置NULL时取消回调。
	**输入：
	*		hHandle：回调函数参数。当UnpackageCallBack执行，回传该参数。一个32位整形值，当没有句柄时可以设置NULL
	*		fUnpackageCallBack：解包回调函数。
	**输出：
	*		无。
	**返回值：
	*		执行成功返回0，错误时返回错误码。
	**功能：
	************************************************************************/
	long SN_C_API TSUnpackager_SetUnpackageCallBack( long p_hHandle, 
		long ( CALLBACK * fUnpackageCallBack ) ( long p_hHandle, NVDC_STRUCT::ST_AVFrameData* pAVFrameData, void* pUserData), void* pUserData);



	//////////////////////////////////PS解包器////////////////////////////////////////
	/************************************************************************
	**概述：
	*		初始化PS解包器。
	**输入：
	*		
	**输出：
	*		hHandle：解包器句柄。
	**返回值：
	*		执行成功返回0，输出句柄； 错误时返回错误码。
	**功能：
	*		
	************************************************************************/
	long SN_C_API PSUnpackager_Init( long* p_hHandle );

	/************************************************************************
	**概述：
	*		释放PS解包器环境。
	**输入：
	*		hHandle：解包器句柄。
	**输出：
	*		无。
	**返回值：
	*		执行成功返回0，错误时返回错误码。
	**功能：
	*		在使用完PS解包器后，必须调用该函数释放编解码器
	************************************************************************/
	long SN_C_API PSUnpackager_Uninit(long p_hHandle);

	/************************************************************************
	**概述：
	*		输入PS音视频流
	**输入：
	*		p_objPSAVData：PS数据流。
	*		p_nDataLen：流数据大小，单位为字节。
	**输出：
	*		
	**返回值：
	*		SN_SUCCESS：成功。
	*		SN_ERROR_QUEUE_FULL：缓冲队列满，需要重新调用接口塞入数据。
	**功能：
	*
	************************************************************************/
	long SN_C_API PSUnpackager_InputPSData(long p_hHandle, const char* p_szPSData, const unsigned int p_nDataLen);

	/************************************************************************
	**概述：
	*		设置解包回调函数,当UnpackageCallBack设置NULL时取消回调。
	**输入：
	*		hHandle：回调函数参数。当UnpackageCallBack执行，回传该参数。一个32位整形值，当没有句柄时可以设置NULL
	*		fUnpackageCallBack：解包回调函数。
	**输出：
	*		无。
	**返回值：
	*		执行成功返回0，错误时返回错误码。
	**功能：
	************************************************************************/
	long SN_C_API PSUnpackager_SetUnpackageCallBack( long p_hHandle, 
		long ( CALLBACK * fUnpackageCallBack ) ( long p_hHandle, NVDC_STRUCT::ST_AVFrameData* pAVFrameData, void* pUserData), void* pUserData);


	/************************************************************************
	**概述：
	*		初始化PS解包器。
	**输入：
	*		
	**输出：
	*		hHandle：解包器句柄。
	**返回值：
	*		执行成功返回0，输出句柄； 错误时返回错误码。
	**功能：
	*		
	************************************************************************/
	long SN_C_API PSUnpackagerV2_Init( long* p_hHandle );

	/************************************************************************
	**概述：
	*		释放PS解包器环境。
	**输入：
	*		hHandle：解包器句柄。
	**输出：
	*		无。
	**返回值：
	*		执行成功返回0，错误时返回错误码。
	**功能：
	*		在使用完PS解包器后，必须调用该函数释放编解码器
	************************************************************************/
	long SN_C_API PSUnpackagerV2_Uninit(long p_hHandle);

	//设置数据帧的格式，1：原始流，4：ps流
	long SN_C_API PSUnpackagerV2_SetFrameDataFormat(long p_hHandle, const int p_nFormat);

	//使用数据标志，false：返回的帧数据没有视频数据，true：返回的帧数据里携带视频数据
	long SN_C_API PSUnpackagerV2_SetUseDateFlag(long p_hHandle, const bool p_bFlag);

	/************************************************************************
	**概述：
	*		输入PS音视频流
	**输入：
	*		p_objPSAVData：PS数据流。
	*		p_nDataLen：流数据大小，单位为字节。
	**输出：
	*		
	**返回值：
	*		SN_SUCCESS：成功。
	*		SN_ERROR_QUEUE_FULL：缓冲队列满，需要重新调用接口塞入数据。
	**功能：
	*
	************************************************************************/
	long SN_C_API PSUnpackagerV2_InputPSData(long p_hHandle, const char* p_szPSData, const unsigned int p_nDataLen);

	/************************************************************************
	**概述：
	*		输入PS音视频流
	**输入：
	*		p_objPSAVData：PS数据流。
	*		p_nDataLen：流数据大小，单位为字节。
	**输出：
	*		
	**返回值：
	*		SN_SUCCESS：成功。
	*		SN_ERROR_QUEUE_FULL：缓冲队列满，需要重新调用接口塞入数据。
	**功能：
	*
	************************************************************************/
	long SN_C_API PSUnpackagerV2_GetNextAVFrameData(long p_hHandle, NVDC_STRUCT::ST_AVFrameData* p_pstAVFrameData);


	/************************************************************************
	**概述：
	*		初始化PS解包器。
	**输入：
	*		
	**输出：
	*		hHandle：解包器句柄。
	**返回值：
	*		执行成功返回0，输出句柄； 错误时返回错误码。
	**功能：
	*		
	************************************************************************/
	long SN_C_API PSUnpackagerV3_Init( long* p_hHandle );

	/************************************************************************
	**概述：
	*		释放PS解包器环境。
	**输入：
	*		hHandle：解包器句柄。
	**输出：
	*		无。
	**返回值：
	*		执行成功返回0，错误时返回错误码。
	**功能：
	*		在使用完PS解包器后，必须调用该函数释放编解码器
	************************************************************************/
	long SN_C_API PSUnpackagerV3_Uninit(long p_hHandle);

	//设置数据帧的格式，1：原始流，4：ps流
	long SN_C_API PSUnpackagerV3_SetFrameDataFormat(long p_hHandle, const int p_nFormat);

	//使用数据标志，false：返回的帧数据没有视频数据，true：返回的帧数据里携带视频数据
	long SN_C_API PSUnpackagerV3_SetUseDateFlag(long p_hHandle, const bool p_bFlag);

	/************************************************************************
	**概述：
	*		输入PS音视频流
	**输入：
	*		p_objPSAVData：PS数据流。
	*		p_nDataLen：流数据大小，单位为字节。
	**输出：
	*		
	**返回值：
	*		SN_SUCCESS：成功。
	*		SN_ERROR_QUEUE_FULL：缓冲队列满，需要重新调用接口塞入数据。
	**功能：
	*
	************************************************************************/
	long SN_C_API PSUnpackagerV3_InputPSData(long p_hHandle, const char* p_szPSData, const unsigned int p_nDataLen);

	/************************************************************************
	**概述：
	*		输入PS音视频流
	**输入：
	*		p_objPSAVData：PS数据流。
	*		p_nDataLen：流数据大小，单位为字节。
	**输出：
	*		
	**返回值：
	*		SN_SUCCESS：成功。
	*		SN_ERROR_QUEUE_FULL：缓冲队列满，需要重新调用接口塞入数据。
	**功能：
	*
	************************************************************************/
	long SN_C_API PSUnpackagerV3_GetNextAVFrameData(long p_hHandle, NVDC_STRUCT::ST_AVFrameData* p_pstAVFrameData);

} //namespace
#ifdef __cplusplus 
}
#endif //__cplusplus 
#endif
