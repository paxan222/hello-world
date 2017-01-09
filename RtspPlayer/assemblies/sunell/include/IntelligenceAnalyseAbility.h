#ifndef _INTELLIGENCEANALYSEABILITY_H
#define _INTELLIGENCEANALYSEABILITY_H

#include "LibCommonAbility.h"
#include "MotionDetectionAbilityV2.h"
#include "PerimeterAbility.h"
#include "TripWireAbility.h"
#include "MultiTripWireAbility.h"
#include "LoiterAbility.h"
#include "MultiLoiterAbility.h"
#include "ObjLeftAbility.h"
#include "ObjMoveAbility.h"
#include "AbnormalSpeedAbility.h"
#include "ConverseAbility.h"
#include "NoParkingAbility.h"
#include "CameraTamperAbility.h"
#include "CameraMoveAbility.h"
#include "AdvancedAbility.h"
#include "SignalBadAbility.h"

#include <string>
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
/**********************************************************************/

class SN_DLL_API IntelligenceAnalyseAbility
{
public:
	IntelligenceAnalyseAbility();
	~IntelligenceAnalyseAbility();

    /***********************************************************************
	*	�������������ܷ��������İ汾
	*	���룺
	*		p_nVersion �����ܷ��������İ汾
	*	�����
	*		��
	*	����ֵ��
	*		��
	*   �������ģ�
	*       �汾���ڱ�־��ǰ�����Ƿ����µ�
	************************************************************************/
	void setVersion(const int p_nVersion);

    /***********************************************************************
	*	��������ȡ���ܷ��������İ汾
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		int �����ܷ��������İ汾
	*   �������ģ�
	*       �汾���ڱ�־��ǰ�����Ƿ����µ�
	************************************************************************/
	const int getVersion() const;

    /***********************************************************************
	*	�������������ܷ����Ĺ��������б�
	*	���룺
	*		p_objLibCommonAbilityList �����ܷ����Ĺ��������б�
	*	�����
	*		��
	*	����ֵ��
	*		��
	*   �������ģ�
	*       p_objLibCommonAbilityList�б���Ϊ��ǰ�豸����֧�ֵ����ܷ�����ĸ�����
	*       �Լ���Ҫ�����ò�����
	************************************************************************/
	void setLibCommonAbilityList(const std::vector<LibCommonAbility> &p_objLibCommonAbilityList);

    /***********************************************************************
	*	��������ȡ���ܷ����Ĺ��������б�
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		vector<LibCommonAbility> �����ܷ����Ĺ��������б�
	*   �������ģ�
	*       p_objLibCommonAbilityList�б���Ϊ��ǰ�豸����֧�ֵ����ܷ�����ĸ�����
	*       �Լ���Ҫ�����ò�����
	************************************************************************/
	const std::vector<LibCommonAbility>& getLibCommonAbilityList() const;

    /***********************************************************************
	*	�������������ܷ������ƶ���������
	*	���룺
	*		p_objMotionDetectionAbilityV2 �����ܷ��������ܷ������ƶ���������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*   �������ģ�
	*       ��
	************************************************************************/
	void setMotionDetectionAbilityV2(const MotionDetectionAbilityV2 &p_objMotionDetectionAbilityV2);

    /***********************************************************************
	*	��������ȡ���ܷ������ƶ���������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		MotionDetectionAbilityV2 �����ܷ������ƶ���������
	*   �������ģ�
	*       ��
	************************************************************************/
	const MotionDetectionAbilityV2& getMotionDetectionAbilityV2() const;

    /***********************************************************************
	*	�������������ܷ������ܽ����ֵ�����
	*	���룺
	*		p_objPerimeterAbility �����ܷ������ܽ����ֵ�����
	*	�����
	*		��
	*	����ֵ��
	*		��
	*   �������ģ�
	*       ��
	************************************************************************/
	void setPerimeterAbility(const PerimeterAbility &p_objPerimeterAbility);

    /***********************************************************************
	*	��������ȡ���ܷ������ܽ����ֵ�����
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		PerimeterAbility �����ܷ������ܽ����ֵ�����
	*   �������ģ�
	*       ��
	************************************************************************/
	const PerimeterAbility& getPerimeterAbility() const;

    /***********************************************************************
	*	�������������ܷ����İ��ߵ�����
	*	���룺
	*		p_objTripWireAbility �����ܷ����İ��ߵ�����
	*	�����
	*		��
	*	����ֵ��
	*		��
	*   �������ģ�
	*       ��
	************************************************************************/
	void setTripWireAbility(const TripWireAbility &p_objTripWireAbility);

    /***********************************************************************
	*	��������ȡ���ܷ����İ��ߵ�����
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		TripWireAbility �����ܷ����İ��ߵ�����
	*   �������ģ�
	*       ��
	************************************************************************/
	const TripWireAbility& getTripWireAbility() const;

    /***********************************************************************
	*	�������������ܷ�����˫���ߵ�����
	*	���룺
	*		p_objMultiTripWireAbility �����ܷ�����˫���ߵ�����
	*	�����
	*		��
	*	����ֵ��
	*		��
	*   �������ģ�
	*       ��
	************************************************************************/
	void setMultiTripWireAbility(const MultiTripWireAbility &p_objMultiTripWireAbility);

    /***********************************************************************
	*	��������ȡ���ܷ����İ��ߵ�����
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		MultiTripWireAbility �����ܷ�����˫���ߵ�����
	*   �������ģ�
	*       ��
	************************************************************************/
	const MultiTripWireAbility& getMultiTripWireAbility() const;

    /***********************************************************************
	*	�������������ܷ������ǻ�������
	*	���룺
	*		p_objLoiterAbility �����ܷ������ǻ�������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*   �������ģ�
	*       ��
	************************************************************************/
	void setLoiterAbility(const LoiterAbility &p_objLoiterAbility);

    /***********************************************************************
	*	��������ȡ���ܷ������ǻ�������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		LoiterAbility �����ܷ������ǻ�������
	*   �������ģ�
	*       ��
	************************************************************************/
	const LoiterAbility& getLoiterAbility() const;

    /***********************************************************************
	*	�������������ܷ����Ķ����ǻ�������
	*	���룺
	*		p_objMultiLoiterAbility �����ܷ����Ķ����ǻ�������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*   �������ģ�
	*       ��
	************************************************************************/
	void setMultiLoiterAbility(const MultiLoiterAbility &p_objMultiLoiterAbility);

    /***********************************************************************
	*	��������ȡ���ܷ����Ķ����ǻ�������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		MultiLoiterAbility �����ܷ����Ķ����ǻ�������
	*   �������ģ�
	*       ��
	************************************************************************/
	const MultiLoiterAbility& getMultiLoiterAbility() const;

    /***********************************************************************
	*	�������������ܷ�������������������
	*	���룺
	*		p_objObjLeftAbility �����ܷ�������������������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*   �������ģ�
	*       ��
	************************************************************************/
	void setObjLeftAbility(const ObjLeftAbility &p_objObjLeftAbility);

    /***********************************************************************
	*	��������ȡ���ܷ�������������������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		ObjLeftAbility �����ܷ�������������������
	*   �������ģ�
	*       ��
	************************************************************************/
	const ObjLeftAbility& getObjLeftAbility() const;

    /***********************************************************************
	*	�������������ܷ����������ƶ�������
	*	���룺
	*		p_objObjMoveAbility �����ܷ����������ƶ�������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*   �������ģ�
	*       ��
	************************************************************************/
	void setObjMoveAbility(const ObjMoveAbility &p_objObjMoveAbility);

    /***********************************************************************
	*	��������ȡ���ܷ����������ƶ�������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		ObjMoveAbility �����ܷ����������ƶ�������
	*   �������ģ�
	*       ��
	************************************************************************/
	const ObjMoveAbility& getObjMoveAbility() const;

    /***********************************************************************
	*	�������������ܷ����ķ������ٶȵ�����
	*	���룺
	*		p_objAbnormalSpeedAbility �����ܷ����ķ������ٶȵ�����
	*	�����
	*		��
	*	����ֵ��
	*		��
	*   �������ģ�
	*       ��
	************************************************************************/
	void setAbnormalSpeedAbility(const AbnormalSpeedAbility &p_objAbnormalSpeedAbility);

    /***********************************************************************
	*	��������ȡ���ܷ����ķ������ٶȵ�����
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		AbnormalSpeedAbility �����ܷ����ķ������ٶȵ�����
	*   �������ģ�
	*       ��
	************************************************************************/
	const AbnormalSpeedAbility& getAbnormalSpeedAbility() const;

    /***********************************************************************
	*	�������������ܷ��������е�����
	*	���룺
	*		p_objConverseAbility �����ܷ��������е�����
	*	�����
	*		��
	*	����ֵ��
	*		��
	*   �������ģ�
	*       ��
	************************************************************************/
	void setConverseAbility(const ConverseAbility &p_objConverseAbility);

    /***********************************************************************
	*	��������ȡ���ܷ��������е�����
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		ConverseAbility �����ܷ��������е�����
	*   �������ģ�
	*       ��
	************************************************************************/
	const ConverseAbility& getConverseAbility() const;

    /***********************************************************************
	*	�������������ܷ����ķǷ�ͣ��������
	*	���룺
	*		p_objNoParkingAbility �����ܷ����ķǷ�ͣ��������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*   �������ģ�
	*       ��
	************************************************************************/
	void setNoParkingAbility(const NoParkingAbility &p_objNoParkingAbility);

    /***********************************************************************
	*	��������ȡ���ܷ����ķǷ�ͣ��������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		NoParkingAbility �����ܷ����ķǷ�ͣ��������
	*   �������ģ�
	*       ��
	************************************************************************/
	const NoParkingAbility& getNoParkingAbility() const;

    /***********************************************************************
	*	�������������ܷ������ź��쳣������
	*	���룺
	*		p_objSignalBadAbility �����ܷ������ź��쳣������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*   �������ģ�
	*       ��
	************************************************************************/
	void setSignalBadAbility(const SignalBadAbility &p_objSignalBadAbility);

    /***********************************************************************
	*	��������ȡ���ܷ������ź��쳣������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		SignalBadAbility �����ܷ������ź��쳣������
	*   �������ģ�
	*       ��
	************************************************************************/
	const SignalBadAbility& getSignalBadAbility() const;

    /***********************************************************************
	*	�������������ܷ�������Ƶ�ڵ�������
	*	���룺
	*		p_objCameraTamperAbility �����ܷ�������Ƶ�ڵ�������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*   �������ģ�
	*       ��
	************************************************************************/
	void setCameraTamperAbility(const CameraTamperAbility &p_objCameraTamperAbility);

    /***********************************************************************
	*	��������ȡ���ܷ�������Ƶ�ڵ�������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		CameraTamperAbility �����ܷ�������Ƶ�ڵ�������
	*   �������ģ�
	*       ��
	************************************************************************/
	const CameraTamperAbility& getCameraTamperAbility() const;

    /***********************************************************************
	*	�������������ܷ�����������ƶ�������
	*	���룺
	*		p_objCameraMoveAbility �����ܷ�����������ƶ�������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*   �������ģ�
	*       ��
	************************************************************************/
	void setCameraMoveAbility(const CameraMoveAbility &p_objCameraMoveAbility);

    /***********************************************************************
	*	��������ȡ���ܷ�����������ƶ�������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		CameraMoveAbility �����ܷ�����������ƶ�������
	*   �������ģ�
	*       ��
	************************************************************************/
	const CameraMoveAbility& getCameraMoveAbility() const;

    /***********************************************************************
	*	�������������ܷ����ĸ߼�����������
	*	���룺
	*		p_objAdvancedAbility �����ܷ����ĸ߼�����������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*   �������ģ�
	*       ��
	************************************************************************/
	void setAdvancedAbility(const AdvancedAbility &p_objAdvancedAbility);

    /***********************************************************************
	*	��������ȡ���ܷ����ĸ߼�����������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		AdvancedAbility �����ܷ����ĸ߼�����������
	*   �������ģ�
	*       ��
	************************************************************************/
	const AdvancedAbility& getAdvancedAbility() const;

	IntelligenceAnalyseAbility& operator=(const IntelligenceAnalyseAbility& p_objIntelligenceAnalyseAbility);

private:
	int    	                       m_nVersion;                            //�汾
	std::vector<LibCommonAbility>  m_objLibCommonAbilityList;             //�������ܷ�����ر�������ֵ

	MotionDetectionAbilityV2       m_objMotionDetectionAbilityV2;         //�ƶ�����Ӧ������
	PerimeterAbility               m_objPerimeterAbility;                 //��������
	TripWireAbility                m_objTripWireAbility;                  //��������
	MultiTripWireAbility           m_objMultiTripWireAbility;             //˫��������
	LoiterAbility                  m_objLoiterAbility;                    //�ǻ�����
	MultiLoiterAbility             m_objMultiLoiterAbility;               //�����ǻ���Ӧ������
	ObjLeftAbility                 m_objObjLeftAbility;                   //��Ʒ������Ӧ������
	ObjMoveAbility                 m_objObjMoveAbility;                   //�������߶�Ӧ������
	AbnormalSpeedAbility           m_objAbnormalSpeedAbility;             //�������ٶȶ�Ӧ������
	ConverseAbility                m_objConverseAbility;                  //���ж�Ӧ������
	NoParkingAbility               m_objNoParkingAbility;                 //�Ƿ�ͣ����Ӧ������
	SignalBadAbility               m_objSignalBadAbility;                 //�ź��쳣��Ӧ������
	CameraTamperAbility            m_objCameraTamperAbility;              //��Ƶ�ڵ���Ӧ������
	CameraMoveAbility              m_objCameraMoveAbility;                //������ƶ���Ӧ������
	AdvancedAbility                m_objAdvancedAbility;                  //�߼�������Ӧ������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif //_INTELLIGENCEANALYSEABILITY_H
