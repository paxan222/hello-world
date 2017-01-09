#ifndef _AVSTREAMMULTICASTADDR_H_
#define _AVSTREAMMULTICASTADDR_H_

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

class SN_DLL_API AVStreamMulticastAddr
{
public:
	AVStreamMulticastAddr(void);
	~AVStreamMulticastAddr(void);

	AVStreamMulticastAddr(const AVStreamMulticastAddr &p_RecordInfo);

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

	/************************************************************************
	**������
	*		�����豸ͨ����
	**���룺
	*		p_nCameraId	�豸ͨ����
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setCameraId(int p_nCameraId);

	/************************************************************************
	**������
	*		��ȡ�豸ͨ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸ͨ����
	************************************************************************/
	const int getCameraId() const;

	bool setMulticastIP(const char * p_pszMulticastIP);
	const char * getMulticastIP() const;

	void setMulticastProt(int p_nMulticastProt);
	const int getMuticastProt() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objRecordInfo ��¼����Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	AVStreamMulticastAddr& operator = (const AVStreamMulticastAddr& p_objRecordInfo);

private:
	char				m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];					//�豸id
	int					m_nCameraId;												//�豸ͨ����
	char				m_szMulticastIP[CONST_MAXLENGTH_IP + 1];
	int					m_nMulticastProt;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_AVStreamMulticastAddr_H_
