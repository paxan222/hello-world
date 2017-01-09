#ifndef _CMSDEVICEONLINESEARCHER_H_
#define _CMSDEVICEONLINESEARCHER_H_


#include "InetAddr.h"
#include "IDeviceSearcherListener.h"
#include "SNPlatOS.h"
#include <vector>
using namespace std;

class DeviceOnlineSearchThread;

class SN_DLL_API CMSDeviceOnlineSearcher
{

public:

	CMSDeviceOnlineSearcher();

	~CMSDeviceOnlineSearcher(void);

public:

	/************************************************************************
	**������
	*		����������Ƶ�豸�˿�
	**���룺
	*		p_nPort���豸�����˿�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	//void setDevicePort(const unsigned short p_nPort = 30001);
	void setIPProtoVer(const int p_nIPProtoVer);

	/************************************************************************
	**������
	*		������������
	**���룺
	*		p_nSearchCount������������-1Ϊ��������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		������Ϊ-1����������IP�б����������ֱ������ֹͣ
	************************************************************************/
	void setSearchCount(const int p_nSearchCount);

	/************************************************************************
	**������
	*		�����������
	**���룺
	*		p_nSearchInterval��������������루S��Ϊ��λ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		���setSearchCount����Ϊ1��setSearchInterval������Ч
	************************************************************************/
	void setSearchInterval(const int p_nInterval);


	/************************************************************************
	**������
	*		�����Ƿ�����ظ����豸
	**���룺
	*		p_bFlag�������ظ��豸��ʶ��true�����ˣ�false��������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setDeviceFilterFlag(const bool p_bFlag);


	/************************************************************************
	**������
	*		�����豸���������ߣ�������ΪNULLʱ��ȡ������
	**���룺
	*		p_pobjDeviceSearcherListener���豸����������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setDeviceSearcherListener(IDeviceSearcherListener* p_pobjDeviceSearcherListener);


public:
	bool addDeviceAddr(InetAddr& p_objInetAddr);
	bool addDeviceAddr(vector<InetAddr>& p_objInetAddrList);
	void clearDeviceAddrList();


	/************************************************************************
	**������
	*		��������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��start�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int start();

	/************************************************************************
	**������
	*		�ر�����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void stop();

private:

	DeviceOnlineSearchThread*	m_pobjDeviceSearcherThread;		//�豸���������߳�
};

#endif //_CMSDEVICEONLINESEARCHER_H_
