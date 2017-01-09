#ifndef _LAYOUT_WND_INFO_H_
#define _LAYOUT_WND_INFO_H_

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

class SN_DLL_API LayoutWndInfo
{
public:
	LayoutWndInfo(void);
	~LayoutWndInfo(void);

	//�������캯��
	LayoutWndInfo(const LayoutWndInfo& p_objLayoutWndInfo);

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
	*		�����������ID��
	**���룺
	*		p_nCameraId �� �������ID��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*      
	************************************************************************/
	void setCameraId(int p_nCameraId);

	/************************************************************************
	**������
	*		��ȡ�������ID��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ID��
	**���ܣ�
	*
	************************************************************************/
	const int getCameraId() const;

	/************************************************************************
	**������
	*		���ò��Ŵ��ڵ�ID��
	**���룺
	*		p_nWndId �� ���Ŵ��ڵ�ID��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*      
	************************************************************************/
	void setPlayWndId(int p_nWndId);

	/************************************************************************
	**������
	*		��ȡ���Ŵ��ڵ�ID��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���Ŵ��ڵ�ID��
	**���ܣ�
	*
	************************************************************************/
	const int getPlayWndId() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objRecordBackupParam ��¼�񱸷ݲ�������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	**************************************************************************/
	LayoutWndInfo& operator = (const LayoutWndInfo& p_objLayoutWndInfo);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objRecordBackupParam��LayoutWndInfo���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����LayoutWndInfo��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const LayoutWndInfo& p_objPlayLayout);

private:

	int m_nPlayWndId;

	char m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];

	int m_nCameraId;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_LAYOUT_WND_INFO_H_
