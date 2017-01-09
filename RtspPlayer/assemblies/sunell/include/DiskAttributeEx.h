#ifndef _FILEATTRIBUTE_
#define _FILEATTRIBUTE_

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

class SN_DLL_API DiskAttributeEx
{
public:
	DiskAttributeEx(void);
	//�������캯��
	DiskAttributeEx(const DiskAttributeEx &p_objDiskAttributeEx);
	
	DiskAttributeEx &operator =(const DiskAttributeEx &p_objDiskAttributeEx);
	
	~DiskAttributeEx(void);
	
	void   setDiskAttribute(int p_nDiskAttribute);
	const int	   getDiskAttribute() const;

	void   setAttributeName(const char* p_szAttributeName);
	const char* getAttributeName() const;

private:
	int				m_nDiskAttribute;
	char			m_strAttributeName[CONST_MAXLENGTH_DISKATTRIBUTE_NAME+1];
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif  //_FILEATTRIBUTE_


