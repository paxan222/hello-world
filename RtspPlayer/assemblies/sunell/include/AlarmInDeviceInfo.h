#ifndef _ALARMINDEVICEINFO_H_
#define _ALARMINDEVICEINFO_H_

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

class SN_DLL_API AlarmInDeviceInfo
{
public:
	AlarmInDeviceInfo();

	~AlarmInDeviceInfo();

	//�������캯��
	AlarmInDeviceInfo(const AlarmInDeviceInfo &p_objAlarmInDeviceInfo);
public:

	/************************************************************************
	**������
	*		����������Ƶ�豸��������ID��
    **���룺
	*	  p_nAlarmInputId ����������ID��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*       
	************************************************************************/
	void setAlarmInId(int p_nAlarmInputId);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸��������ID��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��������ID��
	**���ܣ�
	*       
	************************************************************************/
	int getAlarmInId() const;

	/****************************************************************************
	**������
	*		���ñ�����������
    **���룺
	*		p_pszAlarmInName �������������ƣ��ַ�������󳤶�ΪCONST_MAXLENGTH_ALARMINPUTNAME�ֽ�,
	*		��β�ԡ�\0��������
	**�����
	*		��
	**����ֵ��
	*		true �� �ɹ�
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
	*		��ȡ������������
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�����������ơ� 
	**���ܣ�
	* 	
	*****************************************************************************/
	const char* getAlarmInName() const;

	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objAlarmInDeviceInfo�����������豸����
	**�����
	*		��
	**����ֵ��
	*		��ֵ��ı��������豸���� 
	** ���ܣ�
	*
	*****************************************************************************/
	AlarmInDeviceInfo& operator = (const AlarmInDeviceInfo &p_objAlarmInDeviceInfo);

private:
	
	int			m_nAlarmInputId;											//��������ID

	char		m_szAlarmInputName[CONST_MAXLENGTH_ALARMINPUTNAME + 1];		//������������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_ALARMINDEVICE_H_


