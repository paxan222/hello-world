#ifndef _BONJOUR_SERVICE_PARAM_H_
#define _BONJOUR_SERVICE_PARAM_H_

#include "DomainConst.h"
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

class SN_DLL_API BonjourServiceParam
{

public:
	BonjourServiceParam(void);
	~BonjourServiceParam(void);

	//�������캯��
	BonjourServiceParam(const BonjourServiceParam& p_objBonjourServiceParam);

public:
	/************************************************************************
	**������
	*		�����Ƿ�����Bonjour
	**���룺
	*		p_bFlag ������Bonjour��ʶ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	void setBonjourEnableFlag(const bool p_bFlag);

	/************************************************************************
	**������
	*		��ȡ����Bonjour��ʶ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����Bonjour��ʶ
	**���ܣ�
	*		
	**************************************************************************/
	const bool getBonjourEnableFlag() const;

	BonjourServiceParam &operator =(const BonjourServiceParam &p_objBonjourServiceParam);
	bool operator == (const BonjourServiceParam& p_objBonjourServiceParam);


private:
	bool		m_bBonjourEnableFlag;								//����bonjour��ʶ(true�����ã�false��������)
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_PPPOEPARAM_H_

