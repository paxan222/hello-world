#ifndef MAGNIFY_PT_SPEED_PARAM_H
#define MAGNIFY_PT_SPEED_PARAM_H

#include <vector>
#include "SNPlatOS.h"
#include "PTZStageToSpeedParam.h"

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

class SN_DLL_API MagnifyPTSpeedParam
{
public:
	MagnifyPTSpeedParam();
	~MagnifyPTSpeedParam();

	// 设置倍速
	void setMagnify(const int p_nMagnify);
	//获取倍速
	const int getMagnify() const;
	//设置档位速度对照表
	void setPTZStageToSpeedParamList(const std::vector<PTZStageToSpeedParam> p_objPTZStageToSpeedParamList);
	//获得档位速度对照表
	const std::vector<PTZStageToSpeedParam> &getPTZStageToSpeedParamList() const ;

	MagnifyPTSpeedParam& operator =(const MagnifyPTSpeedParam& p_objMagnifyPTSpeedParam);

private:
	int m_nMagnify;	//倍速
	std::vector<PTZStageToSpeedParam> m_objPTZStageToSpeedParamList;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/

#endif