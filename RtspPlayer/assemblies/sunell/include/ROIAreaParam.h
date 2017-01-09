#ifndef  _ROI_AREA_PARAM_H_
#define _ROI_AREA_PARAM_H_

#include "SNPlatOS.h"
#include "ROIInfoParam.h"
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

class SN_DLL_API ROIAreaParam
{
public:
    ROIAreaParam(void);
    ~ROIAreaParam(void);

    ROIAreaParam(const ROIAreaParam& p_objROIAreaParam);
public:
    /************************************************************************
	**������
	*		���ø���Ȥ�������ID
    **���룺
	*		p_nStreamID ������Ȥ�������ID
	************************************************************************/
	void setStreamID(const int p_nStreamID);
    /************************************************************************
	**������
	*		��ȡ����Ȥ�������
	**����ֵ��
	*		����Ȥ�������
	**************************************************************************/
	const int getStreamID() const ;
    /************************************************************************
	**������
	*		���ø���Ȥ����������ȼ�
	**���룺
	*		p_nROILevel�������ȼ�
	**************************************************************************/	
	void setROILevel(const int p_nROILevel);
    /************************************************************************
	**������
	*		��ȡ����Ȥ����������ȼ�
	**����ֵ��
	*		int������Ȥ����������ȼ�
	**************************************************************************/
	const int getROILevel() const ;
    //����ROI�������������Ϣ
    void setROIInfoList(const std::vector<ROIInfoParam> &p_objROIInfoParamList);
    //��ȡROI�������������Ϣ
    const std::vector<ROIInfoParam>& getROIInfoList()const;
    //��ֵ����
    ROIAreaParam& operator = (const ROIAreaParam& p_objROIAreaParam);
    //���ڱȽϺ���
    bool operator == (const ROIAreaParam& p_objROIAreaParam)const;

private:
    int				m_nStreamID;										        //��ID
    int				m_nROILevel;										        //ROI����������ȼ�
    std::vector<ROIInfoParam> m_objROIInfoParamList;  //ROI�����б���Ϣ
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/

#endif