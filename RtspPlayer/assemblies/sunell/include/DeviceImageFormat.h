#ifndef _DEVICEIMAGEFORMAT_H_
#define _DEVICEIMAGEFORMAT_H_

#include "DomainConst.h"

#include <string.h>
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

class SN_DLL_API DeviceImageFormat
{

public:
	DeviceImageFormat();
	~DeviceImageFormat();

	DeviceImageFormat(const DeviceImageFormat& p_objDeviceImageFormat);

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
	*		true ���ɹ�
	*		false��ʧ�� 
	**���ܣ�
	*		������p_pszDeviceId����<=CONST_MAXLENGTH_DEVICEID������true��
	*		�����浽m_szDeviceId;
	*		������p_pszDeviceIdΪNULL���䳤��>CONST_MAXLENGTH_DEVICEID������false
	************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸���豸ID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������Ƶ�豸���豸ID�� 
	**���ܣ�
	*	��ȡ������DVR�豸ID���ַ���ָ��
	*************************************************************************/
	const char* getDeviceId() const;

	/************************************************************************
	**������
	*		��������ͷID��
    **���룺
	*		p_nCameraId ������ͷ��ID��
	**�����
	*		��
	*����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**������
	*		��ȡ����ͷ��ID��
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ͷ��ID��
	**���ܣ�
	*    
	************************************************************************/
	const int getCameraId() const;

	/************************************************************************
	**������
	*		����ͼ���ʽID
	**���룺
	*		p_nImageFormatId ��Ҫ���õ�ͼ���ʽID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setImageFormatId(const int p_nImageFormatId);

	/************************************************************************
	*������
	*		��ȡͼ���ʽid
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		ͼ���ʽId
	*���ܣ�       
	*************************************************************************/
	const int getImageFormatId() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objDeviceImageFormat����̨Ԥ�Ƶ�
	**�����
	*		��
	**����ֵ��
	*		��̨Ԥ�Ƶ�
	**���ܣ�
	************************************************************************/
	DeviceImageFormat& operator =(const DeviceImageFormat& p_objDeviceImageFormat);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objDeviceImageFormat��DeviceImageFormat���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����DeviceImageFormat��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const DeviceImageFormat& p_objDeviceImageFormat);

private:

	char		m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//�豸ID

	int			m_nCameraId;											//����ͷID��
	
	int			m_nImageFormatId;										//ͼ���ʽid
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DEVICEIMAGEFORMAT_H_

