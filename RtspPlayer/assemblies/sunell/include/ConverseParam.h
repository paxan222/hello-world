#ifndef _CONVERSE_PARAM_H
#define _CONVERSE_PARAM_H

#include "IntelligeBaseParam.h"
#include "DomainConst.h"
//#include <vector>
#include "ConverseRegionParam.h"
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

//���в���
class SN_DLL_API ConverseParam: public IntelligeBaseParam
{
public:
	ConverseParam();
	~ConverseParam();

	ConverseParam(const ConverseParam& p_objConverseParam);
	ConverseParam& operator=(const ConverseParam& p_objConverseParam);
public:
	void setIsGetDetail(const bool p_bIsGetDetail);
	const bool getIsGetDetail()const;

	void setConverseRegionParamList(const std::vector<ConverseRegionParam>& p_objConverseRegionParamList);
	const std::vector<ConverseRegionParam>& getConverseRegionParamList()const;

private:
	bool			m_bIsGetDetail;//�Ƿ���ʾ��ϸ��Ϣ
	vector<ConverseRegionParam > m_objConverseRegionParamList;//���������б�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif
