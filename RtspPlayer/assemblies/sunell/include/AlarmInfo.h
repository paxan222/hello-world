#ifndef _ALARMINFO_H_
#define _ALARMINFO_H_

#include "AlarmData.h"
#include "const.h"
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

class SN_DLL_API AlarmInfo
{
public:
	AlarmInfo(void);
	~AlarmInfo(void);

	AlarmInfo (const AlarmInfo &p_objAlarmInfo);

public:
	/****************************************************************************
	**������
	*		����������Ƶ�豸��Ψһ��ʶ��
	**���룺
	*		p_pszDeviceId ��������Ƶ�豸��Ψһ��ʶ�����ַ�������󳤶�ΪCONST_MAXLENGTH_DEVICEID�ֽ�,
	*						��β�ԡ�\0��������
	**�����
	*		��
	**����ֵ��
	*		true�� �ɹ�
	*		false��ʧ�� 
	**���ܣ�
	*		������p_pszDeviceId����<=CONST_MAXLENGTH_DEVICEID������true.
	*		������p_pszDeviceIdΪNULL���䳤��>CONST_MAXLENGTH_DEVICEID������false.
	*****************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/****************************************************************************
	**������
	*		��ȡ�����豸��Ψһ��ʶ��
	**���룺
	*		��
	**�����
	*		��
	*����ֵ��
	*		�����豸��Ψһ��ʶ�����ַ������� 
	**���ܣ�
	*		
	*****************************************************************************/
	const char* getDeviceId() const;

	/************************************************************************
	**������
	*		����������Ƶ�豸���豸����
	**���룺
	*		p_nDeviceType ��������Ƶ�豸���豸����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	void setDeviceType(const int p_nDeviceType);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸���豸����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������Ƶ�豸���豸����
	**���ܣ�
	*
	************************************************************************/
	const int getDeviceType() const;

	/************************************************************************
	**������
	*		����������Ƶ�豸������IP��ַ
	**���룺
	*		p_pszDeviceIp ��������Ƶ�豸������IP��ַ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	bool setDeviceIp(const char * p_pszDeviceIp);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸������IP��ַ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������Ƶ�豸������IP��ַ
	**���ܣ�
	*
	************************************************************************/
	const char * getDeviceIp() const;

	/************************************************************************
	**������
	*		���ñ�������
	**���룺
	*		p_objAlarmData ����������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	void setAlarmData(const AlarmData& p_objAlarmData);
	
	/************************************************************************
	**������
	*		��ȡ��������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��������
	**���ܣ�
	*
	************************************************************************/
	const AlarmData& getAlarmData() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objAlarmInfo ��������Ϣ����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	AlarmInfo& operator = (const AlarmInfo &p_objAlarmInfo);

private:
	char			m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//�豸id

	int				m_nDeviceType;											//�豸����

	char			m_szDeviceIp[CONST_MAXLENGTH_IP + 1];						//�豸IP��ַ
	
	AlarmData		m_objAlarmData;											//��������
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_ALARMINFO_H_