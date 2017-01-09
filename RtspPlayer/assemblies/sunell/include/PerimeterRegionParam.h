#ifndef _PERIMETER_REGION_PARAM_H
#define _PERIMETER_REGION_PARAM_H
#include "IntelligeBaseParam.h"
#include "DomainConst.h"
#include "PolygonArea.h"
#include "DetectionAreaV2.h"
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

//�����ܽ����
class SN_DLL_API PerimeterRegionParam
{
public:
	enum
	{
		HUMAN_VEHICLE = 0,
		HUMAN  = 1,
		VEHICLE = 2
	};
public:
	PerimeterRegionParam();
	~PerimeterRegionParam();

	PerimeterRegionParam(const PerimeterRegionParam& p_objPerimeterRegionParam);
	PerimeterRegionParam& operator=(const PerimeterRegionParam& p_objPerimeterRegionParam);
public:
	void setSensitivity(const int p_nSensitivity);
	const int getSensitivity()const;

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

	/******************************************************
	����/��ȡ�������򣬴˷�������Ϊ����Σ����ݲ�ͬ����Ҫ��
	�����͵ķ����������ʹ�á�
	**************************************************/
	void setRegion(const PolygonArea& p_objRegion);
	const PolygonArea& getRegion()const;

	/******************************************************
	����/��ȡ�������򣬴˷�������Ϊ���񣬸��ݲ�ͬ����Ҫ��
	����η����������ʹ�á�
	**************************************************/
	void setDetectionAreaV2(const DetectionAreaV2& p_objDetectionAreaV2);
	const DetectionAreaV2& getDetectionAreaV2()const;

private:
	int					m_nSensitivity;	//	������	
	bool 					m_bTargetTypeConstrain;	//!< �Ƿ��޶�Ŀ������(ȡֵ��Χ��0(��)��1(��))
	int					m_nTargetType;	//!< �����޶�ģʽ(ȡֵ��Χ��0(�˻�)��1(��)��2(��))
	bool					m_bTargetSizeConstrain;	//!< �Ƿ��޶�Ŀ��ߴ�(ȡֵ��Χ��0(��)��1(��))
	int					m_nMinTargetSize;	//!< Ŀ����С�ߴ�(��λ��ƽ������)
	int					m_nMaxTargetSize;	//!< Ŀ�����ߴ�(��λ��ƽ������)
	PolygonArea			m_objRegion;	//!< ��������(����Σ����ֲ�ͬ�ķ��������ڲ�ͬ�ĵײ������¶���ʹ�ã������ǲ���ͬʱʹ�õģ�������������ȡ)
	DetectionAreaV2		m_objDetectionAreaV2;//���������������ֲ�ͬ�ķ��������ڲ�ͬ�ĵײ������¶���ʹ�ã������ǲ���ͬʱʹ�õģ�������������ȡ��
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif
