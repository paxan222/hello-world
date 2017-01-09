#ifndef _PTZSpeed_H_
#define _PTZSpeed_H_

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

class SN_DLL_API PTZSpeed
{

public:
	PTZSpeed();
	~PTZSpeed();

	PTZSpeed(const PTZSpeed& p_objPTZSpeed);

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
	*		������̨�ٶ�
	**���룺
	*		p_nSpeed ����̨�ٶ�
	**�����
	*		��
	*����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setSpeed(const int p_nSpeed);

	/************************************************************************
	**������
	*		��ȡ��̨�ٶ�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		Ԥ�Ƶ��ID��
	**���ܣ�
	*    
	************************************************************************/
	const int getSpeed() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objPTZSpeed����̨�ٶ�
	**�����
	*		��
	**����ֵ��
	*		��̨Ԥ�Ƶ�
	**���ܣ�
	************************************************************************/
	PTZSpeed& operator =(const PTZSpeed& p_objPTZSpeed);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objPTZSpeed��PTZSpeed���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����PTZSpeed��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const PTZSpeed& p_objPTZSpeed) const;

	bool operator < (const PTZSpeed& p_objPTZSpeed) const;

private:

	int		m_nCameraId;													//����ͷID��
	
	int		m_nSpeed;														//��̨�ٶ�ֵ
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //__PTZSpeed_H__

