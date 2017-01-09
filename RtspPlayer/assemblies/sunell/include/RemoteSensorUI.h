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
	**概述：
	*		生成对话框
	**输入：
	*		p_PDeviceInfo	设备信息
	*		p_nLanguage		语言类型，参照"LanguageId.h"
	*		p_nTimeout		超时时间
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		生成配置界面
	************************************************************************/
	void show(int p_nLanguage);

	/************************************************************************
	**概述：
	*		生成对话框(v1)
	**输入：
	*		p_pszXmlFilePath： Xml文件路径
	*		p_nLanguage		： 语言类型，参照"LanguageId.h"
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		生成配置界面,第一代前端配置接口
	************************************************************************/
	void show(const char* p_pszXmlFilePath, int p_nLanguage); 

	/************************************************************************
	**概述：
	*		生成对话框
	**输入：
	*		p_pszStyleFilePath： 样式文件路径
	*		p_szCommonFilePath： 通用文件路径
	*		p_pszLanguageFilePath： 语言文件路径
	*		p_nLanguage： 语言类型，参照"LanguageId.h"
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		生成配置界面，第二代前端配置接口
	************************************************************************/
	void show(const char *p_pszStyleFilePath, const char *p_szCommonFilePath, const char *p_pszLanguageFilePath,int p_nLanguage);
private:
	DeviceInfoEx	m_objDeviceInfo;
	int				m_nTimeout;
};
