#ifndef _LOG_INFO_DESCRIPTION_H_
#define _LOG_INFO_DESCRIPTION_H_



//用户管理  
#define LOG_DESC_ID_ADD_PRIVILEGE_USER					"AddPrivilegeUser"				//添加权限用户
#define LOG_DESC_ID_DELETE_PRIVILEGE_USER				"DeletePrivilegeUser"			//删除权限用户

#define LOG_DESC_ID_MODIFY_PRIVILEGE_USER				"ModifyPrivilegeUser"			//修改权限用户
#define LOG_DESC_ID_MODIFY_PRIVILEGE_USER_PASSWORD		"ModifyPrivilegeUserPassword"	//修改权限用户密码
#define LOG_DESC_ID_MODIFY_PRIVILEGE_USER_GROUP			"ModifyPrivilegeUserGroup"		//修改权限用户组别

#define LOG_DESC_ID_LOCK_PRIVILEGE_USER					"LockPrivilegeUser"				//锁定权限用户
#define LOG_DESC_ID_UNLOCK_PRIVILEGE_USER				"UnlockPrivilegeUser"			//解锁权限用户

#define LOG_DESC_ID_AUTO_LOCK_PRIVILEGE_USER			"AutoLockPrivilegeUser"			//自动锁定权限用户
#define LOG_DESC_ID_AUTO_UNLOCK_PRIVILEGE_USER			"AutoUnlockPrivilegeUser"		//自动解锁权限用户

#define LOG_DESC_ID_ADD_PRIVILEGE_GROUP					"AddPrivilegeGroup"				//添加权限组
#define LOG_DESC_ID_DELETE_PRIVILEGE_GROUP				"DeletePrivilegeGroup"			//删除权限组
#define LOG_DESC_ID_MODIFY_PRIVILEGE_GROUP				"ModifyPrivilegeGroup"			//修改权限组

#define LOG_DESC_ID_CONFIGURE_GROUP_PRIVILEGE			"ConfigureGroupPrivilege"		//配置组权限

#define	LOG_DESC_ID_ADD_USER_MANAGER_PRIVILEGE			"AddPrivilegeManagerPrivilege"		//修改用户管理权限
#define	LOG_DESC_ID_REMOVE_USER_MANAGER_PRIVILEGE		"RemovePrivilegeManagerPrivilege"

#define	LOG_DESC_ID_ADD_SYSTEM_MANAGER_PRIVILEGE		"AddSystemMaintenancePrivilege"		//修改系统管理权限
#define	LOG_DESC_ID_REMOVE_SYSTEM_MANAGER_PRIVILEGE		"RemoveSystemMaintenancePrivilege"

#define	LOG_DESC_ID_ADD_DEVICE_CONFIG_PRIVILEGE			"AddParameterConfigurePrivilege"		//修改设备配置权限
#define	LOG_DESC_ID_REMOVE_DEVICE_CONFIG_PRIVILEGE		"RemoveParameterConfigurePrivilege"

#define	LOG_DESC_ID_ADD_RECORD_CTRL_PRIVILEGE			"AddRecordOperationPrivilege"		//修改录像操作权限
#define	LOG_DESC_ID_REMOVE_RECORD_CTRL_PRIVILEGE		"RemoveRecordOperationPrivilege"

#define	LOG_DESC_ID_ADD_LIVEVIDEO_CTRL_PRIVILEGE		"AddVideoCtrlPrivilege"		//修改视频控制权限
#define	LOG_DESC_ID_REMOVE_LIVEVIDEO_CTRL_PRIVILEGE		"RemoveVideoCtrlPrivilege"

#define	LOG_DESC_ID_ADD_LIVEVIDEO_PRIVILEGE				"AddLiveVideoPrivilege"			//修改实时视频点播权限
#define	LOG_DESC_ID_REMOVE_LIVEVIDEO_PRIVILEGE			"RemoveLiveVideoPrivilege"

#define LOG_DESC_ID_CHANGE_SELF_PASSWORD				"ChangeSelfPassword"			//修改自己的密码
#define LOG_DESC_ID_CHANGE_SELF_PASSWORD_SUCCESS		"ChangeSelfPasswordSuccess"		//修改自己的密码成功
#define LOG_DESC_ID_CHANGE_SELF_PASSWORD_FAIL			"ChangeSelfPasswordFailed"		//修改自己的密码错误

#define LOG_DESC_ID_USER_LOGIN							"UserLogin"						//用户登录
#define LOG_DESC_ID_USER_LOGOUT							"UserLogout"					//用户注销

#define LOG_DESC_ID_USER_LOGIN_SUCCESS					"UserLoginSuccess"					//登录成功
#define LOG_DESC_ID_USER_LOGIN_VALIDATECODE_ERROR		"LoginFailedValidateCodeError"		//验证码错误
#define LOG_DESC_ID_USER_LOGIN_USER_ERROR				"LoginFailedUsernameError"			//用户名错误
#define LOG_DESC_ID_USER_LOGIN_PASSWORD_ERROR			"LoginFailedPasswordError"			//用户密码错误
#define LOG_DESC_ID_USER_LOGIN_USER_LOCKED				"LoginFailedUserLocked"				//用户已锁定
#define LOG_DESC_ID_USER_LOGIN_USER_REPEATED			"LoginFailedUserRepeated"			//用户重复登录
		
#define LOG_DESC_ID_USER_LOGOUT_ABNORMALLY				"UserLogoutAbnormally"			//用户非正常退出
#define LOG_DESC_ID_USER_LOGOUT_DUE_TIMEOUT				"UserLogoutDueTimeout"			//用户超时退出






//系统维护  
#define LOG_DESC_ID_RESTART_DEVICE						"RestartDevice"					//重启设备
#define LOG_DESC_ID_RESET_DEVICE_TO_FACTORY_SETTING		"ResetDeviceToFactorySetting"	//恢复设备到出厂配置
#define LOG_DESC_ID_STARTUP_DEVICE						"StartUpDevice"					//启动设备
#define LOG_DESC_ID_SHUTDOWN_DEVICE						"ShutDownDevice"				//关闭设备
#define LOG_DESC_ID_MODIFY_SYSTEM_PASSWORD				"ModifySystemPassword"			//修改系统密码
#define LOG_DESC_ID_DOWNLOAD_OPERATIONLOG				"DownloadOperationLog"			//下载操作日志
#define LOG_DESC_ID_DOWNLOAD_ALARMLOG					"DownloadAlarmLog"				//下载报警日志
#define LOG_DESC_ID_COLLECT_LOG							"CollectLog"					//收集日志

//设备配置  
#define LOG_DESC_ID_CONFIGURE_ALARM_IN					"ConfigureAlarmIn"				//报警输入配置
#define LOG_DESC_ID_CONFIGURE_ALARM_IN_LINKAGE			"ConfigureAlarmInLinkage"		//报警联动
#define LOG_DESC_ID_CONFIGURE_ALARM_OUT					"ConfigureAlarmOut"				//报警输出配置
#define LOG_DESC_ID_CONFIGURE_ALARM_PARAM				"ConfigureAlarmParam"				//报警参数
#define LOG_DESC_ID_CONFIGURE_ALARM_SERVICE_PARAM		"ConfigureAlarmServiceParam"		//报警服务参数
#define LOG_DESC_ID_CONFIGURE_MOTION_DETECTION_LINKAGE	"ConfigureMotionDetectionLinkage"	//移动侦测配置
#define LOG_DESC_ID_CONFIGURE_AUDIO_DETECTION_LINKAGE	"ConfigureAudioDetectionLinkage"	//语音侦测配置
#define LOG_DESC_ID_CONFIGURE_DDNS						"ConfigureDDNS"					//DDNS配置
#define LOG_DESC_ID_CONFIGURE_HOST_NETWORK				"ConfigureHostNetwork"			//网络配置
#define LOG_DESC_ID_CONFIGURE_RS485						"ConfigureRS485"				//485串口配置
#define LOG_DESC_ID_CONFIGURE_UPDATE_PARAM				"ConfigureUpdateParam"			//升级配置
#define LOG_DESC_ID_CONFIGURE_NTP						"ConfigureNTP"					//NTP配置
#define LOG_DESC_ID_CONFIGURE_PPPOE						"ConfigurePPPoE"				//PPPoE拨号配置
#define LOG_DESC_ID_CONFIGURE_CAMERA_INFO				"ConfigureCameraInfo"			//摄像机信息配置
#define LOG_DESC_ID_CONFIGURE_RECORD_DIR				"ConfigureRecordDir"			//录像路径配置
#define LOG_DESC_ID_CONFIGURE_RECORD_POLICY				"ConfigureRecordPolicy"			//录像策略
#define LOG_DESC_ID_CONFIGURE_SNAPSHOT_DIR				"ConfigureSnapshotDir"			//抓拍路径配置
#define LOG_DESC_ID_CONFIGURE_PROTOCOL					"ConfigureProtocol"				//协议配置参数
#define LOG_DESC_ID_CONFIGURE_DEVICE_LANGUAGE			"ConfigureDeviceLanguage"		//设备语言配置
#define LOG_DESC_ID_CONFIGURE_SNAPSHOT_PARAM			"ConfigureSnapshotParam"		//抓拍参数配置
#define LOG_DESC_ID_CONFIGURE_SMTP						"ConfigureSMTP"					//SMTP参数配置
#define LOG_DESC_ID_CONFIGURE_DEVICE_ID					"ConfigureDeviceId"				//配置设备ID 
#define LOG_DESC_ID_CONFIGURE_DEVICE_NAME				"ConfigureDeviceName"			//配置设备名称
#define LOG_DESC_ID_CONFIGURE_DEVICE_TIME				"ConfigureDeviceTime"			//设备时间配置
#define LOG_DESC_ID_CONFIGURE_TIME_ZONE					"ConfigureTimeZone"				//时区配置
#define LOG_DESC_ID_CONFIGURE_REGISTER_PARAM			"ConfigureRegisterParam"		//设备注册配置
#define LOG_DESC_ID_CONFIGURE_LOUDHAILER				"ConfigureLoudhailer"			//扬声器配置
#define LOG_DESC_ID_CONFIGURE_TONE_ARM					"ConfigureToneArm"				//拾音器配置
#define LOG_DESC_ID_CONFIGURE_DISK_ALARM_PARAM			"ConfigureDiskAlarmParam"		//硬盘报警配置
#define LOG_DESC_ID_CONFIGURE_VIDEO_OSD						"ConfigureVideoOSD"			//OSD配置
#define LOG_DESC_ID_CONFIGURE_VIDEO_OSD_FONT				"ConfigureVideoOSDFont"	
#define LOG_DESC_ID_CONFIGURE_DEVICE_PORT					"ConfigureDevicePort"		//设备端口配置
#define LOG_DESC_ID_CONFIGURE_AVSTREAM_MULTICAST_ADDRESS	"ConfigureAVStreamMulticastAddress"	//音视频流多播地址名
#define LOG_DESC_ID_CONFIGURE_AVSTREAM_PARAM				"ConfigureAVStreamParam"			//音视频流配置
#define LOG_DESC_ID_CONFIGURE_CASH_REGISTER					"ConfigureCashRegister"				//点钞机配置
#define LOG_DESC_ID_CONFIGURE_BLIND_AREA					"ConfigureBlindArea"				//隐私遮挡
#define LOG_DESC_ID_CONFIGURE_3G_POLICY						"Configure3GPolicy"					//3G策略
#define LOG_DESC_ID_CONFIGURE_WIFI							"ConfigureWifi"						//Wifi参数配置
#define LOG_DESC_ID_CONFIGURE_WIFI_HOT_SPOT					"ConfigureWifiHotspot"				//Wifi热点参数配置
#define LOG_DESC_ID_CONFIGURE_BONJOUR						"ConfigureBonjour"					//Bonjour参数配置
#define LOG_DESC_ID_CONFIGURE_UPNP							"ConfigureUpnp"						//Upnp参数配置
#define LOG_DESC_ID_CONFIGURE_OCCLUSION_DETECTION_LINKAGE	"ConfigureOcclusionDetectionLinkage"//摄像机遮挡配置
#define LOG_DESC_ID_CONFIGURE_PTZ							"ConfigurePTZ"						//PTZ配置
#define LOG_DESC_ID_CONFIGURE_PTZ_KEYBOARD					"ConfigurePTZKeyboard"				//PTZ键盘配置
#define LOG_DESC_ID_CONFIGURE_RS232							"ConfigureRS232"					//RS232配置
#define LOG_DESC_ID_CONFIGURE_SOURCE_RESOLUTION				"ConfigureSourceResolution"			//配置源分辨率
#define LOG_DESC_ID_CONFIGURE_VIDEO_LOSE_DETECTION_LINKAGE	"ConfigureVideoLoseDetectionLinkage"//视频帧丢失报警事件
#define LOG_DESC_ID_CONFIGURE_WEB_PARAM						"ConfigureWebParam"					//Web参数配置
#define LOG_DESC_ID_CONFIGURE_BROADCAST						"ConfigureBroadcast"				//广播参数配置
#define LOG_DESC_ID_CONFIGURE_SNAPSHOT						"ConfigureSnapshot"					//抓图配置
#define LOG_DESC_ID_CONFIGURE_SNAPSHOT_POLICY				"ConfigureSnapshotPolicy"			//抓拍配置
#define LOG_DESC_ID_CONFIGURE_TRANSFER_PROTOCOL				"ConfigureTransferProtocol"			//通讯配置
#define LOG_DESC_ID_CONFIGURE_NETWORK_ALARM_PARAM			"ConfigureNetworkAlarmParam"		//网络报警配置
#define LOG_DESC_ID_CONFIGURE_DISK_ALARM_V2_PARAM			"ConfigureDiskAlarmV2Param"			//硬盘报警配置（含告警联动）
#define LOG_DESC_ID_CONFIGURE_SECURITY_PARAM				"ConfigureSecurityParam"		//目前支持配置Web登录方式(http/https)及是否加密(SDK通信SSL加密)
#define LOG_DESC_ID_CONFIGURE_MTU_PARAM						"ConfigureMTUParam"				//MTU配置
#define LOG_DESC_ID_CONFIGURE_SVCSTREAM_PARAM				"ConfigureSVCStreamParam"			//伴随流配置
//#define LOG_DESC_ID_CONFIGURE_IVA_INTRUSION_PARAM			"ConfigureAVIIntrusionParam"		//IVA库移动侦测配置
//#define LOG_DESC_ID_CONFIGURE_AVI_CAMERATAMPER_PARAM		"ConfigureAVICameraTamperParam"		//IVA库遮挡侦测配置
//#define LOG_DESC_ID_CONFIGURE_AVI_LINECOUNTING_PARAM		"ConfigureAVILineCountingParam"		//IVA库越界侦测配置
#define LOG_DESC_ID_CONFIGURE_PERIMETER_PARAM 						"ConfigureIntelligePerimeterParam"			//智能分析周界入侵
#define LOG_DESC_ID_CONFIGURE_ROI_PARAM						"ConfigureROIParam"					//ROI配置
#define LOG_DESC_ID_CONFIGURE_TRIP_WIRE_PARAM 						"ConfigureIntelligeTripWireParam"			//智能分析单绊线
#define LOG_DESC_ID_CONFIGURE_MULTI_TRIP_WIRE_PARAM 				"ConfigureIntelligeMultiTripWireParam"		//智能分析双绊线
#define LOG_DESC_ID_CONFIGURE_LOITER_PARAM 							"ConfigureIntelligeLoiterParam"				//智能分析徘徊
#define LOG_DESC_ID_CONFIGURE_MULTI_LOITER_PARAM 					"ConfigureIntelligeMultiLoiterParam"		//智能分析多人徘徊
#define LOG_DESC_ID_CONFIGURE_OBJECT_LEFT_PARAM 					"ConfigureIntelligeObjectLeftParam"			//智能分析物品遗留
#define LOG_DESC_ID_CONFIGURE_OBJECT_MOVED_PARAM 					"ConfigureIntelligeObjectMovedParam"		//智能分析物品移动
#define LOG_DESC_ID_CONFIGURE_ABNORMAL_SPEED_PARAM 					"ConfigureIntelligeAbnormalSpeedParam"		//智能分析非正常速度
#define LOG_DESC_ID_CONFIGURE_CONVERSE_PARAM 						"ConfigureIntelligeConverseParam"			//智能分析逆行
#define LOG_DESC_ID_CONFIGURE_NO_PARKING_PARAM 						"ConfigureIntelligeNoParkingParam"			//智能分析非法停车
#define LOG_DESC_ID_CONFIGURE_CAMERA_TAMPER_PARAM 					"ConfigureIntelligeCameraTamperParam"		//智能分析视频遮挡
#define LOG_DESC_ID_CONFIGURE_CAMERA_MOVED_PARAM 					"ConfigureIntelligeCameraMovedParam"		//智能分析摄像机移动
#define LOG_DESC_ID_CONFIGURE_MOTION_DETECTION_PARAM_V3 			"ConfigureIntelligeMotionDetectionParamV3"	//智能分析移动侦测
#define LOG_DESC_ID_CONFIGURE_ADVANCED_PARAM 						"ConfigureIntelligeAdvancedParam"			//智能分析高级参数设置
#define LOG_DESC_ID_CONFIGURE_SIGNALBAD_PARAM 						"ConfigureIntelligeSignalBadParam"			//智能分析视频信号异常参数设置


//录像操作  
#define LOG_DESC_ID_DELETE_FTP_RECORD_FILE		"DeleteFtpRecordFile"	//FTP文件删除
#define LOG_DESC_ID_LOCK_RECORD_FILE			"LockRecordFile"		//录像加锁
#define LOG_DESC_ID_UNLOCK_RECORD_FILE			"UnLockRecordFile"		//录像解锁
#define LOG_DESC_ID_PLAY_RECORD					"PlayRecord"			//播放录像
#define LOG_DESC_ID_START_MANUAL_RECORD			"StartManualRecord"		//启动手动录像
#define LOG_DESC_ID_STOP_MANUAL_RECORD			"StopManualRecord"		//停止手动录像
#define LOG_DESC_ID_DISK_FORMAT					"DiskFormat"			//磁盘格式化
#define LOG_DESC_ID_DISK_FORMAT_SUCCESS			"DiskFormatSuccess"			//磁盘格式化成功
#define LOG_DESC_ID_DISK_FORMAT_FAIL			"DiskFormatFailed"			//磁盘格式化失败

//音视频控制  
#define LOG_DESC_ID_CONFIGURE_PTZ_TIMER				"ConfigurePTZTimer"				//PTZ时间配置
#define LOG_DESC_ID_OPEN_VIDEO_OUT					"OpenVideoOut"					//开启模拟输出
#define LOG_DESC_ID_CLOSE_VIDEO_OUT					"CloseVideoOut"					//关闭模拟输出
#define LOG_DESC_ID_SAVE_SENSOR_CONFIGURE			"SaveSensorConfigure"			//保存前端配置
#define LOG_DESC_ID_RESET_SENSOR_TO_FACTORY_SETTING	"ResetSensorToFactorySetting"	//复位前端到出厂配置

//音视频点播  
#define LOG_DESC_ID_START_INTERPHONE			"StartInterPhone"		//打开语音对讲
#define LOG_DESC_ID_STOP_INTERPHONE				"StopInterPhone"		//关闭语音对讲
#define LOG_DESC_ID_START_MICROPHONE			"StartMicrophone"		//打开麦克风
#define LOG_DESC_ID_STOP_MICROPHONE				"StopMicrophone"		//关闭麦克风
#define LOG_DESC_ID_START_VIDEO_STREAM			"StartVideoStream"		//打开视频流
#define LOG_DESC_ID_STOP_VIDEO_STREAM			"StopVideoStream"		//关闭视频流
#define LOG_DESC_ID_START_AUDIO_STREAM			"StartAudioStream"		//开始音频
#define LOG_DESC_ID_STOP_AUDIO_STREAM			"StopAudioStream"		//停止音频
#define LOG_DESC_ID_START_INTELLIGENCEANALYSE_STREAM			"StartIntelligenceAnalyseStream"		//开始智能分析流
#define LOG_DESC_ID_STOP_INTELLIGENCEANALYSE_STREAM			"StopIntelligenceAnalyseStream"		//停止智能分析流

//音频报警数据请求
#define LOG_DESC_ID_RESQUEST_AUDIO_ALARM_DATA			"RequestAudioAlarmData"		//请求音频报警数据操作

//add in 2015-04-15 for NVR
#define LOG_NVR_ID_USER_LOGIN							"UserLogin"						//用户登录
#define LOG_NVR_ID_USER_LOGOUT							"UserLogout"					//用户注销
#define LOG_NVR_ID_UPDATE_PRIVILEGE_USER				"UpdatePrivilegeUser"			//更新权限用户
#define LOG_NVR_ID_UPDATE_PRIVILEGE_GROUP				"UpdatePrivilegeGroup"			//更新权限组
#define LOG_NVR_ID_ADD_PRIVILEGE_USER					"AddPrivilegeUser"				//添加权限用户
#define LOG_NVR_ID_DELETE_PRIVILEGE_USER				"DeletePrivilegeUser"			//删除权限用户
#define LOG_NVR_ID_MODIFY_PRIVILEGE_USER				"ModifyPrivilegeUser"			//修改权限用户
#define LOG_NVR_ID_LOCK_PRIVILEGE_USER					"LockPrivilegeUser"				//锁定权限用户
#define LOG_NVR_ID_UNLOCK_PRIVILEGE_USER				"UnlockPrivilegeUser"			//解锁权限用户
#define LOG_NVR_ID_ADD_PRIVILEGE_GROUP					"AddPrivilegeGroup"				//添加权限组
#define LOG_NVR_ID_DELETE_PRIVILEGE_GROUP				"DeletePrivilegeGroup"			//删除权限组
#define LOG_NVR_ID_MODIFY_PRIVILEGE_GROUP				"ModifyPrivilegeGroup"			//修改权限组

#define LOG_NVR_ID_ADD_CHANNEL							"AddChannel"					//添加通道
#define LOG_NVR_ID_DELETE_CHANNEL						"DeleteChannel"					//删除通道

#define LOG_NVR_ID_ADD_LIVEVIDEO						"AddLiveVideo"					//添加实时视频
#define LOG_NVR_ID_DELETE_LIVEVIDEO						"DeleteLiveVideo"				//删除实时视频
#define LOG_NVR_ID_START_LIVEVIDEO						"PlayLiveVideo"					//播放实时视频
#define LOG_NVR_ID_STOP_LIVEVIDEO						"PauseLiveVideo"				//停止实时视频
#define LOG_NVR_ID_START_AUDIO_PLAY						"StartAudioPlay"				//打开音频
#define LOG_NVR_ID_STOP_AUDIO_PLAY						"StopAudioPlay"					//关闭音频
#define LOG_NVR_ID_CONFIGURE_AVSTREAM					"ConfigureAVStream"				//配置音视频流

#define LOG_NVR_ID_START_RECORD							"StartRecord"					//开始录像
#define LOG_NVR_ID_STOP_RECORD							"StopRecord"					//停止录像
#define LOG_NVR_ID_START_MANUAL_RECORD					"StartManualRecord"				//开始手动录像
#define LOG_NVR_ID_STOP_MANUAL_RECORD					"StopManualRecord"				//停止手动录像
#define LOG_NVR_ID_DELETE_RECORD						"DeleteRecord"					//删除录像
#define LOG_NVR_ID_CONFIGURE_RECORD_POLICY				"ConfigureRecordPolicy"			//配置录像策略
#define LOG_NVR_ID_DELETE_RECORD_POLICY					"DeleteRecordPolicy"			//删除录像策略
#define LOG_NVR_ID_RECORD_STORAGE						"ConfigureRecordStorage"		//配置录像存储
#define LOG_NVR_ID_FORMAT_DISK							"FormatDisk"					//格式化磁盘
#define LOG_NVR_ID_INSTALL_DISK							"InstallDisk"					//加载磁盘
#define LOG_NVR_ID_UN_INSTALL_DISK						"UnInstallDisk"					//卸载磁盘

#define LOG_NVR_ID_START_RECORD_PLAYBACK				"StartRecordPlayBack"			//开始录像回放
#define LOG_NVR_ID_PAUSE_RECORD_PLAYBACK				"PauseRecordPlayBack"			//暂停录像回放
#define LOG_NVR_ID_STOP_RECORD_PLAYBACK					"StopRecordPlayBack"			//停止录像回放
#define LOG_NVR_ID_ADD_RECORD_PLAYBACK					"AddRecordPlayBack"				//添加一路录像回放
#define LOG_NVR_ID_REMOVE_RECORD_PLAYBACK				"RemoveRecordPlayBack"			//移除一路录像回放
#define LOG_NVR_ID_REMOVE_ALL_RECORD_PLAYBACK			"RemoveAllRecordPlayBack"		//移除所有录像回放
#define LOG_NVR_ID_FAST_FORWARD_RECORD_PLAYBACK			"FastForwardRecordPlayBack"		//录像回放快进
#define LOG_NVR_ID_FAST_BACKWARD_RECORD_PLAYBACK		"FastBackwardRecordPlayBack"	//录像回放快退

#define LOG_NVR_ID_START_RECORD_BACKUP					"StartRecordBackup"				//开始录像备份
#define LOG_NVR_ID_PAUSE_RECORD_BACKUP					"PauseRecordBackup"				//暂停录像备份
#define LOG_NVR_ID_STOP_RECORD_BACKUP					"StopRecordBackup"				//停止录像备份
#define LOG_NVR_ID_ADD_RECORD_BACKUP_TASK				"AddRecordBackupTask"			//添加录像备份任务
#define LOG_NVR_ID_DELETE_RECORD_BACKUP_TASK			"DeleteRecordBackupTask"		//删除录像备份任务

#define LOG_NVR_ID_CONFIGURE_DEVICE_ID					"ConfigureDeviceId"				//配置设备ID 
#define LOG_NVR_ID_CONFIGURE_DEVICE_NAME				"ConfigureDeviceName"			//配置设备名称
#define LOG_NVR_ID_CONFIGURE_NETWORK					"ConfigureNetwork"				//配置网络
#define LOG_NVR_ID_CONFIGURE_DDNS						"ConfigureDDNS"					//配置DDNS
#define LOG_NVR_ID_CONFIGURE_PPPOE						"ConfigurePPPoE"				//配置PPPoE
#define LOG_NVR_ID_SYNC_DEVICES_TIME					"SyncDevicesTime"				//同步设备时间
#define LOG_NVR_ID_CONFIGURE_DEVICE_TIME				"ConfigureDeviceTime"			//配置设备时间
#define LOG_NVR_ID_CONFIGURE_TIME_ZONE					"ConfigureTimeZone"				//配置时区
#define LOG_NVR_ID_START_TIME_REBOOT_SERVICE			"StartTimeRebootService"		//开启定时重启
#define LOG_NVR_ID_STOP_TIME_REBOOT_SERVICE				"StopTimeRebootService"			//关闭定时重启
#define LOG_NVR_ID_RESET_DEVICE_TO_FACTORY_SETTING		"ResetDeviceToFactorySetting"	//恢复设备到出厂配置
#define LOG_NVR_ID_RESTART_DEVICE						"RestartDevice"					//重启设备

#endif	//_LOG_INFO_DESCRIPTION_H_



