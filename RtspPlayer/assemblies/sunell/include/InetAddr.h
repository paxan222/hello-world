#ifndef _INETADDR_H_ 
#define _INETADDR_H_

#include "SNPlatOS.h"

#if (defined(WIN32) || defined(_WIN32_WCE))
#ifdef SN_DLL_EXPORTS
	#define INETADDR_API __declspec(dllexport)
#else
	#define INETADDR_API __declspec(dllimport)
#endif
#else
	#define INETADDR_API
#endif

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

namespace SNSocketConst
{
	const int MAXLENGTH_IP = 48;	//IP地址最大长度
};
class INETADDR_API InetAddr
{
public:
	
	InetAddr();

	~InetAddr();

	InetAddr (const InetAddr& p_objInetAddr);

public:

	/************************************************************************
	**概述：
	*		检验IP的合法性
    **输入：
	*	  p_pszIP：IP地址,格式如：xxx.xxx.xxx.xxx,xxx为0-255数字。
	**输出：
	*		无
	**返回值：
	*	  true： 成功
	*	  false：失败 
	**功能：
	*     若p_pszIP为合法的IP，返回true;
	*	  若p_pszIP不合法的IP，返回false
	************************************************************************/
	static bool checkIP(const char * p_pszIP);

	/************************************************************************
	**概述：
	*		设置IP地址
    **输入：
	*	   p_pszIP：IP地址,格式如：xxx.xxx.xxx.xxx。
	**输出：
	*		无
	**返回值：
	*	  true： 成功
	*	  false：失败 
	**功能：
	*	  若p_pszIP不合法的IP，返回false
	*	  若转换p_pszIP为网络字节顺序不成功， 返回false
	*	  若p_pszIP为合法的IP，返回true，并且存储p_pszIP为主机字节顺序的整形值。
    ************************************************************************/
	bool setIP(const char* p_pszIP);

	/************************************************************************
	**概述：
	*		获取点分制表示的IP地址
	**输入：
	*	   无
	**输出：
	*		无
	**返回值：
	*		格式如：xxx.xxx.xxx.xxx的点分十进制IP地址字符串
	*功能：
	*		
	************************************************************************/
	const char* getIP() const;


	/************************************************************************
	** 概述：
	*		设置端口号
    **输入：
	*		端口号
	**输出：
	*	  无
	**返回值：
	*	  true： 成功
	*	  false：失败 
	**功能：
	*	  若设置的端口为不合法的端口，返回false
	*	  若设置的端口为合法的端口，返回true，并且存储该端口。
    ************************************************************************/
	bool		setPORT(const unsigned short p_nPORT);
	
	/************************************************************************
	**概述：
	*		获取端口号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		主机字节顺序端口号
	**功能：
	*		得到主机字节顺序的端口。
    ************************************************************************/
	const unsigned short getPORT()  const;

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
	*		比较两个地址对象是否相等
    **输入：
	*		InetAddr类对象
	*输出：
	*	  无
	**返回值：
	*	  true：两个地址相等
	*	  false：两个地址不相等
	**功能：
	*	  若两个地址中的IP和port均相等，则返回true
	*	  若两个地址中的IP和port有一项或多项不相等，返回false。
    ************************************************************************/
	bool operator ==(InetAddr &) ;


	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		InetAddr类对象
	*输出：
	*	  无
	**返回值：
	*	  InetAddr地址对象
	**功能：
	*	  
	************************************************************************/
	InetAddr & operator =(const InetAddr &) ;
	
private:
	
	char			m_szHostIP[SNSocketConst::MAXLENGTH_IP + 1];		//IP地址（主机字节顺序）

	unsigned short	m_nPORT;				//端口号

	int				m_nIPProtoVer;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_INETADDR_H_
