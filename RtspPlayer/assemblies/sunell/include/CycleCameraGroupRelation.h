#ifndef _CYCLECAMERAGROUPRELATION_H_
#define _CYCLECAMERAGROUPRELATION_H_

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

class  SN_DLL_API CycleCameraGroupRelation
{
public:
	CycleCameraGroupRelation(void);
	~CycleCameraGroupRelation(void);

	//拷贝构造函数
	CycleCameraGroupRelation(const CycleCameraGroupRelation& p_objCameraGroupRelation);

public:
	/****************************************************************************
	**概述：
	*		设置网络视频设备的唯一标识符
	**输入：
	*		p_pszDeviceId ：网络视频设备的唯一标识符，字符串，最大长度为CONST_MAXLENGTH_DEVICEID字节,
	*						结尾以‘\0’结束。
	**输出：
	*		无
	**返回值：
	*		true： 成功
	*		false：失败 
	**功能：
	*		若输入p_pszDeviceId长度<=CONST_MAXLENGTH_DEVICEID，返回true.
	*		若输入p_pszDeviceId为NULL或其长度>CONST_MAXLENGTH_DEVICEID，返回false.
	*****************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/****************************************************************************
	**概述：
	*		获取网络设备的唯一标识符
	**输入：
	*		无
	**输出：
	*		无
	*返回值：
	*		网络设备的唯一标识符，字符串类型 
	**功能：
	*		
	*****************************************************************************/
	const char* getDeviceId() const;


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


	/************************************************************************
	**概述：
	*		设置隶属组ID
	**输入：
	*		p_nSupGroupId ：隶属组ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*    设置隶属组ID
	************************************************************************/
	void setSupGroupId(const int p_nSupGroupId);

	/************************************************************************
	**概述：
	*		获取隶属组ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		隶属组ID
	**功能：
	*     获取隶属组ID
	**************************************************************************/
	const int getSupGroupId() const;


	/************************************************************************
	**概述：
	*		设置顺序ID（针对画面）
	**输入：
	*		p_nSupGroupId ：顺序ID（针对画面）
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*    
	************************************************************************/
	void setSequenceId(const int p_nSequenceId);
	
	/************************************************************************
	**概述：
	*		获取顺序ID（针对画面）
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		顺序ID（针对画面）
	**功能：
	*     
	**************************************************************************/
	const int getSequenceId() const;
	

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objCameraGroupRelation ：摄像机组对象
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	**************************************************************************/
	CycleCameraGroupRelation& operator = (const CycleCameraGroupRelation& p_objCameraGroupRelation);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objCameraGroupRelation：CycleCameraGroupRelation类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个CycleCameraGroupRelation类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const CycleCameraGroupRelation& p_objCameraGroupRelation);

private:
	char	m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];	//设备id

	int		m_nCameraId;								//摄像机id

	int		m_nSupGroupId;								//隶属组id

	int		m_nPictureId;								//画面id

	int		m_nSequenceId;								//顺序ID（针对画面）

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CYCLECAMERAGROUPRELATION_H_
