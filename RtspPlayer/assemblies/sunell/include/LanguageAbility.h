#ifndef _LANGUAGE_ABILITY_
#define _LANGUAGE_ABILITY_

#include "LanguageType.h"
#include "SNPlatOS.h"
#include <vector>

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

class SN_DLL_API LanguageAbility
{

public:
	LanguageAbility(void);
	LanguageAbility(const LanguageAbility &p_objLanguageAbility);
	~LanguageAbility(void);

public:
	/************************************************************************
	**概述：设置摄像机语言类型列表
	**输入：
	*		摄像机语言类型列表
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setLanguageTypeList(const std::vector<LanguageType>& p_objLanguageTypeList);

	/************************************************************************
	**概述：获取摄像机语言类型列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		摄像机语言类型列表
	*************************************************************************/
	const std::vector<LanguageType>& getLanguageTypeList() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objLanguageAbility ：语言能力对象
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	LanguageAbility& operator = (const LanguageAbility &p_objLanguageAbility);

private:

	std::vector<LanguageType> m_objLanguageTypeList;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif	//_LANGUAGE_ABILITY_


