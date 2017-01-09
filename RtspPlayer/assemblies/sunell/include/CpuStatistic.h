#ifndef _CPUSTATISTIC_H_
#define _CPUSTATISTIC_H_

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

class SN_DLL_API CpuStatistic
{
public:
	enum CpuStatus
	{
		CPUSTATUS_NORMAL				= 0,	//����
		CPUSTATUS_HIGH					= 1		//CPUռ����̫��
	};
public:
	CpuStatistic(void);
	~CpuStatistic(void);
	
	//�������캯��
	CpuStatistic(const CpuStatistic& p_objCpuStatistic);

public:

	/************************************************************************
	**������
	*		����cpuʹ����
	**���룺
	*		p_fCpuPercent��cpuʹ����,�磺CPUʹ����Ϊ45.5%��������Ϊ45.5
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setCpuPercent(const float p_fCpuPercent);

	/************************************************************************
	*������
	*		��ȡcpuʹ����
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		cpuʹ����
	*���ܣ�       
	*************************************************************************/
	const float getCpuPercent() const;


	/************************************************************************
	**������
	*		����cpu����״̬
	**���룺
	*		p_btCpuStatus��cpu����״̬
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setCpuStatus(const byte p_btCpuStatus);

	/************************************************************************
	*������
	*		��ȡcpu����״̬
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		cpu����״̬
	*���ܣ�       
	*************************************************************************/
	const byte getCpuStatus() const;

	/************************************************************************
	*������
	*		��ֵ����
	**���룺
	*		p_objCpuStatistic��CPUͳ����Ϣ
	**�����
	*		��
	**����ֵ��
	*		CPUͳ����Ϣ
	**���ܣ�
	*
	*************************************************************************/
	CpuStatistic& operator =(const CpuStatistic& p_objCpuStatistic);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objCpuStatistic��CpuStatistic���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����CpuStatistic��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const CpuStatistic& p_objCpuStatistic);


private:
	float		m_fCpuPercent;				//�豸cpu�ٷֱ�
	byte		m_btCpuStatus;				//�豸cpu����״̬
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_CPUSTATISTIC_H_
