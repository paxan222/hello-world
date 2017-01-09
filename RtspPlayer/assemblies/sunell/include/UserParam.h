#ifndef _USERPARAM_H_
#define _USERPARAM_H_

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

class SN_DLL_API UserParam
{
public:
	UserParam(void);
	~UserParam(void);

	//�������캯��
	UserParam(const UserParam& p_objUserParam);

public:

	/****************************************************************************
	**������
	*		�����û���
	**���룺
	*		p_pszUserName ���û���,��β�ԡ�\0��������
	**�����
	*		��
	**����ֵ��
	*		true�� �ɹ�
	*		false��ʧ�� 
	**���ܣ�
	*		������p_pszUserName����<=CONST_MAXLENGTH_USERNAME������true.
	*		������p_pszUserNameΪNULL���䳤��>CONST_MAXLENGTH_USERNAME������false.
	*****************************************************************************/
	bool setUserName(const char* p_pszUserName);

	/****************************************************************************
	**������
	*		��ȡ�û���
	**���룺
	*		��
	**�����
	*		��
	*����ֵ��
	*		�û������ַ������� 
	**���ܣ�
	*		
	*****************************************************************************/
	const char* getUserName() const;


	/****************************************************************************
	**������
	*		��������
	**���룺
	*		p_pszPassword ������,��β�ԡ�\0��������
	**�����
	*		��
	**����ֵ��
	*		true�� �ɹ�
	*		false��ʧ�� 
	**���ܣ�
	*		������p_pszPassword����<=CONST_MAXLENGTH_USERPASSWORD������true.
	*		������p_pszPasswordΪNULL���䳤��>CONST_MAXLENGTH_USERPASSWORD������false.
	*****************************************************************************/
	bool setPassword(const char* p_pszPassword);

	/****************************************************************************
	**������
	*		��ȡ����
	**���룺
	*		��
	**�����
	*		��
	*����ֵ��
	*		���룬�ַ������� 
	**���ܣ�
	*		
	*****************************************************************************/
	const char* getPassword() const;


	/****************************************************************************
	**�����������û�����
	*
	**���룺
	*		p_pszDesc���û�����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*****************************************************************************/
	bool setDesc(const char* p_pszDesc);

	/****************************************************************************
	**��������ȡ�û�����
	*
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����
	**���ܣ�
	*****************************************************************************/
	const char* getDesc() const;


	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objUserParam ����ʾ�������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	**************************************************************************/
	UserParam& operator = (const UserParam& p_objUserParam);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objUserParam��UserParam���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����UserParam��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const UserParam& p_objUserParam);

private:

	char	m_szUserName[CONST_MAXLENGTH_USERNAME + 1];				//�û���
	char	m_szPassword[CONST_MAXLENGTH_USERPASSWORD + 1];			//����
	char	m_szDesc[CONST_MAXLENGTH_USER_DESC + 1];				//����

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_USERPARAM_H_
