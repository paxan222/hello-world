#ifndef _RECOR_DBACKUP_PARAM_H_
#define _RECOR_DBACKUP_PARAM_H_

#include "DomainConst.h"
#include "RecordDirInfo.h"

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

class SN_DLL_API RecordBackupParam
{
public:

public:
	RecordBackupParam(void);
	~RecordBackupParam(void);

	//拷贝构造函数
	RecordBackupParam(const RecordBackupParam& p_objRecordBackupParam);

public:

	/************************************************************************
	**概述：
	*		设置文件尺寸
	**输入：
	*		p_nFileSize ：文件尺寸
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*    设置文件尺寸
	************************************************************************/
	void setFileSize(const int p_nFileSize);

	/************************************************************************
	**概述：
	*		获取文件尺寸
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		文件尺寸
	**功能：
	*     获取文件尺寸
	**************************************************************************/
	const int getFileSize() const ;

	/************************************************************************
	**概述：
	*		设置子目录类型
	**输入：
	*		p_nSubDirType ：子目录类型
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*    
	************************************************************************/
	void setSubDirType(const int p_nSubDirType);

	/************************************************************************
	**概述：
	*		获取子目录类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		子目录类型
	**功能：
	*     
	**************************************************************************/
	const int getSubDirType() const;


	/************************************************************************
	**概述：
	*		设置备份目录信息
	**输入：
	*		p_objRecordDirInfo ：备份目录参数
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*    
	************************************************************************/
	void setRecordDirInfo(const RecordDirInfo& p_objRecordDirInfo);

	/************************************************************************
	**概述：
	*		获取备份目录信息
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		备份目录信息
	**功能：
	*     
	**************************************************************************/
	const RecordDirInfo& getRecordDirInfo() const;

	
	/************************************************************************
	**概述：
	*		设置是否采用公共文件录制
	**输入：
	*		p_bIsCommonFile ：是否采用公共文件录制
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*    
	************************************************************************/
	void setIsCommonFile(const bool p_bIsCommonFile);

	/************************************************************************
	**概述：
	*		获取是否采用公共文件录制
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		是否采用公共文件录制
	**功能：
	*     
	**************************************************************************/
	const bool getIsCommonFile() const;


	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objRecordBackupParam ：录像备份参数对象
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	**************************************************************************/
	RecordBackupParam& operator = (const RecordBackupParam& p_objRecordBackupParam);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objRecordBackupParam：RecordBackupParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个RecordBackupParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const RecordBackupParam& p_objRecordBackupParam);

private:

	int m_nFileSize;										//文件尺寸

	int m_nSubDirType;										//子目录类型

	bool m_bIsCommonFile;									//是否采用公共文件录制
	
	RecordDirInfo m_objRecordDirInfo;						//目录信息
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_RECOR_DBACKUP_PARAM_H_
