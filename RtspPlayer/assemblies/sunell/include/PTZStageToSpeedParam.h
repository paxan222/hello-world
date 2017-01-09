#ifndef PTZ_STAGE_TO_SPEED_PARAM_h__
#define PTZ_STAGE_TO_SPEED_PARAM_h__

#include <vector>
#include "SNPlatOS.h"


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
 @brief �ٶȵ�ת�ٶ�һ���ʵ����
******************************************************************************/

class SN_DLL_API PTZStageToSpeedParam
{
public:
	PTZStageToSpeedParam();
	~PTZStageToSpeedParam();

	// ��ȡ�ٶȵ�
	const int getStage() const;

	// �����ٶȵ�
	void setStage(const int p_nStage);

	// ��ȡpan�ٶ�
	const int getPanSpeed() const;

	// ����pan�ٶ�
	void setPanSpeed(const int p_nSpeed);

	// ��ȡtilt�ٶ�
	const int getTiltSpeed() const;

	// ����tilt�ٶ�
	void setTiltSpeed(const int p_nSpeed);


private:
	int m_nStage;		// �ٶȵ�
	int m_nPanSpeed;	// pan�ٶ�
	int m_nTiltSpeed;	// tilt�ٶ�

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/


#endif // PTZ_STAGE_TO_SPEED_PARAM_h__