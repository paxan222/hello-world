#ifndef  _RECORD_TIME_SEGMENT_
#define  _RECORD_TIME_SEGMENT_

#include "SNPlatOS.h"
#include "TimeStruct.h"

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

class SN_DLL_API RecordTimeSegment
{
public:
	RecordTimeSegment(void);
	RecordTimeSegment(unsigned long p_nBeginTime,unsigned long p_nEndTime,bool p_bIsLock,unsigned long p_DataLength,bool p_IsAlarm);
	~RecordTimeSegment(void);

	RecordTimeSegment(const RecordTimeSegment &p_RecordTimeSegment);

public:

	/************************************************************************
	**概述：
	*		设置录像开始时间
	**输入：
	*		p_nRecordBeginTime	设备录像段开始时间
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setRecordBeginTime(unsigned long p_nRecordBeginTime);
	void setStructRecordBeginTime(const TimeStruct& p_objTime);

	/************************************************************************
	**概述：
	*		获取录像开始时间
	**输入：
	*		获取录像开始时间
	**输出：
	*		无
	**返回值：
	*		录像开始时间
	************************************************************************/
	const unsigned long getRecordBeginTime() const;
	const TimeStruct& getStructRecordBeginTime() const;


	/************************************************************************
	**概述：
	*		设置录像结束时间
	**输入：
	*		p_nRecordEndTime	设备录像段结束时间
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setRecordEndTime(unsigned long p_nRecordEndTime);
	void setStructRecordEndTime(const TimeStruct& p_objTime);

	/************************************************************************
	**概述：
	*		获取录像段结束时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录像结束时间
	************************************************************************/
	const unsigned long getRecordEndTime() const;
	const TimeStruct& getStructRecordEndTime() const;


	/************************************************************************
	**概述：
	*		设置录像锁标记
	**输入：
	*		p_isLock	：true 锁定文件，false 解锁文件
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void   setRecordLockFlag(bool p_isLock);
	
	/************************************************************************
	**概述：
	*		获取当前录像是否加锁
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		true：文件加锁
	*		false：文件没有加锁
	************************************************************************/
	const bool getRecordLockFlag() const;

	/************************************************************************
	**概述：
	*		设置录像报警标记
	**输入：
	*		p_isAlarm	：true 报警，false 不是报警文件
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void   setRecordAlarmFlag(bool p_isAlarm);

	/************************************************************************
	**概述：
	*		获取当前录像是否报警
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		true：文件报警
	*		false：文件没有报警
	************************************************************************/
	const bool getRecordAlarmFlag() const;


	/************************************************************************
	**概述：
	*		设置录像数据长度
	**输入：
	*		p_nRecordDataLength	：录像数据长度
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setRecordDataLength(unsigned long p_nRecordDataLength);

	/************************************************************************
	**概述：
	*		获取录像数据长度
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录像数据长度
	************************************************************************/
	const unsigned long getRecordDataLength() const;

	void setVideoEncoderType(int p_nVideoEncoderType);

	const int getVideoEncoderType() const;


	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objRecordTimeSegment ：录像时间段信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	RecordTimeSegment& operator = (const RecordTimeSegment &p_objRecordTimeSegment);

private:
	unsigned long					m_nBeginTime;				//开始时间
	TimeStruct						m_objRecordBeginTime;		//
	unsigned long					m_nEndTime;					//结束时间
	TimeStruct						m_objRecordEndTime;			//
	bool							m_bIsLock;					//文件是否加锁
	unsigned long					m_nRecordDataLength;		//该时间段内数据长度
	bool							m_bIsAlarmRecordFlag;		//是否是报警录像
	int								m_nVideoEncoderType;		//视频编码类型
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_RECORD_TIME_SEGMENT_
