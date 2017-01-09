#ifndef _OBJECT_MOVED_REGION_PARAM_H
#define _OBJECT_MOVED_REGION_PARAM_H
#include "IntelligeBaseParam.h"
#include "DomainConst.h"
#include "PolygonArea.h"

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

//��Ʒ���߲���
class SN_DLL_API ObjectMovedRegionParam
{
public:
	ObjectMovedRegionParam();
	~ObjectMovedRegionParam();

	ObjectMovedRegionParam(const ObjectMovedRegionParam& p_objObjectMovedRegionParam);
	ObjectMovedRegionParam& operator=(const ObjectMovedRegionParam& p_objObjectMovedRegionParam);
public:
	void setMinTargetSize(const int p_nMinTargetSize);
	const int  getMinTargetSize()const;

	void setMaxTargetSize(const int p_nMaxTargetSize);
	const int  getMaxTargetSize()const;

	void setMinTime(const int p_nMinTime);
	const int  getMinTime()const;

	void setRegion(const PolygonArea& p_objRegion);
	const PolygonArea& getRegion()const;

private:
	int 						m_nMinTargetSize;		//!< ��Ʒ��С�ߴ�(��λ��ƽ������)
	int							m_nMaxTargetSize;	//!< ��Ʒ���ߴ�(��λ��ƽ������)
	int							m_nMinTime;			//!< ��Ʒ�������ʱ��(��λ����)

	PolygonArea			m_objRegion;		//������Ϣ
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif
