#ifndef _ERRORDEF_
#define _ERRORDEF_

#include "GeneralError.h"

#define SN_ERROR_DB_BEGIN				(-300)

//���ݿ��ʧ��
#define SN_ERROR_DB_OPEN_FAILED						(SN_ERROR_DB_BEGIN -1)

//���ݿ�ر�ʧ��
#define SN_ERROR_DB_CLOSE_FAILED					(SN_ERROR_DB_BEGIN - 2)

//��ʼ����ʧ��
#define SN_ERROR_DB_BEGIN_TRANSACTION_ERROR			(SN_ERROR_DB_BEGIN - 3)

//�ع�����ʧ��
#define SN_ERROR_DB_ROLLBACK_TRANSACTION_ERROR		(SN_ERROR_DB_BEGIN - 4)

//�ύ����ʧ��
#define SN_ERROR_DB_COMMIT_TRANSACTION_ERROR		(SN_ERROR_DB_BEGIN - 5)

//��������ʧ��
#define SN_ERROR_DB_INSERT_ERROR					(SN_ERROR_DB_BEGIN - 6)

//ɾ������ʧ��
#define SN_ERROR_DB_DELETE_ERROR					(SN_ERROR_DB_BEGIN - 7)

//��������ʧ��
#define SN_ERROR_DB_UPDATE_ERROR					(SN_ERROR_DB_BEGIN - 8)

//��ѯ����ʧ��
#define SN_ERROR_DB_SELECT_ERROR					(SN_ERROR_DB_BEGIN - 9)

//��ѯ��������
#define SN_ERROR_DB_SELECT_CONDITION_ERROR			(SN_ERROR_DB_BEGIN - 10)

//��ѯ���Ϊ��
#define SN_ERROR_DB_RECORDSET_EMPTY					(SN_ERROR_DB_BEGIN - 11)

#endif // _AVOBSERVER_H_
