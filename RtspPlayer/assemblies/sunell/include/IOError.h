#ifndef _IOERROR_H_
#define _IOERROR_H_
#include "GeneralError.h"

// -101~ -200
#define SN_ERROR_DISKIO_BEGIN				(-100)

//�ļ�������
#define SN_ERROR_FILE_NOT_FOUND             (SN_ERROR_DISKIO_BEGIN - 1)

//�ļ�·��������
#define SN_ERROR_PATH_NOT_FOUND             (SN_ERROR_DISKIO_BEGIN - 2)

//�򿪴���ʱ��������
#define SN_ERROR_DISKIO_OPEN				(SN_ERROR_DISKIO_BEGIN - 3)

//������ʱ��������
#define SN_ERROR_DISKIO_READ				(SN_ERROR_DISKIO_BEGIN - 4)

//д����ʱ��������
#define SN_ERROR_DISKIO_WRITE				(SN_ERROR_DISKIO_BEGIN - 5)

//��λ(seek)�ļ�λ��ʱ����
#define SN_ERROR_DISKIO_SEEK				(SN_ERROR_DISKIO_BEGIN - 6)

//��д���̵���ĩβ
#define SN_ERROR_DISKIO_END					(SN_ERROR_DISKIO_BEGIN - 7)

//���̿ռ䲻�㣬����̿ռ�����
#define SN_ERROR_DISK_SPACE_FULL			(SN_ERROR_DISKIO_BEGIN - 8)

//���̲�����
#define SN_ERROR_DISK_NOT_EXISTENT			(SN_ERROR_DISKIO_BEGIN - 9)

//����д����
#define SN_ERROR_DISK_WRITE_PROTECT			(SN_ERROR_DISKIO_BEGIN - 10)

//����δ��ʽ��
#define SN_ERROR_DISK_NOT_FORMAT			(SN_ERROR_DISKIO_BEGIN - 12)

//���̴�����Ҫ�ϵ�����
#define SN_ERROR_DISK_ERROR					(SN_ERROR_DISKIO_BEGIN - 13)

//�������ڸ�ʽ��
#define SN_ERROR_DISK_FORMATTING			(SN_ERROR_DISKIO_BEGIN - 14)

//--------------------����------------------------//
//�򿪴���ʱ��������
#define SN_ERROR_COM_OPEN					(SN_ERROR_DISKIO_BEGIN - 50)

//��ȡ����(com)����ʱ��������
#define SN_ERROR_COM_READ					(SN_ERROR_DISKIO_BEGIN - 51)

//�򴮿�д����ʱ��������
#define SN_ERROR_COM_WRITE					(SN_ERROR_DISKIO_BEGIN - 52)

//--------------------USB------------------------//
//��USBʱ��������
#define  SN_ERROR_USB_OPEN					(SN_ERROR_DISKIO_BEGIN - 53)

//��ȡUSB������ʱ��������
#define SN_ERROR_USB_READ					(SN_ERROR_DISKIO_BEGIN - 54)

//��USB��д����ʱ��������
#define SN_ERROR_USB_WRITE					(SN_ERROR_DISKIO_BEGIN - 55)

#endif // 
