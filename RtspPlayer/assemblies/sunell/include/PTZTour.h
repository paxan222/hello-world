#ifndef _PTZTour_H_
#define _PTZTour_H_

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

class SN_DLL_API PTZTour
{

public:
	PTZTour();
	~PTZTour();

	PTZTour(const PTZTour& p_objPTZTour);

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
	*		������̨Ѳ�εı�ע��
    **���룺
	*	  p_pszTourName ����̨Ԥ�Ƶ�����֣��ַ�������󳤶�
	*						  ΪCONST_MAXLENTH_PTZ_PROTOCOL_NAME�ֽ�,��β�ԡ�\0�������� 
	**�����
	*		��
	**����ֵ��
	*		true ���ɹ�
	*		false��ʧ��
	*���ܣ�
	*    ������p_pszTourName����<=CONST_MAXLENGTH_PTZ_TOUR_NAME������true�������浽m_szProtocolName;
	*	 ������p_pszTourNameΪnull�����䳤��>CONST_MAXLENGTH_PTZ_TOUR_NAME������false
	************************************************************************/
	bool setTourName(const char* p_pszTrackName);

	/************************************************************************
	**������
	*		��ȡ��̨Ѳ�εı�ע��
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��̨Ѳ�εı�ע��
	**���ܣ�
	*		
	************************************************************************/
	const char* getTourName() const;

	/************************************************************************
	**������
	*		���帳ֵ������
	**���룺
	*		p_objPTZTour��PTZTour���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		PTZTour���һ�����������
	**���ܣ�
	************************************************************************/
	PTZTour& operator =(const PTZTour& p_objPTZTour);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objPTZTour��PTZTour���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����PTZTour��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const PTZTour& p_objPTZTour) const;

	bool operator < (const PTZTour& p_objPTZTour) const;

private:

	int		m_nCameraId;												//����ͷID��
	
	int		m_nTourId;													//��̨Ѳ�ε�ID��
	
	char	m_szTourName[CONST_MAXLENGTH_PTZ_TOUR_NAME + 1];			//��̨Ѳ�ε�����
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_PTZTour_H_

