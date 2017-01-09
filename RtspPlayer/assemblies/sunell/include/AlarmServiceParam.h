#ifndef _ALARMSERVICEPARAM_H_
#define _ALARMSERVICEPARAM_H_

#include "DomainConst.h"
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

class SN_DLL_API AlarmServiceParam
{

public:
	AlarmServiceParam(void);
	~AlarmServiceParam(void);

	//拷贝构造函数
	AlarmServiceParam(const AlarmServiceParam& p_objAlarmServiceParam);

public:

	/************************************************************************
	** 概述：
	*		设置IP协议类型
	**输入：
	*		p_nIPProtoVer：IP协议类型
	**输出：
	*	  无
	**返回值：
	*	  无
	************************************************************************/
	void setIPProtoVer(const int p_nIPProtoVer);

	/************************************************************************
	**概述：
	*		获取IP协议类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		IP协议类型
	************************************************************************/
	const int getIPProtoVer()  const;

	/************************************************************************
	**概述：
	*		设置是否启用报警中心标志
	**输入：
	*		p_bFlag：是否启用报警中心标志
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	设置是否启用报警中心标志
	************************************************************************/
	void setAlarmCenterEnableFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取是否启用报警中心标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		是否启用报警中心标志
	**功能：
	*	获取是否启报警中心标志
	************************************************************************/
	const bool getAlarmCenterEnableFlag() const ;
	
	/************************************************************************
	**概述：
	*		设置 报警中心的地址
	**输入：
	*		p_pszAlarmCenterServerIP ：报警中心的IP地址
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	bool setAlarmCenterServerIP(const char * p_nAlarmCenterServerIP);

	/************************************************************************
	**概述：
	*		获取 报警中心的IP地址
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警中心的IP地址
	**功能：
	*
	************************************************************************/
	const char * getAlarmCenterServerIP() const;

	/************************************************************************
	**概述：
	*		设置报警中心的端口
	**输入：
	*		p_nAlarmCenterServerPort ：报警中心的端口
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setAlarmCenterServerPort(const unsigned short p_nAlarmCenterServerPort);

	/************************************************************************
	**概述：
	*		获取报警中心的端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警中心的端口
	**功能：
	*
	************************************************************************/
	const unsigned short getAlarmCenterServerPort() const;


	/************************************************************************
	**概述：
	*		设置是否启用报警邮件标志
	**输入：
	*		p_bFlag：是否启用报警邮件标志
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	设置是否启用报警邮件标志
	************************************************************************/
	void setAlarmEmailEnableFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取是否启用报警邮件标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		是否启用报警邮件标志
	**功能：
	*	获取是否启用报警邮件标志
	************************************************************************/
	const bool getAlarmEmailEnableFlag() const ;

	/************************************************************************
	**概述：
	*		设置报警邮件地址
	**输入：
	*		p_pszAlarmEmailAddress ：报警邮件地址
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	bool setAlarmEmailAddress(const char* p_pszAlarmEmailAddress);

	/************************************************************************
	**概述：
	*		获取报警邮件地址
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警邮件地址
	**功能：
	*
	************************************************************************/
	const char* getAlarmEmailAddress() const;


	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objAlarmServiceParam：报警服务信息
	**输出：
	*		无
	**返回值：
	*		报警服务信息
	*功能：
	*
	************************************************************************/
	AlarmServiceParam& operator =(const AlarmServiceParam& p_objAlarmServiceParam);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objAlarmServiceParam：AlarmServiceParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个AlarmServiceParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const AlarmServiceParam& p_objAlarmServiceParam);

private:
	bool				m_bAlarmCenterEnableFlag;										//是否启用报警中心(false：不启用， true：启用)
	char				m_szAlarmCenterServerIP[CONST_MAXLENGTH_IP + 1];				//报警中心IP地址
	unsigned short		m_nAlarmCenterServerPort;										//报警中心的端口

	bool				m_bAlarmEmailEnableFlag;										//是否启用报警邮件
	char				m_szAlarmEmailAddress[CONST_MAXLENTH_EMAIL_ADDRESS + 1];		//报警邮件地址

	int					m_nIPProtoVer;													//IP协议类型
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_ALARMSERVICEPARAM_H_
