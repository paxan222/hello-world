#ifndef _EXTERNINTERFACE_H_
#define _EXTERNINTERFACE_H_

#include "RS485Device.h"
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

class SN_DLL_API ExternInterface
{
public:
	enum InterfaceType
	{	
		EXTERN_INTERFACE_TYPE_RS485 = 1, //485串口接口类型	
		EXTERN_INTERFACE_TYPE_RS232 = 2, //232串口接口类型	
		EXTERN_INTERFACE_TYPE_USB = 3,   //USB接口类型
		EXTERN_INTERFACE_TYPE_NET = 4	 //网络接口类型
	};

public:
	ExternInterface();
	~ExternInterface();

public:
	void setInterfaceType(int p_nInterfaceType);
	int getInterfaceType() const;

	void setRS485Device(const RS485Device & p_objRS485Device);
	const RS485Device & getRS485Device() const;
		
private:
	int	    m_nInterfaceType;
	RS485Device m_objRS485Device;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_EXTERNINTERFACE_H_
