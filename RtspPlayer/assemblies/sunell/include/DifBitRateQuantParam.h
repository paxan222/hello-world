#ifndef DIF_BITRATE_QUANT_PARAM_H
#define DIF_BITRATE_QUANT_PARAM_H
#include <map>
#include "SNPlatOS.h"
#include "DomainConst.h"

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

class SN_DLL_API DifBitRateQuantParam
{
public:
    DifBitRateQuantParam(void);
    ~DifBitRateQuantParam(void);
public:
    void setBitRateQuantParam(const double &p_dDifBitRate, const int & p_nDifQuant);

    void getBitRateQuantParam(double &p_dDifBitRate, int & p_nDifQuant);

private:
    double  m_dDifBitRate;
    int         m_nDifQuant;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/

#endif