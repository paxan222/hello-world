#ifndef _NO_PARKING_PARAM_H
#define _NO_PARKING_PARAM_H

#include "IntelligeBaseParam.h"
#include "DomainConst.h"
//#include <vector>
#include "NoParkingRegionParam.h"
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
class SN_DLL_API NoParkingParam: public IntelligeBaseParam
{
public:
	NoParkingParam();
	~NoParkingParam();

	NoParkingParam(const NoParkingParam& p_objNoParkingParam);
	NoParkingParam& operator=(const NoParkingParam& p_objNoParkingParam);
public:
	void setIsGetDetail(const bool p_bIsGetDetail);
	const bool getIsGetDetail()const;

	void setNoParkingRegionParamList(const std::vector<NoParkingRegionParam>& p_objNoParkingRegionParamList);
	const std::vector<NoParkingRegionParam>& getNoParkingRegionParamList()const;

private:
	bool			m_bIsGetDetail;//�Ƿ���ʾ��ϸ��Ϣ
	std::vector<NoParkingRegionParam > m_objNoParkingRegionParamList;//���������б�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif
