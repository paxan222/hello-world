#ifndef PTZTourPointV2_H_
#define PTZTourPointV2_H_

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

class SN_DLL_API PTZTourPointV2
{
public:
	PTZTourPointV2(void);
	~PTZTourPointV2(void);
/************************************************************************
	**������
	*		������̨Ԥ�Ƶ�ID��
	**���룺
	*		p_nPresetId ��Ԥ�Ƶ��ID��
	**�����
	*		��
	*����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setPresetId(const int p_nPresetId);

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
	const int getPresetId() const;

	/************************************************************************
	**������
	*		����Ԥ�õ�ת���ٶ�
	**���룺
	*		p_nSpeedValue ��ת���ٶ�
	**�����
	*		��
	*����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setSpeedValue(const int p_nSpeedValue);

	/************************************************************************
	**������
	*		��ȡԤ�õ�ת���ٶ�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		Ԥ�õ�ת���ٶ�
	**���ܣ�
	*    
	************************************************************************/
	const int getSpeedValue() const;

	/************************************************************************
	**������
	*		����ֹͣʱ��
	**���룺
	*		p_nStopTime ��ֹͣʱ��
	**�����
	*		��
	*����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setStopTime(const int p_nStopTime);

	/************************************************************************
	**������
	*		��ȡֹͣʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ֹͣʱ��
	**���ܣ�
	*    
	************************************************************************/
	const int getStopTime() const;

	PTZTourPointV2 &operator=(const PTZTourPointV2 p_objPTZTourPointV2);
private:
	int m_nPresetId;
	int m_nSpeedValue;
	int m_nStopTime;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
#endif


