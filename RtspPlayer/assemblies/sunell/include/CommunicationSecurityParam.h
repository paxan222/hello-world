#ifndef  _COMMUNICATION_SECURITY_PARAM_H
#define  _COMMUNICATION_SECURITY_PARAM_H

#include "SNPlatOS.h"
#include "DomainConst.h"

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


class SN_DLL_API CommunicationSecurityParam
{

public:
	enum	SN_WEBMODE
	{
		WEBMODE_HTTP = 1,
		WEBMODE_HTTP_HTTPS = 2,
		WEBMODE_HTTPS =3
	};
public:

	CommunicationSecurityParam(void);
	~CommunicationSecurityParam(void);

	/*************************************************************
	*	概述：设置Web端登陆网络音视频设备模式
	*	输入：
	*		p_nWebMode:Web端登陆网络音视频设备登陆模式
	*	输出：
	*		无
	*	返回值：
	*		无
	*	备注：
	*		 WebMode：1 http；2 https和http；3 https
	**************************************************************/
	void setWebMode(const int& p_nWebMode);

	/*************************************************************
	*	概述：获取Web端登陆网络音视频设备登陆模式
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		Web端登陆网络音视频设备登陆模式
	*	备注：
	*		 WebMode：1 http；2 https和http；3 https
	**************************************************************/
	const int& getWebMode()const;

	/*************************************************************
	*	概述：设置Web端与网络音视频设备通讯是否加密标志
	*	输入：
	*		p_bCommunicationEncryptFlag：加密标志
	*	输出：
	*		无
	*	返回值：
	*		无
	*	备注：
	*		true： 加密
	*		flase：不加密
	**************************************************************/
	void setCommunicationEncryptFlag(const bool& p_bCommunicationEncryptFlag);

	/*************************************************************
	*	概述：获取Web端与网络音视频设备通讯是否加密标志
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		否加密标志
	*	备注：
	*		true： 加密
	*		flase：不加密
	**************************************************************/
	const bool& getCommunicationEncryptFlag()const;

	CommunicationSecurityParam& operator=(const CommunicationSecurityParam& p_objCommunicationSecurityParam);

private:
	int m_nWebMode; //默认值为0，但实际不合法   WebMode：1 http；2 https和http；3 https

	bool m_bCommunicationEncryptFlag;//默认值为false

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif  //_COMMUNICATION_SECURITY_PARAM_H