#ifndef _CAMERA_ABILITY_
#define _CAMERA_ABILITY_

#include <vector>
#include "EncoderAbility.h"
#include "MotionDetectionAbility.h"
#include "SNPlatOS.h"

using namespace std;

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

/************************************************************************
**����������ͷ������Ϣ
*	��Ҫ����������Ϣ��
*		����ͷ��ţ�������ͷ֧�ֵı�����������Ϣ�б�
************************************************************************/

class SN_DLL_API CameraAbility
{
public:
	CameraAbility(void);
	~CameraAbility(void);

public:
	/************************************************************************
	**��������ȡ������ͷ�ı�����������Ϣ�б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������������Ϣ�б�
	*************************************************************************/
	vector<EncoderAbility>* getEncoderAbilityList() const;

	/************************************************************************
	**���������һ��������������Ϣ
	**���룺
	*		p_pobjEncoderAbility	������������Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void addEncoderAbility(EncoderAbility p_objEncoderAbility);

	/************************************************************************
	**���������ݱ�������ź���ʽ���Ҷ�Ӧ�ı�����������Ϣ��Ϣ
	**���룺
	*		p_nImageFormatId��ͼ���ʽ���
	*		p_nVideoSystem: ��Ƶ��ʽ
	**�����
	*		pobjEncoderAbility����������������
	**����ֵ��
	*		true �����ҳɹ�
	*		false������ʧ��
	*************************************************************************/
	bool findEncoderAbility(const int p_nImageFormatId, const int p_nVideoSystem, EncoderAbility& pobjEncoderAbility);
	bool findEncoderAbility(const int p_nVideoSystem, vector<EncoderAbility> & pobjEncoderAbilityList);


	/************************************************************************
	**��������ȡ������ͷ���ƶ����������Ϣ�б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�ƶ����������Ϣ�б�
	*************************************************************************/
	vector<MotionDetectionAbility>* getMotionDetectionAbilityList() const;

	/************************************************************************
	**���������һ���ƶ����������Ϣ
	**���룺
	*		p_pobjMotionDetectionAbility	�ƶ����������Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void addMotionDetectionAbility(MotionDetectionAbility p_objMotionDetectionAbility);

	/************************************************************************
	**�����������ƶ�����ź���ʽ���Ҷ�Ӧ���ƶ����������Ϣ��Ϣ
	**���룺
	*		p_nImageFormatId��ͼ���ʽ���
	**�����
	*		pobjMotionDetectionAbility���ƶ������������
	**����ֵ��
	*		true �����ҳɹ�
	*		false������ʧ��
	*************************************************************************/
	bool findMotionDetectionAbility(const int p_nImageFormatId, MotionDetectionAbility& pobjMotionDetectionAbility);

	/************************************************************************
	**��������������ͷ���
	**���룺
	*		p_nCameraId��	����ͷ���
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**��������ȡ����ͷ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ͷ���
	*************************************************************************/
	const int getCameraId() const;

	
	/************************************************************************
	**�����������û������ñ�־
	**���룺
	*		p_UserConfigurable	�û������ñ�־(true:�û����䣬false:�û�������)
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setUserConfigurable(const bool p_UserConfigurable);

	/************************************************************************
	**��������ȡ�û������ñ�־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�û������ñ�־
	*************************************************************************/
	const bool getUserConfigurable() const;

	/************************************************************************
	**�����������˶�����־
	**���룺
	*		p_bFlag		�˶�����־
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setMotionDetectionSupportFlag(const bool p_bFlag);

	/************************************************************************
	**��������ȡ�˶�����־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		true	�˶�����־	
	*		false	���˶�����־	
	*************************************************************************/
	const bool getMotionDetectionSupportFlag() const;

	bool operator < (const CameraAbility& p_objCameraAbility) const;

	bool operator == (const CameraAbility& p_objCameraAbility) const;

private:
	vector<EncoderAbility>				m_objEncoderAbilityList;						//��Ƶ���������б�
	vector<MotionDetectionAbility>		m_objMotionDetectionAbilityList;				//�ƶ���������б�
	int									m_nCameraId;									//����ͷ���
	bool								m_bUserConfigurable;							//��Ƶ���Ƿ����û�����
	bool								m_bMotionDetectionSupportFlag;					//�˶�����־,true��ʾ֧��,false��ʾ��֧��
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CAMERA_ABILITY_
