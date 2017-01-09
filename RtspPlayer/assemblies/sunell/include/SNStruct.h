#ifndef _SN_STRUCT_H_
#define _SN_STRUCT_H_

#include "SNPlatOS.h"

//#pragma pack(push, 1)
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

//ͼ���������ϢFRAME_INFO�ṹ�������£�
typedef struct _PACKED_1_{ 
	long nWidth;	// �������λΪ���أ��������Ƶ������Ϊ0
	long nHeight;	// ����ߣ���λΪ���أ��������Ƶ������Ϊ0
	long nStamp;	// ʱ����Ϣ����λ����
	long nType;		//�������ͣ����±�
	long nFrameRate;// ����ʱ������ͼ��֡��
}FRAME_INFO; 

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
//#pragma pack(pop)  

#endif 