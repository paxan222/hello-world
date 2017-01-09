#ifndef _PPPOEPARAM_H_
#define _PPPOEPARAM_H_

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

class SN_DLL_API PPPoEParam
{

public:
	PPPoEParam(void);
	~PPPoEParam(void);

	//拷贝构造函数
	PPPoEParam(const PPPoEParam& p_objPPPoEParam);

public:
	/************************************************************************
	**概述：
	*		设置是否启用PPPoE
	**输入：
	*		p_bFlag ：启用PPPoE标识
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setPPPoEEnableFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取启用PPPoE标识
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		启用PPPoE标识
	**功能：
	*		获取启用PPPoE的状态
	**************************************************************************/
	const bool getPPPoEEnableFlag() const;


	/************************************************************************
	**概述：
	*		设置 PPPoE用户名
	**输入：
	*		p_pszPPPoEUserName ：PPPoE用户名，一个以‘\0’结尾的字符串，
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		若p_pszPPPoEUserName为空时，返回false
	*		若字符串的长度大于 CONST_MAXLENGTH_PPPOE_USERNAME 时，返回false
	*		若设置PPPoE用户名成功，返回true
	************************************************************************/
	bool setPPPoEUserName(const char *p_pszPPPoEUserName);

	/************************************************************************
	**概述：
	*		获取PPPoE用户名
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		PPPoE用户名
	**功能：
	*		
	**************************************************************************/
	const char *getPPPoEUserName() const;


	/************************************************************************
	**概述：
	*		设置PPPoE密码
	**输入：
	*		p_pszPPPoEPassword ：PPPoE密码，一个以‘\0’结尾的字符串，
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		若p_pszPPPoEPassword为空时，返回false
	**		若字符串的长度大于 CONST_MAXLENGTH_PPPOE_PASSWORD 时，返回false
	**		若设置密码成功，返回true
	************************************************************************/
	bool setPPPoEPassword(const char *p_pszPPPoEPassword);

	/************************************************************************
	**概述：
	*		获取PPPoE密码
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		PPPoE密码
	**功能：
	*
	**************************************************************************/
	const char *getPPPoEPassword() const;


	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objPPPoEParam：设备网络信息
	**输出：
	*		无
	**返回值：
	*		PPPoE信息
	**功能：
	*************************************************************************/
	PPPoEParam &operator =(const PPPoEParam &p_objPPPoEParam);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objPPPoEParam：PPPoEParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个PPPoEParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const PPPoEParam& p_objPPPoEParam);


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
	bool		m_bPPPoEEnableFlag;											//启用PPPoE标识(true：启用，false：不启用)

	char		m_szPPPoEUserName[CONST_MAXLENGTH_PPPOE_USERNAME + 1];		//PPPoE用户名

	char		m_szPPPoEPassword[CONST_MAXLENGTH_PPPOE_PASSWORD + 1];		//PPPoE密码
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_PPPOEPARAM_H_

