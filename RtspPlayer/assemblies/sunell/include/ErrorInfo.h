#ifndef _ERRORINFO_H_
#define _ERRORINFO_H_

#include <string>
using namespace std;

#include "SNPlatOS.h"
#include "SNError.h"
#include "RecordError.h"

class SNMutex;

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

class SN_DLL_API ErrorInfoHelper
{
public:
	ErrorInfoHelper();

	~ErrorInfoHelper();

public:
	string  formatErrorInfo(const int p_nErrorCode);

private:
	string	m_strErrorInfo;
	SNMutex * m_objSNMutex;
	

}_PACKED_1_;

class ErrorInfo
{
private:
	ErrorInfo(void){};

	~ErrorInfo(void){};

public:
	/************************************************************************
	**概述：
	*		获取指定错误号对应的错误信息的详细描述
	**输入：
	*		p_nErrorCode :错误号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		获取指定错误号对应的错误信息的详细描述
	************************************************************************/
	static  string formatMessage(const int p_nErrorCode)
	{
		static ErrorInfoHelper objErrorInfoHelper;
		return objErrorInfoHelper.formatErrorInfo(p_nErrorCode);
	}


}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif
