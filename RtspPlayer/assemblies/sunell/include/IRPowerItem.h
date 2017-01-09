#ifndef IR_POWER_ITEM_h__
#define IR_POWER_ITEM_h__


#include <vector>
#include "SNPlatOS.h"


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
 @brief ����ƹ���һ���ʵ����
******************************************************************************/

class SN_DLL_API IRPowerItem
{
public:
	IRPowerItem();
	~IRPowerItem();

	// ��ȡzoom����
	const int getZoomUp() const { return m_nZoomUp; }

	// ����zoom����
	void setZoomUp(const int p_nZoomUp);

	// ��ȡԶ�ƹ���
	const int getFarIrPower() const { return m_nFarIrPower; }

	// ����Զ�ƹ���
	void setFarPower(const int p_nPower);

	// ��ȡ�еƹ���
	const int getMidIrPower() const { return m_nMidIrPower; }

	// �����еƹ���
	void setMidPower(const int p_nPower);

	// ��ȡ���ƹ���
	const int getNearIrPower() const { return m_nNearIrPower; }

	// ���ý��ƹ���
	void setNearPower(const int p_nPower);

private:
	int m_nZoomUp;			// zoom����
	int m_nFarIrPower;		// Զ�ƹ��ʰٷֱ�
	int m_nMidIrPower;		// �еƹ��ʰٷֱ�
	int m_nNearIrPower;		// ���ƹ��ʰٷֱ�

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/


#endif // IR_POWER_ITEM_h__