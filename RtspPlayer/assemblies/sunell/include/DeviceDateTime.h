#ifndef _DEVICEDATETIME_H_
#define _DEVICEDATETIME_H_

#include "DomainConst.h"
#include "SNPlatOS.h"

#ifndef byte
typedef unsigned char byte;
#endif

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

class SN_DLL_API DeviceDateTime
{
public:
	DeviceDateTime(void);
	~DeviceDateTime(void);

	DeviceDateTime(const DeviceDateTime& p_objDeviceDateTime);

public:
	/****************************************************************************
	����������DVR�豸���豸ID
	���룺
	p_pszDeviceId ���ַ�������󳤶�ΪCONST_MAXLENGTH_DEVICEID�ֽ�,
	��β�ԡ�\0��������
	�����
	��
	����ֵ��
	true�� �ɹ�
	false��ʧ�� 
	���ܣ�
	������p_pszDeviceId����<=CONST_MAXLENGTH_DEVICEID������true��
	�����浽m_szDeviceId;
	������p_pszDeviceIdΪNULL���䳤��>CONST_MAXLENGTH_DEVICEID������false
	*****************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/****************************************************************************
	��������ȡDVR�豸���豸ID
	���룺
	��
	�����
	��
	����ֵ��
	���ر���DVR�豸ID��m_szDeviceId�ַ���ָ�롣 
	���ܣ�
	��ȡ������DVR�豸ID���ַ���ָ��
	*****************************************************************************/
	const char* getDeviceId() const;

	void setTimeZone(const int p_nTimeZone);
	const int getTimeZone() const;

	void setDataFormat(const int p_nDataFormat);
	const int getDataFormat() const;

	void setTimeFormat(const int p_nTimeFormat);
	const int getTimeFormat() const;

	void setDTSOpenFlag(const byte p_bDTSOpenFlag);
	const byte getDTSOpenFlag() const;

	void setBeginXun(const int p_nszBeginXun);
	const int getBeginXun() const;

	void setBeginMonth(const int p_nBeginMonth);
	const int getBeginMonth() const;

	void setBeginWeekly(const int p_nBeginWeekly);
	const int getBeginWeekly() const;

	void setBeginWeekDays(const int p_nBeginWeekDays);
	const int getBeginWeekDays() const;

	bool setBeginTime(const char* p_pszBeginTime);
	const char* getBeginTime() const;

	void  setEndXun(const int p_nEndXun);
	const int getEndXun() const;

	void setEndMonth(const int p_nEndMonth);
	const int getEndMonth() const;

	void setEndWeekly(const int p_nEndWeekly);
	const int getEndWeekly() const;

	void setEndWeekDays(const int p_nEndWeekDays);
	const int getEndWeekDays() const;

	bool setEndTime(const char* p_pszEndTime);
	const char* getEndTime() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objDeviceDateTime���豸����������Ϣ
	**�����
	*		��
	**����ֵ��
	*		�豸����������Ϣ
	**���ܣ�
	************************************************************************/
	DeviceDateTime& operator =(const DeviceDateTime& p_objDeviceDateTime);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objDeviceDateTime��DeviceDateTime���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����DeviceDateTime��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const DeviceDateTime& p_objDeviceDateTime);

private:
	
	char		m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];						//DVR�豸���豸ID

	int			m_nTimeZone;												//ʱ��
	int			m_nDataFormat;												//���ڸ�ʽ
	int			m_nTimeFormat;												//ʱ���ʽ

	byte		m_bDTSOpenFlag;											//����ʱ������־

	int			m_nBeginXun;												//����ʱ��ʼ��һ���е�������Ѯ��
	int			m_nBeginMonth;												//����ʱ��ʼ�·�
	int			m_nBeginWeekly;												//����ʱ��ʼ�ܣ�һ���еĵڼ��ܣ�
	int			m_nBeginWeekDays;											//���ڼ�
	char		m_szBeginTime[CONST_MAXLENGTH_TIME + 1];						//����ʱ��ʼʱ��

	int			m_nEndXun;													//����ʱ������һ���е�������Ѯ��
	int			m_nEndMonth;												//����ʱ�����·�
	int			m_nEndWeekly;												//����ʱ�����ܣ�һ���еĵڼ��ܣ�
	int			m_nEndWeekDays;												//���ڼ�
	char		m_szEndTime[CONST_MAXLENGTH_TIME + 1];							//����ʱ����ʱ��
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DEVICEDATETIME_H_
