#ifndef _MEMSTATISTIC_H_
#define _MEMSTATISTIC_H_

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

class SN_DLL_API MemStatistic
{
public:
	MemStatistic(void);
	~MemStatistic(void);

	//�������캯��
	MemStatistic(const MemStatistic& p_objMemStatistic);

public:
	/************************************************************************
	**������
	*		�������ڴ��С
	**���룺
	*		p_nMemTotalSize�����ڴ��С
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setMemTotalSize(const int p_nMemTotalSize);

	/************************************************************************
	*������
	*		��ȡ���ڴ��С
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		���ڴ��С
	*���ܣ�       
	*************************************************************************/
	const int getMemTotalSize() const;

	
	/************************************************************************
	**������
	*		���ÿ����ڴ��С
	**���룺
	*		p_nMemFreeSize�������ڴ��С
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setMemFreeSize(const int p_nMemFreeSize);

	/************************************************************************
	*������
	*		��ȡ�����ڴ��С
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		�����ڴ��С
	*���ܣ�       
	*************************************************************************/
	const int getMemFreeSize() const;


	/************************************************************************
	*������
	*		��ֵ����
	**���룺
	*		p_objMemStatistic���ڴ���Ϣ
	**�����
	*		��
	**����ֵ��
	*		�ڴ���Ϣ
	**���ܣ�
	*
	*************************************************************************/
	MemStatistic& operator =(const MemStatistic& p_objMemStatistic);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objMemStatistic��MemStatistic���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����MemStatistic��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const MemStatistic& p_objMemStatistic);


private:
	int		m_nMemTotalSize;			//�ڴ��ܴ�С����KBΪ��λ
	int		m_nMemFreeSize;				//�ڴ�ʣ���С����KBΪ��λ
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_MEMSTATISTIC_H_
