#ifndef _BONJOUR_SERVICE_PARAM_H_
#define _BONJOUR_SERVICE_PARAM_H_

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

class SN_DLL_API BonjourServiceParam
{

public:
	BonjourServiceParam(void);
	~BonjourServiceParam(void);

	//拷贝构造函数
	BonjourServiceParam(const BonjourServiceParam& p_objBonjourServiceParam);

public:
	/************************************************************************
	**概述：
	*		设置是否启用Bonjour
	**输入：
	*		p_bFlag ：启用Bonjour标识
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setBonjourEnableFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取启用Bonjour标识
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		启用Bonjour标识
	**功能：
	*		
	**************************************************************************/
	const bool getBonjourEnableFlag() const;

	BonjourServiceParam &operator =(const BonjourServiceParam &p_objBonjourServiceParam);
	bool operator == (const BonjourServiceParam& p_objBonjourServiceParam);


private:
	bool		m_bBonjourEnableFlag;								//启用bonjour标识(true：启用，false：不启用)
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_PPPOEPARAM_H_

