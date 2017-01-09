#ifndef _ALARMINDEVICE_H_
#define _ALARMINDEVICE_H_

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

class SN_DLL_API AlarmInDevice
{
public:
	AlarmInDevice();

	~AlarmInDevice();

	AlarmInDevice(const AlarmInDevice& p_objAlarmInDevice);
public:

	/************************************************************************
	**������
	*		����������Ƶ�豸��������ID��
    **���룺
	*		  p_nAlarmInId ��������Ƶ�豸��������ID��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*      
	************************************************************************/
	void setAlarmInId(int p_nAlarmInId);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸�豸��������ID��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������Ƶ�豸��������ID��
	**���ܣ�
	*      
	**************************************************************************/
	int getAlarmInId() const;

	/****************************************************************************
	**������
	*		����������Ƶ�豸������������
    **���룺
	*		p_pszAlarmInputName ���ַ�������󳤶�ΪCONST_MAXLENGTH_ALARMINPUTNAME�ֽ�,
	*		��β�ԡ�\0��������
	**�����
	*		��
	**����ֵ��
	*		true�� �ɹ�
	* 		false��ʧ�� 
	**���ܣ�
	*		������p_pszAlarmInputName����<=CONST_MAXLENGTH_ALARMINPUTNAME������true��
	*		�����浽m_szAlarmInputName;
	*		������p_pszAlarmInputNameΪNULL���䳤��>CONST_MAXLENGTH_ALARMINPUTNAME��
	*		����false
	*****************************************************************************/
	bool setAlarmInName(const char* p_pszAlarmInName);

	/****************************************************************************
	**������
	*		��ȡ������Ƶ�豸������������
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������������
	**���ܣ�
	* 		
	*******************************************************************************/
	const char* getAlarmInName() const;

	/************************************************************************
	**������
	*		���ñ���������Ч��ƽ
	**���룺
	*		p_nValidLevel������������Ч��ƽ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	**************************************************************************/
	void setAlarmInValidLevel(int p_nAlarmInValidLevel);


	/************************************************************************
	**������
	*		��ȡ����������Ч��ƽ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����������Ч��ƽ
	**���ܣ�
	*		
	**************************************************************************/
	int getAlarmInValidLevel() const;

	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		true����ֵ�ɹ� 
	*		true����ֵʧ�� 
	**���ܣ�
	*		����ֵ�������ɹ�������true
	*		����ֵ�������ʧ�ܣ�����false
	*****************************************************************************/
	AlarmInDevice& operator =(const AlarmInDevice& p_objAlarmInDevice);

	bool operator == (const AlarmInDevice& p_objAlarmInDevice) const;
	
	bool operator < (const AlarmInDevice& p_objAlarmInDevice) const;

private:
	
	int m_nAlarmInId;												//��������ID��

	char m_szAlarmInputName[CONST_MAXLENGTH_ALARMINPUTNAME + 1];	//������������

	int m_nAlarmInValidLevel;										//�����������Ч��ƽ
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_ALARMINDEVICE_H_


