#ifndef _CMSREGISTERINFOPARAM_H_
#define _CMSREGISTERINFOPARAM_H_

#include "DomainConst.h"
#include "SNPlatOS.h"
#include "CMSRegisterServerParamV2.h"
#include "CMSDeviceRegisterInfoParam.h"
#include "CMSCameraRegisterInfoParam.h"
#include "CMSExternConfigParamV2.h"	
#include <vector>

/**********************************************************************/
//此处用于控制文件编译字节对齐，拷贝时两行注释间内容需一起拷贝，
//结束处的“#ifdef PRAGMA_PACK”部分也要一起拷贝，否则pragma pack入栈出栈不匹配
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

class SN_DLL_API CMSRegisterInfoParam
{
public:
	CMSRegisterInfoParam();

	~CMSRegisterInfoParam();

	CMSRegisterInfoParam(const CMSRegisterInfoParam &p_objCMSRegisterInfoParam);

public:
	/****************************************************************************
	**概述：
	*		设置协议名称
	**输入：
	*	p_pszProtocolName ：字符串，最大长度为CONST_MAXLENTH_PROTOCOL_NAME字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszProtocolName长度<=CONST_MAXLENTH_PROTOCOL_NAME，返回true，
	*	并保存到m_szProtocolName;
	*	若输入p_pszProtocolName长度>CONST_MAXLENTH_PROTOCOL_NAME，返回false
	*****************************************************************************/	
	bool setProtocolName(const char *p_pszProtocolName);

	/****************************************************************************
	**概述：
	*		获取协议名称
	**输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存协议名称的m_szProtocolName字符串指针。 
	*功能：
	*	获取保存有协议名称的字符串指针
	*****************************************************************************/
	const char *getProtocolName() const;

	/****************************************************************************
	**概述：
	*		设置协议版本
	**输入：
	*	p_pszProtocolVersion ：字符串，最大长度为CONST_MAXLENTH_PROTOCOL_VERSION字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszProtocolVersion长度<=CONST_MAXLENTH_PROTOCOL_VERSION，返回true，
	*	并保存到m_szProtocolVersion;
	*	若输入p_pszProtocolVersion长度>CONST_MAXLENTH_PROTOCOL_VERSION，返回false
	*****************************************************************************/	
	bool setProtocolVersion(const char *p_pszProtocolVersion);

	/****************************************************************************
	**概述：
	*		获取协议版本
	**输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存协议版本的m_szProtocolVersion字符串指针。 
	**功能：
	*	获取保存有协议版本的字符串指针
	*****************************************************************************/
	const char *getProtocolVersion() const;

	/****************************************************************************
	**概述：
	*		设置协议连接状态
	**输入：
	*	p_pszDeviceProtocolState ：字符串，最大长度为CONST_MAXLENGTH_DEVICE_STATUS字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszDeviceProtocolState长度<=CONST_MAXLENGTH_DEVICE_STATUS，返回true，
	*	并保存到m_szDeviceProtocolState;
	*	若输入p_pszDeviceProtocolState长度>CONST_MAXLENGTH_DEVICE_STATUS，返回false
	*****************************************************************************/	
	bool setDeviceProtocolState(const char *p_pszDeviceProtocolState);

	/****************************************************************************
	**概述：
	*		获取协议连接状态
	**输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存协议连接状态的m_szDeviceProtocolState字符串指针。 
	**功能：
	*	获取保存有协议连接状态的字符串指针
	*****************************************************************************/
	const char *getDeviceProtocolState() const;

	/****************************************************************************
	**概述：
	*		设置/获取CMS注册服务器参数
	**输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	0	设置成功
	*	-1  设置失败
	**功能：
	*	设置/获取CMS注册服务器参数
	*****************************************************************************/
	int setCMSRegisterServerParam(const std::vector<CMSRegisterServerParamV2>& p_objCMSRegisterServerParamList);

	const std::vector<CMSRegisterServerParamV2>& getCMSRegisterServerParam() const;

	/****************************************************************************
	**概述：
	*		设置/获取CMS设备注册参数
	**输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	0	设置成功
	*	-1  设置失败
	**功能：
	*	设置/获取CMS设备注册参数
	*****************************************************************************/
	int setCMSDeviceRegisterInfoParam(const std::vector<CMSDeviceRegisterInfoParam>& p_objCMSDeviceRegisterInfoParamList);

	const std::vector<CMSDeviceRegisterInfoParam>& getCMSDeviceRegisterInfoParam() const;

	/****************************************************************************
	**概述：
	*		设置/获取CMS通道注册参数
	**输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	0	设置成功
	*	-1  设置失败
	**功能：
	*	设置/获取CMS通道注册参数
	*****************************************************************************/
	int setCMSCameraRegisterInfoParam(const std::vector<CMSCameraRegisterInfoParam>& p_objCMSCameraRegisterInfoParamList);

	const std::vector<CMSCameraRegisterInfoParam>& getCMSCameraRegisterInfoParam() const;

	/****************************************************************************
	**概述：
	*		设置/获取CMS扩展配置参数
	**输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	0	设置成功
	*	-1  设置失败
	**功能：
	*	设置/获取CMS扩展配置参数
	*****************************************************************************/
	int setCMSExternConfigParam(const std::vector<CMSExternConfigParamV2>& p_objCMSExternConfigParamList);

	const std::vector<CMSExternConfigParamV2>& getCMSExternConfigParam() const;

	CMSRegisterInfoParam &operator =(const CMSRegisterInfoParam &p_objCMSRegisterInfoParam);
private:
	char			m_szDeviceProtocolState[CONST_MAXLENGTH_DEVICE_STATUS + 1];	
	char			m_szProtocolName[CONST_MAXLENTH_PROTOCOL_NAME + 1];							//协议名称
	char			m_szProtocolVersion[CONST_MAXLENTH_PROTOCOL_VERSION + 1];					//协议版本
	std::vector<CMSRegisterServerParamV2>		m_objCMSRegisterServerParamList;
	std::vector<CMSDeviceRegisterInfoParam> m_objCMSDeviceRegisterInfoParamList;
	std::vector<CMSCameraRegisterInfoParam> m_objCMSCameraRegisterInfoParamList;
	std::vector<CMSExternConfigParamV2>		m_objCMSExternConfigParamList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/


#endif //_CMSPROTOCOLPARAM_H_
