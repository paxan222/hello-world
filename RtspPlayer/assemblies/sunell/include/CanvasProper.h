#ifndef _CANVASPROPER_H_
#define _CANVASPROPER_H_

#include "DomainConst.h"
#include "SNPlatOS.h"
#include "OSDInfoExV2.h"
#include "AreaParamV2.h"
#include <map>
using namespace std;

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

class SN_DLL_API CanvasProper
{
public:
	CanvasProper();
	~CanvasProper();

public:
	enum CanvasInfoAlignMode
	{
		ALIGNMODE_LEFT				= 0,	//�����
		ALIGNMODE_RIGHT				= 1		//�Ҷ���
	};

	
	/****************************************************************************
	**������
	*		��ȡOSDInfoList(����)
    **���룺
	*		p_objOSDInfoMap:OSD��ϢMap
	**�����
	*		��
	**����ֵ��
	*		�� 
	**���ܣ�
	*		
	*******************************************************************************/
	const std::map<int,OSDInfoExV2>& getOSDInfoMap() const ;

	/****************************************************************************
	**������
	*		����OSDInfoList
    **���룺
	*		p_objOSDInfoMap:OSD��ϢMap
	**�����
	*		��
	**����ֵ��
	*		�� 
	**���ܣ�
	*		
	*******************************************************************************/
	void setOSDInfoMap(const std::map<int,OSDInfoExV2>& p_objOSDInfoMap);


	/****************************************************************************
	**������
	*		���ö���ģʽ
    **���룺
	*		p_nAlignMode:����ģʽ
	**�����
	*		��
	**����ֵ��
	*		�� 
	**���ܣ�
	*		
	*******************************************************************************/
	void setAlignMode(const int & p_nAlignMode);

	/****************************************************************************
	**������
	*		��ȡ����ģʽ
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ģʽ
	**���ܣ�
	*	
	*******************************************************************************/
	const int& getAlignMode() const;

	/****************************************************************************
	**������
	*		������������Ϣ�����
    **���룺
	*		p_nFrontWidth�������
	**�����
	*		��
	**����ֵ��
	*		�� 
	**���ܣ�
	*		
	*******************************************************************************/
	void setFrontWidth(const int & p_nFrontWidth);

	/****************************************************************************
	**������
	*		��ȡ��������Ϣ�����
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�����
	**���ܣ�
	*	
	*******************************************************************************/
	const int& getFrontWidth() const;


	/****************************************************************************
	**������
	*		������������Ϣ�����С��
    **���룺
	*		p_nFrontHeight:�����
	**�����
	*		��
	**����ֵ��
	*		�� 
	**���ܣ�
	*		
	*******************************************************************************/
	void setFrontHeight(const int & p_nFrontHeight);

	/****************************************************************************
	**������
	*		��ȡ��������Ϣ�����
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�����
	**���ܣ�
	*	
	*******************************************************************************/
	const int& getFrontHeight() const;



	/****************************************************************************
	**������
	*		���û����������
    **���룺
	*		p_objAreaParamV2:�����������
	**�����
	*		��
	**����ֵ��
	*		�� 
	**���ܣ�
	*		
	*******************************************************************************/
	void setAreaParam(const AreaParamV2& p_objAreaParamV2);

	/****************************************************************************
	**������
	*		��ȡ�����������
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�����������
	**���ܣ�
	*	
	*******************************************************************************/
	const AreaParamV2& getAreaParam() const ;




	/****************************************************************************
	**������
	*		��������
	**���룺
	*		CanvasProper���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		CanvasProper����������
	**���ܣ�
	*		������������������Ը�ֵ������һ�����󣬽�����һ����������÷��ء�
	*******************************************************************************/
	CanvasProper & operator =(const CanvasProper& p_objCanvasProper) ;
private:
	AreaParamV2					m_objAreaParamV2;//�������
	int							m_nFrontWidth;//�����С��
	int							m_nFrontHeight;//�����С��
	int							m_nAlignMode;//����ģʽ
	std::map<int,OSDInfoExV2>	m_objOSDInfoList;//�к�OSD��Ϣ�ļ�ֵ��
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CANVASPROPER_H_