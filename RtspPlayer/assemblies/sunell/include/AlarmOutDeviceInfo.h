#ifndef _ALARMOUTDEVICEINFO_H_
#define _ALARMOUTDEVICEINFO_H_

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

class SN_DLL_API AlarmOutDeviceInfo
{
public:
	AlarmOutDeviceInfo();

	~AlarmOutDeviceInfo();

public:
	/************************************************************************
	概述：设置DVR设备报警输出ID号
    输入：
		  p_nAlarmOutId ：DVR设备报警输出ID号
	输出：
		无
	返回值：
		无
	功能：
	      设置DVR设备报警输出ID号
	************************************************************************/
	void setAlarmOutId(int p_nAlarmOutId);
	
	/************************************************************************
	概述：获取DVR设备报警输出ID号
	输入：
		无
	输出：
		无
	返回值：
		DVR设备报警输出ID号
	功能：
	      获取DVR设备报警输出ID号
	************************************************************************/
	int getAlarmOutId() const;
	
	/****************************************************************************
	概述：设置DVR设备报警输出名字
    输入：
		p_pszAlarmOutName ：字符串，最大长度为CONST_MAXLENGTH_ALARMOUTPUTNAME字节,
		结尾以‘\0’结束。
	输出：
		无
	返回值：
		true： 成功
		false：失败 
	功能：
		若输入p_pszAlarmOutName长度<=CONST_MAXLENGTH_ALARMOUTPUTNAME，返回true，
		并保存到m_szAlarmOutName;
		若输入p_pszAlarmOutName为NULL或其长度>CONST_MAXLENGTH_ALARMOUTPUTNAME，
		返回false
	*****************************************************************************/
	bool setAlarmOutName(const char* p_pszAlarmOutName);
	
	/****************************************************************************
	概述：获取DVR设备报警输出名字
    输入：
		无
	输出：
		无
	返回值：
		返回保存DVR设备报警输出名字的m_szAlarmOutName字符串指针。 
	功能：
		获取保存有DVR设备报警输出名字的字符串指针
	*****************************************************************************/
	const char* getAlarmOutName() const;


	AlarmOutDeviceInfo(const AlarmOutDeviceInfo &p_objAlarmOutDeviceInfo);

	AlarmOutDeviceInfo& operator = (const AlarmOutDeviceInfo& p_objAlarmOutDeviceInfo);

private:
	
	int m_nAlarmOutId;

	char m_szAlarmOutName[CONST_MAXLENGTH_ALARMOUTNAME + 1];
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_ALARMOUTDEVICE_H_


