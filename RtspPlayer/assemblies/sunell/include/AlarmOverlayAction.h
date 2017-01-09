#ifndef _ALARMOVERLAYACTION_H_
#define _ALARMOVERLAYACTION_H_

#include "DomainConst.h"
#include "OSDInfo.h"
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

class SN_DLL_API AlarmOverlayAction
{
public:
	AlarmOverlayAction();
	~AlarmOverlayAction();

	//�������캯��
	AlarmOverlayAction(const AlarmOverlayAction &p_objAlarmOverlayAction);

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
	*		false��ʧ�� 
	**���ܣ�
	*		������p_pszDeviceId����<=CONST_MAXLENGTH_DEVICEID������true��
	*		�����浽m_szDeviceId;
	*		������p_pszDeviceIdΪNULL���䳤��>CONST_MAXLENGTH_DEVICEID������false
	**************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸���豸ID
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


	/****************************************************************************
	**������
	*	�����������Id��
    **���룺
	*		p_nCamaraId���������Id��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	*****************************************************************************/
	void setCameraId(int p_nCamaraId);

	/****************************************************************************
	**������
	*		��������ID��
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�����ID��
	**���ܣ�
	*	
	*****************************************************************************/
	const int getCameraId() const;


	/****************************************************************************
	**������
	*		����OSD��Ϣ
    **���룺
	*		p_objOSDInfo��OSDInfo���һ����������ã�������ֻ����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	*****************************************************************************/
	void setOSDInfo(const OSDInfo& p_objOSDInfo);

	/****************************************************************************
	**������
	*		���OSD��Ϣ
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		OSD��Ϣ
	**���ܣ�
	*	
	*****************************************************************************/
	const OSDInfo& getOSDInfo() const ;


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
	const int getEventTypeId() const;


	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objAlarmOverlayAction������ˮӡ��Ϊ����
	**�����
	*		��
	**����ֵ��
	*		��ֵ��ı���ˮӡ��Ϊ����
	**���ܣ�
	*		
	*****************************************************************************/
	AlarmOverlayAction& operator = (const AlarmOverlayAction& p_objAlarmOverlayAction);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objAlarmOverlayAction��AlarmOverlayAction���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true �����
	*		false�������
	**���ܣ�
	*		����AlarmOverlayAction��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const AlarmOverlayAction& p_objAlarmOverlayAction) const;

	bool operator < (const AlarmOverlayAction& p_objAlarmOverlayAction) const;

private:
	
	int			m_nEventTypeId;									//�����¼�����

	char		m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];		//�豸ID
	
	int			m_nCameraId;									//�����ID��
	
	OSDInfo		m_objOSDInfo;									//ˮӡ��Ϣ
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_ALARMOVERLAYACTION_H_


