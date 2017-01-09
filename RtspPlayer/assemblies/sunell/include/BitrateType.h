#ifndef _BITRATETYPE_H_
#define _BITRATETYPE_H_

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

class SN_DLL_API BitrateType
{
public:
	enum BITRATE_TYPE
	{
		CBR_TYPE = 1,//固定码率

		VBR_TYPE = 2 //不固定码率
	};

public:
	BitrateType(void);
	~BitrateType(void);
	BitrateType(const BitrateType& p_objBitrateType);

public:

	/************************************************************************
	**概述：
	*		设置比特率类型ID
	**输入：
	*		p_nBitrateTypeId ：要设置的比特率类型ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setBitrateTypeId(const int p_nBitrateTypeId);

	/************************************************************************
	*概述：
	*		获取比特率类型id
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		比特率类型Id
	*功能：       
	*************************************************************************/
	const int getBitrateTypeId() const;


	/************************************************************************
	**概述：
	*		设置比特率类型ID
	**输入：
	*		p_pszBitrateTypeName：要设置的比特率类型名称
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	bool setBitrateTypeName(const char* p_pszBitrateTypeName);

	/************************************************************************
	*概述：
	*		获取比特率类型名称
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		比特率类型名称
	*功能：       
	*************************************************************************/
	const char* getBitrateTypeName() const;

	/************************************************************************
	*概述：
	*		赋值函数
	*输入：
	*		p_objBitrateType：DDNS信息
	*输出：
	*		无
	*返回值：
	*		DDNS信息
	*功能：
	*************************************************************************/
	BitrateType& operator =(const BitrateType& p_objBitrateType);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objBitrateType：BitrateType类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个BitrateType类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const BitrateType& p_objBitrateType);


private:
	int			m_nBitrateTypeId;										//比特率类型id
	char		m_szBitrateTypeName[CONST_MAXLENGTH_BITRATETYPE_NAME + 1];	//比特率类型名称
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_BITRATETYPE_H_
