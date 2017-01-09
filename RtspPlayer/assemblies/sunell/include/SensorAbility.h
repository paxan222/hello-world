#ifndef _SENSORABILITY_H_
#define _SENSORABILITY_H_
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

class SN_DLL_API SensorAbility
{
public:
	enum SensorControllerOpenType
	{
		SENSOR_CONTROLLER_OPEN_TYPE_NULL		=0,
		SENSOR_CONTROLLER_OPEN_TYPE_UI			=1,	//打开UI界面的前端配置
		SENSOR_CONTROLLER_OPEN_TYPE_OSD_SN		=2, //打开SN的OSD类型的前端配置
		SENSOR_CONTROLLER_OPEN_TYPE_OSD_ZTB10	=3 //打开的OSD前端配置（针对ZTB10机型，95号预置位后需要先向左，再向下调出菜单）
	};
public:
	SensorAbility();
	~SensorAbility();
	/************************************************************************
	**概述：设置前端配置打开类型
	*
	**输入：
	*		p_nSensorControllerOpenType   前端配置打开类型，具体参照SensorControllerOpenType
	**输出：
	*		无
	**功能：       
	*		设置支持遮挡区域数量
	************************************************************************/
	void setSensorControllerOpenType(const int &p_nSensorControllerOpenType);

	/************************************************************************
	**概述：获取前端配置打开类型
	*
	**输入：
	*		无
	**返回：
	*		前端配置打开类型
	**功能：       
	*		获取前端配置打开类型
	************************************************************************/
	const int getSensorControllerOpenType() const;
private:
	int m_nSensorControllerOpenType;	     //前端配置打开类型，具体参照SensorControllerOpenType
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif // _SENSORABILITY_H_