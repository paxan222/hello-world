#ifndef NETWORK_ALARM_PARAM_H
#define NETWORK_ALARM_PARAM_H

#include "NetworkAlarmEvent.h"
#include "SNPlatOS.h"
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

class SN_DLL_API NetworkAlarmParam
{
public:
	NetworkAlarmParam(void);
	~NetworkAlarmParam(void);

	//拷贝构造函数
	NetworkAlarmParam (const NetworkAlarmParam &p_objNetworkAlarmParam);
	
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
	*		设置网络报警事件
	**输入：
	*		p_objNetworkAlarmEventList：网络报警事件列表
	**输出：
	*		无
	**返回值：
	*		
	**功能：
	*      
	**************************************************************************/
	void setNetworkAlarmEvent(const vector<NetworkAlarmEvent>& p_objNetworkAlarmEventList);

	/************************************************************************
	**概述：
	*		获取网络报警事件列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		网络报警事件列表
	**功能：
	*      
	**************************************************************************/
	vector<NetworkAlarmEvent>* getNetworkAlarmEvent() const;

	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objNetworkAlarmParam：网络报警
	**输出：
	*		无
	**返回值：
	*		赋值后的网络报警
	**功能：
	*		
	*****************************************************************************/
	NetworkAlarmParam& operator = (const NetworkAlarmParam &p_objNetworkAlarmParam);

private:

	unsigned int					m_nInterval;					//上报间隔，单位为秒，最小间隔为10秒，最大为86400秒(1天)
	vector<NetworkAlarmEvent>		m_objNetworkAlarmEventList;		//设置网络报警事件列表

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif //NETWORK_ALARM_PARAM_H
