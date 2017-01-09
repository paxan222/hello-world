#ifndef SVCSTREAMPARAM_H_
#define SVCSTREAMPARAM_H_

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

class SN_DLL_API SVCStreamParam
{
public:
	SVCStreamParam(void);
	~SVCStreamParam(void);
	SVCStreamParam(const SVCStreamParam &p_objSVCStreamParam);
public:
	/************************************************************************
	**概述：
	*		设置源流ID
	**输入：
	*		p_nSourceStreamID ：原流ID
	**输出：
	*		无
	**返回值：
	*		无
	**说明：
	*		即是伴随流所对应的原始流的ID
	************************************************************************/
	void setSourceStreamID(const int p_nSourceStreamID);
	/************************************************************************
	**概述：
	*		获取原流ID
	**输入：
	*		无
	**输出：
	*		原流ID
	**返回值：
	*		无
	**功能：       
	*		即是伴随流所对应的原始流的ID
	************************************************************************/
	const int getSourceStreamID() const;

	/************************************************************************
	**概述：
	*		设置伴随流ID
	**输入：
	*		p_nSVCStreamID ：伴随流ID
	**输出：
	*		无
	**返回值：
	*		无
	**说明：
	*		即是伴随流的虚拟ID如（stream3或者stream4的id）
	************************************************************************/
	void setSVCStreamID(const int p_nSVCStreamID);
	/************************************************************************
	**概述：
	*		获取伴随流ID
	**输入：
	*		无
	**输出：
	*		伴随流ID
	**返回值：
	*		无
	**功能：       
	*		即是伴随流的虚拟ID如（stream3或者stream4的id）
	************************************************************************/
	const int getSVCStreamID() const;

	/***********************************************************************
	**概述：
	*		设置流名称
	**输入：
	*		p_pszStreamName：流名称
	**输出：
	*		无
	**返回值：
	*		true ：设置成功
	*		false：设置失败
	**功能：
	************************************************************************/
	bool setSVCStreamName(const char*  p_pszStreamName);

	/************************************************************************
	**概述：
	*		获取流名称
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		流名称
	**功能：
	*
	***************************************************************************/
	const char* getSVCStreamName() const;

	/************************************************************************
	**概述：
	*		设置伴随流P帧取帧间隔
	**输入：
	*		p_nPFrameInterval ：取帧间隔
	**输出：
	*		无
	**返回值：
	*		无
	**说明：取帧间隔为0则表示原始流与伴随流P帧比为1:1；
	*	若取帧间隔为1则表示原始流与伴随流P帧比为2:1，即伴随流P帧为原始流P帧数的二分之一；
	*	若取帧间隔为2则表示原始流与伴随流P帧比为3:1，即伴随流P帧为原始流P帧数的三分之一；
	*		
	************************************************************************/
	void setFrameSkipInterval(const int p_nFrameSkipInterval);
	/************************************************************************
	**概述：
	*		获取伴随流P帧取帧率
	**输入：
	*		无
	**输出：
	*		取帧间隔
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	const int getFrameSkipInterval() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objSVCStreamParam：设备伴随流参数信息
	**输出：
	*		无
	**返回值：
	*		设备伴随流参数信息
	**功能：
	************************************************************************/
	SVCStreamParam& operator =(const SVCStreamParam& p_objSVCStreamParam);
	bool operator == (const SVCStreamParam& p_objSVCStreamParam) const;
private:
	int		m_nSourceStreamID;		//原流ID
	int		m_nSVCStreamID;			//伴随流ID
	int		m_nFrameSkipInterval;   //p帧跳帧间隔
	char	m_szStreamName[CONST_MAXLENGTH_AVSREAM_NAME + 1];		//码流名称
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif



