#ifndef _BROADCASTPARAM_H_
#define _BROADCASTPARAM_H_

#include "DomainConst.h"
#include "const.h"
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

class SN_DLL_API BroadcastParam
{

public:
	BroadcastParam(void);
	~BroadcastParam(void);

	//�������캯��
	BroadcastParam(const BroadcastParam& p_objBroadcastParam);

public:


	/************************************************************************
	**������
	*		�����Ƿ����ù㲥��־
	**���룺
	*		p_bFlag���Ƿ����ù㲥��־
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	�����Ƿ����ù㲥��־
	************************************************************************/
	void setBroadcastEnableFlag(const bool p_bFlag);

	/************************************************************************
	**������
	*		��ȡ�Ƿ����ù㲥��־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�Ƿ����ù㲥��־
	**���ܣ�
	*	��ȡ�Ƿ����㲥��־
	************************************************************************/
	const bool getBroadcastEnableFlag() const ;


	/************************************************************************
	**������
	*		���ù㲥�˿�
	**���룺
	*		p_nBroadcastPort ���㲥�˿�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	void setBroadcastPort(const unsigned short p_nBroadcastPort);

	/************************************************************************
	**������
	*		��ȡ�㲥�˿�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�㲥�˿�
	**���ܣ�
	*
	************************************************************************/
	const unsigned short getBroadcastPort() const;


	/************************************************************************
	**������
	*		���÷��͹㲥���
	**���룺
	*		p_nBroadcastServerPort���㲥��������루s��Ϊ��λ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	void setBroadcastInterval(const int p_nBroadcastInterval);

	/************************************************************************
	**������
	*		��ȡ���͹㲥���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�㲥���,���루s��Ϊ��λ
	**���ܣ�
	*
	************************************************************************/
	const int getBroadcastInterval() const;


	//������ֵ����λ1
	void setReserveValue1(const int p_nReserveValue1);
	//��ȡ��ֵ����λ1
	const int getReserveValue1() const;


	//������ֵ����λ2
	void setReserveValue2(const int p_nReserveValue2);
	//��ȡ��ֵ����λ2
	const int getReserveValue2() const;


	//������ֵ����λ3
	void setReserveValue3(const int p_nReserveValue3);
	//��ȡ��ֵ����λ3
	const int getReserveValue3() const;

	
	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objBroadcastParam���㲥������Ϣ
	**�����
	*		��
	**����ֵ��
	*		�㲥������Ϣ
	*���ܣ�
	*
	************************************************************************/
	BroadcastParam& operator =(const BroadcastParam& p_objBroadcastParam);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objBroadcastParam��BroadcastParam���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����BroadcastParam��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const BroadcastParam& p_objBroadcastParam);

private:

	bool				m_bBroadcastEnableFlag;							//�Ƿ����ù㲥(false�������ã� true������)

	unsigned short		m_nBroadcastPort;								//�㲥�������Ķ˿�
	
	int					m_nBroadcastInterval;							//���͹㲥���������Ϊ��λ

	int					m_nReserveValue1;								//��ֵ����λ1
	int					m_nReserveValue2;								//��ֵ����λ2
	int					m_nReserveValue3;								//��ֵ����λ3

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_BROADCASTPARAM_H_
