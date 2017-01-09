#ifndef _OBJECT_MOVED_PARAM_H
#define _OBJECT_MOVED_PARAM_H
#include "IntelligeBaseParam.h"
#include "DomainConst.h"
//#include <vector>
#include "ObjectMovedRegionParam.h"
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
class SN_DLL_API ObjectMovedParam: public IntelligeBaseParam
{
public:
	ObjectMovedParam();
	~ObjectMovedParam();

	ObjectMovedParam(const ObjectMovedParam& p_objObjectMovedParam);
	ObjectMovedParam& operator=(const ObjectMovedParam& p_objObjectMovedParam);
public:
	void setIsGetDetail(const bool p_bIsGetDetail);
	const bool getIsGetDetail()const;

	void setObjectMovedRegionParamList(const std::vector<ObjectMovedRegionParam>& p_objObjectMovedRegionParamList);
	const std::vector<ObjectMovedRegionParam>& getObjectMovedRegionParamList()const;

private:
	bool			m_bIsGetDetail;//�Ƿ���ʾ��ϸ��Ϣ
	std::vector<ObjectMovedRegionParam > m_objObjectMovedRegionParamList;//���������б�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif
