#ifndef PTZTourParamV2_H_
#define PTZTourParamV2_H_

#include "DomainConst.h"
#include "PTZTourPointV2.h"
#include <string.h>
#include <vector>
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

class SN_DLL_API PTZTourParamV2
{
public:
	PTZTourParamV2(void);
	~PTZTourParamV2(void);
public:
	/************************************************************************
	**������
	*		������̨Ѳ��ID��
	**���룺
	*		p_nTourId ��Ѳ�ε�ID��
	**�����
	*		��
	*����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setTourId(const int p_nTourId);

	/************************************************************************
	**������
	*		��ȡѲ�ε�ID��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		Ѳ�ε�ID��
	**���ܣ�
	*    
	************************************************************************/
	const int getTourId() const;

	/************************************************************************
	**������
	*		������̨Ѳ�ε�����
    **���룺
	*	  p_pszTourName ����̨Ѳ�ε����֣��ַ�������󳤶�
	*						  ΪCONST_MAXLENGTH_PTZ_TOUR_NAME�ֽ�,��β�ԡ�\0�������� 
	**�����
	*		��
	**����ֵ��
	*		true ���ɹ�
	*		false��ʧ��
	*���ܣ�
	*    ������p_pszTourName����<=CONST_MAXLENGTH_PTZ_TOUR_NAME������true�������浽m_pszTourName;
	*	 ������p_pszTourNameΪnull�����䳤��>CONST_MAXLENGTH_PTZ_TOUR_NAME������false
	************************************************************************/
	bool setTourName(const char* p_pszTourName);

	/************************************************************************
	**������
	*		��ȡ��̨Ѳ�ε�����
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��̨Ѳ�ε����ֵĵ�ַ
	**���ܣ�
	*		
	************************************************************************/
	const char* getTourName() const;

	/************************************************************************
	**������
	*		������̨Ѳ��Ԥ�õ��б�
	**���룺
	*		p_vecPTZPresetV2List ��Ѳ�ε�Ԥ�õ��б�
	**�����
	*		��
	*����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setPTZTourPointV2List(const std::vector<PTZTourPointV2> &p_vecPTZTourPointV2List);

	/************************************************************************
	**������
	*		��ȡѲ�ε�Ԥ�õ��б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		Ѳ�ε�Ԥ�õ��б�
	**���ܣ�
	*    
	************************************************************************/
	const std::vector<PTZTourPointV2> &getPTZTourPointV2List() const;

	PTZTourParamV2& operator =(const PTZTourParamV2& p_objPTZTourParamV2);
private:
	int		m_nTourId;													//��̨Ѳ�ε�ID��
	char	m_szTourName[CONST_MAXLENGTH_PTZ_TOUR_NAME + 1];			//��̨Ѳ�ε�����
	std::vector<PTZTourPointV2> m_vecPTZTourPointV2List;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
#endif


