#ifndef _FISHEYE_PTZ_PRESET_H_
#define _FISHEYE_PTZ_PRESET_H_

#include "DomainConst.h"
#include <string.h>
#include "SNPlatOS.h"

/**********************************************************************/
//�˴����ڿ����ļ������ֽڶ��룬����ʱ����ע�ͼ�������һ�𿽱���
//�������ġ�#ifdef PRAGMA_PACK������ҲҪһ�𿽱�������pragma pack��ջ��ջ��ƥ��
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
	int		m_nCameraId;													//����ͷID��
	int		m_nDewarpMode;													//����ģʽ
	int		m_nPtzId;														//PTZ ID��
	int		m_nPresetId;													//��̨Ԥ�Ƶ��ID��
	char	m_szPresetName[CONST_MAXLENGTH_PTZ_PRESET_NAME + 1];			//��̨Ԥ�Ƶ������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif
