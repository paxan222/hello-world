#ifndef  _IALARM_CENTER2_MESSAGE_LISTENER_H_
#define  _IALARM_CENTER2_MESSAGE_LISTENER_H_

# include "SNPlatOS.h"

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

class SN_DLL_API IAlarmCenter2MessageListener
{
public:
	IAlarmCenter2MessageListener()
	{
		m_nListenerId = 0;
	}
	virtual ~IAlarmCenter2MessageListener()
	{

	}

public:

	
public:
	/************************************************************************
	**������
	*		���ü�����Ψһ��ʶ
	**���룺
	*		p_nListenerId �� ������Ψһ��ʶ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setListenerId(int p_nListenerId)
	{
		m_nListenerId = p_nListenerId;
	}

	/************************************************************************
	**������
	*		��ȡ������Ψһ��ʶ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		 ������Ψһ��ʶ
	**���ܣ�
	*		
	*************************************************************************/
	int getListenerId()
	{
		return m_nListenerId;
	}

	/************************************************************************
	**������
	*		������
	**���룺
	*		
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	virtual int handleMessage(const char* p_pszDeviceIP, const char* p_pszDeviceID, const int p_nMessageID) = 0;

private:

	int		m_nListenerId;				//����������Ψһ��ʶ
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/
#endif