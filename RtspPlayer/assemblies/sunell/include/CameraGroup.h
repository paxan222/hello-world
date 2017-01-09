#ifndef _CAMERAGROUP_H_
#define _CAMERAGROUP_H_

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

class SN_DLL_API CameraGroup
{
public:
	CameraGroup(void);
	~CameraGroup(void);

	//拷贝构造函数
	CameraGroup(const CameraGroup& p_objCameraGroup);

public:

	/************************************************************************
	**概述：
	*		设置组Id号
	**输入：
	*		p_nGroupId ：组Id号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*    设置组Id号
	************************************************************************/
	void setGroupId(const int p_nGroupId);

	/************************************************************************
	**概述：
	*		获取组Id号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		组Id号
	**功能：
	*     获取摄像机的Id号
	**************************************************************************/
	const int getGroupId() const ;


	/****************************************************************************
	**概述：
	*		设置组名称
	**输入：
	*		p_pszGroupName ：组名称,结尾以‘\0’结束。
	**输出：
	*		无
	**返回值：
	*		true： 成功
	*		false：失败 
	**功能：
	*		若输入p_pszGroupName长度<=CONST_MAXLENGTH_GROUPNAME，返回true.
	*		若输入p_pszGroupName为NULL或其长度>CONST_MAXLENGTH_GROUPNAME，返回false.
	*****************************************************************************/
	bool setGroupName(const char* p_pszGroupName);

	/****************************************************************************
	**概述：
	*		获取组名称
	**输入：
	*		无
	**输出：
	*		无
	*返回值：
	*		组名称，字符串类型 
	**功能：
	*		
	*****************************************************************************/
	const char* getGroupName() const;


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
	*		设置组的级别
	**输入：
	*		p_nGroupLevel ：组级别
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*    设置组的级别
	************************************************************************/
	void setGroupLevel(const int p_nGroupLevel);

	/************************************************************************
	**概述：
	*		获取组的级别
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		组级别
	**功能：
	*     获取组的级别
	**************************************************************************/
	const int getGroupLevel() const;


	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objCameraGroup ：设备组对象
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	**************************************************************************/
	CameraGroup& operator = (const CameraGroup& p_objCameraGroup);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objCameraGroup：CameraGroup类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个CameraGroup类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const CameraGroup& p_objCameraGroup);

private:

	int		m_nGroupId;										//组id
	
	char	m_szGroupName[CONST_MAXLENGTH_GROUPNAME + 1];	//组名称
	
	int		m_nSupGroupId;									//隶属组id，若无隶属组为0

	int		m_nGroupLevel;									//组级别

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CAMERAGROUP_H_
