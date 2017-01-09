#ifndef _TRIP_WIRE_REGION_PARAM_H
#define _TRIP_WIRE_REGION_PARAM_H
#include "SNPlatOS.h"
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

//�����߲���
class SN_DLL_API TripWireRegionParam
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

public:
	TripWireRegionParam();
	~TripWireRegionParam();

	TripWireRegionParam(const TripWireRegionParam& p_objTripWireRegionParam);
	TripWireRegionParam& operator=(const TripWireRegionParam& p_objTripWireRegionParam);
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

	void setIsBidirection(const bool p_bIsBidirection);
	const bool  getIsBidirection()const;

	void setTriggerDirection(const int m_nTriggerDirection);
	const int getTriggerDirection() const;

	void setLineCross(const LineCross& p_objTripWireLine);
	const LineCross&  getLineCross()const;

private:
	bool 					m_bTargetTypeConstrain;    //!< �Ƿ��޶�Ŀ������(ȡֵ��Χ��0(��)��1(��))
	int						m_nTargetType;             //!< �����޶�ģʽ(ȡֵ��Χ��0(�˻�)��1(��)��2(��))
	bool					m_bTargetSizeConstrain;	   //!< �Ƿ��޶�Ŀ��ߴ�(ȡֵ��Χ��0(��)��1(��))
	int						m_nMinTargetSize;          //!< Ŀ����С�ߴ�(��λ��ƽ������)
	int						m_nMaxTargetSize;          //!< Ŀ�����ߴ�(��λ��ƽ������)

	bool					m_bIsBidirection;          //!< ��ʾ�����Ƿ�Ϊ˫�����(ȡֵ��Χ��0(��)��1(��))
	int					    m_nTriggerDirection;       //!< ���߽�ֹ����Ƕ�(��λ����)
	LineCross				m_objTripWireLine;         //!< ����λ��(��λ������)
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif
