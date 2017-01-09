#ifndef TSUNPACKAGER_H_
#define TSUNPACKAGER_H_

#include "SN_Struct.h"
#include "SNPlatOS.h"

#if (defined(WIN32) || defined(_WIN32_WCE))
	#include <winsock2.h>
#endif


typedef long (CALLBACK* UnpackageCallBack) (long hHandle, NVDC_STRUCT::ST_AVFrameData* p_pstAVFrameData, void* pUserData);

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
/**********************************************************************//**********************************************************************/

class TSUnpackagerImpl;

class SN_DLL_API TSUnpackager
{
public:
	TSUnpackager(void);
	~TSUnpackager(void);
	
public:

	/************************************************************************
	**������
	*		���ý���ص�����,��UnpackageCallBack����NULLʱȡ���ص���
	**���룺
	*		hHandle���ص�������������UnpackageCallBackִ�У��ش��ò�����һ��32λ����ֵ����û�о��ʱ��������NULL
	*		fUnpackageCallBack������ص�������
	**�����
	*		�ޡ�
	**����ֵ��
	*		ִ�гɹ�����0������ʱ���ش����롣
	**��ע��
	*		�������ܿ��ǣ�fUnpackageCallBack�ص��ӿ��е�p_pstAVFrameData������ڴ���sdk�ڲ����䣬�ڵ���stop֮�������ڴ�ᱻ�ͷ�
	*		����stop֮ǰ��ȷ��p_pstAVFrameData����ʹ��
	************************************************************************/
	void setUnpackageCallBack(long hHandle, UnpackageCallBack fUnpackageCallBack, void* pUserData);

	/************************************************************************
	**������
	*		������������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ִ�гɹ�����true������ʱ����false��
	**���ܣ�
	************************************************************************/
	bool start();

	/************************************************************************
	**������
	*		ֹͣ������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		
	**���ܣ�
	************************************************************************/
	void stop();

	/************************************************************************
	**������
	*		����TS����Ƶ��
	**���룺
	*		p_objTSAVData��TS��������
	*		p_nDataLen�������ݴ�С����λΪ�ֽڡ�
	**�����
	*		
	**����ֵ��
	*		SN_SUCCESS���ɹ���
	*		SN_ERROR_QUEUE_FULL���������������Ҫ���µ��ýӿ��������ݡ�
	**���ܣ�
	*
	************************************************************************/
	int inputTSData(const char* p_szTSData, const unsigned int p_nDataLen);

private:
	TSUnpackagerImpl*	m_pTSUnpackagerImpl;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif
