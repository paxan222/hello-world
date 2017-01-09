#ifndef _BLINDABILITY_H_
#define _BLINDABILITY_H_
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

class SN_DLL_API BlindAbility
{

public:
	BlindAbility();
	~BlindAbility();
	/************************************************************************
	**����������֧���ڵ����������
	*
	**���룺
	*		p_nMaxBlindAreaNum   �ڵ�������
	**�����
	*		��
	**���ܣ�       
	*		����֧���ڵ���������
	************************************************************************/
	void setMaxBlindAreaNum(const int &p_nMaxBlindAreaNum);

	/************************************************************************
	**��������ȡ֧���ڵ����������
	*
	**���룺
	*		��
	**���أ�
	*		����������
	**���ܣ�       
	*		��ȡ֧���ڵ���������
	************************************************************************/
	const int getMaxBlindAreaNum() const;

	/************************************************************************
	**�����������ڵ��������ռԴ�ֱ��ʰٷֱ�ֵ
	*
	**���룺
	*		p_nBlindArea   �ٷֱ�ֵ
	**�����
	*		��
	**���ܣ�       
	*		�����ڵ��������ռԴ�ֱ��ʰٷֱ�ֵ
	************************************************************************/
	void setBlindArea(const int &p_nBlindArea);	

	/************************************************************************
	**��������ȡ�ڵ��������ռԴ�ֱ��ʰٷֱ�ֵ
	*
	**���룺
	*		��
	**���أ�
	*		�������ռԴ�ֱ��ʰٷֱ�ֵ
	**���ܣ�       
	*		��ȡ�ڵ��������ռԴ�ֱ��ʰٷֱ�ֵ
	************************************************************************/
	const int getBlindArea() const;


	/************************************************************************
	**�����������ڵ�����
	*
	**���룺
	*		p_nBlindType   �ڵ�����
	**�����
	*		��
	**���ܣ�       
	*		�����ڵ�����
	************************************************************************/
	void setBlindType(const int &p_nBlindType);	

	/************************************************************************
	**��������ȡ�ڵ�����
	*
	**���룺
	*		��
	**���أ�
	*		�ڵ�����
	**���ܣ�       
	*		��ȡ�ڵ�����
	************************************************************************/
	const int getBlindType() const;

	//��ֵ����
	BlindAbility& operator = (const BlindAbility& p_objBlindAbility);

	bool operator == (const BlindAbility& p_objBlindAbility) const;
private:
	int m_nMaxBlindAreaNum;	     //֧�������ڵ�������Ŀ
	int m_nBlindArea;			//�ڵ��������ռԴ�ֱ��ʰٷֱ�     					
	int m_nBlindType;			//�ڵ�����
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif // _BLINDABILITY_H_