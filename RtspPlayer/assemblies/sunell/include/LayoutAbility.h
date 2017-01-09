#ifndef _LAYOUTABILITY_
#define _LAYOUTABILITY_
#include "SNPlatOS.h"
#include "LayoutModel.h"
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

/************************************************************************
*	������Layout������Ϣ��
*	��Ҫ����������Ϣ��Layoutģʽ�б�
************************************************************************/
class SN_DLL_API LayoutAbility
{
public:
	LayoutAbility(void);
	~LayoutAbility(void);

public:
	/************************************************************************
	*	������
	*		����Layoutģʽ�б�
	*	���룺
	*		p_LayoutModelList	Layoutģʽ�б�
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	void setLayoutModelList(const std::vector<LayoutModel> &p_LayoutModelList);

	/************************************************************************
	*	������
	*		��ȡLayoutģʽ�б�
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		Layoutģʽ�б�
	************************************************************************/
	const std::vector<LayoutModel> &getLayoutModelList() const;

	LayoutAbility& operator = (const LayoutAbility& p_objLayoutAbility);
private:
	std::vector<LayoutModel>	m_LayoutModelList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_LAYOUTABILITY_
