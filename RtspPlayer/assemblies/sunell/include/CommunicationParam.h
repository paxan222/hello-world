#ifndef _COMMUNICATIONPARAM_H_
#define _COMMUNICATIONPARAM_H_

#include "DomainConst.h"
#include "const.h"
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

class SN_DLL_API CommunicationParam
{

public:
	CommunicationParam(void);
	~CommunicationParam(void);

	//拷贝构造函数
	CommunicationParam(const CommunicationParam& p_objCommunicationParam);

public:

	/************************************************************************
	** 概述：
	*		设置IP协议类型
	**输入：
	*		p_nIPProtoFlag：IP协议类型
	**输出：
	*	  无
	**返回值：
	*	  无
	************************************************************************/
	void setIPProtoFlag(const int p_nIPProtoFlag);

	/************************************************************************
	**概述：
	*		获取IP协议类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		IP协议类型
	************************************************************************/
	const int getIPProtoFlag()  const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objCommunicationParam：NTP信息
	**输出：
	*		无
	**返回值：
	*		NTP信息
	*功能：
	*
	************************************************************************/
	CommunicationParam& operator =(const CommunicationParam& p_objCommunicationParam);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objCommunicationParam：CommunicationParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个CommunicationParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const CommunicationParam& p_objCommunicationParam);

private:

	int				m_nIPProtoFlag;							//IP协议类型
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_COMMUNICATIONPARAM_H_
