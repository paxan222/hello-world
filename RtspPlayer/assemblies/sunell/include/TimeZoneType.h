#ifndef _TIME_ZONE_TYPE_H_
#define _TIME_ZONE_TYPE_H_

#include "DomainConst.h"
#include "SNPlatOS.h"

/**********************************************************************/
//此处用于控制文件编译字节对齐，拷贝时两行注释间内容需一起拷贝，
//结束处的“#ifdef PRAGMA_PACK”部分也要一起拷贝，否则pragma pack入栈出栈不匹配
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

//
class  SN_DLL_API TimeZoneType
{
public:

	void setTimeZoneID(int p_nTimeZoneID);
	int getTimeZoneID() const;


	bool setTimeZoneName(const char* p_pszTimeZoneName);
	const char* getTimeZoneName() const;

	bool setSTDTimeZoneAbbreviation(const char* p_pszSTDTimeZoneAbbreviation);
	const char* getSTDTimeZoneAbbreviation() const;

	bool setDSTTimeZoneAbbreviation(const char* p_pszSTDTimeZoneAbbreviation);
	const char* getDSTTimeZoneAbbreviation() const;

	TimeZoneType& operator = (const TimeZoneType &p_objTimeZoneType);

private:

	int		m_nTimeZoneID;													//时区ID
	char	m_szTimeZoneName[CONST_MAXLENGTH_TIME_ZONE_NAME + 1];			//时区名称
	char	m_szSTDTimeZoneAbbreviation[CONST_MAXLENGTH_TIME_ZONE_NAME + 1];//标准时区简称
	char	m_szDSTTimeZoneAbbreviation[CONST_MAXLENGTH_TIME_ZONE_NAME + 1];//夏令时时区简称
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif	//_TIME_ZONE_TYPE_H_



