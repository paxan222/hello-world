#ifndef _ALARMOUTACTION_H_
#define _ALARMOUTACTION_H_

#include "DomainConst.h"
#include "SNPlatOS.h"

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

class SN_DLL_API AlarmOutAction
{
public:
	enum
	{
		ALARMOUTFLAG_START		= 1,		//报警有效标志位，开始报警
		ALARMOUTFLAG_STOP		= 0			//报警无效标志位，停止报警
	};
public:

	AlarmOutAction();

	~AlarmOutAction();

	//拷贝构造函数
	AlarmOutAction(const AlarmOutAction& p_objAlarmOutAction);

public:	
	/***********************************************************************
	**概述：
	*		设置网络视频设备的设备ID
    **输入：
	*		p_pszDeviceId ：字符串，最大长度为CONST_MAXLENGTH_DEVICEID字节,
	*		结尾以‘\0’结束。
	**输出：
	*		无
	**返回值：
	*		true ： 成功
	* 		false：失败 
	**功能：
	*		若输入p_pszDeviceId长度<=CONST_MAXLENGTH_DEVICEID，返回true，
	*		并保存到m_szDeviceId;
	*		若输入p_pszDeviceId为NULL或其长度>CONST_MAXLENGTH_DEVICEID，返回false
	*************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);


	/************************************************************************
	**概述：
	*		获取DVR设备的设备ID
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		返回保存DVR设备ID的m_szDeviceId字符串指针。 
	**功能：
	* 		
	*************************************************************************/
	const char* getDeviceId() const;


	/************************************************************************
	**概述：
	*		设置报警输出ID号
	**输入：
	*		p_nAlarmOutId ：报警输出ID号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	* 	  
	************************************************************************/
	void setAlarmOutId(const int p_nAlarmOutId);

	/************************************************************************
	**概述：
	*		获取报警输出ID号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警输出端口的ID号
	**功能：
	* 	  
	************************************************************************/
	const int getAlarmOutId() const;


	/************************************************************************
	**概述：
	*		设置报警标志
	**输入：
	*		p_nAlarmFlag ：要设置的报警标志位
	*		ALARMFLAG_START		开始报警
	*		ALARMFLAG_STOP		停止报警
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*
	************************************************************************/
	void setAlarmOutFlag(const int p_nAlarmFlag);

	/************************************************************************
	*概述：
	*		获取报警标志
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		报警标志
	*功能：       
	*
	*************************************************************************/
	const int getAlarmOutFlag() const;


	/************************************************************************
	**概述：
	*		设置报警事件类型
	**输入：
	*		p_nEventTypeId ：报警事件类型
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	* 
	************************************************************************/
	void setEventTypeId(const int p_nEventTypeId);

	/************************************************************************
	**概述：
	*		获取报警事件类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警事件类型
	**功能：
	* 
	************************************************************************/
	const int getEventTypeId() const;


	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objAlarmOutAction：报警输出行为对象
	**输出：
	*		无
	**返回值：
	*		赋值后的报警输出行为对象
	**功能：
	*		
	*****************************************************************************/
	AlarmOutAction& operator = (const AlarmOutAction& p_objAlarmOutAction);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objAlarmOutAction：AlarmOutAction类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true ：相等
	*		false：不相等
	**功能：
	*		两个AlarmOutAction类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const AlarmOutAction& p_objAlarmOutAction) const;

	bool operator < (const AlarmOutAction& p_objAlarmOutAction) const;

private:
	
	char	m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];	//设备id
	
	int		m_nAlarmOutId;								//报警输出端口的ID号	
	
	int		m_nAlarmOutFlag;							//报警输出标志
	
	int		m_nEventTypeId;								//报警事件类型


}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_ALARMOUTACTION_H_

