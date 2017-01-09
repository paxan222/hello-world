#ifndef _AudioDetectionParam_
#define _AudioDetectionParam_

#include "SNPlatOS.h"
#include "DomainConst.h"

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

class SN_DLL_API AudioDetectionParam
{
public:
	AudioDetectionParam(void);
	~AudioDetectionParam(void);

public:
	/************************************************************************
	*	����������������
	*	���룺
	*		p_nSensitivity	������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setSensitivity(int p_nSensitivity);

	/************************************************************************
	*	��������ȡ������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		������
	*************************************************************************/
	int getSensitivity() const;

	/************************************************************************
	*	���������ñ�����ֵ
	*	���룺
	*		p_nAlarmLevel	������ֵ
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setAlarmLevel(int p_nAlarmLevel);

	/************************************************************************
	*	��������ȡ������ֵ
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		������ֵ
	*************************************************************************/
	int getAlarmLevel() const;
	/************************************************************************
	*	���������������������
	*	���룺
	*		p_nAlarmLevel	�����������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setDetectType(int p_nDetectType);

	/************************************************************************
	*	��������ȡ�����������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		�����������
	*************************************************************************/
	int getDetectType() const;
	AudioDetectionParam& operator = (const AudioDetectionParam& p_objAudioDetectionParam);
private:
	int		m_nSensitivity;
	int		m_nDetectType;
	int		m_nAlarmLevel;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_AudioDetectionParam_
