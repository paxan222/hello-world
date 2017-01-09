#ifndef _TIME_ZONE_ABILITY_H_
#define _TIME_ZONE_ABILITY_H_

#include "TimeZoneType.h"
#include "SNPlatOS.h"
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

//
class SN_DLL_API TimeZoneAbility
{
public:
	TimeZoneAbility();
	
	~TimeZoneAbility();

	void setTimeZoneTypeList(const std::vector<TimeZoneType>& p_objTimeZoneTypeList);
	const std::vector<TimeZoneType>& getTimeZoneTypeList() const;

	int getInt() const;
private:
	
	std::vector<TimeZoneType> m_objTimeZoneTypeList;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif	//_TIME_ZONE_ABILITY_H_








