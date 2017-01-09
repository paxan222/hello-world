#ifndef _DOMAINCONST_H_
#define _DOMAINCONST_H_

#ifndef CONST_MAXLENGTH_IP
#define CONST_MAXLENGTH_IP								48		//�ַ���IP����
#endif

#define CONST_MAXLENGTH_DN								256		//DNS����
#define CONST_MAX_CHANNEL_NAME							48		//ͨ������

#define CONST_IPPROTO_V4								1		//IPV4Э��
#define CONST_IPPROTO_V6								2		//IPV6Э��
#define CONST_MAXLENGTH_DEVICEID						32		//�豸id����
#define CONST_MAXLENGTH_PTZDEVICEID						32		//
#define CONST_MAXLENGTH_ALARMINPUTNAME					32		//�����������ֳ���
#define CONST_MAXLENGTH_ALARMOUTNAME					32		//����������ֳ���
#define CONST_MAXLENGTH_ALARMSOURCENAME					32		//����Դ���ֳ���
#define CONST_MAXLENGTH_DEVICENAME						32		//�豸���Ƴ���
#define CONST_MAXLENGTH_USERNAME						32		//�û�������
#define CONST_MAXLENGTH_USERPASSWORD					20		//�û����볤��
#define CONST_MAXLENGTH_USER_DESC						256		//�û���������
#define CONST_MAXLENGTH_GROUP_NAME						32		//��������
#define CONST_MAXLENGTH_GROUP_DESC						256		//����������
#define CONST_MAXLENGTH_MANUFACTURERID					32		//�豸�ͺų���
#define CONST_MAXLENGTH_MANUFACTURER_NAME				32		//�豸���Ƴ���
#define CONST_MAXLENGTH_DEVICEMODEL						64		//�豸�ͺų���
#define CONST_MAXLENGTH_DEVICEDESCRIPTOR				32		//�豸����������
#define CONST_MAXLENGTH_MANUFACTURERNAME				32		//�豸�������ҳ���
#define CONST_MAXLENGTH_DEVICEPARAM_RESERVE				32		//�豸��������λ

#define CONST_MAXLENGTH_PRODUCTMODEL					32		//��Ʒģ��
#define CONST_MAXLENGTH_PRODUCTDESCRIPTION				32		//��Ʒ����
#define CONST_MAXLENGTH_HARDWAREMODEL					32		//Ӳ��ģ��
#define CONST_MAXLENGTH_HARDWAREDESCRIPTION				64		//Ӳ������
#define CONST_MAXLENGTH_MACADDRESS						20		//MAC��ַ
#define CONST_MAXLENGTH_BARCODE							16		//����������
#define CONST_MAXLENGTH_SN                              32      //SN���к�
#define CONST_MAXLENGTH_PRODUCTIONTIME					32		//����ʱ��
#define CONST_MAXLENGTH_SUMMARYINFO_RESERVE				16		//��Ҫ��Ϣ��������



#define CONST_MAXLENGTH_PROTOCOL						16		//Э�鳤��
#define CONST_MAXLENGTH_PPPOE_USERNAME					32		//PPPoE�û�������
#define CONST_MAXLENGTH_PPPOE_PASSWORD					32		//PPPoE���볤��
#define CONST_MAXLENGTH_DDNS_DOMAINNAME					64		//DDNS��������
#define CONST_MAXLENGTH_DDNS_ACCOUNTS					32		//DDNS�ʻ�����
#define CONST_MAXLENGTH_DDNS_PASSWORD					32		//DDNS���볤��
#define CONST_MAXLENGTH_DDNS_PROVIDER					32		//DDNS�ṩ��������󳤶�
#define CONST_MAXLENGTH_NAS_STORAGE_USERNAME			32		//NAS�洢�û���
#define CONST_MAXLENGTH_NAS_STORAGE_PASSWORD			32		//NAS����
#define CONST_MAXLENGTH_CAMERA_NAME						32		//��������Ƴ���
#define CONST_MAXLENGTH_CAMERAMODEL						64		//�������ʽ����
#define CONST_MAXLENTH_PTZ_DEVICE_NAME					32		//��̨�豸�����ֳ���
#define CONST_MAXLENTH_PTZ_PROTOCOL_NAME				16		//��̨Э������ֳ���
#define CONST_MAXLENGTH_HARDWAREVERSION					16		//�豸Ӳ���汾����
#define CONST_MAXLENGTH_SOFTWAREVERSION					16		//�豸����汾����
#define CONST_MAXLENGTH_HARDWAREVERSION_EXPAND			48		//�豸Ӳ���汾����
#define CONST_MAXLENGTH_SOFTWAREVERSION_EXPAND			48		//�豸����汾����
#define CONST_MAXLENGTH_OSDINFO							256		//OSD��Ϣ����

#define CONST_MAXLENGTH_TIME							16		//�ַ���ʱ�䳤��
#define CONST_MAXLENGTH_FILE_NAME						512		//¼���ļ�������

#define CONST_MAXLENGTH_ENCODER_NAME					32		//���������Ƴ���
#define CONST_MAXLENGTH_RESOLUTION_NAME					32		//�ֱ������Ƴ���
#define CONST_MAXLENGTH_IMAGEFORMAT_NAME				32		//ͼ���ʽ���Ƴ���
#define CONST_MAXLENGTH_DEVICETYPE_NAME					16		//�豸�������Ƴ���
#define CONST_MAXLENGTH_BITRATETYPE_NAME				16		//�������������Ƴ���
#define CONST_MAXLENGTH_VIDEOSYSTEM_NAME				16		//��Ƶ��ʽ���Ƴ���

#define CONST_MAXLENGTH_AUDIO_IN_TYPE_NAME				32		//��Ƶ�����������Ƴ���
#define CONST_MAXLENGTH_AUDIO_ENCODE_TYPE_NAME			32		//��Ƶ�����������Ƴ���
#define CONST_MAXLENGTH_AUDIO_DECODE_TYPE_NAME			32		//��Ƶ�����������Ƴ���


#define CONST_LENGTH_RS232_NAME							32		//RS232�������Ƴ���
#define CONST_LENGTH_COM_ID								32		//����id����

#define CONST_MAXLENGTH_NAS_PATH						256		//NAS·������

#define CONST_LENGTH_RS485_NAME							32		//RS485�������Ƴ���

#define CONST_MAXLENGTH_COMDATA							1024	//ÿ�ζ�д����������ݳ���
#define CONST_MAXLENGTH_FILEDATA						1024	//ÿ�ζ�дԶ���ļ�������ݳ���

#define CONST_MAXLENGTH_ALARM_TYPE_NAME					64		//�����������Ƴ���

#define CONST_MAXLENGTH_PTZ_PRESET_NAME					32		//��̨Ԥ�Ƶ�����ֳ���
#define CONST_MAXLENGTH_PTZ_TRACK_NAME					32		//��̨�켣�����ֳ���
#define CONST_MAXLENGTH_PTZ_TOUR_NAME					32		//��̨Ѳ�ε����ֳ���
#define CONST_MAXLENGTH_PTZ_SCAN_NAME					32		//��̨ɨ������ֳ���
#define CONST_MAXLENGTH_PTZ_KEEPER_NAME					32		//��̨����λ�����ֳ���
#define CONST_MAXLENGTH_PTZ_TRACE_NAME					32      //��̨�켣S2V1�����ֳ���

#define CONST_MAXLENGTH_VIDEO_OSD_TEXT					256		//��ƵOSD��Ϣ����
#define CONST_MAXLENGTH_FILENAME_SUFFIX					16		//¼���ļ���׺��
#define CONST_MAXLENGTH_LOG_DATA						128		//��־��Ϣ��೤��
#define CONST_MAXLENGTH_LOG_PARAM_DATA					512		//��־��Ϣ��ϸ������󳤶�

#define  CONST_MAXLENTH_PTZOPERATION_CMD				10		//��̨����������󳤶�

#define  CONST_MAXLENTH_COMMUNICATION_VERIFY_CODE		10		//ͨ��У������󳤶�
#define  CONST_MAXLENTH_RESERVE							8		//����λ��󳤶�

#define  CONST_MAXLENTH_EMAIL_ADDRESS					32		//�ʼ���󳤶�

#define  CONST_MAXLENGTH_FTP_SERVERADDR					32		//FTP��������ַ��󳤶�
#define  CONST_MAXLENGTH_FTP_USERNAME					32		//FTP�˻�����󳤶�
#define  CONST_MAXLENGTH_FTP_PASSWORD					32		//FTP������󳤶�
#define  CONST_MAXLENGTH_FTP_WORKPATH					64		//FTP����·����󳤶�

#define CONST_MAXLENGTH_SQL								1024	//SQL��ѯ�����󳤶�
#define CONST_MAXLENGTH_DBNAME							256		//���ݿ�������󳤶�

#define CONST_ALARM_INPUT_EVENT_TYPE_ID					1		//���뱨���¼�����
#define CONST_MOTION_DETECT_EVENT_TYPE_ID				2		//�˶���ⱨ���¼�����
#define CONST_CAMERA_MASK_EVENT_TYPE_ID					3		//����ͷ�ڵ������¼�����

#define CONST_MAXLENGTH_USERID							32		//�û���ID��󳤶�
#define CONST_MAXLENGTH_PASSWORD						20		//���������󳤶�

#define CONST_MAXLENGTH_EMAIL_ADDRESS					128		//�����ʼ���ַ��󳤶�

#define CONST_MAXLENGTH_RECORD_FILE_HEAD				128		//¼���ļ�ͷ��󳤶�

#define CONST_MAXLENGTH_GROUPNAME						32		//�����Ƴ���
#define CONST_MAXLENGTH_PICTURENAME						32		//�������Ƴ���

#define CONST_MAXLENGTH_DEVICE_SERVICE					32		//�豸�������ݳ���

#define CONST_MAXLENGTH_AVSREAM_NAME					32		//�����Ƴ���

#define CONST_MAXLENGTH_ALARM_SOURCE_ID					32		//����ԴID
#define CONST_MAXLENGTH_ALARM_DESCRIPTION				64		//��������
#define CONST_MAXLENTH_PTZ_CMD							32		//��̨�����
#define CONST_MAXLENTH_AUDIO_DECODE_TYPE_NAME			32		//��Ƶ�����������Ƴ���
#define CONST_MAXLENTH_AUDIO_ENCODE_TYPE_NAME			32		//��Ƶ�����������Ƴ���
#define CONST_MAXLENTH_AUDIO_IN_TYPE_NAME				32		//��Ƶ�����������Ƴ���
#define CONST_MAXLENTH_RESOLUTION_NAME					32		//�ֱ������Ƴ���
#define CONST_MAXLENTH_DISK_FILE_SYSTEM_NAME			32		//�ļ�ϵͳ������
#define CONST_MAXLENTH_MONITOR_TYPE_NAME				32		//�������������������

#define CONST_MAXLENTH_PROTOCOL_NAME					64		//Э�����ֳ���
#define CONST_MAXLENTH_PROTOCOL_VERSION					64		//Э��汾����
#define CONST_MAXLENTH_PROTOCOL_SOFTWARE_VERSION		64		//Э������汾����

#define	 CONST_MAXLENGTH_DEVICE_STATUS					256		//�豸����״̬��������	
#define  CONST_MAXLENGTH_DEVICE_REGISTER_ID				128
#define  CONST_MAXLENGTH_CAMERA_REGISTER_ID				128
#define  CONST_MAXLENGTH_UUID							128		//UUID��󳤶�
#define  CONST_MAXLENGTH_DEVICE_ADDR					256		//�豸��ַ��IP��������url����ʽ��
#define  CONST_MAXLENGTH_EXTERN_CONFIG					64		//����������չ���ó���

#define CONST_MAXLENGTH_LANGUAGE_NAME					32		//�������Ƴ���
#define CONST_OSD_TIMEFORMAT_DESCRIPTION				128		//OSDʱ���ʽ����
#define CONST_OSD_FONT_DESCRIPTION						16		//OSD���峤��
#define CONST_WORKMODE_NAME								32		//����ģʽ����

#define CONST_MAXLENGTH_PROTOCOL_TYPE                   64		//Э�����ͳ���
#define CONST_MAXLENGTH_PROTOCOL_TYPE_VERSION			64		//Э�����Ͱ汾����

#define CONST_MAXLENGTH_ENCODER_LEVEL_NAME				32		//����ȼ����Ƴ���

#define CONST_MAXLENGTH_TIME_ZONE_NAME					128		//ʱ�����Ƴ���

#define CONST_MAXLENGTH_PROTOCOL_PARAM                  256		//Э���������

#define CONST_MAXLENGTH_SSID							128		//�ȵ�SSID����
#define CONST_MAXLENGTH_SSID_PASSWORD					128		//�ȵ�SSID���볤��
#define CONST_MAXLENGTH_ENCRYPTION_TYPE                 64		//�������ͳ���
#define CONST_MAXLENGTH_PHONE_NO						32		//�绰���볤��
#define CONST_MAXLENGTH_MESSAGE_CONTENT                 256		//��Ϣ���ݳ��ȳ���
#define CONST_MAXLENGTH_MESSAGE_TIME					64		//��Ϣʱ�䳤��
#define CONST_MAXLENGTH_ACCESS_POINT					64		//����㳤��
#define CONST_MAXLENGTH_IDENTIFICATION_TYPE				32		//��֤��ʽ����
#define CONST_MAXLENGTH_3G_OPERATOR						32		//3G��Ӧ�̳���
#define CONST_MAXLENGTH_NET_TYPE						32		//3G�������ͳ���
#define CONST_MAXLENGTH_3G_DEVICE_NAME					32		//3G�豸������
#define CONST_MAXLENGTH_WIFI_DEVICE_NAME				32		//wifi �豸������
#define CONST_MAXLENGTH_FILESYSTEM_NAME					32		//�ļ�ϵͳ���ֳ���
#define CONST_MAXLENGTH_DETECTIONAREA_NAME				32		//�ƶ�����������Ƴ���
#define CONST_MAXLENGTH_DISKATTRIBUTE_NAME				32		//�����������ֳ���
#define CONST_MAXLENGTH_LAYOUT_NAME						128		//�������ֳ���
#define CONST_MAXLENGTH_CMS_REGISTER_SRV_NAME			32		//CMSע����������ֳ���
#define CONST_MAXLENGTH_EXTERN_CONFIG_NAME				32		//CMS��չ�������ֳ���


#define CONST_NETWORK_CARD_NAME							32		//��������
#define CONST_NETWORK_CARD_DESCRIPTION					64		//��������
#define CONST_MAXLENGTH_CHANNEL_NAME					64		//ͨ�����Ƴ���	

#define CONST_STATE_STREAM								1		//��֧�ְ�������ԭʼ��
#define CONST_STATE_WITH_SVC_STREAM						2		//֧�ְ�������ԭʼ��
#define CONST_SVC_STREAM								3		//������

#define	CONST_TAGET_TYPE_UNKNOWN									0
#define CONST_TAGET_TYPE_HUMAN										1
#define CONST_TAGET_TYPE_VEHICLE									2
#define CONST_INTELLIGENCE_ANALYSE_UNIT_LEN					10		//���ܷ���������λ����
#endif //_DOMAINCONST_H_
