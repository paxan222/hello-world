#ifndef _DISKSTATISTIC_H_
#define _DISKSTATISTIC_H_

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

class SN_DLL_API DiskStatistic
{
public:
	enum DiskStatus
	{
		DISKSTATUS_DORMANCY					= 1,	//����״̬
		DISKSTATUS_ABNORMAL					= 2,	//������״̬
		DISKSTATUS_NOT_EXISTENT				= 3,	//���̲�����
		DISKSTATUS_WRITE_PROTECT			= 4,	//����д����	
		DISKSTATUS_NOT_FORMAT				= 5,	//����δ��ʽ��
		DISKSTATUS_FORMATTING				= 6		//�������ڸ�ʽ��
	};

public:
	DiskStatistic(void);
	~DiskStatistic(void);

	//�������캯��
	DiskStatistic(const DiskStatistic& p_objDiskStatistic);

public:
	/************************************************************************
	**������
	*		���ô��̱��
	**���룺
	*		p_nDiskId�����̱��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setDiskId(const int p_nDiskId);

	/************************************************************************
	*������
	*		��ȡ���̱��
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		���̱��
	*���ܣ�       
	*************************************************************************/
	const int getDiskId() const;


	/************************************************************************
	**������
	*		���ô����ܴ�С
	**���룺
	*		p_nDiskTotalSize�������ܴ�С,��KBΪ��λ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setDiskTotalSize(const int p_nDiskTotalSize);

	/************************************************************************
	*������
	*		��ȡ�����ܴ�С
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		�����ܴ�С����KBΪ��λ
	*���ܣ�       
	*************************************************************************/
	const int getDiskTotalSize() const;


	/************************************************************************
	**������
	*		���ô���ʣ��ռ�
	**���룺
	*		p_nDiskFreeSize������ʣ��ռ�,��KBΪ��λ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setDiskFreeSize(const int p_nDiskFreeSize);

	/************************************************************************
	*������
	*		��ȡ����ʣ��ռ�
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		����ʣ��ռ�
	*���ܣ�       
	*************************************************************************/
	const int getDiskFreeSize() const;


	/************************************************************************
	**������
	*		���ô���״̬
	**���룺
	*		p_btDiskStatus������״̬
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setDiskStatus(const byte p_btDiskStatus);

	/************************************************************************
	*������
	*		��ȡ����״̬
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		����״̬
	*���ܣ�       
	*************************************************************************/
	const byte getDiskStatus() const;


	/************************************************************************
	*������
	*		��ֵ����
	**���룺
	*		p_objDiskStatistic��������Ϣ
	**�����
	*		��
	**����ֵ��
	*		DDNS��Ϣ
	**���ܣ�
	*
	*************************************************************************/
	DiskStatistic& operator =(const DiskStatistic& p_objDiskStatistic);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objDiskStatistic��DiskStatistic���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����DiskStatistic��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const DiskStatistic& p_objDiskStatistic) const;
	bool operator < (const DiskStatistic& p_objDiskStatistic) const;


private:
	int		m_nDiskId;				//���̱��

	int		m_nDiskTotalSize;		//�����ܴ�С,��KBΪ��λ

	int		m_nDiskFreeSize;		//����ʣ���С,��KBΪ��λ

	byte	m_btDiskStatus;			//����״̬
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DISKSTATISTIC_H_
