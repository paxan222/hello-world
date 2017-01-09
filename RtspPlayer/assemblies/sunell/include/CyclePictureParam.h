#ifndef _DISPLAYPICTUREPARAM_H_
#define _DISPLAYPICTUREPARAM_H_

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

class SN_DLL_API CyclePictureParam
{
public:
	CyclePictureParam(void);
	~CyclePictureParam(void);

	//�������캯��
	CyclePictureParam(const CyclePictureParam& p_objCyclePictureParam);

public:

	/************************************************************************
	**������
	*		���û���ID
	**���룺
	*		p_nPictureId ������ID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*    
	************************************************************************/
	void setPictureId(const int p_nPictureId);

	/************************************************************************
	**������
	*		��ȡ����ID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ID
	**���ܣ�
	*     
	**************************************************************************/
	const int getPictureId() const;


	/****************************************************************************
	**������
	*		���û�������
	**���룺
	*		p_pszPictureName ����������,��β�ԡ�\0��������
	**�����
	*		��
	**����ֵ��
	*		true�� �ɹ�
	*		false��ʧ�� 
	**���ܣ�
	*		������p_pszPictureName����<=CONST_MAXLENGTH_PICTURENAME������true.
	*		������p_pszPictureNameΪNULL���䳤��>CONST_MAXLENGTH_PICTURENAME������false.
	*****************************************************************************/
	bool setPictureName(const char* p_pszPictureName);

	/****************************************************************************
	**������
	*		��ȡ��������
	**���룺
	*		��
	**�����
	*		��
	*����ֵ��
	*		�������ƣ��ַ������� 
	**���ܣ�
	*		
	*****************************************************************************/
	const char* getPictureName() const;


	/************************************************************************
	**������
	*		����������Id
	**���룺
	*		p_nSupGroupId ��������Id
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*    
	************************************************************************/
	void setSupGroupId(const int p_nSupGroupId);

	/************************************************************************
	**������
	*		��ȡ������Id
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������Id
	**���ܣ�
	*     
	**************************************************************************/
	const int getSupGroupId() const ;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objCyclePictureParam ����ʾ�������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	**************************************************************************/
	CyclePictureParam& operator = (const CyclePictureParam& p_objCyclePictureParam);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objCyclePictureParam��CyclePictureParam���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����CyclePictureParam��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const CyclePictureParam& p_objCyclePictureParam);

private:

	int		m_nPictureId;									//����id

	char	m_szPictureName[CONST_MAXLENGTH_PICTURENAME + 1];	//��������
	
	int		m_nSupGroupId;									//������id

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_DISPLAYPICTUREPARAM_H_
