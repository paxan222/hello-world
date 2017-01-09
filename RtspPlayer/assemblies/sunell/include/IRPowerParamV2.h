#ifndef IR_POWER_PARAM_V2_h__
#define IR_POWER_PARAM_V2_h__

#include <vector>
#include "SNPlatOS.h"
#include "IRPowerItem.h"

/**********************************************************************/
//�˴����ڿ����ļ������ֽڶ��룬����ʱ����ע�ͼ�������һ�𿽱���
//�������ġ�#ifdef PRAGMA_PACK������ҲҪһ�𿽱�������pragma pack��ջ��ջ��ƥ��
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
@brief ����ƹ��ʵ�ʵ����
******************************************************************************/

class SN_DLL_API IRPowerParamV2
{
public:
	IRPowerParamV2();
	~IRPowerParamV2();

	// ��ȡIR POWER
	const std::vector<IRPowerItem>& getIrPower() const { return m_objIrPower; };

	// ����IR POWER
	void setIrPower(const std::vector<IRPowerItem>& p_objIrPower);

private:
	std::vector<IRPowerItem> m_objIrPower;		// IR POWER�����ü�
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/


#endif // IR_POWER_PARAM_V2_h__