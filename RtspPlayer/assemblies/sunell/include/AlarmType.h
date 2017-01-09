#ifndef _ALARMTYPE_H_
#define _ALARMTYPE_H_

#include "DomainConst.h"
#include "SNPlatOS.h"

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

class SN_DLL_API AlarmType
{
public:
	//��������
	enum
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
		TYPE_RECORD_STORAGE_FAILED		= 15,   //¼��洢ʧ��
		TYPE_PIR_ALARM					= 16,	//PIR������add by weihuiquan
		TYPE_AUDIO_DETECT				= 17	//��������
	};

	//��չ����������
	enum AlarmMajorType
	{
		SECURITY_ALARM						= 1, //��ȫ����
		DISK_ALARM							= 4, //���̱���
		RECORD_ALARM						= 5, //¼�񱨾�
		INTELLIGENCE_ANALYSE_ALARM			= 6	 //���ܷ�������
	};

	enum IntelligenceAnalyseAlarmMinorType
	{
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_TRIPWIRE							= 21,	//���ܷ��� ���߼�ⱨ��
		//INTELLIGENCEANALYSEALARM_MINOR_TYPE_MOTIONDETECT						= 22,	//���ܷ��� �ƶ���ⱨ��
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_CAMERATAMPER						= 23,	//���ܷ��� �ڵ���ⱨ��
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_PERIMETER							= 24,	//���ܷ��� �ܽ����ֱ���
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_MULTITRIPWIRE						= 25,	//���ܷ��� ˫���߱���
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_LOITER								= 26,	//���ܷ��� �ǻ�����   
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_MULTILOITER							= 27,	//���ܷ��� �����ǻ�����
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_OBJECTLEFT							= 28,	//���ܷ��� ��Ʒ��������
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_OBJECTMOVED							= 29,	//���ܷ��� ��Ʒ���߱���
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_ABNORMALSPEED						= 30,	//���ܷ��� �������ٶȱ��� 
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_CONVERSE							= 31,	//���ܷ��� ���б���
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_NOPARKING							= 32,	//���ܷ��� �Ƿ�ͣ������
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_CAMERAREMOVED						= 33,	//���ܷ��� �������λ����
		INTELLIGENCEANALYSEALARM_MINOR_TYPE_SIGNAL_BAD							= 34	//���ܷ��� ��Ƶ�ź��쳣����
	};

	//��չ��ȫ����������
	enum SecurityAlarmMinorType
	{
		SECURITYALARM_MINOR_TYPE_ALARMIO				= 1,	//I/O����
		SECURITYALARM_MINOR_TYPE_MOTIONDETECT			= 2,	//�˶���ⱨ��
		SECURITYALARM_MINOR_TYPE_CAMERAMASK				= 3,	//����ͷ�ڵ�����
		SECURITYALARM_MINOR_TYPE_VIDEO_LOST				= 4,	//��Ƶ��ʧ����
		SECURITYALARM_MINOR_TYPE_NETWORK_DISCONNECTION	= 5,	//����Ͽ��澯
		SECURITYALARM_MINOR_TYPE_PIRALARM				= 9, 	//PIR������add by weihuiquan
		SECURITYALARM_MINOR_TYPE_ALARM_NETIO			= 10,	//����IO����
		SECURITYALARM_MINOR_TYPE_AUDIO_DETECT			= 11	//��������
	};

	//��չ���̱���������
	enum DiskAlarmMinorType
	{
		DISKALARM_MINOR_TYPE_DISK_OK			= 1,	//����״̬����
		DISKALARM_MINOR_TYPE_DISK_ERROR			= 2,	//���̶�д�쳣
		DISKALARM_MINOR_TYPE_CONNECT_FAILED		= 3,	//�����������ʧ��
		DISKALARM_MINOR_TYPE_DISK_FULL			= 4,	//������
		DISKALARM_MINOR_TYPE_NOT_EXISTENT		= 5,	//���̲�����
		DISKALARM_MINOR_TYPE_THRESHOLD_ALARM	= 6,	//�������ÿռ�ﵽָ����ֵ 
		DISKALARM_MINOR_TYPE_NOT_FORMAT			= 7,	//����δ��ʽ��
		DISKALARM_MINOR_TYPE_DEVICE_NOSPACE		= 8,	//�豸�洢�ռ䲻��
		DISKALARM_MINOR_TYPE_DATAVERSION_LOW	= 9,	//���ݰ汾̫��
		DISKALARM_MINOR_TYPE_DATAVERSION_HIGH	= 10,	//���ݰ汾̫��
		DISKALARM_MINOR_TYPE_ACCESS_ABILITY_UNMATCH	= 11	//���̷���������ƥ��
	};

	////��չ¼�񱨾�������
	//enum RecordAlarmMinorType
	//{
	//	RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_SUCCESS			= 1,		//����Դ���ӳɹ�
	//	RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_LOGIN_ERROR		= 2,		//����Դ�����û����������
	//	RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_NO_PRIVILEGE		= 3,		//����Դ����û��Ȩ��
	//	RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_MAX_CONNECTION	= 4,		//����Դ���Ӵﵽ���������
	//	RECORDSOURCE_MINOR_TYPE_AVDATA_MAX_SPEED				= 5,		//����Դ�ﵽ�����������
	//	RECORDSOURCE_MINOR_TYPE_LOGIN_USER_REPEATED				= 6,
	//	RECORDSOURCE_MINOR_TYPE_NOT_SUPPORT_VIDEO				= 7,
	//	RECORDSOURCE_MINOR_TYPE_CREATE_VIDEO_SESSION_FAILED		= 8,
	//	RECORDSTORAGE_MINOR_TYPE_STORAGE_FAILED					= 9,
	//	RECORDSTORAGE_MAIN_RECORD_FAILED						= 10,
	//	RECORDSTORAGE_MAIN_BUCKUP_RECORD_FAILED					= 11,
	//	RECORDSTORAGE_MAIN_RECORD_STATE_OK						= 12,
	//	RECORDSTORAGE_BACKUP_RECORD_STATE_OK					= 13
	//};

		//��չ¼�񱨾�������
	enum RecordAlarmMinorType
	{
		RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_SUCCESS			= 1,		//����Դ���ӳɹ�
		RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_LOGIN_ERROR		= 2,		//����Դ�����û����������
		RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_NO_PRIVILEGE		= 3,		//����Դ����û��Ȩ��
		RECORDSOURCE_MINOR_TYPE_DEVICE_CONNECT_MAX_CONNECTION	= 4,		//����Դ���Ӵﵽ���������
		RECORDSOURCE_MINOR_TYPE_AVDATA_MAX_SPEED				= 5,		//����Դ�ﵽ�����������
		RECORDSOURCE_MINOR_TYPE_LOGIN_USER_REPEATED				= 6,		
		RECORDSOURCE_MINOR_TYPE_NOT_SUPPORT_VIDEO				= 7,
		RECORDSOURCE_MINOR_TYPE_CREATE_VIDEO_SESSION_FAILED		= 8,
		RECORDSTORAGE_MINOR_TYPE_STORAGE_FAILED					= 9,		//�洢ʧ��
		RECORDSTORAGE_MINOR_TYPE_START_RECORD					= 10,		//����¼��
		RECORDSTORAGE_MINOR_TYPE_STOP_RECORD					= 11,		//ֹͣ¼��
	
	    RECORDSTORAGE_MAIN_RECORD_FAILED						= 12,
		RECORDSTORAGE_MAIN_BUCKUP_RECORD_FAILED					= 13,
		RECORDSTORAGE_MAIN_RECORD_STATE_OK						= 14,
		RECORDSTORAGE_BACKUP_RECORD_STATE_OK					= 15

	};


	enum AlarmFlag
	{
		ALARM_FLAG_STOP = 0,						//����ֹͣ
		ALARM_FLAG_START = 1						//������ʼ
	};

public:
	AlarmType(void);
	~AlarmType(void);
	
	AlarmType(const AlarmType& p_objAlarmType);

public:

	/************************************************************************
	**������
	*		���ñ�������id
	**���룺
	*		p_nAlarmTypeId����������id��һ���ԡ�\0����β���ַ�����
	**�����
	*		��
	**����ֵ��
	*		��
	*���ܣ�
	*	
	************************************************************************/
	void setAlarmTypeId(const int p_nAlarmTypeId);

	/************************************************************************
	**������
	*		��ȡ��������id
	*���룺
	*		��
	*�����
	*		��
	**����ֵ��
	*		��������id
	**���ܣ�
	*
	*************************************************************************/
	const int getAlarmTypeId() const;


	/************************************************************************
	**������
	*		���ñ�����������
	**���룺
	*		p_pszAlarmTypeName�������������ƣ�һ���ԡ�\0����β���ַ�����
	**�����
	*		��
	**����ֵ��
	*		ture ��	���óɹ�
	*		false ���豸ֻ��
	*���ܣ�
	*		��p_pszAlarmTypeNameΪ��ʱ������false��
	*		�����ñ����������Ƴɹ�ʱ������true��
	************************************************************************/
	bool setAlarmTypeName(const char* p_pszAlarmTypeName);

	/************************************************************************
	**������
	*		��ȡ������������
	*���룺
	*		��
	*�����
	*		��
	**����ֵ��
	*		������������
	**���ܣ�
	*
	*************************************************************************/
	const char* getAlarmTypeName() const;

	/************************************************************************
	*������
	*		��ֵ����
	**���룺
	*		p_objAlarmType������������Ϣ
	**�����
	*		��
	**����ֵ��
	*		����������Ϣ
	**���ܣ�
	*
	*************************************************************************/
	AlarmType& operator =(const AlarmType& p_objAlarmType);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objAlarmType��AlarmType���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����AlarmType��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const AlarmType& p_objAlarmType);

private:
	int			m_nAlarmTypeId;											//��������id

	char		m_szAlarmTypeName[CONST_MAXLENGTH_ALARM_TYPE_NAME + 1];		//������������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_ALARMTYPE_H_

