#ifndef _CMSREGISTERINFOPARAM_H_
#define _CMSREGISTERINFOPARAM_H_

#include "DomainConst.h"
#include "SNPlatOS.h"
#include "CMSRegisterServerParamV2.h"
#include "CMSDeviceRegisterInfoParam.h"
#include "CMSCameraRegisterInfoParam.h"
#include "CMSExternConfigParamV2.h"	
#include <vector>

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

class SN_DLL_API CMSRegisterInfoParam
{
public:
	CMSRegisterInfoParam();

	~CMSRegisterInfoParam();

	CMSRegisterInfoParam(const CMSRegisterInfoParam &p_objCMSRegisterInfoParam);

public:
	/****************************************************************************
	**������
	*		����Э������
	**���룺
	*	p_pszProtocolName ���ַ�������󳤶�ΪCONST_MAXLENTH_PROTOCOL_NAME�ֽ�,
	*	��β�ԡ�\0��������
	**�����
	*	��
	**����ֵ��
	*	true�� �ɹ�
	*	false��ʧ�� 
	**���ܣ�
	*	������p_pszProtocolName����<=CONST_MAXLENTH_PROTOCOL_NAME������true��
	*	�����浽m_szProtocolName;
	*	������p_pszProtocolName����>CONST_MAXLENTH_PROTOCOL_NAME������false
	*****************************************************************************/	
	bool setProtocolName(const char *p_pszProtocolName);

	/****************************************************************************
	**������
	*		��ȡЭ������
	**���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	���ر���Э�����Ƶ�m_szProtocolName�ַ���ָ�롣 
	*���ܣ�
	*	��ȡ������Э�����Ƶ��ַ���ָ��
	*****************************************************************************/
	const char *getProtocolName() const;

	/****************************************************************************
	**������
	*		����Э��汾
	**���룺
	*	p_pszProtocolVersion ���ַ�������󳤶�ΪCONST_MAXLENTH_PROTOCOL_VERSION�ֽ�,
	*	��β�ԡ�\0��������
	**�����
	*	��
	**����ֵ��
	*	true�� �ɹ�
	*	false��ʧ�� 
	**���ܣ�
	*	������p_pszProtocolVersion����<=CONST_MAXLENTH_PROTOCOL_VERSION������true��
	*	�����浽m_szProtocolVersion;
	*	������p_pszProtocolVersion����>CONST_MAXLENTH_PROTOCOL_VERSION������false
	*****************************************************************************/	
	bool setProtocolVersion(const char *p_pszProtocolVersion);

	/****************************************************************************
	**������
	*		��ȡЭ��汾
	**���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	���ر���Э��汾��m_szProtocolVersion�ַ���ָ�롣 
	**���ܣ�
	*	��ȡ������Э��汾���ַ���ָ��
	*****************************************************************************/
	const char *getProtocolVersion() const;

	/****************************************************************************
	**������
	*		����Э������״̬
	**���룺
	*	p_pszDeviceProtocolState ���ַ�������󳤶�ΪCONST_MAXLENGTH_DEVICE_STATUS�ֽ�,
	*	��β�ԡ�\0��������
	**�����
	*	��
	**����ֵ��
	*	true�� �ɹ�
	*	false��ʧ�� 
	**���ܣ�
	*	������p_pszDeviceProtocolState����<=CONST_MAXLENGTH_DEVICE_STATUS������true��
	*	�����浽m_szDeviceProtocolState;
	*	������p_pszDeviceProtocolState����>CONST_MAXLENGTH_DEVICE_STATUS������false
	*****************************************************************************/	
	bool setDeviceProtocolState(const char *p_pszDeviceProtocolState);

	/****************************************************************************
	**������
	*		��ȡЭ������״̬
	**���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	���ر���Э������״̬��m_szDeviceProtocolState�ַ���ָ�롣 
	**���ܣ�
	*	��ȡ������Э������״̬���ַ���ָ��
	*****************************************************************************/
	const char *getDeviceProtocolState() const;

	/****************************************************************************
	**������
	*		����/��ȡCMSע�����������
	**���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	0	���óɹ�
	*	-1  ����ʧ��
	**���ܣ�
	*	����/��ȡCMSע�����������
	*****************************************************************************/
	int setCMSRegisterServerParam(const std::vector<CMSRegisterServerParamV2>& p_objCMSRegisterServerParamList);

	const std::vector<CMSRegisterServerParamV2>& getCMSRegisterServerParam() const;

	/****************************************************************************
	**������
	*		����/��ȡCMS�豸ע�����
	**���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	0	���óɹ�
	*	-1  ����ʧ��
	**���ܣ�
	*	����/��ȡCMS�豸ע�����
	*****************************************************************************/
	int setCMSDeviceRegisterInfoParam(const std::vector<CMSDeviceRegisterInfoParam>& p_objCMSDeviceRegisterInfoParamList);

	const std::vector<CMSDeviceRegisterInfoParam>& getCMSDeviceRegisterInfoParam() const;

	/****************************************************************************
	**������
	*		����/��ȡCMSͨ��ע�����
	**���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	0	���óɹ�
	*	-1  ����ʧ��
	**���ܣ�
	*	����/��ȡCMSͨ��ע�����
	*****************************************************************************/
	int setCMSCameraRegisterInfoParam(const std::vector<CMSCameraRegisterInfoParam>& p_objCMSCameraRegisterInfoParamList);

	const std::vector<CMSCameraRegisterInfoParam>& getCMSCameraRegisterInfoParam() const;

	/****************************************************************************
	**������
	*		����/��ȡCMS��չ���ò���
	**���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	0	���óɹ�
	*	-1  ����ʧ��
	**���ܣ�
	*	����/��ȡCMS��չ���ò���
	*****************************************************************************/
	int setCMSExternConfigParam(const std::vector<CMSExternConfigParamV2>& p_objCMSExternConfigParamList);

	const std::vector<CMSExternConfigParamV2>& getCMSExternConfigParam() const;

	CMSRegisterInfoParam &operator =(const CMSRegisterInfoParam &p_objCMSRegisterInfoParam);
private:
	char			m_szDeviceProtocolState[CONST_MAXLENGTH_DEVICE_STATUS + 1];	
	char			m_szProtocolName[CONST_MAXLENTH_PROTOCOL_NAME + 1];							//Э������
	char			m_szProtocolVersion[CONST_MAXLENTH_PROTOCOL_VERSION + 1];					//Э��汾
	std::vector<CMSRegisterServerParamV2>		m_objCMSRegisterServerParamList;
	std::vector<CMSDeviceRegisterInfoParam> m_objCMSDeviceRegisterInfoParamList;
	std::vector<CMSCameraRegisterInfoParam> m_objCMSCameraRegisterInfoParamList;
	std::vector<CMSExternConfigParamV2>		m_objCMSExternConfigParamList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/


#endif //_CMSPROTOCOLPARAM_H_
