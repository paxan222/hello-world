#ifndef PSUNPACKAGERV3_H_
#define PSUNPACKAGERV3_H_

#include "SN_Struct.h"
#include "SNPlatOS.h"
#include <vector>

class Mpeg2PSBuffer;
class SNMutex;
using namespace NVDC_STRUCT;

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

class PSUnpackagerV3Impl;

class SN_DLL_API PSUnpackagerV3
{
public:
	PSUnpackagerV3(void);
	~PSUnpackagerV3(void);
	
public:

	//��������֡�ĸ�ʽ��1��ԭʼ����4��ps��
	void setFrameDataFormat(const int p_nFormat);

	//ʹ�����ݱ�־��false�����ص�֡����û����Ƶ���ݣ�true�����ص�֡������Я����Ƶ����
	void setUseDateFlag(const bool p_bFlag);

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
	*		����PS����Ƶ��
	**���룺
	*		p_objPSAVData��PS��������
	*		p_nDataLen�������ݴ�С����λΪ�ֽڡ�
	**�����
	*		
	**����ֵ��
	*		SN_SUCCESS���ɹ���
	*		SN_ERROR_QUEUE_FULL���������������Ҫ���µ��ýӿ��������ݡ�
	**���ܣ�
	*
	************************************************************************/
	int inputPSData(const char* p_szPSData, const unsigned int p_nDataLen);

	/************************************************************************
	**������
	*		�����һ֡����
	**���룺
	*		p_pstAVFrameData��֡����
	**�����
	*		
	**����ֵ��
	*		ִ�гɹ�����0������ʱ���ش����롣
	**��ע��
	*		p_pstAVFrameData������ڴ���sdk�����߷���
	************************************************************************/
	int getNextAVFrameData(NVDC_STRUCT::ST_AVFrameData* p_pstAVFrameData);

private:
	void clearBuffer();

public:
	void insertOneFrame(NVDC_STRUCT::ST_AVFrameData* p_pstAVFrameData);

private:
	Mpeg2PSBuffer*	m_pobjMpeg2PSBuffer;
	std::vector<NVDC_STRUCT::ST_AVFrameData*>	m_objFrameVector;
	SNMutex*   m_pobjLock;

	int				m_nFormat;				//��֡�����������
	bool			m_bUseDateFlag;			//ʹ�����ݱ�־

	char*			m_pszPSBuf;				//���ݻ���
	int				m_nLeftDataLen;			//������Ч����
	int				m_nBufMaxSize;			//������󳤶�

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //PSUNPACKAGERV3_H_
