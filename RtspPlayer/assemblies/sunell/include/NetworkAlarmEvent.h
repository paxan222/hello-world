#ifndef _NETWORK_ALARM_EVENT_H
#define _NETWORK_ALARM_EVENT_H

#include "AlarmOutAction.h"
#include "AlarmPTZAction.h"
#include "SNPlatOS.h"
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

class SN_DLL_API NetworkAlarmEvent
{
public:
	NetworkAlarmEvent(void);
	~NetworkAlarmEvent(void);

	//拷贝构造函数
	NetworkAlarmEvent (const NetworkAlarmEvent &p_objNetworkAlarmEvent);

	/************************************************************************
	**概述：
	*		设置设备网卡ID号
	**输入：
	*		p_nNetworkCardId：设备网卡ID号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setNetworkCardId(int p_nNetworkCardId);

	/************************************************************************
	**概述：
	*		获取设备网卡ID号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		设备网卡ID号
	**功能：
	*
	************************************************************************/
	int getNetworkCardId() const;

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
	NetworkAlarmEvent& operator = (const NetworkAlarmEvent &p_objNetworkAlarmEvent);

private:

	int								m_nNetworkCardId;			//报警网卡ID号
	bool							m_bAlarmEnableFlag;			//是否启动报警(false：不启动， true：启动)
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

#endif //_NETWORK_ALARM_EVENT_H
