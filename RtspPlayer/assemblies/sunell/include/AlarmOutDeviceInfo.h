#ifndef _ALARMOUTDEVICEINFO_H_
#define _ALARMOUTDEVICEINFO_H_

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

class SN_DLL_API AlarmOutDeviceInfo
{
public:
	AlarmOutDeviceInfo();

	~AlarmOutDeviceInfo();

public:
	/************************************************************************
	����������DVR�豸�������ID��
    ���룺
		  p_nAlarmOutId ��DVR�豸�������ID��
	�����
		��
	����ֵ��
		��
	���ܣ�
	      ����DVR�豸�������ID��
	************************************************************************/
	void setAlarmOutId(int p_nAlarmOutId);
	
	/************************************************************************
	��������ȡDVR�豸�������ID��
	���룺
		��
	�����
		��
	����ֵ��
		DVR�豸�������ID��
	���ܣ�
	      ��ȡDVR�豸�������ID��
	************************************************************************/
	int getAlarmOutId() const;
	
	/****************************************************************************
	����������DVR�豸�����������
    ���룺
		p_pszAlarmOutName ���ַ�������󳤶�ΪCONST_MAXLENGTH_ALARMOUTPUTNAME�ֽ�,
		��β�ԡ�\0��������
	�����
		��
	����ֵ��
		true�� �ɹ�
		false��ʧ�� 
	���ܣ�
		������p_pszAlarmOutName����<=CONST_MAXLENGTH_ALARMOUTPUTNAME������true��
		�����浽m_szAlarmOutName;
		������p_pszAlarmOutNameΪNULL���䳤��>CONST_MAXLENGTH_ALARMOUTPUTNAME��
		����false
	*****************************************************************************/
	bool setAlarmOutName(const char* p_pszAlarmOutName);
	
	/****************************************************************************
	��������ȡDVR�豸�����������
    ���룺
		��
	�����
		��
	����ֵ��
		���ر���DVR�豸����������ֵ�m_szAlarmOutName�ַ���ָ�롣 
	���ܣ�
		��ȡ������DVR�豸����������ֵ��ַ���ָ��
	*****************************************************************************/
	const char* getAlarmOutName() const;


	AlarmOutDeviceInfo(const AlarmOutDeviceInfo &p_objAlarmOutDeviceInfo);

	AlarmOutDeviceInfo& operator = (const AlarmOutDeviceInfo& p_objAlarmOutDeviceInfo);

private:
	
	int m_nAlarmOutId;

	char m_szAlarmOutName[CONST_MAXLENGTH_ALARMOUTNAME + 1];
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_ALARMOUTDEVICE_H_


