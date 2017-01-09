#ifndef _DISKCONST_
#define _DISKCONST_
namespace DiskConst
{
	const int  MiniRecordQueryPrecision = 4;//最小查询时间精度
	const int  MaxRecordQueryPresion = 3600;//最大查询时间精度

	const char SDCardAlarmSourceName[] = {"SDCard"};
	const char NasDiskAlarmSourceName[] = {"NasDisk"};
	const char FtpDiskAlarmSourceName[] = {"FtpDisk"};

	enum DiskType
	{
		DISKTYPE_HARDDISK			= 1, //本地硬盘
		DISKTYPE_SDCARD				= 2, //SD卡
		DISKTYPE_FTP				= 3, //FTP
		DISKTYPE_NAS				= 4,  //NAS
		DISKTYPE_EXTERN_DISK		= 5,  //外接设备
		DISKTYPE_REMOTE_EXTERN_DISK = 6	  //远程外接设备
	};

	enum DiskStatus
	{
	
		DISKSTATUS_TIME_OUT					= -1,    //写文件超时
		DISKSTATUS_OK						= 1,	//正常状态
		DISKSTATUS_ERROR					= 2,	//不正常状态
		DISKSTATUS_SD_NOT_EXISTENT			= 3,	//sd卡不存在
		DISKSTATUS_WRITE_PROTECT			= 4,	//磁盘写保护
		DISKSTATUS_NOT_FORMAT				= 5,	//磁盘未格式化
		DISKSTATUS_FORMATTING				= 6,	//磁盘正在格式化
		DISKSTATUS_HD_NOT_EXISTENT			= 7,	//磁盘不存在
		DISKSTATUS_HD_SLEEP					= 8,	//磁盘休眠
		DISKSTATUS_CONNECT_FAILED			= 9,	//连接失败
		DISKSTATUS_NAS_NOT_EXISTENT			= 10,	//NAS不存在
		DISKSTATUS_NOT_EXISTENT				= 11,	//NAS磁盘不存在
		DISKSTATUS_NO_PARTITION				= 12,	///磁盘未分区
		DISKSTATUS_DISCONNECT_DEVICE		= 13,	///磁盘未连接
		DISKSTATUS_DISK_ISREPAIRING			= 14,   //硬盘正在修复		
		DISKSTATUS_DISK_REMOVED				= 15,   //硬盘已移除
		DISKSTATUS_WAIT_FROMAT				= 16,	//准备格式化
		DISKSTATUS_DISK_ISREMOVING			= 17,	// 正在移除硬盘
		
		DISKSTATUS_FORMAT_SUCCEED			= 18,	// 格式化成功
		DISKSTATUS_FORMAT_FAILED			= 19,	// 格式化失败
		DISKSTATUS_WAIT_REPAIR				= 20,	// 等待修复
		DISKSTATUS_REPAIR_SUCCEED			= 21,	// 修复成功
		DISKSTATUS_REPAIR_FAILED			= 22,	// 修复失败
		DISKSTATUS_HD_EXISTENT				= 23,	//磁盘存储
		DISKSTATUS_PYSICAL_ERROR            = 24    //磁盘物理坏
	};
	
		enum DataVersion
	{
		DataVersion_OK							= 30, //数据格式版本符合要求
		DataVersion_Low_OK						= 31, // 数据格式版本太低，但可以兼容
		DataVersion_Low_Unuseable				= 32, // 数据格式版本太低，无法兼容
		DataVersion_High_OK						= 33, // 数据格式版本太高，但可以兼容
		DataVersion_High_Unuseable				= 34, // 数据格式版本太高，无法兼容 	
		DataVersion_Access_Ability_UnMatch		= 35 //	磁盘数据访问能力不匹配
	};


	enum DiskAttribute
	{
		DISKATTRIBUTE_READ_WRITE	= 1,//可读写
		DISKATTRIBUTE_READ_ONLY		= 2,//只读
		DISKATTRIBUTE_REDUNDANCY	= 3, //冗余
		DISKATTRIBUTE_BACKUP		= 4 //备份盘
	};

	enum FileSystemFormat
	{
		FILESYSTEM_UNKNOWN			= 0,		//未知的文件系统
		FILESYSTEM_SDVIDEO			= 1,		//自定义的SDCard文件系统
		FILESYSTEM_FAT32			= 2,		//Fat32
		FILESYSTEM_EXT2				= 3,		//Ext2
		FILESYSTEM_EXT3				= 4,		//Ext3
		FILESYSTEM_CIFS				= 5,		//CIFS,网络磁盘文件系统
		FILESYSTEM_NFS				= 6,		//NFS,网络磁盘文件系统
		FILESYSTEM_NTFS				= 7,		//NTFS,
		FILESYSTEM_EXT4				= 8		    //Ext4
	};

	enum DiskError
	{
		DISKERROR_STATUS_ERROR		= -1,    //磁盘状态错误
		DISKERROR_NO_LEFT_SPACE	    = -2,	 //磁盘没有可用空间
		DISKERROR_THRESHOLD_ALARM	= -3	 //磁盘剩余空间达到指定阀值 	
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
