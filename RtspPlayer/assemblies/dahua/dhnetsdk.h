
#ifndef DHNETSDK_H
#define DHNETSDK_H


#if (defined(WIN32) || defined(WIN64))
#include <windows.h>
#ifdef DHNETSDK_EXPORTS

#ifndef CLIENT_API
#define CLIENT_API  __declspec(dllexport) 
#endif

#else

#ifndef CLIENT_API
#define CLIENT_API  __declspec(dllimport)
#endif

#endif

#define CALLBACK __stdcall
#define CALL_METHOD  __stdcall  //__cdecl

#define INT64 __int64

#ifndef LLONG
#ifdef WIN32
#define LLONG LONG
#else //WIN64 
#define LLONG INT64
#endif
#endif

#ifndef LDWORD
#ifdef WIN32
#define LDWORD DWORD
#else //WIN64 
#define LDWORD INT64
#endif
#endif

#else	//linux

#define CLIENT_API	extern "C"
#define CALL_METHOD
#define CALLBACK

//#define RELEASE_HEADER	//Release header 
#ifdef RELEASE_HEADER

#define WORD	unsigned short
#define DWORD	unsigned int
#define LONG	int
#define LPDWORD	DWORD*
#define BOOL	int
#define TRUE	1
#define FALSE	0
#define BYTE	unsigned char
#define UINT	unsigned int
#define HDC		void*
#define HWND	void*
#define LPVOID	void*
#define NULL	0
#define LLONG	long
#define INT64   long long
#define LDWORD	long 

#ifndef MAX_PATH
#define MAX_PATH	260
#endif
typedef struct  tagRECT
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT;

#else	//Internal translation
#include "../Platform/osIndependent.h"
#endif

#endif
#include "dhassistant.h"

#ifndef LDWORD
#if (defined(WIN32) || defined(WIN64))
#ifdef WIN32
#define LDWORD DWORD
#else //WIN64 
#define LDWORD __int64
#endif
#else	//linux
#define LDWORD long 
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************
 ** Constant Definition
 ***********************************************************************/
#define DH_SERIALNO_LEN 			48			// Device SN string length
#define DH_MAX_DISKNUM 				256			// Max HDD number
#define DH_MAX_SDCARDNUM			32			// Max SD card number
#define DH_MAX_BURNING_DEV_NUM		32			// Max buner amount
#define DH_BURNING_DEV_NAMELEN		32			// Burner name max length 
#define DH_MAX_LINK 				6
#define DH_MAX_CHANNUM 				16			// Max channel amount
#define DH_MAX_DECODER_CHANNUM		64			// decoder device max channel number
#define DH_MAX_ALARMIN 				128			// Max alarm input amount 
#define DH_MAX_ALARMOUT 			64			// Max alarm output amount 
#define DH_MAX_RIGHT_NUM			100			// Max user right amount
#define DH_MAX_GROUP_NUM			20			// Max user group amount
#define DH_MAX_USER_NUM				200			// Max user account amount
#define DH_RIGHT_NAME_LENGTH		32			// Right name length
#define DH_USER_NAME_LENGTH			8			// User name length 
#define DH_USER_PSW_LENGTH			8			// User password length 
#define DH_MEMO_LENGTH				32			// Note length 
#define DH_MAX_STRING_LEN			128
#define DH_DVR_SERIAL_RETURN		1			// Device send out SN callback
#define DH_DVR_DISCONNECT			-1			// Device disconnection callback during the verification period
#define MAX_STRING_LINE_LEN			6			// Max six rows
#define MAX_PER_STRING_LEN			20			// Line max length 
#define DH_MAX_MAIL_NAME_LEN		64			// The user name length the new mail structure supported
#define DH_MAX_MAIL_PSW_LEN			64			// Password length the new mail structhre supported
#define DH_SPEEDLIMIT_TYPE_LEN      32          // speed limit string max length
#define DH_VEHICLE_TYPE_LEN         32          // vehicle info type max length
#define DH_VEHICLE_INFO_LEN         32          // vehicle info string max length
#define DH_VEHICLE_DRIVERNO_LEN     32          // Driver no string max length=
#define DH_MAX_CROSSING_NUM         128         // Max supported crossing num 
#define DH_MAX_CROSSING_ID          32          // Max crossing ID length 
#define DH_MAX_CARD_INFO_LEN		256			// max card info length
#define DH_MAX_CHANNUM_EX           32          // extended max channel number
#define DH_MAX_SAERCH_IP_NUM        256         // max number of IP for saerch

// Remote configuration structure corresponding constant 
#define DH_MAX_MAIL_ADDR_LEN		128			// Mail address max length
#define DH_MAX_MAIL_SUBJECT_LEN		64			// Mail subject max length 
#define DH_MAX_IPADDR_LEN			16			// IP address string length 
#define DH_MACADDR_LEN				40			// MACE address string length
#define DH_MAX_URL_LEN				128			// URL string length 
#define DH_MAX_DEV_ID_LEN			48			// Device serial number max length 
#define	DH_MAX_HOST_NAMELEN			64			// Host name length 
#define DH_MAX_HOST_PSWLEN			32			// Password length 
#define DH_MAX_NAME_LEN				16			// Universal name string length 
#define DH_MAX_ETHERNET_NUM			2			// Ethernet max amount 
#define DH_MAX_ETHERNET_NUM_EX	    10			// extended Ethernet max amount
#define	DH_DEV_SERIALNO_LEN			48			// Serial number string length 
#define DH_DEV_TYPE_LEN				32			// Device type string length 
#define DH_N_WEEKS					7			// The days in one week 
#define DH_N_TSECT					6			// Time period amount 
#define DH_N_REC_TSECT				6			// Record period amount 
#define DH_N_COL_TSECT				2			// Color period amount 
#define DH_CHAN_NAME_LEN			32			// Channel name length. DVR DSP capacity limit. Max 32 bytes.		
#define DH_N_ENCODE_AUX				3			// Extra stream amount 
#define DH_N_TALK					1			// Max audio talk channel amount 
#define DH_N_COVERS					1			// Privacy mask zone amount 
#define DH_N_CHANNEL				16			// Max channel amount 
#define DH_N_ALARM_TSECT			2			// Alarm prompt period amount 
#define DH_MAX_ALARMOUT_NUM			16			// Alarm output ports max amount 
#define DH_MAX_AUDIO_IN_NUM			16			// Audio input ports max amount 
#define DH_MAX_VIDEO_IN_NUM			16			// Video input ports max amount 
#define DH_MAX_ALARM_IN_NUM			16			// Alarm input ports max amount 
#define DH_MAX_DISK_NUM				16			// HDD max amount. Now the value is 16.
#define DH_MAX_DECODER_NUM			16			// Decoder(485) max amount 
#define DH_MAX_232FUNCS				10			// 232 COM function max amount 
#define DH_MAX_232_NUM				2			// 232 COM port max amount 
#define DH_MAX_232_NUM_EX           16          // extended 232 COM port max amount 
#define DH_MAX_DECPRO_LIST_SIZE		100			// Decoder protocol list max amount 
#define DH_FTP_MAXDIRLEN			240			// FTP file folder max length 
#define DH_MATRIX_MAXOUT			16			// Matrix output ports max amount
#define DH_TOUR_GROUP_NUM			6			// Matrix output ports max amount 
#define DH_MAX_DDNS_NUM				10			// ddns max amount the device supported 
#define DH_MAX_SERVER_TYPE_LEN		32			// ddns type and max string length 
#define DH_MAX_DOMAIN_NAME_LEN		256			// ddns domain name and max string length 
#define DH_MAX_DDNS_ALIAS_LEN		32			// ddns alias and max string length 
#define DH_MAX_DEFAULT_DOMAIN_LEN	60			// ddns default domain, max sring length	
#define DH_MOTION_ROW				32			// Motion detection zone row amount 
#define DH_MOTION_COL				32			// Motion detection zone column amount 
#define DH_STATIC_ROW				32			// Static detection zone row amount 
#define DH_STATIC_COL				32			// Static detection zone column amount 
#define	DH_FTP_USERNAME_LEN			64			// FTP setup:user name max lengh 
#define	DH_FTP_PASSWORD_LEN			64			// FTP setup:password max length 
#define	DH_TIME_SECTION				2			// FTP setup:time periods in each day.
#define DH_FTP_MAX_PATH				240			// FTP setup:file path max length 
#define DH_FTP_MAX_SUB_PATH			128 		// FTP setup:sub path max length
#define DH_INTERVIDEO_UCOM_CHANID	32			// Platform embedded setup:U China Net Communication (CNC)channel ID
#define DH_INTERVIDEO_UCOM_DEVID	32			// Platform embedded setup:UCNC device ID
#define DH_INTERVIDEO_UCOM_REGPSW	16			// Platform embedded setup:UCNC registration password 
#define DH_INTERVIDEO_UCOM_USERNAME	32			// Platform embedded setup:UCNC user name 
#define DH_INTERVIDEO_UCOM_USERPSW	32			// Platform embedded setup: UCNC password 
#define DH_INTERVIDEO_NSS_IP		32			// Platform embedded setup:ZTE Netview IP
#define DH_INTERVIDEO_NSS_SERIAL	32			// Serial Platform embedded setup:ZTE Netview  serial
#define DH_INTERVIDEO_NSS_USER		32			// User Platform embedded setup:ZTE Netview user
#define DH_INTERVIDEO_NSS_PWD		50			// Password Platform embedded setup:ZTE Netview password
#define DH_MAX_VIDEO_COVER_NUM		16			// Privacy mask zones max amount 
#define DH_MAX_WATERMAKE_DATA		4096		// Watermark data max length 
#define DH_MAX_WATERMAKE_LETTER		128			// Watermark text max length
#define DH_MAX_WLANDEVICE_NUM		10			// Max searched wireless device amount 
#define DH_MAX_WLANDEVICE_NUM_EX	32			// Max searched wireless device amount
#define DH_MAX_ALARM_NAME			64			// Address length 
#define DH_MAX_REGISTER_SERVER_NUM	10			// Auto registration server amount 
#define DH_SNIFFER_FRAMEID_NUM		6			// 6 FRAME ID options
#define DH_SNIFFER_CONTENT_NUM		4			// 4 sniffer in each FRAME
#define DH_SNIFFER_CONTENT_NUM_EX	8			// 8 sniffer in each FRAME
#define DH_SNIFFER_PROTOCOL_SIZE	20			// protocol length
#define DH_MAX_PROTOCOL_NAME_LENGTH 20
#define DH_SNIFFER_GROUP_NUM		4			// 4 group sniffer setup 
#define MAX_PATH_STOR				240			// Remote folder length 
#define DH_ALARM_OCCUR_TIME_LEN		40			// New alarm upload time length 
#define DH_VIDEO_OSD_NAME_NUM		64			// Overlay name length. Now it supports 32-digit English and 16-digit Chinese.
#define DH_VIDEO_CUSTOM_OSD_NUM		8			// The self-defined amount supported excluding time and channel.
#define DH_CONTROL_AUTO_REGISTER_NUM 100        // Targeted initiatives to support the number of registration servers
#define DH_MMS_RECEIVER_NUM          100        // Support the number of messages the recipient
#define DH_MMS_SMSACTIVATION_NUM     100        // Support the number of SMS sender
#define DH_MMS_DIALINACTIVATION_NUM  100        // Support for dial-up number of the sender
#define DH_MAX_ALARMOUT_NUM_EX		 32			// Alarm output amount max limit
#define DH_MAX_VIDEO_IN_NUM_EX		 32			// Video input amount max limit
#define DH_MAX_ALARM_IN_NUM_EX		 32			// Alarm input amount max limit
#define DH_MAX_IPADDR_OR_DOMAIN_LEN	 64			// IP or domain name length
#define DH_MAX_OBJECT_LIST			16			// the upper limit number of object id that detected by device in intelligent analysis 
#define DH_MAX_RULE_LIST			16			// the upper limit number of device rule in intelligent analysis 
#define DH_MAX_POLYGON_NUM			16			// the max number of polygon's culmination
#define DH_MAX_DETECT_LINE_NUM       20          // rule detect line's max point number
#define DH_MAX_DETECT_REGION_NUM     20          // rule detect region's max point number
#define DH_MAX_TRACK_LINE_NUM        20         // object moving track's max point number
#define DH_MAX_CANDIDATE_NUM         50         // max candidate number
#define DH_MAX_PERSON_IMAGE_NUM      48         // max image of every person
#define DH_MAX_FENCE_LINE_NUM        2          // max fence line number
#define MAX_SMART_VALUE_NUM          30         // the max number of smart disk information
#define DH_MACHINE_NAME_NUM			 64         // Device name length
#define DH_INTERVIDEO_AMP_DEVICESERIAL    48    // Platform embedded setup, AMP,Device serial numb length
#define DH_INTERVIDEO_AMP_DEVICENAME      16    // Platform embedded setup, AMP,Device Name length
#define DH_INTERVIDEO_AMP_USER            32    // Platform embedded setup, AMP,User Name Length
#define DH_INTERVIDEO_AMP_PWD             32    // Platform embedded setup, AMP,password length
#define MAX_SUBMODULE_NUM            32         // Max number of submodule information
#define DH_MAX_CARWAY_NUM            8          // traffic snapshot,the max car way number
#define DH_MAX_SNAP_SIGNAL_NUM       3          // one car way max time for snapshot
#define DH_MAX_CARD_NUM              128        // max number of card
#define DH_MAX_CARDINFO_LEN          32         // max length of card information
#define DH_MAX_CONTROLER_NUM         64         // max supported controller number
#define DH_MAX_LIGHT_NUM             32         // max control light group number
#define DH_MAX_SNMP_COMMON_LEN       64         // max Snmp read or write buffer
#define DH_MAX_DDNS_STATE_LEN        128        // max DDNS state buffer
#define DH_MAX_PHONE_NO_LEN          16         // max phone len
#define DH_MAX_MSGTYPE_LEN           32         // max type len
#define DH_MAX_MSG_LEN               256        // max message len
#define DH_MAX_DRIVINGDIRECTION      256        // max driving direction len
#define DH_MAX_GRAB_INTERVAL_NUM     4	        // max snapshot count
#define DH_MAX_FLASH_NUM			 5			// max flash count
#define DH_MAX_LANE_NUM              8          // max number of road in every channel
#define DH_MAX_ISCSI_PATH_NUM		 64			// max ISCSI remote path number
#define DH_MAX_WIRELESS_CHN_NUM		 256		// max wireless channel number
#define DH_PROTOCOL3_BASE			 100		// protocol 3 base value
#define DH_PROTOCOL3_SUPPORT		 11			// protocol 3 support
#define DH_MAX_CHANMASK              64         // max channel mask count

// Search type, corresponding to CLIENT_QueryDevState
#define DH_DEVSTATE_COMM_ALARM		0x0001		// Search general alarm status(including external alarm,video loss, motion detection)
#define DH_DEVSTATE_SHELTER_ALARM	0x0002		// Search camera masking alarm status
#define DH_DEVSTATE_RECORDING		0x0003		// Search record status 
#define DH_DEVSTATE_DISK			0x0004		// Search HDD information 
#define DH_DEVSTATE_RESOURCE		0x0005		// Search system resources status 
#define DH_DEVSTATE_BITRATE			0x0006		// Search channel bit stream 
#define DH_DEVSTATE_CONN			0x0007		// Search device connection status 
#define DH_DEVSTATE_PROTOCAL_VER	0x0008		// Search network protocol version number , pBuf = int*
#define DH_DEVSTATE_TALK_ECTYPE		0x0009		// Search the audio talk format the device supported. Please refer to structure DHDEV_TALKFORMAT_LIST
#define DH_DEVSTATE_SD_CARD			0x000A		// Search SD card information(FOR IPC series)
#define DH_DEVSTATE_BURNING_DEV		0x000B		// Search burner information
#define DH_DEVSTATE_BURNING_PROGRESS 0x000C		// Search burning information
#define DH_DEVSTATE_PLATFORM		0x000D		// Search the embedded platform the device supported
#define DH_DEVSTATE_CAMERA			0x000E		// Search camera property information ( for IPC series),pBuf = DHDEV_CAMERA_INFO *,there can be several structure.
#define DH_DEVSTATE_SOFTWARE		0x000F		// Search device software version information
#define DH_DEVSTATE_LANGUAGE        0x0010		// Search the audio type the device supported 
#define DH_DEVSTATE_DSP				0x0011		// Search DSP capacity description 
#define	DH_DEVSTATE_OEM				0x0012		// Search OEM information 
#define	DH_DEVSTATE_NET				0x0013		// Search network running status information 
#define DH_DEVSTATE_TYPE			0x0014		// Search function attributes(for IPC serirs)
#define DH_DEVSTATE_SNAP			0x0015		// Search snapshot function attribute(For IPC series)
#define DH_DEVSTATE_RECORD_TIME		0x0016		// Query the first time and the recent video time
#define DH_DEVSTATE_NET_RSSI        0x0017      // Query the wireless network signal strength,Please refer to structure DHDEV_WIRELESS_RSS_INFO
#define DH_DEVSTATE_BURNING_ATTACH	0x0018		// Burning options inquiry
#define DH_DEVSTATE_BACKUP_DEV		0x0019		// Query the list of backup device
#define DH_DEVSTATE_BACKUP_DEV_INFO	0x001a		// Query the backup device information
#define DH_DEVSTATE_BACKUP_FEEDBACK	0x001b		// backup rate of progress
#define DH_DEVSTATE_ATM_QUERY_TRADE 0x001c		// Query ATM trade type
#define DH_DEVSTATE_SIP				0x001d		// Query sip state
#define DH_DEVSTATE_VICHILE_STATE	0x001e		// Query wifi state of mobile DVR
#define DH_DEVSTATE_TEST_EMAIL      0x001f      // Query Email Function
#define DH_DEVSTATE_SMART_HARD_DISK 0x0020      // Query Hard Disk Information
#define DH_DEVSTATE_TEST_SNAPPICTURE 0x0021     // Query Snap Picture Function
#define DH_DEVSTATE_STATIC_ALARM    0x0022      // Query static alarm state
#define DH_DEVSTATE_SUBMODULE_INFO  0x0023      // Query submodule information
#define DH_DEVSTATE_DISKDAMAGE      0x0024      // Query harddisk damage ability     
#define DH_DEVSTATE_IPC             0x0025      // Query device supported IPC ability,see struct DH_DEV_IPC_INFO 
#define DH_DEVSTATE_ALARM_ARM_DISARM 0x0026     // Query alarm arm disarm state
#define DH_DEVSTATE_ACC_POWEROFF_ALARM 0x0027   // Query ACC power off state(return a DWORD type value, 1 means power off,0 means power on)
#define DH_DEVSTATE_TEST_FTP_SERVER 0x0028      // FTP server connect test
#define DH_DEVSTATE_3GFLOW_EXCEED   0x0029      // Query 3G Flow exceed state info(see struct DHDEV_3GFLOW_EXCEED_STATE_INFO)
#define DH_DEVSTATE_3GFLOW_INFO     0x002a      // Query 3G Flow info(see struct DH_DEV_3GFLOW_INFO)
#define DH_DEVSTATE_VIHICLE_INFO_UPLOAD  0x002b // Vihicle information uploading
#define DH_DEVSTATE_SPEED_LIMIT     0x002c      // Speed limit alarm
#define DH_DEVSTATE_DSP_EX          0x002d      // Query DSP expended cap(struct DHDEV_DSP_ENCODECAP_EX)
#define DH_DEVSTATE_3GMODULE_INFO    0x002e     // Query 3G module info(struct DH_DEV_3GMODLE_INFO)
#define DH_DEVSTATE_MULTI_DDNS      0x002f      // Query multi DDNS status(struct DH_DEV_MULTI_DDNS_INFO)
#define DH_DEVSTATE_CONFIG_URL      0x0030      // Query Device URL info(struct DH_DEV_URL_INFO)
#define DH_DEVSTATE_HARDKEY        0x0031       // Query Hard key state(struct DHDEV_HARDKEY_STATE)
#define DH_DEVSTATE_ISCSI_PATH		0x0032		// Query ISCSI path(struct DHDEV_ISCSI_PATHLIST)
#define DH_DEVSTATE_DLPREVIEW_SLIPT_CAP   0x0033      // Query local preview split capability(struct DEVICE_LOCALPREVIEW_SLIPT_CAP)
#define DH_DEVSTATE_WIFI_ROUTE_CAP	0x0034		// Query wifi capablity(struct DHDEV_WIFI_ROUTE_CAP)
#define DH_DEVSTATE_ONLINE          0x0035      // Query device online state(return a DWORD value, 1-online, 0-offline)
#define DH_DEVSTATE_PTZ_LOCATION    0x0036      // Query ptz state(struct DH_PTZ_LOCATION_INFO)
#define DH_DEVSTATE_MONITOR_INFO    0x0037      // Query monitor state(state DHDEV_MONITOR_INFO)
#define DH_DEVSTATE_SUBDEVICE		0x0300		// Query subdevcie(fan,cpu...) state(struct CFG_DEVICESTATUS_INFO)
#define DH_DEVSTATE_RAID_INFO       0x0038      // Query RAID state(struct ALARM_RAID_INFO)  
#define DH_DEVSTATE_TEST_DDNSDOMAIN 0x0039      // test DDNS domain enable
#define DH_DEVSTATE_VIRTUALCAMERA   0x003a      // query virtual camera state(struct DHDEV_VIRTUALCAMERA_STATE_INFO)
#define DH_DEVSTATE_TRAFFICWORKSTATE 0x003b     // get device's state of video/coil module(struct DHDEV_TRAFFICWORKSTATE_INFO)
#define DH_DEVSTATE_ALARM_CAMERA_MOVE 0x003c    // get camera move alarm state(struct ALARM_CAMERA_MOVE_INFO)
#define DH_DEVSTATE_ALARM           0x003e      // get external alarm(struct NET_CLIENT_ALARM_STATE) 
#define DH_DEVSTATE_VIDEOLOST       0x003f      // get video loss alarm(struct NET_CLIENT_VIDEOLOST_STATE) 
#define DH_DEVSTATE_MOTIONDETECT    0x0040      // get motion alarm(struct NET_CLIENT_MOTIONDETECT_STATE)
#define DH_DEVSTATE_DETAILEDMOTION  0x0041      // get detailed motion alarm(struct NET_CLIENT_DETAILEDMOTION_STATE)


// Configuration type,corresponding to CLIENT_GetDevConfig and CLIENT_SetDevConfig
#define DH_DEV_DEVICECFG			0x0001		// Device property setup 
#define DH_DEV_NETCFG				0x0002		// Network setup 
#define DH_DEV_CHANNELCFG			0x0003		// Video channel setup
#define DH_DEV_PREVIEWCFG 			0x0004		// Preview parameter setup
#define DH_DEV_RECORDCFG			0x0005		// Record setup
#define DH_DEV_COMMCFG				0x0006		// COM property setup 
#define DH_DEV_ALARMCFG 			0x0007		// Alarm property setup
#define DH_DEV_TIMECFG 				0x0008		// DVR time setup 
#define DH_DEV_TALKCFG				0x0009		// Audio talk parameter setup 
#define DH_DEV_AUTOMTCFG			0x000A		// Auto matrix setup
#define	DH_DEV_VEDIO_MARTIX			0x000B		// Local matrix control strategy setup
#define DH_DEV_MULTI_DDNS			0x000C		//  Multiple ddns setup 
#define DH_DEV_SNAP_CFG				0x000D		// Snapshot corresponding setup 
#define DH_DEV_WEB_URL_CFG			0x000E		// HTTP path setup 
#define DH_DEV_FTP_PROTO_CFG		0x000F		// FTP upload setup 
#define DH_DEV_INTERVIDEO_CFG		0x0010		// Plaform embedded setup. Now the channel parameter represents the platform type. 
												// channel=4:Bell alcatel;channel=10:ZTE Netview;channel=11:U CNC  channel = 51 AMP
#define DH_DEV_VIDEO_COVER			0x0011		// Privacy mask setup
#define DH_DEV_TRANS_STRATEGY		0x0012		// Transmission strategy. Video quality\Fluency
#define DH_DEV_DOWNLOAD_STRATEGY	0x0013		//  Record download strategy setup:high-speed\general download
#define DH_DEV_WATERMAKE_CFG		0x0014		// Video watermark setup
#define DH_DEV_WLAN_CFG				0x0015		// Wireless network setup 
#define DH_DEV_WLAN_DEVICE_CFG		0x0016		// Search wireless device setup 
#define DH_DEV_REGISTER_CFG			0x0017		// Auto register parameter setup 
#define DH_DEV_CAMERA_CFG			0x0018		// Camera property setup 
#define DH_DEV_INFRARED_CFG 		0x0019		// IR alarm setup 
#define DH_DEV_SNIFFER_CFG			0x001A		// Sniffer setup 
#define DH_DEV_MAIL_CFG				0x001B		// Mail setup 
#define DH_DEV_DNS_CFG				0x001C		// DNS setup 
#define DH_DEV_NTP_CFG				0x001D		// NTP setup
#define DH_DEV_AUDIO_DETECT_CFG		0x001E		// Audio detection setup 
#define DH_DEV_STORAGE_STATION_CFG  0x001F      // Storage position setup 
#define DH_DEV_PTZ_OPT_CFG			0x0020		// PTZ operation property(It is invalid now. Please use CLIENT_GetPtzOptAttr to get PTZ operation property.)
#define DH_DEV_DST_CFG				0x0021      // Daylight Saving Time (DST)setup
#define DH_DEV_ALARM_CENTER_CFG		0x0022		// Alarm centre setup
#define DH_DEV_VIDEO_OSD_CFG        0x0023		// VIdeo OSD setup
#define DH_DEV_CDMAGPRS_CFG         0x0024		// CDMA\GPRS configuration

#define DH_DEV_IPFILTER_CFG         0x0025		// IP Filter configuration
#define DH_DEV_TALK_ENCODE_CFG      0x0026      // Talk encode configuration
#define DH_DEV_RECORD_PACKET_CFG    0X0027      // The length of the video package configuration
#define DH_DEV_MMS_CFG              0X0028		// SMS MMS configuration 
#define DH_DEV_SMSACTIVATION_CFG	0X0029		// SMS to activate the wireless connection configuration
#define DH_DEV_DIALINACTIVATION_CFG	0X002A		// Dial-up activation of a wireless connection configuration
#define DH_DEV_SNIFFER_CFG_EX		0x0030		// Capture network configuration
#define DH_DEV_DOWNLOAD_RATE_CFG	0x0031		// Download speed limit
#define DH_DEV_PANORAMA_SWITCH_CFG	0x0032		// Panorama switch alarm configuration
#define DH_DEV_LOST_FOCUS_CFG		0x0033		// Lose focus alarm configuration
#define DH_DEV_ALARM_DECODE_CFG		0x0034		// Alarm decoder configuration
#define DH_DEV_VIDEOOUT_CFG         0x0035      // Video output configuration
#define DH_DEV_POINT_CFG			0x0036		// Preset enable configuration
#define DH_DEV_IP_COLLISION_CFG     0x0037      // IP conflication configurationIp
#define DH_DEV_OSD_ENABLE_CFG		0x0038		// OSD overlay enable configuration
#define DH_DEV_LOCALALARM_CFG 		0x0039		// Local alarm configuration(Structure DH_ALARMIN_CFG_EX)
#define DH_DEV_NETALARM_CFG 		0x003A		// Network alarm configuration(Structure DH_ALARMIN_CFG_EX)
#define DH_DEV_MOTIONALARM_CFG 		0x003B		// Motion detection configuration(Structure DH_MOTION_DETECT_CFG_EX)
#define DH_DEV_VIDEOLOSTALARM_CFG 	0x003C		// Video loss configuration(Structure DH_VIDEO_LOST_CFG_EX)
#define DH_DEV_BLINDALARM_CFG 		0x003D		// Camera masking configuration(Structure DH_BLIND_CFG_EX)
#define DH_DEV_DISKALARM_CFG 		0x003E		// HDD alarm configuration(Structure DH_DISK_ALARM_CFG_EX)
#define DH_DEV_NETBROKENALARM_CFG 	0x003F		// Network disconnection alarm configuration(Structure DH_NETBROKEN_ALARM_CFG_EX)
#define DH_DEV_ENCODER_CFG          0x0040      // Digital channel info of front encoders(Hybrid DVR use,Structure DEV_ENCODER_CFG)
#define DH_DEV_TV_ADJUST_CFG        0x0041      // TV adjust configuration(Now the channel parameter represents the TV numble(from 0), Structure DHDEV_TVADJUST_CFG)
#define DH_DEV_ABOUT_VEHICLE_CFG	0x0042		// about vehicle configuration
#define DH_DEV_ATM_OVERLAY_ABILITY	0x0043		// ATM ability information
#define DH_DEV_ATM_OVERLAY_CFG		0x0044		// ATM overlay configuration
#define DH_DEV_DECODER_TOUR_CFG		0x0045		// Decoder tour configuration
#define DH_DEV_SIP_CFG				0x0046		// SIP configuration
#define DH_DEV_VICHILE_WIFI_AP_CFG	0x0047		// wifi ap configuration
#define DH_DEV_STATICALARM_CFG      0x0048      // Static 
#define DH_DEV_DECODE_POLICY_CFG    0x0049      // decode policy configuration(Structure DHDEV_DECODEPOLICY_CFG,channel start with 0) 
#define DH_DEV_MACHINE_CFG			0x004A		// Device relative config (Structure DHDEV_MACHINE_CFG)
#define DH_DEV_MAC_COLLISION_CFG    0x004B      // MACconflication configuration(Structure ALARM_MAC_COLLISION_CFG)
#define DH_DEV_RTSP_CFG             0x004C      // RTSP configuration(structure DHDEV_RTSP_CFG)
#define DH_DEV_232_COM_CARD_CFG     0x004E      // 232 com card signal event configuration(structure COM_CARD_SIGNAL_LINK_CFG)
#define DH_DEV_485_COM_CARD_CFG     0x004F      // 485 com card signal event configuration(structure COM_CARD_SIGNAL_LINK_CFG)
#define DH_DEV_FTP_PROTO_CFG_EX		0x0050		// extend FTP upload setup(Structure DHDEV_FTP_PROTO_CFG_EX)
#define DH_DEV_SYSLOG_REMOTE_SERVER	0x0051		// SYSLOG remote server config (Structure DHDEV_SYSLOG_REMOTE_SERVER)
#define DH_DEV_COMMCFG_EX           0x0052      // Extended com configuration(structure DHDEV_COMM_CFG_EX)
#define DH_DEV_NETCARD_CFG          0x0053      // net card configuration(structure DHDEV_NETCARD_CFG)
#define DH_DEV_BACKUP_VIDEO_FORMAT  0x0054		// Video backup format(structure DHDEV_BACKUP_VIDEO_FORMAT)
#define DH_DEV_STREAM_ENCRYPT_CFG   0x0055      // stream encrypt configuration(structure DHEDV_STREAM_ENCRYPT)
#define DH_DEV_IPFILTER_CFG_EX      0x0056		// IP filter extended configuration(structure DHDEV_IPIFILTER_CFG_EX)
#define DH_DEV_CUSTOM_CFG           0x0057      // custom configuration(structure DHDEV_CUSTOM_CFG)
#define DH_DEV_WLAN_DEVICE_CFG_EX   0x0058      // Search wireless device extended setup(structure DHDEV_WLAN_DEVICE_LIST_EX)
#define DH_DEV_ACC_POWEROFF_CFG     0x0059      // ACC power off configuration(structure DHDEV_ACC_POWEROFF_CFG)
#define DH_DEV_EXPLOSION_PROOF_CFG  0x005a      // explosion proof alarm configuration(structure DHDEV_EXPLOSION_PROOF_CFG)
#define DH_DEV_NETCFG_EX			0x005b		// Network extended setup(struct DHDEV_NET_CFG_EX)
#define DH_DEV_LIGHTCONTROL_CFG     0x005c      // light control config(struct DHDEV_LIGHTCONTROL_CFG)
#define DH_DEV_3GFLOW_CFG           0x005d      // 3G flow info config(struct DHDEV_3GFLOW_INFO_CFG)
#define DH_DEV_IPV6_CFG             0x005e      // IPv6 config(struct DHDEV_IPV6_CFG)
#define DH_DEV_SNMP_CFG             0X005f      // Snmp config(struct DHDEV_NET_SNMP_CFG)
#define DH_DEV_SNAP_CONTROL_CFG     0x0060      // snap control config(struct DHDEV_SNAP_CONTROL_CFG)
#define DH_DEV_GPS_MODE_CFG         0X0061      // GPS mode config(struct DHDEV_GPS_MODE_CFG)
#define DH_DEV_SNAP_UPLOAD_CFG      0X0062      // Snap upload config(struct DHDEV_SNAP_UPLOAD_CFG)
#define DH_DEV_SPEED_LIMIT_CFG      0x0063      // Speed limit config(struct DHDEV_SPEED_LIMIT_CFG)
#define DH_DEV_ISCSI_CFG			0x0064		// iSCSI config(struct DHDEV_ISCSI_CFG), need reboot
#define DH_DEV_WIRELESS_ROUTING_CFG	0x0065		// wifi config(struc DHDEV_WIRELESS_ROUTING_CFG)
#define DH_DEV_ENCLOSURE_CFG        0x0066      // enclosure config(stuct DHDEV_ENCLOSURE_CFG)
#define DH_DEV_ENCLOSURE_VERSION_CFG 0x0067     // enclosure version config(struct DHDEV_ENCLOSURE_VERSION_CFG)
#define DH_DEV_RIAD_EVENT_CFG        0x0068     // Raid event config(struct DHDEV_RAID_EVENT_CFG)
#define DH_DEV_FIRE_ALARM_CFG        0x0069     // fire alarm config(struct DHDEV_FIRE_ALARM_CFG)
#define DH_DEV_LOCALALARM_NAME_CFG   0x006a     // local alarm name config(string like "Name1&&name2&&name3...")
#define DH_DEV_URGENCY_RECORD_CFG    0x0070     // urgency storage config(struct DHDEV_URGENCY_RECORD_CFG)
#define DH_DEV_ELEVATOR_ATTRI_CFG    0x0071     // elevator parameter config(struct DHDEV_ELEVATOR_ATTRI_CFG)
#define DH_DEV_USER_END_CFG			1000

// Alarm type, corresponding to CLIENT_StartListen
#define DH_COMM_ALARM				0x1100		// General alarm(Including external alarm, video loss and motion detection)
#define DH_SHELTER_ALARM			0x1101		// Camera masking alarm 
#define DH_DISK_FULL_ALARM			0x1102		// HDD full alarm 
#define DH_DISK_ERROR_ALARM			0x1103		// HDD malfunction alarm 
#define DH_SOUND_DETECT_ALARM		0x1104		// Audio detection alarm 
#define DH_ALARM_DECODER_ALARM		0x1105		// Alarm decoder alarm 

// Extensive alarm type,corresponding to CLIENT_StartListenEx
#define DH_ALARM_ALARM_EX			0x2101		// External alarm 
#define DH_MOTION_ALARM_EX			0x2102		// Motion detection alarm 
#define DH_VIDEOLOST_ALARM_EX		0x2103		// Video loss alarm 
#define DH_SHELTER_ALARM_EX			0x2104		// Camera masking alarm 
#define DH_SOUND_DETECT_ALARM_EX	0x2105		// Audio detection alarm 
#define DH_DISKFULL_ALARM_EX		0x2106		// HDD full alarm 
#define DH_DISKERROR_ALARM_EX		0x2107		// HDD malfunction alarm 
#define DH_ENCODER_ALARM_EX			0x210A		// Encoder alarm 
#define DH_URGENCY_ALARM_EX			0x210B		// Emergency alarm 
#define DH_WIRELESS_ALARM_EX		0x210C		// Wireless alarm 
#define DH_NEW_SOUND_DETECT_ALARM_EX 0x210D		// New auido detection alarm. Please refer to DH_NEW_SOUND_ALARM_STATE for alarm information structure;
#define DH_ALARM_DECODER_ALARM_EX	0x210E		// Alarm decoder alarm 
#define DH_DECODER_DECODE_ABILITY	0x210F		// NVD:Decoding capacity
#define DH_FDDI_DECODER_ABILITY		0x2110		// Fiber encoder alarm
#define DH_PANORAMA_SWITCH_ALARM_EX	0x2111		// Panorama switch alarm
#define DH_LOSTFOCUS_ALARM_EX		0x2112		// Lost focus alarm
#define DH_OEMSTATE_EX				0x2113		// oem state
#define DH_DSP_ALARM_EX				0x2114		// DSP alarm
#define DH_ATMPOS_BROKEN_EX			0x2115		// atm and pos disconnection alarm, 0:disconnection 1:connection
#define DH_RECORD_CHANGED_EX		0x2116		// Record state changed alarm
#define DH_CONFIG_CHANGED_EX		0x2117		// Device config changed alarm
#define DH_DEVICE_REBOOT_EX			0x2118		// Device rebooting alarm
#define DH_WINGDING_ALARM_EX        0x2119      // CoilFault alarm
#define DH_TRAF_CONGESTION_ALARM_EX 0x211A      // traffic congestion alarm
#define DH_TRAF_EXCEPTION_ALARM_EX  0x211B      // traffic exception alarm
#define DH_EQUIPMENT_FILL_ALARM_EX  0x211C      // FlashFault alarm
#define DH_ALARM_ARM_DISARM_STATE	0x211D		// alarm arm disarm 
#define DH_ALARM_ACC_POWEROFF       0x211E      // ACC power off alarm
#define DH_ALARM_3GFLOW_EXCEED      0x211F      // Alarm of 3G flow exceed(see struct DHDEV_3GFLOW_EXCEED_STATE_INFO)
#define DH_ALARM_SPEED_LIMIT        0x2120      // Speed limit alarm 
#define DH_ALARM_VEHICLE_INFO_UPLOAD  0x2121    // Vehicle information uploading 
#define DH_STATIC_ALARM_EX          0x2122      // Static detection alarm
#define DH_PTZ_LOCATION_EX          0x2123      // ptz location info
#define DH_ALARM_CARD_RECORD_UPLOAD	0x2124		// card record info(struct ALARM_CARD_RECORD_INFO_UPLOAD)
#define DH_ALARM_ATM_INFO_UPLOAD	0x2125		// ATM trade info(struct ALARM_ATM_INFO_UPLOAD)
#define DH_ALARM_ENCLOSURE          0x2126      // enclosure alarm(struct ALARM_ENCLOSURE_INFO)
#define DH_ALARM_SIP_STATE          0x2127      // SIP state alarm(struct ALARM_SIP_STATE)
#define DH_ALARM_RAID_STATE         0x2128      // RAID state alarm(struct ALARM_RAID_INFO)
#define DH_ALARM_CROSSING_SPEED_LIMIT 0x2129	// crossing speed limit alarm(struct ALARM_SPEED_LIMIT)
#define DH_ALARM_OVER_LOADING         0x212A      // over loading alarm(struct ALARM_OVER_LOADING)
#define DH_ALARM_HARD_BRAKING         0x212B      // hard brake alarm(struct ALARM_HARD_BRAKING)
#define DH_ALARM_SMOKE_SENSOR         0x212C      // smoke sensor alarm(struct ALARM_SMOKE_SENSOR)
#define DH_ALARM_TRAFFIC_LIGHT_FAULT 0x212D     // traffic light fault alarm(struct ALARM_TRAFFIC_LIGHT_FAULT) 
#define DH_ALARM_TRAFFIC_FLUX_STAT   0x212E     // traffic flux alarm(struct ALARM_TRAFFIC_FLUX_LANE_INFO)
#define DH_ALARM_CAMERA_MOVE         0x212F     // camera move alarm(struct ALARM_CAMERA_MOVE_INFO)
#define DH_ALARM_DETAILEDMOTION      0x2130     // detailed motion alarm(struct ALARM_DETAILEDMOTION_CHNL_INFO)
#define DH_ALARM_STORAGE_FAILURE     0x2131     // storage failure alarm(struct ALARM_STORAGE_FAILURE)
#define DH_ALARM_FRONTDISCONNECT     0x2132     // front IPC disconnect alarm(struct ALARM_FRONTDISCONNET_INFO)
#define DH_ALARM_ALARM_EX_REMOTE     0x2133     // remote external alarm
#define DH_ALARM_BATTERYLOWPOWER     0x2134     // battery low power alarm(struct ALARM_BATTERYLOWPOWER_INFO)
#define DH_ALARM_TEMPERATURE         0x2135     // temperature alarm(struct ALARM_TEMPERATURE_INFO)
#define DH_ALARM_TIREDDRIVE          0x2136     // tired drive alarm(struct ALARM_TIREDDRIVE_INFO)
#define DH_ALARM_LOST_RECORD         0x2137     // Alarm of record loss (corresponding structure ALARM_LOST_RECORD)
#define DH_ALARM_HIGH_CPU            0x2138     // Alarm of High CPU Occupancy rate (corresponding structure ALARM_HIGH_CPU) 
#define DH_ALARM_LOST_NETPACKET      0x2139     // Alarm of net package loss (corresponding structure ALARM_LOST_NETPACKET)
#define DH_ALARM_HIGH_MEMORY         0x213A     // Alarm of high memory occupancy rate(corresponding structure ALARM_HIGH_MEMORY)
#define DH_LONG_TIME_NO_OPERATION	 0X213B	    //WEB user have no operation for long time (no extended info)

// Event type
#define DH_CONFIG_RESULT_EVENT_EX	0x3000		// Modify the return code of the setup. Please refer to DEV_SET_RESULT for returned structure.
#define DH_REBOOT_EVENT_EX			0x3001		//  Device reboot event. Current modification becomes valid unitl sending out the reboot command. 
#define DH_AUTO_TALK_START_EX		0x3002		// Device automatically invites to begin audio talk 
#define DH_AUTO_TALK_STOP_EX		0x3003		// Device actively stop audio talk 
#define DH_CONFIG_CHANGE_EX			0x3004		// Device setup changes.
#define DH_IPSEARCH_EVENT_EX        0x3005      // IP search event, the return value format is:DevName:::Manufacturer::MAC:: IP:: Port&& DevName:: Manufacturer::MAC:: IP:: Port&&?-
#define DH_AUTO_RECONNECT_FAILD     0x3006      // reconnect failed
#define DH_REALPLAY_FAILD_EVENT     0x3007      // real play failed
#define DH_PLAYBACK_FAILD_EVENT     0x3008      // playback failed

// Alarm type of alarm upload function,corresponding to CLIENT_StartService?¡éNEW_ALARM_UPLOAD structure.
#define DH_UPLOAD_ALARM					0x4000		// External alarm 		
#define DH_UPLOAD_MOTION_ALARM			0x4001		// Motion detection alarm 
#define DH_UPLOAD_VIDEOLOST_ALARM		0x4002		//Video loss alarm 
#define DH_UPLOAD_SHELTER_ALARM			0x4003		// Camera masking alarm 
#define DH_UPLOAD_SOUND_DETECT_ALARM	0x4004		//Audio detection alarm 
#define DH_UPLOAD_DISKFULL_ALARM		0x4005		// HDD full alarm 
#define DH_UPLOAD_DISKERROR_ALARM		0x4006		// HDD malfunction alarm 
#define DH_UPLOAD_ENCODER_ALARM			0x4007		//Encoder alarm 
#define DH_UPLOAD_DECODER_ALARM			0x400B		// Alarm decoder alarm 
#define DH_UPLOAD_EVENT					0x400C		// Scheduled upload 

// Asynchronous interface callback type
#define RESPONSE_DECODER_CTRL_TV	0x00000001		// refer to CLIENT_CtrlDecTVScreen interface
#define RESPONSE_DECODER_SWITCH_TV	0x00000002		// refer to CLIENT_SwitchDecTVEncoder interface
#define RESPONSE_DECODER_PLAYBACK	0x00000003		// refer to CLIENT_DecTVPlayback interface

// CLIENT_FileTransmit Interface transmission file type
#define DH_DEV_UPGRADEFILETRANS_START	0x0000		// Begin sending update file(Corresponding structure DHDEV_UPGRADE_FILE_INFO)
#define DH_DEV_UPGRADEFILETRANS_SEND	0x0001		// Send update file  
#define DH_DEV_UPGRADEFILETRANS_STOP	0x0002		// Stop sending update file
#define DH_DEV_FILETRANS_STOP			0x002B		// Stop file upload
#define DH_DEV_FILETRANS_BURN			0x002C		// Burn File Upload

// Resolution list. Use to AND & OR of resolution subnet mask 
#define	DH_CAPTURE_SIZE_D1			0x00000001
#define DH_CAPTURE_SIZE_HD1			0x00000002
#define DH_CAPTURE_SIZE_BCIF		0x00000004
#define DH_CAPTURE_SIZE_CIF			0x00000008
#define DH_CAPTURE_SIZE_QCIF		0x00000010	
#define DH_CAPTURE_SIZE_VGA			0x00000020	
#define DH_CAPTURE_SIZE_QVGA		0x00000040
#define DH_CAPTURE_SIZE_SVCD		0x00000080
#define DH_CAPTURE_SIZE_QQVGA		0x00000100
#define DH_CAPTURE_SIZE_SVGA		0x00000200
#define DH_CAPTURE_SIZE_XVGA		0x00000400
#define DH_CAPTURE_SIZE_WXGA		0x00000800
#define DH_CAPTURE_SIZE_SXGA		0x00001000
#define DH_CAPTURE_SIZE_WSXGA		0x00002000   
#define DH_CAPTURE_SIZE_UXGA		0x00004000
#define DH_CAPTURE_SIZE_WUXGA       0x00008000
#define DH_CAPTURE_SIZE_LFT         0x00010000
#define DH_CAPTURE_SIZE_720		    0x00020000
#define DH_CAPTURE_SIZE_1080		0x00040000
#define DH_CAPTURE_SIZE_1_3M        0x00080000
#define DH_CAPTURE_SIZE_2M			0x00100000
#define DH_CAPTURE_SIZE_5M			0x00200000
#define DH_CAPTURE_SIZE_3M			0x00400000	
#define DH_CAPTURE_SIZE_5_0M        0x00800000
#define DH_CPTRUTE_SIZE_1_2M 		0x01000000
#define DH_CPTRUTE_SIZE_1408_1024   0x02000000
#define DH_CPTRUTE_SIZE_8M	        0x04000000	
#define DH_CPTRUTE_SIZE_2560_1920   0x08000000
#define DH_CAPTURE_SIZE_960H        0x10000000	
#define DH_CAPTURE_SIZE_960_720     0x20000000				

// Encode mode list. Use to work AND & OR operation of encode mode mask.
#define DH_CAPTURE_COMP_DIVX_MPEG4	0x00000001
#define DH_CAPTURE_COMP_MS_MPEG4 	0x00000002
#define DH_CAPTURE_COMP_MPEG2		0x00000004
#define DH_CAPTURE_COMP_MPEG1		0x00000008
#define DH_CAPTURE_COMP_H263		0x00000010
#define DH_CAPTURE_COMP_MJPG		0x00000020
#define DH_CAPTURE_COMP_FCC_MPEG4	0x00000040
#define DH_CAPTURE_COMP_H264		0x00000080

// Alarm activation operation. Use to work AND & OR operation of alarm activation operation.
#define DH_ALARM_UPLOAD				0x00000001
#define DH_ALARM_RECORD				0x00000002
#define DH_ALARM_PTZ				0x00000004
#define DH_ALARM_MAIL				0x00000008
#define DH_ALARM_TOUR				0x00000010
#define DH_ALARM_TIP				0x00000020
#define DH_ALARM_OUT				0x00000040
#define DH_ALARM_FTP_UL				0x00000080
#define DH_ALARM_BEEP				0x00000100
#define DH_ALARM_VOICE				0x00000200
#define DH_ALARM_SNAP				0x00000400

// Restore default setup mask. Can use to AND & OR operation
#define DH_RESTORE_COMMON			0x00000001	// General setup
#define DH_RESTORE_CODING			0x00000002	// Encode setup
#define DH_RESTORE_VIDEO			0x00000004	// Record setup
#define DH_RESTORE_COMM				0x00000008	// COM setup
#define DH_RESTORE_NETWORK			0x00000010	//network setup
#define DH_RESTORE_ALARM			0x00000020	// Alarm setup
#define DH_RESTORE_VIDEODETECT		0x00000040	// Video detection
#define DH_RESTORE_PTZ				0x00000080	// PTZ control 
#define DH_RESTORE_OUTPUTMODE		0x00000100	// Output mode
#define DH_RESTORE_CHANNELNAME		0x00000200	// Channel name
#define DH_RESTORE_VIDEOINOPTIONS   0x00000400  // Camera attribute
#define DH_RESTORE_CPS              0x00000800  // TrafficSnapshot
#define DH_RESTORE_INTELLIGENT      0x00001000  // Intelligent Component
#define DH_RESTORE_REMOTEDEVICE     0x00002000  // Remote device configuration
#define DH_RESTORE_ALL				0x80000000	// Reset all

// PTZ property list
// Lower four bytes subnet mask
#define PTZ_DIRECTION				0x00000001	// Direction
#define PTZ_ZOOM					0x00000002	// Zoom
#define PTZ_FOCUS					0x00000004	// Focus
#define PTZ_IRIS					0x00000008	// Aperture
#define PTZ_ALARM					0x00000010	// Alarm function 
#define PTZ_LIGHT					0x00000020	// Light 
#define PTZ_SETPRESET				0x00000040	// Set preset 
#define PTZ_CLEARPRESET				0x00000080	// Delete preset
#define PTZ_GOTOPRESET				0x00000100	// Go to a preset
#define PTZ_AUTOPANON				0x00000200	// Enable pan
#define PTZ_AUTOPANOFF				0x00000400	// isable pan
#define PTZ_SETLIMIT				0x00000800	// Set limit
#define PTZ_AUTOSCANON				0x00001000	// Enable auto scan
#define PTZ_AUTOSCANOFF				0x00002000	// Disable auto scan 
#define PTZ_ADDTOUR					0x00004000	// Add tour point
#define PTZ_DELETETOUR				0x00008000	// Delete tour point
#define PTZ_STARTTOUR				0x00010000	// Begin tour
#define PTZ_STOPTOUR				0x00020000	// Stop tour
#define PTZ_CLEARTOUR				0x00040000	// Delete tour
#define PTZ_SETPATTERN				0x00080000	// Set pattern
#define PTZ_STARTPATTERN			0x00100000	// Enbale pattern
#define PTZ_STOPPATTERN				0x00200000	// Disable pattern
#define PTZ_CLEARPATTERN			0x00400000	// Delete pattern
#define PTZ_POSITION				0x00800000	// Position 
#define PTZ_AUX						0x01000000	// auxiliary button 
#define PTZ_MENU					0x02000000	// Speed dome menu 
#define PTZ_EXIT					0x04000000	// Exit speed dome menu 
#define PTZ_ENTER					0x08000000	// Confirm
#define PTZ_ESC						0x10000000	// Cancel 
#define PTZ_MENUUPDOWN				0x20000000	// Menu up/down
#define PTZ_MENULEFTRIGHT			0x40000000	// Menu left/right 
#define PTZ_OPT_NUM					0x80000000	// Operation amount
// Higher four bytes subnet mask
#define PTZ_DEV						0x00000001	// PTZ control 
#define PTZ_MATRIX					0x00000002	// Matrix control 

// Snapshot video encode type
#define CODETYPE_MPEG4				0
#define CODETYPE_H264				1
#define CODETYPE_JPG				2

// Bit stream control control list
#define DH_CAPTURE_BRC_CBR			0
#define DH_CAPTURE_BRC_VBR			1
//#define DH_CAPTURE_BRC_MBR		2

// the type of intelligent analysis event 
#define EVENT_IVS_ALL						0x00000001		// subscription all event
#define EVENT_IVS_CROSSLINEDETECTION		0x00000002		// cross line event
#define EVENT_IVS_CROSSREGIONDETECTION		0x00000003		// cross region event
#define EVENT_IVS_PASTEDETECTION			0x00000004		// past event
#define EVENT_IVS_LEFTDETECTION				0x00000005		// left event 
#define EVENT_IVS_STAYDETECTION				0x00000006		// stay event
#define EVENT_IVS_WANDERDETECTION			0x00000007		// wander event
#define EVENT_IVS_PRESERVATION				0x00000008		// reservation event 
#define EVENT_IVS_MOVEDETECTION				0x00000009		// move event
#define EVENT_IVS_TAILDETECTION				0x0000000A		// tail event
#define EVENT_IVS_RIOTERDETECTION			0x0000000B		// rioter event
#define EVENT_IVS_FIREDETECTION				0x0000000C		// fire event
#define EVENT_IVS_SMOKEDETECTION			0x0000000D		// smoke event
#define EVENT_IVS_FIGHTDETECTION			0x0000000E		// fight event
#define EVENT_IVS_FLOWSTAT					0x0000000F		// flow stat event
#define EVENT_IVS_NUMBERSTAT				0x00000010		// number stat event
#define EVENT_IVS_CAMERACOVERDDETECTION		0x00000011		// camera cover event
#define EVENT_IVS_CAMERAMOVEDDETECTION		0x00000012		// camera move event
#define EVENT_IVS_VIDEOABNORMALDETECTION	0x00000013		// video abnormal event
#define EVENT_IVS_VIDEOBADDETECTION			0x00000014		// video bad event
#define EVENT_IVS_TRAFFICCONTROL			0x00000015		// traffic control event
#define EVENT_IVS_TRAFFICACCIDENT			0x00000016		// traffic accident event
#define EVENT_IVS_TRAFFICJUNCTION			0x00000017		// traffic junction event
#define EVENT_IVS_TRAFFICGATE				0x00000018		// traffic gate event
#define EVENT_TRAFFICSNAPSHOT				0x00000019		// traffic snapshot
#define EVENT_IVS_FACEDETECT                0x0000001A      // face detection
#define EVENT_IVS_TRAFFICJAM                0x0000001B      // traffic-Jam
#define EVENT_IVS_TRAFFIC_RUNREDLIGHT		0x00000100		// traffic-RunRedLight
#define EVENT_IVS_TRAFFIC_OVERLINE			0x00000101		// traffic-Overline
#define EVENT_IVS_TRAFFIC_RETROGRADE		0x00000102		// traffic-Retrograde
#define EVENT_IVS_TRAFFIC_TURNLEFT			0x00000103		// traffic-TurnLeft
#define EVENT_IVS_TRAFFIC_TURNRIGHT			0x00000104		// traffic-TurnRight	
#define EVENT_IVS_TRAFFIC_UTURN				0x00000105		// traffic-Uturn
#define EVENT_IVS_TRAFFIC_OVERSPEED			0x00000106		// traffic-Overspeed
#define EVENT_IVS_TRAFFIC_UNDERSPEED		0x00000107		// traffic-Underspeed
#define EVENT_IVS_TRAFFIC_PARKING           0x00000108      // traffic-Parking
#define EVENT_IVS_TRAFFIC_WRONGROUTE        0x00000109      // traffic-WrongRoute
#define EVENT_IVS_TRAFFIC_CROSSLANE         0x0000010A      // traffic-CrossLane
#define EVENT_IVS_TRAFFIC_OVERYELLOWLINE    0x0000010B      // traffic-OverYellowLine
#define EVENT_IVS_TRAFFIC_DRIVINGONSHOULDER 0x0000010C      // traffic-DrivingOnShoulder   
#define EVENT_IVS_TRAFFIC_YELLOWPLATEINLANE 0x0000010E      // traffic-YellowPlateInLane
#define EVENT_IVS_TRAFFIC_PEDESTRAINPRIORITY 0x0000010F		// Traffic offense-Pedestral has higher priority at the  crosswalk
#define EVENT_IVS_CROSSFENCEDETECTION       0x0000011F      // cross fence 
#define EVENT_IVS_ELECTROSPARKDETECTION     0x00000110      // ElectroSpark event 
#define EVENT_IVS_TRAFFIC_NOPASSING         0x00000111      // no passing
#define EVENT_IVS_ABNORMALRUNDETECTION      0x00000112      // abnormal run
#define EVENT_IVS_RETROGRADEDETECTION       0x00000113      // retrograde
#define EVENT_IVS_INREGIONDETECTION         0x00000114      // in region detection
#define EVENT_IVS_TAKENAWAYDETECTION        0x00000115      // taking away things
#define EVENT_IVS_PARKINGDETECTION          0x00000116      // parking
#define EVENT_IVS_FACERECOGNITION			0x00000117		// face recognition
#define EVENT_IVS_TRAFFIC_MANUALSNAP        0x00000118      // manual snap
#define EVENT_IVS_TRAFFIC_FLOWSTATE			0x00000119		// traffic flow state
#define EVENT_IVS_TRAFFIC_STAY				0x0000011A		// traffic stay
#define EVENT_IVS_TRAFFIC_VEHICLEINROUTE	0x0000011B		// traffic vehicle route
#define EVENT_ALARM_MOTIONDETECT            0x0000011C      // motion detect
#define EVENT_ALARM_LOCALALARM              0x0000011D      // local alarm
#define EVENT_IVS_PRISONERRISEDETECTION		0x0000011E		// prisoner rise detect
#define EVENT_IVS_TRAFFIC_TOLLGATE			0x00000120		// traffic tollgate
#define EVENT_IVS_DENSITYDETECTION			0x00000121      // density detection of persons
#define EVENT_IVS_VIDEODIAGNOSIS            0x00000122		// video diagnosis result
#define EVENT_IVS_QUEUEDETECTION            0x00000123      // Queue detection

//
#define EVENT_IVS_TRAFFIC_ALL				0x000001FF		// All event start with [TRAFFIC]
															// EVENT_IVS_TRAFFICCONTROL -> EVENT_TRAFFICSNAPSHOT
															// EVENT_IVS_TRAFFIC_RUNREDLIGHT -> EVENT_IVS_TRAFFIC_UNDERSPEED
// Error type code. Corresponding to the return value of CLIENT_GetLastError
#define _EC(x)						(0x80000000|x)
#define NET_NOERROR 				0			// No error 
#define NET_ERROR					-1			// Unknown error
#define NET_SYSTEM_ERROR			_EC(1)		// Windows system error
#define NET_NETWORK_ERROR			_EC(2)		// Protocol error it may result from network timeout
#define NET_DEV_VER_NOMATCH			_EC(3)		// Device protocol does not match 
#define NET_INVALID_HANDLE			_EC(4)		// Handle is invalid
#define NET_OPEN_CHANNEL_ERROR		_EC(5)		// Failed to open channel 
#define NET_CLOSE_CHANNEL_ERROR		_EC(6)		// Failed to close channel 
#define NET_ILLEGAL_PARAM			_EC(7)		// User parameter is illegal 
#define NET_SDK_INIT_ERROR			_EC(8)		// SDK initialization error 
#define NET_SDK_UNINIT_ERROR		_EC(9)		// SDK clear error 
#define NET_RENDER_OPEN_ERROR		_EC(10)		// Error occurs when apply for render resources.
#define NET_DEC_OPEN_ERROR			_EC(11)		// Error occurs when opening the decoder library 
#define NET_DEC_CLOSE_ERROR			_EC(12)		// Error occurs when closing the decoder library 
#define NET_MULTIPLAY_NOCHANNEL		_EC(13)		// The detected channel number is 0 in multiple-channel preview. 
#define NET_TALK_INIT_ERROR			_EC(14)		// Failed to initialize record library 
#define NET_TALK_NOT_INIT			_EC(15)		// The record library has not been initialized
#define	NET_TALK_SENDDATA_ERROR		_EC(16)		// Error occurs when sending out audio data 
#define NET_REAL_ALREADY_SAVING		_EC(17)		// The real-time has been protected.
#define NET_NOT_SAVING				_EC(18)		// The real-time data has not been save.
#define NET_OPEN_FILE_ERROR			_EC(19)		// Error occurs when opening the file.
#define NET_PTZ_SET_TIMER_ERROR		_EC(20)		// Failed to enable PTZ to control timer.
#define NET_RETURN_DATA_ERROR		_EC(21)		// Error occurs when verify returned data.
#define NET_INSUFFICIENT_BUFFER		_EC(22)		// There is no sufficient buffer.
#define NET_NOT_SUPPORTED			_EC(23)		// The current SDK does not support this fucntion.
#define NET_NO_RECORD_FOUND			_EC(24)		// There is no searched result.
#define NET_NOT_AUTHORIZED			_EC(25)		// You have no operation right.
#define NET_NOT_NOW					_EC(26)		// Can not operate right now. 
#define NET_NO_TALK_CHANNEL			_EC(27)		// There is no audio talk channel.
#define NET_NO_AUDIO				_EC(28)		// There is no audio.
#define NET_NO_INIT					_EC(29)		// The network SDK has not been initialized.
#define NET_DOWNLOAD_END			_EC(30)		// The download completed.
#define NET_EMPTY_LIST				_EC(31)		// There is no searched result.
#define NET_ERROR_GETCFG_SYSATTR	_EC(32)		// Failed to get system property setup.
#define NET_ERROR_GETCFG_SERIAL		_EC(33)		// Failed to get SN.
#define NET_ERROR_GETCFG_GENERAL	_EC(34)		// Failed to get general property.
#define NET_ERROR_GETCFG_DSPCAP		_EC(35)		// Failed to get DSP capacity description.
#define NET_ERROR_GETCFG_NETCFG		_EC(36)		// Failed to get network channel setup.
#define NET_ERROR_GETCFG_CHANNAME	_EC(37)		// Failed to get channel name.
#define NET_ERROR_GETCFG_VIDEO		_EC(38)		// Failed to get video property.
#define NET_ERROR_GETCFG_RECORD		_EC(39)		// Failed to get record setup
#define NET_ERROR_GETCFG_PRONAME	_EC(40)		// Failed to get decoder protocol name 
#define NET_ERROR_GETCFG_FUNCNAME	_EC(41)		// Failed to get 232 COM function name.
#define NET_ERROR_GETCFG_485DECODER	_EC(42)		// Failed to get decoder property
#define NET_ERROR_GETCFG_232COM		_EC(43)		// Failed to get 232 COM setup
#define NET_ERROR_GETCFG_ALARMIN	_EC(44)		// Failed to get external alarm input setup
#define NET_ERROR_GETCFG_ALARMDET	_EC(45)		// Failed to get motion detection alarm
#define NET_ERROR_GETCFG_SYSTIME	_EC(46)		// Failed to get device time
#define NET_ERROR_GETCFG_PREVIEW	_EC(47)		// Failed to get preview parameter
#define NET_ERROR_GETCFG_AUTOMT		_EC(48)		// Failed to get audio maintenance setup
#define NET_ERROR_GETCFG_VIDEOMTRX	_EC(49)		// Failed to get video matrix setup
#define NET_ERROR_GETCFG_COVER		_EC(50)		// Failed to get privacy mask zone setup
#define NET_ERROR_GETCFG_WATERMAKE	_EC(51)		// Failed to get video watermark setup
#define NET_ERROR_SETCFG_GENERAL	_EC(55)		// Failed to modify general property
#define NET_ERROR_SETCFG_NETCFG		_EC(56)		// Failed to modify channel setup
#define NET_ERROR_SETCFG_CHANNAME	_EC(57)		// Failed to modify channel name
#define NET_ERROR_SETCFG_VIDEO		_EC(58)		// Failed to modify video channel 
#define NET_ERROR_SETCFG_RECORD		_EC(59)		// Failed to modify record setup 
#define NET_ERROR_SETCFG_485DECODER	_EC(60)		// Failed to modify decoder property 
#define NET_ERROR_SETCFG_232COM		_EC(61)		// Failed to modify 232 COM setup 
#define NET_ERROR_SETCFG_ALARMIN	_EC(62)		// Failed to modify external input alarm setup
#define NET_ERROR_SETCFG_ALARMDET	_EC(63)		// Failed to modify motion detection alarm setup 
#define NET_ERROR_SETCFG_SYSTIME	_EC(64)		// Failed to modify device time 
#define NET_ERROR_SETCFG_PREVIEW	_EC(65)		// Failed to modify preview parameter
#define NET_ERROR_SETCFG_AUTOMT		_EC(66)		// Failed to modify auto maintenance setup 
#define NET_ERROR_SETCFG_VIDEOMTRX	_EC(67)		// Failed to modify video matrix setup 
#define NET_ERROR_SETCFG_COVER		_EC(68)		// Failed to modify privacy mask zone
#define NET_ERROR_SETCFG_WATERMAKE	_EC(69)		// Failed to modify video watermark setup 
#define NET_ERROR_SETCFG_WLAN		_EC(70)		// Failed to modify wireless network information 
#define NET_ERROR_SETCFG_WLANDEV	_EC(71)		// Failed to select wireless network device
#define NET_ERROR_SETCFG_REGISTER	_EC(72)		// Failed to modify the actively registration parameter setup.
#define NET_ERROR_SETCFG_CAMERA		_EC(73)		// Failed to modify camera property
#define NET_ERROR_SETCFG_INFRARED	_EC(74)		// Failed to modify IR alarm setup
#define NET_ERROR_SETCFG_SOUNDALARM	_EC(75)		// Failed to modify audio alarm setup
#define NET_ERROR_SETCFG_STORAGE    _EC(76)		// Failed to modify storage position setup
#define NET_AUDIOENCODE_NOTINIT		_EC(77)		// The audio encode port has not been successfully initialized. 
#define NET_DATA_TOOLONGH			_EC(78)		// The data are too long.
#define NET_UNSUPPORTED				_EC(79)		// The device does not support current operation. 
#define NET_DEVICE_BUSY				_EC(80)		// Device resources is not sufficient.
#define NET_SERVER_STARTED			_EC(81)		// The server has boot up 
#define NET_SERVER_STOPPED			_EC(82)		// The server has not fully boot up 
#define NET_LISTER_INCORRECT_SERIAL	_EC(83)		// Input serial number is not correct.
#define NET_QUERY_DISKINFO_FAILED	_EC(84)		// Failed to get HDD information.
#define NET_ERROR_GETCFG_SESSION	_EC(85)		// Failed to get connect session information.
#define NET_USER_FLASEPWD_TRYTIME	_EC(86)		// The password you typed is incorrect. You have exceeded the maximum number of retries.
#define NET_LOGIN_ERROR_PASSWORD	_EC(100)	// Password is not correct
#define NET_LOGIN_ERROR_USER		_EC(101)	// The account does not exist
#define NET_LOGIN_ERROR_TIMEOUT		_EC(102)	// Time out for log in returned value.
#define NET_LOGIN_ERROR_RELOGGIN	_EC(103)	// The account has logged in 
#define NET_LOGIN_ERROR_LOCKED		_EC(104)	// The account has been locked
#define NET_LOGIN_ERROR_BLACKLIST	_EC(105)	// The account bas been in the black list
#define NET_LOGIN_ERROR_BUSY		_EC(106)	// Resources are not sufficient. System is busy now.
#define NET_LOGIN_ERROR_CONNECT		_EC(107)	// Time out. Please check network and try again.
#define NET_LOGIN_ERROR_NETWORK		_EC(108)	// Network connection failed.
#define NET_LOGIN_ERROR_SUBCONNECT	_EC(109)	// Successfully logged in the device but can not create video channel. Please check network connection.
#define NET_LOGIN_ERROR_MAXCONNECT  _EC(110)    // exceed the max connect number
#define NET_LOGIN_ERROR_PROTOCOL3_ONLY _EC(111)	// protocol 3 support
#define NET_LOGIN_ERROR_UKEY_LOST	_EC(112)	// There is no USB or USB info error
#define NET_LOGIN_ERROR_NO_AUTHORIZED _EC(113)  // Client-end IP address has no right to login
#define NET_RENDER_SOUND_ON_ERROR	_EC(120)	// Error occurs when Render library open audio.
#define NET_RENDER_SOUND_OFF_ERROR	_EC(121)	// Error occurs when Render library close audio 
#define NET_RENDER_SET_VOLUME_ERROR	_EC(122)	// Error occurs when Render library control volume
#define NET_RENDER_ADJUST_ERROR		_EC(123)	// Error occurs when Render library set video parameter
#define NET_RENDER_PAUSE_ERROR		_EC(124)	// Error occurs when Render library pause play
#define NET_RENDER_SNAP_ERROR		_EC(125)	// Render library snapshot error
#define NET_RENDER_STEP_ERROR		_EC(126)	// Render library stepper error
#define NET_RENDER_FRAMERATE_ERROR	_EC(127)	// Error occurs when Render library set frame rate.
#define NET_GROUP_EXIST				_EC(140)	// Group name has been existed.
#define	NET_GROUP_NOEXIST			_EC(141)	// The group name does not exist. 
#define NET_GROUP_RIGHTOVER			_EC(142)	// The group right exceeds the right list!
#define NET_GROUP_HAVEUSER			_EC(143)	// The group can not be removed since there is user in it!
#define NET_GROUP_RIGHTUSE			_EC(144)	// The user has used one of the group right. It can not be removed. 
#define NET_GROUP_SAMENAME			_EC(145)	// New group name has been existed
#define	NET_USER_EXIST				_EC(146)	// The user name has been existed
#define NET_USER_NOEXIST			_EC(147)	// The account does not exist.
#define NET_USER_RIGHTOVER			_EC(148)	// User right exceeds the group right. 
#define NET_USER_PWD				_EC(149)	// Reserved account. It does not allow to be modified.
#define NET_USER_FLASEPWD			_EC(150)	// password is not correct
#define NET_USER_NOMATCHING			_EC(151)	// Password is invalid
#define NET_USER_INUSE				_EC(152)	// account in use
#define NET_ERROR_GETCFG_ETHERNET	_EC(300)	// Failed to get network card setup.
#define NET_ERROR_GETCFG_WLAN		_EC(301)	// Failed to get wireless network information.
#define NET_ERROR_GETCFG_WLANDEV	_EC(302)	// Failed to get wireless network device.
#define NET_ERROR_GETCFG_REGISTER	_EC(303)	// Failed to get actively registration parameter.
#define NET_ERROR_GETCFG_CAMERA		_EC(304)	// Failed to get camera property 
#define NET_ERROR_GETCFG_INFRARED	_EC(305)	// Failed to get IR alarm setup
#define NET_ERROR_GETCFG_SOUNDALARM	_EC(306)	// Failed to get audio alarm setup
#define NET_ERROR_GETCFG_STORAGE    _EC(307)	// Failed to get storage position 
#define NET_ERROR_GETCFG_MAIL		_EC(308)	// Failed to get mail setup.
#define NET_CONFIG_DEVBUSY			_EC(309)	// Can not set right now. 
#define NET_CONFIG_DATAILLEGAL		_EC(310)	// The configuration setup data are illegal.
#define NET_ERROR_GETCFG_DST        _EC(311)    // Failed to get DST setup
#define NET_ERROR_SETCFG_DST        _EC(312)    // Failed to set DST 
#define NET_ERROR_GETCFG_VIDEO_OSD  _EC(313)    // Failed to get video osd setup.
#define NET_ERROR_SETCFG_VIDEO_OSD  _EC(314)    // Failed to set video osd 
#define NET_ERROR_GETCFG_GPRSCDMA   _EC(315)    // Failed to get CDMA\GPRS configuration
#define NET_ERROR_SETCFG_GPRSCDMA   _EC(316)    // Failed to set CDMA\GPRS configuration
#define NET_ERROR_GETCFG_IPFILTER   _EC(317)    // Failed to get IP Filter configuration
#define NET_ERROR_SETCFG_IPFILTER   _EC(318)    // Failed to set IP Filter configuration
#define NET_ERROR_GETCFG_TALKENCODE _EC(319)    // Failed to get Talk Encode configuration
#define NET_ERROR_SETCFG_TALKENCODE _EC(320)    // Failed to set Talk Encode configuration
#define NET_ERROR_GETCFG_RECORDLEN  _EC(321)    // Failed to get The length of the video package configuration
#define NET_ERROR_SETCFG_RECORDLEN  _EC(322)    // Failed to set The length of the video package configuration
#define	NET_DONT_SUPPORT_SUBAREA	_EC(323)	// Not support Network hard disk partition
#define	NET_ERROR_GET_AUTOREGSERVER	_EC(324)	// Failed to get the register server information
#define	NET_ERROR_CONTROL_AUTOREGISTER		_EC(325)	// Failed to control actively registration
#define	NET_ERROR_DISCONNECT_AUTOREGISTER	_EC(326)	// Failed to disconnect actively registration
#define NET_ERROR_GETCFG_MMS				_EC(327)	// Failed to get mms configuration
#define NET_ERROR_SETCFG_MMS				_EC(328)	// Failed to set mms configuration
#define NET_ERROR_GETCFG_SMSACTIVATION      _EC(329)	// Failed to get SMS configuration
#define NET_ERROR_SETCFG_SMSACTIVATION      _EC(330)	// Failed to set SMS configuration
#define NET_ERROR_GETCFG_DIALINACTIVATION	_EC(331)	// Failed to get activation of a wireless connection
#define NET_ERROR_SETCFG_DIALINACTIVATION	_EC(332)	// Failed to set activation of a wireless connection
#define NET_ERROR_GETCFG_VIDEOOUT           _EC(333)    // Failed to get the parameter of video output
#define NET_ERROR_SETCFG_VIDEOOUT			_EC(334)	// Failed to set the configuration of video output
#define NET_ERROR_GETCFG_OSDENABLE			_EC(335)	// Failed to get osd overlay enabling
#define NET_ERROR_SETCFG_OSDENABLE			_EC(336)	// Failed to set OSD overlay enabling
#define NET_ERROR_SETCFG_ENCODERINFO        _EC(337)    // Failed to set digital input configuration of front encoders
#define NET_ERROR_GETCFG_TVADJUST		    _EC(338)	// Failed to get TV adjust configuration
#define NET_ERROR_SETCFG_TVADJUST			_EC(339)	// Failed to set TV adjust configuration

#define NET_ERROR_CONNECT_FAILED			_EC(340)	// Failed to request to establish a connection
#define NET_ERROR_SETCFG_BURNFILE			_EC(341)	// Failed to request to upload burn files
#define NET_ERROR_SNIFFER_GETCFG			_EC(342)	// // Failed to get capture configuration information
#define NET_ERROR_SNIFFER_SETCFG			_EC(343)	// Failed to set capture configuration information
#define NET_ERROR_DOWNLOADRATE_GETCFG		_EC(344)	// Failed to get download restrictions information
#define NET_ERROR_DOWNLOADRATE_SETCFG		_EC(345)	// Failed to set download restrictions information
#define NET_ERROR_SEARCH_TRANSCOM			_EC(346)	// Failed to query serial port parameters
#define NET_ERROR_GETCFG_POINT				_EC(347)	// Failed to get the preset info
#define NET_ERROR_SETCFG_POINT				_EC(348)	// Failed to set the preset info
#define NET_SDK_LOGOUT_ERROR				_EC(349)    // SDK log out the device abnormally
#define NET_ERROR_GET_VEHICLE_CFG			_EC(350)	// Failed to get vehicle configuration
#define NET_ERROR_SET_VEHICLE_CFG			_EC(351)	// Failed to set vehicle configuration
#define NET_ERROR_GET_ATM_OVERLAY_CFG		_EC(352)	// Failed to get ATM overlay configuration
#define NET_ERROR_SET_ATM_OVERLAY_CFG		_EC(353)	// Failed to set ATM overlay configuration
#define NET_ERROR_GET_ATM_OVERLAY_ABILITY	_EC(354)	// Failed to get ATM overlay ability
#define NET_ERROR_GET_DECODER_TOUR_CFG		_EC(355)	// Failed to get decoder tour configuration
#define NET_ERROR_SET_DECODER_TOUR_CFG		_EC(356)	// Failed to set decoder tour configuration
#define NET_ERROR_CTRL_DECODER_TOUR			_EC(357)	// Failed to control decoder tour
#define NET_GROUP_OVERSUPPORTNUM			_EC(358)	// Beyond the device supports for the largest number of user groups
#define NET_USER_OVERSUPPORTNUM				_EC(359)	// Beyond the device supports for the largest number of users 
#define NET_ERROR_GET_SIP_CFG				_EC(368)	// Failed to get SIP configuration
#define NET_ERROR_SET_SIP_CFG				_EC(369)	// Failed to set SIP configuration
#define NET_ERROR_GET_SIP_ABILITY			_EC(370)	// Failed to get SIP capability
#define NET_ERROR_GET_WIFI_AP_CFG			_EC(371)	// Failed to get "WIFI ap' configuration 
#define NET_ERROR_SET_WIFI_AP_CFG			_EC(372)	// Failed to set "WIFI ap" configuration  
#define NET_ERROR_GET_DECODE_POLICY		    _EC(373)	// Failed to get decode policy 
#define NET_ERROR_SET_DECODE_POLICY			_EC(374)	// Failed to set decode policy 
#define NET_ERROR_TALK_REJECT				_EC(375)	// refuse talk
#define NET_ERROR_TALK_OPENED				_EC(376)	// talk has opened by other client
#define NET_ERROR_TALK_RESOURCE_CONFLICIT   _EC(377)	// resource conflict
#define NET_ERROR_TALK_UNSUPPORTED_ENCODE   _EC(378)	// unsupported encode type
#define NET_ERROR_TALK_RIGHTLESS			_EC(379)	// no right
#define NET_ERROR_TALK_FAILED				_EC(380)	// request failed
#define NET_ERROR_GET_MACHINE_CFG			_EC(381)	// Failed to get device relative config
#define NET_ERROR_SET_MACHINE_CFG			_EC(382)	// Failed to set device relative config
#define NET_ERROR_GET_DATA_FAILED			_EC(383)	// get data failed
#define NET_ERROR_MAC_VALIDATE_FAILED       _EC(384)    // MAC validate failed
#define NET_ERROR_GET_INSTANCE              _EC(385)    // Failed to get server instance 
#define NET_ERROR_JSON_REQUEST              _EC(386)    // Generated json string is error
#define NET_ERROR_JSON_RESPONSE             _EC(387)    // The responding json string is error
#define NET_ERROR_VERSION_HIGHER            _EC(388)    // The protocol version is lower than current version
#define NET_SPARE_NO_CAPACITY				_EC(389)	// Hotspare disk operation failed. The capacity is low
#define NET_ERROR_SOURCE_IN_USE				_EC(390)	// Display source is used by other output
#define NET_ERROR_REAVE                     _EC(391)    // The advanced user is taking the resources of the lower user. 
#define NET_ERROR_NETFORBID                 _EC(392)    // Forbid Access 
#define NET_ERROR_SENIOR_VALIDATE_FAILED    _EC(398)    // senior validate failed
/************************************************************************
 ** Enumeration Definition
 ***********************************************************************/
// Device type
enum NET_DEVICE_TYPE 
{
	NET_PRODUCT_NONE = 0,
	NET_DVR_NONREALTIME_MACE,					// Non real-time MACE
	NET_DVR_NONREALTIME,						// Non real-time
	NET_NVS_MPEG1,								// Network video server
	NET_DVR_MPEG1_2,							// MPEG1 2-ch DVR
	NET_DVR_MPEG1_8,							// MPEG1 8-ch DVR
	NET_DVR_MPEG4_8,							// MPEG4 8-ch DVR
	NET_DVR_MPEG4_16,							// MPEG4 16-ch DVR
	NET_DVR_MPEG4_SX2,							// LB series DVR
	NET_DVR_MEPG4_ST2,							// GB  series DVR
	NET_DVR_MEPG4_SH2,							// HB  series DVR
	NET_DVR_MPEG4_GBE,							// GBE  series DVR
	NET_DVR_MPEG4_NVSII,						// II network video server
	NET_DVR_STD_NEW,							// New standard configuration protocol
	NET_DVR_DDNS,								// DDNS server
	NET_DVR_ATM,								// ATM series 
	NET_NB_SERIAL,								// 2nd non real-time NB series DVR
	NET_LN_SERIAL,								// LN  series 
	NET_BAV_SERIAL,								// BAV series
	NET_SDIP_SERIAL,							// SDIP series
	NET_IPC_SERIAL,								// IPC series
	NET_NVS_B,									// NVS B series
	NET_NVS_C,									// NVS H series 
	NET_NVS_S,									// NVS S series
	NET_NVS_E,									// NVS E series
	NET_DVR_NEW_PROTOCOL,						// Search device type from QueryDevState. it is in string format
	NET_NVD_SERIAL,								// NVD
	NET_DVR_N5,									// N5
	NET_DVR_MIX_DVR,							// HDVR
	NET_SVR_SERIAL,								// SVR series
	NET_SVR_BS,									// SVR-BS
	NET_NVR_SERIAL,								// NVR series
	NET_DVR_N51,                                // N51
	NET_ITSE_SERIAL,							// ITSE Intelligent Analysis Box
	NET_ITC_SERIAL,                             // Intelligent traffic camera equipment
	NET_HWS_SERIAL,                             // radar speedometer HWS
	NET_PVR_SERIAL,                             // portable video record
	NET_IVS_SERIAL,                             // IVS(intelligent video server series)
	NET_IVS_B,                                  // universal intelligent detect video server series 
	NET_IVS_F,                                  // face recognisation server
	NET_IVS_V,                                  // video quality diagnosis server
	NET_MATRIX_SERIAL,							// matrix
	NET_DVR_N52,								// N52
	NET_DVR_N56,								// N56
	NET_ESS_SERIAL,                             // ESS
	NET_IVS_PC,                                 // number statistic server
	NET_PC_NVR,                                 // pc-nvr
	NET_DSCON,									//	
	NET_EVS,									//
	NET_EIVS,									//
};

// Language type
typedef enum __LANGUAGE_TYPE
{
	DH_LANGUAGE_ENGLISH,						// English 
	DH_LANGUAGE_CHINESE_SIMPLIFIED,				// Simplified Chinese
	DH_LANGUAGE_CHINESE_TRADITIONAL,			// Traditional Chinese
	DH_LANGUAGE_ITALIAN,						// Italian 
	DH_LANGUAGE_SPANISH,						// Spanish
	DH_LANGUAGE_JAPANESE,						// Japanese
	DH_LANGUAGE_RUSSIAN,						// Russian 
	DH_LANGUAGE_FRENCH,							// French
	DH_LANGUAGE_GERMAN, 						// German
	DH_LANGUAGE_PORTUGUESE,						// Portuguese
	DH_LANGUAGE_TURKEY,							// Turkey	
	DH_LANGUAGE_POLISH,							// Polish
	DH_LANGUAGE_ROMANIAN,						// Romanian 
	DH_LANGUAGE_HUNGARIAN,						// Hungarian
	DH_LANGUAGE_FINNISH,						// Finnish
	DH_LANGUAGE_ESTONIAN,						// Estonian	
	DH_LANGUAGE_KOREAN,							// Korean
	DH_LANGUAGE_FARSI,							// Farsi	
	DH_LANGUAGE_DANSK,							// Denmark
	DH_LANGUAGE_CZECHISH,						// Czechish
	DH_LANGUAGE_BULGARIA,						// Bulgaria
	DH_LANGUAGE_SLOVAKIAN,						// Slovakian
	DH_LANGUAGE_SLOVENIA,						// Slovenia
	DH_LANGUAGE_CROATIAN,						// Croatian
	DH_LANGUAGE_DUTCH,							// Dutch
	DH_LANGUAGE_GREEK,							// Greek
	DH_LANGUAGE_UKRAINIAN,						// Ukrainian
	DH_LANGUAGE_SWEDISH,						// Swedish
	DH_LANGUAGE_SERBIAN,						// Serbian
	DH_LANGUAGE_VIETNAMESE,						// Vietnamese
	DH_LANGUAGE_LITHUANIAN,						// Lithuanian
	DH_LANGUAGE_FILIPINO,						// Filipino
	DH_LANGUAGE_ARABIC,							// Arabic
	DH_LANGUAGE_CATALAN,						// Catalan
	DH_LANGUAGE_LATVIAN,						// Latvian
	DH_LANGUAGE_THAI,							// Thai
	DH_LANGUAGE_HEBREW,							// Hebrew
	DH_LANGUAGE_Bosnian,						// Bosnian
} DH_LANGUAGE_TYPE;

// Upgrade type
typedef enum __EM_UPGRADE_TYPE
{
	DH_UPGRADE_BIOS_TYPE = 1,					// BIOS  upgrade
	DH_UPGRADE_WEB_TYPE,						// WEB upgrade
	DH_UPGRADE_BOOT_YPE,						// BOOT upgrade
	DH_UPGRADE_CHARACTER_TYPE,					// Chinese character library
	DH_UPGRADE_LOGO_TYPE,						// LOGO
	DH_UPGRADE_EXE_TYPE,						// EXE such as player
} EM_UPGRADE_TYPE;

// Record related (schedule,motion detection,alarm)
typedef enum __REC_TYPE
{
	DH_REC_TYPE_TIM = 0,
	DH_REC_TYPE_MTD,
	DH_REC_TYPE_ALM,
	DH_REC_TYPE_NUM,
} REC_TYPE;

// network type  
typedef enum __GPRSCDMA_NETWORK_TYPE
{
	DH_TYPE_AUTOSEL = 0,						// Automatic selection
	DH_TYPE_TD_SCDMA,							// TD-SCDMA network 
	DH_TYPE_WCDMA,								// WCDMA network
	DH_TYPE_CDMA_1x,							// CDMA 1.x network
	DH_TYPE_EDGE,								// GPRS network
	DH_TYPE_EVDO,								// EVDO network
	DH_TYPE_WIFI,
} EM_GPRSCDMA_NETWORK_TYPE;

// Interface type,responding to the interface CLIENT_SetSubconnCallBack
typedef enum __EM_INTERFACE_TYPE
{
	DH_INTERFACE_OTHER = 0x00000000,			// Unknown interface
	DH_INTERFACE_REALPLAY,						// Realtime monitoring interface
	DH_INTERFACE_PREVIEW,						// Realtime multiple-window preview
	DH_INTERFACE_PLAYBACK,						// Playback interface
	DH_INTERFACE_DOWNLOAD,						// Download interface
	DH_INTERFACE_REALLOADPIC,                   // Download picture interface
} EM_INTERFACE_TYPE;

// realplay disconnect event
typedef enum _EM_REALPLAY_DISCONNECT_EVENT_TYPE
{
	DISCONNECT_EVENT_REAVE,                     // resources is taked by advanced user
	DISCONNECT_EVENT_NETFORBID,                 // forbidden
	DISCONNECT_EVENT_SUBCONNECT,                // sublink disconnect
}EM_REALPLAY_DISCONNECT_EVENT_TYPE;

// event file's tag type
typedef enum __EM_EVENT_FILETAG
{
	DH_ATMBEFOREPASTE = 1,                      // Before ATM Paste
	DH_ATMAFTERPASTE,                           // After ATM Paste
}EM_EVENT_FILETAG;

// IPC type
typedef enum __EM_IPC_TYPE
{
	DH_IPC_PRIVATE,                             // dahua
	DH_IPC_AEBELL,                              // AEBell
	DH_IPC_PANASONIC,                           // panasonic
	DH_IPC_SONY,                                // sony
	DH_IPC_DYNACOLOR,                           // Dynacolor
	DH_IPC_TCWS = 5 ,                           // TCWS	
	DH_IPC_SAMSUNG,                             // Samsung
	DH_IPC_YOKO,                                // YOKO
	DH_IPC_AXIS,                                // AXIS
	DH_IPC_SANYO,							    // sanyo       
	DH_IPC_BOSH = 10,							// Bosch
	DH_IPC_PECLO,								// PECLO
	DH_IPC_PROVIDEO,							// Provideo
	DH_IPC_ACTI,								// ACTi
	DH_IPC_VIVOTEK,								// Vivotek
	DH_IPC_ARECONT = 15,                        // Arecont
	DH_IPC_PRIVATEEH,			                // PrivateEH	
	DH_IPC_IMATEK,					            // IMatek
	DH_IPC_SHANY,                               // Shany
	DH_IPC_VIDEOTREC,                           // videorec
	DH_IPC_URA = 20,                            // Ura
	DH_IPC_BITICINO,                            // Bticino 
	DH_IPC_ONVIF,                               // Onvif protocol type
	DH_IPC_SHEPHERD,                            // Shepherd
	DH_IPC_YAAN,                                // Yaan
	DH_IPC_AIRPOINT = 25,                       // Airpoint
	DH_IPC_TYCO,                                // TYCO
	DH_IPC_XUNMEI,								// Xunmei
	DH_IPC_HIKVISION,							// HIKVISION
	DH_IPC_LG,                                  // LG
	DH_IPC_AOQIMAN = 30,                        // Aoqiman
	DH_IPC_BAOKANG,                             // baokang  
	DH_IPC_WATCHNET,                            // Watchnet
	DH_IPC_XVISION,                             // Xvision
	DH_IPC_FUSITSU,                             // Fisitu
	DH_IPC_CANON = 35,							// Canon
	DH_IPC_GE,								    // GE
	DH_IPC_Basler,								// Basler
	DH_IPC_Patro,								// Patro
	DH_IPC_CPKNC,								// CPPLUS K series
	DH_IPC_CPRNC,								// CPPLUS R series
	DH_IPC_CPUNC,								// CPPLUS U series
}EM_IPC_TYPE;

// H264 profile rank
typedef enum __EM_H264_PROFILE_RANK
{
    	DH_PROFILE_BASELINE = 1,                 // offer I/P frame, only support progressive and CAVLC
		DH_PROFILE_MAIN,                         // offer I/P/B frame, support progressiv and interlaced,offer CAVLC and CABAC
		DH_PROFILE_EXTENDED,                     // offer I/P/B/SP/SI frame,only support progressive and CAVLC
		DH_PROFILE_HIGH,                         // FRExt,base on Main_Profile:8x8 intra prediction, custom quant, lossless video coding, more yuv
}EM_H264_PROFILE_RANK;

typedef enum __EM_DISK_TYPE
{
    DH_DISK_READ_WRITE,                          // read write disk
		DH_DISK_READ_ONLY,                       // read only disk
		DH_DISK_BACKUP,	                         // back up disk or media disk
		DH_DISK_REDUNDANT,                       // redundancy disk
		DH_DISK_SNAPSHOT,	                     // snapshot disk
}EM_DISK_TYPE;

// stream encrypt algorithm work mode
typedef enum  __EM_ENCRYPT_ALOG_WORKMODE
{
		ENCRYPT_ALOG_WORKMODE_ECB,				// ECB mode
		ENCRYPT_ALOG_WORKMODE_CBC,				// CBC mode
		ENCRYPT_ALOG_WORKMODE_CFB,				// CFB mode
		ENCRYPT_ALOG_WORKMODE_OFB,				// OFB mode
}EM_ENCRYPT_ALOG_WORKMODE;

typedef enum __EM_MOBILE_PPP_STATE
{
	MOBILE_PPP_UP = 0,							// connect has being build
	MOBILE_PPP_DOWN,							// ppp connect has being cut		
	MOBILE_PPP_CONNECTING,						// be connecting		
	MOBILE_PPP_CLOSEING,						// be closing PPP connect
} EM_MOBILE_PPP_STATE;

typedef enum __EM_3GMOBILE_STATE
{
    MOBILE_MODULE_OFF,							// means 3g net card mod is closed   		
	MOBILE_MODULE_STARTING,						// means 3g net card mod is starting
	MOBILE_MODULE_WORKING,						// means 3g net card mod is working
}EM_3GMOBILE_STATE;
/////////////////////////////////Monitor related/////////////////////////////////

// Preview type.Corresponding to CLIENT_RealPlayEx
typedef enum _RealPlayType
{
	DH_RType_Realplay = 0,						// Real-time preview
	DH_RType_Multiplay,							// Multiple-channel preview 
		
	DH_RType_Realplay_0,						// Real-time monitor-main stream. It is the same as DH_RType_Realplay
	DH_RType_Realplay_1,						// 1 Real-time monitor---extra stream 1
	DH_RType_Realplay_2,						// 2Real-time monitor-- extra stream 2
	DH_RType_Realplay_3,						// 3 Real-time monitor -- extra stream 3
		
	DH_RType_Multiplay_1,						// Multiple-channel preview-- 1-window 
	DH_RType_Multiplay_4,						// Multiple-channel preview--4-window
	DH_RType_Multiplay_8,						// Multiple-channel preview--8-window
	DH_RType_Multiplay_9,						// Multiple-channel preview--9-window
	DH_RType_Multiplay_16,						// Multiple-channel preview--16-window
	DH_RType_Multiplay_6,						// Multiple-channel preview--6-window
	DH_RType_Multiplay_12,						// Multiple-channel preview--12-window
} DH_RealPlayType;

/////////////////////////////////About PTZ/////////////////////////////////

// General PTZ control command
typedef enum _PTZ_ControlType
{
	DH_PTZ_UP_CONTROL = 0,						// Up
	DH_PTZ_DOWN_CONTROL,						// Down
	DH_PTZ_LEFT_CONTROL,						// Left
	DH_PTZ_RIGHT_CONTROL,						// Right
	DH_PTZ_ZOOM_ADD_CONTROL,					// +Zoom in 
	DH_PTZ_ZOOM_DEC_CONTROL,					// -Zoom out 
	DH_PTZ_FOCUS_ADD_CONTROL,					// +Zoom in 
	DH_PTZ_FOCUS_DEC_CONTROL,					// -Zoom out 
	DH_PTZ_APERTURE_ADD_CONTROL,				// + Aperture 
	DH_PTZ_APERTURE_DEC_CONTROL,				// -Aperture
    DH_PTZ_POINT_MOVE_CONTROL,					// Go to preset 
    DH_PTZ_POINT_SET_CONTROL,					// Set 
    DH_PTZ_POINT_DEL_CONTROL,					// Delete
    DH_PTZ_POINT_LOOP_CONTROL,					// Tour 
    DH_PTZ_LAMP_CONTROL							// Light and wiper 
} DH_PTZ_ControlType;

// PTZ control extensive command 
typedef enum _EXTPTZ_ControlType
{
	DH_EXTPTZ_LEFTTOP = 0x20,					// Upper left
	DH_EXTPTZ_RIGHTTOP,							// Upper right 
	DH_EXTPTZ_LEFTDOWN,							// Down left
	DH_EXTPTZ_RIGHTDOWN,						// Down right 
	DH_EXTPTZ_ADDTOLOOP,						// Add preset to tour		tour	 preset value
	DH_EXTPTZ_DELFROMLOOP,						// Delete preset in tour	tour	 preset value
    DH_EXTPTZ_CLOSELOOP,						// Delete tour				tour		
	DH_EXTPTZ_STARTPANCRUISE,					// Begin pan rotation		
	DH_EXTPTZ_STOPPANCRUISE,					// Stop pan rotation		
	DH_EXTPTZ_SETLEFTBORDER,					// Set left limit		
	DH_EXTPTZ_SETRIGHTBORDER,					// Set right limit	
	DH_EXTPTZ_STARTLINESCAN,					// Begin scanning			
    DH_EXTPTZ_CLOSELINESCAN,					// Stop scanning		
    DH_EXTPTZ_SETMODESTART,						// Start mode	mode line		
    DH_EXTPTZ_SETMODESTOP,						// Stop mode	mode line		
	DH_EXTPTZ_RUNMODE,							// Enable mode	Mode line		
	DH_EXTPTZ_STOPMODE,							// Disable mode	Mode line	
	DH_EXTPTZ_DELETEMODE,						// Delete mode	Mode line
	DH_EXTPTZ_REVERSECOMM,						// Flip
	DH_EXTPTZ_FASTGOTO,							// 3D position	X address(8192)	Y address(8192)	zoom(4)
	DH_EXTPTZ_AUXIOPEN,							// auxiliary open	Auxiliary point	
	DH_EXTPTZ_AUXICLOSE,						// Auxiliary close	Auxiliary point
	DH_EXTPTZ_OPENMENU = 0x36,					// Open dome menu 
	DH_EXTPTZ_CLOSEMENU,						// Close menu 
	DH_EXTPTZ_MENUOK,							// Confirm menu 
	DH_EXTPTZ_MENUCANCEL,						// Cancel menu 
	DH_EXTPTZ_MENUUP,							// menu up 
	DH_EXTPTZ_MENUDOWN,							// menu down
	DH_EXTPTZ_MENULEFT,							// menu left
	DH_EXTPTZ_MENURIGHT,						// Menu right 
	DH_EXTPTZ_ALARMHANDLE = 0x40,				// Alarm activate PTZ parm1:Alarm input channel;parm2:Alarm activation type  1-preset 2-scan 3-tour;parm 3:activation value,such as preset value.
	DH_EXTPTZ_MATRIXSWITCH = 0x41,				// Matrix switch parm1:monitor number(video output number);parm2:video input number;parm3:matrix number 
	DH_EXTPTZ_LIGHTCONTROL,						// Light controller
	DH_EXTPTZ_EXACTGOTO,						// 3D accurately positioning parm1:Pan degree(0~3600); parm2: tilt coordinates(0~900); parm3:zoom(1~128)
	DH_EXTPTZ_RESETZERO,                        // Reset  3D positioning as zero
	DH_EXTPTZ_UP_TELE = 0x70,					// Up + TELE param1=speed (1-8) 
	DH_EXTPTZ_DOWN_TELE,						// Down + TELE
	DH_EXTPTZ_LEFT_TELE,						// Left + TELE
	DH_EXTPTZ_RIGHT_TELE,						// Right + TELE
	DH_EXTPTZ_LEFTUP_TELE,						// Upper left + TELE
	DH_EXTPTZ_LEFTDOWN_TELE,					// Down left + TELE
	DH_EXTPTZ_TIGHTUP_TELE,						// Upper right + TELE
	DH_EXTPTZ_RIGHTDOWN_TELE,					// Down right + TELE
	DH_EXTPTZ_UP_WIDE,							// Up + WIDE param1=speed (1-8) 
	DH_EXTPTZ_DOWN_WIDE,						// Down + WIDE
	DH_EXTPTZ_LEFT_WIDE,						// Left + WIDE
	DH_EXTPTZ_RIGHT_WIDE,						// Right + WIDE
	DH_EXTPTZ_LEFTUP_WIDE,						// Upper left + WIDE
	DH_EXTPTZ_LEFTDOWN_WIDE,					// Down left+ WIDE
	DH_EXTPTZ_TIGHTUP_WIDE,						// Upper right + WIDE
	DH_EXTPTZ_RIGHTDOWN_WIDE,					// Down right + WIDE
	DH_EXTPTZ_TOTAL,							// max command value
} DH_EXTPTZ_ControlType;

/////////////////////////////////About Log /////////////////////////////////

// Log search type 
typedef enum _DH_LOG_QUERY_TYPE
{
	DHLOG_ALL = 0,								// All logs
	DHLOG_SYSTEM,								// System logs 
	DHLOG_CONFIG,								// Configuration logs 
	DHLOG_STORAGE,								// Storage logs
	DHLOG_ALARM,								// Alarm logs 
	DHLOG_RECORD,								// Record related
	DHLOG_ACCOUNT,								// Account related
	DHLOG_CLEAR,								// Clear log 
	DHLOG_PLAYBACK,								// Playback related 
	DHLOG_MANAGER                               // Concerning the front-end management and running
} DH_LOG_QUERY_TYPE;

// Log Type
typedef enum _DH_LOG_TYPE
{
	DH_LOG_REBOOT = 0x0000,						// Device reboot 
	DH_LOG_SHUT,								// Shut down device 
	DH_LOG_UPGRADE = 0x0004,					// Device Upgrade
	DH_LOG_SYSTIME_UPDATE = 0x0005,             // system time update
	DH_LOG_CONFSAVE = 0x0100,					// Save configuration 
	DH_LOG_CONFLOAD,							// Read configuration 
	DH_LOG_FSERROR = 0x0200,					// File system error
	DH_LOG_HDD_WERR,							// HDD write error 
	DH_LOG_HDD_RERR,							// HDD read error
	DH_LOG_HDD_TYPE,							// Set HDD type 
	DH_LOG_HDD_FORMAT,							// Format HDD
	DH_LOG_HDD_NOSPACE,							// Current working HDD space is not sufficient
	DH_LOG_HDD_TYPE_RW,							// Set HDD type as read-write 
	DH_LOG_HDD_TYPE_RO,							// Set HDD type as read-only
	DH_LOG_HDD_TYPE_RE,							// Set HDD type as redundant 
	DH_LOG_HDD_TYPE_SS,							// Set HDD type as snapshot
	DH_LOG_HDD_NONE,							// No HDD
	DH_LOG_HDD_NOWORKHDD,						// No work HDD
	DH_LOG_HDD_TYPE_BK,							// Set HDD type to backup HDD
	DH_LOG_HDD_TYPE_REVERSE,					// Set HDD type to reserve subarea
	DH_LOG_HDD_START_INFO = 0x200 +14,          // note the boot-strap's hard disk info
	DH_LOG_HDD_WORKING_DISK,                    // note the disk number after the disk change
	DH_LOG_HDD_OTHER_ERROR,                     // note other errors of disk
	DH_LOG_HDD_SLIGHT_ERR,						// there has some little errors on disk
	DH_LOG_HDD_SERIOUS_ERR,                     // there has some serious errors on disk
	DH_LOG_HDD_NOSPACE_END,                     // the end of the alarm that current disk has no space left 
	DH_LOG_HDD_TYPE_RAID_CONTROL,               // Raid control
	DH_LOG_ALM_IN = 0x0300,						// External alarm begin 
	DH_LOG_NETALM_IN,							// Network alarm input 
	DH_LOG_ALM_END = 0x0302,					// External input alarm stop 
	DH_LOG_LOSS_IN,								// Video loss alarm begin 
	DH_LOG_LOSS_END,							// Video loss alarm stop
	DH_LOG_MOTION_IN,							// Motion detection alarm begin 
	DH_LOG_MOTION_END,							// Motion detection alarm stop 
	DH_LOG_ALM_BOSHI,							// Annunciator alarm input 
	DH_LOG_NET_ABORT = 0x0308,					// Network disconnected 
	DH_LOG_NET_ABORT_RESUME,					// Network connection restore 
	DH_LOG_CODER_BREAKDOWN,						// Encoder error
	DH_LOG_CODER_BREAKDOWN_RESUME,				// Encoder error restore 
	DH_LOG_BLIND_IN,							// Camera masking 
	DH_LOG_BLIND_END,							// Restore camera masking 
	DH_LOG_ALM_TEMP_HIGH,						// High temperature 
	DH_LOG_ALM_VOLTAGE_LOW,						// Low voltage
	DH_LOG_ALM_BATTERY_LOW,						// Battery capacity is not sufficient 
	DH_LOG_ALM_ACC_BREAK,						// ACC power off 
	DH_LOG_INFRAREDALM_IN = 0x03a0,				// Wireless alarm begin 
	DH_LOG_INFRAREDALM_END,						// Wireless alarm end 
	DH_LOG_IPCONFLICT,							// IP conflict 
	DH_LOG_IPCONFLICT_RESUME,					// IP restore
	DH_LOG_SDPLUG_IN,							// SD Card insert
	DH_LOG_SDPLUG_OUT,							// SD Card Pull-out
	DH_LOG_NET_PORT_BIND_FAILED,				// Failed to bind port
	DH_LOG_HDD_BEEP_RESET,                      // Hard disk error beep reset 
	DH_LOG_MAC_CONFLICT,                        // MAC conflict
	DH_LOG_MAC_CONFLICT_RESUME,                 // MAC conflict resume
	DH_LOG_ALARM_OUT,							// alarm out
	DH_LOG_ALM_RAID_STAT_EVENT,                 // RAID state event    
	DH_LOG_ABLAZE_ON,				            // Fire alarm, smoker or high temperature
	DH_LOG_ABLAZE_OFF,			                // Fire alarm reset 
	DH_LOG_INTELLI_ALARM_PLUSE,					// Intelligence pulse alarm
	DH_LOG_INTELLI_ALARM_IN,					// Intelligence alarm start
	DH_LOG_INTELLI_ALARM_END,					// Intelligence alarm end
	DH_LOG_AUTOMATIC_RECORD = 0x0400,			// Auto record 
	DH_LOG_MANUAL_RECORD = 0x0401,				// Manual record 
	DH_LOG_CLOSED_RECORD,						// Stop record 
	DH_LOG_LOGIN = 0x0500,						// Log in 
	DH_LOG_LOGOUT,								// Log off 
	DH_LOG_ADD_USER,							// Add user
	DH_LOG_DELETE_USER,							// Delete user
	DH_LOG_MODIFY_USER,							// Modify user 
	DH_LOG_ADD_GROUP,							// Add user group 
	DH_LOG_DELETE_GROUP,						// Delete user group 
	DH_LOG_MODIFY_GROUP,						// Modify user group 
	DH_LOG_NET_LOGIN = 0x0508,					// Network Login
	DH_LOG_MODIFY_PASSWORD,						// Modify password
	DH_LOG_CLEAR = 0x0600,						// Clear log 
	DH_LOG_SEARCHLOG,							// Search log 
	DH_LOG_SEARCH = 0x0700,						// Search record 
	DH_LOG_DOWNLOAD,							// Record download
	DH_LOG_PLAYBACK,							// Record playback
	DH_LOG_BACKUP,								// Backup recorded file 
	DH_LOG_BACKUPERROR,							// Failed to backup recorded file
    DH_LOG_TIME_UPDATE  = 0x0800,               // Time update

	DH_LOG_TYPE_NR = 8,
} DH_LOG_TYPE;

// Extensive log type. Correponding to CLIENT_QueryLogEx, Condition (int nType = 1; parameter reserved = &nType)
typedef enum _DH_NEWLOG_TYPE
{
	DH_NEWLOG_REBOOT = 0x0000,					// Device reboot 
	DH_NEWLOG_SHUT,								// Shut down device
	DH_NEWLOG_UPGRADE = 0x0004,					// Device upgrade
	DH_NEWLOG_SYSTIME_UPDATE = 0x0005,          // system time update
	DH_NEWLOG_CONFSAVE = 0x0100,				// Save configuration 
	DH_NEWLOG_CONFLOAD,							// Read configuration 
	DH_NEWLOG_FSERROR = 0x0200,					// File system error
	DH_NEWLOG_HDD_WERR,							// HDD write error 
	DH_NEWLOG_HDD_RERR,							// HDD read error
	DH_NEWLOG_HDD_TYPE,							// Set HDD type 
	DH_NEWLOG_HDD_FORMAT,						// Format HDD
	DH_NEWLOG_HDD_NOSPACE,						// Current working HDD space is not sufficient
	DH_NEWLOG_HDD_TYPE_RW,						// Set HDD type as read-write 
	DH_NEWLOG_HDD_TYPE_RO,						// Set HDD type as read-only
	DH_NEWLOG_HDD_TYPE_RE,						// Set HDD type as redundant 
	DH_NEWLOG_HDD_TYPE_SS,						// Set HDD type as snapshot
	DH_NEWLOG_HDD_NONE,							// No HDD
	DH_NEWLOG_HDD_NOWORKHDD,					// No work HDD
	DH_NEWLOG_HDD_TYPE_BK,						// Set HDD type to backup HDD
	DH_NEWLOG_HDD_TYPE_REVERSE,					// Set HDD type to reserve subareas
	DH_NEWLOG_HDD_START_INFO = 0x200 +14,       // note the boot-strap's hard disk info
	DH_NEWLOG_HDD_WORKING_DISK,                 // note the disk number after the disk change
	DH_NEWLOG_HDD_OTHER_ERROR,                  // note other errors of disk
	DH_NEWLOG_HDD_SLIGHT_ERR,					// there has some little errors on disk
	DH_NEWLOG_HDD_SERIOUS_ERR,                  // there has some serious errors on disk
	DH_NEWLOG_HDD_NOSPACE_END,                  // the end of the alarm that current disk has no space left 
	DH_NEWLOG_ALM_IN = 0x0300,					// External alarm begin 
	DH_NEWLOG_NETALM_IN,						// Network alarm input 
	DH_NEWLOG_ALM_END = 0x0302,					// External input alarm stop 
	DH_NEWLOG_LOSS_IN,							// Video loss alarm begin 
	DH_NEWLOG_LOSS_END,							// Video loss alarm stop
	DH_NEWLOG_MOTION_IN,						// Motion detection alarm begin 
	DH_NEWLOG_MOTION_END,						// Motion detection alarm stop 
	DH_NEWLOG_ALM_BOSHI,						// Annunciator alarm input 
	DH_NEWLOG_NET_ABORT = 0x0308,				// Network disconnected 
	DH_NEWLOG_NET_ABORT_RESUME,					// Network connection restore 
	DH_NEWLOG_CODER_BREAKDOWN,					// Encoder error
	DH_NEWLOG_CODER_BREAKDOWN_RESUME,			// Encoder error restore 
	DH_NEWLOG_BLIND_IN,							// Camera masking 
	DH_NEWLOG_BLIND_END,						// Restore camera masking 
	DH_NEWLOG_ALM_TEMP_HIGH,					// High temperature 
	DH_NEWLOG_ALM_VOLTAGE_LOW,					// Low voltage
	DH_NEWLOG_ALM_BATTERY_LOW,					// Battery capacity is not sufficient 
	DH_NEWLOG_ALM_ACC_BREAK,					// ACC power off 
	DH_NEWLOG_INFRAREDALM_IN = 0x03a0,			// Wireless alarm begin 
	DH_NEWLOG_INFRAREDALM_END,					// Wireless alarm end 
	DH_NEWLOG_IPCONFLICT,						// IP conflict 
	DH_NEWLOG_IPCONFLICT_RESUME,				// IP restore
	DH_NEWLOG_SDPLUG_IN,						// SD Card insert
	DH_NEWLOG_SDPLUG_OUT,						// SD Card Pull-out
	DH_NEWLOG_NET_PORT_BIND_FAILED,				// Failed to bind port
	DH_NEWLOG_HDD_BEEP_RESET,                   // Hard disk error beep reset
	DH_NEWLOG_AUTOMATIC_RECORD = 0x0400,		// Auto record 
	DH_NEWLOG_MANUAL_RECORD,					// Manual record 
	DH_NEWLOG_CLOSED_RECORD,					// Stop record 
	DH_NEWLOG_LOGIN = 0x0500,					// Log in 
	DH_NEWLOG_LOGOUT,							// Log off 
	DH_NEWLOG_ADD_USER,							// Add user
	DH_NEWLOG_DELETE_USER,						// Delete user
	DH_NEWLOG_MODIFY_USER,						// Modify user 
	DH_NEWLOG_ADD_GROUP,						// Add user group 
	DH_NEWLOG_DELETE_GROUP,						// Delete user group 
	DH_NEWLOG_MODIFY_GROUP,						// Modify user group
	DH_NEWLOG_NET_LOGIN = 0x0508,				// Network user login
	DH_NEWLOG_CLEAR = 0x0600,					// Clear log 
	DH_NEWLOG_SEARCHLOG,						// Search log 
	DH_NEWLOG_SEARCH = 0x0700,					// Search record 
	DH_NEWLOG_DOWNLOAD,							// Record download
	DH_NEWLOG_PLAYBACK,							// Record playback
	DH_NEWLOG_BACKUP,							// Backup recorded file 
	DH_NEWLOG_BACKUPERROR,						// Failed to backup recorded file
	DH_NEWLOG_TIME_UPDATE  = 0x0800,            // Time update

	DH_NEWLOG_TYPE_NR = 8,		
} DH_NEWLOG_TYPE;

///////////////////////////////About audio talk ///////////////////////////////

// Audio encode type 
typedef enum __TALK_CODING_TYPE
{
	DH_TALK_DEFAULT = 0,						// No-head PCM
	DH_TALK_PCM = 1,							// With head PCM
	DH_TALK_G711a,								// G711a
	DH_TALK_AMR,								// AMR
	DH_TALK_G711u,								// G711u
	DH_TALK_G726,								// G726
	DH_TALK_G723_53,							// G723_53
	DH_TALK_G723_63,							// G723_63
	DH_TALK_AAC,								// AAC
} DH_TALK_CODING_TYPE;

// Audio talk way 
typedef enum __EM_USEDEV_MODE
{
	DH_TALK_CLIENT_MODE,						// Set client-end mode to begin audio talk 
	DH_TALK_SERVER_MODE,						// Set server mode to begin audio talk 
	DH_TALK_ENCODE_TYPE,						// Set encode format for audio talk 
	DH_ALARM_LISTEN_MODE,						// Set alarm subscribe way 
	DH_CONFIG_AUTHORITY_MODE,					// Set user right to realize configuration management
	DH_TALK_TALK_CHANNEL,						// set talking channel(0~MaxChannel-1)
	DH_RECORD_STREAM_TYPE,                      // set the stream type of the record for query(0-both main and extra stream,1-only main stream,2-only extra stream)  
} EM_USEDEV_MODE;

// AMR Encode Type
typedef enum __EM_ARM_ENCODE_MODE
{
	DH_TALK_AMR_AMR475 = 1,						// AMR475
	DH_TALK_AMR_AMR515,							// AMR515
	DH_TALK_AMR_AMR59,							// AMR59
	DH_TALK_AMR_AMR67,							// AMR67
	DH_TALK_AMR_AMR74,							// AMR74
	DH_TALK_AMR_AMR795,							// AMR795
	DH_TALK_AMR_AMR102,							// AMR102
	DH_TALK_AMR_AMR122,							// AMR122
} EM_ARM_ENCODE_MODE;

/////////////////////////////////Control Related/////////////////////////////////

// Control type    Corresponding to CLIENT_ControlDevice
typedef enum _CtrlType
{
	DH_CTRL_REBOOT = 0,							// Reboot device	
	DH_CTRL_SHUTDOWN,							// Shut down device
	DH_CTRL_DISK,								// HDD management
	DH_KEYBOARD_POWER = 3,						// Network keyboard
	DH_KEYBOARD_ENTER,
	DH_KEYBOARD_ESC,
	DH_KEYBOARD_UP,
	DH_KEYBOARD_DOWN,
	DH_KEYBOARD_LEFT,
	DH_KEYBOARD_RIGHT,
	DH_KEYBOARD_BTN0,
	DH_KEYBOARD_BTN1,
	DH_KEYBOARD_BTN2,
	DH_KEYBOARD_BTN3,
	DH_KEYBOARD_BTN4,
	DH_KEYBOARD_BTN5,
	DH_KEYBOARD_BTN6,
	DH_KEYBOARD_BTN7,
	DH_KEYBOARD_BTN8,
	DH_KEYBOARD_BTN9,
	DH_KEYBOARD_BTN10,
	DH_KEYBOARD_BTN11,
	DH_KEYBOARD_BTN12,
	DH_KEYBOARD_BTN13,
	DH_KEYBOARD_BTN14,
	DH_KEYBOARD_BTN15,
	DH_KEYBOARD_BTN16,
	DH_KEYBOARD_SPLIT,
	DH_KEYBOARD_ONE,
	DH_KEYBOARD_NINE,
	DH_KEYBOARD_ADDR,
	DH_KEYBOARD_INFO,
	DH_KEYBOARD_REC,
	DH_KEYBOARD_FN1,
	DH_KEYBOARD_FN2,
	DH_KEYBOARD_PLAY,
	DH_KEYBOARD_STOP,
	DH_KEYBOARD_SLOW,
	DH_KEYBOARD_FAST,
	DH_KEYBOARD_PREW,
	DH_KEYBOARD_NEXT,
	DH_KEYBOARD_JMPDOWN,
	DH_KEYBOARD_JMPUP,
	DH_TRIGGER_ALARM_IN = 100,					// Activate alarm input
	DH_TRIGGER_ALARM_OUT,						// Activate alarm output 
	DH_CTRL_MATRIX,								// Matrix control 
	DH_CTRL_SDCARD,								// SD card control(for IPC series). Please refer to HDD control
	DH_BURNING_START,							// Burner control:begin burning 
	DH_BURNING_STOP,							// Burner control:stop burning 
	DH_BURNING_ADDPWD,							// Burner control:overlay password(The string ended with '\0'. Max length is 8 bits. )
	DH_BURNING_ADDHEAD,							// Burner control:overlay head title(The string ended with '\0'. Max length is 1024 bytes. Use '\n' to Enter.)
	DH_BURNING_ADDSIGN,							// Burner control:overlay dot to the burned information(No parameter) 
	DH_BURNING_ADDCURSTOMINFO,					// Burner control:self-defined overlay (The string ended with '\0'. Max length is 1024 bytes. Use '\n' to Enter)
	DH_CTRL_RESTOREDEFAULT,						// restore device default setup 
	DH_CTRL_CAPTURE_START,						// Activate device snapshot
	DH_CTRL_CLEARLOG,							// Clear log
	DH_TRIGGER_ALARM_WIRELESS = 200,			// Activate wireless alarm (IPC series)
	DH_MARK_IMPORTANT_RECORD,					// Mark important record
	DH_CTRL_DISK_SUBAREA, 						// Network hard disk partition	
	DH_BURNING_ATTACH,							// Annex burning
	DH_BURNING_PAUSE,							// Burn Pause
	DH_BURNING_CONTINUE,						// Burn Resume
	DH_BURNING_POSTPONE,						// Burn Postponed
	DH_CTRL_OEMCTRL,							// OEM control
	DH_BACKUP_START,							// Start to device backup
	DH_BACKUP_STOP,								// Stop to device backup
	DH_VIHICLE_WIFI_ADD,						// Add WIFI configuration manually for car device
	DH_VIHICLE_WIFI_DEC,						// Delete WIFI configuration manually for car device
	DH_BUZZER_START,                            // Start to buzzer control 
	DH_BUZZER_STOP,                             // Stop to buzzer control
	DH_REJECT_USER,                             // Reject User
	DH_SHIELD_USER,                             // Shield User
	DH_RAINBRUSH,                               // Rain Brush 
	DH_MANUAL_SNAP,                             // manual snap (struct MANUAL_SNAP_PARAMETER)
	DH_MANUAL_NTP_TIMEADJUST,                   // manual ntp time adjust
	DH_NAVIGATION_SMS,                          // navigation info and note
	DH_CTRL_ROUTE_CROSSING,                     // route info
	DH_BACKUP_FORMAT,							// backup device format
	DH_DEVICE_LOCALPREVIEW_SLIPT,               // local preview split(struct DEVICE_LOCALPREVIEW_SLIPT_PARAMETER)    
	DH_CTRL_INIT_RAID,							// RAID init
	DH_CTRL_RAID,								// RAID control
	DH_CTRL_SAPREDISK,							// sapredisk control
	DH_WIFI_CONNECT,							// wifi connect(struct WIFI_CONNECT)
	DH_WIFI_DISCONNECT,							// wifi disconnect(struct WIFI_CONNECT)
	DH_CTRL_ARMED,                              // Arm/disarm operation 
} CtrlType;

// IO control command. Corresponding to CLIENT_QueryIOControlState
typedef enum _IOTYPE
{
	DH_ALARMINPUT = 1,							// Control alarm input 
	DH_ALARMOUTPUT = 2,							// ontrol alarm output 
	DH_DECODER_ALARMOUT = 3,					// Control alarm decoder output 
	DH_WIRELESS_ALARMOUT = 5,					// Control wireless alarm output 
	DH_ALARM_TRIGGER_MODE = 7,					// Alarm activation type(auto/manual/close). Use TRIGGER_MODE_CONTROL structure 
} DH_IOTYPE;

/////////////////////////////////Configuration Related/////////////////////////////////

// Resolution enumeration. For DH_DSP_ENCODECAP to use 
typedef enum _CAPTURE_SIZE
{
	CAPTURE_SIZE_D1,							// 704*576(PAL)  704*480(NTSC)
	CAPTURE_SIZE_HD1,							// 352*576(PAL)  352*480(NTSC)
	CAPTURE_SIZE_BCIF,							// 704*288(PAL)  704*240(NTSC)
	CAPTURE_SIZE_CIF,							// 352*288(PAL)  352*240(NTSC)
	CAPTURE_SIZE_QCIF,							// 176*144(PAL)  176*120(NTSC)
	CAPTURE_SIZE_VGA,							// 640*480
	CAPTURE_SIZE_QVGA,							// 320*240
	CAPTURE_SIZE_SVCD,							// 480*480
	CAPTURE_SIZE_QQVGA,							// 160*128
	CAPTURE_SIZE_SVGA,							// 800*592
	CAPTURE_SIZE_XVGA,							// 1024*768
	CAPTURE_SIZE_WXGA,							// 1280*800
	CAPTURE_SIZE_SXGA,							// 1280*1024  
	CAPTURE_SIZE_WSXGA,							// 1600*1024  
	CAPTURE_SIZE_UXGA,							// 1600*1200
	CAPTURE_SIZE_WUXGA,							// 1920*1200
	CAPTURE_SIZE_LTF,							// 240*192
	CAPTURE_SIZE_720,							// 1280*720
	CAPTURE_SIZE_1080,							// 1920*1080
	CAPTURE_SIZE_1_3M,							// 1280*960
	CAPTURE_SIZE_2M,							// 1872*1408
	CAPTURE_SIZE_5M,							// 3744*1408
	CAPTURE_SIZE_3M,							// 2048*1536
	CAPTURE_SIZE_5_0M,                          // 2432*2050
	CPTRUTE_SIZE_1_2M,							// 1216*1024
	CPTRUTE_SIZE_1408_1024,                     // 1408*1024
	CPTRUTE_SIZE_8M,                            // 3296*2472
	CPTRUTE_SIZE_2560_1920,                     // 2560*1920(5M)
	CAPTURE_SIZE_960H,                          // 960*576(PAL) 960*480(NTSC)
	CAPTURE_SIZE_960_720,                       // 960*720
	CAPTURE_SIZE_NR  
} CAPTURE_SIZE;

// Configuration file type. For CLIENT_ExportConfigFile to use. 
typedef enum __DH_CONFIG_FILE_TYPE
{
	DH_CONFIGFILE_ALL = 0,						// All configuration file 
	DH_CONFIGFILE_LOCAL,						// Local configuration file 
	DH_CONFIGFILE_NETWORK,						// Network configuration file 
	DH_CONFIGFILE_USER,							// User configuration file 
} DH_CONFIG_FILE_TYPE;

// NTP
typedef enum __DH_TIME_ZONE_TYPE
{
	DH_TIME_ZONE_0,								// {0, 0*3600,"GMT+00:00"}
	DH_TIME_ZONE_1,								// {1, 1*3600,"GMT+01:00"}
	DH_TIME_ZONE_2,								// {2, 2*3600,"GMT+02:00"}
	DH_TIME_ZONE_3,								// {3, 3*3600,"GMT+03:00"}
	DH_TIME_ZONE_4,								// {4, 3*3600+1800,"GMT+03:30"}
	DH_TIME_ZONE_5,								// {5, 4*3600,"GMT+04:00"}
	DH_TIME_ZONE_6,								// {6, 4*3600+1800,"GMT+04:30"}
	DH_TIME_ZONE_7,								// {7, 5*3600,"GMT+05:00"}
	DH_TIME_ZONE_8,								// {8, 5*3600+1800,"GMT+05:30"}
	DH_TIME_ZONE_9,								// {9, 5*3600+1800+900,"GMT+05:45"}
	DH_TIME_ZONE_10,							// {10, 6*3600,"GMT+06:00"}
	DH_TIME_ZONE_11,							// {11, 6*3600+1800,"GMT+06:30"}
	DH_TIME_ZONE_12,							// {12, 7*3600,"GMT+07:00"}
	DH_TIME_ZONE_13,							// {13, 8*3600,"GMT+08:00"}
	DH_TIME_ZONE_14,							// {14, 9*3600,"GMT+09:00"}
	DH_TIME_ZONE_15,							// {15, 9*3600+1800,"GMT+09:30"}
	DH_TIME_ZONE_16,							// {16, 10*3600,"GMT+10:00"}
	DH_TIME_ZONE_17,							// {17, 11*3600,"GMT+11:00"}
	DH_TIME_ZONE_18,							// {18, 12*3600,"GMT+12:00"}
	DH_TIME_ZONE_19,							// {19, 13*3600,"GMT+13:00"}
	DH_TIME_ZONE_20,							// {20, -1*3600,"GMT-01:00"}
	DH_TIME_ZONE_21,							// {21, -2*3600,"GMT-02:00"}
	DH_TIME_ZONE_22,							// {22, -3*3600,"GMT-03:00"}
	DH_TIME_ZONE_23,							// {23, -3*3600-1800,"GMT-03:30"}
	DH_TIME_ZONE_24,							// {24, -4*3600,"GMT-04:00"}
	DH_TIME_ZONE_25,							// {25, -5*3600,"GMT-05:00"}
	DH_TIME_ZONE_26,							// {26, -6*3600,"GMT-06:00"}
	DH_TIME_ZONE_27,							// {27, -7*3600,"GMT-07:00"}
	DH_TIME_ZONE_28,							// {28, -8*3600,"GMT-08:00"}
	DH_TIME_ZONE_29,							// {29, -9*3600,"GMT-09:00"}
	DH_TIME_ZONE_30,							// {30, -10*3600,"GMT-10:00"}
	DH_TIME_ZONE_31,							// {31, -11*3600,"GMT-11:00"}
	DH_TIME_ZONE_32,							// {32, -12*3600,"GMT-12:00"}
} DH_TIME_ZONE_TYPE;

typedef enum _SNAP_TYPE
{
	SNAP_TYP_TIMING = 0,
	SNAP_TYP_ALARM,
	SNAP_TYP_NUM,
} SNAP_TYPE;

typedef enum _CONNECT_STATE
{
	CONNECT_STATE_UNCONNECT  = 0,
	CONNECT_STATE_CONNECTING,
	CONNECT_STATE_CONNECTED,
} CONNECT_STATE;

// Snap mode
typedef enum tagDH_TRAFFIC_SNAP_MODE
{	
	DH_TRAFFIC_SNAP_MODE_COIL = 1,				       // Loop snap
	DH_TRAFFIC_SNAP_MODE_COIL_PICANALYSIS,		       // Loop snap   picture analysis
	DH_TRAFFIC_SNAP_MODE_STREAM,				       // Video snap
	DH_TRAFFIC_SNAP_MODE_STREAM_IDENTIFY,		       // Video snap and recognize
} DH_TRAFFIC_SNAP_MODE;

/////////////////////////////////Cancelled Type/////////////////////////////////

// Configuration type. The interface that uses the enumberaiton has been canceled. Please do not use. 
typedef enum _CFG_INDEX
{
    CFG_GENERAL = 0,							// General 
	CFG_COMM,									// COM
	CFG_NET,									// Network
	CFG_RECORD,									// Record
	CFG_CAPTURE,								// Video setup
	CFG_PTZ,									// PTZ
	CFG_DETECT,									// Motion detection
	CFG_ALARM,									// Alarm 
	CFG_DISPLAY,								// Display 
	CFG_RESERVED,								// Reserved to keet type consecutive
	CFG_TITLE = 10,								// channel title 
	CFG_MAIL = 11,								// Mail function 
	CFG_EXCAPTURE = 12,							// preview video setup
	CFG_PPPOE = 13,								// pppoe setup
	CFG_DDNS = 14,								// DDNS  setup
	CFG_SNIFFER	= 15,							// Network monitor capture setup
	CFG_DSPINFO	= 16,							// Encode capacity information
	CFG_COLOR = 126,							// Color setup information 
	CFG_ALL,									// Reserved 
} CFG_INDEX;


/************************************************************************
 ** Structure Definition 
 ***********************************************************************/
// Time
typedef struct 
{
	DWORD				dwYear;					// Year
	DWORD				dwMonth;				// Month
	DWORD				dwDay;					// Date
	DWORD				dwHour;					// Hour
	DWORD				dwMinute;				// Minute
	DWORD				dwSecond;				// Second
} NET_TIME,*LPNET_TIME;

typedef struct 
{
	DWORD				dwYear;					// Year
	DWORD				dwMonth;				// Month
	DWORD				dwDay;					// Date
	DWORD				dwHour;					// Hour
	DWORD				dwMinute;				// Minute
	DWORD				dwSecond;				// Second
	DWORD               dwMillisecond;          // Millisecond
	DWORD               dwReserved[2];          // reserved
} NET_TIME_EX,*LPNET_TIME_EX;

// The time definition in the log information
typedef struct _DHDEVTIME
{
	DWORD				second		:6;			// Second	1-60		
	DWORD				minute		:6;			// Minute	1-60		
	DWORD				hour		:5;			// Hour		1-24		
	DWORD				day			:5;			// Date		1-31		
	DWORD				month		:4;			// Month	1-12		
	DWORD				year		:6;			// Year	2000-2063	
} DHDEVTIME, *LPDHDEVTIME;

// callback data(Asynchronous interface)
typedef struct __NET_CALLBACK_DATA 
{
	int					nResultCode;			// Result code;0:Success
	char				*pBuf;					// Receive data,buffer is opened by the user,from the interface parameters
	int					nRetLen;				// the length of receive data
	LLONG				lOperateHandle;			// Operating handle
	void*				userdata;				// User parameters
	char				reserved[16];
} NET_CALLBACK_DATA, *LPNET_CALLBACK_DATA;

///////////////////////////////Monitor Related Definition ///////////////////////////////

// Frame parameter structure of Callback video data frame 
typedef struct _tagVideoFrameParam
{
	BYTE				encode;					// Encode type 
	BYTE				frametype;				// I = 0, P = 1, B = 2...
	BYTE				format;					// PAL - 0, NTSC - 1
	BYTE				size;					// CIF - 0, HD1 - 1, 2CIF - 2, D1 - 3, VGA - 4, QCIF - 5, QVGA - 6 ,
												// SVCD - 7,QQVGA - 8, SVGA - 9, XVGA - 10,WXGA - 11,SXGA - 12,WSXGA - 13,UXGA - 14,WUXGA - 15,
	DWORD				fourcc;					// If it is H264 encode it is always 0,Fill in FOURCC('X','V','I','D') in MPEG 4;
	DWORD				reserved;				// Reserved
	NET_TIME			struTime;				// Time information 
} tagVideoFrameParam;

// Frame parameter structure of audio data callback 
typedef struct _tagCBPCMDataParam
{
	BYTE				channels;				// Track amount 
	BYTE				samples;				// sample 0 - 8000, 1 - 11025, 2 - 16000, 3 - 22050, 4 - 32000, 5 - 44100, 6 - 48000
	BYTE				depth;					// Sampling depth. Value:8/16 show directly
	BYTE				param1;					// 0 - indication no symbol,1-indication with symbol
	DWORD				reserved;				// Reserved
} tagCBPCMDataParam;

// Data structure of channel video title overlay 
typedef struct _DH_CHANNEL_OSDSTRING
{
	BOOL				bEnable;				// Enable 
	DWORD				dwPosition[MAX_STRING_LINE_LEN];//Character position in each line. The value ranges from 1 to 9.Corresponding to the small keyboard.
												//		7upper left 	8upper		9upper right 
												//		4left			5middle 	6right 
												//		1down left		2down	    3down right 
	char				szStrings[MAX_STRING_LINE_LEN][MAX_PER_STRING_LEN];	// Max 6 lines. Each line max 20 bytes.
} DH_CHANNEL_OSDSTRING;

// Para struct of YUV callback
typedef struct _tagCBYUVDataParam
{
	long				nWidth;                 // Width of image
	long				nHeight;				// Height of image
	DWORD				reserved[8];			// reserved
} tagCBYUVDataParam;

///////////////////////////////Definition relate with playback///////////////////////////////

// Record file information
typedef struct
{
    unsigned int		ch;						// Channel number
    char				filename[128];			// File name 
    unsigned int		size;					// File length 
    NET_TIME			starttime;				// Start time 
    NET_TIME			endtime;				// End time 
    unsigned int		driveno;				// HDD number 
    unsigned int		startcluster;			// Initial cluster number 
	BYTE				nRecordFileType;		// Recorded file type  0:general record;1:alarm record ;2:motion detection;3:card number record ;4:image 
	BYTE                bImportantRecID;		// 0:general record 1:Important record
	BYTE                bHint;					// Document Indexing
	BYTE                bRecType;               // 0-main stream record 1-sub1 stream record 2-sub2 stream record 3-sub3 stream record
} NET_RECORDFILE_INFO, *LPNET_RECORDFILE_INFO;

// record state of everyday in one month
typedef struct
{
	BYTE 	    flag[32];						// has record this day 0-no, 1-yes
	BYTE		Reserved[64];					// reserved
}NET_RECORD_STATUS, *LPNET_RECORD_STATUS;

typedef struct
{
	unsigned short      left;                   // 0~8192
    unsigned short      right;                  // 0~8192
    unsigned short      top;                    // 0~8192
    unsigned short      bottom;                 // 0~8192
} MotionDetectRect;

// Smart Playback Information
typedef struct 
{
	MotionDetectRect    motion_rect;             // MotionDetect area
    NET_TIME            stime;                   // PlayBack start time
    NET_TIME            etime;                   // PlayBack stop time
	BYTE                bStart;                  // 1,start,2:stop
    BYTE                reserved[116];
} IntelligentSearchPlay, *LPIntelligentSearchPlay;

// The first recording time
typedef struct  
{
	int					nChnCount;				// Channel amount
	NET_TIME			stuFurthestTime[16];	// The first recording time, valid value is 0 to (nChnCount-1).If there is no video, the first recording time is 0.
	BYTE				bReserved[384];			// Reserved words
} NET_FURTHEST_RECORD_TIME;

///////////////////////////////Alarm Related Definition ///////////////////////////////

// General alarm informaiton 
typedef struct
{
	int					channelcount;
	int					alarminputcount;
	unsigned char		alarm[16];				// External alarm 
	unsigned char		motiondection[16];		// Motion detection 
	unsigned char		videolost[16];			// Video loss 
} NET_CLIENT_STATE;

// General alarm information
typedef struct
{
	int					channelcount;
	int					alarminputcount;
    unsigned char		alarm[32];				// External alarm 
	unsigned char		motiondection[32];		// Motion detection 
	unsigned char		videolost[32];			// Video loss 
	BYTE                bReserved[32];
} NET_CLIENT_STATE_EX;

// struct of input alarm
typedef struct
{
	DWORD              dwSize;
	int				   alarminputcount;
	DWORD              dwAlarmState[DH_MAX_CHANMASK];// one DWORD for 32 channels, the state by bit of channels 0-31,0-no alarm,1-alarm
}NET_CLIENT_ALARM_STATE;

// struct of video loss alarm
typedef struct
{
	DWORD              dwSize;
	int				   channelcount;
	DWORD              dwAlarmState[DH_MAX_CHANMASK];// one DWORD for 32 channels, the state by bit of channels 0-31,0-no alarm,1-alarm
}NET_CLIENT_VIDEOLOST_STATE;

// struct of motion alarm
typedef struct
{
	DWORD              dwSize;
	int				   channelcount;
	DWORD              dwAlarmState[DH_MAX_CHANMASK];// one DWORD for 32 channels, the state by bit of channels 0-31,0-no alarm,1-alarm
}NET_CLIENT_MOTIONDETECT_STATE;

// struct of querying detailed motion alarm
typedef struct
{
	DWORD              dwSize;
	int                nChannelID;				// channel id
	BOOL               bAlarm;					// alarm or not,value is TRUE/FALSE
	int                nLevel;					// alarm level,in 1/1000 as a unit
}NET_CLIENT_DETAILEDMOTION_STATE;

// Alarm IO control 
typedef struct 
{
	unsigned short		index;					// Port serial number 
	unsigned short		state;					// Port status 
} ALARM_CONTROL;

//Activation type 
typedef struct
{
	unsigned short		index;					// Port serial number 
	unsigned short		mode;					// Activation way(0:close.1:manual.2:auto); The SDK reserves the original setup if you do not set channel here. 
	BYTE				bReserved[28];			
} TRIGGER_MODE_CONTROL;

// Alarm decoder control 
typedef struct 
{
	int					decoderNo;				// Alarm decoder. It begins from 0. 
	unsigned short		alarmChn;				// Alarm output port. It begin from o., 
	unsigned short		alarmState;				// Alarm output status;1:open,0:close.
} DECODER_ALARM_CONTROL;

// Alarm information of alarm upload function
typedef struct  
{
	DWORD				dwAlarmType;			// Alarm type,when dwAlarmType = DH_UPLOAD_EVENT,dwAlarmMask and bAlarmDecoderIndex are invalid.
	DWORD				dwAlarmMask;			// Alarm information subnet mask. Bit represents each alarm status
	char				szGlobalIP[DH_MAX_IPADDR_LEN];				// Client-end IP address 
	char				szDomainName[DH_MAX_DOMAIN_NAME_LEN];		// Client-end domain name
	int					nPort;					// The port client-end connected when upload alarm 
	char				szAlarmOccurTime[DH_ALARM_OCCUR_TIME_LEN];	// Alarm occurred time 
	BYTE				bAlarmDecoderIndex;		// It means which alarm decoder. It is valid when dwAlarmType = DH_UPLOAD_DECODER_ALARM.
	BYTE				bReservedSpace[15];
} NEW_ALARM_UPLOAD;

// Recording-changed alarm information
typedef struct
{
	int					nChannel;				// Record channel number
	char				reserved[12];
} ALARM_RECORDING_CHANGED;

// CoilFault alarm event
typedef struct __ALARM_WINGDING_INFO
{
	int                 nDriveWayID;            // road number
	int                 nWindingID;             // coil ID
	NET_TIME            stuTime;                // event happen time 
	int                 nState;                 // Device state,0 indicate fault recover,1 indicate fault happen
	DWORD				dwChannel;				// Channel of alarm
	char                reserve[28];
} ALARM_WINGDING_INFO;

// traffic congestion alarm 
typedef struct __ALARM_TRAF_CONGESTION_INFO
{
	int                 nDriveWayID;            // road number
	int                 nCongestionLevel;       // traffic congestion grade:1,2,3,4,5,6;1 indicate the most one 
	NET_TIME            stuTime;                // event happen time 
	int                 nState;                 // Device state,0 indicate fault recover,1 indicate fault happen
	DWORD				dwChannel;				// Channel of alarm
	char                reserve[28];
} ALARM_TRAF_CONGESTION_INFO;

// traffic exception alarm
typedef struct __ALARM_TRAF_EXCEPTION_INFO
{
	int                 nDriveWayID;            // road number
	NET_TIME            stuTime;                // event happen time
	int                 nState;                 // Device state,0 indicate fault recover,1 indicate fault happen
	DWORD				dwChannel;				// Channel of alarm
	char                reserve[28];
} ALARM_TRAF_EXCEPTION_INFO;

// fill equipment alarm 
typedef struct __ALARM_EQUIPMENT_FILL_INFO
{
	int                 nDriveWayID;            // road number
	NET_TIME            stuTime;                // event happen time
	int                 nState;                 // Device state,0 indicate fault recover,1 indicate fault happen
	DWORD				dwChannel;				// Channel of alarm
	char                reserve[28];
} ALARM_EQUIPMENT_FILL_INFO;

// alarm arm disarm state info
typedef struct __ALARM_ARM_DISARM_STATE_INFO
{
	BYTE                bState;                 // arm-disarm,0 means disarm,1 means arm, 2 means ForceOn
	char                reserve[31];
} ALARM_ARM_DISARM_STATE_INFO;

// 3G flow exceed state info 
typedef struct __DHDEV_3GFLOW_EXCEED_STATE_INFO
{
	BYTE                bState;                 //  3G flow exceed state,0 means not exceed,1 means exceed
	char                reserve[31];
} DHDEV_3GFLOW_EXCEED_STATE_INFO;

// alarm of speed limit (DH_DEVSTATE_SPEED_LIMIT)
typedef struct __ALARM_SPEED_LIMIT
{
	char                szType[DH_SPEEDLIMIT_TYPE_LEN];   // alarm type?¨ºoLowerSpeed, UpperSpeed
	int                 iSpeedLimit;            // limit speed KM/H 
	int                 iSpeed;                 // speed KM/H
	char                szCrossingID[DH_MAX_CROSSING_ID]; // crossing ID
	DWORD				dwLongitude;			// longitude(millionth degree, 0-360)
    DWORD				dwLatidude;				// latidude(millionth degree,0-180)
	char				reserve[24];
}ALARM_SPEED_LIMIT;

// alarm of over loading
typedef struct __ALARM_OVER_LOADING
{
    NET_TIME			stuCurTime;             // current time
    DWORD				dwLatidude;				// latidude(millionth degree,0-180)
    DWORD				dwLongitude;			// longitude(millionth degree, 0-360)
    char				szDriverNo[DH_VEHICLE_DRIVERNO_LEN];    // driver id
    DWORD				dwCurSpeed;             // current speed
    BYTE				byReserved[128]; 
}ALARM_OVER_LOADING;

// alarm of hard braking
typedef struct __ALARM_HARD_BRAKING
{
    NET_TIME			stuCurTime;             // current time
    DWORD				dwLatidude;				// latidude(millionth degree,0-180)
    DWORD				dwLongitude;			// longitude(millionth degree, 0-360)
    char				szDriverNo[DH_VEHICLE_DRIVERNO_LEN];    // driver id
    DWORD				dwCurSpeed;             // current speed
    BYTE				byReserved[128]; 
}ALARM_HARD_BRAKING;

// alarm of smoke sensor
typedef struct __ALARM_SMOKE_SENSOR
{
	NET_TIME			stuCurTime;             // current time
	int					nChannel;               // channel
	BYTE				byHighTemperature;      // 1:hight temperature alarm start,0:end
	BYTE				bySmoke;                // 1:smoke alarm start,0:end
	BYTE				byReservrd[126];
}ALARM_SMOKE_SENSOR;

// alarm of traffic light
typedef struct _LIGHT_INFO
{
	BYTE               byDirection;            // direction: 1-left,2-right,3-straight , 4-turn round
	BYTE               byState;                // light state: 1-fault,2-normal
	BYTE               byReserved[62];         // reserved
}LIGHT_INFO;

typedef struct __ALARM_TRAFFIC_LIGHT_FAULT 
{
	NET_TIME           stTime;                 // alarm time
	int                nInfoNumber;            // info number
	LIGHT_INFO         stLightInfo[8];         // info
	BYTE               byReserved[128];        // reserved
}ALARM_TRAFFIC_LIGHT_FAULT;

// Flux alarm channel information
typedef struct __ALARM_TRAFFIC_FLUX_LANE_INFO
{
	NET_TIME            stuCurTime;            // current time
	int                 nLane;                 // lane number
	int                 nState;                // state:1-traffic jam, 2-traffic jam recover, 3-normal 4-break, 5-break recover
	int                 nFlow;                 // flow value,unit:per/second
	BYTE                byReserved[124];       // reserved
}ALARM_TRAFFIC_FLUX_LANE_INFO;

// SIP state alarm
typedef struct __ALARM_SIP_STATE
{
	int					nChannelID;
	BYTE				byStatus;               //0:succeed,1:unregistered ,2:invalid,3:registing,4:talking
	BYTE				bReserved[63];			//reserved
}ALARM_SIP_STATE;

// vehicle info uploading (DH_DEVSTATE_VIHICLE_INFO_UPLOAD)
typedef struct __ALARM_VEHICLE_INFO_UPLOAD
{
    char                szType[DH_VEHICLE_TYPE_LEN];            //type: DirverCheck ,Driver check in or check out
	char                szCheckInfo[DH_VEHICLE_INFO_LEN];       //Check in, Check out
    char                szDirverNO[DH_VEHICLE_DRIVERNO_LEN];    //Driver NO. string
	char                reserved[64];
}ALARM_VEHICLE_INFO_UPLOAD;

// card record uploading
typedef struct __ALARM_CARD_RECORD_INFO_UPLOAD
{
	int					nChannel;				// channel id
	BOOL				bEnable;				// is recording
	char				szCardInfo[DH_MAX_CARD_INFO_LEN];	// card info
	NET_TIME			stuTime;				// card start time
	BOOL                bPreviewOverlayEn;      // preview overlay enable
	BYTE                byOverlayPos;           // overlay position,1-left top,2-left bottom,3-right top,4-right bottom
	char				reserved[59];
}ALARM_CARD_RECORD_INFO_UPLOAD;

typedef enum __ATMTradeTypes
{
	TRADE_TYPE_INC = 0,							// INSERTCARD
	TRADE_TYPE_WDC,								// WITHDRAWCARD
	TRADE_TYPE_CKT,								// CHECKTIME
	TRADE_TYPE_INQ,								// Query
	TRADE_TYPE_CWD,								// draw 
	TRADE_TYPE_PIN,								// change password
	TRADE_TYPE_TFR,								// debit
	TRADE_TYPE_DEP,								// deposit
	TRADE_TYPE_NCINQ,							// card less query
	TRADE_TYPE_NCDEP,							// card less deposit
	TRADE_TYPE_OTHERS,							// other
	TRADE_TYPE_ALL,								// all
}DH_eATMTradeTypes;

typedef struct __ALARM_ATM_INFO_UPLOAD_CHNL
{
	int					nChannel;				// channel
	char				szATMID[32];			// ATM id
	char				szCardNo[32];			// card number, 6222421541208230456 
	char				szTradetime[32];		// trade time, 20111118112200 means 2011-11-18 11:22:00
	DH_eATMTradeTypes	emTradeType;			// trade type
	int					nAmount;				// trade mount	0-4294967296
	BYTE				byRerved[32];			// reserved
}ALARM_ATM_INFO_UPLOAD_CHNL;

// ATM trade info uploading info
typedef struct __ALARM_ATM_INFO_UPLOAD
{
	int							nCnt;
	ALARM_ATM_INFO_UPLOAD_CHNL	m_stAtmInfo[DH_MAX_CHANNUM];
}ALARM_ATM_INFO_UPLOAD;

// camera move alarm
typedef struct __ALARM_CAMERA_MOVE_INFO
{
	int                         nChannelNum;                        // the number of alarm channel
	unsigned char               alarmChannels[DH_MAX_CHANNUM_EX];   // the channel information of alarm happened
	BYTE                        byReserved[128];
}ALARM_CAMERA_MOVE_INFO;
// detailed motion alarm
typedef struct __ALARM_DETAILEDMOTION_CHNL_INFO
{
	DWORD              dwSize;
	int                nChannelID;    // channel
	BOOL               bAlarm;        // alarm or not,value is TRUE/FALSE
	int                nLevel;        // alarm level,in 1/1000 as a unit
}ALARM_DETAILEDMOTION_CHNL_INFO;

// storage failure alarm info
typedef struct __ALARM_STORAGE_FAILURE
{
	DWORD     dwSize;                                     // struct size
	UINT      ActionType;                                 // 0:stop 1:start
	char      szProtocol[DH_MAX_STRING_LEN];              // protocol type
	char      szServerAddr[DH_MAX_IPADDR_OR_DOMAIN_LEN];  // server device's ip 
	DWORD     dwPort;                                     // port number
	NET_TIME  stuTime;                                    // event happen time
	int		  nChannel;									  // channel, from 1 to n, 0-this param is not valid.
}ALARM_STORAGE_FAILURE;

// front IPC disconnect alarm info
typedef struct __ALARM_FRONTDISCONNET_INFO
{
	DWORD              dwSize;                           // struct size
	int                nChannelID;                       // channel id
	int                nAction;                          // 0:stop 1:start
	NET_TIME           stuTime;                          // event happen time
	char               szIpAddress[MAX_PATH];            // front IP's address
}ALARM_FRONTDISCONNET_INFO;

// battery low power alarm info
typedef struct __ALARM_BATTERYLOWPOWER_INFO
{
	DWORD             dwSize;                            // struct size
	int               nAction;                           // 0:stop 1:start
	int               nBatteryLeft;                      // battery left, unit:%
	NET_TIME          stTime;                            // event happen time
	
}ALARM_BATTERYLOWPOWER_INFO;

// temperature alarm info
typedef struct __ALARM_TEMPERATURE_INFO
{
	DWORD              dwSize;                           // struct size
	char               szSensorName[DH_MACHINE_NAME_NUM];// sensor name
	int                nChannelID;                       // channel id
	int                nAction;                          // 0:stop 1:start
	float              fTemperature;                     // current temperature, unit:degree centigrade
	NET_TIME           stTime;                           // event happen time
}ALARM_TEMPERATURE_INFO;

// ?¡ê¨¤¨ª?Y¨º?¡À¡§?¡¥
typedef struct __ALARM_TIREDDRIVE_INFO
{
	DWORD             dwSize;                            // struct size
	int               nAction;                           // 0:stop 1:start
	int               nDriveTime;                        // drive time, unit:minute
	NET_TIME          stTime;                            // event happen time
}ALARM_TIREDDRIVE_INFO;

//Alarm of record loss
typedef struct __ALARM_LOST_RECORD
{
	DWORD     dwSize;                                     //Structure size
	UINT      ActionType;                                 // 0: Stop, 1: start
	UINT      nChannelID;                                 // Channel ID, start from 1
	UINT      nStreamType;                                // Bit Stream type, 0: main stream; 1: extra stream1; 2: extra stream2; 3: extra stream3; 4: snapshot stream
	NET_TIME  stuTime;                                    // Event occurrence time	
}ALARM_LOST_RECORD;

// Alarm of High CPU Occupancy rate, temporarily we set the max limit as 95%
typedef struct __ALARM_HIGH_CPU
{
	DWORD     dwSize;                                     //Structure size
	UINT      ActionType;                                 // 0: Stop, 1: start
	UINT      nUsed;                                      // 1000 times of  CPU Occupancy rate
	NET_TIME  stuTime;                                    // Event occurrence time
}ALARM_HIGH_CPU;


// Alarm of netpackage loss
typedef struct __ALARM_LOST_NETPACKET
{
	DWORD     dwSize;                                     //Structure size
	UINT      ActionType;                                 //0: Stop, 1: start
	UINT      nChannelID;                                 // Channel ID, start from 1
	UINT      nStreamType;                                // Bit stream type, 0: main stream; 1: extra stream1; 2: extra stream2; 3: extra stream3; 4: snapshot stream
	char      szRemoteIP[DH_MAX_IPADDR_LEN];              // IP address of sending
	DWORD     dwRemotePort;                               // Port address of sending 
	NET_TIME  stuTime;                                    // Event occurrence time
}ALARM_LOST_NETPACKET;

// Alarm of High memory Occupancy rate, temporarily we set the max limit as 95%
typedef struct __ALARM_HIGH_MEMORY
{
	DWORD     dwSize;                                     //Structure size
	UINT      ActionType;                                 // 0: Stop, 1: start
	UINT      nUsed;                                      // 1000 times of  memory Occupancy rate
	NET_TIME  stuTime;                                    // Event occurrence time	
}ALARM_HIGH_MEMORY;
/////////////////////////////Audio Talk Related Definition/////////////////////////////

// Audio format information 
typedef struct
{
	BYTE				byFormatTag;			// Encode type such as 0:PCM
	WORD				nChannels;				// Track number 
	WORD				wBitsPerSample;			// Sampling depth 	
	DWORD				nSamplesPerSec;			// Sampling rate
} DH_AUDIO_FORMAT, *LPDH_AUDIO_FORMAT;

/////////////////////////////User Management Corresponding Definition /////////////////////////////

// Support the device with max 8 bits user name. Corresponding to the CLIENT_QueryUserInfo and CLIENT_OperateUserInfo.
// Right information 
typedef struct _OPR_RIGHT
{
	DWORD				dwID;
	char				name[DH_RIGHT_NAME_LENGTH];
	char				memo[DH_MEMO_LENGTH];
} OPR_RIGHT;

// User information 
typedef struct _USER_INFO
{
	DWORD				dwID;
	DWORD				dwGroupID;
	char				name[DH_USER_NAME_LENGTH];
	char				passWord[DH_USER_PSW_LENGTH];
	DWORD				dwRightNum;
	DWORD				rights[DH_MAX_RIGHT_NUM];
	char				memo[DH_MEMO_LENGTH];
	DWORD				dwReusable;				// Reuse or not;1:enable reuse;0:disable reuser 
} USER_INFO;

// User group information 
typedef struct _USER_GROUP_INFO
{
	DWORD				dwID;
	char				name[DH_USER_NAME_LENGTH];
	DWORD				dwRightNum;
	DWORD				rights[DH_MAX_RIGHT_NUM];
	char				memo[DH_MEMO_LENGTH];
} USER_GROUP_INFO;

// User information list 
typedef struct _USER_MANAGE_INFO
{
	DWORD				dwRightNum;				// Right information 
	OPR_RIGHT			rightList[DH_MAX_RIGHT_NUM];
	DWORD				dwGroupNum;				// User group information 
	USER_GROUP_INFO		groupList[DH_MAX_GROUP_NUM];
	DWORD				dwUserNum;				// User information 
	USER_INFO			userList[DH_MAX_USER_NUM];
	DWORD				dwSpecial;				// User account reuse; 1:support account to be reused. 0:Does not support account to be reused.
} USER_MANAGE_INFO;

// Support the device of max 8-bit or 16-bit name. Corresponding interface to CLIENT_QueryUserInfoEx and CLIENT_OperateUserInfoEx
#define DH_USER_NAME_LENGTH_EX		16			// User name length 
#define DH_USER_PSW_LENGTH_EX		16			// Password 

// Right information
typedef struct _OPR_RIGHT_EX
{
	DWORD				dwID;
	char				name[DH_RIGHT_NAME_LENGTH];
	char				memo[DH_MEMO_LENGTH];
} OPR_RIGHT_EX;

// User information 
typedef struct _USER_INFO_EX
{
	DWORD				dwID;
	DWORD				dwGroupID;
	char				name[DH_USER_NAME_LENGTH_EX];
	char				passWord[DH_USER_PSW_LENGTH_EX];
	DWORD				dwRightNum;
	DWORD				rights[DH_MAX_RIGHT_NUM];
	char				memo[DH_MEMO_LENGTH];
	DWORD				dwFouctionMask;			// Subnet mask,0x00000001 - support reuse  
	BYTE				byReserve[32];
} USER_INFO_EX;

// User group information 
typedef struct _USER_GROUP_INFO_EX
{
	DWORD				dwID;
	char				name[DH_USER_NAME_LENGTH_EX];
	DWORD				dwRightNum;
	DWORD				rights[DH_MAX_RIGHT_NUM];
	char				memo[DH_MEMO_LENGTH];
} USER_GROUP_INFO_EX;

// User information sheet 
typedef struct _USER_MANAGE_INFO_EX
{
	DWORD				dwRightNum;				// Right information 
	OPR_RIGHT_EX		rightList[DH_MAX_RIGHT_NUM];
	DWORD				dwGroupNum;				// User group information 
	USER_GROUP_INFO_EX  groupList[DH_MAX_GROUP_NUM];
	DWORD				dwUserNum;				// User information 
	USER_INFO_EX		userList[DH_MAX_USER_NUM];
	DWORD				dwFouctionMask;			// Subnet mask;0x00000001 - support reuse, 0x00000002 - Password has been modified , it needs to be verified.
	BYTE				byNameMaxLength;		// The supported user name max length 
	BYTE				byPSWMaxLength;			// The supported password max length
	BYTE				byReserve[254];
} USER_MANAGE_INFO_EX;

// Max support a device of 64-channel. Corresponding extension interface CLIENT_QueryUserInfoNew and CLIENT_OperateUserInfoNew
#define  DH_NEW_MAX_RIGHT_NUM    320
#define DH_NEW_USER_NAME_LENGTH	 128			// User name length
#define DH_NEW_USER_PSW_LENGTH	 128			// password

// Rights info
typedef struct _OPR_RIGHT_NEW
{
	DWORD               dwSize;
	DWORD				dwID;
	char				name[DH_RIGHT_NAME_LENGTH];
	char				memo[DH_MEMO_LENGTH];
} OPR_RIGHT_NEW;

// User info
typedef struct _USER_INFO_NEW
{
	DWORD               dwSize;
	DWORD				dwID;
	DWORD				dwGroupID;
	char				name[DH_NEW_USER_NAME_LENGTH];
	char				passWord[DH_NEW_USER_PSW_LENGTH];
	DWORD				dwRightNum;
	DWORD				rights[DH_NEW_MAX_RIGHT_NUM];
	char				memo[DH_MEMO_LENGTH];
	DWORD				dwFouctionMask;			// Sub mask,0x00000001 - Support account reusable
	BYTE				byReserve[32];
} USER_INFO_NEW;

// User group info
typedef struct _USER_GROUP_INFO_NEW
{
	DWORD               dwSize;
	DWORD				dwID;
	char				name[DH_USER_NAME_LENGTH_EX];
	DWORD				dwRightNum;
	DWORD				rights[DH_NEW_MAX_RIGHT_NUM];
	char				memo[DH_MEMO_LENGTH];
} USER_GROUP_INFO_NEW;

// User info list
typedef struct _USER_MANAGE_INFO_NEW
{
	DWORD               dwSize;
	DWORD				dwRightNum;				// Rights info
	OPR_RIGHT_NEW		rightList[DH_NEW_MAX_RIGHT_NUM];
	DWORD				dwGroupNum;				// User group info
	USER_GROUP_INFO_NEW  groupList[DH_MAX_GROUP_NUM];
	DWORD				dwUserNum;				// User info
	USER_INFO_NEW		userList[DH_MAX_USER_NUM];
	DWORD				dwFouctionMask;			// Sub mask; 0x00000001 - Support account reusable,0x00000002 - Verification needed when change password
	BYTE				byNameMaxLength;		// Max user name length supported
	BYTE				byPSWMaxLength;			// Max password length supported
	BYTE				byReserve[254];
} USER_MANAGE_INFO_NEW;

///////////////////////////////Search Related Definition ///////////////////////////////

// The language types device supported 
typedef struct _DH_LANGUAGE_DEVINFO
{
	DWORD				dwLanguageNum;			// The language amount supported
	BYTE				byLanguageType[252];	// Enumeration value please refer to DH_LANGUAGE_TYPE
} DH_DEV_LANGUAGE_INFO, *LPDH_DEV_LANGUAGE_INFO;

// the IPC types device supported
typedef struct
{
	int                 nTypeCount;              // The IPC type amount supported
	BYTE                bSupportTypes[128];      // Enumeration value please refer to EM_IPC_TYPE
}DH_DEV_IPC_INFO;

//3G net flow info
typedef struct
{
	int					nStrategy;              // strategy,0: charged by flow every month 1:charged by time every month
	int                 nUplimit;               // up limit flow, by flow: MB, by time: h
	int                 nUsed;                  // have used flow, by flow: MB, by time: h
	BYTE                bReserved[64];          // reserved
}DH_DEV_3GFLOW_INFO;

typedef struct
{
	BYTE			    byEthNum;				// 3G model number
	BYTE				byReserved[255];        // reserved
}DH_DEV_3GMODULE_INFO;
typedef struct
{
	DWORD				dwId;                            // ddns server id
	char				szState[DH_MAX_DDNS_STATE_LEN];	 // ddns status
	BYTE				bReserved[512];                  // reserved
}DH_DEV_DNS_INFO;

typedef struct
{
	DWORD				dwDdnsServerNum;	
	DH_DEV_DNS_INFO     stDdns[DH_MAX_DDNS_NUM];
}DH_DEV_MULTI_DDNS_INFO;
// device URL info
typedef struct
{
	char				szURLInfo[512];         // device URL info, by string
	BYTE				bReserved[512];
}DH_DEV_URL_INFO;
// HDD informaiton 
typedef struct
{
	DWORD				dwVolume;				// HDD capacity 
	DWORD				dwFreeSpace;			// HDD free space 
	BYTE				dwStatus;				// higher 4 byte instruct hdd type, see the enum struct EM_DISK_TYPE; lower four byte instruct HDD status,0-hiberation,1-active,2-malfucntion and etc.;Devide DWORD into four BYTE
	BYTE				bDiskNum;				// HDD number
	BYTE				bSubareaNum;			// Subarea number
	BYTE				bSignal;				// Symbol. 0:local. 1:remote
} NET_DEV_DISKSTATE,*LPNET_DEV_DISKSTATE;

// Device HDD informaiton 
typedef struct _DH_HARDDISK_STATE
{
	DWORD				dwDiskNum;				// Amount 
	NET_DEV_DISKSTATE	stDisks[DH_MAX_DISKNUM];// HDD or subarea information 
} DH_HARDDISK_STATE, *LPDH_HARDDISK_STATE;

typedef DH_HARDDISK_STATE	DH_SDCARD_STATE;	// SD card. Please refer to HDD information for data structure. 

// Audio encode information 
typedef struct  
{
	DH_TALK_CODING_TYPE	encodeType;				// Encode type 
	int					nAudioBit;				// Bit:8/16
	DWORD				dwSampleRate;			// Sampling rate such as 8000 or 16000
	char				reserved[64];
} DHDEV_TALKDECODE_INFO;

// The audio talk type the device supported
typedef struct 
{
	int					nSupportNum;			// Amount
	DHDEV_TALKDECODE_INFO type[64];				// Encode type 
	char				reserved[64];
} DHDEV_TALKFORMAT_LIST;

// PTZ property information
#define  NAME_MAX_LEN 16
typedef struct 
{
	DWORD				dwHighMask;				// Operation mask high bit 
	DWORD				dwLowMask;				// Operation mask low bit 
	char				szName[NAME_MAX_LEN];	// Operation protocol name 
	WORD				wCamAddrMin;			// Channel address min value
	WORD				wCamAddrMax;			// Channel address max value
	WORD				wMonAddrMin;			// Monitor address min value
	WORD				wMonAddrMax;			// Monitor address max value
	BYTE				bPresetMin;				// Preset min value
	BYTE				bPresetMax;				// Preset max value
	BYTE				bTourMin;				// Auto tour min value
	BYTE				bTourMax;				// Auto tour max value
	BYTE				bPatternMin;			// Pattern min value
	BYTE				bPatternMax;			// Pattern max value
	BYTE				bTileSpeedMin;			// Tilt speed min value
	BYTE				bTileSpeedMax;			// Tilt speed max value
	BYTE				bPanSpeedMin;			// Pan speed min value
	BYTE				bPanSpeedMax;			// Pan speed max value
	BYTE				bAuxMin;				// Aux function min value
	BYTE				bAuxMax;				// Aux function max value
	int					nInternal;				// Command interval
	char				cType;					// Protocol type
	BYTE				bReserved_1;			// Reserved
	BYTE				bFuncMask;				// function mask :0x01 - support PTZ-inside function
	BYTE				bReserved_2;
	char				Reserved[4];
} PTZ_OPT_ATTR;

// Burner informaiton 
typedef struct _NET_DEV_BURNING
{
	DWORD				dwDriverType;			// Burner driver type;0:DHFS,1:DISK,2:CDRW
	DWORD				dwBusType;				// Bus type;0:USB,1:1394,2:IDE
	DWORD				dwTotalSpace;			// Total space(KB)
	DWORD				dwRemainSpace;			// Free space(KB)
	BYTE				dwDriverName[DH_BURNING_DEV_NAMELEN];	// Burner driver name
} NET_DEV_BURNING, *LPNET_DEV_BURNING;

// Device burner informaiton 
typedef struct _DH_BURNING_DEVINFO
{
	DWORD				dwDevNum;				// Burner device amount
	NET_DEV_BURNING		stDevs[DH_MAX_BURNING_DEV_NUM];	// Each burner device information 
} DH_BURNING_DEVINFO, *LPDH_BURNING_DEVINFO;

// Burner progress 
typedef struct _DH_BURNING_PROGRESS
{
	BYTE				bBurning;				// Burner status;0:ready to burn,1:burner typs is not correct. It does not match. 
												// 2:there is no burner available,3:There is burning in process,4:Burner is not free(It is backup or buring or playback.) 
	BYTE				bRomType;				// CD type;0:Dahua file system,1:Portable HDD or flash disk,2:CD
	BYTE				bOperateType;			// Operation type;0:free,1:backup,2:burning,3:playback from the cd 
	BYTE				bType;					// Backup pr burning status:0:stop or end,1:start,2:error,3:full,4:initializing
	NET_TIME			stTimeStart;			// Begin time 
	DWORD				dwTimeElapse;			// Burning time(second)
	DWORD				dwTotalSpace;			// Total space
	DWORD				dwRemainSpace;			// Free space
	DWORD				dwBurned;				// Burned capacity 
	WORD				dwStatus;				// Reserved
	WORD				wChannelMask;			// The burning channel mask 
} DH_BURNING_PROGRESS, *LPDH_BURNING_PROGRESS;

// Log information. Corresponding to CLIENT_QueryLog
typedef struct _DH_LOG_ITEM
{
    DHDEVTIME			time;					// Date 
    unsigned short		type;					// Type
    unsigned char		reserved;				// Reserved
    unsigned char		data;					// Data 
    unsigned char		context[8];				// Content
} DH_LOG_ITEM, *LPDH_LOG_ITEM;

// Log information. Corresponding to CLIENT_QueryLogEx, paramter reserved(int nType=1;reserved=&nType;)
typedef struct _DH_NEWLOG_ITEM
{
	DHDEVTIME			time;					// Date
	WORD				type;					// Type
	WORD				data;					// data
	char				szOperator[8]; 			// User name 
	BYTE				context[16];		    // Content	
} DH_NEWLOG_ITEM, *LPDH_NEWLOG_ITEM;

// Log information. Corresponding to CLIENT_QueryDeviceLog
typedef struct _DH_DEVICE_LOG_ITEM
{
	int					nLogType;				// Log type 
	DHDEVTIME			stuOperateTime;			// Date
	char				szOperator[16]; 		// Operator
	BYTE				bReserved[3];
	BYTE				bUnionType;				// union structure type,0:szLogContext;1:stuOldLog?¡ê
	union
	{
		char			szLogContext[64];		// Log content
		struct 
		{
			DH_LOG_ITEM		stuLog;				// Old log structure 
			BYTE			bReserved[48];		// Reserved
		}stuOldLog;
	};
	char				reserved[16];
} DH_DEVICE_LOG_ITEM, *LPDH_DEVICE_LOG_ITEM;

// new Log information. Corresponding to CLIENT_QueryDeviceLog
typedef struct _DH_DEVICE_LOG_ITEM_EX
{
	int					nLogType;				// Log type 
	DHDEVTIME			stuOperateTime;			// Date
	char				szOperator[16]; 		// Operator
	BYTE				bReserved[3];
	BYTE				bUnionType;				// union structure type,0:szLogContext;1:stuOldLog?¡ê
	union
	{
		char			szLogContext[64];		// Log content
		struct 
		{
			DH_LOG_ITEM		stuLog;				// Old log structure 
			BYTE			bReserved[48];		// Reserved
		}stuOldLog;
	};
	char                szOperation[32];        // Detail operation
	char				szDetailContext[4 * 1024];  // DetailContext
} DH_DEVICE_LOG_ITEM_EX, *LPDH_DEVICE_LOG_ITEM_EX;

// Record log informaiton. Corresponding to the context of log structure 
typedef struct _LOG_ITEM_RECORD
{
	DHDEVTIME			time;					// Time 
	BYTE				channel;				// Channel
	BYTE				type;					// Record type
	BYTE				reserved[2];
} LOG_ITEM_RECORD, *LPLOG_ITEM_RECORD;

typedef struct _QUERY_DEVICE_LOG_PARAM
{
	 DH_LOG_QUERY_TYPE	emLogType;				// Searched log type
	 NET_TIME			stuStartTime;			// The searched log start time
	 NET_TIME			stuEndTime;				// The searched log end time. 
	 int				nStartNum;				// The search begins from which log in one period. It shall begin with 0 if it is the first time search.
	 int				nEndNum;				// The ended log serial number in one search,the max returning number is 1024 
	 BYTE                nLogStuType;           // log struct type,0:DH_DEVICE_LOG_ITEM;1:DH_DEVICE_LOG_ITEM_EX
	BYTE                reserved[3];            // Reserved
	unsigned int        nChannelID;             // Channel no. 0:Compatible with previous all channel numbers. The channel No. begins with 1.1: The first channel.
	BYTE				bReserved[40];
} QUERY_DEVICE_LOG_PARAM;

// record information in the hard disk
typedef struct __DEV_DISK_RECORD_INFO 
{
	NET_TIME			stuBeginTime;			// The first time video
	NET_TIME			stuEndTime;				// Recently video
	char				reserved[128];
} DEV_DISK_RECORD_INFO;

///////////////////////////////Control Related Definition///////////////////////////////

// HDD operation
typedef struct _DISKCTRL_PARAM
{
	DWORD				dwSize;					// Structure size. For version control.
	int					nIndex;					// Subscript of array stDisks of information structure DH_HARDDISK_STATE. It begins from 0. 
	int					ctrlType;				// Operation type
												// 0 -  clear data, 1 - set as read-write HDD , 2 -  set as read-only HDD
												// 3 - set as redundant , 4 - restore error , 5 -set as snapshot disk  
	NET_DEV_DISKSTATE	stuDisk;				// diskInfo, replace nIndex
} DISKCTRL_PARAM;

typedef struct  
{
	BYTE				bSubareaNum;			// The number of pre-partition
	BYTE				bIndex;					// Subscript of array stDisks of informaiton structure DH_HARDDISK_STATE. It begins from 0. 
	BYTE				bSubareaSize[32];		// partition Size(Percentage)
	BYTE				bReserved[30];			// Reservations
} DISKCTRL_SUBAREA;

// Alarm status
typedef struct _ALARMCTRL_PARAM
{
	DWORD				dwSize;
	int					nAlarmNo;				// Alarm channel. It begins from 0. 
	int					nAction;				// 1:activate alarm,0:stop alarm  
} ALARMCTRL_PARAM;

// Matrix control 
typedef struct _MATRIXCTRL_PARAM
{
	DWORD				dwSize;
	int					nChannelNo;				// Video input number. It begins from  0.
	int					nMatrixNo;				// Matrix output number. It begins from 0
} MATRIXCTRL_PARAM;

// Burner control 
typedef struct _BURNING_PARM
{
	int					channelMask;			// channel subnet mask. Bit means the channel to be burned.
	//int				devMask;				// Burner subnet mask.  Use bit to represent according to the searched burner list 
	BYTE				devMask;				// Burner subnet mask.  Use bit to represent according to the searched burner list 
	BYTE                bySpicalChannel;        // PIP channel(Channel No.+32)
	BYTE                byReserved[2];          // Reserved
} BURNNG_PARM;

// Annex burn
typedef struct _BURNING_PARM_ATTACH
{
	BOOL				bAttachBurn;			// Whether,0:Not; 1:Yes
	BYTE				bReserved[12];			// Reservations
} BURNING_PARM_ATTACH;

// Manual snap parameter
typedef struct  _MANUAL_SNAP_PARAMETER{
	int                 nChannel;               // snap channel,start with 0
	BYTE                bySequence[64];	        // snap sequence string
	BYTE                byReserved[60];         // reserved
}MANUAL_SNAP_PARAMETER;

// local preview split parameter
typedef struct _DEVICE_LOCALPREVIEW_SLIPT_PARAMETER
{
	int                 nSliptMode;            // split mode
	int                 nSubSliptNum;          // split num, start with 1
	BYTE                byReserved[64];        // reserved
}DEVICE_LOCALPREVIEW_SLIPT_PARAMETER;

// local preview split capability
typedef struct _DEVICE_LOCALPREVIEW_SLIPT_CAP
{
	int                 nModeNumber;
	int                 nSliptMode[36];        // split array
	BYTE                byReserved[64];        // reserved
}DEVICE_LOCALPREVIEW_SLIPT_CAP;

// Crossing information
typedef struct  _CROSSING_INFO
{
	char              szCrossingID[DH_MAX_CROSSING_ID];  // Crossing ID
	DWORD             dwLatitude;				// Latitude(0-180 Degree, 30.183382 degree==120183382)
	DWORD             dwLongitude;				// Longitude(0-360 Degree, 120.178274 degree==300178274)
	WORD              wSpeedLimit;				// limit speed(KM/H)
	BYTE 	          byReserved[22];
}CROSSING_INFO;

// Route crossing information
typedef struct  _ROUTE_CROSSING_INFO
{
	BYTE 			   byCrossingNum;             // valid number is 1~DH_MAX_CROSSING_NUM
	BYTE			   byReserved1; 
	WORD               wCrossingRange;            // Crossing range(m)
	CROSSING_INFO 	   stCrossingInfo[DH_MAX_CROSSING_NUM]; // Crossing information struct array
    BYTE			   byReserved2[2044];
}ROUTE_CROSSING_INFO;

// raid control
typedef struct _CTRL_RAID_INFO
{
	char				szAction[16];						// Add,Delete
	char				szName[16];							// Raid name
	int					nType;								// type 1:Jbod     2:Raid0      3:Raid1     4:Raid5
	int					nStatus;							// status 0:unknown ,1:active,2:degraded,3:inactive,4:recovering
	int					nCntMem;							// nMember count
	int					nMember[32];						// 1,2,3,... 
	int					nCapacity;							// capacity(G)
	int					nRemainSpace;						// remain space(M)
	int					nTank;								// tank 0:main,1:tank1,2:tank2.....
	char				reserved[128];
}CTRL_RAID_INFO;

// spake disk info
typedef struct _CTRL_SPARE_DISK_INFO
{
	char				szAction[16];						// Enable
	char				szScope[16];						// Global,Local
	char				szName[16];							// name
	unsigned int        nIndex;								// disk index
	char				reserved[128];
}CTRL_SPARE_DISK_INFO;

typedef struct _CTRL_SPARE_DISK_INFO_A
{
	int						nCnt;							// count
	CTRL_SPARE_DISK_INFO	stSpaceDiskInfo[32];			// spare disk info array
}CTRL_SPARE_DISK_INFO_A;

// Alarm arm and disarm control
typedef struct __CTRL_ARM_DISARM_PARAM
{
	BYTE                bState;                 // Arm/disarm state, 0 means disarm, 1 means arm, 2 means forced arm
	char                reserve[31];
} CTRL_ARM_DISARM_PARAM;
//////////////////////////////////////////////////////////////

//-------------------------------Device Property ---------------------------------
// Device information 
typedef struct
{
	BYTE				sSerialNumber[DH_SERIALNO_LEN];	// SN
	BYTE				byAlarmInPortNum;		// DVR alarm input amount
	BYTE				byAlarmOutPortNum;		// DVR alarm output amount
	BYTE				byDiskNum;				// DVR HDD amount 
	BYTE				byDVRType;				// DVR type.Please refer to DHDEV_DEVICE_TYPE
	BYTE				byChanNum;				// DVR channel amount 
} NET_DEVICEINFO, *LPNET_DEVICEINFO;

//Device software version information. The higher 16-bit means the main version number and low 16-bit means second version number. 
typedef struct 
{
	DWORD				dwSoftwareVersion;
	DWORD				dwSoftwareBuildDate;
	DWORD				dwDspSoftwareVersion;
	DWORD				dwDspSoftwareBuildDate;
	DWORD				dwPanelVersion;
	DWORD				dwPanelSoftwareBuildDate;
	DWORD				dwHardwareVersion;
	DWORD				dwHardwareDate;
	DWORD				dwWebVersion;
	DWORD				dwWebBuildDate;
} DH_VERSION_INFO, *LPDH_VERSION_INFO;

// Device software version information. Corresponding to CLIENT_QueryDevState
typedef struct  
{
	char				szDevSerialNo[DH_DEV_SERIALNO_LEN];	// Serial number 
	char				byDevType;							// Device type, please refer to DHDEV_DEVICE_TYPE
	char				szDevType[DH_DEV_TYPE_LEN];			// Device detailed type. String format. It may be null.
	int					nProtocalVer;						// Protocol version number 
	char				szSoftWareVersion[DH_MAX_URL_LEN];
	DWORD				dwSoftwareBuildDate;
	char				szDspSoftwareVersion[DH_MAX_URL_LEN];
	DWORD				dwDspSoftwareBuildDate;
	char				szPanelVersion[DH_MAX_URL_LEN];
	DWORD				dwPanelSoftwareBuildDate;
	char				szHardwareVersion[DH_MAX_URL_LEN];
	DWORD				dwHardwareDate;
	char				szWebVersion[DH_MAX_URL_LEN];
	DWORD				dwWebBuildDate;
	char				reserved[256];
} DHDEV_VERSION_INFO;

// DSP capacity description. Correspondign to CLIENT_GetDevConfig
typedef struct 
{
	DWORD				dwVideoStandardMask;	// video format mask. Bit stands for the video format device supported.
	DWORD				dwImageSizeMask;		// Resolution mask bit. Bit stands for the resolution setup devices supported.
	DWORD				dwEncodeModeMask;		// Encode mode mask bit. Bit stands for the encode mode devices supported.
	DWORD				dwStreamCap;			// The multiple-media function the devices supported
												// The first bit:main stream
												// The second bit:extra stream 1
												// The third bit:extra stream 2
												// The fifth bit: snapshot in .jpg format
	DWORD				dwImageSizeMask_Assi[8];// When the main stream is the corresponding resolution, the supported extra stream resolution mask.
	DWORD				dwMaxEncodePower;		// The highest encode capacity DSP supported
	WORD				wMaxSupportChannel;		// The max video channel amount each DSP supported.
	WORD				wChannelMaxSetSync;		// Max encode bit setup in each DSP channel  are synchronized or not ;0:does not synchronized,1:synchronized
} DH_DSP_ENCODECAP, *LPDH_DSP_ENCODECAP;

// DSP capacity description. Extensive type. Corresponding to CLIENT_QueryDevState
typedef struct 
{
	DWORD				dwVideoStandardMask;	// video format mask. Bit stands for the video format device supported.
	DWORD				dwImageSizeMask;		// Resolution mask bit. Bit stands for the resolution setup devices supported.
	DWORD				dwEncodeModeMask;		// Encode mode mask bit. Bit stands for the encode mode devices supported.
	DWORD				dwStreamCap;			// The multiple-media function the devices supported
												// The first bit:main stream
												// The second bit:extra stream 1
												// The third bit:extra stream 2
												// The fifth bit: snapshot in .jpg format
	DWORD				dwImageSizeMask_Assi[32];// When the main stream is the corresponding resolution, the supported extra stream resolution mask.
	DWORD				dwMaxEncodePower;		// The highest encode capacity DSP supported
	WORD				wMaxSupportChannel;		// The max video channel amount each DSP supported.
	WORD				wChannelMaxSetSync;		// Max encode bit setup in each DSP channel  are synchronized or not;0:do not synchronized,1:synchronized
	BYTE				bMaxFrameOfImageSize[32];// The max sampling frame rate in different resolution. Bit corresponding to the dwVideoStandardMask.
	BYTE				bEncodeCap;				// Symbol. The configuration shall meet the following requirements, otherwise the configuration is invalid.
												// 0:main stream encode capacity+extra stream encode capacity<= device encode capacity 
												// 1:main stream encode capacity +extra stream encode capacity<= device encode capacity 
												// Extra stream encode capacity <=main stream encode capacity 
												// Extra stream resolution<=main stream resolution 
												// Main stream resolution and extra stream resolution <=front-end video collection frame rate
												// 2:N5 Device
												// Extra stream encode capacity <=main stream encode capacity
												// Query  the supported resolution and the corresponding maximum frame rate
	char				reserved[95];
} DHDEV_DSP_ENCODECAP, *LPDHDEV_DSP_ENCODECAP;
typedef struct 
{
	DWORD				dwVideoStandardMask;	// video format mask. Bit stands for the video format device supported.
	DWORD				dwImageSizeMask;		// Resolution mask bit. Bit stands for the resolution setup devices supported.
	DWORD				dwEncodeModeMask;		// Encode mode mask bit. Bit stands for the encode mode devices supported.
	DWORD				dwStreamCap;			// The multiple-media function the devices supported.
												// The first bit:main stream
												// The second bit:extra stream 1
												// The third bit:extra stream 2
												// The forth bit:extra stream 3
												// The fifth bit: snapshot in .jpg format
	DWORD				dwImageSizeMask_Assi[3][64];// When the main stream is the corresponding resolution, the supported extra stream resolution mask, the 0,1,2 member in the group correspond extra stream1,2,3
	DWORD				dwMaxEncodePower;		// The highest encode capacity DSP supported
	WORD				wMaxSupportChannel;		// The max video channel amount each DSP supported.
	WORD				wChannelMaxSetSync;		// Max encode bit setup in each DSP channel  are synchronized or not;0:do not synchronized,1:synchronized
	BYTE				bMaxFrameOfImageSize[32];// The max sampling frame rate in different resolution. Bit corresponding to the dwVideoStandardMask.
	BYTE				bEncodeCap;				// Symbol. The configuration shall meet the following requirements, otherwise the configuration is invalid.
												// 0:main stream encode capacity+extra stream encode capacity<= device encode capacity 
												// 1:main stream encode capacity +extra stream encode capacity<= device encode capacity 
												// Extra stream encode capacity <=main stream encode capacity 
												// Extra stream resolution<=main stream resolution 
												// Main stream resolution and extra stream resolution <=front-end video collection frame rate
												// 2:N5 Device
												// Extra stream encode capacity <=main stream encode capacity
												// Query  the supported resolution and the corresponding maximum frame rate
	BYTE				btReserve1[3];			// reserved
	DWORD				dwExtraStream;			// bit0-main stream, bit1-extra stream1, bit2-extra stream2
	DWORD				dwCompression[3];		// extra stream compression

	char				reserved[108];
} DHDEV_DSP_ENCODECAP_EX, *LPDHDEV_DSP_ENCODECAP_EX;

// System information
typedef struct 
{
	DWORD				dwSize;
	/* The following are read only for device. */
	DH_VERSION_INFO		stVersion;
	DH_DSP_ENCODECAP	stDspEncodeCap;			// DSP  capacity description 
	BYTE				szDevSerialNo[DH_DEV_SERIALNO_LEN];	// SN
	BYTE				byDevType;				// device type. Please refer to enumeration DHDEV_DEVICE_TYPE
	BYTE				szDevType[DH_DEV_TYPE_LEN];	// Device detailed type. String format. It may be empty.
	BYTE				byVideoCaptureNum;		// Video port amount
	BYTE				byAudioCaptureNum;		// Audio port amount 
	BYTE				byTalkInChanNum;		// NSP
	BYTE				byTalkOutChanNum;		// NSP
	BYTE				byDecodeChanNum;		// NSP
	BYTE				byAlarmInNum;			// Alarm input port amount
	BYTE				byAlarmOutNum;			// Alarm output amount port
	BYTE				byNetIONum;				// network port amount 
	BYTE				byUsbIONum;				// USB USB port amount
	BYTE				byIdeIONum;				// IDE amount 
	BYTE				byComIONum;				// COM amount 
	BYTE				byLPTIONum;				// LPT amount
	BYTE				byVgaIONum;				// NSP
	BYTE				byIdeControlNum;		// NSP
	BYTE				byIdeControlType;		// NSP
	BYTE				byCapability;			// NSP, expansible description 
	BYTE				byMatrixOutNum;			// video matrix output amount 
	/* The following are read-write part for device */
	BYTE				byOverWrite;			// Operate when HDD is full(overwrite/stop)
	BYTE				byRecordLen;			// Video file Package length
	BYTE				byDSTEnable;			// Enable  DTS or not  1--enable. 0--disable
	WORD				wDevNo;					// Device serial number. Remote control can use this SN to control.
	BYTE				byVideoStandard;		// Video format
	BYTE				byDateFormat;			// Date format
	BYTE				byDateSprtr;			// Date separator(0:".",1:"-",2:"/")
	BYTE				byTimeFmt;				// Time separator  (0-24H,1¡ê-12H)
	BYTE				byLanguage;				// Please refer to DH_LANGUAGE_TYPE for enumeration value
} DHDEV_SYSTEM_ATTR_CFG, *LPDHDEV_SYSTEM_ATTR_CFG;

// The returned information after modify device 
typedef struct
{
	DWORD				dwType;					// Type (type of GetDevConfig and SetDevConfig)
	WORD				wResultCode;			// Returned bit;0:succeeded,1:failed,2:illegal data,3:can not set right now,4:have no right 
	WORD   				wRebootSign;			// Reboot symbol;0:do not need to reboot,1:need to reboot to get activated 
	DWORD				dwReserved[2];			// Reserved 
} DEV_SET_RESULT;

// play result
typedef struct
{
	DWORD              dwResultCode;            // result code,1:no authority,2:device not support,3:insufficient resources,4:get data error, 11:resouces are taked by advance users, 12:forbidden
	LLONG               lPlayHandle;             // play handle
	BYTE               byReserved[32];          // reserved                       
}DEV_PLAY_RESULT;

//DST(Daylight Save Time) setup
typedef struct  
{
	int					nYear;					// Year[200 - 2037]
	int					nMonth;					// Month[1 - 12]
	int					nHour;					// Hour[0 - 23]
	int					nMinute;				// Minute [0 - 59]
	int					nWeekOrDay;				// [-1 - 4]0:It means it adopts the date calculation method. 
												// 1:in week: the first week ,2:the second week,3:the third week,4: The fourth week ,-1: the last week  
	union
	{
		int				iWeekDay;				// week[0 - 6](nWeekOrDay:calculated in week )0: Sunday, 1:Monday , 2:Tuesday ,3: Wednesday,4:Thirsday ,5: Friday,6:Saturday 
		int				iDay;					// date[1 - 31] (nWeekOrDay: in date)
	};
	
	DWORD				dwReserved[8];			// Reserved 
}DH_DST_POINT;

typedef struct  
{
	DWORD				dwSize;
	int					nDSTType;				// DST position way. 0: position in date  , 1:position in week  
	DH_DST_POINT        stDSTStart;             // Enable DTS
	DH_DST_POINT        stDSTEnd;				// End DTS
	DWORD				dwReserved[16];			// Reserved
}DHDEV_DST_CFG;


// Auto maintenance setup
typedef struct
{
	DWORD				dwSize;
	BYTE				byAutoRebootDay;		// Auto reboot;0:never, 1:each day,2:each Sunday,3:Each Monday ,......
	BYTE				byAutoRebootTime;		// 0:0:00,1:1:00,......23:23:00
	BYTE				byAutoDeleteFilesTime;	// Auto delete file;0:never,1:24H,2:48H,3:72H,4:96H,5:ONE WEEK,6:ONE MONTH
	BYTE				reserved[13];			// Reserved bit
} DHDEV_AUTOMT_CFG;

//-----------------------------Video Channel Property -------------------------------

// Time period structure 															    
typedef struct 
{
	BOOL				bEnable;				// Current record period . Bit means the four Enable functions. From the low bit to the high bit:Motion detection record, alarm record and general record, when Motion detection and alarm happened at the same time can record.
	int					iBeginHour;
	int					iBeginMin;
	int					iBeginSec;
	int					iEndHour;
	int					iEndMin;
	int					iEndSec;
} DH_TSECT, *LPDH_TSECT;

// Zone;Each margin is total lenght :8192
typedef struct 
{
   long					left;
   long					top;
   long					right;
   long					bottom;
} DH_RECT, *LPDH_RECT;

// 2 dimension point
typedef struct 
{
	short					nx;
	short					ny;
} DH_POINT, *LPDH_POINT;

// 
typedef struct
{
	int        nPointNum;                           // point number
	DH_POINT   stuPoints[DH_MAX_DETECT_REGION_NUM]; // point info
}DH_POLY_POINTS;
typedef struct  tagENCODE_WIDGET
{
	DWORD				rgbaFrontground;		// Object front view. Use bit to represent:red, green, blue and transparency.
	DWORD				rgbaBackground;			// Object back ground. Use bit to represent:red, green, blue and transparency.
	DH_RECT				rcRect;					// Position
	BYTE				bShow;					// Enable display
	BYTE                bExtFuncMask;           // Extended function,mask 
                                                // bit0 indicate week showing,0-not show 1-show 
	BYTE				byReserved[2];
} DH_ENCODE_WIDGET, *LPDH_ENCODE_WIDGET;

// Channel audio property 
typedef struct 
{
	// Video property 
	BYTE				byVideoEnable;			// Enable video;1:open,0:close 
	BYTE				byBitRateControl;		// Bit stream control;Please refer to constant Bit Stream Control definition 
	BYTE				byFramesPerSec;			// Frame rate
	BYTE				byEncodeMode;			// Encode mode:please refer to constant Encode Mode definition
	BYTE				byImageSize;			// Resolution:please refer to constant Resolution definition.
	BYTE				byImageQlty:7;			// Level 1-6
	BYTE                byImageQltyType:1;       
	WORD				wLimitStream;			// Limit stream parameter
	// Audio property 
	BYTE				byAudioEnable;			// Enable audio;1:open,0:close
	BYTE				wFormatTag;				// Audio encode mode:0:G711A,1:PCM,2:G711U,3:AMR,4:AAC 
	WORD				nChannels;				// Track amount 
	WORD				wBitsPerSample;			// Sampling depth 	
	BYTE				bAudioOverlay;			// Enabling audio
	BYTE				bH264ProfileRank;       // H.264 Profile rank(when byEncodeMode is h264, this value works ), see enmu struct EM_H264_PROFILE_RANK,when this value is 0, it means nothing
	DWORD				nSamplesPerSec;			// Sampling rate 
	BYTE				bIFrameInterval;		// 0-149. I frame interval amount. Describe the P frame amount between two I frames.
	BYTE				bScanMode;				// NSP
	BYTE				bReserved_3;
	BYTE				bReserved_4;
} DH_VIDEOENC_OPT, *LPDH_VIDEOENC_OPT;

// Image color property  
typedef struct 
{
	DH_TSECT			stSect;
	BYTE				byBrightness;			// Brightness:0-100
	BYTE				byContrast;				// Contrast:0-100
	BYTE				bySaturation;			// Saturation:0-100
	BYTE				byHue;					// Hue:0-100
	BYTE				byGainEn;				// Enable gain
	BYTE				byGain;					// Gain:0-100
	BYTE				byReserved[2];
} DH_COLOR_CFG, *LPDH_COLOR_CFG;

// Image channel property structure 
typedef struct 
{
	//DWORD				dwSize;
	WORD				dwSize;
	BYTE				bNoise;
	BYTE				bMode;   // (vehicle's special need)model 1 (quality first): 4-way video resolution D1, frame rate 2fps, bit rate 128kbps(225MB per hour) 
	                             // Mode 2 (fluency preferred): 4-way video resolution CIF, frame rate of 12fps, bit rate 256kbps (550MB per hour) 
                                 // Mode 3 (Custom) video resolution can be defined by the user, limited the maximum capacity of 4CIF/25fps
	char				szChannelName[DH_CHAN_NAME_LEN];
	DH_VIDEOENC_OPT		stMainVideoEncOpt[DH_REC_TYPE_NUM];
	DH_VIDEOENC_OPT		stAssiVideoEncOpt[DH_N_ENCODE_AUX];		
	DH_COLOR_CFG		stColorCfg[DH_N_COL_TSECT];
	DH_ENCODE_WIDGET	stTimeOSD;
	DH_ENCODE_WIDGET	stChannelOSD;
	DH_ENCODE_WIDGET	stBlindCover[DH_N_COVERS];	// Single privacy mask zone
	BYTE				byBlindEnable;				// Privacy mask zone enable button;0x00:disable privacy mask ,0x01:privacy mask local preview ,0x10:privacy mask record and network preview,0x11: Privacy mask all
	BYTE				byBlindMask;				// Privacy mask zone subnet mask. The first bit; device local preview ;The second bit :record (and network preview ) */
	BYTE				bVolume;					// volume(0~100)
	BYTE				bVolumeEnable;				// volume enable
} DHDEV_CHANNEL_CFG, *LPDHDEV_CHANNEL_CFG;

// Preview image property 
typedef struct 
{
	DWORD				dwSize;
	DH_VIDEOENC_OPT		stPreView;
	DH_COLOR_CFG		stColorCfg[DH_N_COL_TSECT];
}DHDEV_PREVIEW_CFG;

// snap control configuration
typedef struct _config_snap_control
{
	BYTE               bySnapState[32];           // every channel's snap on-off: 0 Autumn(other configuration and event will control whether snap picture ); 1: turn on snap; 2: turn off snap
    BYTE               byReserved[480];
}DHDEV_SNAP_CONTROL_CFG;

enum _gps_mode
{
	GPS_OR_GLONASS_MODE,	// GPS,GLONASS
	GLONASS_MODE,			// GLONASS
	GPS_MODE,				// GPS
};
// DH_DEV_GPS_MODE_CFG configuration
typedef struct tagDHDEV_GPS_MODE_CFG
{
	BYTE				byGPSMode; // GPS mode
	BYTE				byRev[255];
}DHDEV_GPS_MODE_CFG;

// snap upload DH_DEV_SNAP_UPLOAD_CFG configuration
typedef struct tagDHDEV_SNAP_UPLOAD_CFG
{
	int					nUploadInterval;		// the interval time of upload picture(s)
	BYTE				byReserved[252];	
}DHDEV_SNAP_UPLOAD_CFG;

// DH_DEV_SPEED_LIMIT_CFG configuration
typedef struct tagDHDEV_SPEED_LIMIT_CFG
{
	BYTE       byEnable;						// Enable speed limit;1:enable,0:disable
	BYTE       byReserved1;      
	WORD       wMaxSpeed;						// upper speed(KM/H) 0: none limit speed, >0:limit speed
	WORD       wMinSpeed;						// low speed(KM/H) 0: none limit speed, >0:limit speed
	BYTE       byReserved2[122];  
}DHDEV_SPEED_LIMIT_CFG;

// wireless routing config
typedef struct
{
	BOOL		bEnable;						// enable
	char		szSSID[36];						// SSID
	BOOL		bHideSSID;						// hide SSID
	char		szIP[DH_MAX_IPADDR_LEN];		// IP
	char		szSubMark[DH_MAX_IPADDR_LEN];	// sub mark
	char		szGateWay[DH_MAX_IPADDR_LEN];	// gateway
	char		szCountry[32];					// country
	int			nSafeType;						// safe type: 1-no encryption; 2-WEP; 2-WPA-PSK; 3-WPA2-PSK
	int			nEncryption;					// encryption: WEP(1-auto 2-open 3-shareable); WPA-PSK/WPA2-PSK(4-TKIP 5-AES)
	char		szKey[32];						// key
	int			nChannel;						// channel
	BOOL		bAutoChannelSelect;				// auto channel select
}DHDEV_WIRELESS_ROUTING_CFG;

//-------------------------------COM property ---------------------------------

// COM basic property 
typedef struct
{
	BYTE				byDataBit;				// Data bit;0:5,1:6,2:7,3:8
	BYTE				byStopBit;				// Stop bit;0:1 bit,1:1.5 bit,2:2 bits
	BYTE				byParity;				// Parity;0: None,1: Odd;2: even;3:sign;4:empty
	BYTE				byBaudRate;				// Baud rate;0:300,1:600,2:1200,3:2400,4:4800,
												// 5:9600,6:19200,7:38400,8:57600,9:115200
} DH_COMM_PROP;

// 485 decoder setup 
typedef struct
{ 
	DH_COMM_PROP		struComm;
	BYTE				wProtocol;				// Protocol type. Corresponding to the subscript of Protocol Name List
	BYTE				bPTZType;				// 0-Compatible,local ptz 1-remote network ptz, the capability refer to DEV_ENCODER_CFG.
	BYTE				wDecoderAddress;		// Decoder address;0 - 255
	BYTE 				byMartixID;				// Matrix number 
} DH_485_CFG;

// 232 COM setup 
typedef struct
{
	DH_COMM_PROP		struComm;
	BYTE				byFunction;				// COM function,Corresponding to the subscript of Function Name list. 
	BYTE				byReserved[3];
} DH_RS232_CFG;

// COM configuration structure 
typedef struct
{
	DWORD				dwSize;

	DWORD				dwDecProListNum;										// Decoder protocol amount
	char				DecProName[DH_MAX_DECPRO_LIST_SIZE][DH_MAX_NAME_LEN];	// Protocol name list
	DH_485_CFG			stDecoder[DH_MAX_DECODER_NUM];							// Each decoder current property

	DWORD				dw232FuncNameNum;										// 232 function amount 
	char				s232FuncName[DH_MAX_232FUNCS][DH_MAX_NAME_LEN];			// Function name list 
	DH_RS232_CFG		st232[DH_MAX_232_NUM];									// Current 232 COM property 
} DHDEV_COMM_CFG;

// Extended COM configuration structure 
typedef struct
{
	DWORD				dwSize;
	
	DWORD				dwDecProListNum;			                           // Decoder protocol amount
	char				DecProName[DH_MAX_DECPRO_LIST_SIZE][DH_MAX_NAME_LEN];  // Protocol name list
	DH_485_CFG			stDecoder[DH_MAX_DECODER_NUM];						   // Each decoder current property
	
	DWORD				dw232FuncNameNum;									   // 232 function amount
	char				s232FuncName[DH_MAX_232FUNCS][DH_MAX_NAME_LEN];	       // Function name list
	DWORD               dw232ComNum;										   // 232 com amount  
	DH_RS232_CFG		st232[DH_MAX_232_NUM_EX];	                           // Current 232 COM property
} DHDEV_COMM_CFG_EX;

// Serial port status
typedef struct
{
	unsigned int		uBeOpened;
	unsigned int		uBaudRate;
	unsigned int		uDataBites;
	unsigned int		uStopBits;
	unsigned int		uParity;
	BYTE				bReserved[32];
} DH_COMM_STATE;

//-------------------------------Record configuration---------------------------------

// Scheduled record 
typedef struct 
{
	DWORD				dwSize;
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT];
	BYTE				byPreRecordLen;			// Pre-record button. Unit is second. 0 means disble pre-record 
	BYTE				byRedundancyEn;			// Record redundant enable button 
	BYTE                byRecordType;           // Video bit-stream type:0:Main Stream 1:Assist Stream1 2:Assist Stream2 3:Assist Stream3
	BYTE				byReserved;
} DHDEV_RECORD_CFG, *LPDH_RECORD_CFG;

// NTP setup 
typedef struct  
{
	BOOL				bEnable;				// Enable or not
	int					nHostPort;				// NTP  server default port is 123
	char				szHostIp[32];			// Host IP
	char				szDomainName[128];		// Domain name 
	int					nType;					// Read only ,0:IP,1:domain name ,2:IP and domain name 
	int					nUpdateInterval;		// Update time(minute)
	int					nTimeZone;				// Please refer to DH_TIME_ZONE_TYPE
	char				reserved[128];
} DHDEV_NTP_CFG;

// FTP upload setup 
typedef struct
{
	struct
	{
		DH_TSECT		struSect;				// Enable function is disabled during the period. Can ignore
		BOOL			bMdEn;					// Upload motion detection record
		BOOL			bAlarmEn;				// Upload external alarm record 
		BOOL			bTimerEn;				// Upload scheduled record 
		DWORD			dwRev[4];
	} struPeriod[DH_TIME_SECTION];
} DH_FTP_UPLOAD_CFG;

typedef struct
{
	DWORD				dwSize;
	BOOL				bEnable;							// Enable or not
	char				szHostIp[DH_MAX_IPADDR_LEN];		// Host IP
	WORD				wHostPort;							// Host port 
	char				szDirName[DH_FTP_MAX_PATH];			// FTP path
	char				szUserName[DH_FTP_USERNAME_LEN];	// User name
	char				szPassword[DH_FTP_PASSWORD_LEN];	// Password 
	int					iFileLen;							// File length
	int					iInterval;							// Time interval between two near files.
	DH_FTP_UPLOAD_CFG	struUploadCfg[DH_MAX_CHANNUM][DH_N_WEEKS];
	char 				protocol;							// 0-FTP 1-SMB 2-NFS,3-ISCSI
	char				NASVer;								// Network storage server version 0=Old FTP(There is time period in the user interface),1=NAS storage(There is no time period in the user interface. )
	DWORD				dwFunctionMask;						// Function capacity mask. Use bit to represent. Lower 16-bit:FTP,SMB,NFS, ISCSI and higher 16-bit:(Local storage)DISK,U
	BYTE                bDataType;                          // data type, 0-all, 1-video, 2-image
	BYTE 				reserved[123];
} DHDEV_FTP_PROTO_CFG;

// extend FTP upload setup (support setting the FTP's path, maximal picture number)
typedef struct 
{
    int            nMaxPictures;                             // the maximal number of the FTP can save,can set limit of the picture number in the every chennel's direct;
	                                                         // if the saved picture number extended the limit the old picture will be covered by new one; the value 0 indecate that it will save picture untill the disck was full.
    char           szPreChannelName[DH_FTP_MAX_SUB_PATH];    // the picture named mod
    char           szFTPChannelPath[DH_FTP_MAX_SUB_PATH];    // the FTP's sub direction
    char           szRev[128];                               // reserved
}DHDEV_FTP_CHANNEL_CFG; 


typedef struct 
{ 
	DHDEV_FTP_PROTO_CFG      stuFtpNormalSet;                // the normal function of the FTP
	DHDEV_FTP_CHANNEL_CFG     stuFtpChannelSet[DH_MAX_CHANNUM]; // the extended function of the FTP
	char                      szRev[128];                    // reserved
}DHDEV_FTP_PROTO_CFG_EX;

//-------------------------------Network Configuration---------------------------------

// Ethernet Configuration
typedef struct 
{
	char				sDevIPAddr[DH_MAX_IPADDR_LEN];	// DVR IP  address
	char				sDevIPMask[DH_MAX_IPADDR_LEN];	// DVR IP subnet mask    
	char				sGatewayIP[DH_MAX_IPADDR_LEN];	// Gateway address

	/*
	 * 1:10Mbps full-duplex
	 * 2:10Mbps auto-duplex
	 * 3:10Mbps half-duplex
	 * 4:100Mbps full-duplex
	 * 5:100Mbps auto-duplex
	 * 6:100Mbps half-duplex
	 * 7:auto
	 */
	// Divide DWORD into four to future development
	BYTE				dwNetInterface;			// NSP
	BYTE				bTranMedia;				// 0:cable,1:wireless
	BYTE				bValid;					// Use bit to represent, The first bit:1:valid 0:invalid;The second bit:0:Disable DHCP 1:Enable DHCP;The third bit:0:Do not support DHCP 1:Support DHCP
	BYTE				bDefaultEth;			// To be the default network card or not.  1: default 0:non-default 
	char				byMACAddr[DH_MACADDR_LEN];	// MAC address , read-only., 
} DH_ETHERNET; 

// Remote host setup 
typedef struct 
{
	BYTE				byEnable;				// Enable connection 
	BYTE				byAssistant;            // Only for PPPoE server,0:on the cabled network; 1:on the wireless network
	WORD				wHostPort;				// Remote host Port 
	char				sHostIPAddr[DH_MAX_IPADDR_LEN];		// Remote host IP address  				
	char				sHostUser[DH_MAX_HOST_NAMELEN];		// Remote host User name   
	char				sHostPassword[DH_MAX_HOST_PSWLEN];	// Remote host Password   
} DH_REMOTE_HOST;

// Mail setup 
typedef struct 
{
	char				sMailIPAddr[DH_MAX_IPADDR_LEN];		// Email server IP
	WORD				wMailPort;							// Email server port 
	WORD				wReserved;							// Reserved
	char				sSenderAddr[DH_MAX_MAIL_ADDR_LEN];	// Send out address 
	char				sUserName[DH_MAX_NAME_LEN];			// User name 
	char				sUserPsw[DH_MAX_NAME_LEN];			// User password 
	char				sDestAddr[DH_MAX_MAIL_ADDR_LEN];	// Destination address 
	char				sCcAddr[DH_MAX_MAIL_ADDR_LEN];		// CC address 
	char				sBccAddr[DH_MAX_MAIL_ADDR_LEN];		// BCC address 
	char				sSubject[DH_MAX_MAIL_SUBJECT_LEN];	// Subject 
} DH_MAIL_CFG;

// Network configuration structure 
typedef struct
{ 
	DWORD				dwSize; 

	char				sDevName[DH_MAX_NAME_LEN];	// Device host name

	WORD				wTcpMaxConnectNum;		// TCP max connection amount
	WORD				wTcpPort;				// TCP listening port 
	WORD				wUdpPort;				// UDP listening port 
	WORD				wHttpPort;				// HTTP port number 
	WORD				wHttpsPort;				// HTTPS port number 
	WORD				wSslPort;				// SSL port number 
	DH_ETHERNET			stEtherNet[DH_MAX_ETHERNET_NUM];	// Ethernet port 

	DH_REMOTE_HOST		struAlarmHost;			// Alarm server 
	DH_REMOTE_HOST		struLogHost;			// Log server 
	DH_REMOTE_HOST		struSmtpHost;			// SMTP server 
	DH_REMOTE_HOST		struMultiCast;			// Multiple-cast group 
	DH_REMOTE_HOST		struNfs;				// NFS server
	DH_REMOTE_HOST		struPppoe;				// PPPoE server 
	char				sPppoeIP[DH_MAX_IPADDR_LEN]; // returned IP after PPPoE registration 
	DH_REMOTE_HOST		struDdns;				// DDNS server
	char				sDdnsHostName[DH_MAX_HOST_NAMELEN];	// DDNS host name
	DH_REMOTE_HOST		struDns;				// DNS server 
	DH_MAIL_CFG			struMail;				// Email setup 
} DHDEV_NET_CFG;

// Ethernet extended Configuration
typedef struct 
{
	char				sDevIPAddr[DH_MAX_IPADDR_LEN];	// DVR IP  address
	char				sDevIPMask[DH_MAX_IPADDR_LEN];	// DVR IP subnet mask
	char				sGatewayIP[DH_MAX_IPADDR_LEN];	// Gateway address

	/*
	 * 1:10Mbps full-duplex
	 * 2:10Mbps auto-duplex
	 * 3:10Mbps half-duplex
	 * 4:100Mbps full-duplex
	 * 5:100Mbps auto-duplex
	 * 6:100Mbps half-duplex
	 * 7:auto
	 */
	// Divide DWORD into four to future development
	BYTE				dwNetInterface;			// NSP
	BYTE				bTranMedia;				// 0:cable,1:wireless
	BYTE				bValid;					// Use bit to represent, The first bit:1:valid 0:invalid;The second bit:0:Disable DHCP 1:Enable DHCP;The third bit:0:Do not support DHCP 1:Support DHCP
	BYTE				bDefaultEth;			//To be the default network card or not.  1: default 0:non-default 
	char				byMACAddr[DH_MACADDR_LEN];	// MAC address , read-only.
	BYTE                bMode;                  // mode, 1:balance, 2:multi, 3:fault-toerant
	BYTE                bReserved[31];         // reserved   
} DH_ETHERNET_EX; 

// Network extended configuration structure
typedef struct
{ 
	DWORD				dwSize; 
	
	char				sDevName[DH_MAX_NAME_LEN];	// Device host name
	
	WORD				wTcpMaxConnectNum;		// TCP max connection amount
	WORD				wTcpPort;				// TCP listening port
	WORD				wUdpPort;				// UDP listening port 
	WORD				wHttpPort;				// HTTP port number
	WORD				wHttpsPort;				// HTTPS port number
	WORD				wSslPort;				// SSL port number
	int                 nEtherNetNum;           // Ethernet port number
	DH_ETHERNET_EX		stEtherNet[DH_MAX_ETHERNET_NUM_EX];	// Ethernet info
	
	DH_REMOTE_HOST		struAlarmHost;			// Alarm server
	DH_REMOTE_HOST		struLogHost;			// Log server
	DH_REMOTE_HOST		struSmtpHost;			// SMTP server
	DH_REMOTE_HOST		struMultiCast;			// Multiple-cast group
	DH_REMOTE_HOST		struNfs;				// NFS server
	DH_REMOTE_HOST		struPppoe;				// PPPoE server
	char				sPppoeIP[DH_MAX_IPADDR_LEN]; // returned IP after PPPoE registration
	DH_REMOTE_HOST		struDdns;				// DDNS server
	char				sDdnsHostName[DH_MAX_HOST_NAMELEN];	// DDNS host name
	DH_REMOTE_HOST		struDns;				// DNS server
	DH_MAIL_CFG			struMail;				// Email setup
	BYTE                bReserved[128];         // reserved
} DHDEV_NET_CFG_EX;

// ddns configuraiton structure 
typedef struct
{
	DWORD				dwId;					// ddns server id
	BOOL				bEnable;				// Enable. There is only one valid ddns server at one time.
	char				szServerType[DH_MAX_SERVER_TYPE_LEN];	// Server type. www.3322.org.
	char				szServerIp[DH_MAX_DOMAIN_NAME_LEN];		// Server IP or domain name 
	DWORD				dwServerPort;			// Server port 
	char				szDomainName[DH_MAX_DOMAIN_NAME_LEN];	// DVR domain name such as jeckean.3322.org
	char				szUserName[DH_MAX_HOST_NAMELEN];		// User name
	char				szUserPsw[DH_MAX_HOST_PSWLEN];			// Password
	char				szAlias[DH_MAX_DDNS_ALIAS_LEN];			// Server alias such as "dahua inter ddns"
	DWORD				dwAlivePeriod;							// DDNS alive period
	BYTE				ByMode;									// domain mode:0-manual,szDomainName enable; 1-default szDefaultDomainName enable
	char				szDefaultDomainName[DH_MAX_DEFAULT_DOMAIN_LEN];// default domain, real only
	char				reserved[195];
} DH_DDNS_SERVER_CFG;

typedef struct
{
	DWORD				dwSize;
	DWORD				dwDdnsServerNum;	
	DH_DDNS_SERVER_CFG	struDdnsServer[DH_MAX_DDNS_NUM];	
} DHDEV_MULTI_DDNS_CFG;

// Mail configuration structure 
typedef struct 
{
	char				sMailIPAddr[DH_MAX_DOMAIN_NAME_LEN];	// Mail server address(IP and domain name )
	char				sSubMailIPAddr[DH_MAX_DOMAIN_NAME_LEN];
	WORD				wMailPort;								// Mail server port 
	WORD				wSubMailPort;
	WORD				wReserved;								// Reserved 
	char				sSenderAddr[DH_MAX_MAIL_ADDR_LEN];		// From
	char				sUserName[DH_MAX_MAIL_NAME_LEN];		// User name
	char				sUserPsw[DH_MAX_MAIL_NAME_LEN];			// password
	char				sDestAddr[DH_MAX_MAIL_ADDR_LEN];		// To
	char				sCcAddr[DH_MAX_MAIL_ADDR_LEN];			// CC
	char				sBccAddr[DH_MAX_MAIL_ADDR_LEN];			// BCC
	char				sSubject[DH_MAX_MAIL_SUBJECT_LEN];		// Subject
	BYTE				bEnable;								// Enable 0:false,	1:true
	BYTE				bSSLEnable;								// SSL enable
	WORD				wSendInterval;							// Send interval,[0,3600]s
	BYTE				bAnonymous;								// Anonymous Options[0,1], 0:FALSE,1:TRUE.
	BYTE				bAttachEnable;							// Attach enable[0,1], 0:FALSE,1:TRUE.
	char				reserved[154];
} DHDEV_MAIL_CFG;

// DNS server setup 
typedef struct  
{
	char				szPrimaryIp[DH_MAX_IPADDR_LEN];
	char				szSecondaryIp[DH_MAX_IPADDR_LEN];
	char				reserved[256];
} DHDEV_DNS_CFG;

// Record download strategy setup 
typedef struct
{
	DWORD				dwSize;
	BOOL				bEnable;				// TRUE: high-speed download,FALSE:general download  
}DHDEV_DOWNLOAD_STRATEGY_CFG;

// Network transmission strategy setup 
typedef struct
{
	DWORD				dwSize;
	BOOL				bEnable;
	int					iStrategy;				// 0: video quality,1:fluency ,2: auto
}DHDEV_TRANSFER_STRATEGY_CFG;

// The corresponding parameter when setting log in
typedef struct  
{
	int					nWaittime;				// Waiting time(unit is ms), 0:default 5000ms.
	int					nConnectTime;			// Connection timeout value(Unit is ms), 0:default 1500ms.
	int					nConnectTryNum;			// Connection trial times(Unit is ms), 0:default 1.
	int					nSubConnectSpaceTime;	// Sub-connection waiting time(Unit is ms), 0:default 10ms.
	int					nGetDevInfoTime;		// Access to device information timeout, 0:default 1000ms.
	int					nConnectBufSize;		// Each connected to receive data buffer size(Bytes), 0:default 250*1024
	int					nGetConnInfoTime;		// Access to sub-connect information timeout(Unit is ms), 0:default 1000ms.
	int                 nSearchRecordTime;      // Timeout value of search video (unit ms), default 3000ms
	int                 nsubDisconnetTime;      // dislink disconnect time,0:default 60000ms
	BYTE				byNetType;				// net type, 0-LAN, 1-WAN
	BYTE                byReserved1[3];         // reserved
	int                 nPicBufSize;            // Receive picture data buffer size(Bytes), 0:default 2*1024*1024

	BYTE				bReserved[4];			// reserved
} NET_PARAM;

// Corresponding to CLIENT_SearchDevices
typedef struct 
{
	char				szIP[DH_MAX_IPADDR_LEN];		// IP
	int					nPort;							// Port
	char				szSubmask[DH_MAX_IPADDR_LEN];	// Subnet mask
	char				szGateway[DH_MAX_IPADDR_LEN];	// Gateway
	char				szMac[DH_MACADDR_LEN];			// MAC address
	char				szDeviceType[DH_DEV_TYPE_LEN];	// Device type
	BYTE                byManuFactory;				    // manufactory
	BYTE                byIPVersion;                    // 4: IPv4, szXXX?a¦Ì?¡¤?¡Á?¡¤?¡ä?D?¨º?;  6:IPv6, szXXX?a128??(16¡Á??¨²)¨ºy?¦ÌD?¨º?
	BYTE				bReserved[30];					// reserved
} DEVICE_NET_INFO;

// Corresponding to CLIENT_StartSearchDevices
typedef struct 
{
	int                 iIPVersion;                      // 4 for IPV4, 6 for IPV6
	char				szIP[64];		                 // IP IPV4 like"192.168.0.1" IPV6 like "2008::1/64"
	int				    nPort;		                     // port
	char				szSubmask[64];	                 // Subnet mask(IPV6 do not have subnet mask)
	char				szGateway[64];	                 // Gateway
	char				szMac[DH_MACADDR_LEN];           // MAC address
	char				szDeviceType[DH_DEV_TYPE_LEN];	 // Device type
	BYTE                byManuFactory;				     // device manufactory, see EM_IPC_TYPE
	BYTE                byDefinition;                    // 1-Standard definition 2-High definition
	bool                bDhcpEn;                         // Dhcp, true-open, false-close
	BYTE                byReserved1;                     // reserved
	char                verifyData[88];                  // ECC data 
	char                szSerialNo[DH_DEV_SERIALNO_LEN]; // serial no
	char                szDevSoftVersion[DH_MAX_URL_LEN];// soft version    
    char                szDetailType[DH_DEV_TYPE_LEN];   // device detail type
	char                szVendor[DH_MAX_STRING_LEN];     // OEM type
	char                szDevName[DH_MACHINE_NAME_NUM];  // device name
	
	char                szUserName[DH_USER_NAME_LENGTH_EX];  // user name for log in device(it need be filled when modify device ip)
	char                szPassWord[DH_USER_NAME_LENGTH_EX];  // pass word for log in device(it need be filled when modify device ip)
	unsigned short		nHttpPort;							 // HTTP·þÎñ¶Ë¿ÚºÅ
	char                cReserved[254];
}DEVICE_NET_INFO_EX;

// Corresponding to CLIENT_SearchDevicesByIPs
typedef struct
{
	DWORD               dwSize;                          // struct size 
	int                 nIpNum;                          // the IPs number for search
	char                szIP[DH_MAX_SAERCH_IP_NUM][64];  // the IPs for search
}DEVICE_IP_SEARCH_INFO;

// struct SNMP config struct
typedef struct
{
	BOOL                bEnable;                                // SNMP enable
	int                 iSNMPPort;                              // SNMP port
	char                szReadCommon[DH_MAX_SNMP_COMMON_LEN];   // read common
	char                szWriteCommon[DH_MAX_SNMP_COMMON_LEN];  // write common
	char                szTrapServer[64];                       // trap address
	int                 iTrapPort;                              // trap port
	BYTE				bSNMPV1;								// SNMP V1 enable
	BYTE				bSNMPV2;								// SNMP V2 enable
	BYTE				bSNMPV3;								// SNMP V3 enable
	char                szReserve[125];
}DHDEV_NET_SNMP_CFG;
// ISCSI server
typedef struct
{
	char				szServerName[32];				// name
	union
	{ 
		BYTE	c[4];
		WORD	s[2];
		DWORD	l;
	}					stuIP;							// IP
	int					nPort;							// port
	char				szUserName[32];					// username
	char				szPassword[32];					// password
	BOOL				bAnonymous;						// anonymous
}DHDEV_ISCSI_SERVER;

// ISCSI config
typedef struct
{
	BOOL				bEnable;						// enable
	DHDEV_ISCSI_SERVER	stuServer;						// server
	char				szRemotePath[240];				// remote path
	BYTE				reserved[256];
}DHDEV_ISCSI_CFG;
//-------------------------------Alarm Property ---------------------------------

// PTZ Activation
typedef struct 
{
	int					iType;
	int					iValue;
} DH_PTZ_LINK, *LPDH_PTZ_LINK;

//Alarm activation structure 
typedef struct 
{
	/* Message process way. There can be several process ways.
	 * 0x00000001 -  Alarm upload
	 * 0x00000002 -  Activation alarm 
	 * 0x00000004 -  PTZ activation
	 * 0x00000008 -  Send out mail
	 * 0x00000010 -  Local tour
	 * 0x00000020 -  Local prompt
	 * 0x00000040 -  Alarm output
	 * 0x00000080 - Ftp upload
	 * 0x00000100 -  Buzzer 
	 * 0x00000200 -  Video prompt
	 * 0x00000400 -  Snapshot
	*/

	/* The process way current alarm supported. Use bit mask to represent */
	DWORD				dwActionMask;

	/* Use bit mask to represent. The parameters of detailed operation are in its correspond configuration */
	DWORD				dwActionFlag;
	
	/* The output channel the alarm activated. The output alarm activated. 1 means activate current output. */ 
	BYTE				byRelAlarmOut[DH_MAX_ALARMOUT_NUM];
	DWORD				dwDuration;				/*  Alarm duration time*/

	/* Activation record */
	BYTE				byRecordChannel[DH_MAX_VIDEO_IN_NUM]; /*  The record channel alarm activated. 1 means activate current channel. */
	DWORD				dwRecLatch;				/*  Record duration time */

	/* Snapshot channel  */
	BYTE				bySnap[DH_MAX_VIDEO_IN_NUM];
	/* Tour channel */
	BYTE				byTour[DH_MAX_VIDEO_IN_NUM];

	/* PTZ activation  */
	DH_PTZ_LINK			struPtzLink[DH_MAX_VIDEO_IN_NUM];
	DWORD				dwEventLatch;			/* The latch time after activation begins. Unit is second. The value ranges from 0 to 15. Default value is 0. */
	/* The wireless output channel alarm activated.The output alarm activated. 1 means activate current output.*/ 
	BYTE				byRelWIAlarmOut[DH_MAX_ALARMOUT_NUM];
	BYTE				bMessageToNet;
	BYTE                bMMSEn;					/* SMS Alarm enabled */
	BYTE                bySnapshotTimes;		/* the number of sheets of drawings */
	BYTE				bMatrixEn;				/*enable matrix */
	DWORD				dwMatrix;				/*matrix mask */			
	BYTE				bLog;					/*enable log */
	BYTE				bSnapshotPeriod;		/*<Snapshot frame interval. System can snapshot regularly at the interval you specify here. The snapshot amount in a period of time also has relationship with the snapshot frame rate. 0 means there is no interval, system just snapshot continuously.*/
	BYTE                byEmailType;            /*<0,picture,1,record>*/
	BYTE                byEmailMaxLength;       /*<max record length,unit:MB>*/
	BYTE                byEmailMaxTime;         /*<max time length, unit:second>*/
	BYTE				byReserved[99];     
} DH_MSG_HANDLE;

// External alarm 
typedef struct
{
	BYTE				byAlarmType;			// Annunciator type,0: normal close,1:normal open 
	BYTE				byAlarmEn;				// Enable alarm 
	BYTE				byReserved[2];						
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT]; // NSP
	DH_MSG_HANDLE		struHandle;				// Process way 
} DH_ALARMIN_CFG, *LPDHDEV_ALARMIN_CFG; 

//Motion detection alarm 
typedef struct 
{
	BYTE				byMotionEn;				// Enable motion detection alarm 
	BYTE				byReserved;
	WORD				wSenseLevel;			// Sensitivity 
	WORD				wMotionRow;				// Row amount in motion detection zones
	WORD				wMotionCol;				// Column amount in motion detection zones 
	BYTE				byDetected[DH_MOTION_ROW][DH_MOTION_COL]; // Detection zones .Max 32*32 zones.
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT];	// NSP
	DH_MSG_HANDLE		struHandle;				// Process way 
} DH_MOTION_DETECT_CFG;

// Video loss alarm 
typedef struct
{
	BYTE				byAlarmEn;				// Enable video loss alarm 
	BYTE				byReserved[3];
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT];	// NSP
	DH_MSG_HANDLE		struHandle;				// Process way
} DH_VIDEO_LOST_CFG;

// Camera masking alarm 
typedef struct
{
	BYTE				byBlindEnable;						// Enable
	BYTE				byBlindLevel;						// Sensitivity 1-6
	BYTE				byReserved[2];
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT];	// NSP
	DH_MSG_HANDLE		struHandle;							// Process way 
} DH_BLIND_CFG;

// HDD information(External alarm )
typedef struct 
{
	BYTE				byNoDiskEn;								// Alarm when there is no HDD
	BYTE				byReserved_1[3];
	DH_TSECT			stNDSect[DH_N_WEEKS][DH_N_REC_TSECT];	// NSP
	DH_MSG_HANDLE		struNDHandle;							// Process way 

	BYTE				byLowCapEn;								// Alarm when HDD capacity is low 
	BYTE				byLowerLimit;							// Capacity threshold 0-99
	BYTE				byReserved_2[2];
	DH_TSECT			stLCSect[DH_N_WEEKS][DH_N_REC_TSECT];	// NSP
	DH_MSG_HANDLE		struLCHandle;							// Process way 

	BYTE				byDiskErrEn;							// HDD malfunction alarm 
	BYTE				bDiskNum;
	BYTE				byReserved_3[2];
	DH_TSECT			stEDSect[DH_N_WEEKS][DH_N_REC_TSECT];	// NSP
	DH_MSG_HANDLE		struEDHandle;							// Process way 
} DH_DISK_ALARM_CFG;

typedef struct
{
	BYTE				byEnable;
	BYTE				byReserved[3];
	DH_MSG_HANDLE		struHandle;
} DH_NETBROKEN_ALARM_CFG;

// Alarm deployment 
typedef struct
{
	DWORD dwSize;
	DH_ALARMIN_CFG 		struLocalAlmIn[DH_MAX_ALARM_IN_NUM];
	DH_ALARMIN_CFG		struNetAlmIn[DH_MAX_ALARM_IN_NUM];
	DH_MOTION_DETECT_CFG struMotion[DH_MAX_VIDEO_IN_NUM];
	DH_VIDEO_LOST_CFG	struVideoLost[DH_MAX_VIDEO_IN_NUM];
	DH_BLIND_CFG		struBlind[DH_MAX_VIDEO_IN_NUM];
	DH_DISK_ALARM_CFG	struDiskAlarm;
	DH_NETBROKEN_ALARM_CFG	struNetBrokenAlarm;
} DHDEV_ALARM_SCHEDULE;

#define DECODER_OUT_SLOTS_MAX_NUM 		16
#define DECODER_IN_SLOTS_MAX_NUM 		16

// Alarm decoder configuration
typedef struct  
{
	DWORD				dwAddr;									// Alarm decoder address
	BOOL				bEnable;								// Alarm decoder enable
	DWORD				dwOutSlots[DECODER_OUT_SLOTS_MAX_NUM];	// Now only support 8
	int					nOutSlotNum;							// Effective number of array elements.
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT];
	DH_MSG_HANDLE		struHandle[DECODER_IN_SLOTS_MAX_NUM];	// Now only support 8
	int					nMsgHandleNum;							// Effective number of array elements.
	BYTE				bReserved[120];
} DH_ALARMDEC_CFG;

// The setup of alarm upload
typedef struct  
{
	BYTE				byEnable;						// Enable upload
	BYTE				bReserverd;						// Reserved
	WORD				wHostPort;						// Alarm center listening port 
	char				sHostIPAddr[DH_MAX_IPADDR_LEN];	// Alarm center IP

	int					nByTimeEn;						// Enable scheduled upload.Use it to upload IP or domain name to the centre.
	int					nUploadDay;						/*  Set upload date 
														"Never = 0", "Everyday = 1", "Sunday = 2", 
														"Monday = 3", Tuesday = 4", "Wednesday = 5",
														"Thursday = 6", "Friday = 7", "Saturday = 8"*/	
	int					nUploadHour;					// Set upload time ,[0~23]o'clock
	
	DWORD				dwReserved[300]; 				// Reserved for future development 
} ALARMCENTER_UP_CFG;

// Panorama switch alarm configuration
typedef struct __DH_PANORAMA_SWITCH_CFG 
{
	BOOL				bEnable;				// Enabled
	int					nReserved[5];			// Reserved
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT];
	DH_MSG_HANDLE		struHandle;				// Process way
} DH_PANORAMA_SWITCH_CFG;

typedef struct __ALARM_PANORAMA_SWITCH_CFG 
{
	int					nAlarmChnNum;			// Number of alarm channels
	DH_PANORAMA_SWITCH_CFG stuPanoramaSwitch[DH_MAX_VIDEO_IN_NUM];
} ALARM_PANORAMA_SWITCH_CFG;

// Lose focus alarm configuration
typedef struct __DH_LOST_FOCUS_CFG
{
	BOOL				bEnable;				// Enabled
	int					nReserved[5];			// Reserved
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT];
	DH_MSG_HANDLE		struHandle;				// Process way
} DH_LOST_FOCUS_CFG;

typedef struct __ALARM_LOST_FOCUS_CFG 
{
	int					nAlarmChnNum;			// Number of alarm channels
	DH_LOST_FOCUS_CFG stuLostFocus[DH_MAX_VIDEO_IN_NUM];
} ALARM_LOST_FOCUS_CFG;

// IP collision detection alarm configuration
typedef struct __ALARM_IP_COLLISION_CFG
{
	BOOL				bEnable;				// Enable
	DH_MSG_HANDLE		struHandle;				// Alarm activation
	int                 nReserved[300];			// Reserved
} ALARM_IP_COLLISION_CFG;

// MACcollision detection configuration
typedef struct __ALARM_MAC_COLLISION_CFG
{
	BOOL				bEnable;				// Enable
	DH_MSG_HANDLE		struHandle;				// Alarm activation
	int                 nReserved[300];			// Reserved
} ALARM_MAC_COLLISION_CFG;

// 232/485 com card signal info configuration
typedef struct __COM_CARD_SIGNAL_INFO
{
	WORD                wCardStartPose;          // card number start location
	WORD                wCardLenth;              // card number length
	char                cStartCharacter[32];     // start string
	char                cEndCharacter[32];       // end string
	BYTE                byReserved[28];          // reserved
}COM_CARD_SIGNAL_INFO;

// 232/485 com card  linked configuration(when the info from the com fit the configuration, it will trigger the device snap picture)
typedef struct __COM_CARD_SIGNAL_LINK_CFG
{
	COM_CARD_SIGNAL_INFO  struCardInfo;          // card info
	DH_MSG_HANDLE         struHandle;            // event link
	BYTE                  byReserved[24];        // reserved
	
}COM_CARD_SIGNAL_LINK_CFG;


//------------------------------Multiple privacy mask zones--------------------------------

// Privacy mask information
typedef struct __VIDEO_COVER_ATTR
{
	DH_RECT				rcBlock;				// Privacy mask zone coordinates
	int					nColor;					// Privacy mask color
	BYTE				bBlockType;				// Mask type;0:Black block,1: mosaic
	BYTE				bEncode;				// Encode lelel mask;1:valid,0:invalid
	BYTE				bPriview;				// Preview mask; 1:valid,0:invalid
	char				reserved[29];			// Reserved 
} VIDEO_COVER_ATTR;

// Multiple privacy mask zones 
typedef struct __DHDEV_VIDEOCOVER_CFG 
{
	DWORD				dwSize;
	char				szChannelName[DH_CHAN_NAME_LEN]; // Read-only
	BYTE				bTotalBlocks;			// The mask zones supported
	BYTE				bCoverCount;			// The mask zones have been set 
	VIDEO_COVER_ATTR	CoverBlock[DH_MAX_VIDEO_COVER_NUM]; // The mask zones 
	char				reserved[30];			// Reserved 
}DHDEV_VIDEOCOVER_CFG;

// decode policy configuration
typedef struct __DHDEV_DECODEPOLICY_CFG 
{
	int					nMinTime;				// (read only):minimal delay time(ms)
	int					nMaxTime;				// (read only):maximal delay time(ms)
	int					nDeocdeBufTime;			// device decode delay time(ms)
	
	char				reserved[128];			// reserved
}DHDEV_DECODEPOLICY_CFG;

// Device relative configuration
typedef struct __DHDEV_MACHINE_CFG 
{
	char				szMachineName[DH_MACHINE_NAME_NUM];		// Device name or SN 
	char				szMachineAddress[DH_MACHINE_NAME_NUM];	// Device location
	char				reserved[128];							// reserved
}DHDEV_MACHINE_CFG;


////////////////////////////////IPC series ////////////////////////////////

// Set wireless network information 
typedef struct 
{
	int					nEnable;				// Enable wireless
	char				szSSID[36];				// SSID
	int					nLinkMode;				// connection mode;0:auto,1:adhoc,2:Infrastructure
	int					nEncryption;			// encrypt;0:off,2:WEP64bit,3:WEP128bit, 4:WPA-PSK-TKIP, 5: WPA-PSK-CCMP
	int					nKeyType;				// 0:Hex,1:ASCII
    int					nKeyID;					// Serial number
	union
	{
		char			szKeys[4][32];			// Four group passwords
		char			szWPAKeys[128];			// when nEncryption is 4 or 5, use szWPAKeys
	};
	int					nKeyFlag;
	BYTE                byConnectedFlag;        // 0: not connect, 1: connect 
	char				reserved[11];
} DHDEV_WLAN_INFO;

// Select to use one wireless device 
typedef struct  
{
	char				szSSID[36];
	int					nLinkMode;				// Connection mode;0:adhoc,1:Infrastructure
	int 				nEncryption;			// Encrypt;0:off,2:WEP64bit,3:WEP128bit
	char				reserved[48];
} DHDEV_WLAN_DEVICE;

// The searched wireless device list 
typedef struct  
{
	DWORD				dwSize;
	BYTE				bWlanDevCount;			// The wireless devices searched 
	DHDEV_WLAN_DEVICE	lstWlanDev[DH_MAX_WLANDEVICE_NUM];
	char				reserved[255];
} DHDEV_WLAN_DEVICE_LIST;

// wireless device expended configuration
typedef struct
{
	char                szSSID[36];                         // server id
	char                szMacAddr[18];                      // mac address 
	BYTE                byApConnected;                      // connect state 0: not connect,1: connected
	BYTE                byLinkMode;                         // connect mod 0:adhoc 1:Infrastructure;
	int                 nRSSIQuality;                       // rssi quality(dbm)
	unsigned int        unApMaxBitRate;                     // max transmit speed
	BYTE                byAuthMode;                         // attestation mod:0:OPEN;1:SHARED;2:WPA;3:WPA-PSK;4:WPA2;5:WPA2-PSK;
															// 6:WPA-NONE(only use in Adhoc mode),
															// 7-11 are mix mode,choose one of them can to be connected 
															// 7:WPA-PSK | WPA2-PSK; 8:WPA | WPA2; 9:WPA | WPA-PSK;
															// 10:WPA2 | WPA2-PSK; 11:WPA | WPA-PSK |WPA2 |WPA2-PSK //12: UnKnown
	BYTE                byEncrAlgr;                         // encrypt mod 0:off; 2:WEP64bit; 3:WEP128bit; 4:WEP; 5:TKIP; 6:AES(CCMP)
															// 7: TKIP+AES( mix Mode) 8: UnKnown
	BYTE                byLinkQuality;                      // link quality 0~100(%)
    BYTE                byReserved[129];                     // Reserved 
}DHDEV_WLAN_DEVICE_EX;

// The searched wireless device expended configuration list 
typedef struct  
{
	DWORD				dwSize;
	BYTE				bWlanDevCount;			// The wireless device number searched
	DHDEV_WLAN_DEVICE_EX  lstWlanDev[DH_MAX_WLANDEVICE_NUM_EX];
	char				reserved[255];
} DHDEV_WLAN_DEVICE_LIST_EX;

// Function Test
typedef struct
{
	int                 nResult;                  // 0:success,1:failure
	BYTE                reserved[32];
} DHDEV_FUNC_TEST;

// FTP server info
typedef struct
{
	char                szServerName[32];          // server name
	char                szIp[16];                  // IP address
	int                 nPort;                     // port number
	char                szUserName[32];            // user name
	char                szPassword[32];	           // pass word
	BOOL                bAnonymity;                // whether anonymity log in 
	BYTE                byReserved[256];           // reserved
}FTP_SERVER_CFG;

// ftp server connect test
typedef struct
{
	FTP_SERVER_CFG     stuFtpServerInfo;           // ftp server info(filled by user)
	DHDEV_FUNC_TEST    stuTestResult;              // ftp server connect state
	BYTE               byReserved[64];
}DHDEV_FTP_SERVER_TEST;

// DDNS domain info
typedef struct
{

	char				szServerType[DH_MAX_SERVER_TYPE_LEN];	//server type
	char				szServerIp[DH_MAX_DOMAIN_NAME_LEN];		// server ip or domain
	DWORD				dwServerPort;			// server port
	char				szDomainName[DH_MAX_DOMAIN_NAME_LEN];	// dvr domain,such as jeckean.3322.org
	char				szUserName[DH_MAX_HOST_NAMELEN];		// username
	char				szUserPsw[DH_MAX_HOST_PSWLEN];			// password
	BYTE                byReserved[256];           // reserved
}DDNS_DOMAIN_INFO;


// DDNS domain test
typedef struct
{
	DDNS_DOMAIN_INFO   stuDomainInfo;				// DDNS domain
	DHDEV_FUNC_TEST    stuTestResult;				// test result
	char			   szMemo[128];					// test result memo
	BYTE               byReserved[64];
}DHDEV_DDNS_DOMAIN_TEST;

// hard disk's basic information
typedef struct 
{
	BYTE                byModle[32];				// model
	BYTE                bySerialNumber[32];			// serial number
	BYTE                byFirmWare[32];				// firmware no
	int                 nAtaVersion;				// ATA protocol version no
	int                 nSmartNum ;					// smart information no
	INT64				Sectors;	
	int                 nStatus;					// disk state 0-normal 1-abnormal
	int                 nReserved[33]; 
} DHDEV_DEVICE_INFO;

//smart information of harddisk,there may be many items up to more than 30????
typedef struct
{
	BYTE				byId;						// ID
	BYTE				byCurrent;					// attribute values 
	BYTE				byWorst;					// maximum error value 
	BYTE				byThreshold;				// threshold value 
	char				szName[64];					// property name
	char				szRaw[8];					// actual value
	int					nPredict;					// state
	char				reserved[128];
} DHDEV_SMART_VALUE;

//search hard disk smart information
typedef struct
{
    int                nDiskNum;					// disk number
	DHDEV_DEVICE_INFO  deviceInfo;    
	DHDEV_SMART_VALUE  smartValue[MAX_SMART_VALUE_NUM];
} DHDEV_SMART_HARDDISK;

// submodule information
typedef struct
{
	char               szModuleName[64];			//  submodule name
	char               szHardWareVersion[32];		//  submodule HardWareVersion
	char               szSoftwareVersion[32];		//  submodule SoftWareVersion
	BYTE               reserved[128]; 
} DHDEV_SUBMODELE_VALUE;

// search submodule information
typedef struct
{
	int                    nSubModuleNum;							//  nSubModuleNum
	DHDEV_SUBMODELE_VALUE  stuSubmoduleValue[MAX_SUBMODULE_NUM];	// Submodule information
	BYTE				   bReserved[256];
} DHDEV_SUBMODULE_INFO;

// Query harddisk damage ability
typedef struct
{
	BYTE                bDiskDamageLevel[DH_MAX_DISK_NUM];  // every disk's damage level
	BYTE                bReserved[128];
} DHDEV_DISKDAMAGE_INFO;

// SYSLOG remote server ability
typedef struct 
{
	char				szServerIp[DH_MAX_IPADDR_OR_DOMAIN_LEN];	//Server IP address
	int					nServerPort;								//Server port
	BYTE				bEnable;									//Server Enable
	BYTE				bReserved[255];								//Reserved bytes
}DHDEV_SYSLOG_REMOTE_SERVER;

// Video backup config parameter
typedef struct
{
	BYTE				backupVideoFormat;							//file type to backup, 0:dav, 1:asf
	BYTE				reversed[511];								//reserved
}DHDEV_BACKUP_VIDEO_FORMAT;


// Auto register config parameter
typedef struct  
{
	char				szServerIp[32];			// Registration server IP ; no use it,use szServerIpEx
	int					nServerPort;			// Port number 
	BYTE                byReserved[3];          // 
	BYTE                bServerIpExEn;          // Extend Registration server IP enable, 0-not enable, 1-enable
	char				szServerIpEx[60];       // Extend Registration server IP
} DHDEV_SERVER_INFO;

typedef struct  
{
	DWORD				dwSize;
	BYTE				bServerNum;				// The max IP amount supported
	DHDEV_SERVER_INFO	lstServer[DH_MAX_REGISTER_SERVER_NUM];
	BYTE				bEnable;				// Enable
	char				szDeviceID[32];			// Device ID
	char				reserved[94];
} DHDEV_REGISTER_SERVER;

// Camera property 
typedef struct __DHDEV_CAMERA_INFO
{
	BYTE				bBrightnessEn;			// Brightness adjustable;1:adjustable,0:can not be adjusted
	BYTE				bContrastEn;			// Contrast adjustable
	BYTE				bColorEn;				// Hue adjustable
	BYTE				bGainEn;				// Gain adjustable
	BYTE				bSaturationEn;			// Saturation adjustable
	BYTE				bBacklightEn;			// Backlight compensation adjustable
	BYTE				bExposureEn;			// Exposure option adjustable
	BYTE				bColorConvEn;			// Day/night switch 
	BYTE				bAttrEn;				// Property option; 1:Enable, 0:Disable
	BYTE				bMirrorEn;				// Mirror;1:support,0:do not support 
    BYTE				bFlipEn;				// Flip;1:support,0:do not support 
	BYTE				iWhiteBalance;			// White Balance 1 Support,0 :Do not support
	BYTE				iSignalFormatMask;		// Signal format mask,Bitwise:0-Inside(Internal input) 1- BT656 2-720p 3-1080i  4-1080p  5-1080sF
	BYTE				bRotate90;				// 90-degree rotation 1:support,0:do not support 
    BYTE				bLimitedAutoExposure;   // Support the time limit with automatic exposure 1:support,0:do not support 
    BYTE				bCustomManualExposure;  // support user-defined manual exposure time 1:support,0:do not support
	BYTE				bFlashAdjustEn;			// Support the flash lamp adjust
	BYTE				bNightOptions;			// Support day and night change
	BYTE                iReferenceLevel;    	// Support electric reference setting
	BYTE                bExternalSyncInput;     // Support external sync Input
	unsigned short      usMaxExposureTime;      // Max exposure time, unit:ms         
	unsigned short      usMinExposureTime;      // Min exposure time, unit:ms
	BYTE                bWideDynamicRange;      // Wide dynamic range,0-present not support,2~n max supported range value
	BYTE                bDoubleShutter;         // Double Shutter
	BYTE				bRev[110];				// reserved 
} DHDEV_CAMERA_INFO;

// Special configuration for night,will automatically switch to night configuration when low light
typedef struct __DHDEV_NIGHTOPTIONS 
{
	BYTE  bEnable;								// 0-Do not switch,1-Switch 
												// Roughly sunrise and sunset time, before sunrise or after sunset, will use a special configuration for night.
												// 00:00:00 ~23:59:59
	BYTE  bSunriseHour;
	BYTE  bSunriseMinute;
	BYTE  bSunriseSecond;
	BYTE  bSunsetHour;
	BYTE  bSunsetMinute;
	BYTE  bSunsetSecond;  
	BYTE  bWhiteBalance ;						// White balance  0:Disabled,1:Auto 2:sunny 3:cloudy 4:home 5:office 6:night 7: Custom
	BYTE  bGainRed;								// Red gain adjustment, white balance to "Custom" mode will effect 0~100
	BYTE  bGainBlue;							// Green gain adjustment, white balance to "Custom" mode will effect 0~100
	BYTE  bGainGreen;							// Blue gain adjustment, white balance to "Custom" mode will effect 0~100
	BYTE  bGain;								// 0~100
	BYTE  bGainAuto;							// 0-Without auto gain 1-Auto gain
	BYTE  bBrightnessThreshold ;				// Brightness value 0~100
	BYTE  ReferenceLevel;                       // electric value 0~100   
	BYTE  bExposureSpeed;						// Range depends on the device capability: 0-Auto Exposure  1~n-1-manual exposure level;  n-Auto Exposure with time limit;  n+1-manual exposure customized time (n means exposure level)
	float ExposureValue1;						// Lower limit of automatic exposure time or customized manual exposure time, in milliseconds, value 0.1ms ~ 80ms
	float ExposureValue2;						// Automatic exposure time limit, in milliseconds, value 0.1ms ~ 80ms
	BYTE  bAutoApertureEnable;                  // Auto Aperture Enable,1:open,0:close
	BYTE  bWideDynamicRange;                    // wide dynamic value, it depends on max support value
	WORD  wNightSyncValue;						// night sync 0~360
	WORD  wNightSyncValueMillValue;             // night sync mill value 0~999
	BYTE res[10];								// Reserve
} DHDEV_NIGHTOPTIONS;

// camera attribute configration
typedef struct __DHDEV_CAMERA_CFG 
{ 
	DWORD				dwSize;
	BYTE				bExposure;				// Exposure mode;1-9:Manual exposure level  ,0: Auto exposure 
	BYTE				bBacklight;				// Backlight compensation:3:High,2:Medium,1:Low,0:close
	BYTE				bAutoColor2BW;			// Day/night mode;2:Open,1:Auto,0:Close
	BYTE				bMirror;				// Mirror;1:Open,0:Close
	BYTE				bFlip;					// Flip;1:Open,0:Close  support;0 :do not support 
	BYTE				bLensEn;				// the capacity of Auto Iris function 1:support;0 :do not support
	BYTE				bLensFunction;			// Auto aperture function: 1:Enable aperture  ;0: Disable aperture  
	BYTE				bWhiteBalance;			// White Balance 0:Disabled,1:Auto 2:sunny 3:cloudy 4:home 5:office 6:night
	BYTE				bSignalFormat;			// Signal format 0-Inside(Internal input) 1- BT656 2-720p 3-1080i  4-1080p  5-1080sF
	BYTE				bRotate90;				// 0-Not rotating,1-90 degrees clockwise,2-90 degrees counterclockwise
	BYTE                bReferenceLevel;        // electric value 0~100  
	BYTE                byReserve;              // Reserved
	float				ExposureValue1;			// Auto exposure or manual exposure limit custom time,Milliseconds(0.1ms~80ms)
	float				ExposureValue2;			// Auto exposure limit,Milliseconds(0.1ms~80ms)
	DHDEV_NIGHTOPTIONS	stuNightOptions;		// Configuration parameter options for night 
	BYTE				bGainRed;				// Red gain adjustment, effective when white balance to "Custom" mode,  0 ~ 100
	BYTE				bGainBlue;				// Green gain adjustment, effective when white balance to "Custom" mode,  0 ~ 100
	BYTE				bGainGreen;				// Blue gain adjustment, effective when white balance to "Custom" mode,  0 ~ 100
	BYTE				bFlashMode;				// Flash mode,0-close,1-always,2-auto 
	BYTE				bFlashValue;			// Flash work values,  0-0us, 1-64us, 2-128us,...15-960us
	BYTE				bFlashPole;				// Flash trigger mode 0 - low level 1 - high level
	BYTE                bExternalSyncPhase;     // External single input
	BYTE                bFlashInitValue;        // Flash brightness prevlue, 0~100
	WORD                wExternalSyncValue ;    // External value 0~360
	WORD                wExternalSyncValueMillValue; //  External SyncValue Mill Value0~999
	BYTE                bWideDynamicRange;           // wide dynamic range, it depends on max support value
	char				bRev[55];				// Reserved
} DHDEV_CAMERA_CFG;

#define ALARM_MAX_NAME 64
// (wireless)IR alarm setup
typedef struct
{
	BOOL				bEnable;				// Enable alarm input
	char				szAlarmName[DH_MAX_ALARM_NAME];	// Alarm input name
	int					nAlarmInPattern;		// Annunciator input wave
	int					nAlarmOutPattern;		// Annunciator output wave
	char				szAlarmInAddress[DH_MAX_ALARM_NAME];// Alarm input address
	int					nSensorType;			// External device sensor type normal open or normal close 
	int					nDefendEfectTime;		// Deploy and cancel latch time. The alarm input becomes activated after the specified time.
	int					nDefendAreaType;		// Defend area 
	int					nAlarmSmoothTime;		// Alarm smooth time:system ignores the second alarm if one alarm inputs in two times. 
	char				reserved[128];
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT];
	DH_MSG_HANDLE		struHandle;				// Process way 
} DH_INFRARED_INFO;

// Wireless remote control setup 
typedef struct 
{
	BYTE				address[ALARM_MAX_NAME];// Remote control address
	BYTE				name[ALARM_MAX_NAME];	// Remote control name
	BYTE				reserved[32];			// Reserved string 
} DH_WI_CONFIG_ROBOT;

// Wireless alarm output setup 
typedef struct 
{
	BYTE				address[ALARM_MAX_NAME];// Alarm output address
	BYTE				name[ALARM_MAX_NAME];	// Aalarm output name
	BYTE				reserved[32];			// Reserved string 
} DH_WI_CONFIG_ALARM_OUT;

typedef struct  
{
	DWORD				dwSize;
	BYTE				bAlarmInNum;			// Wireless alarm input amount 
	BYTE				bAlarmOutNum;			// Wireless alarm output amount 
	DH_WI_CONFIG_ALARM_OUT AlarmOutAddr[16];	// Alarm output address
	BYTE				bRobotNum;				// Remote control amount
	DH_WI_CONFIG_ROBOT RobotAddr[16];			// Remote control address 
	DH_INFRARED_INFO	InfraredAlarm[16];
	char				reserved[256];
} DH_INFRARED_CFG;

// New audio detection alarm information 
typedef struct
{
	int					channel;				// Alarm channel number
	int					alarmType;				// Alarm type;0:Volumn value is too low ,1:Volumn value is too high. 
	unsigned int		volume;					// Volume
	BYTE                byState;                // volume alarm state, 0: alarm appear, 1: alarm disappear
	char				reserved[255];
} NET_NEW_SOUND_ALARM_STATE;

typedef struct  
{
	int					channelcount;			// Alarm channel amount 
	NET_NEW_SOUND_ALARM_STATE SoundAlarmInfo[DH_MAX_ALARM_IN_NUM];
} DH_NEW_SOUND_ALARM_STATE;

// Snapshot function property structure 
typedef struct 
{
	int					nChannelNum;			// Channel amount 
	DWORD				dwVideoStandardMask;	// Resolution(Bit). Please refer to enumeration CAPTURE_SIZE						
	int					nFramesCount;			// Valid length of Frequency[128] array
	char				Frames[128];			// Frame rate(value) 
												// -25:1f/25s;-24:1f/24s;-23:1f/23s;-22:1f/23s
												// ?-?-
												// 0: invalid;1:1f/s;2:2f/s;3:13f/s
												// 4:4f/s;5:5f/s;17:17f/s;18:18f/s
												// 19:19f/s;20:20f/s
												// ?-?-
												// 25: 25f/s
	int					nSnapModeCount;			// valid length of SnapMode[16] array
	char				SnapMode[16];			// (value)0:activate scheduled snapshot,1:Manually activate snapshot
	int					nPicFormatCount;		// Valid length of Format[16] array 
	char 				PictureFormat[16];		// (Value)0:BMP format,1:JPG format
	int					nPicQualityCount;		// valid length of Quality[32] array
	char 				PictureQuality[32];		// value
												// 100:Image quality 100%;80:Image quality 80%;60:Image quality60%
												// 50:Image quality50%;30:Image quality30%;10:Image quality10%
	char 				nReserved[128];			// Reserved
} DH_QUERY_SNAP_INFO;

typedef struct 
{
	int					nChannelCount;			// Channel amount 
	DH_QUERY_SNAP_INFO  stuSnap[DH_MAX_CHANNUM];
} DH_SNAP_ATTR_EN;


/* IP Filtering configuration */
#define DH_IPIFILTER_NUM			200			// IP
#define DH_IPIFILTER_NUM_EX			512			// IP

// IP Information
typedef struct 
{
	DWORD				dwIPNum;				// IP count
	char				SZIP[DH_IPIFILTER_NUM][DH_MAX_IPADDR_LEN]; // IP
	char				byReserve[32];			// Reserved
} IPIFILTER_INFO;

// IP Filtering configuration
typedef struct
{
	DWORD				dwSize;
	DWORD				dwEnable;				// Enable
	DWORD				dwType;					// The current list type;0:White List 1:Blacklist(The device can enable only one type of list)
	IPIFILTER_INFO		BannedIP;				// Black list
	IPIFILTER_INFO		TrustIP;				// Trusted sites
	char				byReserve[256];			// Reserved
} DHDEV_IPIFILTER_CFG;

// IP Information extended
typedef struct 
{
	DWORD				dwIPNum;				// IP count
	char				SZIP[DH_IPIFILTER_NUM_EX][DH_MAX_IPADDR_LEN]; // IP
	char				byReserve[32];			// Reserved
} IPIFILTER_INFO_EX;

// IP Filtering extended configuration
typedef struct
{
	DWORD				dwSize;
	DWORD				dwEnable;				// Enable
	DWORD				dwType;					// The current list type;0:White List 1:Blacklist(The device can enable only one type of list)
	IPIFILTER_INFO_EX		BannedIP;			// Black list
	IPIFILTER_INFO_EX		TrustIP;			// Trusted sites
	char				byReserve[256];			// Reserved
} DHDEV_IPIFILTER_CFG_EX;

typedef struct
{
	int                nCardNum;                // card number
	char 	           cardInfo [DH_MAX_CARD_NUM][DH_MAX_CARDINFO_LEN]; // card info string 
	BYTE               byReserve[32];           // reserved
}DHDEV_NETCARD_CFG;

// RTSP configuration
typedef struct
{
	WORD               wPort;                  // port number(can't be the same as tcp or udp's port number)
	BYTE               byReserved[62];         // reserved
}DHDEV_RTSP_CFG;

// stream encrypt configuration
// encrypt key info
typedef struct _ENCRYPT_KEY_INFO
{
	BYTE        byEncryptEnable;       //  encrypt enable, 0: not encrypt, 1:encrypt
	BYTE        byReserved[3]; 
	union
	{
		BYTE    byDesKey[8];           // des key
		BYTE    by3DesKey[3][8];       // 3des key
		BYTE    byAesKey[32];          // aes key
		
	};
}ENCRYPT_KEY_INFO;

// encrypt algorithm
typedef struct _ALGO_PARAM_INFO
{
	WORD       wEncryptLenth;       // encrypt length, for example: wEncryptLenth = 128,the effictive encprypt key vlue only include byAesKey[0]~[15] in the  ENCRYPT_KEY_INFO struct
									// when the encrypt algorithm is AES,it only support 3 kind length such as 128,192,256
									// when the encrypt algorithm is DES,it has a fixed value 64
									// when the encrypt algorithm is DES,it means the encrypt key's number(2 or 3 encrypt key)
	BYTE       byAlgoWorkMode ;     // work mode, see EM_ENCRYPT_ALOG_WORKMODE 
	BYTE       reserved[13];        // reserved
}ALGO_PARAM_INFO;

// stream encrypt configuration
typedef struct _DHEDV_STREAM_ENCRYPT
{
    BYTE                    byEncrptAlgoType;        // encrypt algorithm type:00: AES,01:DES,02: 3DES
    BYTE                    byReserved1[3];
    ALGO_PARAM_INFO         stuEncrptAlgoparam;      // encrypt algorithm param
    ENCRYPT_KEY_INFO        stuEncryptKeys[32];      // each channel's encrypt key's info
    BYTE                    reserved2[1388];
}DHEDV_STREAM_ENCRYPT;

// custom configuration
typedef struct _DHDEV_CUSTOM_CFG
{
	char                   szData[1024];            // custom configuration information
	char                   reserved[3072];          // reserved
}DHDEV_CUSTOM_CFG;

/*audio talk configuration*/
typedef struct
{
	DWORD				dwSize;
	int					nCompression;			// Compression type,value,refer to DH_TALK_CODING_TYPE,please set the compression type according to the mode the device supports?¡ê
	int					nMode;					// Encode mode, value, 0 means not support the compression tyep
												// Set the responding type according to compression type
												// like AMR, please refer to EM_ARM_ENCODE_MODE
	char				byReserve[256];			// Reserved
} DHDEV_TALK_ENCODE_CFG;

// According to the mobile function
// (Event triggers message)MMS Configuration Structure
typedef struct
{
	DWORD				dwSize;
	DWORD				dwEnable;				// Enable
	DWORD				dwReceiverNum;			// Receiver amount
	char				SZReceiver[DH_MMS_RECEIVER_NUM][32];	// Receiver,normally cellphone
    BYTE                byType;					// Message type 0:MMS;1:SMS
	char                SZTitle[32];			// Message title
	char				byReserve[223];			// Reserved
} DHDEV_MMS_CFG;

// (Message triggers wireless connection configuration)
typedef struct  
{
	DWORD				dwSize;
	DWORD				dwEnable;				// Enable
	DWORD				dwSenderNum;			// Sender amount
	char				SZSender[DH_MMS_SMSACTIVATION_NUM][32];	// Sender, normally the cellphone number
 	char				byReserve[256];			// Reserved
}DHDEV_SMSACTIVATION_CFG;

// (Dailing triggers the wireless connection)
typedef struct  
{
	DWORD				dwSize;
	DWORD				dwEnable;				// Enable
	DWORD				dwCallerNum;			// Sender amount
	char				SZCaller[DH_MMS_DIALINACTIVATION_NUM][32];	// Sender, normally the cellphone
 	char				byReserve[256];			// Reserved
}DHDEV_DIALINACTIVATION_CFG;
// Above is with the mobile phone functions


// Wireless network signal strength structure
typedef struct
{
	DWORD				dwSize;
	DWORD				dwTDSCDMA;				// TD-SCDMA strength,range:0-100
	DWORD				dwWCDMA;				// WCDMA strength,range:0-100
	DWORD				dwCDMA1x;				// CDMA1x strength,range:0-100
	DWORD				dwEDGE;					// EDGE strength,range:0-100
	DWORD				dwEVDO;					// EVDO strength,range:0-100
	int					nCurrentType;			// Current type
												// 0	The device can't support this
												// 1    TD_SCDMA
												// 2	WCDMA
												// 3	CDMA_1x
												// 4	EDGE
												// 5	EVDO
	char				byReserve[252];			// Reserved
} DHDEV_WIRELESS_RSS_INFO;

typedef struct _DHDEV_SIP_CFG
{
	BOOL				bUnregOnBoot;			//Unregister on Reboot
	char				szAccoutName[64];		//Account Name
	char				szSIPServer[128];		//SIP Server
	char				szOutBoundProxy[128];	//Outbound Proxy
	DWORD				dwSIPUsrID;				//SIP User ID
	DWORD				dwAuthID;				//Authenticate ID
	char				szAuthPsw[64];			//Authenticate Password
	char				szSTUNServer[128];		//STUN Server
	DWORD				dwRegExp;				//Registration Expiration
	DWORD				dwLocalSIPPort;			//Local SIP Port
	DWORD				dwLocalRTPPort;			//Local RTP Port
	BOOL				bEnable;				// Enable
	char				szNotifyID[128];        // Notify ID
	NET_TIME			stuRegTime;             // register time, read only 
	BYTE				bReserved[868];		    //reserved
} DHDEV_SIP_CFG;

typedef struct _DHDEV_SIP_STATE
{
	int					nStatusNum;				//SIP state number 
	BYTE				byStatus[64];           //0:on line,1:off line,2:invalid sip,3:registering,4:talking
	BYTE				bReserved[64];		    //reserved
}DHDEV_SIP_STATE;

typedef struct _DHDEV_HARDKEY_STATE
{
	BOOL				bState;                 // 0:Hard Key disconnect, 1:Hard Key connect
	BYTE				bReserved[64];          // reserved
}DHDEV_HARDKEY_STATE;

typedef struct _DHDEV_ISCSI_PATHLIST
{
	int					nCount;
	char				szPaths[DH_MAX_ISCSI_PATH_NUM][MAX_PATH_STOR];	// remote path
} DHDEV_ISCSI_PATHLIST;

// wifi capability country
typedef struct _DHDEV_WIFI_ROUTE_CAP_COUNTRY
{
	char				szCountry[32];			// country
	int					nValidChnNum;			// valid channel number
	int					nValideChannels[32];	// valid channel array
	char				reserved[64];			// reserved
} DHDEV_WIFI_ROUTE_CAP_COUNTRY;

typedef struct _DHDEV_WIFI_ROUTE_CAP
{
	int					nCountryNum;				// country number
	DHDEV_WIFI_ROUTE_CAP_COUNTRY stuCountry[256];	// country config
	char				reserved[256];				// reserved
} DHDEV_WIFI_ROUTE_CAP;

//  monitor info
typedef struct _MONITOR_INFO
{
	int					nPresetObjectNum;        // preset object number
	int					nActualObjectNum;        // actural object number
	char				reserved[64]; 
}MONITOR_INFO;

typedef struct _DHDEV_MONITOR_INFO
{
	int					nChannelNumber;
	MONITOR_INFO		stMonitorInfo[64];			//  monitor info
	char				reserved[128];
}DHDEV_MONITOR_INFO;
/***************************** PTZ preset configuration ***********************************/
typedef struct _POINTEANBLE
{
	BYTE				bPoint;					// Preset range[1,80], invalid setting is 0.
	BYTE				bEnable;				// Valid or not,0 invalid,1 valid
	BYTE				bReserved[2];
} POINTEANBLE;

typedef struct _POINTCFG
{
	char				szIP[DH_MAX_IPADDR_LEN];// ip
	int					nPort;					// Port	
	POINTEANBLE			stuPointEnable[80];		// Preset enable
	BYTE				bReserved[256];
}POINTCFG;

typedef struct _DHDEV_POINT_CFG
{
	int					nSupportNum;			// Read only parameters,when configuration, please return to SDK,means the supported preset¡À¨ª¨º??¡ì3?¦Ì??¡è??¦Ì?¨ºy
	POINTCFG			stuPointCfg[16];		// 2D config means point info.
	BYTE				bReserved[256];			// Reserved
}DHDEV_POINT_CFG;
////////////////////////////////Mobile DVR supported////////////////////////////////

// GPS information(Mobile device)
typedef struct _GPS_Info
{
    NET_TIME			revTime;				// position time 
	char				DvrSerial[50];			// Device serial number
    double				longitude;				// Longitude
    double				latidude;				// Latitude 
    double				height;					// Height(meter)
    double				angle;					// Angle(The north pole is the original point and clockwise is +)
    double				speed;					// Speed(Kilometer/hour)
    WORD				starCount;				// Starcount
    BOOL				antennaState;			// Antenna status(true=good,false =bad)
    BOOL				orientationState;		// Orientation status (true=position,false = no position )
} GPS_Info,*LPGPS_Info;

// alarm state info
typedef struct 
{
	int                nAlarmCount;             // alarm count
	int                nAlarmState[128];        // alarm state
	BYTE               byRserved[128];          // reserved
}ALARM_STATE_INFO;

// Snapshot parameter structure 
typedef struct _snap_param
{
	unsigned int		Channel;				// Snapshot channel
	unsigned int		Quality;				// Image quality:level 1 to level 6
	unsigned int		ImageSize;				// Video size;0:QCIF,1:CIF,2:D1
	unsigned int		mode;					// Snapshot mode;0:request one frame,1:send out requestion regularly,2: Request consecutively
	unsigned int		InterSnap;				// Time unit is second.If mode=1, it means send out requestion regularly. The time is valid.
	unsigned int		CmdSerial;				// Request serial number
	unsigned int		Reserved[4];
} SNAP_PARAMS, *LPSNAP_PARAMS;

// Snapshot function setup 
typedef struct 
{
	DWORD				dwSize;
	BYTE				bTimingEnable;				// Schedule snapshot button(The alarm snapshot button is in alarm activation configuration)
	BYTE                bPicIntervalHour;           // timing snapshot interval hour
	short	            PicTimeInterval;			// The time intervals of timing capture (s). At present, the capture device supports the largest time interval is 30 minutes 
	DH_VIDEOENC_OPT		struSnapEnc[SNAP_TYP_NUM]; // Snapshot encode setup. The resolution, video quality, frame rate setup and fram rate are all negative. It means the snapshot times in each second. 
} DHDEV_SNAP_CFG;

//wifi state of car device
typedef struct  
{
	char	szSSID[128];							//SSID
	BOOL	bEnable;								//If enable wifi function, 0:Disable 1:Enable
	int		nSafeType;								//Verify type
													//0:OPEN 
													//1:RESTRICTE
													//2:WEP
													//3:WPA
													//4:WPA2
													//5:WPA-PSK
													//6:WPA2-PSK
	int		nEncryprion;							//Encryption method
													//0:OPEN
													//1:TKIP
													//2:WEP
													//3:AES
													//4:NONE(without verify)
													//5:AUTO
	                                                //6:SHARED
	int		nStrength;								//AP site signal
	char	szHostIP[128];							//host address
	char	szHostNetmask[128];						//host mask
	char	szHostGateway[128];						//host gate  way
	BYTE	bReserved[1024];
} DHDEV_VEHICLE_WIFI_STATE;

typedef struct
{
	char	szSSID[128];							//SSID
	int		nPriority;								//Priority,(1-32)
	int		nSafeType;								//Verify type
													//0:OPEN 
													//1:RESTRICTE
													//2:WEP
													//3:WPA
													//4:WPA2
													//5:WPA-PSK
													//6:WPA2-PSK
	int		nEncryprion;							//Encryption method
													//0:OPEN
													//1:TKIP
													//2:WEP
													//3:AES
													//4:NONE(No verify)
													//5:AUTO
	                                                //6:SHARED
	char	szKey[128];								//Connection key
	char	szHostIP[128];							//Host address
	char	szHostNetmask[128];						//Host mask
	char	szHostGateway[128];						//Host gateway
	BYTE	bReserved[1024];
} DHDEV_VEHICLE_WIFI_CONFIG;
typedef struct
{
	char    szSSID[128];                            // SSID   
	BYTE    bReserved[256];                         // reserved
}WIFI_CONNECT;

typedef struct 
{
	BOOL	bIsScan;								//0:Not scan wifi (Manually added), 1: scanned wifi
	char	szSSID[128];							//SSID
	int		nSafeType;								//Verify type
													//0:OPEN 
													//1:RESTRICTE
													//2:WEP
													//3:WPA
													//4:WPA2
													//5:WPA-PSK
													//6:WPA2-PSK
	int		nEncryprion;							//Encryption method
													//0:OPEN
													//1:TKIP
													//2:WEP
													//3:AES
													//4:NONE(No verify)	
													//5:AUTO
	                                                //6:SHARED
	char	szKey[128];								//Connection key
	int		nStrength;								//AP site signal
	int		nMaxBitRate;							//AP site maximum transmission rate, with units, read-only
	int		nIsCnnted;								//If success connect read-only
	int		nIsSaved;								//If save read-only
	int		nPriority;								//Priority,(1-32)
	char	szHostIP[128];							//Host address
	char	szHostNetmask[128];						//Host network mask
	char	szHostGateway[128];						//Host gateway
	int		nWifiFreq;								//Radio frequency, using channel logo
	BYTE	bReserved[1024];
}DHDEV_VEHICLE_SINGLE_WIFI_AP_CFG;

typedef struct 
{
	BOOL	bEnable;								//if enable wifi, 0:disable, 1:enable
	int		nWifiApNum;								// Effective number of structure:DHDEV_VEHICLE_WIFI_AP_CFG 
	DHDEV_VEHICLE_SINGLE_WIFI_AP_CFG struWifiAp[64];//Single WIFI AP configration
	int	nReserved[512];								//reserved
}DHDEV_VEHICLE_WIFI_AP_CFG;

// GPS log structure
typedef struct _DH_DEVICE_GPS_LOG_ITEM
{
	DHDEVTIME       stuDevTime;             // device time  
	DWORD		    dwLatidude;				// Longitude(0-180 degree)north Longitude 30.183382 = (30.183382 + 90) * 100000 = 120183382
	DWORD		    dwLongitude;			// Latitude(0-360 degree)east Latitude 120.178274 =(120.178274 + 180) * 100000 = 300178274
	DWORD           dwSpeed;                // speed,dwSpeed/1000*1.852km/h
	DWORD           dwHight;                // hight,m
	DWORD           dwAngle;                // direction,0~360,the north is it's origin, clockwise
	DHDEVTIME       stuGpsTime;             // GPS time 
	BYTE            bAntStatus; 		    // GPS antenna state,0 means good;!=0 meams there has some exception 
	BYTE            bOriStatus; 			// orientation state, != 0 means orientation sucess;
	BYTE            bSatCount; 				// satellite count
	BYTE            bGPSStatus; 			// GPS state,0:not orientation, 1:non differential position information 2:differential position information
	DWORD           dwTemp;                 // temperature(centigrade),if real value is 30.0 centigrade,this param will be valued as 30000
	DWORD           dwHumidity;             // humidity(%),if real value is 30.0%,this param will be valued as 30000
	BYTE            bReserved[24];          // reserved
    
}DH_DEVICE_GPS_LOG_ITEM;

// query GPS param
typedef struct _QUERY_GPS_LOG_PARAM
{
	NET_TIME			stuStartTime;			// start time
	NET_TIME			stuEndTime;				// end time
	int					nStartNum;				// start index,the first time to query an be valued with 0
	BYTE				bReserved[20];
} QUERY_GPS_LOG_PARAM;

typedef struct _GPS_TEMP_HUMIDITY_INFO
{
	double              dTemperature;          // temperature(centigrade),if real value is 30.0 centigrade,this param will be valued as 30000
	double              dHumidity;             // humidity(%),if real value is 30.0%,this param will be valued as 30000
	BYTE                bReserved[128];        // reserved
}GPS_TEMP_HUMIDITY_INFO;

// enclosure type
typedef enum
{
	ENCLOSURE_LIMITSPEED = 0x01,				// speed limit
	ENCLOSURE_DRIVEALLOW = 0x02,				// drive allow
	ENCLOSURE_FORBIDDRIVE = 0x04,				// forbind drive
	ENCLOSURE_LOADGOODS = 0x08,					// load goods
	ENCLOSURE_UPLOADGOODS = 0x10,				// upload goods
}ENCLOSURE_TYPE;

typedef enum
{
	 ENCLOSURE_ALARM_DRIVEIN ,	                 // drive in
	 ENCLOSURE_ALARM_DRIVEOUT,	                 // drive out
	 ENCLOSURE_ALARM_OVERSPEED,				     // over speed
	 ENCLOSURE_ALARM_SPEEDCLEAR,				 // speed clear
}ENCLOSURE_ALARM_TYPE;

typedef struct 
{
	DWORD				dwLongitude;			// longitude
    DWORD				dwLatidude;				// latidude
}GPS_POINT;

// enclosure config
typedef struct _DHDEV_ENCLOSURE_CFG
{
	UINT				unType;                 // mask
	BYTE				bRegion[8];             // front 4 bit means country, province, city, town
	UINT				unId;                   // rect id
	UINT				unSpeedLimit;           // speed limit(km/h)
	UINT				unPointNum;             // rect point number
	GPS_POINT			stPoints[128];			// rect point info
	BYTE				reserved[64];           // reserved
}DHDEV_ENCLOSURE_CFG;

// enclosure version config
typedef struct _DHDEV_ENCLOSURE_VERSION_CFG
{
	UINT				unType;                 // type mask,such as LIMITSPEED | DRIVEALLOW
    UINT				unVersion[32];          // version
    int					nReserved;              // reserved 
}DHDEV_ENCLOSURE_VERSION_CFG;

// enclosure alarm info
typedef struct __ALARM_ENCLOSURE_INFO
{
	int					nTypeNumber;                    // type number
	BYTE				bType[16];						// type
	int					nAlarmTypeNumber;               // alarm type number
	BYTE				bAlarmType[16];                 // alarm type
	char				szDriverId[DH_VEHICLE_DRIVERNO_LEN];  // drive id
	UINT				unEnclosureId;      	        // enclosure id
	UINT				unLimitSpeed;	                // speed limit(km/h)
	UINT				unCurrentSpeed;                 // current speed
	NET_TIME			stAlarmTime;                    // alarm time
	DWORD				dwLongitude;					// longitude
	DWORD				dwLatidude;						// latidude
	BYTE				byReserved[120];                // reserved
}ALARM_ENCLOSURE_INFO;

// RAID state
#define DH_MAX_RAID_NUM  16
typedef struct __RAID_STATE_INFO
{
	char				szName[16];					// Raid name
	BYTE				byType;						// type 1:Jbod     2:Raid0      3:Raid1     4:Raid5
	BYTE				byStatus;					// status 0:unknown ,1:active,2:degraded,3:inactive,4:recovering
	BYTE                byReserved[2];
	int					nCntMem;					// nMember number
	int					nMember[32];				// 1,2,3,.
	int					nCapacity;					// capacity(G)
	int					nRemainSpace;				// remain space(M)
	int					nTank;						// Tank 0:main,1:tank1,2:tank2,¡­¡­
	char				reserved[32];
}RAID_STATE_INFO;

typedef struct __ALARM_RAID_INFO
{
	int              nRaidNumber;                   // RAID number
	RAID_STATE_INFO  stuRaidInfo[DH_MAX_RAID_NUM];  // RAID info
	char             reserved[128];
}ALARM_RAID_INFO;
//////////////////////////////////ATM support//////////////////////////////////

typedef struct
{
	int					Offset;					// Symbol position bit Offset
	int					Length;					// Symbol position length
	char				Key[16];				// Symbol position value 
} DH_SNIFFER_FRAMEID;

typedef struct 
{
	int					Offset;					// Symbol position bit offset 
	int					Offset2;				// It is invalid now 
	int					Length;					// The symbol position length
	int					Length2;				// It is invalid now
	char				Title[12];  			// Title value 
	char                Key[12];                // Key value
} DH_SNIFFER_CONTENT;

// Network sniffer setup 
typedef struct 
{
	DH_SNIFFER_FRAMEID	snifferFrameId;			// Each FRAME ID option
	DH_SNIFFER_CONTENT	snifferContent[DH_SNIFFER_CONTENT_NUM];	// The corresponding four sniffers in each FRAME
} DH_SNIFFER_FRAME;

// Configuration structure of each sniffer 
typedef struct
{
	char				SnifferSrcIP[DH_MAX_IPADDR_LEN];	// Sniffer source address 	
	int					SnifferSrcPort;						// Sniffer source port 
	char				SnifferDestIP[DH_MAX_IPADDR_LEN];	// Sniffer destination address 
	int					SnifferDestPort;					// Sniffer destination port 
	char				reserved[28];						// Reserved string 
	DH_SNIFFER_FRAME	snifferFrame[DH_SNIFFER_FRAMEID_NUM];// 6 FRAME options 
	int					displayPosition;					// Display position 
	int					recdChannelMask;					// Channel mask
} DH_ATM_SNIFFER_CFG;

typedef struct  
{
	DWORD				dwSize;
	DH_ATM_SNIFFER_CFG	SnifferConfig[4];
	char				reserved[256];						// Reserved string 
} DHDEV_SNIFFER_CFG;

typedef DH_SNIFFER_FRAMEID DH_SNIFFER_FRAMEID_EX;
typedef DH_SNIFFER_CONTENT DH_SNIFFER_CONTENT_EX;

// Capture network configuration
typedef struct  
{
	DH_SNIFFER_FRAMEID	snifferFrameId;								// Each FRAME ID Options
	DH_SNIFFER_CONTENT	snifferContent[DH_SNIFFER_CONTENT_NUM_EX];	// Each FRAME Corresponding to the contents of capture	
} DH_SNIFFER_FRAME_EX;

// Capture each of the corresponding structure
typedef struct
{
	char				SnifferSrcIP[DH_MAX_IPADDR_LEN];					// Source address capture		
	int					SnifferSrcPort;										// Capture source port
	char				SnifferDestIP[DH_MAX_IPADDR_LEN];					// Destination address capture
	int					SnifferDestPort;									// Capture the target port
	DH_SNIFFER_FRAME_EX	snifferFrame[DH_SNIFFER_FRAMEID_NUM];				// 6 FRAME Options
	int					displayPosition;									// Display Position
	int					recdChannelMask;									// Channel mask
	BOOL				bDateScopeEnable;									// Data sources enable
	BOOL				bProtocolEnable;									// Protocol enable
	char				szProtocolName[DH_SNIFFER_PROTOCOL_SIZE];			// Protocol name
	int					nSnifferMode;										// Capture mode; 0:net,1:232.
	int					recdChannelMask1;									// Channel submask  32 ~ 63 channel
	char				reserved[252];
} DH_ATM_SNIFFER_CFG_EX;

// Atm trade type
#define ATM_MAX_TRADE_TYPE_NAME	64
#define ATM_MAX_TRADE_NUM		1024

typedef struct __DH_ATM_QUERY_TRADE   
{
	int					nTradeTypeNum;										// number of trade types
	int					nExceptionTypeNum;									// number of exception events
	char				szSupportTradeType[ATM_MAX_TRADE_NUM][ATM_MAX_TRADE_TYPE_NAME];    // trade events
	char				szSupportExceptionType[ATM_MAX_TRADE_NUM][ATM_MAX_TRADE_TYPE_NAME];// exception events
} DH_ATM_QUERY_TRADE, *LPDH_ATM_QUERY_TRADE;

/////////////////////////////////NVD support/////////////////////////////////
#define nEncoderID nDecoderID
#define byEncoderID byDecoderID

// Decoder information
typedef struct __DEV_DECODER_INFO 
{
	char			szDecType[64];			// type
	int				nMonitorNum;			// TV number
	int				nEncoderNum;			// Decoder channel number
	BYTE			szSplitMode[16];		// Supported by a number of TV screen partition
	BYTE            bMonitorEnable[16];		// TV enable
	BYTE            bTVTipDisplay;          // TV tip display enable 0:not support 1:support.
	BYTE            reserved1[3];
	BYTE            byLayoutEnable[48];     // every channel's tip display enable
	char			reserved[12];
} DEV_DECODER_INFO, *LPDEV_DECODER_INFO;

// Encoder information
#ifndef NANJINGDITIE_NVD
typedef struct __DEV_ENCODER_INFO 
{
	char			szDevIp[DH_MAX_IPADDR_LEN];			// IP address of Front-end DVR 
	WORD			wDevPort;							// Port of Front-end DVR
	BYTE			bDevChnEnable;                      // Decoder channel enable
	BYTE			byDecoderID;						// The corresponding channel number decoder
	char			szDevUser[DH_USER_NAME_LENGTH_EX];	// User Name
	char			szDevPwd[DH_USER_PSW_LENGTH_EX];	// Password
	int				nDevChannel;						// Channel Number
	int				nStreamType;						// Stream type; 0:Main Stream, 1:Sub-stream
	BYTE			byConnType;							// 0:TCP, 1:UDP, 2:Multicast
	BYTE			byWorkMode;							// 0:Direct Connect, 1:transmit
	WORD			wListenPort;						// Listening port services, for transmit
	DWORD			dwProtoType;						// Protocol type
														// 0:compatible with each other.
														// 1:dahua 2nd protocol
														// 2:dahua system integration protocol
														// 3:dahua DSS protocol
														// 4:dahua rtsp protocol
	char			szDevName[64];						// Front device name
	BYTE            byVideoInType;                      // video source type:0-SD,1-HD		
	char			szDevIpEx[DH_MAX_IPADDR_OR_DOMAIN_LEN];// szDevIp extended, IP or domain name
	BYTE            bySnapMode;                         // snap mode(when nStreamType==2 effective) 0:That request a frame,1:Time to send a request
	BYTE            byManuFactory;						// The target device manufacturers,See the enum struct EM_IPC_TYPE
	BYTE            byDeviceType;                       // The target device's device type,0:IPC
	BYTE            byDecodePolicy;                     // The target device's decode policy
														// 0:LatencyLevel3 1:LatencyLevel2
														// 2:LatencyLevel1 3:MiddleLevel
														// 4:FluencyLevel3 5:FluencyLevel2
														// 6:FluencyLevel1
	BYTE            bReserved[3];                          // reserved
	DWORD           dwHttpPort;                         // http port 0-65535
	DWORD           dwRtspPort;                         // RTSP port 0-65535
	char			szChnName[32];						// remote channel name
	char			reserved[4];
} DEV_ENCODER_INFO, *LPDEV_ENCODER_INFO;

#else

// encoder info
typedef struct __DEV_ENCODER_INFO 
{
	char			szDevIp[DH_MAX_IPADDR_LEN];			// IP address of Front-end DVR 
	WORD			wDevPort;							// Port of Front-end DVR
	BYTE			bDevChnEnable;                      // Decoder channel enable
	BYTE			byDecoderID;						// The corresponding channel number decoder
	char			szDevUser[DH_USER_NAME_LENGTH_EX];	// User Name
	char			szDevPwd[DH_USER_PSW_LENGTH_EX];	// Password
	int				nDevChannel;						// Channel Number
	int				nStreamType;						// Stream type; 0:Main Stream, 1:Sub-stream
	BYTE			byConnType;							// 0:TCP, 1:UDP, 2:Multicast
	BYTE			byWorkMode;							// 0:Direct Connect, 1:transmit
	WORD			wListenPort;						// Listening port services, for transmit
	DWORD			dwProtoType;						// Protocol type
														// 0:compatible with each other.
														// 1:dahua 2nd protocol
														// 2:dahua system integration protocol
														// 3:dahua DSS protocol
														// 4:dahua rtsp protocol
	char			szDevName[32];						// Front device name
	BYTE            byVideoInType;                      // video source type:0-SD,1-HD		
	char			szDevIpEx[DH_MAX_IPADDR_OR_DOMAIN_LEN];// szDevIp extended, IP or domain name
	BYTE            bySnapMode;                         // snap mode(when nStreamType==2 effective) 0:That request a frame,1:Time to send a request
	BYTE            byManuFactory;						// The target device manufacturers,See the enum struct EM_IPC_TYPE
	BYTE            byDeviceType;                       // The target device's device type,0:IPC
	BYTE            byDecodePolicy;                     // The target device's decode policy
														// 0:LatencyLevel3 1:LatencyLevel2
														// 2:LatencyLevel1 3:MiddleLevel
														// 4:FluencyLevel3 5:FluencyLevel2
														// 6:FluencyLevel1
	BYTE            bReserved[3];                          // reserved
	DWORD           dwHttpPort;                         // http port 0-65535
	DWORD           dwRtspPort;                         // RTSP port 0-65535
	char			szChnName[32];						// remote channel name
	char			szMcastIP[DH_MAX_IPADDR_LEN];       // multicast address
	char            reserved[128];
} DEV_ENCODER_INFO, *LPDEV_ENCODER_INFO;

#endif

// TV parameters 
typedef struct __DEV_DECODER_TV 
{
	int				nID;								// TV ID
	BOOL			bEnable;							// Enable, open or close
	int				nSplitType;							// Partition number
	DEV_ENCODER_INFO stuDevInfo[16];					// All encoder information
	BYTE			bySupportSplit[10];					// Split mode supported
	char			reserved[6];
} DEV_DECODER_TV, *LPDEV_DECODER_TV;

// Screen combination of information
typedef struct __DEC_COMBIN_INFO
{
	int				nCombinID;							// Combin ID
	int             nSplitType;							// Partition number
	BYTE            bDisChn[16];						// Display channel
	char			reserved[16];
} DEC_COMBIN_INFO, *LPDEC_COMBIN_INFO;

// Tour Information
#define DEC_COMBIN_NUM 			32						// the number of tour combination
typedef struct __DEC_TOUR_COMBIN 
{
	int				nTourTime;							// Tour Interval(s)
	int				nCombinNum;							// the number of combination
	BYTE			bCombinID[DEC_COMBIN_NUM];			// Combination Table
	char			reserved1[32];
	BYTE			bCombinState[DEC_COMBIN_NUM];		// Combination option state,0:close;1:open
	char			reserved2[32];
} DEC_TOUR_COMBIN, *LPDEC_TOUR_COMBIN;

// Decoder Playback type
typedef enum __DEC_PLAYBACK_MODE
{
	Dec_By_Device_File = 0,								// Front-end DVR--By File
	Dec_By_Device_Time,									// Front-end DVR--By Time
} DEC_PLAYBACK_MODE;

// Decoder Playback control type
typedef enum __DEC_CTRL_PLAYBACK_TYPE
{
	Dec_Playback_Seek = 0,								// Drag
	Dec_Playback_Play,									// Play
	Dec_Playback_Pause,									// Pause
	Dec_Playback_Stop,									// Stop
} DEC_CTRL_PLAYBACK_TYPE;

// tour ctrol type
typedef enum __DEC_CTRL_TOUR_TYPE
{
	Dec_Tour_Stop = 0,									// stop
	Dec_Tour_Start,										// start
	Dec_Tour_Pause,										// pause
	Dec_Tour_Resume,									// resume
} DEC_CTRL_TOUR_TYPE;

// Playback by file Conditions
typedef struct __DEC_PLAYBACK_FILE_PARAM 
{
	char			szDevIp[DH_MAX_IPADDR_LEN];			// IP address of Front-end DVR
	WORD			wDevPort;							// Port of Front-end DVR
	BYTE			bDevChnEnable;                      // Decoder channel enable
	BYTE			byDecoderID;						// The corresponding channel number
	char			szDevUser[DH_USER_NAME_LENGTH_EX];	// User Name
	char			szDevPwd[DH_USER_PSW_LENGTH_EX];	// Password
	NET_RECORDFILE_INFO stuRecordInfo;					// Record file information
	char			reserved[12];
} DEC_PLAYBACK_FILE_PARAM, *LPDEC_PLAYBACK_FILE_PARAM;

// Playback by time Conditions
typedef struct __DEC_PLAYBACK_TIME_PARAM 
{
	char			szDevIp[DH_MAX_IPADDR_LEN];			// IP address of Front-end DVR
	WORD			wDevPort;							// Port of Front-end DVR
	BYTE			bDevChnEnable;                      // Decoder channel enable
	BYTE			byDecoderID;						// The corresponding channel number
	char			szDevUser[DH_USER_NAME_LENGTH_EX];	// User Name
	char			szDevPwd[DH_USER_PSW_LENGTH_EX];	// Password
	int				nChannelID;
	NET_TIME		startTime;
	NET_TIME		endTime;
	char			reserved[12];
} DEC_PLAYBACK_TIME_PARAM, *LPDEC_PLAYBACK_TIME_PARAM;

// Current decoding channel status(including channel status, decoding stream info and etc.)
typedef struct __DEV_DECCHANNEL_STATE
{
	BYTE			byDecoderID;						// Responding decoding channel number
	BYTE            byChnState;                         // Current decoding channel in opertion status:0 -free,1 -realtime monitoring,2 - playback 3 - Decode Tour
	BYTE			byFrame;                            // Current data frame rate
	BYTE            byReserved;                         // Reserved
	int				nChannelFLux;						// Decoding channel data amount
	int             nDecodeFlux;						// Decoding data amount
	char            szResolution[16];                   // Current data resolution
	char			reserved[256];
} DEV_DECCHANNEL_STATE, *LPDEV_DECCHANNEL_STATE;

// Device TV display info
typedef struct __DEV_VIDEOOUT_INFO
{
	DWORD				dwVideoStandardMask;			// NSP,video standard mask,according to the bit which shows video format(not support now)
	int					nVideoStandard;                 // NSP,current format(not support now,please use DHDEV_SYSTEM_ATTR_CFG by VideoStandard to read and config the video format)
	DWORD				dwImageSizeMask;				// Resolution mask,according the bit which shows video resolution
	int                 nImageSize;                     // Current resolution
	char				reserved[256];
}DEV_VIDEOOUT_INFO, *LPDEV_VIDEOOUT_INFO;

// TV adjust
typedef struct __DEV_TVADJUST_CFG
{
	int					nTop;							// top(0 - 100)
	int					nBotton;						// botton(0 - 100)
	int					nLeft;							// left(0 - 100)
	int                 nRight;							// right(0 - 100)
	int					reserved[32];
}DHDEV_TVADJUST_CFG, *LPDHDEV_TVADJUST_CFG;

// decoder tour configuration
typedef struct __DEV_DECODER_TOUR_SINGLE_CFG
{
	char		szIP[128];								// Front-end device's ip.Such as"10.7.5.21". Support retention of the domain name, end by '\0'.
	int			nPort;									// Front-end device's port.(0, 65535).
	int			nPlayChn;								// front-end device's Request channel [1, 16].
	int			nPlayType;								// front-end device's Stream type, 0:main; 1:sub.
	char		szUserName[32];							// front-end device's user name,end by '\0'.
	char		szPassword[32];							// front-end device's Password,end by '\0'.
	int			nInterval;								// Round tour interval [10, 120],s.
	DWORD		nManuFactory;							// device's factory(enum see IPC_TYPE)
	UINT		nHttpPport;								// device's http port
	UINT		nRtspPort;								// device's rtsp port
	BYTE		bReserved[52];							// reserved.
}DHDEV_DECODER_TOUR_SINGLE_CFG;

typedef struct __DEV_DECODER_TOUR_CFG
{
	int								nCfgNum;			// the number of Configure structures. The biggest support 32. Specific number of support inquiries through capacity.
	DHDEV_DECODER_TOUR_SINGLE_CFG	tourCfg[64];		// Polling configuration array, the effective number of structures by the members of the "nCfgNum" designation. Keep left to expand 32.
	BYTE							bReserved[256];		// reserved.
}DHDEV_DECODER_TOUR_CFG;

/////////////////////////////////intelligent support/////////////////////////////////
// picture info
typedef struct  
{
	DWORD                dwOffSet;                       // current picture file's offset in the binary file, byte
	DWORD                dwFileLenth;                    // current picture file's size, byte
	WORD                 wWidth;                         // picture width, pixel
	WORD                 wHeight;                        // picture high, pixel
	BYTE                 bReserved[16];                 
}DH_PIC_INFO;

// Struct of object info for video analysis 
typedef struct 
{
	int					nObjectID;						// Object ID,each ID represent a unique object
	char				szObjectType[128];				// Object type
	int					nConfidence;					// Confidence(0~255),a high value indicate a high confidence
	int					nAction;						// Object action:1:Appear 2:Move 3:Stay 4:Remove 5:Disappear 6:Split 7:Merge 8:Rename
	DH_RECT				BoundingBox;					// BoundingBox
	DH_POINT			Center;							// The shape center of the object
	int					nPolygonNum;					// the number of culminations for the polygon
	DH_POINT			Contour[DH_MAX_POLYGON_NUM];	// a polygon that have a exactitude figure
	DWORD				rgbaMainColor;					// The main color of the object;the first byte indicate red value, as byte order as green, blue, transparence, for example:RGB(0,255,0),transparence = 0, rgbaMainColor = 0x00ff0000.
    char				szText[128];					// the interrelated text of object,such as number plate,container number
	char                szObjectSubType[64];            // object sub type,different object type has different sub type:
														// Vehicle Category:"Unknown","Motor","Non-Motor","Bus","Bicycle","Motorcycle"
														// Plate Category:"Unknown","mal","Yellow","DoubleYellow","Police","Armed",
														// "Military","DoubleMilitary","SAR","Trainning"
														// "Personal" ,"Agri","Embassy","Moto","Tractor","Other"
														// HumanFace Category:"Normal","HideEye","HideNose","HideMouth"
	BYTE                byReserved1[3];
	bool                bPicEnble;                     // picture info enable
	DH_PIC_INFO         stPicInfo;                     // picture info
	bool				bShotFrame;						// is shot frame
	bool				bColor;							// rgbaMainColor is enable
	BYTE				byReserved[222];    
} DH_MSG_OBJECT;

// snapshot info
typedef struct
{
	short              snSpeed;                          // current car speed,km/h
	short              snCarLength;                      // current car length, dm
	float              fRedTime;                         // current red light time, s.ms
	float              fCapTime;                         // current car way snapshot time, s.ms 
	BYTE               bSigSequence;                     // current snapshot Sequence
	BYTE               bType;                            // current snapshot type
														 // 0: radar up speed limit;1: radar low speed limit;2: car detector up speed limit;3:car detector low speed limit
														 // 4: reverse;5: break red light;6: red light on;7: red light off;8: snapshot or traffic gate
	BYTE               bDirection;                       // breaking type :01:left turn;02:straight;03:right
	BYTE               bLightColor;                      // current car way traffic light state,0: green, 1: red, 2: yellow
	BYTE               bSnapFlag[16];                    // snap flag from device
}DH_SIG_CARWAY_INFO;

// Vehicle detector redundancy info
typedef struct
{
	BYTE                byRedundance[8];                // The vehicle detector generates the snap signal redundancy info
	BYTE                bReserved[120];                 // Reserved field
}DH_SIG_CARWAY_INFO_EX;


// car way info
typedef struct  
{
	BYTE                bCarWayID;                           // current car way id 
	BYTE                bReserve[2];                         // reserved
	BYTE                bSigCount;                           // being snapshotted
	DH_SIG_CARWAY_INFO  stuSigInfo[DH_MAX_SNAP_SIGNAL_NUM];  // the snapshot info	
	BYTE                bReserved[12];                       // reserved
}DH_CARWAY_INFO;

// event file info
typedef struct  
{
	BYTE               bCount;                               // the file count in the current file's group
	BYTE               bIndex;                               // the index of the file in the group
	BYTE               bFileTag;                             // file tag, see the enum struct EM_EVENT_FILETAG
	BYTE               bFileType;                            // file type,0-normal 1-compose 2-cut picture
	NET_TIME_EX        stuFileTime;                          // file time
	DWORD               nGroupId;                             // the only id of one group file
}DH_EVENT_FILE_INFO;

// pic resolution 
typedef struct
{
	unsigned short   snWidth;    // width
 	unsigned short   snHight;    // hight
}DH_RESOLUTION_INFO;

// person info
typedef struct
{
	char                szPersonName[DH_MAX_NAME_LEN];		// name                 
	WORD				wYear;								// birth year
	BYTE				byMonth;							// birth month
	BYTE				byDay;								// birth day
	char                szID[32];							// the unicle ID for the person
	BYTE                bImportantRank;						// importance level,1~10,the higher value the higher level
	BYTE                bySex;								// sex, 0-man, 1-female
	WORD                wFacePicNum;						// picture number
	DH_PIC_INFO         szFacePicInfo[DH_MAX_PERSON_IMAGE_NUM]; // picture info
	BYTE                bReserved[256];
}FACERECOGNITION_PERSON_INFO;

// cadidate person info
typedef struct
{
	FACERECOGNITION_PERSON_INFO  stPersonInfo;            // person info
	BYTE                         bySimilarity;            // similarity
	BYTE                         byReserved[127];         // reserved
}CANDIDATE_INFO;

// TrafficCar
typedef struct tagDEV_EVENT_TRAFFIC_TRAFFICCAR_INFO
{
	char               szPlateNumber[32];               // plate number
	char               szPlateType[32];                 // plate type
	char               szPlateColor[32];                // plate color, "Blue","Yellow", "White","Black"
	char               szVehicleColor[32];              // vehicle color, "White", "Black", "Red", "Yellow", "Gray", "Blue","Green"
	int                nSpeed;                          // speed, Km/H
	char               szEvent[64];                     // trigger event type
	char               szViolationCode[32];             // violation code, see TrafficGlobal.ViolationCode
	char               szViolationDesc[64];             // violation describe
	int                nLowerSpeedLimit;                // lower speed limit
	int                nUpperSpeedLimit;                // upper speed limit
	int                nOverSpeedMargin;                // over speed margin, km/h 
	int                nUnderSpeedMargin;               // under speed margin, km/h 
	int                nLane;                           // lane	
	int                nVehicleSize;                    // vehicle size, see VideoAnalyseRule's describe
	float              fVehicleLength;                  // vehicle length, m
	int                nSnapshotMode;                   // snap mode 0-normal,1-globle,2-near,4-snap on the same side,8-snap on the reverse side,16-plant picture
	char               szChannelName[32];               // channel name
	char               szMachineName[256];              // Machine name
	char               szMachineGroup[256];             // machine group
	char               szRoadwayNo[64];                 // road way number	
	char               szDrivingDirection[3][DH_MAX_DRIVINGDIRECTION];   
																			// DrivingDirection: for example ["Approach", "Shanghai", "Hangzhou"]
													     					// "Approach" means driving direction,where the car is more near;"Leave"-means where if mor far to the car
														 					// the second and third param means the location of the driving direction

	BYTE				bReserved[1024];				// reserved
}DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO;

// the describe of EVENT_IVS_CROSSLINEDETECTION's data
typedef struct tagDEV_EVENT_CROSSLINE_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	DH_POINT            DetectLine[DH_MAX_DETECT_LINE_NUM];    // rule detect line
	int                 nDetectLineNum;                        // rule detect line's point number
	DH_POINT            TrackLine[DH_MAX_TRACK_LINE_NUM];      // object moveing track
	int                 nTrackLineNum;                         // object moveing track's point number
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                bDirection;                     // direction, 0-left to right, 1-right to left
	BYTE                byReserved[2];
	DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[876];					//

} DEV_EVENT_CROSSLINE_INFO;

// the describe of EVENT_IVS_CROSSREGIONDETECTION's data
typedef struct tagDEV_EVENT_CROSSREGION_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
		DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // rule detect region
	int                 nDetectRegionNum;                          // rule detect region's point number
	DH_POINT            TrackLine[DH_MAX_TRACK_LINE_NUM];          // object moving track
	int                 nTrackLineNum;                             // object moving track's point number
		BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                bDirection;                     // direction, 0-in, 1-out,2-apaer,3-leave
	BYTE                bActionType;                    // action type,0-appear 1-disappear 2-in area 3-cross area
	BYTE				bReserved1[1];					// 
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[804];					// 
	int                 nObjectNum;                     // Detect object amount
	DH_MSG_OBJECT		stuObjectIDs[DH_MAX_OBJECT_LIST];// Detected object
	int                 nTrackNum;                      // Locus amount(Corresponding to the detected object amount.)
	DH_POLY_POINTS      stuTrackInfo[DH_MAX_OBJECT_LIST];// Locus info(Corresponding to the detected object)
} DEV_EVENT_CROSSREGION_INFO;

// the describe of EVENT_IVS_PASTEDETECTION's data
typedef struct tagDEV_EVENT_PASTE_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	int                 nDetectRegionNum;				// rule detect region's point number
	DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // rule detect region
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[888];			    	// Reserved

} DEV_EVENT_PASTE_INFO;

// the describe of EVENT_IVS_LEFTDETECTION's data
typedef struct tagDEV_EVENT_LEFT_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
	int                 nDetectRegionNum;				// detect region point number
	DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // detect region
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[888];			    	// Reserved

} DEV_EVENT_LEFT_INFO;

// the describe of EVENT_IVS_PRESERVATION's data
typedef struct tagDEV_EVENT_PRESERVATION_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
	int                 nDetectRegionNum;				// detect region point number
	DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // detect region
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[888];			    	// Reserved

} DEV_EVENT_PRESERVATION_INFO;

// the describe of EVENT_IVS_STAYDETECTION's data
typedef struct tagDEV_EVENT_STAY_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
	int                 nDetectRegionNum;				// detect region point number
	DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // detect region
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[888];			    	// Reserved

} DEV_EVENT_STAY_INFO;

// the describe of EVENT_IVS_WANDERDETECTION's data
typedef struct tagDEV_EVENT_WANDER_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];                  // reserved
	int                 nObjectNum;                     // detected objects number
	DH_MSG_OBJECT		stuObjectIDs[DH_MAX_OBJECT_LIST];	// detected objects
	int                 nTrackNum;                      // track number
	DH_POLY_POINTS      stuTrackInfo[DH_MAX_OBJECT_LIST];// track info
	int                 nDetectRegionNum;				// detect region point number
	DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // detect region
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[1020];				

} DEV_EVENT_WANDER_INFO;

// the describe of EVENT_IVS_MOVEDETECTION's data
typedef struct tagDEV_EVENT_MOVE_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
	int                 nDetectRegionNum;				// detect region point 
	DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // detect region
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[888];					

} DEV_EVENT_MOVE_INFO;

// the describe of EVENT_IVS_TAILDETECTION's data
typedef struct tagDEV_EVENT_TAIL_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
	int                 nDetectRegionNum;				// detect region point 
	DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    //  detect region
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[888];					

} DEV_EVENT_TAIL_INFO;

// the describe of EVENT_IVS_RIOTERDETECTION's data
typedef struct tagDEV_EVENT_RIOTER_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	int					nObjectNum;						// have being detected object number
	DH_MSG_OBJECT		stuObjectIDs[DH_MAX_OBJECT_LIST];// have being detected object list
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];                  // reserved
	int                 nDetectRegionNum;				// detect region point 
	DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // detect region

    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[888];					

} DEV_EVENT_RIOTERL_INFO;

// the describe of EVENT_IVS_FIGHTDETECTION's data
typedef struct tagDEV_EVENT_FIGHT_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	int					nObjectNum;						// have being detected object number
	DH_MSG_OBJECT		stuObjectIDs[DH_MAX_OBJECT_LIST];// have being detected object list
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];                  // reserved
	int                 nDetectRegionNum;				// detect region point 
	DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // detect region
	
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[888];					
} DEV_EVENT_FIGHT_INFO;

// the describe of EVENT_IVS_FIREDETECTION's data
typedef struct tagDEV_EVENT_FIRE_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];                  // reserved
	int                 nDetectRegionNum;				// detect region point
	DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // detect region
	
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[888];					// Reserved

} DEV_EVENT_FIRE_INFO;

// add by lihu 2011/8/8 begin
// the describe of EVENT_IVS_FIREDETECTION's data
typedef struct tagDEV_EVENT_ELECTROSPARK_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[972];					// reserved
	
} DEV_EVENT_ELECTROSPARK_INFO;
// add by lihu 2011/8/8 end

// the describe of EVENT_IVS_SMOKEDETECTION's data
typedef struct tagDEV_EVENT_SMOKE_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[972];					

} DEV_EVENT_SMOKE_INFO;

// the describe of EVENT_IVS_FLOWSTAT's data
typedef struct tagDEV_EVENT_FLOWSTAT_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	int					nNumberLeft;					// the number of person across from left
	int					nNumberRight;					// the number of person across from right
	int					nUpperLimit;					// upper limit
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[972];					

} DEV_EVENT_FLOWSTAT_INFO;

// the describe of EVENT_IVS_NUMBERSTAT's data
typedef struct tagDEV_EVENT_NUMBERSTAT_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	int					nNumber;						// the number of object which is in the area
	int					nUpperLimit;					// upper limit
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE				bReserved1[3];					// 
	int                 nEnteredNumber;                 // entered object number
	int                 nExitedNumber;                  // exited object number
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[964];					// Reserved

} DEV_EVENT_NUMBERSTAT_INFO;

// the describe of EVENT_IVS_CROSSFENCEDETECTION's data
typedef struct tagDEV_EVENT_CROSSFENCEDETECTION_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	int					nUpstairsLinePointNumber;		               // Upstairs Line Point Number
	DH_POINT		    stuUpstairsLine[DH_MAX_DETECT_LINE_NUM];	   // Upstairs Line info
	int					nDownstairsLinePointNumber;		               // Downstairs Line Point Number
	DH_POINT		    stuDownstairsLine[DH_MAX_DETECT_LINE_NUM];     // Downstairs Line info
	int                 nTrackLineNum;                                 // track line point number                
	DH_POINT            TrackLine[DH_MAX_TRACK_LINE_NUM];              // track line info
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                bDirection;                     // direction, 0-left to right, 1-right to left
	BYTE                byReserved[2];
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[1016];				// Reserved
	
} DEV_EVENT_CROSSFENCEDETECTION_INFO;

// the describe of EVENT_IVS_INREGIONDETECTION's data
typedef struct tagDEV_EVENT_INREGIONDETECTION_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	int                 nObjectNum;                     // have being detected objects number
	DH_MSG_OBJECT		stuObjectIDs[DH_MAX_OBJECT_LIST];	// have being detected objects
	int                 nTrackNum;                      // track line number
	DH_POLY_POINTS      stuTrackInfo[DH_MAX_OBJECT_LIST];// track lines info
	int                 nDetectRegionNum;				// detect regions number
	DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // detect regions
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[1016];				// Reserved
	
} DEV_EVENT_INREGIONDETECTION_INFO;

// the describe of EVENT_IVS_TAKENAWAYDETECTION's data
typedef struct tagDEV_EVENT_TAKENAWAYDETECTION_INFO
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						//  have being detected object
	int                 nDetectRegionNum;				// detect region's point number
	DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // detect region info
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[1016];				// Reserved
	
} DEV_EVENT_TAKENAWAYDETECTION_INFO;

// the describe of EVENT_IVS_VIDEOABNORMALDETECTION's data
typedef struct tagDEV_EVENT_VIDEOABNORMALDETECTION_INFO
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                bType;                          // type, 0-video lost, 1-video freeze, 2-video blind, 3-camera moving, 4-too dark, 5-too light
	BYTE                byReserved[2];
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[1016];				// Reserved
	
} DEV_EVENT_VIDEOABNORMALDETECTION_INFO;

// the describe of EVENT_IVS_PARKINGDETECTION's data
typedef struct tagDEV_EVENT_PARKINGDETECTION_INFO
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	int                 nDetectRegionNum;				// detect region's point number
	DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // detect region info
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[1016];				// Reserved 
	
} DEV_EVENT_PARKINGDETECTION_INFO;

// the describe of EVENT_IVS_ABNORMALRUNDETECTION's data
typedef struct tagDEV_EVENT_ABNORMALRUNDETECTION 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	double              dbSpeed;                        // speed ,km/h
	double              dbTriggerSpeed;                 // triggerSpeed,km/h
	int                 nDetectRegionNum;				// detect region's point number
	DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // detect region info
	int                 nTrackLineNum;                         // track line point number              
	DH_POINT            TrackLine[DH_MAX_TRACK_LINE_NUM];      // track line info
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                bRunType;                       // type, 0-run fast, 1-sudden speedup, 2-sudden speed-down
	BYTE                byReserved[2];
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[1016];				// Reserved 
	
} DEV_EVENT_ABNORMALRUNDETECTION_INFO;

// the describe of EVENT_IVS_RETROGRADEDETECTION's data
typedef struct tagDEV_EVENT_RETROGRADEDETECTION_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	int                 nTrackLineNum;                           // track line point number                   
	DH_POINT            TrackLine[DH_MAX_TRACK_LINE_NUM];        // track line info
	int                 nDirectionPointNum;                      // direction point number
	DH_POINT            stuDirections[DH_MAX_DETECT_LINE_NUM];   // direction info
	int                 nDetectRegionNum;				         // detect region's point number
	DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];  // detect region info
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[1016];				// Reserved  
	
} DEV_EVENT_RETROGRADEDETECTION_INFO;

// the describe of EVENT_IVS_FACERECOGNITION's data
typedef struct tagDEV_EVENT_FACERECOGNITION_INFO
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	NET_TIME_EX			UTC;							// the event happen time
	DH_MSG_OBJECT		stuObject;						// have being detected object
	int                 nCandidateNum;                  // candidate number
    CANDIDATE_INFO      stuCandidates[DH_MAX_CANDIDATE_NUM]; // candidate info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE				bReserved[1023];				// reserved
}DEV_EVENT_FACERECOGNITION_INFO;

// Event type EVENT_IVS_DENSITYDETECTION(Population amount detect) corresponding data block description info
typedef struct tagDEV_EVENT_DENSITYDETECTTION_INFO
{
	int					nChannelID;						// Channel No.
	char				szName[128];					// Event name
	double				PTS;							// Time stamp(ms)
	NET_TIME_EX			UTC;							// Event occurred time
	int					nEventID;						// Event ID
	int					nObjectNum;						// Detected object amount
	DH_MSG_OBJECT		stuObjectIDs[DH_MAX_OBJECT_LIST];	// Detected object list
	DH_EVENT_FILE_INFO  stuFileInfo;                    // The corresponding file info of the event
	BYTE                bEventAction;                   // Event operation.0=pulse event,1=begin of the durative event,2=end of the durative event;
	BYTE                byReserved[3];                  // Reserved field
	int                 nDetectRegionNum;				// Acme amount of the rule detect zone
	DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // Rule detect zone
	
    DWORD               dwSnapFlagMask;	                // Snap flag(by bit)¡ê?please refer to NET_RESERVED_COMMON
	BYTE				bReserved[1020];				// Reserved field. For extension use.
}DEV_EVENT_DENSITYDETECTION_INFO;

// Event type EVENT_IVS_QUEUEDETECTION(queue detect)corresponding data block description info
typedef struct tagDEV_EVENT_QUEUEDETECTION_INFO 
{
	int					nChannelID;						// Channel No.
	char				szName[128];					// Event name
	double				PTS;							// Time stamp(ms)
	NET_TIME_EX			UTC;							// Event occurred time
	int					nEventID;						// Event ID
	DH_EVENT_FILE_INFO  stuFileInfo;                    // The corresponding file info of the event
	BYTE                bEventAction;                   // Event operation.0=pulse event,1=begin of the durative event,2=end of the durative event;
	BYTE				bReserved1[3];				    // Reserved field
	DH_POINT            stuDetectLine[2];               // rule detect line
	BYTE				bReserved[1012];				// Reserved field.
}DEV_EVENT_QUEUEDETECTION_INFO;

typedef struct tagDEV_EVENT_TRAFFICCONTROL_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[972];					// Reserved field. For extension use. 

} DEV_EVENT_TRAFFICCONTROL_INFO;

// the describe of EVENT_IVS_TRAFFICACCIDENT's data
typedef struct tagDEV_EVENT_TRAFFICACCIDENT_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	int					nObjectNum;						// have being detected object number
	DH_MSG_OBJECT		stuObjectIDs[DH_MAX_OBJECT_LIST];// have being detected object list
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[972];					// Reserved

} DEV_EVENT_TRAFFICACCIDENT_INFO;

// the describe of EVENT_IVS_TRAFFICJUNCTION's data
typedef struct tagDEV_EVENT_TRAFFICJUNCTION_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	int					nLane;							// road number
	DWORD				dwBreakingRule;					// BreakingRule's mask,first byte: crash red light; 
	                                                    // secend byte:break the rule of driving road number; 
	                                                    // the third byte:converse; the forth byte:break rule to turn around;
														// the five byte:traffic jam; the six byte:traffic vacancy; 
														// the seven byte: Overline; defalt:trafficJunction                                                        
	NET_TIME_EX			RedLightUTC;					// the begin time of red light
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	int                 nSequence;                      // snap index,such as 3,2,1,1 means the last one,0 means there has some exception and snap stop
	int                 nSpeed;                         // car's speed (km/h)
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];                  // reserved
	DH_MSG_OBJECT       stuVehicle;                     // vehicle info
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[476];				    // Reserved
	DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;     // Traffic vehicle info

} DEV_EVENT_TRAFFICJUNCTION_INFO;


// the describe of EVENT_IVS_TRAFFICGATE's data
typedef struct tagDEV_EVENT_TRAFFICGATE_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	int					nLane;							// road number
	int					nSpeed;							// the car's actual rate(Km/h)
	int					nSpeedUpperLimit;				// rate upper limit(km/h)
	int					nSpeedLowerLimit;				// rate lower limit(km/h) 
	DWORD				dwBreakingRule;					// BreakingRule's mask,first byte: Retrograde; 
	                                                    // second byte:Overline; the third byte:Overspeed; 
														// the forth byte:UnderSpeed;the five byte: crash red light;the six byte:passing(trafficgate)
	                                                    // the seven byte: OverYellowLine; the eight byte: WrongRunningRoute; the nine byte: YellowVehicleInRoute; default: trafficgate
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	DH_MSG_OBJECT       stuVehicle;                     // vehicle info
	BYTE                szManualSnapNo[64];             // manual snap sequence string                 
	int                 nSequence;                      // snap index,such as 3,2,1,1 means the last one,0 means there has some exception and snap stop
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];                  // reserved
	BYTE                szSnapFlag[16];                 // snap flag from device
	BYTE                bySnapMode;                     // snap mode,0-normal 1-globle 2-near 4-snap on the same side 8-snap on the reverse side 16-plant picture
	BYTE                byOverSpeedPercentage;          // over speed percentage
	BYTE                byUnderSpeedingPercentage;      // under speed percentage
	BYTE                byRedLightMargin;               // red light margin, s
	BYTE                byDriveDirection;               // drive direction,0-"Approach",where the car is more near,1-"Leave",means where if mor far to the car
	char                szRoadwayNo[32];                // road way number
	char                szViolationCode[16];            // violation code
	char                szViolationDesc[128];           // violation desc
	DH_RESOLUTION_INFO  stuResolution;                  // picture resolution
	char                szVehicleType[32];              // car type,"Motor", "Light-duty", "Medium", "Oversize", "Huge", "Other" 
	BYTE                byVehicleLenth;                 // car length, m
	BYTE                byReserved1[3];                 // reserved
	int                 nOverSpeedMargin;               // over speed margin, km/h 
	int                 nUnderSpeedMargin;              // under speed margin, km/h 
	char                szDrivingDirection[3][DH_MAX_DRIVINGDIRECTION]; //
                                                      	// "DrivingDirection" : ["Approach", "Shanghai", "Hangzhou"],
	                                                  	// "Approach" means driving direction,where the car is more near;"Leave"-means where if mor far to the car
	                                                  	// the second and third param means the location of the driving direction
	char                szMachineName[256];             // machine name
	char                szMachineAddress[256];          // machine address
	char                szMachineGroup[256];            // machine group
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	DH_SIG_CARWAY_INFO_EX stuSigInfo;                   // The vehicle detector generates the snap signal redundancy info
	char                szFilePath[MAX_PATH];           // File path
	BYTE				bReserved[3704];				// Reserved field for future extension
} DEV_EVENT_TRAFFICGATE_INFO;

//the describe of EVENT_TRAFFICSNAPSHOT's data
typedef struct tagDEV_EVENT_TRAFFICSNAPSHOT_INFO 
{
	int					nChannelID;						// ChannelId
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	BYTE                bReserv[3];                       // reserved 
	BYTE                bCarWayCount;                     // car way number being snapshotting
	DH_CARWAY_INFO      stuCarWayInfo[DH_MAX_CARWAY_NUM]; // car way info being snapshotting
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[340];		    		// Reserved 
} DEV_EVENT_TRAFFICSNAPSHOT_INFO;

//the describe of EVENT_IVS_TRAFFIC_RUNREDLIGHT's data
typedef struct tagDEV_EVENT_TRAFFIC_RUNREDLIGHT_INFO
{
	int					nChannelID;						  // channel ID
	char				szName[128];					  // event name
	double				PTS;							  // PTS(ms)
	NET_TIME_EX			UTC;				              // the event happen time
	int					nEventID;			              // event ID
	int					nLane;				              // Corresponding Lane number
	DH_MSG_OBJECT		stuObject;	              	      // have being detected object
	DH_MSG_OBJECT       stuVehicle;                       // vehicle info
	DH_EVENT_FILE_INFO  stuFileInfo;                      // event file info
	int					nLightState;	              	  // state of traffic light 0:unknown 1:green 2:red 3:yellow
	int					nSpeed;			              	  // speed,km/h
	int                 nSequence;                        // snap index,such as 3,2,1,1 means the last one,0 means there has some exception and snap stop
	BYTE                bEventAction;					  // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;					  // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[1016];	              // Reserved
	DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;       // Traffic vehicle info
} DEV_EVENT_TRAFFIC_RUNREDLIGHT_INFO;

//the describe of EVENT_IVS_TRAFFIC_OVERLINE's data
typedef struct tagDEV_EVENT_TRAFFIC_OVERLINE_INFO
{
	int					nChannelID;			// channel ID
	char				szName[128];		// event name
	double				PTS;				// PTS(ms)
	NET_TIME_EX			UTC;				// the event happen time
	int					nEventID;			// event ID
	int					nLane;				// Corresponding Lane number
	DH_MSG_OBJECT		stuObject;			// have being detected object
	DH_MSG_OBJECT       stuVehicle;         // vehicle info
	DH_EVENT_FILE_INFO  stuFileInfo;        // event file info
	int                 nSequence;          // snap index,such as 3,2,1,1 means the last one,0 means there has some exception and snap stop
	int                 nSpeed;             // speed,km/h
	BYTE                bEventAction;		// Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;	    // flag(by bit),see NET_RESERVED_COMMON
	
	BYTE				bReserved[1008];	// Reserved 
	DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;       // Traffic vehicle info
} DEV_EVENT_TRAFFIC_OVERLINE_INFO;


//the describe of EVENT_IVS_TRAFFIC_RETROGRADE's data
typedef struct tagDEV_EVENT_TRAFFIC_RETROGRADE_INFO
{
	int					nChannelID;			// channel ID
	char				szName[128];		// event name
	double				PTS;				// PTS(ms)
	NET_TIME_EX			UTC;				// the event happen time
	int					nEventID;			// event ID
	int					nLane;				// Corresponding Lane number
	DH_MSG_OBJECT		stuObject;			// have being detected object
	DH_MSG_OBJECT       stuVehicle;         // vehicle info
	DH_EVENT_FILE_INFO  stuFileInfo;        // event file info
	int                 nSequence;          // snap index: such as 3,2,1,1 means the last one,0 means there has some exception and snap stop
	int                 nSpeed;             // speed, km/h
	BYTE                bEventAction;		// Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;	     // flag(by bit),see NET_RESERVED_COMMON

	BYTE				bReserved[1008];	 //  Reserved
	DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;    // Traffic vehicle info
} DEV_EVENT_TRAFFIC_RETROGRADE_INFO;

//the describe of EVENT_IVS_TRAFFIC_TURNLEFT's data
typedef struct tagDEV_EVENT_TRAFFIC_TURNLEFT_INFO
{
	int					nChannelID;			// channel ID
	char				szName[128];		// event name
	double				PTS;				// PTS(ms)
	NET_TIME_EX			UTC;				// the event happen time
	int					nEventID;			// event ID
	int					nLane;				// Corresponding Lane number
	DH_MSG_OBJECT		stuObject;			// have being detected object
	DH_MSG_OBJECT       stuVehicle;         // vehicle info
	DH_EVENT_FILE_INFO  stuFileInfo;        // event file info
	int                 nSequence;          // snap index: such as 3,2,1,1 means the last one,0 means there has some exception and snap stop
	int                 nSpeed;             // speed,km/h
	BYTE                bEventAction;		// Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;	    // flag(by bit),see NET_RESERVED_COMMON

	BYTE				bReserved[1008];	// Reserved 
	DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;     // Traffic vehicle info
} DEV_EVENT_TRAFFIC_TURNLEFT_INFO;


//the describe of EVENT_IVS_TRAFFIC_TURNRIGHT's data
typedef struct tagDEV_EVENT_TRAFFIC_TURNRIGHT_INFO
{
	int					nChannelID;			// channel ID
	char				szName[128];		// event name
	double				PTS;				// PTS(ms)
	NET_TIME_EX			UTC;				// the event happen time
	int					nEventID;			// event ID
	int					nLane;				// Corresponding Lane number
	DH_MSG_OBJECT		stuObject;			// have being detected object
	DH_MSG_OBJECT       stuVehicle;         // vehicle info
	DH_EVENT_FILE_INFO  stuFileInfo;        // event file info
	int                 nSequence;          // snap index: such as 3,2,1,1 means the last one,0 means there has some exception and snap stop
	int                 nSpeed;             // speed,km/h
	BYTE                bEventAction;		// Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;	    // flag(by bit),see NET_RESERVED_COMMON

	BYTE				bReserved[1008];	// Reserved 
	DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;     // Traffic vehicle info
} DEV_EVENT_TRAFFIC_TURNRIGHT_INFO;

//the describe of EVENT_IVS_TRAFFIC_UTURN's data
typedef struct tagDEV_EVENT_TRAFFIC_UTURN_INFO 
{
	int					nChannelID;						  // channel ID
	char				szName[128];					  // event name
	double				PTS;							  // PTS(ms)
	NET_TIME_EX			UTC;						   	  // the event happen time
	int					nEventID;					      // event ID
	int					nLane;							  // Corresponding Lane number
	DH_MSG_OBJECT		stuObject;						  // have being detected object
	DH_MSG_OBJECT       stuVehicle;                       // vehicle info
	DH_EVENT_FILE_INFO  stuFileInfo;					  // event file info
	int                 nSequence;                        // snap index: such as 3,2,1,1 means the last one,0 means there has some exception and snap stop
	int                 nSpeed;             			  // speed,km/h
	BYTE                bEventAction;		              // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;	                  // flag(by bit),see NET_RESERVED_COMMON
	
	BYTE                bReserved[1008];				  // Reserved 
	DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;       // Traffic vehicle info
}DEV_EVENT_TRAFFIC_UTURN_INFO;

//the describe of EVENT_IVS_TRAFFIC_OVERSPEED's data
typedef struct tagDEV_EVENT_TRAFFIC_OVERSPEED_INFO 
{
	int					nChannelID;						  // channel ID
	char				szName[128];					  // event name
	double				PTS;							  // PTS(ms)
	NET_TIME_EX			UTC;						   	  // the event happen time
	int					nEventID;					      // event ID
	int					nLane;							  // Corresponding Lane number
	DH_MSG_OBJECT		stuObject;						  // have being detected object
	DH_MSG_OBJECT       stuVehicle;                       // vehicle info
	DH_EVENT_FILE_INFO  stuFileInfo;					  // event file info
    int                 nSpeed;                           // vehicle speed Unit:Km/h
	int					nSpeedUpperLimit;			      // Speed Up limit Unit:km/h
	int					nSpeedLowerLimit;				  // Speed Low limit Unit:km/h 
	int                 nSequence;                        // snap index:such as 3,2,1,1 means the last one,0 means there has some exception and snap stop
	BYTE                bEventAction;		              // Event action,0 means pulse event,1 means continuous event's begin,2 means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;	                  // flag(by bit),see NET_RESERVED_COMMON

	BYTE                bReserved[1012];				  // Reserved 
	DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;       // Traffic vehicle info
}DEV_EVENT_TRAFFIC_OVERSPEED_INFO;

//the describe of EVENT_IVS_TRAFFIC_UNDERSPEED's data
typedef struct tagDEV_EVENT_TRAFFIC_UNDERSPEED_INFO 
{
	int					nChannelID;						  // channel ID
	char				szName[128];					  // event name
	double				PTS;							  // PTS(ms)
	NET_TIME_EX			UTC;						   	  // the event happen time
	int					nEventID;					      // event ID
	int					nLane;							  // Corresponding Lane number
	DH_MSG_OBJECT		stuObject;						  // have being detected object
	DH_MSG_OBJECT       stuVehicle;                       // vehicle info
	DH_EVENT_FILE_INFO  stuFileInfo;					  // event file info
    int                 nSpeed;                           // vehicle speed Unit:Km/h
	int					nSpeedUpperLimit;			      // Speed Up limit Unit:km/h
	int					nSpeedLowerLimit;				  // Speed Low limit Unit:km/h 
	int                 nSequence;                        // snap index: such as 3,2,1,1 means the last one,0 means there has some exception and snap stop
	BYTE                bEventAction;		              // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
    BYTE                bReserved1[3];                    // reserved
	int                 nUnderSpeedingPercentage;         // under speed percentage
    DWORD               dwSnapFlagMask;	                  // flag(by bit),see NET_RESERVED_COMMON
	
	BYTE                bReserved[1008];				  // Reserved 
	DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;       // Traffic vehicle info
}DEV_EVENT_TRAFFIC_UNDERSPEED_INFO;

//the describe of EVENT_IVS_FACEDETECT's data
typedef struct tagDEV_EVENT_FACEDETECT_INFO 
{
	int					nChannelID;						  // channel ID
	char				szName[128];					  // event name
	double				PTS;							  // PTS(ms)
	NET_TIME_EX			UTC;						   	  // the event happen time
	int					nEventID;					      // event ID
	DH_MSG_OBJECT		stuObject;						  // have being detected object
	DH_EVENT_FILE_INFO  stuFileInfo;					  // event file info
	BYTE                bEventAction;                     // Event action: 0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                reserved[3];                      // reserved
	int                 nDetectRegionNum;				  // detect region point number
	DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // detect region
    DWORD               dwSnapFlagMask;	                  // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[932];					  // Reserved 
} DEV_EVENT_FACEDETECT_INFO;

// the describe of EVENT_IVS_TRAFFICJAM's data
typedef struct tagDEV_EVENT_TRAFFICJAM_INFO 
{
	int					nChannelID;						// channel ID
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	int					nLane;							// Corresponding Lane number
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info              
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                reserved[3];                    // reserved
	NET_TIME_EX         stuStartJamTime;				// the time of starting jam 
	int                 nSequence;                      // snap index: such as 3,2,1,1 means the last one,0 means there has some exception and snap stop(this param work when bEventAction=2) 
	int                 nAlarmIntervalTime;             // interval time of alarm(s)?¡ê(this is a continuous event,if the interval time of recieving next event go beyond this parm, we can judge that this event is over with exception)
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[1012];				// Reserved 
	DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;     // Traffic vehicle info	
} DEV_EVENT_TRAFFICJAM_INFO;

// the describe of EVENT_IVS_TRAFFIC_PARKING's data
typedef struct tagDEV_EVENT_TRAFFIC_PARKING_INFO 
{
	int					nChannelID;						// channel ID
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	DH_MSG_OBJECT       stuVehicle;                     // vehicle info
	int					nLane;							// Corresponding Lane number
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info               
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                reserved[3];                    // reserved
	NET_TIME_EX         stuStartParkingTime;            // the time of starting parking
	int                 nSequence;                      // snap index: such as 3,2,1,1 means the last one,0 means there has some exception and snap stop(this param work when bEventAction=2) 
	int                 nAlarmIntervalTime;             // interval time of alarm(s) (this is a continuous event,if the interval time of recieving next event go beyond this parm, we can judge that this event is over with exception)
	int                 nParkingAllowedTime;            // the time of legal parking
	int                 nDetectRegionNum;				// detect region point number
	DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // detect region point number
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[924];				    // Reserved 
	DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;     // Traffic vehicle info
} DEV_EVENT_TRAFFIC_PARKING_INFO;

//the describe of EVENT_IVS_TRAFFIC_WRONGROUTE's data
typedef struct tagDEV_EVENT_TRAFFIC_WRONGROUTE_INFO 
{
	int					nChannelID;						// channel ID
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	DH_MSG_OBJECT       stuVehicle;                     // vehicle info
	int					nLane;							// Corresponding Lane number
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info               
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];           
	int                 nSpeed;                         // speed,km/h
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[1012];				// Reserved 
	DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;     // Traffic vehicle info
	
} DEV_EVENT_TRAFFIC_WRONGROUTE_INFO;

//the describe of EVENT_IVS_TRAFFIC_CROSSLANE's data
typedef struct tagDEV_EVENT_TRAFFIC_CROSSLANE_INFO 
{
	int					nChannelID;						// channel ID
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	DH_MSG_OBJECT       stuVehicle;                     // vehicle info
	int					nLane;							// Corresponding Lane number
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info                 
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];           
	int                 nSpeed;                         // speed,km/h
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[1012];				// Reserved 
	
} DEV_EVENT_TRAFFIC_CROSSLANE_INFO;

//the describe of EVENT_IVS_TRAFFIC_OVERYELLOWLINE's data
typedef struct tagDEV_EVENT_TRAFFIC_OVERYELLOWLINE_INFO 
{
	int					nChannelID;						// channel ID
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	DH_MSG_OBJECT       stuVehicle;                     // vehicle info
	int					nLane;							// Corresponding Lane number
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info                 
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];           
	int                 nSpeed;                         // speed,km/h
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[1012];				// Reserved 
	DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;     // Traffic vehicle info
	
} DEV_EVENT_TRAFFIC_OVERYELLOWLINE_INFO;

//the describe of EVENT_IVS_TRAFFIC_DRIVINGONSHOULDER's data
typedef struct tagDEV_EVENT_TRAFFIC_DRIVINGONSHOULDER_INFO
{
	int					nChannelID;						// channel ID
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	DH_MSG_OBJECT       stuVehicle;                     // vehicle info
	int					nLane;							// Corresponding Lane number
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info                                
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];           
	int                 nSpeed;                         // speed,km/h
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[1012];				//  
	
} DEV_EVENT_TRAFFIC_DRIVINGONSHOULDER_INFO;

//the describe of EVENT_IVS_TRAFFIC_YELLOWPLATEINLANE's data
typedef struct tagDEV_EVENT_TRAFFIC_YELLOWPLATEINLANE_INFO
{
	int					nChannelID;						// channel ID
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// have being detected object
	DH_MSG_OBJECT       stuVehicle;                     // vehicle info
	int					nLane;							// Corresponding Lane number
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info                                               
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];           
	int                 nSpeed;                         // speed,km/h
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[1020];				// Reserved 
	DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;     // Traffic vehicle info
	
} DEV_EVENT_TRAFFIC_YELLOWPLATEINLANE_INFO;


//the describe of EVENT_IVS_TRAFFIC_NOPASSING's data
typedef struct tagDEV_EVENT_TRAFFIC_NOPASSING_INFO
{
	int					nChannelID;						// channel ID
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	int                 UTCMS;                          // 
	int                 nMark;                          // 
	int                 nSequence;                      // snap index: such as 3,2,1,1 means the last one,0 means there has some exception and snap stop
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info  
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO   stTrafficCar;   // TrafficCar info
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[1020];				// Reserved 
}DEV_EVENT_TRAFFIC_NOPASSING_INFO;
typedef struct tagDH_TRAFFICFLOWSTAT
{
	char				szMachineAddress[256];			// same as DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO.MachineGroup
	char				szMachineName[256];				// same as DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO.MachineName
	char				szDrivingDirection[3][32];		// DrivingDirection "Approach" means driving direction,where the car is more near;"Leave"-means where if mor far to the car,the scend and third param means the location of the driving direction
	int					nLane;							// lane number
	NET_TIME_EX			UTC;							// Statistic time
	int					nPeriod;						// Statistic period, m
	int					nVehicles;						// passed vehicle number
	float				fAverageSpeed;					// average speed, km/h
	float				fAverageLength;					// average length, m
	float				fTimeOccupyRatio;				// time occupy ratio,
	float				fSpaceOccupyRatio;				// space occupy ratio,
	float				fSpaceHeadway;					// space between two cars,m
	float				fTimeHeadway;					// time between two cars, s
	float				fDensity;						// car density, every km
	int					nOverSpeedVehicles;				// over speed vehicle number
	int					nUnderSpeedVehicles;			// under speed vehicle number
	int					nLargeVehicles;					// big car number  
	int					nMediumVehicles;				// mid car number
	int					nSmallVehicles;					// small car number
	int					nMotoVehicles;					// moto car number
	int					nLongVehicles;					// long vehicle number
}DH_TRAFFICFLOWSTAT;
// the describe of EVENT_IVS_TRAFFIC_FLOWSTATE's data
typedef struct tagDEV_EVENT_TRAFFIC_FLOWSTAT_INFO
{
	char				szName[128];					// name
	double				PTS;							// time stamp(ms)
	NET_TIME_EX			UTC;							// occurrence time
	int					nEventID;						// event id
	int					nLaneCnt;						// channel number
	DH_TRAFFICFLOWSTAT	stTrafficFlowStats[DH_MAX_LANE_NUM];//traffic flow state info
}DEV_EVENT_TRAFFIC_FLOWSTAT_INFO;

//the describe of EVENT_IVS_TRAFFIC_MANUALSNAP's data
typedef struct tagDEV_EVENT_TRAFFIC_MANUALSNAP_INFO
{
	int					nChannelID;						// channel ID
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	int					nLane;							// lane number
	BYTE                szManualSnapNo[64];             // manual snap number 
	DH_MSG_OBJECT		stuObject;						// have being detected object
	DH_MSG_OBJECT       stuVehicle;                     // have being detected vehicle
	DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO   stTrafficCar;   // TrafficCar info
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE				bReserved[1016];				// 
}DEV_EVENT_TRAFFIC_MANUALSNAP_INFO;

//the describe of EVENT_IVS_TRAFFIC_STAY's data
typedef struct tagDEV_EVENT_TRAFFIC_STAY_INFO
{
	int					nChannelID;						// channel id
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// object info
	DH_MSG_OBJECT       stuVehicle;                     // vehicle info
	int					nLane;							// lane number
	int					nSequence;						// snap index
	DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO   stTrafficCar;   // TrafficCar info
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info  
	BYTE                bEventAction; 					// Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved0[3];
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE                byReserved[1016];           
}DEV_EVENT_TRAFFIC_STAY_INFO;

//the describe of EVENT_IVS_TRAFFIC_VEHICLEINROUTE's data
typedef struct tagDEV_EVENT_TRAFFIC_VEHICLEINROUTE_INFO
{
	int					nChannelID;						// channel id
	char				szName[128];					// event name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// event ID
	DH_MSG_OBJECT		stuObject;						// object info
	DH_MSG_OBJECT       stuVehicle;                     // vehicle info
	int					nLane;							// lane number
	int					nSequence;						// snap index
	int					nSpeed;							// speed
	DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO   stTrafficCar;   // TrafficCar info
	DH_EVENT_FILE_INFO  stuFileInfo;                    // event file info            
	BYTE                bEventAction;                   // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved0[3];
    DWORD               dwSnapFlagMask;	                // flag(by bit),see NET_RESERVED_COMMON
	BYTE                byReserved[1016];           
}DEV_EVENT_TRAFFIC_VEHICLEINROUTE_INFO;

// the describe of EVENT_ALARM_LOCALALARM and EVENT_ALARM_MOTIONALARM's data
typedef struct tagDEV_EVENT_ALARM_INFO
{
	int					nChannelID;						// channel id
	char				szName[128];					// evnent name
	double				PTS;							// PTS(ms)
	NET_TIME_EX			UTC;							// the event happen time
	int					nEventID;						// evnet ID                                                                                                                                                                                                                                                                    
}DEV_EVENT_ALARM_INFO;

// the describe of  EVENT_IVS_PRISONERRISEDETECTION's data
typedef struct tagDEV_EVENT_PRISONERRISEDETECTION_INFO
{
	int					nChannelID;						  // channel id
	char				szName[128];					  // evnent name
	double				PTS;							  // PTS(ms)
	NET_TIME_EX			UTC;						   	  // he event happen time
	int					nEventID;					      // evnet ID           
	DH_MSG_OBJECT		stuObject;						  // object info
	int                 nDetectRegionNum;				  // region point number
	DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // region
	DH_EVENT_FILE_INFO  stuFileInfo;                      // event file info
	double				dInitialUTC;			  		  // UTC init time
	BYTE                bEventAction;                     // Event action,0 means pulse event,1 means continuous event's begin,2means continuous event's end;
	BYTE                byReserved[3];
    DWORD               dwSnapFlagMask;	                  // flag(by bit),see NET_RESERVED_COMMON

	BYTE				bReserved[1016];				  // Reserved 
}DEV_EVENT_PRISONERRISEDETECTION_INFO;

//Event type  EVENT_IVS_TRAFFIC_PEDESTRAINPRIORITY(Pedestal has higher priority at the  crosswalk) corresponding data block description info
typedef struct tagDEV_EVENT_TRAFFIC_PEDESTRAINPRIORITY_INFO
{
	int                 nChannelID;                       // Channel No.
	char                szName[128];                      // Event name
	double              PTS;                              // Time stamp(ms)
	NET_TIME_EX         UTC;                              // Event occurred time
	int                 nEventID;                         // Event ID
	DH_MSG_OBJECT       stuObject;                        // Detected object
	DH_MSG_OBJECT       stuVehicle;                       // Vehicle body info
	DH_EVENT_FILE_INFO  stuFileInfo;                      // The corresponding file info of the event
	int                 nLane;                            // Corresponding lane No.
	double				dInitialUTC;			  		  // Event initial UTC time 	UTC is the second of the event UTC (1970-1-1 00:00:00)
	BYTE                bEventAction;                     // Event operation.0=pulse event,1=begin of the durative event,2=end of the durative event;
	BYTE                byReserved[3];
	DWORD               dwSnapFlagMask;                   // Snap flag(by bit),please refer to NET_RESERVED_COMMON		
	DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO   stTrafficCar;     // The record of the database of the traffic vehicle 
	BYTE                bReserved[1024];                  // Reserved field for future extension.
}DEV_EVENT_TRAFFIC_PEDESTRAINPRIORITY_INFO;

// Media file search criteria
typedef enum __EM_FILE_QUERY_TYPE
{
	DH_FILE_QUERY_TRAFFICCAR,							// Vehicle information 
	DH_FILE_QUERY_ATM,									// ATM information
	DH_FILE_QUERY_ATMTXN,								// ATM transaction information 
	DH_FILE_QUERY_FACE,  								// Face info
} EM_FILE_QUERY_TYPE;

//The corresponding search criteria of  DH_MEDIA_QUERY_TRAFFICCAR
typedef struct  
{
	int					nChannelID;						// The channel number begins with 0. -1 is to search information of all channels .
	NET_TIME			StartTime;						// Start time 	
	NET_TIME			EndTime;						// End time 
	int					nMediaType;						// File type:0=search any type.1=search jpg file
	int					nEventType;						// Event type,please refer to Intelligent Analytics Event Type. 0 means search any event. 
	char				szPlateNumber[32];				// Vehicle plate. "\0" is to search any plate number.
	int					nSpeedUpperLimit;				// The searched vehicle speed range. Max speed unit is km/h
	int					nSpeedLowerLimit;				// The searched vehicle speed range. Min speed unit is km/h
	BOOL				bSpeedLimit;					// Search according to the speed or not.  TRUE: search according to the speed.nSpeedUpperLimit and nSpeedLowerLimit is valid.
    DWORD				dwBreakingRule;					// Illegal type:
														// When event type is EVENT_IVS_TRAFFICGATE
														//		bit1: Retrograde;   bit2: Overline; 
														//		bit3: Overspend; 	bit4:Under speed; 
														//		bit5: RunRedLight;
														// When event type is EVENT_IVS_TRAFFICJUNCTION
														//		bit1: RunRedLight;  bit2: WrongLan;  
														//		bit3: Retrograde; 	bit4:UTurn;
														//	    bit5: Overline;
	char                szPlateType[32];                // plate type,"Unknown" ,"Normal" ,"Yellow" ,"DoubleYellow" ,"Police" "Armed" 
	char                szPlateColor[16];               // plate color, "Blue","Yellow", "White","Black"
	char				szVehicleColor[16];		        // vehicle color:"White", "Black", "Red", "Yellow", "Gray", "Blue","Green"
	char				szVehicleSize[16];		        // vehicle type:"Light-duty";"Medium"; "Oversize"
	int                 nGroupID;                       // id of event group(it works when >= 0)
	short               byLane;                         // lane number(it works when >= 0)
	BYTE				byFileFlag;						// file flag, 0xFF-use nFileFlagEx, 0-all record, 1-timing file, 2-manual, 3-event, 4-important, 5-mosaic
	BYTE				reserved;
	int					nFileFlagEx;					// file flag, bit0-timing, bit1-manual, bit2-event, bit3-important, bit4-mosaic, 0xFFFFFFFF-all
	int					nDirection;				        // lane direction 	0-north 1-northeast 2-east 3-southeast 4-south 5-southwest 6-west 7-northwest 8-unknown -1-all directions
	int					bReserved[38];					// Reserved field for future extension.
} MEDIA_QUERY_TRAFFICCAR_PARAM;


// The media file information searched by DH_MEDIA_QUERY_TRAFFICCAR
typedef struct
{
    unsigned int		ch;						// Channel number
    char				szFilePath[128];		// File path 
    unsigned int		size;					// File length 
    NET_TIME			starttime;				// Start time
    NET_TIME			endtime;				// End time
    unsigned int		nWorkDirSN;				// Working directory serial number									
	BYTE				nFileType;				// File type.  1:jpg file
	BYTE                bHint;					// File location index
	BYTE                bDriveNo;               // drive number
	BYTE                bReserved2;
	unsigned int        nCluster;               // cluster number
	BYTE				byPictureType;			// flags
	BYTE                bReserved[3];           // Reserved field for future extension. 

	//The following contents is the vehicle information 
	char				szPlateNumber[32];		// Vehicle plate number
	char				szPlateType[32];		// Plate type: "Unknown" =Unknown; "Normal"=Blue and black plate. "Yellow"=Yellow plate. "DoubleYellow"=Double-layer yellow plate 
												// "Police"=Police plate ; "Armed"= =Military police plate; "Military"=Army plate; "DoubleMilitary"=Army double-layer 
												// "SAR" =HK SAR or Macao SAR plate; "Trainning" =rehearsal plate; "Personal"=Personal plate; "Agri"=Agricultural plate
												// "Embassy"=Embassy plate; "Moto"=Moto plate ; "Tractor"=Tractor plate; "Other"=Other plate 
	char				szPlateColor[16];		// Plate color:"Blue","Yellow", "White","Black"
	char				szVehicleColor[16];		// Vehicle color:"White", "Black", "Red", "Yellow", "Gray", "Blue","Green"
	int					nSpeed;					// Speed. The unit is Km/H
	int					nEventsNum;				// Activation event amount 
	int					nEvents[32];			// Activation event list. The number refers to the corresponding event. Please refer to Intelligent Analytics Event Type.		
	DWORD				dwBreakingRule;			// Detailed offense type subnet mask. The first bit means relight offense, the second bit is illegal straight/left-turn/right-turn driving. 
	                                            // The third bit is the wrong way driving; the four bit is illegal U-turn. Otherwise default value is intersection accident. 
	char				szVehicleSize[16];		// Vehicle type:"Light-duty"=small;"Medium"=medium; "Oversize"=large
	char				szChannelName[DH_CHAN_NAME_LEN];// Local or remote channel name
	char				szMachineName[DH_MAX_NAME_LEN];	// Local or remote device name
	int					nSpeedUpperLimit;	    // up limit of speed, km/h
	int					nSpeedLowerLimit;		// lower limit of speed km/h	
	int                 nGroupID;               // id of event group
	BYTE                byCountInGroup;         // total count of the event group
	BYTE                byIndexInGroup;         // the index of this event
	BYTE                byLane;                 // lane number
	BYTE                bReserved1[45];			// reserved
	int					nDirection;				// lane direction,according to MEDIA_QUERY_TRAFFICCAR_PARAM
	char                szMachineAddress[MAX_PATH]; // Machine address
} MEDIAFILE_TRAFFICCAR_INFO, *LPMEDIAFILE_TRAFFICCAR_INFO;

// FINDNEXT Find input parameter
typedef struct __NET_FINDNEXT_RESERVED
{
	DWORD               dwSize;                 // Structure size
	
	unsigned int        nBeginNumber;           // Search begin number, start from begin number, 0<=beginNumber<= totalCount-1
}NET_FINDNEXT_RESERVED;

// DH_FILE_QUERY_FACE Corresponding face recognition service search parameter
typedef struct __MEDIAFILE_FACERECOGNITION_PARAM
{
	DWORD               dwSize;                 // Structure size

	FACERECOGNITION_PERSON_INFO stPersion;      // Person info

	// Facial recognition match option
	unsigned int        nMatchImportant;        // Personnal importance level(1-10).The higher the value is, the important the person is.
	char                szMode[MAX_PATH];       // Face contrast mode, support:normal area(specified face area group). Auto (automatic combination of each part on face)
	char                szAreas[MAX_PATH];      // Support random combination of the following£ºEyebrow, Eye, Nose ,Mouth,Cheek.  Separate by "," such as "Eyebrow,	char                szAreas[MAX_PATH];      // Support random combination of the following£º Eyebrow ,Eye , Nose , Mouth , Cheek .Separate by ","£¬such as "Eyebrow,	char                szAreas[MAX_PATH];      // Support random combination of the following£º Eyebrow, Eye,Nose, Mouth, Cheek. Separate by ","£¬such as "Eyebrow,Eye"	
	unsigned int        nAccuracy;              // Recognition accuracy (1~10, as value increases, accuracy improves, speed decrease. Min value is 1 meaning speed is prior, max is 10 meaning accuracy has priority. Right now it is for facial recognition only
	unsigned int        nSimilarity;            // Similarity (report only when it is greater than the similarity; in percentage 1-100)
	unsigned int        nMaxCandidate;          // Max candidate amount  (rank by similarity, report candidate with max similarity)

	// Search filter criteria
    NET_TIME			stStartTime;			// Start time
    NET_TIME			stEndTime;				// End time
	char                szMachineAddress[MAX_PATH]; // Address. support fuzzy match
	char                szRange[MAX_PATH];      // "HistoryDB",history database "BlackListDB",blacklist database£»Use "," to separate such as "HistoryDB,BlackListDB"
	//  image binary data
	char              * pBuffer;                // buffer address
	int                 nBufferLen;             // buffer data length

	// output parameter
	unsigned int        nTotalCount;            // total matched results amount
}MEDIAFILE_FACERECOGNITION_PARAM;

// corresponding facial recognition service  DH_FILE_QUERY_FACE FINDNEXT search returned parameter
typedef struct __MEDIAFILE_FACERECOGNITION_INFO
{
	DWORD               dwSize;                 // Structure size
	
	FACERECOGNITION_PERSON_INFO pstPersion;    // person info sheet
	unsigned int        nSimilarity;            // Similarity, in percentage(1~100)
	char                szRange[MAX_PATH];      // "HistoryDB",history database "BlackListDB",blacklist database£»Use "," to separate such as "HistoryDB,BlackListDB"
	// Returned large image info
	char                szFilePath[MAX_PATH];   // file path

	// image binary data
	char              * pBuffer;                // buffer address
	int                 nBufferLen;             // buffer length
}MEDIAFILE_FACERECOGNITION_INFO; 
typedef struct __NET_FLASHCONTROL
{
	DWORD				dwSize;					// struct size
	int					nMode;					// work mode 0-no flash,1-always flash,2-auto flash
}NET_FLASHCONTROL;

// CLIENT_TrafficSnapByNetwork's input param
typedef struct __NET_IN_SNAPSHOT
{
	DWORD				dwSize;					// struct size
	int					nTriggerType;			// trigger type	0-unknown 1-zhongmeng net trigger
	int					nLaneID;				// lane id
	int					nGroupID;				// group id
	int					nGrabTimes;				// picture number
	int					nStartPicNum;			// the start picture id
	int					nDirection;				// road direction 0-north 1-east north 2-east 3-east south 4-south 5-west south 6-west 7-west north 8-unknown
	int					nGrabWaitTime;			// pGrabWaitTime group member number
	DWORD*				pGrabWaitTime;			// interval time between two picture
	int					nLowerSpeedLimit;		// lower speed limit, km/h
	int					nUpperSpeedLimit;		// upper speed limit, km/h
	int					nSpeed;					// speed, km/h
	int					nViolationNo;			// violation number 0-not transgress
												// 1-black shit
												// 2-over speed not over 50% 
												// 3-over speed between 50% and 100% 
												// 4-over speed over 100% 
												// 5-retrograde
												// 6-run red
												// 7-under speed
												// 8-no passing,wrong route
	int					nRedLightTime;			// red light time,s
	int					nFlashControl;			// pFlashControl group member number
	NET_FLASHCONTROL*   pFlashControl;			// flash control
	DWORD				dwUser;					// user data
}NET_IN_SNAPSHOT;

// CLIENT_TrafficSnapByNetwork's output param
typedef struct __NET_OUT_SNAPSHOT
{
	DWORD				dwSize;					// structure size
}NET_OUT_SNAPSHOT;


// CLIENT_StartTrafficFluxStat's callback function
typedef int  (CALLBACK *fFluxStatDataCallBack)(LLONG lFluxStatHandle, DWORD dwEventType, void* pEventInfo, BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser, int nSequence, void *reserved);

// CLIENT_StartTrafficFluxStat's input param
typedef struct __NET_IN_TRAFFICFLUXSTAT
{
	DWORD				dwSize;					// structure size
	fFluxStatDataCallBack		cbData;			// callback function pointer
	DWORD				dwUser;					// user data
}NET_IN_TRAFFICFLUXSTAT;

// CLIENT_StartTrafficFluxStat's output param
typedef struct __NET_OUT_TRAFFICFLUXSTAT
{
	DWORD				dwSize;					// structure size	
}NET_OUT_TRAFFICFLUXSTAT;

// CLIENT_StartFindFluxStat's input param
typedef struct __NET_IN_TRAFFICSTARTFINDSTAT
{
	DWORD				dwSize;					// structure size
	NET_TIME			stStartTime;			// start time, temporarily  
	NET_TIME			stEndTime;				// end time, temporarily 
	int					nWaittime;				// the time to wait result
}NET_IN_TRAFFICSTARTFINDSTAT;

// CLIENT_StartFindFluxStat's output param
typedef struct __NET_OUT_TRAFFICSTARTFINDSTAT
{
	DWORD				dwSize;					// structure size
	DWORD               dwTotalCount;           // The total amount that matched current search criteria                 
}NET_OUT_TRAFFICSTARTFINDSTAT;

// CLIENT_DoFindFluxStat's input param
typedef struct __NET_IN_TRAFFICDOFINDSTAT
{
	DWORD				dwSize;					// structure size
	unsigned int		nCount;					// the number of flow Statistic for query
	int					nWaittime;				// the time to wait result
}NET_IN_TRAFFICDOFINDSTAT;

typedef struct
{
	DWORD				dwSize;					// structure size

	int					nStatInfo;				// the number of statistic info
	DH_TRAFFICFLOWSTAT *pStatInfo;				// the statistic pointer
}DH_TRAFFICFLOWSTAT_OUT;

// CLIENT_DoFindFluxStat's out param
typedef struct __NET_OUT_TRAFFICDOFINDSTAT
{
	DWORD				dwSize;					// structure size
	
	DH_TRAFFICFLOWSTAT_OUT stStatInfo;			// the statistic pointer
}NET_OUT_TRAFFICDOFINDSTAT;

// interface(CLIENT_StartFindNumberStat)'s input param
typedef struct __NET_IN_FINDNUMBERSTAT
{
	DWORD				dwSize;					// size
	int                 nChannelID;             // channel ID
	NET_TIME			stStartTime;			// start time
	NET_TIME			stEndTime;				// end time
	int                 nGranularityType;       // granularity type, 0:minute,1:hour,2:day,3:week,4:month,5:quarter,6:year
	int					nWaittime;				// wait time
}NET_IN_FINDNUMBERSTAT;

// CLIENT_StartFindNumberStat's output param
typedef struct __NET_OUT_FINDNUMBERSTAT
{
	DWORD				dwSize;					 
	DWORD               dwTotalCount;           // total count
}NET_OUT_FINDNUMBERSTAT;

// CLIENT_DoFindNumberStat's input param
typedef struct __NET_IN_DOFINDNUMBERSTAT
{
	DWORD				dwSize;					 
	unsigned int        nBeginNumber;           // [0, totalCount-1]
	unsigned int		nCount;					// count
	int					nWaittime;				// wait time
}NET_IN_DOFINDNUMBERSTAT;

typedef struct __DH_NUMBERSTAT
{
	DWORD    dwSize;
	int      nChannelID;                           // channel id
	char     szRuleName[DH_CHAN_NAME_LEN];         // rule name
	NET_TIME stuStartTime;                         // start time
	NET_TIME stuEndTime;                           // end time
    int      nEnteredSubTotal;                     // entered total
	int      nExitedSubtotal;                      // entered total
    int      nAvgInside;                           // average number inside
	int      nMaxInside;                           // max number inside
}DH_NUMBERSTAT;

// CLIENT_DoFindNumberStat's ouput param
typedef struct __NET_OUT_DOFINDNUMBERSTAT
{
	DWORD				dwSize;					             
	int                 nCount;                              // count
	DH_NUMBERSTAT       *pstuNumberStat;                     // state array
    int                 nBufferLen;                          
}NET_OUT_DOFINDNUMBERSTAT;


// face recognition 

// face recognition param
typedef struct
{
	BYTE                 bySimilarity;                   // similarity,it will report when the similarity higher than this value(1~100)
	BYTE                 byAccuracy;                     // accuracy(1~10, the higher value,the higher accuracy,the lower speed?¡êwhen be valued 1 means speed first, when be valued 10 means accuracy first)
	BYTE                 byMode;                         // mode, 0-normal, 1-area compounding, 2-aptitude mode
	BYTE                 byAreaNum;                      // area number
	BYTE                 byAreas[8];                     // area compounding, 0-eyebrow,1-eye,2-nose,3-mouth,4-face(it work when mode = 1)
	WORD                 wMaxCandidate;                  // the max picture number that fixed
	BYTE                 byReserved[126];                // reserved
}FACERECOGNITION_OPTION_INFO;

///////////////////////////////// IVS server video analysis module /////////////////////////////////
// Video analysis  report result detect type definition
#define NET_DIAGNOSIS_DITHER                    "VideoDitherDetection"                       // Video vibration detect  Corresponding structure body(NET_VIDEO_DITHER_DETECTIONRESULT)
#define NET_DIAGNOSIS_STRIATION                 "VideoStriationDetection"                    // Video stria detect  Corresponding structure body(NET_VIDEO_STRIATION_DETECTIONRESULT)
#define NET_DIAGNOSIS_LOSS                      "VideoLossDetection"                         // Video loss detect  Corresponding structure body(NET_VIDEO_LOSS_DETECTIONRESULT)
#define NET_DIAGNOSIS_COVER                     "VideoCoverDetection"                        // Camera masking detect Corresponding structure body(NET_VIDEO_COVER_DETECTIONRESULT)
#define NET_DIAGNOSIS_FROZEN                    "VideoFrozenDetection"                       // Video freeze detect Corresponding structure body(NET_VIDEO_FROZEN_DETECTIONRESULT)
#define NET_DIAGNOSIS_BRIGHTNESS                "VideoBrightnessDetection"                   // Video brightness abnormal detect Corresponding structure body(NET_VIDEO_BRIGHTNESS_DETECTIONRESULT)
#define NET_DIAGNOSIS_CONTRAST                  "VideoContrastDetection"                     // Video contrast abnormal detect  Corresponding structure body(NET_VIDEO_CONTRAST_DETECTIONRESULT)
#define NET_DIAGNOSIS_UNBALANCE                 "VideoUnbalanceDetection"                    // Video color cast detect Corresponding structure body(NET_VIDEO_UNBALANCE_DETECTIONRESULT)
#define NET_DIAGNOSIS_NOISE                     "VideoNoiseDetection"                        // Video noise detect Corresponding structure body(NET_VIDEO_NOISE_DETECTIONRESULT)
#define NET_DIAGNOSIS_BLUR                      "VideoBlurDetection"                         // Video blur detect Corresponding structure body(NET_VIDEO_BLUR_DETECTIONRESULT)
#define NET_DIAGNOSIS_SCENECHANGE               "VideoSceneChangeDetection"                  // Video scene change detect Corresponding structure body(NET_VIDEO_SCENECHANGE_DETECTIONRESULT)

enum NET_STATE_TYPE
{
	NET_EM_STATE_ERR,        // Others
	NET_EM_STATE_NORMAL,     // "Normal"  
	NET_EM_STATE_WARNING,    // "Warning" 
	NET_EM_STATE_ABNORMAL,   // "Abnormal" 
};
// ¨º¨®?¦Ì??¨¢¡Â¨¤¨¤D¨ª
enum NET_STREAM_TYPE
{
	NET_EM_STREAM_ERR,                   // Others
	NET_EM_STREAM_MAIN,					// "Main"-Main stream
	NET_EM_STREAM_EXTRA_1,				// "Extra1"-Extra stream 1
	NET_EM_STREAM_EXTRA_2,				// "Extra2"-Extra stream 2
	NET_EM_STREAM_EXTRA_3,				// "Extra3"-Extra stream 3
	NET_EM_STREAM_SNAPSHOT,				// "Snapshot"-Snap bit stream
	NET_EM_STREAM_OBJECT,				// "Object"-Object stream
};

// General long character ended with '\0'
typedef struct tagNET_ARRAY
{
	DWORD                dwSize;                         // Current structure body size 
	char*                pArray;                         // Buffer zone. Now the min value is 260 byte¡ê?Caller shall apply for the memory. The filling in data shall ended with '\0'.
	DWORD                dwArrayLen;                     // Buffer space length
}NET_ARRAY;

// Video analysis result report general data
typedef struct tagNET_VIDEODIAGNOSIS_COMMON_INFO
{
	DWORD                dwSize;                         // Current structure body size 
	int                  nDiagnosisID;                   // Detect channel
	NET_ARRAY            stProject;                      // Project name
	NET_ARRAY            stTask;                         // Task name
	NET_ARRAY            stProfile;                      // Parameter list name
	NET_ARRAY            stDeviceID;                     // Device unique ID
	NET_TIME             stStartTime;                    // Start time
	NET_TIME             stEndTime;                      // End time
	int                  nVideoChannelID;                // Video channel No. The channel of the front-end device such as DVR,IPC.
	NET_STREAM_TYPE      emVideoStream;                  // Video bit stream
}NET_VIDEODIAGNOSIS_COMMON_INFO;

// The result of detect type (NET_DIAGNOSIS_DITHER)  Video vibration detect -- Video change,wind or vibration,rotation including the PTZ movement.
typedef struct tagNET_VIDEO_DITHER_DETECTIONRESULT
{
	DWORD                dwSize;                         // Current structure body size 
	int                  nValue;                         // Detect result value 
	NET_STATE_TYPE       emState;                        // Detect result status  Usually smaller than is normal. Larger than is abnormal and the value in the middle is warning. 
	int                  nDuration;                      // Status lasts time  Detect item last time. It is null right now. 
}NET_VIDEO_DITHER_DETECTIONRESULT;

// The result of detect type (NET_DIAGNOSIS_STRIATION) Video stria detect  -- There is abnormal stria on the camera resulting from the interference.
typedef struct tagNET_VIDEO_STRIATION_DETECTIONRESULT
{
	DWORD                dwSize;                         // Current structure body size 
	int                  nValue;                         // Detect result value 
	NET_STATE_TYPE       emState;                        // Detect result status
	int                  nDuration;                      // Status lasts time
}NET_VIDEO_STRIATION_DETECTIONRESULT;

// The result of detect type (NET_DIAGNOSIS_LOSS) Video loss detect  -- Result from power failure or disconnection.
typedef struct tagNET_VIDEO_LOSS_DETECTIONRESULT
{
	DWORD                dwSize;                         // Current structure body size 
	NET_STATE_TYPE       emState;                        // Detect result status
	int                  nDuration;                      // Status lasts time
}NET_VIDEO_LOSS_DETECTIONRESULT;

// The result of detect type (NET_DIAGNOSIS_COVER) Camera masking detect -- The camera masking occurred
typedef struct tagNET_VIDEO_COVER_DETECTIONRESULT
{
	DWORD                dwSize;                         // Current structure body size 
	int                  nValue;                         // Detect result value 
	NET_STATE_TYPE       emState;                        // Detect result status
	int                  nDuration;                      // Status lasts time
}NET_VIDEO_COVER_DETECTIONRESULT;

// The result of detect type (NET_DIAGNOSIS_FROZEN) Video freeze detect -- The video idles for specified time is regarded as freeze.
typedef struct tagNET_VIDEO_FROZEN_DETECTIONRESULT
{
	DWORD                dwSize;                         // Current structure body size 
	NET_STATE_TYPE       emState;                        // Detect result status
	int                  nDuration;                      // Status lasts time
}NET_VIDEO_FROZEN_DETECTIONRESULT;

// The result of detect type (NET_DIAGNOSIS_BRIGHTNESS) Video brightness abnormal detect --The following contents are some camera improper setup detect.
typedef struct tagNET_VIDEO_BRIGHTNESS_DETECTIONRESULT
{
	DWORD                dwSize;                         // Current structure body size 
	int                  nValue;                         // Detect result value 
	NET_STATE_TYPE       emState;                        // Detect result status
	int                  nDuration;                      // Status lasts time
}NET_VIDEO_BRIGHTNESS_DETECTIONRESULT;

// The result of detect type (NET_DIAGNOSIS_CONTRAST) Video contrast abnormal detect
typedef struct tagNET_VIDEO_CONTRAST_DETECTIONRESULT
{
	DWORD                dwSize;                         // Current structure body size 
	int                  nValue;                         // Detect result value 
	NET_STATE_TYPE       emState;                        // Detect result status
	int                  nDuration;                      // Status lasts time
}NET_VIDEO_CONTRAST_DETECTIONRESULT;

// The result of detect type (NET_DIAGNOSIS_UNBALANCE) Video color cast detect
typedef struct tagNET_VIDEO_UNBALANCE_DETECTIONRESULT
{
	DWORD                dwSize;                         // Current structure body size 
	int                  nValue;                         // Detect result value 
	NET_STATE_TYPE       emState;                        // Detect result status
	int                  nDuration;                      // Status lasts time
}NET_VIDEO_UNBALANCE_DETECTIONRESULT;

// The result of detect type (NET_DIAGNOSIS_NOISE) Video noise detect
typedef struct tagNET_VIDEO_NOISE_DETECTIONRESULT
{
	DWORD                dwSize;                         // Current structure body size 
	int                  nValue;                         // Detect result value 
	NET_STATE_TYPE       emState;                        // Detect result status
	int                  nDuration;                      // Status lasts time
}NET_VIDEO_NOISE_DETECTIONRESULT;

// The result of detect type (NET_DIAGNOSIS_BLUR) Video blur detect
typedef struct tagNET_VIDEO_BLUR_DETECTIONRESULT
{
	DWORD                dwSize;                         // Current structure body size 
	int                  nValue;                         // Detect result value 
	NET_STATE_TYPE       emState;                        // Detect result status
	int                  nDuration;                      // Status lasts time
}NET_VIDEO_BLUR_DETECTIONRESULT;

// The result of detect type (NET_DIAGNOSIS_SCENECHANGE) Video scene change detect
typedef struct tagNET_VIDEO_SCENECHANGE_DETECTIONRESULT
{
	DWORD                dwSize;                         // Current structure body size 
	int                  nValue;                         // Detect result value 
	NET_STATE_TYPE       emState;                        // Detect result status
	int                  nDuration;                      // Status lasts time
}NET_VIDEO_SCENECHANGE_DETECTIONRESULT;

typedef struct tagNET_DIAGNOSIS_RESULT_HEADER
{
	DWORD                dwSize;                         // Current structure body size 
	
	char                 szDiagnosisType[MAX_PATH];      // Analysis type. Please refer to dhnetsdk.h for "video analysis report result type definition"  such as NET_DIAGNOSIS_DITHER
	int                  nDiagnosisTypeLen;              // The structure body size of current analysis type
}NET_DIAGNOSIS_RESULT_HEADER;

// cbVideoDiagnosis Call parameter type
typedef struct tagNET_REAL_DIAGNOSIS_RESULT
{
	DWORD                dwSize;                         // Current structure body size 
	
    NET_VIDEODIAGNOSIS_COMMON_INFO* pstDiagnosisCommonInfo;  //Video analysisi general info
	
	int					 nTypeCount;					 // Analysis result data analysis type amount
	void*                pDiagnosisResult;               // The analysis result data for once. The format is as NET_DIAGNOSIS_RESULT_HEADER+analysis type1+NET_DIAGNOSIS_RESULT_HEADER+analysis type 2+...
	DWORD                dwBufSize;                      // Buffer length
}NET_REAL_DIAGNOSIS_RESULT;

// Video analysis result report call function
typedef int (CALLBACK *fRealVideoDiagnosis)(LLONG lDiagnosisHandle, NET_REAL_DIAGNOSIS_RESULT* pDiagnosisInfo, void* pBuf, int nBufLen, LDWORD dwUser);

//The input parameter of interface  CLIENT_StartVideoDiagnosis
typedef struct tagNET_IN_VIDEODIAGNOSIS
{
	DWORD                dwSize;                         // Current structure body size 
	int                  nDiagnosisID;                   // Video analysis ID begins with 0
	DWORD                dwWaitTime;                     // Interface time out waiting time
	
	fRealVideoDiagnosis  cbVideoDiagnosis;               // Video analysis result call function.
	LDWORD                dwUser;                         // User customized parameter
}NET_IN_VIDEODIAGNOSIS;

// The output parameter of interface CLIENT_StartVideoDiagnosis 
typedef struct tagNET_OUT_ATTACH_REALDIAGNOSIS
{
	DWORD                dwSize;                         // Current structure body size 
	LLONG                 lDiagnosisHandle;               // Subscribe handle
}NET_OUT_VIDEODIAGNOSIS;

// The input parameter of interface CLIENT_StartFindDiagnosisResult 
typedef struct tagNET_IN_FIND_DIAGNOSIS
{
	DWORD                dwSize;                         // Current structure body size 
	int                  nDiagnosisID;                   // Video analysis ID begins with 0
	DWORD                dwWaitTime;                     // Interface time out waiting time
	
	NET_ARRAY            stuDeviceID;                    // Device unique ID.pArray:NULL means does not search by device ID.
	NET_TIME             stuStartTime;                   // Start time
	NET_TIME             stuEndTime;                     // End time
	int                  nVideoChannel;                  // Video channel No.,-1: All channel No.
	int                  nTypeCount;                     // Analysis type amount.0:Do not use analysis type to search.
	NET_ARRAY*           pstDiagnosisTypes;              // Analysis type array. It is the analysis type to be searched. 
	char                 szProjectName[MAX_PATH];        // Project name
} NET_IN_FIND_DIAGNOSIS;

// The output parameter of interface CLIENT_StartFindDiagnosisResult
typedef struct tagNET_OUT_FIND_DIAGNOSIS
{
	DWORD                dwSize;                         // Current structure body size 
	LLONG                 lFindHandle;                    // Search handle
	DWORD                dwTotalCount;                   // The total amount that matched the criteria
}NET_OUT_FIND_DIAGNOSIS;

// The input parameter of interface CLIENT_DoFindDiagnosisResult 
typedef struct tagNET_IN_DIAGNOSIS_INFO
{
	DWORD                dwSize;                         // Current structure body size 
	int                  nDiagnosisID;                   // Video analysis ID begins with 0
	DWORD                dwWaitTime;                     // Interface time out waiting time
	
	int                  nFindCount;                     // The video analysis result amount of each search
	int                  nBeginNumber;                   // Search initial SN 0<=beginNumber<= totalCount-1
}NET_IN_DIAGNOSIS_INFO;

typedef struct tagNET_DEV_VIDEODIAGNOSIS_MULTI_INFO
{
	DWORD                dwSize;                         // Current structure body size 
	
    NET_VIDEODIAGNOSIS_COMMON_INFO*          pstDiagnosisCommonInfo;  //Video analysis general info. You need to allocate the following pointer of the structure body.
	
	BOOL                 abDither;						 // It is to stand for current analysis item is valid or not in this result.
	NET_VIDEO_DITHER_DETECTIONRESULT*        pstDither;  //  Video vibration detect
	
	BOOL                 abStration;
	NET_VIDEO_STRIATION_DETECTIONRESULT*     pstStration;// Video stria detect
	
	BOOL                 abLoss;
	NET_VIDEO_LOSS_DETECTIONRESULT*          pstLoss;    // Video loss detect 
	
	BOOL                 abCover;
	NET_VIDEO_COVER_DETECTIONRESULT*         pstCover;   // Camera masking detect
	
	BOOL                 abFrozen;
	NET_VIDEO_FROZEN_DETECTIONRESULT*        pstFrozen;  // Video freeze detect
	
	BOOL                 abBrightness;
	NET_VIDEO_BRIGHTNESS_DETECTIONRESULT*    pstBrightness;// Video brightness abnormal detect 
	
	BOOL                 abContrast;
	NET_VIDEO_CONTRAST_DETECTIONRESULT*      pstContrast;//Video contrast abnormal detect 
	
	BOOL                 abUnbalance;
	NET_VIDEO_UNBALANCE_DETECTIONRESULT*     pstUnbalance;//  Video color cast detect
	
	BOOL                 abNoise;
	NET_VIDEO_NOISE_DETECTIONRESULT*         pstNoise;   //Video noise detect 
	
	BOOL                 abBlur;
	NET_VIDEO_BLUR_DETECTIONRESULT*          pstBlur;    // Video blur detect
	
	BOOL                 abSceneChange;
	NET_VIDEO_SCENECHANGE_DETECTIONRESULT*   pstSceneChange;// Video scene change detect 
}NET_VIDEODIAGNOSIS_RESULT_INFO;

// The output parameter of interface CLIENT_DoFindDiagnosisResult
typedef struct tagNET_OUT_DIAGNOSIS_INFO
{
	DWORD                dwSize;                         // Current structure body size 
	
	int                  nInputNum;                      // The amount of the NET_DEV_RESULT_VIDEODIAGNOSIS_INFO you allocate
	int                  nReturnNum;                     // Returned amount
	NET_VIDEODIAGNOSIS_RESULT_INFO*  pstDiagnosisResult; // Result data You need to allocate the pointer of the structure body
}NET_OUT_DIAGNOSIS_INFO;

/////////////////////////////////CLIENT_OperateVideoAnalyseDevice Interface parameter /////////////////////////////////
#define     NET_SET_MODULESTATE                         "devVideoAnalyse.setModuleState"                        // Set module status
#define		NET_TEST_WITH_SCREENPOINTS					"devVideoAnalyse.testCalibrateWithScreenPoints"			// Detect depth of the field according to the coordinates on the screen. It is the actual distance between these two points. Please complete the parameter setup before you test.
#define		NET_TEST_WITH_METRICLENGTH					"devVideoAnalyse.testCalibrateWithMetricLength"		    // Detect parameter of depth of the field according to actual lenght,start point,and direction coordinates.
#define		NET_GET_INTERNALOPTIONS						"devVideoAnalyse.getInternalOptions"					// Get internal option
#define		NET_TUNE_INTERNALOPTIONS					"devVideoAnalyse.tuneInternalOptions"					// Debug internal item
#define		NET_RESET_INTERNALOPTIONS					"devVideoAnalyse.resetInternalOptions"					// Reset all debug internal item

// Line type
enum NET_EM_LINETYPE
{
	NET_EM_HORIZONTAL,
	NET_EM_VERTICAL,
};

// NET_TEST_WITH_SCREENPOINTS
typedef struct __NET_IN_CALIBRATE_BY_POINTS
{
	DWORD               dwSize;                 // Current structure body size 
	DH_POINT            stStartPoint;           // Start point of the line 	 The point of the line is within [0,8191].
	DH_POINT            stEndPoint;             // End point 	The point of the line is within [0,8191]
	NET_EM_LINETYPE     emType;                 // Line type	em_Horizontal("Horizontal")  em_Vertical("Vertical")
}NET_IN_CALIBRATE_BY_POINTS;

typedef struct __NET_OUT_CALIBRATE_BY_POINTS
{
	DWORD               dwSize;                 // Current structure body size 	
	double              dlength;                // The actual length between these two points. Unit is meter.
}NET_OUT_CALIBRATE_BY_POINTS;

// NET_TEST_WITH_METRICLENGTH
typedef struct __NET_IN_CALIBRATE_BY_LENGTH
{
	DWORD               dwSize;                 // Current structure body size 
	double				nLength;				// The actual length between these two points. Unit is meter.
	DH_POINT			stStartPoint;			// Start point of the line	The point of the line is within [0,8191]
	DH_POINT			stDirection;			// Line direction coordinates	For vertical line ony. The point of the line is within [0,8191]
	NET_EM_LINETYPE		emType;					// Line type	em_Horizontal("Horizontal")  em_Vertical("Vertical")				
}NET_IN_CALIBRATE_BY_LENGTH;

typedef struct __NET_OUT_CALIBRATE_BY_LENGTH
{
	DWORD               dwSize;                 // Current structure body size 
	DH_POINT			stEndPoint;				// Coordinates of the end of the line on the screen. 	The point of the line is within[0,8191]	
}NET_OUT_CALIBRATE_BY_LENGTH;

typedef struct __NET_INTERNAL_OPTION
{
	DWORD               dwSize;                 // Current structure body size 
	int					nIndex;					// Item SN
	NET_ARRAY           stKey;				    // Option name. 256 bytes including'\0'. Encryption data
	int					nValue;					// Option value
	int					nMinValue;				// Min value
	int					nMaxValue;				// Max value
}NET_INTERNAL_OPTION;

// Debug internal option NET_GET_INTERNALOPTIONS
typedef struct __NET_IN_GETINTERNAL_OPTIONS
{
	DWORD               dwSize;                 // Current structure body size
}NET_IN_GETINTERNAL_OPTIONS;

typedef struct __NET_OUT_GETINTERNAL_OPTIONS
{
	DWORD               dwSize;                 // Current structure body size 
	
	int					nTotalOptionNum;		// Option amount. Max value search capability.
	int					nReturnOptionNum;		// returned actual option amount.
	NET_INTERNAL_OPTION* pstInternalOption;	    // Option list. Caller shall allocate the address.
}NET_OUT_GETINTERNAL_OPTIONS;

// NET_TUNE_INTERNALOPTIONS
typedef struct __NET_IN_TUNEINTERNAL_OPTION
{
	DWORD               dwSize;                 // Current structure body size 
	int					nOptionCount;	    	// Option amount
	NET_INTERNAL_OPTION* pstInternalOption;	    // Option list. The amount stands for the capability.
}NET_IN_TUNEINTERNAL_OPTION;

typedef struct __NET_OUT_TUNEINTERNAL_OPTION
{
	DWORD               dwSize;                 // Current structure body size 
}NET_OUT_TUNEINTERNAL_OPTION;

// NET_RESET_INTERNALOPTIONS
typedef struct __NET_IN_RESETINTERNAL_OPTION
{
	DWORD               dwSize;                 // Current structure body size 
}NET_IN_RESETINTERNAL_OPTION;

typedef struct __NET_OUT_RESETINTERNAL_OPTION
{
	DWORD               dwSize;                 // Current structure body size 
}NET_OUT_RESETINTERNAL_OPTION;

// NET_SET_MODULESTATE
enum NET_EM_MODULESTATE
{
	NET_EM_MODULESTATE_OK,
	NET_EM_MODULESTATE_PAUSE,
};
typedef struct __NET_IN_SETMODULESTATE
{
	DWORD				dwSize;					// Current structure body size 
	NET_EM_MODULESTATE  emState;				// 0-Normal work.1-Pause. Need to rebuild background when you switch to the normal video since it may change.
	int                 nIndex;                 // Model SN.	-1 stands for all modules.
}NET_IN_SETMODULESTATE;

typedef struct __NET_OUT_SETMODULESTATE
{
	DWORD				dwSize;					// Current structure body size
}NET_OUT_SETMODULESTATE;

/////////////////////////////////CLIENT_DeleteDevConfig Interface parameter/////////////////////////////////
/*
 * CLIENT_DeleteDevConfig Input and output parameter
 */

enum NET_EM_CONFIGOPTION
{
	NET_EM_CONFIGOPTION_OK,
	NET_EM_CONFIGOPTION_NEEDRESTART,
	NET_EM_CONFIGOPTION_NEEDREBOOT=2,
	NET_EM_CONFIGOPTION_WRITEFILEERROR=4,
	NET_EM_CONFIGOPTION_CAPSNOTSUPPORT=8,
	NET_EM_CONFIGOPTION_VALIDATEFAILED=16,
};

typedef struct tagNET_IN_DELETECFG
{
	DWORD         dwSize;						// Structure body size
	char*         szCommand;                    // Configuration command
}NET_IN_DELETECFG;

typedef struct tagNET_OUT_DELETECFG
{
	DWORD         dwSize;                       // Structure body size
    int           nError;                       // The error code device returns
    int           nRestart;                     // Device reboot or not
	DWORD         dwOptionMask;                 // Option. Please refer to enumeration NET_EM_CONFIGOPTION
}NET_OUT_DELETECFG;

/////////////////////////////////CLIENT_GetMemberNames interface parameter/////////////////////////////////
/*
 * CLIENT_GetMemberNames Input and output parameter
 */
typedef struct tagNET_IN_MEMBERNAME
{
	DWORD         dwSize;                       // Structure body size
	char*         szCommand;                    // Configuration command
}NET_IN_MEMBERNAME;

typedef struct tagNET_OUT_MEMBERNAME
{
	DWORD         dwSize;                       // Structure body size 
	int           nError;                       // The error code device returns
    int           nRestart;                     // Device reboot or not	
	int           nTotalNameCount;              // Name amount. Fromt the capability set. Caller fill in.
	int           nRetNameCount;                // The returned actual name amount
	NET_ARRAY*    pstNames;                     // Name array. The caller apply for the memory. The amount is nTotalNameCount.
}NET_OUT_MEMBERNAME;

/////////////////////////////////Special version/////////////////////////////////

// Activate device to snapshot overlay card number information 
typedef struct __NET_SNAP_COMMANDINFO 
{
	char				szCardInfo[16];			// Card information
	char				reserved[64];			// Reserved 
} NET_SNAP_COMMANDINFO, LPNET_SNAP_COMMANDINFO;

typedef struct
{
	int					nChannelNum;			// Channel number 
	char				szUseType[32];			// Channel type 
	DWORD				dwStreamSize;			// Stream size(Unit:kb/s)
	char				reserved[32];			// Reserved 
} DHDEV_USE_CHANNEL_STATE;

typedef struct 
{
	char				szUserName[32];			// User name 
	char				szUserGroup[32];		// User group 
	NET_TIME			time;					// Log in time
	int					nOpenedChannelNum;		// Enabled channel amount 
	DHDEV_USE_CHANNEL_STATE	channelInfo[DH_MAX_CHANNUM];
	char                szIpAddress[DH_MAX_IPADDR_LEN];  // ip
	char				reserved[48];
} DHDEV_USER_NET_INFO;

// Network running status information 
typedef	struct 
{
	int					nUserCount;				// User amount
	DHDEV_USER_NET_INFO	stuUserInfo[32];
	char				reserved[256];
}DHDEV_TOTAL_NET_STATE;

typedef struct
{
    char                szIpAddress[DH_MAX_IPADDR_LEN];  // ip
	char                szUserGroup[32];                 // User Group
	char                szUserName[32];                  // User Name
	char                reserved[64];
}DHDEV_USER_REJECT_INFO;

// Reject User
typedef struct
{ 
	int                       nUserCount;				// User Account
	DHDEV_USER_REJECT_INFO    stuUserInfo[10];     
	char				      reserved[256];
}DHDEV_REJECT_USER;

typedef struct
{
	char                szIpAddress[DH_MAX_IPADDR_LEN];  // ip
	char                szUserGroup[32];                 // User Group
	char                szUserName[32];                  // User Name
	int                 nForbiddenTime;                  // Forbidden Time
	char                reserved[64];
}DHDEV_USER_SHIELD_INFO;

// Shield User
typedef struct
{ 
	int                       nUserCount;          // User Account
	DHDEV_USER_SHIELD_INFO    stuUserInfo[10];     
	char				      reserved[256];
}DHDEV_SHIELD_USER;

// longitude latitude
typedef struct
{//  longitude first,then latitude
	char                chPreLogi;        // preflag of longitude:N(north),S(south),W(west),E(east)
	char                chPreLati;        // preflag of latitude:N(north),S(south),W(west),E(east)
	BYTE                reserved[6];      // 
	double              dbLongitude;      // longitude
	double              dbLatitude;       // latitude
}DHDEV_LONGI_LATI;

// NAVIGATION OR SMS
typedef struct
{
	char                szPhoneNum[DH_MAX_PHONE_NO_LEN];    // phone no
	NET_TIME            stMsgTime;                          // time of sending message
	char                szMsgType[DH_MAX_MSGTYPE_LEN];      // type:Navigation message-Navigation,short message--SMS
	char                szSmsContext[DH_MAX_MSG_LEN];       // message to send

	DHDEV_LONGI_LATI    stLogiLati;                         // longitude
	unsigned int        uFlag;                              // 01:marking true longitude
	char                szNavigationType[16];               // TNC,TXZ
	char                szAddress[32];                      // address
	char                szNavigationMode[32];               // mode
	DHDEV_LONGI_LATI    stPassLogiLati[5];                  // passing
	DHDEV_LONGI_LATI    stNoPassLogiLati[5];                // no passing
	BYTE				reserved[256];
}DHDEV_NAVIGATION_SMSS;

// Image watermark setup 
typedef struct __DHDEV_WATERMAKE_CFG 
{
	DWORD				dwSize;
	int					nEnable;				// Enable 
	int					nStream;				// Bit stream(1~n)0- All bit streams
	int					nKey;					// Data type(1- text,2- image )
	char				szLetterData[DH_MAX_WATERMAKE_LETTER];	// text
	char				szData[DH_MAX_WATERMAKE_DATA]; // Image data
	BYTE				bReserved[512];			// Reserved
} DHDEV_WATERMAKE_CFG;

// Storage position set structure.  Each channel set separately.Each channel can set several storage types including local,portableand remote storage.
typedef struct 
{
	DWORD				dwSize;
	DWORD				dwLocalMask;			// Local storage mask. Use bit to represent.
												// The first bit:system pre-record. The second bit:scheduled record. The third bit:motion detection record.
												// The fourth bit:alarm record. The fifth bit:card record. The sixth bit:manual record.
	DWORD				dwMobileMask;			// Moving storage mask. Storage mask such as local storage mask.
	int					RemoteType;				// Remote storage type 0: Ftp  1: Smb 
	DWORD				dwRemoteMask;			// Remote storage mask.  Storage mask such as local storage mask.
	DWORD				dwRemoteSecondSelLocal;	// Local storage mask when remote is abnormal
	DWORD				dwRemoteSecondSelMobile;// Moving storage mask when remote is abnormal.
	char				SubRemotePath[MAX_PATH_STOR]; // Remote path. Its length is 240
	DWORD				dwFunctionMask;			// Function shield bit. Use bit to represent bit0 = 1:Shield sanpshot event activate storage position function.
	DWORD				dwAutoSyncMask;			// If synchronous mask; after remote storage network recovery, the local storage data will automatically synchronized to the remote storage.
	BYTE				bAutoSyncRange;			// the time for synchronous from the network synchronous time. In hour. 0:all data  1:data in one hour n:data in n hours
	char				reserved[119];
} DH_STORAGE_STATION_CFG;

#define MAX_ALARM_DECODER_NUM 16
typedef struct  
{
	DWORD				dwAlarmDecoder;			// Now it supports max 8 alarm input ports. Reserved 8 bits for future development.
	BYTE				bDecoderIndex;			// It means it is from which alarm decoder.
	BYTE				bReserved[3];
} ALARM_DECODER;

// Alarm decoder alarm 
typedef struct
{
	int					nAlarmDecoderNum;
	ALARM_DECODER		stuAlarmDecoder[MAX_ALARM_DECODER_NUM];
	BYTE				bReserved[32];
} ALARM_DECODER_ALARM;

//DSP alarm
typedef struct  
{
	BOOL				bError;			//0,DSP normal 1,DSP abnormal
	DWORD				dwErrorMask;	//Bit shows,Nor 0 shows havening this error,0 shows no.(Now alarm has only 1 bit valid)
										//bit		DSP alarm
										//1			DSP downloading failure 
										//2			DSP error
										//3			Format not correct 
										//4			Resolution not support
										//5			Data format not support
										//6			Can't find I frame
	DWORD               dwDecChnnelMask;//Bit shows,alarm decoding channel number,dwErrorMask is DSP fault,incorrect format,incorrect resolution,data format not support
	DWORD               dwDecChnnelMask1;//Bit shows, alarm decoding channel number for 33-64,dwErrorMask is DSP fault,incorrect format,incorrect resolution,data format not support
	BYTE				bReserved[24];
} DSP_ALARM;

// Fiber-optic alarm
typedef struct  
{
	int		nFDDINum;
	BYTE	bAlarm[256];
} ALARM_FDDI_ALARM;

#define ALARM_PTZ_LOCATION_INFO DH_PTZ_LOCATION_INFO

//PTZ location alarm 
typedef struct
{
	int     nChannelID;             // Channel Id 
	int     nPTZPan;                // PTZ pan location
	int     nPTZTilt;               // PTZ tilt location
	int     nPTZZoom;               // PTZ zoom
	BYTE    bState;                 // ptz state,0-unknown,1-moving,2-idle
	BYTE    bReserved[3];           // 
	int     reserved[255];          // 
}DH_PTZ_LOCATION_INFO;

// New audio detection alarm setup 
typedef struct
{
	BOOL				bEnable;				// Enable alarm input 
	int					Volume_min;				// Min volume
	int					Volume_max;				// Max volume
	char				reserved[128];	
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT];	
	DH_MSG_HANDLE		struHandle;				// Process way 
} DH_AUDIO_DETECT_INFO;

typedef struct  
{
	DWORD				dwSize;
	int					AlarmNum;
	DH_AUDIO_DETECT_INFO AudioDetectAlarm[DH_MAX_AUDIO_IN_NUM];
	char				reserved[256];
} DH_AUDIO_DETECT_CFG;

typedef struct
{
	BOOL				bTourEnable;			// Enable tour
	int					nTourPeriod;			// Tour interval. Unit is second. The value ranges from 5 to 300 
	DWORD				dwChannelMask;			// Tour channel. Use mas bit to represent.
	char				reserved[64];
}DH_VIDEOGROUP_CFG;

// Local matrix control strategy setup 
typedef struct
{
	DWORD				dwSize;
	int					nMatrixNum;				// Matrix amount(Read only )
	DH_VIDEOGROUP_CFG	struVideoGroup[DH_MATRIX_MAXOUT];
	char				reserved[32];
} DHDEV_VIDEO_MATRIX_CFG;   

// WEB path setup 
typedef struct 
{
	DWORD				dwSize;
	BOOL				bSnapEnable;					// Snapshot or not
	int					iSnapInterval;					// Snapshot interval
	char				szHostIp[DH_MAX_IPADDR_LEN];	// HTTP host IP
	WORD				wHostPort;
	int					iMsgInterval;					// Message sending out interval
	char				szUrlState[DH_MAX_URL_LEN];		// Status message upload URL
	char				szUrlImage[DH_MAX_URL_LEN];		// Image upload Url
	char				szDevId[DH_MAX_DEV_ID_LEN];		// Device web serial number
	BYTE				byReserved[2];
} DHDEV_URL_CFG;

// OEM search 
typedef struct  
{
	char				szVendor[DH_MAX_STRING_LEN];
	char				szType[DH_MAX_STRING_LEN];
	char				reserved[128];
} DHDEV_OEM_INFO;


//Video OSD
typedef struct 
{ 
	DWORD	rgbaFrontground;		// Object front view. Use bit to represent:red,green, blue and transparency.
	DWORD	rgbaBackground;			// Object background. Use bit to represent:red,green, blue and transparency
	RECT	rcRelativePos;			// Position. The proportion of border distance and whole length *8191
	BOOL	bPreviewBlend;			// Enable preview overlay	
	BOOL	bEncodeBlend;			// Enable encode overlay
	BYTE    bReserved[4];           // Reserved 
} DH_DVR_VIDEO_WIDGET;

typedef struct 
{
	DH_DVR_VIDEO_WIDGET	StOSD_POS; 								// OSD position and background color.
	char 				SzOSD_Name[DH_VIDEO_OSD_NAME_NUM]; 		// OSD name 
}DH_DVR_VIDEOITEM;
 
// OSD information in each channel
typedef struct 
{
	DWORD 				dwSize;
	DH_DVR_VIDEOITEM 	StOSDTitleOpt [DH_VIDEO_CUSTOM_OSD_NUM];// Each channel OSD information
	BYTE    			bReserved[16];							// Reserved
} DH_DVR_VIDEOOSD_CFG;

// CDMA/GPRS Configuration
// Time structure															    
typedef struct 
{
	BYTE				bEnable;					// Time period enable,1 shows this time period valid,0 shows invalid.
	BYTE				bBeginHour;
	BYTE				bBeginMin;
	BYTE				bBeginSec;
	BYTE				bEndHour;
	BYTE				bEndMin;
	BYTE				bEndSec;
	BYTE    			bReserved;					//Reserved
} DH_3G_TIMESECT, *LPDH_3G_TIMESECT;

typedef struct 
{
	DWORD 				dwSize;
	BOOL				bEnable;					// Wireless module enable
	DWORD               dwTypeMask;                 // Network type mask;Use bit to represent,The first bit:Automatic selection
													// The second bit:TD-SCDMA network;The third bit:WCDMA network;
													// The fourth bit:CDMA 1.x network;The fifth bit:GPRS network;The sixth bit:EVDO network
													// The seventh bit:EVDO network;The eighth bit:WIFI network;
	DWORD               dwNetType;                  // Types of wireless networks,EM_GPRSCDMA_NETWORK_TYPE
	char				szAPN[128];					// Access Point Name
	char				szDialNum[128];				// Dial-up number
	char				szUserName[128];			// Dial-up user name
	char				szPWD[128];					// Dial-up Password
	
	/* Read-only part */
	BOOL				iAccessStat;				// Wireless network registration status
    char				szDevIP[16];				// dial-up IP of Front-end equipment  
	char				szSubNetMask [16];			// Dial-up mask of Front-end equipment
	char				szGateWay[16];				// Dial-up Gateway of Front-end equipment

	int                 iKeepLive;					// Keep-alive time
	DH_3G_TIMESECT		stSect[DH_N_WEEKS][DH_N_TSECT];// 3G dial period,valid time period,start dialing;beyond this period,shut the dial.
	BYTE                byActivate;                  //Whether need to be active by voice or message
	
	BYTE                bySimStat;                    //SIM(UIM) State: 1, 0 (read-only data) be occupied the 1 byte
	char                szIdentify[128];               // identify mode
	bool                bPPPEnable;                    // PPP Dial-up,0- cut down ppp connect,1-ppp dial-up
	BYTE                bPPPState;                     // PPP Dial-up statr(real only),see EM_MOBILE_PPP_STATE
	BYTE                bNetCardState;                 // net card state(read only),see EM_3GMOBILE_STATE
	char				Reserved[39];				   // reserved
} DHDEV_CDMAGPRS_CFG;

// The length of the video package configuration
typedef struct  
{
	DWORD 				dwSize;
	int					nType;						// 0:by time,1:by size
	int					nValue;						// nType = 0:(minutes),nType = 1:(KB)
	char				Reserved[128];				// Reserved
} DHDEV_RECORD_PACKET_CFG;

// (Directional)register the server information
typedef struct __DEV_AUTOREGISTER_INFO 
{
	LONG			lConnectionID;					// Connection ID
	char			szServerIp[DH_MAX_IPADDR_LEN];	// Server IP
	int				nPort;							// Port:0- 65535
	int             nState;                         // Server status:0¡ê-Registration failure;1-Registration success; 2-Connection failed
	char			reserved[16];
} DEV_AUTOREGISTER_INFO;

typedef struct __DEV_SERVER_AUTOREGISTER 
{
	DWORD					dwSize;
	int						nRegisterSeverCount;									// Number of registered servers
	DEV_AUTOREGISTER_INFO	stuDevRegisterSeverInfo[DH_CONTROL_AUTO_REGISTER_NUM];	// Server information
	char					reserved[256];
} DEV_SERVER_AUTOREGISTER, *LPDEV_SERVER_AUTOREGISTER;

// Upload burning annex
typedef struct
{
	DWORD				dwSize;		
	char				szSourFile[MAX_PATH_STOR];	// Source file path
	int					nFileSize;					// Source file size,If less than or equal to 0, sdk to calculate file size.
	char				szBurnFile[MAX_PATH_STOR];	// After burning the file name
	BYTE				bReserved[64];
} DHDEV_BURNFILE_TRANS_CFG;

// Update file upload
typedef struct
{
	char                 szFile[MAX_PATH_STOR];      // Update file path
	int                  nFileSize;                  // Update file size  
	BYTE                 byChannelId;                // Channel No.
	BYTE                 byManufactryType;           // Manufacturer type    Please refer to EM_IPC_TYPE
	
	BYTE                 byReserved[126];            // Reserved      
}DHDEV_UPGRADE_FILE_INFO;


// Zhengzhou EC_U video data overlay enabling configuration
typedef struct 
{
	BOOL				bEnable;					// Enable
	int					nPort;						// Port
	BYTE				bReserved[64];
}DHDEV_OSD_ENABLE_CFG;

// about vehicle configuration
typedef struct	
{
	BOOL				bAutoBootEnable;				//auto boot enable
	DWORD				dwAutoBootTime;					//auto boot time, Unit is second. The value ranges from 0 to 82800.
	BOOL				bAutoShutDownEnable;			//auto shut down enable
	DWORD				dwAutoShutDownTime;				//auto shut down time ,  Unit is second. The value ranges from 0 to 82800.
	DWORD				dwShutDownDelayTime;			//shut down delay time, Unit is second.
	BYTE				bEventNoDisk;					//1,(Ignore); 2,(Reboot)
	BYTE				bWifiEnable;					//If support car wifi module.
	BYTE				bUpperSpeedEnable;				//if use over speed verdict
	BYTE				bLowerSpeedEnable;				//if use low speed verdict
	DWORD				dwUpperSpeedValue;				//Over speed area(1,1000).km/hour.
	DWORD               dwLowerSpeedValue;              //Low speed area(1,1000).km/hour.
    DWORD               dwUpperSpeedDelayTime;          //Upper Speed Delay Time
	DWORD               dwLowerSpeedDelayTime;          //Lower Speed Delay Time
	DWORD               dwAlarmMaskEnable;              //Search/set OSD alarm information enable, every bit present one external alarm channel, 0:close;1:open
	BOOL                bSpeedOverAlarmRecordEnable;    // Over Speed Alarm Record Enable
	BOOL                bSpeedLowAlarmRecordEnable;     // Low Speed Alarm Record Enable
	BYTE				bReserved[480];					//reserved byte.
} DHDEV_ABOUT_VEHICLE_CFG;

// atm: query overlay ability information
typedef struct  
{
	DWORD				dwDataSource;					//1:Network, 2:Comm, 3:Network&Comm
	char				szProtocol[32][33];				//protocol name
	BYTE				bReserved[256];
} DHDEV_ATM_OVERLAY_GENERAL;
 
// atm: overlay configuration
typedef struct 
{
	DWORD				dwDataSource;					// 1:Network, 2:Comm
	char				szProtocol[33];					// protocol name, from DHDEV_ATM_OVERLAY_GENERAL
	BYTE				bReserved_1[3];
	DWORD				dwChannelMask;					// channel mask
	BYTE				bMode;							// 1:Preview, 2:Encode, 3:Preview&Encode
	BYTE				bLocation;						// 1:LeftTop, 2:LeftBottom, 3:RightTop, 4:RightBottom
	BYTE                bReserved_3[2];
	int                 nLatchTime;                     // display latch time on overlay, instruct the video's close latch time, 0~65535
	BYTE                bReserved_4[3];
	BYTE                bRecordSrcKeyNum;               // key number
	int                 nRecordSrcKey[32];              // key of channels 
	BYTE				bReserved_2[120];
} DHDEV_ATM_OVERLAY_CONFIG;

#define DH_MAX_BACKUPDEV_NUM			16
#define DH_MAX_BACKUP_NAME				32

// backup device list
typedef struct 
{
	int					nBackupDevNum;												// number of backup devices
	char				szBackupDevNames[DH_MAX_BACKUPDEV_NUM][DH_MAX_BACKUP_NAME]; // backup device name
} DHDEV_BACKUP_LIST, *LPDHDEV_BACKUP_LIST;

// backup device type
typedef enum __BACKUP_TYPE
{
	BT_DHFS = 0,							// dvr file system
	BT_DISK,								// floating disk
	BT_CDRW									// CD
} DHDEV_BACKUP_TYPE;	

// backup device interface
typedef enum __BACKUP_BUS
{
	BB_USB = 0,								// usb
	BB_1394,								// 1394
	BB_IDE,									// ide
	BB_ESATA,								// esata
} DHDEV_BACKUP_BUS;	

typedef struct 
{
	char				szName[32];						// name
	BYTE				byType;							// see BACKUP_TYPE
	BYTE				byBus;							// see BACKUP_BUS
	UINT				nCapability;					// total capability(kBytes)
	UINT				nRemain;						// remain capability(kBytes)
	char				szDirectory[128];				// Remote Directory
} DHDEV_BACKUP_INFO, *LPDHDEV_BACKUP_INFO;

typedef struct 
{
	char				szName[32];						// name 
	UINT				nCapability;					// total capability(kBytes)
	UINT				nRemain;						// remain capability(kBytes)
} DHDEV_BACKUP_FEEDBACK, *LPDHDEV_BACKUP_FEEDBACK;

#define  DH_MAX_BACKUPRECORD_NUM 1024

typedef struct  
{
	char				szDeviceName[DH_MAX_BACKUP_NAME];			//name
	int					nRecordNum;									//number of records
	NET_RECORDFILE_INFO	stuRecordInfo[DH_MAX_BACKUPRECORD_NUM];		//record information
} BACKUP_RECORD, *LPBACKUP_RECORD;

// multiplay input param
typedef struct
{
	int                 iChannelID;      // channel id
	DH_RealPlayType     realplayType;    // real play type
	char                reserve[32];
}DHDEV_IN_MULTIPLAY_PARAM;

// multiplay output param
typedef struct
{
	int                 iChannelID;      // channel id
	LLONG                lRealHandle;     // real play handle
	char                reserve[32];
}DHDEV_OUT_MULTIPLAY_PARAM;
/////////////////////////////////Embedded platform/////////////////////////////////

// Platform embedded setup ¡ê- U China Network Communication(CNC)
typedef struct
{
    BOOL				bChnEn;
    char				szChnId[DH_INTERVIDEO_UCOM_CHANID];
} DH_INTERVIDEO_UCOM_CHN_CFG;

typedef struct
{
	DWORD				dwSize;
	BOOL				bFuncEnable;			// Enable connection
	BOOL				bAliveEnable;			// Enable alive
	DWORD				dwAlivePeriod;			// Alive period. Unit is second. The value ranges from 0 to 3600.
	char				szServerIp[DH_MAX_IPADDR_LEN];			// CMS IP
	WORD				wServerPort;							// CMS Port
    char				szRegPwd[DH_INTERVIDEO_UCOM_REGPSW];	// Registration password 
	char				szDeviceId[DH_INTERVIDEO_UCOM_DEVID];	// Device id
	char				szUserName[DH_INTERVIDEO_UCOM_USERNAME];
	char				szPassWord[DH_INTERVIDEO_UCOM_USERPSW];
    DH_INTERVIDEO_UCOM_CHN_CFG  struChnInfo[DH_MAX_CHANNUM];	// Channel id,en
} DHDEV_INTERVIDEO_UCOM_CFG;

//  Platform embedded setup ¡ê- Alcatel
typedef struct
{
	DWORD				dwSize;
    unsigned short		usCompanyID[2];			// Company ID,Value. the different three party service company. Now use the first array considering the four bytes in line.
    char				szDeviceNO[32];			// Strings including '\0' are 32 bytes.
    char				szVSName[32];			// Front-end device name. Strings including '\0' are 16 bytes.
    char				szVapPath[32];			// VAP path
    unsigned short		usTcpPort;				// TCP port,value:value ranges from 1 to 65535 
    unsigned short		usUdpPort;				// UDP port,Value:Value ranges from 1 to 65535
    bool				bCsEnable[4];			// Enable central server symbol. Value:true=enable,false=disable.Now only use the first array considering the four bytes in line.
    char				szCsIP[16];				// Central server IP address.Strings including '\0' are 16 bytes.
    unsigned short		usCsPort[2];			// Central server port. Value ranges from 1 to 65535.Now only use the first array considering the four bytes in line.
    bool				bHsEnable[4];			// Enable pulse server symbol. Value:true-enable,false=disable.Now only use the first array considering the four bytes in line.
    char				szHsIP[16];				// Pulse server IP address. Strings including '\0' are 16 bytes.
    unsigned short		usHsPort[2];			// Pulse server port. Value ranges from 1 to 65535.Now only use the first array considering the four bytes in line
    int					iHsIntervalTime;		// Pulse server interval. Value(unit is second)
    bool				bRsEnable[4];			// Enable registration server symbol. Value:,true=enable,false=disable.Now only use the first array considering the four bytes in line. 
    char				szRsIP[16];				// Registration server IP address. Strings including '\0' are 16 bytes.
    unsigned short		usRsPort[2];			// Registration server port. Value. The value ranges from 1 to 65535.Now use the first array considering the four bytes in line
    int					iRsAgedTime;			// Registration server valid duration. Value(unit is hour)
    char				szAuthorizeServerIp[16];// IP Authorization server IP
    unsigned short		usAuthorizePort[2];		// Authorization server port. Now only use the first array considering the four bytes in line
    char				szAuthorizeUsername[32];// Authorization server account
    char				szAuthorizePassword[36];// Authorization server password
    
    char				szIpACS[16];			// ACS( auto registration server) IP
    unsigned short		usPortACS[2];			// ACS Port,Now only use the first array considering the four bytes in line. 
    char				szUsernameACS[32];		// ACS user name
    char				szPasswordACS[36];		// ACS password
    bool				bVideoMonitorEnabled[4];// DVS regularly uploads front-end video monitor message or not.Value:true=enable,false=disable
    int					iVideoMonitorInterval;	// Upload interval(minute)
    
    char				szCoordinateGPS[64];	// GPS coordinates
    char				szPosition[32];			// Device position
    char				szConnPass[36];			// Device connection bit 
} DHDEV_INTERVIDEO_BELL_CFG;

//  Platform embedded setup ¡ê- ZTE Netview
typedef struct  
{
	DWORD				dwSize;
	unsigned short		nSevPort;								// Server port. Value. The value ranges from 1 to 65535
    char				szSevIp[DH_INTERVIDEO_NSS_IP];			// Server IP address,string,including '\0' end symbol, there are total 32byte.
    char				szDevSerial[DH_INTERVIDEO_NSS_SERIAL];	// Front-end device serial number, string including '\0' end symbol, there are total 32byte.
    char				szUserName[DH_INTERVIDEO_NSS_USER];
    char				szPwd[DH_INTERVIDEO_NSS_PWD];
} DHDEV_INTERVIDEO_NSS_CFG;

// Platform embedded setup ¡ê- AMP
typedef struct  
{
	char               szDevSerial[DH_INTERVIDEO_AMP_DEVICESERIAL];                  // Front Device Serial num(encoder serial num), read only	
	char               szDevName[DH_INTERVIDEO_AMP_DEVICENAME];                      // Front Device Name(encoder name), read only
	char               szRegUserName[DH_INTERVIDEO_AMP_USER];                        // Server Name
	char               szRegPwd[DH_INTERVIDEO_AMP_PWD];                              // Server Password
	BYTE			   bReserved[128];
} DHDEV_INTERVIDEO_AMP_CFG;  
////////////////////////////////HDVR special use//////////////////////////////////
// Alarm relay structure
typedef struct 
{
	/* Message triggered methods,multiple methods,including
	 * 0x00000001 - alarm upload
	 * 0x00000002 - triggering recording
	 * 0x00000004 - PTZ movement
	 * 0x00000008 - sending email
	 * 0x00000010 - local tour
	 * 0x00000020 - local tips
	 * 0x00000040 - alarm output
	 * 0x00000080 - ftp upload
	 * 0x00000100 - buzzer
	 * 0x00000200 - voice tips 
	 * 0x00000400 - snapshot
	*/

	/* Current alarm supporting methods, shown by bit mask */
	DWORD				dwActionMask;

	/* Triggering action,shown by bit mask,concrete action parameter is shows in the configuration */
	DWORD				dwActionFlag;
	
	/* Triggering alarm output channel,1 means triggering this output */ 
	BYTE				byRelAlarmOut[DH_MAX_ALARMOUT_NUM_EX];
	DWORD				dwDuration;				/* Alarm lasting period */

	/* Triggering recording */
	BYTE				byRecordChannel[DH_MAX_VIDEO_IN_NUM_EX]; /* Record channel triggered by alarm,1 means triggering this channel */
	DWORD				dwRecLatch;				/* Recording period */

	/* Snapshot channel */
	BYTE				bySnap[DH_MAX_VIDEO_IN_NUM_EX];
	/* Tour channel */
	BYTE				byTour[DH_MAX_VIDEO_IN_NUM_EX];

	/* PTZ movement */
	DH_PTZ_LINK			struPtzLink[DH_MAX_VIDEO_IN_NUM_EX];
	DWORD				dwEventLatch;			/* Event delay time, s for unit,range is 0~15,default is 0 */
	/* Alarm trigerring wireless output,alarm output,1 for trigerring output */ 
	BYTE				byRelWIAlarmOut[DH_MAX_ALARMOUT_NUM_EX];
	BYTE				bMessageToNet;
	BYTE                bMMSEn;                /*Message triggering alarm enabling*/
	BYTE                bySnapshotTimes;       /* the number of sheets of drawings */
	BYTE				bMatrixEn;				/*!< Matrix output enable */
	DWORD				dwMatrix;				/*!< Matrix mask */			
	BYTE				bLog;					/*!< Log enable,only used in WTN motion detection */
	BYTE				bSnapshotPeriod;		/*!<Snapshot frame interval. System can snapshot regularly at the interval you specify here. The snapshot amount in a period of time also has relationship with the snapshot frame rate. 0 means there is no interval, system just snapshot continuously.*/
	BYTE				byTour2[DH_MAX_VIDEO_IN_NUM_EX];/* Tour channel 32-63*/
	BYTE                byEmailType;             /*<0,picture,1,record>*/
	BYTE                byEmailMaxLength;        /*<max record length,unit:MB>*/
	BYTE                byEmailMaxTime;          /*<max time length, unit:second>*/
	BYTE				byReserved[475];   
} DH_MSG_HANDLE_EX;

// External alarm expansion
typedef struct
{
	BYTE				byAlarmType;			// Alarm type,0:normal closed,1:normal open
	BYTE				byAlarmEn;				// Alarm enable
	BYTE				byReserved[2];						
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT]; //NSP
	DH_MSG_HANDLE_EX	struHandle;				// Handle method
} DH_ALARMIN_CFG_EX, *LPDHDEV_ALARMIN_CFG_EX; 

// Motion detection alarm
typedef struct 
{
	BYTE				byMotionEn;				// Motion detection alarm enabling
	BYTE				byReserved;
	WORD				wSenseLevel;			// Sensitivity
	WORD				wMotionRow;				// Motion detection area rows
	WORD				wMotionCol;				// Motion detection area lines
	BYTE				byDetected[DH_MOTION_ROW][DH_MOTION_COL]; // Motion detection area,most 32*32
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT];	//NSP
	DH_MSG_HANDLE_EX		struHandle;				//Handle method
} DH_MOTION_DETECT_CFG_EX;

// fire alarm
typedef struct
{
	BOOL                byFireEn;              // enable
	DH_MSG_HANDLE_EX    struHandle;            // handler
	BYTE                byReserved[128];
}DHDEV_FIRE_ALARM_CFG;

// Static detection alarm

typedef struct 
{
	BYTE				byStaticEn;				// Static detection alarm enabling
	BYTE				byLatch;                // detect delay (old struct)
	WORD				wSenseLevel;			// Sensitivity
	WORD				wStaticRow;				// Static detection area rows
	WORD				wStaticCol;				// Static detection area lines
	BYTE				byDetected[DH_STATIC_ROW][DH_STATIC_COL]; // Static detection area,most 32*32
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT];	//NSP
	DH_MSG_HANDLE_EX		struHandle;				//Handle method
	int                 nLatch;                 // detect delay (new struct)
	BYTE                bReserved[64];          // reserved
} DH_STATIC_DETECT_CFG_EX;

// ACC power off configuration
typedef struct _DHDEV_ACC_POWEROFF_CFG
{
	BOOL                bEnable;               // ACC power off configuration enable
	int                 nDelayTime;            // ACC power off delay time(m)
	DH_MSG_HANDLE_EX    struHandle;            // handle method
	BYTE                Reserved[128];         // reserved
}DHDEV_ACC_POWEROFF_CFG;

// explosion proof alarm configuration
typedef struct _DHDEV_EXPLOSION_PROOF_CFG
{
	BOOL                bEnable;               // explosion proof alarm configuration enable
	DH_MSG_HANDLE_EX    struHandle;            // handle method
	BYTE                Reserved[128];         // reserved
}DHDEV_EXPLOSION_PROOF_CFG;

// Raid evnet config
typedef struct _DHDEV_RAID_EVENT_CFG
{
	BOOL                bEnable;               // enable
	DH_MSG_HANDLE_EX    struHandle;            // handle
	BYTE                Reserved[128];         // 
}DHDEV_RAID_EVENT_CFG;

// Video loss alarm
typedef struct
{
	BYTE				byAlarmEn;				// Video loss alarm enabling
	BYTE				byReserved[3];
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT];	//NSP
	DH_MSG_HANDLE_EX	struHandle;				// Handle method
} DH_VIDEO_LOST_CFG_EX;

// Camera masking alarm
typedef struct
{
	BYTE				byBlindEnable;			// Enable
	BYTE				byBlindLevel;			// Sensitivity 1-6
	BYTE				byReserved[2];
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT];	//NSP
	DH_MSG_HANDLE_EX	struHandle;				// Handle method
} DH_BLIND_CFG_EX;

// HDD info(alarm)
typedef struct 
{
	BYTE				byNoDiskEn;				// No HDD alarm
	BYTE				byReserved_1[3];
	DH_TSECT			stNDSect[DH_N_WEEKS][DH_N_REC_TSECT]; //NSP
	DH_MSG_HANDLE_EX	struNDHandle;			// Handle method
	
	BYTE				byLowCapEn;				// Low capacity alarm
	BYTE				byLowerLimit;			// Lower limit,0-99
	BYTE				byReserved_2[2];
	DH_TSECT			stLCSect[DH_N_WEEKS][DH_N_REC_TSECT]; //NSP
	DH_MSG_HANDLE_EX	struLCHandle;			// Handle method
	
	BYTE				byDiskErrEn;			// HDD error alarm
	BYTE				bDiskNum;
	BYTE				byReserved_3[2];
	DH_TSECT			stEDSect[DH_N_WEEKS][DH_N_REC_TSECT]; //NSP
	DH_MSG_HANDLE_EX	struEDHandle;			// Handle method
} DH_DISK_ALARM_CFG_EX;

typedef struct
{
	BYTE				byEnable;
	BYTE				byReserved[3];
	DH_MSG_HANDLE_EX	struHandle;
} DH_NETBROKEN_ALARM_CFG_EX;

// Front encoder configuration parameter
typedef struct __DEV_ENCODER_CFG 
{
	int					nChannels;				// Digital channel number
	DEV_ENCODER_INFO	stuDevInfo[32];			// Digital channel info
	BYTE				byHDAbility;			// The max high definition video amount the digital channel supported. (0 means it does not support high definition setup.)
												// If it supports high definition setup, the high definition channel ranges from 0 to N-1. If your high definition channel number is more than N, the save operation may fail. 
	BYTE				bTVAdjust;				// TV adjust. 0:not support, 1:support.
	BYTE				bDecodeTour;			// Decode tour. 0:not support, greater than zero: it means the maximal number supported.
	BYTE				bRemotePTZCtl;			// Remote PTZ control. 0:not support, 1:support.
	char				reserved[12];
} DEV_ENCODER_CFG, *LPDEV_ENCODER_CFG;

// Controller
typedef struct tagDHCONFIG_CONTROLER{
	DH_COMM_PROP        struComm;	                     // Com attribution
	BYTE                bLightGroup[DH_MAX_LIGHT_NUM];   // Controlled light group,light number start from 1,such as[1,3,8,0?-0]present control light number 1,3,8 light
	BYTE	            bDeviceAddr;	                 // Controller address
	BYTE                bComPortType;                    // Com Type 0:485 COM, 1:232 COM
	BYTE                bReserved[6];		             // Reserved
} DH_CONFIG_CONTROLER;

// Light control config
typedef struct __DHDEV_LIGHTCONTROL_CFG
{
	DH_CONFIG_CONTROLER    struControlers[DH_MAX_CONTROLER_NUM]; // Control config
	BYTE                   bControlerNum;                        // Effective controller number
	BYTE                   bReserved[1023];                      // Reserved
} DHDEV_LIGHTCONTROL_CFG, *LPDHDEV_LIGHTCONTROL_CFG;

// 3G Flow info config
typedef struct
{
	int                 nStrategy;       // strategy, 0: charged by flow every month 1:charged by time every month
	int                 nUpLimit;        // up limit, by flow: MB, by time: h
	int                 nreserved[22];   // reserved
}DHDEV_3GFLOW_INFO_CFG;

// IPv6 config
typedef struct 
{
	char               szLinkAddr[44];	 // link address: string length = 44;(every host has an exclusive link address, read only)
	char               szHostIP[40]; 	 // host IP
	DWORD              dwPreFix;		 // net prefix, 1-128
	char               szGateWay[40];	 // gateway
	BOOL               bAutoGet;		 // enable of auto get ip 
	char               szPrimaryDns[40]; // primary DNS
	char               szSecondDns[40];	 // second DNS
    char               cReserved[256];   // reserved
}DHDEV_IPV6_CFG;

//Emergency storage configuration
typedef struct __DEV_URGENCY_RECORD_CFG
{
	DWORD dwSize;           // Structure body size
	BOOL bEnable;           // Enable or not. 1=enable.0=disable
	UINT nMaxRecordTime;    // Max record time. Unit is second.
}DHDEV_URGENCY_RECORD_CFG;

// Lift running parameter configuration
typedef struct __DEV_ELEVATOR_ATTRI_CFG
{
	DWORD dwSize;           // Structure body size
	UINT   nMAXFloorNum;     //Max floor. Min is 2.
	UINT   nFloorDelayTime;  //Stay verification time ranges from 5-60. It regards as stop current floor if keep this time period.
	UINT   nIntervalTime;    //The max time for the lift to go up/down a floor. It regars the lift is malfunction if the time is out of the threshold. The lift stopsa between two floors.
}DHDEV_ELEVATOR_ATTRI_CFG;

// Virtual camera status search
typedef struct tagDHDEV_VIRTUALCAMERA_STATE_INFO
{
	DWORD              nStructSize;        // Structure body size
	int                nChannelID;         // Channel No.
	CONNECT_STATE      emConnectState;     // Connection status
	UINT               uiPOEPort;          // The PoE port the virtual camera connected to. 0=It is not a PoE connection.
	char               szDeviceName[64];   // Device name
	char               szDeviceType[128];  // Device type
}DHDEV_VIRTUALCAMERA_STATE_INFO;

// Device working video/loop mode status info and etc search 
typedef struct tagDHDEV_TRAFFICWORKSTATE_INFO
{
	DWORD                nStructSize;      // Structure body size
	int                  nChannelID;       // Channel No.
	DH_TRAFFIC_SNAP_MODE emSnapMode;       // Snap mode
}DHDEV_TRAFFICWORKSTATE_INFO;

/////////////////////////////////ITS picture subscription interface parameter/////////////////////////////////
typedef struct RESERVED_DATA_INTEL_BOX
{
	DWORD  dwEventCount;	 //Event count
	DWORD* dwPtrEventType;	 //Point to continuous value of event type, user should request and fr
	BYTE   bReserved[1024];	 //Reserved
}ReservedDataIntelBox;

#define RESERVED_TYPE_FOR_INTEL_BOX 0x00000001
typedef struct RESERVED_PARA
{
	DWORD 	dwType;	//pData's type
					//when [dwType] is RESERVED_TYPE_FOR_INTEL_BOX, pData is address of type ReservedDataIntelBox					
					//when [dwType] is ...,[pData] is ...
	void*	pData;	//data
}ReservedPara;
#define RESERVED_TYPE_FOR_COMMON   0x00000010
typedef struct tagNET_RESERVED_COMMON
{
	DWORD            dwStructSize;
	ReservedDataIntelBox* pIntelBox;    // include RESERVED_TYPE_FOR_INTEL_BOX
	DWORD            dwSnapFlagMask;	// snap flags(by bit),0bit:"*",1bit:"Timing",2bit:"Manual",3bit:"Marked",4bit:"Event",5bit:"Mosaic",6bit:"Cutout"
}NET_RESERVED_COMMON;

/////////////////////////////////Intelligent speed dome control interface parameter/////////////////////////////////
// Scene structure info
typedef struct 
{
	DWORD       dwSize;
	int         nScene;			//Scene SN
}DHDEV_INTELLI_SCENE_INFO;

// Scene margin limit position info
typedef struct 
{
	DWORD       dwSize;
	int         nScene;			//Scene SN
	int         nType;			//0:Top margin limit;1:Bottom margin limit;2:Left margin;3:Right margin
}DHDEV_INTELLI_SCENELIMIT_INFO;

// Manually track object structure body info
typedef struct
{
	DWORD       dwSize;
	int         nObjectID;		// Object ID¡ê?-1 = Set the intelligent frame upload the position of any object out of the frame in the Web¡ê?>=0: select the intelligent frame to send the object in the frame. 
	RECT        stuBound;		// Rectangle range. The coordinates of the point is within [0,8192].
}DHDEV_INTELLI_TRACKOBJECT_INFO;

typedef enum __TRACKCONTROL_TYPE
{
	DH_TRACK_MARKSCENE,				// Specified scene. Corresponding to the structure body of the DHDEV_INTELLI_SCENE_INFO
		DH_TRACK_GOTOSCENE,			// Go to scene. Corresponding to the structure body of the DHDEV_INTELLI_SCENE_INFO
		DH_TRACK_MARKSCENELIMIT,	// The margin limit position of the specified scene. Corresponding to the structure body of the DHDEV_INTELLI_SCENELIMIT_INFO
		DH_TRACK_GOTOSCENELIMIT,	// Go to the marin limit position of the scene. Corresponding to the structure body of the DHDEV_INTELLI_SCENELIMIT_INFO
		DH_TRACK_MARKSCENEMAXZOOM,	// The max track rate in the specified scene. Corresponding to the structure body of the DHDEV_INTELLI_SCENE_INFO
		DH_TRACK_OBJECT,			// The tracking object in the selected scene. Corresponding to the structure body of the DHDEV_INTELLI_TRACKOBJECT_INFO
		DH_TRACK_START,				// Begin intelligent track. No need to specify parameter information.
		DH_TRACK_STOP,				// Stop intelligent track. No need to specify parameter information.
		DH_TRACK_TYPE_NUM,
}DH_TRACKCONTROL_TYPE;

//Intelligent speed dome control input parameter
typedef struct tagNET_IN_CONTROL_INTELLITRACKER
{
    DWORD       dwSize;
    int         nChannelID;            // Channel ID
    DH_TRACKCONTROL_TYPE emCtrlType;   // Control type
    void*       pCtrlInfo;             // The corresponding inform structure pointer of the control type. Please refer to DH_TRACKCONTROL_TYPE for definition.
    int         nMaxLen;               // Structure body size of the control information
	int         nWaittime;             // Wait time out time
}NET_IN_CONTROL_INTELLITRACKER;

//Intelligent speed dome control output parameter
typedef struct tagNET_OUT_CONTROL_INTELLITRACKER
{
    DWORD       dwSize;
}NET_OUT_CONTROL_INTELLITRACKER;


/////////////////////////////////Abandoned Type/////////////////////////////////

// Search device working status channel information. Corresponding interfaces have been abandoned. Do not user.
typedef struct
{
	BYTE				byRecordStatic;			// Channel is recording or not. ;0: does not record,1: manual record,2:auto record  
	BYTE				bySignalStatic;			// Connected signal status ;0:normal,1:signal loss  
	BYTE				byHardwareStatic;		// Channel hardware status;0:normal ,1:abnormal such as DSP is down , 
	char				reserve;
	DWORD				dwBitRate;				// Actual bit rate
	DWORD				dwLinkNum;				// The client-end connected amount 
	DWORD				dwClientIP[DH_MAX_LINK];// Client-end IP address 
} NET_DEV_CHANNELSTATE, *LPNET_DEV_CHANNELSTATE;

// Search device working status. The corresponding interfaces have been abandoned. Please do not use
typedef struct
{
	DWORD				dwDeviceStatic;			// Device status;0x00:normal ,0x01:CPU occupation is too high ,0x02:hardware error 
	NET_DEV_DISKSTATE	stHardDiskStatic[DH_MAX_DISKNUM]; 
	NET_DEV_CHANNELSTATE stChanStatic[DH_MAX_CHANNUM];	// Channel status
	BYTE				byAlarmInStatic[DH_MAX_ALARMIN];// Alarm port status;0:no alarm,1: alarm
	BYTE				byAlarmOutStatic[DH_MAX_ALARMOUT]; // Alarm output port status;0:no alarm,1:alarm  
	DWORD				dwLocalDisplay;			// Local display status  ;0:normal,1:abnormal 
} NET_DEV_WORKSTATE, *LPNET_DEV_WORKSTATE;

// Protocol information
typedef struct 
{
	char				protocolname[12];		// Protocol name
	unsigned int		baudbase;				// Baud rate
	unsigned char		databits;				// Data bit
	unsigned char		stopbits;				// Stop bit
	unsigned char		parity;					// Pairty bit 
	unsigned char		reserve;
} PROTOCOL_INFO, *LPPROTOCOL_INFO;

// Audio talk parameter setup
typedef struct 
{
	// Audio input parameter
	BYTE				byInFormatTag;			// Encode type such as PCM
	BYTE				byInChannels;			// Track amount
	WORD				wInBitsPerSample;		// Sampling depth 				
	DWORD				dwInSamplesPerSec;		// Sampling rate 

	// Audio output parameter
	BYTE				byOutFormatTag;			// Encode type such as PCM
	BYTE				byOutChannels;			// Track amount
	WORD				wOutBitsPerSample;		// Sampling depth 		
	DWORD				dwOutSamplesPerSec;		// Sampling rate
} DHDEV_TALK_CFG, *LPDHDEV_TALK_CFG;

/////////////////////////////////// Matrix ///////////////////////////////////////

#define DH_MATRIX_INTERFACE_LEN		16		// Signal interface name length
#define DH_MATRIX_MAX_CARDS			16		// Matrix sub card max amount
#define DH_SPLIT_PIP_BASE			1000	// The basic value of the PIP split mode
#define	DH_MAX_SPLIT_MODE_NUM		64		// Max split matrix amount
#define DH_MATRIX_MAX_CHANNEL_IN	1500	// Matrix max input channel amount
#define DH_MATRIX_MAX_CHANNEL_OUT	256		// Matrix max output channel amount
#define DH_DEVICE_NAME_LEN			64		// Device name length
#define DH_MAX_CPU_NUM				16		// Max CPU amount
#define DH_MAX_FAN_NUM				16		// Max fan amount
#define DH_MAX_POWER_NUM			16		// Max power amount
#define DH_MAX_TEMPERATURE_NUM		16		// Max temperature sensor amount
#define DH_MAX_ISCSI_NAME_LEN		128		// ISCSI Name length
#define DH_STORAGE_NAME_LEN			128		// storage device name length
#define DH_VERSION_LEN				64		// Version info length
#define DH_MAX_STORAGE_PARTITION_NUM 32		//  Storage partition max number
#define DH_STORAGE_MOUNT_LEN		64		// Mount length
#define DH_STORAGE_FILE_SYSTEM_LEN	16		// File system name length
#define DH_MAX_MEMBER_PER_RAID		32		// RAID max members
#define DH_DEV_ID_LEN_EX			128		// Device ID max length


#define DH_DEVICE_ID_LOCAL		"Local"		// LocalID
#define DH_DEVICE_ID_REMOTE		"Remote"	// RemoteID

// Split mode
typedef enum tagDH_SPLIT_MODE
{
	DH_SPLIT_1 = 1,							// 1-window
	DH_SPLIT_2 = 2, 						// 2-window
	DH_SPLIT_4 = 4, 						// 4-window
	DH_SPLIT_6 = 6, 						// 6-window
	DH_SPLIT_8 = 8, 						// 8-window
	DH_SPLIT_9 = 9, 						// 9-window
	DH_SPLIT_12 = 12, 						// 12-window
	DH_SPLIT_16 = 16, 						// 16-window
	DH_SPLIT_20 = 20, 						// 20-window
	DH_SPLIT_25 = 25, 						// 25-window
	DH_SPLIT_36 = 36, 						// 36-window
	DH_SPLIT_64 = 64, 						// 64-window
	DH_SPLIT_144 = 144, 					// 144-window
	DH_PIP_1 = DH_SPLIT_PIP_BASE + 1,		// PIP mode.1-full screen+1-small window
	DH_PIP_3 = DH_SPLIT_PIP_BASE + 3,		// PIP mode.1-full screen+3-small window
} DH_SPLIT_MODE;

// Device protocol type
typedef enum tagDH_DEVICE_PROTOCOL
{
	DH_PROTOCOL_DAHUA2,						// Dahua 2nd protocol
	DH_PROTOCOL_DAHUA3,						// Dahua 3rd protocol
	DH_PROTOCOL_ONVIF,						// Onvif
} DH_DEVICE_PROTOCOL;

// Split mode info
typedef struct tagDH_SPLIT_MODE_INFO
{
	DWORD				dwSize;
	DH_SPLIT_MODE		emSplitMode;			// Split mode
	int					nGroupID;				// Group SN
} DH_SPLIT_MODE_INFO;

// Split capability
typedef struct tagDH_SPLIT_CAPS 
{
	DWORD				dwSize;
	int					nModeCount;				// The split amount supported
	DH_SPLIT_MODE		emSplitMode[DH_MAX_SPLIT_MODE_NUM];	// The split mode supported
	int				    nMaxSourceCount;		// Max display source allocation amount
} DH_SPLIT_CAPS;

// Display source
typedef struct tagDH_SPLIT_SOURCE
{
	DWORD				dwSize;
	BOOL			    bEnable;						    // Enable
	char			    szIp[DH_MAX_IPADDR_LEN];		    // IP, null means there is no setup.
	char			    szUser[DH_USER_NAME_LENGTH];	    // User name
	char			    szPwd[DH_USER_PSW_LENGTH];	    	// Password
	int			    	nPort;							    // Port
	int				    nChannelID;						    // Channel No.
	int				    nStreamType;					    // Video bit stream. -1-auto, 0-main stream, 1-extra stream 1, 2-extra stream 2, 3-extra stream 3
	int				    nDefinition;					    // Definition, 0-standard definition, 1-high definition
	DH_DEVICE_PROTOCOL  emProtocol;							// Protocol type
	char			    szDevName[DH_DEVICE_NAME_LEN];		// Device name
	int					nVideoChannel;						// Video input channel amount
	int					nAudioChannel;						// Audio input channel amount
	// For decoder only
	BOOL				bDecoder;							// Decoder or not.
	BYTE				byConnType;							// 0:TCP;1:UDP;2:multicast
	BYTE				byWorkMode;							// 0:connect directly; 1:transfer 
	WORD				wListenPort;						// isten port, valid with transfer; when byConnType is multicast, it is multiport
	char				szDevIpEx[DH_MAX_IPADDR_OR_DOMAIN_LEN];// szDevIp extension, front DVR Ip address (enter domain name)
	BYTE				bySnapMode;                         //  snapshot mode (valid when nStreamType==4) 0: request for single frame, 1: sechdule sending request
	BYTE				byManuFactory;						// Target device manufacturer. Refer to EM_IPC_TYPE for detailed information.
	BYTE				byDeviceType;                       //  target device type, 0:IPC
	BYTE				byDecodePolicy;                     // target device decode policy, 0:compatible with previous  
															// 1:real time level high 2: real time level medium
															// 3: real time level low 4: default level 
															// 5: fluency level high 6: fluency level medium
															// 7: fluency level low
	DWORD				dwHttpPort;                         // Http port number, 0-65535
	DWORD				dwRtspPort;                         // Rtsp port number, 0-65535
	char				szChnName[DH_DEVICE_NAME_LEN];		// Remote channel name, modifiable only when name read is not vacant
	char				szMcastIP[DH_MAX_IPADDR_LEN];       // Multicast IP address. Valid only when byConnType is multicast
	char				szDeviceID[DH_DEV_ID_LEN_EX];		// DeviceID, szIp==NULL and szDevIpEx== NULL. this param is valid, ""-null, "Local", "Remote",or the DeviceID of RemoteDevice
} DH_SPLIT_SOURCE;

// Video output capability set
typedef struct tagDH_VIDEO_OUT_CAPS 
{
	DWORD				dwSize;
	BOOL				bColor;							// Support color output setup or not
	BOOL				bMargin;						// Support margin setup or not
	int					nLayers;						// The max layers supported at the same time
	BOOL				bPowerMode;						// Support power control or not.
	int					bSplitMode;						// The video split mode supported. 0-1-window. 1-'#' mode(inclduing 1-window).2-Any mode
} DH_VIDEO_OUT_CAPS;

// Color RGBA
typedef struct tagDH_COLOR_RGBA
{
	int					nRed;							// Red
	int					nGreen;							// Green
	int					nBlue;							// Blue
	int					nAlpha;							// Transparent
} DH_COLOR_RGBA;

// Color BCSH
typedef struct tagDH_COLOR_BCSH 
{
	int					nBirghtness;					// Brightness
	int					nContrast;						// Contrast
	int			        nSaturation;					// Saturation
	int					nHue;						    // Hue
} DH_COLOR_BCSH;

// Dimensions
typedef struct tagDH_SIZE 
{
	int					nWidth;							// Width
	int					nHeight;						// Height
} DH_SIZE;

// Video output option 
typedef struct tagDH_VIDEO_OUT_OPT
{
	DWORD				dwSize;
	DH_RECT*			pstuMargin;						// Margin range
	DH_COLOR_BCSH*		pstuColor;						// Output color
	DH_COLOR_RGBA*		pstuBackground;					// Background color
	DH_SIZE*			pstuSize;						// Output dimensions
} DH_VIDEO_OUT_OPT;

// Production definition
typedef struct tagDH_PRODUCTION_DEFNITION
{
	DWORD				dwSize;
	int					nVideoInChannel;				// Video input channel amount
	int					nVideoOutChannel;				// Video output channel amount
	int					nRemoteDecChannel;				// Remote decode channel amount
	char				szDevType[DH_DEV_TYPE_LEN];		// Device type
	char				szVendor[DH_MAX_NAME_LEN];		// OEM customer
	int					nOEMVersion;					// OEM version
	int					nMajorVerion;					// Main version No.
	int					nMinorVersion;					// SUb version No.
	int					nRevision;						// Revision version
	char				szWebVerion[DH_MAX_NAME_LEN];	// Web version
	char				szDefLanguage[DH_MAX_NAME_LEN];	// Default setup
	NET_TIME			stuBuildDateTime;				// Release time. Unit is second.
	int					nAudioInChannel;				// Audio input channel amount
	int					nAudioOutChannel;				// Audio output channel amount
	BOOL				bGeneralRecord;					// Support schedule storage or not.
	BOOL				bLocalStore;					// Support local storage or not.
	BOOL				bRemoteStore;					// Support network storage or not.
	BOOL				bLocalurgentStore;				// Support emergency local storage or not.
	BOOL				bRealtimeCompress;				// Support real-time compression storage or not.
	DWORD				dwVideoStandards;				// The video format supported. bit0-PAL, bit1-NTSC
	int					nDefVideoStandard;				// Default video format, 0-PAL, 1-NTSC
	int					nMaxExtraStream;				// Max extra stream channel amount
	int					nRemoteRecordChannel;			// Remote record channel amount
	int					nRemoteSnapChannel;				// Remote snap channel amount
	int					nRemoteVideoAnalyseChannel;		// Remote video analysis channel amount
	int					nRemoteTransmitChannel;			// Remote real-time stream transmit max channel amount
	int					nRemoteTransmitFileChannel;		// Remote transmit file channel amount
	int					nStreamTransmitChannel;			// Max network transmit channel amount
	int					nStreamReadChannel;				// Max read file channel amount
	int					nMaxStreamSendBitrate;			// Max bit stream network send capability, kbps
	int					nMaxStreamRecvBitrate;			// Max bit stream network interface capability, kbps
	BOOL				bCompressOldFile;				// Old compression file or not. Delete P frame and save I frame.
	BOOL				bRaid;							// Support RAID or not.
	int					nMaxPreRecordTime;				// Max pre-record time.Unit is second.
	BOOL				bPtzAlarm;						// Support PTZ alarm or not.
	BOOL				bPtz;							// Support PTZ or not.
	BOOL				bATM;							// Support corresponding function of the ATM or not.
	BOOL				b3G;							// Support 3G module or not.
	BOOL				bNumericKey;					// With number button or not.
	BOOL				bShiftKey;						// With Shift button or not.
	BOOL				bCorrectKeyMap;					// Number character map sheet is right or not.
	BOOL				bNewATM;						// The new 2nd ATM front panel.
	BOOL				bDecoder;						// Decoder or not
	DEV_DECODER_INFO	stuDecoderInfo;					// Decoder info. Valid when bDecoder=true.bDecoder=true
    int					nVideoOutputCompositeChannels;	// Max VideoOutput Composite channel amount
} DH_PRODUCTION_DEFNITION;

// Matrix sub card type. Various setups.
#define DH_MATRIX_CARD_INPUT	0x0001
#define DH_MATRIX_CARD_OUTPUT	0x0002
#define DH_MATRIX_CARD_ENCODE	0x0004
#define DH_MATRIX_CARD_DECODE	0x0008

// Matrix sub card info
typedef struct tagDH_MATRIX_CARD
{
	DWORD				dwSize;
	BOOL				bEnable;					// Valid or not
	DWORD				dwCardType;					// Sub card type
	char		    	szInterface[DH_MATRIX_INTERFACE_LEN];	// Signal interface type, "CVBS", "VGA", "DVI"...
	char		    	szAddress[DH_MAX_IPADDR_OR_DOMAIN_LEN];	// Device IP or domain name. The sub card that has no network conneciton can be null.
	int			    	nPort;						// Port No. The sub card that has no network conneciton can be 0.
	int					nDefinition;				// Definition. 0=standard definition. 1=High definition
	int					nVideoInChn;				// Video input channel amount
	int					nAudioInChn;				// Audio input channel amount
	int					nVideoOutChn;				// Video output channel amount
	int				    nAudioOutChn;				// Audio output channel amount
	int			    	nVideoEncChn;				// Video encode channel amount
	int				    nAudioEncChn;				// Audio encode channel amount
	int			    	nVideoDecChn;				// Video decode channel amount
	int			    	nAudioDecChn;				// Audio decode channel amount
	int					nStauts;					// Status: 0-OK, 1-no respond, 2-network disconnection, 3-conflict, 4-upgrading now
	int					nCommPorts;					// COM amount
	int					nVideoInChnMin;				// Video input channel min value
	int					nVideoInChnMax;				// Video input channel max value
	int					nAudioInChnMin;				// Audio input channel min value
	int					nAudioInChnMax;				// Audio input channel max value
	int					nVideoOutChnMin;			// Video output channel min value
	int					nVideoOutChnMax;			// Video output channel max value
	int					nAudioOutChnMin;			// Audio output channel min value
	int					nAudioOutChnMax;			// Audio output channel max value	
	int					nVideoEncChnMin;			// Video encode channel min value
	int					nVideoEncChnMax;			// Video encode channel max value
	int					nAudioEncChnMin;			// Audio encode channel min value
	int					nAudioEncChnMax;			// Audio encode channel max value
	int					nVideoDecChnMin;			// Video decode channel min value
	int					nVideoDecChnMax;			// Video decode channel max value
	int					nAudioDecChnMin;			// Audio decode channel min value
	int					nAudioDecChnMax;			// Audio decode channel max value
} DH_MATRIX_CARD;

// Matrix sub card list
typedef struct tagDH_MATRIX_CARD_LIST 
{
	DWORD				dwSize;
	int					nCount;							// sub card  amount
	DH_MATRIX_CARD		stuCards[DH_MATRIX_MAX_CARDS];	// Sub card list 
} DH_MATRIX_CARD_LIST;

// Video output window
typedef struct tagDH_VIDEO_OUT_WINDOW
{
	DWORD				dwSize;
	int					nBackboardID;				// Backboard ID
	int					nScreenID;					// Screen ID
	int					nWindowID;					// Window ID
} DH_VIDEO_OUT_WINDOW;

// CLIENT_GetISCSITargets
typedef struct tagDH_IN_ISCSI_TARGETS 
{
	DWORD				dwSize;
	const char*			pszAddress;					// Server address
	int					nPort;						// port
	const char*			pszUser;					// Username
	const char*			pszPwd;						// Password
} DH_IN_ISCSI_TARGETS;

// ISCSI Target Info
typedef struct tagDH_ISCSI_TARGET 
{
	DWORD				dwSize;
	char				szName[DH_MAX_ISCSI_NAME_LEN];	// Name
} DH_ISCSI_TARGET;

// CLIENT_GetISCSITargets Interface output parameter
typedef struct tagDH_OUT_ISCSI_TARGETS
{
	DWORD				dwSize;
	DH_ISCSI_TARGET*	pstuTargets;				// iscsi array
	int					nMaxCount;					// iscsi group size
	int					nRetCount;					// Received iscSi amount
} DH_OUT_ISCSI_TARGETS;

// Storage device name
typedef struct tagDH_STORAGE_DEVICE_NAME 
{
	DWORD				dwSize;
	char				szName[DH_STORAGE_NAME_LEN];
} DH_STORAGE_DEVICE_NAME;
// RAID state
#define DH_RAID_STATE_ACTIVE		0x00000001
#define DH_RAID_STATE_INACTIVE		0x00000002
#define DH_RAID_STATE_CLEAN			0x00000004
#define DH_RAID_STATE_FAILED		0x00000008
#define DH_RAID_STATE_DEGRADED		0x00000010
#define DH_RAID_STATE_RECOVERING	0x00000020
#define DH_RAID_STATE_RESYNCING		0x00000040
#define DH_RAID_STATE_RESHAPING		0x00000080
#define DH_RAID_STATE_CHECKING		0x00000100
#define DH_RAID_STATE_NOTSTARTED	0x00000200

// RAID Info
typedef struct tagDH_STORAGE_RAID
{
	DWORD				dwSize;
	int					nLevel;										// level
	int					nState;										// RAID state combinationDH_RAID_STATE_ACTIVE | DH_RAID_STATE_DEGRADED
	int					nMemberNum;									// member amount
	char				szMembers[DH_MAX_MEMBER_PER_RAID][DH_STORAGE_NAME_LEN];	// RAID member
} DH_STORAGE_RAID;

// Storage partition info
typedef struct tagDH_STORAGE_PARTITION
{
	DWORD				dwSize;
	char				szName[DH_STORAGE_NAME_LEN];				// Name
	DWORD				dwTotalSpace;								//Total space(MB) 
	DWORD				dwFreeSpace;								// free space(MB)
	char				szMountOn[DH_STORAGE_MOUNT_LEN];			// Mount point
	char				szFileSystem[DH_STORAGE_FILE_SYSTEM_LEN];	//File system
	int					nStatus;									// partition state, 0-LV not available, 1-LV available
} DH_STORAGE_PARTITION;

// Storage device info
typedef struct tagDH_STORAGE_DEVICE 
{
	DWORD				dwSize;
	char				szName[DH_STORAGE_NAME_LEN];				// name
	DWORD				dwTotalSpace;								// Total space (MB) 
	DWORD				dwFreeSpace;								// free space (MB) 
	BYTE				byMedia;									// Media, 0-DISK, 1-CDROM, 2-FLASH medium,  
	BYTE				byBUS;										// BUS, 0-ATA, 1-SATA, 2-USB, 3-SDIO, 4-SCSI main line 0-ATA, 1-SATA, 2-USB, 3-SDIO, 4-SCSI
	BYTE				byVolume;									// volume type, 0-physics, 1-Raid, 2- VG virtual 
	BYTE				byState;									// Physics disk state, 0-physics disk offline state 1-physics disk  2- RAID activity 3- RAID sync 4-RAID hotspare 5-RAID invalidation 6- RAID re-creation  7- RAID delete
	int					nPhysicNo;									// storage interface of devices of same type logic number
	int					nLogicNo;									// storage interface of devices of same type physics number
	char				szParent[DH_STORAGE_NAME_LEN];				// superior storage group name
	char				szModule[DH_STORAGE_NAME_LEN];				// device module
	char				szSerial[DH_SERIALNO_LEN];					// device serial number
	char				szFirmware[DH_VERSION_LEN];					// Firmware version
	int					nPartitionNum;								//partition number
	DH_STORAGE_PARTITION stuPartitions[DH_MAX_STORAGE_PARTITION_NUM];// partition info
	DH_STORAGE_RAID		stuRaid;									// Raid info, for RAID use only(byVolume == 1) 
	DH_ISCSI_TARGET		stuISCSI;									// Iscsi info, for iscsi use only (byVolume == 2)
} DH_STORAGE_DEVICE; 
////////////////////////////////// System status////////////////////////////////////////

// CPU info
typedef struct tagDH_CPU_INFO
{
	DWORD				dwSize;
	int					nUsage;						// CPU usage
} DH_CPU_INFO;

// CPU status
typedef struct tagDH_CPU_STATUS
{
	DWORD				dwSize;
	BOOL				bEnable;					// Search succeeded or not
	int					nCount;						// CPU amount
	DH_CPU_INFO			stuCPUs[DH_MAX_CPU_NUM];	// CPU info
} DH_CPU_STATUS;

// Memory info
typedef struct tagDH_MEMORY_INFO
{
	DWORD				dwSize;
	DWORD				dwTotal;					// Total memory, M
	DWORD				dwFree;						// Free memory, M
} DH_MEMORY_INFO;

// Memory status
typedef struct tagDH_MEMORY_STATUS 
{
	DWORD				dwSize;
	BOOL				bEnable;					// Search succeeded or not
	DH_MEMORY_INFO		stuMemory;					// Memory info
} DH_MEMORY_STATUS;

// Fan info
typedef struct tagDH_FAN_INFO
{
	DWORD				dwSize;
	char				szName[DH_DEVICE_NAME_LEN];	// Name
	DWORD				nSpeed;						// Speed
} DH_FAN_INFO;

// Fan status
typedef struct tagDH_FAN_STATUS
{
	DWORD				dwSize;
	BOOL				bEnable;					// Search succeeded or not
	int					nCount;						// Fan amount
	DH_FAN_INFO			stuFans[DH_MAX_FAN_NUM];	// Fan status
} DH_FAN_STATUS;

// Power info
typedef struct tagDH_POWER_INFO
{
	DWORD				dwSize;
	BOOL				bPowerOn;					// Power is on or not
} DH_POWER_INFO;

// Power status
typedef struct tagDH_POWER_STATUS
{
	DWORD				dwSize;
	BOOL				bEnable;					//Search succeeded or not
	int					nCount;						// Power amount
	DH_POWER_INFO		stuPowers[DH_MAX_POWER_NUM];// Power status
} DH_POWER_STATUS;

// Temperature info
typedef struct tagDH_TEMPERATURE_INFO
{
	DWORD				dwSize;
	char				szName[DH_DEVICE_NAME_LEN];	// Sensor name
	float				fTemperature;				// Temperature
} DH_TEMPERATURE_INFO;

//Temperature status
typedef struct tagDH_TEMPERATURE_STATUS
{
	DWORD				dwSize;
	BOOL				bEnable;							// Search succeeded or not
	int					nCount;								// Temperature  amount
	DH_TEMPERATURE_INFO	stuTemps[DH_MAX_TEMPERATURE_NUM];	// Temperature  info
} DH_TEMPERATURE_STATUS;

// System status
typedef struct tagDH_SYSTEM_STATUS
{
	DWORD				dwSize;
	DH_CPU_STATUS*		pstuCPU;					// CPU status
	DH_MEMORY_STATUS*	pstuMemory;					// Memory status
	DH_FAN_STATUS*		pstuFan;					// Fan status
	DH_POWER_STATUS*	pstuPower;					// Power status
	DH_TEMPERATURE_STATUS*	pstuTemp;				// Temperature  status
} DH_SYSTEM_STATUS;

/************************************************************************
 ** Callback Function Definition 
 ***********************************************************************/

// Network disconnection callback function original shape 
typedef void (CALLBACK *fDisConnect)(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);

// network re-connection callback function original shape
typedef void (CALLBACK *fHaveReConnect)(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);

// The prototype of dynamic sub connection offline call function 
typedef void (CALLBACK *fSubDisConnect)(EM_INTERFACE_TYPE emInterfaceType, BOOL bOnline, LLONG lOperateHandle, LLONG lLoginID, LDWORD dwUser);

// monitor disconnect callback function
typedef void (CALLBACK *fRealPlayDisConnect)(LLONG lOperateHandle, EM_REALPLAY_DISCONNECT_EVENT_TYPE dwEventType, void* param, LDWORD dwUser);

// Real-time monitor data callback function original shape
typedef void (CALLBACK *fRealDataCallBack)(LLONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser);

// Real-time monitor data callback function original shape---extensive
typedef void (CALLBACK *fRealDataCallBackEx)(LLONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, LONG param, LDWORD dwUser);

// OSD callback function original shape 
typedef void (CALLBACK *fDrawCallBack)(LLONG lLoginID, LLONG lPlayHandle, HDC hDC, LDWORD dwUser);

// Playback data callback function original shape 
typedef int (CALLBACK *fDataCallBack)(LLONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser);

// Playback process callback function original shape 
typedef void (CALLBACK *fDownLoadPosCallBack)(LLONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, LDWORD dwUser);

// Playback process by time callback function original shape
typedef void (CALLBACK *fTimeDownLoadPosCallBack) (LLONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, int index, NET_RECORDFILE_INFO recordfileinfo, LDWORD dwUser);

// Alarm message callback function original shape
typedef BOOL (CALLBACK *fMessCallBack)(LONG lCommand, LLONG lLoginID, char *pBuf, DWORD dwBufLen, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);

// Listening server callback function original shape
typedef int (CALLBACK *fServiceCallBack)(LLONG lHandle, char *pIp, WORD wPort, LONG lCommand, void *pParam, DWORD dwParamLen, LDWORD dwUserData);

// Audio data of audio talk callback function original shape 
typedef void (CALLBACK *pfAudioDataCallBack)(LLONG lTalkHandle, char *pDataBuf, DWORD dwBufSize, BYTE byAudioFlag, LDWORD dwUser);

// Upgrade device callback function original shape
typedef void (CALLBACK *fUpgradeCallBack) (LLONG lLoginID, LLONG lUpgradechannel, int nTotalSize, int nSendSize, LDWORD dwUser);

// Transparent COM callback function original shape
typedef void (CALLBACK *fTransComCallBack) (LLONG lLoginID, LLONG lTransComChannel, char *pBuffer, DWORD dwBufSize, LDWORD dwUser);

// Search device log data callback function original shape 
typedef void (CALLBACK *fLogDataCallBack)(LLONG lLoginID, char *pBuffer, DWORD dwBufSize, DWORD nTotalSize, BOOL bEnd, LDWORD dwUser);

// Snapshot callback function original shape 
typedef void (CALLBACK *fSnapRev)(LLONG lLoginID, BYTE *pBuf, UINT RevLen, UINT EncodeType, DWORD CmdSerial, LDWORD dwUser);

// GPS message subscription callback 
typedef void( CALLBACK *fGPSRev)(LLONG lLoginID, GPS_Info GpsInfo, LDWORD dwUserData);

// GPSGPS message subscription callback - extra
typedef void (CALLBACK *fGPSRevEx)(LLONG lLoginID, GPS_Info GpsInfo, ALARM_STATE_INFO stAlarmInfo, LDWORD dwUserData, void *reserved);

// GPS GPS subscription of temperature and humidity callback
typedef void (CALLBACK *fGPSTempHumidityRev)(LLONG lLoginID, GPS_TEMP_HUMIDITY_INFO GpsTHInfo, LDWORD dwUserData);

// Asynchronous data callback
typedef void (CALLBACK *fMessDataCallBack)(LLONG lCommand, LPNET_CALLBACK_DATA lpData, LDWORD dwUser);

// File Transfer callback
typedef void (CALLBACK *fTransFileCallBack)(LLONG lHandle, int nTransType, int nState, int nSendSize, int nTotalSize, LDWORD dwUser);

// intelligent analysis data callback;nSequence instruct the repeat picture's station,0 instruct the first time it appear, 2 instruct the last time it appear or it only appear once,1 instruct it will appear next time
// int nState = (int) reserved instruct current callback data's state, 0 means realtime data,1 means offline data,2 means send offline data over
typedef int  (CALLBACK *fAnalyzerDataCallBack)(LLONG lAnalyzerHandle, DWORD dwAlarmType, void* pAlarmInfo, BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser, int nSequence, void *reserved);

// Asynchronism search device call
typedef void (CALLBACK *fSearchDevicesCB)(DEVICE_NET_INFO_EX *pDevNetInfo, void* pUserData);

/************************************************************************
 ** Interface Definition 
 ***********************************************************************/

// SDK Initialization 
CLIENT_API BOOL CALL_METHOD CLIENT_Init(fDisConnect cbDisConnect, LDWORD dwUser);

// SDK exit and clear
CLIENT_API void CALL_METHOD CLIENT_Cleanup();

//------------------------------------------------------------------------

// Set re-connection callback function after disconnection. Internal SDK  auto connect again after disconnection 
CLIENT_API void CALL_METHOD CLIENT_SetAutoReconnect(fHaveReConnect cbAutoConnect, LDWORD dwUser);

// Dynamic sub-set link disconnected callback function, the current monitoring and playback equipment SVR is a short connection
CLIENT_API void CALL_METHOD CLIENT_SetSubconnCallBack(fSubDisConnect cbSubDisConnect, LDWORD dwUser);

// Return the function execution failure code
CLIENT_API DWORD CALL_METHOD CLIENT_GetLastError(void);

// Set device connection timeout value and trial times 
CLIENT_API void CALL_METHOD CLIENT_SetConnectTime(int nWaitTime, int nTryTimes);

// Set log in network environment 
CLIENT_API void CALL_METHOD CLIENT_SetNetworkParam(NET_PARAM *pNetParam);

// Get SDK version information 
CLIENT_API DWORD CALL_METHOD CLIENT_GetSDKVersion();

//------------------------------------------------------------------------

// Register to the device 
CLIENT_API LLONG CALL_METHOD CLIENT_Login(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, LPNET_DEVICEINFO lpDeviceInfo, int *error = 0);

// Expension interfacenSpecCap =0 is login under TCP mode£¬ nSpecCap =2 is login with active registeration£¬ nSpecCap =3 is login under multicast mode£¬
//			 nSpecCap =4 is login under UDP mode£¬ nSpecCap =6 is login with main connection£¬nSpecCap =7 is SSL encription
//			  £¬nSpecCap =8 is Chengdu Jiafa login
//			 nSpecCap=9 is login in to remote device, enter void* pCapParam as remote device name
//          nSpecCap = 12 is login under LDAP mode
//          nSpecCap = 13 is login under AD mode
CLIENT_API LLONG CALL_METHOD CLIENT_LoginEx(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, int nSpecCap, void* pCapParam, LPNET_DEVICEINFO lpDeviceInfo, int *error = 0);

// Log out the device 
CLIENT_API BOOL CALL_METHOD CLIENT_Logout(LLONG lLoginID);

//------------------------------------------------------------------------

// Begin real-time monitor 
CLIENT_API LLONG CALL_METHOD CLIENT_RealPlay(LLONG lLoginID, int nChannelID, HWND hWnd);

// Begin real-time monitor--extensive
CLIENT_API LLONG CALL_METHOD CLIENT_RealPlayEx(LLONG lLoginID, int nChannelID, HWND hWnd, DH_RealPlayType rType = DH_RType_Realplay);

//start real-time monitor
CLIENT_API LLONG CALL_METHOD CLIENT_StartRealPlay(LLONG lLoginID, int nChannelID, HWND hWnd, DH_RealPlayType rType, fRealDataCallBackEx cbRealData, fRealPlayDisConnect cbDisconnect, LDWORD dwUser, DWORD dwWaitTime = 10000);

// Multiple-window preview 
CLIENT_API LLONG CALL_METHOD CLIENT_MultiPlay(LLONG lLoginID, HWND hWnd);

// Stop multiple-window preview 
CLIENT_API BOOL CALL_METHOD CLIENT_StopMultiPlay(LLONG lMultiHandle);

// Snapshot;hPlayHandle is monitor or playback handle
CLIENT_API BOOL CALL_METHOD CLIENT_CapturePicture(LLONG hPlayHandle, const char *pchPicFileName);

// Set real-time monitor data callback 
CLIENT_API BOOL CALL_METHOD CLIENT_SetRealDataCallBack(LLONG lRealHandle, fRealDataCallBack cbRealData, LDWORD dwUser);

// Set real-time monitor data callback--extensive 
CLIENT_API BOOL CALL_METHOD CLIENT_SetRealDataCallBackEx(LLONG lRealHandle, fRealDataCallBackEx cbRealData, LDWORD dwUser, DWORD dwFlag);

// Set video fluency
CLIENT_API BOOL	CALL_METHOD CLIENT_AdjustFluency(LLONG lRealHandle, int nLevel);

// Save data as file
CLIENT_API BOOL CALL_METHOD CLIENT_SaveRealData(LLONG lRealHandle, const char *pchFileName);

// Stop saving data as file 
CLIENT_API BOOL CALL_METHOD CLIENT_StopSaveRealData(LLONG lRealHandle);

// Set video property
CLIENT_API BOOL CALL_METHOD CLIENT_ClientSetVideoEffect(LLONG lPlayHandle, unsigned char nBrightness, unsigned char nContrast, unsigned char nHue, unsigned char nSaturation);

// Get video property 
CLIENT_API BOOL CALL_METHOD CLIENT_ClientGetVideoEffect(LLONG lPlayHandle, unsigned char *nBrightness, unsigned char *nContrast, unsigned char *nHue, unsigned char *nSaturation);

// Set screen overlay callback 
CLIENT_API void CALL_METHOD CLIENT_RigisterDrawFun(fDrawCallBack cbDraw, LDWORD dwUser);

// Open audio 
CLIENT_API BOOL CALL_METHOD CLIENT_OpenSound(LLONG hPlayHandle);

// Set volume;lPlayHandle is monitor handle or playabck handle 
CLIENT_API BOOL CALL_METHOD CLIENT_SetVolume(LLONG lPlayHandle, int nVolume);

// Stop audio 
CLIENT_API BOOL CALL_METHOD CLIENT_CloseSound();

// Stop real-time preview 
CLIENT_API BOOL CALL_METHOD CLIENT_StopRealPlay(LLONG lRealHandle);

// stop real-time preview-extensive
CLIENT_API BOOL CALL_METHOD CLIENT_StopRealPlayEx(LLONG lRealHandle);

//------------------------------------------------------------------------

// general PTZ control
CLIENT_API BOOL CALL_METHOD CLIENT_PTZControl(LLONG lLoginID, int nChannelID, DWORD dwPTZCommand, DWORD dwStep, BOOL dwStop);

// Dahua PTZ control 
CLIENT_API BOOL CALL_METHOD CLIENT_DHPTZControl(LLONG lLoginID, int nChannelID, DWORD dwPTZCommand, unsigned char param1, unsigned char param2, unsigned char param3, BOOL dwStop,void* param4=NULL);

//  Dahua PTZ control extensive port. support 3D intelligent position
CLIENT_API BOOL CALL_METHOD CLIENT_DHPTZControlEx(LLONG lLoginID, int nChannelID, DWORD dwPTZCommand, LONG lParam1, LONG lParam2, LONG lParam3, BOOL dwStop);

//------------------------------------------------------------------------
// query record state everyday in the month
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRecordStatus(LLONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmMonth, char* pchCardid, LPNET_RECORD_STATUS pRecordStatus, int waittime=1000);

// Search whether there is recorded file in specified period
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRecordTime(LLONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmStart, LPNET_TIME tmEnd, char* pchCardid, BOOL *bResult, int waittime=1000);

// Search all recorded file sin the specified periods
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRecordFile(LLONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmStart, LPNET_TIME tmEnd, char* pchCardid, LPNET_RECORDFILE_INFO nriFileinfo, int maxlen, int *filecount, int waittime=1000, BOOL bTime = FALSE);

// search first 16 records
CLIENT_API BOOL CALL_METHOD CLIENT_QuickQueryRecordFile(LLONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmStart, LPNET_TIME tmEnd, char* pchCardid, LPNET_RECORDFILE_INFO nriFileinfo, int maxlen, int *filecount, int waittime=1000, BOOL bTime = FALSE);


// Query the first record time 
CLIENT_API BOOL CALL_METHOD CLIENT_QueryFurthestRecordTime(LLONG lLoginID, int nRecordFileType, char *pchCardid, NET_FURTHEST_RECORD_TIME* pFurthrestTime, int nWaitTime);

// Begin searching recorded file
CLIENT_API LLONG	CALL_METHOD CLIENT_FindFile(LLONG lLoginID, int nChannelId, int nRecordFileType, char* cardid, LPNET_TIME time_start, LPNET_TIME time_end, BOOL bTime, int waittime);

// Search recorded file 
CLIENT_API int	CALL_METHOD CLIENT_FindNextFile(LLONG lFindHandle,LPNET_RECORDFILE_INFO lpFindData);

// Stop searching recorded file 
CLIENT_API BOOL CALL_METHOD CLIENT_FindClose(LLONG lFindHandle);

// Playback in file 
CLIENT_API LLONG CALL_METHOD CLIENT_PlayBackByRecordFile(LLONG lLoginID, LPNET_RECORDFILE_INFO lpRecordFile, HWND hWnd, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwUserData);

// Playback in file--extensive
CLIENT_API LLONG CALL_METHOD CLIENT_PlayBackByRecordFileEx(LLONG lLoginID, LPNET_RECORDFILE_INFO lpRecordFile, HWND hWnd, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser, fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser);

// playback in file - disconnect callback
CLIENT_API LLONG CALL_METHOD CLIENT_StartPlayBackByRecordFile(LLONG lLoginID,  LPNET_RECORDFILE_INFO lpRecordFile, HWND hWnd, 
															 fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser, 
															 fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser, 
															 fRealPlayDisConnect fDisConnectCallBack, LDWORD dwDisUser, DWORD dwWaitTime = 10000);

//Playback in file--Drop frame playback (not enough bandwidth can be used)
CLIENT_API LLONG CALL_METHOD CLIENT_FramCotrolPlayBackByRecordFile(LLONG lLoginID, LPNET_RECORDFILE_INFO lpRecordFile, HWND hWnd, 
																   fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser, 
																   fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser, unsigned int nCutFrameRate);

// Playback in time
CLIENT_API LLONG CALL_METHOD CLIENT_PlayBackByTime(LLONG lLoginID, int nChannelID, LPNET_TIME lpStartTime, LPNET_TIME lpStopTime, HWND hWnd, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser);

// Playback in time--extensive
CLIENT_API LLONG CALL_METHOD CLIENT_PlayBackByTimeEx(LLONG lLoginID, int nChannelID, LPNET_TIME lpStartTime, LPNET_TIME lpStopTime, HWND hWnd, 
													 fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser, 
													 fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser);

// playback in time--disconnect callback
CLIENT_API LLONG CALL_METHOD CLIENT_StartPlayBackByTime(LLONG lLoginID, int nChannelID, 
													   LPNET_TIME lpStartTime, LPNET_TIME lpStopTime, HWND hWnd, 
													   fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser,
													   fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser, 
													   fRealPlayDisConnect fDisConnectCallBack, LDWORD dwDisUser, DWORD dwWaitTime = 10000);

//Playback in time--Drop frame playback (not enough bandwidth can be used)
CLIENT_API LLONG CALL_METHOD CLIENT_FramCotrolPlayBackByTime(LLONG lLoginID, int nChannelID, LPNET_TIME lpStartTime, LPNET_TIME lpStopTime, HWND hWnd, 
															 fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser, 
															 fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser, unsigned int nCutFrameRate);

// Locate recorded file playback start time 
CLIENT_API BOOL CALL_METHOD CLIENT_SeekPlayBack(LLONG lPlayHandle, unsigned int offsettime, unsigned int offsetbyte);

// Pause or restore file playback 
CLIENT_API BOOL CALL_METHOD CLIENT_PausePlayBack(LLONG lPlayHandle, BOOL bPause);

// Fast playback file 
CLIENT_API BOOL CALL_METHOD CLIENT_FastPlayBack(LLONG lPlayHandle);

// Slow playback file 
CLIENT_API BOOL CALL_METHOD CLIENT_SlowPlayBack(LLONG lPlayHandle);

// Step playback file 
CLIENT_API BOOL CALL_METHOD CLIENT_StepPlayBack(LLONG lPlayHandle, BOOL bStop);

// Control playback direction--Forward or Backward playback
CLIENT_API BOOL CALL_METHOD CLIENT_PlayBackControlDirection(LLONG lPlayHandle, BOOL bBackward);

// Set playback frame rate 
CLIENT_API BOOL CALL_METHOD CLIENT_SetFramePlayBack(LLONG lPlayHandle, int framerate);

// Get playback frame rate
CLIENT_API BOOL CALL_METHOD CLIENT_GetFramePlayBack(LLONG lPlayHandle, int *fileframerate, int *playframerate);

// Restore ordinary playback
CLIENT_API BOOL CALL_METHOD CLIENT_NormalPlayBack(LLONG lPlayHandle);

// smart search play back
CLIENT_API BOOL CALL_METHOD CLIENT_SmartSearchPlayBack(LLONG lPlayHandle, LPIntelligentSearchPlay lpPlayBackParam);

// Get playback OSD time 
CLIENT_API BOOL CALL_METHOD CLIENT_GetPlayBackOsdTime(LLONG lPlayHandle, LPNET_TIME lpOsdTime, LPNET_TIME lpStartTime, LPNET_TIME lpEndTime);

// Stop file playback 
CLIENT_API BOOL CALL_METHOD CLIENT_StopPlayBack(LLONG lPlayHandle);

// Download recorded file 
CLIENT_API LLONG CALL_METHOD CLIENT_DownloadByRecordFile(LLONG lLoginID,LPNET_RECORDFILE_INFO lpRecordFile, char *sSavedFileName, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwUserData);

// Download file by time 
CLIENT_API LLONG CALL_METHOD CLIENT_DownloadByTime(LLONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmStart, LPNET_TIME tmEnd, char *sSavedFileName, fTimeDownLoadPosCallBack cbTimeDownLoadPos, LDWORD dwUserData);

// Search record download process 
CLIENT_API BOOL CALL_METHOD CLIENT_GetDownloadPos(LLONG lFileHandle, int *nTotalSize, int *nDownLoadSize);

// Stop record download 
CLIENT_API BOOL CALL_METHOD CLIENT_StopDownload(LLONG lFileHandle);

//------------------------------------------------------------------------

// Set alarm callback function 
CLIENT_API void CALL_METHOD CLIENT_SetDVRMessCallBack(fMessCallBack cbMessage,LDWORD dwUser);

// subscribe alarm 
CLIENT_API BOOL CALL_METHOD CLIENT_StartListen(LLONG lLoginID);

// subscribe alarm---extensive
CLIENT_API BOOL CALL_METHOD CLIENT_StartListenEx(LLONG lLoginID);

// Stop subscribe alarm 
CLIENT_API BOOL CALL_METHOD CLIENT_StopListen(LLONG lLoginID);

//------------------------------------------------------------------------

// actively registration function. enable service. nTimeout is invalid. 
CLIENT_API LLONG CALL_METHOD CLIENT_ListenServer(char* ip, WORD port, int nTimeout, fServiceCallBack cbListen, LDWORD dwUserData);

// stop service
CLIENT_API BOOL CALL_METHOD CLIENT_StopListenServer(LLONG lServerHandle);

// Respond the registration requestion from the device 
CLIENT_API BOOL CALL_METHOD CLIENT_ResponseDevReg(char *devSerial, char* ip, WORD port, BOOL bAccept);

//------------------------------------------------------------------------

// Alarm upload function. Enable service. dwTimeOut paramter is invalid 
CLIENT_API LLONG CALL_METHOD CLIENT_StartService(WORD wPort, char *pIp = NULL, fServiceCallBack pfscb = NULL, DWORD dwTimeOut = 0xffffffff, LDWORD dwUserData = 0);

// Stop service 
CLIENT_API BOOL CALL_METHOD CLIENT_StopService(LLONG lHandle);

//------------------------------------------------------------------------

// Set audio talk mode(client-end mode or server mode)
CLIENT_API BOOL CALL_METHOD CLIENT_SetDeviceMode(LLONG lLoginID, EM_USEDEV_MODE emType, void* pValue);

// Enable audio talk 
CLIENT_API LLONG CALL_METHOD CLIENT_StartTalkEx(LLONG lLoginID, pfAudioDataCallBack pfcb, LDWORD dwUser);

// Begin PC record 
CLIENT_API BOOL CALL_METHOD CLIENT_RecordStart();

// Stop PC record 
CLIENT_API BOOL CALL_METHOD CLIENT_RecordStop();

// Send out audio data to the device 
CLIENT_API LONG CALL_METHOD CLIENT_TalkSendData(LLONG lTalkHandle, char *pSendBuf, DWORD dwBufSize);

// Decode audio data 
CLIENT_API void CALL_METHOD CLIENT_AudioDec(char *pAudioDataBuf, DWORD dwBufSize);

// Set audio talk volume
CLIENT_API BOOL CALL_METHOD CLIENT_SetAudioClientVolume(LLONG lTalkHandle, WORD wVolume);

// Stop audio talk 
CLIENT_API BOOL CALL_METHOD CLIENT_StopTalkEx(LLONG lTalkHandle);

// add device into broadcast group 
CLIENT_API BOOL CALL_METHOD CLIENT_AudioBroadcastAddDev(LLONG lLoginID);

// Remove device from the broadcast group 
CLIENT_API BOOL CALL_METHOD CLIENT_AudioBroadcastDelDev(LLONG lLoginID);

// audio encode-initialization(specified standard format, Dahua format)
CLIENT_API int  CALL_METHOD CLIENT_InitAudioEncode(DH_AUDIO_FORMAT aft);

// Audio encode--data encode
CLIENT_API int	CALL_METHOD	CLIENT_AudioEncode(LLONG lTalkHandle, BYTE *lpInBuf, DWORD *lpInLen, BYTE *lpOutBuf, DWORD *lpOutLen);

// audio encode--complete and then exit
CLIENT_API int	CALL_METHOD	CLIENT_ReleaseAudioEncode();

//------------------------------------------------------------------------

// Search device log
CLIENT_API BOOL CALL_METHOD CLIENT_QueryLog(LLONG lLoginID, char *pLogBuffer, int maxlen, int *nLogBufferlen, int waittime=3000);

// Search device log page by page.
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDeviceLog(LLONG lLoginID, QUERY_DEVICE_LOG_PARAM *pQueryParam, char *pLogBuffer, int nLogBufferLen, int *pRecLogNum, int waittime=3000);

// Search channel record status 
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRecordState(LLONG lLoginID, char *pRSBuffer, int maxlen, int *nRSBufferlen, int waittime=1000);

// Search channel extra record status (the returned byte number was equal to the channel number, every byte instruct the respond channel's state,0-stop,1-manual,2-schedule)
CLIENT_API BOOL CALL_METHOD CLIENT_QueryExtraRecordState(LLONG lLoginID, char *pRSBuffer, int maxlen, int *nRSBufferlen, void *pReserved, int waittime=1000);

// Search device status
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDevState(LLONG lLoginID, int nType, char *pBuf, int nBufLen, int *pRetLen, int waittime=1000);

// Search system capacity information 
CLIENT_API BOOL CALL_METHOD CLIENT_QuerySystemInfo(LLONG lLoginID, int nSystemType, char *pSysInfoBuffer, int maxlen, int *nSysInfolen, int waittime=1000);

// New Search system capacity information(by Json)
CLIENT_API BOOL CALL_METHOD CLIENT_QueryNewSystemInfo(LLONG lLoginID, char* szCommand, int nChannelID, char* szOutBuffer, DWORD dwOutBufferSize, int *error, int waittime=1000);

// Get channel bit stream 
CLIENT_API LONG CALL_METHOD CLIENT_GetStatiscFlux(LLONG lLoginID, LLONG lPlayHandle);

// Get PTZ information 
CLIENT_API BOOL  CALL_METHOD CLIENT_GetPtzOptAttr(LLONG lLoginID,DWORD dwProtocolIndex,LPVOID lpOutBuffer,DWORD dwBufLen,DWORD *lpBytesReturned,int waittime=500);

//------------------------------------------------------------------------

// Reboot device 
CLIENT_API BOOL CALL_METHOD CLIENT_RebootDev(LLONG lLoginID);

// Shut down devic e
CLIENT_API BOOL CALL_METHOD CLIENT_ShutDownDev(LLONG lLoginID);

// Device control 
CLIENT_API BOOL CALL_METHOD CLIENT_ControlDevice(LLONG lLoginID, CtrlType type, void *param, int waittime = 1000);

// Set channel record status 
CLIENT_API BOOL CALL_METHOD CLIENT_SetupRecordState(LLONG lLoginID, char *pRSBuffer, int nRSBufferlen);

// set channel extra record status
CLIENT_API BOOL CALL_METHOD CLIENT_SetupExtraRecordState(LLONG lLoginID, char *pRSBuffer, int nRSBufferlen, void* pReserved);

// Search IO status
CLIENT_API BOOL CALL_METHOD CLIENT_QueryIOControlState(LLONG lLoginID, DH_IOTYPE emType, 
                                           void *pState, int maxlen, int *nIOCount, int waittime=1000);

// IO control 
CLIENT_API BOOL CALL_METHOD CLIENT_IOControl(LLONG lLoginID, DH_IOTYPE emType, void *pState, int maxlen);

// Compulsive I frame
CLIENT_API BOOL CALL_METHOD CLIENT_MakeKeyFrame(LLONG lLoginID, int nChannelID, int nSubChannel=0);

//------------------------------------------------------------------------

// Search user information 
CLIENT_API BOOL CALL_METHOD CLIENT_QueryUserInfo(LLONG lLoginID, USER_MANAGE_INFO *info, int waittime=1000);

// Search user information--extensive
CLIENT_API BOOL CALL_METHOD CLIENT_QueryUserInfoEx(LLONG lLoginID, USER_MANAGE_INFO_EX *info, int waittime=1000);

// Search device info--Max supports device of 64-ch
CLIENT_API BOOL CALL_METHOD CLIENT_QueryUserInfoNew(LLONG lLoginID, USER_MANAGE_INFO_NEW *info, void* pReserved, int waittime = 1000);
// Device operation user 
CLIENT_API BOOL CALL_METHOD CLIENT_OperateUserInfo(LLONG lLoginID, int nOperateType, void *opParam, void *subParam, int waittime=1000);

// Device operation user--extensive
CLIENT_API BOOL CALL_METHOD CLIENT_OperateUserInfoEx(LLONG lLoginID, int nOperateType, void *opParam, void *subParam, int waittime=1000);

// User operates the device--Max supports device of 64-ch
CLIENT_API BOOL CALL_METHOD CLIENT_OperateUserInfoNew(LLONG lLoginID, int nOperateType, void *opParam, void *subParam, void* pReserved, int waittime = 1000);

//------------------------------------------------------------------------

// Create transparent COM channel 
CLIENT_API LLONG CALL_METHOD CLIENT_CreateTransComChannel(LLONG lLoginID, int TransComType, unsigned int baudrate, unsigned int databits, unsigned int stopbits, unsigned int parity, fTransComCallBack cbTransCom, LDWORD dwUser);

// Transparent COM send out data 
CLIENT_API BOOL CALL_METHOD CLIENT_SendTransComData(LLONG lTransComChannel, char *pBuffer, DWORD dwBufSize);

// Release transparent COM channel 
CLIENT_API BOOL CALL_METHOD CLIENT_DestroyTransComChannel(LLONG lTransComChannel);

// Query the status of a transparent serial port
CLIENT_API BOOL CALL_METHOD CLIENT_QueryTransComParams(LLONG lLoginID, int TransComType, DH_COMM_STATE* pCommState, int nWaitTime = 500);

//------------------------------------------------------------------------

// Begin upgrading device program 
CLIENT_API LLONG CALL_METHOD CLIENT_StartUpgrade(LLONG lLoginID, char *pchFileName, fUpgradeCallBack cbUpgrade, LDWORD dwUser);

// Begin upgrading device program--extensive
CLIENT_API LLONG CALL_METHOD CLIENT_StartUpgradeEx(LLONG lLoginID, EM_UPGRADE_TYPE emType, char *pchFileName, fUpgradeCallBack cbUpgrade, LDWORD dwUser);

// Send out data
CLIENT_API BOOL CALL_METHOD CLIENT_SendUpgrade(LLONG lUpgradeID);

// Stop upgrading device program 
CLIENT_API BOOL CALL_METHOD CLIENT_StopUpgrade(LLONG lUpgradeID);

//------------------------------------------------------------------------

// Search configuration information 
CLIENT_API BOOL  CALL_METHOD CLIENT_GetDevConfig(LLONG lLoginID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned,int waittime=500);

// Set configuration information 
CLIENT_API BOOL  CALL_METHOD CLIENT_SetDevConfig(LLONG lLoginID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize, int waittime=500);

// New configuration interface, Search configuration information(using Json protocol, see configuration SDK)
CLIENT_API BOOL CALL_METHOD CLIENT_GetNewDevConfig(LLONG lLoginID, char* szCommand, int nChannelID, char* szOutBuffer, DWORD dwOutBufferSize, int *error, int waittime=500);

// New configuration interface, Set configuration information(using Json protocol, see configuration SDK)
CLIENT_API BOOL CALL_METHOD CLIENT_SetNewDevConfig(LLONG lLoginID, char* szCommand, int nChannelID, char* szInBuffer, DWORD dwInBufferSize, int *error, int *restart, int waittime=500);

// Delete configuration interface(Json format)
CLIENT_API BOOL CALL_METHOD CLIENT_DeleteDevConfig(LLONG lLoginID, NET_IN_DELETECFG* pInParam, NET_OUT_DELETECFG* pOutParam, int waittime=500);

// Get the configuration member name interface(Json format)
CLIENT_API BOOL CALL_METHOD CLIENT_GetMemberNames(LLONG lLoginID, NET_IN_MEMBERNAME* pInParam, NET_OUT_MEMBERNAME* pOutParam, int waittime=500);

//------------------------------------------------------------------------

// Search device channel name 
CLIENT_API BOOL CALL_METHOD CLIENT_QueryChannelName(LLONG lLoginID, char *pChannelName, int maxlen, int *nChannelCount, int waittime=1000);

// Set device channel name
CLIENT_API BOOL  CALL_METHOD CLIENT_SetupChannelName(LLONG lLoginID,char *pbuf, int nbuflen);

// Set device channel character overlay 
CLIENT_API BOOL  CALL_METHOD CLIENT_SetupChannelOsdString(LLONG lLoginID, int nChannelNo, DH_CHANNEL_OSDSTRING* struOsdString, int nbuflen);

// Search device current time
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDeviceTime(LLONG lLoginID, LPNET_TIME pDeviceTime, int waittime=1000);

// Set device current time
CLIENT_API BOOL CALL_METHOD CLIENT_SetupDeviceTime(LLONG lLoginID, LPNET_TIME pDeviceTime);

// Set device max bit stream
CLIENT_API BOOL CALL_METHOD CLIENT_SetMaxFlux(LLONG lLoginID, WORD wFlux);

//------------------------------------------------------------------------

// Import configuration file 
CLIENT_API LLONG CALL_METHOD CLIENT_ImportConfigFile(LLONG lLoginID, char *szFileName, fDownLoadPosCallBack cbUploadPos, LDWORD dwUserData, DWORD param=0);

// Stop importing configuration file
CLIENT_API BOOL CALL_METHOD CLIENT_StopImportCfgFile(LLONG lImportHandle);

// Exporting configuration file
CLIENT_API LLONG CALL_METHOD CLIENT_ExportConfigFile(LLONG lLoginID, DH_CONFIG_FILE_TYPE emConfigFileType, char *szSavedFilePath, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwUserData);

// top exporting configuration file
CLIENT_API BOOL CALL_METHOD CLIENT_StopExportCfgFile(LLONG lExportHandle);

//------------------------------------------------------------------------

// Search device IP in DDBS by device name or device serial number
CLIENT_API BOOL CALL_METHOD CLIENT_GetDVRIPByResolveSvr(char *pchDVRIP, WORD wDVRPort, BYTE *sDVRName, WORD wDVRNameLen, BYTE *sDVRSerialNumber, WORD wDVRSerialLen, char* sGetIP);

// Search IPC,NVS and etc in LAN 
CLIENT_API BOOL CALL_METHOD CLIENT_SearchDevices(char* szBuf, int nBufLen, int* pRetLen, DWORD dwSearchTime, char* szLocalIp=NULL);

// asynchronism search IPC, NVS and etc in LAN
CLIENT_API LLONG CALL_METHOD CLIENT_StartSearchDevices(fSearchDevicesCB cbSearchDevices, void* pUserData, char* szLocalIp=NULL);

// stop asynchronism search IPC, NVS and etc in LAN
CLIENT_API BOOL CALL_METHOD CLIENT_StopSearchDevices(LLONG lSearchHandle);

// modify Device ip
CLIENT_API BOOL CALL_METHOD CLIENT_ModifyDevice(DEVICE_NET_INFO_EX *pDevNetInfo, DWORD dwWaitTime, int *iError = NULL, char* szLocalIp = NULL, void *reserved = NULL);

// search device ip cross VLAN
CLIENT_API BOOL CALL_METHOD CLIENT_SearchDevicesByIPs(DEVICE_IP_SEARCH_INFO* pIpSearchInfo, fSearchDevicesCB cbSearchDevices, LDWORD dwUserData, char* szLocalIp, DWORD dwWaitTime);
//------------------------------------------------------------------------

// Platform embedded interface
CLIENT_API BOOL CALL_METHOD CLIENT_GetPlatFormInfo(LLONG lLoginID, DWORD dwCommand, int nSubCommand, int nParam, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned,int waittime=500);
CLIENT_API BOOL CALL_METHOD CLIENT_SetPlatFormInfo(LLONG lLoginID, DWORD dwCommand, int nSubCommand, int nParam, LPVOID lpInBuffer, DWORD dwInBufferSize, int waittime=500);


///////////////////////////////Mobile DVR interface///////////////////////////////

// Set snapshot callback function 
CLIENT_API void CALL_METHOD CLIENT_SetSnapRevCallBack(fSnapRev OnSnapRevMessage, LDWORD dwUser);

// Snapshot request
CLIENT_API BOOL CALL_METHOD CLIENT_SnapPicture(LLONG lLoginID, SNAP_PARAMS par);

// Snapshot request--extensive
CLIENT_API BOOL CALL_METHOD CLIENT_SnapPictureEx(LLONG lLoginID, SNAP_PARAMS *par, int *reserved = 0);

// Set GPS subscription callback function 
CLIENT_API void CALL_METHOD CLIENT_SetSubcribeGPSCallBack(fGPSRev OnGPSMessage, LDWORD dwUser);

// Set GPS subscription callback function - extensive
CLIENT_API void CALL_METHOD CLIENT_SetSubcribeGPSCallBackEX(fGPSRevEx OnGPSMessage, LDWORD dwUser);

// GPS message subscription 
CLIENT_API BOOL CALL_METHOD CLIENT_SubcribeGPS (LLONG lLoginID, BOOL bStart, LONG KeepTime, LONG InterTime);

// Set GPS subscription of temperature and humidity callback function
CLIENT_API void CALL_METHOD CLIENT_SetSubcribeGPSTHCallBack(fGPSTempHumidityRev OnGPSMessage, LDWORD dwUser);

// GPS subscription of temperature and humidity
CLIENT_API BOOL CALL_METHOD CLIENT_SubcribeGPSTempHumidity (LLONG lLoginID, BOOL bStart,	int InterTime, void* Reserved);

//GPS log query
CLIENT_API BOOL CALL_METHOD CLIENT_QueryGPSLog(LLONG lLoginID,QUERY_GPS_LOG_PARAM *pQueryParam, char *pLogBuffer, int nLogBufferLen, int *pRecLogNum, BOOL *bContinue, int waittime);

//////////////////////////////NVD interface//////////////////////////////

// Query decoder information
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDecoderInfo(LLONG lLoginID, LPDEV_DECODER_INFO lpDecInfo, int waittime=1000);

// Query decoder TV information
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDecoderTVInfo(LLONG lLoginID, int nMonitorID, LPDEV_DECODER_TV lpMonitorInfo, int waittime=1000);

// Query decoder channel information
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDecEncoderInfo(LLONG lLoginID, int nDecoderID, LPDEV_ENCODER_INFO lpEncoderInfo, int waittime=1000);

// Set decoder TV enable
CLIENT_API BOOL CALL_METHOD CLIENT_SetDecTVOutEnable(LLONG lLoginID, BYTE *pDecTVOutEnable, int nBufLen, int waittime=1000);

// set decoder tip layout enable, channel number start at 0
CLIENT_API BOOL CALL_METHOD CLIENT_SetDecLayOutEnable(LLONG lLoginID, BYTE bDecLayOutEnable, int nChannel, int waittime=1000);
//------------------------------------------------------------------------

// Set up asynchronous callback function
CLIENT_API BOOL CALL_METHOD CLIENT_SetOperateCallBack(LLONG lLoginID, fMessDataCallBack cbMessData, LDWORD dwUser);

// Control decoder TV screen partition,Interface is asynchronous
CLIENT_API LLONG CALL_METHOD CLIENT_CtrlDecTVScreen(LLONG lLoginID, int nMonitorID, BOOL bEnable, int nSplitType, BYTE *pEncoderChannel, int nBufLen, void* userdata=NULL);

// Switch decoder TV screen,Interface is asynchronous
// According to nMonitorID(TV ID)?¡énWndID(Screen ID) Convert to nDecoderID(decoder channel) formula:nEncoderID¡ê?nMonitorID*nSplitNum(Partition number)+nWndID
CLIENT_API LLONG CALL_METHOD CLIENT_SwitchDecTVEncoder(LLONG lLoginID, int nDecoderID, LPDEV_ENCODER_INFO lpEncoderInfo, void* userdata=NULL);

//------------------------------------------------------------------------

// Add combination of screen
CLIENT_API int CALL_METHOD CLIENT_AddTourCombin(LLONG lLoginID, int nMonitorID, int nSplitType, BYTE *pEncoderChannnel, int nBufLen, int waittime=1000);

// Delete combination of screen
CLIENT_API BOOL CALL_METHOD CLIENT_DelTourCombin(LLONG lLoginID, int nMonitorID, int nCombinID, int waittime=1000);

// Modify combination of screen
CLIENT_API BOOL CALL_METHOD CLIENT_SetTourCombin(LLONG lLoginID, int nMonitorID, int nCombinID, int nSplitType, BYTE *pEncoderChannel, int nBufLen, int waittime=1000);

// Query combination of screen,nCombinID: 0??32
CLIENT_API BOOL CALL_METHOD CLIENT_QueryTourCombin(LLONG lLoginID, int nMonitorID, int nCombinID, LPDEC_COMBIN_INFO lpDecCombinInfo, int waittime=1000);

// Set up tour operation
CLIENT_API BOOL CALL_METHOD CLIENT_SetDecoderTour(LLONG lLoginID, int nMonitorID, LPDEC_TOUR_COMBIN lpDecTourInfo, int waittime=1000);

// Query tour operation
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDecoderTour(LLONG lLoginID, int nMonitorID, LPDEC_TOUR_COMBIN lpDecTourInfo, int waittime=1000);

// Query the current flux information of decoding channel
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDecChannelFlux(LLONG lLoginID, int nDecoderID, LPDEV_DECCHANNEL_STATE lpChannelStateInfo, int waittime=1000);

// control decoder tour operation
CLIENT_API BOOL CALL_METHOD CLIENT_CtrlDecoderTour(LLONG lLoginID, int nMonitorID, DEC_CTRL_TOUR_TYPE emActionParam, int waittime = 1000);
//------------------------------------------------------------------------

typedef void (CALLBACK *fDecPlayBackPosCallBack)(LLONG lLoginID, int nEncoderID, DWORD dwTotalSize, DWORD dwPlaySize, LDWORD dwUser);

// Set the playback progress callback function
CLIENT_API BOOL CALL_METHOD CLIENT_SetDecPlaybackPos(LLONG lLoginID, fDecPlayBackPosCallBack cbPlaybackPos, LDWORD dwUser);

// Decoder TV screen playback,Interface is asynchronous
CLIENT_API LLONG CALL_METHOD CLIENT_DecTVPlayback(LLONG lLoginID, int nDecoderID, DEC_PLAYBACK_MODE emPlaybackMode, LPVOID lpInBuffer, DWORD dwInBufferSize, void* userdata=NULL);

// Control TV screen playback
CLIENT_API BOOL CALL_METHOD CLIENT_CtrlDecPlayback(LLONG lLoginID, int nDecoderID, DEC_CTRL_PLAYBACK_TYPE emCtrlType, int nValue, int waittime=1000);

///////////////////////////////intelligent device interface///////////////////////////////

// real load picture of intelligent analysis 
CLIENT_API LLONG CALL_METHOD CLIENT_RealLoadPicture(LLONG lLoginID, int nChannelID, DWORD dwAlarmType, fAnalyzerDataCallBack cbAnalyzerData, LDWORD dwUser);

// real load picture of intelligent analysis(expand interface: 'bNeedPicFile == true' instruct load picture file, 'bNeedPicFile == false' instruct not load picture file ) 
CLIENT_API LLONG CALL_METHOD CLIENT_RealLoadPictureEx(LLONG lLoginID, int nChannelID, 
													 DWORD dwAlarmType, 
													 BOOL bNeedPicFile, 
													 fAnalyzerDataCallBack cbAnalyzerData, 
													 LDWORD dwUser, 
													 void* Reserved);

// stop load picture of intelligent analysis
CLIENT_API BOOL CALL_METHOD CLIENT_StopLoadPic(LLONG lAnalyzerHandle);

// Search according to the criteria
CLIENT_API LLONG	CALL_METHOD CLIENT_FindFileEx(LLONG lLoginID, EM_FILE_QUERY_TYPE emType, void* pQueryCondition, void *reserved, int waittime=1000);	

// Search file:nFilecount:the searched amount. The return value is media file amount. The search in the specified time completed if return <nFilecount.
CLIENT_API int	CALL_METHOD CLIENT_FindNextFileEx(LLONG lFindHandle, int nFilecount, void* pMediaFileInfo, int maxlen, void *reserved, int waittime=1000);

// End the file search
CLIENT_API BOOL CALL_METHOD CLIENT_FindCloseEx(LLONG lFindHandle);

// Download the specified intelligent analytics data-image
CLIENT_API LLONG CALL_METHOD CLIENT_DownloadMediaFile(LLONG lLoginID,EM_FILE_QUERY_TYPE emType, void* lpMediaFileInfo, char *sSavedFileName, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwUserData,  void *reserved);

// Stop downloading the data
CLIENT_API BOOL CALL_METHOD CLIENT_StopDownloadMediaFile(LLONG lFileHandle);

// download picture of intelligent analysis when being off line
CLIENT_API LLONG CALL_METHOD CLIENT_LoadOffLineFile(LLONG lLoginID, int nChannelID, DWORD dwAlarmType, LPNET_TIME_EX lpStartTime, LPNET_TIME_EX lpEndTime, fAnalyzerDataCallBack cbAnalyzerData, LDWORD dwUser);

//Pause IVS data download(bPause=TRUE, it is to stop download , bPause=FALSE , it is to resume download.)
CLIENT_API BOOL CALL_METHOD CLIENT_PauseLoadPic(LLONG lLoadHadle, BOOL bPause);

// traffic snap--snapshot by network
CLIENT_API BOOL CALL_METHOD CLIENT_TrafficSnapByNetwork(LLONG lLoginID, int nChannelID, NET_IN_SNAPSHOT* pstInParam, NET_OUT_SNAPSHOT* pstOutParam);
// start traffic flux state
CLIENT_API LLONG CALL_METHOD CLIENT_StartTrafficFluxStat(LLONG lLoginID, NET_IN_TRAFFICFLUXSTAT* pstInParam,NET_OUT_TRAFFICFLUXSTAT* pstOutParam);

// stop traffic flux state
CLIENT_API BOOL CALL_METHOD CLIENT_StopTrafficFluxStat(LLONG lFluxStatHandle);

// start find flux state
CLIENT_API LLONG CALL_METHOD CLIENT_StartFindFluxStat(LLONG lLoginID, NET_IN_TRAFFICSTARTFINDSTAT* pstInParam, NET_OUT_TRAFFICSTARTFINDSTAT* pstOutParam);

// do find flux state
CLIENT_API int	CALL_METHOD CLIENT_DoFindFluxStat(LLONG lFindHandle, NET_IN_TRAFFICDOFINDSTAT* pstInParam,NET_OUT_TRAFFICDOFINDSTAT* pstOutParam);

// stop find flux state
CLIENT_API BOOL CALL_METHOD CLIENT_StopFindFluxStat(LLONG lFindHandle);
// start find number state
CLIENT_API LLONG CALL_METHOD CLIENT_StartFindNumberStat(LLONG lLoginID, NET_IN_FINDNUMBERSTAT* pstInParam, NET_OUT_FINDNUMBERSTAT* pstOutParam);

// do find number state
CLIENT_API int	CALL_METHOD CLIENT_DoFindNumberStat(LLONG lFindHandle, NET_IN_DOFINDNUMBERSTAT* pstInParam, NET_OUT_DOFINDNUMBERSTAT* pstOutParam);

// stop find number state
CLIENT_API BOOL CALL_METHOD CLIENT_StopFindNumberStat(LLONG lFindHandle);

// Call of the analysis device method
CLIENT_API BOOL CALL_METHOD CLIENT_OperateVideoAnalyseDevice(LLONG lLoginID, int nChannelID, char* szCmd, void *pstInParam, void *pstOutParam, int waittime=1000);

// Intelligent track speed dome control port.
CLIENT_API BOOL CALL_METHOD CLIENT_ControlIntelliTracker(LLONG lLoginID, NET_IN_CONTROL_INTELLITRACKER* pstInParam, NET_OUT_CONTROL_INTELLITRACKER* pstOutParam);

////////////////////////////////  Video analysis /////////////////////////////////

// Real-time get video analysis result 
CLIENT_API BOOL CALL_METHOD CLIENT_StartVideoDiagnosis(LLONG lLoginID, NET_IN_VIDEODIAGNOSIS *pstInParam, NET_OUT_VIDEODIAGNOSIS *pstOutParam);

// Stop video analysis result report
CLIENT_API BOOL CALL_METHOD CLIENT_StopVideoDiagnosis(LLONG hDiagnosisHandle);

// Start video analysis result search
CLIENT_API BOOL CALL_METHOD CLIENT_StartFindDiagnosisResult(LLONG lLoginID, NET_IN_FIND_DIAGNOSIS* pstInParam, NET_OUT_FIND_DIAGNOSIS* pstOutParam);

// Get video analysis result info
CLIENT_API BOOL CALL_METHOD CLIENT_DoFindDiagnosisResult(LLONG hFindHandle,NET_IN_DIAGNOSIS_INFO* pstInParam, NET_OUT_DIAGNOSIS_INFO* pstOutParam);

// End video analysis result search
CLIENT_API BOOL CALL_METHOD CLIENT_StopFindDiagnosis(LLONG hFindHandle);

////////////////////////////////  Matrix interface /////////////////////////////////

// Search product definition
CLIENT_API BOOL CALL_METHOD CLIENT_QueryProductionDefinition(LLONG lLoginID, DH_PRODUCTION_DEFNITION* pstuProdDef, int nWaitTime = 1000);

// Search matri sub card info
CLIENT_API BOOL CALL_METHOD CLIENT_QueryMatrixCardInfo(LLONG lLoginID, DH_MATRIX_CARD_LIST* pstuCardList, int nWaitTime = 1000);

// Search system status
CLIENT_API BOOL CALL_METHOD	CLIENT_QuerySystemStatus(LLONG lLoginID, DH_SYSTEM_STATUS* pstuStatus, int nWaitTime = 1000);

// Search split mode
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitCaps(LLONG lLoginID, int nChannel, DH_SPLIT_CAPS* pstuCaps, int nWaitTime = 1000);

// Search/set display source 
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitSource(LLONG lLoginID, int nChannel, int nWindow, DH_SPLIT_SOURCE* pstuSplitSrc, int nMaxCount, int* pnRetCount, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_SetSplitSource(LLONG lLoginID, int nChannel, int nWindow, const DH_SPLIT_SOURCE* pstuSplitSrc, int nSrcCount, int nWaitTime = 1000);

// Search/set split mode
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitMode(LLONG lLoginID, int nChannel, DH_SPLIT_MODE_INFO* pstuSplitInfo, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_SetSplitMode(LLONG lLoginID, int nChannel, const DH_SPLIT_MODE_INFO* pstuSplitInfo, int nWaitTime = 1000);

// Search split group amount
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitGroupCount(LLONG lLoginID, int nChannel, DH_SPLIT_MODE emSplitMode, int* pnGroupCount, int nWaitTime = 1000);

// Search video output capability
CLIENT_API BOOL CALL_METHOD CLIENT_GetVideoOutCaps(LLONG lLoginID, int nChannel, DH_VIDEO_OUT_CAPS* pstuCaps, int nWaitTime = 1000);

// Set video output option
CLIENT_API BOOL CALL_METHOD CLIENT_SetVideoOutOption(LLONG lLoginID, int nChannel, const DH_VIDEO_OUT_OPT* pstuVideoOut, int nWaitTime = 1000);

// Search the current window of video input channel
CLIENT_API BOOL CALL_METHOD CLIENT_QueryVideoOutWindows(LLONG lLoginID, int nChannel, DH_VIDEO_OUT_WINDOW* pstuWnds, int nMaxWndCount, int* pnRetWndCount, int nWaitTime = 1000);

// Get ISCSI target list
CLIENT_API BOOL CALL_METHOD	CLIENT_GetISCSITargets(LLONG lLoginID, const DH_IN_ISCSI_TARGETS* pInParam, DH_OUT_ISCSI_TARGETS* pOutParam, int nWaitTime = 1000);

// Get storage device name list
CLIENT_API BOOL CALL_METHOD	CLIENT_GetStorageDeviceNames(LLONG lLoginID, DH_STORAGE_DEVICE_NAME* pstuNames, int nMaxCount, int* pnRetCount, int nWaitTime = 1000);

// Get storage device info
CLIENT_API BOOL CALL_METHOD	CLIENT_GetStorageDeviceInfo(LLONG lLoginID, const char* pszDevName, DH_STORAGE_DEVICE* pDevice, int nWaitTime = 1000);

///////////////////////////////Special Version Interface///////////////////////////////

// Search device log--extensive
CLIENT_API BOOL CALL_METHOD CLIENT_QueryLogEx(LLONG lLoginID, DH_LOG_QUERY_TYPE logType, char *pLogBuffer, int maxlen, int *nLogBufferlen, void* reserved, int waittime=3000);

// Active registered redirect function,establish directed connections
CLIENT_API LONG CALL_METHOD CLIENT_ControlConnectServer(LLONG lLoginID, char* RegServerIP, WORD RegServerPort, int TimeOut=3000);

// Establish active registered connection
CLIENT_API BOOL CALL_METHOD CLIENT_ControlRegisterServer(LLONG lLoginID, LONG ConnectionID, int waittime=1000);

// Disconnected directional connection
CLIENT_API BOOL CALL_METHOD CLIENT_ControlDisconnectRegServer(LLONG lLoginID, LONG ConnectionID);

// Query active registered server information
CLIENT_API BOOL CALL_METHOD CLIENT_QueryControlRegServerInfo(LLONG lLoginID, LPDEV_SERVER_AUTOREGISTER lpRegServerInfo, int waittime=2000);

// Upload file
CLIENT_API LLONG CALL_METHOD CLIENT_FileTransmit(LLONG lLoginID, int nTransType, char* szInBuf, int nInBufLen, fTransFileCallBack cbTransFile, LDWORD dwUserData, int waittime);

// web info trasmit
CLIENT_API BOOL  CALL_METHOD CLIENT_TransmitInfoForWeb(LLONG lLoginID, char* szInBuffer, DWORD dwInBufferSize, char* szOutBuffer, DWORD dwOutBufferSize, void* pReserved, int waittime=500);

// watermark verify for picture *nResult = 0-means no verify *nResult = 1-means has verify
CLIENT_API BOOL  CALL_METHOD CLIENT_WatermarkVerifyForPicture(char* szFilePath, int* nResult, void* pReserved);

// multi realplay
CLIENT_API BOOL  CALL_METHOD CLIENT_MultiRealPlay(LLONG lLoginID, DHDEV_IN_MULTIPLAY_PARAM* pInBuf, int nInBufLen, DHDEV_OUT_MULTIPLAY_PARAM* pOutBuf, int nOutBufLen, int* pRetLen);
 
// stop multi realplay
CLIENT_API BOOL  CALL_METHOD CLIENT_StopMultiRealPlay(LLONG* lRealHandles, int nNumOfHandles);
/////////////////////////////////Cancelled Interface/////////////////////////////////

// Search system server setup. This interface is invalid now please use  CLIENT_GetDevConfig
CLIENT_API BOOL CALL_METHOD CLIENT_QueryConfig(LLONG lLoginID, int nConfigType, char *pConfigbuf, int maxlen, int *nConfigbuflen, int waittime=1000);

// Set system server setup. This interface is invalid now please use  CLIENT_SetDevConfig
CLIENT_API BOOL CALL_METHOD CLIENT_SetupConfig(LLONG lLoginID, int nConfigType, char *pConfigbuf, int nConfigbuflen, int waittime=1000);

// This interface is invalid now. 
CLIENT_API BOOL CALL_METHOD CLIENT_Reset(LLONG lLoginID, BOOL bReset);

// Search COM protocol. This interface is invalid now please use  CLIENT_GetDevConfig
CLIENT_API BOOL CALL_METHOD CLIENT_QueryComProtocol(LLONG lLoginID, int nProtocolType, char *pProtocolBuffer, int maxlen, int *nProtocollen, int waittime=1000);

// Begin audio talk. This interface is invalid now. Please use  CLIENT_StartTalkEx
CLIENT_API BOOL CALL_METHOD CLIENT_StartTalk(LLONG lRealHandle, BOOL bCustomSend=false);

// Stop audio talk. This interface is invalid now , please use  CLIENT_StopTalkEx
CLIENT_API BOOL CALL_METHOD CLIENT_StopTalk(LLONG lRealHandle);

// Send out self-defined audio talk data. This interface is invalid now, please use  CLIENT_TalkSendData
CLIENT_API BOOL CALL_METHOD CLIENT_SendTalkData_Custom(LLONG lRealHandle, char *pBuffer, DWORD dwBufSize);

// Set real-time preview buffer size
CLIENT_API BOOL CALL_METHOD CLIENT_SetPlayerBufNumber(LLONG lRealHandle, DWORD dwBufNum);

// Download file by time
CLIENT_API BOOL CALL_METHOD CLIENT_GetFileByTime(LLONG lLoginID, int nChannelID, LPNET_TIME lpStartTime, LPNET_TIME lpStopTime, char *sSavedFileName);

// Network playback control 
CLIENT_API BOOL CALL_METHOD CLIENT_PlayBackControl(LLONG lPlayHandle, DWORD dwControlCode, DWORD dwInValue, DWORD *lpOutValue);

// Search device working status .This interface is invalid now, please use  CLIENT_QueryDevState
CLIENT_API BOOL CALL_METHOD CLIENT_GetDEVWorkState(LLONG lLoginID, LPNET_DEV_WORKSTATE lpWorkState, int waittime=1000);

// Asynchronism search device log 
CLIENT_API BOOL CALL_METHOD CLIENT_QueryLogCallback(LLONG lLoginID, fLogDataCallBack cbLogData, LDWORD dwUser);



#ifdef __cplusplus
}
#endif

#endif // DHNETSDK_H










































