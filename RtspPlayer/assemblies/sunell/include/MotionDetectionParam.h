#ifndef _MOTIONDETECTIONPARAM_H_
#define _MOTIONDETECTIONPARAM_H_

#include "SNPlatOS.h"
#include "DetectionArea.h"
#include <vector>
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

class SN_DLL_API MotionDetectionParam
{
public:
	MotionDetectionParam(void);
	~MotionDetectionParam(void);

	//�������캯��
	MotionDetectionParam (const MotionDetectionParam &p_objMotionDetectionParam);

	/****************************************************************************
	**������
	*		����������
	**���룺
	*		p_nSensitivity��������
	**�����
	*		��
	**����ֵ��
	*		�� 
	**���ܣ�
	*		
	*******************************************************************************/
	void setSensitivity(const int p_nSensitivity);

	/****************************************************************************
	**������
	*		���������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������
	**���ܣ�
	*
	*******************************************************************************/
	const int getSensitivity() const;


	/************************************************************************
	**������
	*		�����������ļ�����
	**���룺
	*		p_nCheckBlockNum���������ļ�����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	void setCheckBlockNum(const int p_nCheckBlockNum);

	/************************************************************************
	**������
	*		��ȡ�������ļ�����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ļ�����
	**���ܣ�
	*
	************************************************************************/
	const int getCheckBlockNum() const ;


	/************************************************************************
	**������
	*		�������ϼ��ı�־
	**���룺
	*		p_bToUpCheckFlag�����ϼ��ı�־
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	�������ϼ��ı�־
	************************************************************************/
	void setToUpCheckFlag(const bool p_bToUpCheckFlag);

	/************************************************************************
	**������
	*		��ȡ���ϼ��ı�־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���ϼ��ı�־
	**���ܣ�
	*	��ȡ���ϼ��ı�־
	************************************************************************/
	const bool getToUpCheckFlag()const;


	/************************************************************************
	**������
	*		�������¼��ı�־
	**���룺
	*		p_bToDownCheckFlag�����¼��ı�־
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	�������¼��ı�־
	************************************************************************/
	void setToDownCheckFlag(const bool p_bToDownCheckFlag);

	/************************************************************************
	**������
	*		��ȡ���¼��ı�־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���¼��ı�־
	**���ܣ�
	*	��ȡ���¼��ı�־
	************************************************************************/
	const bool getToDownCheckFlag() const ;


	/************************************************************************
	**������
	*		����������ı�־
	**���룺
	*		p_bToLeftCheckFlag��������ı�־
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	����������ı�־
	************************************************************************/
	void setToLeftCheckFlag(const bool p_bToLeftCheckFlag);

	/************************************************************************
	**������
	*		��ȡ������ı�־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������ı�־
	**���ܣ�
	*	��ȡ������ı�־
	************************************************************************/
	const bool getToLeftCheckFlag() const ;


	/************************************************************************
	**������
	*		�������Ҽ��ı�־
	**���룺
	*		p_bToRightCheckFlag�����Ҽ��ı�־
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	�������Ҽ��ı�־
	************************************************************************/
	void setToRightCheckFlag(const bool p_bToRightCheckFlag);

	/************************************************************************
	**������
	*		��ȡ���Ҽ��ı�־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���Ҽ��ı�־
	**���ܣ�
	*	��ȡ���Ҽ��ı�־
	************************************************************************/
	const bool getToRightCheckFlag() const ;


	/************************************************************************
	**������
	*		������������Ƿ����α�ʶ
	**���룺
	*		p_bAreaMaskFlag����������Ƿ����α�ʶ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	������������Ƿ����α�ʶ
	************************************************************************/
	void setAreaMaskFlag(const bool p_bAreaMaskFlag) ;

	/************************************************************************
	**������
	*		��ȡ��������Ƿ����α�ʶ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��������Ƿ����α�ʶ
	**���ܣ�
	*	��ȡ��������Ƿ����α�ʶ
	************************************************************************/
	const bool getAreaMaskFlag() const ;


	/************************************************************************
	**������
	*		������Ƶ��ʽID
	**���룺
	*		p_nImageFormatId����Ƶ��ʽID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	������Ƶ��ʽID
	************************************************************************/
	void setImageFormatId(const int p_nImageFormatId) ;

	/************************************************************************
	**������
	*		��ȡ��Ƶ��ʽID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ��ʽID
	**���ܣ�
	*	��ȡ��Ƶ��ʽID
	************************************************************************/
	const int getImageFormatId() const ;


	/************************************************************************
	**������
	*		�����������֡���
	**���룺
	*		p_nFrameInterval���������֡���
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	�����������֡���
	************************************************************************/
	void setFrameInterval(const int p_nFrameInterval);

	/************************************************************************
	**������
	*		��ȡ�������֡���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������֡���
	**���ܣ�
	*	��ȡ�������֡���
	************************************************************************/
	const int getFrameInterval() const ;

	/************************************************************************
	**������
	*		�����������
	**���룺
	*		p_pobjDetectionAreaList���������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	�����������
	************************************************************************/
	void setDetectionArea(const vector<DetectionArea>& p_pobjDetectionAreaList);

	/************************************************************************
	**������
	*		��ȡ�����������б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�����������б�
	**���ܣ�
	*      
	**************************************************************************/
	vector<DetectionArea>* getDetectionArea() const;

	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objMotionDetectionParam���ƶ����������
	**�����
	*		��
	**����ֵ��
	*		��ֵ����ƶ����������
	**���ܣ�
	*		
	*****************************************************************************/
	MotionDetectionParam& operator = (const MotionDetectionParam &p_objMotionDetectionParam);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objMotionDetectionParam��MotionDetectionParam���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true �����
	*		false�������
	**���ܣ�
	*		����MotionDetectionParam��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	//bool operator == (const MotionDetectionParam& p_objMotionDetectionParam) const;

private:

	bool		m_bToUpCheckFlag;										//�����⣨true����⣬false������⣩
	bool		m_bToDownCheckFlag;										//���¼�⣨true����⣬false������⣩
	bool		m_bToLeftCheckFlag;										//�����⣨true����⣬false������⣩
	bool		m_bToRightCheckFlag;									//���Ҽ�⣨true����⣬false������⣩
	bool		m_bAreaMaskFlag;										//���α�ʶ��true�����Σ�false����⣩
	int			m_nCheckBlockNum;										//���������ٷֱȣ�ָռ���ƶ��������İٷֱȣ��ٷֱ�ԽС�����������Խ��
	int			m_nSensitivity;											//�����ȣ��˲�����Ч������ʹ��
	int			m_nImageFormatId;										//��Ƶ��ʽ���˲�����Ч������ʹ��
	int			m_nFrameInterval;										//֡���
	vector<DetectionArea>			m_objDetectionAreaList;				//�ƶ���������б�

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_MOTIONDETECTIONPARAM_H_