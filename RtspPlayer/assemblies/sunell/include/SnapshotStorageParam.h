#ifndef _SNAPSHOTSTORAGEPARAM_H_
#define _SNAPSHOTSTORAGEPARAM_H_

#include <string>
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

class SN_DLL_API SnapshotStorageParam
{
public:
	SnapshotStorageParam(void);
	~SnapshotStorageParam(void);

	enum ServerType
	{
		SERVERTYPE_FTP	= 1
	};

	/************************************************************************
	**概述：
	*		获得服务类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		服务类型
	************************************************************************/
	const int getServerType() const;

	/************************************************************************
	**概述：
	*		设置服务类型
	**输入：
	*		p_nServerType:  服务类型
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setServerType(const int &p_nServerType);

	/************************************************************************
	**概述：
	*		获得服务路径地址
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		服务路径地址
	************************************************************************/
	const std::string getServerAddress() const;

	/************************************************************************
	**概述：
	*		设置服务路径地址
	**输入：
	*		p_ServerAddress 服务路径地址
	**输出：
	*		无
	**返回值：
	*	    无
	************************************************************************/
	void setServerAddress(const std::string &p_ServerAddress);

	SnapshotStorageParam& operator = (const SnapshotStorageParam &p_objSnapshotStorageParam);

private:
	int m_nServerType;				//类型
	std::string  m_ServerAddress;      


}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif