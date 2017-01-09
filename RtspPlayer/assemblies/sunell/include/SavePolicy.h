#ifndef _SAVEPOLICY_H_
#define _SAVEPOLICY_H_

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

class SN_DLL_API SavePolicy
{
public:
	SavePolicy();

	~SavePolicy();

	//��ֵ����
	SavePolicy(const SavePolicy &p_objSavePolicy);

public:
	/***********************************************************************
	**������
	*		����¼���ļ��ı�������
	**���룺
	*		p_nDelay����������
	**�����
	*		
	**����ֵ��
	*		��
	**���ܣ�
	*		����¼���ļ��ı�������
	************************************************************************/
	void setRecordSaveDays(const int p_nRecordSaveDays);

	/***********************************************************************
	**������
	*		��ȡ¼���ļ��ı�������
	**���룺
	*		
	**�����
	*		
	**����ֵ��
	*		¼���ļ��ı�������
	**���ܣ�
	*		��ȡ¼���ļ��ı�������
	************************************************************************/
	const int getRecordSaveDays() const;

	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objSavePolicy���洢���Զ���
	**�����
	*		��
	**����ֵ��
	*		��ֵ��Ĵ洢���Զ���
	**���ܣ�
	*		
	*****************************************************************************/
	SavePolicy & operator=(const SavePolicy &p_objSavePolicy);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objSavePolicy��SavePolicy���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����SavePolicy��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator==(const SavePolicy &p_objSavePolicy);

private:
	int				m_nRecordSaveDays;				//�洢����

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_LOCALSavePolicy_H_
