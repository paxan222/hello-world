#ifndef MAGNIFY_PT_SPEED_PARAM_H
#define MAGNIFY_PT_SPEED_PARAM_H

#include <vector>
#include "SNPlatOS.h"
#include "PTZStageToSpeedParam.h"

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

class SN_DLL_API MagnifyPTSpeedParam
{
public:
	MagnifyPTSpeedParam();
	~MagnifyPTSpeedParam();

	// ���ñ���
	void setMagnify(const int p_nMagnify);
	//��ȡ����
	const int getMagnify() const;
	//���õ�λ�ٶȶ��ձ�
	void setPTZStageToSpeedParamList(const std::vector<PTZStageToSpeedParam> p_objPTZStageToSpeedParamList);
	//��õ�λ�ٶȶ��ձ�
	const std::vector<PTZStageToSpeedParam> &getPTZStageToSpeedParamList() const ;

	MagnifyPTSpeedParam& operator =(const MagnifyPTSpeedParam& p_objMagnifyPTSpeedParam);

private:
	int m_nMagnify;	//����
	std::vector<PTZStageToSpeedParam> m_objPTZStageToSpeedParamList;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/

#endif