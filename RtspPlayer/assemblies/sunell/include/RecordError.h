#ifndef _RECORDERROR_H_
#define _RECORDERROR_H_

//����û��ʣ��ռ�
#define	SN_RECORD_NO_FREE_SPACE									-701

//��¼���ļ�ʧ��
#define	SN_RECORD_OPEN_RECORDFILE_FAILED						-702

//д��¼���ļ�ʧ��
#define	SN_RECORD_WRITE_RECORDFILE_FAILED						-703	

//д�������ļ�ʧ��
#define	SN_RECORD_WRITE_INDEXFILE_FAILED						-704

//�������ļ�ʧ��
#define	SN_RECORD_OPEN_INDEXFILE_FAILED							-705

//��ȡ�����ļ�����ʧ��
#define	SN_RECORD_READ_INDEXFILE_FAILED							-706

//�Ѿ�д��һ��¼���ļ�Ƭ��С
#define	SN_RECORD_RECORDFILE_ISMAXSIZE							-707

//û�����ô���Ŀ¼
#define	SN_RECORD_NO_SET_ROOT_DIR								-708

//��ȡ����¼���ļ�ʧ��
#define	SN_RECORD_GET_EARLIEST_FILE_FAILED						-709

//�滻�ļ�ʧ��
#define	SN_RECORD_REPLACE_FILE_FAILED							-710

//��ȡ¼���ļ�����ʧ��
#define	SN_RECORD_GET_FILE_LENGTH_FAILED						-711

//��ȡ¼���ļ�ʧ��
#define	SN_RECORD_READ_RECORDFILE_FAILED						-712

//û�д���Ŀ¼��д��¼��
#define	SN_RECORD_NO_DIR_WRITE									-713

//���̿ռ�д��
#define	SN_RECORD_FULL_STOP										-714

//¼���ѯ���Ϊ��
#define	SN_RECORD_RETRIEVER_QUERY_EMPTY_LIST					-715

//¼���ȡ������ѯ��ʱ�䷶Χ
#define	SN_RECORD_RETRIVER_OUT_TIME_RANGE						-716

#define SN_RECORD_PARSE_ERROR									-717
#define SN_RECORD_PARSE_EMPTY									-718
#define SN_RECORD_PARSE_NO_IFRAM								-719
#define	SN_RECORD_QUERY_FAILED									-720

//¼���ļ�û�д�
#define	SN_RECORD_NOT_OPEN										-721

//δ֪�Ĵ�������
#define	SN_RECORD_UNKNOWN_DISKTYPE								-722

//��λ��ʼλ��ʧ��
#define	SN_RECORD_LOCATE_BEGINPOS_FAILED						-723

//��λ����λ��ʧ��
#define	SN_RECORD_LOCATE_ENDPOS_FAILED							-724

//�ļ�seekʧ��
#define	SN_RECORD_SEEK_ERROR									-725

//¼���ȡ����
#define	SN_RECORD_READ_END										-726

//
#define	SN_RECORD_FRAMEID_ERROR									-727

//û��¼������
#define SN_RECORD_NO_RECORD_DATA								-728

//��ȡ�ļ�����ʧ��
#define	SN_RECORD_GET_LENGTH_FAILED							    -729

//û�п��ÿռ�
#define	SN_RECORD_NO_ENOUGH_SIZE								-730

//����I֡ʧ��
#define	SN_RECORD_NO_IFRAME										-731

#define	SN_RECORD_NO_FRAME										-732

//��ȡ�ļ��б�ʧ��
#define	SN_RECORD_GET_FILELIST_FAILED							-733

//�����豸��Ϣ
#define SN_RECORD_INVALID_DEVICEINFO							-734

//��ȡ�豸�б�ʧ��
#define SN_RECORD_GET_DEVICELIST_FAILED							-735

//��ȡ�����б�ʧ��
#define SN_RECORD_GET_DATELIST_FAILED							-736

//¼������ʱ����ع�
#define SN_RECORD_TIME_ADJUST									-737

//¼�����������л�
#define SN_RECORD_DATE_SWITCH									-738

//IO����
#define SN_RECORD_IO_ERROR										-739

//¼��Ŀ¼����
#define SN_RECORD_DIR_UPDATE									-740

//δ֪�Ĵ����ļ�ϵͳ��ʽ
#define SN_RECORD_UNKNOWN_DISK_FORMAT							-741

#define SN_SNAPSHOT_OPENFILE_FAILED								-742

#define SN_SNAPSHOT_READFILE_FAILED								-743

#define SN_SNAPSHOT_FILE_NO_EXIST								-744

#define SN_SNAPSHOT_QUERY_FAILED								-745

#define SN_SNAPSHOT_CREATE_FILE_FAILED							-746

#define SN_RECORD_INVALID_FILE_NAME								-747


#define SN_RECORD_VIDEO_TYPE_CHANGED							-748

#define SN_RECORD_AUDIO_TYPE_CHANGED							-749
//�ֱ��ʸı�
#define SN_RECORD_VIDEO_IMAGE_CHANGED							-750

//û�������豸����
#define	SN_RECORD_NO_FIND_DEVICEPOLICY							-751

//�ļ�seekʧ��
#define	SN_RECORD_SEEK_BEGIN		 							-752

#define SN_RECORD_INVALID_DATE									-753

//TSFrameQueue����ʱ��ʱ�����TS����ʽ����
#define DATA_FARMAT_ERROR										-754

//û�з��ָô�����
#define SN_RECORD_NO_FIND_GROUP									-755

//����ռ�ʧ��
#define  SN_RECORD_CLEAR_SPACE_FAILED							-756

//¼��100���ļ�������
#define  SN_RECORD_NAME_OVER									-757

//�ƶ�����վ�ļ�ʧ��
#define SN_RECORD_MOVE_RECYCLEBIN_FILE_FAILED					-758

//�ƶ����ļ����ļ�ʧ��
#define SN_RECORD_MOVE_EMPTY_FILE_FAILED				    	-759

//û�п���ʹ�õ�Ŀ¼
#define SN_RECORD_NOT_FIND_DIR									-760

//û�д��̿���ʹ�ã���һ�±�Ĵ���
#define SN_RECORD_WAIT_DISK										-761

#define SN_RECORD_DISCARD_FRAME									-762

//���������ļ�ռ�ܿռ�25%�ķ�ֵ
#define SN_0VER_LOCKFILE_THRESHOLD								-763

#define SN_LOCK_FILE_FAILD										-764
#define SN_UNLOCK_FILE_FAILD									-765

//add by lmg 2014-09-09
//�洢Ŀ¼������                                            
#define SN_RECORD_DIR_NOT_USEABLE                               -766

//���������ļ�ʧ��
#define SN_RECORD_CREATE_INDEXFILE_FAIL                         -767
//û���ҵ�����Ŀ¼
#define SN_RECORD_NO_USEABLE_DIR                                -768
//����¼���ļ���ʧ��
#define SN_RECORD_CREATE_RECORDFILENAME_FAIL                    -769
//����¼��Ŀ¼ʧ��
#define SN_RECORD_CREATE_RECORDDIR_FAIL                         -770
//����¼���ļ�ʧ��
#define SN_RECORD_CREATE_RECORDFILE_FAIL                        -771

#include "SNError.h"
#endif //_RECORDERROR_H_
