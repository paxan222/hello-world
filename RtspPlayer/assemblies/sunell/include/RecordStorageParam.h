#ifndef _RECORDSTORAGEPARAM_H_
#define _RECORDSTORAGEPARAM_H_

#include "WritePolicy.h"
#include "SavePolicy.h"
#include "SpacePolicy.h"
#include <vector>
#include "SNPlatOS.h"

using namespace std;

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

class SN_DLL_API RecordStorageParam
{
public:
	RecordStorageParam();
	~RecordStorageParam();

	//拷贝构造函数
	RecordStorageParam(const RecordStorageParam &p_objRecordStorageParam);

public:
	/************************************************************************
	**概述：
	*		设置磁盘写策略
	**输入：
	*		p_objWritePolicy ：磁盘写策略
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	**************************************************************************/
	void setWritePolicy(const WritePolicy & p_objWritePolicy);

	/************************************************************************
	**概述：
	*		获取磁盘写策略
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		磁盘写策略
	**功能：
	*	
	**************************************************************************/
	const WritePolicy & getWritePolicy() const;


	/************************************************************************
	**概述：
	*		设置保存策略
	**输入：
	*		p_objSavePolicy ：保存策略
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	**************************************************************************/
	void setSavePolicy(const SavePolicy & p_objSavePolicy);

	/************************************************************************
	**概述：
	*		获取保存策略
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		保存策略
	**功能：
	*
	**************************************************************************/
	const SavePolicy & getSavePolicy() const;


	/************************************************************************
	**概述：
	*		设置磁盘空间策略
	**输入：
	*		pobjSpacePolicyList：磁盘空间策略列表
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	**************************************************************************/
	void setSpacePolicyList(const vector<SpacePolicy>& p_objSpacePolicyList);


	/************************************************************************
	**概述：
	*		获取磁盘空间策略
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		磁盘空间策略列表
	**功能：
	*	
	**************************************************************************/
	vector<SpacePolicy> * getSpacePolicyList() const;

	/****************************************************************************
	**概述：
	*		赋值函数
	*
	**输入：
	*		p_objRecordStorageParam：录制存储对象
	**输出：
	*		无
	**返回值：
	*		赋值后的录制存储对象
	**功能：
	*		
	*****************************************************************************/
	RecordStorageParam & operator=(const RecordStorageParam &p_objRecordStorageParam);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objRecordStorageParam：RecordStorageParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个RecordStorageParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator==(const RecordStorageParam &p_objRecordStorageParam);

private:
	WritePolicy				m_objWritePolicy;			//磁盘写策略

	SavePolicy				m_objSavePolicy;			//保存策略

	vector<SpacePolicy>		m_objSpacePolicyVector;		//磁盘空间策略
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_LOCALRECORDSTORAGEPARAM_H_
