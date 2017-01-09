#ifndef _VIDEOINFO_H_
#define _VIDEOINFO_H_

#include "SNPlatOS.h"

/*
#ifdef __cplusplus
extern "C" {
#endif
*/ 

#if (defined(WIN32) || defined(_WIN32_WCE))
	#ifdef SN_DLL_EXPORTS
		#define VIDEOINFO_API __declspec(dllexport)
	#else
		#define VIDEOINFO_API __declspec(dllimport)
	#endif
#else
	#define VIDEOINFO_API
#endif

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

class VIDEOINFO_API VideoInfo
{
public:
	VideoInfo();
	~VideoInfo();

public:
	void setBitRate(const unsigned long p_nBitRate);
	const unsigned long	getBitRate() const ;

	void  setBitErrorRate(const unsigned long p_nBitErrorRate);
	const unsigned long	getBitErrorRate() const;

	void setTimePerFrame(const unsigned long p_nTimePerFrame);
	const unsigned long	getTimePerFrame() const;

	void setSize(const unsigned long p_nSize);
	const unsigned long	getSize() const;

	void setWidth(const unsigned long p_nWidth);
	const unsigned long	getWidth() const;

	void setHeight(const unsigned long p_nHeight);
	const unsigned long	getHeight() const;

	void setPlanes(const unsigned short p_nPlanes);
	const unsigned short getPlanes() const;

	void setBitCount(const unsigned short p_nBitCount);
	const unsigned short getBitCount() const;

	void setCompression(const unsigned long p_nCompression);
	const unsigned long getCompression() const;

	void setSizeImage(const unsigned long p_nSizeImage);
	const unsigned long getSizeImage() const;

	void setXPelsPerMeter(const long p_nXPelsPerMeter);
	const long getXPelsPerMeter() const;

	void setYPelsPerMeter(const long p_nYPelsPerMeter);
	const long getYPelsPerMeter() const;

	void setClrUsed(const unsigned long p_nClrUsed);
	const unsigned long getClrUsed() const;

	void setClrImportant(const unsigned long p_nClrImportant);
	const unsigned long getClrImportant() const;

	void setSPS_PPSData(const char * p_pszData, int p_nDataLen);
	const int getSPS_PPSDataLen() const;
	const char*	getSPS_PPSData() const;

	//拷贝构造函数
	VideoInfo(const VideoInfo &p_objVideoInfo);
	//赋值函数
	VideoInfo &operator =(const VideoInfo &p_objVideoInfo);

	
private:

	unsigned long		m_nBitRate;
	unsigned long		m_nBitErrorRate;
	unsigned long		m_nTimePerFrame;

	unsigned long		m_nSize;
	unsigned long		m_nWidth;
	unsigned long		m_nHeight;
	unsigned short		m_nPlanes;
	unsigned short		m_nBitCount;
	unsigned long		m_nCompression;
	unsigned long		m_nSizeImage;
	long				m_nXPelsPerMeter;
	long				m_nYPelsPerMeter;
	unsigned long		m_nClrUsed;
	unsigned long		m_nClrImportant;

	char				m_szSPS_PPSData[512];
	int					m_nSPS_PPSDataLen;

};

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif // _VIDEOINFO_H_
