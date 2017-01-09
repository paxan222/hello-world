#ifndef _RS485DEVICEINFO_H_
#define _RS485DEVICEINFO_H_

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

class SN_DLL_API RS485DeviceInfo
{
public:
	RS485DeviceInfo();
	~RS485DeviceInfo();

	RS485DeviceInfo(const RS485DeviceInfo& p_objRS485DeviceInfo);

public:
	bool setName(const char* p_pszName);
	const char* getName() const ;

	/************************************************************************
	**������
	*		���ô���ID
	**���룺
	*		p_nComId������ID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	*************************************************************************/
	void setComId(const int p_nComId);

	/************************************************************************
	**������
	*		��ȡ����ID
	**���룺
	*		��
	**��� ��
	*		��
	*����ֵ ��
	*		����ID
	**���ܣ�
	*    
	*************************************************************************/
	const int getComId() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objRS485DeviceInfo���豸����������Ϣ
	**�����
	*		��
	**����ֵ��
	*		�豸����������Ϣ
	**���ܣ�
	************************************************************************/
	RS485DeviceInfo& operator =(const RS485DeviceInfo& p_objRS485DeviceInfo);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objRS485DeviceInfo��RS485DeviceInfo���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����RS485DeviceInfo��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const RS485DeviceInfo& p_objRS485DeviceInfo);


private:
	char	m_szName[CONST_LENGTH_RS485_NAME + 1];				//�����Զ�������
	int		m_nComId;										//����ID
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_RS485DEVICEINFO_H_
