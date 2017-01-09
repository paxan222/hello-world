#ifndef _TRACE_ABILITY_PARAM_V2_H
#define _TRACE_ABILITY_PARAM_V2_H

#include "SNPlatOS.h"
#include "IPTZModuleAbilityParam.h"

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

/***************************************************************************//**
 @brief 轨迹能力设置参数实体类
******************************************************************************/

class SN_DLL_API TraceAbilityParamV2 : public IPTZModuleAbilityParam
{
public:
	TraceAbilityParamV2(void);
	~TraceAbilityParamV2(void);
	//获取轨迹最大秒数
	const int getTraceMaxSecond() const {return m_nTraceMaxSecond;}
	//设置轨迹最大秒数
	void setTraceMaxSecond(const int &p_nSecond);
	//获取轨迹最大命令条数
	const int getTraceMaxCmdNum() const {return m_nTraceMaxCmdNum;}
	//设置轨迹最大命令条数
 	void setTraceMaxCmdNum(const int &p_nNum);
// 	//设置轨迹的起始ID
// 	void setTraceBeginID(const int p_nTraceBeginID);
// 	//设置轨迹的结束ID
// 	const int getTraceBeginID()const;
// 	//设置轨迹的起始ID
// 	void setTraceEndID(const int p_nTraceEndID);
// 	//设置轨迹的结束ID
// 	const int getTraceEndID()const;
	//赋值函数
	TraceAbilityParamV2& operator=(const TraceAbilityParamV2 &p_objTraceAbilityParam); 

	void setIDRange(const int & p_nIDRangeFrom , const int & p_nIDRangeTo);

	bool getIDRange(int & p_nIDRangeFrom , int & p_nIDRangeTo) const;

private:
	int m_nTraceMaxSecond;					//轨迹最大秒数
	int m_nTraceMaxCmdNum;				//轨迹最大命令条数
	//int m_nTraceBeginID;				//轨迹的起始点ID
	//int m_nTraceEndID;					//轨迹的结束点ID

	int		m_nIDRangeFrom;				//The min ID value 
	int		m_nIDRangeTo;					//The max ID value
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/

#endif
