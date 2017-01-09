#ifndef _TRACE_ABILITY_PARAM_V2_H
#define _TRACE_ABILITY_PARAM_V2_H

#include "SNPlatOS.h"
#include "IPTZModuleAbilityParam.h"

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

/***************************************************************************//**
 @brief �켣�������ò���ʵ����
******************************************************************************/

class SN_DLL_API TraceAbilityParamV2 : public IPTZModuleAbilityParam
{
public:
	TraceAbilityParamV2(void);
	~TraceAbilityParamV2(void);
	//��ȡ�켣�������
	const int getTraceMaxSecond() const {return m_nTraceMaxSecond;}
	//���ù켣�������
	void setTraceMaxSecond(const int &p_nSecond);
	//��ȡ�켣�����������
	const int getTraceMaxCmdNum() const {return m_nTraceMaxCmdNum;}
	//���ù켣�����������
 	void setTraceMaxCmdNum(const int &p_nNum);
// 	//���ù켣����ʼID
// 	void setTraceBeginID(const int p_nTraceBeginID);
// 	//���ù켣�Ľ���ID
// 	const int getTraceBeginID()const;
// 	//���ù켣����ʼID
// 	void setTraceEndID(const int p_nTraceEndID);
// 	//���ù켣�Ľ���ID
// 	const int getTraceEndID()const;
	//��ֵ����
	TraceAbilityParamV2& operator=(const TraceAbilityParamV2 &p_objTraceAbilityParam); 

	void setIDRange(const int & p_nIDRangeFrom , const int & p_nIDRangeTo);

	bool getIDRange(int & p_nIDRangeFrom , int & p_nIDRangeTo) const;

private:
	int m_nTraceMaxSecond;					//�켣�������
	int m_nTraceMaxCmdNum;				//�켣�����������
	//int m_nTraceBeginID;				//�켣����ʼ��ID
	//int m_nTraceEndID;					//�켣�Ľ�����ID

	int		m_nIDRangeFrom;				//The min ID value 
	int		m_nIDRangeTo;					//The max ID value
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/

#endif
