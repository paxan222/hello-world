#ifndef _ABNORMAL_SPEED_PARAM_H
#define _ABNORMAL_SPEED_PARAM_H

#include "IntelligeBaseParam.h"
#include "DomainConst.h"
//#include <vector>
#include "AbnormalSpeedRegionParam.h"
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
class SN_DLL_API AbnormalSpeedParam: public IntelligeBaseParam
{
public:
	AbnormalSpeedParam();
	~AbnormalSpeedParam();

	AbnormalSpeedParam(const AbnormalSpeedParam& p_objAbnormalSpeedParam);
	AbnormalSpeedParam& operator=(const AbnormalSpeedParam& p_objAbnormalSpeedParam);
public:
	void setIsGetDetail(const bool p_bIsGetDetail);
	const bool getIsGetDetail()const;

	void setAbnormalSpeedRegionParamList(const std::vector<AbnormalSpeedRegionParam>& p_objAbnormalSpeedRegionParamList);
	const std::vector<AbnormalSpeedRegionParam>& getAbnormalSpeedRegionParamList()const;

private:
	bool			m_bIsGetDetail;//�Ƿ���ʾ��ϸ��Ϣ
	std::vector<AbnormalSpeedRegionParam > m_objAbnormalSpeedRegionParamList;//���������б�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif
