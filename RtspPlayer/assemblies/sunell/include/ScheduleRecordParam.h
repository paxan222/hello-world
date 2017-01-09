#ifndef _SCHEDULERECORDPARAM_H_
#define _SCHEDULERECORDPARAM_H_

#include "DomainConst.h"
#include "ScheduleTimeParam.h"
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

class SN_DLL_API ScheduleRecordParam
{
public:
	ScheduleRecordParam(void);
	~ScheduleRecordParam(void);

	//�������캯��
	ScheduleRecordParam(const ScheduleRecordParam& p_objScheduleRecordParam);

public:
	enum RuleType
	{
		RECORD_RULE_TYPE_ALWAYS = 1,			//����¼��
		RECORD_RULE_TYPE_SCHEDULE = 2			//�ƻ�¼��
	};

public:
	/************************************************************************
	**�����������豸ID
	*
	**���룺
	*		p_pszDeviceId ���豸ID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		�����豸ID
	************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**��������ȡ�豸ID
	*
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸ID
	**���ܣ�       
	*		��ȡ�豸ID
	************************************************************************/
	const char* getDeviceId() const;


	/************************************************************************
	**���������������ID��
	*
	**���룺
	*		p_nCameraId �������ID��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		���������ID��
	************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**��������ȡ�����ID��
	*
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�����ID
	**���ܣ�       
	*		��ȡ�����ID��
	************************************************************************/
	const int getCameraId() const;


	/************************************************************************
	**�����������Ƿ�¼���־
	*
	**���룺
	*		p_bIsEnableRecord ��true��ʾ��������¼��false��ʾ����������¼��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		�����Ƿ�¼���־
	************************************************************************/
	void setEnableRecord(const bool p_bIsEnableRecord);

	/************************************************************************
	**��������ȡ�Ƿ�¼���־
	*
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		true��ʾ��������¼��false��ʾ����������¼��
	**���ܣ�       
	*		��ȡ�Ƿ�¼���־
	************************************************************************/
	const bool getEnableRecord() const;


	/************************************************************************
	**����������¼���������
	*
	**���룺
	*		p_nRuleType ��RECORD_RULE_TYPE_ALWAYS��ʾ7*24Сʱ¼��
	*					  RECORD_RULE_TYPE_SCHEDULE��ʾ�ƻ�¼��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		����¼���������
	************************************************************************/
	void setScheduleRecordType(const int p_nScheduleRecordType);

	/************************************************************************
	**��������ȡ¼���������
	*
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		¼��������ͣ� RECORD_RULE_TYPE_ALWAYS��ʾ7*24Сʱ¼��
	*					  RECORD_RULE_TYPE_SCHEDULE��ʾ�ƻ�¼��
	**���ܣ�       
	*		��ȡ¼���������
	************************************************************************/
	const  int getScheduleRecordType() const;


	/************************************************************************
	**���������üƻ�¼��ʱ�������������Ϊ¼�����Ϊ�ƻ�¼��ʱ��ͨ���˷�������
	*		�ƻ�¼�����
	*
	**���룺
	*		p_objScheduleTimeParam ���ƻ�¼��ʱ�����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setScheduleTimeParam(const ScheduleTimeParam &p_objScheduleTimeParam);

	/************************************************************************
	**��������ȡ�ƻ�¼��ʱ�������������Ϊ¼�����Ϊ�ƻ�¼��ʱ��ͨ���˷�����ȡ
	*		�ƻ�¼�����
	*
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�ƻ�¼��ʱ�����
	**���ܣ�       
	*		
	************************************************************************/
	const ScheduleTimeParam& getScheduleTimeParam() const;


	/************************************************************************
	**�����������Ƿ�¼����Ƶ
	*
	**���룺
	*		p_bIsRecordAudio��¼����Ƶ��־��true��ʾ¼����Ƶ��false��ʾ��¼����Ƶ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setEnableRecordAudio(const bool p_bIsRecordAudio);

	/************************************************************************
	**��������ȡ�Ƿ�¼����Ƶ
	*
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		¼����Ƶ��־��true��ʾ¼����Ƶ��false��ʾ��¼����Ƶ
	**���ܣ�       
	*		
	************************************************************************/
	const bool getEnableRecordAudio() const ;


	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objScheduleRecordParam���ƻ�¼�Ʋ�������
	**�����
	*		��
	**����ֵ��
	*		��ֵ��ļƻ�¼�Ʋ�������
	**���ܣ�
	*		
	*****************************************************************************/
	ScheduleRecordParam & operator =(const ScheduleRecordParam &p_objScheduleRecordParam);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objScheduleRecordParam��ScheduleRecordParam���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true �����
	*		false�������
	**���ܣ�
	*		����ScheduleRecordParam��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const ScheduleRecordParam &p_objScheduleRecordParam) const;

	bool operator < (const ScheduleRecordParam &p_objScheduleRecordParam) const;

private:
	char						m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];		//�豸ID

	int							m_nCameraId;									//�����ID��

	bool						m_bIsEnableRecord;								//����¼���־ false:�ر�¼��true����¼��

	int							m_nScheduleRecordType;							//¼���������

	ScheduleTimeParam			m_objScheduleTimeParam;							//�ƻ�¼��ʱ��

	bool						m_bIsEnableRecordAudio;							//�Ƿ�¼����Ƶ
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_SCHEDULERECORDPARAM_H_
