#ifndef _ALARMOUTACTION_H_
#define _ALARMOUTACTION_H_

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

class SN_DLL_API AlarmOutAction
{
public:
	enum
	{
		ALARMOUTFLAG_START		= 1,		//������Ч��־λ����ʼ����
		ALARMOUTFLAG_STOP		= 0			//������Ч��־λ��ֹͣ����
	};
public:

	AlarmOutAction();

	~AlarmOutAction();

	//�������캯��
	AlarmOutAction(const AlarmOutAction& p_objAlarmOutAction);

public:	
	/***********************************************************************
	**������
	*		����������Ƶ�豸���豸ID
    **���룺
	*		p_pszDeviceId ���ַ�������󳤶�ΪCONST_MAXLENGTH_DEVICEID�ֽ�,
	*		��β�ԡ�\0��������
	**�����
	*		��
	**����ֵ��
	*		true �� �ɹ�
	* 		false��ʧ�� 
	**���ܣ�
	*		������p_pszDeviceId����<=CONST_MAXLENGTH_DEVICEID������true��
	*		�����浽m_szDeviceId;
	*		������p_pszDeviceIdΪNULL���䳤��>CONST_MAXLENGTH_DEVICEID������false
	*************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);


	/************************************************************************
	**������
	*		��ȡDVR�豸���豸ID
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���ر���DVR�豸ID��m_szDeviceId�ַ���ָ�롣 
	**���ܣ�
	* 		
	*************************************************************************/
	const char* getDeviceId() const;


	/************************************************************************
	**������
	*		���ñ������ID��
	**���룺
	*		p_nAlarmOutId ���������ID��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	* 	  
	************************************************************************/
	void setAlarmOutId(const int p_nAlarmOutId);

	/************************************************************************
	**������
	*		��ȡ�������ID��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��������˿ڵ�ID��
	**���ܣ�
	* 	  
	************************************************************************/
	const int getAlarmOutId() const;


	/************************************************************************
	**������
	*		���ñ�����־
	**���룺
	*		p_nAlarmFlag ��Ҫ���õı�����־λ
	*		ALARMFLAG_START		��ʼ����
	*		ALARMFLAG_STOP		ֹͣ����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*
	************************************************************************/
	void setAlarmOutFlag(const int p_nAlarmFlag);

	/************************************************************************
	*������
	*		��ȡ������־
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		������־
	*���ܣ�       
	*
	*************************************************************************/
	const int getAlarmOutFlag() const;


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
	void setEventTypeId(const int p_nEventTypeId);

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
	const int getEventTypeId() const;


	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objAlarmOutAction�����������Ϊ����
	**�����
	*		��
	**����ֵ��
	*		��ֵ��ı��������Ϊ����
	**���ܣ�
	*		
	*****************************************************************************/
	AlarmOutAction& operator = (const AlarmOutAction& p_objAlarmOutAction);

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
	bool operator == (const AlarmOutAction& p_objAlarmOutAction) const;

	bool operator < (const AlarmOutAction& p_objAlarmOutAction) const;

private:
	
	char	m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];	//�豸id
	
	int		m_nAlarmOutId;								//��������˿ڵ�ID��	
	
	int		m_nAlarmOutFlag;							//���������־
	
	int		m_nEventTypeId;								//�����¼�����


}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_ALARMOUTACTION_H_

