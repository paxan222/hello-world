#ifndef PSUNPACKAGERV3_H_
#define PSUNPACKAGERV3_H_

#include "SN_Struct.h"
#include "SNPlatOS.h"
#include <vector>

class Mpeg2PSBuffer;
class SNMutex;
using namespace NVDC_STRUCT;

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

class PSUnpackagerV3Impl;

class SN_DLL_API PSUnpackagerV3
{
public:
	PSUnpackagerV3(void);
	~PSUnpackagerV3(void);
	
public:

	//设置数据帧的格式，1：原始流，4：ps流
	void setFrameDataFormat(const int p_nFormat);

	//使用数据标志，false：返回的帧数据没有视频数据，true：返回的帧数据里携带视频数据
	void setUseDateFlag(const bool p_bFlag);

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
	*		输入PS音视频流
	**输入：
	*		p_objPSAVData：PS数据流。
	*		p_nDataLen：流数据大小，单位为字节。
	**输出：
	*		
	**返回值：
	*		SN_SUCCESS：成功。
	*		SN_ERROR_QUEUE_FULL：缓冲队列满，需要重新调用接口塞入数据。
	**功能：
	*
	************************************************************************/
	int inputPSData(const char* p_szPSData, const unsigned int p_nDataLen);

	/************************************************************************
	**概述：
	*		获得下一帧数据
	**输入：
	*		p_pstAVFrameData：帧数据
	**输出：
	*		
	**返回值：
	*		执行成功返回0，错误时返回错误码。
	**备注：
	*		p_pstAVFrameData里面的内存由sdk调用者分配
	************************************************************************/
	int getNextAVFrameData(NVDC_STRUCT::ST_AVFrameData* p_pstAVFrameData);

private:
	void clearBuffer();

public:
	void insertOneFrame(NVDC_STRUCT::ST_AVFrameData* p_pstAVFrameData);

private:
	Mpeg2PSBuffer*	m_pobjMpeg2PSBuffer;
	std::vector<NVDC_STRUCT::ST_AVFrameData*>	m_objFrameVector;
	SNMutex*   m_pobjLock;

	int				m_nFormat;				//解帧后的数据类型
	bool			m_bUseDateFlag;			//使用数据标志

	char*			m_pszPSBuf;				//数据缓存
	int				m_nLeftDataLen;			//数据有效长度
	int				m_nBufMaxSize;			//数据最大长度

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //PSUNPACKAGERV3_H_
