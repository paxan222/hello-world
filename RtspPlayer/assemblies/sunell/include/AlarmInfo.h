#ifndef _ALARMINFO_H_
#define _ALARMINFO_H_

#include "AlarmData.h"
#include "const.h"
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

class SN_DLL_API AlarmInfo
{
public:
	AlarmInfo(void);
	~AlarmInfo(void);

	AlarmInfo (const AlarmInfo &p_objAlarmInfo);

public:
	/****************************************************************************
	**概述：
	*		设置网络视频设备的唯一标识符
	**输入：
	*		p_pszDeviceId ：网络视频设备的唯一标识符，字符串，最大长度为CONST_MAXLENGTH_DEVICEID字节,
	*						结尾以‘\0’结束。
	**输出：
	*		无
	**返回值：
	*		true： 成功
	*		false：失败 
	**功能：
	*		若输入p_pszDeviceId长度<=CONST_MAXLENGTH_DEVICEID，返回true.
	*		若输入p_pszDeviceId为NULL或其长度>CONST_MAXLENGTH_DEVICEID，返回false.
	*****************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/****************************************************************************
	**概述：
	*		获取网络设备的唯一标识符
	**输入：
	*		无
	**输出：
	*		无
	*返回值：
	*		网络设备的唯一标识符，字符串类型 
	**功能：
	*		
	*****************************************************************************/
	const char* getDeviceId() const;

	/************************************************************************
	**概述：
	*		设置网络视频设备的设备类型
	**输入：
	*		p_nDeviceType ：网络视频设备的设备类型
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setDeviceType(const int p_nDeviceType);

	/************************************************************************
	**概述：
	*		获取网络视频设备的设备类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		网络视频设备的设备类型
	**功能：
	*
	************************************************************************/
	const int getDeviceType() const;

	/************************************************************************
	**概述：
	*		设置网络视频设备的主机IP地址
	**输入：
	*		p_pszDeviceIp ：网络视频设备的主机IP地址
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	bool setDeviceIp(const char * p_pszDeviceIp);

	/************************************************************************
	**概述：
	*		获取网络视频设备的主机IP地址
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		网络视频设备的主机IP地址
	**功能：
	*
	************************************************************************/
	const char * getDeviceIp() const;

	/************************************************************************
	**概述：
	*		设置报警数据
	**输入：
	*		p_objAlarmData ：报警数据
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setAlarmData(const AlarmData& p_objAlarmData);
	
	/************************************************************************
	**概述：
	*		获取报警数据
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警数据
	**功能：
	*
	************************************************************************/
	const AlarmData& getAlarmData() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objAlarmInfo ：报警信息对象
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	AlarmInfo& operator = (const AlarmInfo &p_objAlarmInfo);

private:
	char			m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//设备id

	int				m_nDeviceType;											//设备类型

	char			m_szDeviceIp[CONST_MAXLENGTH_IP + 1];						//设备IP地址
	
	AlarmData		m_objAlarmData;											//报警数据
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_ALARMINFO_H_
