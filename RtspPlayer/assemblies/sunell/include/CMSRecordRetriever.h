#ifdef RECORD_INTERFACE
#ifndef _CMSRECORDRETRIEVER_H_
#define _CMSRECORDRETRIEVER_H_

#include "SNPlatOS.h"
#include "RecordDirInfo.h"
#include "RecordInfo.h"
#include <vector>
#include "RecordFileEx.h"

class RecordRetriever;

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

class SN_DLL_API CMSRecordRetriever
{
public:
	CMSRecordRetriever();

	~CMSRecordRetriever();

public:
	/************************************************************************
	**概述：
	*		设置目录列表
	**输入：
	*		p_RecordDirInfoList:录像目录列表
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	 void  setRecordDirList(const std::vector<RecordDirInfo> &p_RecordDirInfoList);

	/***********************************************************************
	**概述：
	*		打开录像文件。
	**输入：
	*		p_RecordInfo	要打开的录像文件信息。
	**输出：
	*		无
	**返回值：
	*		SN_SCUESS:	打开成功
	*		<0:			打开失败
	**功能描述：
	*		根据p_RecordInfo打开录像文件，返回值等于0则打开成功，否则打开失败。
	*		文件打开成功后用read不停的读取视频数据。
	************************************************************************/
	int open(const RecordInfo &p_RecordInfo);

	/***********************************************************************
	**概述：
	*		打开ftp录像文件。
	**输入：
	*		p_RecordFile:ftp录像文件信息
	**输出：
	*		无
	**返回值：
	*		SN_SCUESS:	打开成功
	*		<0:			打开失败
	**功能描述：
	*		根据p_RecordFile打开ftp录像文件，返回值等于0则打开成功，否则打开失败。
	*		文件打开成功后用read不停的读取视频数据。
	************************************************************************/
	int open(const RecordFileEx &p_RecordFile);

	/***********************************************************************
	**概述：
	*		关闭录像文件
	**输入：
	*		无
	**输出：
	*		无。
	**返回值：
	*		无
	**功能描述：
	*		关闭录像文件
	************************************************************************/
	void close();

	/***********************************************************************
	**概述：
	*		读取录像文件数据。
	**输入：
	*		p_nDataLength:要读取的数据长度
	**输出：
	*		p_szAVData:读取的音视频数据。
	**返回值：
	*		>0:	读取到的数据长度。
	*		=0：文件已读到结尾。
	*		<0:	读文件出错。
	**功能描述：
	*		读取录像数据到指定的缓冲区中，返回读取录像数据的长度。如果返回值等于0则已读到文件结尾，
	*		小于0则读文件出错。
	************************************************************************/
	int read(char *p_szAVData,int p_nDataLength);

	/***********************************************************************
	**概述：
	*		录像文件定位。
	**输入：
	*		p_TimeStamp	录像文件要定位到的时间位置。绝对时间，单位：s
	**输出：
	*		无。
	**返回值：
	*		SN_SCUESS:	定位成功
	*		<0:			定位失败
	**功能描述：
	*		根据p_TimeStamp定位录像文件到指定的时间位置，返回值等于0则定位成功，否则失败。
	*		文件定位成功后用read不停的读取视频数据。
	************************************************************************/
	int locateTime(unsigned long p_nTimeStamp);

	/***********************************************************************
	**概述：
	*		定位当前读取位置的下一个I帧
	**输入：
	*		无
	**输出：
	*		无。
	**返回值：
	*		SN_SCUESS:	定位成功
	*		<0:			定位失败
	**功能描述：
	*		
	************************************************************************/
	int locateNextIFrame();

	/***********************************************************************
	**概述：
	*		定位当前读取位置的上一个I帧
	**输入：
	*		无
	**输出：
	*		无。
	**返回值：
	*		SN_SCUESS:	定位成功
	*		<0:			定位失败
	**功能描述：
	*		
	************************************************************************/
	int locatePreIFrame();

private:
	//拷贝构造函数
	CMSRecordRetriever(const CMSRecordRetriever& p_objObject)
	{
	}

	//赋值函数
	CMSRecordRetriever& operator = (const CMSRecordRetriever& p_objObject)
	{
		return *this;
	}

private:
	RecordRetriever* m_pobjRecordRetriever;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSRECORDRETRIEVER_H_
#endif