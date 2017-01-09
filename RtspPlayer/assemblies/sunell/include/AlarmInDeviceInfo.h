#ifndef _ALARMINDEVICEINFO_H_
#define _ALARMINDEVICEINFO_H_

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

class SN_DLL_API AlarmInDeviceInfo
{
public:
	AlarmInDeviceInfo();

	~AlarmInDeviceInfo();

	//拷贝构造函数
	AlarmInDeviceInfo(const AlarmInDeviceInfo &p_objAlarmInDeviceInfo);
public:

	/************************************************************************
	**概述：
	*		设置网络视频设备报警输入ID号
    **输入：
	*	  p_nAlarmInputId ：报警输入ID号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*       
	************************************************************************/
	void setAlarmInId(int p_nAlarmInputId);

	/************************************************************************
	**概述：
	*		获取网络视频设备报警输入ID号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警输入ID号
	**功能：
	*       
	************************************************************************/
	int getAlarmInId() const;

	/****************************************************************************
	**概述：
	*		设置报警输入名称
    **输入：
	*		p_pszAlarmInName ：报警输入名称，字符串，最大长度为CONST_MAXLENGTH_ALARMINPUTNAME字节,
	*		结尾以‘\0’结束。
	**输出：
	*		无
	**返回值：
	*		true ： 成功
	* 		false：失败 
	**功能：
	*		若输入p_pszAlarmInputName长度<=CONST_MAXLENGTH_ALARMINPUTNAME，返回true，
	*		并保存到m_szAlarmInputName;
	*		若输入p_pszAlarmInputName为NULL或其长度>CONST_MAXLENGTH_ALARMINPUTNAME，
	*		返回false
	*****************************************************************************/
	bool setAlarmInName(const char* p_pszAlarmInName);

	/****************************************************************************
	**概述：
	*		获取报警输入名称
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警输入名称。 
	**功能：
	* 	
	*****************************************************************************/
	const char* getAlarmInName() const;

	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objAlarmInDeviceInfo：报警输入设备对象
	**输出：
	*		无
	**返回值：
	*		赋值后的报警输入设备对象 
	** 功能：
	*
	*****************************************************************************/
	AlarmInDeviceInfo& operator = (const AlarmInDeviceInfo &p_objAlarmInDeviceInfo);

private:
	
	int			m_nAlarmInputId;											//报警输入ID

	char		m_szAlarmInputName[CONST_MAXLENGTH_ALARMINPUTNAME + 1];		//报警输入名称
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_ALARMINDEVICE_H_


