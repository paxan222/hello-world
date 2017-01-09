#ifndef _LOG_INFO_DESCRIPTION_H_
#define _LOG_INFO_DESCRIPTION_H_



//�û�����  
#define LOG_DESC_ID_ADD_PRIVILEGE_USER					"AddPrivilegeUser"				//���Ȩ���û�
#define LOG_DESC_ID_DELETE_PRIVILEGE_USER				"DeletePrivilegeUser"			//ɾ��Ȩ���û�

#define LOG_DESC_ID_MODIFY_PRIVILEGE_USER				"ModifyPrivilegeUser"			//�޸�Ȩ���û�
#define LOG_DESC_ID_MODIFY_PRIVILEGE_USER_PASSWORD		"ModifyPrivilegeUserPassword"	//�޸�Ȩ���û�����
#define LOG_DESC_ID_MODIFY_PRIVILEGE_USER_GROUP			"ModifyPrivilegeUserGroup"		//�޸�Ȩ���û����

#define LOG_DESC_ID_LOCK_PRIVILEGE_USER					"LockPrivilegeUser"				//����Ȩ���û�
#define LOG_DESC_ID_UNLOCK_PRIVILEGE_USER				"UnlockPrivilegeUser"			//����Ȩ���û�

#define LOG_DESC_ID_AUTO_LOCK_PRIVILEGE_USER			"AutoLockPrivilegeUser"			//�Զ�����Ȩ���û�
#define LOG_DESC_ID_AUTO_UNLOCK_PRIVILEGE_USER			"AutoUnlockPrivilegeUser"		//�Զ�����Ȩ���û�

#define LOG_DESC_ID_ADD_PRIVILEGE_GROUP					"AddPrivilegeGroup"				//���Ȩ����
#define LOG_DESC_ID_DELETE_PRIVILEGE_GROUP				"DeletePrivilegeGroup"			//ɾ��Ȩ����
#define LOG_DESC_ID_MODIFY_PRIVILEGE_GROUP				"ModifyPrivilegeGroup"			//�޸�Ȩ����

#define LOG_DESC_ID_CONFIGURE_GROUP_PRIVILEGE			"ConfigureGroupPrivilege"		//������Ȩ��

#define	LOG_DESC_ID_ADD_USER_MANAGER_PRIVILEGE			"AddPrivilegeManagerPrivilege"		//�޸��û�����Ȩ��
#define	LOG_DESC_ID_REMOVE_USER_MANAGER_PRIVILEGE		"RemovePrivilegeManagerPrivilege"

#define	LOG_DESC_ID_ADD_SYSTEM_MANAGER_PRIVILEGE		"AddSystemMaintenancePrivilege"		//�޸�ϵͳ����Ȩ��
#define	LOG_DESC_ID_REMOVE_SYSTEM_MANAGER_PRIVILEGE		"RemoveSystemMaintenancePrivilege"

#define	LOG_DESC_ID_ADD_DEVICE_CONFIG_PRIVILEGE			"AddParameterConfigurePrivilege"		//�޸��豸����Ȩ��
#define	LOG_DESC_ID_REMOVE_DEVICE_CONFIG_PRIVILEGE		"RemoveParameterConfigurePrivilege"

#define	LOG_DESC_ID_ADD_RECORD_CTRL_PRIVILEGE			"AddRecordOperationPrivilege"		//�޸�¼�����Ȩ��
#define	LOG_DESC_ID_REMOVE_RECORD_CTRL_PRIVILEGE		"RemoveRecordOperationPrivilege"

#define	LOG_DESC_ID_ADD_LIVEVIDEO_CTRL_PRIVILEGE		"AddVideoCtrlPrivilege"		//�޸���Ƶ����Ȩ��
#define	LOG_DESC_ID_REMOVE_LIVEVIDEO_CTRL_PRIVILEGE		"RemoveVideoCtrlPrivilege"

#define	LOG_DESC_ID_ADD_LIVEVIDEO_PRIVILEGE				"AddLiveVideoPrivilege"			//�޸�ʵʱ��Ƶ�㲥Ȩ��
#define	LOG_DESC_ID_REMOVE_LIVEVIDEO_PRIVILEGE			"RemoveLiveVideoPrivilege"

#define LOG_DESC_ID_CHANGE_SELF_PASSWORD				"ChangeSelfPassword"			//�޸��Լ�������
#define LOG_DESC_ID_CHANGE_SELF_PASSWORD_SUCCESS		"ChangeSelfPasswordSuccess"		//�޸��Լ�������ɹ�
#define LOG_DESC_ID_CHANGE_SELF_PASSWORD_FAIL			"ChangeSelfPasswordFailed"		//�޸��Լ����������

#define LOG_DESC_ID_USER_LOGIN							"UserLogin"						//�û���¼
#define LOG_DESC_ID_USER_LOGOUT							"UserLogout"					//�û�ע��

#define LOG_DESC_ID_USER_LOGIN_SUCCESS					"UserLoginSuccess"					//��¼�ɹ�
#define LOG_DESC_ID_USER_LOGIN_VALIDATECODE_ERROR		"LoginFailedValidateCodeError"		//��֤�����
#define LOG_DESC_ID_USER_LOGIN_USER_ERROR				"LoginFailedUsernameError"			//�û�������
#define LOG_DESC_ID_USER_LOGIN_PASSWORD_ERROR			"LoginFailedPasswordError"			//�û��������
#define LOG_DESC_ID_USER_LOGIN_USER_LOCKED				"LoginFailedUserLocked"				//�û�������
#define LOG_DESC_ID_USER_LOGIN_USER_REPEATED			"LoginFailedUserRepeated"			//�û��ظ���¼
		
#define LOG_DESC_ID_USER_LOGOUT_ABNORMALLY				"UserLogoutAbnormally"			//�û��������˳�
#define LOG_DESC_ID_USER_LOGOUT_DUE_TIMEOUT				"UserLogoutDueTimeout"			//�û���ʱ�˳�






//ϵͳά��  
#define LOG_DESC_ID_RESTART_DEVICE						"RestartDevice"					//�����豸
#define LOG_DESC_ID_RESET_DEVICE_TO_FACTORY_SETTING		"ResetDeviceToFactorySetting"	//�ָ��豸����������
#define LOG_DESC_ID_STARTUP_DEVICE						"StartUpDevice"					//�����豸
#define LOG_DESC_ID_SHUTDOWN_DEVICE						"ShutDownDevice"				//�ر��豸
#define LOG_DESC_ID_MODIFY_SYSTEM_PASSWORD				"ModifySystemPassword"			//�޸�ϵͳ����
#define LOG_DESC_ID_DOWNLOAD_OPERATIONLOG				"DownloadOperationLog"			//���ز�����־
#define LOG_DESC_ID_DOWNLOAD_ALARMLOG					"DownloadAlarmLog"				//���ر�����־
#define LOG_DESC_ID_COLLECT_LOG							"CollectLog"					//�ռ���־

//�豸����  
#define LOG_DESC_ID_CONFIGURE_ALARM_IN					"ConfigureAlarmIn"				//������������
#define LOG_DESC_ID_CONFIGURE_ALARM_IN_LINKAGE			"ConfigureAlarmInLinkage"		//��������
#define LOG_DESC_ID_CONFIGURE_ALARM_OUT					"ConfigureAlarmOut"				//�����������
#define LOG_DESC_ID_CONFIGURE_ALARM_PARAM				"ConfigureAlarmParam"				//��������
#define LOG_DESC_ID_CONFIGURE_ALARM_SERVICE_PARAM		"ConfigureAlarmServiceParam"		//�����������
#define LOG_DESC_ID_CONFIGURE_MOTION_DETECTION_LINKAGE	"ConfigureMotionDetectionLinkage"	//�ƶ��������
#define LOG_DESC_ID_CONFIGURE_AUDIO_DETECTION_LINKAGE	"ConfigureAudioDetectionLinkage"	//�����������
#define LOG_DESC_ID_CONFIGURE_DDNS						"ConfigureDDNS"					//DDNS����
#define LOG_DESC_ID_CONFIGURE_HOST_NETWORK				"ConfigureHostNetwork"			//��������
#define LOG_DESC_ID_CONFIGURE_RS485						"ConfigureRS485"				//485��������
#define LOG_DESC_ID_CONFIGURE_UPDATE_PARAM				"ConfigureUpdateParam"			//��������
#define LOG_DESC_ID_CONFIGURE_NTP						"ConfigureNTP"					//NTP����
#define LOG_DESC_ID_CONFIGURE_PPPOE						"ConfigurePPPoE"				//PPPoE��������
#define LOG_DESC_ID_CONFIGURE_CAMERA_INFO				"ConfigureCameraInfo"			//�������Ϣ����
#define LOG_DESC_ID_CONFIGURE_RECORD_DIR				"ConfigureRecordDir"			//¼��·������
#define LOG_DESC_ID_CONFIGURE_RECORD_POLICY				"ConfigureRecordPolicy"			//¼�����
#define LOG_DESC_ID_CONFIGURE_SNAPSHOT_DIR				"ConfigureSnapshotDir"			//ץ��·������
#define LOG_DESC_ID_CONFIGURE_PROTOCOL					"ConfigureProtocol"				//Э�����ò���
#define LOG_DESC_ID_CONFIGURE_DEVICE_LANGUAGE			"ConfigureDeviceLanguage"		//�豸��������
#define LOG_DESC_ID_CONFIGURE_SNAPSHOT_PARAM			"ConfigureSnapshotParam"		//ץ�Ĳ�������
#define LOG_DESC_ID_CONFIGURE_SMTP						"ConfigureSMTP"					//SMTP��������
#define LOG_DESC_ID_CONFIGURE_DEVICE_ID					"ConfigureDeviceId"				//�����豸ID 
#define LOG_DESC_ID_CONFIGURE_DEVICE_NAME				"ConfigureDeviceName"			//�����豸����
#define LOG_DESC_ID_CONFIGURE_DEVICE_TIME				"ConfigureDeviceTime"			//�豸ʱ������
#define LOG_DESC_ID_CONFIGURE_TIME_ZONE					"ConfigureTimeZone"				//ʱ������
#define LOG_DESC_ID_CONFIGURE_REGISTER_PARAM			"ConfigureRegisterParam"		//�豸ע������
#define LOG_DESC_ID_CONFIGURE_LOUDHAILER				"ConfigureLoudhailer"			//����������
#define LOG_DESC_ID_CONFIGURE_TONE_ARM					"ConfigureToneArm"				//ʰ��������
#define LOG_DESC_ID_CONFIGURE_DISK_ALARM_PARAM			"ConfigureDiskAlarmParam"		//Ӳ�̱�������
#define LOG_DESC_ID_CONFIGURE_VIDEO_OSD						"ConfigureVideoOSD"			//OSD����
#define LOG_DESC_ID_CONFIGURE_VIDEO_OSD_FONT				"ConfigureVideoOSDFont"	
#define LOG_DESC_ID_CONFIGURE_DEVICE_PORT					"ConfigureDevicePort"		//�豸�˿�����
#define LOG_DESC_ID_CONFIGURE_AVSTREAM_MULTICAST_ADDRESS	"ConfigureAVStreamMulticastAddress"	//����Ƶ���ಥ��ַ��
#define LOG_DESC_ID_CONFIGURE_AVSTREAM_PARAM				"ConfigureAVStreamParam"			//����Ƶ������
#define LOG_DESC_ID_CONFIGURE_CASH_REGISTER					"ConfigureCashRegister"				//�㳮������
#define LOG_DESC_ID_CONFIGURE_BLIND_AREA					"ConfigureBlindArea"				//��˽�ڵ�
#define LOG_DESC_ID_CONFIGURE_3G_POLICY						"Configure3GPolicy"					//3G����
#define LOG_DESC_ID_CONFIGURE_WIFI							"ConfigureWifi"						//Wifi��������
#define LOG_DESC_ID_CONFIGURE_WIFI_HOT_SPOT					"ConfigureWifiHotspot"				//Wifi�ȵ��������
#define LOG_DESC_ID_CONFIGURE_BONJOUR						"ConfigureBonjour"					//Bonjour��������
#define LOG_DESC_ID_CONFIGURE_UPNP							"ConfigureUpnp"						//Upnp��������
#define LOG_DESC_ID_CONFIGURE_OCCLUSION_DETECTION_LINKAGE	"ConfigureOcclusionDetectionLinkage"//������ڵ�����
#define LOG_DESC_ID_CONFIGURE_PTZ							"ConfigurePTZ"						//PTZ����
#define LOG_DESC_ID_CONFIGURE_PTZ_KEYBOARD					"ConfigurePTZKeyboard"				//PTZ��������
#define LOG_DESC_ID_CONFIGURE_RS232							"ConfigureRS232"					//RS232����
#define LOG_DESC_ID_CONFIGURE_SOURCE_RESOLUTION				"ConfigureSourceResolution"			//����Դ�ֱ���
#define LOG_DESC_ID_CONFIGURE_VIDEO_LOSE_DETECTION_LINKAGE	"ConfigureVideoLoseDetectionLinkage"//��Ƶ֡��ʧ�����¼�
#define LOG_DESC_ID_CONFIGURE_WEB_PARAM						"ConfigureWebParam"					//Web��������
#define LOG_DESC_ID_CONFIGURE_BROADCAST						"ConfigureBroadcast"				//�㲥��������
#define LOG_DESC_ID_CONFIGURE_SNAPSHOT						"ConfigureSnapshot"					//ץͼ����
#define LOG_DESC_ID_CONFIGURE_SNAPSHOT_POLICY				"ConfigureSnapshotPolicy"			//ץ������
#define LOG_DESC_ID_CONFIGURE_TRANSFER_PROTOCOL				"ConfigureTransferProtocol"			//ͨѶ����
#define LOG_DESC_ID_CONFIGURE_NETWORK_ALARM_PARAM			"ConfigureNetworkAlarmParam"		//���籨������
#define LOG_DESC_ID_CONFIGURE_DISK_ALARM_V2_PARAM			"ConfigureDiskAlarmV2Param"			//Ӳ�̱������ã����澯������
#define LOG_DESC_ID_CONFIGURE_SECURITY_PARAM				"ConfigureSecurityParam"		//Ŀǰ֧������Web��¼��ʽ(http/https)���Ƿ����(SDKͨ��SSL����)
#define LOG_DESC_ID_CONFIGURE_MTU_PARAM						"ConfigureMTUParam"				//MTU����
#define LOG_DESC_ID_CONFIGURE_SVCSTREAM_PARAM				"ConfigureSVCStreamParam"			//����������
//#define LOG_DESC_ID_CONFIGURE_IVA_INTRUSION_PARAM			"ConfigureAVIIntrusionParam"		//IVA���ƶ��������
//#define LOG_DESC_ID_CONFIGURE_AVI_CAMERATAMPER_PARAM		"ConfigureAVICameraTamperParam"		//IVA���ڵ��������
//#define LOG_DESC_ID_CONFIGURE_AVI_LINECOUNTING_PARAM		"ConfigureAVILineCountingParam"		//IVA��Խ���������
#define LOG_DESC_ID_CONFIGURE_PERIMETER_PARAM 						"ConfigureIntelligePerimeterParam"			//���ܷ����ܽ�����
#define LOG_DESC_ID_CONFIGURE_ROI_PARAM						"ConfigureROIParam"					//ROI����
#define LOG_DESC_ID_CONFIGURE_TRIP_WIRE_PARAM 						"ConfigureIntelligeTripWireParam"			//���ܷ���������
#define LOG_DESC_ID_CONFIGURE_MULTI_TRIP_WIRE_PARAM 				"ConfigureIntelligeMultiTripWireParam"		//���ܷ���˫����
#define LOG_DESC_ID_CONFIGURE_LOITER_PARAM 							"ConfigureIntelligeLoiterParam"				//���ܷ����ǻ�
#define LOG_DESC_ID_CONFIGURE_MULTI_LOITER_PARAM 					"ConfigureIntelligeMultiLoiterParam"		//���ܷ��������ǻ�
#define LOG_DESC_ID_CONFIGURE_OBJECT_LEFT_PARAM 					"ConfigureIntelligeObjectLeftParam"			//���ܷ�����Ʒ����
#define LOG_DESC_ID_CONFIGURE_OBJECT_MOVED_PARAM 					"ConfigureIntelligeObjectMovedParam"		//���ܷ�����Ʒ�ƶ�
#define LOG_DESC_ID_CONFIGURE_ABNORMAL_SPEED_PARAM 					"ConfigureIntelligeAbnormalSpeedParam"		//���ܷ����������ٶ�
#define LOG_DESC_ID_CONFIGURE_CONVERSE_PARAM 						"ConfigureIntelligeConverseParam"			//���ܷ�������
#define LOG_DESC_ID_CONFIGURE_NO_PARKING_PARAM 						"ConfigureIntelligeNoParkingParam"			//���ܷ����Ƿ�ͣ��
#define LOG_DESC_ID_CONFIGURE_CAMERA_TAMPER_PARAM 					"ConfigureIntelligeCameraTamperParam"		//���ܷ�����Ƶ�ڵ�
#define LOG_DESC_ID_CONFIGURE_CAMERA_MOVED_PARAM 					"ConfigureIntelligeCameraMovedParam"		//���ܷ���������ƶ�
#define LOG_DESC_ID_CONFIGURE_MOTION_DETECTION_PARAM_V3 			"ConfigureIntelligeMotionDetectionParamV3"	//���ܷ����ƶ����
#define LOG_DESC_ID_CONFIGURE_ADVANCED_PARAM 						"ConfigureIntelligeAdvancedParam"			//���ܷ����߼���������
#define LOG_DESC_ID_CONFIGURE_SIGNALBAD_PARAM 						"ConfigureIntelligeSignalBadParam"			//���ܷ�����Ƶ�ź��쳣��������


//¼�����  
#define LOG_DESC_ID_DELETE_FTP_RECORD_FILE		"DeleteFtpRecordFile"	//FTP�ļ�ɾ��
#define LOG_DESC_ID_LOCK_RECORD_FILE			"LockRecordFile"		//¼�����
#define LOG_DESC_ID_UNLOCK_RECORD_FILE			"UnLockRecordFile"		//¼�����
#define LOG_DESC_ID_PLAY_RECORD					"PlayRecord"			//����¼��
#define LOG_DESC_ID_START_MANUAL_RECORD			"StartManualRecord"		//�����ֶ�¼��
#define LOG_DESC_ID_STOP_MANUAL_RECORD			"StopManualRecord"		//ֹͣ�ֶ�¼��
#define LOG_DESC_ID_DISK_FORMAT					"DiskFormat"			//���̸�ʽ��
#define LOG_DESC_ID_DISK_FORMAT_SUCCESS			"DiskFormatSuccess"			//���̸�ʽ���ɹ�
#define LOG_DESC_ID_DISK_FORMAT_FAIL			"DiskFormatFailed"			//���̸�ʽ��ʧ��

//����Ƶ����  
#define LOG_DESC_ID_CONFIGURE_PTZ_TIMER				"ConfigurePTZTimer"				//PTZʱ������
#define LOG_DESC_ID_OPEN_VIDEO_OUT					"OpenVideoOut"					//����ģ�����
#define LOG_DESC_ID_CLOSE_VIDEO_OUT					"CloseVideoOut"					//�ر�ģ�����
#define LOG_DESC_ID_SAVE_SENSOR_CONFIGURE			"SaveSensorConfigure"			//����ǰ������
#define LOG_DESC_ID_RESET_SENSOR_TO_FACTORY_SETTING	"ResetSensorToFactorySetting"	//��λǰ�˵���������

//����Ƶ�㲥  
#define LOG_DESC_ID_START_INTERPHONE			"StartInterPhone"		//�������Խ�
#define LOG_DESC_ID_STOP_INTERPHONE				"StopInterPhone"		//�ر������Խ�
#define LOG_DESC_ID_START_MICROPHONE			"StartMicrophone"		//����˷�
#define LOG_DESC_ID_STOP_MICROPHONE				"StopMicrophone"		//�ر���˷�
#define LOG_DESC_ID_START_VIDEO_STREAM			"StartVideoStream"		//����Ƶ��
#define LOG_DESC_ID_STOP_VIDEO_STREAM			"StopVideoStream"		//�ر���Ƶ��
#define LOG_DESC_ID_START_AUDIO_STREAM			"StartAudioStream"		//��ʼ��Ƶ
#define LOG_DESC_ID_STOP_AUDIO_STREAM			"StopAudioStream"		//ֹͣ��Ƶ
#define LOG_DESC_ID_START_INTELLIGENCEANALYSE_STREAM			"StartIntelligenceAnalyseStream"		//��ʼ���ܷ�����
#define LOG_DESC_ID_STOP_INTELLIGENCEANALYSE_STREAM			"StopIntelligenceAnalyseStream"		//ֹͣ���ܷ�����

//��Ƶ������������
#define LOG_DESC_ID_RESQUEST_AUDIO_ALARM_DATA			"RequestAudioAlarmData"		//������Ƶ�������ݲ���

//add in 2015-04-15 for NVR
#define LOG_NVR_ID_USER_LOGIN							"UserLogin"						//�û���¼
#define LOG_NVR_ID_USER_LOGOUT							"UserLogout"					//�û�ע��
#define LOG_NVR_ID_UPDATE_PRIVILEGE_USER				"UpdatePrivilegeUser"			//����Ȩ���û�
#define LOG_NVR_ID_UPDATE_PRIVILEGE_GROUP				"UpdatePrivilegeGroup"			//����Ȩ����
#define LOG_NVR_ID_ADD_PRIVILEGE_USER					"AddPrivilegeUser"				//���Ȩ���û�
#define LOG_NVR_ID_DELETE_PRIVILEGE_USER				"DeletePrivilegeUser"			//ɾ��Ȩ���û�
#define LOG_NVR_ID_MODIFY_PRIVILEGE_USER				"ModifyPrivilegeUser"			//�޸�Ȩ���û�
#define LOG_NVR_ID_LOCK_PRIVILEGE_USER					"LockPrivilegeUser"				//����Ȩ���û�
#define LOG_NVR_ID_UNLOCK_PRIVILEGE_USER				"UnlockPrivilegeUser"			//����Ȩ���û�
#define LOG_NVR_ID_ADD_PRIVILEGE_GROUP					"AddPrivilegeGroup"				//���Ȩ����
#define LOG_NVR_ID_DELETE_PRIVILEGE_GROUP				"DeletePrivilegeGroup"			//ɾ��Ȩ����
#define LOG_NVR_ID_MODIFY_PRIVILEGE_GROUP				"ModifyPrivilegeGroup"			//�޸�Ȩ����

#define LOG_NVR_ID_ADD_CHANNEL							"AddChannel"					//���ͨ��
#define LOG_NVR_ID_DELETE_CHANNEL						"DeleteChannel"					//ɾ��ͨ��

#define LOG_NVR_ID_ADD_LIVEVIDEO						"AddLiveVideo"					//���ʵʱ��Ƶ
#define LOG_NVR_ID_DELETE_LIVEVIDEO						"DeleteLiveVideo"				//ɾ��ʵʱ��Ƶ
#define LOG_NVR_ID_START_LIVEVIDEO						"PlayLiveVideo"					//����ʵʱ��Ƶ
#define LOG_NVR_ID_STOP_LIVEVIDEO						"PauseLiveVideo"				//ֹͣʵʱ��Ƶ
#define LOG_NVR_ID_START_AUDIO_PLAY						"StartAudioPlay"				//����Ƶ
#define LOG_NVR_ID_STOP_AUDIO_PLAY						"StopAudioPlay"					//�ر���Ƶ
#define LOG_NVR_ID_CONFIGURE_AVSTREAM					"ConfigureAVStream"				//��������Ƶ��

#define LOG_NVR_ID_START_RECORD							"StartRecord"					//��ʼ¼��
#define LOG_NVR_ID_STOP_RECORD							"StopRecord"					//ֹͣ¼��
#define LOG_NVR_ID_START_MANUAL_RECORD					"StartManualRecord"				//��ʼ�ֶ�¼��
#define LOG_NVR_ID_STOP_MANUAL_RECORD					"StopManualRecord"				//ֹͣ�ֶ�¼��
#define LOG_NVR_ID_DELETE_RECORD						"DeleteRecord"					//ɾ��¼��
#define LOG_NVR_ID_CONFIGURE_RECORD_POLICY				"ConfigureRecordPolicy"			//����¼�����
#define LOG_NVR_ID_DELETE_RECORD_POLICY					"DeleteRecordPolicy"			//ɾ��¼�����
#define LOG_NVR_ID_RECORD_STORAGE						"ConfigureRecordStorage"		//����¼��洢
#define LOG_NVR_ID_FORMAT_DISK							"FormatDisk"					//��ʽ������
#define LOG_NVR_ID_INSTALL_DISK							"InstallDisk"					//���ش���
#define LOG_NVR_ID_UN_INSTALL_DISK						"UnInstallDisk"					//ж�ش���

#define LOG_NVR_ID_START_RECORD_PLAYBACK				"StartRecordPlayBack"			//��ʼ¼��ط�
#define LOG_NVR_ID_PAUSE_RECORD_PLAYBACK				"PauseRecordPlayBack"			//��ͣ¼��ط�
#define LOG_NVR_ID_STOP_RECORD_PLAYBACK					"StopRecordPlayBack"			//ֹͣ¼��ط�
#define LOG_NVR_ID_ADD_RECORD_PLAYBACK					"AddRecordPlayBack"				//���һ·¼��ط�
#define LOG_NVR_ID_REMOVE_RECORD_PLAYBACK				"RemoveRecordPlayBack"			//�Ƴ�һ·¼��ط�
#define LOG_NVR_ID_REMOVE_ALL_RECORD_PLAYBACK			"RemoveAllRecordPlayBack"		//�Ƴ�����¼��ط�
#define LOG_NVR_ID_FAST_FORWARD_RECORD_PLAYBACK			"FastForwardRecordPlayBack"		//¼��طſ��
#define LOG_NVR_ID_FAST_BACKWARD_RECORD_PLAYBACK		"FastBackwardRecordPlayBack"	//¼��طſ���

#define LOG_NVR_ID_START_RECORD_BACKUP					"StartRecordBackup"				//��ʼ¼�񱸷�
#define LOG_NVR_ID_PAUSE_RECORD_BACKUP					"PauseRecordBackup"				//��ͣ¼�񱸷�
#define LOG_NVR_ID_STOP_RECORD_BACKUP					"StopRecordBackup"				//ֹͣ¼�񱸷�
#define LOG_NVR_ID_ADD_RECORD_BACKUP_TASK				"AddRecordBackupTask"			//���¼�񱸷�����
#define LOG_NVR_ID_DELETE_RECORD_BACKUP_TASK			"DeleteRecordBackupTask"		//ɾ��¼�񱸷�����

#define LOG_NVR_ID_CONFIGURE_DEVICE_ID					"ConfigureDeviceId"				//�����豸ID 
#define LOG_NVR_ID_CONFIGURE_DEVICE_NAME				"ConfigureDeviceName"			//�����豸����
#define LOG_NVR_ID_CONFIGURE_NETWORK					"ConfigureNetwork"				//��������
#define LOG_NVR_ID_CONFIGURE_DDNS						"ConfigureDDNS"					//����DDNS
#define LOG_NVR_ID_CONFIGURE_PPPOE						"ConfigurePPPoE"				//����PPPoE
#define LOG_NVR_ID_SYNC_DEVICES_TIME					"SyncDevicesTime"				//ͬ���豸ʱ��
#define LOG_NVR_ID_CONFIGURE_DEVICE_TIME				"ConfigureDeviceTime"			//�����豸ʱ��
#define LOG_NVR_ID_CONFIGURE_TIME_ZONE					"ConfigureTimeZone"				//����ʱ��
#define LOG_NVR_ID_START_TIME_REBOOT_SERVICE			"StartTimeRebootService"		//������ʱ����
#define LOG_NVR_ID_STOP_TIME_REBOOT_SERVICE				"StopTimeRebootService"			//�رն�ʱ����
#define LOG_NVR_ID_RESET_DEVICE_TO_FACTORY_SETTING		"ResetDeviceToFactorySetting"	//�ָ��豸����������
#define LOG_NVR_ID_RESTART_DEVICE						"RestartDevice"					//�����豸

#endif	//_LOG_INFO_DESCRIPTION_H_



