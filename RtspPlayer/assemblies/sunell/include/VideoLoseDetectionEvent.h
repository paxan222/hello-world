#ifndef _VIDEOLOSEDETECTIONEVENT_H_
#define _VIDEOLOSEDETECTIONEVENT_H_

#include "DomainConst.h"
#include "AlarmOutAction.h"
#include "AlarmPTZAction.h"
#include "SNPlatOS.h"
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
/**********************************************************************/

class SN_DLL_API VideoLoseDetectionEvent
{
public:
	VideoLoseDetectionEvent();
	~VideoLoseDetectionEvent();

	//�������캯��
	VideoLoseDetectionEvent (const VideoLoseDetectionEvent& p_objVideoLoseDetectionEvent);

public:

	/**********************************************************************
	**������
	*		����������Ƶ�豸���豸ID
	**���룺
	*		p_pszDeviceId ���ַ�������󳤶�ΪCONST_MAXLENGTH_DEVICEID�ֽ�,
	*		��β�ԡ�\0��������
	**�����
	*		��
	**����ֵ��
	*		true �� �ɹ�
	*		false��	ʧ�� 
	**���ܣ�
	*		������p_pszDeviceId����<=CONST_MAXLENGTH_DEVICEID������true��
	*		�����浽m_szDeviceId;
	*		������p_pszDeviceIdΪNULL���䳤��>CONST_MAXLENGTH_DEVICEID������false
	************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸���豸ID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸ID
	**���ܣ�
	*
	***************************************************************************/
	const char* getDeviceId() const;

	/************************************************************************
	**������
	*		�����豸����ͷID��
	**���룺
	*		p_nCameraId���豸����ͷID��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	void setCameraId(int p_nCameraId);

	/************************************************************************
	**������
	*		��ȡ�豸����ͷID��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸����ͷID��
	**���ܣ�
	*
	************************************************************************/
	int getCameraId() const;

	/************************************************************************
	**������
	*		�����Ƿ�������־
	**���룺
	*		p_bFlag		�Ƿ�������־
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setVideoLoseDetectionEnableFlag(const bool p_bFlag);

	/************************************************************************
	**������
	*		��ȡ�Ƿ�������־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�Ƿ�������־
	************************************************************************/
	const bool getVideoLoseDetectionEnableFlag() const ;

	/************************************************************************
	**������
	*		���ñ��������Ϊ�����б�
	**���룺
	*		p_objAlarmOutActionList�����������Ϊ�����б�
	**�����
	*		��
	**����ֵ��
	*		
	**���ܣ�
	*      
	**************************************************************************/
	void setAlarmOutAction(const std::vector<AlarmOutAction>& p_objAlarmOutActionList);

	/************************************************************************
	**������
	*		��ȡ���������Ϊ�����б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���������Ϊ�����б�
	**���ܣ�
	*      
	**************************************************************************/
	const std::vector<AlarmOutAction>& getAlarmOutAction() const;

	/************************************************************************
	**������
	*		���ñ���PTZ��Ϊ�����б�
	**���룺
	*		p_objAlarmOutActionList������PTZ��Ϊ�����б�
	**�����
	*		��
	**����ֵ��
	*		
	**���ܣ�
	*      
	**************************************************************************/
	void setAlarmPTZAction(const std::vector<AlarmPTZAction>& p_objAlarmPTZActionList);

	/************************************************************************
	**������
	*		��ȡ����PTZ��Ϊ�����б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���������Ϊ�����б�
	**���ܣ�
	*      
	**************************************************************************/
	const  std::vector<AlarmPTZAction>& getAlarmPTZAction() const;

	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objVideoLoseDetectionEvent����Ƶ��ʧ�����¼�����
	**�����
	*		��
	**����ֵ��
	*		��ֵ�����Ƶ��ʧ�����¼�����
	**���ܣ�
	*		
	*****************************************************************************/
	VideoLoseDetectionEvent& operator = (const VideoLoseDetectionEvent& p_objVideoLoseDetectionEvent);



private:

	char							m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//�豸ID

	int								m_nCameraId;											//����ͷID��

	bool							m_bVideoLoseDetectionEnableFlag;						//�Ƿ��������

	std::vector<AlarmOutAction>		m_objAlarmOutActionList;								//���������Ϊ�����б�

	std::vector<AlarmPTZAction>		m_objAlarmPTZActionList;								//����PTZ��Ϊ�����б�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif	//_VIDEOLOSEDETECTIONEVENT_H_


