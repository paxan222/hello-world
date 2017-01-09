#ifndef _BLINDAREAINFOV2_H_
#define _BLINDAREAINFOV2_H_

#include "SNPlatOS.h"
#include "BlindAreaParamV2.h"
#include "PTZPointParamV2.h"

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

class SN_DLL_API BlindAreaInfoV2
{
public:
	BlindAreaInfoV2(void);
	~BlindAreaInfoV2(void);

	//�������캯��
	BlindAreaInfoV2 (const BlindAreaInfoV2 &p_objBlindAreaInfoV2);

	/************************************************************************
	**������
	*		������˽�ڱ���Ϣ
	**���룺
	*		p_objBlindAreaParamV2:��˽�ڱ���Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*      
	**************************************************************************/
	void setBlindAreaParamV2(const BlindAreaParamV2& p_objBlindAreaParamV2);


	/************************************************************************
	**������
	*		��ȡ��˽�ڱ���Ϣ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��˽�ڱ���Ϣ
	**���ܣ�
	*      
	**************************************************************************/
	const BlindAreaParamV2& getBlindAreaParamV2() const;

	/************************************************************************
	**������
	*		����PTZ������Ϣ
	**���룺
	*		p_objPTZPointParamV2:PTZ������Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*      
	**************************************************************************/
	void setPTZPointParamV2(const PTZPointParamV2& p_objPTZPointParamV2);


	/************************************************************************
	**������
	*		��ȡPTZ������Ϣ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		PTZ������Ϣ
	**���ܣ�
	*      
	**************************************************************************/
	const PTZPointParamV2& getPTZPointParamV2() const;


	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objBlindAreaParam���ƶ����������
	**�����
	*		��
	**����ֵ��
	*		��ֵ����ƶ����������
	**���ܣ�
	*		
	*****************************************************************************/
	BlindAreaInfoV2& operator = (const BlindAreaInfoV2 &p_objBlindAreaParam);

private:
	BlindAreaParamV2		m_objBlindAreaParamV2;			//�ƶ�������Ϣ

	PTZPointParamV2			m_objPTZPointParamV2;			//PTZ������Ϣ

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_BLINDAREAINFOV2_H_
