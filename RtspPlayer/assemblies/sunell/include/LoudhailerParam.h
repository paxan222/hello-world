#ifndef _LOUDHAILERPARAM_H_
#define _LOUDHAILERPARAM_H_

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

class SN_DLL_API LoudhailerParam
{
public:

	enum LoudhailerType
	{
		LOUDHAILER_TYPE_IN			= 1,	//����
		LOUDHAILER_TYPE_OUT			= 2		//����
	};

public:
	LoudhailerParam();
	~LoudhailerParam();

	//�������캯��
	LoudhailerParam(const LoudhailerParam &p_objLoudhailerParam);

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
	*		�����Ƿ�����������
	**���룺
	*		p_bFlag��������������ʶ��false�������ã�true�����ã�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	**************************************************************************/	
	void setLoudhailerEnableFlag(const bool p_bFlag);

	/************************************************************************
	**������
	*		��ȡ�Ƿ�������������ʶ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�Ƿ���������ʶ��false�������ã�true�����ã�
	**���ܣ�
	*     
	**************************************************************************/
	const bool getLoudhailerEnableFlag() const ;


	/************************************************************************
	**������
	*		��������������
	**���룺
	*		p_nLoudhailerType������������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	**************************************************************************/
	void setLoudhailerType(const int p_nLoudhailerType);

	/************************************************************************
	**������
	*		��ȡ����������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����������
	**���ܣ�
	*     
	**************************************************************************/
	const int getLoudhailerType() const ;


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
	*		p_objLoudhailerParam ������������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	**************************************************************************/
	LoudhailerParam& operator = (const LoudhailerParam& p_objLoudhailerParam);

	bool operator == (const LoudhailerParam& p_objLoudhailerParam) const;

	bool operator < (const LoudhailerParam& p_objLoudhailerParam) const;

private:
	
	int				m_nCameraId;										//�������ID��

	bool			m_bLoudhailerEnableFlag;							//�Ƿ�������������false�������ã�true�����ã�
	
	int				m_nLoudhailerType;									//����������

	int				m_nVolume;											//����
		
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_LOUDHAILERPARAM_H_
