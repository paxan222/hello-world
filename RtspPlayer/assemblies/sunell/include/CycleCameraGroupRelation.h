#ifndef _CYCLECAMERAGROUPRELATION_H_
#define _CYCLECAMERAGROUPRELATION_H_

#include "SNPlatOS.h"
#include "DomainConst.h"

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

class  SN_DLL_API CycleCameraGroupRelation
{
public:
	CycleCameraGroupRelation(void);
	~CycleCameraGroupRelation(void);

	//�������캯��
	CycleCameraGroupRelation(const CycleCameraGroupRelation& p_objCameraGroupRelation);

public:
	/****************************************************************************
	**������
	*		����������Ƶ�豸��Ψһ��ʶ��
	**���룺
	*		p_pszDeviceId ��������Ƶ�豸��Ψһ��ʶ�����ַ�������󳤶�ΪCONST_MAXLENGTH_DEVICEID�ֽ�,
	*						��β�ԡ�\0��������
	**�����
	*		��
	**����ֵ��
	*		true�� �ɹ�
	*		false��ʧ�� 
	**���ܣ�
	*		������p_pszDeviceId����<=CONST_MAXLENGTH_DEVICEID������true.
	*		������p_pszDeviceIdΪNULL���䳤��>CONST_MAXLENGTH_DEVICEID������false.
	*****************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/****************************************************************************
	**������
	*		��ȡ�����豸��Ψһ��ʶ��
	**���룺
	*		��
	**�����
	*		��
	*����ֵ��
	*		�����豸��Ψһ��ʶ�����ַ������� 
	**���ܣ�
	*		
	*****************************************************************************/
	const char* getDeviceId() const;


	/************************************************************************
	**������
	*		�����������Id��
	**���룺
	*		p_nCameraId ���������Id��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*    �����������Id��
	************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**������
	*		��ȡ�������Id��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������Id��
	**���ܣ�
	*     ��ȡ�������Id��
	**************************************************************************/
	const int getCameraId() const ;


	/************************************************************************
	**������
	*		���û���ID
	**���룺
	*		p_nPictureId ������ID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*    
	************************************************************************/
	void setPictureId(const int p_nPictureId);

	/************************************************************************
	**������
	*		��ȡ����ID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ID
	**���ܣ�
	*     
	**************************************************************************/
	const int getPictureId() const;


	/************************************************************************
	**������
	*		����������ID
	**���룺
	*		p_nSupGroupId ��������ID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*    ����������ID
	************************************************************************/
	void setSupGroupId(const int p_nSupGroupId);

	/************************************************************************
	**������
	*		��ȡ������ID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������ID
	**���ܣ�
	*     ��ȡ������ID
	**************************************************************************/
	const int getSupGroupId() const;


	/************************************************************************
	**������
	*		����˳��ID����Ի��棩
	**���룺
	*		p_nSupGroupId ��˳��ID����Ի��棩
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*    
	************************************************************************/
	void setSequenceId(const int p_nSequenceId);
	
	/************************************************************************
	**������
	*		��ȡ˳��ID����Ի��棩
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		˳��ID����Ի��棩
	**���ܣ�
	*     
	**************************************************************************/
	const int getSequenceId() const;
	

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objCameraGroupRelation ������������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	**************************************************************************/
	CycleCameraGroupRelation& operator = (const CycleCameraGroupRelation& p_objCameraGroupRelation);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objCameraGroupRelation��CycleCameraGroupRelation���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����CycleCameraGroupRelation��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const CycleCameraGroupRelation& p_objCameraGroupRelation);

private:
	char	m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];	//�豸id

	int		m_nCameraId;								//�����id

	int		m_nSupGroupId;								//������id

	int		m_nPictureId;								//����id

	int		m_nSequenceId;								//˳��ID����Ի��棩

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CYCLECAMERAGROUPRELATION_H_
