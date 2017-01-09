#ifndef _NETWORK_CARD_STATUS_H
#define _NETWORK_CARD_STATUS_H

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

class SN_DLL_API NetworkCardStatus
{
public:
	enum ChangedState
	{
		CONNECT_STATUS_CHANGE				=0x00000001,				//����״̬�ı�
		SPEED_CHANGE						=0x00000002,				//�����ٶȸı�
		IP_CONFLICT_CHANGE					=0x00000004					//IP��ͻ״̬�ı�
	};

	enum ConnectState
	{
		LINK_ON							=1,				//��������
		LINK_OFF						=2				//���߰γ�
	};

	enum NetCardSpeed
	{
		SPEED_10M						=1,					//ʮ��
		SPEED_100M						=2,					//����
		SPEED_1G						=3					//ǧ��
	};

	NetworkCardStatus(void);
	~NetworkCardStatus(void);

public:
	/************************************************************************
	*	�����������������
	*	���룺
	*		p_nNetworkCardId	�������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setNetworkCardId(int p_nNetworkCardId);

	/************************************************************************
	*	��������ȡ�������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		�������
	*************************************************************************/
	const int getNetworkCardId() const;

	/************************************************************************
	*	������������������״̬
	*	���룺
	*		p_nConnectStatus	��������״̬
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setConnectStatus(int p_nConnectStatus);

	/************************************************************************
	*	��������ȡ��������״̬
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		��������״̬
	*************************************************************************/
	const int getConnectStatus() const;


	/************************************************************************
	*	���������������ٶ�
	*	���룺
	*		p_nSpeed	�����ٶ�
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setSpeed(int p_nSpeed);

	/************************************************************************
	*	��������ȡ�����ٶ�
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		�����ٶ�
	*************************************************************************/
	const int getSpeed() const;


	/************************************************************************
	*	����������IP��ͻ��־
	*	���룺
	*		p_bIPConflictedFlag	IP��ͻ��־
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setIPConflictedFlag(bool p_bIPConflictedFlag);

	/************************************************************************
	*	��������ȡIP��ͻ��־
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		IP��ͻ��־
	*************************************************************************/
	const bool getIPConflictedFlag() const;

	void setState(int p_nState);
	const int getState() const;

	NetworkCardStatus& operator = (const NetworkCardStatus& p_objNetworkCardStatus);
	bool operator == (const NetworkCardStatus &p_objNetworkCardStatus);

private:
	int		m_nNetworkCardId;
	int		m_nConnectStatus;	//����״̬��1����������2���߱��γ�
	int		m_nSpeed;			//�����ٶȣ�1���ס�2ǧ��
	bool	m_bIPConflictedFlag;
	int		m_nState;			//ÿһλ��¼һ��״̬�ĸı�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/


#endif //_MONITORTYPE_
