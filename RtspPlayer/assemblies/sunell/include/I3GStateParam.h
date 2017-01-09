#ifndef _I3GSTATEPARAM_H_
#define _I3GSTATEPARAM_H_

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

class SN_DLL_API I3GStateParam
{
public:
	enum I3GState
	{
		I3G_STATE_DISCONNECT				= 0,	//未连接
		I3G_STATE_CONNECTED					= 1,	//已经连接
		I3G_STATE_CONNECTING				= 2		//正在连接
	};

	enum SIMState
	{
		SIM_STATE_OK						= 0,	//未插入SIM卡
		SIM_STATE_NOEXIST					= 1,	//SIM卡正常
		SIM_STATE_ERROR						= 2		//SIM卡异常
	};

public:
	I3GStateParam(void);
	~I3GStateParam(void);


public:

	/************************************************************************
	**概述：
	*		设置连接状态
	**输入：
	*		p_nConnectState：连接状态
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setConnectState(const int p_nConnectState);

	/************************************************************************
	**概述：
	*		获取连接状态
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*	
	************************************************************************/
	const int getConnectState() const;


	/************************************************************************
	**概述：
	*		设置供应商
	**输入：
	*		p_strOperator：供应商
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	bool setOperator(const char* p_pszOperator);

	/************************************************************************
	**概述：
	*		获取供应商
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		
	************************************************************************/
	const char* getOperator() const ;


	/************************************************************************
	**概述：
	*		设置网络类型
	**输入：
	*		p_nNetType ：网络类型
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	bool setNetType(const char * p_pszNetType);

	/************************************************************************
	**概述：
	*		获取网络类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		网络类型
	**功能：
	*
	************************************************************************/
	const char * getNetType() const;

	/************************************************************************
	**概述：
	*		设置信号质量
	**输入：
	*		p_nSignalQuality：信号质量
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setSignalQuality(const int p_nSignalQuality);

	/************************************************************************
	**概述：
	*		获取信号质量
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*	
	************************************************************************/
	const int getSignalQuality() const;


	/************************************************************************
	**概述：
	*		设置SIM卡状态
	**输入：
	*		p_nSIMState：SIM卡状态
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setSIMState(const int p_nSIMState);

	/************************************************************************
	**概述：
	*		获取SIM卡状态
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*	
	************************************************************************/
	const int getSIMState() const;

private:
	int				m_nConnectState;									//连接状态
	char			m_szOperator[CONST_MAXLENGTH_3G_OPERATOR+1];		//提供商
	char			m_szNetType[CONST_MAXLENGTH_NET_TYPE + 1];			//网络类型

	int				m_nSignalQuality;									//信号质量
	int				m_nSIMState;										//SIM卡状态

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_I3GSTATEPARAM_H_
