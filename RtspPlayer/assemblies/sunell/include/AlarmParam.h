#ifndef _ALARMPARAM_H_
#define _ALARMPARAM_H_


#include "DomainConst.h"
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

class SN_DLL_API AlarmParam
{
public:
	AlarmParam();
	~AlarmParam();
	AlarmParam (const AlarmParam &p_objAlarmParam);

public:
	/************************************************************************
	**������
	*		���ñ������
	**���룺
	*		  p_nAlarmInterval ���������������Ϊ��λ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*      
	************************************************************************/
	void setAlarmInterval(const int p_nAlarmInterval);

	/************************************************************************
	**������
	*		��ȡ�������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������
	**���ܣ�
	*       
	**************************************************************************/
	const int getAlarmInterval() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objAlarmParam ���������ݶ���
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	AlarmParam& operator = (const AlarmParam &p_objAlarmParam);

private:

	int		m_nAlarmInterval;											//�������
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_ALARMPARAM_H_

