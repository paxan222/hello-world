#ifndef _IMAGEFORMAT_H_
#define _IMAGEFORMAT_H_

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

class SN_DLL_API ImageFormat
{
public:
	enum Format
	{
		IMAGEFORMAT_D1					= 1,	//PAL 704*576,1-25frame； NTSC 704*480 1-30framre
		IMAGEFORMAT_LOW_BITRATE_D1		= 2,	//PAL 704*576 1-12frame；NTSC 704*480 1-15framre
		IMAGEFORMAT_CIF					= 4,	//PAL 352*288 1-25frame；NTSC 352*240 1-30framre
		IMAGEFORMAT_QCIF				= 5,	//PAL 176*144 1-25frame；NTSC 240*160 1-30framre
		IMAGEFORMAT_SXGA				= 6,	//NA 1280*960 1-22frame
		IMAGEFORMAT_QVGA				= 7,	//NA 320*240 1-22frame
		IMAGEFORMAT_1280_720			= 8,	//NA 1280*720 1-25frame
		IMAGEFORMAT_360_160				= 9,	//NA 320*160 1-25frame
		IMAGEFORMAT_640_360				= 10,	//NA 640*368 1-25frame
		IMAGEFORMAT_VGA					= 11,	//NA 640*480 1-25frame
		IMAGEFORMAT_UXGA				= 12,	//NA 1600*1200 1-25frame
		IMAGEFORMAT_1920_1080			= 13,	//NA 1920*1080 1-25frame
		IMAGEFORMAT_640_360_EX			= 14,	//NA 640*360 1-25frame

		IMAGEFORMAT_QXGA				= 15,	//NA 2048*1536 1-25frame
		IMAGEFORMAT_2592_1920			= 16	//NA 2592*1920 1-25frame
	} ;

public:
	ImageFormat(void);
	~ImageFormat(void);

	ImageFormat(const ImageFormat& p_objImageFormat);

public:
	
	/************************************************************************
	**概述：
	*		设置图像格式ID
	**输入：
	*		p_nImageFormatId ：要设置的图像格式ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setImageFormatId(const int p_nImageFormatId);

	/************************************************************************
	*概述：
	*		获取图像格式id
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		图像格式Id
	*功能：       
	*************************************************************************/
	const int getImageFormatId() const;


	/************************************************************************
	**概述：
	*		设置图像格式名称
	**输入：
	*		p_pszImageFormatName：要设置的图像格式名称
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	bool setImageFormatName(const char* p_pszImageFormatName);

	/************************************************************************
	*概述：
	*		获取图像格式名称
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		图像格式名称
	*功能：       
	*************************************************************************/
	const char* getImageFormatName() const;

	/************************************************************************
	*概述：
	*		赋值函数
	*输入：
	*		p_objImageFormat：DDNS信息
	*输出：
	*		无
	*返回值：
	*		DDNS信息
	*功能：
	*************************************************************************/
	ImageFormat& operator =(const ImageFormat& p_objImageFormat);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objImageFormat：ImageFormat类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个ImageFormat类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const ImageFormat& p_objImageFormat);

	//通过高宽获取图像格式ID值
	static int getImageFormat(int p_nVideoWidth, int p_nVideoHeight);
	static bool getImageFormatName(const int p_nImageFormatID, char* p_nImageFormatName);

private:
	int			m_nImageFormatId;											//图像格式id
	char		m_szImageFormatName[CONST_MAXLENGTH_IMAGEFORMAT_NAME + 1];	//图像格式名称
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_IMAGEFORMAT_H_
