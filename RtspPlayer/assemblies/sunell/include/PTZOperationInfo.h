#ifndef PTZOPERATIONINFO_H_
#define PTZOPERATIONINFO_H_

#include "PTZOperationConst.h"
#include "PTZPointParamV2.h"
#include <string>
//PTZ������Ϣ�࣬��Ҫ��¼ˮƽ�ʹ�ֱת�����ٶȣ�ˮƽλ�úʹ�ֱλ�õ�����ȡ�
//ע�⣺�����а����ٶ����ݵ�����ת��
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


class SN_DLL_API PTZOperationInfo
{
public:
	PTZOperationInfo(void);
	~PTZOperationInfo(void);

public:
	//����ͨ��ID
	void setCommonID(const int p_nCommonID);
	//��ȡͨ��ID
	const int getCommonID()const;
	/*********************************************************************
	*********˵��������ˮƽ�ٶ�ֵ
	********************************************************************/
	void setPanSpeed(const int p_nPanSpeed);
	/*********************************************************************
	*********����ֵ��ˮƽ�ٶ���Ϣ
	********************************************************************/
	const int getPanSpeed()const;
	/*********************************************************************
	*********˵�������ô�ֱ�ٶ�
	********************************************************************/
	void setTiltSpeed(const int p_nTiltSpeed);
	/*********************************************************************
	*********����ֵ����ֱ�ٶ�
	********************************************************************/
	const int getTiltSpeed()const;
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

	//���ñ䱶�ٶ�ֵ
	void setZoomSpeedValue(const int p_nZoomSpeedValue);
	const int getZoomSpeedValue()const;

	//���þ۽��ٶ�ֵ
	void setFocusSpeedValue(const int p_nFocusSpeedValue);
	const int getFocusSpeedValue()const;

	//����ת������
	void setDirectionValue(const int p_nDirectionValue);
	const int getDirectionValue()const;

	//�����������Ϣ
	void setPTZPointParamV2(const PTZPointParamV2 &p_objPTZPointParamV2);
	//��ȡ�������Ϣ
	const PTZPointParamV2 &getPTZPointParamV2()const;

    bool setAlarmIOState(const unsigned char* p_szAlarmIOState, unsigned int nSize);
    const unsigned char* getAlarmIOState() const;

	//����ֹͣʱ��
	void setStopTime(const int p_nStopTime);
	const int getStopTime()const;

	//����PTZ�汾��
	void setPTZVersion(const std::string& p_strPTZVersion);
	const std::string& getPTZVersion()const;

	//����MCU�¶�
	void setMCUTemperature(const double p_dMCUTemperature);
	const double getMCUTemperature()const;

	//��������
	void setTypeValue(const int p_nVerticalMaxPosition);
	const int getTypeValue()const;

	//���ô�ֱ�������Ƕ�
	void setVerticalMaxPosition(const int p_nStopTime);
	const int getVerticalMaxPosition()const;

	PTZOperationInfo &operator=(const PTZOperationInfo &p_objPTOperationInfo);

	bool operator!=(const PTZOperationInfo& p_objPTZOperationInfo) const;

    bool operator==(const PTZOperationInfo& p_objPTZOperationInfo) const;

private:
	int m_nCommonID;
	int m_nPanSpeed;  //ˮƽ�ٶ�
	int m_nTiltSpeed; //��ֱ�ٶ�
	int m_nZoomSpeedValue; //�䱶�ٶ�
	int m_nFocusSpeedValue; //�۽��ٶ�
	int m_nDirectionValue; //ת������
	int m_nStopTime;	//ֹͣʱ��
	int m_nType;		// ����bit0=1��ʾ����PAN��Ч��0����PAN��ͬ��ģ�bit1��ӦTILT��bit2��ӦZOOM
	
	PTZPointParamV2 m_objPTZPointParamV2;//��¼������λ����Ϣ
    unsigned char   m_szAlarmIOState[2]; //����IO״̬
	std::string     m_strPTZVersion;  //PTZ�汾��
	double m_dMCUTemperature;//MCU�¶�
	int m_nVerticalMaxPosition;	//��ֱ�������Ƕ�
}_PACKED_1_;
/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
#endif

