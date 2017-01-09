#ifndef _PLAY_LAYOUT_H_
#define _PLAY_LAYOUT_H_

#include "DomainConst.h"
#include "LayoutWndInfo.h"

#include <vector>
using namespace std;

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

class SN_DLL_API PlayLayout
{
public:
	PlayLayout(void);
	~PlayLayout(void);

	//拷贝构造函数
	PlayLayout(const PlayLayout& p_objPlayLayout);

public:

	/************************************************************************
	**概述：
	*		设置画面数目
	**输入：
	*		p_nPicNum ：画面数目
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*    设置画面数目
	************************************************************************/
	void setPictureNum(const int p_nPicNum);

	/************************************************************************
	**概述：
	*		获取画面数目
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		画面数目
	**功能：
	*     获取画面数目
	**************************************************************************/
	const int getPictureNum() const ;

	/************************************************************************
	**概述：
	*		设置显示器ID
	**输入：
	*		p_nScreenId ：设置显示器ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*    设置显示器ID
	************************************************************************/
	void setScreenId(const int p_nScreenId);

	/************************************************************************
	**概述：
	*		获取显示器ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		显示器ID
	**功能：
	*     获取显示器ID
	**************************************************************************/
	const int getScreenId() const ;

	/************************************************************************
	**概述：
	*		设置布局窗口信息列表
	**输入：
	*		p_objLayoutWndInfoList ：布局窗口信息列表
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*    
	************************************************************************/
	void setLayoutWndInfoList(const std::vector<LayoutWndInfo>& p_objLayoutWndInfoList);

	/************************************************************************
	**概述：
	*		获取布局窗口信息列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		布局窗口信息列表
	**功能：
	*     
	**************************************************************************/
	const std::vector<LayoutWndInfo>& getLayoutWndInfoList() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objRecordBackupParam ：录像备份参数对象
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	**************************************************************************/
	PlayLayout& operator = (const PlayLayout& p_objPlayLayout);

private:

	int m_nPictureNum;

	int m_nScreenId;

	vector<LayoutWndInfo> m_objLayoutWndInfoList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_PLAY_LAYOUT_H_
