#ifndef _DEVICEWORKSTATE_H_
#define _DEVICEWORKSTATE_H_

#include "AlarmInStatistic.h"
#include "AlarmOutStatistic.h"
#include "CpuStatistic.h"
#include "DiskStatistic.h"
#include "MemStatistic.h"
#include "VideoChannelStatistic.h"
#include "SNPlatOS.h"
#include<vector>
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

class SN_DLL_API DeviceWorkState
{
public:
	DeviceWorkState(void);
	~DeviceWorkState(void);
	
	//�������캯��
	DeviceWorkState(const DeviceWorkState& p_objDeviceWorkState);

public:
	
	/************************************************************************
	**������
	*		����cpuͳ����Ϣ
	**���룺
	*		p_objCpuStatistic��cpuͳ����Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setCpuStatistic(const CpuStatistic& p_objCpuStatistic);
	
	/************************************************************************
	*������
	*		��ȡcpuͳ����Ϣ
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		cpuͳ����Ϣ
	*���ܣ�       
	*************************************************************************/
	const CpuStatistic& getCpuStatistic() const;


	/************************************************************************
	**������
	*		�����ڴ�ͳ����Ϣ
	**���룺
	*		p_objMemStatistic���ڴ�ͳ����Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setMemStatistic(const MemStatistic& p_objMemStatistic);
	
	/************************************************************************
	*������
	*		��ȡ�ڴ�ͳ����Ϣ
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		�ڴ�ͳ����Ϣ
	*���ܣ�       
	*************************************************************************/
	const MemStatistic& getMemStatistic() const;


	/************************************************************************
	**������
	*		���ô���ͳ����Ϣ
	**���룺
	*		p_objDiskStatisticList������ͳ����Ϣ�б�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setDiskStatisticList(const vector<DiskStatistic>& p_objDiskStatisticList);
	
	/************************************************************************
	*������
	*		��ȡ����ͳ����Ϣ
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		����ͳ����Ϣ
	*���ܣ�       
	*************************************************************************/
	const vector<DiskStatistic>* getDiskStatisticList() const;

	
	/************************************************************************
	**������
	*		������Ƶͨ��ͳ����Ϣ
	**���룺
	*		p_objVideoChannelStatisticList����Ƶͨ��ͳ����Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setVideoChannelStatisticList(const vector<VideoChannelStatistic>& p_objVideoChannelStatisticList);
	
	/************************************************************************
	*������
	*		��ȡ��Ƶͨ��ͳ����Ϣ
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		��Ƶͨ��ͳ����Ϣ
	*���ܣ�       
	*************************************************************************/
	const vector<VideoChannelStatistic>* getVideoChannelStatisticList() const;

	
	/************************************************************************
	**������
	*		���ñ�������ͨ��ͳ����Ϣ
	**���룺
	*		p_objAlarmInStatisticList����������ͨ��ͳ����Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setAlarmInStatisticList(const vector<AlarmInStatistic>&	p_objAlarmInStatisticList);
	
	/************************************************************************
	*������
	*		��ȡ��������ͨ��ͳ����Ϣ
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		��������ͨ��ͳ����Ϣ
	*���ܣ�       
	*************************************************************************/
	const vector<AlarmInStatistic>* getAlarmInStatisticList() const;

	
	/************************************************************************
	**������
	*		���ñ������ͨ��ͳ����Ϣ
	**���룺
	*		p_objAlarmOutStatisticList���������ͨ��ͳ����Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setAlarmOutStatisticList(const vector<AlarmOutStatistic>& p_objAlarmOutStatisticList);
	
	/************************************************************************
	*������
	*		��ȡ�������ͨ��ͳ����Ϣ
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		�������ͨ��ͳ����Ϣ
	*���ܣ�       
	*************************************************************************/
	const vector<AlarmOutStatistic>* getAlarmOutStatisticList() const;

	/************************************************************************
	*������
	*		��ֵ����
	**���룺
	*		p_objDeviceWorkState���豸����״̬��Ϣ
	**�����
	*		��
	**����ֵ��
	*		DDNS��Ϣ
	**���ܣ�
	*
	*************************************************************************/
	DeviceWorkState& operator =(const DeviceWorkState& p_objDeviceWorkState);


private:
	
	CpuStatistic					m_objCpuStatistic;					//cpuͳ����Ϣ
	MemStatistic					m_objMemStatistic;					//�ڴ�ͳ����Ϣ
	vector<DiskStatistic>			m_objDiskStatisticList;				//����ͳ����Ϣ
	vector<VideoChannelStatistic>	m_objVideoChannelStatisticList;		//��Ƶͨ��ͳ����Ϣ
	vector<AlarmInStatistic>		m_objAlarmInStatisticList;			//��������ͳ����Ϣ
	vector<AlarmOutStatistic>		m_objAlarmOutStatisticList;			//�������ͳ����Ϣ
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_DEVICEWORKSTATE_H_
