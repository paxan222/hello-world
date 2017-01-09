#ifndef _IPC_NET_WORK_CARD_ABILITY_H
#define _IPC_NET_WORK_CARD_ABILITY_H

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

class SN_DLL_API IPCNetworkCardAbility
{
public:
	IPCNetworkCardAbility(void);
	~IPCNetworkCardAbility(void);

	/************************************************************************
	*	�����������������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setNetWorkCardId(int p_nNetWorkCardId);

	/************************************************************************
	*	��������ȡ�������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		�������
	*************************************************************************/
	int getNetWorkCardId() const;

	/************************************************************************
	*	������������������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		true	�����óɹ�
	*		false   ������ʧ��
	*************************************************************************/
	bool setNetWorkCardName(const char* p_pszNetWorkCardName);

	/************************************************************************
	*	��������ȡ��������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		��������
	*************************************************************************/
	const char* getNetWorkCardName()const;

	/************************************************************************
	*	������������������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		true	�����óɹ�
	*		false   ������ʧ��
	*************************************************************************/
	bool setDescription(const char* p_pszDescription);
	
	/************************************************************************
	*	��������ȡ��������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		��������
	*************************************************************************/
	const char* getDescription()const;

	void setSupportAlarm(bool p_bSupportAlarm);
	bool getSupportAlarm() const;

private:
	
	int								m_nNetWorkCardId;									//�������
	char							m_szNetWorkCardName[CONST_NETWORK_CARD_NAME + 1];	//��������
	char							m_szDescription[CONST_NETWORK_CARD_DESCRIPTION + 1];//��������							//
	bool							m_bSupportAlarm;									//֧�ֶ�������

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif //_IPC_NET_WORK_CARD_ABILITY_H
