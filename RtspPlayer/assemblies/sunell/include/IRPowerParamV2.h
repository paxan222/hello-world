#ifndef IR_POWER_PARAM_V2_h__
#define IR_POWER_PARAM_V2_h__

#include <vector>
#include "SNPlatOS.h"
#include "IRPowerItem.h"

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
@brief 红外灯功率的实体类
******************************************************************************/

class SN_DLL_API IRPowerParamV2
{
public:
	IRPowerParamV2();
	~IRPowerParamV2();

	// 获取IR POWER
	const std::vector<IRPowerItem>& getIrPower() const { return m_objIrPower; };

	// 设置IR POWER
	void setIrPower(const std::vector<IRPowerItem>& p_objIrPower);

private:
	std::vector<IRPowerItem> m_objIrPower;		// IR POWER的设置及
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/


#endif // IR_POWER_PARAM_V2_h__