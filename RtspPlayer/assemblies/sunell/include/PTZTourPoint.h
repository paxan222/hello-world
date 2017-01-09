#ifndef _PTZ_TOUR_POINT_H_
#define _PTZ_TOUR_POINT_H_

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

class SN_DLL_API PTZTourPoint
{
public:
	PTZTourPoint(void);
	~PTZTourPoint(void);
public:
	void setTourPointID(const int p_nTourPointID);
	const int getTourPointID()const;

	void setWaiteTime(const int p_nWaiteTime);
	const int getWaiteTime()const;

	void setSpeed(const int p_nSpeed);
	const int getSpeed()const;

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objPTZTourPoint��PTZTourPoint���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����SMTPParam��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const PTZTourPoint& p_objPTZTourPoint);
private:
	int m_nTourPointID;		//�켣Ԥ�õ�id
	int m_nWaiteTime;		//�ȴ�ʱ��
	int m_nSpeed;			//�ٶ�


}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif

