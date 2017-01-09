#ifndef _LAYOUTMODEL_
#define _LAYOUTMODEL_

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

class SN_DLL_API LayoutModel
{
public:
	enum LAYOUTMODELID
	{
		Layout_Model_1 = 0,		//һ����
		Layout_Model_2,			//�Ĵ���
		Layout_Model_3,			//������ƽ��
		Layout_Model_4,			//������,һ����С
		Layout_Model_5,			//�˴��ڣ�һ����С
		Layout_Model_6,			//�Ŵ���
		Layout_Model_7,			//ʮ������
		Layout_Model_8,			//��ʮ������
		Layout_Model_9,			//��ʮ�Ĵ���
		Layout_Model_Max = Layout_Model_9
	};

public:
	LayoutModel(void);
	~LayoutModel(void);

public:
	/************************************************************************
	*	�������������ͱ��
	*	���룺
	*		p_ModelId	���ͱ��
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setModelId(int p_ModelId);

	/************************************************************************
	*	��������ȡ���ͱ��
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		���ͱ��
	*************************************************************************/
	int getModelId() const;

	/************************************************************************
	*	���������û�������
	*	���룺
	*		p_PicNumber	��������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setPicNumber(int p_PicNumber);

	/************************************************************************
	*	��������ȡ��������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		��������
	*************************************************************************/
	int getPicNumber() const;

	LayoutModel& operator = (const LayoutModel& p_objLayoutModel);

private:
	int		m_nModelId;
	int		m_nPicNumber;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_LAYOUTMODEL_
