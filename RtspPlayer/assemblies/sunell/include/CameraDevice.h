#ifndef _CAMERADEVICE_H_
#define _CAMERADEVICE_H_

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

class SN_DLL_API CameraDevice
{
public:
	CameraDevice();
	~CameraDevice();

	//拷贝构造函数
	CameraDevice(const CameraDevice &p_objCameraDevice);

public:
	/************************************************************************
	**概述：
	*		设置摄像机的Id号
    **输入：
	*		p_nCameraId ：摄像机的Id号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*    设置摄像机的Id号
	************************************************************************/
	void setCameraId(const int p_nCameraId);
	
	/************************************************************************
	**概述：
	*		获取摄像机的Id号
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		摄像机的Id号
	**功能：
	*     获取摄像机的Id号
	**************************************************************************/
	const int getCameraId() const ;
	
	/************************************************************************
	**概述：
	*		设置摄像机的名称
    **输入：,
	*	  p_pszCameraName ：摄像机的名称，字符串，
	*	  最大长度为CONST_MAXLENGTH_CAMERA_NAME字节,结尾以‘\0’结束。 
	**输出：
	*	无
	**返回值：
	*		true : 成功
	* 		false：失败
	**功能：
	*	   若输入p_pszCameraName长度<=CONST_MAXLENGTH_CAMERA_NAME，返回true，
	*		并保存到m_szCameraName;
	*		若输入p_pszCameraName为null或者其长度>CONST_MAXLENGTH_CAMERA_NAME，
	*		返回false
	************************************************************************/
	bool setCameraName(const char* p_pszCameraName);

	/************************************************************************
	**概述：
	*		获取摄像机的名称
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		摄像机名称
	**功能：
	*		
	**************************************************************************/
	const char* getCameraName() const;

	/****************************************************************************
	**概述：
	*		设置摄像机样式
    **输入：
	*		p_pszCameraModel ：字符串，最大长度为CONST_MAXLENGTH_CAMERAMODEL字节,
	*		结尾以‘\0’结束。
	**输出：
	*		无
	**返回值：
	*		true： 成功
	* 		false：失败 
	**功能：
	*		若输入p_pszCameraModel长度<=CONST_MAXLENGTH_CAMERAMODEL，返回true，
	*		并保存到m_szCameraModel;
	*		若输入p_pszCameraModel为NULL或其长度>CONST_MAXLENGTH_CAMERAMODEL，
	*		返回false
	*****************************************************************************/
	bool setCameraModel(const char* p_pszCameraModel);

	/****************************************************************************
	**概述：
	*		获取摄像机样式
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		返回保存摄像机样式的m_szCameraModel字符串指针。 
	**功能：
	* 		获取保存有摄像机样式的字符串指针
	*******************************************************************************/
	const char* getCameraModel() const;

	/************************************************************************
	**概述：
	*		设置模拟视频制式
    **输入：
	*		p_nAnalogVideo ：模拟视频制式，（有两种， PAL和NTSC）
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		设置模拟视频制式
	**************************************************************************/
	void setVideoSystem(const int p_nVideoSystem);

	/************************************************************************
	**概述：
	*		获取模拟视频制式
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		模拟视频制式
	**功能：
	*     获取模拟视频制式
	**************************************************************************/
	const int getVideoSystem() const ;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objCameraDevice ：摄像机设备对象
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	**************************************************************************/
	CameraDevice& operator = (const CameraDevice& p_objCameraDevice);
	bool operator < (const CameraDevice& p_objCameraDevice) const;

	bool operator == (const CameraDevice& p_objCameraDevice) const;

private:
	
	int				m_nCameraId;										//摄像机的ID号
	
	char			m_szCameraName[CONST_MAXLENGTH_CAMERA_NAME + 1];	//摄像机的名字
	
	char			m_szCameraModel[CONST_MAXLENGTH_CAMERAMODEL + 1];	//摄像机的样式	
	
	int				m_nVideoSystem;										//视频制式
		
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CAMERADEVICE_H_
