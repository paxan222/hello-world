#ifndef  _FILE_SYSTEM_ABILITY_
#define  _FILE_SYSTEM_ABILITY_
#include "FileSystem.h"
#include "DiskAttributeEx.h"
#include <vector>
#include "SNPlatOS.h"

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

class SN_DLL_API FileSystemAbility
{
public:
	FileSystemAbility();
	//拷贝构造函数
	/************************************************************************
	**概述：设置设备ID
	*
	**输入：
	*		p_objFileSystemAbility
	**输出：
	*		p_objFileSystemAbility
	**返回值：
	*		无
	**功能：       
	*		拷贝构造文件系统能力
	************************************************************************/
	FileSystemAbility(const FileSystemAbility &p_objFileSystemAbility);

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objFileSystemAbility
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	FileSystemAbility &operator =(const FileSystemAbility &p_objFileSystemAbility);
	~FileSystemAbility();
	const int  getDiskType() const;
	void	   setDiskType(const int p_DiskType);

	const std::vector<FileSystem>  getFileSystemList() const;
	void setFileSystemList(const std::vector<FileSystem> &p_FileSystemList);
	
	const std::vector<DiskAttributeEx>& getDiskAttributeList() const;
	void setDiskAttributeList(const std::vector<DiskAttributeEx> &p_DiskAttributeList);

private:
	int							m_DiskType;
	std::vector<FileSystem>		m_FileSystemList;
	std::vector<DiskAttributeEx>	m_DiskAttributeList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_FILE_SYSTEM_ABILITY_
