#ifndef _UPLOADPOLICY_H_
#define _UPLOADPOLICY_H_

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

class SN_DLL_API UploadPolicy
{

public:
	UploadPolicy(void);
	~UploadPolicy(void);

	//拷贝构造函数
	UploadPolicy(const UploadPolicy& p_objUploadPolicy);

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
	*		设置是否启用上传标志
	**输入：
	*		p_bFlag：是否启用上传标志
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	设置是否启用上传标志
	************************************************************************/
	void setUploadEnableFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取是否启用上传标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		是否启用上传标志
	**功能：
	*	获取是否启上传标志
	************************************************************************/
	const bool getUploadEnableFlag() const ;
	
	/************************************************************************
	**概述：
	*		设置 上传中心的地址
	**输入：
	*		p_pszUploadServerIP ：上传中心的IP地址
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	bool setUploadServerIP(const char * p_nUploadServerIP);

	/************************************************************************
	**概述：
	*		获取上传中心的IP地址
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		上传中心的IP地址
	**功能：
	*
	************************************************************************/
	const char * getUploadServerIP() const;

	/************************************************************************
	**概述：
	*		设置上传中心的端口
	**输入：
	*		p_nUplandServerPort ：上传中心的端口
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setUploadServerPort(const unsigned short p_nUploadServerPort);

	/************************************************************************
	**概述：
	*		获取上传中心的端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		上传中心的端口
	**功能：
	*
	************************************************************************/
	const unsigned short getUploadServerPort() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objUploadPolicy：上传策略信息
	**输出：
	*		无
	**返回值：
	*		
	*功能：
	*
	************************************************************************/
	UploadPolicy& operator =(const UploadPolicy& p_objUploadPolicy);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objUploadPolicy：UploadPolicy类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个UploadPolicy类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const UploadPolicy& p_objUploadPolicy);

private:
	bool				m_bUploadEnableFlag;						//是否启用上传(false：不启用， true：启用)
	char				m_szUploadServerIP[CONST_MAXLENGTH_IP + 1]; //上传服务器IP地址
	unsigned short		m_nUploadServerPort;						//上传服务器的端口
	int					m_nIPProtoVer;								//IP协议类型
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_UploadPolicy_H_
