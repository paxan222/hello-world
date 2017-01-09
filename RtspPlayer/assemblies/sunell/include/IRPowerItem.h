#ifndef IR_POWER_ITEM_h__
#define IR_POWER_ITEM_h__


#include <vector>
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


/***************************************************************************//**
 @brief 红外灯功率一项的实体类
******************************************************************************/

class SN_DLL_API IRPowerItem
{
public:
	IRPowerItem();
	~IRPowerItem();

	// 获取zoom上限
	const int getZoomUp() const { return m_nZoomUp; }

	// 设置zoom上限
	void setZoomUp(const int p_nZoomUp);

	// 获取远灯功率
	const int getFarIrPower() const { return m_nFarIrPower; }

	// 设置远灯功率
	void setFarPower(const int p_nPower);

	// 获取中灯功率
	const int getMidIrPower() const { return m_nMidIrPower; }

	// 设置中灯功率
	void setMidPower(const int p_nPower);

	// 获取近灯功率
	const int getNearIrPower() const { return m_nNearIrPower; }

	// 设置近灯功率
	void setNearPower(const int p_nPower);

private:
	int m_nZoomUp;			// zoom上限
	int m_nFarIrPower;		// 远灯功率百分比
	int m_nMidIrPower;		// 中灯功率百分比
	int m_nNearIrPower;		// 近灯功率百分比

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/


#endif // IR_POWER_ITEM_h__