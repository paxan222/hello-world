#ifndef _ADV_PARAM_H
#define _ADV_PARAM_H
#include "DomainConst.h"
#include "PixelToRealSize.h"
#include <vector>

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

//�����ܽ�߼�����
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
	int			m_nScene;					//����/����
	int			m_nHight;						//��װ�߶�hight
	float			m_fAngle;						//��װ�Ƕ�,�������ֱ����
	float			m_fFOV;						//��ͷ�ӳ���

	int			m_nCameraShake;				//�����������0���ر� 1���򿪣�
	int			m_nHighNoise;				//������������0: �ر� 1���򿪣�
	int			m_nLowContrast;				//�ͶԱȶȣ�0:�ر� 1���򿪣�
	int			m_nPeriodMotion;			//�����˶�������0:�ر� 1����)
	int			m_nPeriodMotionTime;		//�����˶�����ʱ��(��)

	std::vector<PixelToRealSize> m_objPixelToRealSizeList;//�����������ʵ�����峤�ȵ�ת��
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif