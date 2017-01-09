#ifndef _DISKCONST_
#define _DISKCONST_
namespace DiskConst
{
	const int  MiniRecordQueryPrecision = 4;//��С��ѯʱ�侫��
	const int  MaxRecordQueryPresion = 3600;//����ѯʱ�侫��

	const char SDCardAlarmSourceName[] = {"SDCard"};
	const char NasDiskAlarmSourceName[] = {"NasDisk"};
	const char FtpDiskAlarmSourceName[] = {"FtpDisk"};

	enum DiskType
	{
		DISKTYPE_HARDDISK			= 1, //����Ӳ��
		DISKTYPE_SDCARD				= 2, //SD��
		DISKTYPE_FTP				= 3, //FTP
		DISKTYPE_NAS				= 4,  //NAS
		DISKTYPE_EXTERN_DISK		= 5,  //����豸
		DISKTYPE_REMOTE_EXTERN_DISK = 6	  //Զ������豸
	};

	enum DiskStatus
	{
	
		DISKSTATUS_TIME_OUT					= -1,    //д�ļ���ʱ
		DISKSTATUS_OK						= 1,	//����״̬
		DISKSTATUS_ERROR					= 2,	//������״̬
		DISKSTATUS_SD_NOT_EXISTENT			= 3,	//sd��������
		DISKSTATUS_WRITE_PROTECT			= 4,	//����д����
		DISKSTATUS_NOT_FORMAT				= 5,	//����δ��ʽ��
		DISKSTATUS_FORMATTING				= 6,	//�������ڸ�ʽ��
		DISKSTATUS_HD_NOT_EXISTENT			= 7,	//���̲�����
		DISKSTATUS_HD_SLEEP					= 8,	//��������
		DISKSTATUS_CONNECT_FAILED			= 9,	//����ʧ��
		DISKSTATUS_NAS_NOT_EXISTENT			= 10,	//NAS������
		DISKSTATUS_NOT_EXISTENT				= 11,	//NAS���̲�����
		DISKSTATUS_NO_PARTITION				= 12,	///����δ����
		DISKSTATUS_DISCONNECT_DEVICE		= 13,	///����δ����
		DISKSTATUS_DISK_ISREPAIRING			= 14,   //Ӳ�������޸�		
		DISKSTATUS_DISK_REMOVED				= 15,   //Ӳ�����Ƴ�
		DISKSTATUS_WAIT_FROMAT				= 16,	//׼����ʽ��
		DISKSTATUS_DISK_ISREMOVING			= 17,	// �����Ƴ�Ӳ��
		
		DISKSTATUS_FORMAT_SUCCEED			= 18,	// ��ʽ���ɹ�
		DISKSTATUS_FORMAT_FAILED			= 19,	// ��ʽ��ʧ��
		DISKSTATUS_WAIT_REPAIR				= 20,	// �ȴ��޸�
		DISKSTATUS_REPAIR_SUCCEED			= 21,	// �޸��ɹ�
		DISKSTATUS_REPAIR_FAILED			= 22,	// �޸�ʧ��
		DISKSTATUS_HD_EXISTENT				= 23,	//���̴洢
		DISKSTATUS_PYSICAL_ERROR            = 24    //��������
	};
	
		enum DataVersion
	{
		DataVersion_OK							= 30, //���ݸ�ʽ�汾����Ҫ��
		DataVersion_Low_OK						= 31, // ���ݸ�ʽ�汾̫�ͣ������Լ���
		DataVersion_Low_Unuseable				= 32, // ���ݸ�ʽ�汾̫�ͣ��޷�����
		DataVersion_High_OK						= 33, // ���ݸ�ʽ�汾̫�ߣ������Լ���
		DataVersion_High_Unuseable				= 34, // ���ݸ�ʽ�汾̫�ߣ��޷����� 	
		DataVersion_Access_Ability_UnMatch		= 35 //	�������ݷ���������ƥ��
	};


	enum DiskAttribute
	{
		DISKATTRIBUTE_READ_WRITE	= 1,//�ɶ�д
		DISKATTRIBUTE_READ_ONLY		= 2,//ֻ��
		DISKATTRIBUTE_REDUNDANCY	= 3, //����
		DISKATTRIBUTE_BACKUP		= 4 //������
	};

	enum FileSystemFormat
	{
		FILESYSTEM_UNKNOWN			= 0,		//δ֪���ļ�ϵͳ
		FILESYSTEM_SDVIDEO			= 1,		//�Զ����SDCard�ļ�ϵͳ
		FILESYSTEM_FAT32			= 2,		//Fat32
		FILESYSTEM_EXT2				= 3,		//Ext2
		FILESYSTEM_EXT3				= 4,		//Ext3
		FILESYSTEM_CIFS				= 5,		//CIFS,��������ļ�ϵͳ
		FILESYSTEM_NFS				= 6,		//NFS,��������ļ�ϵͳ
		FILESYSTEM_NTFS				= 7,		//NTFS,
		FILESYSTEM_EXT4				= 8		    //Ext4
	};

	enum DiskError
	{
		DISKERROR_STATUS_ERROR		= -1,    //����״̬����
		DISKERROR_NO_LEFT_SPACE	    = -2,	 //����û�п��ÿռ�
		DISKERROR_THRESHOLD_ALARM	= -3	 //����ʣ��ռ�ﵽָ����ֵ 	
	};
	enum BackupTaskSubDirType
	{
		BACKUP_DIR_TYPE_DEVICE_IP = 1,
		BACKUP_DIR_TYPE_DEVICE_ID,
		BACKUP_DIR_TYPE_NONE 
	};

	enum BackupTaskFileType
	{
		BACKUP_FILE_TYPE_TS = 1,
		BACKUP_FILE_TYPE_AVI = 2
	};

	enum FTPFileMode
	{
		FTPMODE_READ_ONLY = 0x01,
		FTPMODE_WRITE_ONLY = 0x02,
		FTPMODE_ReadWrite = 0x04
	};

	enum DiskPlatForm
	{
		PLATFORM_WINDOWS = 0,
		PLATFORM_OTHER = 1
	};
};
#endif
