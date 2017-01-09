#ifndef AVSTREAMATTRIBUTEABILITY_H_
#define AVSTREAMATTRIBUTEABILITY_H_
#include "SNPlatOS.h"
#include "DomainConst.h"
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

class SN_DLL_API AVStreamAttributeAbility
{
public:
	AVStreamAttributeAbility(void);
	~AVStreamAttributeAbility(void);
	
public:
	/************************************************************************
	*	概述：设置流类型
	*	输入：
	*		p_nStreamMode：	码流类型
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setStreamMode(const int p_nStreamMode);
	/************************************************************************
	*	概述：获取流类型
	*	输入：
	*		无：
	*	输出：
	*		流类型
	*	返回值：
	*		无
	*************************************************************************/
	const int getStreamMode()const;

	/************************************************************************
	*	概述：设置支持的P帧取帧间隔列表
	*	输入：
	*		p_vecFrameSkipIntervalList：	P帧取帧间隔列表
	*	输出：
	*		无
	*	返回值：
	*		无
	*	说明：
	*		只有支持伴随流的原始流才能设置此项属性，其他流类型设置此属性将返回失败
	*************************************************************************/
	void setFrameSkipIntervalList(const std::vector<int> &p_vecFrameSkipIntervalList);
	/************************************************************************
	*	概述：获取支持的P帧取帧间隔列表
	*	输入：
	*		无：	
	*	输出：
	*		p_vecFrameSkipIntervalList  P帧取帧间隔列表
	*	返回值：
	*		无
	*	说明：
	*		只有支持伴随流的原始流才能获取此项属性，其他流类型获取此属性将返回失败
	*************************************************************************/
	void getFrameSkipIntervalList(std::vector<int> &p_vecFrameSkipIntervalList);

	/************************************************************************
	*	概述：设置支持的可映射的伴随流列表
	*	输入：
	*		p_vecSVCStreamIDList：	伴随流列表
	*	输出：
	*		无
	*	返回值：
	*		无
	*	说明：
	*		只有流类型为伴随流才能设置此项属性，其他流类型设置此属性将返回失败
	*************************************************************************/
	void setSVCStreamIDList(const std::vector<int> &p_vecSVCStreamIDList);
	/************************************************************************
	*	概述：获取支持的可映射的伴随流列表
	*	输入：
	*		无：	
	*	输出：
	*		p_vecSVCStreamIDList  伴随流列表
	*	返回值：
	*		无
	*	说明：
	*		只有流类型为伴随流才能获取此项属性，其他流类型获取此属性将返回失败
	*************************************************************************/
	void getSVCStreamIDList(std::vector<int> &p_vecSVCStreamIDList);
private:
	int m_nStreamMode;							//流类型
	std::vector<int> m_vecFrameSkipIntervalList;   //支持的伴随流P帧取帧间隔列表
	std::vector<int> m_vecSVCStreamIDList;		//支持的伴随流ID列表
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/

#endif


