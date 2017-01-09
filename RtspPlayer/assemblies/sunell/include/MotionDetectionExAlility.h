#ifndef _MOTIONDETECTIONEXALILITY_H_
#define _MOTIONDETECTIONEXALILITY_H_

#include "SNPlatOS.h"
#include <vector>
using namespace std;


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

/************************************************************************
*	�������ƶ����������Ϣ��
*	��������Ƶ��ʽ,���������,��С֡���
************************************************************************/

class SN_DLL_API MotionDetectionExAlility
{
public:
	MotionDetectionExAlility(void);
	~MotionDetectionExAlility(void);

public:
	void setMotionDetectionSupportFlag(bool p_bMotionDetectionSupportFlag);
	bool getMotionDetectionSupportFlag() const;

	bool operator < (const MotionDetectionExAlility& p_objMotionDetectionExAlility) const;

	bool operator == (const MotionDetectionExAlility& p_objMotionDetectionExAlility) const;

private:
	bool m_bMotionDetectionSupportFlag;		//�˶�����־,true��ʾ֧��,false��ʾ��֧��

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_MOTIONDETECTIONEXALILITY_H_
