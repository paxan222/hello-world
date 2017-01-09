#ifndef _ENCODEQUALITY_H_
#define _ENCODEQUALITY_H_

#include "AudioEncodeQuality.h"
#include "VideoEncodeQuality.h"
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

class SN_DLL_API EncodeQuality
{
public:
	EncodeQuality(void);
	~EncodeQuality(void);

	EncodeQuality(const EncodeQuality& p_objEncodeQuality);

public:
	//设置视频质量
	bool setVideoEncodeQuality(const VideoEncodeQuality& p_objVideoEncodeQuality);
	const VideoEncodeQuality& getVideoEncodeQuality() const;

	//设置音频质量
	bool setAudioEncodeQuality(const AudioEncodeQuality& p_objAudioEncodeQuality);
	const AudioEncodeQuality& getAudioEncodeQuality() const;

	void setCameraId(const int p_nCameraId);
	const int getCameraId() const ;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objEncodeQuality：编码质量信息
	**输出：
	*		无
	**返回值：
	*		编码质量信息
	**功能：
	************************************************************************/
	EncodeQuality& operator =(const EncodeQuality& p_objEncodeQuality);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objEncodeQuality：EncodeQuality类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个EncodeQuality类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const EncodeQuality& p_objEncodeQuality);

private:
	int							m_nCameraId;				//摄像机id

	VideoEncodeQuality			m_objVideoEncodeQuality;	//视频质量
	AudioEncodeQuality			m_objAudioEncodeQuality;	//音频质量
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_ENCODEQUALITY_H_
