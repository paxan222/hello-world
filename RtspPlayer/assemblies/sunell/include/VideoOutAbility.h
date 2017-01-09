#ifndef _VIDE_OOUT_ABILITY_H_
#define _VIDE_OOUT_ABILITY_H_
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



class SN_DLL_API VideoOutAbility
{

public:
	VideoOutAbility();
	~VideoOutAbility();
	/************************************************************************
	**����������ģ������Ƿ������
	*
	**���룺
	*		p_VideoOutConfigurable   ������
	**�����
	*		��
	**���ܣ�       
	*		����ģ������Ƿ����
	************************************************************************/
	void setVideoOutConfigurable(const bool p_VideoOutConfigurable);

	/************************************************************************
	**��������ȡģ������Ƿ������
	*
	**���룺
	*		��
	**���أ�
	*		������
	**���ܣ�       
	*		��ȡģ������Ƿ������
	************************************************************************/
	const bool getVideoOutConfigurable() const;

	/************************************************************************
	**�����������Ƿ�֧����Ƶģ�����
	*
	**���룺
	*		p_Flag   ֧�ֱ��
	**�����
	*		��
	**���ܣ�       
	*		�����Ƿ�֧����Ƶģ�����
	************************************************************************/
	void setIsSupportVideoOut(const bool p_Flag);

	/************************************************************************
	**��������ȡ�Ƿ�֧����Ƶģ�����
	*
	**���룺
	*		��
	**�����
	*		��
	**���ܣ�       
	*		��ȡ�Ƿ�֧����Ƶģ�����
	************************************************************************/
	const bool getIsSupportVideoOut() const;


private:
	bool m_VideoOutConfigurable;   
	bool m_IsSupportVideoOut;
	    					
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif 

