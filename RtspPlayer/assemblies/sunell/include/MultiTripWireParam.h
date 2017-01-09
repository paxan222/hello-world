#ifndef _MULTI_TRIP_WIRE_PARAM_H
#define _MULTI_TRIP_WIRE_PARAM_H

#include "IntelligeBaseParam.h"
#include "DomainConst.h"
//#include <vector>
#include "MultiTripWireRegionParam.h"
#include <vector>
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
class SN_DLL_API MultiTripWireParam: public IntelligeBaseParam
{
public:
	MultiTripWireParam();
	~MultiTripWireParam();

	MultiTripWireParam(const MultiTripWireParam& p_objMultiTripWireParam);
	MultiTripWireParam& operator=(const MultiTripWireParam& p_objMultiTripWireParam);
public:
	void setIsGetDetail(const bool p_bIsGetDetail);
	const bool getIsGetDetail()const;

	void setMultiTripWireRegionParamList(const std::vector<MultiTripWireRegionParam>& p_objMultiTripWireRegionParamList);
	const std::vector<MultiTripWireRegionParam>& getMultiTripWireRegionParamList()const;

private:
	bool				m_bIsGetDetail;	//�Ƿ��ȡ��ϸ��Ϣ
	std::vector<MultiTripWireRegionParam > m_objMultiTripWireRegionParamList;//���������б�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif
