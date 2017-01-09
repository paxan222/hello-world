#ifndef _VIDEOSYSTEM_H_
#define _VIDEOSYSTEM_H_

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

class SN_DLL_API VideoSystem
{
public:
	enum 
	{
		NTSC		= 0,	//NTFS制式
		PAL			= 1,	//PAL制式
		NA			= 2,	//
		BOUNDARY	= 5		//边界检测
	};

public:
	VideoSystem(void);
	~VideoSystem(void);

	VideoSystem(const VideoSystem& p_objVideoSystem);

public:
	
	/************************************************************************
	**概述：
	*		设置视频制式ID
	**输入：
	*		p_nVideoSystemId ：要设置的视频制式ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setVideoSystemId(const int p_nVideoSystemId);

	/************************************************************************
	*概述：
	*		获取视频制式id
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		视频制式Id
	*功能：       
	*************************************************************************/
	const int getVideoSystemId() const;


	/************************************************************************
	**概述：
	*		设置视频制式名称
	**输入：
	*		p_pszVideoSystemName：要设置的视频制式名称
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	bool setVideoSystemName(const char* p_pszVideoSystemName);

	/************************************************************************
	*概述：
	*		获取视频制式名称
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		视频制式名称
	*功能：       
	*************************************************************************/
	const char* getVideoSystemName() const;

	/************************************************************************
	*概述：
	*		赋值函数
	*输入：
	*		p_objVideoSystem：DDNS信息
	*输出：
	*		无
	*返回值：
	*		DDNS信息
	*功能：
	*************************************************************************/
	VideoSystem& operator =(const VideoSystem& p_objVideoSystem);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objVideoSystem：VideoSystem类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个VideoSystem类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const VideoSystem& p_objVideoSystem);


	//通过高宽获取制式
	static int getVideoSystem(int p_nVideoWidth, int p_nVideoHeight);

private:
	int			m_nVideoSystemId;											//视频制式id
	char		m_szVideoSystemName[CONST_MAXLENGTH_VIDEOSYSTEM_NAME + 1];	//视频制式名称
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_VIDEOSYSTEM_H_
