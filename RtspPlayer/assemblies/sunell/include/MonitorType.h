#ifndef _MONITORTYPE_
#define _MONITORTYPE_

#include "SNPlatOS.h"
#include "DomainConst.h"

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

class SN_DLL_API MonitorType
{
public:
	MonitorType(void);
	~MonitorType(void);

public:
	/************************************************************************
	*	概述：设置类型编号
	*	输入：
	*		p_TypeId	类型编号
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setTypeId(int p_TypeId);

	/************************************************************************
	*	概述：获取类型编号
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		类型编号
	*************************************************************************/
	int getTypeId() const;

	/************************************************************************
	*	概述：设置类型名称
	*	输入：
	*		p_pszTypeName	类型名称
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	bool setTypeName(const char* p_pszTypeName);

	/************************************************************************
	*	概述：获取类型名称
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		类型名称
	*************************************************************************/
	const char* getTypeName() const;

	MonitorType& operator = (const MonitorType& p_objMonitorType);
private:
	int		m_nTypeId;
	char	m_szTypeName[CONST_MAXLENTH_MONITOR_TYPE_NAME + 1];	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_MONITORTYPE_
