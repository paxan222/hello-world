#ifndef _AUDIO_ALARM_DATA_H_
#define _AUDIO_ALARM_DATA_H_

#include "DomainConst.h"
#include "SNPlatOS.h"

#if defined( WIN32 )
	typedef __int64				INT64;
#else
	typedef long long			INT64;
#endif

#if (defined(WIN32) || defined(_WIN32_WCE))
	#ifdef SN_DLL_EXPORTS
		#define AUDIO_ALARM_DATA_API __declspec(dllexport)
	#else
		#define AUDIO_ALARM_DATA_API __declspec(dllimport)
	#endif
#else
	#define AUDIO_ALARM_DATA_API
#endif



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

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class AUDIO_ALARM_DATA_API AudioAlarmData
{

public:
	AudioAlarmData();
	~AudioAlarmData();


	void setCameraNo(const int p_nCameraNo);

	/************************************************************************
	**概述：
	*		获取产生语音报警频数据的摄像机的编号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		产生语音报警频数据的摄像机的编号
	**功能：
	*		获取产生语音报警频数据的摄像机的编号
	**************************************************************************/
	const int getCameraNo() const;



	/************************************************************************
	**概述：
	*		设置语音报警频数据的帧序列号
	**输入：
	*		p_nSequenceId : 帧序列号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		设置语音报警频数据的帧序列号
	**************************************************************************/
	void setSequenceId(const unsigned int p_nSequenceId);

	/************************************************************************
	**概述：
	*		获取语音报警数据的帧序列号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		帧序列号
	**功能：
	*		获取语音报警频数据的帧序列号，用来对语音报警频数据进行排序
	**************************************************************************/
	const unsigned int getSequenceId() const;

	
	void setAudioAlarmData(const int p_nAudioAlarmData);


	const int getAudioAlarmData() const;

private:
	int m_nCameraNo;						//摄像机号，表示数据来自第几路
	unsigned int m_nSequenceId;				//数据帧序号

	int m_nAlarmData;						//数据

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_AUDIO_ALARM_DATA_H_
