#ifndef _INTELLIGE_BASE_PARAM_H
#define _INTELLIGE_BASE_PARAM_H
#include "AlarmOutAction.h"
#include "AlarmRecordAction.h"
#include "AlarmPTZAction.h"
#include "AlarmOverlayAction.h"
#include "ScheduleTimeParam.h"
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

//�����ܽ�Ļ���
class SN_DLL_API IntelligeBaseParam
{

public:
	IntelligeBaseParam();
	virtual ~IntelligeBaseParam();

	IntelligeBaseParam(const IntelligeBaseParam& p_objIntelligeBaseParam);
	IntelligeBaseParam& operator=(const IntelligeBaseParam& p_objIntelligeBaseParam);
public:
	bool setDeviceID(const char* p_pszDeviceID);
	const char* getDeviceID()const;

	void setCameraID(const int p_nCameraID);
	const int getCameraID()const;

	void setEnable(const bool p_bIsEnable);
	const bool getEnable()const;

	void setAlarmInterval(const int p_nAlarmInterval);
	const int  getAlarmInterval()const;

	void setScheduleTimeParam(const ScheduleTimeParam& p_objScheduleTimeParam);
	const ScheduleTimeParam& getScheduleTimeParam()const;

	void setAlarmOutActionList(const std::vector<AlarmOutAction>& p_objAlarmOutActionList);
	const std::vector<AlarmOutAction>& getAlarmOutActionList()const;

	void setAlarmRecordActionList(const std::vector<AlarmRecordAction>& p_objAlarmRecordActionList);
	const std::vector<AlarmRecordAction>& getAlarmRecordActionList()const;


	void setAlarmPTZActionList(const std::vector<AlarmPTZAction>& p_objAlarmPTZActionList);
	const std::vector<AlarmPTZAction>& getAlarmPTZActionList()const;

	void setAlarmOverlayActionList(const std::vector<AlarmOverlayAction>& p_objAlarmOverlayActionListList);
	const std::vector<AlarmOverlayAction>& getAlarmOverlayActionList()const;
private:
	char	m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//�豸���豸ID
	int	m_nCameraId;
	bool	m_bIsEnable;
	int	m_nAlarmInterval;

	ScheduleTimeParam	m_objScheduleTimeParam;

	std::vector<AlarmOutAction>			m_objAlarmOutActionList;			//���������Ϊ�����б�
	std::vector<AlarmRecordAction>		m_objAlarmRecordActionList;			//����¼����Ϊ�����б�
	std::vector<AlarmPTZAction>			m_objAlarmPTZActionList;			//������̨��Ϊ�����б�
	std::vector<AlarmOverlayAction>		m_objAlarmOverlayActionList;		//����ˮӡ��Ϊ�����б�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif
