#ifndef PTZPointParamV2_H_
#define PTZPointParamV2_H_

#include "SNPlatOS.h"
#include "PTZOperationConst.h"
#include <string>
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


class SN_DLL_API PTZPointParamV2
{
public:
	PTZPointParamV2(void);
	~PTZPointParamV2(void);
public:
	/*********************************************************************
	*********˵������ˮƽ����
	********************************************************************/
	void setPanPosion(const int p_nPanPosion);
	/*********************************************************************
	*********����ֵ��ˮƽλ����Ϣ
	********************************************************************/
	const int getPanPosion()const;
	/*********************************************************************
	*********˵�������ô�ֱ����
	********************************************************************/
	void setTiltPosion(const int p_nTiltPosion);
	/*********************************************************************
	*********����ֵ����ֱλ����Ϣ
	********************************************************************/
	const int getTiltPosion()const;

	//���ñ䱶�ı���ֵ
	void setZoomValue(const int p_nZoomValue);
	const int getZoomValue()const;

	//�������ֱ䱶�ı���ֵ
	void setDZoomValue(const int p_nDZoomValue);
	const int getDZoomValue()const;

	//���þ۽��ľ۽�ֵ
	void setDayFocusValue(const int p_nDayFocusValue);
	const int getDayFocusValue()const;

	void setNightFocusValue(const int p_nNightFocusValue);
	const int getNightFocusValue()const;

	PTZPointParamV2 &operator=(const PTZPointParamV2 &p_objPTZPointParamV2);

	bool operator!=(const PTZPointParamV2& p_objPTZPointParamV2) const;
	bool operator==(const PTZPointParamV2& p_objPTZPointParamV2) const;

private:
	int m_nPanPosion; //ˮƽ����
	int m_nTiltPosion; //��ֱ����
	int m_nZoomValue; //�䱶����
	int m_nDZoomValue;	//���ֱ䱶ֵ
	int m_nDayFocusValue; //�վ۽�ֵ
	int m_nNightFocusValue; //ҹ�۽�ֵ
}_PACKED_1_;
/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
#endif

