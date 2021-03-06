#ifndef _RECORDDIRINFO_H_
#define _RECORDDIRINFO_H_

#include "os_define.h"
#include "SNPlatOS.h"
#include "DomainConst.h"
#include "DiskConst.h"
using namespace DiskConst;

/**********************************************************************/
//此处用于控制文件编译字节对齐，拷贝时两行注释间内容需一起拷贝，
//结束处的“#ifdef PRAGMA_PACK”部分也要一起拷贝，否则pragma pack入栈出栈不匹配
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

class SN_DLL_API RecordDirInfo
{

public:
	RecordDirInfo(void);
	~RecordDirInfo(void);

	RecordDirInfo(const RecordDirInfo &p_RecordDirInfo);

public:
	

	/***********************************************************************
	**概述：
	*		设置当前目录的磁盘类型。
	**输入：
	*		p_nDiskType：本地盘(1)  SD(2)  FTP盘(3)  网络共享盘(4)	，可查看DiskConst.h中DiskType枚举		
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void setDiskType(int p_nDiskType);

	/***********************************************************************
	**概述：
	*		获取当前目录的磁盘类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		当前目录的磁盘类型。
	*功能：
	************************************************************************/
	const int getDiskType() const;	

	
	/***********************************************************************
	**概述：
	*		设置当前目录的磁盘名称。
	**输入：
	*		p_pszDiskName：磁盘名称
	*		例如：网络共享盘(admin(123456)@//192.168.10.194/record)	
	*			  FTP盘(admin(123456)@ftp://192.168.10.194:2100/record)	
	*			  SD(SD1)				  		
	*			  本地盘(F:)				  		
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	bool setDiskName(const char* p_pszDiskName);

	/***********************************************************************
	**概述：
	*		获取当前目录的磁盘名称
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		当前目录的磁盘名称。
	*功能：
	************************************************************************/
	const char* getDiskName() const;	

	/***********************************************************************
	**概述：
	*		设置当前目录的磁盘组编号。
	**输入：
	*		p_nGroupId：磁盘组编号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	void setGroupId(int p_nGroupId);

	/***********************************************************************
	**概述：
	*		获取当前目录的磁盘盘组编号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		当前目录的磁盘盘组编号。
	*功能：
	************************************************************************/
	const int getGroupId() const;

	
	/************************************************************************
	**概述：
	*		设置磁盘可用空间
	**输入：
	*		p_nUsableSpace：磁盘可用空间大小，以M为单位
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setUsableSpace(int p_nUsableSpace);
	
	/************************************************************************
	**概述：
	*		获取磁盘可用空间大小
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		磁盘空间大小
	************************************************************************/
	const int getUsableSpace()	const;
	

	/************************************************************************
	**概述：
	*		设置磁盘剩余空间大小
	**输入：
	*		p_nFreeSpace：磁盘剩余空间，以M为单位
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setFreeSpace(int p_nFreeSpace);

	/************************************************************************
	**概述：
	*		获取磁盘剩余空间大小
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		磁盘剩余空间大小
	************************************************************************/
	const int getFreeSpace() const;

	/************************************************************************
	**概述：
	*		设置属性
	**输入：
	*		p_nAttribute：
	*					网络共享盘：0表示只读，1表示可写，2表示冗余
	*				    SD		: 正常录像（可读写1）  网络盘连接失败时暂存（冗余2）
	*					本地盘	: 可读写（1）  只读（0）  冗余（2）
	*					可查看DiskConst.h中DiskAttribute枚举
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setAttribute(int p_nAttribute);

	/************************************************************************
	**概述：
	*		获取用户可用磁盘属性
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		用户可用磁盘属性
	************************************************************************/
	const int getAttribute() const;

	
	/************************************************************************
	**概述：
	*		设置磁盘是否启用标识
	**输入：
	*		p_bEnableFlag：true表示启用，false表示不启用
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setEnableFlag(bool p_bEnableFlag);

	/************************************************************************
	**概述：
	*		获取磁盘是否启用标识
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		磁盘是否启用标识
	************************************************************************/
	const bool getEnableFlag() const; 


	/************************************************************************
	**概述：
	*		设置报警阈值
	**输入：
	*		p_nAlarmThreshold：百分比表示，0表示不报警
	*						   当磁盘录像空间达到，百分比是启动报警
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setAlarmThreshold(int p_nAlarmThreshold);

	/************************************************************************
	**概述：
	*		获取报警阈值
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警阈值
	************************************************************************/
	const int getAlarmThreshold() const; 

	
	/************************************************************************
	**概述：
	*		设置磁盘状态
	**输入：
	*		p_nStatus：网络共享盘：正常（0）、连接失败（1）
	*				   FTP盘	 : 正常（0）、连接失败（1）
	*				   SD		 : 未格式化（2）、正常（0）、只读（3）、异常（4）、未插卡（5）
	*				   本地盘    ：未格式化（2）、正常（0）、异常（4）、sleep（6）
	*					可查看DiskConst.h中DiskStatus枚举
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setStatus(int p_nStatus);
	
	/************************************************************************
	**概述：
	*		获取状态
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		状态值
	************************************************************************/
	const int getStatus() const;

	/************************************************************************
	**概述：
	*		设置磁盘文件系统格式
	**输入：
	*				
	*SD卡：1：自定义的SDCard文件系统，2 Fat32文件系统，3 Ext2，4 Ext3
	*网盘：5：CIFS文件系统
	*0:未知的文件系统
	*本地磁盘：2 Fat32文件系统
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setFileSystemFormat(int p_nFileSystemFormat);

	/************************************************************************
	**概述：
	*		获取磁盘文件系统格式
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		系统格式值
	************************************************************************/
	const int getFileSystemFormat() const;




	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objRecordDirInfo ：录像目录信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	RecordDirInfo& operator = (const RecordDirInfo &p_objRecordDirInfo);

	/***********************************************************************
	**概述：
	*		判等函数
	**输入：
	*		p_objRecordDirInfo：RecordDirInfo对象
	**输出：
	*		无
	**返回值：
	*		true：相等，false：不相等。
	*功能：
	************************************************************************/
	bool operator == (const RecordDirInfo &p_objRecordDirInfo) const;

private:
	int							m_nDiskType;										//目录磁盘类型
	char						m_szDiskName[CONST_MAXLENGTH_FILE_NAME + 1];		//磁盘名称
	int							m_nGroupId;											//磁盘所属盘组编号
	int							m_nUsableSpace;										//磁盘可用空间 单位：M
	int							m_nFreeSpace;										//磁盘剩余空间 单位：M
	int							m_nAttribute;										//属性
	bool						m_bEnableFlag;										//启用标示
	int							m_nAlarmThreshold;									//报警阈值，单位：M
	int							m_nStatus;											//磁盘状态
	int							m_nFileSystemFormat;								//磁盘文件系统格式

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_RECORDDIRINFO_H_
