#ifndef _REGISTERPARAM_H_
#define _REGISTERPARAM_H_

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

class SN_DLL_API RegisterParam
{

public:
	RegisterParam(void);
	~RegisterParam(void);

	//拷贝构造函数
	RegisterParam(const RegisterParam& p_objRegisterParam);

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
	*		设置是否启用注册标志
	**输入：
	*		p_bFlag：是否启用注册标志
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	设置是否启用注册标志
	************************************************************************/
	void setRegisterEnableFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取是否启用注册标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		是否启用注册标志
	**功能：
	*	获取是否启注册标志
	************************************************************************/
	const bool getRegisterEnableFlag() const ;


	/************************************************************************
	**概述：
	*		设置 注册服务器的地址
	**输入：
	*		p_pszRegisterSrvIP ：注册服务器的IP地址
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	bool setRegisterServerIP(const char * p_pszRegisterSrvIP);

	/************************************************************************
	**概述：
	*		获取 注册服务器的IP地址
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		注册服务器的IP地址
	**功能：
	*
	************************************************************************/
	const char * getRegisterServerIP() const;


	/************************************************************************
	**概述：
	*		设置注册服务器的端口
	**输入：
	*		p_nRegisterSrvPort ：注册服务器的端口
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setRegisterServerPort(const unsigned short p_nRegisterSrvPort);

	/************************************************************************
	**概述：
	*		获取注册服务器的端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		注册服务器的端口
	**功能：
	*
	************************************************************************/
	const unsigned short getRegisterServerPort() const;

	
	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objRegisterParam：注册参数信息
	**输出：
	*		无
	**返回值：
	*		注册参数信息
	*功能：
	*
	************************************************************************/
	RegisterParam& operator =(const RegisterParam& p_objRegisterParam);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objRegisterParam：RegisterParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个RegisterParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const RegisterParam& p_objRegisterParam);

private:

	bool				m_bRegisterEnableFlag;								//是否启用注册(false：不启用， true：启用)

	char				m_szRegisterSrvIP[CONST_MAXLENGTH_IP + 1];			//注册服务器IP地址

	unsigned short		m_nRegisterSrvPort;									//注册服务器的端口

	int					m_nIPProtoVer;										//IP协议类型
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REGISTERPARAM_H_
