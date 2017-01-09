#ifndef _DISPLAYPICTUREPARAM_H_
#define _DISPLAYPICTUREPARAM_H_

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

class SN_DLL_API CyclePictureParam
{
public:
	CyclePictureParam(void);
	~CyclePictureParam(void);

	//拷贝构造函数
	CyclePictureParam(const CyclePictureParam& p_objCyclePictureParam);

public:

	/************************************************************************
	**概述：
	*		设置画面ID
	**输入：
	*		p_nPictureId ：画面ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*    
	************************************************************************/
	void setPictureId(const int p_nPictureId);

	/************************************************************************
	**概述：
	*		获取画面ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		画面ID
	**功能：
	*     
	**************************************************************************/
	const int getPictureId() const;


	/****************************************************************************
	**概述：
	*		设置画面名称
	**输入：
	*		p_pszPictureName ：画面名称,结尾以‘\0’结束。
	**输出：
	*		无
	**返回值：
	*		true： 成功
	*		false：失败 
	**功能：
	*		若输入p_pszPictureName长度<=CONST_MAXLENGTH_PICTURENAME，返回true.
	*		若输入p_pszPictureName为NULL或其长度>CONST_MAXLENGTH_PICTURENAME，返回false.
	*****************************************************************************/
	bool setPictureName(const char* p_pszPictureName);

	/****************************************************************************
	**概述：
	*		获取画面名称
	**输入：
	*		无
	**输出：
	*		无
	*返回值：
	*		画面名称，字符串类型 
	**功能：
	*		
	*****************************************************************************/
	const char* getPictureName() const;


	/************************************************************************
	**概述：
	*		设置隶属组Id
	**输入：
	*		p_nSupGroupId ：隶属组Id
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*    
	************************************************************************/
	void setSupGroupId(const int p_nSupGroupId);

	/************************************************************************
	**概述：
	*		获取隶属组Id
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		隶属组Id
	**功能：
	*     
	**************************************************************************/
	const int getSupGroupId() const ;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objCyclePictureParam ：显示画面对象
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	**************************************************************************/
	CyclePictureParam& operator = (const CyclePictureParam& p_objCyclePictureParam);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objCyclePictureParam：CyclePictureParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个CyclePictureParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const CyclePictureParam& p_objCyclePictureParam);

private:

	int		m_nPictureId;									//画面id

	char	m_szPictureName[CONST_MAXLENGTH_PICTURENAME + 1];	//画面名称
	
	int		m_nSupGroupId;									//隶属组id

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_DISPLAYPICTUREPARAM_H_
