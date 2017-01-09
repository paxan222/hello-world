#ifndef _ALARMTYPE_H_
#define _ALARMTYPE_H_

#include "DomainConst.h"
#include "SNPlatOS.h"

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

class SN_DLL_API AlarmType
{
public:
	//报警类型
	enum
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
		TYPE_RECORD_STORAGE_FAILED		= 15,   //录像存储失败
		TYPE_PIR_ALARM					= 16,	//PIR报警，add by weihuiquan
		TYPE_AUDIO_DETECT				= 17	//语音报警
	};

	//扩展报警主类型
	enum AlarmMajorType
	{
		SECURITY_ALARM						= 1, //安全报警
		DISK_ALARM							= 4, //磁盘报警
		RECORD_ALARM						= 5, //录像报警
		INTELLIGENCE_ANALYSE_ALARM			= 6	 //智能分析报警
	};

	enum IntelligenceAnalyseAlarmMinorType
	{
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_TRIPWIRE							= 21,	//智能分析 绊线检测报警
		//INTELLIGENCEANALYSEALARM_MINOR_TYPE_MOTIONDETECT						= 22,	//智能分析 移动检测报警
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_CAMERATAMPER						= 23,	//智能分析 遮挡检测报警
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_PERIMETER							= 24,	//智能分析 周界入侵报警
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_MULTITRIPWIRE						= 25,	//智能分析 双绊线报警
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_LOITER								= 26,	//智能分析 徘徊报警   
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_MULTILOITER							= 27,	//智能分析 多人徘徊报警
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_OBJECTLEFT							= 28,	//智能分析 物品遗留报警
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_OBJECTMOVED							= 29,	//智能分析 物品移走报警
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_ABNORMALSPEED						= 30,	//智能分析 非正常速度报警 
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_CONVERSE							= 31,	//智能分析 逆行报警
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_NOPARKING							= 32,	//智能分析 非法停车报警
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_CAMERAREMOVED						= 33,	//智能分析 摄像机移位报警
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_SIGNAL_BAD							= 34	//智能分析 视频信号异常报警
	};

	//扩展安全报警子类型
	enum SecurityAlarmMinorType
	{
		SECURITYALARM_MINOR_TYPE_ALARMIO				= 1,	//I/O报警
		SECURITYALARM_MINOR_TYPE_MOTIONDETECT			= 2,	//运动检测报警
		SECURITYALARM_MINOR_TYPE_CAMERAMASK				= 3,	//摄像头遮挡报警
		SECURITYALARM_MINOR_TYPE_VIDEO_LOST				= 4,	//视频丢失报警
		SECURITYALARM_MINOR_TYPE_NETWORK_DISCONNECTION	= 5,	//网络断开告警
		SECURITYALARM_MINOR_TYPE_PIRALARM				= 9, 	//PIR报警，add by weihuiquan
		SECURITYALARM_MINOR_TYPE_ALARM_NETIO			= 10,	//网络IO报警
		SECURITYALARM_MINOR_TYPE_AUDIO_DETECT			= 11	//语音报警
	};

	//扩展磁盘报警子类型
	enum DiskAlarmMinorType
	{
		DISKALARM_MINOR_TYPE_DISK_OK			= 1,	//磁盘状态正常
		DISKALARM_MINOR_TYPE_DISK_ERROR			= 2,	//磁盘读写异常
		DISKALARM_MINOR_TYPE_CONNECT_FAILED		= 3,	//网络磁盘连接失败
		DISKALARM_MINOR_TYPE_DISK_FULL			= 4,	//磁盘满
		DISKALARM_MINOR_TYPE_NOT_EXISTENT		= 5,	//磁盘不存在
		DISKALARM_MINOR_TYPE_THRESHOLD_ALARM	= 6,	//磁盘已用空间达到指定阀值 
		DISKALARM_MINOR_TYPE_NOT_FORMAT			= 7,	//磁盘未格式化
		DISKALARM_MINOR_TYPE_DEVICE_NOSPACE		= 8,	//设备存储空间不足
		DISKALARM_MINOR_TYPE_DATAVERSION_LOW	= 9,	//数据版本太低
		DISKALARM_MINOR_TYPE_DATAVERSION_HIGH	= 10,	//数据版本太高
		DISKALARM_MINOR_TYPE_ACCESS_ABILITY_UNMATCH	= 11	//磁盘访问能力不匹配
	};

	////扩展录像报警子类型
	//enum RecordAlarmMinorType
	//{
	//	RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_SUCCESS			= 1,		//数据源连接成功
	//	RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_LOGIN_ERROR		= 2,		//数据源连接用户名密码错误
	//	RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_NO_PRIVILEGE		= 3,		//数据源连接没有权限
	//	RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_MAX_CONNECTION	= 4,		//数据源连接达到最大连接数
	//	RECORDSOURCE_MINOR_TYPE_AVDATA_MAX_SPEED				= 5,		//数据源达到最大限制速率
	//	RECORDSOURCE_MINOR_TYPE_LOGIN_USER_REPEATED				= 6,
	//	RECORDSOURCE_MINOR_TYPE_NOT_SUPPORT_VIDEO				= 7,
	//	RECORDSOURCE_MINOR_TYPE_CREATE_VIDEO_SESSION_FAILED		= 8,
	//	RECORDSTORAGE_MINOR_TYPE_STORAGE_FAILED					= 9,
	//	RECORDSTORAGE_MAIN_RECORD_FAILED						= 10,
	//	RECORDSTORAGE_MAIN_BUCKUP_RECORD_FAILED					= 11,
	//	RECORDSTORAGE_MAIN_RECORD_STATE_OK						= 12,
	//	RECORDSTORAGE_BACKUP_RECORD_STATE_OK					= 13
	//};

		//扩展录像报警子类型
	enum RecordAlarmMinorType
	{
		RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_SUCCESS			= 1,		//数据源连接成功
		RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_LOGIN_ERROR		= 2,		//数据源连接用户名密码错误
		RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_NO_PRIVILEGE		= 3,		//数据源连接没有权限
		RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_MAX_CONNECTION	= 4,		//数据源连接达到最大连接数
		RECORDSOURCE_MINOR_TYPE_AVDATA_MAX_SPEED				= 5,		//数据源达到最大限制速率
		RECORDSOURCE_MINOR_TYPE_LOGIN_USER_REPEATED				= 6,		
		RECORDSOURCE_MINOR_TYPE_NOT_SUPPORT_VIDEO				= 7,
		RECORDSOURCE_MINOR_TYPE_CREATE_VIDEO_SESSION_FAILED		= 8,
		RECORDSTORAGE_MINOR_TYPE_STORAGE_FAILED					= 9,		//存储失败
		RECORDSTORAGE_MINOR_TYPE_START_RECORD					= 10,		//启动录像
		RECORDSTORAGE_MINOR_TYPE_STOP_RECORD					= 11,		//停止录像
	
	    RECORDSTORAGE_MAIN_RECORD_FAILED						= 12,
		RECORDSTORAGE_MAIN_BUCKUP_RECORD_FAILED					= 13,
		RECORDSTORAGE_MAIN_RECORD_STATE_OK						= 14,
		RECORDSTORAGE_BACKUP_RECORD_STATE_OK					= 15

	};


	enum AlarmFlag
	{
		ALARM_FLAG_STOP = 0,						//报警停止
		ALARM_FLAG_START = 1						//报警开始
	};

public:
	AlarmType(void);
	~AlarmType(void);
	
	AlarmType(const AlarmType& p_objAlarmType);

public:

	/************************************************************************
	**概述：
	*		设置报警类型id
	**输入：
	*		p_nAlarmTypeId：报警类型id，一个以‘\0’结尾的字符串，
	**输出：
	*		无
	**返回值：
	*		无
	*功能：
	*	
	************************************************************************/
	void setAlarmTypeId(const int p_nAlarmTypeId);

	/************************************************************************
	**概述：
	*		获取报警类型id
	*输入：
	*		无
	*输出：
	*		无
	**返回值：
	*		报警类型id
	**功能：
	*
	*************************************************************************/
	const int getAlarmTypeId() const;


	/************************************************************************
	**概述：
	*		设置报警类型名称
	**输入：
	*		p_pszAlarmTypeName：报警类型名称，一个以‘\0’结尾的字符串，
	**输出：
	*		无
	**返回值：
	*		ture ：	设置成功
	*		false ：设备只是
	*功能：
	*		当p_pszAlarmTypeName为空时，返回false；
	*		当设置报警类型名称成功时，返回true；
	************************************************************************/
	bool setAlarmTypeName(const char* p_pszAlarmTypeName);

	/************************************************************************
	**概述：
	*		获取报警类型名称
	*输入：
	*		无
	*输出：
	*		无
	**返回值：
	*		报警类型名称
	**功能：
	*
	*************************************************************************/
	const char* getAlarmTypeName() const;

	/************************************************************************
	*概述：
	*		赋值函数
	**输入：
	*		p_objAlarmType：报警类型信息
	**输出：
	*		无
	**返回值：
	*		报警类型信息
	**功能：
	*
	*************************************************************************/
	AlarmType& operator =(const AlarmType& p_objAlarmType);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objAlarmType：AlarmType类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个AlarmType类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const AlarmType& p_objAlarmType);

private:
	int			m_nAlarmTypeId;											//报警类型id

	char		m_szAlarmTypeName[CONST_MAXLENGTH_ALARM_TYPE_NAME + 1];		//报警类型名称
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_ALARMTYPE_H_

