#ifndef _SNAPSHOTSTATUS_H_
#define _SNAPSHOTSTATUS_H_

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

class SN_DLL_API SnapshotStatus
{
public:
	SnapshotStatus(void);
	~SnapshotStatus(void);

	SnapshotStatus(const int p_CameraId,const int p_Status);

	//�������캯��
	SnapshotStatus(const SnapshotStatus& p_SnapshotStatus);

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
	*		����ץ��״̬
	**���룺
	*		p_Status	ץ��״̬(0:��ʾû��ץ�ģ���0ֵ����ʾ��ǰ����ץ�ĵ�����)
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setStatus(const int p_Status);
	
	/************************************************************************
	*	������
	*		��ȡ¼��״̬
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		¼��״̬
	*************************************************************************/
	const int getStatus() const;

	/************************************************************************
	*������
	*		��ֵ����
	**���룺
	*		p_SnapshotStatus����Ƶͨ��״̬��Ϣ
	**�����
	*		��
	**����ֵ��
	*		��Ƶͨ��״̬��Ϣ
	**���ܣ�
	*
	*************************************************************************/
	SnapshotStatus& operator =(const SnapshotStatus& p_SnapshotStatus);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_SnapshotStatus��SnapshotStatus���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����SnapshotStatus��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const SnapshotStatus& p_SnapshotStatus)  const;

private:
	int		m_CameraId;					//��������
	int		m_Status;					//¼��״̬
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_SNAPSHOTSTATUS_H_
