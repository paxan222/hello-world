#ifndef _PTZKEYBOARDPARAM_H_
#define _PTZKEYBOARDPARAM_H_

#include "ExternInterface.h"
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

class SN_DLL_API PTZKeyboardParam
{
public:
	PTZKeyboardParam();
	~PTZKeyboardParam();

public:
	/************************************************************************
	**概述：
	*		设置是否启用云台键盘服务
	**输入：
	*		p_bEnableFlag：启用云台键盘服务的状态
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setEnableFlag(const bool p_bEnableFlag);

	/************************************************************************
	**概述：
	*		获取是否启用云台键盘服务标识
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		是否启用云台键盘服务标识
	**功能：
	*		
	*************************************************************************/
	const bool getEnableFlag() const;

	void setExternInterface(const ExternInterface & p_objExternInterface);
	const ExternInterface & getExternInterface() const;
private:
	bool m_bEnableFlag; //是否启动云台键盘(true：启动，false：不启动)
	ExternInterface m_objExternInterface;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_PTZKeyboardParam_H_
