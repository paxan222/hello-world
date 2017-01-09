
#ifndef _SN_STURCT_C_
#define _SN_STURCT_C_

#include "DomainConst.h"
#include "SNPlatOS.h"

//#pragma pack(push, 1)
/**********************************************************************/
//此处用于控制文件编译字节对齐，拷贝时两行注释间内容需一起拷贝，
//结束处的“#ifdef PRAGMA_PACK”部分也要一起拷贝，否则pragma pack入栈出栈不匹配
#if(PRAGMA_PACK_DEFINE != 10000)
	# error Not included "SNPlatOS.h".
#endif
 
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(push, PRAGMA_PACK_CHAR)
	#endif

	#ifndef WIN32  
		#ifndef _PACKED_1_  
		  
		#define _PACKED_1_ __attribute__((packed, aligned(PRAGMA_PACK_CHAR)))	// for gcc   
		#endif  
	#else  
		#ifndef _PACKED_1_  
		#define _PACKED_1_  
		#endif  
	#endif  
#else  
	#ifndef _PACKED_1_  
	#define _PACKED_1_  
	#endif  
#endif
/**********************************************************************/


namespace NVDC_STRUCT
{
	const int  CONST_MAX_RS484_NUM = 16;							//允许的最大RS485个数
	const int  CONST_MAX_PERIOD_SCHEDULE_RECORD_TIME_NUM = 3;		//允许的最大计划录像设定的单日时间段数
	const int  CONST_MAX_ALARM_OUT_NUM = 16;						//允许的最大报警输出通道个数	
	const int  CONST_MAX_ALARM_IN_NUM = 16;							//允许的最大报警输入通道个数
	const int  CONST_MAX_CAMERA_NUM = 16;							//允许的最大摄像头数目
	const int  CONST_MAX_NVR_DEVICE_NUM = 64;						//允许的最大设备数目

	const int  CONST_MAX_PTZ_PRESET_NUM = 255;						//允许的最大云台预置点数目
	const int  CONST_MAX_PTZ_TOURPOINT_NUM =12;						//允许的最大云台巡游数目
	const int  CONST_MAX_PTZ_TRACK_NUM =6;							//允许的最大云台轨迹数目
	const int  CONST_MAX_PTZ_SCAN_NUM =12;							//允许的最大云台扫描数目

	const int  CONST_MAX_DETECTION_NUM = 8;							//允许的最大侦测区域数
	const int  CONST_MAX_DISK_NUM = 16;								//允许的最大磁盘个数
	const int  CONST_MAX_OSDINFO_NUM = 16;							//允许的最大OSD数量
	const int  CONST_MAX_OSD_FONT_TYPE_NUM = 16;					//允许的OSD字体数目

	const int  CONST_MAX_PTZ_PROTOCOL_NUM = 8;						//允许的最大云台协议数
	const int  CONST_MAX_DEVICE_TYPE_NUM = 8;						//允许的最大的设备类型数
	const int  CONST_MAX_BITRATE_TYPE_NUM = 8;						//允许的最大比特率类型数目
	const int  CONST_MAX_DEVICE_IMAGE_FORMAT_NUM = 8;				//允许的设备支持的图像格式最大数目
	const int  CONST_MAX_DDNS_PROVIDER_NUM = 8;						//允许的最大的DDNS提供者数目
	const int  CONST_MAX_ALARM_TYPE_NUM = 8;						//允许的最大的报警类型数目
	const int  CONST_MAX_VIDEO_SYSTEM_NUM = 8;						//允许的最大的视频制式种类
	const int  CONST_MAX_FRAME_LENGTH = 1600*1200;					//一帧数据的最大值
	const int  CONST_MAX_ALARM_ACTION_STRATEGY = 5;					//报警行为策略最大个数
	const int  CONST_MAX_STREAM_NUM = 4*16;							//允许的设备最大流数目
	const int  CONST_MAX_ALARM_EVENT_NUM = 36;						//允许的最大报警事件数
	
	const int  CONST_MAX_AREA_NUM = 3;								//允许的最大区域数

	const int  CONST_MAX_FILE_SYSTEM_NUM = 6;						//允许的最大文件系统数目
	const int  CONST_MAX_DEVICE_VIDEO_ENCODER_NUM = 4;				//允许的最大视频编码器类型数目
	const int  CONST_MAX_AUDIO_TYPE_NUM = 16;						//允许的最大音频输入类型数
	const int  CONST_MAX_AUDIO_ENCODE_TYPE_NUM = 16;				//允许的最大音频编码类型数
	const int  CONST_MAX_AUDIO_DECODE_TYPE_NUM = 16;				//允许的最大音频解码类型数
	const int  CONST_MAX_SOURCE_RESOLUTION_NUM = 4;					//允许的最大源分辨率配置数目
	const int  CONST_MAX_CAMERA_STREAM_NUM = 6;						//允许的摄像头最大流数目
	const int  CONST_MAX_DISK_TYPE_NUM = 6;							//允许的最大磁盘类型数目

	const int  CONST_MAX_RETAIN_TYPE = 64;							//保留类型最大数

	const int  CONST_MAX_MONITOR_TYPE_NUM = 12;						//保留类型最大数
	const int  CONST_MAX_LAYOUT_MODEL_NUM = 16;						//layout模式最大数
	const int  CONST_MAX_LAYOUT_DECODING_ABILITY_NUM = 16;			//布局解码能力最大数
	const int  CONST_MAX_SUB_WIN_DECODING_ABILITY_NUM = 6;			//子窗口解码能力最大数
	const int  CONST_MAX_SUB_WIN_NUM = 64;							//子窗口最大数
	const int  CONST_MAX_NVR_FILE_SYSTEM_NUM = 16;					//文件系统最大数
	const int  CONST_MAX_DISK_ATTRIBUTE_NUM = 12;					//磁盘属性最大数
	const int  CONST_MAX_ATTRIBUTE_NAME_NUM = 256;					//磁盘属性名称最大值
	const int  CONST_MAX_NETWORK_CARD_NUM = 4;						//网卡数量最大值
	const int  CONST_MAX_NETWORKING_MODE_NUM = 4;					//网卡工作模式最大值



	const int  CONST_MAX_AV_STREAM_NUM = 8;							//允许的设备最大流数目
	const int  CONST_MAX_LAYOUT_NAME = 64;							//Layout名称长度
	const int  CONST_MAX_LAYOUIT_WINDOW_NUM = 64;					//Layout窗口最大数
	const int  CONST_MAX_LIVE_VIDEO_CHANNEL_NUM = 16;				//实时视频通道数
	const int  CONST_MAX_LIVE_VIDEO_LAYOUT_NUM = 16;				//实时视频布局最大数
	const int  CONST_MAX_DEVICE_AV_STREAM_PARAM_NUM = 128;			//设备流参数最大数
	const int  CONST_MAX_RECORD_STATE_NUM = 128;					//录像状态最大数
	const int  CONST_MAX_MONITOR_NUM = 8;							//监视器最大数

	const int  CONST_MAX_WIFIHOTSPOTPARAM_NUM = 10;					//wifi 热点最大数
	const int  CONST_MAX_OSD_TIME_FORMAT_TYPE_NUM = 20;             //OSD 时间格式类型最大数
	const int  CONST_MAX_PTZ_TIME_RTIMESEGMENT_NUM = 10;

	const int CONST_MAX_BLINDABILITYV2_TYPE	= 10;					//隐私遮蔽类型支持最大个数
	const int CONST_MAX_BLINDABILITYV2_ALPHA =101;					//隐私遮蔽透明度支持最大个数（0-100）
	const int CONST_MAX_BLINDABILITYV2_RGBCOLOR = 20;				//隐私遮蔽颜色支持最大个数，（如果RGBColor的颜色分量为-1代表支持所有颜色）
	const int CONST_MAX_BLINDABILITYV2_MOSAICPARAM = 10;             //隐私遮蔽马赛克支持最大个数


	const int CONST_MAX_DETECTIONAREA = 2048;     //

	const int CONST_MAX_LIBCOMMONABILITY_NUM = 20;
	const int CONST_MAX_PIXELTOREALSIZE = 20;

	const int CONST_MAX_NOPARKINGREGIONPARAM = 20;

	const int CONST_MAX_SNPOINT = 20;
	const int CONST_MAX_CONVERSEREGIONPARAM = 20;
	const int CONST_MAX_MULTITRIPWIREREGIONPARAM = 20;
	const int CONST_MAX_LOITERPARAM = 10;
	const int CONST_MAX_MULTILOITERPARAM = 10;
	const int CONST_MAX_OBJECTLEFTREGIONPARAM = 10;
	const int CONST_MAX_OBJECTMOVEDREGIONPARAM = 10;
	const int CONST_MAX_ABNORMALSPEEDREGIONPARAM = 10;

	const int CONST_MAX_TRIGGERDIRECTION = 2;
	const int CONST_MAX_TRIPWIRELINE = 2;

	const int CONST_MAX_TRIPWIREREGIONPARAM = 20;
	const int CONST_MAX_PERIMETERREGIONPARAM = 20;

	//鱼眼配置
	const int CONST_MAX_FISHEYEVIDEOLAYOUT  = 16;
	const int CONST_MAX_FISHEYEMOUNTTYPE = 10;
	const int CONST_MAX_FISHEYEVIDEOABILITY = 10;
	const int CONST_MAX_DEWARPMODE = 10;
	const int CONST_MAX_AREANAME = 48;
	const int CONST_MAX_BLINDAREAPARAMV2NUM = 10;

	//ExternDeviceAbility
	const int CONST_MAX_EXTERNCOMTYPE = 5;
	const int CONST_MAX_EXTERNCOMID = 5 ;
	const int CONST_MAX_EXTERNCOMINFO = 10;
	const int CONST_MAX_BAUDRATE = 20;
	const int CONST_MAX_DATABITS = 10;
	const int CONST_MAX_STOPBITS = 10;
	const int CONST_MAX_PARITY	= 20;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//Ip传输协议
	enum ENUM_TransferProtocol
	{
		UDP = 0X01,			//UDP协议
		TCP = 0X02,			//TCP协议
		RTP = 0X04			//RTP协议
	};

	//Ip协议版本
	enum ENUM_IPProtoVer	
	{
		IPPROTO_V4  = 1,	//IPv4协议

		IPPROTO_V6  = 2		//IPv6协议
	};

	//设备类型
	enum ENUM_DeviceType	
	{
		IPCAMERA	= 1,	//IP Camera
		DVR			= 2,	//DVR
		DVS			= 3,	//DVS
		IPDOME		= 4,	//IP Dome
		NVR			= 5		//NVR
	};

	//水印类型
	enum ENUM_OSDType
	{
		OSDTYPE_DEVICENAME	= 1,	//设备名
		OSDTYPE_CAMERAID	= 2,	//摄像机号
		OSDTYPE_CAMERANAME	= 3,	//摄像机名
		OSDTYPE_TIME		= 4,	//时间水印
		OSDTYPE_TEXT		= 5		//文字水印
	};

	//图像格式类型
	enum ENUM_ImageFormat
	{
		IMAGEFORMAT_D1					= 1,	//PAL 704*576,25frame； NTSC 704*480 30framre
		IMAGEFORMAT_LOW_BITRATE_D1		= 2,	//PAL 704*576 12.5frame；NTSC 704*480 15framre
		IMAGEFORMAT_CIF					= 4,	//PAL 352*288 25frame；NTSC 352*240 30framre
		IMAGEFORMAT_QCIF				= 5,	//PAL 176*144 25frame；NTSC 240*160 30framre
		IMAGEFORMAT_SXGA				= 6,	//NA 1280*960 1-22frame
		IMAGEFORMAT_QVGA				= 7,	//NA 320*240 1-22frame
		IMAGEFORMAT_1280_720			= 8,	//NA 1280*720 1-25frame
		IMAGEFORMAT_360_160				= 9,	//NA 320*160 1-25frame
		IMAGEFORMAT_640_360				= 10,	//NA 640*368 1-25frame
		IMAGEFORMAT_VGA					= 11,	//NA 640*480 1-25frame
		IMAGEFORMAT_UXGA				= 12,	//NA 1600*1200 1-25frame
		IMAGEFORMAT_1920_1080			= 13,	//NA 1920*1080 1-25frame
		IMAGEFORMAT_640_360_EX			= 14	//NA 640*360 1-25frame
	} ;

	//比特率类型
	enum ENUM_BitRateType
	{
		CBR_TYPE = 1,					//固定码率

		VBR_TYPE = 2					//不固定码率
	};

	//录像状态
	enum ENUM_RecordStatus
	{
		RECORDSTATUS_NO_RECORD	= 0,	//无录制
		RECORDSTATUS_RECORD		= 1		//有录制
	};

	//信号状态
	enum ENUM_SignalStatus
	{
		SIGNALSTATUS_HAS_SIGNAL	  = 0,	//信号正常
		SIGNALSTATUS_LOSS_SIGNAL  = 1	//信号丢失
	};

	//硬件状态
	enum ENUM_HardwareStatus
	{
		HARDWARESTATUS_NORMAL	  = 0,	//硬件正常
		HARDWARESTATUS_ABNORMAL	  = 1	//硬件错误
	};

	//磁盘状态
	enum ENUM_DiskStatus
	{
		DISKSTATUS_DORMANCY		  = 1,	//正常状态
		DISKSTATUS_ABNORMAL		  = 2,	//不正常状态
		DISKSTATUS_NOT_EXISTENT	  = 3,	//磁盘不存在
		DISKSTATUS_WRITE_PROTECT  = 4,	//磁盘写保护	
		DISKSTATUS_NOT_FORMAT	  = 5,	//磁盘未格式化
		DISKSTATUS_FORMATTING	  = 6	//磁盘正在格式化
	};

	//麦克风类型
	enum ENUM_ToneArmType
	{
		TONEARM_TYPE_INTERNAL				= 1,	//内置
		TONEARM_TYPE_EXTERNAL				= 2,	//外置
		TONEARM_TYPE_LINEIN					= 3,	//线输入
		TONEARM_TYPE_DIFF_LINEIN			= 4,	//差分线输入
		TONEARM_TYPE_DOUBLE_LINEIN			= 5		//双输入
	};

	//扬声器类型
	enum ENUM_LoudhailerType
	{
		LOUDHAILER_TYPE_IN		  = 1,	//内置
		LOUDHAILER_TYPE_OUT		  = 2	//外置
	};

	//485配置流控
	enum ENUM_FlowControl
	{
		FLOWCONTROL_NONE		  = 0,	//无
		FLOWCONTROL_SOFT		  = 1,	//软流控
		FLOWCONTROL_HARD		  = 2	//硬流控
	};

	//奇偶校验
	enum ENUM_COMParity
	{
		COM_PARITY_NONE				= 0,	//None，无校验
		COM_PARITY_ODD				= 1,	//Odd，奇校验
		COM_PARITY_EVEN				= 2,	//Even，偶校验
		COM_PARITY_MARK				= 3,	//Mark，标记校验
		COM_PARITY_SPACE			= 4		//Space，空格校验
	};

	//停止位
	enum ENUM_StopBits
	{
		STOPBITS_ONE				= 0,	//1
		STOPBITS_ONEHALF			= 1,	//1.5
		STOPBITS_TWO				= 2		//2
	};


	//报警有效信号
	enum ENUM_AlarmValidSignal
	{
		ALARM_VALID_SIGNAL_CLOSE  = 0,	//继电器闭合
		ALARM_VALID_SIGNAL_OPEN	  = 1	//继电器断开
	};

	//报警模式
	enum ENUM_AlarmMode
	{
		ALARMMODE_SWITCH		  = 1,	//开关模式
		ALARMMODE_MULTIPLE		  = 2	//方波模式
	};

	//适配器类型
	enum ENUM_AdapterType
	{
		ADAPTER_TYPE_LOCAL		  = 1,	//本地连接
		ADAPTER_TYPE_PPPOE		  = 2	//PPPoE连接
	};

	//DDNS域名提供者ID
	enum ENUM_ProviderId
	{
		PROVIDERID_3322			  = 1,	//3322.org
		PROVIDERID_DYNDNS		  = 2	//dyndns
	};

	//存储策略
	enum ENUM_StoragePolicy
	{
		STORAGE_POLICY_CYCLE	 = 1,	//循环存储
		STORAGE_POLICY_FULLSTOP  = 2	//磁盘满停止
	};

	//录制方式
	enum ENUM_RecordMode
	{
		RECORD_MODE_SIZE = 1,		  //按文件大小录制
		RECORD_MODE_TIME = 2		  //按时间长度录制
	};

	//录像格式类型
	enum ENUM_RecordFormatType	
	{
		RECORD_FORMAT_MPEG2_PS	= 1,			//PS格式
		RECORD_FORMAT_CUSTOM	= 2,			//自定义格式
		RECORD_FORMAT_MPEG2_TS	= 3				//TS格式
	};

	//录像规则
	enum ENUM_RuleType
	{
		RECORD_RULE_TYPE_ALWAYS = 1,			//总是录像
		RECORD_RULE_TYPE_SCHEDULE = 2			//计划录像
	};

	//报警输出标志
	enum ENUM_AlarmOutFlag
	{
		ALARMOUTFLAG_START		= 1,			//报警有效标志位，开始报警
		ALARMOUTFLAG_STOP		= 0				//报警无效标志位，停止报警
	};

	//报警输出状态
	enum ENUM_AlarmOutStatus
	{
		ALARMOUT_NO_ALARMOUT	= 0,			//无报警输出
		ALARMOUT_ALARMOUT		= 1				//有报警输出
	};

	//报警类型
	enum ENUM_AlarmType
	{
		TYPE_ALARMIO					= 1,	//I/O报警
		TYPE_MOTIONDETECT				= 2,	//运动检测报警
		TYPE_CAMERAMASK					= 3,	//摄像头遮挡报警
		TYPE_VIDEO_LOST					= 5,	//视频丢失报警
		TYPE_DISK_ERROR					= 6,	//磁盘读写异常
		TYPE_DISK_CONNECT_FAILED		= 7,	//网络磁盘连接失败
		TYPE_DISK_FULL					= 8,	//磁盘满
		TYPE_DISK_NOT_EXISTENT			= 9,	//磁盘不存在
		TYPE_DISK_THRESHOLD_ALARM		= 10,	//磁盘已用空间达到指定阀值 
		TYPE_DISK_NOT_FORMAT			= 11,	//磁盘未格式化
		TYPE_RECORD_STORAGE_FAILED		= 15    //录像存储失败
	};

	//扩展报警主类型
	enum  ENUM_AlarmMajorType
	{
		SECURITY_ALARM						= 1, //安全报警
		DISK_ALARM							= 4, //磁盘报警
		RECORD_ALARM						= 5  //录像报警。
	};

	//扩展安全报警子类型
	enum  ENUM_SecurityAlarmMinorType
	{
		SECURITYALARM_MINOR_TYPE_ALARMIO		= 1,	//I/O报警
		SECURITYALARM_MINOR_TYPE_MOTIONDETECT	= 2,	//运动检测报警
		SECURITYALARM_MINOR_TYPE_CAMERAMASK		= 3,	//摄像头遮挡报警
		SECURITYALARM_MINOR_TYPE_VIDEO_LOST		= 4		//视频丢失报警
	};

	//扩展磁盘报警子类型
	enum  ENUM_DiskAlarmMinorType
	{
		DISKALARM_MINOR_TYPE_DISK_OK			= 1,	//磁盘状态正常
		DISKALARM_MINOR_TYPE_DISK_ERROR			= 2,	//磁盘读写异常
		DISKALARM_MINOR_TYPE_CONNECT_FAILED		= 3,	//网络磁盘连接失败
		DISKALARM_MINOR_TYPE_DISK_FULL			= 4,	//磁盘满
		DISKALARM_MINOR_TYPE_NOT_EXISTENT		= 5,	//磁盘不存在
		DISKALARM_MINOR_TYPE_THRESHOLD_ALARM	= 6,	//磁盘已用空间达到指定阀值 
		DISKALARM_MINOR_TYPE_NOT_FORMAT			= 7,	//磁盘未格式化
		DISKALARM_MINOR_TYPE_DEVICE_NOSPACE		= 8		//设备存储空间不足
	};

	//扩展录像报警子类型
	enum ENUM_RecordAlarmMinorType
	{
		RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_SUCCESS			= 1,		//数据源连接成功
		RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_LOGIN_ERROR		= 2,		//数据源连接用户名密码错误
		RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_NO_PRIVILEGE		= 3,		//数据源连接没有权限
		RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_MAX_CONNECTION	= 4,		//数据源连接达到最大连接数
		RECORDSOURCE_MINOR_TYPE_AVDATA_MAX_SPEED				= 5,		//数据源达到最大限制速率
		RECORDSOURCE_MINOR_TYPE_LOGIN_USER_REPEATED				= 6,
		RECORDSOURCE_MINOR_TYPE_NOT_SUPPORT_VIDEO				= 7,
		RECORDSOURCE_MINOR_TYPE_CREATE_VIDEO_SESSION_FAILED		= 8,
		RECORDSTORAGE_MINOR_TYPE_STORAGE_FAILED					= 9
	};

	enum  ENUM_AlarmFlag
	{
		ALARM_FLAG_STOP = 0,						//报警停止
		ALARM_FLAG_START = 1						//报警开始
	};

	//图片格式
	enum ENUM_PhotoFormat
	{
		PHOTOFORMAT_JPEG	    = 1,			//jpge格式

		PHOTOFORMAT_BMP			= 2				//bmp格式
	};

	//抓拍状态
	enum ENUM_PhoteSnapShotFlag
	{
		PHOTESNAPSHOT_FLAG_NO		= 0,		//没配置抓拍
		PHOTESNAPSHOT_FLAG			= 1			//配置抓拍
	};

	//查询方式
	enum ENUM_RecordFileSelectMode
	{
		SELECT_MODE_ALL		= 0,				//查询所有
		SELECT_MODE_TYPE	= 1,				//按类型查询
		SELECT_MODE_TIME 	= 2					//按时间查询
	};

	//视频制式
	enum ENUM_VideoSystem
	{
		NTSC	= 0,	//PAL制式
		PAL		= 1,	//NTFS制式
		NA		= 2		//
	};

	//录像类型
	enum ENUM_RecordType
	{
		RECORD_TYPE_ALWAYS		= 1,	//总是录像
		RECORD_TYPE_SCHEDULE	= 2,	//计划录像
		RECORD_TYPE_ALARM		= 3		//报警录像
	};

	//打开模式
	enum ENUM_OpenMode
	{
		OPENMODE_SHARE		= 0,		//共享模式打开
		OPENMODE_EXCLUSIVE	= 1			//独占模式打开
	};

	//播放状态
	enum ENUM_PlayStatus
	{
		PLAY_STATUS_STOP = 1,       //停止
		PLAY_STATUS_PAUSE = 2,		//暂停
		PLAY_STATUS_PLAY = 3,		//播放
		PLAY_STATUS_FASTPLAY = 4,	//快进
		PLAY_STATUS_SLOWPLAY = 5,	//慢放
		PLAY_STATUS_FRAME_PLAY = 6, //帧进
		PLAY_STATUS_FRAME_BACK = 7  //帧退

	} ;

	//PTZ协议
	enum  ENUM_PTZProtocol
	{
		PROTOCOL_PELCO_D = 0,		//PELCO_D协议
		PROTOCOL_PELCO_P = 1		//PELCO_P协议
	};

	//录制状态
	enum ENUM_LiveRecordStatus
	{
		RECORD_RUNNING = 1,			//正在录制
		RECORD_STOP	   = 2			//停止录制
	};

	//编码格式
	enum ENUM_EncoderType
	{
		MPEG4		= 0,			//MPEG4编码
		H264		= 1,			//H264编码
		MJPEG		= 2,			//MJPEG编码
		SVC			= 3,			//SVC编码
		H264_MAIN	= 4,			//H264 main profile
		H264_HIGH	= 5,			//H264 high profile
		G7231		= 101,			//G7231编码
		G711_ALAW	= 102,			//G711A律编码
		G711_ULAW	= 103,			//G711U律编码
		G722		= 104,			//G722编码
		G726		= 105,			//G726编码
		G729		= 106,			//G729编码
		AMR			= 107,			//AMR编码
		RAW_PCM		= 108,			//PCM编码，即不编码
		UNKNOWN		= 0xFF			//未知编码

	};

	//流格式
	enum ENUM_StreamFormat
	{
		ES_STREAM			=   1,		//原始流	
		TS_STREAM			=   2,		//TS混合流
		ES_ENCRYPT_STREAM1	=   3,		//原始加密流，同方加密算法
		PS_STREAM			=   4		//PS混合流
	};

	//文件格式
	enum ENUM_FileFormat
	{
		FILE_FORMAT_TS		= 1,	//录像文件为Mpeg2TS格式
		FILE_FORMAT_SUNELL  = 2,	//录像文件为Sunell格式
		FILE_FORMAT_AVI		= 3,	//录制的文件格式为AVI格式
		FILE_FORMAT_PS		= 4		//录制的文件格式为Mpeg2PS流格式
	};

	enum ENUM_ESStreamType
	{
		VIDEO			=  1,		//视频流
		AUDIO			=  2		//音频流
	};

	//帧类型
	enum ENUM_FrameType
	{
		UnknownFrame	=	0, //未知帧类型
		IFrame			=	1, //I帧
		PFrame			=	2, //P帧
		BFrame			=	3  //B帧
	};

	//磁盘类型
	enum ENUM_DiskType
	{
		DISKTYPE_HARDDISK			= 1, //本地硬盘
		DISKTYPE_SDCARD				= 2, //SD卡
		DISKTYPE_FTP				= 3, //FTP
		DISKTYPE_NAS				= 4,  //NAS
		DISKTYPE_EXTERN_DISK		= 5  //外接设备
	};

	//PTZ守望类型
	enum ENUM_PTZ_Keeper_Type
	{
		PTZ_KEEPER_TYPE_PRESET		= 1,	//预置位
		PTZ_KEEPER_TYPE_SCAN		= 2,	//扫描
		PTZ_KEEPER_TYPE_AUTO_STUDY	= 3,	//自学习
		PTZ_KEEPER_TYPE_TOUR		= 4		//巡游
	};

	//RTSP传输协议
	enum RtspTransferProtocol
	{
		RTP_UDP		= 0x1,		//UDP
		RTSP_TUNNEL = 0x2,		//RTSP隧道
		HTTP_TUNNEL = 0x3		//HTTP隧道
	};

	enum DrawVideoMode
	{
		DRAW_VIDEO_MODE_DDRAW	= 1,//DirectDraw
		DRAW_VIDEO_MODE_D2D		= 2 //D2D
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////////

	//时间参数
	typedef struct _PACKED_1_ tagTimeStruct
	{
		int				nTimeZone;				//时区
		unsigned short	nDaylightSavingTime;	//夏令营时
		unsigned short	nYear;					//年
		unsigned short 	nMonth;					//月[0,11]
		unsigned short 	nDay;					//日[1,31]
		unsigned short 	nDayOfWeek;				//星期几[0,6]
		unsigned short 	nHour;					//时[0,24]
		unsigned short 	nMinute;				//分[0,60]
		unsigned short 	nSecond;				//秒[0,60]
		int 			nMilliseconds;			//微妙[0,1000000]
	}ST_TimeStruct;


	//IP地址
	typedef struct _PACKED_1_ tagInetAddr
	{
		char			szHostIP[CONST_MAXLENGTH_IP + 1];		//IP地址（点分符形式）

		unsigned short	nPORT;									//端口号

		long			nIPProtoVer;							//IP协议版本（1：IPv4协议，2：IPv6协议）

	}ST_InetAddr;

	//设备信息
	typedef struct _PACKED_1_ tagDeviceInfo
	{
		ST_InetAddr		stInetAddr;											//设备的网络地址

		char			szUserID[CONST_MAXLENGTH_USERID + 1];				//登陆设备的用户ID

		char			szPassword[CONST_MAXLENGTH_PASSWORD + 1];			//登陆设备的密码

		char			szDeviceID[CONST_MAXLENGTH_DEVICEID + 1];			//设备ID

		char			szDeviceName[CONST_MAXLENGTH_DEVICENAME + 1];		//设备名称

		long			nDeviceType;										//设备类型

	}ST_DeviceInfo;

	//设备信息
	typedef struct _PACKED_1_ tagDeviceInfoEx
	{
		ST_InetAddr		stInetAddr;											//设备的网络地址

		char			szUserID[CONST_MAXLENGTH_USERID + 1];				//登陆设备的用户ID

		char			szPassword[CONST_MAXLENGTH_PASSWORD + 1];			//登陆设备的密码

		char			szDeviceID[CONST_MAXLENGTH_DEVICEID + 1];			//设备ID

		char			szDeviceName[CONST_MAXLENGTH_DEVICENAME + 1];		//设备名称

		long			nDeviceType;										//设备类型

		unsigned char	m_bRouterMappingEnableFlag;							//路由器映射标志
		char			m_szRouterAddr[CONST_MAXLENGTH_IP + 1];				//路由器地址，IP地址或域名
		unsigned short	m_nRouterMappingControlPort;						//控制映射端口
		unsigned short	m_nRouterMappingTCPAVPort;							//TCP音视频映射端口
		unsigned short	m_nRouterMappingRTSPPort;							//RTSP映射端口
		unsigned short	m_nRouterMappingRTPPort;							//RTP映射端口
		unsigned short	m_nRouterMappingRTCPPort;							//RTCP映射端口

	}ST_DeviceInfoEx;

	//云台协议
	typedef struct _PACKED_1_ tagPTZProtocol
	{
		long	nProtocolId;													//云台协议的ID号

		char	szProtocolName[CONST_MAXLENTH_PTZ_PROTOCOL_NAME + 1];			//云台协议的名字

	}ST_PTZProtocol;

	//设备类型
	typedef struct _PACKED_1_ tagDeviceType
	{
		long		nDeviceTypeId;										//设备类型id

		char		szDeviceTypeName[CONST_MAXLENGTH_DEVICETYPE_NAME];	//设备类型名称

	}ST_DeviceType;

	//比特率类型
	typedef struct _PACKED_1_ tagBitrateType
	{
		long		nBitrateTypeId;												//比特率类型id

		char		szBitrateTypeName[CONST_MAXLENGTH_BITRATETYPE_NAME + 1];	//比特率类型名称

	}ST_BitrateType;

	//域名提供者
	typedef struct _PACKED_1_ tagDDNSProvider
	{
		long		nProviderId;											//提供者id

		char		szProviderName[CONST_MAXLENGTH_DDNS_PROVIDER + 1];		//提供者名称

	}ST_DDNSProvider;

	//报警类型
	typedef struct _PACKED_1_ tagAlarmType
	{
		long		nAlarmTypeId;												//报警类型id

		char		szAlarmTypeName[CONST_MAXLENGTH_ALARM_TYPE_NAME + 1];		//报警类型名称
	}ST_AlarmType;

	//图像格式
	typedef struct _PACKED_1_ tagImageFormat
	{
		long		nImageFormatId;												//图像格式id

		char		szImageFormatName[CONST_MAXLENGTH_IMAGEFORMAT_NAME + 1];	//图像格式名称

	}ST_ImageFormat;

	//视频制式
	typedef struct _PACKED_1_ tagVideoSystem
	{
		long		nVideoSystemId;												//视频制式id

		char		szVideoSystemName[CONST_MAXLENGTH_VIDEOSYSTEM_NAME + 1];	//视频制式名称

	}ST_VideoSystem;

	//摄像头视频制式
	typedef struct _PACKED_1_ tagCameraVideoSystem
	{
		long			nCameraId;				//摄像头id

		ST_VideoSystem	stWebVideoSystem;		//视频制式

	}ST_CameraVideoSystem;

	//设备摄像头视频制式
	typedef struct _PACKED_1_ tagDeviceVideoSystem
	{
		long						nCameraNum;										//摄像头个数

		ST_CameraVideoSystem		stWebCameraVideoSystem[CONST_MAX_CAMERA_NUM];	//摄像头制式列表

	}ST_DeviceVideoSystem;

	//字典表数据结构
	typedef struct _PACKED_1_ tagDictionaryService
	{
		long					nWebPTZProtocolNum;		  	
		ST_PTZProtocol			stWebPTZProtocol[CONST_MAX_PTZ_PROTOCOL_NUM];			//云台协议

		long					nWebDeviceTypeNum;
		ST_DeviceType			stWebDeviceType[CONST_MAX_DEVICE_TYPE_NUM];				//设备类型

		long					nWebBitrateTypeNum;
		ST_BitrateType			stWebBitrateType[CONST_MAX_BITRATE_TYPE_NUM];			//比特率类型

		long					nWebDDNSProviderNum;							
		ST_DDNSProvider			stWebDDNSProvider[CONST_MAX_DDNS_PROVIDER_NUM];			//域名提供者

		long					nWebAlarmTypeNum;
		ST_AlarmType			stWebAlarmType[CONST_MAX_ALARM_TYPE_NUM];				//报警类型

		long					nWebImageFormatNum;
		ST_ImageFormat			stWebImageFormat[CONST_MAX_DEVICE_IMAGE_FORMAT_NUM];    //分辨率类型

		long					nWebVideoSystemNum;
		ST_VideoSystem			stWebVideoSystem[CONST_MAX_VIDEO_SYSTEM_NUM];			//视频制式

	}ST_DictionaryService;

	//编码能力参数信息
	typedef struct _PACKED_1_ tagEncoderAbility
	{
		long nImageFormatId;								//视频格式
		long nMaxFrameRate;									//最大码率
		long nMinFrameRate;									//最小码率
		long nMaxBitRate;									//最大比特率
		long nMinBitRate;									//最小比特率
		long nMaxQuality;									//最大视频质量值
		long nMinQuality;									//最小视频质量值
		long nBitRateTypeNum;								//比特路类型数目
		long nBitRateTypeList[CONST_MAX_BITRATE_TYPE_NUM];	//比特率类型列表

		long nVideoSystem;									//制式
		long nHeight;										//高度
		long nWidth;											//宽度
		long nEncoderType;									//编码类型。具体可查看ENUM_EncoderType枚举定义

	}ST_EncoderAbility;

	//侦测能力
	typedef struct _PACKED_1_ tagMotionDetectionAbility
	{
		long			m_nImageFormatId;				//视频格式
		long			m_nMaxSensitivity;				//最大灵敏度
		long			m_nMinFrameInterval;			//最小帧间隔

	}ST_MotionDetectionAbility;

	//摄像头能力参数
	typedef struct _PACKED_1_ tagCameraAbility
	{
		long							nCameraId;														//摄像头ID

		unsigned char					bUserConfigurable;												//视频制是否由用户配置
		unsigned char					bMotionDetectionSupportFlag;									//运动检测标志,1表示支持,0表示不支持

		long							nImageFormatNum;												//编码能力参数
		ST_EncoderAbility				stEncoderAbility[CONST_MAX_DEVICE_IMAGE_FORMAT_NUM*2];

		long							nDetectionImageFormatNum;
		ST_MotionDetectionAbility		stMotionDetectionAbility[CONST_MAX_DEVICE_IMAGE_FORMAT_NUM*2];	//移动侦测能力参数

	}ST_CameraAbility;

	//视频能力信息
	typedef struct _PACKED_1_ tagVideoAbility
	{
		long					nCameraNum;											//摄像头个数
		ST_CameraAbility		stCameraAbility[CONST_MAX_CAMERA_NUM];				//摄像头能力

	}ST_VideoAbility;

	typedef struct _PACKED_1_ tagAudioAbility
	{
		unsigned char bInterPhoneFlag;
		long nAudioInTypeList[CONST_MAX_CAMERA_NUM];
		long nAudioEncodeTypeList[CONST_MAX_CAMERA_NUM];
		long nAudioDecodeTypeList[CONST_MAX_CAMERA_NUM];
	}ST_AudioAbility;

	//设备能力信息参数
	typedef struct _PACKED_1_ tagDeviceAbility
	{
		ST_VideoAbility	stVideoAbility;
		ST_AudioAbility stAudioAbility;

	}ST_DeviceAbility;

	typedef struct _PACKED_1_ tagPTZAbility
	{
		unsigned char			bInternalPTZFlag;											//内置PTZ标志	1表示支持内置PTZ，0表示不支持。

		int						nPTZProtocolNum;											//支持的PTZ协议数
		ST_PTZProtocol			stPTZProtocolList[CONST_MAX_PTZ_PROTOCOL_NUM];				//支持的PTZ协议列表

	}ST_PTZAbility;


	//文件系统
	typedef struct _PACKED_1_ tagFileSystem
	{
		int					nFileSystemType;

		char				szFileSystemName[CONST_MAXLENTH_DISK_FILE_SYSTEM_NAME];

	}ST_FileSystem;

	//文件系统能力
	typedef struct _PACKED_1_ tagFileSystemAbility
	{
		int							nDiskType;

		int							nFileSystemTypeNum;
		ST_FileSystem			stFileSystemList[CONST_MAX_FILE_SYSTEM_NUM];

	}ST_FileSystemAbility;


	//音频解码类型
	typedef struct _PACKED_1_ tagAudioDecodeType
	{
		int					nAudioDecodeTypeId;														//音频解码类型Id

		char				szAudioDecodeTypeName[CONST_MAXLENGTH_AUDIO_DECODE_TYPE_NAME];			//音频解码类型名

	}ST_AudioDecodeType;

	//音频编码类型
	typedef struct _PACKED_1_ tagEncodeType
	{
		int					nAudioEncodeTypeId;	   												//音频编码类型Id

		char				szAudioEncodeTypeName[CONST_MAXLENGTH_AUDIO_ENCODE_TYPE_NAME];		//音频编码类型名

	}ST_EncodeType;

	//音频输入类型
	typedef struct _PACKED_1_ tagAudioInType
	{
		int	 nAudioInTypeId;													//音频输入类型Id

		char szAudioInTypeName[CONST_MAXLENGTH_AUDIO_IN_TYPE_NAME];				//音频输入类型名

	}ST_AudioInType;

	//支持视频分辨率
	typedef struct _PACKED_1_ tagVideoResolution
	{
		int						nVideoHeight;													//高度
		int						nVideoWidth;													//宽度
		char					szResolutionName[CONST_MAXLENGTH_RESOLUTION_NAME];				//分辨率别名

	}ST_VideoResolution;
	

	//隐式遮蔽能力
	typedef struct _PACKED_1_ tagBlindAbility
	{
		int						nMaxBlindAreaNum;													//最大的遮挡区域数目
		int						nBlindArea;															//遮挡区域面积占源分辨率百分比
	}ST_BlindAbility;



	//视频分辨率能力
	typedef struct _PACKED_1_ tagVideoResolutionAbility
	{
		ST_VideoResolution		stVideoResolution;								//视频分辨率
		int						nMaxFrameRate;									//最大帧率
		int						nMinFrameRate;									//最小帧率
		int						nMaxBitRate;									//最大码率
		int						nMinBitRate;									//最小码率
		int						nMaxQuality;									//最大视频质量值
		int						nMinQuality;									//最小视频质量值
		int						nMaxIFrameInterval;								//最大I帧的步长
		int						nMinIFrameInterval;								//最小I帧的步长

		int						nBitRateTypeNum;								//比特路类型数目
		int						nBitRateTypeList[CONST_MAX_BITRATE_TYPE_NUM];	//比特率类型列表
	}ST_VideoResolutionAbility;

	//视频分辨率能力
	typedef struct _PACKED_1_ tagVideoResolutionAbilityV2
	{
		ST_VideoResolution		stVideoResolution;								//视频分辨率
		int						nMaxFrameRate;									//最大帧率
		int						nMinFrameRate;									//最小帧率
		int						nMaxBitRate;									//最大码率
		int						nMinBitRate;									//最小码率
		int						nMaxQuality;									//最大视频质量值
		int						nMinQuality;									//最小视频质量值
		int						nMaxIFrameInterval;								//最大I帧的步长
		int						nMinIFrameInterval;								//最小I帧的步长

		int						nBitRateTypeNum;								//比特路类型数目
		int						nBitRateTypeList[CONST_MAX_BITRATE_TYPE_NUM];	//比特率类型列表
		int						nIFrameIntervalUnit;							//I帧的步长单位    1,//单位为秒  2//单位为帧
	}ST_VideoResolutionAbilityV2;

	//视频编码器
	typedef struct _PACKED_1_ tagVideoEncoderAbility
	{
		int									nEncoderType;	//编码类型。具体可查看ENUM_EncoderType枚举定义																		//编码器类型
		char								szEncoderName[CONST_MAXLENGTH_ENCODER_NAME];											//编码器名称
		int									nVideoEncodeTotleAbility;																//视频编码总能力 

		int									nVideoResolutionAbilityNum;																
		ST_VideoResolutionAbility			stVideoResolutionAbilityList[CONST_MAX_DEVICE_IMAGE_FORMAT_NUM];						//视频分辨率能力

	}ST_VideoEncoderAbility;

	//视频编码器
	typedef struct _PACKED_1_ tagVideoEncoderAbilityV2
	{
		int									nEncoderType;	//编码类型。具体可查看ENUM_EncoderType枚举定义																		//编码器类型
		char								szEncoderName[CONST_MAXLENGTH_ENCODER_NAME];											//编码器名称
		int									nVideoEncodeTotleAbility;																//视频编码总能力 

		int									nVideoResolutionAbilityNum;																
		ST_VideoResolutionAbilityV2			stVideoResolutionAbilityList[CONST_MAX_DEVICE_IMAGE_FORMAT_NUM];						//视频分辨率能力

	}ST_VideoEncoderAbilityV2;


	//流编码能力
	typedef struct _PACKED_1_ tagStreamEncodeAbility
	{
		int						nEncoderType;					//码流ID

		int						nVideoResolutionNum;			//分辨率数目

		ST_VideoResolution		stVideoResolutionList[CONST_MAX_DEVICE_IMAGE_FORMAT_NUM];

	}ST_StreamEncodeAbility;

	//摄像头流能力参数
	typedef struct _PACKED_1_ tagAVStreamAbility
	{
		int							nStreamId;													//码流ID

		int							nStreamEncodeAbilityNum;									//流编码能力数量

		ST_StreamEncodeAbility		stStreamEncodeAbility[CONST_MAX_DEVICE_VIDEO_ENCODER_NUM];	//码流编码能力列表

	}ST_AVStreamAbility;


	//音频扩展能力信息
	typedef struct _PACKED_1_ tagAudioExAbility
	{
		unsigned char			bInterPhoneFlag;											//音频对讲有效标志	1表示支持对讲，0表示不支持对讲功能。

		unsigned char			bAudioInFlag;												//音频输入有效标志	1表示支持音频输入，0表示不支持音频输入功能。

		int						nAudioInTypeNum;	
		ST_AudioInType			stAudioInTypeList[CONST_MAX_AUDIO_TYPE_NUM];				//音频输入类型列表

		int						nAudioEncodeTypeNum;
		ST_EncodeType			stAudioEncodeTypeList[CONST_MAX_AUDIO_ENCODE_TYPE_NUM];		//音频编码类型列表

		int						nAudioDecodeTypeNum;
		ST_AudioDecodeType		stAudioDecodeTypeList[CONST_MAX_AUDIO_DECODE_TYPE_NUM];		//音频解码类型列表

	}ST_AudioExAbility;

	typedef struct _PACKED_1_ tagMotionDetectionExAbility
	{
		int			nMaxSensitivity;			//最大灵敏度
		int			nMinSensitivity;			//最小灵敏度
		int			nDefualSensitivity;			//默认灵敏度
		int			nDefualWidthCellNumber;		//默认区域宽块数
		int			nDefualHighCellNumber;		//默认区域高块数
		int			nMaxWidthCellNumber;		//最大区域宽块数
		int			nMinWidthCellNumber;		//最小区域宽块数
		int			nMaxHighCellNumber;			//最大区域高块数
		int			nMinHighCellNumber;			//最小区域高块数
	}ST_MotionDetectionExAbility;
	

	//摄像头扩展能力参数
	typedef struct _PACKED_1_ tagCameraExAbility
	{
		int							nCameraId;														//摄像头编号
		ST_VideoResolution			stMaxVideoResolution;											//支持的最大分辨率

		int							nSourceResolutionNum;
		ST_VideoResolution			stSourceResolutionList[CONST_MAX_SOURCE_RESOLUTION_NUM];		//支持源分辨率列表

		int							nImageFormatNum;
		ST_VideoResolution			stVideoResolutionList[CONST_MAX_DEVICE_IMAGE_FORMAT_NUM];		//支持视频分辨率列表

		int							nAVStreamAbilityNum;
		ST_AVStreamAbility			stAVStreamAbilityList[CONST_MAX_CAMERA_STREAM_NUM];				//摄像机流

		ST_BlindAbility				stBlindAbility;

		//ST_MotionDetectionExAbility stMotionDetectionExAbility;

	}ST_CameraExAbility;

	//视频扩展能力信息
	typedef struct _PACKED_1_ tagVideoExAbility
	{
		int								nCameraNum;
		ST_CameraExAbility				stCameraExAbilityList[CONST_MAX_CAMERA_NUM];					//摄像机能力列表

		unsigned char					bIsVideoSystemConfigurable;										//视频制是否可配置

		int								nVideoEncoderNum;
		ST_VideoEncoderAbility			stVideoEncoderAbilityList[CONST_MAX_DEVICE_VIDEO_ENCODER_NUM];	//视频编码器列表

		int								nVideoSystemNum;
		ST_VideoSystem					stVideoSystem[CONST_MAX_VIDEO_SYSTEM_NUM];						//视频制式
	
	}ST_VideoExAbility;

	//视频扩展能力信息
	typedef struct _PACKED_1_ tagVideoExAbilityV2
	{
		int								nCameraNum;
		ST_CameraExAbility				stCameraExAbilityList[CONST_MAX_CAMERA_NUM];					//摄像机能力列表

		unsigned char					bIsVideoSystemConfigurable;										//视频制是否可配置

		int								nVideoEncoderNum;
		ST_VideoEncoderAbilityV2		stVideoEncoderAbilityList[CONST_MAX_DEVICE_VIDEO_ENCODER_NUM];	//视频编码器列表

		int								nVideoSystemNum;
		ST_VideoSystem					stVideoSystem[CONST_MAX_VIDEO_SYSTEM_NUM];						//视频制式

	}ST_VideoExAbilityV2;


	//设备扩展能力信息参数
	typedef struct _PACKED_1_ tagDeviceExAbility
	{
		ST_VideoExAbility				stVideoExAbility;												//视频能力

		ST_AudioExAbility				stAudioExAbility;												//音频能力

		ST_PTZAbility					stPTZAbility;													//PTZ能力

		int								nDiskTypeNum;													//磁盘类型个数
		ST_FileSystemAbility			stFileSystemAbilityList[CONST_MAX_DISK_TYPE_NUM];				//文件系统能力

	}ST_DeviceExAbility;



	//设备扩展能力信息参数
	typedef struct _PACKED_1_ tagDeviceExAbilityV2
	{
		ST_VideoExAbilityV2				stVideoExAbility;												//视频能力

		ST_AudioExAbility				stAudioExAbility;												//音频能力

		ST_PTZAbility					stPTZAbility;													//PTZ能力

		int								nDiskTypeNum;													//磁盘类型个数
		ST_FileSystemAbility			stFileSystemAbilityList[CONST_MAX_DISK_TYPE_NUM];				//文件系统能力

	}ST_DeviceExAbilityV2;


////////////////////////////////////////////

	//监视器类型参数
	typedef struct _PACKED_1_ tagMonitorType
	{
		int		nTypeId;												//类型编号
		char	szTypeName[CONST_MAXLENTH_MONITOR_TYPE_NAME];			//类型名称

	}ST_MonitorType;

	//监视器类型能力信息参数
	typedef struct _PACKED_1_ tagMonitorAbility
	{
		int							nMonitorId;										//监视器编号
		int							nMonitorTypeNum;								//监视器类型数量
		ST_MonitorType				stMonitorTypeList[CONST_MAX_MONITOR_TYPE_NUM];	//监视器类型列表

	}ST_MonitorAbility;

	//layout模式参数
	typedef struct _PACKED_1_ tagLayoutModel
	{
		int		nModelId;			//模式编号
		int		nPicNumber;			//画面数量

	}ST_LayoutModel;

	//layout能力信息参数
	typedef struct _PACKED_1_ tagLayoutAbility
	{
		int				nLayoutModelNum;								//layout模式个数		
		ST_LayoutModel	stLayoutModelList[CONST_MAX_LAYOUT_MODEL_NUM];	//layout模式列表

	}ST_LayoutAbility;

	//子窗口解码能力信息参数
	typedef struct _PACKED_1_ tagSubWinDecodingAbility
	{
		ST_VideoResolution		stMaxVideoResolution;					//最大分辨率
		int						nSubWinNum;								//子窗口个数		
		int						nSubWinList[CONST_MAX_SUB_WIN_NUM];		//子窗口列表

	}ST_SubWinDecodingAbility;

	//布局解码能力能力信息参数
	typedef struct _PACKED_1_ tagLayoutDecodingAbility
	{
		int							nLayoutModeID;															//布局模式ID
		int							nSubWinDecodingAbilityNum;												//子窗口解码能力个数
		ST_SubWinDecodingAbility	stSubWinDecodingAbilityList[CONST_MAX_SUB_WIN_DECODING_ABILITY_NUM];	//子窗口解码能力列表

	}ST_LayoutDecodingAbility;

	//解码能力信息参数
	typedef struct _PACKED_1_ tagDecodingAbility
	{
		int							nLayoutDecodingAbilityNum;												//布局解码能力个数
		ST_LayoutDecodingAbility	stLayoutDecodingAbilityList[CONST_MAX_LAYOUT_DECODING_ABILITY_NUM];		//布局解码能力列表

	}ST_DecodingAbility;

	//磁盘属性信息参数
	typedef struct _PACKED_1_ tagDiskAttributeEx
	{
		int				nDiskAttribute;									//磁盘属性
		char			szAttributeName[CONST_MAX_ATTRIBUTE_NAME_NUM];	//磁盘属性名称

	}ST_DiskAttributeEx;


	//文件系统能力信息参数
	typedef struct _PACKED_1_ tagNVRFileSystemAbility
	{
		int					nDiskType;											//磁盘类型

		int					nFileSystemNum;										//文件系统个数
		ST_FileSystem		stFileSystemList[CONST_MAX_NVR_FILE_SYSTEM_NUM];	//文件系统列表

		int					nDiskAttributeNum;									//磁盘列表个数
		ST_DiskAttributeEx	stDiskAttributeList[CONST_MAX_DISK_ATTRIBUTE_NUM];	//磁盘列表

	}ST_NVRFileSystemAbility;

	//网口工作模式参数
	typedef struct _PACKED_1_ tagNetWorkingMode
	{
		int									nWorkingType;							//工作类型
		char								szWorkingName[CONST_WORKMODE_NAME];		//工作模式名称
		bool								bSupportIPConfigFlag;					//IP可配置标志
		bool								bSupportDHCPServerFlag;					//dhcp服务端标志
		bool								bSupportDHCPClientFlag;					//dhcp客户端标志
		bool								bSupportDNSConfigFlag;					//DNS配置标志

	}ST_NetWorkingMode;

	//网卡能力信息参数
	typedef struct _PACKED_1_ tagNetworkCardAbility
	{
		int							nNetworkCardId;											//网卡ID
		int							nNetworkingModeNum;										//网卡工作模式个数
		ST_NetWorkingMode			stNetworkingModeList[CONST_MAX_NETWORKING_MODE_NUM];	//网卡工作模式列表

	}ST_NetworkCardAbility;

	//网络能力信息参数
	typedef struct _PACKED_1_ tagNetworkAbility
	{
		int									nNetworkCardNum;										//网卡数量
		ST_NetworkCardAbility				stNetworkCardAbilityList[CONST_MAX_NETWORK_CARD_NUM];	//网卡能力列表

	}ST_NetworkAbility;

	//NVR设备能力信息参数
	typedef struct _PACKED_1_ tagNVRDeviceAbility
	{
		int									nMaxChannelNumber;				// 支持的最大路数
		int									nDiskNumber;					// 支持的硬盘个数
		int									nMaxDecodeAbility;				// 最大解码能力，D1为单位
		int									nMaxBitRate;					// 录像最大码流
		int									nMaxPlaybackChannelNumber;		// 最大回放路数

		int									nMonitorAbilityNum;				// 监视器能力个数
		ST_MonitorAbility					stMonitorAbilityList[CONST_MAX_MONITOR_NUM];			// 监视器能力

		ST_LayoutAbility					stLayoutAbility;				// Layout能力

		ST_DecodingAbility					stDecodingAbility;				// 解码能力

		int									nFileSystemAbilityNum;			// 磁盘文件系统格式个数
		ST_NVRFileSystemAbility				stFileSystemAbilityList[CONST_MAX_FILE_SYSTEM_NUM];		// 磁盘文件系统格式能力	

		ST_NetworkAbility					stNetworkAbility;				//网络能力

	}ST_NVRDeviceAbility;

	//////////////////////////////////////////////////////////////









	//用户登陆信息
	typedef struct _PACKED_1_ tagLoginInfo
	{
		char	szUserName[CONST_MAXLENGTH_USERNAME + 1];							//登陆用户名
		char    szPassword[CONST_MAXLENGTH_USERPASSWORD + 1];						//登陆密码

	}ST_LoginInfo;

	//设备概要信息
	typedef struct _PACKED_1_ tagDeviceSummaryParam
	{
		char	szDeviceName[CONST_MAXLENGTH_DEVICENAME + 1];						//设备名称
		char	szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];							//设备号

		char	szManufacturerId[CONST_MAXLENGTH_MANUFACTURERID + 1];				//设备型号
		char	szManufacturerName[CONST_MAXLENGTH_MANUFACTURERNAME + 1];			//生产厂家

		char	szProductModel[CONST_MAXLENGTH_PRODUCTMODEL + 1];					//产品模组
		char	szProductDescription[CONST_MAXLENGTH_PRODUCTDESCRIPTION + 1];		//产品描述
		char	szHardwareModel[CONST_MAXLENGTH_HARDWAREMODEL + 1];					//硬件模组

		char	szHardwareDescription[CONST_MAXLENGTH_HARDWAREDESCRIPTION + 1];		//硬件描述

		char	szMACAddress[CONST_MAXLENGTH_MACADDRESS + 1];						//MAC地址
		char	szBarCode[CONST_MAXLENGTH_BARCODE + 1];								//机器条形码
		char	szProductionTime[CONST_MAXLENGTH_PRODUCTIONTIME + 1];				//生产时间


		long	nDeviceType;														//设备类型
		long	nVideoSystem;														//编码帧模式

		long	nCameraNum;															//摄像头数
		long	nAlarmInNum;														//报警输入个数
		long	nAlarmOutNum;														//报警输出个数

		char	szHardwareVer[CONST_MAXLENGTH_HARDWAREVERSION_EXPAND + 1];					//版本信息
		char	szSoftwareVer[CONST_MAXLENGTH_SOFTWAREVERSION_EXPAND + 1];

		long	nRS485Num;															//RS485串口个数
		long	nRS232Num;															//RS232串口个数

	}ST_DeviceSummaryParam;

	//摄像头信息
	typedef struct _PACKED_1_ tagCameraInfoParam
	{
		long			nCameraId;												//摄像机的ID号

		char			szCameraName[CONST_MAXLENGTH_CAMERA_NAME + 1];			//摄像机的名字

		char			szCameraModel[CONST_MAXLENGTH_CAMERAMODEL + 1];			//摄像机的样式	

		long			nVideoSystem;											//视频制式

	}ST_CameraInfoParam;

	//所有摄像头信息
	typedef struct _PACKED_1_ tagAllCameraInfoParam
	{
		long					nCameraNum;											//摄像头数

		ST_CameraInfoParam		stWebCameraInfoParamList[CONST_MAX_CAMERA_NUM];		//摄像头信息

	}ST_AllCameraInfoParam;

	//cpu统计信息
	typedef struct _PACKED_1_ tagCpuStatistic
	{
		float				fCpuPercent;				//设备cpu百分比
		unsigned char		btCpuStatus;				//设备cpu工作状态

	}ST_CpuStatistic;

	//内存统计信息
	typedef struct _PACKED_1_ tagMemStatistic
	{
		long		nMemTotalSize;				//内存总大小，以KB为单位
		long		nMemFreeSize;				//内存剩余大小，以KB为单位

	}ST_MemStatistic;

	//磁盘统计信息
	typedef struct _PACKED_1_ tagDiskStatistic
	{
		long			nDiskId;				//磁盘编号

		long			nDiskTotalSize;			//磁盘总大小,以KB为单位

		long			nDiskFreeSize;			//磁盘剩余大小,以KB为单位

		unsigned char	btDiskStatus;			//磁盘状态

	}ST_DiskStatistic;

	//所有磁盘统计信息
	typedef struct _PACKED_1_ tagAllDiskStatistic
	{
		ST_DiskStatistic		stDiskStatisticList[CONST_MAX_DISK_NUM];			//磁盘信息

		long					nDiskNum;											//磁盘个数		

	}ST_AllDiskStatistic;

	//视频通道统计信息
	typedef struct _PACKED_1_ tagVideoChannelStatistic
	{
		long			nCameraId;					//摄像机编号

		unsigned char	btRecordStatus;				//录制状态

		unsigned char	btCaptureStatus;			//抓拍状态

		unsigned char	btSignalStatus;				//连接信号状态

		unsigned char	btHardwareStatus;			//硬件状态

		long			nBitRate;					//比特率

	}ST_VideoChannelStatistic;

	//报警输入统计信息
	typedef struct _PACKED_1_ tagAlarmInStatistic
	{
		long			nAlarmInId;					//报警输入通道id号

		unsigned char	btAlarmInStatus;			//报警输入通道状态

		long			nLastAlarmTime;				//最后报警输入时间

	}ST_AlarmInStatistic;

	//报警输出统计信息
	typedef struct _PACKED_1_ tagAlarmOutStatistic
	{
		long			nAlarmOutId;				//报警输出通道id号

		unsigned char	btAlarmOutStatus;			//报警输出通道状态

		long			nLastAlarmTime;				//最后报警时间

	}ST_AlarmOutStatistic;

	//设备运行状态
	typedef struct _PACKED_1_ tagDeviceWorkState
	{
		ST_CpuStatistic				stCpuStatistic;											//cpu统计信息

		ST_MemStatistic				stMemStatistic;											//内存统计信息

		ST_DiskStatistic			stDiskStatisticList[CONST_MAX_DISK_NUM];				//磁盘统计信息
		long						nDiskNum;

		ST_VideoChannelStatistic	stVideoChannelStatisticList[CONST_MAX_CAMERA_NUM];		//视频通道统计信息
		long						nVideoChannelNum;

		ST_AlarmInStatistic			stAlarmInStatisticList[CONST_MAX_ALARM_IN_NUM];			//报警输入统计信息
		long						nAlarmInNum;

		ST_AlarmOutStatistic		stAlarmOutStatisticList[CONST_MAX_ALARM_OUT_NUM];		//报警输出统计信息
		long						nAlarmOutNum;

	}ST_DeviceWorkState;

	//NTP参数
	typedef struct _PACKED_1_ tagNTPParam
	{
		unsigned char	bNTPEnableFlag;											//是否启用NTP的状态

		char			szNTPIp[CONST_MAXLENGTH_IP + 1];						//NTPIP地址

		unsigned short	nNTPPort;												//NTP的端口

		long			nRunTime;												//NTP较时时间

		long			nIPProtoVer;											//IP协议类型

	}ST_NTPParam;

	//DDNS参数
	typedef struct _PACKED_1_ tagDDNSParam
	{
		unsigned char	bDDNSEnableFlag;										//是否启用DDNS的状态

		long			nDDNSProviderId;										//提供者id

		char			szDDNSAccounts[CONST_MAXLENGTH_DDNS_ACCOUNTS + 1];		//DDNS账户

		char			szDDNSDomainName[CONST_MAXLENGTH_DDNS_DOMAINNAME + 1];	//DDNS域名	

		char			szDDNSPassword[CONST_MAXLENGTH_DDNS_PASSWORD + 1];		//DDNS密码
	}ST_DDNSParam;

	//PPPoE参数
	typedef struct _PACKED_1_ tagPPPoEParam
	{
		unsigned char	bPPPoEEnableFlag;										//是否启用PPPoE的状态

		char			szPPPoEUserName[CONST_MAXLENGTH_PPPOE_USERNAME + 1];	//PPPoE的用户名
		char			szPPPoEPassword[CONST_MAXLENGTH_PPPOE_PASSWORD + 1];	//PPPoE的密码

	}ST_PPPoEParam;

	//网络参数
	typedef struct _PACKED_1_ tagHostNetworkParam
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//设备的设备ID

		long			nNetId;													//网口编号

		unsigned char	bAutoGetIpFlag;											//自动获取ip地址
		char			szLocalIp[CONST_MAXLENGTH_IP + 1];						//设备本地IP地址
		char			szLocalSubnetMask[CONST_MAXLENGTH_IP + 1];				//设备本地子网掩码
		char			szGateway[CONST_MAXLENGTH_IP + 1];						//设备网关

		unsigned char	bAutoGetDNSFlag;										//自动获取DNS服务器地址
		char			szPrimaryDNSIp[CONST_MAXLENGTH_IP + 1];					//主DNS
		char			szSpareDNSIp[CONST_MAXLENGTH_IP + 1];					//备用DNS

		unsigned short	nControlPort;											//设备网络控制端口
		unsigned short	nRegisterPort;											//设备注册端口
		unsigned short	nHttpPort;												//设备HTTP端口

		long			nIPProtoVer;											//IP协议类型

		long			nAdapterType;											//适配器类型

	}ST_HostNetworkParam;

	//设备端口参数
	typedef struct _PACKED_1_ tagDevicePortParam
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//DVR设备的设备ID

		unsigned short	m_nControlPort;											//网络视频设备的设备网络控制端口
		unsigned short	m_nTCPAVPort;											//网络视频设备的TCP音视频端口
		unsigned short	m_nRTSPPort;											//网络视频设备的RTSP端口
		unsigned short	m_nRTPPort;												//网络视频设备的RTP端口
		unsigned short	m_nRTCPPort;											//网络视频设备的RTCP端口
		unsigned short	m_nRegisterPort;										//网络视频设备的设备注册端口
		unsigned short	m_nHttpPort;											//网络视频设备的设备HTTP端口

		unsigned short	m_nReservePort1;										//保留使用
		unsigned short	m_nReservePort2;										
		unsigned short	m_nReservePort3;										
		unsigned short	m_nReservePort4;

	}ST_DevicePortParam;

	// PTZ参数
	typedef struct _PACKED_1_ tagPTZParam
	{
		unsigned char	    bPTZEnableFlag;										//是否启动云台

		long				nCameraId;											//云台对应的摄像机号

		long				nPTZDeviceId;										//云台设备地址

		long				nPTZProtocol;										//云台协议

		long				nComId;												//云台连接的串口id

		long				nBaudRate;											//波特率

		long				nDataBits;											//数据位

		long				nStopBits;											//停止位

		long				nParity;											//奇偶校验

	}ST_PTZParam;

	//所有的PTZ参数
	typedef struct _PACKED_1_ tagAllPTZParam
	{
		ST_PTZParam		stPTZParamList[CONST_MAX_CAMERA_NUM];	//PTZ参数

		long			nPTZParamNum;							//PTZ参数个数

	}ST_AllPTZParam;

	//RS485参数
	typedef struct _PACKED_1_ tagRS485Param
	{
		long		nComId;										//串口ID

		char		szComName[CONST_LENGTH_RS485_NAME + 1];		//串口自定义名称

		long		nBaudRate;									//波特率

		long		nDataBits;									//数据位

		long		nStopBits;									//停止位

		long		nParity;									//奇偶校验

		long		nFlowControl;								//流控

	}ST_RS485Param;

	//所有的RS485参数
	typedef struct _PACKED_1_ tagAllRS485Param
	{
		ST_RS485Param stRS485ParamList[CONST_MAX_RS484_NUM];	//RS485参数

		long		  nRs485Num;								//RS485个数

	}ST_AllRS485Param;

	//自动更新服务
	typedef struct _PACKED_1_ tagUpdateParam
	{
		unsigned char   bUpdateEnableFlag;										//启动自动更新服务

		char	    	szUpdateServerIP[CONST_MAXLENGTH_IP + 1];				//更新服务器IP地址

		unsigned short	nUpdateServerPort;										//更新服务器端口号

		long			nUpdatePeriod;											//升级周期时间

		long			nIPProtoVer;											//IP协议类型

	}ST_UpdateParam;

	//计划时间
	typedef struct _PACKED_1_ tagScheduleTime
	{
		long nStartTime;					//开始时间

		long nEndTime;						//结束时间

	}ST_ScheduleTime;

	typedef struct _PACKED_1_ tagScheduleWeek
	{
		long						nWeekDay;	

		int							nScheduleTimeNum;

		ST_ScheduleTime				stScheduleTime[CONST_MAX_PERIOD_SCHEDULE_RECORD_TIME_NUM];

	}ST_ScheduleWeek;

	//计划时间参数
	typedef struct _PACKED_1_ tagScheduleTimeParam
	{
		char						szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];		//设备ID

		long						nCameraId;										//摄像机ID

		ST_ScheduleWeek				stScheduleWeekList[7];							//计划时间

	}ST_ScheduleTimeParam;

	//计划录像参数
	typedef struct _PACKED_1_ tagScheduleRecordParam
	{
		char						szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];

		long						nCameraId;

		unsigned char			    nIsEnableRecord;										//开启录像标志 0:关闭录像；1开启录像

		unsigned char				nIsEnableRecordAudio;									//是否录制音频 0:不录制；1：录制

		long						nScheduleRecordType;									//录像规则

		ST_ScheduleTimeParam		stScheduleTimeParam;									//计划录像时间

	}ST_ScheduleRecordParam;

	//所有的计划录像参数
	typedef struct _PACKED_1_ tagAllScheduleRecordParam
	{
		ST_ScheduleRecordParam stScheduleRecordParamList[CONST_MAX_CAMERA_NUM];				//计划录像参数

		long				   nScheduleRecordNum;											//计划录像数目

	}ST_AllScheduleRecordParam;

	//本地录像磁盘写策略
	typedef struct _PACKED_1_ tagWritePolicy
	{
		long  nStoragePolicy;																//存储策略

		int	  nRecordLengthMode;															//录像类型, （1：按大小录制；2：按时间录制）

		long  nRecordFileMaxSize;															//录制文件最大尺寸

		long  nRecordFileTime;																//单个录像文件的时间大小, 以秒（S）为单位

		char  szFileNameSuffix[CONST_MAXLENGTH_FILENAME_SUFFIX + 1];						//录制文件后缀名

		long  nRecordFormatType;															//录像格式	1为MPEG2PS流，2为自定义流

	}ST_WritePolicy;

	//本地录像保存策略
	typedef struct _PACKED_1_ tagSavePolicy
	{
		long nSaveDays;																		//存储天

	}ST_SavePolicy;

	//本地录像空间策略
	typedef struct _PACKED_1_ tagSpacePolicy
	{
		long	  nCameraId;										//摄像机id

		long	  nMaxDiskSize;										//所能使用的最大磁盘空间

		float	  nScheduleRecordPercent;							//计划录像的所能使用的最大磁盘空间的百分比

		float	  nAlarmRecordPercent;								//报警录像所能使用的最大磁盘空间的百分比

	}ST_SpacePolicy;

	//本地录像存储参数
	typedef struct _PACKED_1_ tagRecordStorageParam
	{
		ST_WritePolicy		stWritePolicy;							//写策略

		ST_SavePolicy		stSavePolicy;							//保存策略

		long			    nCameraNum;								//摄像头数

		ST_SpacePolicy		stSpacePolicy[CONST_MAX_CAMERA_NUM];	//空间策略

	}ST_RecordStorageParam;

	//视频编码质量参数
	typedef struct _PACKED_1_ tagVideoEncodeQuality
	{
		long		nQuality;			//视频质量

		long		nVideoSystem;		//编码帧模式

		double		dFrameRate;			//编码帧速

		long	    nImageFormatId;		//分辨率

		long	    nBitRateType;		//码率类型

		long		nBitRate;			//比特率

		long		nQuant;				//Q值

		long		nIFrameInterval;	//I帧的步长

		long		nEncoderType;		//编码格式。具体可查看ENUM_EncoderType枚举定义

		long		nCodingFlag;		//码流：1：主码流，0：子码流

	}ST_VideoEncodeQuality;

	//音频编码质量参数
	typedef struct _PACKED_1_ tagAudioEncodeQuality
	{
		unsigned short		nFormatTag;					//格式标记

		unsigned short		nChannels;					//声音通道数（声道）

		unsigned long		nSamplesPerSec;				//每秒采样数

		unsigned long		nAvgBytesPerSec;			//

		unsigned short		nBlockAlign;				//

		unsigned short		nBitsPerSample;				//每次采样的大小

		unsigned short		nCBSize;					//后面追加数据长度

		long				nEncodeType;				//编码格式

	}ST_AudioEncodeQuality;

	//录像质量参数
	typedef struct _PACKED_1_ tagRecordQualityParam
	{
		long				  nCameraId;							//摄像头id

		ST_VideoEncodeQuality stVideoVideoEncodeQuality;			//视频编码质量

		ST_AudioEncodeQuality stAudioEncodeQuality;					//音频编码质量

	}ST_RecordQualityParam;

	//所有的录像质量参数
	typedef struct _PACKED_1_ tagAllRecordQualityParam
	{
		ST_RecordQualityParam	  stRecordQualityParamList[CONST_MAX_CAMERA_NUM];				//录像质量

		long					  nRecordQualityNum;											//

	}ST_AllRecordQualityParam;

	//报警输出事件参数
	typedef struct _PACKED_1_ tagAlarmOutActionParam
	{
		char szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];

		long nAlarmOutId;																		//报警输出端口的ID号

		long nAlarmOutFlag;																		//报警输出标志

		long nEventTypeId;																		//报警事件类型

	}ST_AlarmOutActionParam;

	//报警录像事件参数
	typedef struct _PACKED_1_ tagAlarmRecordActionParam
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];								//DVR设备的设备ID

		long			nCameraId;																//摄像机的ID号

		long			nPreRecordTime;															//预录时长

		long			nRecordTime;															//录制时长

		long			nEventTypeId;															//报警事件类型

		unsigned char   nIsEnableRecordAudio;													//是否录制音频

	}ST_AlarmRecordActionParam;

	//报警云台事件参数
	typedef struct _PACKED_1_ tagAlarmPTZActionParam
	{
		long					nEventTypeId;											//报警事件类型

		char					szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//DVR设备的设备ID

		long					nCameraId;												//摄像机的ID号

		long					nComId;													//串口id号

		long					nPtzId;													//云台设备的ID号

		char					btPtzOperationCmd[CONST_MAXLENTH_PTZOPERATION_CMD];		//云台操作命令

		long					nPtzOperationCmdLen;									//云台操作命令长度

		long					nReserve;												//保留位

	}ST_AlarmPTZActionParam;

	//OSD信息参数
	typedef struct _PACKED_1_ tagOSDInfoParam
	{
		long				nOSDType;							//水印类型

		char				szInfo[CONST_MAXLENGTH_OSDINFO + 1];

		unsigned char		bOSDEnableFlag;						//是否显示水印（0：不显示，1：显示）

		long				nTopX;

		long				nTopY;

	}ST_OSDInfoParam;

	//视频OSD信息参数
	typedef struct _PACKED_1_ tagVideoOSDInfoParam
	{
		long					nCameraId;								//摄像机id

		long					nImageFormatID;							//图像格式(此参数已废弃)

		ST_OSDInfoParam			stOSDInfoParam[CONST_MAX_CAMERA_NUM];	//OSD信息参数

		long					nOSDInfoNum;							//OSD信息条目

	}ST_VideoOSDInfoParam;

	//视频OSD信息参数
	typedef struct _PACKED_1_ tagAllVideoOSDInfoParam
	{
		long							nVideoOSDInfoParamNum;							//OSD参数数目

		ST_VideoOSDInfoParam			stVideoOSDInfoParamList[CONST_MAX_CAMERA_NUM];		//OSD参数参数

	}ST_AllVideoOSDInfoParam;
	//OSD信息参数
	typedef struct _PACKED_1_ tagOSDInfoExParam
	{
		long				nOSDType;							//水印类型

		unsigned char		bOSDEnableFlag;						//是否显示水印（0：不显示，1：显示）

		float				nX;

		float				nY;
		
		char				szInfo[CONST_MAXLENGTH_OSDINFO];

	}ST_OSDInfoExParam;

	//视频OSD信息参数
	typedef struct _PACKED_1_ tagVideoOSDInfoExParam
	{
		long					nCameraId;								//摄像机id

		long					nOSDInfoNum;							//OSD信息条目
		ST_OSDInfoExParam		stOSDInfoParam[CONST_MAX_OSDINFO_NUM];	//OSD信息参数

	}ST_VideoOSDInfoExParam;

	//视频OSD信息参数
	typedef struct _PACKED_1_ tagAllVideoOSDInfoExParam
	{
		long							nCameraNum;										//OSD参数数目

		ST_VideoOSDInfoExParam			stVideoOSDInfoParamList[CONST_MAX_CAMERA_NUM];	//OSD参数参数

	}ST_AllVideoOSDInfoExParam;

	typedef struct tagVideoOSDFontTypeParam
	{
		int			nFontID;
		char		szDescription[CONST_OSD_FONT_DESCRIPTION];		//OSD字体

	}ST_VideoOSDFontTypeParam;

	typedef struct tagOSDFontAbilityParam
	{
		int							nVideoOSDFontTypeNum;
		ST_VideoOSDFontTypeParam	stVideoOSDFontTypeList[CONST_MAX_OSD_FONT_TYPE_NUM];

	}ST_OSDFontAbilityParam;

	typedef struct tagVideoOSDFontParam
	{
		int		nCameraID;
		int		nStreamID;
		int		nFontID;

	}ST_VideoOSDFontParam;

	typedef struct tagAllVideoOSDFontParam
	{
		int							nVideoOSDFontNum;
		ST_VideoOSDFontParam		stVideoOSDFonteList[CONST_MAX_CAMERA_NUM];

	}ST_AllVideoOSDFontParam;

	//报警覆盖事件参数
	typedef struct _PACKED_1_ tagAlarmOverlayActionParam
	{
		long nEventTypeId;										//报警事件类型

		char szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];			//DVR设备的设备ID

		long nCameraId;											//摄像机ID号

		ST_OSDInfoParam stOSDInfoParam;							//水印信息类的对象

	}ST_AlarmOverlayActionParam;

	//报警IO参数
	typedef struct _PACKED_1_ tagAlarmIOEventParam
	{
		long								nEventId;																		//报警事件ID

		long								nPolicyId;																		//报警策略ID

		long								nAlarmInId;																		//报警输入端口号

		unsigned char						bAlarmIOEnableFlag;																//是否启动IO报警(0：不启动， 1：启动)

		ST_ScheduleTimeParam				stScheduleTimeParam;															//布防时间参数
		char								szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];										//设备ID号

		long								nAlarmOutActionNum;																//报警输出事件个数
		ST_AlarmOutActionParam				stAlarmOutActionParam[CONST_MAX_ALARM_OUT_NUM];									//报警输出事件

		long								nAlarmRecordActionNum;															//报警录像事件个数
		ST_AlarmRecordActionParam			stAlarmRecordActionParam[CONST_MAX_CAMERA_NUM];									//报警录像事件

		long								nAlarmPTZActionNum;																//报警云台事件个数
		ST_AlarmPTZActionParam				stAlarmPTZActionParam[CONST_MAX_CAMERA_NUM];									//报警云台事件

		long								nAlarmOverlayNum;																//报警覆盖事件个数
		ST_AlarmOverlayActionParam			stAlarmOverlayActionParam[CONST_MAX_CAMERA_NUM];								//报警覆盖事件

	}ST_AlarmIOEventParam;

	//所有I/O报警事件参数
	typedef struct _PACKED_1_ tagAllAlarmIOEventParam
	{
		ST_AlarmIOEventParam stAlarmIOEventParamList[CONST_MAX_ALARM_IN_NUM];			//报警I/O事件

		long				 nAlarmIOEventNum;											//报警I/O事件数目

	}ST_AllAlarmIOEventParam;

	//侦测区域
	typedef struct _PACKED_1_ tagDetectionAreaParam
	{
		long		nTopX;								//侦测区域左上角 x 的坐标
		long		nTopY;								//侦测区域左上角 y 的坐标
		long		nWidth;								//侦测区域宽度
		long		nHeight;							//侦测区域高度

	}ST_DetectionAreaParam;

	//侦测参数
	typedef struct _PACKED_1_ tagMotionDetectionParam
	{
		long							nSensitivity;																	//灵敏度，此参数无效，保留使用

		long							nCheckBlockNum;																	//检测块数

		unsigned char					bToUpCheckFlag;																	//向左检测（1：检测，0：不检测）
		unsigned char					bToDownCheckFlag;																//向下检测（1：检测，0：不检测）
		unsigned char					bToLeftCheckFlag;																//向左检测（1：检测，0：不检测）
		unsigned char					bToRightCheckFlag;																//向右检测（1：检测，0：不检测）
		unsigned char					bAreaMaskFlag;																	//屏蔽标识（1：屏蔽，0：检测）

		long							nImageFormatId;																	//视频格式

		long							nFrameInterval;																	//帧间隔

		long							nDetectionAreaNum;																//侦测区域数目，百分比，指占总移动侦测区域的百分比，百分比越小，侦测灵敏度越高

		ST_DetectionAreaParam			stDetectionAreaList[CONST_MAX_DETECTION_NUM];									//移动侦测区域

	}ST_MotionDetectionParam;

	//侦测报警参数
	typedef struct _PACKED_1_ tagMotionDetectionEventParam
	{
		long							nEventId;																		//报警事件ID

		long							nPolicyId;																		//报警策略ID

		char							szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];										//DVR设备的设备ID

		long							nCameraId;																		//DVR设备摄像头ID号

		unsigned char					bMotionDetectionEnableFlag;														//是否启动运动检测
		ST_ScheduleTimeParam			stScheduleTimeParam;															//布防时间参数

		ST_MotionDetectionParam			stMotionDetectionParam;															//侦测参数

		long							nAlarmOutActionNum;																//报警输出事件个数
		ST_AlarmOutActionParam			stAlarmOutActionParam[CONST_MAX_ALARM_OUT_NUM];									//报警输出事件

		long							nAlarmRecordActionNum;															//报警录像事件个数
		ST_AlarmRecordActionParam		stAlarmRecordActionParam[CONST_MAX_CAMERA_NUM];									//报警录像事件

		long							nAlarmPTZActionNum;																//报警云台事件个数
		ST_AlarmPTZActionParam			stAlarmPTZActionParam[CONST_MAX_CAMERA_NUM];									//报警云台事件

		long							nAlarmOverlayNum;																//报警覆盖事件个数
		ST_AlarmOverlayActionParam		stAlarmOverlayActionParam[CONST_MAX_CAMERA_NUM];								//报警覆盖事件


	}ST_MotionDetectionEventParam;

	//设备所有移动侦测报警事件
	typedef struct _PACKED_1_ tagAllMotionDetectionEventParam
	{
		ST_MotionDetectionEventParam stMotionDetectionEventParamList[CONST_MAX_CAMERA_NUM];				//移动侦测报警事件

		long						 nMotionDetectionEventNum;											//移动侦测报警事件条目

	}ST_AllMotionDetectionEventParam;

	typedef struct _PACKED_1_ tagDetectionAreaV2
	{
		int		nWidthCellNumber;								//区域宽块数，这里代表把整个画面的宽划分为几块
		int		nHighCellNumber;								//区域高块数，这里代表把整个画面的高划分为几块
		char    szData[CONST_MAX_DETECTIONAREA];				//整个区域列表数组，其中以一位代表一格，0表示不需要侦测，1表示需要侦测， 8位一个字节保存在数组中，不足八位的以0填充。
		int		nDataLen;										//字节数组长度,8的整数倍 >= (区域宽块数 * 区域高块数)

	}ST_DetectionAreaV2;

	typedef struct _PACKED_1_ tagMotionDetectionParamV2
	{
		int						nCheckBlockNum;										//检测块数
		int						nSensitivity;											//灵敏度
		ST_DetectionAreaV2		stDetectionAreaV2;	

	}ST_MotionDetectionParamV2;

	typedef struct _PACKED_1_ tagMotionDetectionEventParamV2
	{
		long							nEventId;																		//报警事件ID

		long							nPolicyId;																		//报警策略ID

		char							szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];										//DVR设备的设备ID

		long							nCameraId;																		//DVR设备摄像头ID号

		unsigned char					bMotionDetectionEnableFlag;														//是否启动运动检测
		ST_ScheduleTimeParam			stScheduleTimeParam;															//布防时间参数

		ST_MotionDetectionParamV2		stMotionDetectionParam;															//侦测参数

		long							nAlarmOutActionNum;																//报警输出事件个数
		ST_AlarmOutActionParam			stAlarmOutActionParam[CONST_MAX_ALARM_OUT_NUM];									//报警输出事件

		long							nAlarmRecordActionNum;															//报警录像事件个数
		ST_AlarmRecordActionParam		stAlarmRecordActionParam[CONST_MAX_CAMERA_NUM];									//报警录像事件

		long							nAlarmPTZActionNum;																//报警云台事件个数
		ST_AlarmPTZActionParam			stAlarmPTZActionParam[CONST_MAX_CAMERA_NUM];									//报警云台事件

		long							nAlarmOverlayNum;																//报警覆盖事件个数
		ST_AlarmOverlayActionParam		stAlarmOverlayActionParam[CONST_MAX_CAMERA_NUM];								//报警覆盖事件


	}ST_MotionDetectionEventParamV2;

	//设备所有移动侦测报警事件
	typedef struct _PACKED_1_ tagAllMotionDetectionEventParamV2
	{
		ST_MotionDetectionEventParamV2 stMotionDetectionEventParamList[CONST_MAX_CAMERA_NUM];				//移动侦测报警事件

		long						 nMotionDetectionEventNum;											//移动侦测报警事件条目

	}ST_AllMotionDetectionEventParamV2;



//////////////////

	//遮挡侦测参数
	typedef struct _PACKED_1_ tagOcclusionDetectionParam
	{
		int								nSensitivity;																//灵敏度

		int								nDetectionAreaNum;															//侦测区域数目
		ST_DetectionAreaParam			stDetectionAreaList[CONST_MAX_DETECTION_NUM];								//移动侦测区域

	}ST_OcclusionDetectionParam;

	//遮挡报警参数
	typedef struct _PACKED_1_ tagOcclusionDetectionEventParam
	{
		char							szDeviceId[CONST_MAXLENGTH_DEVICEID];										//设备ID

		int								nCameraId;																	//摄像头ID号

		unsigned char					bOcclusionDetectionEnableFlag;												//是否启动检测

		ST_ScheduleTimeParam			stScheduleTimeParam;														//布防时间参数

		ST_OcclusionDetectionParam		stOcclusionDetectionParam;													//侦测参数

		int								nAlarmOutActionNum;															//报警输出事件个数
		ST_AlarmOutActionParam			stAlarmOutActionParam[CONST_MAX_ALARM_OUT_NUM];								//报警输出事件

		int								nAlarmPTZActionNum;															//报警云台事件个数
		ST_AlarmPTZActionParam			stAlarmPTZActionParam[CONST_MAX_CAMERA_NUM];								//报警云台事件

	}ST_OcclusionDetectionEventParam;

	//设备所有遮挡侦测报警事件
	typedef struct _PACKED_1_ tagAllOcclusionDetectionEventParam
	{
		ST_OcclusionDetectionEventParam stOcclusionDetectionEventParamList[CONST_MAX_CAMERA_NUM];					//移动侦测报警事件

		long							nDetectionEventNum;															//移动侦测报警事件条目

	}ST_AllOcclusionDetectionEventParam;

	//视频丢失报警参数
	typedef struct _PACKED_1_ tagVideoLoseDetectionEventParam
	{
		char							szDeviceId[CONST_MAXLENGTH_DEVICEID];										//设备ID

		int								nCameraId;																	//摄像头ID号

		unsigned char					bVideoLoseDetectionEnableFlag;												//是否启动检测

		int								nAlarmOutActionNum;															//报警输出事件个数
		ST_AlarmOutActionParam			stAlarmOutActionParam[CONST_MAX_ALARM_OUT_NUM];								//报警输出事件

		int								nAlarmPTZActionNum;															//报警云台事件个数
		ST_AlarmPTZActionParam			stAlarmPTZActionParam[CONST_MAX_CAMERA_NUM];								//报警云台事件

	}ST_VideoLoseDetectionEventParam;

	//设备所有移动侦测报警事件
	typedef struct _PACKED_1_ tagAllVideoLoseDetectionEventParam
	{
		ST_VideoLoseDetectionEventParam stVideoLoseDetectionEventParamList[CONST_MAX_CAMERA_NUM];					//视频丢失报警事件

		long							nDetectionEventNum;															//视频丢失报警事件条目

	}ST_AllVideoLoseDetectionEventParam;


/////////////////////

	//报警I/O输入
	typedef struct _PACKED_1_ tagAlarmInParam
	{
		long  nAlarmInId;													//报警输入端口号

		char  szAlarmInputName[CONST_MAXLENGTH_ALARMINPUTNAME + 1];			//报警输入端口名

		long  nAlarmInValidLevel;											//报警输入的有效电平

	}ST_AlarmInParam;

	//报警I/O输出
	typedef struct _PACKED_1_ tagAlarmOutParam
	{

		long		nAlarmOutId;											//报警输出ID号

		char		szAlarmOutName[CONST_MAXLENGTH_ALARMOUTNAME + 1];		//报警输出名称

		long		nAlarmValidSignal;										//报警有效信号

		long		nAlarmMode;												//报警模式
		float		nAlarmOutFrequency;										//报警频率

		long		nAlarmTime;												//报警时长

		long		nActivatedStartTime;									//报警激活开始时间(从00：00到开始时间hh：mm的秒数)
		long		nActivatedEndTime;										//报警激活结束时间(从00：00到结束时间hh：mm的秒数)

	}ST_AlarmOutParam;

	//报警输入设备
	typedef struct _PACKED_1_ tagAllAlarmInParam
	{
		long					nAlarmInNum;									//报警输入设备数目

		ST_AlarmInParam			stAlarmInParamList[CONST_MAX_ALARM_IN_NUM];		//报警输入设备参数

	}ST_AllAlarmInParam;

	//报警输出设备
	typedef struct _PACKED_1_ tagAllAlarmOutParam
	{
		long					nAlarmOutNum;									//报警输出设备数目

		ST_AlarmOutParam		stAlarmOutParamList[CONST_MAX_ALARM_OUT_NUM];	//报警输出设备参数

	}ST_AllAlarmOutParam;

	//报警设备
	typedef struct _PACKED_1_ tagAlarmDeviceParam
	{
		long					nAlarmInNum;									//报警输入数目

		ST_AlarmInParam			stAlarmInParam[CONST_MAX_ALARM_IN_NUM];			//报警输入参数

		long					nAlarmOutNum;									//报警输入数目

		ST_AlarmOutParam		stAlarmOutParam[CONST_MAX_ALARM_OUT_NUM];		//报警输入参数		

	}ST_AlarmDeviceParam;

	//磁盘报警参数
	typedef struct _PACKED_1_ tagDiskAlarmParam
	{
		unsigned char		bDiskFullAlarmCheckFlag;		//是否检测硬盘满
		long				nMaxDiskPercent;				//硬盘报警高阀值（占用硬盘最大比率）
		long				nMinDiskPercent;				//硬盘报警低阀值（占用硬盘最低比率）

		unsigned char		bDiskErrorAlarmCheckFlag;		//是否检测硬盘出错

	}ST_DiskAlarmParam;

	//磁盘报警参数
	typedef struct _PACKED_1_ tagDiskAlarmParamV2
	{
		unsigned int					nInterval;					//上报间隔，单位为秒，最小间隔为10秒，最大为86400秒(1天)
		int								nAlarmThreshold;			//报警阈值, 单位为百分比
		bool							bAlarmEnableFlag;			//是否启动磁盘报警(false：不启动， true：启动)
		long							nAlarmOutActionNum;																//报警输出事件个数
		ST_AlarmOutActionParam			stAlarmOutActionParam[CONST_MAX_ALARM_OUT_NUM];									//报警输出事件
		long							nAlarmPTZActionNum;																//报警云台事件个数
		ST_AlarmPTZActionParam			stAlarmPTZActionParam[CONST_MAX_CAMERA_NUM];									//报警云台事件
	}ST_DiskAlarmParamV2;

	//报警中心参数
	typedef struct _PACKED_1_ tagAlarmServiceParam
	{
		unsigned char		bAlarmCenterEnableFlag;										//是否启用报警中心(0：不启用， 1：启用)

		char				szAlarmCenterServerIP[CONST_MAXLENGTH_IP + 1];				//报警中心IP地址
		unsigned short		nAlarmCenterServerPort;										//报警中心的端口

		unsigned char		bAlarmEmailEnableFlag;										//是否启用报警邮件
		char				szAlarmEmailAddress[CONST_MAXLENTH_EMAIL_ADDRESS + 1];		//报警邮件地址

		long				nIPProtoVer;												//IP协议类型

	}ST_AlarmServiceParam;

	//报警参数
	typedef struct _PACKED_1_ tagAlarmParam
	{
		int						m_nAlarmInterval;			//报警间隔

	}ST_AlarmParam;

	//设备注册服务
	typedef struct _PACKED_1_ tagRegisterParam
	{
		unsigned char	bRegisterEnableFlag;								//是否启用注册(0：不启用， 1：启用)

		char			szRegisterSrvIP[CONST_MAXLENGTH_IP + 1];			//注册服务器IP地址,主机字节顺序

		unsigned short	nRegisterSrvPort;									//注册服务器的端口

		long			nIPProtoVer;										//IP协议类型

	}ST_RegisterParam;

	//拾音器参数配置
	typedef struct _PACKED_1_ tagToneArmParam
	{
		long			nCameraId;											//摄像机的ID号

		unsigned char	bToneArmEnableFlag;									//是否启用拾音器（0：不启用，1：启用）

		long			nToneArmType;										//拾音器类型

		long			nVolume;											//音量

	}ST_ToneArmParam;

	//所有拾音器参数
	typedef struct _PACKED_1_ tagAllToneArmParam 
	{
		ST_ToneArmParam  stToneArmParamList[CONST_MAX_CAMERA_NUM];

		long			 nToneArmNum;

	}ST_AllToneArmParam;

	//扬声器参数
	typedef struct _PACKED_1_ tagLoudhailerParam
	{
		long			nCameraId;										//摄像机的ID号

		unsigned char	bLoudhailerEnableFlag;							//是否启用扬声器（0：不启用，1：启用）

		long			nLoudhailerType;								//扬声器类型

		long			nVolume;										//音量

	}ST_LoudhailerParam;

	typedef struct _PACKED_1_ tagAllLoudhailerParam
	{
		ST_LoudhailerParam stLoudhailerParamList[CONST_MAX_CAMERA_NUM];

		long			   nLoudhailerNum;

	}ST_AllLoudhailerParam;

	//心跳参数配置
	typedef struct _PACKED_1_ tagHeartbeatParam
	{
		char			szHeartbeatServerIp[CONST_MAXLENGTH_IP + 1];	//心跳服务器IP

		unsigned short	nHeartbeatServerPort;							//心跳服务器端口

		long			nHeartbeatInterval;								//发送心跳间隔，以秒为单位

		long			nHeartbeatAckTimeout;							//单个心跳应答超时时间，以秒为单位

		long			nHeartbeatTimeoutCount;							//心跳超时总次数,超过这个次数重登录心跳服务器

		long			nIPProtoVer;									//IP协议类型

	}ST_HeartbeatParam;

	//FTP参数配置
	typedef struct _PACKED_1_ tagFTPParam
	{
		unsigned char	bFTPEnableFlag;												//是否启用FTP的状态

		char			szFTPServerAddr[CONST_MAXLENGTH_IP + 1];					//FTP服务器地址

		char			szFTPUserName[CONST_MAXLENGTH_FTP_USERNAME + 1];			//FTP账户

		char			szFTPPassword[CONST_MAXLENGTH_FTP_PASSWORD + 1];			//FTP密码

		char			szFTPWorkPath[CONST_MAXLENGTH_FTP_WORKPATH + 1];			//FTP工作路径	

		long			nIPProtoVer;												//IP协议类型

	}ST_FTPParam;

	//SMTP参数配置
	typedef struct _PACKED_1_ tagSMTPParam
	{
		unsigned char	bSMTPEnableFlag;										//SMTP启用标志(0：不启用，1：启用)

		unsigned char	bUseDefaultSMTPServerFlag;								//是否使用默认邮箱标识(0：不启用，1：启用)

		char			szSMTPServerAddr[CONST_MAXLENGTH_IP + 1];				//SMTP服务器地址

		unsigned short  nSMTPServerPort;										//SMTP服务器端口

		char			szSMTPUserName[CONST_MAXLENGTH_USERNAME + 1];			//账户

		char			szSMTPPassword[CONST_MAXLENGTH_USERPASSWORD + 1];		//密码

		char			szSenderEmailAddress[CONST_MAXLENGTH_EMAIL_ADDRESS + 1];//发件人地址	

		char			szRecipientEmailAddressList[16][CONST_MAXLENGTH_EMAIL_ADDRESS + 1];//发件人地址
		int				nRecipientEmailAddressCount;							//收件人个数

		int				nMailLanguage;											//邮件内容语言

		int				nAttachmentImageQuality;								//邮件附件的图像质量

	}ST_SMTPParam;

	//IP协议参数
	typedef struct _PACKED_1_ tagCommunicationParam
	{
		long			nIPProtoFlag;			//IP协议类型

	}ST_CommunicationParam;

	//IP协议参数
	typedef struct _PACKED_1_ tagBroadcastParam
	{
		unsigned char	bBroadcastEnableFlag;					//是否启用广播（0：不启用，1：启用）

		unsigned short	nBroadcastPort;							//广播端口

		long			nBroadcastInterval;						//发送广播间隔，以秒为单位

	}ST_BroadcastParam;


	//快照参数
	typedef struct _PACKED_1_ tagSnapshotParam
	{
		long			nCameraId;				//摄像机id

		unsigned char	bSnapshotEnableFlag;	//是否允许抓拍(0：不允许， 1：允许)

		long			nImageFormatId;			//分辨率

		long			nQuality;				//抓拍质量

		long			nShootTimes;			//每次触警抓拍次数

		long			nPhotoFormat;			//图片格式

	}ST_SnapshotParam;

	//所有摄像头快照参数
	typedef struct _PACKED_1_ tagAllSnapshotParam
	{
		ST_SnapshotParam stSnapshotParamList[CONST_MAX_CAMERA_NUM];

		long			 nCameraNum;

	}ST_AllSnapshotParam;

	//录像文件查询参数
	typedef struct _PACKED_1_ tagRecordFileSearchParam
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];			//设备ID

		char			szDeviceName[CONST_MAXLENGTH_DEVICENAME + 1];		//设备名称

		long			nCameraId;											//摄像机ID

		char			szCameraName[CONST_MAXLENGTH_CAMERA_NAME + 1];		//摄像机名称

		char			szDeviceIp[CONST_MAXLENGTH_IP + 1];					//设备IP

		char			szRecordFileName[CONST_MAXLENGTH_FILE_NAME + 1];	//录制文件名称

		unsigned long	nStartTime;											//录制文件开始时间

		unsigned long	nEndTime;											//录制文件结束时间

		long			nRecordType;										//录制类型

		long			nAlarmId;											//报警ID

		long			nAlarmType;											//报警类型

	}ST_RecordFileSearchParam;

	//录像文件参数
	typedef struct _PACKED_1_ tagRecordFile
	{
		long			nId;												//数据库表中的Id

		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];			//设备ID

		char			szDeviceName[CONST_MAXLENGTH_DEVICENAME + 1];		//设备名称

		long			nCameraId;											//摄像机编号

		char			szCameraName[CONST_MAXLENGTH_CAMERA_NAME + 1];		//摄像机名词

		char			szDeviceIp[CONST_MAXLENGTH_IP + 1];					//设备IP

		char			szRecordFileName[CONST_MAXLENGTH_FILE_NAME + 1];	//录制文件名称

		long			nRecordTime;										//录制时间

		long			nRecordType;										//录制文件类型

		long			nAlarmId;											//报警Id

		long			nAlarmType;											//报警类型

		long			nFileByteLength;									//录像文件大小，以字节为单位。

		long			nFileTimeLength;									//录像文件的播放时间长度，以S（秒）为单位

	}ST_RecordFile;

	//日志请求参数
	typedef struct _PACKED_1_ tagLogRequestParam
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];		//设备ID

		char			szDeviceIp[CONST_MAXLENGTH_IP + 1];				//设备IP

		long			nCameraId;										//摄像机ID号

		char			szUserName[CONST_MAXLENGTH_USERNAME + 1];		//用户名

		long			nSelectMode;									//查询方式

		long			nMajorType;										//主类型

		long			nMinorType;										//次类型

		unsigned long	nStartTime;										//开始时间

		unsigned long	nEndTime;										//结束时间

	}ST_LogRequestParam;

	//日志信息参数
	typedef struct _PACKED_1_ tagLogInfo
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];			//设备ID

		char			szDeviceIp[CONST_MAXLENGTH_IP + 1];					//设备IP

		long			nCameraId;											//摄像机ID号

		char			szUserName[CONST_MAXLENGTH_USERNAME + 1];			//用户名

		long			nMajorType;											//主类型

		long			nMinorType;											//次类型

		unsigned long	nLogTime;											//日志产生时间

		char			szLogData[CONST_MAXLENGTH_LOG_DATA + 1];			//日志信息

	}ST_LogInfo;

	///////////
	//日志请求参数
	typedef struct _PACKED_1_ tagLogRequestParamV2
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID];			//设备ID

		char			szDeviceIp[CONST_MAXLENGTH_IP];					//设备IP

		long			nCameraId;										//摄像机ID号

		char			szUserName[CONST_MAXLENGTH_USERNAME];			//用户名

		long			nSelectMode;									//查询方式

		long			nMajorType;										//主类型

		long			nMinorType;										//次类型

		ST_TimeStruct	stStartTime;										//开始时间

		ST_TimeStruct	stEndTime;										//结束时间

	}ST_LogRequestParamV2;

	//日志信息参数
	typedef struct _PACKED_1_ tagLogInfoV2
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID];				//设备ID

		char			szDeviceIp[CONST_MAXLENGTH_IP];						//设备IP

		long			nCameraId;											//摄像机ID号

		char			szUserName[CONST_MAXLENGTH_USERNAME];				//用户名

		long			nMajorType;											//主类型

		long			nMinorType;											//次类型

		ST_TimeStruct	stLogTime;											//日志产生时间

		char			szLogData[CONST_MAXLENGTH_LOG_DATA];				//日志信息

	}ST_LogInfoV2;
	///////////

	typedef struct _PACKED_1_ tagAVFrameData
	{
		long					nStreamFormat;						//1表示原始流，2表示TS混合流，3表示原始加密流，4表示PS混合流。具体可查看ENUM_StreamFormat枚举定义

		long					nESStreamType;						//原始流类型，1表示视频，2表示音频。具体可查看ENUM_ESStreamType枚举定义

		long					nEncoderType;						//编码格式。具体可查看ENUM_EncoderType枚举定义

		long					nCameraNo;							//摄像机号，表示数据来自第几路

		unsigned long			nSequenceId;						//数据帧序号

		long					nFrameType;							//数据帧类型,1表示I帧, 2表示P帧, 0表示未知类型

		INT64					nTimeStamp;							//数据采集时间戳，单位为毫秒

		char*					pszData;							//数据

		unsigned long			nDataLength;						//数据有效长度

		long					nFrameRate;							//帧率

		long					nBitRate;							//当前码率　

		long					nImageFormatId;						//当前格式

		long					nImageWidth;						//视频宽度

		long					nImageHeight;						//视频高度

		long					nVideoSystem;						//当前视频制式

		unsigned long			nFrameBufLen;						//当前缓冲长度

		long					nStreamId;							// 流ID
		long					nTimezone;							// 时区
		long					nDaylightSavingTime;				//夏令时

	}ST_AVFrameData;

	typedef struct _PACKED_1_ tagVideoInfo
	{
		unsigned long		nBitRate;								//比特率

		unsigned long		nBitErrorRate;

		unsigned long		nTimePerFrame;				

		unsigned long		nSize;

		unsigned long		nWidth;									//视频宽度

		unsigned long		nHeight;								//视频高度

		unsigned short		nPlanes;

		unsigned short		nBitCount;

		unsigned long		nCompression;

		unsigned long		nSizeImage;

		long				nXPelsPerMeter;

		long				nYPelsPerMeter;

		unsigned long		nClrUsed;

		unsigned long		nClrImportant;

		char				pszSPS_PPSData[512];

		long				nSPS_PPSDataLen;

	}ST_VideoInfo;

	typedef struct _PACKED_1_ tagAudioInfo
	{
		unsigned short		nFormatTag;			//格式标记

		unsigned short		nChannels;			//声音通道数（声道）

		unsigned long		nSamplesPerSec;		//每秒采样数

		unsigned long		nAvgBytesPerSec;	//

		unsigned short		nBlockAlign;		//

		unsigned short		nBitsPerSample;		//每次采样的大小

		unsigned short		nCBSize;			//后面追加数据长度

		long				nEncodeType;

	}ST_AudioInfo;

	typedef struct _PACKED_1_ tagAlarmData 
	{
		long		nAlarmSourceId;											//报警源ID号

		char		szAlarmSourceName[CONST_MAXLENGTH_ALARMSOURCENAME + 1];	//报警源名称

		long		nAlarmTime;												//报警时间

		long		nAlarmType;												//报警类型

		long		nEventType;												//环境类型

		long		nAlarmCode;												//报警代码

		long		nAlarmFlag;												//报警标志（0：报警产生，1：报警消除）

	}ST_AlarmData;

	typedef struct _PACKED_1_ tagAlarmInfo
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//设备id

		long			nDeviceType;											//设备类型

		char			szDeviceIp[CONST_MAXLENGTH_IP + 1];						//设备IP地址

		ST_AlarmData	stAlarmData;											//报警数据

	}ST_AlarmInfo;

	typedef struct _PACKED_1_ tagAlarmInfoEx
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//设备id

		long			nDeviceType;											//设备类型

		char			szDeviceIp[CONST_MAXLENGTH_IP + 1];						//设备IP地址

		int				nMajorType;												//报警主类型
		int				nMinorType;												//报警子类型
		char			szSourceId[CONST_MAXLENGTH_ALARM_SOURCE_ID + 1];		//源ID
		char			szSourceName[CONST_MAXLENGTH_ALARMSOURCENAME + 1];		//源名称
		int				nAlarmFlag;												//启动/结束标志,（1：报警产生，0：报警消除）
		unsigned long	nAlarmTime;												//时间
		char			szDescription[CONST_MAXLENGTH_ALARM_DESCRIPTION + 1];	//描述

	}ST_AlarmInfoEx;

	typedef struct _PACKED_1_ tagAlarmInfoExV2
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID];					//设备id

		long			nDeviceType;											//设备类型

		char			szDeviceIp[CONST_MAXLENGTH_IP];							//设备IP地址

		int				nMajorType;												//报警主类型
		int				nMinorType;												//报警子类型
		char			szSourceId[CONST_MAXLENGTH_ALARM_SOURCE_ID];			//源ID
		char			szSourceName[CONST_MAXLENGTH_ALARMSOURCENAME];			//源名称
		int				nAlarmFlag;												//启动/结束标志,（1：报警产生，0：报警消除）
		ST_TimeStruct	stAlarmTime;											//报警时间
		char			szDescription[CONST_MAXLENGTH_ALARM_DESCRIPTION];		//描述

	}ST_AlarmInfoExV2;

	//报警行为类型
	typedef struct _PACKED_1_ tagAlarmActionStrategy
	{
		long					nAlarmActionStrategyNum;										//报警行为策略个数
		long					stAlarmActionStrategy[CONST_MAX_ALARM_ACTION_STRATEGY];				//报警行为策略

	}ST_AlarmActionStrategy;

	typedef struct _PACKED_1_ tagDeviceAccessParam
	{
		char			szLocalIp[CONST_MAXLENGTH_IP + 1];					//本地IP地址

		unsigned short	nControlPort;										//网络视频设备的设备网络控制端口
		unsigned short	nVideoTransferPort;									//网络视频设备的设备视频传输端口
		unsigned short	nAudioTransferPort;									//网络视频设备的设备音频传输端口
		unsigned short	nHttpPort;											//网络视频设备的设备HTTP端口

	}ST_DeviceAccessParam;

	typedef struct _PACKED_1_ tagNetVideoDeviceInfo
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];			//设备唯一标识

		int				nDeviceType;										//设备类型

		char			szLocalIp[CONST_MAXLENGTH_IP + 1];					//本地IP地址

		unsigned short	nControlPort;										//网络视频设备的设备网络控制端口

		unsigned short	nHttpPort;											//网络视频设备的设备HTTP端口

		char			szHardwareVer[CONST_MAXLENGTH_HARDWAREVERSION + 1];		//硬件版本信息
		char			szSoftwareVer[CONST_MAXLENGTH_SOFTWAREVERSION + 1];		//软件版本信息

		char			szManufacturerId[CONST_MAXLENGTH_MANUFACTURERID + 1];		//厂商ID
		char			szManufacturerName[CONST_MAXLENGTH_MANUFACTURERNAME + 1];	//厂商名称


	}ST_NetVideoDeviceInfo;

	typedef struct _PACKED_1_ tagRecordDirInfo
	{
		int nDiskType;													//目录磁盘类型
		char szDiskName[CONST_MAXLENGTH_FILE_NAME + 1];					//磁盘名称
		int nGroupId;													//磁盘所属盘组编号
		int nUsableSpace;												//磁盘可用空间 单位：M
		int nFreeSpace;													//磁盘剩余空间 单位：M
		int nAttribute;													//属性
		unsigned char bEnableFlag;										//启用标示
		int nAlarmThreshold;											//报警阈值
		int nStatus;													//磁盘状态	
		int	nFileSystemFormat;											//磁盘文件系统格式
	}ST_RecordDirInfo;

	typedef struct _PACKED_1_ tagRecordDirInfoList
	{
		ST_RecordDirInfo stRecordDirInfoList[CONST_MAX_DISK_NUM];			//磁盘信息列表
		int				 nRecordDirInfoNum;									//磁盘个数
	}ST_RecordDirInfoList;

	typedef struct _PACKED_1_ tagRecordQueryCondition
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];	//设备编号
		char			szDeviceIP[CONST_MAXLENGTH_IP + 1];			//设备IP
		int				nCameraId;									//设备通道号
		unsigned long	nRecordBeginTime;							//录像段开始时间
		unsigned long	nRecordEndTime;								//录像段结束时间
		unsigned char			bIsLockFile;						//录像锁标识
	}ST_RecordQueryCondition;

	typedef struct _PACKED_1_ tagRecordQueryResult
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];	//设备编号
		char			szDeviceIP[CONST_MAXLENGTH_IP + 1];			//设备IP
		int				nCameraId;									//设备通道号
		unsigned long	nRecordBeginTime;							//录像段开始时间
		unsigned long	nRecordEndTime;								//录像段结束时间
		unsigned char	bIsLockFile;								//录像锁标识
		unsigned long	nQuerySegmentInterval;						//查询分段间隔,按多久时间分一段，单位s，0:表示不分段
		int				nQueryTimePrecision;						//录像查询时间精度
	}ST_RecordQueryResult;

	typedef struct _PACKED_1_ tagRecordQueryConditionV2
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];	//设备编号
		char			szDeviceIP[CONST_MAXLENGTH_IP + 1];			//设备IP
		int				nCameraId;									//设备通道号
		ST_TimeStruct	stRecordBeginTime;							//录像段开始时间
		ST_TimeStruct	stRecordEndTime;							//录像段结束时间
		unsigned char	bIsLockFile;								//录像锁标识
		unsigned long	nQuerySegmentInterval;						//查询分段间隔,按多久时间分一段，单位s，0:表示不分段
		int				nQueryTimePrecision;						//录像查询时间精度
	}ST_RecordQueryConditionV2;

	typedef struct _PACKED_1_ tagRecordQueryResultV2
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];	//设备编号
		char			szDeviceIP[CONST_MAXLENGTH_IP + 1];			//设备IP
		int				nCameraId;									//设备通道号
		ST_TimeStruct	stRecordBeginTime;							//录像段开始时间
		ST_TimeStruct	stRecordEndTime;								//录像段结束时间
		unsigned char	bIsLockFile;								//录像锁标识
	}ST_RecordQueryResultV2;

	typedef struct _PACKED_1_ tagRecordInfo
	{
		char					szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];	//设备编号
		char					szDeviceIP[CONST_MAXLENGTH_IP + 1];			//设备IP
		int						nCameraId;									//设备通道号
		unsigned long			nRecordBeginTime;							//录像段开始时间
		unsigned long			nRecordEndTime;								//录像段结束时间
		unsigned char			bIsLockFile;								//录像锁标识
	}ST_RecordInfo;

	typedef struct _PACKED_1_ tagRecordInfoV2
	{
		char					szDeviceId[CONST_MAXLENGTH_DEVICEID];		//设备编号
		char					szDeviceIP[CONST_MAXLENGTH_IP];				//设备IP
		int						nCameraId;									//设备通道号
		ST_TimeStruct			stRecordBeginTime;							//录像段开始时间
		ST_TimeStruct			stRecordEndTime;							//录像段结束时间
		unsigned char			bIsLockFile;								//录像锁标识
		bool					bIsAlarm;									//文件是否报警
	}ST_RecordInfoV2;

	//流配置参数
	typedef struct _PACKED_1_ tagAVStreamParam
	{
		int				nCameraId;												//摄像机ID
		int				nStreamId;												//码流ID
		char			szStreamName[CONST_MAXLENGTH_AVSREAM_NAME + 1];				//码流名
		int				nVideoHeight;											//高度
		int				nVideoWidth;											//宽度
		int				nFrameRate;												//帧率
		int				nBitRateType;											//码率类型
		int				nBitRate;												//码率
		int				nQuality;												//视频质量值
		int				nIFrameInterval;										//I帧步长
		int				nIFrameIntervalUnit;									//I帧单位
		int				nVideoEncoderType;										//视频编码类型。具体可查看ENUM_EncoderType枚举定义
		int				nAudioEncoderType;										//音频编码类型。具体可查看ENUM_EncoderType枚举定义
	}ST_AVStreamParam;

	//流配置参数
	typedef struct _PACKED_1_ tagAllAVStreamParam
	{
		int						nStreamNum;

		ST_AVStreamParam		stAVStreamParamList[CONST_MAX_STREAM_NUM];

	}ST_AllAVStreamParam;

	
	//报警事件
	typedef struct _PACKED_1_ tagAlarmEvent
	{
		int nAlarmType;

		int nAlarmId;

	}ST_AlarmEvent;

	//报警录像策略
	typedef struct _PACKED_1_ tagAlarmRecordPolicy
	{
		int								nAlarmPreRecordTime;

		int								nAlarmDelayRecordTime;

		unsigned char					bIsAlarmRecordFileLocked;

		unsigned char					bIsAlarmRecordOpened;

		int								nAlarmEventNum;

		ST_AlarmEvent					stAlarmEventList[CONST_MAX_ALARM_EVENT_NUM];

	}ST_AlarmRecordPolicy;

	//计划录像策略
	typedef struct _PACKED_1_ tagScheduleRecordPolicy
	{
		unsigned char					bIsScheduleRecordOpened;

		int								nScheduleRecordType;

		ST_ScheduleTimeParam			stScheduleTimeParam;

	}ST_ScheduleRecordPolicy;

	//录像策略
	typedef struct _PACKED_1_ tagRecordPolicyParam
	{
		int								nCameraId;				//摄像机编号

		int								nSaveDays;				//保存天数

		unsigned char					bCycleWriteFlag;		//循环写标志

		unsigned char					bIsRedundancy;			//是否冗余

		int								nDiskGroupId;			//存储盘组ID

		int								nStreamId;				//码流ID

		unsigned char					bIsRecordAudioOpened;	//是否录制音频

		ST_AlarmRecordPolicy			stAlarmRecordPolicy;	//报警录制策略

		ST_ScheduleRecordPolicy			stScheduleRecordPolicy;	//计划录像策略

	}ST_RecordPolicyParam;

	//所有的录像策略参数
	typedef struct _PACKED_1_ tagAllRecordPolicyParam
	{
		int								nRecordPolicyNum;

		ST_RecordPolicyParam			stRecordPolicyParam[CONST_MAX_CAMERA_NUM];
		
	}ST_AllRecordPolicyParam;

////////////////////////////////////////////////////////////////

	//侦测区域
	typedef struct _PACKED_1_ tagColorParam
	{
		unsigned long		nRed;						//红色值（0-255）
		unsigned long		nGreen;						//绿色值（0-255）
		unsigned long		nBlue;						//蓝色值（0-255）
		unsigned long		nAlpha;						//透明度（0-100），此参数预留

	}ST_ColorParam;

	//侦测区域
	typedef struct _PACKED_1_ tagAreaParam
	{
		long		nTopX;								//区域左上角 x 的坐标占总视频区宽度的百分比
		long		nTopY;								//区域左上角 y 的坐标占总视频区高度的百分比
		long		nWidth;								//区域宽度占视频区总宽度的百分比
		long		nHeight;							//区域高度占总视频区高度的百分比

	}ST_AreaParam;

	//设备隐私遮蔽参数
	typedef struct _PACKED_1_ tagBlindAreaParam
	{
		long					nCameraId;											//摄像机ID号

		unsigned char			bEnableFlag;										//是否启用遮蔽（1：启用，0：不启用）
		
		ST_ColorParam			stColorParam;										//颜色
		
		long					nAreaParamNum;										//侦测区域数目
		ST_AreaParam			stAreaParamList[CONST_MAX_AREA_NUM];				//移动侦测区域

	}ST_BlindAreaParam;

	//设备所有隐私遮蔽参数
	typedef struct _PACKED_1_ tagAllBlindAreaParam
	{
		long						nBlindAreaParamNum;									//隐私遮蔽参数条目
	
		ST_BlindAreaParam			stBlindAreaParamList[CONST_MAX_CAMERA_NUM];				//隐私遮蔽参数列表

	}ST_AllBlindAreaParam;

	//设备基本信息
	typedef struct _PACKED_1_ tagDeviceBaseInfo
	{
		char				szDeviceId[CONST_MAXLENGTH_DEVICEID];								//设备唯一标识
		char				szDeviceName[CONST_MAXLENGTH_DEVICENAME];							//设备名称
		int					nDeviceType;														//设备类型

		char				szDeviceIP[CONST_MAXLENGTH_IP];										//设备IP地址
		unsigned short		nDevicePort;														//设备端口
		int					nIPProtoVer;														//IP协议类型
		char				szUserID[CONST_MAXLENGTH_USERID];									//登陆设备的用户ID
		char				szPassword[CONST_MAXLENGTH_PASSWORD];								//登陆设备的密码

		char				szManufacturerId[CONST_MAXLENGTH_MANUFACTURERID];					//设备型号
		char				szManufacturerName[CONST_MAXLENGTH_MANUFACTURERNAME];				//设备生产厂家
		char				szProductModel[CONST_MAXLENGTH_PRODUCTMODEL];						//产品模组
		char				szProductDescription[CONST_MAXLENGTH_PRODUCTDESCRIPTION];			//产品描述
		char				szHardwareModel[CONST_MAXLENGTH_HARDWAREMODEL];						//硬件模组
		char				szHardwareDescription[CONST_MAXLENGTH_HARDWAREDESCRIPTION];			//硬件描述
		char				szMACAddress[CONST_MAXLENGTH_MACADDRESS];							//MAC地址
		char				szBarCode[CONST_MAXLENGTH_BARCODE];									//机器条形码
		char				szProductionTime[CONST_MAXLENGTH_PRODUCTIONTIME];					//生产时间
		
		char				szHardwareVer[CONST_MAXLENGTH_HARDWAREVERSION_EXPAND];				//版本信息
		char				szSoftwareVer[CONST_MAXLENGTH_SOFTWAREVERSION_EXPAND];


		int					nCameraNum;																//通道数（摄像机数）
		int					nAlarmInNum;															//报警输入个数
		int					nAlarmOutNum;															//报警输出个数
		int					nRS485Num;																//RS485串口个数

		ST_CameraInfoParam	stWebCameraInfoParamList[CONST_MAX_CAMERA_NUM];							//摄像头信息

	}ST_DeviceBaseInfo;

	//设备基本信息列表
	typedef struct _PACKED_1_ tagDeviceBaseInfoList
	{
		int					nDeviceBaseInfoNum;													//设备数

		ST_DeviceBaseInfo	stDeviceBaseInfoList[CONST_MAX_NVR_DEVICE_NUM];							//设备列表

	}ST_DeviceBaseInfoList;

	//设备状态信息
	typedef struct _PACKED_1_ tagDeviceStateInfo
	{
		char				szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];							//设备唯一标识

		int					nDeviceType;														//设备类型

		long				nLastActiveTime;													//最后活动时间，精确到秒

		unsigned char		btOnlineState;														//在线状态（0：不在线，1：在线）

		ST_InetAddr			stInetAddr;															//设备的网络地址

		int					m_nSearchMode;														//在线更新方式，1：广播，2：主动搜索，3：在线搜索

	}ST_DeviceStateInfo;


	//外部接口
	typedef struct _PACKED_1_ tagExternInterface
	{
		int					nInterfaceType;
		ST_RS485Param		stRS485Device;

	}ST_ExternInterface;

	//PTZ键盘参数
	typedef struct _PACKED_1_ tagPTZKeyboardParam
	{
		unsigned char		bEnableFlag; //是否启动云台键盘(1：启动，0：不启动)

		ST_ExternInterface	stExternInterface;

	}ST_PTZKeyboardParam;

	//点钞机参数
	typedef struct _PACKED_1_ tagCashRegistersParam
	{
		unsigned char		bEnableFlag;	//是否启动点钞机(1：启动，0：不启动)
		int					nOSDTopX;		//列
		int					nOSDTopY;		//行
		int					nOSDLanguage;	//语言
		int					nModel;			//模式

		int					nOSDCameraIDList[CONST_MAX_CAMERA_NUM]; //通道ID
		int					nCameraNum;								//通道数

		ST_ExternInterface stExternInterface;					//外部接口

	}ST_CashRegistersParam;


	//点钞机参数
	typedef struct _PACKED_1_ tagTimeZoneParam
	{
		int				nTimeZone;												//时区

		bool			bDSTOpenFlag;											//夏令时开启标志
		int				nDSTOffset;												//夏令时偏移，以秒为单位

		int				nBeginMonth;											//夏令时开始月份
		int				nBeginWeekly;											//夏令时开始周（一月中的第几周）
		int				nBeginWeekDays;											//星期几
		unsigned int	nBeginTime;												//开始时间

		int				nEndMonth;												//夏令时结束月份
		int				nEndWeekly;												//夏令时结束周（一月中的第几周）
		int				nEndWeekDays;											//星期几
		unsigned int	nEndTime;												//结束时间

	}ST_TimeZoneParam;

	//快照参数
	typedef struct _PACKED_1_ tagRemoteSnapshotParam
	{
		int				nCameraID;													//通道号
		int				nQuality;													//质量
		int				nPhotoFormat;												//图像格式

	}ST_RemoteSnapshotParam;

	//保留列表
	typedef struct _PACKED_1_ tagRetainTypeList
	{
		int					nRetainTypeNum;										//报警行为策略个数
		int					nRetainTypeList[CONST_MAX_RETAIN_TYPE];				//报警行为策略

	}ST_RetainTypeList;


	//网络参数
	typedef struct _PACKED_1_ tagNetworkParam
	{
		int				nNetworkCardId;									//网口编号
		int				nWorkingType;									//工作类型，1.公共网络 2.摄像机网络 3.绑定
		int				nIPProtoVer;									//IP协议类型
		bool			bAutoGetIpFlag;									//自动获取IP地址(true：自动获取，false：不自动获取)
		char			szDhcpIp[CONST_MAXLENGTH_IP];					//DHCP IP
		char			szLocalIp[CONST_MAXLENGTH_IP];					//本地IP地址
		char			szLocalSubnetMask[CONST_MAXLENGTH_IP];			//子网掩码
		char			szGateway[CONST_MAXLENGTH_IP];					//网关
		bool			bAutoGetDNSFlag;								//自动获取DNS服务器IP地址(true：自动获取，false：不自动获取)
		char			szPrimaryDNSIp[CONST_MAXLENGTH_IP];				//首选DNS服务器IP地址
		char			szSpareDNSIp[CONST_MAXLENGTH_IP];				//备用DNS服务器IP地址
	}ST_NetworkParam;
	
	//网络参数列表
	typedef struct _PACKED_1_ tagNetworkParamList
	{
		int							nNetworkParamNum;									//网络参数个数
		ST_NetworkParam				stNetworkParam[CONST_MAX_NETWORK_CARD_NUM];		//网络参数列表
	}ST_NetworkParamList;


	//报警查询参数
	typedef struct _PACKED_1_ tagAlarmInfoExQueryParam
	{
			char				szDeviceId[CONST_MAXLENGTH_DEVICEID];				//设备编号
			char				szDeviceIP[CONST_MAXLENGTH_IP];						//设备IP地址
			char				szSourceId[CONST_MAXLENGTH_ALARM_SOURCE_ID];		//报警源Id
			char				szSourceName[CONST_MAXLENGTH_ALARMSOURCENAME];		//源名称
			int					nMajorType;											//报警主类型
			int					nMinorType;											//报警子类型
			ST_TimeStruct		stAlarmBeginTime;									//开始时间
			ST_TimeStruct		stAlarmEndTime;										//结束时间

	}ST_AlarmInfoExQueryParam;

	//报警记录参数
	typedef struct _PACKED_1_ tagAlarmInfoExRecordSet
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID];					//设备ID
		char			szDeviceIP[CONST_MAXLENGTH_IP];							//设备IP
		char			szSourceId[CONST_MAXLENGTH_ALARM_SOURCE_ID];			//报警源ID
		char			szSourceName[CONST_MAXLENGTH_ALARMSOURCENAME];			//源名称
		char			szDescription[CONST_MAXLENGTH_ALARM_DESCRIPTION];		//描述
		int				nDeviceType;											//设备类型
		int				nMajorType;												//报警主类型
		int				nMinorType;												//报警小类型

		ST_TimeStruct	stAlarmBeginTime;										//报警开始时间
		ST_TimeStruct	stAlarmEndTime;											//报警结束时间

	}ST_AlarmInfoExRecordSet;


	//实时视频通道参数
	typedef struct _PACKED_1_ tagLiveVideoChannel
	{
		char szDeviceID[CONST_MAXLENGTH_DEVICEID];	//设备ID
		int  nChannelID;							//通道ID

	}ST_LiveVideoChannel;

	//布局窗口参数
	typedef struct _PACKED_1_ tagLayoutWindow
	{
		int					nWinId;
		int					nLiveVideoChannelNum;
		ST_LiveVideoChannel stLiveVideoChannelList[CONST_MAX_LIVE_VIDEO_CHANNEL_NUM];

	}ST_LayoutWindow;

	//实时视频布局参数
	typedef struct _PACKED_1_ tagLiveVideoLayout
	{
		char  szLayoutName[CONST_MAX_LAYOUT_NAME];
		char  szUserName[CONST_MAXLENGTH_USERNAME];
		int	  nAccessControlType;
		int   nLayoutMode;
		int   nCycleScanInterval;

		int				nLayoutWindowNum;
		ST_LayoutWindow stLayoutWindowList[CONST_MAX_LAYOUIT_WINDOW_NUM];	//

	}ST_LiveVideoLayout;

	//实时视频布局参数列表
	typedef struct _PACKED_1_ tagLiveVideoLayoutList
	{
		int					nLiveVideoLayoutNum;
		ST_LiveVideoLayout	stLiveVideoLayoutList[CONST_MAX_LIVE_VIDEO_LAYOUT_NUM];	//

	}ST_LiveVideoLayoutList;

	//设备流参数
	typedef struct _PACKED_1_ tagDeviceAVStreamParam
	{
		char						szDeviceId[CONST_MAXLENGTH_UUID];	
		int							nAVStreamParamNum;
		ST_AVStreamParam			stAVStreamParamList[CONST_MAX_AV_STREAM_NUM];

	}ST_DeviceAVStreamParam;

	//设备流参数列表
	typedef struct _PACKED_1_ tagDeviceAVStreamParamList
	{
		int							nDeviceAVStreamParamNum;
		ST_DeviceAVStreamParam		stDeviceAVStreamParamList[CONST_MAX_DEVICE_AV_STREAM_PARAM_NUM];

	}ST_DeviceAVStreamParamList;

	//录像状态参数
	typedef struct _PACKED_1_ tagRecordState
	{
		char	szDeviceId[CONST_MAXLENGTH_DEVICEID];			//设备ID
		int		nCameraId;										//摄像机ID
		int		nState;											//录像状态

	}ST_RecordState;

	//录像状态参数列表
	typedef struct _PACKED_1_ tagRecordStateList
	{
		int					nRecordStateNum;								//录像状态数量
		ST_RecordState		stRecordStateList[CONST_MAX_RECORD_STATE_NUM];  //录像状态

	}ST_RecordStateList;

	//监视器参数
	typedef struct _PACKED_1_ tagMonitorParam
	{
		int		nMonitorId;			//监视器ID
		int		nMonitorType;		//监视器类型

	}ST_MonitorParam;

	//监视器参数
	typedef struct _PACKED_1_ tagMonitorParamList
	{
		int					nMonitorParamNum;			//监视器个数
		ST_MonitorParam		stMonitorParamList[CONST_MAX_MONITOR_NUM];		//监视器列表

	}ST_MonitorParamList;

	//Bonjour配置参数
	typedef struct _PACKED_1_ tagBonjourServiceParam
	{
		bool	bBonjourEnableFlag;								//启用bonjour标识(true：启用，false：不启用)

	}ST_BonjourServiceParam;

	//Bonjour配置参数
	typedef struct _PACKED_1_ tagUpnpServiceParam
	{
		bool	bUpnpEnableFlag;								//启用Upnp标识(true：启用，false：不启用)

	}ST_UpnpServiceParam;

	//////////////////////////////////wifi////////////////////////////////////////
	typedef struct _PACKED_1_ tagWifiHotspotParam
	{
		char	szSSID[CONST_MAXLENGTH_SSID+1];
		char	szEncryptionType[CONST_MAXLENGTH_ENCRYPTION_TYPE+1];
		int		nSignalQuality;

	}ST_WifiHotspotParam;

	typedef struct _PACKED_1_ tagWifiHotspotParamList
	{
		int					nWifiHotspotParamNum;
		ST_WifiHotspotParam stWifiHotspotParam[CONST_MAX_WIFIHOTSPOTPARAM_NUM];

	}ST_WifiHotspotParamList;

	typedef struct _PACKED_1_ tagWifiParam
	{
		bool			bEnableFlag;								//是否启用Wifi
		char			szSSID[CONST_MAXLENGTH_SSID+1];				//SSID
		char			szPassword[CONST_MAXLENGTH_USERPASSWORD+1];	//密码

		bool			bUseDynamicIPFlag;							//是否启用动态IP
		char			szStaticIP[CONST_MAXLENGTH_IP + 1];			//静态IP地址
		char			szSubnetMask[CONST_MAXLENGTH_IP + 1];		//子网掩码
		char			szGateway[CONST_MAXLENGTH_IP + 1];			//网关
		char			szDNS[CONST_MAXLENGTH_IP + 1];				//DNS服务器IP地址
	}ST_WifiParam;

	typedef struct _PACKED_1_ tagWifiStateParam
	{
		int		nConnectState;									//连接状态
		int		nSignalQuality;									//信号状态
	}ST_WifiStateParam;


	typedef struct _PACKED_1_ tagWifiAbilityParam
	{
		bool	bSupportFlag;														//是否支持标志
		char	szWifiDeviceName[CONST_MAXLENGTH_WIFI_DEVICE_NAME+1];				//Wifi设备名
	}ST_WifiAbilityParam;


	typedef struct _PACKED_1_ tagWifiNetworkParam
	{
		char	szIP[CONST_MAXLENGTH_IP + 1];				//IP地址
		char	szSubnetMask[CONST_MAXLENGTH_IP + 1];		//子网掩码
		char	szGateway[CONST_MAXLENGTH_IP + 1];			//网关

		char	szPrimaryDNS[CONST_MAXLENGTH_IP + 1];		//首选DNS服务器IP地址
		char	szSpareDNS[CONST_MAXLENGTH_IP + 1];			//备用DNS服务器IP地址
	}ST_WifiNetworkParam;

	typedef struct _PACKED_1_ tagSVCStreamParam
	{
		int		nSourceStreamID;		//原流ID
		int		nSVCStreamID;			//伴随流ID
		int		nFrameSkipInterval;   //p帧跳帧间隔
		char	szStreamName[CONST_MAXLENGTH_AVSREAM_NAME + 1];		//码流名称
	}ST_SVCStreamParam;

	//PTZ
	typedef struct _PACKED_1_ tagPTZPreset
	{
		int		nCameraId;													//摄像头ID号
		int		nPresetId;													//云台预制点的ID号
		char	szPresetName[CONST_MAXLENGTH_PTZ_PRESET_NAME + 1];			//云台预制点的名字

	}ST_PTZPreset;

	typedef struct _PACKED_1_ tagPTZPresetList
	{
		int nPTZPresetCount;
		ST_PTZPreset  stPTZPreset[CONST_MAX_PTZ_PRESET_NUM];
	}ST_PTZPresetList;

	typedef struct _PACKED_1_ tagPTZTourPoint
	{
		int nTourPointID;		//轨迹预置点id
		int nWaiteTime;		//等待时间
		int nSpeed;			//速度
	}ST_PTZTourPoint;

	typedef struct _PACKED_1_ tagPTZTourPointList
	{
		int nPTZTourPointCount;
		ST_PTZTourPoint stPTZTourPoint[CONST_MAX_PTZ_TOURPOINT_NUM];

	}ST_PTZTourPointList;

	typedef struct _PACKED_1_ tagPTZTourEx
	{
		int		nTourID;																//轨迹编号
		char	szTourName[CONST_MAXLENGTH_PTZ_TOUR_NAME + 1];							//云台巡游的名字

		int		nPTZTourPointCount;
		ST_PTZTourPoint	stPTZTourPointList[CONST_MAX_PTZ_TOURPOINT_NUM];			//组成轨迹的预置点集合
	}ST_PTZTourEx;

	typedef struct _PACKED_1_ tagPTZTourExList
	{
		int nPTZTourExCount;
		ST_PTZTourEx  stPTZTourPointList[CONST_MAX_PTZ_TOURPOINT_NUM];
	}ST_PTZTourExList;

	typedef struct _PACKED_1_ tagPTZScan
	{
		int		nCameraId;												//摄像头ID号
		int		nScanId;													//云台扫描的ID号
		char	szScanName[CONST_MAXLENGTH_PTZ_SCAN_NAME + 1];			//云台扫描的名字
	}ST_PTZScan;

	typedef struct _PACKED_1_ tagPTZScanList
	{
		int nPTZScanNum;
		ST_PTZScan	stPTZScanList[CONST_MAX_PTZ_SCAN_NUM];									//云台扫描的名字
	}ST_PTZScanList;

	//轨迹
	typedef struct _PACKED_1_ tagPTZTrack
	{
		int		nCameraId;												//摄像头ID号
		int		nTrackId;												//云台预制点的ID号
		char	szTrackName[CONST_MAXLENGTH_PTZ_TRACK_NAME + 1];		//云台预制点的名字
	}ST_PTZTrack;
	
	typedef struct _PACKED_1_ tagPTZTrackList
	{
		int nPTZTrackNum;
		ST_PTZTrack  stPTZTrackList[CONST_MAX_PTZ_TRACK_NUM];

	}ST_PTZTrackList;

	typedef struct _PACKED_1_ tagSensorAbility
	{
		int nSensorControllerOpenType;	     //前端配置打开类型，具体参照SensorControllerOpenType
	}ST_SensorAbility;

	typedef struct _PACKED_1_ tagOSDTimeFormatType
	{
		int nFormatId;
		char szDescription[CONST_OSD_TIMEFORMAT_DESCRIPTION + 1];		//OSD时间格式

	}ST_OSDTimeFormatType;

	typedef struct _PACKED_1_ tagOSDFormatAbility
	{
		int nOSDTimeFormatTypeNum;
		ST_OSDTimeFormatType stOSDTimeFormatTypeList[CONST_MAX_OSD_TIME_FORMAT_TYPE_NUM];
	}ST_OSDFormatAbility;


	typedef struct _PACKED_1_ tagNetworkAlarmEvent
	{
		int								nNetworkCardId;			//报警网卡ID号
		bool							bAlarmEnableFlag;		//是否启动报警(false：不启动， true：启动)
		long							nAlarmOutActionNum;																//报警输出事件个数
		ST_AlarmOutActionParam			stAlarmOutActionParam[CONST_MAX_ALARM_OUT_NUM];									//报警输出事件
		long							nAlarmPTZActionNum;																//报警云台事件个数
		ST_AlarmPTZActionParam			stAlarmPTZActionParam[CONST_MAX_CAMERA_NUM];									//报警云台事件

	}ST_NetworkAlarmEvent;

	typedef struct _PACKED_1_ tagNetworkAlarmEventList
	{
		int                         nNetworkAlarmEventCount;
		ST_NetworkAlarmEvent        stNetworkAlarmEvent[CONST_MAX_CAMERA_NUM];
	}ST_NetworkAlarmEventList;
	
	typedef struct _PACKED_1_ tagNetworkAlarmParam
	{
		unsigned int					nInterval;					//上报间隔，单位为秒，最小间隔为10秒，最大为86400秒(1天)
		ST_NetworkAlarmEventList		stNetworkAlarmEventList;		//设置网络报警事件列表
	}ST_NetworkAlarmParam;

	typedef struct _PACKED_1_ tagPTZTimerTimeSegment
	{
		unsigned long	nBeginTime;									//开始时间，从00:00开始到当前时间的秒数，如01:30为5400
		unsigned long	nEndTime;										//结束时间，从00:00开始到当前时间的秒数，如01:30为5400
		char			szPTZOperation[CONST_MAXLENTH_PTZ_CMD + 1];	//云台操作命令

	}ST_PTZTimerTimeSegment;

	typedef struct _PACKED_1_ tagPTZTimerTimeSegmentList
	{
		int nPTZTimerTimeSegmentCount;
		ST_PTZTimerTimeSegment  stPTZTimerTimeSegment[CONST_MAX_PTZ_TIME_RTIMESEGMENT_NUM];
	}ST_PTZTimerTimeSegmentList;

	typedef struct _PACKED_1_ tagPTZTimer
	{
		bool								bEnableFlag;					//是否启用
		int									nCameraId;						//摄像头ID号
		int									nTimerMode;						//时间模式，为TIMER_MODE枚举之一
		ST_TimeStruct						stTimeStruct;					//设置一次时间模式时的时间日期
		ST_PTZTimerTimeSegmentList			stPTZTimerTimeSegmentList;		//定时器时间段列表
	}ST_PTZTimer;

	typedef struct _PACKED_1_ tagPTZTimerList
	{
		int			nPTZTimerCount;
		ST_PTZTimer  stPTZTimerList[CONST_MAX_PTZ_TIME_RTIMESEGMENT_NUM];
	}ST_PTZTimerList;

	typedef struct _PACKED_1_ tagMTUParam
	{
		int		nMTUValue;//MTU值
	}ST_MTUParam;

	typedef struct _PACKED_1_ tagRGBColor
	{
		int nRed;
		int nGreen;
		int nBlue;
	}ST_RGBColor;

	typedef struct _PACKED_1_ tagMosaicParam
	{
		unsigned int		nWidth;								//宽
		unsigned int		nHeight;							//高
	}ST_MosaicParam;

	typedef struct _PACKED_1_ tagBlindAbilityV2
	{
		int nMaxBlindAreaNum;	     //支持最大的遮挡区域数目
		int nBlindAreaRate;			//遮挡区域面积占源分辨率百分比

		int nTypeNum;
		int szTypeList[CONST_MAX_BLINDABILITYV2_TYPE];			//支持的隐私遮蔽类型列表
 
		int nAlphaNum;
		int szAlphaList[CONST_MAX_BLINDABILITYV2_ALPHA];			//支持的透明度列表

		int nRGBColorNum;
		ST_RGBColor stRGBColor[CONST_MAX_BLINDABILITYV2_RGBCOLOR];	//颜色支持列表
	
		int nMosaicParamNum;
		ST_MosaicParam stMosaicParam[CONST_MAX_BLINDABILITYV2_MOSAICPARAM];//支持的马赛克大小列表
	}ST_BlindAbilityV2;

	typedef struct _PACKED_1_ tagLibCommonAbility
	{
		int		nLibId;                    //库ID
		bool	bEnable;                   //ID库是否启用

		int		nResolutionWidth;          //要求的源分辨率
		int		nResolutionHeight;         //要求的源分辨率

		int		nTotalAnalyseRegionNum;    //该库支持的分析功能个数
		int		nMaxEnableFunsNum;         //该库最多同时开启的功能

	}ST_LibCommonAbility;


	typedef struct _PACKED_1_ tagMotionDetectionAbilityV2
	{
		int  nLibId;					//智能库ID
		bool bCellEnable;				//是否支持该项能力
		int  nCellHeightCellNumber;	//移动侦测方格的高的块数
		int	 nCellWidthCellNumber;		//移动侦测方格的宽的块数
		bool bEnable;					//是否支持该项能力  todo
		bool bSensitivityEnable;		//是否支持配置该项能力
		int  nSensitivityMax;			//所支持配置的灵敏度的最大值
		int  nSensitivityMin;			//所支持配置的灵敏度的最小值

	}ST_MotionDetectionAbilityV2;

	typedef struct _PACKED_1_ tagPerimeterAbility
	{
		int		nLibId;							//智能库ID
		bool	bDetailGetEnable;				//是否支持该能力
		int		nEdgeNum;							//分析区域个数
		bool	bEnable;							//是否支持该项能力
		int		nMaxRegionNum;					//最多支持的分析区域个数
		bool	bMaxTargetSizeEnable;			//物品移动（ObjMove）能力是否支持		
		int		nMaxTargetSizeMax;				//最多支持的分析区域个数
		int		nMaxTargetSizeMin;				//目标最大尺寸的最小值
		char	szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//目标最大尺寸的单位	//TODO
		bool	bMinTargetSizeEnable;			//是否支持目标最小尺寸
		int		nMinTargetSizeMax;				//目标最大尺寸的最大值
		int		nMinTargetSizeMin;				//目标最大尺寸的最小值
		char    szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//目标最小尺寸的单位	//TODO
		bool	bRegionEnable;					//分析区域能力是否支持
		bool	bSensitivityEnable;				//是否支持灵敏度的配置
		int		nSensitivityMax;					//所支持配置的灵敏度的最大值
		int		nSensitivityMin;					//所支持配置的灵敏度的最小值
		bool	bTargetSizeConstrainEnable;		//是否限定目标大小的能力的支持与否
		int		nTargetSizeConstrainMax;			//限定目标大小的最大值
		int		nTargetSizeConstrainMin;			//限定目标大小的最小值
		char    szTargetSizeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];//限定目标大小的单位
		bool	bTargetTypeConstrainEnable;		 //限定目标类型的能力的支持与否
		int		nTargetTypeConstrainMax;			 //目标类型的最大尺寸
		int		nTargetTypeConstrainMin;			 // 目标类型的最小尺寸
		char   szTargetTypeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];//目标类型尺寸的单位	//TODO
		bool	bTargetTypeEnable;				 //限定类型能力的支持与否
		int		nTargetTypeMax;					 //限定类型的尺寸的最大值
		int		nTargetTypeMin;					 //限定类型的尺寸的最小值
		char    szTargetTypeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		 //限定类型的尺寸的单位 //TODO

	}ST_PerimeterAbility;

	typedef struct _PACKED_1_ tagTripWireAbility
	{
		int		nLibId;							//智能库ID
		bool	bRegionEnable;					//是否支持该项能力
		int		nEdgeNum;							//分析区域个数
		int		nMaxRegionNum;					//最多支持的分析区域个数
		bool	bBidirectionEnable;				//是否支持该项能力
		bool	bDetailGetEnable;				//获取详细信息的能力是否支持
		bool	bEnable;							//绊线（TripWire）能力是否支持
		bool	bMaxTargetSizeEnable;			//是否支持目标最大尺寸
		int		nMaxTargetSizeMax;				//目标最大尺寸的最大值
		int		nMaxTargetSizeMin;				//目标最大尺寸的最小值
		char    szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN+1];		//目标最大尺寸的单位		//TODO
		bool	bMinTargetSizeEnable;			//是否支持目标最小尺寸
		int		nMinTargetSizeMax;				//目标最小尺寸的最大值
		int		nMinTargetSizeMin;				//目标最小尺寸的最小值
		char    szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN+1];		//目标最小尺寸的单位		//TODO
		bool	bTargetSizeConstrainEnable;		//限定目标大小的能力的支持与否
		int		nTargetSizeConstrainMax;			//限定目标大小的最大值
		int		nTargetSizeConstrainMin;			//限定目标大小的最小值
		char   szTargetSizeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN+1]; //限定目标大小的单位		//TODO
		bool	bTargetTypeConstrainEnable;		//限定目标类型的能力的支持与否
		int		nTargetTypeConstrainMax;			//目标类型的最大尺寸
		int		nTargetTypeConstrainMin;			//目标类型的最小尺寸
		char   szTargetTypeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN+1];//目标类型尺寸的单位		//TODO
		bool	bTargetTypeEnable;				//限定类型能力的支持与否
		int		nTargetTypeMax;					//限定类型的尺寸的最大值
		int		nTargetTypeMin;					//限定类型的尺寸的最小值
		char   szTargetTypeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN+1];		//限定类型的尺寸的单位		//TODO
		bool	bTriggerDirectionEnable;			//是否支持双绊线的触发方向设置的功能

	}ST_TripWireAbility;

	typedef struct _PACKED_1_ tagMultiTripWireAbility
	{
		int		nLibId;							//智能库ID
		bool	bRegionEnable;					//分析区域能力是否支持
		int		nEdgeNum;						//支持的分析区域个数
		int		nMaxRegionNum;					//最多支持的分析区域个数	
		bool	bDetailGetEnable;				//是否获取详细信息的能力是否支持
		bool	bEnable;						//双绊线（MultiTripWire）能力是否支持
		bool	bMaxTargetSizeEnable;			//是否支持目标最大尺寸
		int		nMaxTargetSizeMax;				//目标最大尺寸的最大值
		int		nMaxTargetSizeMin;				//目标最大尺寸的最小值
		char    szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//目标最大尺寸的单位
		bool	bMinTargetSizeEnable;			//是否支持目标最小尺寸
		int		nMinTargetSizeMax;				//目标最小尺寸的最大值
		int		nMinTargetSizeMin;				//目标最小尺寸的最小值
		char    szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//目标最小尺寸的单位
		bool	bTargetSizeConstrainEnable;		//是否限定目标大小的能力的支持与否
		int		nTargetSizeConstrainMax;		//限定目标大小的最大值
		int		nTargetSizeConstrainMin;		//限定目标大小的最小值
		char   szTargetSizeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];//限定目标大小的单位
		bool	bTargetTypeConstrainEnable;		 //限定目标类型的能力的支持与否
		int		nTargetTypeConstrainMax;		 //目标类型的最大尺寸
		int		nTargetTypeConstrainMin;		 //目标类型的最小尺寸
		char   szTargetTypeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];//目标类型尺寸的单位
		bool	bTargetTypeEnable;				//限定类型能力的支持与否
		int		nTargetTypeMax;					//限定类型的尺寸的最大值
		int		nTargetTypeMin;					//限定类型的尺寸的最小值
		char	szTargetTypeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//限定类型的尺寸的单位
		bool	bTimeIntervalEnable;			//是否支持双绊线的时间间隔的功能
		int		nTimeIntervalMin;				//双绊线的时间间隔的最小值
		int		nTimeIntervalMax;				//双绊线的时间间隔的最大值
		char   szTimeIntervalUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//双绊线的时间间隔的单位
		bool	bTriggerDirectionEnable;		//是否支持双绊线的触发方向设置的功能
	}ST_MultiTripWireAbility;

	typedef struct _PACKED_1_ tagLoiterAbility
	{
		int		nLibId;								//智能库ID
		bool	bAnalysisPathEnable;				//是否支持路径判断
		int		nAnalysisPathMax;					//路径判断的最大值
		int		nAnalysisPathMin;					//路径判断的最小值
		char   szAnalysisPathUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//路径判断的单位
		bool	bDetailGetEnable;					//是否获取详细信息的能力是否支持
		int		nEdgeNum;							//支持的分析区域个数
		bool	bEnable;							//徘徊（Loiter）能力是否支持
		int		nMaxRegionNum;						//最多支持的分析区域个数
		bool	bMaxTargetSizeEnable;				//是否支持目标最大尺寸
		int		nMaxTargetSizeMax;					//目标最大尺寸的最大值
		int		nMaxTargetSizeMin;					//目标最大尺寸的最小值
		char    szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//目标最大尺寸的单位
		bool	bMinTargetSizeEnable;				//是否支持目标最小尺寸
		int		nMinTargetSizeMax;					//目标最小尺寸的最大值
		int		nMinTargetSizeMin;					//目标最小尺寸的最小值
		char    szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//目标最小尺寸的单位
		bool	bMinTimeEnable;						//是否支持最小时间的能力
		int		nMinTimeMax;						//最小时间的最大值
		int		nMinTimeMin;						// 最小时间的最小值
		char    szMinTimeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//最小时间的单位
		bool	bRegionEnable;						//分析区域能力是否支持
		bool	bTargetSizeConstrainEnable;			//是否限定目标大小的能力的支持与否
		int		nTargetSizeConstrainMax;			//限定目标大小的最大值
		int		nTargetSizeConstrainMin;			//限定目标大小的最小值
		char   szTargetSizeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];	//限定目标大小的单位
		bool	bTargetTypeConstrainEnable;			//是否限定目标大小的能力的支持与否
		int		nTargetTypeConstrainMax;			//目标类型的最大尺寸
		int		nTargetTypeConstrainMin;			//目标类型的最小尺寸
		char   szTargetTypeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];	//目标类型尺寸的单位
		bool	bTargetTypeEnable;					//限定类型能力的支持与否
		int		nTargetTypeMax;						//限定类型的尺寸的最大值
		int		nTargetTypeMin;						//限定类型的尺寸的最小值
		char   szTargetTypeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//限定类型的尺寸的单位
	}ST_LoiterAbility;

	typedef struct _PACKED_1_ tagMultiLoiterAbility
	{
		int		nLibId;						//智能库ID
		bool	bAnalysisPathEnable;		//是否支持路径判断
		int		nAnalysisPathMax;			//路径判断的最大值
		int		nAnalysisPathMin;			//路径判断的最小值
		char   szAnalysisPathUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];	//路径判断的单位
		bool	bDetailGetEnable;			//是否获取详细信息的能力是否支持
		int		nEdgeNum;					//分析区域个数
		bool	bEnable;					//多人徘徊（MultiLoiter）能力是否支持
		bool	bForbiddenTypeEnable;		//是否支持禁止人数范围的功能
		int		nMaxRegionNum;				//最多支持的分析区域个数
		bool	bMaxTargetSizeEnable;		//是否支持目标最大尺寸
		int		nMaxTargetSizeMax;			//目标最大尺寸的最大值
		int		nMaxTargetSizeMin;			//目标最大尺寸的最小值
		char    szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];	//目标最大尺寸的单位
		bool	bMaximumEnable;				//是否支持禁止人数范围的最大值功能
		int		nMaximumMax;				//禁止人数范围最大值范围的最大值
		int		nMaximumMin;				//禁止人数范围最大值范围的最小值
		char   szMaximumUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//禁止人数范围最大值范围的单位
		bool	bMinTargetSizeEnable;		//是否支持目标最小尺寸
		int		nMinTargetSizeMax;			//目标最小尺寸的最大值
		int		nMinTargetSizeMin;			//目标最小尺寸的最小值
		char   szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];	//目标最小尺寸的单位
		bool	bMinTimeEnable;				//是否支持最小时间的能力
		int		nMinTimeMax;				//最小时间的最大值
		int		nMinTimeMin;				//最小时间的最小值
		char   szMinTimeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//最小时间的单位
		bool	bMinimumEnable;				//是否支持禁止人数范围的最小值功能
		int		nMinimumMax;				//禁止人数范围最小值范围的最大值
		int		nMinimumMin;				//禁止人数范围最小值范围的最小值
		char    szMinimumUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//禁止人数范围最小值范围的单位
		bool	bRegionEnable;				//分析区域能力是否支持
		bool	bTargetSizeConstrainEnable;	//是否限定目标大小的能力的支持与否
		int		nTargetSizeConstrainMax;	//限定目标大小的最大值
		int		nTargetSizeConstrainMin;	//限定目标大小的最小值
		char   szTargetSizeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];//限定目标大小的单位
	}ST_MultiLoiterAbility;

	typedef struct _PACKED_1_ tagObjLeftAbility
	{
		int		nLibId;								//智能库ID
		bool	bDetailGetEnable;					//是否获取详细信息的能力是否支持
		int		nEdgeNum;							//支持的分析区域个数
		bool	bEnable;							//物品遗留（ObjLeft）能力是否支持
		int		nMaxRegionNum;						//最多支持的分析区域个数
		bool	bMaxTargetSizeEnable;				//是否支持目标最大尺寸
		int		nMaxTargetSizeMax;					//目标最大尺寸的最大值
		int		nMaxTargetSizeMin;					//目标最大尺寸的最小值
		char    szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//目标最大尺寸的单位
		bool	bMinTargetSizeEnable;				//是否支持目标最小尺寸
		int		nMinTargetSizeMax;					//目标最小尺寸的最大值
		int		nMinTargetSizeMin;					//目标最小尺寸的最小值
		char    szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//目标最小尺寸的单位
		bool	bMinTimeEnable;						//是否支持该项能力
		int		nMinTimeMax;						//最小时间的最大值
		int		nMinTimeMin;						//最小时间的最小值
		char    szMinTimeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//最小时间的单位
		bool	bRegionEnable;						//是否支持该项能力
	}ST_ObjLeftAbility;

	typedef struct _PACKED_1_ tagObjMoveAbility
	{
		int		nLibId;								//智能库ID
		bool	bDetailGetEnable;					//是否获取详细信息的能力是否支持
		int		nEdgeNum;							//分析区域个数
		bool	bEnable;							//物品移动（ObjMove）能力是否支持
		int		nMaxRegionNum;						//最多支持的分析区域个数
		bool	bMaxTargetSizeEnable;				//是否支持目标最大尺寸
		int		nMaxTargetSizeMax;					//目标最大尺寸的最大值
		int		nMaxTargetSizeMin;					//目标最大尺寸的最小值
		char    szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//目标最大尺寸的单位
		bool	bMinTargetSizeEnable;				//是否支持目标最小尺寸
		int		nMinTargetSizeMax;					//目标最小尺寸的最大值
		int		nMinTargetSizeMin;					//目标最小尺寸的最小值
		char    szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//目标最小尺寸的单位
		bool	bMinTimeEnable;						//是否支持最小时间的能力
		int		nMinTimeMax;						//最小时间的最大值
		int		nMinTimeMin;						//最小时间的最小值
		char    szMinTimeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//最小时间的单位
		bool	bRegionEnable;						//分析区域能力是否支持
	}ST_ObjMoveAbility;


	typedef struct _PACKED_1_ tagAbnormalSpeedAbility
	{
		bool	bEnable;									//非正常速度（AbnormalSpeed）能力是否支持
		int		nLibId;										//智能库ID

		bool	bRegionEnable;								//是否支持该项能力
		int		nEdgeNum;									//分析区域个数
		int		nMaxRegionNum;								//最多支持的分析区域个数
		bool	bDetailGetEnable;							//是否获取详细信息的能力是否支持

		bool	bTargetTypeConstrainEnable;					//限定目标类型的能力的支持与否
		int		nTargetTypeConstrainMin;					//目标类型的最小尺寸
		int		nTargetTypeConstrainMax;					//目标类型的最大尺寸
		char	szTargetTypeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//目标类型尺寸的单位

		bool	bTargetTypeEnable;							//限定类型能力的支持与否
		int		nTargetTypeMin;								//限定类型的尺寸的最小值
		int		nTargetTypeMax;								//限定类型的尺寸的最大值
		char	szTargetTypeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];					//限定类型的尺寸的单位

		bool	bTargetSizeConstrainEnable;					//是否限定目标大小的能力的支持与否
		int		nTargetSizeConstrainMin;					//限定目标大小的最小值
		int		nTargetSizeConstrainMax;					//限定目标大小的最大值
		char	szTargetSizeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//限定目标大小的单位

		bool	bMinTargetSizeEnable;						//是否支持目标最小尺寸
		int		nMinTargetSizeMin;							//目标最小尺寸的最小值
		int		nMinTargetSizeMax;							//目标最小尺寸的最大值
		char	szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];					//目标最小尺寸的单位

		bool	bMaxTargetSizeEnable;						//是否支持目标最大尺寸
		int		nMaxTargetSizeMin;							//目标最大尺寸的最小值
		int		nMaxTargetSizeMax;							//目标最大尺寸的最大值
		char	szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];					//目标最大尺寸的单位

		bool	bRateLimitingTypeEnable;					//是否支持极速标识（允许范围或禁止范围）的能力
		int		nRateLimitingTypeMin;						//极速标识的最小值
		int		nRateLimitingTypeMax;						//极速标识的最大值
		char	szRateLimitingTypeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//极速标识的单位

		bool	bMinRateEnable;								//是否支持最小运动速度
		int		nMinRateMin;								//最小运动速度的最小值
		int		nMinRateMax;								//最小运动速度的最大值
		char	szMinRateUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];						//最小运动速度的单位

		bool	bMaxRateEnable;								//是否支持最大运动速度
		int		nMaxRateMin;								//最大运动速度的最小值
		int		nMaxRateMax;								//最大运动速度的最大值
		char	szMaxRateUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];						//最大运动速度的单位
	}ST_AbnormalSpeedAbility;

	typedef struct _PACKED_1_ tagConverseAbility
	{
		int		nLibId;									//智能库ID
		bool	bConverseAngleEnable;					//是否支持翻转角度的能力
		float	fConverseAngleMax;						//翻转角度值的最大值
		float	fConverseAngleMin;						//翻转角度值的最小值
		char    szConverseAngleUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//翻转角度值的单位
		bool	bDetailGetEnable;						//是否获取详细信息的能力的是否支持
		int		nEdgeNum;								//分析区域个数
		bool	bEnable;								//翻转（Converse）能力是否支持
		int		nMaxRegionNum;							//最多支持的分析区域个数
		bool	bMaxTargetSizeEnable;					//是否支持目标最大尺寸
		int		nMaxTargetSizeMax;						//目标最大尺寸的最大值
		int		nMaxTargetSizeMin;						//目标最大尺寸的最小值
		char	szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//目标最大尺寸的单位

		bool	bMinTargetSizeEnable;					//是否支持目标最小尺寸
		int		nMinTargetSizeMax;						//目标最小尺寸的最大值
		int		nMinTargetSizeMin;						//目标最小尺寸的最小值
		char	szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//目标最小尺寸的单位

		bool	bRegionEnable;							//分析区域能力是否支持
		bool	bTargetSizeConstrainEnable;				//限定目标大小的能力的支持与否
		int		nTargetSizeConstrainMax;				//限定目标大小的最大值
		int		nTargetSizeConstrainMin;				//限定目标大小的最小值
		char	szTargetSizeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//限定目标大小的单位

		bool	bTargetTypeConstrainEnable;				//限定目标类型的能力的支持与否
		int		nTargetTypeConstrainMax;				//目标类型的最大尺寸
		int		nTargetTypeConstrainMin;				//目标类型的最小尺寸
		char	szTargetTypeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//目标类型尺寸的单位
		bool	bTargetTypeEnable;						//限定类型能力的支持与否
		int		nTargetTypeMax;							//限定类型的尺寸的最大值
		int		nTargetTypeMin;							//限定类型的尺寸的最小值
		char	szTargetTypeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//限定类型的尺寸的单位
	}ST_ConverseAbility;	

	typedef struct _PACKED_1_ tagNoParkingAbility
	{
		int		nLibId;								//智能库ID
		bool	bDetailGetEnable;					//详细信息的能力是否支持
		int		nEdgeNum;							//分析区域个数
		bool	bEnable;							//非法停车（NoParking）能力是否支持

		int		nMaxRegionNum;						//最多支持的分析区域个数
		bool	bMaxTargetSizeEnable;				//是否支持目标最大尺寸
		int		nMaxTargetSizeMax;					//目标最大尺寸的最大值
		int		nMaxTargetSizeMin;					//目标最大尺寸的最小值
		char	szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//目标最大尺寸的单位

		bool	bMinTargetSizeEnable;				//是否支持目标最小尺寸
		int		nMinTargetSizeMax;					//目标最小尺寸的最大值
		int		nMinTargetSizeMin;					//目标最小尺寸的最小值
		char	szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//目标最小尺寸的单位

		bool	bMinTimeEnable;						//是否支持最小时间的能力
		int		nMinTimeMax;						//最小时间的最大值
		int		nMinTimeMin;						//最小时间的最小值
		char	szMinTimeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//最小时间的单位
		bool	bRegionEnable;						//分析区域能力是否支持
	}ST_NoParkingAbility;

	typedef struct _PACKED_1_ tagSignalBadAbility
	{
		int		nLibId;                   //所属的库ID
		bool	bEnable;                 //是否支持该项能力
		bool	bDetailGet;              //是否获取详细信息
	}ST_SignalBadAbility;

	typedef struct _PACKED_1_ tagCameraTamperAbility
	{
		bool	bEnable;				//视频遮挡（CameraTamper）能力是否支持
		int		nLibId;					//智能库ID
		bool	bMinTimeEnable;			//是否支持最小时间的能力
		int		nMinTimeMax;			//最小时间的最大值
		int		nMinTimeMin;			//最小时间的最小值
		char    szMinTimeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];	//最小时间的单位

	}ST_CameraTamperAbility;

	typedef struct _PACKED_1_ tagCameraMoveAbility
	{
		bool	bEnable;			//摄像机移动（CameraMoveAbility）能力是否支持
		int		nLibId;			//智能库ID
	}ST_CameraMoveAbility;

	typedef struct _PACKED_1_ tagAdvancedAbility
	{
		bool	bEnable;						//高级参数（Advanced）能力是否支持
		int		nLibId;							//智能库ID

		bool	bSceneEnable;					//室内/室外的能力是否支持
		int		nSceneMin;						//室内/室外的参数值的最小值
		int		nSceneMax;						//室内/室外的参数值的最大值
		char	szSceneUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//室内/室外的参数值的单位

		bool	bHightEnable;					//安装高度的能力是否支持
		char	szHightUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//安装高度的单位

		bool	bAngleEnable;					//安装角度的能力是否支持
		char	szAngleUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//安装角度的单位

		bool	bFOVEnable;						//摄像机镜头视场角FOV的能力是否支持
		char	szFOVUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//摄像机镜头视场角FOV的单位

		bool	bPixelToRealSizeEnable;			//摄像机像素与实体物体长度的转换的能力是否支持
		bool	bRealSizeEnable;				//物体实际长度的能力是否支持
		char	szRealSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//物体实际长度的单位
		bool	bSegmentLayTypeEnable;			//线段方位(水平/垂直)是否支持
		bool	bSegmentEnable;					//线段参数的能力是否支持
//add new 
		bool	bCameraShakeEnable;
		int		nCameraShakeMin;
		int		nCameraShakeMax;

		bool	bHighNoiseEnable;
		int		nHighNoiseMin;
		int		nHighNoiseMax;

		bool	bLowContrastEnable;
		int		nLowContrastMin;
		int		nLowContrastMax;

		bool	bPeriodMotionEnable;
		int		nPeriodMotionMin;
		int		nPeriodMotionMax;

		bool	bPeriodMotionTimeEnable;
		int		nPeriodMotionTimeMin;
		int		nPeriodMotionTimeMax;

		char	szPeriodMotionTimeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];

	}ST_AdvancedAbility;

	typedef struct _PACKED_1_ tagIntelligenceAnalyseAbility
	{
		int    							  nVersion;                         //版本
		int								  nLibCommonAbilityNum;				 //各个智能分析库必备的能力值个数
		ST_LibCommonAbility				  stLibCommonAbilityList[CONST_MAX_LIBCOMMONABILITY_NUM];        //各个智能分析库必备的能力值  //todo

		ST_MotionDetectionAbilityV2       stMotionDetectionAbilityV2;         //移动侦测对应的能力
		ST_PerimeterAbility               stPerimeterAbility;                 //入侵能力
		ST_TripWireAbility                stTripWireAbility;                  //绊线能力
		ST_MultiTripWireAbility           stMultiTripWireAbility;             //双绊线能力
		ST_LoiterAbility                  stLoiterAbility;                    //徘徊能力
		ST_MultiLoiterAbility             stMultiLoiterAbility;               //多人徘徊对应的能力
		ST_ObjLeftAbility                 stObjLeftAbility;                   //物品遗留对应的能力
		ST_ObjMoveAbility                 stObjMoveAbility;                   //物体移走对应的能力

		ST_AbnormalSpeedAbility           stAbnormalSpeedAbility;             //非正常速度对应的能力
		ST_ConverseAbility                stConverseAbility;                  //逆行对应的能力
		ST_NoParkingAbility               stNoParkingAbility;                 //非法停车对应的能力
		ST_SignalBadAbility               stSignalBadAbility;                 //信号异常对应的能力
		ST_CameraTamperAbility            stCameraTamperAbility;              //视频遮挡对应的能力
		ST_CameraMoveAbility              stCameraMoveAbility;                //摄像机移动对应的能力
		ST_AdvancedAbility                stAdvancedAbility;                  //高级参数对应的能力

	}ST_IntelligenceAnalyseAbility;

	typedef struct _PACKED_1_ tagSNPoint
	{
		float fXval;			//X坐标
		float fYval;			//y 坐标
	}ST_SNPoint;

	typedef struct _PACKED_1_ tagPolygonArea
	{
		int nSNPointNum;						//节点个数
		ST_SNPoint		stSNPoint[CONST_MAX_SNPOINT];			//节点 //TODO

	}ST_PolygonArea;

	typedef struct _PACKED_1_ tagPerimeterRegionParam
	{
		int					nSensitivity;			//	灵敏度	
		bool 				bTargetTypeConstrain;	//	是否限定目标类型(取值范围：0(否)，1(是))
		int					nTargetType;			//	类型限定模式(取值范围：0(人或车)，1(人)，2(车))
		bool				bTargetSizeConstrain;	//	是否限定目标尺寸(取值范围：0(否)，1(是))
		int					nMinTargetSize;			//  目标最小尺寸(单位：平方厘米)
		int					nMaxTargetSize;			//	目标最大尺寸(单位：平方厘米)
		ST_PolygonArea		stRegion;				//	分析区域

	}ST_PerimeterRegionParam;

	typedef struct _PACKED_1_ tagIntelligeBaseParam
	{
		char	szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//设备的设备ID
		int		nCameraId;
		bool	bIsEnable;
		int		nAlarmInterval;

		ST_ScheduleTimeParam				stScheduleTimeParam;

		long								nAlarmOutActionNum;																//报警输出事件个数
		ST_AlarmOutActionParam				stAlarmOutActionParam[CONST_MAX_ALARM_OUT_NUM];									//报警输出事件

		long								nAlarmRecordActionNum;															//报警录像事件个数
		ST_AlarmRecordActionParam			stAlarmRecordActionParam[CONST_MAX_CAMERA_NUM];									//报警录像事件

		long								nAlarmPTZActionNum;																//报警云台事件个数
		ST_AlarmPTZActionParam				stAlarmPTZActionParam[CONST_MAX_CAMERA_NUM];									//报警云台事件

		long								nAlarmOverlayNum;																//报警覆盖事件个数
		ST_AlarmOverlayActionParam			stAlarmOverlayActionParam[CONST_MAX_CAMERA_NUM];	
	}ST_IntelligeBaseParam;

	typedef struct _PACKED_1_ tagPerimeterParam			
	{													
		bool					bIsGetDetail;//是否显示详细信息
		int						nPerimeterRegionParamNum;	//分析区域个数			
		ST_PerimeterRegionParam stPerimeterRegionParamList[CONST_MAX_PERIMETERREGIONPARAM];//分析区域列表//TODO									
		ST_IntelligeBaseParam	stIntelligeBaseParam;

	}ST_PerimeterParam;


	typedef struct _PACKED_1_ tagLineCross
	{
		float		fLineCrossStartX;       //起始点X坐标（占屏幕的百分比）
		float		fLineCrossStartY;       //起始点Y坐标
		float		fLineCrossEndX;		    //结束点X坐标
		float		fLineCrossEndY;		    //结束点Y坐标
	}ST_LineCross;


	typedef struct _PACKED_1_ tagTripWireRegionParam
	{
		bool 		bTargetTypeConstrain;    //是否限定目标类型(取值范围：0(否)，1(是))
		int			nTargetType;             // 类型限定模式(取值范围：0(人或车)，1(人)，2(车))
		bool		bTargetSizeConstrain;	 // 是否限定目标尺寸(取值范围：0(否)，1(是))
		int			nMinTargetSize;          // 目标最小尺寸(单位：平方厘米)
		int			nMaxTargetSize;          //目标最大尺寸(单位：平方厘米)

		bool		bIsBidirection;          // 表示绊线是否为双向绊线(取值范围：0(否)，1(是))
		int			nTriggerDirection;       //绊线禁止方向角度(单位：度)
		ST_LineCross	stTripWireLine;      //绊线位置(单位：像素)
	}ST_TripWireRegionParam;

	typedef struct _PACKED_1_ tagTripWireParam
	{
		bool						bIsGetDetail;			//是否显示详细信息
		int							nTripWireRegionParamNum;//分析区域个数
		ST_TripWireRegionParam		stTripWireRegionParamList[CONST_MAX_TRIPWIREREGIONPARAM];	//分析区域//TODO
		ST_IntelligeBaseParam		stIntelligeBaseParam;
	}ST_TripWireParam;



	typedef struct _PACKED_1_ tagMultiTripWireRegionParam
	{
		bool 				bTargetTypeConstrain;        // 是否限定目标类型(取值范围：0(否)，1(是))
		int					nTargetType;                 // 类型限定模式(取值范围：0(人或车)，1(人)，2(车))
		bool				bTargetSizeConstrain;        //是否限定目标尺寸(取值范围：0(否)，1(是))
		int					nMinTargetSize;              //目标最小尺寸(单位：平方厘米)
		int					nMaxTargetSize;              //目标最大尺寸(单位：平方厘米)

		int					nTimeInterval;               //穿越两条线的最长时间间隔(单位：秒)
		int				    nTriggerDirectionList[CONST_MAX_TRIGGERDIRECTION];    //绊线禁止方向角度(单位：度)0～360 度  //TODO
		
		ST_LineCross		stTripWireLineList[CONST_MAX_TRIPWIRELINE];      //绊线位置(单位：像素)  //TODO
	}ST_MultiTripWireRegionParam;

	typedef struct _PACKED_1_ tagMultiTripWireParam
	{
		bool	bIsGetDetail;	//是否获取详细信息
		int		nMultiTripWireRegionParamNum;//分析区域个数
		ST_MultiTripWireRegionParam stMultiTripWireRegionParamList[CONST_MAX_MULTITRIPWIREREGIONPARAM];//分析区域列表  TODO
		ST_IntelligeBaseParam		stIntelligeBaseParam;
	}ST_MultiTripWireParam;



	typedef struct _PACKED_1_ tagLoiterRegionParam
	{
		bool 				 bTargetTypeConstrain;		//是否限定目标类型(取值范围：0(否)，1(是))
		int					 nTargetType;				//类型限定模式(取值范围：0(人或车)，1(人)，2(车))
		bool				 bTargetSizeConstrain;		//是否限定目标尺寸(取值范围：0(否)，1(是))
		int					 nMinTargetSize;			//目标最小尺寸(单位：平方厘米)(取值范围：0~1000000)
		int					 nMaxTargetSize;			//目标最大尺寸(单位：平方厘米)(取值范围：0~1000000)

		int					 nMinTime;					//徘徊最短时间(单位: 秒)
		bool				 bIsAnalysisPath;			//是否启用路径判断(取值范围：0(否)，1(是))

		ST_PolygonArea		 stRegion;					//区域信息
	}ST_LoiterRegionParam;

	typedef struct _PACKED_1_ tagLoiterParam
	{
		bool				 bIsGetDetail;//是否显示详细信息
		int					 nLoiterRegionParamNum;
		ST_LoiterRegionParam LoiterRegionParamList[CONST_MAX_LOITERPARAM];//分析区域列表//TODO
		ST_IntelligeBaseParam		stIntelligeBaseParam;
	}ST_LoiterParam;


	typedef struct _PACKED_1_ tagMultiLoiterRegionParam
	{	
		bool			bTargetSizeConstrain;		//!< 是否限定目标尺寸(取值范围：0(否)，1(是))
		int				nMinTargetSize;				//!< 目标最小尺寸(单位：平方厘米)
		int				nMaxTargetSize;				//!< 目标最大尺寸(单位：平方厘米)

		int				nMinTime;						//!< 徘徊最短时间(单位：秒)
		bool			bAnalysisPath;					//是否启用路径判断

		bool			bForbiddenType;				//限制人数标志
		int				nMinimum;						//最小值
		int				nMaximum;						//最大值

		ST_PolygonArea	stRegion;				//区域信息

	}ST_MultiLoiterRegionParam;

	typedef struct _PACKED_1_ tagMultiLoiterParam
	{
		bool		bIsGetDetail;//是否显示详细信息
		int			nMultiLoiterRegionParam;
		ST_MultiLoiterRegionParam stMultiLoiterRegionParamList[CONST_MAX_MULTILOITERPARAM];//分析区域列表//todo
		ST_IntelligeBaseParam		stIntelligeBaseParam;
	}ST_MultiLoiterParam;

	typedef struct _PACKED_1_ tagObjectLeftRegionParam
	{
		int 				nMinTargetSize;		// 物品最小尺寸(单位：平方厘米)
		int					nMaxTargetSize;		//物品最大尺寸(单位：平方厘米)
		int					nMinTime;			//物品遗留最短时间(单位：秒)

		ST_PolygonArea		stRegion;			//区域信息
	}ST_ObjectLeftRegionParam;

	typedef struct _PACKED_1_ tagObjectLeftParam
	{
		bool					 bIsGetDetail;//是否显示详细信息
		int						 nObjectLeftRegionParamNum;//分析区域个数
		ST_ObjectLeftRegionParam stObjectLeftRegionParamList[CONST_MAX_OBJECTLEFTREGIONPARAM];//分析区域列表
		ST_IntelligeBaseParam		stIntelligeBaseParam;
	}ST_ObjectLeftParam;

	typedef struct _PACKED_1_ tagObjectMovedRegionParam
	{
		int 						nMinTargetSize;	// 物品最小尺寸(单位：平方厘米)
		int							nMaxTargetSize;	// 物品最大尺寸(单位：平方厘米)
		int							nMinTime;			// 物品移走最短时间(单位：秒)

		ST_PolygonArea				stRegion;				//区域信息
	}ST_ObjectMovedRegionParam;

	typedef struct _PACKED_1_ tagObjectMovedParam
	{
		bool						bIsGetDetail;//是否显示详细信息
		int							nObjectMovedRegionParamNum;//分析区域个数
		ST_ObjectMovedRegionParam   stObjectMovedRegionParamList[CONST_MAX_OBJECTMOVEDREGIONPARAM];//分析区域列表
		ST_IntelligeBaseParam		stIntelligeBaseParam;
	}ST_ObjectMovedParam;

	typedef struct _PACKED_1_ tagAbnormalSpeedRegionParam
	{
		bool 			bTargetTypeConstrain;		// 是否限定目标类型(取值范围：0(否)，1(是))
		int				nTargetType;				// 类型限定模式(取值范围：0(人或车)，1(人)，2(车))
		bool			bTargetSizeConstrain;		// 是否限定目标尺寸(取值范围：0(否)，1(是))
		int				nMinTargetSize;				// 目标最小尺寸(单位：平方厘米)
		int				nMaxTargetSize;				// 目标最大尺寸(单位：平方厘米)

		int				nRateLimitingType;			// 限速标识（0：允许范围；1：禁止范围）
		int				nMinRate;				    // 最小运动速度(单位：米/秒)
		int				nMaxRate;				    // 最大运动速度(单位：米/秒)

		ST_PolygonArea	stRegion;					//区域信息
	}ST_AbnormalSpeedRegionParam;

	typedef struct _PACKED_1_ tagAbnormalSpeedParam
	{
		bool						bIsGetDetail;//是否显示详细信息
		int							nAbnormalSpeedRegionParamNum;//分析区域个数
		ST_AbnormalSpeedRegionParam stAbnormalSpeedRegionParamList[CONST_MAX_ABNORMALSPEEDREGIONPARAM];//分析区域列表
		ST_IntelligeBaseParam		stIntelligeBaseParam;
	}ST_AbnormalSpeedParam;

	typedef struct _PACKED_1_ tagConverseRegionParam
	{
		bool 			bTargetTypeConstrain;	// 是否限定目标类型(取值范围：0(否)，1(是))
		int				nTargetType;			// 类型限定模式(取值范围：0(人或车)，1(人)，2(车))
		bool			bTargetSizeConstrain;	// 是否限定目标尺寸(取值范围：0(否)，1(是))
		int				nMinTargetSize;			// 目标最小尺寸(单位：平方厘米)
		int				nMaxTargetSize;			// 目标最大尺寸(单位：平方厘米)

		float			fConverseAngle;			// 逆行方向角度(单位：度) 0～360 度

		ST_PolygonArea	stRegion;//区域信息
	}ST_ConverseRegionParam;

	typedef struct _PACKED_1_ tagConverseParam
	{
		bool					bIsGetDetail;//是否显示详细信息
		int						nConverseRegionParamNum;//分析区域个数
		ST_ConverseRegionParam  stConverseRegionParamList[CONST_MAX_CONVERSEREGIONPARAM];//分析区域列表
		ST_IntelligeBaseParam  stIntelligeBaseParam;

	}ST_ConverseParam;

	typedef struct _PACKED_1_ tagNoParkingRegionParam
	{
		int 			nMinTargetSize;	//!< 车辆最小尺寸(单位：平方厘米)
		int				nMaxTargetSize;	//!< 车辆最大尺寸(单位：平方厘米)
		int				nMinTime;			//!< 车辆停留最短时间(单位：秒)

		ST_PolygonArea	stRegion;				//区域信息
	}ST_NoParkingRegionParam;

	typedef struct _PACKED_1_ tagNoParkingParam
	{
		bool					bIsGetDetail;				//是否显示详细信息
		int						nNoParkingRegionParamNum;	//分析区域个数
		ST_NoParkingRegionParam stNoParkingRegionParamList[CONST_MAX_NOPARKINGREGIONPARAM];//分析区域列表 //TODO
		ST_IntelligeBaseParam  stIntelligeBaseParam;
	}ST_NoParkingParam;


	typedef struct _PACKED_1_ tagMotionDetectionParamV3
	{
		int					nSensitivity;	//	灵敏度
		bool				bIsGetDetail;//是否显示详细信息

		ST_DetectionAreaV2		stDetectionAreaV2;//区域信息
		
		ST_IntelligeBaseParam  stIntelligeBaseParam;
	}ST_MotionDetectionParamV3;

	typedef struct _PACKED_1_ tagCameraTamperParam
	{
		ST_IntelligeBaseParam  stIntelligeBaseParam;
		int 			nMinTime;  //	遮挡最小时间
	}ST_CameraTamperParam;



	typedef struct _PACKED_1_ tagSignalBadParam
	{
		ST_IntelligeBaseParam stIntelligeBaseParam;
		bool	bIsGetDetail;//是否显示详细信息
	}ST_SignalBadParam;


	typedef struct _PACKED_1_ tagPixelToRealSize
	{
		int				nRealSize;					//物体实际长度 单位厘米
		int				nSegmentLayType;	//线段方位(水平/ 垂直) 
		ST_LineCross	stLineCross;				//线段参数
	}ST_PixelToRealSize;

	typedef struct _PACKED_1_ tagAdvancedParam
	{
		int			nScene;					//室内/室外
		int			nHight;					//安装高度hight
		float		fAngle;					//安装角度,相对于竖直向下
		float		fFOV;					//镜头视场角

		int			nCameraShake;				//摄像机抖动（0：关闭 1：打开）
		int			nHighNoise;				//高噪声环境（0: 关闭 1：打开）
		int			nLowContrast;				//低对比度（0:关闭 1：打开）
		int			nPeriodMotion;			//周期运动背景（0:关闭 1：打开)
		int			nPeriodMotionTime;		//周期运动背景时间(秒)

		int			nPixelToRealSizeNum;	//摄像机像素与实体物体长度的转换个数	

		ST_PixelToRealSize stPixelToRealSizeList[CONST_MAX_PIXELTOREALSIZE];//摄像机像素与实体物体长度的转换  TODO
	}ST_AdvancedParam;



	typedef struct  _PACKED_1_ tagCameraMovedParam
	{
		ST_IntelligeBaseParam  stIntelligeBaseParam;
	}ST_CameraMovedParam;


	//FisheyeDewarpMode设置
	typedef struct _PACKED_1_ tagFisheyeDewarpModeParam
	{
		int nCameraId;			//通道号
		int nFisheyeVideoMode;	//鱼眼视频模式,具体定义可查看FisheyeConst.h中FISHEYE_VIDEO_MODE枚举定义
		int nDewarpMode;			//矫正模式,具体定义可查看FisheyeConst.h中FISHEYE_DEWARP_MODE枚举定义
	}ST_FisheyeDewarpModeParam;

	typedef struct _PACKED_1_  tagVideoRect
	{
		int			nId;			//0永远是鱼眼或者全景视频，其它为ptz
		double		nStartX;		//百分比（0~1）x100，精度为小数点后2位
		double		nStartY;		//百分比（0~1）x100，精度为小数点后2位
		double		nWidth;			//百分比（0~1）x100，精度为小数点后2位
		double		nHeight;		//百分比（0~1）x100，精度为小数点后2位
	}ST_VideoRect;

	typedef struct _PACKED_1_ tagFisheyeVideoLayout
	{
		int		nCameraId;										//通道号
		int		nVideoRectNum;									//显示区域个数
		ST_VideoRect stVideoRect[CONST_MAX_FISHEYEVIDEOLAYOUT]; //鱼眼、全景或PTZ显示区域
	}ST_FisheyeVideoLayout;

	typedef struct _PACKED_1_ tagFisheyeMountParam
	{
		int nFisheyeMountType;		//安装模式
	}ST_FisheyeMountParam;


	typedef struct _PACKED_1_ tagFisheyeDewarpMode
	{
		int		nDewarpMode;	//矫正模式,具体定义可查看FisheyeConst.h中FISHEYE_DEWARP_MODE枚举定义
		bool	bMoveable;		//是否可移动标识
	}ST_FisheyeDewarpMode;

	typedef struct _PACKED_1_ tagFisheyeVideoAbility
	{
		int nFisheyeVideoMode;										//鱼眼视频模式,具体定义可查看FisheyeConst.h中FISHEYE_VIDEO_MODE枚举定义
		int nDewarpModeNum;
		ST_FisheyeDewarpMode stDewarpModeList[CONST_MAX_DEWARPMODE]; //鱼眼纠正模式

	}ST_FisheyeVideoAbility;

	typedef struct _PACKED_1_ tagFisheyeAbility
	{
		bool	bFisheyeSupportFlag;									//鱼眼功能支持标识

		int		nFisheyeMountTypeNum;
		int		nFisheyeMountTypeList[CONST_MAX_FISHEYEMOUNTTYPE]; //安装模式，具体定义可查看FisheyeConst.h中FISHEYE_MOUNT_TYPE枚举定义

		int		nFisheyeVideoAbilityNum;
		ST_FisheyeVideoAbility stFisheyeVideoAbility[CONST_MAX_FISHEYEVIDEOABILITY]; //鱼眼视频能力
	}ST_FisheyeAbility;

	typedef struct _PACKED_1_ tagAreaParamV2
	{
		double	dTopX;								//区域左上角 x 的坐标占总视频区宽度的百分比
		double	dTopY;								//区域左上角 y 的坐标占总视频区高度的百分比
		double	dWidth;								//区域宽度占视频区总宽度的百分比
		double	dHeight;								//区域高度占总视频区高度的百分比
	}ST_AreaParamV2;

	typedef struct _PACKED_1_ tagBlindAreaParamV2
	{
		int						nAreaId;					//移动区域ID
		bool					bEnableFlag;				//是否启用遮蔽（true：启用，false：不启用）
		ST_ColorParam			stColorParam;				//区域颜色，此参数预留

		ST_AreaParamV2			stAreaParamV2;				//移动区域
		char					szAreaName[CONST_MAX_AREANAME + 1];		//设备名称
		int						nMirrorValue;				//镜像类型
	}ST_BlindAreaParamV2;

	typedef struct _PACKED_1_ tagAllBlindAreaParamV2
	{
		int			nBlindAreaParamV2Num;
		ST_BlindAreaParamV2 stBlindAreaParamV2[CONST_MAX_BLINDAREAPARAMV2NUM]; 
	}ST_AllBlindAreaParamV2;

	typedef struct _PACKED_1_ tagExternComInfo
	{
		char				szExternComType[CONST_MAX_EXTERNCOMTYPE];
		int					nExternComIDNum;
		int					stExternComIDList[CONST_MAX_EXTERNCOMID];
	}ST_ExternComInfo;

	typedef struct _PACKED_1_ tagExternDeviceAbility
	{
		int						    nExternComInfoNum;
		ST_ExternComInfo			stExternComInfoList[CONST_MAX_EXTERNCOMINFO];

		int							nBaudRateNum;
		int							szBaudRateList[CONST_MAX_BAUDRATE];

		int							nDataBitsNum;
		int							szDataBitsList[CONST_MAX_DATABITS];

		int							nStopBitsNum;
		char						szStopBitsList[CONST_MAX_STOPBITS];
	
		int							nParityNum;
		char						szParityList[CONST_MAX_PARITY];
	}ST_ExternDeviceAbility;

	typedef struct _PACKED_1_ tagAlarmIOMode
	{ 
		int nAlarmIOModeID;  //开关力状态 1:开关量模式   2:高低电平模式
	}ST_AlarmIOMode;

}

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
 #endif
/**********************************************************************/
//#pragma pack(push, 1)

#endif
