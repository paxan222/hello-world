#ifndef _DISK_ALARM_PARAMV2_H
#define _DISK_ALARM_PARAMV2_H

#include "SNPlatOS.h"
#include "AlarmOutAction.h"
#include "AlarmPTZAction.h"
#include <vector>
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


class SN_DLL_API DiskAlarmParamV2
{
public:
	DiskAlarmParamV2(void);
	~DiskAlarmParamV2(void);

	//拷贝构造函数
	DiskAlarmParamV2 (const DiskAlarmParamV2 &p_objDiskAlarmParamV2);

	/****************************************************************************
	**概述：
	*		设置上报时间间隔
	**输入：
	*		p_nInterval：上报时间间隔
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setInterval(const int p_nInterval);

	/****************************************************************************
	**概述：
	*		获得上报时间间隔
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		上报时间间隔
	**功能：
	*
	*******************************************************************************/
	const int getInterval() const;

	/************************************************************************
	**概述：
	*		设置是否启动报警检测标志
	**输入：
	*		p_bFlag：是否启动报警检测标志
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	设置是否启动报警检测标志
	************************************************************************/
	void setAlarmEnableFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取是否启动报警检测标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		是否启动报警检测标志
	**功能：
	*	获取是否启动报警检测标志
	************************************************************************/
	const bool getAlarmEnableFlag() const;
	
	/************************************************************************
	**概述：
	*		设置报警阈值
	**输入：
	*		p_nAlarmThreshold：百分比表示，0表示不报警
	*						   当磁盘录像空间达到，百分比是启动报警
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setAlarmThreshold(const int p_nAlarmThreshold);

	/************************************************************************
	**概述：
	*		获取报警阈值
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警阈值
	************************************************************************/
	const int getAlarmThreshold() const; 

	/************************************************************************
	**概述：
	*		设置报警输出行为对象列表
	**输入：
	*		p_objAlarmOutActionList：报警输出行为对象列表
	**输出：
	*		无
	**返回值：
	*		
	**功能：
	*      
	**************************************************************************/
	void setAlarmOutAction(const vector<AlarmOutAction>& p_objAlarmOutActionList);

	/************************************************************************
	**概述：
	*		获取报警输出行为对象列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警输出行为对象列表
	**功能：
	*      
	**************************************************************************/
	vector<AlarmOutAction>* getAlarmOutAction() const;

	/************************************************************************
	**概述：
	*		设置报警云台行为对象列表
	**输入：
	*		p_objAlarmPTZActionList：报警云台行为对象列表
	**输出：
	*		无
	**返回值：
	*		
	**功能：
	*      
	**************************************************************************/
	void setAlarmPTZAction(const vector<AlarmPTZAction>& p_objAlarmPTZActionList);

	/************************************************************************
	**概述：
	*		获取报警云台行为对象列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警云台行为对象列表
	**功能：
	*      
	**************************************************************************/
	vector<AlarmPTZAction>* getAlarmPTZAction() const;

	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objNetworkAlarmEvent：网络报警事件
	**输出：
	*		无
	**返回值：
	*		赋值后的网络报警事件
	**功能：
	*		
	*****************************************************************************/
	DiskAlarmParamV2& operator = (const DiskAlarmParamV2 &p_objDiskAlarmParamV2);

private:

	unsigned int					m_nInterval;				//上报间隔，单位为秒，最小间隔为10秒，最大为86400秒(1天)
	int								m_nAlarmThreshold;			//报警阈值, 单位为百分比
	bool							m_bAlarmEnableFlag;			//是否启动磁盘报警(false：不启动， true：启动)
	std::vector<AlarmOutAction>		m_objAlarmOutActionList;	//报警输出行为对象列表
	std::vector<AlarmPTZAction>		m_objAlarmPTZActionList;	//报警云台行为对象列表

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif //_DISK_ALARM_PARAMV2_H
