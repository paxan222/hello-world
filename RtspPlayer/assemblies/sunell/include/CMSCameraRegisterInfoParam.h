#ifndef _CMSCAMERAREGISTERINFOPARAM_H_
#define _CMSCAMERAREGISTERINFOPARAM_H_

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

class SN_DLL_API CMSCameraRegisterInfoParam
{
public:
	CMSCameraRegisterInfoParam();

	~CMSCameraRegisterInfoParam();
	
	CMSCameraRegisterInfoParam(const CMSCameraRegisterInfoParam &p_objCameraRegisterInfoParam);

public:

	//����ͨ����
	void setCameraID(const int p_nCameraID);
	//��ȡͨ����
	const int getCameraID() const;

	/****************************************************************************
	**������
	*		����ͨ��ע��ID
    **���룺
	*	p_pszCameraRegisterID ���ַ�������󳤶�ΪCONST_MAXLENGTH_CAMERA_REGISTER_ID�ֽ�,
	*	��β�ԡ�\0��������
	**�����
	*	��
	**����ֵ��
	*	true�� �ɹ�
	*	false��ʧ�� 
	**���ܣ�
	*	������p_pszCameraRegisterID����<=CONST_MAXLENGTH_CAMERA_REGISTER_ID������true��
	*	�����浽m_szCameraRegisterID;
	*	������p_pszCameraRegisterID����>CONST_MAXLENGTH_CAMERA_REGISTER_ID������false
	*****************************************************************************/	
	bool setCameraRegisterID(const char *p_pszCameraRegisterID);

	/****************************************************************************
	**������
	*		��ȡͨ��ע��ID
    **���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	���ر���ͨ��ע��ID��m_szCameraRegisterID�ַ���ָ�롣 
	*���ܣ�
	*	��ȡ������ͨ��ע��ID���ַ���ָ��
	*****************************************************************************/
	const char *getCameraRegisterID() const;


	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*****************************************************************************/
	CMSCameraRegisterInfoParam &operator =(const CMSCameraRegisterInfoParam &p_objCameraRegisterInfoParam);

private:

	int				m_nCameraID;													//ͨ����

	char			m_szCameraRegisterID[CONST_MAXLENGTH_CAMERA_REGISTER_ID + 1];	//ͨ��ע��ID
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSCAMERAREGISTERINFOPARAM_H_
