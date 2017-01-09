#ifndef _CAMERA_ABILITY_
#define _CAMERA_ABILITY_

#include <vector>
#include "EncoderAbility.h"
#include "MotionDetectionAbility.h"
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

/************************************************************************
**概述：摄像头能力信息
*	主要包含以下信息：
*		摄像头编号，该摄像头支持的编码器能力信息列表
************************************************************************/

class SN_DLL_API CameraAbility
{
public:
	CameraAbility(void);
	~CameraAbility(void);

public:
	/************************************************************************
	**概述：获取该摄像头的编码器能力信息列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		编码器能力信息列表
	*************************************************************************/
	vector<EncoderAbility>* getEncoderAbilityList() const;

	/************************************************************************
	**概述：添加一个编码器能力信息
	**输入：
	*		p_pobjEncoderAbility	编码器能力信息
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void addEncoderAbility(EncoderAbility p_objEncoderAbility);

	/************************************************************************
	**概述：根据编码器编号和制式查找对应的编码器能力信息信息
	**输入：
	*		p_nImageFormatId：图像格式编号
	*		p_nVideoSystem: 视频制式
	**输出：
	*		pobjEncoderAbility：编码器能力参数
	**返回值：
	*		true ：查找成功
	*		false：查找失败
	*************************************************************************/
	bool findEncoderAbility(const int p_nImageFormatId, const int p_nVideoSystem, EncoderAbility& pobjEncoderAbility);
	bool findEncoderAbility(const int p_nVideoSystem, vector<EncoderAbility> & pobjEncoderAbilityList);


	/************************************************************************
	**概述：获取该摄像头的移动侦测能力信息列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		移动侦测能力信息列表
	*************************************************************************/
	vector<MotionDetectionAbility>* getMotionDetectionAbilityList() const;

	/************************************************************************
	**概述：添加一个移动侦测能力信息
	**输入：
	*		p_pobjMotionDetectionAbility	移动侦测能力信息
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void addMotionDetectionAbility(MotionDetectionAbility p_objMotionDetectionAbility);

	/************************************************************************
	**概述：根据移动侦测编号和制式查找对应的移动侦测能力信息信息
	**输入：
	*		p_nImageFormatId：图像格式编号
	**输出：
	*		pobjMotionDetectionAbility：移动侦测能力参数
	**返回值：
	*		true ：查找成功
	*		false：查找失败
	*************************************************************************/
	bool findMotionDetectionAbility(const int p_nImageFormatId, MotionDetectionAbility& pobjMotionDetectionAbility);

	/************************************************************************
	**概述：设置摄像头编号
	**输入：
	*		p_nCameraId：	摄像头编号
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**概述：获取摄像头编号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		摄像头编号
	*************************************************************************/
	const int getCameraId() const;

	
	/************************************************************************
	**概述：设置用户可配置标志
	**输入：
	*		p_UserConfigurable	用户可配置标志(true:用户可配，false:用户不可配)
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setUserConfigurable(const bool p_UserConfigurable);

	/************************************************************************
	**概述：获取用户可配置标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		用户可配置标志
	*************************************************************************/
	const bool getUserConfigurable() const;

	/************************************************************************
	**概述：设置运动检测标志
	**输入：
	*		p_bFlag		运动检测标志
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setMotionDetectionSupportFlag(const bool p_bFlag);

	/************************************************************************
	**概述：获取运动检测标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		true	运动检测标志	
	*		false	不运动检测标志	
	*************************************************************************/
	const bool getMotionDetectionSupportFlag() const;

	bool operator < (const CameraAbility& p_objCameraAbility) const;

	bool operator == (const CameraAbility& p_objCameraAbility) const;

private:
	vector<EncoderAbility>				m_objEncoderAbilityList;						//视频编码能力列表
	vector<MotionDetectionAbility>		m_objMotionDetectionAbilityList;				//移动侦测能力列表
	int									m_nCameraId;									//摄像头编号
	bool								m_bUserConfigurable;							//视频制是否由用户配置
	bool								m_bMotionDetectionSupportFlag;					//运动检测标志,true表示支持,false表示不支持
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CAMERA_ABILITY_
