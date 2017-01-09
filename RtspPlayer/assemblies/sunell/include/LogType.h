#ifndef _LOGTYPE_H_
#define _LOGTYPE_H_

class LogType
{
public:
	//��־������
	enum MajorType
	{
		LOG_MAJOR_TYPE_EXCEPTION 				= 0x2,	//�쳣��־
		LOG_MAJOR_TYPE_OPERATION 				= 0x3,	//������־
		LOG_MAJOR_TYPE_OPERATION_V2				= 0x4	//������־v2
	};

	enum ExceptionMinorType
	{
		LOG_MINOR_TYPE_VI_LOST					= 0x21,	//�źŶ�ʧ  
		LOG_MINOR_TYPE_ILLEGAL_ACCESS			= 0x22,	//�Ƿ�����  
		LOG_MINOR_TYPE_HD_FULL					= 0x23,	//������  
		LOG_MINOR_TYPE_HD_ERROR					= 0x24,	//���̴���  
		LOG_MINOR_TYPE_HD_NOT_EXISTENT			= 0x27,	//���̲�����  
		LOG_MINOR_TYPE_HD_WRITE_PROTECT			= 0x28,	//����д����
		LOG_MINOR_TYPE_HD_NOT_FORMAT			= 0x29,	//����δ��ʽ��

		LOG_MINOR_TYPE_DCD_LOST					= 0x25,	//MODEM ����  
		LOG_MINOR_TYPE_IP_CONFLICT				= 0x26,	//IP��ַ��ͻ

		LOG_MINOR_TYPE_ALARM_RECORD_HD_FULL			= 0x30,	//����¼�ƴ�����  
		LOG_MINOR_TYPE_SCHEDULE_RECORD_HD_FULL		= 0x31,	//�ƻ�¼�ƴ�����  
		LOG_MINOR_TYPE_ALWAYS_RECORD_HD_FULL		= 0x32	//7*24¼�ƴ�����  

	};

	enum OperaTionMinorType
	{
		LOG_MINOR_TYPE_START_DVR				= 0x41,  //����  
		LOG_MINOR_TYPE_STOP_DVR					= 0x42,  //�ػ�  
		LOG_MINOR_TYPE_STOP_ABNORMAL			= 0x43,  //�Ƿ��ػ�  

		LOG_MINOR_TYPE_LOCAL_LOGIN				= 0x50,  //���ص�½
		LOG_MINOR_TYPE_LOCAL_LOGOUT				= 0x51,  //����ע����½  
		LOG_MINOR_TYPE_LOCAL_CFG_PARM			= 0x52,  //�������ò���  
		LOG_MINOR_TYPE_LOCAL_PLAYBYFILE			= 0x53,  //���ذ��ļ��ط�  
		LOG_MINOR_TYPE_LOCAL_PLAYBYTIME			= 0x54,  //���ذ�ʱ��ط�  
		LOG_MINOR_TYPE_LOCAL_START_REC			= 0x55,  //���ؿ�ʼ¼��  
		LOG_MINOR_TYPE_LOCAL_STOP_REC			= 0x56,  //����ֹͣ¼��  
		LOG_MINOR_TYPE_LOCAL_PTZCTRL			= 0x57,  //������̨����  
		LOG_MINOR_TYPE_LOCAL_PREVIEW			= 0x58,  //����Ԥ��  
		LOG_MINOR_TYPE_LOCAL_MODIFY_TIME		= 0x59,  //�����޸�ʱ��  
		LOG_MINOR_TYPE_LOCAL_UPGRADE			= 0x5a,  //��������  
		LOG_MINOR_TYPE_LOCAL_COPYFILE			= 0x5b,  //���ر����ļ�  

		LOG_MINOR_TYPE_REMOTE_LOGIN				= 0x70,  //Զ�̵�¼  
		LOG_MINOR_TYPE_REMOTE_LOGOUT			= 0x71,  //Զ��ע����½  
		LOG_MINOR_TYPE_REMOTE_START_REC			= 0x72,  //Զ�̿�ʼ¼��  
		LOG_MINOR_TYPE_REMOTE_STOP_REC			= 0x73,  //Զ��ֹͣ¼��  
		LOG_MINOR_TYPE_START_TRANS_CHAN			= 0x74,  //��ʼ͸������  
		LOG_MINOR_TYPE_STOP_TRANS_CHAN			= 0x75,  //ֹͣ͸������  
		LOG_MINOR_TYPE_REMOTE_GET_PARM			= 0x76,  //Զ�̻�ò���  
		LOG_MINOR_TYPE_REMOTE_CFG_PARM			= 0x77,  //Զ�����ò���  
		LOG_MINOR_TYPE_REMOTE_GET_STATUS		= 0x78,  //Զ�̻��״̬  
		LOG_MINOR_TYPE_REMOTE_ARM				= 0x79,  //Զ�̲���  
		LOG_MINOR_TYPE_REMOTE_DISARM			= 0x7a,  //Զ�̳���  
		LOG_MINOR_TYPE_REMOTE_REBOOT			= 0x7b,  //Զ������  
		LOG_MINOR_TYPE_START_VT					= 0x7c,  //��ʼ�����Խ�  
		LOG_MINOR_TYPE_STOP_VT					= 0x7d,  //ֹͣ�����Խ�  
		LOG_MINOR_TYPE_REMOTE_UPGRADE			= 0x7e,  //Զ������
		LOG_MINOR_TYPE_REMOTE_PLAYBYFILE		= 0x7f,  //Զ�̰��ļ��ط�  
		LOG_MINOR_TYPE_REMOTE_PLAYBYTIME		= 0x80,  //Զ�̰�ʱ��ط�  
		LOG_MINOR_TYPE_REMOTE_PTZCTRL			= 0x81,  //Զ����̨����
		LOG_MINOR_TYPE_REMOTE_START_VIDEO		= 0x82,  //Զ�̿�ʼʵʱ��Ƶ
		LOG_MINOR_TYPE_REMOTE_STOP_VIDEO		= 0x83,  //Զ��ֹͣʵʱ��Ƶ
		LOG_MINOR_TYPE_REMOTE_START_AUDIO		= 0x84,	 //Զ�̿�ʼʵʱ��Ƶ
		LOG_MINOR_TYPE_REMOTE_STOP_AUDIO		= 0x85,	 //Զ��ֹͣʵʱ��Ƶ
		LOG_MINOR_TYPE_STORAGE_FORMAT			= 0x86	 //�豸�洢��ʽ����SD����ʽ����
	};


	enum OperaTionMinorType_v2
	{
		LOG_MINOR_TYPE_V2_USER_MANAGE			= 0x01,		//�û�����  
		LOG_MINOR_TYPE_V2_SYSTEM_MANAGE			= 0x02,		//ϵͳά��  
		LOG_MINOR_TYPE_V2_DEVICE_CONFIG			= 0x03,		//�豸����  
		LOG_MINOR_TYPE_V2_RECORD_CTRL			= 0x04,		//¼�����  
		LOG_MINOR_TYPE_V2_LIVE_VIDEO_CTRL		= 0x05,		//����Ƶ����  
		LOG_MINOR_TYPE_V2_LIVE_VIDEO			= 0x06,		//����Ƶ�㲥 
		LOG_MINOR_TYPE_V2_SECURITYPARAM_CONFIG	= 0x07,		//Web����ģʽ��SSL��������

		LOG_MINOR_TYPE_NVR_USER_MANAGER			= 0x11,		//NVR�û�����  
		LOG_MINOR_TYPE_NVR_CONFIG				= 0x12,		//NVR����  
		LOG_MINOR_TYPE_NVR_CHANNEL_MANAGER		= 0x13,		//NVRͨ������
		LOG_MINOR_TYPE_NVR_RECORD_CTR			= 0x14,		//¼�����  
		LOG_MINOR_TYPE_NVR_LIVE_VIDEO			= 0x15,		//����Ƶ

		LOG_MINOR_TYPE_V2_AUDIO_ALARM_DATA			= 0x16,		//��Ƶ������������
	};

};

#endif //_LOGTYPE_H_
