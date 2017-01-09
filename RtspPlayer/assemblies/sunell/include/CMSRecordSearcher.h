#ifdef RECORD_INTERFACE

#ifndef _CMSRECORDSEARCHER_H_
#define _CMSRECORDSEARCHER_H_

#include "SNPlatOS.h"
#include "RecordDirInfo.h"
#include "RecordQueryCondition.h"
#include "RecordQueryResult.h"
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

class SN_DLL_API CMSRecordSearcher
{
public:
	CMSRecordSearcher();

	~CMSRecordSearcher();

public:
	/***********************************************************************
	*������
	*		����¼��Ŀ¼
	*���룺
	*		p_RecordDirInfoList��¼��Ŀ¼�б�
	*�����
	*		��
	*����ֵ��
	*		��
	*���ܣ�
	*		
	************************************************************************/
	void setRecordDirInfoList(const std::vector<RecordDirInfo> &p_objRecordDirInfoList);

	/***********************************************************************
	*������
	*		��ѯ¼��
	*���룺
	*		p_RecordQueryCondition����ѯ����
	*�����
	*		p_objRecordQueryResultList��¼���ѯ�����
	*����ֵ��
	*		��open�����ɹ�������SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*���ܣ�
	*		
	************************************************************************/
	int query(const RecordQueryCondition &p_objRecordQueryCondition, std::vector<RecordQueryResult> &p_objRecordQueryResultList);

private:
	//�������캯��
	CMSRecordSearcher(const CMSRecordSearcher& p_objObject)
	{
	}

	//��ֵ����
	CMSRecordSearcher& operator = (const CMSRecordSearcher& p_objObject)
	{
		return *this;
	}

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSRECORDSEARCHER_H_
#endif