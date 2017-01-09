#ifndef _TONEARMPARAM_H_
#define _TONEARMPARAM_H_

#include "SNPlatOS.h"

#ifndef byte
typedef unsigned char byte;
#endif

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

class SN_DLL_API ToneArmParam
{
public:

	enum ToneArmType
	{
		TONEARM_TYPE_INTERNAL				= 1,	//����
		TONEARM_TYPE_EXTERNAL				= 2,	//����
		TONEARM_TYPE_LINEIN					= 3,	//������
		TONEARM_TYPE_DIFF_LINEIN			= 4,	//���������
		TONEARM_TYPE_DOUBLE_LINEIN			= 5		//˫����
	};

public:
	ToneArmParam();
	~ToneArmParam();

	//�������캯��
	ToneArmParam(const ToneArmParam &p_objToneArmParam);

public:
	/************************************************************************
	**������
	*		�����������Id��
    **���룺
	*		p_nCameraId ���������Id��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*    �����������Id��
	************************************************************************/
	void setCameraId(const int p_nCameraId);
	
	/************************************************************************
	**������
	*		��ȡ�������Id��
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������Id��
	**���ܣ�
	*     ��ȡ�������Id��
	**************************************************************************/
	const int getCameraId() const ;
	
	/************************************************************************
	**������
	*		�����Ƿ�����ʰ����
	**���룺
	*		p_bFlag������ʰ������ʶ��false�������ã�true�����ã�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	**************************************************************************/	
	void setToneArmEnableFlag(const bool p_bFlag);

	/************************************************************************
	**������
	*		��ȡ�Ƿ�����ʰ������ʶ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�Ƿ�ʰ������ʶ��false�������ã�true�����ã�
	**���ܣ�
	*     
	**************************************************************************/
	const bool getToneArmEnableFlag() const ;


	/************************************************************************
	**������
	*		����ʰ��������
    **���룺
	*		p_nToneArmType��ʰ��������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	**************************************************************************/
	void setToneArmType(const int p_nToneArmType);

	/************************************************************************
	**������
	*		��ȡʰ��������
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ʰ��������
	**���ܣ�
	*     
	**************************************************************************/
	const int getToneArmType() const ;


	/************************************************************************
	**������
	*		��������
	**���룺
	*		p_nVolume������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	**************************************************************************/
	void setVolume(const int p_nVolume);

	/************************************************************************
	**������
	*		��ȡ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����
	**���ܣ�
	*     
	**************************************************************************/
	const int getVolume() const ;


	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objToneArmParam ��ʰ��������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	**************************************************************************/
	ToneArmParam& operator = (const ToneArmParam& p_objToneArmParam);

	bool operator == (const ToneArmParam& p_objToneArmParam) const;

	bool operator < (const ToneArmParam& p_objToneArmParam) const;

private:
	
	int				m_nCameraId;										//�������ID��

	bool			m_bToneArmEnableFlag;								//�Ƿ�����ʰ������false�������ã�true�����ã�
	
	int				m_nToneArmType;										//ʰ��������

	int				m_nVolume;											//����
		
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_TONEARMPARAM_H_
