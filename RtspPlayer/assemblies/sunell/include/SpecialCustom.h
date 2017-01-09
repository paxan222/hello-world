#ifndef _SPECIALCUSTOM_H_
#define _SPECIALCUSTOM_H_
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

class SN_DLL_API SpecialCustom
{
public:
	SpecialCustom(void);
	~SpecialCustom(void);

	void setDispalyInfoShowFlag(const bool p_bEnableFlag);
	//��ȡ�Ƿ���ʾ��Ϣ
	bool getDispalyInfoShowFlag() const;

	//�����Ƿ���ʾ������
	void  setStreamNameShowFlag(const bool p_bEnableFlag);
	//��ȡ�Ƿ���ʾ������
	bool getStreamNameShowFlag() const;

	//�����Ƿ���ʾ��������
	void setEncodeTypeShowFlag(const bool p_bEnableFlag);
	//��ȡ�Ƿ���ʾ��������
	bool getEncodeTypeShowFlag() const;

	//�����Ƿ���ʾ�ֱ���
	void setResolutionNameShowFlag(const bool p_bEnableFlag);
	//��ȡ�Ƿ���ʾ�ֱ���
	bool getResolutionNameShowFlag() const;

	//�����Ƿ���ʾ֡��
	void setFrameRateShowFlag(const bool p_bEnableFlag);
	//��ȡ�Ƿ���ʾ֡��
	bool getFrameRateShowFlag() const;

	//�����Ƿ���ʾ������
	void setBitRateShowFlag(const bool p_bEnableFlag);
	//��ȡ�Ƿ���ʾ������
	bool getBitRateShowFlag() const;


	bool operator == (const SpecialCustom &p_objSpecialCustom);
private:
	bool		m_bDispalyInfoShowFlag;
	bool		m_bStreamNameShowFlag;
	bool		m_bEncodeTypeShowFlag;
	bool		m_bResolutionNameShowFlag;
	bool		m_bFrameRateShowFlag;
	bool		m_bBitRateShowFlag;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif
