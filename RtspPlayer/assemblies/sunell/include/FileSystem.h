#ifndef _FILE_SYSTEM_
#define _FILE_SYSTEM_

#include "SNPlatOS.h"
#include "DomainConst.h"

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

class SN_DLL_API FileSystem
{
public:
	FileSystem();

	//拷贝构造函数
	FileSystem(const FileSystem &p_objFileSystem);
	
	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objFileSystem     系统类型
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	FileSystem &operator =(const FileSystem &p_objFileSystem);

	~FileSystem();

	const char*   getFileSystemName() const;
	void	setFileSystemName(const char* p_szFileSystemName);
	const int			getFileSystemType() const;
	void	setFileSystemType(int p_SystemType);
private:
	int					m_FileSystemType;
	char				m_szFileSystemName[CONST_MAXLENGTH_FILESYSTEM_NAME+1];
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_FILE_SYSTEM_

