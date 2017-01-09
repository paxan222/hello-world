#ifndef _SNERROR_H_
#define _SNERROR_H_

#include "GeneralError.h"
#include "IOError.h"
#include "DbError.h"
#include "NetworkIOError.h"
#include "CommandError.h"
//-501 => -700

#define SN_ERROR_BEGIN				(-500)

//---------����-----------------//
//����������Ӧ��
#define SN_ERROR_NOT_EXPECT_RESPONSE						(SN_ERROR_BEGIN - 1)

//Զ�˴���ʧ��
#define SN_ERROR_REMOTE_FAILED								(SN_ERROR_BEGIN - 2)

//�豸δ��
#define SN_ERROR_DEVICE_NOT_OPEN 							(SN_ERROR_BEGIN - 3)

//�豸��ʧ��
#define SN_ERROR_DEVICE_OPEN_FAILED 						(SN_ERROR_BEGIN - 4)

//�豸��ռ��
#define SN_ERROR_DEVICE_USED								(SN_ERROR_BEGIN - 5)

//��֧�ֵ��豸
#define SN_ERROR_DEVICE_NOT_SUPPORT							(SN_ERROR_BEGIN - 6)

//��¼�û�������
#define SN_ERROR_LOGIN_USERNAME_ERROR						(SN_ERROR_BEGIN - 7)

//��¼�������
#define SN_ERROR_LOGIN_USERPASSWORD_ERROR					(SN_ERROR_BEGIN - 8)

//����ʧ��
#define SN_ERROR_ADSL_DIAL_FAILED							(SN_ERROR_BEGIN - 9)

//���ڱ���ռ
#define SN_ERROR_COM_ISUSED									(SN_ERROR_BEGIN - 10)

//�������Ѿ��ﵽ���
#define SN_ERROR_MAX_CONNECTION								(SN_ERROR_BEGIN - 11)

//Ȩ�޲���
#define SN_ERROR_NO_PRIVILEGE								(SN_ERROR_BEGIN - 12)

//�豸δ����
#define SN_ERROR_DEVICE_NOT_CONFIGURE						(SN_ERROR_BEGIN - 13)

//��������ʹ���޷���ʽ��
#define SN_ERROR_FORMAT_FAIL_BY_USING						(SN_ERROR_BEGIN - 14)

//��¼�û�������
#define SN_ERROR_USER_LOCKED								(SN_ERROR_BEGIN - 15)

//��¼�û��ص�¼�����û���֧�ֶ���¼ʱ���ظ���¼���ظô���
#define SN_ERROR_USER_REPEATED								(SN_ERROR_BEGIN - 16)

//�û����ڵ�¼
#define SN_ERROR_USER_LONGINING								(SN_ERROR_BEGIN - 17)

//�豸��������
#define SN_ERROR_DEVICE_ABILITY_NOT_ENOUGH					(SN_ERROR_BEGIN - 18)

//��֤�����
#define SN_ERROR_VALIDATE_CODE								(SN_ERROR_BEGIN - 19)

//�û������Ѵﵽ���
#define SN_ERROR_MAX_USER									(SN_ERROR_BEGIN - 20)

//�û��Ѵ���
#define SN_ERROR_USER_EXIST									(SN_ERROR_BEGIN - 21)

//Ȩ�����Ѵ���
#define SN_ERROR_GROUP_EXIST								(SN_ERROR_BEGIN - 22)

//---------VIDEO---------------//
//��Ƶ�Ự�Ѿ��ر�
#define SN_ERROR_VIDEO_SESSION_CLOSE						(SN_ERROR_BEGIN - 50)

//��Ƶ�Ự�߳��Ѿ��ر�
#define SN_ERROR_VIDEO_SESSION_THREAD_CLOSE					(SN_ERROR_BEGIN - 51)

//����Directshow��Ƶ���ʧ��
#define SN_ERROR_DIRECTSHOW_VIDEO_CREATE_FAILED				(SN_ERROR_BEGIN - 52)

//����DirectShow��Ƶ���ʧ��
#define SN_ERROR_DIRECTSHOW_VIDEO_OPERATION_FAILED			(SN_ERROR_BEGIN - 53)

//������������
#define SN_ERROR_DECODER_ABILITY_NOT_ENOUGH					(SN_ERROR_BEGIN - 55)

//��֧�ֱ�������
#define SN_ERROR_NOT_SUPPORT_ENCODER_TYPE					(SN_ERROR_BEGIN - 56)

//---------AUDIO---------------//
//��Ƶ�Ự�Ѿ��ر�
#define SN_ERROR_AUDIO_SESSION_CLOSE						(SN_ERROR_BEGIN - 101)

//��Ƶ�Ự�߳��Ѿ��رա�
#define SN_ERROR_AUDIO_SESSION_THREAD_CLOSE					(SN_ERROR_BEGIN - 102)

//����Directshow��Ƶ���ʧ��
#define SN_ERROR_DIRECTSHOW_AUDIO_CREATE_FAILED				(SN_ERROR_BEGIN - 103)

//����Directshow��Ƶ���ʧ��
#define SN_ERROR_DIRECTSHOW_AUDIO_OPERATION_FAILED			(SN_ERROR_BEGIN - 104)

//��ʼ��DirectDraw���ʧ��
#define SN_ERROR_DIRECTDRAW_CREATE_FAILED					(SN_ERROR_BEGIN - 105)

//��ʼ��������ʧ��
#define SN_ERROR_VIDEO_DECODER_INIT_FAILED					(SN_ERROR_BEGIN - 106)

//����ʧ��
#define SN_ERROR_VIDEO_DECODE_FAILED						(SN_ERROR_BEGIN - 107)

//OSD��Խ��
#define SN_ERROR_VIDEO_OSD_ROW_OVERLOAD						(SN_ERROR_BEGIN - 150)

//OSD�ַ���Խ��
#define SN_ERROR_VIDEO_OSD_CHARACTER_OVERLOAD				(SN_ERROR_BEGIN - 151)

//ONVIF����
#define SN_ERROR_SOAP_FAULT									(SN_ERROR_BEGIN - 152)

//Ȩ���鲻Ϊ��
#define SN_ERROR_PRIVILEGE_GROUP_NOT_EMPTY					(SN_ERROR_BEGIN - 160)

#endif // _SNERROR_H_
