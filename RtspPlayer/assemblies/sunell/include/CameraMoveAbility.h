#ifndef _CAMERAMOVEABILITY_H_
#define _CAMERAMOVEABILITY_H_

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

class SN_DLL_API CameraMoveAbility
{
public:
	CameraMoveAbility();
	~CameraMoveAbility();

    /***********************************************************************
	*	�����������ṩ������ƶ���CameraMoveAbility�����ܵ����ܿ��ID
	*	���룺
	*		p_nLibId �����ܿ�ID
	*	�����
	*		��
	*	����ֵ��
	*		��
	*   �������ģ�
	*       ��������ܿ�ID��Ҫ�������б�Ŀ�IDƥ�䣬��Ȼ����Ϊ�Ƿ���ID��
	*       �����޷��������á�
	************************************************************************/
	void setLibId(const int p_nLibId);

    /***********************************************************************
	*	��������ȡ�ṩ������ƶ���CameraMoveAbility�����ܵ����ܿ��ID
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		const int : ��ǰ�ṩ�ù��ܵ����ܿ�ID
	*   �������ģ�
	*       ���صĿ�ID�ǵ�ǰ�豸�ṩ�����ܷ������ܵĿ�ID
	************************************************************************/
	const int getLibId() const;

    /***********************************************************************
	*	����������������ƶ���CameraMoveAbility�������Ƿ�֧��
	*	���룺
	*		p_bEnable ���Ƿ�֧�ָ�������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*   �������ģ�
	*       ����Ϊtrue : ֧�ָ���������
	*       ����Ϊfalse : ��֧�ָ���������
	************************************************************************/
	void setEnable(const bool p_bEnable);

    /***********************************************************************
	*	��������ȡ������ƶ���CameraMoveAbility�������Ƿ�֧��
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		bool : ���֧�֣�����true��
	*              �����֧�֣�����false��
	*   �������ģ�
	*       ��
	************************************************************************/
	const bool getEnable() const;

private:
	bool m_bEnable;
	int m_nLibId;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif   //_CAMERAMOVEABILITY_H_
