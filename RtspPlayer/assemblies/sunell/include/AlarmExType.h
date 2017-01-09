#ifndef _ALARMEXTYPE_H_
#define _ALARMEXTYPE_H_

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

class SN_DLL_API AlarmExType
{
public:
	AlarmExType(void);
	~AlarmExType(void);

	AlarmExType(const AlarmExType& p_objAlarmType);
public:
		
	/************************************************************************
	**概述：
	*		设置报警主类型
	**输入：
	*		p_nMajorType：报警主类型
	**输出：
	*		无
	**返回值：
	*		无
	*功能：
	*	
	************************************************************************/
	void setMajorType(const int p_nMajorType);

	
	/************************************************************************
	**概述：
	*		获取报警主类型
	*输入：
	*		无
	*输出：
	*		无
	**返回值：
	*		报警主类型
	**功能：
	*
	*************************************************************************/
	const int getMajorType() const;
	

	/************************************************************************
	**概述：
	*		设置报警子类型
	**输入：
	*		p_nMinorType：报警子类型
	**输出：
	*		无
	**返回值：
	*		无
	*功能：
	*	
	************************************************************************/
	void setMinorType(const int p_nMinorType);


	/************************************************************************
	**概述：
	*		获取报警子类型
	*输入：
	*		无
	*输出：
	*		无
	**返回值：
	*		报警子类型
	**功能：
	*
	*************************************************************************/
	const int getMinorType() const;

		
	/************************************************************************
	**概述：
	*		设置报警类型名称
	**输入：
	*		p_pszAlarmExTypeName：报警类型名称，一个以‘\0’结尾的字符串，
	**输出：
	*		无
	**返回值：
	*		ture ：	设置成功
	*		false ：设备只是
	*功能：
	*		当p_pszAlarmExTypeName为空时，返回false；
	*		当设置报警类型名称成功时，返回true；
	************************************************************************/
	bool setAlarmExTypeName(const char* p_pszAlarmExTypeName);
	

	/************************************************************************
	**概述：
	*		获取报警类型名称
	*输入：
	*		无
	*输出：
	*		无
	**返回值：
	*		报警类型名称
	**功能：
	*
	*************************************************************************/
	const char* getAlarmExTypeName() const;


	/************************************************************************
	*概述：
	*		赋值函数
	**输入：
	*		p_objAlarmExType：报警类型信息
	**输出：
	*		无
	**返回值：
	*		报警类型信息
	**功能：
	*
	*************************************************************************/
	AlarmExType& operator =(const AlarmExType& p_objAlarmExType);



	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objAlarmExType：AlarmExType类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个AlarmExType类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const AlarmExType& p_objAlarmExType);

private:
	int			m_nMajorType;													//报警主类型
	int			m_nMinorType;													//报警子类型
	char		m_szAlarmExTypeName[CONST_MAXLENGTH_ALARM_TYPE_NAME + 1];		//报警类型名称


}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_ALARMEXTYPE_H_
