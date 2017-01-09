#ifndef _MONITORTYPE_
#define _MONITORTYPE_

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

class SN_DLL_API MonitorType
{
public:
	MonitorType(void);
	~MonitorType(void);

public:
	/************************************************************************
	*	�������������ͱ��
	*	���룺
	*		p_TypeId	���ͱ��
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setTypeId(int p_TypeId);

	/************************************************************************
	*	��������ȡ���ͱ��
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		���ͱ��
	*************************************************************************/
	int getTypeId() const;

	/************************************************************************
	*	������������������
	*	���룺
	*		p_pszTypeName	��������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	bool setTypeName(const char* p_pszTypeName);

	/************************************************************************
	*	��������ȡ��������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		��������
	*************************************************************************/
	const char* getTypeName() const;

	MonitorType& operator = (const MonitorType& p_objMonitorType);
private:
	int		m_nTypeId;
	char	m_szTypeName[CONST_MAXLENTH_MONITOR_TYPE_NAME + 1];	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_MONITORTYPE_
