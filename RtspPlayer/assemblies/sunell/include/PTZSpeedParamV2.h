#ifndef PTZ_SPEED_PARAM_V2_h__
#define PTZ_SPEED_PARAM_V2_h__



#include <vector>
#include "SNPlatOS.h"
#include "PTZStageToSpeedParam.h"
#include "IPTZModuleAbilityParam.h"

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
/**********************************************************************/


/***************************************************************************//**
 @brief �ٶ����ò���ʵ����
******************************************************************************/

class SN_DLL_API PTZSpeedParamV2 : public IPTZModuleAbilityParam
{
public:
	PTZSpeedParamV2();
	~PTZSpeedParamV2();

	// ��ȡpan��������
	const int getPanStepPeriod() const { return m_nPanStepPeriod; }

	// ����pan��������
	void setPanStepPeriod(const int p_nPeriod);

	// ��ȡtilt��������
	const int getTiltStepPeriod() const { return m_nTiltStepPeriod; }

	// ����tilt��������
	void setTiltStepPeriod(const int p_nPeriod);

	// ��ȡ�ٶȲ����б�
	const std::vector<PTZStageToSpeedParam>& getSpeedList() const { return m_objSpeedParamList; }

	// �����ٶȲ����б�
	void setSpeedList(const std::vector<PTZStageToSpeedParam>& p_objSpeedParamlist);

	// ��ȡPan���goto�ٶ�
	const int getPanGotoMaxSpeed() const { return m_nPanGotoMaxSpeed; }

	// ����Pan���goto�ٶ�
	void setPanGotoMaxSpeed(const int p_nMaxSpeed);

	// ��ȡTilt���goto�ٶ�
	const int getTiltGotoMaxSpeed() const { return m_nTiltGotoMaxSpeed; }

	// ����Tilt���goto�ٶ�
	void setTiltGotoMaxSpeed(const int p_nMaxSpeed);

	//��ֵ����
	PTZSpeedParamV2& operator=(const PTZSpeedParamV2 &objPTZSpeedParamV2);

	void setSpeedRange(const int & p_nSpeedRangeFrom , const int & p_nSpeedRangeTo);

	bool getSpeedRange(int & p_nSpeedRangeFrom , int & p_nSpeedRangeTo) const;

private:
	int m_nPanStepPeriod;		// pan��������
	int m_nTiltStepPeriod;		// tilt��������
	std::vector<PTZStageToSpeedParam> m_objSpeedParamList;		// �ٶȲ����б�
	int m_nPanGotoMaxSpeed;		// pan���goto�ٶ�
	int m_nTiltGotoMaxSpeed;	// tilt���goto�ٶ�

	int		m_nMinSpeed;
	int		m_nMaxSpeed;	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/


#endif // PTZ_SPEED_PARAM_V2_h__