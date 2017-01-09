#ifndef _I3GMESSAGECONNECTPOLICYPARAM_H_
#define _I3GMESSAGECONNECTPOLICYPARAM_H_

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

class SN_DLL_API I3GMessageConnectPolicyParam
{
public:
	I3GMessageConnectPolicyParam(void);
	~I3GMessageConnectPolicyParam(void);

public:
	
	/************************************************************************
	**������
	*		�������ñ�־
	**���룺
	*		p_bEnableFlag:���ñ�־
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setEnableFlag(const bool p_bEnableFlag);

	/************************************************************************
	**������
	*		��ȡ���ñ�־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		
	************************************************************************/
	const bool getEnableFlag() const;

	/************************************************************************
	*	����������������Ϣ�绰����
	*	���룺
	*		p_pszConnectMessagePhoneNO:������Ϣ�绰����
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	bool setConnectMessagePhoneNO(const char* p_pszConnectMessagePhoneNO);

	/************************************************************************
	*	��������ȡ������Ϣ�绰����
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		������Ϣ�绰����
	************************************************************************/
	const char* getConnectMessagePhoneNO() const ;


	/************************************************************************
	*	����������������Ϣ����
	*	���룺
	*		p_pszConnectMessageContent:������Ϣ����
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	bool setConnectMessageContent(const char* p_pszConnectMessageContent);

	/************************************************************************
	*	��������ȡ������Ϣ����
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		
	************************************************************************/
	const char* getConnectMessageContent() const ;


	/************************************************************************
	**������
	*		���öϿ�������Ϣ�绰����
	**���룺
	*		p_pszDisconnectMessagePhoneNO ���Ͽ�������Ϣ�绰����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	bool setDisconnectMessagePhoneNO(const char * p_pszDisconnectMessagePhoneNO);

	/************************************************************************
	**������
	*		��ȡ�Ͽ�������Ϣ�绰����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�Ͽ�������Ϣ�绰����
	**���ܣ�
	*
	************************************************************************/
	const char * getDisconnectMessagePhoneNO() const;

	/************************************************************************
	**������
	*		���öϿ�������Ϣ����
	**���룺
	*		p_pszDisconnectMessageContent ���Ͽ�������Ϣ����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	bool setDisconnectMessageContent(const char* p_pszDisconnectMessageContent);

	/************************************************************************
	**������
	*		��ȡ�Ͽ�������Ϣ����
	**���룺
	*		��
	**�����
	**		��
	**����ֵ��
	*		�Ͽ�������Ϣ����
	**���ܣ�
	*
	************************************************************************/
	const char* getDisconnectMessageContent() const;

private:
	bool			m_bEnableFlag;														//���ñ�־

	char			m_szConnectMessagePhoneNO[CONST_MAXLENGTH_PHONE_NO+1];				//������Ϣ�绰����
	char			m_szConnectMessageContent[CONST_MAXLENGTH_MESSAGE_CONTENT+1];		//������Ϣ�ڴ�
	
	char			m_szDisconnectMessagePhoneNO[CONST_MAXLENGTH_PHONE_NO + 1];			//�Ͽ�������Ϣ�绰����
	char			m_szDisconnectMessageContent[CONST_MAXLENGTH_MESSAGE_CONTENT + 1];	//�Ͽ�������Ϣ�ڴ�

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_I3GMESSAGECONNECTPOLICYPARAM_H_
