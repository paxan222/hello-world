#ifndef TSUNPACKAGER_H_
#define TSUNPACKAGER_H_

#include "SN_Struct.h"
#include "SNPlatOS.h"

#if (defined(WIN32) || defined(_WIN32_WCE))
	#include <winsock2.h>
#endif


typedef long (CALLBACK* UnpackageCallBack) (long hHandle, NVDC_STRUCT::ST_AVFrameData* p_pstAVFrameData, void* pUserData);

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
/**********************************************************************//**********************************************************************/

class TSUnpackagerImpl;

class SN_DLL_API TSUnpackager
{
public:
	TSUnpackager(void);
	~TSUnpackager(void);
	
public:

	/************************************************************************
	**概述：
	*		设置解包回调函数,当UnpackageCallBack设置NULL时取消回调。
	**输入：
	*		hHandle：回调函数参数。当UnpackageCallBack执行，回传该参数。一个32位整形值，当没有句柄时可以设置NULL
	*		fUnpackageCallBack：解包回调函数。
	**输出：
	*		无。
	**返回值：
	*		执行成功返回0，错误时返回错误码。
	**备注：
	*		出于性能考虑，fUnpackageCallBack回调接口中的p_pstAVFrameData里面的内存由sdk内部分配，在调用stop之后分配的内存会被释放
	*		调用stop之前需确保p_pstAVFrameData不被使用
	************************************************************************/
	void setUnpackageCallBack(long hHandle, UnpackageCallBack fUnpackageCallBack, void* pUserData);

	/************************************************************************
	**概述：
	*		启动解码器。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		执行成功返回true，错误时返回false。
	**功能：
	************************************************************************/
	bool start();

	/************************************************************************
	**概述：
	*		停止解码器
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		
	**功能：
	************************************************************************/
	void stop();

	/************************************************************************
	**概述：
	*		输入TS音视频流
	**输入：
	*		p_objTSAVData：TS数据流。
	*		p_nDataLen：流数据大小，单位为字节。
	**输出：
	*		
	**返回值：
	*		SN_SUCCESS：成功。
	*		SN_ERROR_QUEUE_FULL：缓冲队列满，需要重新调用接口塞入数据。
	**功能：
	*
	************************************************************************/
	int inputTSData(const char* p_szTSData, const unsigned int p_nDataLen);

private:
	TSUnpackagerImpl*	m_pTSUnpackagerImpl;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif
