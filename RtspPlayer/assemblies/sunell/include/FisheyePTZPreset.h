#ifndef _FISHEYE_PTZ_PRESET_H_
#define _FISHEYE_PTZ_PRESET_H_

#include "DomainConst.h"
#include <string.h>
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

class SN_DLL_API FisheyePTZPreset
{
public:
	FisheyePTZPreset(void);
	virtual ~FisheyePTZPreset(void);
	FisheyePTZPreset(const FisheyePTZPreset& p_objPTZPreset);	

	void setCameraId(const int p_nCameraId);
	const int getCameraId() const;

	void setDewarpMode(const int p_nDewarpMode);
	const int getDewarpMode()const;

	void setPtzId(const int p_nPtzId);
	const int getPtzId()const;

	void setPresetId(const int p_nPresetId);
	const int getPresetId() const;

	bool setPresetName(const char* p_pszPresetName);
	const char* getPresetName() const;

	FisheyePTZPreset& operator =(const FisheyePTZPreset& p_objPTZPreset);
	bool operator == (const FisheyePTZPreset& p_objPTZPreset)const;

private:
	int		m_nCameraId;													//摄像头ID号
	int		m_nDewarpMode;													//矫正模式
	int		m_nPtzId;														//PTZ ID号
	int		m_nPresetId;													//云台预制点的ID号
	char	m_szPresetName[CONST_MAXLENGTH_PTZ_PRESET_NAME + 1];			//云台预制点的名字
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif
