#ifndef _DEVICEWORKSTATE_H_
#define _DEVICEWORKSTATE_H_

#include "AlarmInStatistic.h"
#include "AlarmOutStatistic.h"
#include "CpuStatistic.h"
#include "DiskStatistic.h"
#include "MemStatistic.h"
#include "VideoChannelStatistic.h"
#include "SNPlatOS.h"
#include<vector>
using namespace std;


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

class SN_DLL_API DeviceWorkState
{
public:
	DeviceWorkState(void);
	~DeviceWorkState(void);
	
	//拷贝构造函数
	DeviceWorkState(const DeviceWorkState& p_objDeviceWorkState);

public:
	
	/************************************************************************
	**概述：
	*		设置cpu统计信息
	**输入：
	*		p_objCpuStatistic：cpu统计信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setCpuStatistic(const CpuStatistic& p_objCpuStatistic);
	
	/************************************************************************
	*概述：
	*		获取cpu统计信息
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		cpu统计信息
	*功能：       
	*************************************************************************/
	const CpuStatistic& getCpuStatistic() const;


	/************************************************************************
	**概述：
	*		设置内存统计信息
	**输入：
	*		p_objMemStatistic：内存统计信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setMemStatistic(const MemStatistic& p_objMemStatistic);
	
	/************************************************************************
	*概述：
	*		获取内存统计信息
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		内存统计信息
	*功能：       
	*************************************************************************/
	const MemStatistic& getMemStatistic() const;


	/************************************************************************
	**概述：
	*		设置磁盘统计信息
	**输入：
	*		p_objDiskStatisticList：磁盘统计信息列表
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setDiskStatisticList(const vector<DiskStatistic>& p_objDiskStatisticList);
	
	/************************************************************************
	*概述：
	*		获取磁盘统计信息
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		磁盘统计信息
	*功能：       
	*************************************************************************/
	const vector<DiskStatistic>* getDiskStatisticList() const;

	
	/************************************************************************
	**概述：
	*		设置视频通道统计信息
	**输入：
	*		p_objVideoChannelStatisticList：视频通道统计信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setVideoChannelStatisticList(const vector<VideoChannelStatistic>& p_objVideoChannelStatisticList);
	
	/************************************************************************
	*概述：
	*		获取视频通道统计信息
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		视频通道统计信息
	*功能：       
	*************************************************************************/
	const vector<VideoChannelStatistic>* getVideoChannelStatisticList() const;

	
	/************************************************************************
	**概述：
	*		设置报警输入通道统计信息
	**输入：
	*		p_objAlarmInStatisticList：报警输入通道统计信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setAlarmInStatisticList(const vector<AlarmInStatistic>&	p_objAlarmInStatisticList);
	
	/************************************************************************
	*概述：
	*		获取报警输入通道统计信息
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		报警输入通道统计信息
	*功能：       
	*************************************************************************/
	const vector<AlarmInStatistic>* getAlarmInStatisticList() const;

	
	/************************************************************************
	**概述：
	*		设置报警输出通道统计信息
	**输入：
	*		p_objAlarmOutStatisticList：报警输出通道统计信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setAlarmOutStatisticList(const vector<AlarmOutStatistic>& p_objAlarmOutStatisticList);
	
	/************************************************************************
	*概述：
	*		获取报警输出通道统计信息
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		报警输出通道统计信息
	*功能：       
	*************************************************************************/
	const vector<AlarmOutStatistic>* getAlarmOutStatisticList() const;

	/************************************************************************
	*概述：
	*		赋值函数
	**输入：
	*		p_objDeviceWorkState：设备工作状态信息
	**输出：
	*		无
	**返回值：
	*		DDNS信息
	**功能：
	*
	*************************************************************************/
	DeviceWorkState& operator =(const DeviceWorkState& p_objDeviceWorkState);


private:
	
	CpuStatistic					m_objCpuStatistic;					//cpu统计信息
	MemStatistic					m_objMemStatistic;					//内存统计信息
	vector<DiskStatistic>			m_objDiskStatisticList;				//磁盘统计信息
	vector<VideoChannelStatistic>	m_objVideoChannelStatisticList;		//视频通道统计信息
	vector<AlarmInStatistic>		m_objAlarmInStatisticList;			//报警输入统计信息
	vector<AlarmOutStatistic>		m_objAlarmOutStatisticList;			//报警输出统计信息
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_DEVICEWORKSTATE_H_
