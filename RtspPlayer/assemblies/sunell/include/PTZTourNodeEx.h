#ifndef _PTZ_TOUR_NODE_EX_H_
#define _PTZ_TOUR_NODE_EX_H_

#include "DomainConst.h"

#include <string.h>
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

class  SN_DLL_API PTZTourNodeEx
{

public:
	PTZTourNodeEx();
	~PTZTourNodeEx();

	PTZTourNodeEx(const PTZTourNodeEx& p_objAlcatelPTZTourNode);

public:

	/************************************************************************
	**������
	*		��������ͷID��
    **���룺
	*		p_nCameraId ������ͷ��ID��
	**�����
	*		��
	*����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**������
	*		��ȡ����ͷ��ID��
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ͷ��ID��
	**���ܣ�
	*    
	************************************************************************/
	const int getCameraId() const;

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
	*		��ȡ��̨Ѳ��ID��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��̨Ѳ��ID��
	**���ܣ�
	*    
	************************************************************************/
	const int getTourId() const;

	/************************************************************************
	**������
	*		������̨Ѳ�νڵ�Ԥ�õ�ID
    **���룺
	*	  p_nPreset ����̨Ԥ�Ƶ�Id
	**�����
	*		��
	**����ֵ��
	*		
	*���ܣ�
	************************************************************************/
	void setPresetId(const int p_nPresetId);

	/************************************************************************
	**������
	*		��ȡ��̨Ѳ�νڵ��Ԥ�õ�ID
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��̨Ѳ�νڵ��Ԥ�õ�ID
	**���ܣ�
	*		
	************************************************************************/
	const int getPresetId() const;

	/************************************************************************
	**������
	*		������̨Ѳ�νڵ�ͣ��ʱ��
	**���룺
	*	  p_nTime ����̨Ѳ�νڵ��ͣ��ʱ��
	**�����
	*		��
	**����ֵ��
	*		
	*���ܣ�
	************************************************************************/
	void setWaitTime(const int p_nTime);

	/************************************************************************
	**������
	*		��ȡ��̨Ѳ�νڵ�ͣ��ʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��̨Ѳ�νڵ�ͣ��ʱ��
	**���ܣ�
	*		
	************************************************************************/
	const int getWaitTime() const;

	/************************************************************************
	**������
	*		�����ٶ�
	**���룺
	*	  p_nSpeed ���ٶ�
	**�����
	*		��
	**����ֵ��
	*		
	*���ܣ�
	************************************************************************/
	void setSpeed(const int p_nSpeed);

	/************************************************************************
	**������
	*		��ȡ�ٶ�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�ٶ�
	**���ܣ�
	*		
	************************************************************************/
	const int getSpeed() const;

	/************************************************************************
	**������
	*		���帳ֵ������
	**���룺
	*		p_objAlcatelPTZTourNode��PTZTourNodeEx���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		PTZTourNodeEx���һ�����������
	**���ܣ�
	************************************************************************/
	PTZTourNodeEx& operator =(const PTZTourNodeEx& p_objAlcatelPTZTourNode);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objAlcatelPTZTourNode��PTZTourNodeEx���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����PTZTourNodeEx��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const PTZTourNodeEx& p_objAlcatelPTZTourNode) const;

	bool operator < (const PTZTourNodeEx& p_objAlcatelPTZTourNode) const;

private:

	int		m_nCameraId;												//����ͷID��
	
	int		m_nTourId;													//��̨Ѳ�ε�ID��
						
	int 	m_nPTZPresetId;												//��̨Ԥ�õ�ID

	int		m_nWaitTime;												//ͣ��ʱ��

	int		m_nSpeed;													//�ٶ�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_AlcatelPTZTourNode_H_
