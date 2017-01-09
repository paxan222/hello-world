#ifndef _OCCLUSIONDETECTIONEVENT_H_
#define _OCCLUSIONDETECTIONEVENT_H_

#include "DomainConst.h"
#include "AlarmOutAction.h"
#include "AlarmRecordAction.h"
#include "AlarmPTZAction.h"
#include "AlarmOverlayAction.h"
#include "DetectionArea.h"
#include "OcclusionDetectionParam.h"
#include "ScheduleTimeParam.h"
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

class SN_DLL_API OcclusionDetectionEvent
{
public:
	OcclusionDetectionEvent();
	~OcclusionDetectionEvent();

	//�������캯��
	OcclusionDetectionEvent (const OcclusionDetectionEvent &p_objOcclusionDetectionEvent);

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
	*		false��ʧ�� 
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
	void setOcclusionDetectionEnableFlag(const bool p_bFlag);

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
	const bool getOcclusionDetectionEnableFlag() const ;

	/************************************************************************
	**������
	*		���ñ�������ʱ��
	**���룺
	*		p_objScheduleTimeParam����������ʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	���ñ�������ʱ��
	************************************************************************/
	void setScheduleTimeParam(const ScheduleTimeParam &p_objScheduleTimeParam);

	/************************************************************************
	**������
	*		��ȡ��������ʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��������ʱ��
	**���ܣ�
	*	��ȡ��������ʱ��
	************************************************************************/
	const ScheduleTimeParam & getScheduleTimeParam() const;

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
	const vector<AlarmOutAction>& getAlarmOutAction() const;

	/************************************************************************
	**������
	*		���ñ�����̨��Ϊ�����б�
	**���룺
	*		p_objAlarmPTZActionList��������̨��Ϊ�����б�
	**�����
	*		��
	**����ֵ��
	*		
	**���ܣ�
	*      
	**************************************************************************/
	void setAlarmPTZAction(const vector<AlarmPTZAction>& p_objAlarmPTZActionList);

	/************************************************************************
	**������
	*		��ȡ������̨��Ϊ�����б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������̨��Ϊ�����б�
	**���ܣ�
	*      
	**************************************************************************/
	const vector<AlarmPTZAction>& getAlarmPTZAction() const;

	/************************************************************************
	**������
	*		�����ڵ�������
	**���룺
	*		p_objOcclusionDetectionParam���ڵ�������
	**�����
	*		��
	**����ֵ��
	*		
	**���ܣ�
	*      
	**************************************************************************/
	void setOcclusionDetectionParam(const OcclusionDetectionParam& p_objOcclusionDetectionParam); 

	/************************************************************************
	**������
	*		��ȡ�ƶ����������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��ȡ�ƶ����������
	**���ܣ�
	*      
	**************************************************************************/
	const OcclusionDetectionParam& getOcclusionDetectionParam() const; 


	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objOcclusionDetectionEvent���Ƶ���ⱨ���¼�����
	**�����
	*		��
	**����ֵ��
	*		��ֵ����Ƶ���ⱨ���¼�����
	**���ܣ�
	*		
	*****************************************************************************/
	OcclusionDetectionEvent& operator = (const OcclusionDetectionEvent& p_objOcclusionDetectionEvent);

private:
	
	char							m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//DVR�豸���豸ID
	int								m_nCameraId;											//DVR�豸����ͷID��
	bool							m_bOcclusionDetectionEnableFlag;						//�Ƿ�����
	
	OcclusionDetectionParam         m_objOcclusionDetectionParam;							//���������

	ScheduleTimeParam				m_objScheduleTimeParam;									//����ʱ�����

	std::vector<AlarmOutAction>			m_objAlarmOutActionList;								//���������Ϊ�����б�
	std::vector<AlarmPTZAction>			m_objAlarmPTZActionList;								//������̨��Ϊ�����б�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_OCCLUSIONDETECTIONEVENT_H_
