#ifndef _DEVICETYPE_H_
#define _DEVICETYPE_H_

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

class SN_DLL_API DeviceType
{
public:
	enum 
	{
		IPCAMERA		= 1,	//����������豸
		DVR				= 2,	//������Ƶ¼����豸
		DVS				= 3,	//������Ƶ�������豸
		IPDOME			= 4,	//���������
		NVR				= 5,	//NVR
		ONVIF_DEVICE	= 6,	//Onvif �豸
		DECODER			= 7,	//������
		HK_DVR			= 100,	//HK DVR
		RS_DVR			= 101,	//����DVR
		DH_DVR			= 102,	//��DVR
		VIRTUAL_NVR		= 103   //���ڼ���NVR�ͻ�����ʹ�õı���Server
	};

	DeviceType();
	
	~DeviceType();

	DeviceType(const DeviceType& p_objDeviceType);

public:
	
	/************************************************************************
	**������
	*		�����豸����ID
	**���룺
	*		p_nDeviceTypeId ��Ҫ���õ��豸����ID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setDeviceTypeId(const int p_nDeviceTypeId);

	/************************************************************************
	*������
	*		��ȡ�豸����ID
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		�豸����Id
	*���ܣ�       
	*************************************************************************/
	const int getDeviceTypeId() const;


	/************************************************************************
	**������
	*		�����豸����ID
	**���룺
	*		p_pszDeviceTypeName��Ҫ���õ��豸��������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	bool setDeviceTypeName(const char* p_pszDeviceTypeName);

	/************************************************************************
	*������
	*		��ȡ�豸��������
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		�豸��������
	*���ܣ�       
	*************************************************************************/
	const char* getDeviceTypeName() const;

	/************************************************************************
	*������
	*		��ֵ����
	*���룺
	*		p_objDeviceType��DDNS��Ϣ
	*�����
	*		��
	*����ֵ��
	*		DDNS��Ϣ
	*���ܣ�
	*************************************************************************/
	DeviceType& operator =(const DeviceType& p_objDeviceType);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objDeviceType��DeviceType���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����DeviceType��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const DeviceType& p_objDeviceType);

public:

	/************************************************************************
	**������
	*		�����豸���ͳ�����ȡ�豸���͵�����
	**���룺
	*		p_nType : �豸����
	**�����
	*		p_pszName : �豸����
	**����ֵ��
	*		��
	**���ܣ�
	*		�����豸���ͳ�����ȡ�豸���͵�����
	************************************************************************/
	static void translateDeviceTypeName(const int p_nType, char* p_pszName);


private:

	int			m_nDeviceTypeId;										//�豸����id
	char		m_szDeviceTypeName[CONST_MAXLENGTH_DEVICETYPE_NAME];	//�豸��������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DEVICETYPE_H_
