#ifndef _AUDIOENCODEQUALITY_H_
#define _AUDIOENCODEQUALITY_H_

#include "DomainConst.h"
#include <string>
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

class SN_DLL_API AudioEncodeQuality
{
public:

	AudioEncodeQuality(void);

	~AudioEncodeQuality(void);

	//拷贝构造函数
	AudioEncodeQuality(const AudioEncodeQuality& p_objAudioEncodeQuality);

public:

	//设置格式标记
	void setFormatTag(const unsigned short p_nFormatTag);
	//获取格式标记
	const unsigned short getFormatTag() const;

	//设置声音通道数（声道）
	void setChannels(const unsigned short p_nChannels);
	//获取声音通道数（声道）
	const unsigned short getChannels() const;

	//设置每秒采样数
	void setSamplesPerSec(const unsigned long p_nSamplesPerSec);
	//获取每秒采样数
	const unsigned long getSamplesPerSec() const;

	void setAvgBytesPerSec(const unsigned long p_nAvgBytesPerSec);
	const unsigned long getAvgBytesPerSec() const;

	void setBlockAlign(const unsigned short p_nBlockAlign);
	const unsigned short getBlockAligns() const;

	//设置每次采样的大小
	void setBitsPerSample(const unsigned short p_nBitsPerSample);
	//获取每次采样的大小
	const unsigned short getBitsPerSample() const;

	//设置追加数据长度
	void setCBSize(const unsigned short p_nCBSize);
	//获取追加数据长度
	const unsigned short getCBSize() const;

	//设置编码格式
	void setEncodeType(const int p_nCompression);
	//获取编码格式
	const int getEncodeType() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objAudioEncodeQuality：音频编码质量对象
	**输出：
	*		无
	**返回值：
	*		赋值后的音频编码质量对象
	**功能：       
	*
	************************************************************************/
	AudioEncodeQuality& operator =(const AudioEncodeQuality &p_objAudioEncodeQuality);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objAudioEncodeQuality：AudioEncodeQuality类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个AudioEncodeQuality类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const AudioEncodeQuality& p_objAudioEncodeQuality) const;

	bool operator < (const AudioEncodeQuality& p_objAudioEncodeQuality) const;

private:

	unsigned short		m_nFormatTag;					//格式标记

	unsigned short		m_nChannels;					//声音通道数（声道）

	unsigned long		m_nSamplesPerSec;				//每秒采样数

	unsigned long		m_nAvgBytesPerSec;				//

	unsigned short		m_nBlockAlign;					//

	unsigned short		m_nBitsPerSample;				//每次采样的大小

	unsigned short		m_nCBSize;						//后面追加数据长度

	int					m_nEncodeType;					//编码格式


}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_AUDIOENCODEQUALITY_H_
