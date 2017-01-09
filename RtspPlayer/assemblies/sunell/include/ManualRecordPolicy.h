#ifndef _MANUALRECORDPOLICY_
#define _MANUALRECORDPOLICY_
#include "SNPlatOS.h"
#include "RecordInfo.h"

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

class  SN_DLL_API ManualRecordPolicy
{
public:
	ManualRecordPolicy();
	~ManualRecordPolicy();

	const bool isFileLocked() const;
	void  setFileLocked(bool p_bIsFileLocked);
	
	void setPreRecordTime(int p_nPreRecordTime);
	const int  getPreRecordTime() const;
	
	void setRecordInfo(const RecordInfo &p_objRecordInfo);	

	const RecordInfo& getRecordInfo() const;
	
	void setDelayRecordTime(int p_nDelayRecordTime);

	const int  getDelayRecordTime() const;


	bool operator == (const ManualRecordPolicy& p_objManualRecordpolicy);
	

private:
	RecordInfo		m_objRecordInfo;			
	bool			m_bIsFileLocked;			//�ֶ�¼���ļ��Ƿ�����
	int				m_nPreRecordTime;			//¼���Ԥ¼ʱ��
	int				m_nDelayRecordTime;			//¼�����¼ʱ��
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_MANUALRECORDPOLICY_
