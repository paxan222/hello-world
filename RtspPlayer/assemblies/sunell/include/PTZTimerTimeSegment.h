#ifndef  _PTZTIMERTIMESEGMENT_
#define  _PTZTIMERTIMESEGMENT_

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

class SN_DLL_API PTZTimerTimeSegment
{
public:
	PTZTimerTimeSegment();
	~PTZTimerTimeSegment();
	
	//设置开始时间
	void setBeginTime(const unsigned long p_nBeginTime);
	const unsigned long getBeginTime() const;

	//设置结束时间
	void setEndTime(const unsigned long p_nEndTime);
	const unsigned long getEndTime() const;

	//设置云台命令
	bool setPTZOperation(const char* p_pszPTZOperation);
	const char* getPTZOperation() const;
	

	/***********************************************************************
	**概述：
	*		判等函数
	**输入：
	*		p_objPTZTimerTimeSegment：PTZTimerTimeSegment对象
	**输出：
	*		无
	**返回值：
	*		true：相等，false：不相等。
	*功能：
	************************************************************************/
	bool operator == (const PTZTimerTimeSegment &p_objPTZTimerTimeSegment) const;

	PTZTimerTimeSegment& operator=(const PTZTimerTimeSegment& p_objPTZTimerTimeSegment);
private:
	unsigned long	m_nBeginTime;									//开始时间，从00:00开始到当前时间的秒数，如01:30为5400
	unsigned long	m_nEndTime;										//结束时间，从00:00开始到当前时间的秒数，如01:30为5400
	char			m_szPTZOperation[CONST_MAXLENTH_PTZ_CMD + 1];	//云台操作命令
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/

#endif



