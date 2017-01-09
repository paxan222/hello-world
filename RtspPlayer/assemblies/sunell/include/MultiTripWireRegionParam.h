#ifndef _MULTI_TRIP_WIRE_REGION_PARAM_H
#define _MULTI_TRIP_WIRE_REGION_PARAM_H
#include "IntelligeBaseParam.h"
#include "DomainConst.h"
#include "LineCross.h"

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

//˫���߲���
class SN_DLL_API MultiTripWireRegionParam
{
public:
	enum
	{
		HUMAN_VEHICLE = 0,
		HUMAN  = 1,
		VEHICLE = 2, 

		TRIGGER_DIRECTION_LEFT = 1,       //����������
		TRIGGER_DIRECTION_RIGHT = 2       //����������
	};

	MultiTripWireRegionParam();
	~MultiTripWireRegionParam();

	MultiTripWireRegionParam(const MultiTripWireRegionParam& p_objMultiTripWireRegionParam);
	MultiTripWireRegionParam& operator=(const MultiTripWireRegionParam& p_objMultiTripWireRegionParam);
public:
	void setTargetTypeConstrain(const bool p_bTargetTypeConstrain);
	const bool getTargetTypeConstrain()const;

	void setTargetType(const int p_nTargetType);
	const int  getTargetType()const;

	void setTargetSizeConstrain(const bool p_bTargetSizeConstrain);
	const bool  getTargetSizeConstrain()const;

	void setMinTargetSize(const int p_nMinTargetSize);
	const int  getMinTargetSize()const;

	void setMaxTargetSize(const int p_nMaxTargetSize);
	const int  getMaxTargetSize()const;

	void setTimeInterval(const int p_nTimeInterval);
	const int  getTimeInterval()const;

	void setTriggerDirection1(const int p_nTriggerDirection1);
	const int getTriggerDirection1() const;
	void setTriggerDirection2(const int p_nTriggerDirection2);
	const int getTriggerDirection2() const;

	void setTripWireLine1(const LineCross& p_objTripWireLine1);
	const LineCross&  getTripWireLine1()const;
	void setTripWireLine2(const LineCross& p_objTripWireLine2);
	const LineCross&  getTripWireLine2()const;

private:
	bool 				m_bTargetTypeConstrain;        //!< �Ƿ��޶�Ŀ������(ȡֵ��Χ��0(��)��1(��))
	int					m_nTargetType;                 //!< �����޶�ģʽ(ȡֵ��Χ��0(�˻�)��1(��)��2(��))
	bool				m_bTargetSizeConstrain;        //!< �Ƿ��޶�Ŀ��ߴ�(ȡֵ��Χ��0(��)��1(��))
	int					m_nMinTargetSize;              //!< Ŀ����С�ߴ�(��λ��ƽ������)
	int					m_nMaxTargetSize;              //!< Ŀ�����ߴ�(��λ��ƽ������)

	int					m_nTimeInterval;               //!<  ��Խ�����ߵ��ʱ����(��λ����)
	int				    m_nTriggerDirectionList[2];    //!<  ���߽�ֹ����Ƕ�(��λ����)0��360 ��
	LineCross			m_objTripWireLineList[2];      //!<  ����λ��(��λ������)
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif
