#ifndef _I3GMESSAGECONNECTPOLICYPARAM_H_
#define _I3GMESSAGECONNECTPOLICYPARAM_H_

#include "DomainConst.h"
#include "SNPlatOS.h"

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

class SN_DLL_API I3GMessageConnectPolicyParam
{
public:
	I3GMessageConnectPolicyParam(void);
	~I3GMessageConnectPolicyParam(void);

public:
	
	/************************************************************************
	**概述：
	*		设置启用标志
	**输入：
	*		p_bEnableFlag:启用标志
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setEnableFlag(const bool p_bEnableFlag);

	/************************************************************************
	**概述：
	*		获取启用标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		
	************************************************************************/
	const bool getEnableFlag() const;

	/************************************************************************
	*	概述：设置连接消息电话号码
	*	输入：
	*		p_pszConnectMessagePhoneNO:连接消息电话号码
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	bool setConnectMessagePhoneNO(const char* p_pszConnectMessagePhoneNO);

	/************************************************************************
	*	概述：获取连接消息电话号码
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		连接消息电话号码
	************************************************************************/
	const char* getConnectMessagePhoneNO() const ;


	/************************************************************************
	*	概述：设置连接消息内容
	*	输入：
	*		p_pszConnectMessageContent:连接消息内容
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	bool setConnectMessageContent(const char* p_pszConnectMessageContent);

	/************************************************************************
	*	概述：获取连接消息内容
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		
	************************************************************************/
	const char* getConnectMessageContent() const ;


	/************************************************************************
	**概述：
	*		设置断开连接消息电话号码
	**输入：
	*		p_pszDisconnectMessagePhoneNO ：断开连接消息电话号码
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	bool setDisconnectMessagePhoneNO(const char * p_pszDisconnectMessagePhoneNO);

	/************************************************************************
	**概述：
	*		获取断开连接消息电话号码
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		断开连接消息电话号码
	**功能：
	*
	************************************************************************/
	const char * getDisconnectMessagePhoneNO() const;

	/************************************************************************
	**概述：
	*		设置断开连接消息内容
	**输入：
	*		p_pszDisconnectMessageContent ：断开连接消息内容
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	bool setDisconnectMessageContent(const char* p_pszDisconnectMessageContent);

	/************************************************************************
	**概述：
	*		获取断开连接消息内容
	**输入：
	*		无
	**输出：
	**		无
	**返回值：
	*		断开连接消息内容
	**功能：
	*
	************************************************************************/
	const char* getDisconnectMessageContent() const;

private:
	bool			m_bEnableFlag;														//启用标志

	char			m_szConnectMessagePhoneNO[CONST_MAXLENGTH_PHONE_NO+1];				//连接消息电话号码
	char			m_szConnectMessageContent[CONST_MAXLENGTH_MESSAGE_CONTENT+1];		//连接消息内存
	
	char			m_szDisconnectMessagePhoneNO[CONST_MAXLENGTH_PHONE_NO + 1];			//断开连接消息电话号码
	char			m_szDisconnectMessageContent[CONST_MAXLENGTH_MESSAGE_CONTENT + 1];	//断开连接消息内存

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_I3GMESSAGECONNECTPOLICYPARAM_H_
