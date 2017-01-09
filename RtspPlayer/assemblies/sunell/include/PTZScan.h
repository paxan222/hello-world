#ifndef _PTZScan_H_
#define _PTZScan_H_

#include "DomainConst.h"

#include <string.h>
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

class SN_DLL_API PTZScan
{

public:
	PTZScan();
	~PTZScan();

	PTZScan(const PTZScan& p_objPTZScan);

public:

	/************************************************************************
	**������
	*		��������ͷID��
    **���룺
	*		p_nCameraId ������ͷ��ID��
	**�����
	*		��
	*����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**������
	*		��ȡ����ͷ��ID��
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ͷ��ID��
	**���ܣ�
	*    
	************************************************************************/
	const int getCameraId() const;

	/************************************************************************
	**������
	*		������̨ɨ��ID��
	**���룺
	*		p_nScanId ����̨ɨ���ID��
	**�����
	*		��
	*����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setScanId(const int p_nScanId);

	/************************************************************************
	**������
	*		��ȡɨ���ID��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��ȡɨ���ID��
	**���ܣ�
	*    
	************************************************************************/
	const int getScanId() const;

	/************************************************************************
	**������
	*		������̨ɨ�������
    **���룺
	*	  p_pszScanName ����̨ɨ������֣��ַ�������󳤶�
	*						  ΪCONST_MAXLENTH_PTZ_PROTOCOL_NAME�ֽ�,��β�ԡ�\0�������� 
	**�����
	*		��
	**����ֵ��
	*		true ���ɹ�
	*		false��ʧ��
	*���ܣ�
	*    ������p_pszScanName����<=CONST_MAXLENGTH_PTZ_SCAN_NAME������true�������浽m_szProtocolName;
	*	 ������p_pszScanNameΪnull�����䳤��>CONST_MAXLENGTH_PTZ_SCAN_NAME������false
	************************************************************************/
	bool setScanName(const char* p_pszScanName);

	/************************************************************************
	**������
	*		��ȡ��̨ɨ�������
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��̨ɨ�������
	**���ܣ�
	*		
	************************************************************************/
	const char* getScanName() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objPTZScan����̨ɨ��
	**�����
	*		��
	**����ֵ��
	*		��̨ɨ��
	**���ܣ�
	************************************************************************/
	PTZScan& operator =(const PTZScan& p_objPTZScan);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objPTZScan��PTZScan���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����PTZScan��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const PTZScan& p_objPTZScan) const;

	bool operator < (const PTZScan& p_objPTZScan) const;

private:

	int		m_nCameraId;												//����ͷID��
	
	int		m_nScanId;													//��̨ɨ���ID��
	
	char	m_szScanName[CONST_MAXLENGTH_PTZ_SCAN_NAME + 1];			//��̨ɨ�������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_PTZScan_H_

