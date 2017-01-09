#ifndef _MOTIONDETECTIONEVENT_H_
#define _MOTIONDETECTIONEVENT_H_

#include "DomainConst.h"
#include "AlarmOutAction.h"
#include "AlarmRecordAction.h"
#include "AlarmPTZAction.h"
#include "AlarmOverlayAction.h"
#include "DetectionArea.h"
#include "MotionDetectionParam.h"
#include "ScheduleTimeParam.h"
#include "SNPlatOS.h"
#include <vector>
using namespace std;

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

class SN_DLL_API MotionDetectionEvent
{
public:
	MotionDetectionEvent();
	~MotionDetectionEvent();

	//�������캯��
	MotionDetectionEvent (const MotionDetectionEvent &p_objMotionDetectionEvent);

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


	/**********************************************************************
	**������
	*		���ñ����¼�ID
	**���룺
	*		p_nEventId �������¼�ID��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	void setEventId(int p_nEventId);

	/************************************************************************
	**������
	*		��ȡ�����¼�ID
	**���룺
	*		��
	**�����
	*		
	**����ֵ��
	*		�����¼�ID
	**���ܣ�
	*	
	***************************************************************************/
	int getEventId() const;


	/**********************************************************************
	**������
	*		���ñ�������ID
	**���룺
	*		p_nPolicyId ����������ID��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setPolicyId(int p_nPolicyId);

	/************************************************************************
	**������
	*		��ȡ��������ID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��������ID
	**���ܣ�
	*	
	***************************************************************************/
	int getPolicyId() const;


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
	*		�����Ƿ������˶�����־
	**���룺
	*		p_bFlag���Ƿ������˶�����־
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	�����Ƿ������˶�����־
	************************************************************************/
	void setMotionDetectionEnableFlag(const bool p_bFlag);

	/************************************************************************
	**������
	*		��ȡ�Ƿ������˶�����־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�Ƿ������˶�����־
	**���ܣ�
	*	��ȡ�Ƿ������˶�����־
	************************************************************************/
	const bool getMotionDetectionEnableFlag() const ;

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
	void setAlarmOutAction(const vector<AlarmOutAction>& p_objAlarmOutActionList);

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
	vector<AlarmOutAction>* getAlarmOutAction() const;


	/************************************************************************
	**������
	*		���ñ���¼����Ϊ�����б�
	**���룺
	*		p_objAlarmRecordActionList������¼����Ϊ�����б�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*      
	**************************************************************************/
	void setAlarmRecordAction(const vector<AlarmRecordAction>& p_objAlarmRecordActionList);

	/************************************************************************
	**������
	*		��ȡ����¼����Ϊ�����б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����¼����Ϊ�����б�
	**���ܣ�
	*      
	**************************************************************************/
	vector<AlarmRecordAction>* getAlarmRecordAction() const;


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
	vector<AlarmPTZAction>* getAlarmPTZAction() const;


	/************************************************************************
	**������
	*		���ñ���ˮӡ��Ϊ�����б�
	**���룺
	*		p_objAlarmOverlayActionList������ˮӡ��Ϊ�����б�
	**�����
	*		��
	**����ֵ��
	*		
	**���ܣ�
	*      
	**************************************************************************/
	void setAlarmOverlayAction(const vector<AlarmOverlayAction>& p_objAlarmOverlayActionList);

	/************************************************************************
	**������
	*		��ȡ����ˮӡ��Ϊ�����б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ˮӡ��Ϊ�����б�
	**���ܣ�
	*      
	**************************************************************************/
	vector<AlarmOverlayAction>* getAlarmOverlayAction() const;


		/************************************************************************
	**������
	*		�����ƶ����������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�����ƶ����������
	**���ܣ�
	*      
	**************************************************************************/
	void setMotionDetectionParam(const MotionDetectionParam & p_MotionDetectionParam); 
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
	MotionDetectionParam* getMotionDetectionParam() const; 


	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objMotionDetectionEvent���Ƶ���ⱨ���¼�����
	**�����
	*		��
	**����ֵ��
	*		��ֵ����Ƶ���ⱨ���¼�����
	**���ܣ�
	*		
	*****************************************************************************/
	MotionDetectionEvent& operator = (const MotionDetectionEvent &p_objMotionDetectionEvent);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objMotionDetectionEvent��MotionDetectionEvent���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true �����
	*		false�������
	**���ܣ�
	*		����MotionDetectionEvent��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	//bool operator == (const MotionDetectionEvent& p_objMotionDetectionEvent) const;

	//bool operator < (const MotionDetectionEvent& p_objMotionDetectionEvent) const;

private:
	
	int			m_nEventId;												//�����¼�ID
	int			m_nPolicyId;											//��������ID
	char		m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//DVR�豸���豸ID
	int			m_nCameraId;											//DVR�豸����ͷID��
	bool		m_bMotionDetectionEnableFlag;							//�Ƿ������˶����
	
	//bool		m_bToUpCheckFlag;										//�����⣨true����⣬false������⣩
	//bool		m_bToDownCheckFlag;										//���¼�⣨true����⣬false������⣩
	//bool		m_bToLeftCheckFlag;										//�����⣨true����⣬false������⣩
	//bool		m_bToRightCheckFlag;									//���Ҽ�⣨true����⣬false������⣩
	//bool		m_bAreaMaskFlag;										//���α�ʶ��true�����Σ�false����⣩
	//int			m_nCheckBlockNum;										//������
	//int			m_nSensitivity;											//������
	//int			m_nImageFormatId;										//��Ƶ��ʽ
	//int			m_nFrameInterval;										//֡���
	//vector<DetectionArea>			m_objDetectionAreaList;				//�ƶ������������б�
	
	MotionDetectionParam            m_objMotionDetectionParam;			//�ƶ����������

	ScheduleTimeParam				m_objScheduleTimeParam;				//����ʱ�����

	vector<AlarmOutAction>			m_objAlarmOutActionList;			//���������Ϊ�����б�
	vector<AlarmRecordAction>		m_objAlarmRecordActionList;			//����¼����Ϊ�����б�
	vector<AlarmPTZAction>			m_objAlarmPTZActionList;			//������̨��Ϊ�����б�
	vector<AlarmOverlayAction>		m_objAlarmOverlayActionList;		//����ˮӡ��Ϊ�����б�

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_MOTIONDETECTIONEVENT_H_
