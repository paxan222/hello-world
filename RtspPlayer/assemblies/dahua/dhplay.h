/************************************************************************/
/* dhplay   Version:  3.34			                                    */
/************************************************************************/

#ifndef _DHPLAY_H
#define _DHPLAY_H

#if (defined(WIN32) || defined(WIN64))
	#ifdef dhplay_EXPORTS
		#define PLAYSDK_API __declspec(dllexport)
	#else
		#define PLAYSDK_API __declspec(dllimport)
	#endif
	#define CALLMETHOD __stdcall
	#define CALLBACK   __stdcall
#else
	#define CALLMETHOD
	#define CALLBACK
	#define PLAYSDK_API //extern "C"
#endif

#if defined(WIN32) || defined(WIN64)
#include <windows.h>
#else
#define BOOL		int
#define BYTE		unsigned char
#define PBYTE		BYTE*
#define LPBYTE		BYTE*
#ifndef LONG
#define LONG		long
#endif
#ifndef DWORD
#define DWORD		unsigned long
#endif
#define WORD		unsigned short
#define COLORREF	DWORD
#define HDC			void*
#define HWND		void*
#define LPSTR		char*
#define UINT		unsigned int
#define TRUE		1
#define FALSE		0

typedef struct _SYSTEMTIME
{
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;
#endif

typedef struct _tagRECT
{
	LONG left;
	LONG top;
	LONG right;
	LONG bottom;
}DISPLAYRECT;

#ifdef	__cplusplus
extern "C" {
#endif

/************************************************************************/
/* Macro Definition			                                                    */
/************************************************************************/

#define  FUNC_MAX_PORT					501		//max play channel amount

#define MIN_WAVE_COEF					-100	
#define MAX_WAVE_COEF					100		

#define TIMER_1							1		//Default timer. Accurate time. Support max 16 in one progress
#define TIMER_2							2		//Thread timer. No amount limit.

#define BUF_VIDEO_SRC					1		//Video source buffer
#define BUF_AUDIO_SRC					2		//Audio source buffer
#define BUF_VIDEO_RENDER				3		//Video data buffer after decoding
#define BUF_AUDIO_RENDER				4		//Audio data buffer after decoding

#define MAX_DISPLAY_WND					4		//Support max 4 zones in one time

#define DISPLAY_NORMAL					1		// In normal resolution
#define DISPLAY_QUARTER					2		//In 1/4 resolution

#define MAX_DIS_FRAMES					50		//Max decode buffer amount
#define MIN_DIS_FRAMES					6		//Mim decode buffer amount

#define BY_FRAMENUM						1		//In accordance with frame number
#define BY_FRAMETIME					2		//In accordance with time

#define SOURCE_BUF_MAX					1024*100000	//Max original buffer
#define SOURCE_BUF_MIN					1024*50		//Mim original buffer

#define STREAME_REALTIME				0		//The real-time has the highest priority
#define STREAME_FILE					1		//The fluency has the highest priority

#define T_AUDIO16						101		
#define T_AUDIO8						100		

#define T_UYVY							1		
#define T_IYUV							3		
#define T_RGB32							7		

#define SUPPORT_DDRAW					1		//Support DIRECTDRAW. If not, player can not work
#define SUPPORT_BLT						2		//Display card support BLT operation. If not, player cannot work
#define SUPPORT_BLTFOURCC				4		//Display card BLT supports color switch
#define SUPPORT_BLTSHRINKX				8		//Display car BLT supports X axis zoom out
#define SUPPORT_BLTSHRINKY				16		//Display card BLT supports Y axis zoom out
#define SUPPORT_BLTSTRETCHX				32		//Display card BLT supports X axis zoom in
#define SUPPORT_BLTSTRETCHY				64		//Display card BLT supports Y axis zoom in
#define SUPPORT_SSE						128		//CPU support SSE command,Intel Pentium3 or higher support SSE command
#define SUPPORT_MMX						256		//CPU support MMX instruction set

#define PLAY_CMD_GetTime				1		
#define PLAY_CMD_GetFileRate			2		
#define PLAY_CMD_GetMediaInfo			3		
#define PLAY_CMD_GetRenderNum			4		
#define PLAY_CMD_GetRenderTime			5		
#define PLAY_CMD_GetSrcTime				6

#define AVI_MEDIACHANGE_FRAMERATE		1		
#define AVI_MEDIACHANGE_RESOLUTION		2		

#define WATERMARK_DATA_TEXT				0		
#define WATERMARK_DATA_JPEG_BMP			1		
#define WATERMARK_DATA_FRAMEDATA		3		

#define	DH_PLAY_NOERROR					0		// No error
#define DH_PLAY_PARA_OVER				1		//Illegal input parameter
#define DH_PLAY_ORDER_ERROR				2		//Callabck sequence is not right
#define DH_PLAY_TIMER_ERROR				3		// Failed to set multiple-media setup
#define DH_PLAY_DEC_VIDEO_ERROR			4		//Failed to decode video
#define DH_PLAY_DEC_AUDIO_ERROR			5		//Failed to decode audio
#define DH_PLAY_ALLOC_MEMORY_ERROR		6		//Failed to allocate meomory
#define DH_PLAY_OPEN_FILE_ERROR			7		//file operation failed
#define DH_PLAY_CREATE_OBJ_ERROR		8		//Failed to create thread events
#define DH_PLAY_CREATE_DDRAW_ERROR		9		//Failed to create directDraw
#define DH_PLAY_CREATE_OFFSCREEN_ERROR	10		//Failed to create back-end buffer
#define DH_PLAY_BUF_OVER				11		//Buffer is full. Input stream failed
#define DH_PLAY_CREATE_SOUND_ERROR		12		//Failed to create audio device
#define DH_PLAY_SET_VOLUME_ERROR		13		//Failed to set volume
#define DH_PLAY_SUPPORT_FILE_ONLY		14		//Become valid when play file
#define DH_PLAY_SUPPORT_STREAM_ONLY		15		//Become valid when play stream
#define DH_PLAY_SYS_NOT_SUPPORT			16		//System does not support. Decoder can work in Pentium 3 or higher
#define DH_PLAY_FILEHEADER_UNKNOWN		17		//No file head
#define DH_PLAY_VERSION_INCORRECT		18		//Decoder and encoder version are not compatilble
#define DH_PLAY_INIT_DECODER_ERROR		19		//Failed to initialize decoder
#define DH_PLAY_CHECK_FILE_ERROR		20		//File is too short or bit stream can not be recognized
#define DH_PLAY_INIT_TIMER_ERROR		21		//Failed to initialize MMTimer
#define DH_PLAY_BLT_ERROR				22		//Bit copy failed
#define DH_PLAY_UPDATE_ERROR			23		//Failed to display overlay
#define DH_PLAY_MEMORY_TOOSMALL			24		//memory too small

/************************************************************************/
/*struct                                                            */
/************************************************************************/

typedef enum __tPicFormats
{
	PicFormat_BMP = 0,						//BMP 32bit
	PicFormat_JPEG,							//JPEG
	PicFormat_JPEG_70,						//70% JPEG
	PicFormat_JPEG_50,						//50% JPEG
	PicFormat_JPEG_30,						//30% JPEG
	PicFormat_JPEG_10,						//10% JPEG
	PicFormat_BMP24,						//BMP 24bit
	PicFormat_TIFF							//TIFF
} tPicFormats;

typedef struct
{
	LONG			nFilePos;				//Specify the frame offset position in the file
	LONG			nFrameLen;				//Frame length
	LONG			nFrameNum;				//Frame serial number
	LONG			nFrameTime;				//Frame time
	LONG			nErrorFrameNum;			//Error frame number
	SYSTEMTIME*		pErrorTime;				//Error frame time
	LONG			nErrorLostFrameNum;		//Error frame number
	LONG			nErrorFrameSize;		//Error frame size
}FRAME_POS,*PFRAME_POS;

typedef struct
{
	LONG			nWidth;					//Width, unit is pixel, 0 for audio data.
	LONG			nHeight;				//height, 0 for audio data
	LONG			nStamp;					//Time stamp info, unit is ms
	LONG			nType;					//Video frame type,T_AUDIO16,T_RGB32,T_IYUV
	LONG			nFrameRate;				//Image frame rate created during encoding
}FRAME_INFO;

typedef struct
{
	#define FRAME_TYPE_VIDEO 0				//Video Frame
	#define FRAME_TYPE_AUDIO 1				//Audio Frame
	int				nFrameType;				//Frame Type
	int				nFrameSeq;				//Frame serial number
	int				nStamp;					//Frame time ,MilliSecond
	int				nWidth;					//Width, unit is pixel, 0 for audio data.
	int 			nHeight;				//height, 0 for audio data.
	int				nFrameRate;				// Image frame rate created during encoding
	int				nChannels;				//Audio Channel No.
	int				nBitPerSample;			//Audio Sampling Bit
	int				nSamplesPerSec;			//Audio Sampling Frequency
	int				nRemainData;			//Remain data of internal buffer
	SYSTEMTIME		nDataTime;				//Frame time, year/month.   
	int				nReserved[59];			//Reserved
}FRAME_INFO_EX;

typedef struct 
{
	int				nFrameType;					//Frame type, definition as FRAME_INFO_EX nFrameType text
	
	void*			pAudioData;				//Audio data if it is audio frame
	int				nAudioDataLen;			//Audio Data Length

	void*			pVideoData[3];			//as YUV components
	int				nStride[3];				//as spacing among YUV components
	int				nWidth[3];				//as width of YUV components
	int				nHeight[3];				//as height of YUV components
	int				nReserved[64];			//Reserved Text
}FRAME_DECODE_INFO;

typedef struct 
{
	int			lWidth;					
	int			lHeight;				
	int			lFrameRate;				
	int			lChannel;				
	int			lBitPerSample;			
	int			lSamplesPerSec;			
}MEDIA_INFO;

typedef struct 
{
	char*			pDataBuf;				//Frame data
	LONG			nSize;					//Frame size
	LONG			nFrameNum;				//Frame serial number
	BOOL			bIsAudio;				//Audio frame or not
	LONG			nReserved;				//Reserved character
}FRAME_TYPE;


/************************************************************************/
/*  Interface Definition	                                                            */
/************************************************************************/

//------------------------------------------------------------------------
// Function:	PLAY_OpenFile
// Description: Open file
// Parameter:	nPort,Port number
//		 sFileName,File name, The file size ranges from 4G to 4K
// Returns:		BOOL,TRUE--succeeded FALSE--failed
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OpenFile(LONG nPort,LPSTR sFileName);

//------------------------------------------------------------------------
// Function:	PLAY_CloseFile
// Description: Close played file, call after PLAY_Stop
// Parameter:	nPort,Port number
// Returns:		BOOL,TRUE--succeeded FALSE--failed
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CloseFile(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_OpenStream
// Description: Open stream interface (Just the same as open a file)
// Parameter: nPort,Port number
//		 pFileHeadBuf,It is not avialbale now. Please input NULL
//		 nSize,It is not avialbale now.Please input 0
//		 nBufPoolSize,Set storage data stream buffer size in the playe 
//			The value ranges is 
//			[SOURCE_BUF_MIN,SOURCE_BUF_MAX]. Usually it is 900*1024. Please increase the value if the data are not even
// Returns:		BOOL,TRUE--succeeded FALSE--failed
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OpenStream(LONG nPort,PBYTE pFileHeadBuf,DWORD nSize,DWORD nBufPoolSize);

//------------------------------------------------------------------------
// Function:	PLAY_CloseStream
// Description: close data stream (just the same as close file), call after PLAY_Stop
// Parameter: nPort,Port number
// Returns:		BOOL,TRUE--succeeded FALSE--failed
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CloseStream(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_Play
// Description: Start play. If it is playing, then return current play status to normal speed
// Parameter: nPort,Port number
//		 hWnd,Play window handle
// Returns:		BOOL,TRUE--succeeded FALSE--failed
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Play(LONG nPort, HWND hWnd);

//------------------------------------------------------------------------
// Function:	PLAY_Stop
// Description: Stop Play
// Parameter: nPort,Port number
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Stop(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_InputData
// Description: Input the stream data you get from the card. Enable stream and Then call PLAY_Play to input data
// Parameter: nPort,Port number
//		 pBuf,Buffer address
//		 nSize,Buffer size
// Returns:		BOOL,TRUE--succeeded FALSE--failed.There is no data. Usually the buffer is full
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_InputData(LONG nPort,PBYTE pBuf,DWORD nSize);

//------------------------------------------------------------------------
// Function:	PLAY_Pause
// Description: Pause/resume
// Parameter: nPort,Port number
//		 nPause,TRUE Pause,FLASE Resume
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Pause(LONG nPort,DWORD nPause);

//------------------------------------------------------------------------
// Function:	PLAY_Fast
// Description: Fast play. There are 9 levels. The speeds are 1, 3, 6, 12, 25, 50, 75, 100, 125f/s respectively. 
//		The speed escalates one level and support max 4 times in one callback.
//		You can call PLAY_Play to resume normal playback from current position
// Parameter: nPort,Port number
// Returns:		BOOL,TRUE--succeeded FALSE--failed
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Fast(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_Slow
// Description: Slow play. The same as the above. Each time the speed lowers one level. 
//		Support max callback 4 times. Pleae call PLAY_Play to resume normal play
// Parameter: nPort,Port number
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Slow(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_OneByOne
// Description: Play frame by frame. Please call PLAY_ Play to resume normal playback
// Parameter:	nPort,Port number
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OneByOne(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_SetPlayPos
// Description: Set relative position of file play pointer (unit :%)
// Parameter: nPort,Port number
//		 fRelativePos,The value ranges is [0, 100%]
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayPos(LONG nPort,float fRelativePos);

//------------------------------------------------------------------------
// Function: PLAY_SetPlayDirection
// Description: Set play direction
// Parameter: nPort,Port number
//		 emDirection,Play direction:0,Forward ,1,BackWard
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayDirection(LONG nPort, DWORD emDirection);

//------------------------------------------------------------------------
// Function:	PLAY_GetPlayPos
// Description: Get the relative position of the file player pointer.
// Parameter:	nPort,Port number
// Returns:		float,The value ranges is [0, 100%]
//------------------------------------------------------------------------
PLAYSDK_API float CALLMETHOD PLAY_GetPlayPos(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_SetFileEndMsg
// Description: Set the message to be sent when the end of the file is encountered
// Parameter: nPort,Port number
//       hWnd,The window to receive the message
//       nMsg,User defined message. When the end of the file is encountered, user may receive this message in the window process.
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileEndMsg(LONG nPort,HWND hWnd,UINT nMsg);

//------------------------------------------------------------------------
// Function:	PLAY_SetVolume
// Description: Set volume.
// Parameter: nPort,Port number
//		 nVolume,Volume value. The value ranges is [0, 0XFFFF]
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetVolume(LONG nPort,WORD nVolume);

//------------------------------------------------------------------------
// Function:	PLAY_StopSound
// Description: Disable audio
// Parameter: 
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopSound();

//------------------------------------------------------------------------
// Function:	PLAY_PlaySound
// Description: Enable audio. There is only 1-ch audio in one time. System auto 
//		disables previous audio if current audio is enabled. 
//		Please note audio is disabled by default

// Parameter: nPort,Port number
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_PlaySound(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_GetFileTime
// Description: Get file total time length. Unit is second
// Parameter:	nPort,Port number
// Returns:		Total file time.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetFileTime(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_GetPlayedTime
// Description: Get file played time. Unit is second
// Parameter: nPort,Port number
// Returns:		The file current played time
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetPlayedTime(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_GetPlayedFrames
// Description: Get the video frame amount that has been decoded
// Parameter:	nPort,Port number
// Returns:		The video frame amount that have been decoded
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetPlayedFrames(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_SetDecodeCallBack
// Description: Set callback function. It is to replace the displayed section in the player. You can control the displayed video.
//	Please call this function before PLAY_Play. This function becomes null when calling PLAY_Stop. 
//	You need to reset when you call PLAY_Play the next time.The decode section does not control speed. 
//	When you return from the callback function, the decoder will decode the next data. Please note before using this function; 
//	you need to fully understand the video display and audio play. Otherwise, do not use this function casually!
// Parameter: nPort,Port number
//		 cbDec,Callback function pointer. It can not be null
//			nPort,Port number
//			pFrameDecodeInfo,Audio and video data after decoding
//			pFrameInfo,Image and audio information. Please refer to the following information
//			pUser,User defined parameter
// Returns:  	BOOL, TRUE--succeeded  FALSE--failed.
//------------------------------------------------------------------------
typedef void (CALLBACK* fCBDecode)(LONG nPort, FRAME_DECODE_INFO* pFrameDecodeInfo, FRAME_INFO_EX* pFrameInfo, void* pUser);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecodeCallBack(LONG nPort, fCBDecode cbDec, void* pUser);

//------------------------------------------------------------------------
//------------------------------------------------------------------------
// Function:	PLAY_SetDisplayCallBack
// Description: Set video data callback. It can be used to snapshoot. You can set callback function
//		pointer of DisplayCBFun as null to stop callback. The callback function is valid all the time 
//		once it is set, until the program exits. You can call this function at any time
// Parameter: nPort,Port number
//		 DisplayCBFun,Video data callback function. It can be null
//			nPort,Port number
//			pBuf,Video data buffer
//			nSize,video data size
//			nWidth,Image width. Unit is pixel
//			nHeight,Image height
//			nStamp,Time mark information. Unit is ms
//			nType,Data type. T_RGB32, T_UYVY. Please refer to macro definition
//			nReceaved,Reserved
//		 nUser,User-customized parameter
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
typedef void (CALLBACK* fDisplayCBFun)(LONG nPort,char * pBuf,LONG nSize,LONG nWidth,LONG nHeight,LONG nStamp,LONG nType, void* pReserved);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDisplayCallBack(LONG nPort, fDisplayCBFun DisplayCBFun, void* pUserData);

//------------------------------------------------------------------------
// Function:	PLAY_ConvertToBmpFile
// Description: Save the snapshoot image as BMP file.This switch will occupy CPU resources. Do not call this 
//			function if you do not need to save image
// Parameter: pBuf,Image data buffer
//		 nSize,Image data size
//		 nWidth,Image width. Unit is pixel
//		 nHeight,Image height
//		 nType,Data type. T_RGB32, T_UYVY. Please refer to macro definition
//		 sFileName,File name. The file extension name is BMP
// Returns:		BOOL,TRUE--succeeded  FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ConvertToBmpFile(char * pBuf,LONG nSize,LONG nWidth,LONG nHeight,LONG nType, char *sFileName);

//------------------------------------------------------------------------
// Function:	PLAY_ConvertToJpegFile
// Description: Convert YUV image data to jpeg format.
// Parameter: pYUVBuf,Image data buffer
//		 nWidth,Image width
//		 nHeight,Image height
//		 YUVtype,YUV data type. T_YV12,T_UYVY, ex.
//		 quality,Compress quality, (0, 100]
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ConvertToJpegFile(char *pYUVBuf, LONG nWidth, LONG nHeight, int YUVtype, int quality, char *sFileName);

//------------------------------------------------------------------------
// Function:	PLAY_GetFileTotalFrames
// Description: Get total frame count
// Parameter:	nPort,Port number
// Returns:		DWORD,Total frame count
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetFileTotalFrames(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_GetCurrentFrameRate
// Description: get encode frame rate in current bit stream
// Parameter:	nPort,Port number
// Returns:		DWORD,Frame rate value when encoding current bit stream
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetCurrentFrameRate(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_GetPlayedTimeEx
// Description: Get file played time. Unit is ms
// Parameter:	nPort,Port number
// Returns:		DWORD,The file current played time
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetPlayedTimeEx(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_SetPlayedTimeEx
// Description: Set file play position according to the time. This interface takes a little bit longer 
//				than the PLAY_SetPlayPos. But use time to control progress bar (working with PLAY_GetPlayedTime(Ex))
//				to make the progress bar smoothly
// Parameter:	nPort,Port number
//				nTime,Set the file play postion to the specified time. Unit is ms
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayedTimeEx(LONG nPort,DWORD nTime);

//------------------------------------------------------------------------
// Function:	PLAY_GetCurrentFrameNum
// Description: Get current play frame serial number. PLAY_GetPlayedFrames is the total frame amount. If 
//		the play position is the same, the return values of these two functions shall be very close, 
//		unless data loss occurs
// Parameter:	nPort,Port number
// Returns:		Current play frame number.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetCurrentFrameNum(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_SetStreamOpenMode
// Description: Set stream play mode. You need to set before playing
// Parameter:	nPort,Port number
//				nMode,STREAME_REALTIME Real-time mode (default);STREAME_FILE File mode.Real-time mode. It is suitable for network real-time mode.The
//						deocder card will begin decoding right now
//						File mode. It is suitable for you to input file data as stream
//						when PLAY_InputData() return FALSE, you need to wait and then input again.

// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetStreamOpenMode(LONG nPort,DWORD nMode);

//------------------------------------------------------------------------
// Function:	PLAY_GetSdkVersion
// Description: Get player SDK main version, sub-version and pack No.
// Parameter: 
// Returns: The higher 16-bit represents current main version.9-16 represents sub-version. 1-8-bit represents sub-pack number.
//		For example:return value is 0x00030107 then you can see: main version is 3, sub-version is 1 and pack number is 7.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetSdkVersion();

//------------------------------------------------------------------------
// Function:	PLAY_GetLastError
// Description: Get current error code. You can call this function to get error code if you fail to call one function
// Parameter: nPort,Port number
// Returns:		DWORD,Refer to Error type
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetLastError(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_RefreshPlay
// Description: Refresh to display. If you refresh when player is in pause mode, the window video 
//		disappears. You can call this interface to get the video agaian. It is valid in pause and frame 
//		by frame playback mode. System will return directly in other situations
// Parameter: nPort,Port number
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_RefreshPlay(LONG nPort);
// Function:	PLAY_GetPictureSize
// Description: Get the original image size from the bit stream and then adjust display window accordingly. 
//		It does not need display card to support zoom function. It is very useful for those display cards 
//		that does not support hardware zoom
// Parameter: nPort,Port number
//		 pWidth,Width of the original image. In PAL format CIF resolution it is 352
//		pHeight Height of the original image. In PAL format CIF resolution, the value is 288
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------

PLAYSDK_API BOOL CALLMETHOD PLAY_GetPictureSize(LONG nPort,LONG *pWidth,LONG *pHeight);

//------------------------------------------------------------------------
// Function:	PLAY_SetPicQuality
// Description: Set video quality. When it is in high quality the video is vivid, but the CPU comsuption 
//		is high. When system is in multiple-channel play mode, you can set a little bit lower quality so
//		as to lower CPU comsuption. When you want to see one window in large zone, you can set it to high
//		quality to get excellent video effect
// Parameter: nPort,Port number
//		 bHighQuality,The video quality is the best when it is 1.The video quality is the lowest when it is o (default value.)
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPicQuality(LONG nPort,BOOL bHighQuality);

//------------------------------------------------------------------------
// Function:	PLAY_PlaySoundShare
// Description: Play audio in share way. Play current channel audio while not disabling audio from other channels
// Parameter: nPort,Port number
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_PlaySoundShare(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_StopSoundShare
// Description: Disable audio in share way. PLAY_PlaySound and PLAY_StopSound are enable audio in 
//		exclusive way. Please note, in one progress, all channels are required to use
//		same way to enable or disable audio
// Parameter: nPort,Port number
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopSoundShare(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_GetStreamOpenMode
// Description: Get stream mode type
// Parameter:	nPort,Port number
// Returns:		LONG,STREAME_REALTIME or STREAME_FILE.
//------------------------------------------------------------------------
PLAYSDK_API LONG CALLMETHOD PLAY_GetStreamOpenMode(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_GetVolume
// Description: To get current volume setup.
// Parameter: nPort,Port number
// Returns:		WORD,To get current volume value
//------------------------------------------------------------------------
PLAYSDK_API WORD CALLMETHOD PLAY_GetVolume(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_GetPictureQuality
// Description: Get current video quality
// Parameter:	nPort,Port number
//				bHighQuality TRUE high quality,FALSE low quality.
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPictureQuality(LONG nPort,BOOL *bHighQuality);

//------------------------------------------------------------------------
// Function:	PLAY_GetSourceBufferRemain
// Description: Get sourcing buffer remained data in stream play mode
// Parameter:	nPort,Port number
// Returns:		DWORD,Current sourcing buffer size(byte)
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetSourceBufferRemain(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_ResetSourceBuffer
// Description: Clear the remained data in sourcing buffer in stream play mode
// Parameter: nPort,Port number
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ResetSourceBuffer(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_OneByOneBack
// Description: Playback frame by frame. Each callback will return one frame.
//		You can call this function after creating the file index
// Parameter: nPort,Port number
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OneByOneBack(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_SetFileRefCallBack
// Description: Set callback function pointer. Callback when establishing callback. To locate quickly 
//		and accurately, system generates a file index when opening a file. This period may take a little 
//		bit long. Its speed is about 40M/s, mainly because reading data from the HDD is slow. The index 
//		establishment is operated in the background. The functions that need to use this index have to 
//		wait until this process ends, while the other interfaces may not be affected
// Parameter: nPort,Port number
//		 pFileRefDone,Callback function pointer
//			nPort,Port number
//			nUser,User data
//		 nUser,User data
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
typedef void(CALLBACK *fpFileRefDoneCBFun)(DWORD nPort, void* pUserData);									
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileRefCallBack(LONG nPort,
													fpFileRefDoneCBFun pFileRefDoneCBFunc,
													void* pUserData);

//------------------------------------------------------------------------
// Function:	PLAY_SetCurrentFrameNum
// Description: Specify the frame number in current position. Locate the play position according to the 
//				frame number. The function need to be called back after creating the file index
// Parameter:	nPort,Port number
//				nFrameNum,Frame number
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetCurrentFrameNum(LONG nPort,DWORD nFrameNum);

//------------------------------------------------------------------------
// Function:	PLAY_GetKeyFramePos
// Description: Search I frame postion before the specified postion. The video decode begins from I frame.
//		If the saved file is not from I frame, then the data to the next I frame will be ignored. If you 
//		need to get data from the file, you?��e better get from I frame. But the end postion does not matter
//		since you may lose max 3 frames data.
// Parameter:	nPort,Port number
//				nValue,Current position. It can be time or frame number. Its type is appointed by nType
//				nType,Specify nValue type
//					If nType is BY_FRAMENUM, then nValue means frame number
//					If nType is BY_FRAMTIME, then nValue means time and unit is ms

//				pFramePos,I frame position information struct pointer.,?��??PFRAME_POS.
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PFRAME_POS pFramePos);

//------------------------------------------------------------------------
// Function:	PLAY_GetNextKeyFramePos
// Description: Search I frame positon after the specified location
// Parameter: nPort,Port number
//		 nValue,Current position. It can be time or frame number. Its type is appointed by nType.
//		 nType,Specify nValue type
//			If nType is BY_FRAMENUM, then nValue means frame number
//			If nType is BY_FRAMTIME, then nValue means time and unit is ms
//		 pFramePos,I frame position information struct pointer.
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetNextKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PFRAME_POS pFramePos);


//------------------------------------------------------------------------
// Function: PLAY_SetDecCBStream
// Description: Set callback stream type when decoding
// Parameter: nPort,Port number
//		 nStream,1 Video stream;2 Audio stream;3 Composite stream.
// Returns: BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecCBStream(LONG nPort,DWORD nStream);

//------------------------------------------------------------------------
// Function:	PLAY_SetDisplayRegion
// Description: Set or add displayed zone. Support partial enlargement
// Parameter: nPort,Port number
//		 nRegionNum,Display zone serial number. 
//				0~(MAX_DISPLAY_WND-1). 
//				If nRegionNum is 0, it means the main display window
//		 pSrcRect,Partial displayed zone
//		 hDestWnd,Display window handle
//		 bEnable,Open (set) or close displayed zone
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDisplayRegion(LONG nPort,DWORD nRegionNum, DISPLAYRECT *pSrcRect, HWND hDestWnd, BOOL bEnable);


//------------------------------------------------------------------------
// Function:	PLAY_GetRefValue
// Description: To get file index information so that you can use the information directly when you open
//		the same file the next itme. You need to create index to get information
// Parameter:	nPort,Port number
//				pBuffer,Index information
//				pSize,Input pBuffer size, output index information size.
//					Note: you can first set pSize=0,pBuffer=NULL, get the buffer size from the return value 
//					of pSize and then allocate the enough buffer.Then you can callback again 
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetRefValue(LONG nPort,BYTE *pBuffer, DWORD *pSize);

//------------------------------------------------------------------------
// Function:	PLAY_SetRefValue
// Description: Set file index. If there is file index, you do not need to call callback function 
//		(PLAY_SetFileRefCallBack) and then directly input index information. Please note index 
//		information and its length must be accurate
// Parameter:	nPort,Port number
//				pBuffer,Index information
//				nSize,Index information length
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetRefValue(LONG nPort,BYTE *pBuffer, DWORD nSize);

//------------------------------------------------------------------------
// Function:	PLAY_RigisterDrawFun
// Description: Register one callback function to get current surface device context. You can draw 
//		(write) in the DC just as you do in client zone DC of the window. But this DC is not the client 
//		zone DC of the window, it is the DC of Off-Screen in DirectDraw. Please note: This interface is 
//		null if you use overlay surface. You can draw in the window. It will be displayed if it is not
//		a transparent color.
// Parameter: nPort,Port number
//		 DrawFun,Callback function handle
//			nPort,Port number
//			hDc,OffScreen, You can operate it just as operate the displayed window DC
//			nUser,User data
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
typedef void (CALLBACK* fDrawCBFun)(LONG nPort,HDC hDc, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_RigisterDrawFun(LONG nPort, fDrawCBFun DrawCBFun, void* pUserData);

//------------------------------------------------------------------------
// Function:	PLAY_ResetBuffer
// Description: Clear player buffer
// Parameter: nPort,Port number
//		 nBufType,Buffer type, Please refer to macro definition macro definition:
//			BUF_VIDEO_SRC 1 
//			BUF_AUDIO_SRC 2 
//			BUF_VIDEO_RENDER 3 
//			BUF_AUDIO_RENDER 4 
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ResetBuffer(LONG nPort,DWORD nBufType);

//------------------------------------------------------------------------
// Function:	PLAY_GetBufferValue
// Description: To get player buffer size (frame amount or byte). You can use this interface to get the 
//			data in the buffer so that you can estimate the network delaying time
// Parameter: nPort,Port number
//		 nBufType,��???:
//			BUF_VIDEO_SRC 1 
//			BUF_AUDIO_SRC 2 
//			BUF_VIDEO_RENDER 3 
//			BUF_AUDIO_RENDER 4 
// Returns:		DWORD,Return different buffer values in accordance with various parameters. Sourcing buffer 
//					returns byte and the buffer return the frame amount after decoding
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetBufferValue(LONG nPort,DWORD nBufType);

//------------------------------------------------------------------------
// Function:	PLAY_AdjustWaveAudio
// Description: Adjust WAVE to adjust volume. The difference between this function and the PLAY_SetVolume is: 
//			the function is to adjust audio data and only applies to current channel. 
//			But PLAY_SetVolume is to adjust audio card volume and applies to the whole system.
//			This function has not realized yet.
// Parameter: nPort,Port number
//		 nCoefficient,Modified parameter.,The value ranges:[MIN_WAVE_COEF, MAX_WAVE_COEF]. 0 stands for no modification.
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_AdjustWaveAudio(LONG nPort,LONG nCoefficient);

//------------------------------------------------------------------------
// Function:	PLAY_SetAudioCallBack
// Description: Callback wave data after decoding audio frame
// Parameter: nPort,Port number
//		 funAudio,Audio callback function
//			nPort,Port number
//			pAudioBuf,Wave data buffer
//			nSize,Wave data length
//			nStamp,Time mark (ms)
//			nType,Audio type T_AUDIO16. Sampling rate 8000. single-channel. Each sampling spot is represented by 16-bit.
//			nUser,User defined data
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
typedef void (CALLBACK * fAudioCBFun)(LONG nPort, char * pAudioBuf, LONG nSize, LONG nStamp, LONG nType, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetAudioCallBack(LONG nPort, fAudioCBFun AudioCBFun, void* pUserData);

//------------------------------------------------------------------------
// Function:	PLAY_SetEncTypeChangeCallBack
// Description: Callback function to remind you when decoding format changes. Use it before opening a file
// Parameter: nPort,Port number
//		 funEncChange,Callback function
//			nPort,Port number
//			nUser,User data
//		 nUser,User data
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
typedef void(CALLBACK *fEncChangeCBFun)(LONG nPort, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetEncTypeChangeCallBack(LONG nPort, fEncChangeCBFun EncChangeCBFun, void* pUserData);

//------------------------------------------------------------------------
// Function:	PLAY_SetColor
// Description: Set video parameter. It becomes active once it is set
// Parameter:	nPort,Port number
//		 nRegionNum,Display zone. Please refer to PLAY_SetDisplayRegion. Please set it as o if there is only one display zone (usually it is 0)
//		 nBrightness,Brightness. Default value is 64. The value ranges from 0 to 128
//		 nContrast,Contratsness. Default value is 64. The value ranges from 0 to 128
//		 nSaturation,Saturation.Default value is 64. The value ranges from 0 to 128
//		 nHue,Hue.Default value is 64. The value ranges from 0 to 128
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetColor(LONG nPort, DWORD nRegionNum, int nBrightness, int nContrast, int nSaturation, int nHue);

//------------------------------------------------------------------------
// Function:	PLAY_GetColor
// Description: Get the corresponding color value. The parameter is the same as PLAY_SetColor
// Parameter:	nPort,Port number
//				nRegionNum,Display zone. Please refer to PLAY_SetDisplayRegion. Please set it as o if there is only one display zone (usually it is 0)
//				pBrightness,Brightness. Default value is 64. The value ranges from 0 to 128
//				pContrast,Contratsness. Default value is 64. The value ranges from 0 to 128.
//				pSaturation,Saturation.Default value is 64. The value ranges from 0 to 128
//				pHue,Hue.Default value is 64. The value ranges from 0 to 128
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetColor(LONG nPort, DWORD nRegionNum, int *pBrightness, int *pContrast, int *pSaturation, int *pHue);

//------------------------------------------------------------------------
// Function:	PLAY_SetEncChangeMsg
// Description: Set the message to be sent when decode format changes
// Parameter: nPort,Port number
//		 hWnd,The window to receive the message
//		 nMsg,User defined message. When encode format is changed during decoding, user may receive 
//					this message in the window process
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetEncChangeMsg(LONG nPort,HWND hWnd,UINT nMsg);

//------------------------------------------------------------------------
// Function:	PLAY_CatchPic
// Description: Snapshoot, write picture data to specified file. PLAY_SetDisplayCallBack Call this function
//		when decoding video data and then you can process the video data (such  snapshoot). Keep calling
//		this callback function if there is continue decoding data. But LAY_CatchPic snapshoot one image 
//		at one time and it can realize snapshoot in pause or frame by frame play mode. If you want to snapshoot
//		(one time for one image), please call PLAY_CatchPic. You can call PLAY_SetDisplayCallBack to get
//		video data in a period of time.
// Parameter: nPort,Port number
//		 sFileName,File name
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CatchPic(LONG nPort,char* sFileName) ;

//------------------------------------------------------------------------
// Function:	PLAY_CatchPicEx
// Description: Snapshoot. Picture format could be specified as bmp or jpeg 
// Parameter: nPort,Port number
//		 sFileName,File name
//		 ePicfomat,Picture format type refer to tPicFomats
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CatchPicEx(LONG nPort,char* sFileName,tPicFormats ePicfomat);

//------------------------------------------------------------------------
// Function:	PLAY_SetFileEndCallBack
// Description: Set the end of file callback
// Parameter: nPort,Port number
//		 pFileEnd,Callback function pointer
//			nPort,Port number
//			nUser,User data
//		 nUser,User data
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
typedef void (CALLBACK *fpFileEndCBFun)(DWORD nPort, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileEndCallBack(LONG nPort, fpFileEndCBFun pFileEndCBFun, void* pUserData);

//------------------------------------------------------------------------
// Function:	PLAY_StartDataRecord
// Description: Begin record stream data. It applies to stream mode only. Call it after PLAY_Play
// Parameter: nPort,Port number
//		 sFileName,Record file name. If there is no exsiting folder in the name, then create a new folder
//		 idataType,0 Raw video stream;1 convert to avi;2 convert to asf
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StartDataRecord(LONG nPort, char *sFileName, int idataType);

//------------------------------------------------------------------------
// Function: PLAY_WriteData
// Description: Save native stream
// Parameter: nPort,Port Number
//		 pBuf, Stream Buffer
//		 nSize,Buffer Size
// Returns: BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_WriteData(LONG nPort, PBYTE pBuf,DWORD nSize);

//------------------------------------------------------------------------
// Function:	PLAY_StopDataRecord
// Description: Stop recording stream data
// Parameter:	nPort,Port number
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopDataRecord(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_SetPlaySpeed
// Description: Change play speed
// Parameter:	nPort,nPort Number
//		        fCoff,Play Speed,Range[1/64~64.0],less than 1 play slowly��greater than 1 play quickly.
//			    when play speed is high enough ,it wil probally throw frame.
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlaySpeed(LONG nPort, float fCoff);

//------------------------------------------------------------------------
// Function:	PLAY_QueryInfo
// Description: Information status search function. Now it can search current time and frame rate information
// Parameter: nPort,Port number
//		 cmdType,Specify status search type
//			PLAY_CMD_GetTime			get time information.Unit is ms
//			PLAY_CMD_GetFileRate		get frame rate information
//			PLAY_CMD_GetMediaInfo		get media information, sturct is MEDIA_INFO
//		 buf,Information buffer
//		 buflen,Buffer length
//		 returnlen,Valid data length
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_QueryInfo(LONG nPort , int cmdType, char* buf, int buflen, int* returnlen);

//------------------------------------------------------------------------
// Function:	PLAY_OpenAudioRecord
// Description: Enabel audio sampling operation
// Parameter: pProc,Audio sampling data callback pointer
//			pDataBuffer,Data callback pointer
//			DataLength,Callback data length
//			nUser,User data
//		 nBitsPerSample,Represent the bit for each sampling
//		 nSamplesPerSec,Sampling rate
//		 nLength,Data buffer length
//		 nReserved,Reserve
//		 nUser,User defined data
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
typedef void (CALLBACK *pCallFunction)(LPBYTE pDataBuffer, DWORD DataLength, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_OpenAudioRecord(pCallFunction pProc, LONG nBitsPerSample, LONG nSamplesPerSec, LONG nLength, LONG nReserved, void* pUserData);

//------------------------------------------------------------------------
// Function:	PLAY_CloseAudioRecord
// Description: Disable audio sampling function
// Parameter: 
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CloseAudioRecord();

//------------------------------------------------------------------------
// Function:	PLAY_SetWaterMarkCallBack
// Description: Set watermark data callback.
// Parameter: nPort,Port number
//		 pFunc,Watermark information to get callback function
//			buf,Watermark data buffer
//			key,Distinguish different watermarks
//			len,Buffer length
//			reallen,Bufffer actual length
//			reserved,��y?�̡�??��[0,3],o?��?��???
//				0  I frame data water mark information 
//				1  frame water mark
//				2  water mark verification 
//				3  intelligent analysis frame
//		 nUser,User defined data
// Returns: BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
typedef int (CALLBACK* GetWaterMarkInfoCallbackFunc)(char* buf, LONG key, LONG len, LONG reallen, LONG type, void* pUserData);	
PLAYSDK_API BOOL CALLMETHOD PLAY_SetWaterMarkCallBack(LONG nPort, GetWaterMarkInfoCallbackFunc pFunc, void* pUserData);

//------------------------------------------------------------------------
// Function:	PLAY_CreateFile
// Description: Open file and then automatically allocate channel number
// Parameter:	sFileName,File name, The file size ranges from 4G to 4K
// Returns: BOOL,TRUE--succeeded FALSE--failed
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_CreateFile(LPSTR sFileName);

//------------------------------------------------------------------------
// Function:	PLAY_DestroyFile
// Description: Close file and release the automatically allocated channel number
// Parameter: nPort,Port number
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_DestroyFile(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_CreateStream
// Description: Open stream interface and then automatically allocate channel number 
// Parameter: nBufPoolSize,Set storage data stream buffer size in the playe 
//					The value ranges is 
//					[SOURCE_BUF_MIN,SOURCE_BUF_MAX]. Usually it is 900*1024. Please increase the value if the data are not even
// Returns: DWORD,failed Returns false,ReturnsPort number.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_CreateStream(DWORD nBufPoolSize);

//------------------------------------------------------------------------
// Function:	PLAY_DestroyStream
// Description: Close data bit and release the automatically allocated port number
// Parameter: nPort,Port number
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_DestroyStream(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_GetFreePort
// Description: Get free port. 
// Parameter:	plPort,Port number.
// Returns:		BOOL,TRUE--succeeded FALSE--failed
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetFreePort(LONG *plPort);

//------------------------------------------------------------------------
// Function:	PLAY_ReleasePort
// Description: Release the port got with PLAY_GetFreePort
// Parameter:	nPort,Port number
// Returns:		BOOL,TRUE--succeeded FALSE--failed
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ReleasePort(LONG lPort);

//------------------------------------------------------------------------
// Function:	PLAY_VerticalSyncEnable
// Description: Vertical synchronize method, support offscreen mode only
//		Called after PLAY_Play. When displaying dynamic images, this method may be useful.

// Parameter: nPort,Port number
//		 bEnable,TRUE Enable vertical synchronize;FALSE Diable vertical synchronize.
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API	BOOL CALLMETHOD PLAY_VerticalSyncEnable(LONG nPort, BOOL bEnable);

//------------------------------------------------------------------------
// Function:	PLAY_GetPicBMP
// Description: Snapshoot. Return BMP picture data buffer.
// Parameter: nPort,Port number
//		 pBmpBuf,Picture buffer. Allocate by user, suggest size:
//			sizeof(BITMAPFILEHEADER) +
//			sizeof(BITMAPINFOHEADER) + w * h * 4
//			where w is picture width, h is picture height
//		 dwBufSize,Buffer size
//		 pBmpSize,BMP picture data size
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPicBMP(LONG nPort, PBYTE pBmpBuf, DWORD dwBufSize, DWORD* pBmpSize);

//------------------------------------------------------------------------
// Function: PLAY_GetPicBMPEx
// Description: snapshot BMP image
// Parameter: nPort, channel no.
//		 pBmpBuf, buffer address to store BMP data, allocated by user, must be greater than bmp image size,
//			Recommended size :size of(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+w*h*4,
//			w and h are image width and height.
//		 dwBufSize, buffer area size
//		 pBmpSize, image size of actual bmp 
//		 nWidth,designated bmp width
//		 nHeight, designated bmp height
//		 nRgbType, designated RGB format 0��RGB32;1��RGB24;
// Return: BOOL, successful return to TRUE, failed return to FALSE.
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPicBMPEx(LONG nPort, PBYTE pBmpBuf, DWORD dwBufSize, DWORD* pBmpSize, LONG nWidth, LONG nHeight, int nRgbType);

//------------------------------------------------------------------------
// Function:	PLAY_GetPicJPEG
// Description: Snapshoot. Return JPEG picture data buffer.
// Parameter: nPort,Port number
//		 pJpegBuf,Picture buffer. Allocate by user, suggest size:
//			w * h * 3/2
//			where w is picture width, h is picture height
//		 dwBufSize,Buffer size.
//		 pJpegSize,JPEG picture data size.
//		 quality,Quality of the jpeg compression, value is (0, 100]
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPicJPEG(LONG nPort, PBYTE pJpegBuf, DWORD dwBufSize, DWORD* pJpegSize, int quality);

//------------------------------------------------------------------------
// Function: PLAY_SetVisibleDecodeCallBack
// Description: Decoding call, is same almost with PLAY_SetDecCallBackEx, except that decoding call can
//			display video simultaneously, long-time logic processing is not recommended in call function, in order to avoid delay in display.
// Parameter: nPort, channel no.
//		 cbDec, call function indicator, cannot be NULL, its parameter definitions are as following:
//			nPort, channel no.
//			pFrameDecodeInfo, A/V data after decoding
//			pFrameInfo, image and audio, refer to FRAME_INFO structure
//			pUser, user customized parameter.
//		 pUser, user customized parameter.
// Return: BOOL, successful return to TRUE, failed return to FALSE.
PLAYSDK_API BOOL CALLMETHOD PLAY_SetVisibleDecodeCallBack(LONG nPort, fCBDecode cbDec, void* pUser);

//------------------------------------------------------------------------
// Function:	PLAY_RigisterDrawFunEx
// Description: Register one callback function to get current surface device context. You can draw 
//		(write) in the DC just as you do in client zone DC of the window. But this DC is not the client 
//		zone DC of the window, it is the DC of Off-Screen in DirectDraw. Please note: This interface is 
//		null if you use overlay surface. You can draw in the window. It will be displayed if it is not 
//		a transparent color.
// Parameter: nPort,Port number
//		 nReginNum,Display zone serial number
//			0~(MAX_DISPLAY_WND-1).
//			If nRegionNum is 0, it means refresh the main display window
//		 DrawFunEx,Callback function handle
//			nPort,Port number
//			hDc,OffScreen, You can operate it just as operate the displayed window DC
//			nUser,User data
//		 nUser,User data
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
typedef void (CALLBACK* fDrawCBFunEx)(LONG nPort,LONG nReginNum,HDC hDc, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_RigisterDrawFunEx(LONG nPort, LONG nReginNum, fDrawCBFunEx DrawFunEx, void* pUserData);

//------------------------------------------------------------------------
// Function:	PLAY_CatchResizePic
// Description: Snap. Can set format, height and width. 
// Parameter: nPort,Port number
//		 sFileName,file name 
//		 lTargetWidth,picture width
//		 lTargetHeight,picture height
//		 ePicfomat,picture type,refer to tPicFomats
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CatchResizePic(LONG nPort, char* sFileName, LONG lTargetWidth, LONG lTargetHeight, tPicFormats ePicfomat);

//------------------------------------------------------------------------
// Function:	PLAY_GetRealFrameBitRate
// Description: Get video real-time bit rate  
// Parameter: nPort,Port number
//		 pBitRate,output Parameter,Returns Video bit rate 
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetRealFrameBitRate(LONG nPort, double* pBitRate);

//------------------------------------------------------------------------
// Function:	PLAY_SetFileRefCallBackEx
// Description: Set callback function pointer. Callback when establishing callback. To locate quickly 
//		and accurately, system generates a file index when opening a file. This period may take a little 
//		bit long. Its speed is about 40M/s, mainly because reading data from the HDD is slow. The index 
//		establishment is operated in the background. The functions that need to use this index have to 
//		wait until this process ends, while the other interfaces may not be affected
// Parameter: nPort,Port number
//		 pFileRefDoneEx,Callback function pointer
//			nPort,Port number
//			bIndexCreated,Index creation symbol.TRUE=Index creation succeeded. FALSE=Index creation failed.
//			nUser,User data
//		 nUser,User data
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
typedef void (CALLBACK *fpFileRefDoneCBFunEx)(DWORD nPort, BOOL bIndexCreated, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileRefCallBackEx(LONG nPort, fpFileRefDoneCBFunEx pFileRefDoneCBFunEx, void* pUserData);

//------------------------------------------------------------------------
// Function:	PLAY_StartAVIConvert
// Description: Begin AVI conversion and set AVI switch call status. 
// Parameter: nPort,Port number
//		 pAVIFunc,Call Function. Parameter definition is shown as below:
//			nPort,Port number
//			lMediaChangeType,AVI_MEDIACHANGE_FRAMERATE means frame change;AVI_MEDIACHANGE_FRAMERATE means resolution change. 
//			lUser,Customized Parameter
//			pbIfContinue,TRUE=continue conversion;FALSE=stop conversion  
//			sNewFileName,new file name if continue conversion. 
//		 lUser,Customized Parameter
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
typedef void (CALLBACK* AVIConvertCallback)(LONG nPort, LONG lMediaChangeType, void* pUserData, BOOL *pbIfContinue, char *sNewFileName);
PLAYSDK_API BOOL CALLMETHOD PLAY_StartAVIConvert(LONG nPort, char *sFileName, AVIConvertCallback pAVIFunc, void* pUserData);

//------------------------------------------------------------------------
// Function:	PLAY_StopAVIConvert
// Description: stop converting avi 
// Parameter: nPort,Port number
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopAVIConvert(LONG nPort);

//------------------------------------------------------------------------
// Function:	PLAY_SetWaterMarkCallBackEx
// Description: Set watermark data callback.
// Parameter: nPort,Port number
//		 pFunc,Watermark information to get callback function
//			nPort,Port number
//			buf,Watermark data buffer
//			lTimeStamp,Watermark time stamp 
//			lInfoType,Distinguish different watermarks,There are three types: WATERMARK_DATA_TEXT,
//				WATERMARK_DATA_JPEG_BMP,WATERMARK_DATA_FRAMEDATA
//		 len,Buffer length
//		 reallen,Bufffer actual length
//		 lCheckResult,1 no error;2 frame water mark;3 frame data error ;4 frame sequence error
//		 nUser,user data
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
typedef int (CALLBACK* GetWaterMarkInfoCallbackFuncEx)(LONG nPort, char* buf, LONG lTimeStamp, LONG lInfoType, LONG len, LONG reallen, LONG lCheckResult, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetWaterMarkCallBackEx(LONG nPort, GetWaterMarkInfoCallbackFuncEx pFunc, void* pUserData);

//------------------------------------------------------------------------
// Function:	PLAY_SetAudioRecScaling
// Description: Set audio record data zoom rate
// Parameter: fRatio,Zoom rate.from 0 to 1=zoom in audio.1=Original audio.Over 1=audio zoom out.
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetAudioRecScaling(float fRatio);

//------------------------------------------------------------------------
// Function:	PLAY_GetAudioRecScaling
// Description: Get audio record data zoom rate
// Parameter: pfRatio,zoom rate. From 0 to 1=Zoom in audio.1=Original audio. Over 1=zoom out audio.
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetAudioRecScaling(float* pfRatio);

//------------------------------------------------------------------------
// Function:	PLAY_SetAudioRenderScaling
// Description: Set audio decode zoom rate
// Parameter: nPort,Port number
//		 fRatio,Zoom rate.From 0 to 1=Zoom in audio;1=original audio. Over 1=audio zoom out.
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetAudioRenderScaling(LONG nPort, float fRatio);

//------------------------------------------------------------------------
// Function:	PLAY_GetAudioRenderScaling
// Description: Get audio decode zoom rate
// Parameter: nPort,Port number
//		 pfRatio,zoom rate.0 to 1=audio zoom in;1=original audio;over 1=audio zoom out. 
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetAudioRenderScaling(LONG nPort, float* pfRatio);

//------------------------------------------------------------------------
// Function:	PLAY_SetRotateAngle
// Description: Video
// Parameter: nrotateType,Flip type,Range[0,3]. 0=no flip;1=Rotate by 90 degrees;2=Rotate by 180 degrees;3=Rotate by 270 degrees. 
// Returns:		BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetRotateAngle(LONG nPort , int nrotateType);

//------------------------------------------------------------------------
// Function: PLAY_SetDelayTime
// Description: Set realplay delay time.
// Parameter: nDelay,Delay time.
//       nThreshold,Threshold time.
// Returns: BOOL,TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDelayTime(LONG nPort, int nDelay, int nThreshold);

//------------------------------------------------------------------------
// Function: PLAY_SetPlayMethod
// Description: set play strategy��only for realtime
// Parameter: nStartTime, first start play if internal buffer is greater than nStartTime
//       nSlowTime, start play at lower speed if internal buffer is less than nSlowTime
//		 nFastTime, start play at faster speed if internal buffer is greater than nFastTime
//		 nFailedTime, InputData Interface will be failed if internal buffer is greater than nFailedTime
// Return: TRUE--succeeded FALSE--failed.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayMethod(LONG nPort, int nStartTime, int nSlowTime, int nFastTime, int nFailedTime);

//------------------------------------------------------------------------
// Function:	PLAY_BackOne
// Description: This interface is the same with PLAY_OneByOneBack
// Parameter: 
// Returns: 
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_BackOne(LONG nPort);

//------------------------------------------------------------------------
// Function: PLAY_SetDecCallBack (PLAY_SetDecodeCallBack is recommended.)
// Description: Set decoding call to replace display in player, controlled by user, the function at//			call before PLAY_Play, when PLAY_Stop, it automatically become invalid. Next time before PLAY_Play,
//			need to set again, decoding part do not control speed, user shall return from call function, decoder
//			decode next data, only for decoding with no display.
// Parameter: nPort, channel no.
//		 DecCBFun, decoding call function indicator, cannot be NULL. Call function parameter definitions are as follows:
//			nPort, channel no.
//			pBuf, A/V data after decoding
//			nSize, pBuf length of A/V data after decoding
//			pFrameInfo, image and audio, refer to FRAME_INFO structure
//			nReserved1, reserved parameter
//			nReserved2, reserved parameter	
// Return: BOOL, successful return to TRUE, failed return to FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fDecCBFun)(LONG nPort,char * pBuf,LONG nSize,FRAME_INFO * pFrameInfo, void* pUserData, LONG nReserved2);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecCallBack(LONG nPort, fDecCBFun DecCBFun);

//------------------------------------------------------------------------
// Function: PLAY_SetDecCallBackEx(PLAY_SetDecodeCallBack is recommended.)
// Description: Set decoding call to replace display in player, controlled by user, the function at
//			call before PLAY_Play, when PLAY_Stop, it automatically become invalid. Next time before PLAY_Play,
//			Need to set again, decoding part do not control speed, user shall return from call function, decoder
//			decode next data, only for decoding with no display.
// Parameter: nPort, channel no.
//		 DecCBFun, decoding call function indicator, cannot be NULL. Call function parameter definitions are as follows:
//			nPort, channel no.
//			pBuf, A/V data after decoding
//			nSize, pBuf length of A/V data after decoding
//			pFrameInfo, image and audio, refer to FRAME_INFO structure
//			nReserved1, reserved parameter
//			nReserved2, reserved parameter	
// Return: BOOL, successful return to TRUE, failed return to FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecCallBackEx(LONG nPort, fDecCBFun DecCBFun, void* pUserData);

//------------------------------------------------------------------------
// Function: PLAY_SetVisibleDecCallBack(PLAY_SetVisibleDecodeCallBack is recommended)
// Description: Decoding call, is same almost with PLAY_SetDecCallBackEx, except that decoding call can
//			display video simultaneously, long-time logic processing is not recommended in call function, in order to avoid delay in display.
// Parameter: nPort, channel no.
//		 DecCBFun, call function indicator, cannot be NULL, its parameter definitions are as following:
//			nPort, channel no.
//			pBuf, A/V data after decoding
//			nSize, pBuf length of A/V data after decoding
//			pFrameInfo, image and audio, refer to FRAME_INFO structure
//			pUserData, user customized parameter
//			nReserved1, reserved parameter
//		 pUserData, user customized parameter.
// Return: BOOL, successful return to TRUE, failed return to FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fVisibleDecCBFun)(LONG nPort,char * pBuf,LONG nSize,FRAME_INFO * pFrameInfo, void* pUserData, LONG nReserved1);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetVisibleDecCallBack(LONG nPort, fVisibleDecCBFun DecCBFun, void* pUserData);
#ifdef __cplusplus
}
#endif

#endif
