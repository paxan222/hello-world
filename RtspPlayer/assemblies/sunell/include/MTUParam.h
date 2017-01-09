#ifndef _MTUPARAMETER_H_
#define _MTUPARAMETER_H_

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

class SN_DLL_API MTUParam
{
public:
	MTUParam(void);
	~MTUParam(void);
	
	//�������캯��
	MTUParam(const MTUParam& p_objMTUParam);

public:
	/************************************************************************
	** ������
	*		����MTUֵ
	**���룺
	*		p_nMTUValue��MTUֵ
	**�����
	*	  ��
	**����ֵ��
	*	  ��
	************************************************************************/
	void setMTUValue(const int p_nMTUValue);

	/************************************************************************
	**������
	*		��ȡMTUֵ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		MTU
	************************************************************************/
	const int getMTUValue()  const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objMTUParam��MTU��Ϣ
	**�����
	*		��
	**����ֵ��
	*		MTU��Ϣ
	*���ܣ�
	*
	************************************************************************/
	MTUParam& operator =(const MTUParam& p_objMTUParam);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objMTUParam��MTUParam���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����MTUParam��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const MTUParam& p_objMTUParam);

private:
	int			    m_nMTUValue;							//	

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/


#endif //_MTUPARAMETER_H_
