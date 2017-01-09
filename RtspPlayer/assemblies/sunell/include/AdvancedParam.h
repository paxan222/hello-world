#ifndef _ADV_PARAM_H
#define _ADV_PARAM_H
#include "DomainConst.h"
#include "PixelToRealSize.h"
#include <vector>

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

//智能周界高级参数
class  SN_DLL_API AdvancedParam
{
public:
	enum
	{
		INDOOR = 0,
		OUTDOOR = 1
	};
public:
	AdvancedParam();
	~AdvancedParam();

	AdvancedParam(const AdvancedParam& p_objAdvancedParam);
	AdvancedParam& operator=(const AdvancedParam& p_objAdvancedParam);
public:
	void setScene(const int p_nScene);
	const int  getScene()const;

	void setHight(const int p_nHight);
	const int  getHight()const;

	void setAngle(const float p_fAngle);
	const float  getAngle()const;

	void setFOV(const float p_fFOV);
	const float  getFOV()const;

	void setCameraShake(const int p_nCameraShake);
	const int getCameraShake() const;

	void setHighNoise(const int p_nHighNoise);
	const int getHighNoise() const;

	void setLowContrast(const int p_nLowContrast);
	const int getLowContrast() const;

	void setPeriodMotion(const int p_nPeriodMotion);
	const int getPeriodMotion() const;

	void setPeriodMotionTime(const int p_nPeriodMotionTime);
	const int getPeriodMotionTime() const;

	void setPixelToRealSizeList(const std::vector<PixelToRealSize>& p_objPixelToRealSizeList);
	const std::vector<PixelToRealSize>& getPixelToRealSizeList()const;

private:
	int			m_nScene;					//室内/室外
	int			m_nHight;						//安装高度hight
	float			m_fAngle;						//安装角度,相对于竖直向下
	float			m_fFOV;						//镜头视场角

	int			m_nCameraShake;				//摄像机抖动（0：关闭 1：打开）
	int			m_nHighNoise;				//高噪声环境（0: 关闭 1：打开）
	int			m_nLowContrast;				//低对比度（0:关闭 1：打开）
	int			m_nPeriodMotion;			//周期运动背景（0:关闭 1：打开)
	int			m_nPeriodMotionTime;		//周期运动背景时间(秒)

	std::vector<PixelToRealSize> m_objPixelToRealSizeList;//摄像机像素与实体物体长度的转换
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif