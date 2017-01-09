#ifndef _LAYOUTMODEL_
#define _LAYOUTMODEL_

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

class SN_DLL_API LayoutModel
{
public:
	enum LAYOUTMODELID
	{
		Layout_Model_1 = 0,		//一窗口
		Layout_Model_2,			//四窗口
		Layout_Model_3,			//六窗口平均
		Layout_Model_4,			//六窗口,一大五小
		Layout_Model_5,			//八窗口，一大七小
		Layout_Model_6,			//九窗口
		Layout_Model_7,			//十六窗口
		Layout_Model_8,			//三十六窗口
		Layout_Model_9,			//六十四窗口
		Layout_Model_Max = Layout_Model_9
	};

public:
	LayoutModel(void);
	~LayoutModel(void);

public:
	/************************************************************************
	*	概述：设置类型编号
	*	输入：
	*		p_ModelId	类型编号
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setModelId(int p_ModelId);

	/************************************************************************
	*	概述：获取类型编号
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		类型编号
	*************************************************************************/
	int getModelId() const;

	/************************************************************************
	*	概述：设置画面数量
	*	输入：
	*		p_PicNumber	画面数量
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setPicNumber(int p_PicNumber);

	/************************************************************************
	*	概述：获取画面数量
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		画面数量
	*************************************************************************/
	int getPicNumber() const;

	LayoutModel& operator = (const LayoutModel& p_objLayoutModel);

private:
	int		m_nModelId;
	int		m_nPicNumber;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_LAYOUTMODEL_
