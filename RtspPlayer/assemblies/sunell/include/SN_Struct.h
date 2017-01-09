
#ifndef _SN_STURCT_C_
#define _SN_STURCT_C_

#include "DomainConst.h"
#include "SNPlatOS.h"

//#pragma pack(push, 1)
/**********************************************************************/
//�˴����ڿ����ļ������ֽڶ��룬����ʱ����ע�ͼ�������һ�𿽱���
//�������ġ�#ifdef PRAGMA_PACK������ҲҪһ�𿽱�������pragma pack��ջ��ջ��ƥ��
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
	const int  CONST_MAX_RS484_NUM = 16;							//��������RS485����
	const int  CONST_MAX_PERIOD_SCHEDULE_RECORD_TIME_NUM = 3;		//��������ƻ�¼���趨�ĵ���ʱ�����
	const int  CONST_MAX_ALARM_OUT_NUM = 16;						//�������󱨾����ͨ������	
	const int  CONST_MAX_ALARM_IN_NUM = 16;							//�������󱨾�����ͨ������
	const int  CONST_MAX_CAMERA_NUM = 16;							//������������ͷ��Ŀ
	const int  CONST_MAX_NVR_DEVICE_NUM = 64;						//���������豸��Ŀ

	const int  CONST_MAX_PTZ_PRESET_NUM = 255;						//����������̨Ԥ�õ���Ŀ
	const int  CONST_MAX_PTZ_TOURPOINT_NUM =12;						//����������̨Ѳ����Ŀ
	const int  CONST_MAX_PTZ_TRACK_NUM =6;							//����������̨�켣��Ŀ
	const int  CONST_MAX_PTZ_SCAN_NUM =12;							//����������̨ɨ����Ŀ

	const int  CONST_MAX_DETECTION_NUM = 8;							//�����������������
	const int  CONST_MAX_DISK_NUM = 16;								//����������̸���
	const int  CONST_MAX_OSDINFO_NUM = 16;							//��������OSD����
	const int  CONST_MAX_OSD_FONT_TYPE_NUM = 16;					//�����OSD������Ŀ

	const int  CONST_MAX_PTZ_PROTOCOL_NUM = 8;						//����������̨Э����
	const int  CONST_MAX_DEVICE_TYPE_NUM = 8;						//����������豸������
	const int  CONST_MAX_BITRATE_TYPE_NUM = 8;						//�������������������Ŀ
	const int  CONST_MAX_DEVICE_IMAGE_FORMAT_NUM = 8;				//������豸֧�ֵ�ͼ���ʽ�����Ŀ
	const int  CONST_MAX_DDNS_PROVIDER_NUM = 8;						//���������DDNS�ṩ����Ŀ
	const int  CONST_MAX_ALARM_TYPE_NUM = 8;						//��������ı���������Ŀ
	const int  CONST_MAX_VIDEO_SYSTEM_NUM = 8;						//�����������Ƶ��ʽ����
	const int  CONST_MAX_FRAME_LENGTH = 1600*1200;					//һ֡���ݵ����ֵ
	const int  CONST_MAX_ALARM_ACTION_STRATEGY = 5;					//������Ϊ����������
	const int  CONST_MAX_STREAM_NUM = 4*16;							//������豸�������Ŀ
	const int  CONST_MAX_ALARM_EVENT_NUM = 36;						//�������󱨾��¼���
	
	const int  CONST_MAX_AREA_NUM = 3;								//��������������

	const int  CONST_MAX_FILE_SYSTEM_NUM = 6;						//���������ļ�ϵͳ��Ŀ
	const int  CONST_MAX_DEVICE_VIDEO_ENCODER_NUM = 4;				//����������Ƶ������������Ŀ
	const int  CONST_MAX_AUDIO_TYPE_NUM = 16;						//����������Ƶ����������
	const int  CONST_MAX_AUDIO_ENCODE_TYPE_NUM = 16;				//����������Ƶ����������
	const int  CONST_MAX_AUDIO_DECODE_TYPE_NUM = 16;				//����������Ƶ����������
	const int  CONST_MAX_SOURCE_RESOLUTION_NUM = 4;					//��������Դ�ֱ���������Ŀ
	const int  CONST_MAX_CAMERA_STREAM_NUM = 6;						//���������ͷ�������Ŀ
	const int  CONST_MAX_DISK_TYPE_NUM = 6;							//�����������������Ŀ

	const int  CONST_MAX_RETAIN_TYPE = 64;							//�������������

	const int  CONST_MAX_MONITOR_TYPE_NUM = 12;						//�������������
	const int  CONST_MAX_LAYOUT_MODEL_NUM = 16;						//layoutģʽ�����
	const int  CONST_MAX_LAYOUT_DECODING_ABILITY_NUM = 16;			//���ֽ������������
	const int  CONST_MAX_SUB_WIN_DECODING_ABILITY_NUM = 6;			//�Ӵ��ڽ������������
	const int  CONST_MAX_SUB_WIN_NUM = 64;							//�Ӵ��������
	const int  CONST_MAX_NVR_FILE_SYSTEM_NUM = 16;					//�ļ�ϵͳ�����
	const int  CONST_MAX_DISK_ATTRIBUTE_NUM = 12;					//�������������
	const int  CONST_MAX_ATTRIBUTE_NAME_NUM = 256;					//���������������ֵ
	const int  CONST_MAX_NETWORK_CARD_NUM = 4;						//�����������ֵ
	const int  CONST_MAX_NETWORKING_MODE_NUM = 4;					//��������ģʽ���ֵ



	const int  CONST_MAX_AV_STREAM_NUM = 8;							//������豸�������Ŀ
	const int  CONST_MAX_LAYOUT_NAME = 64;							//Layout���Ƴ���
	const int  CONST_MAX_LAYOUIT_WINDOW_NUM = 64;					//Layout���������
	const int  CONST_MAX_LIVE_VIDEO_CHANNEL_NUM = 16;				//ʵʱ��Ƶͨ����
	const int  CONST_MAX_LIVE_VIDEO_LAYOUT_NUM = 16;				//ʵʱ��Ƶ���������
	const int  CONST_MAX_DEVICE_AV_STREAM_PARAM_NUM = 128;			//�豸�����������
	const int  CONST_MAX_RECORD_STATE_NUM = 128;					//¼��״̬�����
	const int  CONST_MAX_MONITOR_NUM = 8;							//�����������

	const int  CONST_MAX_WIFIHOTSPOTPARAM_NUM = 10;					//wifi �ȵ������
	const int  CONST_MAX_OSD_TIME_FORMAT_TYPE_NUM = 20;             //OSD ʱ���ʽ���������
	const int  CONST_MAX_PTZ_TIME_RTIMESEGMENT_NUM = 10;

	const int CONST_MAX_BLINDABILITYV2_TYPE	= 10;					//��˽�ڱ�����֧��������
	const int CONST_MAX_BLINDABILITYV2_ALPHA =101;					//��˽�ڱ�͸����֧����������0-100��
	const int CONST_MAX_BLINDABILITYV2_RGBCOLOR = 20;				//��˽�ڱ���ɫ֧���������������RGBColor����ɫ����Ϊ-1����֧��������ɫ��
	const int CONST_MAX_BLINDABILITYV2_MOSAICPARAM = 10;             //��˽�ڱ�������֧��������


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

	//��������
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


	//Ip����Э��
	enum ENUM_TransferProtocol
	{
		UDP = 0X01,			//UDPЭ��
		TCP = 0X02,			//TCPЭ��
		RTP = 0X04			//RTPЭ��
	};

	//IpЭ��汾
	enum ENUM_IPProtoVer	
	{
		IPPROTO_V4  = 1,	//IPv4Э��

		IPPROTO_V6  = 2		//IPv6Э��
	};

	//�豸����
	enum ENUM_DeviceType	
	{
		IPCAMERA	= 1,	//IP Camera
		DVR			= 2,	//DVR
		DVS			= 3,	//DVS
		IPDOME		= 4,	//IP Dome
		NVR			= 5		//NVR
	};

	//ˮӡ����
	enum ENUM_OSDType
	{
		OSDTYPE_DEVICENAME	= 1,	//�豸��
		OSDTYPE_CAMERAID	= 2,	//�������
		OSDTYPE_CAMERANAME	= 3,	//�������
		OSDTYPE_TIME		= 4,	//ʱ��ˮӡ
		OSDTYPE_TEXT		= 5		//����ˮӡ
	};

	//ͼ���ʽ����
	enum ENUM_ImageFormat
	{
		IMAGEFORMAT_D1					= 1,	//PAL 704*576,25frame�� NTSC 704*480 30framre
		IMAGEFORMAT_LOW_BITRATE_D1		= 2,	//PAL 704*576 12.5frame��NTSC 704*480 15framre
		IMAGEFORMAT_CIF					= 4,	//PAL 352*288 25frame��NTSC 352*240 30framre
		IMAGEFORMAT_QCIF				= 5,	//PAL 176*144 25frame��NTSC 240*160 30framre
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

	//����������
	enum ENUM_BitRateType
	{
		CBR_TYPE = 1,					//�̶�����

		VBR_TYPE = 2					//���̶�����
	};

	//¼��״̬
	enum ENUM_RecordStatus
	{
		RECORDSTATUS_NO_RECORD	= 0,	//��¼��
		RECORDSTATUS_RECORD		= 1		//��¼��
	};

	//�ź�״̬
	enum ENUM_SignalStatus
	{
		SIGNALSTATUS_HAS_SIGNAL	  = 0,	//�ź�����
		SIGNALSTATUS_LOSS_SIGNAL  = 1	//�źŶ�ʧ
	};

	//Ӳ��״̬
	enum ENUM_HardwareStatus
	{
		HARDWARESTATUS_NORMAL	  = 0,	//Ӳ������
		HARDWARESTATUS_ABNORMAL	  = 1	//Ӳ������
	};

	//����״̬
	enum ENUM_DiskStatus
	{
		DISKSTATUS_DORMANCY		  = 1,	//����״̬
		DISKSTATUS_ABNORMAL		  = 2,	//������״̬
		DISKSTATUS_NOT_EXISTENT	  = 3,	//���̲�����
		DISKSTATUS_WRITE_PROTECT  = 4,	//����д����	
		DISKSTATUS_NOT_FORMAT	  = 5,	//����δ��ʽ��
		DISKSTATUS_FORMATTING	  = 6	//�������ڸ�ʽ��
	};

	//��˷�����
	enum ENUM_ToneArmType
	{
		TONEARM_TYPE_INTERNAL				= 1,	//����
		TONEARM_TYPE_EXTERNAL				= 2,	//����
		TONEARM_TYPE_LINEIN					= 3,	//������
		TONEARM_TYPE_DIFF_LINEIN			= 4,	//���������
		TONEARM_TYPE_DOUBLE_LINEIN			= 5		//˫����
	};

	//����������
	enum ENUM_LoudhailerType
	{
		LOUDHAILER_TYPE_IN		  = 1,	//����
		LOUDHAILER_TYPE_OUT		  = 2	//����
	};

	//485��������
	enum ENUM_FlowControl
	{
		FLOWCONTROL_NONE		  = 0,	//��
		FLOWCONTROL_SOFT		  = 1,	//������
		FLOWCONTROL_HARD		  = 2	//Ӳ����
	};

	//��żУ��
	enum ENUM_COMParity
	{
		COM_PARITY_NONE				= 0,	//None����У��
		COM_PARITY_ODD				= 1,	//Odd����У��
		COM_PARITY_EVEN				= 2,	//Even��żУ��
		COM_PARITY_MARK				= 3,	//Mark�����У��
		COM_PARITY_SPACE			= 4		//Space���ո�У��
	};

	//ֹͣλ
	enum ENUM_StopBits
	{
		STOPBITS_ONE				= 0,	//1
		STOPBITS_ONEHALF			= 1,	//1.5
		STOPBITS_TWO				= 2		//2
	};


	//������Ч�ź�
	enum ENUM_AlarmValidSignal
	{
		ALARM_VALID_SIGNAL_CLOSE  = 0,	//�̵����պ�
		ALARM_VALID_SIGNAL_OPEN	  = 1	//�̵����Ͽ�
	};

	//����ģʽ
	enum ENUM_AlarmMode
	{
		ALARMMODE_SWITCH		  = 1,	//����ģʽ
		ALARMMODE_MULTIPLE		  = 2	//����ģʽ
	};

	//����������
	enum ENUM_AdapterType
	{
		ADAPTER_TYPE_LOCAL		  = 1,	//��������
		ADAPTER_TYPE_PPPOE		  = 2	//PPPoE����
	};

	//DDNS�����ṩ��ID
	enum ENUM_ProviderId
	{
		PROVIDERID_3322			  = 1,	//3322.org
		PROVIDERID_DYNDNS		  = 2	//dyndns
	};

	//�洢����
	enum ENUM_StoragePolicy
	{
		STORAGE_POLICY_CYCLE	 = 1,	//ѭ���洢
		STORAGE_POLICY_FULLSTOP  = 2	//������ֹͣ
	};

	//¼�Ʒ�ʽ
	enum ENUM_RecordMode
	{
		RECORD_MODE_SIZE = 1,		  //���ļ���С¼��
		RECORD_MODE_TIME = 2		  //��ʱ�䳤��¼��
	};

	//¼���ʽ����
	enum ENUM_RecordFormatType	
	{
		RECORD_FORMAT_MPEG2_PS	= 1,			//PS��ʽ
		RECORD_FORMAT_CUSTOM	= 2,			//�Զ����ʽ
		RECORD_FORMAT_MPEG2_TS	= 3				//TS��ʽ
	};

	//¼�����
	enum ENUM_RuleType
	{
		RECORD_RULE_TYPE_ALWAYS = 1,			//����¼��
		RECORD_RULE_TYPE_SCHEDULE = 2			//�ƻ�¼��
	};

	//���������־
	enum ENUM_AlarmOutFlag
	{
		ALARMOUTFLAG_START		= 1,			//������Ч��־λ����ʼ����
		ALARMOUTFLAG_STOP		= 0				//������Ч��־λ��ֹͣ����
	};

	//�������״̬
	enum ENUM_AlarmOutStatus
	{
		ALARMOUT_NO_ALARMOUT	= 0,			//�ޱ������
		ALARMOUT_ALARMOUT		= 1				//�б������
	};

	//��������
	enum ENUM_AlarmType
	{
		TYPE_ALARMIO					= 1,	//I/O����
		TYPE_MOTIONDETECT				= 2,	//�˶���ⱨ��
		TYPE_CAMERAMASK					= 3,	//����ͷ�ڵ�����
		TYPE_VIDEO_LOST					= 5,	//��Ƶ��ʧ����
		TYPE_DISK_ERROR					= 6,	//���̶�д�쳣
		TYPE_DISK_CONNECT_FAILED		= 7,	//�����������ʧ��
		TYPE_DISK_FULL					= 8,	//������
		TYPE_DISK_NOT_EXISTENT			= 9,	//���̲�����
		TYPE_DISK_THRESHOLD_ALARM		= 10,	//�������ÿռ�ﵽָ����ֵ 
		TYPE_DISK_NOT_FORMAT			= 11,	//����δ��ʽ��
		TYPE_RECORD_STORAGE_FAILED		= 15    //¼��洢ʧ��
	};

	//��չ����������
	enum  ENUM_AlarmMajorType
	{
		SECURITY_ALARM						= 1, //��ȫ����
		DISK_ALARM							= 4, //���̱���
		RECORD_ALARM						= 5  //¼�񱨾���
	};

	//��չ��ȫ����������
	enum  ENUM_SecurityAlarmMinorType
	{
		SECURITYALARM_MINOR_TYPE_ALARMIO		= 1,	//I/O����
		SECURITYALARM_MINOR_TYPE_MOTIONDETECT	= 2,	//�˶���ⱨ��
		SECURITYALARM_MINOR_TYPE_CAMERAMASK		= 3,	//����ͷ�ڵ�����
		SECURITYALARM_MINOR_TYPE_VIDEO_LOST		= 4		//��Ƶ��ʧ����
	};

	//��չ���̱���������
	enum  ENUM_DiskAlarmMinorType
	{
		DISKALARM_MINOR_TYPE_DISK_OK			= 1,	//����״̬����
		DISKALARM_MINOR_TYPE_DISK_ERROR			= 2,	//���̶�д�쳣
		DISKALARM_MINOR_TYPE_CONNECT_FAILED		= 3,	//�����������ʧ��
		DISKALARM_MINOR_TYPE_DISK_FULL			= 4,	//������
		DISKALARM_MINOR_TYPE_NOT_EXISTENT		= 5,	//���̲�����
		DISKALARM_MINOR_TYPE_THRESHOLD_ALARM	= 6,	//�������ÿռ�ﵽָ����ֵ 
		DISKALARM_MINOR_TYPE_NOT_FORMAT			= 7,	//����δ��ʽ��
		DISKALARM_MINOR_TYPE_DEVICE_NOSPACE		= 8		//�豸�洢�ռ䲻��
	};

	//��չ¼�񱨾�������
	enum ENUM_RecordAlarmMinorType
	{
		RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_SUCCESS			= 1,		//����Դ���ӳɹ�
		RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_LOGIN_ERROR		= 2,		//����Դ�����û����������
		RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_NO_PRIVILEGE		= 3,		//����Դ����û��Ȩ��
		RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_MAX_CONNECTION	= 4,		//����Դ���Ӵﵽ���������
		RECORDSOURCE_MINOR_TYPE_AVDATA_MAX_SPEED				= 5,		//����Դ�ﵽ�����������
		RECORDSOURCE_MINOR_TYPE_LOGIN_USER_REPEATED				= 6,
		RECORDSOURCE_MINOR_TYPE_NOT_SUPPORT_VIDEO				= 7,
		RECORDSOURCE_MINOR_TYPE_CREATE_VIDEO_SESSION_FAILED		= 8,
		RECORDSTORAGE_MINOR_TYPE_STORAGE_FAILED					= 9
	};

	enum  ENUM_AlarmFlag
	{
		ALARM_FLAG_STOP = 0,						//����ֹͣ
		ALARM_FLAG_START = 1						//������ʼ
	};

	//ͼƬ��ʽ
	enum ENUM_PhotoFormat
	{
		PHOTOFORMAT_JPEG	    = 1,			//jpge��ʽ

		PHOTOFORMAT_BMP			= 2				//bmp��ʽ
	};

	//ץ��״̬
	enum ENUM_PhoteSnapShotFlag
	{
		PHOTESNAPSHOT_FLAG_NO		= 0,		//û����ץ��
		PHOTESNAPSHOT_FLAG			= 1			//����ץ��
	};

	//��ѯ��ʽ
	enum ENUM_RecordFileSelectMode
	{
		SELECT_MODE_ALL		= 0,				//��ѯ����
		SELECT_MODE_TYPE	= 1,				//�����Ͳ�ѯ
		SELECT_MODE_TIME 	= 2					//��ʱ���ѯ
	};

	//��Ƶ��ʽ
	enum ENUM_VideoSystem
	{
		NTSC	= 0,	//PAL��ʽ
		PAL		= 1,	//NTFS��ʽ
		NA		= 2		//
	};

	//¼������
	enum ENUM_RecordType
	{
		RECORD_TYPE_ALWAYS		= 1,	//����¼��
		RECORD_TYPE_SCHEDULE	= 2,	//�ƻ�¼��
		RECORD_TYPE_ALARM		= 3		//����¼��
	};

	//��ģʽ
	enum ENUM_OpenMode
	{
		OPENMODE_SHARE		= 0,		//����ģʽ��
		OPENMODE_EXCLUSIVE	= 1			//��ռģʽ��
	};

	//����״̬
	enum ENUM_PlayStatus
	{
		PLAY_STATUS_STOP = 1,       //ֹͣ
		PLAY_STATUS_PAUSE = 2,		//��ͣ
		PLAY_STATUS_PLAY = 3,		//����
		PLAY_STATUS_FASTPLAY = 4,	//���
		PLAY_STATUS_SLOWPLAY = 5,	//����
		PLAY_STATUS_FRAME_PLAY = 6, //֡��
		PLAY_STATUS_FRAME_BACK = 7  //֡��

	} ;

	//PTZЭ��
	enum  ENUM_PTZProtocol
	{
		PROTOCOL_PELCO_D = 0,		//PELCO_DЭ��
		PROTOCOL_PELCO_P = 1		//PELCO_PЭ��
	};

	//¼��״̬
	enum ENUM_LiveRecordStatus
	{
		RECORD_RUNNING = 1,			//����¼��
		RECORD_STOP	   = 2			//ֹͣ¼��
	};

	//�����ʽ
	enum ENUM_EncoderType
	{
		MPEG4		= 0,			//MPEG4����
		H264		= 1,			//H264����
		MJPEG		= 2,			//MJPEG����
		SVC			= 3,			//SVC����
		H264_MAIN	= 4,			//H264 main profile
		H264_HIGH	= 5,			//H264 high profile
		G7231		= 101,			//G7231����
		G711_ALAW	= 102,			//G711A�ɱ���
		G711_ULAW	= 103,			//G711U�ɱ���
		G722		= 104,			//G722����
		G726		= 105,			//G726����
		G729		= 106,			//G729����
		AMR			= 107,			//AMR����
		RAW_PCM		= 108,			//PCM���룬��������
		UNKNOWN		= 0xFF			//δ֪����

	};

	//����ʽ
	enum ENUM_StreamFormat
	{
		ES_STREAM			=   1,		//ԭʼ��	
		TS_STREAM			=   2,		//TS�����
		ES_ENCRYPT_STREAM1	=   3,		//ԭʼ��������ͬ�������㷨
		PS_STREAM			=   4		//PS�����
	};

	//�ļ���ʽ
	enum ENUM_FileFormat
	{
		FILE_FORMAT_TS		= 1,	//¼���ļ�ΪMpeg2TS��ʽ
		FILE_FORMAT_SUNELL  = 2,	//¼���ļ�ΪSunell��ʽ
		FILE_FORMAT_AVI		= 3,	//¼�Ƶ��ļ���ʽΪAVI��ʽ
		FILE_FORMAT_PS		= 4		//¼�Ƶ��ļ���ʽΪMpeg2PS����ʽ
	};

	enum ENUM_ESStreamType
	{
		VIDEO			=  1,		//��Ƶ��
		AUDIO			=  2		//��Ƶ��
	};

	//֡����
	enum ENUM_FrameType
	{
		UnknownFrame	=	0, //δ֪֡����
		IFrame			=	1, //I֡
		PFrame			=	2, //P֡
		BFrame			=	3  //B֡
	};

	//��������
	enum ENUM_DiskType
	{
		DISKTYPE_HARDDISK			= 1, //����Ӳ��
		DISKTYPE_SDCARD				= 2, //SD��
		DISKTYPE_FTP				= 3, //FTP
		DISKTYPE_NAS				= 4,  //NAS
		DISKTYPE_EXTERN_DISK		= 5  //����豸
	};

	//PTZ��������
	enum ENUM_PTZ_Keeper_Type
	{
		PTZ_KEEPER_TYPE_PRESET		= 1,	//Ԥ��λ
		PTZ_KEEPER_TYPE_SCAN		= 2,	//ɨ��
		PTZ_KEEPER_TYPE_AUTO_STUDY	= 3,	//��ѧϰ
		PTZ_KEEPER_TYPE_TOUR		= 4		//Ѳ��
	};

	//RTSP����Э��
	enum RtspTransferProtocol
	{
		RTP_UDP		= 0x1,		//UDP
		RTSP_TUNNEL = 0x2,		//RTSP���
		HTTP_TUNNEL = 0x3		//HTTP���
	};

	enum DrawVideoMode
	{
		DRAW_VIDEO_MODE_DDRAW	= 1,//DirectDraw
		DRAW_VIDEO_MODE_D2D		= 2 //D2D
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////////

	//ʱ�����
	typedef struct _PACKED_1_ tagTimeStruct
	{
		int				nTimeZone;				//ʱ��
		unsigned short	nDaylightSavingTime;	//����Ӫʱ
		unsigned short	nYear;					//��
		unsigned short 	nMonth;					//��[0,11]
		unsigned short 	nDay;					//��[1,31]
		unsigned short 	nDayOfWeek;				//���ڼ�[0,6]
		unsigned short 	nHour;					//ʱ[0,24]
		unsigned short 	nMinute;				//��[0,60]
		unsigned short 	nSecond;				//��[0,60]
		int 			nMilliseconds;			//΢��[0,1000000]
	}ST_TimeStruct;


	//IP��ַ
	typedef struct _PACKED_1_ tagInetAddr
	{
		char			szHostIP[CONST_MAXLENGTH_IP + 1];		//IP��ַ����ַ���ʽ��

		unsigned short	nPORT;									//�˿ں�

		long			nIPProtoVer;							//IPЭ��汾��1��IPv4Э�飬2��IPv6Э�飩

	}ST_InetAddr;

	//�豸��Ϣ
	typedef struct _PACKED_1_ tagDeviceInfo
	{
		ST_InetAddr		stInetAddr;											//�豸�������ַ

		char			szUserID[CONST_MAXLENGTH_USERID + 1];				//��½�豸���û�ID

		char			szPassword[CONST_MAXLENGTH_PASSWORD + 1];			//��½�豸������

		char			szDeviceID[CONST_MAXLENGTH_DEVICEID + 1];			//�豸ID

		char			szDeviceName[CONST_MAXLENGTH_DEVICENAME + 1];		//�豸����

		long			nDeviceType;										//�豸����

	}ST_DeviceInfo;

	//�豸��Ϣ
	typedef struct _PACKED_1_ tagDeviceInfoEx
	{
		ST_InetAddr		stInetAddr;											//�豸�������ַ

		char			szUserID[CONST_MAXLENGTH_USERID + 1];				//��½�豸���û�ID

		char			szPassword[CONST_MAXLENGTH_PASSWORD + 1];			//��½�豸������

		char			szDeviceID[CONST_MAXLENGTH_DEVICEID + 1];			//�豸ID

		char			szDeviceName[CONST_MAXLENGTH_DEVICENAME + 1];		//�豸����

		long			nDeviceType;										//�豸����

		unsigned char	m_bRouterMappingEnableFlag;							//·����ӳ���־
		char			m_szRouterAddr[CONST_MAXLENGTH_IP + 1];				//·������ַ��IP��ַ������
		unsigned short	m_nRouterMappingControlPort;						//����ӳ��˿�
		unsigned short	m_nRouterMappingTCPAVPort;							//TCP����Ƶӳ��˿�
		unsigned short	m_nRouterMappingRTSPPort;							//RTSPӳ��˿�
		unsigned short	m_nRouterMappingRTPPort;							//RTPӳ��˿�
		unsigned short	m_nRouterMappingRTCPPort;							//RTCPӳ��˿�

	}ST_DeviceInfoEx;

	//��̨Э��
	typedef struct _PACKED_1_ tagPTZProtocol
	{
		long	nProtocolId;													//��̨Э���ID��

		char	szProtocolName[CONST_MAXLENTH_PTZ_PROTOCOL_NAME + 1];			//��̨Э�������

	}ST_PTZProtocol;

	//�豸����
	typedef struct _PACKED_1_ tagDeviceType
	{
		long		nDeviceTypeId;										//�豸����id

		char		szDeviceTypeName[CONST_MAXLENGTH_DEVICETYPE_NAME];	//�豸��������

	}ST_DeviceType;

	//����������
	typedef struct _PACKED_1_ tagBitrateType
	{
		long		nBitrateTypeId;												//����������id

		char		szBitrateTypeName[CONST_MAXLENGTH_BITRATETYPE_NAME + 1];	//��������������

	}ST_BitrateType;

	//�����ṩ��
	typedef struct _PACKED_1_ tagDDNSProvider
	{
		long		nProviderId;											//�ṩ��id

		char		szProviderName[CONST_MAXLENGTH_DDNS_PROVIDER + 1];		//�ṩ������

	}ST_DDNSProvider;

	//��������
	typedef struct _PACKED_1_ tagAlarmType
	{
		long		nAlarmTypeId;												//��������id

		char		szAlarmTypeName[CONST_MAXLENGTH_ALARM_TYPE_NAME + 1];		//������������
	}ST_AlarmType;

	//ͼ���ʽ
	typedef struct _PACKED_1_ tagImageFormat
	{
		long		nImageFormatId;												//ͼ���ʽid

		char		szImageFormatName[CONST_MAXLENGTH_IMAGEFORMAT_NAME + 1];	//ͼ���ʽ����

	}ST_ImageFormat;

	//��Ƶ��ʽ
	typedef struct _PACKED_1_ tagVideoSystem
	{
		long		nVideoSystemId;												//��Ƶ��ʽid

		char		szVideoSystemName[CONST_MAXLENGTH_VIDEOSYSTEM_NAME + 1];	//��Ƶ��ʽ����

	}ST_VideoSystem;

	//����ͷ��Ƶ��ʽ
	typedef struct _PACKED_1_ tagCameraVideoSystem
	{
		long			nCameraId;				//����ͷid

		ST_VideoSystem	stWebVideoSystem;		//��Ƶ��ʽ

	}ST_CameraVideoSystem;

	//�豸����ͷ��Ƶ��ʽ
	typedef struct _PACKED_1_ tagDeviceVideoSystem
	{
		long						nCameraNum;										//����ͷ����

		ST_CameraVideoSystem		stWebCameraVideoSystem[CONST_MAX_CAMERA_NUM];	//����ͷ��ʽ�б�

	}ST_DeviceVideoSystem;

	//�ֵ�����ݽṹ
	typedef struct _PACKED_1_ tagDictionaryService
	{
		long					nWebPTZProtocolNum;		  	
		ST_PTZProtocol			stWebPTZProtocol[CONST_MAX_PTZ_PROTOCOL_NUM];			//��̨Э��

		long					nWebDeviceTypeNum;
		ST_DeviceType			stWebDeviceType[CONST_MAX_DEVICE_TYPE_NUM];				//�豸����

		long					nWebBitrateTypeNum;
		ST_BitrateType			stWebBitrateType[CONST_MAX_BITRATE_TYPE_NUM];			//����������

		long					nWebDDNSProviderNum;							
		ST_DDNSProvider			stWebDDNSProvider[CONST_MAX_DDNS_PROVIDER_NUM];			//�����ṩ��

		long					nWebAlarmTypeNum;
		ST_AlarmType			stWebAlarmType[CONST_MAX_ALARM_TYPE_NUM];				//��������

		long					nWebImageFormatNum;
		ST_ImageFormat			stWebImageFormat[CONST_MAX_DEVICE_IMAGE_FORMAT_NUM];    //�ֱ�������

		long					nWebVideoSystemNum;
		ST_VideoSystem			stWebVideoSystem[CONST_MAX_VIDEO_SYSTEM_NUM];			//��Ƶ��ʽ

	}ST_DictionaryService;

	//��������������Ϣ
	typedef struct _PACKED_1_ tagEncoderAbility
	{
		long nImageFormatId;								//��Ƶ��ʽ
		long nMaxFrameRate;									//�������
		long nMinFrameRate;									//��С����
		long nMaxBitRate;									//��������
		long nMinBitRate;									//��С������
		long nMaxQuality;									//�����Ƶ����ֵ
		long nMinQuality;									//��С��Ƶ����ֵ
		long nBitRateTypeNum;								//����·������Ŀ
		long nBitRateTypeList[CONST_MAX_BITRATE_TYPE_NUM];	//�����������б�

		long nVideoSystem;									//��ʽ
		long nHeight;										//�߶�
		long nWidth;											//���
		long nEncoderType;									//�������͡�����ɲ鿴ENUM_EncoderTypeö�ٶ���

	}ST_EncoderAbility;

	//�������
	typedef struct _PACKED_1_ tagMotionDetectionAbility
	{
		long			m_nImageFormatId;				//��Ƶ��ʽ
		long			m_nMaxSensitivity;				//���������
		long			m_nMinFrameInterval;			//��С֡���

	}ST_MotionDetectionAbility;

	//����ͷ��������
	typedef struct _PACKED_1_ tagCameraAbility
	{
		long							nCameraId;														//����ͷID

		unsigned char					bUserConfigurable;												//��Ƶ���Ƿ����û�����
		unsigned char					bMotionDetectionSupportFlag;									//�˶�����־,1��ʾ֧��,0��ʾ��֧��

		long							nImageFormatNum;												//������������
		ST_EncoderAbility				stEncoderAbility[CONST_MAX_DEVICE_IMAGE_FORMAT_NUM*2];

		long							nDetectionImageFormatNum;
		ST_MotionDetectionAbility		stMotionDetectionAbility[CONST_MAX_DEVICE_IMAGE_FORMAT_NUM*2];	//�ƶ������������

	}ST_CameraAbility;

	//��Ƶ������Ϣ
	typedef struct _PACKED_1_ tagVideoAbility
	{
		long					nCameraNum;											//����ͷ����
		ST_CameraAbility		stCameraAbility[CONST_MAX_CAMERA_NUM];				//����ͷ����

	}ST_VideoAbility;

	typedef struct _PACKED_1_ tagAudioAbility
	{
		unsigned char bInterPhoneFlag;
		long nAudioInTypeList[CONST_MAX_CAMERA_NUM];
		long nAudioEncodeTypeList[CONST_MAX_CAMERA_NUM];
		long nAudioDecodeTypeList[CONST_MAX_CAMERA_NUM];
	}ST_AudioAbility;

	//�豸������Ϣ����
	typedef struct _PACKED_1_ tagDeviceAbility
	{
		ST_VideoAbility	stVideoAbility;
		ST_AudioAbility stAudioAbility;

	}ST_DeviceAbility;

	typedef struct _PACKED_1_ tagPTZAbility
	{
		unsigned char			bInternalPTZFlag;											//����PTZ��־	1��ʾ֧������PTZ��0��ʾ��֧�֡�

		int						nPTZProtocolNum;											//֧�ֵ�PTZЭ����
		ST_PTZProtocol			stPTZProtocolList[CONST_MAX_PTZ_PROTOCOL_NUM];				//֧�ֵ�PTZЭ���б�

	}ST_PTZAbility;


	//�ļ�ϵͳ
	typedef struct _PACKED_1_ tagFileSystem
	{
		int					nFileSystemType;

		char				szFileSystemName[CONST_MAXLENTH_DISK_FILE_SYSTEM_NAME];

	}ST_FileSystem;

	//�ļ�ϵͳ����
	typedef struct _PACKED_1_ tagFileSystemAbility
	{
		int							nDiskType;

		int							nFileSystemTypeNum;
		ST_FileSystem			stFileSystemList[CONST_MAX_FILE_SYSTEM_NUM];

	}ST_FileSystemAbility;


	//��Ƶ��������
	typedef struct _PACKED_1_ tagAudioDecodeType
	{
		int					nAudioDecodeTypeId;														//��Ƶ��������Id

		char				szAudioDecodeTypeName[CONST_MAXLENGTH_AUDIO_DECODE_TYPE_NAME];			//��Ƶ����������

	}ST_AudioDecodeType;

	//��Ƶ��������
	typedef struct _PACKED_1_ tagEncodeType
	{
		int					nAudioEncodeTypeId;	   												//��Ƶ��������Id

		char				szAudioEncodeTypeName[CONST_MAXLENGTH_AUDIO_ENCODE_TYPE_NAME];		//��Ƶ����������

	}ST_EncodeType;

	//��Ƶ��������
	typedef struct _PACKED_1_ tagAudioInType
	{
		int	 nAudioInTypeId;													//��Ƶ��������Id

		char szAudioInTypeName[CONST_MAXLENGTH_AUDIO_IN_TYPE_NAME];				//��Ƶ����������

	}ST_AudioInType;

	//֧����Ƶ�ֱ���
	typedef struct _PACKED_1_ tagVideoResolution
	{
		int						nVideoHeight;													//�߶�
		int						nVideoWidth;													//���
		char					szResolutionName[CONST_MAXLENGTH_RESOLUTION_NAME];				//�ֱ��ʱ���

	}ST_VideoResolution;
	

	//��ʽ�ڱ�����
	typedef struct _PACKED_1_ tagBlindAbility
	{
		int						nMaxBlindAreaNum;													//�����ڵ�������Ŀ
		int						nBlindArea;															//�ڵ��������ռԴ�ֱ��ʰٷֱ�
	}ST_BlindAbility;



	//��Ƶ�ֱ�������
	typedef struct _PACKED_1_ tagVideoResolutionAbility
	{
		ST_VideoResolution		stVideoResolution;								//��Ƶ�ֱ���
		int						nMaxFrameRate;									//���֡��
		int						nMinFrameRate;									//��С֡��
		int						nMaxBitRate;									//�������
		int						nMinBitRate;									//��С����
		int						nMaxQuality;									//�����Ƶ����ֵ
		int						nMinQuality;									//��С��Ƶ����ֵ
		int						nMaxIFrameInterval;								//���I֡�Ĳ���
		int						nMinIFrameInterval;								//��СI֡�Ĳ���

		int						nBitRateTypeNum;								//����·������Ŀ
		int						nBitRateTypeList[CONST_MAX_BITRATE_TYPE_NUM];	//�����������б�
	}ST_VideoResolutionAbility;

	//��Ƶ�ֱ�������
	typedef struct _PACKED_1_ tagVideoResolutionAbilityV2
	{
		ST_VideoResolution		stVideoResolution;								//��Ƶ�ֱ���
		int						nMaxFrameRate;									//���֡��
		int						nMinFrameRate;									//��С֡��
		int						nMaxBitRate;									//�������
		int						nMinBitRate;									//��С����
		int						nMaxQuality;									//�����Ƶ����ֵ
		int						nMinQuality;									//��С��Ƶ����ֵ
		int						nMaxIFrameInterval;								//���I֡�Ĳ���
		int						nMinIFrameInterval;								//��СI֡�Ĳ���

		int						nBitRateTypeNum;								//����·������Ŀ
		int						nBitRateTypeList[CONST_MAX_BITRATE_TYPE_NUM];	//�����������б�
		int						nIFrameIntervalUnit;							//I֡�Ĳ�����λ    1,//��λΪ��  2//��λΪ֡
	}ST_VideoResolutionAbilityV2;

	//��Ƶ������
	typedef struct _PACKED_1_ tagVideoEncoderAbility
	{
		int									nEncoderType;	//�������͡�����ɲ鿴ENUM_EncoderTypeö�ٶ���																		//����������
		char								szEncoderName[CONST_MAXLENGTH_ENCODER_NAME];											//����������
		int									nVideoEncodeTotleAbility;																//��Ƶ���������� 

		int									nVideoResolutionAbilityNum;																
		ST_VideoResolutionAbility			stVideoResolutionAbilityList[CONST_MAX_DEVICE_IMAGE_FORMAT_NUM];						//��Ƶ�ֱ�������

	}ST_VideoEncoderAbility;

	//��Ƶ������
	typedef struct _PACKED_1_ tagVideoEncoderAbilityV2
	{
		int									nEncoderType;	//�������͡�����ɲ鿴ENUM_EncoderTypeö�ٶ���																		//����������
		char								szEncoderName[CONST_MAXLENGTH_ENCODER_NAME];											//����������
		int									nVideoEncodeTotleAbility;																//��Ƶ���������� 

		int									nVideoResolutionAbilityNum;																
		ST_VideoResolutionAbilityV2			stVideoResolutionAbilityList[CONST_MAX_DEVICE_IMAGE_FORMAT_NUM];						//��Ƶ�ֱ�������

	}ST_VideoEncoderAbilityV2;


	//����������
	typedef struct _PACKED_1_ tagStreamEncodeAbility
	{
		int						nEncoderType;					//����ID

		int						nVideoResolutionNum;			//�ֱ�����Ŀ

		ST_VideoResolution		stVideoResolutionList[CONST_MAX_DEVICE_IMAGE_FORMAT_NUM];

	}ST_StreamEncodeAbility;

	//����ͷ����������
	typedef struct _PACKED_1_ tagAVStreamAbility
	{
		int							nStreamId;													//����ID

		int							nStreamEncodeAbilityNum;									//��������������

		ST_StreamEncodeAbility		stStreamEncodeAbility[CONST_MAX_DEVICE_VIDEO_ENCODER_NUM];	//�������������б�

	}ST_AVStreamAbility;


	//��Ƶ��չ������Ϣ
	typedef struct _PACKED_1_ tagAudioExAbility
	{
		unsigned char			bInterPhoneFlag;											//��Ƶ�Խ���Ч��־	1��ʾ֧�ֶԽ���0��ʾ��֧�ֶԽ����ܡ�

		unsigned char			bAudioInFlag;												//��Ƶ������Ч��־	1��ʾ֧����Ƶ���룬0��ʾ��֧����Ƶ���빦�ܡ�

		int						nAudioInTypeNum;	
		ST_AudioInType			stAudioInTypeList[CONST_MAX_AUDIO_TYPE_NUM];				//��Ƶ���������б�

		int						nAudioEncodeTypeNum;
		ST_EncodeType			stAudioEncodeTypeList[CONST_MAX_AUDIO_ENCODE_TYPE_NUM];		//��Ƶ���������б�

		int						nAudioDecodeTypeNum;
		ST_AudioDecodeType		stAudioDecodeTypeList[CONST_MAX_AUDIO_DECODE_TYPE_NUM];		//��Ƶ���������б�

	}ST_AudioExAbility;

	typedef struct _PACKED_1_ tagMotionDetectionExAbility
	{
		int			nMaxSensitivity;			//���������
		int			nMinSensitivity;			//��С������
		int			nDefualSensitivity;			//Ĭ��������
		int			nDefualWidthCellNumber;		//Ĭ����������
		int			nDefualHighCellNumber;		//Ĭ������߿���
		int			nMaxWidthCellNumber;		//�����������
		int			nMinWidthCellNumber;		//��С��������
		int			nMaxHighCellNumber;			//�������߿���
		int			nMinHighCellNumber;			//��С����߿���
	}ST_MotionDetectionExAbility;
	

	//����ͷ��չ��������
	typedef struct _PACKED_1_ tagCameraExAbility
	{
		int							nCameraId;														//����ͷ���
		ST_VideoResolution			stMaxVideoResolution;											//֧�ֵ����ֱ���

		int							nSourceResolutionNum;
		ST_VideoResolution			stSourceResolutionList[CONST_MAX_SOURCE_RESOLUTION_NUM];		//֧��Դ�ֱ����б�

		int							nImageFormatNum;
		ST_VideoResolution			stVideoResolutionList[CONST_MAX_DEVICE_IMAGE_FORMAT_NUM];		//֧����Ƶ�ֱ����б�

		int							nAVStreamAbilityNum;
		ST_AVStreamAbility			stAVStreamAbilityList[CONST_MAX_CAMERA_STREAM_NUM];				//�������

		ST_BlindAbility				stBlindAbility;

		//ST_MotionDetectionExAbility stMotionDetectionExAbility;

	}ST_CameraExAbility;

	//��Ƶ��չ������Ϣ
	typedef struct _PACKED_1_ tagVideoExAbility
	{
		int								nCameraNum;
		ST_CameraExAbility				stCameraExAbilityList[CONST_MAX_CAMERA_NUM];					//����������б�

		unsigned char					bIsVideoSystemConfigurable;										//��Ƶ���Ƿ������

		int								nVideoEncoderNum;
		ST_VideoEncoderAbility			stVideoEncoderAbilityList[CONST_MAX_DEVICE_VIDEO_ENCODER_NUM];	//��Ƶ�������б�

		int								nVideoSystemNum;
		ST_VideoSystem					stVideoSystem[CONST_MAX_VIDEO_SYSTEM_NUM];						//��Ƶ��ʽ
	
	}ST_VideoExAbility;

	//��Ƶ��չ������Ϣ
	typedef struct _PACKED_1_ tagVideoExAbilityV2
	{
		int								nCameraNum;
		ST_CameraExAbility				stCameraExAbilityList[CONST_MAX_CAMERA_NUM];					//����������б�

		unsigned char					bIsVideoSystemConfigurable;										//��Ƶ���Ƿ������

		int								nVideoEncoderNum;
		ST_VideoEncoderAbilityV2		stVideoEncoderAbilityList[CONST_MAX_DEVICE_VIDEO_ENCODER_NUM];	//��Ƶ�������б�

		int								nVideoSystemNum;
		ST_VideoSystem					stVideoSystem[CONST_MAX_VIDEO_SYSTEM_NUM];						//��Ƶ��ʽ

	}ST_VideoExAbilityV2;


	//�豸��չ������Ϣ����
	typedef struct _PACKED_1_ tagDeviceExAbility
	{
		ST_VideoExAbility				stVideoExAbility;												//��Ƶ����

		ST_AudioExAbility				stAudioExAbility;												//��Ƶ����

		ST_PTZAbility					stPTZAbility;													//PTZ����

		int								nDiskTypeNum;													//�������͸���
		ST_FileSystemAbility			stFileSystemAbilityList[CONST_MAX_DISK_TYPE_NUM];				//�ļ�ϵͳ����

	}ST_DeviceExAbility;



	//�豸��չ������Ϣ����
	typedef struct _PACKED_1_ tagDeviceExAbilityV2
	{
		ST_VideoExAbilityV2				stVideoExAbility;												//��Ƶ����

		ST_AudioExAbility				stAudioExAbility;												//��Ƶ����

		ST_PTZAbility					stPTZAbility;													//PTZ����

		int								nDiskTypeNum;													//�������͸���
		ST_FileSystemAbility			stFileSystemAbilityList[CONST_MAX_DISK_TYPE_NUM];				//�ļ�ϵͳ����

	}ST_DeviceExAbilityV2;


////////////////////////////////////////////

	//���������Ͳ���
	typedef struct _PACKED_1_ tagMonitorType
	{
		int		nTypeId;												//���ͱ��
		char	szTypeName[CONST_MAXLENTH_MONITOR_TYPE_NAME];			//��������

	}ST_MonitorType;

	//����������������Ϣ����
	typedef struct _PACKED_1_ tagMonitorAbility
	{
		int							nMonitorId;										//���������
		int							nMonitorTypeNum;								//��������������
		ST_MonitorType				stMonitorTypeList[CONST_MAX_MONITOR_TYPE_NUM];	//�����������б�

	}ST_MonitorAbility;

	//layoutģʽ����
	typedef struct _PACKED_1_ tagLayoutModel
	{
		int		nModelId;			//ģʽ���
		int		nPicNumber;			//��������

	}ST_LayoutModel;

	//layout������Ϣ����
	typedef struct _PACKED_1_ tagLayoutAbility
	{
		int				nLayoutModelNum;								//layoutģʽ����		
		ST_LayoutModel	stLayoutModelList[CONST_MAX_LAYOUT_MODEL_NUM];	//layoutģʽ�б�

	}ST_LayoutAbility;

	//�Ӵ��ڽ���������Ϣ����
	typedef struct _PACKED_1_ tagSubWinDecodingAbility
	{
		ST_VideoResolution		stMaxVideoResolution;					//���ֱ���
		int						nSubWinNum;								//�Ӵ��ڸ���		
		int						nSubWinList[CONST_MAX_SUB_WIN_NUM];		//�Ӵ����б�

	}ST_SubWinDecodingAbility;

	//���ֽ�������������Ϣ����
	typedef struct _PACKED_1_ tagLayoutDecodingAbility
	{
		int							nLayoutModeID;															//����ģʽID
		int							nSubWinDecodingAbilityNum;												//�Ӵ��ڽ�����������
		ST_SubWinDecodingAbility	stSubWinDecodingAbilityList[CONST_MAX_SUB_WIN_DECODING_ABILITY_NUM];	//�Ӵ��ڽ��������б�

	}ST_LayoutDecodingAbility;

	//����������Ϣ����
	typedef struct _PACKED_1_ tagDecodingAbility
	{
		int							nLayoutDecodingAbilityNum;												//���ֽ�����������
		ST_LayoutDecodingAbility	stLayoutDecodingAbilityList[CONST_MAX_LAYOUT_DECODING_ABILITY_NUM];		//���ֽ��������б�

	}ST_DecodingAbility;

	//����������Ϣ����
	typedef struct _PACKED_1_ tagDiskAttributeEx
	{
		int				nDiskAttribute;									//��������
		char			szAttributeName[CONST_MAX_ATTRIBUTE_NAME_NUM];	//������������

	}ST_DiskAttributeEx;


	//�ļ�ϵͳ������Ϣ����
	typedef struct _PACKED_1_ tagNVRFileSystemAbility
	{
		int					nDiskType;											//��������

		int					nFileSystemNum;										//�ļ�ϵͳ����
		ST_FileSystem		stFileSystemList[CONST_MAX_NVR_FILE_SYSTEM_NUM];	//�ļ�ϵͳ�б�

		int					nDiskAttributeNum;									//�����б����
		ST_DiskAttributeEx	stDiskAttributeList[CONST_MAX_DISK_ATTRIBUTE_NUM];	//�����б�

	}ST_NVRFileSystemAbility;

	//���ڹ���ģʽ����
	typedef struct _PACKED_1_ tagNetWorkingMode
	{
		int									nWorkingType;							//��������
		char								szWorkingName[CONST_WORKMODE_NAME];		//����ģʽ����
		bool								bSupportIPConfigFlag;					//IP�����ñ�־
		bool								bSupportDHCPServerFlag;					//dhcp����˱�־
		bool								bSupportDHCPClientFlag;					//dhcp�ͻ��˱�־
		bool								bSupportDNSConfigFlag;					//DNS���ñ�־

	}ST_NetWorkingMode;

	//����������Ϣ����
	typedef struct _PACKED_1_ tagNetworkCardAbility
	{
		int							nNetworkCardId;											//����ID
		int							nNetworkingModeNum;										//��������ģʽ����
		ST_NetWorkingMode			stNetworkingModeList[CONST_MAX_NETWORKING_MODE_NUM];	//��������ģʽ�б�

	}ST_NetworkCardAbility;

	//����������Ϣ����
	typedef struct _PACKED_1_ tagNetworkAbility
	{
		int									nNetworkCardNum;										//��������
		ST_NetworkCardAbility				stNetworkCardAbilityList[CONST_MAX_NETWORK_CARD_NUM];	//���������б�

	}ST_NetworkAbility;

	//NVR�豸������Ϣ����
	typedef struct _PACKED_1_ tagNVRDeviceAbility
	{
		int									nMaxChannelNumber;				// ֧�ֵ����·��
		int									nDiskNumber;					// ֧�ֵ�Ӳ�̸���
		int									nMaxDecodeAbility;				// ������������D1Ϊ��λ
		int									nMaxBitRate;					// ¼���������
		int									nMaxPlaybackChannelNumber;		// ���ط�·��

		int									nMonitorAbilityNum;				// ��������������
		ST_MonitorAbility					stMonitorAbilityList[CONST_MAX_MONITOR_NUM];			// ����������

		ST_LayoutAbility					stLayoutAbility;				// Layout����

		ST_DecodingAbility					stDecodingAbility;				// ��������

		int									nFileSystemAbilityNum;			// �����ļ�ϵͳ��ʽ����
		ST_NVRFileSystemAbility				stFileSystemAbilityList[CONST_MAX_FILE_SYSTEM_NUM];		// �����ļ�ϵͳ��ʽ����	

		ST_NetworkAbility					stNetworkAbility;				//��������

	}ST_NVRDeviceAbility;

	//////////////////////////////////////////////////////////////









	//�û���½��Ϣ
	typedef struct _PACKED_1_ tagLoginInfo
	{
		char	szUserName[CONST_MAXLENGTH_USERNAME + 1];							//��½�û���
		char    szPassword[CONST_MAXLENGTH_USERPASSWORD + 1];						//��½����

	}ST_LoginInfo;

	//�豸��Ҫ��Ϣ
	typedef struct _PACKED_1_ tagDeviceSummaryParam
	{
		char	szDeviceName[CONST_MAXLENGTH_DEVICENAME + 1];						//�豸����
		char	szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];							//�豸��

		char	szManufacturerId[CONST_MAXLENGTH_MANUFACTURERID + 1];				//�豸�ͺ�
		char	szManufacturerName[CONST_MAXLENGTH_MANUFACTURERNAME + 1];			//��������

		char	szProductModel[CONST_MAXLENGTH_PRODUCTMODEL + 1];					//��Ʒģ��
		char	szProductDescription[CONST_MAXLENGTH_PRODUCTDESCRIPTION + 1];		//��Ʒ����
		char	szHardwareModel[CONST_MAXLENGTH_HARDWAREMODEL + 1];					//Ӳ��ģ��

		char	szHardwareDescription[CONST_MAXLENGTH_HARDWAREDESCRIPTION + 1];		//Ӳ������

		char	szMACAddress[CONST_MAXLENGTH_MACADDRESS + 1];						//MAC��ַ
		char	szBarCode[CONST_MAXLENGTH_BARCODE + 1];								//����������
		char	szProductionTime[CONST_MAXLENGTH_PRODUCTIONTIME + 1];				//����ʱ��


		long	nDeviceType;														//�豸����
		long	nVideoSystem;														//����֡ģʽ

		long	nCameraNum;															//����ͷ��
		long	nAlarmInNum;														//�����������
		long	nAlarmOutNum;														//�����������

		char	szHardwareVer[CONST_MAXLENGTH_HARDWAREVERSION_EXPAND + 1];					//�汾��Ϣ
		char	szSoftwareVer[CONST_MAXLENGTH_SOFTWAREVERSION_EXPAND + 1];

		long	nRS485Num;															//RS485���ڸ���
		long	nRS232Num;															//RS232���ڸ���

	}ST_DeviceSummaryParam;

	//����ͷ��Ϣ
	typedef struct _PACKED_1_ tagCameraInfoParam
	{
		long			nCameraId;												//�������ID��

		char			szCameraName[CONST_MAXLENGTH_CAMERA_NAME + 1];			//�����������

		char			szCameraModel[CONST_MAXLENGTH_CAMERAMODEL + 1];			//���������ʽ	

		long			nVideoSystem;											//��Ƶ��ʽ

	}ST_CameraInfoParam;

	//��������ͷ��Ϣ
	typedef struct _PACKED_1_ tagAllCameraInfoParam
	{
		long					nCameraNum;											//����ͷ��

		ST_CameraInfoParam		stWebCameraInfoParamList[CONST_MAX_CAMERA_NUM];		//����ͷ��Ϣ

	}ST_AllCameraInfoParam;

	//cpuͳ����Ϣ
	typedef struct _PACKED_1_ tagCpuStatistic
	{
		float				fCpuPercent;				//�豸cpu�ٷֱ�
		unsigned char		btCpuStatus;				//�豸cpu����״̬

	}ST_CpuStatistic;

	//�ڴ�ͳ����Ϣ
	typedef struct _PACKED_1_ tagMemStatistic
	{
		long		nMemTotalSize;				//�ڴ��ܴ�С����KBΪ��λ
		long		nMemFreeSize;				//�ڴ�ʣ���С����KBΪ��λ

	}ST_MemStatistic;

	//����ͳ����Ϣ
	typedef struct _PACKED_1_ tagDiskStatistic
	{
		long			nDiskId;				//���̱��

		long			nDiskTotalSize;			//�����ܴ�С,��KBΪ��λ

		long			nDiskFreeSize;			//����ʣ���С,��KBΪ��λ

		unsigned char	btDiskStatus;			//����״̬

	}ST_DiskStatistic;

	//���д���ͳ����Ϣ
	typedef struct _PACKED_1_ tagAllDiskStatistic
	{
		ST_DiskStatistic		stDiskStatisticList[CONST_MAX_DISK_NUM];			//������Ϣ

		long					nDiskNum;											//���̸���		

	}ST_AllDiskStatistic;

	//��Ƶͨ��ͳ����Ϣ
	typedef struct _PACKED_1_ tagVideoChannelStatistic
	{
		long			nCameraId;					//��������

		unsigned char	btRecordStatus;				//¼��״̬

		unsigned char	btCaptureStatus;			//ץ��״̬

		unsigned char	btSignalStatus;				//�����ź�״̬

		unsigned char	btHardwareStatus;			//Ӳ��״̬

		long			nBitRate;					//������

	}ST_VideoChannelStatistic;

	//��������ͳ����Ϣ
	typedef struct _PACKED_1_ tagAlarmInStatistic
	{
		long			nAlarmInId;					//��������ͨ��id��

		unsigned char	btAlarmInStatus;			//��������ͨ��״̬

		long			nLastAlarmTime;				//��󱨾�����ʱ��

	}ST_AlarmInStatistic;

	//�������ͳ����Ϣ
	typedef struct _PACKED_1_ tagAlarmOutStatistic
	{
		long			nAlarmOutId;				//�������ͨ��id��

		unsigned char	btAlarmOutStatus;			//�������ͨ��״̬

		long			nLastAlarmTime;				//��󱨾�ʱ��

	}ST_AlarmOutStatistic;

	//�豸����״̬
	typedef struct _PACKED_1_ tagDeviceWorkState
	{
		ST_CpuStatistic				stCpuStatistic;											//cpuͳ����Ϣ

		ST_MemStatistic				stMemStatistic;											//�ڴ�ͳ����Ϣ

		ST_DiskStatistic			stDiskStatisticList[CONST_MAX_DISK_NUM];				//����ͳ����Ϣ
		long						nDiskNum;

		ST_VideoChannelStatistic	stVideoChannelStatisticList[CONST_MAX_CAMERA_NUM];		//��Ƶͨ��ͳ����Ϣ
		long						nVideoChannelNum;

		ST_AlarmInStatistic			stAlarmInStatisticList[CONST_MAX_ALARM_IN_NUM];			//��������ͳ����Ϣ
		long						nAlarmInNum;

		ST_AlarmOutStatistic		stAlarmOutStatisticList[CONST_MAX_ALARM_OUT_NUM];		//�������ͳ����Ϣ
		long						nAlarmOutNum;

	}ST_DeviceWorkState;

	//NTP����
	typedef struct _PACKED_1_ tagNTPParam
	{
		unsigned char	bNTPEnableFlag;											//�Ƿ�����NTP��״̬

		char			szNTPIp[CONST_MAXLENGTH_IP + 1];						//NTPIP��ַ

		unsigned short	nNTPPort;												//NTP�Ķ˿�

		long			nRunTime;												//NTP��ʱʱ��

		long			nIPProtoVer;											//IPЭ������

	}ST_NTPParam;

	//DDNS����
	typedef struct _PACKED_1_ tagDDNSParam
	{
		unsigned char	bDDNSEnableFlag;										//�Ƿ�����DDNS��״̬

		long			nDDNSProviderId;										//�ṩ��id

		char			szDDNSAccounts[CONST_MAXLENGTH_DDNS_ACCOUNTS + 1];		//DDNS�˻�

		char			szDDNSDomainName[CONST_MAXLENGTH_DDNS_DOMAINNAME + 1];	//DDNS����	

		char			szDDNSPassword[CONST_MAXLENGTH_DDNS_PASSWORD + 1];		//DDNS����
	}ST_DDNSParam;

	//PPPoE����
	typedef struct _PACKED_1_ tagPPPoEParam
	{
		unsigned char	bPPPoEEnableFlag;										//�Ƿ�����PPPoE��״̬

		char			szPPPoEUserName[CONST_MAXLENGTH_PPPOE_USERNAME + 1];	//PPPoE���û���
		char			szPPPoEPassword[CONST_MAXLENGTH_PPPOE_PASSWORD + 1];	//PPPoE������

	}ST_PPPoEParam;

	//�������
	typedef struct _PACKED_1_ tagHostNetworkParam
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//�豸���豸ID

		long			nNetId;													//���ڱ��

		unsigned char	bAutoGetIpFlag;											//�Զ���ȡip��ַ
		char			szLocalIp[CONST_MAXLENGTH_IP + 1];						//�豸����IP��ַ
		char			szLocalSubnetMask[CONST_MAXLENGTH_IP + 1];				//�豸������������
		char			szGateway[CONST_MAXLENGTH_IP + 1];						//�豸����

		unsigned char	bAutoGetDNSFlag;										//�Զ���ȡDNS��������ַ
		char			szPrimaryDNSIp[CONST_MAXLENGTH_IP + 1];					//��DNS
		char			szSpareDNSIp[CONST_MAXLENGTH_IP + 1];					//����DNS

		unsigned short	nControlPort;											//�豸������ƶ˿�
		unsigned short	nRegisterPort;											//�豸ע��˿�
		unsigned short	nHttpPort;												//�豸HTTP�˿�

		long			nIPProtoVer;											//IPЭ������

		long			nAdapterType;											//����������

	}ST_HostNetworkParam;

	//�豸�˿ڲ���
	typedef struct _PACKED_1_ tagDevicePortParam
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//DVR�豸���豸ID

		unsigned short	m_nControlPort;											//������Ƶ�豸���豸������ƶ˿�
		unsigned short	m_nTCPAVPort;											//������Ƶ�豸��TCP����Ƶ�˿�
		unsigned short	m_nRTSPPort;											//������Ƶ�豸��RTSP�˿�
		unsigned short	m_nRTPPort;												//������Ƶ�豸��RTP�˿�
		unsigned short	m_nRTCPPort;											//������Ƶ�豸��RTCP�˿�
		unsigned short	m_nRegisterPort;										//������Ƶ�豸���豸ע��˿�
		unsigned short	m_nHttpPort;											//������Ƶ�豸���豸HTTP�˿�

		unsigned short	m_nReservePort1;										//����ʹ��
		unsigned short	m_nReservePort2;										
		unsigned short	m_nReservePort3;										
		unsigned short	m_nReservePort4;

	}ST_DevicePortParam;

	// PTZ����
	typedef struct _PACKED_1_ tagPTZParam
	{
		unsigned char	    bPTZEnableFlag;										//�Ƿ�������̨

		long				nCameraId;											//��̨��Ӧ���������

		long				nPTZDeviceId;										//��̨�豸��ַ

		long				nPTZProtocol;										//��̨Э��

		long				nComId;												//��̨���ӵĴ���id

		long				nBaudRate;											//������

		long				nDataBits;											//����λ

		long				nStopBits;											//ֹͣλ

		long				nParity;											//��żУ��

	}ST_PTZParam;

	//���е�PTZ����
	typedef struct _PACKED_1_ tagAllPTZParam
	{
		ST_PTZParam		stPTZParamList[CONST_MAX_CAMERA_NUM];	//PTZ����

		long			nPTZParamNum;							//PTZ��������

	}ST_AllPTZParam;

	//RS485����
	typedef struct _PACKED_1_ tagRS485Param
	{
		long		nComId;										//����ID

		char		szComName[CONST_LENGTH_RS485_NAME + 1];		//�����Զ�������

		long		nBaudRate;									//������

		long		nDataBits;									//����λ

		long		nStopBits;									//ֹͣλ

		long		nParity;									//��żУ��

		long		nFlowControl;								//����

	}ST_RS485Param;

	//���е�RS485����
	typedef struct _PACKED_1_ tagAllRS485Param
	{
		ST_RS485Param stRS485ParamList[CONST_MAX_RS484_NUM];	//RS485����

		long		  nRs485Num;								//RS485����

	}ST_AllRS485Param;

	//�Զ����·���
	typedef struct _PACKED_1_ tagUpdateParam
	{
		unsigned char   bUpdateEnableFlag;										//�����Զ����·���

		char	    	szUpdateServerIP[CONST_MAXLENGTH_IP + 1];				//���·�����IP��ַ

		unsigned short	nUpdateServerPort;										//���·������˿ں�

		long			nUpdatePeriod;											//��������ʱ��

		long			nIPProtoVer;											//IPЭ������

	}ST_UpdateParam;

	//�ƻ�ʱ��
	typedef struct _PACKED_1_ tagScheduleTime
	{
		long nStartTime;					//��ʼʱ��

		long nEndTime;						//����ʱ��

	}ST_ScheduleTime;

	typedef struct _PACKED_1_ tagScheduleWeek
	{
		long						nWeekDay;	

		int							nScheduleTimeNum;

		ST_ScheduleTime				stScheduleTime[CONST_MAX_PERIOD_SCHEDULE_RECORD_TIME_NUM];

	}ST_ScheduleWeek;

	//�ƻ�ʱ�����
	typedef struct _PACKED_1_ tagScheduleTimeParam
	{
		char						szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];		//�豸ID

		long						nCameraId;										//�����ID

		ST_ScheduleWeek				stScheduleWeekList[7];							//�ƻ�ʱ��

	}ST_ScheduleTimeParam;

	//�ƻ�¼�����
	typedef struct _PACKED_1_ tagScheduleRecordParam
	{
		char						szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];

		long						nCameraId;

		unsigned char			    nIsEnableRecord;										//����¼���־ 0:�ر�¼��1����¼��

		unsigned char				nIsEnableRecordAudio;									//�Ƿ�¼����Ƶ 0:��¼�ƣ�1��¼��

		long						nScheduleRecordType;									//¼�����

		ST_ScheduleTimeParam		stScheduleTimeParam;									//�ƻ�¼��ʱ��

	}ST_ScheduleRecordParam;

	//���еļƻ�¼�����
	typedef struct _PACKED_1_ tagAllScheduleRecordParam
	{
		ST_ScheduleRecordParam stScheduleRecordParamList[CONST_MAX_CAMERA_NUM];				//�ƻ�¼�����

		long				   nScheduleRecordNum;											//�ƻ�¼����Ŀ

	}ST_AllScheduleRecordParam;

	//����¼�����д����
	typedef struct _PACKED_1_ tagWritePolicy
	{
		long  nStoragePolicy;																//�洢����

		int	  nRecordLengthMode;															//¼������, ��1������С¼�ƣ�2����ʱ��¼�ƣ�

		long  nRecordFileMaxSize;															//¼���ļ����ߴ�

		long  nRecordFileTime;																//����¼���ļ���ʱ���С, ���루S��Ϊ��λ

		char  szFileNameSuffix[CONST_MAXLENGTH_FILENAME_SUFFIX + 1];						//¼���ļ���׺��

		long  nRecordFormatType;															//¼���ʽ	1ΪMPEG2PS����2Ϊ�Զ�����

	}ST_WritePolicy;

	//����¼�񱣴����
	typedef struct _PACKED_1_ tagSavePolicy
	{
		long nSaveDays;																		//�洢��

	}ST_SavePolicy;

	//����¼��ռ����
	typedef struct _PACKED_1_ tagSpacePolicy
	{
		long	  nCameraId;										//�����id

		long	  nMaxDiskSize;										//����ʹ�õ������̿ռ�

		float	  nScheduleRecordPercent;							//�ƻ�¼�������ʹ�õ������̿ռ�İٷֱ�

		float	  nAlarmRecordPercent;								//����¼������ʹ�õ������̿ռ�İٷֱ�

	}ST_SpacePolicy;

	//����¼��洢����
	typedef struct _PACKED_1_ tagRecordStorageParam
	{
		ST_WritePolicy		stWritePolicy;							//д����

		ST_SavePolicy		stSavePolicy;							//�������

		long			    nCameraNum;								//����ͷ��

		ST_SpacePolicy		stSpacePolicy[CONST_MAX_CAMERA_NUM];	//�ռ����

	}ST_RecordStorageParam;

	//��Ƶ������������
	typedef struct _PACKED_1_ tagVideoEncodeQuality
	{
		long		nQuality;			//��Ƶ����

		long		nVideoSystem;		//����֡ģʽ

		double		dFrameRate;			//����֡��

		long	    nImageFormatId;		//�ֱ���

		long	    nBitRateType;		//��������

		long		nBitRate;			//������

		long		nQuant;				//Qֵ

		long		nIFrameInterval;	//I֡�Ĳ���

		long		nEncoderType;		//�����ʽ������ɲ鿴ENUM_EncoderTypeö�ٶ���

		long		nCodingFlag;		//������1����������0��������

	}ST_VideoEncodeQuality;

	//��Ƶ������������
	typedef struct _PACKED_1_ tagAudioEncodeQuality
	{
		unsigned short		nFormatTag;					//��ʽ���

		unsigned short		nChannels;					//����ͨ������������

		unsigned long		nSamplesPerSec;				//ÿ�������

		unsigned long		nAvgBytesPerSec;			//

		unsigned short		nBlockAlign;				//

		unsigned short		nBitsPerSample;				//ÿ�β����Ĵ�С

		unsigned short		nCBSize;					//����׷�����ݳ���

		long				nEncodeType;				//�����ʽ

	}ST_AudioEncodeQuality;

	//¼����������
	typedef struct _PACKED_1_ tagRecordQualityParam
	{
		long				  nCameraId;							//����ͷid

		ST_VideoEncodeQuality stVideoVideoEncodeQuality;			//��Ƶ��������

		ST_AudioEncodeQuality stAudioEncodeQuality;					//��Ƶ��������

	}ST_RecordQualityParam;

	//���е�¼����������
	typedef struct _PACKED_1_ tagAllRecordQualityParam
	{
		ST_RecordQualityParam	  stRecordQualityParamList[CONST_MAX_CAMERA_NUM];				//¼������

		long					  nRecordQualityNum;											//

	}ST_AllRecordQualityParam;

	//��������¼�����
	typedef struct _PACKED_1_ tagAlarmOutActionParam
	{
		char szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];

		long nAlarmOutId;																		//��������˿ڵ�ID��

		long nAlarmOutFlag;																		//���������־

		long nEventTypeId;																		//�����¼�����

	}ST_AlarmOutActionParam;

	//����¼���¼�����
	typedef struct _PACKED_1_ tagAlarmRecordActionParam
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];								//DVR�豸���豸ID

		long			nCameraId;																//�������ID��

		long			nPreRecordTime;															//Ԥ¼ʱ��

		long			nRecordTime;															//¼��ʱ��

		long			nEventTypeId;															//�����¼�����

		unsigned char   nIsEnableRecordAudio;													//�Ƿ�¼����Ƶ

	}ST_AlarmRecordActionParam;

	//������̨�¼�����
	typedef struct _PACKED_1_ tagAlarmPTZActionParam
	{
		long					nEventTypeId;											//�����¼�����

		char					szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//DVR�豸���豸ID

		long					nCameraId;												//�������ID��

		long					nComId;													//����id��

		long					nPtzId;													//��̨�豸��ID��

		char					btPtzOperationCmd[CONST_MAXLENTH_PTZOPERATION_CMD];		//��̨��������

		long					nPtzOperationCmdLen;									//��̨���������

		long					nReserve;												//����λ

	}ST_AlarmPTZActionParam;

	//OSD��Ϣ����
	typedef struct _PACKED_1_ tagOSDInfoParam
	{
		long				nOSDType;							//ˮӡ����

		char				szInfo[CONST_MAXLENGTH_OSDINFO + 1];

		unsigned char		bOSDEnableFlag;						//�Ƿ���ʾˮӡ��0������ʾ��1����ʾ��

		long				nTopX;

		long				nTopY;

	}ST_OSDInfoParam;

	//��ƵOSD��Ϣ����
	typedef struct _PACKED_1_ tagVideoOSDInfoParam
	{
		long					nCameraId;								//�����id

		long					nImageFormatID;							//ͼ���ʽ(�˲����ѷ���)

		ST_OSDInfoParam			stOSDInfoParam[CONST_MAX_CAMERA_NUM];	//OSD��Ϣ����

		long					nOSDInfoNum;							//OSD��Ϣ��Ŀ

	}ST_VideoOSDInfoParam;

	//��ƵOSD��Ϣ����
	typedef struct _PACKED_1_ tagAllVideoOSDInfoParam
	{
		long							nVideoOSDInfoParamNum;							//OSD������Ŀ

		ST_VideoOSDInfoParam			stVideoOSDInfoParamList[CONST_MAX_CAMERA_NUM];		//OSD��������

	}ST_AllVideoOSDInfoParam;
	//OSD��Ϣ����
	typedef struct _PACKED_1_ tagOSDInfoExParam
	{
		long				nOSDType;							//ˮӡ����

		unsigned char		bOSDEnableFlag;						//�Ƿ���ʾˮӡ��0������ʾ��1����ʾ��

		float				nX;

		float				nY;
		
		char				szInfo[CONST_MAXLENGTH_OSDINFO];

	}ST_OSDInfoExParam;

	//��ƵOSD��Ϣ����
	typedef struct _PACKED_1_ tagVideoOSDInfoExParam
	{
		long					nCameraId;								//�����id

		long					nOSDInfoNum;							//OSD��Ϣ��Ŀ
		ST_OSDInfoExParam		stOSDInfoParam[CONST_MAX_OSDINFO_NUM];	//OSD��Ϣ����

	}ST_VideoOSDInfoExParam;

	//��ƵOSD��Ϣ����
	typedef struct _PACKED_1_ tagAllVideoOSDInfoExParam
	{
		long							nCameraNum;										//OSD������Ŀ

		ST_VideoOSDInfoExParam			stVideoOSDInfoParamList[CONST_MAX_CAMERA_NUM];	//OSD��������

	}ST_AllVideoOSDInfoExParam;

	typedef struct tagVideoOSDFontTypeParam
	{
		int			nFontID;
		char		szDescription[CONST_OSD_FONT_DESCRIPTION];		//OSD����

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

	//���������¼�����
	typedef struct _PACKED_1_ tagAlarmOverlayActionParam
	{
		long nEventTypeId;										//�����¼�����

		char szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];			//DVR�豸���豸ID

		long nCameraId;											//�����ID��

		ST_OSDInfoParam stOSDInfoParam;							//ˮӡ��Ϣ��Ķ���

	}ST_AlarmOverlayActionParam;

	//����IO����
	typedef struct _PACKED_1_ tagAlarmIOEventParam
	{
		long								nEventId;																		//�����¼�ID

		long								nPolicyId;																		//��������ID

		long								nAlarmInId;																		//��������˿ں�

		unsigned char						bAlarmIOEnableFlag;																//�Ƿ�����IO����(0���������� 1������)

		ST_ScheduleTimeParam				stScheduleTimeParam;															//����ʱ�����
		char								szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];										//�豸ID��

		long								nAlarmOutActionNum;																//��������¼�����
		ST_AlarmOutActionParam				stAlarmOutActionParam[CONST_MAX_ALARM_OUT_NUM];									//��������¼�

		long								nAlarmRecordActionNum;															//����¼���¼�����
		ST_AlarmRecordActionParam			stAlarmRecordActionParam[CONST_MAX_CAMERA_NUM];									//����¼���¼�

		long								nAlarmPTZActionNum;																//������̨�¼�����
		ST_AlarmPTZActionParam				stAlarmPTZActionParam[CONST_MAX_CAMERA_NUM];									//������̨�¼�

		long								nAlarmOverlayNum;																//���������¼�����
		ST_AlarmOverlayActionParam			stAlarmOverlayActionParam[CONST_MAX_CAMERA_NUM];								//���������¼�

	}ST_AlarmIOEventParam;

	//����I/O�����¼�����
	typedef struct _PACKED_1_ tagAllAlarmIOEventParam
	{
		ST_AlarmIOEventParam stAlarmIOEventParamList[CONST_MAX_ALARM_IN_NUM];			//����I/O�¼�

		long				 nAlarmIOEventNum;											//����I/O�¼���Ŀ

	}ST_AllAlarmIOEventParam;

	//�������
	typedef struct _PACKED_1_ tagDetectionAreaParam
	{
		long		nTopX;								//����������Ͻ� x ������
		long		nTopY;								//����������Ͻ� y ������
		long		nWidth;								//���������
		long		nHeight;							//�������߶�

	}ST_DetectionAreaParam;

	//������
	typedef struct _PACKED_1_ tagMotionDetectionParam
	{
		long							nSensitivity;																	//�����ȣ��˲�����Ч������ʹ��

		long							nCheckBlockNum;																	//������

		unsigned char					bToUpCheckFlag;																	//�����⣨1����⣬0������⣩
		unsigned char					bToDownCheckFlag;																//���¼�⣨1����⣬0������⣩
		unsigned char					bToLeftCheckFlag;																//�����⣨1����⣬0������⣩
		unsigned char					bToRightCheckFlag;																//���Ҽ�⣨1����⣬0������⣩
		unsigned char					bAreaMaskFlag;																	//���α�ʶ��1�����Σ�0����⣩

		long							nImageFormatId;																	//��Ƶ��ʽ

		long							nFrameInterval;																	//֡���

		long							nDetectionAreaNum;																//���������Ŀ���ٷֱȣ�ָռ���ƶ��������İٷֱȣ��ٷֱ�ԽС�����������Խ��

		ST_DetectionAreaParam			stDetectionAreaList[CONST_MAX_DETECTION_NUM];									//�ƶ��������

	}ST_MotionDetectionParam;

	//��ⱨ������
	typedef struct _PACKED_1_ tagMotionDetectionEventParam
	{
		long							nEventId;																		//�����¼�ID

		long							nPolicyId;																		//��������ID

		char							szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];										//DVR�豸���豸ID

		long							nCameraId;																		//DVR�豸����ͷID��

		unsigned char					bMotionDetectionEnableFlag;														//�Ƿ������˶����
		ST_ScheduleTimeParam			stScheduleTimeParam;															//����ʱ�����

		ST_MotionDetectionParam			stMotionDetectionParam;															//������

		long							nAlarmOutActionNum;																//��������¼�����
		ST_AlarmOutActionParam			stAlarmOutActionParam[CONST_MAX_ALARM_OUT_NUM];									//��������¼�

		long							nAlarmRecordActionNum;															//����¼���¼�����
		ST_AlarmRecordActionParam		stAlarmRecordActionParam[CONST_MAX_CAMERA_NUM];									//����¼���¼�

		long							nAlarmPTZActionNum;																//������̨�¼�����
		ST_AlarmPTZActionParam			stAlarmPTZActionParam[CONST_MAX_CAMERA_NUM];									//������̨�¼�

		long							nAlarmOverlayNum;																//���������¼�����
		ST_AlarmOverlayActionParam		stAlarmOverlayActionParam[CONST_MAX_CAMERA_NUM];								//���������¼�


	}ST_MotionDetectionEventParam;

	//�豸�����ƶ���ⱨ���¼�
	typedef struct _PACKED_1_ tagAllMotionDetectionEventParam
	{
		ST_MotionDetectionEventParam stMotionDetectionEventParamList[CONST_MAX_CAMERA_NUM];				//�ƶ���ⱨ���¼�

		long						 nMotionDetectionEventNum;											//�ƶ���ⱨ���¼���Ŀ

	}ST_AllMotionDetectionEventParam;

	typedef struct _PACKED_1_ tagDetectionAreaV2
	{
		int		nWidthCellNumber;								//��������������������������Ŀ���Ϊ����
		int		nHighCellNumber;								//����߿���������������������ĸ߻���Ϊ����
		char    szData[CONST_MAX_DETECTIONAREA];				//���������б����飬������һλ����һ��0��ʾ����Ҫ��⣬1��ʾ��Ҫ��⣬ 8λһ���ֽڱ����������У������λ����0��䡣
		int		nDataLen;										//�ֽ����鳤��,8�������� >= (�������� * ����߿���)

	}ST_DetectionAreaV2;

	typedef struct _PACKED_1_ tagMotionDetectionParamV2
	{
		int						nCheckBlockNum;										//������
		int						nSensitivity;											//������
		ST_DetectionAreaV2		stDetectionAreaV2;	

	}ST_MotionDetectionParamV2;

	typedef struct _PACKED_1_ tagMotionDetectionEventParamV2
	{
		long							nEventId;																		//�����¼�ID

		long							nPolicyId;																		//��������ID

		char							szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];										//DVR�豸���豸ID

		long							nCameraId;																		//DVR�豸����ͷID��

		unsigned char					bMotionDetectionEnableFlag;														//�Ƿ������˶����
		ST_ScheduleTimeParam			stScheduleTimeParam;															//����ʱ�����

		ST_MotionDetectionParamV2		stMotionDetectionParam;															//������

		long							nAlarmOutActionNum;																//��������¼�����
		ST_AlarmOutActionParam			stAlarmOutActionParam[CONST_MAX_ALARM_OUT_NUM];									//��������¼�

		long							nAlarmRecordActionNum;															//����¼���¼�����
		ST_AlarmRecordActionParam		stAlarmRecordActionParam[CONST_MAX_CAMERA_NUM];									//����¼���¼�

		long							nAlarmPTZActionNum;																//������̨�¼�����
		ST_AlarmPTZActionParam			stAlarmPTZActionParam[CONST_MAX_CAMERA_NUM];									//������̨�¼�

		long							nAlarmOverlayNum;																//���������¼�����
		ST_AlarmOverlayActionParam		stAlarmOverlayActionParam[CONST_MAX_CAMERA_NUM];								//���������¼�


	}ST_MotionDetectionEventParamV2;

	//�豸�����ƶ���ⱨ���¼�
	typedef struct _PACKED_1_ tagAllMotionDetectionEventParamV2
	{
		ST_MotionDetectionEventParamV2 stMotionDetectionEventParamList[CONST_MAX_CAMERA_NUM];				//�ƶ���ⱨ���¼�

		long						 nMotionDetectionEventNum;											//�ƶ���ⱨ���¼���Ŀ

	}ST_AllMotionDetectionEventParamV2;



//////////////////

	//�ڵ�������
	typedef struct _PACKED_1_ tagOcclusionDetectionParam
	{
		int								nSensitivity;																//������

		int								nDetectionAreaNum;															//���������Ŀ
		ST_DetectionAreaParam			stDetectionAreaList[CONST_MAX_DETECTION_NUM];								//�ƶ��������

	}ST_OcclusionDetectionParam;

	//�ڵ���������
	typedef struct _PACKED_1_ tagOcclusionDetectionEventParam
	{
		char							szDeviceId[CONST_MAXLENGTH_DEVICEID];										//�豸ID

		int								nCameraId;																	//����ͷID��

		unsigned char					bOcclusionDetectionEnableFlag;												//�Ƿ��������

		ST_ScheduleTimeParam			stScheduleTimeParam;														//����ʱ�����

		ST_OcclusionDetectionParam		stOcclusionDetectionParam;													//������

		int								nAlarmOutActionNum;															//��������¼�����
		ST_AlarmOutActionParam			stAlarmOutActionParam[CONST_MAX_ALARM_OUT_NUM];								//��������¼�

		int								nAlarmPTZActionNum;															//������̨�¼�����
		ST_AlarmPTZActionParam			stAlarmPTZActionParam[CONST_MAX_CAMERA_NUM];								//������̨�¼�

	}ST_OcclusionDetectionEventParam;

	//�豸�����ڵ���ⱨ���¼�
	typedef struct _PACKED_1_ tagAllOcclusionDetectionEventParam
	{
		ST_OcclusionDetectionEventParam stOcclusionDetectionEventParamList[CONST_MAX_CAMERA_NUM];					//�ƶ���ⱨ���¼�

		long							nDetectionEventNum;															//�ƶ���ⱨ���¼���Ŀ

	}ST_AllOcclusionDetectionEventParam;

	//��Ƶ��ʧ��������
	typedef struct _PACKED_1_ tagVideoLoseDetectionEventParam
	{
		char							szDeviceId[CONST_MAXLENGTH_DEVICEID];										//�豸ID

		int								nCameraId;																	//����ͷID��

		unsigned char					bVideoLoseDetectionEnableFlag;												//�Ƿ��������

		int								nAlarmOutActionNum;															//��������¼�����
		ST_AlarmOutActionParam			stAlarmOutActionParam[CONST_MAX_ALARM_OUT_NUM];								//��������¼�

		int								nAlarmPTZActionNum;															//������̨�¼�����
		ST_AlarmPTZActionParam			stAlarmPTZActionParam[CONST_MAX_CAMERA_NUM];								//������̨�¼�

	}ST_VideoLoseDetectionEventParam;

	//�豸�����ƶ���ⱨ���¼�
	typedef struct _PACKED_1_ tagAllVideoLoseDetectionEventParam
	{
		ST_VideoLoseDetectionEventParam stVideoLoseDetectionEventParamList[CONST_MAX_CAMERA_NUM];					//��Ƶ��ʧ�����¼�

		long							nDetectionEventNum;															//��Ƶ��ʧ�����¼���Ŀ

	}ST_AllVideoLoseDetectionEventParam;


/////////////////////

	//����I/O����
	typedef struct _PACKED_1_ tagAlarmInParam
	{
		long  nAlarmInId;													//��������˿ں�

		char  szAlarmInputName[CONST_MAXLENGTH_ALARMINPUTNAME + 1];			//��������˿���

		long  nAlarmInValidLevel;											//�����������Ч��ƽ

	}ST_AlarmInParam;

	//����I/O���
	typedef struct _PACKED_1_ tagAlarmOutParam
	{

		long		nAlarmOutId;											//�������ID��

		char		szAlarmOutName[CONST_MAXLENGTH_ALARMOUTNAME + 1];		//�����������

		long		nAlarmValidSignal;										//������Ч�ź�

		long		nAlarmMode;												//����ģʽ
		float		nAlarmOutFrequency;										//����Ƶ��

		long		nAlarmTime;												//����ʱ��

		long		nActivatedStartTime;									//�������ʼʱ��(��00��00����ʼʱ��hh��mm������)
		long		nActivatedEndTime;										//�����������ʱ��(��00��00������ʱ��hh��mm������)

	}ST_AlarmOutParam;

	//���������豸
	typedef struct _PACKED_1_ tagAllAlarmInParam
	{
		long					nAlarmInNum;									//���������豸��Ŀ

		ST_AlarmInParam			stAlarmInParamList[CONST_MAX_ALARM_IN_NUM];		//���������豸����

	}ST_AllAlarmInParam;

	//��������豸
	typedef struct _PACKED_1_ tagAllAlarmOutParam
	{
		long					nAlarmOutNum;									//��������豸��Ŀ

		ST_AlarmOutParam		stAlarmOutParamList[CONST_MAX_ALARM_OUT_NUM];	//��������豸����

	}ST_AllAlarmOutParam;

	//�����豸
	typedef struct _PACKED_1_ tagAlarmDeviceParam
	{
		long					nAlarmInNum;									//����������Ŀ

		ST_AlarmInParam			stAlarmInParam[CONST_MAX_ALARM_IN_NUM];			//�����������

		long					nAlarmOutNum;									//����������Ŀ

		ST_AlarmOutParam		stAlarmOutParam[CONST_MAX_ALARM_OUT_NUM];		//�����������		

	}ST_AlarmDeviceParam;

	//���̱�������
	typedef struct _PACKED_1_ tagDiskAlarmParam
	{
		unsigned char		bDiskFullAlarmCheckFlag;		//�Ƿ���Ӳ����
		long				nMaxDiskPercent;				//Ӳ�̱����߷�ֵ��ռ��Ӳ�������ʣ�
		long				nMinDiskPercent;				//Ӳ�̱����ͷ�ֵ��ռ��Ӳ����ͱ��ʣ�

		unsigned char		bDiskErrorAlarmCheckFlag;		//�Ƿ���Ӳ�̳���

	}ST_DiskAlarmParam;

	//���̱�������
	typedef struct _PACKED_1_ tagDiskAlarmParamV2
	{
		unsigned int					nInterval;					//�ϱ��������λΪ�룬��С���Ϊ10�룬���Ϊ86400��(1��)
		int								nAlarmThreshold;			//������ֵ, ��λΪ�ٷֱ�
		bool							bAlarmEnableFlag;			//�Ƿ��������̱���(false���������� true������)
		long							nAlarmOutActionNum;																//��������¼�����
		ST_AlarmOutActionParam			stAlarmOutActionParam[CONST_MAX_ALARM_OUT_NUM];									//��������¼�
		long							nAlarmPTZActionNum;																//������̨�¼�����
		ST_AlarmPTZActionParam			stAlarmPTZActionParam[CONST_MAX_CAMERA_NUM];									//������̨�¼�
	}ST_DiskAlarmParamV2;

	//�������Ĳ���
	typedef struct _PACKED_1_ tagAlarmServiceParam
	{
		unsigned char		bAlarmCenterEnableFlag;										//�Ƿ����ñ�������(0�������ã� 1������)

		char				szAlarmCenterServerIP[CONST_MAXLENGTH_IP + 1];				//��������IP��ַ
		unsigned short		nAlarmCenterServerPort;										//�������ĵĶ˿�

		unsigned char		bAlarmEmailEnableFlag;										//�Ƿ����ñ����ʼ�
		char				szAlarmEmailAddress[CONST_MAXLENTH_EMAIL_ADDRESS + 1];		//�����ʼ���ַ

		long				nIPProtoVer;												//IPЭ������

	}ST_AlarmServiceParam;

	//��������
	typedef struct _PACKED_1_ tagAlarmParam
	{
		int						m_nAlarmInterval;			//�������

	}ST_AlarmParam;

	//�豸ע�����
	typedef struct _PACKED_1_ tagRegisterParam
	{
		unsigned char	bRegisterEnableFlag;								//�Ƿ�����ע��(0�������ã� 1������)

		char			szRegisterSrvIP[CONST_MAXLENGTH_IP + 1];			//ע�������IP��ַ,�����ֽ�˳��

		unsigned short	nRegisterSrvPort;									//ע��������Ķ˿�

		long			nIPProtoVer;										//IPЭ������

	}ST_RegisterParam;

	//ʰ������������
	typedef struct _PACKED_1_ tagToneArmParam
	{
		long			nCameraId;											//�������ID��

		unsigned char	bToneArmEnableFlag;									//�Ƿ�����ʰ������0�������ã�1�����ã�

		long			nToneArmType;										//ʰ��������

		long			nVolume;											//����

	}ST_ToneArmParam;

	//����ʰ��������
	typedef struct _PACKED_1_ tagAllToneArmParam 
	{
		ST_ToneArmParam  stToneArmParamList[CONST_MAX_CAMERA_NUM];

		long			 nToneArmNum;

	}ST_AllToneArmParam;

	//����������
	typedef struct _PACKED_1_ tagLoudhailerParam
	{
		long			nCameraId;										//�������ID��

		unsigned char	bLoudhailerEnableFlag;							//�Ƿ�������������0�������ã�1�����ã�

		long			nLoudhailerType;								//����������

		long			nVolume;										//����

	}ST_LoudhailerParam;

	typedef struct _PACKED_1_ tagAllLoudhailerParam
	{
		ST_LoudhailerParam stLoudhailerParamList[CONST_MAX_CAMERA_NUM];

		long			   nLoudhailerNum;

	}ST_AllLoudhailerParam;

	//������������
	typedef struct _PACKED_1_ tagHeartbeatParam
	{
		char			szHeartbeatServerIp[CONST_MAXLENGTH_IP + 1];	//����������IP

		unsigned short	nHeartbeatServerPort;							//�����������˿�

		long			nHeartbeatInterval;								//�����������������Ϊ��λ

		long			nHeartbeatAckTimeout;							//��������Ӧ��ʱʱ�䣬����Ϊ��λ

		long			nHeartbeatTimeoutCount;							//������ʱ�ܴ���,������������ص�¼����������

		long			nIPProtoVer;									//IPЭ������

	}ST_HeartbeatParam;

	//FTP��������
	typedef struct _PACKED_1_ tagFTPParam
	{
		unsigned char	bFTPEnableFlag;												//�Ƿ�����FTP��״̬

		char			szFTPServerAddr[CONST_MAXLENGTH_IP + 1];					//FTP��������ַ

		char			szFTPUserName[CONST_MAXLENGTH_FTP_USERNAME + 1];			//FTP�˻�

		char			szFTPPassword[CONST_MAXLENGTH_FTP_PASSWORD + 1];			//FTP����

		char			szFTPWorkPath[CONST_MAXLENGTH_FTP_WORKPATH + 1];			//FTP����·��	

		long			nIPProtoVer;												//IPЭ������

	}ST_FTPParam;

	//SMTP��������
	typedef struct _PACKED_1_ tagSMTPParam
	{
		unsigned char	bSMTPEnableFlag;										//SMTP���ñ�־(0�������ã�1������)

		unsigned char	bUseDefaultSMTPServerFlag;								//�Ƿ�ʹ��Ĭ�������ʶ(0�������ã�1������)

		char			szSMTPServerAddr[CONST_MAXLENGTH_IP + 1];				//SMTP��������ַ

		unsigned short  nSMTPServerPort;										//SMTP�������˿�

		char			szSMTPUserName[CONST_MAXLENGTH_USERNAME + 1];			//�˻�

		char			szSMTPPassword[CONST_MAXLENGTH_USERPASSWORD + 1];		//����

		char			szSenderEmailAddress[CONST_MAXLENGTH_EMAIL_ADDRESS + 1];//�����˵�ַ	

		char			szRecipientEmailAddressList[16][CONST_MAXLENGTH_EMAIL_ADDRESS + 1];//�����˵�ַ
		int				nRecipientEmailAddressCount;							//�ռ��˸���

		int				nMailLanguage;											//�ʼ���������

		int				nAttachmentImageQuality;								//�ʼ�������ͼ������

	}ST_SMTPParam;

	//IPЭ�����
	typedef struct _PACKED_1_ tagCommunicationParam
	{
		long			nIPProtoFlag;			//IPЭ������

	}ST_CommunicationParam;

	//IPЭ�����
	typedef struct _PACKED_1_ tagBroadcastParam
	{
		unsigned char	bBroadcastEnableFlag;					//�Ƿ����ù㲥��0�������ã�1�����ã�

		unsigned short	nBroadcastPort;							//�㲥�˿�

		long			nBroadcastInterval;						//���͹㲥���������Ϊ��λ

	}ST_BroadcastParam;


	//���ղ���
	typedef struct _PACKED_1_ tagSnapshotParam
	{
		long			nCameraId;				//�����id

		unsigned char	bSnapshotEnableFlag;	//�Ƿ�����ץ��(0�������� 1������)

		long			nImageFormatId;			//�ֱ���

		long			nQuality;				//ץ������

		long			nShootTimes;			//ÿ�δ���ץ�Ĵ���

		long			nPhotoFormat;			//ͼƬ��ʽ

	}ST_SnapshotParam;

	//��������ͷ���ղ���
	typedef struct _PACKED_1_ tagAllSnapshotParam
	{
		ST_SnapshotParam stSnapshotParamList[CONST_MAX_CAMERA_NUM];

		long			 nCameraNum;

	}ST_AllSnapshotParam;

	//¼���ļ���ѯ����
	typedef struct _PACKED_1_ tagRecordFileSearchParam
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];			//�豸ID

		char			szDeviceName[CONST_MAXLENGTH_DEVICENAME + 1];		//�豸����

		long			nCameraId;											//�����ID

		char			szCameraName[CONST_MAXLENGTH_CAMERA_NAME + 1];		//���������

		char			szDeviceIp[CONST_MAXLENGTH_IP + 1];					//�豸IP

		char			szRecordFileName[CONST_MAXLENGTH_FILE_NAME + 1];	//¼���ļ�����

		unsigned long	nStartTime;											//¼���ļ���ʼʱ��

		unsigned long	nEndTime;											//¼���ļ�����ʱ��

		long			nRecordType;										//¼������

		long			nAlarmId;											//����ID

		long			nAlarmType;											//��������

	}ST_RecordFileSearchParam;

	//¼���ļ�����
	typedef struct _PACKED_1_ tagRecordFile
	{
		long			nId;												//���ݿ���е�Id

		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];			//�豸ID

		char			szDeviceName[CONST_MAXLENGTH_DEVICENAME + 1];		//�豸����

		long			nCameraId;											//��������

		char			szCameraName[CONST_MAXLENGTH_CAMERA_NAME + 1];		//���������

		char			szDeviceIp[CONST_MAXLENGTH_IP + 1];					//�豸IP

		char			szRecordFileName[CONST_MAXLENGTH_FILE_NAME + 1];	//¼���ļ�����

		long			nRecordTime;										//¼��ʱ��

		long			nRecordType;										//¼���ļ�����

		long			nAlarmId;											//����Id

		long			nAlarmType;											//��������

		long			nFileByteLength;									//¼���ļ���С�����ֽ�Ϊ��λ��

		long			nFileTimeLength;									//¼���ļ��Ĳ���ʱ�䳤�ȣ���S���룩Ϊ��λ

	}ST_RecordFile;

	//��־�������
	typedef struct _PACKED_1_ tagLogRequestParam
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];		//�豸ID

		char			szDeviceIp[CONST_MAXLENGTH_IP + 1];				//�豸IP

		long			nCameraId;										//�����ID��

		char			szUserName[CONST_MAXLENGTH_USERNAME + 1];		//�û���

		long			nSelectMode;									//��ѯ��ʽ

		long			nMajorType;										//������

		long			nMinorType;										//������

		unsigned long	nStartTime;										//��ʼʱ��

		unsigned long	nEndTime;										//����ʱ��

	}ST_LogRequestParam;

	//��־��Ϣ����
	typedef struct _PACKED_1_ tagLogInfo
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];			//�豸ID

		char			szDeviceIp[CONST_MAXLENGTH_IP + 1];					//�豸IP

		long			nCameraId;											//�����ID��

		char			szUserName[CONST_MAXLENGTH_USERNAME + 1];			//�û���

		long			nMajorType;											//������

		long			nMinorType;											//������

		unsigned long	nLogTime;											//��־����ʱ��

		char			szLogData[CONST_MAXLENGTH_LOG_DATA + 1];			//��־��Ϣ

	}ST_LogInfo;

	///////////
	//��־�������
	typedef struct _PACKED_1_ tagLogRequestParamV2
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID];			//�豸ID

		char			szDeviceIp[CONST_MAXLENGTH_IP];					//�豸IP

		long			nCameraId;										//�����ID��

		char			szUserName[CONST_MAXLENGTH_USERNAME];			//�û���

		long			nSelectMode;									//��ѯ��ʽ

		long			nMajorType;										//������

		long			nMinorType;										//������

		ST_TimeStruct	stStartTime;										//��ʼʱ��

		ST_TimeStruct	stEndTime;										//����ʱ��

	}ST_LogRequestParamV2;

	//��־��Ϣ����
	typedef struct _PACKED_1_ tagLogInfoV2
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID];				//�豸ID

		char			szDeviceIp[CONST_MAXLENGTH_IP];						//�豸IP

		long			nCameraId;											//�����ID��

		char			szUserName[CONST_MAXLENGTH_USERNAME];				//�û���

		long			nMajorType;											//������

		long			nMinorType;											//������

		ST_TimeStruct	stLogTime;											//��־����ʱ��

		char			szLogData[CONST_MAXLENGTH_LOG_DATA];				//��־��Ϣ

	}ST_LogInfoV2;
	///////////

	typedef struct _PACKED_1_ tagAVFrameData
	{
		long					nStreamFormat;						//1��ʾԭʼ����2��ʾTS�������3��ʾԭʼ��������4��ʾPS�����������ɲ鿴ENUM_StreamFormatö�ٶ���

		long					nESStreamType;						//ԭʼ�����ͣ�1��ʾ��Ƶ��2��ʾ��Ƶ������ɲ鿴ENUM_ESStreamTypeö�ٶ���

		long					nEncoderType;						//�����ʽ������ɲ鿴ENUM_EncoderTypeö�ٶ���

		long					nCameraNo;							//������ţ���ʾ�������Եڼ�·

		unsigned long			nSequenceId;						//����֡���

		long					nFrameType;							//����֡����,1��ʾI֡, 2��ʾP֡, 0��ʾδ֪����

		INT64					nTimeStamp;							//���ݲɼ�ʱ�������λΪ����

		char*					pszData;							//����

		unsigned long			nDataLength;						//������Ч����

		long					nFrameRate;							//֡��

		long					nBitRate;							//��ǰ���ʡ�

		long					nImageFormatId;						//��ǰ��ʽ

		long					nImageWidth;						//��Ƶ���

		long					nImageHeight;						//��Ƶ�߶�

		long					nVideoSystem;						//��ǰ��Ƶ��ʽ

		unsigned long			nFrameBufLen;						//��ǰ���峤��

		long					nStreamId;							// ��ID
		long					nTimezone;							// ʱ��
		long					nDaylightSavingTime;				//����ʱ

	}ST_AVFrameData;

	typedef struct _PACKED_1_ tagVideoInfo
	{
		unsigned long		nBitRate;								//������

		unsigned long		nBitErrorRate;

		unsigned long		nTimePerFrame;				

		unsigned long		nSize;

		unsigned long		nWidth;									//��Ƶ���

		unsigned long		nHeight;								//��Ƶ�߶�

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
		unsigned short		nFormatTag;			//��ʽ���

		unsigned short		nChannels;			//����ͨ������������

		unsigned long		nSamplesPerSec;		//ÿ�������

		unsigned long		nAvgBytesPerSec;	//

		unsigned short		nBlockAlign;		//

		unsigned short		nBitsPerSample;		//ÿ�β����Ĵ�С

		unsigned short		nCBSize;			//����׷�����ݳ���

		long				nEncodeType;

	}ST_AudioInfo;

	typedef struct _PACKED_1_ tagAlarmData 
	{
		long		nAlarmSourceId;											//����ԴID��

		char		szAlarmSourceName[CONST_MAXLENGTH_ALARMSOURCENAME + 1];	//����Դ����

		long		nAlarmTime;												//����ʱ��

		long		nAlarmType;												//��������

		long		nEventType;												//��������

		long		nAlarmCode;												//��������

		long		nAlarmFlag;												//������־��0������������1������������

	}ST_AlarmData;

	typedef struct _PACKED_1_ tagAlarmInfo
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//�豸id

		long			nDeviceType;											//�豸����

		char			szDeviceIp[CONST_MAXLENGTH_IP + 1];						//�豸IP��ַ

		ST_AlarmData	stAlarmData;											//��������

	}ST_AlarmInfo;

	typedef struct _PACKED_1_ tagAlarmInfoEx
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//�豸id

		long			nDeviceType;											//�豸����

		char			szDeviceIp[CONST_MAXLENGTH_IP + 1];						//�豸IP��ַ

		int				nMajorType;												//����������
		int				nMinorType;												//����������
		char			szSourceId[CONST_MAXLENGTH_ALARM_SOURCE_ID + 1];		//ԴID
		char			szSourceName[CONST_MAXLENGTH_ALARMSOURCENAME + 1];		//Դ����
		int				nAlarmFlag;												//����/������־,��1������������0������������
		unsigned long	nAlarmTime;												//ʱ��
		char			szDescription[CONST_MAXLENGTH_ALARM_DESCRIPTION + 1];	//����

	}ST_AlarmInfoEx;

	typedef struct _PACKED_1_ tagAlarmInfoExV2
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID];					//�豸id

		long			nDeviceType;											//�豸����

		char			szDeviceIp[CONST_MAXLENGTH_IP];							//�豸IP��ַ

		int				nMajorType;												//����������
		int				nMinorType;												//����������
		char			szSourceId[CONST_MAXLENGTH_ALARM_SOURCE_ID];			//ԴID
		char			szSourceName[CONST_MAXLENGTH_ALARMSOURCENAME];			//Դ����
		int				nAlarmFlag;												//����/������־,��1������������0������������
		ST_TimeStruct	stAlarmTime;											//����ʱ��
		char			szDescription[CONST_MAXLENGTH_ALARM_DESCRIPTION];		//����

	}ST_AlarmInfoExV2;

	//������Ϊ����
	typedef struct _PACKED_1_ tagAlarmActionStrategy
	{
		long					nAlarmActionStrategyNum;										//������Ϊ���Ը���
		long					stAlarmActionStrategy[CONST_MAX_ALARM_ACTION_STRATEGY];				//������Ϊ����

	}ST_AlarmActionStrategy;

	typedef struct _PACKED_1_ tagDeviceAccessParam
	{
		char			szLocalIp[CONST_MAXLENGTH_IP + 1];					//����IP��ַ

		unsigned short	nControlPort;										//������Ƶ�豸���豸������ƶ˿�
		unsigned short	nVideoTransferPort;									//������Ƶ�豸���豸��Ƶ����˿�
		unsigned short	nAudioTransferPort;									//������Ƶ�豸���豸��Ƶ����˿�
		unsigned short	nHttpPort;											//������Ƶ�豸���豸HTTP�˿�

	}ST_DeviceAccessParam;

	typedef struct _PACKED_1_ tagNetVideoDeviceInfo
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];			//�豸Ψһ��ʶ

		int				nDeviceType;										//�豸����

		char			szLocalIp[CONST_MAXLENGTH_IP + 1];					//����IP��ַ

		unsigned short	nControlPort;										//������Ƶ�豸���豸������ƶ˿�

		unsigned short	nHttpPort;											//������Ƶ�豸���豸HTTP�˿�

		char			szHardwareVer[CONST_MAXLENGTH_HARDWAREVERSION + 1];		//Ӳ���汾��Ϣ
		char			szSoftwareVer[CONST_MAXLENGTH_SOFTWAREVERSION + 1];		//����汾��Ϣ

		char			szManufacturerId[CONST_MAXLENGTH_MANUFACTURERID + 1];		//����ID
		char			szManufacturerName[CONST_MAXLENGTH_MANUFACTURERNAME + 1];	//��������


	}ST_NetVideoDeviceInfo;

	typedef struct _PACKED_1_ tagRecordDirInfo
	{
		int nDiskType;													//Ŀ¼��������
		char szDiskName[CONST_MAXLENGTH_FILE_NAME + 1];					//��������
		int nGroupId;													//��������������
		int nUsableSpace;												//���̿��ÿռ� ��λ��M
		int nFreeSpace;													//����ʣ��ռ� ��λ��M
		int nAttribute;													//����
		unsigned char bEnableFlag;										//���ñ�ʾ
		int nAlarmThreshold;											//������ֵ
		int nStatus;													//����״̬	
		int	nFileSystemFormat;											//�����ļ�ϵͳ��ʽ
	}ST_RecordDirInfo;

	typedef struct _PACKED_1_ tagRecordDirInfoList
	{
		ST_RecordDirInfo stRecordDirInfoList[CONST_MAX_DISK_NUM];			//������Ϣ�б�
		int				 nRecordDirInfoNum;									//���̸���
	}ST_RecordDirInfoList;

	typedef struct _PACKED_1_ tagRecordQueryCondition
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];	//�豸���
		char			szDeviceIP[CONST_MAXLENGTH_IP + 1];			//�豸IP
		int				nCameraId;									//�豸ͨ����
		unsigned long	nRecordBeginTime;							//¼��ο�ʼʱ��
		unsigned long	nRecordEndTime;								//¼��ν���ʱ��
		unsigned char			bIsLockFile;						//¼������ʶ
	}ST_RecordQueryCondition;

	typedef struct _PACKED_1_ tagRecordQueryResult
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];	//�豸���
		char			szDeviceIP[CONST_MAXLENGTH_IP + 1];			//�豸IP
		int				nCameraId;									//�豸ͨ����
		unsigned long	nRecordBeginTime;							//¼��ο�ʼʱ��
		unsigned long	nRecordEndTime;								//¼��ν���ʱ��
		unsigned char	bIsLockFile;								//¼������ʶ
		unsigned long	nQuerySegmentInterval;						//��ѯ�ֶμ��,�����ʱ���һ�Σ���λs��0:��ʾ���ֶ�
		int				nQueryTimePrecision;						//¼���ѯʱ�侫��
	}ST_RecordQueryResult;

	typedef struct _PACKED_1_ tagRecordQueryConditionV2
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];	//�豸���
		char			szDeviceIP[CONST_MAXLENGTH_IP + 1];			//�豸IP
		int				nCameraId;									//�豸ͨ����
		ST_TimeStruct	stRecordBeginTime;							//¼��ο�ʼʱ��
		ST_TimeStruct	stRecordEndTime;							//¼��ν���ʱ��
		unsigned char	bIsLockFile;								//¼������ʶ
		unsigned long	nQuerySegmentInterval;						//��ѯ�ֶμ��,�����ʱ���һ�Σ���λs��0:��ʾ���ֶ�
		int				nQueryTimePrecision;						//¼���ѯʱ�侫��
	}ST_RecordQueryConditionV2;

	typedef struct _PACKED_1_ tagRecordQueryResultV2
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];	//�豸���
		char			szDeviceIP[CONST_MAXLENGTH_IP + 1];			//�豸IP
		int				nCameraId;									//�豸ͨ����
		ST_TimeStruct	stRecordBeginTime;							//¼��ο�ʼʱ��
		ST_TimeStruct	stRecordEndTime;								//¼��ν���ʱ��
		unsigned char	bIsLockFile;								//¼������ʶ
	}ST_RecordQueryResultV2;

	typedef struct _PACKED_1_ tagRecordInfo
	{
		char					szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];	//�豸���
		char					szDeviceIP[CONST_MAXLENGTH_IP + 1];			//�豸IP
		int						nCameraId;									//�豸ͨ����
		unsigned long			nRecordBeginTime;							//¼��ο�ʼʱ��
		unsigned long			nRecordEndTime;								//¼��ν���ʱ��
		unsigned char			bIsLockFile;								//¼������ʶ
	}ST_RecordInfo;

	typedef struct _PACKED_1_ tagRecordInfoV2
	{
		char					szDeviceId[CONST_MAXLENGTH_DEVICEID];		//�豸���
		char					szDeviceIP[CONST_MAXLENGTH_IP];				//�豸IP
		int						nCameraId;									//�豸ͨ����
		ST_TimeStruct			stRecordBeginTime;							//¼��ο�ʼʱ��
		ST_TimeStruct			stRecordEndTime;							//¼��ν���ʱ��
		unsigned char			bIsLockFile;								//¼������ʶ
		bool					bIsAlarm;									//�ļ��Ƿ񱨾�
	}ST_RecordInfoV2;

	//�����ò���
	typedef struct _PACKED_1_ tagAVStreamParam
	{
		int				nCameraId;												//�����ID
		int				nStreamId;												//����ID
		char			szStreamName[CONST_MAXLENGTH_AVSREAM_NAME + 1];				//������
		int				nVideoHeight;											//�߶�
		int				nVideoWidth;											//���
		int				nFrameRate;												//֡��
		int				nBitRateType;											//��������
		int				nBitRate;												//����
		int				nQuality;												//��Ƶ����ֵ
		int				nIFrameInterval;										//I֡����
		int				nIFrameIntervalUnit;									//I֡��λ
		int				nVideoEncoderType;										//��Ƶ�������͡�����ɲ鿴ENUM_EncoderTypeö�ٶ���
		int				nAudioEncoderType;										//��Ƶ�������͡�����ɲ鿴ENUM_EncoderTypeö�ٶ���
	}ST_AVStreamParam;

	//�����ò���
	typedef struct _PACKED_1_ tagAllAVStreamParam
	{
		int						nStreamNum;

		ST_AVStreamParam		stAVStreamParamList[CONST_MAX_STREAM_NUM];

	}ST_AllAVStreamParam;

	
	//�����¼�
	typedef struct _PACKED_1_ tagAlarmEvent
	{
		int nAlarmType;

		int nAlarmId;

	}ST_AlarmEvent;

	//����¼�����
	typedef struct _PACKED_1_ tagAlarmRecordPolicy
	{
		int								nAlarmPreRecordTime;

		int								nAlarmDelayRecordTime;

		unsigned char					bIsAlarmRecordFileLocked;

		unsigned char					bIsAlarmRecordOpened;

		int								nAlarmEventNum;

		ST_AlarmEvent					stAlarmEventList[CONST_MAX_ALARM_EVENT_NUM];

	}ST_AlarmRecordPolicy;

	//�ƻ�¼�����
	typedef struct _PACKED_1_ tagScheduleRecordPolicy
	{
		unsigned char					bIsScheduleRecordOpened;

		int								nScheduleRecordType;

		ST_ScheduleTimeParam			stScheduleTimeParam;

	}ST_ScheduleRecordPolicy;

	//¼�����
	typedef struct _PACKED_1_ tagRecordPolicyParam
	{
		int								nCameraId;				//��������

		int								nSaveDays;				//��������

		unsigned char					bCycleWriteFlag;		//ѭ��д��־

		unsigned char					bIsRedundancy;			//�Ƿ�����

		int								nDiskGroupId;			//�洢����ID

		int								nStreamId;				//����ID

		unsigned char					bIsRecordAudioOpened;	//�Ƿ�¼����Ƶ

		ST_AlarmRecordPolicy			stAlarmRecordPolicy;	//����¼�Ʋ���

		ST_ScheduleRecordPolicy			stScheduleRecordPolicy;	//�ƻ�¼�����

	}ST_RecordPolicyParam;

	//���е�¼����Բ���
	typedef struct _PACKED_1_ tagAllRecordPolicyParam
	{
		int								nRecordPolicyNum;

		ST_RecordPolicyParam			stRecordPolicyParam[CONST_MAX_CAMERA_NUM];
		
	}ST_AllRecordPolicyParam;

////////////////////////////////////////////////////////////////

	//�������
	typedef struct _PACKED_1_ tagColorParam
	{
		unsigned long		nRed;						//��ɫֵ��0-255��
		unsigned long		nGreen;						//��ɫֵ��0-255��
		unsigned long		nBlue;						//��ɫֵ��0-255��
		unsigned long		nAlpha;						//͸���ȣ�0-100�����˲���Ԥ��

	}ST_ColorParam;

	//�������
	typedef struct _PACKED_1_ tagAreaParam
	{
		long		nTopX;								//�������Ͻ� x ������ռ����Ƶ����ȵİٷֱ�
		long		nTopY;								//�������Ͻ� y ������ռ����Ƶ���߶ȵİٷֱ�
		long		nWidth;								//������ռ��Ƶ���ܿ�ȵİٷֱ�
		long		nHeight;							//����߶�ռ����Ƶ���߶ȵİٷֱ�

	}ST_AreaParam;

	//�豸��˽�ڱβ���
	typedef struct _PACKED_1_ tagBlindAreaParam
	{
		long					nCameraId;											//�����ID��

		unsigned char			bEnableFlag;										//�Ƿ������ڱΣ�1�����ã�0�������ã�
		
		ST_ColorParam			stColorParam;										//��ɫ
		
		long					nAreaParamNum;										//���������Ŀ
		ST_AreaParam			stAreaParamList[CONST_MAX_AREA_NUM];				//�ƶ��������

	}ST_BlindAreaParam;

	//�豸������˽�ڱβ���
	typedef struct _PACKED_1_ tagAllBlindAreaParam
	{
		long						nBlindAreaParamNum;									//��˽�ڱβ�����Ŀ
	
		ST_BlindAreaParam			stBlindAreaParamList[CONST_MAX_CAMERA_NUM];				//��˽�ڱβ����б�

	}ST_AllBlindAreaParam;

	//�豸������Ϣ
	typedef struct _PACKED_1_ tagDeviceBaseInfo
	{
		char				szDeviceId[CONST_MAXLENGTH_DEVICEID];								//�豸Ψһ��ʶ
		char				szDeviceName[CONST_MAXLENGTH_DEVICENAME];							//�豸����
		int					nDeviceType;														//�豸����

		char				szDeviceIP[CONST_MAXLENGTH_IP];										//�豸IP��ַ
		unsigned short		nDevicePort;														//�豸�˿�
		int					nIPProtoVer;														//IPЭ������
		char				szUserID[CONST_MAXLENGTH_USERID];									//��½�豸���û�ID
		char				szPassword[CONST_MAXLENGTH_PASSWORD];								//��½�豸������

		char				szManufacturerId[CONST_MAXLENGTH_MANUFACTURERID];					//�豸�ͺ�
		char				szManufacturerName[CONST_MAXLENGTH_MANUFACTURERNAME];				//�豸��������
		char				szProductModel[CONST_MAXLENGTH_PRODUCTMODEL];						//��Ʒģ��
		char				szProductDescription[CONST_MAXLENGTH_PRODUCTDESCRIPTION];			//��Ʒ����
		char				szHardwareModel[CONST_MAXLENGTH_HARDWAREMODEL];						//Ӳ��ģ��
		char				szHardwareDescription[CONST_MAXLENGTH_HARDWAREDESCRIPTION];			//Ӳ������
		char				szMACAddress[CONST_MAXLENGTH_MACADDRESS];							//MAC��ַ
		char				szBarCode[CONST_MAXLENGTH_BARCODE];									//����������
		char				szProductionTime[CONST_MAXLENGTH_PRODUCTIONTIME];					//����ʱ��
		
		char				szHardwareVer[CONST_MAXLENGTH_HARDWAREVERSION_EXPAND];				//�汾��Ϣ
		char				szSoftwareVer[CONST_MAXLENGTH_SOFTWAREVERSION_EXPAND];


		int					nCameraNum;																//ͨ���������������
		int					nAlarmInNum;															//�����������
		int					nAlarmOutNum;															//�����������
		int					nRS485Num;																//RS485���ڸ���

		ST_CameraInfoParam	stWebCameraInfoParamList[CONST_MAX_CAMERA_NUM];							//����ͷ��Ϣ

	}ST_DeviceBaseInfo;

	//�豸������Ϣ�б�
	typedef struct _PACKED_1_ tagDeviceBaseInfoList
	{
		int					nDeviceBaseInfoNum;													//�豸��

		ST_DeviceBaseInfo	stDeviceBaseInfoList[CONST_MAX_NVR_DEVICE_NUM];							//�豸�б�

	}ST_DeviceBaseInfoList;

	//�豸״̬��Ϣ
	typedef struct _PACKED_1_ tagDeviceStateInfo
	{
		char				szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];							//�豸Ψһ��ʶ

		int					nDeviceType;														//�豸����

		long				nLastActiveTime;													//���ʱ�䣬��ȷ����

		unsigned char		btOnlineState;														//����״̬��0�������ߣ�1�����ߣ�

		ST_InetAddr			stInetAddr;															//�豸�������ַ

		int					m_nSearchMode;														//���߸��·�ʽ��1���㲥��2������������3����������

	}ST_DeviceStateInfo;


	//�ⲿ�ӿ�
	typedef struct _PACKED_1_ tagExternInterface
	{
		int					nInterfaceType;
		ST_RS485Param		stRS485Device;

	}ST_ExternInterface;

	//PTZ���̲���
	typedef struct _PACKED_1_ tagPTZKeyboardParam
	{
		unsigned char		bEnableFlag; //�Ƿ�������̨����(1��������0��������)

		ST_ExternInterface	stExternInterface;

	}ST_PTZKeyboardParam;

	//�㳮������
	typedef struct _PACKED_1_ tagCashRegistersParam
	{
		unsigned char		bEnableFlag;	//�Ƿ������㳮��(1��������0��������)
		int					nOSDTopX;		//��
		int					nOSDTopY;		//��
		int					nOSDLanguage;	//����
		int					nModel;			//ģʽ

		int					nOSDCameraIDList[CONST_MAX_CAMERA_NUM]; //ͨ��ID
		int					nCameraNum;								//ͨ����

		ST_ExternInterface stExternInterface;					//�ⲿ�ӿ�

	}ST_CashRegistersParam;


	//�㳮������
	typedef struct _PACKED_1_ tagTimeZoneParam
	{
		int				nTimeZone;												//ʱ��

		bool			bDSTOpenFlag;											//����ʱ������־
		int				nDSTOffset;												//����ʱƫ�ƣ�����Ϊ��λ

		int				nBeginMonth;											//����ʱ��ʼ�·�
		int				nBeginWeekly;											//����ʱ��ʼ�ܣ�һ���еĵڼ��ܣ�
		int				nBeginWeekDays;											//���ڼ�
		unsigned int	nBeginTime;												//��ʼʱ��

		int				nEndMonth;												//����ʱ�����·�
		int				nEndWeekly;												//����ʱ�����ܣ�һ���еĵڼ��ܣ�
		int				nEndWeekDays;											//���ڼ�
		unsigned int	nEndTime;												//����ʱ��

	}ST_TimeZoneParam;

	//���ղ���
	typedef struct _PACKED_1_ tagRemoteSnapshotParam
	{
		int				nCameraID;													//ͨ����
		int				nQuality;													//����
		int				nPhotoFormat;												//ͼ���ʽ

	}ST_RemoteSnapshotParam;

	//�����б�
	typedef struct _PACKED_1_ tagRetainTypeList
	{
		int					nRetainTypeNum;										//������Ϊ���Ը���
		int					nRetainTypeList[CONST_MAX_RETAIN_TYPE];				//������Ϊ����

	}ST_RetainTypeList;


	//�������
	typedef struct _PACKED_1_ tagNetworkParam
	{
		int				nNetworkCardId;									//���ڱ��
		int				nWorkingType;									//�������ͣ�1.�������� 2.��������� 3.��
		int				nIPProtoVer;									//IPЭ������
		bool			bAutoGetIpFlag;									//�Զ���ȡIP��ַ(true���Զ���ȡ��false�����Զ���ȡ)
		char			szDhcpIp[CONST_MAXLENGTH_IP];					//DHCP IP
		char			szLocalIp[CONST_MAXLENGTH_IP];					//����IP��ַ
		char			szLocalSubnetMask[CONST_MAXLENGTH_IP];			//��������
		char			szGateway[CONST_MAXLENGTH_IP];					//����
		bool			bAutoGetDNSFlag;								//�Զ���ȡDNS������IP��ַ(true���Զ���ȡ��false�����Զ���ȡ)
		char			szPrimaryDNSIp[CONST_MAXLENGTH_IP];				//��ѡDNS������IP��ַ
		char			szSpareDNSIp[CONST_MAXLENGTH_IP];				//����DNS������IP��ַ
	}ST_NetworkParam;
	
	//��������б�
	typedef struct _PACKED_1_ tagNetworkParamList
	{
		int							nNetworkParamNum;									//�����������
		ST_NetworkParam				stNetworkParam[CONST_MAX_NETWORK_CARD_NUM];		//��������б�
	}ST_NetworkParamList;


	//������ѯ����
	typedef struct _PACKED_1_ tagAlarmInfoExQueryParam
	{
			char				szDeviceId[CONST_MAXLENGTH_DEVICEID];				//�豸���
			char				szDeviceIP[CONST_MAXLENGTH_IP];						//�豸IP��ַ
			char				szSourceId[CONST_MAXLENGTH_ALARM_SOURCE_ID];		//����ԴId
			char				szSourceName[CONST_MAXLENGTH_ALARMSOURCENAME];		//Դ����
			int					nMajorType;											//����������
			int					nMinorType;											//����������
			ST_TimeStruct		stAlarmBeginTime;									//��ʼʱ��
			ST_TimeStruct		stAlarmEndTime;										//����ʱ��

	}ST_AlarmInfoExQueryParam;

	//������¼����
	typedef struct _PACKED_1_ tagAlarmInfoExRecordSet
	{
		char			szDeviceId[CONST_MAXLENGTH_DEVICEID];					//�豸ID
		char			szDeviceIP[CONST_MAXLENGTH_IP];							//�豸IP
		char			szSourceId[CONST_MAXLENGTH_ALARM_SOURCE_ID];			//����ԴID
		char			szSourceName[CONST_MAXLENGTH_ALARMSOURCENAME];			//Դ����
		char			szDescription[CONST_MAXLENGTH_ALARM_DESCRIPTION];		//����
		int				nDeviceType;											//�豸����
		int				nMajorType;												//����������
		int				nMinorType;												//����С����

		ST_TimeStruct	stAlarmBeginTime;										//������ʼʱ��
		ST_TimeStruct	stAlarmEndTime;											//��������ʱ��

	}ST_AlarmInfoExRecordSet;


	//ʵʱ��Ƶͨ������
	typedef struct _PACKED_1_ tagLiveVideoChannel
	{
		char szDeviceID[CONST_MAXLENGTH_DEVICEID];	//�豸ID
		int  nChannelID;							//ͨ��ID

	}ST_LiveVideoChannel;

	//���ִ��ڲ���
	typedef struct _PACKED_1_ tagLayoutWindow
	{
		int					nWinId;
		int					nLiveVideoChannelNum;
		ST_LiveVideoChannel stLiveVideoChannelList[CONST_MAX_LIVE_VIDEO_CHANNEL_NUM];

	}ST_LayoutWindow;

	//ʵʱ��Ƶ���ֲ���
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

	//ʵʱ��Ƶ���ֲ����б�
	typedef struct _PACKED_1_ tagLiveVideoLayoutList
	{
		int					nLiveVideoLayoutNum;
		ST_LiveVideoLayout	stLiveVideoLayoutList[CONST_MAX_LIVE_VIDEO_LAYOUT_NUM];	//

	}ST_LiveVideoLayoutList;

	//�豸������
	typedef struct _PACKED_1_ tagDeviceAVStreamParam
	{
		char						szDeviceId[CONST_MAXLENGTH_UUID];	
		int							nAVStreamParamNum;
		ST_AVStreamParam			stAVStreamParamList[CONST_MAX_AV_STREAM_NUM];

	}ST_DeviceAVStreamParam;

	//�豸�������б�
	typedef struct _PACKED_1_ tagDeviceAVStreamParamList
	{
		int							nDeviceAVStreamParamNum;
		ST_DeviceAVStreamParam		stDeviceAVStreamParamList[CONST_MAX_DEVICE_AV_STREAM_PARAM_NUM];

	}ST_DeviceAVStreamParamList;

	//¼��״̬����
	typedef struct _PACKED_1_ tagRecordState
	{
		char	szDeviceId[CONST_MAXLENGTH_DEVICEID];			//�豸ID
		int		nCameraId;										//�����ID
		int		nState;											//¼��״̬

	}ST_RecordState;

	//¼��״̬�����б�
	typedef struct _PACKED_1_ tagRecordStateList
	{
		int					nRecordStateNum;								//¼��״̬����
		ST_RecordState		stRecordStateList[CONST_MAX_RECORD_STATE_NUM];  //¼��״̬

	}ST_RecordStateList;

	//����������
	typedef struct _PACKED_1_ tagMonitorParam
	{
		int		nMonitorId;			//������ID
		int		nMonitorType;		//����������

	}ST_MonitorParam;

	//����������
	typedef struct _PACKED_1_ tagMonitorParamList
	{
		int					nMonitorParamNum;			//����������
		ST_MonitorParam		stMonitorParamList[CONST_MAX_MONITOR_NUM];		//�������б�

	}ST_MonitorParamList;

	//Bonjour���ò���
	typedef struct _PACKED_1_ tagBonjourServiceParam
	{
		bool	bBonjourEnableFlag;								//����bonjour��ʶ(true�����ã�false��������)

	}ST_BonjourServiceParam;

	//Bonjour���ò���
	typedef struct _PACKED_1_ tagUpnpServiceParam
	{
		bool	bUpnpEnableFlag;								//����Upnp��ʶ(true�����ã�false��������)

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
		bool			bEnableFlag;								//�Ƿ�����Wifi
		char			szSSID[CONST_MAXLENGTH_SSID+1];				//SSID
		char			szPassword[CONST_MAXLENGTH_USERPASSWORD+1];	//����

		bool			bUseDynamicIPFlag;							//�Ƿ����ö�̬IP
		char			szStaticIP[CONST_MAXLENGTH_IP + 1];			//��̬IP��ַ
		char			szSubnetMask[CONST_MAXLENGTH_IP + 1];		//��������
		char			szGateway[CONST_MAXLENGTH_IP + 1];			//����
		char			szDNS[CONST_MAXLENGTH_IP + 1];				//DNS������IP��ַ
	}ST_WifiParam;

	typedef struct _PACKED_1_ tagWifiStateParam
	{
		int		nConnectState;									//����״̬
		int		nSignalQuality;									//�ź�״̬
	}ST_WifiStateParam;


	typedef struct _PACKED_1_ tagWifiAbilityParam
	{
		bool	bSupportFlag;														//�Ƿ�֧�ֱ�־
		char	szWifiDeviceName[CONST_MAXLENGTH_WIFI_DEVICE_NAME+1];				//Wifi�豸��
	}ST_WifiAbilityParam;


	typedef struct _PACKED_1_ tagWifiNetworkParam
	{
		char	szIP[CONST_MAXLENGTH_IP + 1];				//IP��ַ
		char	szSubnetMask[CONST_MAXLENGTH_IP + 1];		//��������
		char	szGateway[CONST_MAXLENGTH_IP + 1];			//����

		char	szPrimaryDNS[CONST_MAXLENGTH_IP + 1];		//��ѡDNS������IP��ַ
		char	szSpareDNS[CONST_MAXLENGTH_IP + 1];			//����DNS������IP��ַ
	}ST_WifiNetworkParam;

	typedef struct _PACKED_1_ tagSVCStreamParam
	{
		int		nSourceStreamID;		//ԭ��ID
		int		nSVCStreamID;			//������ID
		int		nFrameSkipInterval;   //p֡��֡���
		char	szStreamName[CONST_MAXLENGTH_AVSREAM_NAME + 1];		//��������
	}ST_SVCStreamParam;

	//PTZ
	typedef struct _PACKED_1_ tagPTZPreset
	{
		int		nCameraId;													//����ͷID��
		int		nPresetId;													//��̨Ԥ�Ƶ��ID��
		char	szPresetName[CONST_MAXLENGTH_PTZ_PRESET_NAME + 1];			//��̨Ԥ�Ƶ������

	}ST_PTZPreset;

	typedef struct _PACKED_1_ tagPTZPresetList
	{
		int nPTZPresetCount;
		ST_PTZPreset  stPTZPreset[CONST_MAX_PTZ_PRESET_NUM];
	}ST_PTZPresetList;

	typedef struct _PACKED_1_ tagPTZTourPoint
	{
		int nTourPointID;		//�켣Ԥ�õ�id
		int nWaiteTime;		//�ȴ�ʱ��
		int nSpeed;			//�ٶ�
	}ST_PTZTourPoint;

	typedef struct _PACKED_1_ tagPTZTourPointList
	{
		int nPTZTourPointCount;
		ST_PTZTourPoint stPTZTourPoint[CONST_MAX_PTZ_TOURPOINT_NUM];

	}ST_PTZTourPointList;

	typedef struct _PACKED_1_ tagPTZTourEx
	{
		int		nTourID;																//�켣���
		char	szTourName[CONST_MAXLENGTH_PTZ_TOUR_NAME + 1];							//��̨Ѳ�ε�����

		int		nPTZTourPointCount;
		ST_PTZTourPoint	stPTZTourPointList[CONST_MAX_PTZ_TOURPOINT_NUM];			//��ɹ켣��Ԥ�õ㼯��
	}ST_PTZTourEx;

	typedef struct _PACKED_1_ tagPTZTourExList
	{
		int nPTZTourExCount;
		ST_PTZTourEx  stPTZTourPointList[CONST_MAX_PTZ_TOURPOINT_NUM];
	}ST_PTZTourExList;

	typedef struct _PACKED_1_ tagPTZScan
	{
		int		nCameraId;												//����ͷID��
		int		nScanId;													//��̨ɨ���ID��
		char	szScanName[CONST_MAXLENGTH_PTZ_SCAN_NAME + 1];			//��̨ɨ�������
	}ST_PTZScan;

	typedef struct _PACKED_1_ tagPTZScanList
	{
		int nPTZScanNum;
		ST_PTZScan	stPTZScanList[CONST_MAX_PTZ_SCAN_NUM];									//��̨ɨ�������
	}ST_PTZScanList;

	//�켣
	typedef struct _PACKED_1_ tagPTZTrack
	{
		int		nCameraId;												//����ͷID��
		int		nTrackId;												//��̨Ԥ�Ƶ��ID��
		char	szTrackName[CONST_MAXLENGTH_PTZ_TRACK_NAME + 1];		//��̨Ԥ�Ƶ������
	}ST_PTZTrack;
	
	typedef struct _PACKED_1_ tagPTZTrackList
	{
		int nPTZTrackNum;
		ST_PTZTrack  stPTZTrackList[CONST_MAX_PTZ_TRACK_NUM];

	}ST_PTZTrackList;

	typedef struct _PACKED_1_ tagSensorAbility
	{
		int nSensorControllerOpenType;	     //ǰ�����ô����ͣ��������SensorControllerOpenType
	}ST_SensorAbility;

	typedef struct _PACKED_1_ tagOSDTimeFormatType
	{
		int nFormatId;
		char szDescription[CONST_OSD_TIMEFORMAT_DESCRIPTION + 1];		//OSDʱ���ʽ

	}ST_OSDTimeFormatType;

	typedef struct _PACKED_1_ tagOSDFormatAbility
	{
		int nOSDTimeFormatTypeNum;
		ST_OSDTimeFormatType stOSDTimeFormatTypeList[CONST_MAX_OSD_TIME_FORMAT_TYPE_NUM];
	}ST_OSDFormatAbility;


	typedef struct _PACKED_1_ tagNetworkAlarmEvent
	{
		int								nNetworkCardId;			//��������ID��
		bool							bAlarmEnableFlag;		//�Ƿ���������(false���������� true������)
		long							nAlarmOutActionNum;																//��������¼�����
		ST_AlarmOutActionParam			stAlarmOutActionParam[CONST_MAX_ALARM_OUT_NUM];									//��������¼�
		long							nAlarmPTZActionNum;																//������̨�¼�����
		ST_AlarmPTZActionParam			stAlarmPTZActionParam[CONST_MAX_CAMERA_NUM];									//������̨�¼�

	}ST_NetworkAlarmEvent;

	typedef struct _PACKED_1_ tagNetworkAlarmEventList
	{
		int                         nNetworkAlarmEventCount;
		ST_NetworkAlarmEvent        stNetworkAlarmEvent[CONST_MAX_CAMERA_NUM];
	}ST_NetworkAlarmEventList;
	
	typedef struct _PACKED_1_ tagNetworkAlarmParam
	{
		unsigned int					nInterval;					//�ϱ��������λΪ�룬��С���Ϊ10�룬���Ϊ86400��(1��)
		ST_NetworkAlarmEventList		stNetworkAlarmEventList;		//�������籨���¼��б�
	}ST_NetworkAlarmParam;

	typedef struct _PACKED_1_ tagPTZTimerTimeSegment
	{
		unsigned long	nBeginTime;									//��ʼʱ�䣬��00:00��ʼ����ǰʱ�����������01:30Ϊ5400
		unsigned long	nEndTime;										//����ʱ�䣬��00:00��ʼ����ǰʱ�����������01:30Ϊ5400
		char			szPTZOperation[CONST_MAXLENTH_PTZ_CMD + 1];	//��̨��������

	}ST_PTZTimerTimeSegment;

	typedef struct _PACKED_1_ tagPTZTimerTimeSegmentList
	{
		int nPTZTimerTimeSegmentCount;
		ST_PTZTimerTimeSegment  stPTZTimerTimeSegment[CONST_MAX_PTZ_TIME_RTIMESEGMENT_NUM];
	}ST_PTZTimerTimeSegmentList;

	typedef struct _PACKED_1_ tagPTZTimer
	{
		bool								bEnableFlag;					//�Ƿ�����
		int									nCameraId;						//����ͷID��
		int									nTimerMode;						//ʱ��ģʽ��ΪTIMER_MODEö��֮һ
		ST_TimeStruct						stTimeStruct;					//����һ��ʱ��ģʽʱ��ʱ������
		ST_PTZTimerTimeSegmentList			stPTZTimerTimeSegmentList;		//��ʱ��ʱ����б�
	}ST_PTZTimer;

	typedef struct _PACKED_1_ tagPTZTimerList
	{
		int			nPTZTimerCount;
		ST_PTZTimer  stPTZTimerList[CONST_MAX_PTZ_TIME_RTIMESEGMENT_NUM];
	}ST_PTZTimerList;

	typedef struct _PACKED_1_ tagMTUParam
	{
		int		nMTUValue;//MTUֵ
	}ST_MTUParam;

	typedef struct _PACKED_1_ tagRGBColor
	{
		int nRed;
		int nGreen;
		int nBlue;
	}ST_RGBColor;

	typedef struct _PACKED_1_ tagMosaicParam
	{
		unsigned int		nWidth;								//��
		unsigned int		nHeight;							//��
	}ST_MosaicParam;

	typedef struct _PACKED_1_ tagBlindAbilityV2
	{
		int nMaxBlindAreaNum;	     //֧�������ڵ�������Ŀ
		int nBlindAreaRate;			//�ڵ��������ռԴ�ֱ��ʰٷֱ�

		int nTypeNum;
		int szTypeList[CONST_MAX_BLINDABILITYV2_TYPE];			//֧�ֵ���˽�ڱ������б�
 
		int nAlphaNum;
		int szAlphaList[CONST_MAX_BLINDABILITYV2_ALPHA];			//֧�ֵ�͸�����б�

		int nRGBColorNum;
		ST_RGBColor stRGBColor[CONST_MAX_BLINDABILITYV2_RGBCOLOR];	//��ɫ֧���б�
	
		int nMosaicParamNum;
		ST_MosaicParam stMosaicParam[CONST_MAX_BLINDABILITYV2_MOSAICPARAM];//֧�ֵ������˴�С�б�
	}ST_BlindAbilityV2;

	typedef struct _PACKED_1_ tagLibCommonAbility
	{
		int		nLibId;                    //��ID
		bool	bEnable;                   //ID���Ƿ�����

		int		nResolutionWidth;          //Ҫ���Դ�ֱ���
		int		nResolutionHeight;         //Ҫ���Դ�ֱ���

		int		nTotalAnalyseRegionNum;    //�ÿ�֧�ֵķ������ܸ���
		int		nMaxEnableFunsNum;         //�ÿ����ͬʱ�����Ĺ���

	}ST_LibCommonAbility;


	typedef struct _PACKED_1_ tagMotionDetectionAbilityV2
	{
		int  nLibId;					//���ܿ�ID
		bool bCellEnable;				//�Ƿ�֧�ָ�������
		int  nCellHeightCellNumber;	//�ƶ���ⷽ��ĸߵĿ���
		int	 nCellWidthCellNumber;		//�ƶ���ⷽ��Ŀ�Ŀ���
		bool bEnable;					//�Ƿ�֧�ָ�������  todo
		bool bSensitivityEnable;		//�Ƿ�֧�����ø�������
		int  nSensitivityMax;			//��֧�����õ������ȵ����ֵ
		int  nSensitivityMin;			//��֧�����õ������ȵ���Сֵ

	}ST_MotionDetectionAbilityV2;

	typedef struct _PACKED_1_ tagPerimeterAbility
	{
		int		nLibId;							//���ܿ�ID
		bool	bDetailGetEnable;				//�Ƿ�֧�ָ�����
		int		nEdgeNum;							//�����������
		bool	bEnable;							//�Ƿ�֧�ָ�������
		int		nMaxRegionNum;					//���֧�ֵķ����������
		bool	bMaxTargetSizeEnable;			//��Ʒ�ƶ���ObjMove�������Ƿ�֧��		
		int		nMaxTargetSizeMax;				//���֧�ֵķ����������
		int		nMaxTargetSizeMin;				//Ŀ�����ߴ����Сֵ
		char	szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//Ŀ�����ߴ�ĵ�λ	//TODO
		bool	bMinTargetSizeEnable;			//�Ƿ�֧��Ŀ����С�ߴ�
		int		nMinTargetSizeMax;				//Ŀ�����ߴ�����ֵ
		int		nMinTargetSizeMin;				//Ŀ�����ߴ����Сֵ
		char    szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//Ŀ����С�ߴ�ĵ�λ	//TODO
		bool	bRegionEnable;					//�������������Ƿ�֧��
		bool	bSensitivityEnable;				//�Ƿ�֧�������ȵ�����
		int		nSensitivityMax;					//��֧�����õ������ȵ����ֵ
		int		nSensitivityMin;					//��֧�����õ������ȵ���Сֵ
		bool	bTargetSizeConstrainEnable;		//�Ƿ��޶�Ŀ���С��������֧�����
		int		nTargetSizeConstrainMax;			//�޶�Ŀ���С�����ֵ
		int		nTargetSizeConstrainMin;			//�޶�Ŀ���С����Сֵ
		char    szTargetSizeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];//�޶�Ŀ���С�ĵ�λ
		bool	bTargetTypeConstrainEnable;		 //�޶�Ŀ�����͵�������֧�����
		int		nTargetTypeConstrainMax;			 //Ŀ�����͵����ߴ�
		int		nTargetTypeConstrainMin;			 // Ŀ�����͵���С�ߴ�
		char   szTargetTypeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];//Ŀ�����ͳߴ�ĵ�λ	//TODO
		bool	bTargetTypeEnable;				 //�޶�����������֧�����
		int		nTargetTypeMax;					 //�޶����͵ĳߴ�����ֵ
		int		nTargetTypeMin;					 //�޶����͵ĳߴ����Сֵ
		char    szTargetTypeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		 //�޶����͵ĳߴ�ĵ�λ //TODO

	}ST_PerimeterAbility;

	typedef struct _PACKED_1_ tagTripWireAbility
	{
		int		nLibId;							//���ܿ�ID
		bool	bRegionEnable;					//�Ƿ�֧�ָ�������
		int		nEdgeNum;							//�����������
		int		nMaxRegionNum;					//���֧�ֵķ����������
		bool	bBidirectionEnable;				//�Ƿ�֧�ָ�������
		bool	bDetailGetEnable;				//��ȡ��ϸ��Ϣ�������Ƿ�֧��
		bool	bEnable;							//���ߣ�TripWire�������Ƿ�֧��
		bool	bMaxTargetSizeEnable;			//�Ƿ�֧��Ŀ�����ߴ�
		int		nMaxTargetSizeMax;				//Ŀ�����ߴ�����ֵ
		int		nMaxTargetSizeMin;				//Ŀ�����ߴ����Сֵ
		char    szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN+1];		//Ŀ�����ߴ�ĵ�λ		//TODO
		bool	bMinTargetSizeEnable;			//�Ƿ�֧��Ŀ����С�ߴ�
		int		nMinTargetSizeMax;				//Ŀ����С�ߴ�����ֵ
		int		nMinTargetSizeMin;				//Ŀ����С�ߴ����Сֵ
		char    szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN+1];		//Ŀ����С�ߴ�ĵ�λ		//TODO
		bool	bTargetSizeConstrainEnable;		//�޶�Ŀ���С��������֧�����
		int		nTargetSizeConstrainMax;			//�޶�Ŀ���С�����ֵ
		int		nTargetSizeConstrainMin;			//�޶�Ŀ���С����Сֵ
		char   szTargetSizeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN+1]; //�޶�Ŀ���С�ĵ�λ		//TODO
		bool	bTargetTypeConstrainEnable;		//�޶�Ŀ�����͵�������֧�����
		int		nTargetTypeConstrainMax;			//Ŀ�����͵����ߴ�
		int		nTargetTypeConstrainMin;			//Ŀ�����͵���С�ߴ�
		char   szTargetTypeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN+1];//Ŀ�����ͳߴ�ĵ�λ		//TODO
		bool	bTargetTypeEnable;				//�޶�����������֧�����
		int		nTargetTypeMax;					//�޶����͵ĳߴ�����ֵ
		int		nTargetTypeMin;					//�޶����͵ĳߴ����Сֵ
		char   szTargetTypeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN+1];		//�޶����͵ĳߴ�ĵ�λ		//TODO
		bool	bTriggerDirectionEnable;			//�Ƿ�֧��˫���ߵĴ����������õĹ���

	}ST_TripWireAbility;

	typedef struct _PACKED_1_ tagMultiTripWireAbility
	{
		int		nLibId;							//���ܿ�ID
		bool	bRegionEnable;					//�������������Ƿ�֧��
		int		nEdgeNum;						//֧�ֵķ����������
		int		nMaxRegionNum;					//���֧�ֵķ����������	
		bool	bDetailGetEnable;				//�Ƿ��ȡ��ϸ��Ϣ�������Ƿ�֧��
		bool	bEnable;						//˫���ߣ�MultiTripWire�������Ƿ�֧��
		bool	bMaxTargetSizeEnable;			//�Ƿ�֧��Ŀ�����ߴ�
		int		nMaxTargetSizeMax;				//Ŀ�����ߴ�����ֵ
		int		nMaxTargetSizeMin;				//Ŀ�����ߴ����Сֵ
		char    szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//Ŀ�����ߴ�ĵ�λ
		bool	bMinTargetSizeEnable;			//�Ƿ�֧��Ŀ����С�ߴ�
		int		nMinTargetSizeMax;				//Ŀ����С�ߴ�����ֵ
		int		nMinTargetSizeMin;				//Ŀ����С�ߴ����Сֵ
		char    szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//Ŀ����С�ߴ�ĵ�λ
		bool	bTargetSizeConstrainEnable;		//�Ƿ��޶�Ŀ���С��������֧�����
		int		nTargetSizeConstrainMax;		//�޶�Ŀ���С�����ֵ
		int		nTargetSizeConstrainMin;		//�޶�Ŀ���С����Сֵ
		char   szTargetSizeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];//�޶�Ŀ���С�ĵ�λ
		bool	bTargetTypeConstrainEnable;		 //�޶�Ŀ�����͵�������֧�����
		int		nTargetTypeConstrainMax;		 //Ŀ�����͵����ߴ�
		int		nTargetTypeConstrainMin;		 //Ŀ�����͵���С�ߴ�
		char   szTargetTypeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];//Ŀ�����ͳߴ�ĵ�λ
		bool	bTargetTypeEnable;				//�޶�����������֧�����
		int		nTargetTypeMax;					//�޶����͵ĳߴ�����ֵ
		int		nTargetTypeMin;					//�޶����͵ĳߴ����Сֵ
		char	szTargetTypeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//�޶����͵ĳߴ�ĵ�λ
		bool	bTimeIntervalEnable;			//�Ƿ�֧��˫���ߵ�ʱ�����Ĺ���
		int		nTimeIntervalMin;				//˫���ߵ�ʱ��������Сֵ
		int		nTimeIntervalMax;				//˫���ߵ�ʱ���������ֵ
		char   szTimeIntervalUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//˫���ߵ�ʱ�����ĵ�λ
		bool	bTriggerDirectionEnable;		//�Ƿ�֧��˫���ߵĴ����������õĹ���
	}ST_MultiTripWireAbility;

	typedef struct _PACKED_1_ tagLoiterAbility
	{
		int		nLibId;								//���ܿ�ID
		bool	bAnalysisPathEnable;				//�Ƿ�֧��·���ж�
		int		nAnalysisPathMax;					//·���жϵ����ֵ
		int		nAnalysisPathMin;					//·���жϵ���Сֵ
		char   szAnalysisPathUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//·���жϵĵ�λ
		bool	bDetailGetEnable;					//�Ƿ��ȡ��ϸ��Ϣ�������Ƿ�֧��
		int		nEdgeNum;							//֧�ֵķ����������
		bool	bEnable;							//�ǻ���Loiter�������Ƿ�֧��
		int		nMaxRegionNum;						//���֧�ֵķ����������
		bool	bMaxTargetSizeEnable;				//�Ƿ�֧��Ŀ�����ߴ�
		int		nMaxTargetSizeMax;					//Ŀ�����ߴ�����ֵ
		int		nMaxTargetSizeMin;					//Ŀ�����ߴ����Сֵ
		char    szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//Ŀ�����ߴ�ĵ�λ
		bool	bMinTargetSizeEnable;				//�Ƿ�֧��Ŀ����С�ߴ�
		int		nMinTargetSizeMax;					//Ŀ����С�ߴ�����ֵ
		int		nMinTargetSizeMin;					//Ŀ����С�ߴ����Сֵ
		char    szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//Ŀ����С�ߴ�ĵ�λ
		bool	bMinTimeEnable;						//�Ƿ�֧����Сʱ�������
		int		nMinTimeMax;						//��Сʱ������ֵ
		int		nMinTimeMin;						// ��Сʱ�����Сֵ
		char    szMinTimeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//��Сʱ��ĵ�λ
		bool	bRegionEnable;						//�������������Ƿ�֧��
		bool	bTargetSizeConstrainEnable;			//�Ƿ��޶�Ŀ���С��������֧�����
		int		nTargetSizeConstrainMax;			//�޶�Ŀ���С�����ֵ
		int		nTargetSizeConstrainMin;			//�޶�Ŀ���С����Сֵ
		char   szTargetSizeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];	//�޶�Ŀ���С�ĵ�λ
		bool	bTargetTypeConstrainEnable;			//�Ƿ��޶�Ŀ���С��������֧�����
		int		nTargetTypeConstrainMax;			//Ŀ�����͵����ߴ�
		int		nTargetTypeConstrainMin;			//Ŀ�����͵���С�ߴ�
		char   szTargetTypeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];	//Ŀ�����ͳߴ�ĵ�λ
		bool	bTargetTypeEnable;					//�޶�����������֧�����
		int		nTargetTypeMax;						//�޶����͵ĳߴ�����ֵ
		int		nTargetTypeMin;						//�޶����͵ĳߴ����Сֵ
		char   szTargetTypeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//�޶����͵ĳߴ�ĵ�λ
	}ST_LoiterAbility;

	typedef struct _PACKED_1_ tagMultiLoiterAbility
	{
		int		nLibId;						//���ܿ�ID
		bool	bAnalysisPathEnable;		//�Ƿ�֧��·���ж�
		int		nAnalysisPathMax;			//·���жϵ����ֵ
		int		nAnalysisPathMin;			//·���жϵ���Сֵ
		char   szAnalysisPathUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];	//·���жϵĵ�λ
		bool	bDetailGetEnable;			//�Ƿ��ȡ��ϸ��Ϣ�������Ƿ�֧��
		int		nEdgeNum;					//�����������
		bool	bEnable;					//�����ǻ���MultiLoiter�������Ƿ�֧��
		bool	bForbiddenTypeEnable;		//�Ƿ�֧�ֽ�ֹ������Χ�Ĺ���
		int		nMaxRegionNum;				//���֧�ֵķ����������
		bool	bMaxTargetSizeEnable;		//�Ƿ�֧��Ŀ�����ߴ�
		int		nMaxTargetSizeMax;			//Ŀ�����ߴ�����ֵ
		int		nMaxTargetSizeMin;			//Ŀ�����ߴ����Сֵ
		char    szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];	//Ŀ�����ߴ�ĵ�λ
		bool	bMaximumEnable;				//�Ƿ�֧�ֽ�ֹ������Χ�����ֵ����
		int		nMaximumMax;				//��ֹ������Χ���ֵ��Χ�����ֵ
		int		nMaximumMin;				//��ֹ������Χ���ֵ��Χ����Сֵ
		char   szMaximumUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//��ֹ������Χ���ֵ��Χ�ĵ�λ
		bool	bMinTargetSizeEnable;		//�Ƿ�֧��Ŀ����С�ߴ�
		int		nMinTargetSizeMax;			//Ŀ����С�ߴ�����ֵ
		int		nMinTargetSizeMin;			//Ŀ����С�ߴ����Сֵ
		char   szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];	//Ŀ����С�ߴ�ĵ�λ
		bool	bMinTimeEnable;				//�Ƿ�֧����Сʱ�������
		int		nMinTimeMax;				//��Сʱ������ֵ
		int		nMinTimeMin;				//��Сʱ�����Сֵ
		char   szMinTimeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//��Сʱ��ĵ�λ
		bool	bMinimumEnable;				//�Ƿ�֧�ֽ�ֹ������Χ����Сֵ����
		int		nMinimumMax;				//��ֹ������Χ��Сֵ��Χ�����ֵ
		int		nMinimumMin;				//��ֹ������Χ��Сֵ��Χ����Сֵ
		char    szMinimumUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//��ֹ������Χ��Сֵ��Χ�ĵ�λ
		bool	bRegionEnable;				//�������������Ƿ�֧��
		bool	bTargetSizeConstrainEnable;	//�Ƿ��޶�Ŀ���С��������֧�����
		int		nTargetSizeConstrainMax;	//�޶�Ŀ���С�����ֵ
		int		nTargetSizeConstrainMin;	//�޶�Ŀ���С����Сֵ
		char   szTargetSizeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];//�޶�Ŀ���С�ĵ�λ
	}ST_MultiLoiterAbility;

	typedef struct _PACKED_1_ tagObjLeftAbility
	{
		int		nLibId;								//���ܿ�ID
		bool	bDetailGetEnable;					//�Ƿ��ȡ��ϸ��Ϣ�������Ƿ�֧��
		int		nEdgeNum;							//֧�ֵķ����������
		bool	bEnable;							//��Ʒ������ObjLeft�������Ƿ�֧��
		int		nMaxRegionNum;						//���֧�ֵķ����������
		bool	bMaxTargetSizeEnable;				//�Ƿ�֧��Ŀ�����ߴ�
		int		nMaxTargetSizeMax;					//Ŀ�����ߴ�����ֵ
		int		nMaxTargetSizeMin;					//Ŀ�����ߴ����Сֵ
		char    szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//Ŀ�����ߴ�ĵ�λ
		bool	bMinTargetSizeEnable;				//�Ƿ�֧��Ŀ����С�ߴ�
		int		nMinTargetSizeMax;					//Ŀ����С�ߴ�����ֵ
		int		nMinTargetSizeMin;					//Ŀ����С�ߴ����Сֵ
		char    szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//Ŀ����С�ߴ�ĵ�λ
		bool	bMinTimeEnable;						//�Ƿ�֧�ָ�������
		int		nMinTimeMax;						//��Сʱ������ֵ
		int		nMinTimeMin;						//��Сʱ�����Сֵ
		char    szMinTimeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//��Сʱ��ĵ�λ
		bool	bRegionEnable;						//�Ƿ�֧�ָ�������
	}ST_ObjLeftAbility;

	typedef struct _PACKED_1_ tagObjMoveAbility
	{
		int		nLibId;								//���ܿ�ID
		bool	bDetailGetEnable;					//�Ƿ��ȡ��ϸ��Ϣ�������Ƿ�֧��
		int		nEdgeNum;							//�����������
		bool	bEnable;							//��Ʒ�ƶ���ObjMove�������Ƿ�֧��
		int		nMaxRegionNum;						//���֧�ֵķ����������
		bool	bMaxTargetSizeEnable;				//�Ƿ�֧��Ŀ�����ߴ�
		int		nMaxTargetSizeMax;					//Ŀ�����ߴ�����ֵ
		int		nMaxTargetSizeMin;					//Ŀ�����ߴ����Сֵ
		char    szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//Ŀ�����ߴ�ĵ�λ
		bool	bMinTargetSizeEnable;				//�Ƿ�֧��Ŀ����С�ߴ�
		int		nMinTargetSizeMax;					//Ŀ����С�ߴ�����ֵ
		int		nMinTargetSizeMin;					//Ŀ����С�ߴ����Сֵ
		char    szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//Ŀ����С�ߴ�ĵ�λ
		bool	bMinTimeEnable;						//�Ƿ�֧����Сʱ�������
		int		nMinTimeMax;						//��Сʱ������ֵ
		int		nMinTimeMin;						//��Сʱ�����Сֵ
		char    szMinTimeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//��Сʱ��ĵ�λ
		bool	bRegionEnable;						//�������������Ƿ�֧��
	}ST_ObjMoveAbility;


	typedef struct _PACKED_1_ tagAbnormalSpeedAbility
	{
		bool	bEnable;									//�������ٶȣ�AbnormalSpeed�������Ƿ�֧��
		int		nLibId;										//���ܿ�ID

		bool	bRegionEnable;								//�Ƿ�֧�ָ�������
		int		nEdgeNum;									//�����������
		int		nMaxRegionNum;								//���֧�ֵķ����������
		bool	bDetailGetEnable;							//�Ƿ��ȡ��ϸ��Ϣ�������Ƿ�֧��

		bool	bTargetTypeConstrainEnable;					//�޶�Ŀ�����͵�������֧�����
		int		nTargetTypeConstrainMin;					//Ŀ�����͵���С�ߴ�
		int		nTargetTypeConstrainMax;					//Ŀ�����͵����ߴ�
		char	szTargetTypeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//Ŀ�����ͳߴ�ĵ�λ

		bool	bTargetTypeEnable;							//�޶�����������֧�����
		int		nTargetTypeMin;								//�޶����͵ĳߴ����Сֵ
		int		nTargetTypeMax;								//�޶����͵ĳߴ�����ֵ
		char	szTargetTypeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];					//�޶����͵ĳߴ�ĵ�λ

		bool	bTargetSizeConstrainEnable;					//�Ƿ��޶�Ŀ���С��������֧�����
		int		nTargetSizeConstrainMin;					//�޶�Ŀ���С����Сֵ
		int		nTargetSizeConstrainMax;					//�޶�Ŀ���С�����ֵ
		char	szTargetSizeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//�޶�Ŀ���С�ĵ�λ

		bool	bMinTargetSizeEnable;						//�Ƿ�֧��Ŀ����С�ߴ�
		int		nMinTargetSizeMin;							//Ŀ����С�ߴ����Сֵ
		int		nMinTargetSizeMax;							//Ŀ����С�ߴ�����ֵ
		char	szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];					//Ŀ����С�ߴ�ĵ�λ

		bool	bMaxTargetSizeEnable;						//�Ƿ�֧��Ŀ�����ߴ�
		int		nMaxTargetSizeMin;							//Ŀ�����ߴ����Сֵ
		int		nMaxTargetSizeMax;							//Ŀ�����ߴ�����ֵ
		char	szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];					//Ŀ�����ߴ�ĵ�λ

		bool	bRateLimitingTypeEnable;					//�Ƿ�֧�ּ��ٱ�ʶ������Χ���ֹ��Χ��������
		int		nRateLimitingTypeMin;						//���ٱ�ʶ����Сֵ
		int		nRateLimitingTypeMax;						//���ٱ�ʶ�����ֵ
		char	szRateLimitingTypeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//���ٱ�ʶ�ĵ�λ

		bool	bMinRateEnable;								//�Ƿ�֧����С�˶��ٶ�
		int		nMinRateMin;								//��С�˶��ٶȵ���Сֵ
		int		nMinRateMax;								//��С�˶��ٶȵ����ֵ
		char	szMinRateUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];						//��С�˶��ٶȵĵ�λ

		bool	bMaxRateEnable;								//�Ƿ�֧������˶��ٶ�
		int		nMaxRateMin;								//����˶��ٶȵ���Сֵ
		int		nMaxRateMax;								//����˶��ٶȵ����ֵ
		char	szMaxRateUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];						//����˶��ٶȵĵ�λ
	}ST_AbnormalSpeedAbility;

	typedef struct _PACKED_1_ tagConverseAbility
	{
		int		nLibId;									//���ܿ�ID
		bool	bConverseAngleEnable;					//�Ƿ�֧�ַ�ת�Ƕȵ�����
		float	fConverseAngleMax;						//��ת�Ƕ�ֵ�����ֵ
		float	fConverseAngleMin;						//��ת�Ƕ�ֵ����Сֵ
		char    szConverseAngleUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//��ת�Ƕ�ֵ�ĵ�λ
		bool	bDetailGetEnable;						//�Ƿ��ȡ��ϸ��Ϣ���������Ƿ�֧��
		int		nEdgeNum;								//�����������
		bool	bEnable;								//��ת��Converse�������Ƿ�֧��
		int		nMaxRegionNum;							//���֧�ֵķ����������
		bool	bMaxTargetSizeEnable;					//�Ƿ�֧��Ŀ�����ߴ�
		int		nMaxTargetSizeMax;						//Ŀ�����ߴ�����ֵ
		int		nMaxTargetSizeMin;						//Ŀ�����ߴ����Сֵ
		char	szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//Ŀ�����ߴ�ĵ�λ

		bool	bMinTargetSizeEnable;					//�Ƿ�֧��Ŀ����С�ߴ�
		int		nMinTargetSizeMax;						//Ŀ����С�ߴ�����ֵ
		int		nMinTargetSizeMin;						//Ŀ����С�ߴ����Сֵ
		char	szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//Ŀ����С�ߴ�ĵ�λ

		bool	bRegionEnable;							//�������������Ƿ�֧��
		bool	bTargetSizeConstrainEnable;				//�޶�Ŀ���С��������֧�����
		int		nTargetSizeConstrainMax;				//�޶�Ŀ���С�����ֵ
		int		nTargetSizeConstrainMin;				//�޶�Ŀ���С����Сֵ
		char	szTargetSizeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//�޶�Ŀ���С�ĵ�λ

		bool	bTargetTypeConstrainEnable;				//�޶�Ŀ�����͵�������֧�����
		int		nTargetTypeConstrainMax;				//Ŀ�����͵����ߴ�
		int		nTargetTypeConstrainMin;				//Ŀ�����͵���С�ߴ�
		char	szTargetTypeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];		//Ŀ�����ͳߴ�ĵ�λ
		bool	bTargetTypeEnable;						//�޶�����������֧�����
		int		nTargetTypeMax;							//�޶����͵ĳߴ�����ֵ
		int		nTargetTypeMin;							//�޶����͵ĳߴ����Сֵ
		char	szTargetTypeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//�޶����͵ĳߴ�ĵ�λ
	}ST_ConverseAbility;	

	typedef struct _PACKED_1_ tagNoParkingAbility
	{
		int		nLibId;								//���ܿ�ID
		bool	bDetailGetEnable;					//��ϸ��Ϣ�������Ƿ�֧��
		int		nEdgeNum;							//�����������
		bool	bEnable;							//�Ƿ�ͣ����NoParking�������Ƿ�֧��

		int		nMaxRegionNum;						//���֧�ֵķ����������
		bool	bMaxTargetSizeEnable;				//�Ƿ�֧��Ŀ�����ߴ�
		int		nMaxTargetSizeMax;					//Ŀ�����ߴ�����ֵ
		int		nMaxTargetSizeMin;					//Ŀ�����ߴ����Сֵ
		char	szMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//Ŀ�����ߴ�ĵ�λ

		bool	bMinTargetSizeEnable;				//�Ƿ�֧��Ŀ����С�ߴ�
		int		nMinTargetSizeMax;					//Ŀ����С�ߴ�����ֵ
		int		nMinTargetSizeMin;					//Ŀ����С�ߴ����Сֵ
		char	szMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//Ŀ����С�ߴ�ĵ�λ

		bool	bMinTimeEnable;						//�Ƿ�֧����Сʱ�������
		int		nMinTimeMax;						//��Сʱ������ֵ
		int		nMinTimeMin;						//��Сʱ�����Сֵ
		char	szMinTimeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//��Сʱ��ĵ�λ
		bool	bRegionEnable;						//�������������Ƿ�֧��
	}ST_NoParkingAbility;

	typedef struct _PACKED_1_ tagSignalBadAbility
	{
		int		nLibId;                   //�����Ŀ�ID
		bool	bEnable;                 //�Ƿ�֧�ָ�������
		bool	bDetailGet;              //�Ƿ��ȡ��ϸ��Ϣ
	}ST_SignalBadAbility;

	typedef struct _PACKED_1_ tagCameraTamperAbility
	{
		bool	bEnable;				//��Ƶ�ڵ���CameraTamper�������Ƿ�֧��
		int		nLibId;					//���ܿ�ID
		bool	bMinTimeEnable;			//�Ƿ�֧����Сʱ�������
		int		nMinTimeMax;			//��Сʱ������ֵ
		int		nMinTimeMin;			//��Сʱ�����Сֵ
		char    szMinTimeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];	//��Сʱ��ĵ�λ

	}ST_CameraTamperAbility;

	typedef struct _PACKED_1_ tagCameraMoveAbility
	{
		bool	bEnable;			//������ƶ���CameraMoveAbility�������Ƿ�֧��
		int		nLibId;			//���ܿ�ID
	}ST_CameraMoveAbility;

	typedef struct _PACKED_1_ tagAdvancedAbility
	{
		bool	bEnable;						//�߼�������Advanced�������Ƿ�֧��
		int		nLibId;							//���ܿ�ID

		bool	bSceneEnable;					//����/����������Ƿ�֧��
		int		nSceneMin;						//����/����Ĳ���ֵ����Сֵ
		int		nSceneMax;						//����/����Ĳ���ֵ�����ֵ
		char	szSceneUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//����/����Ĳ���ֵ�ĵ�λ

		bool	bHightEnable;					//��װ�߶ȵ������Ƿ�֧��
		char	szHightUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//��װ�߶ȵĵ�λ

		bool	bAngleEnable;					//��װ�Ƕȵ������Ƿ�֧��
		char	szAngleUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//��װ�Ƕȵĵ�λ

		bool	bFOVEnable;						//�������ͷ�ӳ���FOV�������Ƿ�֧��
		char	szFOVUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];				//�������ͷ�ӳ���FOV�ĵ�λ

		bool	bPixelToRealSizeEnable;			//�����������ʵ�����峤�ȵ�ת���������Ƿ�֧��
		bool	bRealSizeEnable;				//����ʵ�ʳ��ȵ������Ƿ�֧��
		char	szRealSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];			//����ʵ�ʳ��ȵĵ�λ
		bool	bSegmentLayTypeEnable;			//�߶η�λ(ˮƽ/��ֱ)�Ƿ�֧��
		bool	bSegmentEnable;					//�߶β����������Ƿ�֧��
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
		int    							  nVersion;                         //�汾
		int								  nLibCommonAbilityNum;				 //�������ܷ�����ر�������ֵ����
		ST_LibCommonAbility				  stLibCommonAbilityList[CONST_MAX_LIBCOMMONABILITY_NUM];        //�������ܷ�����ر�������ֵ  //todo

		ST_MotionDetectionAbilityV2       stMotionDetectionAbilityV2;         //�ƶ�����Ӧ������
		ST_PerimeterAbility               stPerimeterAbility;                 //��������
		ST_TripWireAbility                stTripWireAbility;                  //��������
		ST_MultiTripWireAbility           stMultiTripWireAbility;             //˫��������
		ST_LoiterAbility                  stLoiterAbility;                    //�ǻ�����
		ST_MultiLoiterAbility             stMultiLoiterAbility;               //�����ǻ���Ӧ������
		ST_ObjLeftAbility                 stObjLeftAbility;                   //��Ʒ������Ӧ������
		ST_ObjMoveAbility                 stObjMoveAbility;                   //�������߶�Ӧ������

		ST_AbnormalSpeedAbility           stAbnormalSpeedAbility;             //�������ٶȶ�Ӧ������
		ST_ConverseAbility                stConverseAbility;                  //���ж�Ӧ������
		ST_NoParkingAbility               stNoParkingAbility;                 //�Ƿ�ͣ����Ӧ������
		ST_SignalBadAbility               stSignalBadAbility;                 //�ź��쳣��Ӧ������
		ST_CameraTamperAbility            stCameraTamperAbility;              //��Ƶ�ڵ���Ӧ������
		ST_CameraMoveAbility              stCameraMoveAbility;                //������ƶ���Ӧ������
		ST_AdvancedAbility                stAdvancedAbility;                  //�߼�������Ӧ������

	}ST_IntelligenceAnalyseAbility;

	typedef struct _PACKED_1_ tagSNPoint
	{
		float fXval;			//X����
		float fYval;			//y ����
	}ST_SNPoint;

	typedef struct _PACKED_1_ tagPolygonArea
	{
		int nSNPointNum;						//�ڵ����
		ST_SNPoint		stSNPoint[CONST_MAX_SNPOINT];			//�ڵ� //TODO

	}ST_PolygonArea;

	typedef struct _PACKED_1_ tagPerimeterRegionParam
	{
		int					nSensitivity;			//	������	
		bool 				bTargetTypeConstrain;	//	�Ƿ��޶�Ŀ������(ȡֵ��Χ��0(��)��1(��))
		int					nTargetType;			//	�����޶�ģʽ(ȡֵ��Χ��0(�˻�)��1(��)��2(��))
		bool				bTargetSizeConstrain;	//	�Ƿ��޶�Ŀ��ߴ�(ȡֵ��Χ��0(��)��1(��))
		int					nMinTargetSize;			//  Ŀ����С�ߴ�(��λ��ƽ������)
		int					nMaxTargetSize;			//	Ŀ�����ߴ�(��λ��ƽ������)
		ST_PolygonArea		stRegion;				//	��������

	}ST_PerimeterRegionParam;

	typedef struct _PACKED_1_ tagIntelligeBaseParam
	{
		char	szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//�豸���豸ID
		int		nCameraId;
		bool	bIsEnable;
		int		nAlarmInterval;

		ST_ScheduleTimeParam				stScheduleTimeParam;

		long								nAlarmOutActionNum;																//��������¼�����
		ST_AlarmOutActionParam				stAlarmOutActionParam[CONST_MAX_ALARM_OUT_NUM];									//��������¼�

		long								nAlarmRecordActionNum;															//����¼���¼�����
		ST_AlarmRecordActionParam			stAlarmRecordActionParam[CONST_MAX_CAMERA_NUM];									//����¼���¼�

		long								nAlarmPTZActionNum;																//������̨�¼�����
		ST_AlarmPTZActionParam				stAlarmPTZActionParam[CONST_MAX_CAMERA_NUM];									//������̨�¼�

		long								nAlarmOverlayNum;																//���������¼�����
		ST_AlarmOverlayActionParam			stAlarmOverlayActionParam[CONST_MAX_CAMERA_NUM];	
	}ST_IntelligeBaseParam;

	typedef struct _PACKED_1_ tagPerimeterParam			
	{													
		bool					bIsGetDetail;//�Ƿ���ʾ��ϸ��Ϣ
		int						nPerimeterRegionParamNum;	//�����������			
		ST_PerimeterRegionParam stPerimeterRegionParamList[CONST_MAX_PERIMETERREGIONPARAM];//���������б�//TODO									
		ST_IntelligeBaseParam	stIntelligeBaseParam;

	}ST_PerimeterParam;


	typedef struct _PACKED_1_ tagLineCross
	{
		float		fLineCrossStartX;       //��ʼ��X���꣨ռ��Ļ�İٷֱȣ�
		float		fLineCrossStartY;       //��ʼ��Y����
		float		fLineCrossEndX;		    //������X����
		float		fLineCrossEndY;		    //������Y����
	}ST_LineCross;


	typedef struct _PACKED_1_ tagTripWireRegionParam
	{
		bool 		bTargetTypeConstrain;    //�Ƿ��޶�Ŀ������(ȡֵ��Χ��0(��)��1(��))
		int			nTargetType;             // �����޶�ģʽ(ȡֵ��Χ��0(�˻�)��1(��)��2(��))
		bool		bTargetSizeConstrain;	 // �Ƿ��޶�Ŀ��ߴ�(ȡֵ��Χ��0(��)��1(��))
		int			nMinTargetSize;          // Ŀ����С�ߴ�(��λ��ƽ������)
		int			nMaxTargetSize;          //Ŀ�����ߴ�(��λ��ƽ������)

		bool		bIsBidirection;          // ��ʾ�����Ƿ�Ϊ˫�����(ȡֵ��Χ��0(��)��1(��))
		int			nTriggerDirection;       //���߽�ֹ����Ƕ�(��λ����)
		ST_LineCross	stTripWireLine;      //����λ��(��λ������)
	}ST_TripWireRegionParam;

	typedef struct _PACKED_1_ tagTripWireParam
	{
		bool						bIsGetDetail;			//�Ƿ���ʾ��ϸ��Ϣ
		int							nTripWireRegionParamNum;//�����������
		ST_TripWireRegionParam		stTripWireRegionParamList[CONST_MAX_TRIPWIREREGIONPARAM];	//��������//TODO
		ST_IntelligeBaseParam		stIntelligeBaseParam;
	}ST_TripWireParam;



	typedef struct _PACKED_1_ tagMultiTripWireRegionParam
	{
		bool 				bTargetTypeConstrain;        // �Ƿ��޶�Ŀ������(ȡֵ��Χ��0(��)��1(��))
		int					nTargetType;                 // �����޶�ģʽ(ȡֵ��Χ��0(�˻�)��1(��)��2(��))
		bool				bTargetSizeConstrain;        //�Ƿ��޶�Ŀ��ߴ�(ȡֵ��Χ��0(��)��1(��))
		int					nMinTargetSize;              //Ŀ����С�ߴ�(��λ��ƽ������)
		int					nMaxTargetSize;              //Ŀ�����ߴ�(��λ��ƽ������)

		int					nTimeInterval;               //��Խ�����ߵ��ʱ����(��λ����)
		int				    nTriggerDirectionList[CONST_MAX_TRIGGERDIRECTION];    //���߽�ֹ����Ƕ�(��λ����)0��360 ��  //TODO
		
		ST_LineCross		stTripWireLineList[CONST_MAX_TRIPWIRELINE];      //����λ��(��λ������)  //TODO
	}ST_MultiTripWireRegionParam;

	typedef struct _PACKED_1_ tagMultiTripWireParam
	{
		bool	bIsGetDetail;	//�Ƿ��ȡ��ϸ��Ϣ
		int		nMultiTripWireRegionParamNum;//�����������
		ST_MultiTripWireRegionParam stMultiTripWireRegionParamList[CONST_MAX_MULTITRIPWIREREGIONPARAM];//���������б�  TODO
		ST_IntelligeBaseParam		stIntelligeBaseParam;
	}ST_MultiTripWireParam;



	typedef struct _PACKED_1_ tagLoiterRegionParam
	{
		bool 				 bTargetTypeConstrain;		//�Ƿ��޶�Ŀ������(ȡֵ��Χ��0(��)��1(��))
		int					 nTargetType;				//�����޶�ģʽ(ȡֵ��Χ��0(�˻�)��1(��)��2(��))
		bool				 bTargetSizeConstrain;		//�Ƿ��޶�Ŀ��ߴ�(ȡֵ��Χ��0(��)��1(��))
		int					 nMinTargetSize;			//Ŀ����С�ߴ�(��λ��ƽ������)(ȡֵ��Χ��0~1000000)
		int					 nMaxTargetSize;			//Ŀ�����ߴ�(��λ��ƽ������)(ȡֵ��Χ��0~1000000)

		int					 nMinTime;					//�ǻ����ʱ��(��λ: ��)
		bool				 bIsAnalysisPath;			//�Ƿ�����·���ж�(ȡֵ��Χ��0(��)��1(��))

		ST_PolygonArea		 stRegion;					//������Ϣ
	}ST_LoiterRegionParam;

	typedef struct _PACKED_1_ tagLoiterParam
	{
		bool				 bIsGetDetail;//�Ƿ���ʾ��ϸ��Ϣ
		int					 nLoiterRegionParamNum;
		ST_LoiterRegionParam LoiterRegionParamList[CONST_MAX_LOITERPARAM];//���������б�//TODO
		ST_IntelligeBaseParam		stIntelligeBaseParam;
	}ST_LoiterParam;


	typedef struct _PACKED_1_ tagMultiLoiterRegionParam
	{	
		bool			bTargetSizeConstrain;		//!< �Ƿ��޶�Ŀ��ߴ�(ȡֵ��Χ��0(��)��1(��))
		int				nMinTargetSize;				//!< Ŀ����С�ߴ�(��λ��ƽ������)
		int				nMaxTargetSize;				//!< Ŀ�����ߴ�(��λ��ƽ������)

		int				nMinTime;						//!< �ǻ����ʱ��(��λ����)
		bool			bAnalysisPath;					//�Ƿ�����·���ж�

		bool			bForbiddenType;				//����������־
		int				nMinimum;						//��Сֵ
		int				nMaximum;						//���ֵ

		ST_PolygonArea	stRegion;				//������Ϣ

	}ST_MultiLoiterRegionParam;

	typedef struct _PACKED_1_ tagMultiLoiterParam
	{
		bool		bIsGetDetail;//�Ƿ���ʾ��ϸ��Ϣ
		int			nMultiLoiterRegionParam;
		ST_MultiLoiterRegionParam stMultiLoiterRegionParamList[CONST_MAX_MULTILOITERPARAM];//���������б�//todo
		ST_IntelligeBaseParam		stIntelligeBaseParam;
	}ST_MultiLoiterParam;

	typedef struct _PACKED_1_ tagObjectLeftRegionParam
	{
		int 				nMinTargetSize;		// ��Ʒ��С�ߴ�(��λ��ƽ������)
		int					nMaxTargetSize;		//��Ʒ���ߴ�(��λ��ƽ������)
		int					nMinTime;			//��Ʒ�������ʱ��(��λ����)

		ST_PolygonArea		stRegion;			//������Ϣ
	}ST_ObjectLeftRegionParam;

	typedef struct _PACKED_1_ tagObjectLeftParam
	{
		bool					 bIsGetDetail;//�Ƿ���ʾ��ϸ��Ϣ
		int						 nObjectLeftRegionParamNum;//�����������
		ST_ObjectLeftRegionParam stObjectLeftRegionParamList[CONST_MAX_OBJECTLEFTREGIONPARAM];//���������б�
		ST_IntelligeBaseParam		stIntelligeBaseParam;
	}ST_ObjectLeftParam;

	typedef struct _PACKED_1_ tagObjectMovedRegionParam
	{
		int 						nMinTargetSize;	// ��Ʒ��С�ߴ�(��λ��ƽ������)
		int							nMaxTargetSize;	// ��Ʒ���ߴ�(��λ��ƽ������)
		int							nMinTime;			// ��Ʒ�������ʱ��(��λ����)

		ST_PolygonArea				stRegion;				//������Ϣ
	}ST_ObjectMovedRegionParam;

	typedef struct _PACKED_1_ tagObjectMovedParam
	{
		bool						bIsGetDetail;//�Ƿ���ʾ��ϸ��Ϣ
		int							nObjectMovedRegionParamNum;//�����������
		ST_ObjectMovedRegionParam   stObjectMovedRegionParamList[CONST_MAX_OBJECTMOVEDREGIONPARAM];//���������б�
		ST_IntelligeBaseParam		stIntelligeBaseParam;
	}ST_ObjectMovedParam;

	typedef struct _PACKED_1_ tagAbnormalSpeedRegionParam
	{
		bool 			bTargetTypeConstrain;		// �Ƿ��޶�Ŀ������(ȡֵ��Χ��0(��)��1(��))
		int				nTargetType;				// �����޶�ģʽ(ȡֵ��Χ��0(�˻�)��1(��)��2(��))
		bool			bTargetSizeConstrain;		// �Ƿ��޶�Ŀ��ߴ�(ȡֵ��Χ��0(��)��1(��))
		int				nMinTargetSize;				// Ŀ����С�ߴ�(��λ��ƽ������)
		int				nMaxTargetSize;				// Ŀ�����ߴ�(��λ��ƽ������)

		int				nRateLimitingType;			// ���ٱ�ʶ��0������Χ��1����ֹ��Χ��
		int				nMinRate;				    // ��С�˶��ٶ�(��λ����/��)
		int				nMaxRate;				    // ����˶��ٶ�(��λ����/��)

		ST_PolygonArea	stRegion;					//������Ϣ
	}ST_AbnormalSpeedRegionParam;

	typedef struct _PACKED_1_ tagAbnormalSpeedParam
	{
		bool						bIsGetDetail;//�Ƿ���ʾ��ϸ��Ϣ
		int							nAbnormalSpeedRegionParamNum;//�����������
		ST_AbnormalSpeedRegionParam stAbnormalSpeedRegionParamList[CONST_MAX_ABNORMALSPEEDREGIONPARAM];//���������б�
		ST_IntelligeBaseParam		stIntelligeBaseParam;
	}ST_AbnormalSpeedParam;

	typedef struct _PACKED_1_ tagConverseRegionParam
	{
		bool 			bTargetTypeConstrain;	// �Ƿ��޶�Ŀ������(ȡֵ��Χ��0(��)��1(��))
		int				nTargetType;			// �����޶�ģʽ(ȡֵ��Χ��0(�˻�)��1(��)��2(��))
		bool			bTargetSizeConstrain;	// �Ƿ��޶�Ŀ��ߴ�(ȡֵ��Χ��0(��)��1(��))
		int				nMinTargetSize;			// Ŀ����С�ߴ�(��λ��ƽ������)
		int				nMaxTargetSize;			// Ŀ�����ߴ�(��λ��ƽ������)

		float			fConverseAngle;			// ���з���Ƕ�(��λ����) 0��360 ��

		ST_PolygonArea	stRegion;//������Ϣ
	}ST_ConverseRegionParam;

	typedef struct _PACKED_1_ tagConverseParam
	{
		bool					bIsGetDetail;//�Ƿ���ʾ��ϸ��Ϣ
		int						nConverseRegionParamNum;//�����������
		ST_ConverseRegionParam  stConverseRegionParamList[CONST_MAX_CONVERSEREGIONPARAM];//���������б�
		ST_IntelligeBaseParam  stIntelligeBaseParam;

	}ST_ConverseParam;

	typedef struct _PACKED_1_ tagNoParkingRegionParam
	{
		int 			nMinTargetSize;	//!< ������С�ߴ�(��λ��ƽ������)
		int				nMaxTargetSize;	//!< �������ߴ�(��λ��ƽ������)
		int				nMinTime;			//!< ����ͣ�����ʱ��(��λ����)

		ST_PolygonArea	stRegion;				//������Ϣ
	}ST_NoParkingRegionParam;

	typedef struct _PACKED_1_ tagNoParkingParam
	{
		bool					bIsGetDetail;				//�Ƿ���ʾ��ϸ��Ϣ
		int						nNoParkingRegionParamNum;	//�����������
		ST_NoParkingRegionParam stNoParkingRegionParamList[CONST_MAX_NOPARKINGREGIONPARAM];//���������б� //TODO
		ST_IntelligeBaseParam  stIntelligeBaseParam;
	}ST_NoParkingParam;


	typedef struct _PACKED_1_ tagMotionDetectionParamV3
	{
		int					nSensitivity;	//	������
		bool				bIsGetDetail;//�Ƿ���ʾ��ϸ��Ϣ

		ST_DetectionAreaV2		stDetectionAreaV2;//������Ϣ
		
		ST_IntelligeBaseParam  stIntelligeBaseParam;
	}ST_MotionDetectionParamV3;

	typedef struct _PACKED_1_ tagCameraTamperParam
	{
		ST_IntelligeBaseParam  stIntelligeBaseParam;
		int 			nMinTime;  //	�ڵ���Сʱ��
	}ST_CameraTamperParam;



	typedef struct _PACKED_1_ tagSignalBadParam
	{
		ST_IntelligeBaseParam stIntelligeBaseParam;
		bool	bIsGetDetail;//�Ƿ���ʾ��ϸ��Ϣ
	}ST_SignalBadParam;


	typedef struct _PACKED_1_ tagPixelToRealSize
	{
		int				nRealSize;					//����ʵ�ʳ��� ��λ����
		int				nSegmentLayType;	//�߶η�λ(ˮƽ/ ��ֱ) 
		ST_LineCross	stLineCross;				//�߶β���
	}ST_PixelToRealSize;

	typedef struct _PACKED_1_ tagAdvancedParam
	{
		int			nScene;					//����/����
		int			nHight;					//��װ�߶�hight
		float		fAngle;					//��װ�Ƕ�,�������ֱ����
		float		fFOV;					//��ͷ�ӳ���

		int			nCameraShake;				//�����������0���ر� 1���򿪣�
		int			nHighNoise;				//������������0: �ر� 1���򿪣�
		int			nLowContrast;				//�ͶԱȶȣ�0:�ر� 1���򿪣�
		int			nPeriodMotion;			//�����˶�������0:�ر� 1����)
		int			nPeriodMotionTime;		//�����˶�����ʱ��(��)

		int			nPixelToRealSizeNum;	//�����������ʵ�����峤�ȵ�ת������	

		ST_PixelToRealSize stPixelToRealSizeList[CONST_MAX_PIXELTOREALSIZE];//�����������ʵ�����峤�ȵ�ת��  TODO
	}ST_AdvancedParam;



	typedef struct  _PACKED_1_ tagCameraMovedParam
	{
		ST_IntelligeBaseParam  stIntelligeBaseParam;
	}ST_CameraMovedParam;


	//FisheyeDewarpMode����
	typedef struct _PACKED_1_ tagFisheyeDewarpModeParam
	{
		int nCameraId;			//ͨ����
		int nFisheyeVideoMode;	//������Ƶģʽ,���嶨��ɲ鿴FisheyeConst.h��FISHEYE_VIDEO_MODEö�ٶ���
		int nDewarpMode;			//����ģʽ,���嶨��ɲ鿴FisheyeConst.h��FISHEYE_DEWARP_MODEö�ٶ���
	}ST_FisheyeDewarpModeParam;

	typedef struct _PACKED_1_  tagVideoRect
	{
		int			nId;			//0��Զ�����ۻ���ȫ����Ƶ������Ϊptz
		double		nStartX;		//�ٷֱȣ�0~1��x100������ΪС�����2λ
		double		nStartY;		//�ٷֱȣ�0~1��x100������ΪС�����2λ
		double		nWidth;			//�ٷֱȣ�0~1��x100������ΪС�����2λ
		double		nHeight;		//�ٷֱȣ�0~1��x100������ΪС�����2λ
	}ST_VideoRect;

	typedef struct _PACKED_1_ tagFisheyeVideoLayout
	{
		int		nCameraId;										//ͨ����
		int		nVideoRectNum;									//��ʾ�������
		ST_VideoRect stVideoRect[CONST_MAX_FISHEYEVIDEOLAYOUT]; //���ۡ�ȫ����PTZ��ʾ����
	}ST_FisheyeVideoLayout;

	typedef struct _PACKED_1_ tagFisheyeMountParam
	{
		int nFisheyeMountType;		//��װģʽ
	}ST_FisheyeMountParam;


	typedef struct _PACKED_1_ tagFisheyeDewarpMode
	{
		int		nDewarpMode;	//����ģʽ,���嶨��ɲ鿴FisheyeConst.h��FISHEYE_DEWARP_MODEö�ٶ���
		bool	bMoveable;		//�Ƿ���ƶ���ʶ
	}ST_FisheyeDewarpMode;

	typedef struct _PACKED_1_ tagFisheyeVideoAbility
	{
		int nFisheyeVideoMode;										//������Ƶģʽ,���嶨��ɲ鿴FisheyeConst.h��FISHEYE_VIDEO_MODEö�ٶ���
		int nDewarpModeNum;
		ST_FisheyeDewarpMode stDewarpModeList[CONST_MAX_DEWARPMODE]; //���۾���ģʽ

	}ST_FisheyeVideoAbility;

	typedef struct _PACKED_1_ tagFisheyeAbility
	{
		bool	bFisheyeSupportFlag;									//���۹���֧�ֱ�ʶ

		int		nFisheyeMountTypeNum;
		int		nFisheyeMountTypeList[CONST_MAX_FISHEYEMOUNTTYPE]; //��װģʽ�����嶨��ɲ鿴FisheyeConst.h��FISHEYE_MOUNT_TYPEö�ٶ���

		int		nFisheyeVideoAbilityNum;
		ST_FisheyeVideoAbility stFisheyeVideoAbility[CONST_MAX_FISHEYEVIDEOABILITY]; //������Ƶ����
	}ST_FisheyeAbility;

	typedef struct _PACKED_1_ tagAreaParamV2
	{
		double	dTopX;								//�������Ͻ� x ������ռ����Ƶ����ȵİٷֱ�
		double	dTopY;								//�������Ͻ� y ������ռ����Ƶ���߶ȵİٷֱ�
		double	dWidth;								//������ռ��Ƶ���ܿ�ȵİٷֱ�
		double	dHeight;								//����߶�ռ����Ƶ���߶ȵİٷֱ�
	}ST_AreaParamV2;

	typedef struct _PACKED_1_ tagBlindAreaParamV2
	{
		int						nAreaId;					//�ƶ�����ID
		bool					bEnableFlag;				//�Ƿ������ڱΣ�true�����ã�false�������ã�
		ST_ColorParam			stColorParam;				//������ɫ���˲���Ԥ��

		ST_AreaParamV2			stAreaParamV2;				//�ƶ�����
		char					szAreaName[CONST_MAX_AREANAME + 1];		//�豸����
		int						nMirrorValue;				//��������
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
		int nAlarmIOModeID;  //������״̬ 1:������ģʽ   2:�ߵ͵�ƽģʽ
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
