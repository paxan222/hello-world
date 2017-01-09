#ifndef _NASSTORAGEPARAM_H_
#define _NASSTORAGEPARAM_H_

#include "DomainConst.h"
#include "SNPlatOS.h"
#include "const.h"

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

class SN_DLL_API NasStorageParam
{

public:
	NasStorageParam(void);
	~NasStorageParam(void);

	//�������캯��
	NasStorageParam(const NasStorageParam& p_objNasStorageParam);

public:

	/************************************************************************
	**������
	*		����NAS�豸��IP��ַ
	**���룺
	*		p_pszNasIpAddress ��NAS�豸��Ip��ַ��һ���ԡ�\0����β���ַ�����
	**�����
	*		��
	**����ֵ��
	*		ture ��	���óɹ�
	*		false ���豸ֻ��
	*���ܣ�
	*		��p_pszNasIpAddressΪ��ʱ������false��
	*		������NAS IP��ַ�ɹ�ʱ������true��
	************************************************************************/
	bool setNASIpAddress(const char *p_pszNasIpAddress);

	/************************************************************************
	**������
	*		��ȡNAS�豸��IP��ַ
	*���룺
	*		��
	*�����
	*		��
	**����ֵ��
	*		IP��ַ
	**���ܣ�
	*
	*************************************************************************/
	const char *getNASIpAddress() const;


	/************************************************************************
	**������
	*		���÷���NAS���û���
	**���룺
	*		p_pszNasUserName��NAS�豸�û�����һ���ԡ�\0����β���ַ�����
	**�����
	*		��
	**����ֵ��
	*		ture ��	���óɹ�
	*		false�� ����ʧ��
	*���ܣ�
	*		��p_pszDDNSDomainNameΪ��ʱ������false
	*		������DDNS�����ɹ�ʱ������true
	************************************************************************/
	bool setNasUserName(const char *p_pszNasUserName);

	/************************************************************************
	*������
	*		��ȡ����NAS���û���
	**���룺
	*		��
	**�����
	*	��
	**����ֵ��
	*		NAS�û���
	**���ܣ�
	*
	*************************************************************************/
	const char *getNASUserName() const;

	/************************************************************************
	**������
	*		����NAS����
	*���룺
	*		p_pszNASPassword������NAS�豸���룬һ���ԡ�\0����β���ַ�����
	**�����
	*		��
	**����ֵ��
	*		ture ��	���óɹ�
	*		false�� ����ʧ��
	*���ܣ�
	*		��p_pszDDNSPasswordΪ��ʱ������false
	*		������NAS����ɹ�ʱ������true
	************************************************************************/
	bool setNASPassword(const char *p_pszNASPassword);

	/************************************************************************
	**������
	*		��ȡNAS����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		NAS������
	*���ܣ�
	*
	*************************************************************************/
	const char *getNasPassword() const;

	/************************************************************************
	**������
	*		��ȡNAS·��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		NAS������
	*���ܣ�
	*
	*************************************************************************/
	const char *getNasPath() const;

	/************************************************************************
	**������
	*		����NAS·��
	*���룺
	*		p_pszNASPath��NAS�豸��·����һ���ԡ�\0����β���ַ�����
	**�����
	*		��
	**����ֵ��
	*		ture ��	���óɹ�
	*		false�� ����ʧ��
	*���ܣ�
	*		��p_pszNASPathΪ��ʱ������false
	*		������NAS·���ɹ�ʱ������true
	************************************************************************/
	bool setNASPath(const char *p_pszNASPath);

	/************************************************************************
	*������
	*		��ֵ����
	**���룺
	*		p_objNasStorageParam��DDNS��Ϣ
	**�����
	*		��
	**����ֵ��
	*		DDNS��Ϣ
	**���ܣ�
	*
	*************************************************************************/
	NasStorageParam& operator =(const NasStorageParam& p_objNasStorageParam);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objNasStorageParam��NasStorageParam���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����NasStorageParam��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const NasStorageParam& p_objNasStorageParam);

	/****************************************************************************
	**������
	*		��λ������Ա�����ָ���ʼĬ��ֵ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		����Ա�����ָ���ʼĬ��ֵ
	*****************************************************************************/
	void reset();

private:

	char			m_szNasIpAddress[CONST_MAXLENGTH_IP + 1];		//NAS IP��ַ

	char			m_szNasUserName[CONST_MAXLENGTH_NAS_STORAGE_USERNAME + 1];	//NAS �û���	

	char			m_szNasPassword[CONST_MAXLENGTH_NAS_STORAGE_PASSWORD + 1];		//NAS ����

	char			m_szNasPath[CONST_MAXLENGTH_NAS_PATH + 1];	// NAS·������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_NASSTORAGEPARAM_H_

