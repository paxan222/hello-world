#ifndef _ALARMRECORDACTION_H_
#define _ALARMRECORDACTION_H_

#include "DomainConst.h"
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

class SN_DLL_API AlarmRecordAction
{
public:

	AlarmRecordAction();
	~AlarmRecordAction();

	//�������캯��
	AlarmRecordAction(const AlarmRecordAction &p_objAlarmRecordAction);

public:	
	/************************************************************************
	*������
	*		����������Ƶ�豸���豸ID
    *���룺
	*		p_pszDeviceId ���ַ�������󳤶�ΪCONST_MAXLENGTH_DEVICEID�ֽ�,
	*		��β�ԡ�\0��������
	*�����
	*		��
	*����ֵ��
	*		true �� �ɹ�
	*		false��ʧ�� 
	*���ܣ�
	*		������p_pszDeviceId����<=CONST_MAXLENGTH_DEVICEID������true��
	*		�����浽m_szDeviceId;
	*		������p_pszDeviceIdΪNULL���䳤��>CONST_MAXLENGTH_DEVICEID������false
	*************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);
	
	/************************************************************************
	**������
	*		��ȡ�����豸���豸ID
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������Ƶ�豸���豸ID
	**���ܣ�
	* 	
	*************************************************************************/
	const char* getDeviceId() const;
	

	/************************************************************************
	**������
	*		�����������ID��
	**���룺
	*		p_nCameraId : �������ID��
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
	*		��ȡ�������ID��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ID��
	**���ܣ�
	*       
	************************************************************************/
	int getCameraId() const;
	
	
	/************************************************************************
	**������
	*		����Ԥ¼ʱ��
	**���룺
	*		p_nPreRecordTime �� Ԥ¼ʱ��������Ϊ��λ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*       
	************************************************************************/
	void setPreRecordTime(int p_nPreRecordTime);
		
	/************************************************************************
	**������
	*		��ȡԤ¼ʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		Ԥ¼ʱ��������Ϊ��λ��
	**���ܣ�
	*       
	************************************************************************/
	int getPreRecordTime() const;
	
	
	/************************************************************************
	**������
	*		����¼��ʱ��
	**���룺
	*		p_nRecordTime ��¼��ʱ��������Ϊ��λ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*       
	************************************************************************/
	void setRecordTime(int p_nRecordTime);
	
	/************************************************************************
	**������
	*		��ȡ¼��ʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		¼��ʱ��������Ϊ��λ��
	**���ܣ�
	*       
	************************************************************************/
	int getRecordTime() const;


	/************************************************************************
	**������
	*		���ñ����¼�����
	**���룺
	*		p_nEventTypeId �������¼�����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	* 
	************************************************************************/
	void setEventTypeId(int p_nEventTypeId);

	/************************************************************************
	**������
	*		��ȡ�����¼�����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�����¼�����
	**���ܣ�
	* 
	************************************************************************/
	int getEventTypeId() const;


	/************************************************************************
	**������
	*		�����Ƿ�¼����Ƶ
	**���룺
	*		p_bIsRecordAudio��¼����Ƶ�ı�־��true��ʾ¼����Ƶ��false��ʾ��¼����Ƶ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setEnableRecordAudio(const bool p_bIsRecordAudio);

	/************************************************************************
	**������
	*		��ȡ�Ƿ�¼����Ƶ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		¼����Ƶ�ı�־��true��ʾ¼����Ƶ��false��ʾ��¼����Ƶ
	**���ܣ�       
	*		
	************************************************************************/
	const bool getEnableRecordAudio() const ;


	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objAlarmRecordAction������¼����Ϊ����
	**�����
	*		��
	**����ֵ��
	*		��ֵ��ı���¼����Ϊ����
	**���ܣ�
	*		
	*****************************************************************************/
	AlarmRecordAction& operator = (const AlarmRecordAction& p_objAlarmRecordAction);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objAlarmOutAction��AlarmOutAction���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true �����
	*		false�������
	**���ܣ�
	*		����AlarmOutAction��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const AlarmRecordAction& p_objAlarmRecordAction) const;

	bool operator < (const AlarmRecordAction& p_objAlarmRecordAction) const;

private:
   
	char	m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];			//�豸ID

	int		m_nCameraId;										//�������ID��

	int		m_nPreRecordTime;									//Ԥ¼ʱ��

	int		m_nRecordTime;										//¼��ʱ��

	int		m_nEventTypeId;										//�����¼�����

	bool	m_bIsEnableRecordAudio;								//�Ƿ�¼����Ƶ
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_ALARMRECORDACTION_H_