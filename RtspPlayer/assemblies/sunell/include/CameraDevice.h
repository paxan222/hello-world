#ifndef _CAMERADEVICE_H_
#define _CAMERADEVICE_H_

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

class SN_DLL_API CameraDevice
{
public:
	CameraDevice();
	~CameraDevice();

	//�������캯��
	CameraDevice(const CameraDevice &p_objCameraDevice);

public:
	/************************************************************************
	**������
	*		�����������Id��
    **���룺
	*		p_nCameraId ���������Id��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*    �����������Id��
	************************************************************************/
	void setCameraId(const int p_nCameraId);
	
	/************************************************************************
	**������
	*		��ȡ�������Id��
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������Id��
	**���ܣ�
	*     ��ȡ�������Id��
	**************************************************************************/
	const int getCameraId() const ;
	
	/************************************************************************
	**������
	*		���������������
    **���룺,
	*	  p_pszCameraName ������������ƣ��ַ�����
	*	  ��󳤶�ΪCONST_MAXLENGTH_CAMERA_NAME�ֽ�,��β�ԡ�\0�������� 
	**�����
	*	��
	**����ֵ��
	*		true : �ɹ�
	* 		false��ʧ��
	**���ܣ�
	*	   ������p_pszCameraName����<=CONST_MAXLENGTH_CAMERA_NAME������true��
	*		�����浽m_szCameraName;
	*		������p_pszCameraNameΪnull�����䳤��>CONST_MAXLENGTH_CAMERA_NAME��
	*		����false
	************************************************************************/
	bool setCameraName(const char* p_pszCameraName);

	/************************************************************************
	**������
	*		��ȡ�����������
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���������
	**���ܣ�
	*		
	**************************************************************************/
	const char* getCameraName() const;

	/****************************************************************************
	**������
	*		�����������ʽ
    **���룺
	*		p_pszCameraModel ���ַ�������󳤶�ΪCONST_MAXLENGTH_CAMERAMODEL�ֽ�,
	*		��β�ԡ�\0��������
	**�����
	*		��
	**����ֵ��
	*		true�� �ɹ�
	* 		false��ʧ�� 
	**���ܣ�
	*		������p_pszCameraModel����<=CONST_MAXLENGTH_CAMERAMODEL������true��
	*		�����浽m_szCameraModel;
	*		������p_pszCameraModelΪNULL���䳤��>CONST_MAXLENGTH_CAMERAMODEL��
	*		����false
	*****************************************************************************/
	bool setCameraModel(const char* p_pszCameraModel);

	/****************************************************************************
	**������
	*		��ȡ�������ʽ
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���ر����������ʽ��m_szCameraModel�ַ���ָ�롣 
	**���ܣ�
	* 		��ȡ�������������ʽ���ַ���ָ��
	*******************************************************************************/
	const char* getCameraModel() const;

	/************************************************************************
	**������
	*		����ģ����Ƶ��ʽ
    **���룺
	*		p_nAnalogVideo ��ģ����Ƶ��ʽ���������֣� PAL��NTSC��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		����ģ����Ƶ��ʽ
	**************************************************************************/
	void setVideoSystem(const int p_nVideoSystem);

	/************************************************************************
	**������
	*		��ȡģ����Ƶ��ʽ
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ģ����Ƶ��ʽ
	**���ܣ�
	*     ��ȡģ����Ƶ��ʽ
	**************************************************************************/
	const int getVideoSystem() const ;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objCameraDevice ��������豸����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	**************************************************************************/
	CameraDevice& operator = (const CameraDevice& p_objCameraDevice);
	bool operator < (const CameraDevice& p_objCameraDevice) const;

	bool operator == (const CameraDevice& p_objCameraDevice) const;

private:
	
	int				m_nCameraId;										//�������ID��
	
	char			m_szCameraName[CONST_MAXLENGTH_CAMERA_NAME + 1];	//�����������
	
	char			m_szCameraModel[CONST_MAXLENGTH_CAMERAMODEL + 1];	//���������ʽ	
	
	int				m_nVideoSystem;										//��Ƶ��ʽ
		
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CAMERADEVICE_H_
