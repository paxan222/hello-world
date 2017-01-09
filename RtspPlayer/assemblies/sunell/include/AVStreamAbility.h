#ifndef _AVSTREAMABILITY_H_
#define _AVSTREAMABILITY_H_

#include <vector>
#include "StreamEncodeAbility.h"
#include "AVStreamAttributeAbility.h"
#include "ROIAbility.h"
#include "DomainConst.h"
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

class SN_DLL_API AVStreamAbility
{
public:
	AVStreamAbility(void);
	~AVStreamAbility(void);

public:
	/************************************************************************
	*	��������������ID
	*	���룺
	*		p_nStreamId��	����ID
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setStreamId(int p_nStreamId);

	/************************************************************************
	*	��������ȡ����ID
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		����ID
	*************************************************************************/
	int getStreamId() const;

	/************************************************************************
	*	�����������������Բ���
	*	���룺
	*		p_objAVStreamAttributeAbility��	�������Բ���
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setAVStreamAttributeAbility(const AVStreamAttributeAbility &p_objAVStreamAttributeParam);

	/************************************************************************
	*	��������ȡ�������Բ���
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		�������Բ���
	*************************************************************************/
	const AVStreamAttributeAbility &getAVStreamAttributeAbility() const;

	/************************************************************************
	*	����������֧�ֵ��������������б�
	*	���룺
	*		p_objStreamEncodeAbilityList��	�������������б�
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setStreamEncodeAbilityList(const vector<StreamEncodeAbility> & p_objStreamEncodeAbilityList);

	/************************************************************************
	*	��������ȡ֧�ֵ��������������б�
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		�������������б�
	*************************************************************************/
	const vector<StreamEncodeAbility> & getStreamEncodeAbilityList() const;

	/************************************************************************
	*	����������ROI����
	*	���룺
	*		p_objROIAbility��	ROI����
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setROIAbility(const ROIAbility & p_objROIAbility);

	/************************************************************************
	*	��������ȡROI����
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		ROI����
	*************************************************************************/
	const ROIAbility & getROIAbility() const;

	bool findStreamEncodeAbility(int p_nEncoderType, StreamEncodeAbility & p_objStreamEncodeAbility) const;

	const bool getSupportROI()const;
	void setSupportROI(const bool p_SupportROI);
private:
	int							m_nStreamId;						//����ID
	vector<StreamEncodeAbility>	m_objStreamEncodeAbilityList;		//�������������б�
	AVStreamAttributeAbility    m_objAVStreamAttributeAbility;	//������������
	bool						m_bSupportROI;
	ROIAbility					m_objROIAbility;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_AVSTREAMABILITY_H_
