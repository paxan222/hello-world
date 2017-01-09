#ifndef _CONVERSE_REGION_PARAM_H
#define _CONVERSE_REGION_PARAM_H
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

////�����ܽ� ����
class SN_DLL_API ConverseRegionParam
{
public:
	enum
	{
		HUMAN_VEHICLE = 0,
		HUMAN  = 1,
		VEHICLE = 2
	};
public:
	ConverseRegionParam();
	~ConverseRegionParam();

	ConverseRegionParam(const ConverseRegionParam& p_objConverseRegionParam);
	ConverseRegionParam& operator=(const ConverseRegionParam& p_objConverseRegionParam);
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

	void setConverseAngle(const float p_nConverseAngle);
	const float  getConverseAngle()const;

	void setRegion(const PolygonArea& p_objRegion);
	const PolygonArea& getRegion()const;
private:
	bool 				m_bTargetTypeConstrain;	//!< �Ƿ��޶�Ŀ������(ȡֵ��Χ��0(��)��1(��))
	int				m_nTargetType;				//!< �����޶�ģʽ(ȡֵ��Χ��0(�˻�)��1(��)��2(��))
	bool				m_bTargetSizeConstrain;	//!< �Ƿ��޶�Ŀ��ߴ�(ȡֵ��Χ��0(��)��1(��))
	int				m_nMinTargetSize;			//!< Ŀ����С�ߴ�(��λ��ƽ������)
	int				m_nMaxTargetSize;			//!< Ŀ�����ߴ�(��λ��ƽ������)
	
	float				m_fConverseAngle;			//!< ���з���Ƕ�(��λ����) 0��360 ��

	PolygonArea			m_objRegion;//������Ϣ
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif
