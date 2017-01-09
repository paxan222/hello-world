#ifndef _ALARMPARAM_H_
#define _ALARMPARAM_H_


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

class SN_DLL_API AlarmParam
{
public:
	AlarmParam();
	~AlarmParam();
	AlarmParam (const AlarmParam &p_objAlarmParam);

public:
	/************************************************************************
	**概述：
	*		设置报警间隔
	**输入：
	*		  p_nAlarmInterval ：报警间隔，以秒为单位
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*      
	************************************************************************/
	void setAlarmInterval(const int p_nAlarmInterval);

	/************************************************************************
	**概述：
	*		获取报警间隔
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警间隔
	**功能：
	*       
	**************************************************************************/
	const int getAlarmInterval() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objAlarmParam ：报警数据对象
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	AlarmParam& operator = (const AlarmParam &p_objAlarmParam);

private:

	int		m_nAlarmInterval;											//报警间隔
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_ALARMPARAM_H_

