#ifndef TIMEREBOOTPARAM_H
#define TIMEREBOOTPARAM_H
#include <vector>
#include "SNPlatOS.h"
#include "RebootTime.h"

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

using std::vector;

class SN_DLL_API TimeRebootParam
{
public:
	TimeRebootParam(void);
	~TimeRebootParam(void);

public:

	/*************************************************************
	*	概述：设置定时重启生效标志
	*	输入：
	*		p_bEnableTimeReboot				定时重启生效标志
	*	输出：
	*		无
	*	返回值：
	*		0		设置成功
	*		-1		设置失败
	**************************************************************/
	int setTimeRebootEnableFlag( bool p_bEnableTimeReboot);
	const bool getTimeRebootEnableFlag() const;

	/*************************************************************
	*	概述：设置定时重启时间参数信息
	*	输入：
	*		p_objRebootTimeList				重启时间列表
	*	输出：
	*		无
	*	返回值：
	*		0		设置成功
	*		-1		设置失败
	**************************************************************/
	int setRebootTimeList(const std::vector<RebootTime>& p_objRebootTimeList);
	const std::vector<RebootTime>& getRebootTimeList() const; 

	TimeRebootParam& operator = (const TimeRebootParam& p_other);
	bool operator == (const TimeRebootParam& p_other);
private:
	bool m_bEnableTimeReboot;
	std::vector<RebootTime> m_objRebootTimeList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/

#endif //TIMEREBOOTPARAM_H