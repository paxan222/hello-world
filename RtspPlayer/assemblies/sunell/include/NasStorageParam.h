#ifndef _NASSTORAGEPARAM_H_
#define _NASSTORAGEPARAM_H_

#include "DomainConst.h"
#include "SNPlatOS.h"
#include "const.h"

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

class SN_DLL_API NasStorageParam
{

public:
	NasStorageParam(void);
	~NasStorageParam(void);

	//拷贝构造函数
	NasStorageParam(const NasStorageParam& p_objNasStorageParam);

public:

	/************************************************************************
	**概述：
	*		设置NAS设备的IP地址
	**输入：
	*		p_pszNasIpAddress ：NAS设备的Ip地址，一个以‘\0’结尾的字符串，
	**输出：
	*		无
	**返回值：
	*		ture ：	设置成功
	*		false ：设备只是
	*功能：
	*		当p_pszNasIpAddress为空时，返回false；
	*		当设置NAS IP地址成功时，返回true；
	************************************************************************/
	bool setNASIpAddress(const char *p_pszNasIpAddress);

	/************************************************************************
	**概述：
	*		获取NAS设备的IP地址
	*输入：
	*		无
	*输出：
	*		无
	**返回值：
	*		IP地址
	**功能：
	*
	*************************************************************************/
	const char *getNASIpAddress() const;


	/************************************************************************
	**概述：
	*		设置访问NAS的用户名
	**输入：
	*		p_pszNasUserName：NAS设备用户名，一个以‘\0’结尾的字符串，
	**输出：
	*		无
	**返回值：
	*		ture ：	设置成功
	*		false： 设置失败
	*功能：
	*		当p_pszDDNSDomainName为空时，返回false
	*		当设置DDNS域名成功时，返回true
	************************************************************************/
	bool setNasUserName(const char *p_pszNasUserName);

	/************************************************************************
	*概述：
	*		获取访问NAS的用户名
	**输入：
	*		无
	**输出：
	*	无
	**返回值：
	*		NAS用户名
	**功能：
	*
	*************************************************************************/
	const char *getNASUserName() const;

	/************************************************************************
	**概述：
	*		设置NAS密码
	*输入：
	*		p_pszNASPassword：访问NAS设备密码，一个以‘\0’结尾的字符串，
	**输出：
	*		无
	**返回值：
	*		ture ：	设置成功
	*		false： 设置失败
	*功能：
	*		当p_pszDDNSPassword为空时，返回false
	*		当设置NAS密码成功时，返回true
	************************************************************************/
	bool setNASPassword(const char *p_pszNASPassword);

	/************************************************************************
	**概述：
	*		获取NAS密码
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		NAS的密码
	*功能：
	*
	*************************************************************************/
	const char *getNasPassword() const;

	/************************************************************************
	**概述：
	*		获取NAS路径
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		NAS的密码
	*功能：
	*
	*************************************************************************/
	const char *getNasPath() const;

	/************************************************************************
	**概述：
	*		设置NAS路径
	*输入：
	*		p_pszNASPath：NAS设备的路径，一个以‘\0’结尾的字符串，
	**输出：
	*		无
	**返回值：
	*		ture ：	设置成功
	*		false： 设置失败
	*功能：
	*		当p_pszNASPath为空时，返回false
	*		当设置NAS路径成功时，返回true
	************************************************************************/
	bool setNASPath(const char *p_pszNASPath);

	/************************************************************************
	*概述：
	*		赋值函数
	**输入：
	*		p_objNasStorageParam：DDNS信息
	**输出：
	*		无
	**返回值：
	*		DDNS信息
	**功能：
	*
	*************************************************************************/
	NasStorageParam& operator =(const NasStorageParam& p_objNasStorageParam);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objNasStorageParam：NasStorageParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个NasStorageParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const NasStorageParam& p_objNasStorageParam);

	/****************************************************************************
	**概述：
	*		复位，将成员变量恢复初始默认值
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		将成员变量恢复初始默认值
	*****************************************************************************/
	void reset();

private:

	char			m_szNasIpAddress[CONST_MAXLENGTH_IP + 1];		//NAS IP地址

	char			m_szNasUserName[CONST_MAXLENGTH_NAS_STORAGE_USERNAME + 1];	//NAS 用户名	

	char			m_szNasPassword[CONST_MAXLENGTH_NAS_STORAGE_PASSWORD + 1];		//NAS 密码

	char			m_szNasPath[CONST_MAXLENGTH_NAS_PATH + 1];	// NAS路径参数
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_NASSTORAGEPARAM_H_

