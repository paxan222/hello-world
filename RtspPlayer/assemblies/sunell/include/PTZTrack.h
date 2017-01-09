#ifndef _PTZTRACK_H_
#define _PTZTRACK_H_

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

class SN_DLL_API PTZTrack
{

public:
	PTZTrack();
	~PTZTrack();

	PTZTrack(const PTZTrack& p_objPTZTrack);

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
	*		������̨Ԥ�Ƶ�ID��
	**���룺
	*		p_nTrackId ��Ԥ�Ƶ��ID��
	**�����
	*		��
	*����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setTrackId(const int p_nTrackId);

	/************************************************************************
	**������
	*		��ȡԤ�Ƶ��ID��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		Ԥ�Ƶ��ID��
	**���ܣ�
	*    
	************************************************************************/
	const int getTrackId() const;

	/************************************************************************
	**������
	*		������̨Ԥ�Ƶ������
    **���룺
	*	  p_pszTrackName ����̨Ԥ�Ƶ�����֣��ַ�������󳤶�
	*						  ΪCONST_MAXLENTH_PTZ_PROTOCOL_NAME�ֽ�,��β�ԡ�\0�������� 
	**�����
	*		��
	**����ֵ��
	*		true ���ɹ�
	*		false��ʧ��
	*���ܣ�
	*    ������p_pszTrackName����<=CONST_MAXLENGTH_PTZ_Track_NAME������true�������浽m_szProtocolName;
	*	 ������p_pszTrackNameΪnull�����䳤��>CONST_MAXLENGTH_PTZ_Track_NAME������false
	************************************************************************/
	bool setTrackName(const char* p_pszTrackName);

	/************************************************************************
	**������
	*		��ȡ��̨Э�������
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��̨Э������ֵĵ�ַ
	**���ܣ�
	*		
	************************************************************************/
	const char* getTrackName() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objPTZTrack����̨Ԥ�Ƶ�
	**�����
	*		��
	**����ֵ��
	*		��̨Ԥ�Ƶ�
	**���ܣ�
	************************************************************************/
	PTZTrack& operator =(const PTZTrack& p_objPTZTrack);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objPTZTrack��PTZTrack���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����PTZTrack��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const PTZTrack& p_objPTZTrack) const;

	bool operator < (const PTZTrack& p_objPTZTrack) const;

private:

	int		m_nCameraId;												//����ͷID��
	
	int		m_nTrackId;													//��̨Ԥ�Ƶ��ID��
	
	char	m_szTrackName[CONST_MAXLENGTH_PTZ_TRACK_NAME + 1];			//��̨Ԥ�Ƶ������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_PTZTRACK_H_

