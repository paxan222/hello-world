#ifndef _FISHEYEMOUNTABILITY_H_
#define _FISHEYEMOUNTABILITY_H_

#include <vector>
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

class SN_DLL_API FisheyeMountAbility
{
public:
	FisheyeMountAbility(void);
	~FisheyeMountAbility(void);
	//安装模式
	void setFisheyeMountTypeList(const std::vector<int> &p_objFisheyeMountTypeList);
	void getFisheyeMountTypeList(std::vector<int> &p_objFisheyeMountTypeList)const;

	//判断 m_objFisheyeMountTypeList 是否为空，空则返回true,
	bool empty()const;

	FisheyeMountAbility& operator=(const FisheyeMountAbility& p_objFisheyeMountAbility);

private:
	std::vector<int> m_objFisheyeMountTypeList; //安装模式，具体定义可查看FisheyeConst.h中FISHEYE_MOUNT_TYPE枚举定义
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/
#endif // _FISHEYEMOUNTABILITY_H_