#ifndef _MULTI_LOITER_REGION_PARAM_H
#define _MULTI_LOITER_REGION_PARAM_H
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

//�����ܽ�  �����ǻ�
class SN_DLL_API MultiLoiterRegionParam
{
public:
	MultiLoiterRegionParam();
	~MultiLoiterRegionParam();

	MultiLoiterRegionParam(const MultiLoiterRegionParam& p_objMultiLoiterRegionParam);
	MultiLoiterRegionParam& operator=(const MultiLoiterRegionParam& p_objMultiLoiterRegionParam);
public:
	void setTargetSizeConstrain(const bool p_bTargetSizeConstrain);
	const bool  getTargetSizeConstrain()const;

	void setMinTargetSize(const int p_nMinTargetSize);
	const int  getMinTargetSize()const;

	void setMaxTargetSize(const int p_nMaxTargetSize);
	const int  getMaxTargetSize()const;

	void setMinTime(const int p_nMinTime);
	const int  getMinTime()const;

	void setAnalysisPath(const bool p_bAnalysisPath);
	const bool  getAnalysisPath()const;

	void setForbiddenType(const bool p_bForbiddenType);
	const bool  getForbiddenType()const;

	void setMinimum(const int p_nMinimum);
	const int  getMinimum()const;

	void setMaximum(const int p_nMaximum);
	const int  getMaximum()const;


	void setRegion(const PolygonArea& p_objRegion);
	const PolygonArea& getRegion()const;
private:
	bool				m_bTargetSizeConstrain;		//!< �Ƿ��޶�Ŀ��ߴ�(ȡֵ��Χ��0(��)��1(��))
	int				m_nMinTargetSize;				//!< Ŀ����С�ߴ�(��λ��ƽ������)
	int				m_nMaxTargetSize;				//!< Ŀ�����ߴ�(��λ��ƽ������)
	
	int				m_nMinTime;						//!< �ǻ����ʱ��(��λ����)
	bool				m_bAnalysisPath;					//�Ƿ�����·���ж�
	
	bool				m_bForbiddenType;				//����������־
	int				m_nMinimum;						//��Сֵ
	int				m_nMaximum;						//���ֵ

	PolygonArea			m_objRegion;				//������Ϣ
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif
