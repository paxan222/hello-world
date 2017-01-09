#ifndef  _RECORD_QUERY_CONTION_
#define  _RECORD_QUERY_CONTION_


#include "SNPlatOS.h"
#include "DomainConst.h"
#include "TimeStruct.h"
#include "AlarmExType.h"
#include <vector>
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

class SN_DLL_API RecordQueryCondition
{
public:
	RecordQueryCondition(void);
	~RecordQueryCondition(void);

	RecordQueryCondition(const RecordQueryCondition &p_RecordQueryCondition);

public:
	/***********************************************************************
	**概述：
	*		设置设备Id。
	**输入：
	*		p_pszDeviceId：设备Id
	**输出：
	*		无
	**返回值：
	*		true	：设置成功
	*		false   ：设置失败
	**功能：
	************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**概述：
	*		获取设备Id
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		设备ID
	**功能：
	*
	***************************************************************************/
	const char* getDeviceId() const;


	/***********************************************************************
	**概述：
	*		设置设备IP地址
	**输入：
	*		p_strDeviceIP：设备IP地址
	**输出：
	*		无
	**返回值：
	*		true	：设置成功
	*		false   ：设置失败
	**功能：
	************************************************************************/
	bool setDeviceIP(const char* p_pszDeviceIP);

	/***********************************************************************
	**概述：
	*		获取设备IP地址
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		设备IP地址
	**功能：
	************************************************************************/
	const char* getDeviceIP() const;


	/************************************************************************
	**概述：
	*		设置设备通道号
	**输入：
	*		p_nCameraId	设备通道号
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setCameraId(int p_nCameraId);

	/************************************************************************
	**概述：
	*		获取设备通道号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		设备通道号
	************************************************************************/
	const int getCameraId() const;


	/************************************************************************
	**概述：
	*		获取录像段的开始时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录像段开始时间
	************************************************************************/
	const unsigned long getRecordBeginTime() const;
	const TimeStruct& getStructRecordBeginTime() const;

	/************************************************************************
	**概述：
	*		设置录像段的开始时间
	**输入：
	*		p_nRecordBeginTime :录像段开始时间
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setRecordBeginTime(unsigned long p_nRecordBeginTime);
	void setStructRecordBeginTime(const TimeStruct& p_objTime);


	/************************************************************************
	**概述：
	*		获取录像段的结束时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录像段结束时间
	************************************************************************/
	const unsigned long getRecordEndTime() const;
	const TimeStruct& getStructRecordEndTime() const;

	/************************************************************************
	**概述：
	*		设置录像段的结束时间
	**输入：
	*		p_nRecordEndTime :录像段结束时间
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setRecordEndTime(unsigned long p_nRecordEndTime);
	void setStructRecordEndTime(const TimeStruct& p_objTime);


	/************************************************************************
	**概述：
	*		设置录像文件锁标志
	**输入：
	*		p_bLockFile:  true:锁定文件，false解除锁定
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setLockFlag(bool p_bLockFile);

	/************************************************************************
	**概述：
	*		获取文件锁标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		true:文件锁定
	*		false:文件没有被锁定
	************************************************************************/
	const bool getLockFlag() const;


	/************************************************************************
	**概述：
	*		设置录像文件报警标志
	**输入：
	*		p_bAlarmFile:  true:只查询报警文件，false所有文件
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setAlarmFlag(bool p_bAlarmFile);

	/************************************************************************
	**概述：
	*		获取是否报警标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		true:查询报警录像
	*		false:查询所有录像
	************************************************************************/
	const bool getAlarmFlag() const;


	/************************************************************************
	**概述：
	*		获取录像查询分段间隔
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录像查询分段间隔时间
	************************************************************************/
	const unsigned long getRecordSegmentInterval() const;

	/************************************************************************
	**概述：
	*		设置录像查询结果分段间隔
	**输入：
	*		p_nRecordSegmentInterval :录像结果分段时间间隔，单位：s
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setRecordSegmentInterval(unsigned long p_nRecordSegmentInterval);


	/************************************************************************
	**概述：
	*		获取录像查询时间精度
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录像查询时间精度
	************************************************************************/
	const int getRecordQueryTimePrecision() const;

	/************************************************************************
	**概述：
	*		设置录像查询时间精度
	**输入：
	*		p_nRecordQueryTimePrecision :录像查询时间精度，单位：s
	*		最小精度是3s，最大1小时
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setRecordQueryTimePrecision(int p_nRecordQueryTimePrecision);

	/************************************************************************
	**概述：
	*		设置录像查询报警类型列表
	**输入：
	*		p_objAlarmExTypeList :录像查询报警类型列表
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setAlarmExTypeList(const std::vector<AlarmExType>& p_objAlarmExTypeList);

	/************************************************************************
	**概述：
	*		获取录像查询报警类型列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录像查询报警类型列表
	************************************************************************/
	const std::vector<AlarmExType>& getAlarmExTypeList() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objRecordQueryCondition ：录像查询参数信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	RecordQueryCondition& operator = (const RecordQueryCondition &p_objRecordQueryCondition);

private:
	char				m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];					//设备id
	char				m_szDeviceIp[CONST_MAXLENGTH_IP + 1];						//设备IP地址
	int					m_nCameraId;												//设备通道号
	unsigned long		m_nRecordBeginTime;											//录像段开始时间
	TimeStruct			m_objRecordBeginTime;										//
	unsigned long		m_nRecordEndTime;											//录像段结束时间
	TimeStruct			m_objRecordEndTime;											//
	unsigned long		m_nQuerySegmentInterval;									//查询分段间隔,按多久时间分一段，单位s，0:表示不分段
	int					m_nQueryTimePrecision;										//录像查询时间精度
	bool				m_bIsLockFile;
	bool				m_bIsAlarm;													//是否报警
	std::vector<AlarmExType> m_objAlarmExTypeList;										//报警类型
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif  //_RECORD_QUERY_CONTION_

