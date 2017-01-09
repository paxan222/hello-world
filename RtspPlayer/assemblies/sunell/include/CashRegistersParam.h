#ifndef _CASHREGISTERSPARAM_H_
#define _CASHREGISTERSPARAM_H_

#include "ExternInterface.h"
#include "SNPlatOS.h"
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

class SN_DLL_API CashRegistersParam
{
public:
	enum OSDLANGUAGE
	{
		CHINESE = 1,
		ENGLISH = 2
	};

public:
	CashRegistersParam();
	~CashRegistersParam();

public:
	/************************************************************************
	**概述：
	*		设置是否启用点钞机服务
	**输入：
	*		p_bEnableFlag：启用点钞机服务的状态
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setEnableFlag(const bool p_bEnableFlag);

	/************************************************************************
	**概述：
	*		获取是否启用点钞机服务标识
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		是否启用点钞机服务标识
	**功能：
	*		
	*************************************************************************/
	const bool getEnableFlag() const;

	void setOSDTopX(int p_nOSDTopX);
	int getOSDTopX() const;

	void setOSDTopY(int p_nOSDTopY);
	int getOSDTopY() const;

	void setOSDLanguage(int p_nOSDLanguage);
	int getOSDLanguage() const;

	void setModel(int p_nModel);
	int getModel() const;

	void setOSDCameraList(const std::vector<int> & p_objOSDCameraList);
	const std::vector<int> & getOSDCameraList() const;

	void setExternInterface(const ExternInterface & p_objExternInterface);
	const ExternInterface & getExternInterface() const;
private:
	bool m_bEnableFlag; //是否启动点钞机(true：启动，false：不启动)
	int m_nOSDTopX;
	int m_nOSDTopY;
	int m_nOSDLanguage;
	int m_nModel;
	std::vector<int> m_objOSDCameraList;
	ExternInterface m_objExternInterface;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CashRegistersParam_H_
