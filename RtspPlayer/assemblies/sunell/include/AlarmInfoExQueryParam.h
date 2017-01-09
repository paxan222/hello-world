#ifndef _ALARMINFOEXQUERYPARAM_H_
#define _ALARMINFOEXQUERYPARAM_H_

#include "DomainConst.h"
#include "SNPlatOS.h"
#include "TimeStruct.h"

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

class SN_DLL_API AlarmInfoExQueryParam
{
public:
	AlarmInfoExQueryParam(void);
	
	~AlarmInfoExQueryParam(void);

	AlarmInfoExQueryParam(const AlarmInfoExQueryParam &p_AlarmInfoExQueryParam);

public:
	/***********************************************************************
	**������
	*		�����豸Id��
	**���룺
	*		p_pszDeviceId���豸Id
	**�����
	*		��
	**����ֵ��
	*		true	�����óɹ�
	*		false   ������ʧ��
	**���ܣ�
	************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**������
	*		��ȡ�豸Id
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

	/***********************************************************************
	**������
	*		�����豸IP��ַ���ýӿ��Ѿ�����
	**���룺
	*		p_strDeviceIP���豸IP��ַ
	**�����
	*		��
	**����ֵ��
	*		true	�����óɹ�
	*		false   ������ʧ��
	**���ܣ�
	************************************************************************/
	bool setDeviceIP(const char* p_pszDeviceIP);

	/***********************************************************************
	**������
	*		��ȡ�豸IP��ַ���ýӿ��Ѿ�����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸IP��ַ
	**���ܣ�
	************************************************************************/
	const char* getDeviceIP() const;

	/***********************************************************************
	**������
	*		����ԴID
	**���룺
	*		p_pszSourceId��ԴID
	**�����
	*		��
	**����ֵ��
	*		true	�����óɹ�
	*		false   ������ʧ��
	**���ܣ�
	************************************************************************/
	bool setSourceId(const char* p_pszSourceId);

	/***********************************************************************
	**������
	*		��ȡԴID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ԴID
	**���ܣ�
	************************************************************************/
	const char* getSourceId() const;

	/***********************************************************************
	**������
	*		����Դ����
	**���룺
	*		p_strSourceName��Դ����
	**�����
	*		��
	**����ֵ��
	*		true	�����óɹ�
	*		false   ������ʧ��
	**���ܣ�
	************************************************************************/
	bool setSourceName(const char* p_pszSourceName);

	/***********************************************************************
	**������
	*		��ȡԴ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		Դ����
	**���ܣ�
	************************************************************************/
	const char* getSourceName() const;

	/***********************************************************************
	**������
	*		���ñ���������
	**���룺
	*		p_nMajorType��������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	************************************************************************/
	void  setMajorType(int p_nMajorType);

	/***********************************************************************
	**������
	*		��ȡ����������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����������
	**���ܣ�
	************************************************************************/
	int getMajorType() const;

	/***********************************************************************
	**������
	*		���ñ���������
	**���룺
	*		p_nMinorType��������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	************************************************************************/
	void  setMinorType(int p_nMinorType);

	/***********************************************************************
	**������
	*		��ȡ����������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����������
	**���ܣ�
	************************************************************************/
	int getMinorType() const;

	/***********************************************************************
	**������
	*		���ÿ�ʼʱ��
	**���룺
	*		p_objTimeStruct����ʼʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	************************************************************************/
	void setAlarmBeginTime(unsigned long p_nAlarmBeginTime);
	void setStructAlarmBeginTime(const TimeStruct& p_objTime);

	/***********************************************************************
	**������
	*		��ȡ��ʼʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��ʼʱ��
	**���ܣ�
	************************************************************************/
	const unsigned long getAlarmBeginTime()const;
	const TimeStruct& getStructAlarmBeginTime() const;

	/***********************************************************************
	**������
	*		���ý���ʱ��
	**���룺
	*		p_objTimeStruct������ʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	************************************************************************/
	void setAlarmEndTime(unsigned long p_nAlarmEndTime);
	void setStructAlarmEndTime(const TimeStruct& p_objTime);

	/***********************************************************************
	**������
	*		��ȡ����ʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ʱ��
	**���ܣ�
	************************************************************************/
	const unsigned long getAlarmEndTime() const;
	const TimeStruct& getStructAlarmEndTime() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objAlarmInfoExQueryParam ��������ѯ��Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	AlarmInfoExQueryParam& operator = (const AlarmInfoExQueryParam &p_objAlarmInfoExQueryParam);
	
private:
	char				m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//�豸���
	char				m_szDeviceIP[CONST_MAXLENGTH_IP + 1];					//�豸IP��ַ���˲����Ѿ����������鲻ʹ�ã�
	char				m_szSourceId[CONST_MAXLENGTH_ALARM_SOURCE_ID + 1];		//����ԴId
	char				m_szSourceName[CONST_MAXLENGTH_ALARMSOURCENAME + 1];	//Դ����
	int					m_nMajorType;											//����������
	int					m_nMinorType;											//����������
	unsigned long		m_nAlarmBeginTime;										//��ѯ��ʼʱ��
	TimeStruct			m_objAlarmBeginTime;									//
	unsigned long		m_nAlarmEndTime;										//��ѯ����ʱ��
	TimeStruct			m_objAlarmEndTime;										//
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif

