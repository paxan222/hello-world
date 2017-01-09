#ifndef NETWORK_ALARM_PARAM_H
#define NETWORK_ALARM_PARAM_H

#include "NetworkAlarmEvent.h"
#include "SNPlatOS.h"
using namespace std;

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

class SN_DLL_API NetworkAlarmParam
{
public:
	NetworkAlarmParam(void);
	~NetworkAlarmParam(void);

	//�������캯��
	NetworkAlarmParam (const NetworkAlarmParam &p_objNetworkAlarmParam);
	
	/****************************************************************************
	**������
	*		�����ϱ�ʱ����
	**���룺
	*		p_nInterval���ϱ�ʱ����
	**�����
	*		��
	**����ֵ��
	*		�� 
	**���ܣ�
	*		
	*******************************************************************************/
	void setInterval(const int p_nInterval);

	/****************************************************************************
	**������
	*		����ϱ�ʱ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�ϱ�ʱ����
	**���ܣ�
	*
	*******************************************************************************/
	const int getInterval() const;

	/************************************************************************
	**������
	*		�������籨���¼�
	**���룺
	*		p_objNetworkAlarmEventList�����籨���¼��б�
	**�����
	*		��
	**����ֵ��
	*		
	**���ܣ�
	*      
	**************************************************************************/
	void setNetworkAlarmEvent(const vector<NetworkAlarmEvent>& p_objNetworkAlarmEventList);

	/************************************************************************
	**������
	*		��ȡ���籨���¼��б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���籨���¼��б�
	**���ܣ�
	*      
	**************************************************************************/
	vector<NetworkAlarmEvent>* getNetworkAlarmEvent() const;

	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objNetworkAlarmParam�����籨��
	**�����
	*		��
	**����ֵ��
	*		��ֵ������籨��
	**���ܣ�
	*		
	*****************************************************************************/
	NetworkAlarmParam& operator = (const NetworkAlarmParam &p_objNetworkAlarmParam);

private:

	unsigned int					m_nInterval;					//�ϱ��������λΪ�룬��С���Ϊ10�룬���Ϊ86400��(1��)
	vector<NetworkAlarmEvent>		m_objNetworkAlarmEventList;		//�������籨���¼��б�

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif //NETWORK_ALARM_PARAM_H
