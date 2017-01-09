#ifndef _PTZPROTOCOL_H_
#define _PTZPROTOCOL_H_

#include "DomainConst.h"

#include <string.h>
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

class SN_DLL_API PTZProtocol
{
public:
	enum 
	{
		PROTOCOL_PELCO_D		= 0,	//PELCO_D协议
		PROTOCOL_PELCO_P		= 1,	//PELCO_P协议
		PROTOCOL_SN				= 2,	//SN自定义协议
		PROTOCOL_PELCO_D_YA		= 3		//亚安PELCO_D协议
	};

public:
	PTZProtocol();
	~PTZProtocol();

	PTZProtocol(const PTZProtocol& p_objPTZProtocol);

public:
	/************************************************************************
	**概述：
	*		设置云台协议的ID号
    **输入：
	*		p_nProtocolId ：云台协议的ID号
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setProtocolId(const int p_nProtocolId);

	/************************************************************************
	**概述：
	*		获取云台协议的ID号
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		云台协议的ID号
	**功能：
	*    
	************************************************************************/
	const int getProtocolId() const;

	/************************************************************************
	**概述：
	*		设置云台协议的名字
    **输入：
	*	  p_pszProtocolName ：云台协议的名字，字符串，最大长度
	*						  为CONST_MAXLENTH_PTZ_PROTOCOL_NAME字节,结尾以‘\0’结束。 
	**输出：
	*		无
	**返回值：
	*		true ：成功
	*		false：失败
	*功能：
	*    若输入p_pszProtocolName长度<=CONST_MAXLENTH_PTZ_PROTOCOL_NAME，返回true，并保存到m_szProtocolName;
	*	 若输入p_pszProtocolName为null或者其长度>CONST_MAXLENTH_PTZ_PROTOCOL_NAME，返回false
	************************************************************************/
	bool setProtocolName(const char* p_pszProtocolName);

	/************************************************************************
	**概述：
	*		获取云台协议的名字
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		云台协议的名字的地址
	**功能：
	*		
	************************************************************************/
	const char* getProtocolName() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objPTZProtocol：云台协议
	**输出：
	*		无
	**返回值：
	*		云台协议
	**功能：
	************************************************************************/
	PTZProtocol& operator =(const PTZProtocol& p_objPTZProtocol);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objPTZProtocol：PTZProtocol类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个PTZProtocol类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const PTZProtocol& p_objPTZProtocol);

private:
	
	int		m_nProtocolId;													//云台协议的ID号
	
	char	m_szProtocolName[CONST_MAXLENTH_PTZ_PROTOCOL_NAME + 1];			//云台协议的名字
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //__PTZPROTOCOL_H__

