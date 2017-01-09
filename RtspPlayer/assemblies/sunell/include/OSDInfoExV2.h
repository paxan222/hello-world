#ifndef _OSDINFOEXV2_H_
#define _OSDINFOEXV2_H_

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

class SN_DLL_API OSDInfoExV2
{
public:
	OSDInfoExV2();
	~OSDInfoExV2();

public:
	/****************************************************************************
	**概述：
	*		设置画布ID
    **输入：
	*		p_nAreaID:画布ID
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setAreaID(const int p_nAreaID);

	/****************************************************************************
	**概述：
	*		获取画布ID
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		画布ID
	**功能：
	*	
	*******************************************************************************/
	const int getAreaID() const;


	/****************************************************************************
	**概述：
	*		设置画布行号
    **输入：
	*		p_nArrowID:画布行号
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setArrowID(const int p_nArrowID);

	/****************************************************************************
	**概述：
	*		获取画布行号
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		画布行号
	**功能：
	*	
	*******************************************************************************/
	const int getArrowID() const;


	
	/****************************************************************************
	**概述：
	*		设置水印类型
    **输入：
	*		p_nOSDType:水印类型，整形值，表示OSD的Id号
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setOSDType(const int p_nOSDType);

	/****************************************************************************
	**概述：
	*		获得水印类型
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		水印类型，整形值，表示得到的OSD的Id号 
	**功能：
	*	
	*******************************************************************************/
	const int getOSDType() const;


	/****************************************************************************
	**概述：
	*		设置是否显示水印
    **输入：
	*		p_nEnableOSD：是否允许显示水印（false：不显示，true：显示）
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setOSDEnableFlag(const bool p_nEnableOSD);

	/****************************************************************************
	**概述：
	*		获得是否允许显示水印
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		是否允许显示水印标识（false：不显示，true：显示）
	**功能：
	*
	*******************************************************************************/
	const bool getOSDEnableFlag() const;

	/****************************************************************************
	**概述：
	*		设置显示模式
    **输入：
	*		p_nShowMode:显示模式（）
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setShowMode(const int p_nShowMode);

	/****************************************************************************
	**概述：
	*		获得显示模式
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		显示模式
	**功能：
	*	
	*******************************************************************************/
	const int getShowMode() const;

	
	/****************************************************************************
	**概述：
	*		设置OSD信息
    **输入：
	*		p_pszInfo：字符串，最大长度为CONST_MAXLENGTH_OSDInfoEx字节,结尾以‘\0’结束。
	**输出：
	*		无
	**返回值：
	*		true： 成功
	*		false：失败 
	**功能：
	*		若输入p_pszInfo长度<=CONST_MAXLENGTH_OSDInfoEx，返回true，并保存到m_szInfo;
	*		若输入p_pszInfo长度>CONST_MAXLENGTH_OSDInfoEx，返回false
	*****************************************************************************/
	bool setInfo(const char* p_pszInfo);

	/****************************************************************************
	**概述：
	*		获得OSD信息
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		返回保存OSD信息的m_szInfo字符串指针。 
	**功能：
	*	
	*******************************************************************************/
	const char* getInfo() const;


	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		OSDInfoEx类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		OSD类对象的引用
	**功能：
	*		将参数对象的所有属性赋值给另外一个对象，将另外一个对象的引用返回。
	*******************************************************************************/
	OSDInfoExV2 & operator =(const OSDInfoExV2& p_objOSDInfoExV2) ;

	/****************************************************************************
	**概述：
	*			定义“等于”操作符
    **输入：
	*			OSD类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		但两个OSD类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const OSDInfoExV2& p_objOSDInfoExV2) const;

private:
	int			m_nAreaID;								//区域ID（属于画布的ID）
	int			m_nArrowID;								//行号
	int			m_nOSDType;								//水印类型
	bool		m_bOSDEnableFlag;						//是否显示水印（false：不显示，true：显示）
	int			m_nShowMode;							//显示模式
	char		m_szInfo[CONST_MAXLENGTH_OSDINFO + 1];	//水印信息

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_OSDINFOEX_H_
