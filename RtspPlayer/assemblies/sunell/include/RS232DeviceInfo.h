#ifndef _RS232DEVICEINFO_H_
#define _RS232DEVICEINFO_H_

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

class SN_DLL_API RS232DeviceInfo
{
public:
	RS232DeviceInfo();
	~RS232DeviceInfo();

	RS232DeviceInfo(const RS232DeviceInfo& p_objRS232DeviceInfo);

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
	*		p_objRS232DeviceInfo���豸����������Ϣ
	**�����
	*		��
	**����ֵ��
	*		�豸����������Ϣ
	**���ܣ�
	************************************************************************/
	RS232DeviceInfo& operator =(const RS232DeviceInfo& p_objRS232DeviceInfo);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objRS232DeviceInfo��RS232DeviceInfo���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����RS232DeviceInfo��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const RS232DeviceInfo& p_objRS232DeviceInfo);


private:
	char	m_szName[CONST_LENGTH_RS232_NAME + 1];				//�����Զ�������
	int	m_nComId;										//����ID
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_RS232DEVICEINFO_H_
