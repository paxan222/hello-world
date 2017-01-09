#ifndef _SAVEPOLICY_H_
#define _SAVEPOLICY_H_

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

class SN_DLL_API SavePolicy
{
public:
	SavePolicy();

	~SavePolicy();

	//赋值函数
	SavePolicy(const SavePolicy &p_objSavePolicy);

public:
	/***********************************************************************
	**概述：
	*		设置录像文件的保存天数
	**输入：
	*		p_nDelay：保存天数
	**输出：
	*		
	**返回值：
	*		无
	**功能：
	*		设置录像文件的保存天数
	************************************************************************/
	void setRecordSaveDays(const int p_nRecordSaveDays);

	/***********************************************************************
	**概述：
	*		获取录像文件的保存天数
	**输入：
	*		
	**输出：
	*		
	**返回值：
	*		录像文件的保存天数
	**功能：
	*		获取录像文件的保存天数
	************************************************************************/
	const int getRecordSaveDays() const;

	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objSavePolicy：存储策略对象
	**输出：
	*		无
	**返回值：
	*		赋值后的存储策略对象
	**功能：
	*		
	*****************************************************************************/
	SavePolicy & operator=(const SavePolicy &p_objSavePolicy);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objSavePolicy：SavePolicy类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个SavePolicy类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator==(const SavePolicy &p_objSavePolicy);

private:
	int				m_nRecordSaveDays;				//存储天数

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_LOCALSavePolicy_H_
