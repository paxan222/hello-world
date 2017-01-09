#ifndef  _COMMUNICATION_SECURITY_PARAM_H
#define  _COMMUNICATION_SECURITY_PARAM_H

#include "SNPlatOS.h"
#include "DomainConst.h"

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


class SN_DLL_API CommunicationSecurityParam
{

public:
	enum	SN_WEBMODE
	{
		WEBMODE_HTTP = 1,
		WEBMODE_HTTP_HTTPS = 2,
		WEBMODE_HTTPS =3
	};
public:

	CommunicationSecurityParam(void);
	~CommunicationSecurityParam(void);

	/*************************************************************
	*	����������Web�˵�½��������Ƶ�豸ģʽ
	*	���룺
	*		p_nWebMode:Web�˵�½��������Ƶ�豸��½ģʽ
	*	�����
	*		��
	*	����ֵ��
	*		��
	*	��ע��
	*		 WebMode��1 http��2 https��http��3 https
	**************************************************************/
	void setWebMode(const int& p_nWebMode);

	/*************************************************************
	*	��������ȡWeb�˵�½��������Ƶ�豸��½ģʽ
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		Web�˵�½��������Ƶ�豸��½ģʽ
	*	��ע��
	*		 WebMode��1 http��2 https��http��3 https
	**************************************************************/
	const int& getWebMode()const;

	/*************************************************************
	*	����������Web������������Ƶ�豸ͨѶ�Ƿ���ܱ�־
	*	���룺
	*		p_bCommunicationEncryptFlag�����ܱ�־
	*	�����
	*		��
	*	����ֵ��
	*		��
	*	��ע��
	*		true�� ����
	*		flase��������
	**************************************************************/
	void setCommunicationEncryptFlag(const bool& p_bCommunicationEncryptFlag);

	/*************************************************************
	*	��������ȡWeb������������Ƶ�豸ͨѶ�Ƿ���ܱ�־
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		����ܱ�־
	*	��ע��
	*		true�� ����
	*		flase��������
	**************************************************************/
	const bool& getCommunicationEncryptFlag()const;

	CommunicationSecurityParam& operator=(const CommunicationSecurityParam& p_objCommunicationSecurityParam);

private:
	int m_nWebMode; //Ĭ��ֵΪ0����ʵ�ʲ��Ϸ�   WebMode��1 http��2 https��http��3 https

	bool m_bCommunicationEncryptFlag;//Ĭ��ֵΪfalse

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif  //_COMMUNICATION_SECURITY_PARAM_H