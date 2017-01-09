#pragma once
#pragma warning( push )
#pragma warning( disable : 4786 )

#include "SNPlatOS.h"
#include "DeviceInfoEx.h"
#include <string>

class SN_DLL_API RemoteSensorUI
{
public:
	RemoteSensorUI();
	RemoteSensorUI(const DeviceInfoEx &p_objDeviceInfo,int p_nTimeout = 10000);

	~RemoteSensorUI();

	void setDeviceInfo(const DeviceInfoEx &p_objDeviceInfo);

	void setTimeout(int p_nTimeout);
public:
	/************************************************************************
	**������
	*		���ɶԻ���
	**���룺
	*		p_PDeviceInfo	�豸��Ϣ
	*		p_nLanguage		�������ͣ�����"LanguageId.h"
	*		p_nTimeout		��ʱʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�������ý���
	************************************************************************/
	void show(int p_nLanguage);

	/************************************************************************
	**������
	*		���ɶԻ���(v1)
	**���룺
	*		p_pszXmlFilePath�� Xml�ļ�·��
	*		p_nLanguage		�� �������ͣ�����"LanguageId.h"
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�������ý���,��һ��ǰ�����ýӿ�
	************************************************************************/
	void show(const char* p_pszXmlFilePath, int p_nLanguage); 

	/************************************************************************
	**������
	*		���ɶԻ���
	**���룺
	*		p_pszStyleFilePath�� ��ʽ�ļ�·��
	*		p_szCommonFilePath�� ͨ���ļ�·��
	*		p_pszLanguageFilePath�� �����ļ�·��
	*		p_nLanguage�� �������ͣ�����"LanguageId.h"
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�������ý��棬�ڶ���ǰ�����ýӿ�
	************************************************************************/
	void show(const char *p_pszStyleFilePath, const char *p_szCommonFilePath, const char *p_pszLanguageFilePath,int p_nLanguage);
private:
	DeviceInfoEx	m_objDeviceInfo;
	int				m_nTimeout;
};
