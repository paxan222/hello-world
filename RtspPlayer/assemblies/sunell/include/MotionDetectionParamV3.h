#ifndef _MOTION_DETECTION_PARAM_V3_H
#define _MOTION_DETECTION_PARAM_V3_H
#include "IntelligeBaseParam.h"
#include "DomainConst.h"
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

//�������ٶȲ���
class  SN_DLL_API MotionDetectionParamV3: public IntelligeBaseParam
{
public:
	MotionDetectionParamV3();
	~MotionDetectionParamV3();

	MotionDetectionParamV3(const MotionDetectionParamV3& p_objMotionDetectionParamV3);
	MotionDetectionParamV3& operator=(const MotionDetectionParamV3& p_objMotionDetectionParamV3);
public:
	void setSensitivity(const int p_nSensitivity);
	const int getSensitivity()const;

	void setIsGetDetail(const bool p_nIsGetDetailed);
	const bool getIsGetDetail()const;

	void setDetectionAreaV2(const DetectionAreaV2& p_objDetectionAreaV2);
	const DetectionAreaV2& getDetectionAreaV2()const;

private:
	int					m_nSensitivity;	//	������
	bool					m_bIsGetDetail;//�Ƿ���ʾ��ϸ��Ϣ

	DetectionAreaV2		m_objDetectionAreaV2;//������Ϣ
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif
