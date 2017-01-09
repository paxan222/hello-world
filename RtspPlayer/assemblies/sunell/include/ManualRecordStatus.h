#ifndef _MANUALRECORDSTATUS_H_
#define _MANUALRECORDSTATUS_H_

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

class SN_DLL_API ManualRecordStatus
{
public:
	enum RecordStatus
	{
		RECORDSTATUS_NO_RECORD				= 0,		//��¼��
		RECORDSTATUS_RECORD					= 1			//��¼��
	};

public:
	ManualRecordStatus(void);
	~ManualRecordStatus(void);

	//�������캯��
	ManualRecordStatus(const ManualRecordStatus& p_objManualRecordStatus);

public:
	/************************************************************************
	**������
	*		������������
	**���룺
	*		p_nCameraId����������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setCameraId(const int p_nCameraId);
	
	/************************************************************************
	*������
	*		��ȡ��������
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		��������
	*���ܣ�       
	*************************************************************************/
	const int getCameraId() const;

	
	/************************************************************************
	**������
	*		����¼��״̬
	**���룺
	*		p_btRecordStatus��¼��״̬
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setRecordStatus(const byte p_btRecordStatus);
	
	/************************************************************************
	*������
	*		��ȡ¼��״̬
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		¼��״̬
	*���ܣ�       
	*************************************************************************/
	const byte getRecordStatus() const;

	/************************************************************************
	*������
	*		��ֵ����
	**���룺
	*		p_objManualRecordStatus����Ƶͨ��״̬��Ϣ
	**�����
	*		��
	**����ֵ��
	*		��Ƶͨ��״̬��Ϣ
	**���ܣ�
	*
	*************************************************************************/
	ManualRecordStatus& operator =(const ManualRecordStatus& p_objManualRecordStatus);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objManualRecordStatus��ManualRecordStatus���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����ManualRecordStatus��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const ManualRecordStatus& p_objManualRecordStatus)  const;

	bool operator < (const ManualRecordStatus& p_objManualRecordStatus) const;

private:

	int		m_nCameraId;				//��������

	int		m_nRecordStatus;			//¼��״̬
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_MANUALRECORDSTATUS_H_
