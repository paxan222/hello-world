#ifndef _PTZKEYBOARDPARAM_H_
#define _PTZKEYBOARDPARAM_H_

#include "ExternInterface.h"
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

class SN_DLL_API PTZKeyboardParam
{
public:
	PTZKeyboardParam();
	~PTZKeyboardParam();

public:
	/************************************************************************
	**������
	*		�����Ƿ�������̨���̷���
	**���룺
	*		p_bEnableFlag��������̨���̷����״̬
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setEnableFlag(const bool p_bEnableFlag);

	/************************************************************************
	**������
	*		��ȡ�Ƿ�������̨���̷����ʶ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�Ƿ�������̨���̷����ʶ
	**���ܣ�
	*		
	*************************************************************************/
	const bool getEnableFlag() const;

	void setExternInterface(const ExternInterface & p_objExternInterface);
	const ExternInterface & getExternInterface() const;
private:
	bool m_bEnableFlag; //�Ƿ�������̨����(true��������false��������)
	ExternInterface m_objExternInterface;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_PTZKeyboardParam_H_
