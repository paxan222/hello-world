#ifndef _RECORDSTORAGEPARAM_H_
#define _RECORDSTORAGEPARAM_H_

#include "WritePolicy.h"
#include "SavePolicy.h"
#include "SpacePolicy.h"
#include <vector>
#include "SNPlatOS.h"

using namespace std;

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

class SN_DLL_API RecordStorageParam
{
public:
	RecordStorageParam();
	~RecordStorageParam();

	//�������캯��
	RecordStorageParam(const RecordStorageParam &p_objRecordStorageParam);

public:
	/************************************************************************
	**������
	*		���ô���д����
	**���룺
	*		p_objWritePolicy ������д����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	**************************************************************************/
	void setWritePolicy(const WritePolicy & p_objWritePolicy);

	/************************************************************************
	**������
	*		��ȡ����д����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����д����
	**���ܣ�
	*	
	**************************************************************************/
	const WritePolicy & getWritePolicy() const;


	/************************************************************************
	**������
	*		���ñ������
	**���룺
	*		p_objSavePolicy ���������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	**************************************************************************/
	void setSavePolicy(const SavePolicy & p_objSavePolicy);

	/************************************************************************
	**������
	*		��ȡ�������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������
	**���ܣ�
	*
	**************************************************************************/
	const SavePolicy & getSavePolicy() const;


	/************************************************************************
	**������
	*		���ô��̿ռ����
	**���룺
	*		pobjSpacePolicyList�����̿ռ�����б�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	**************************************************************************/
	void setSpacePolicyList(const vector<SpacePolicy>& p_objSpacePolicyList);


	/************************************************************************
	**������
	*		��ȡ���̿ռ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���̿ռ�����б�
	**���ܣ�
	*	
	**************************************************************************/
	vector<SpacePolicy> * getSpacePolicyList() const;

	/****************************************************************************
	**������
	*		��ֵ����
	*
	**���룺
	*		p_objRecordStorageParam��¼�ƴ洢����
	**�����
	*		��
	**����ֵ��
	*		��ֵ���¼�ƴ洢����
	**���ܣ�
	*		
	*****************************************************************************/
	RecordStorageParam & operator=(const RecordStorageParam &p_objRecordStorageParam);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objRecordStorageParam��RecordStorageParam���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����RecordStorageParam��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator==(const RecordStorageParam &p_objRecordStorageParam);

private:
	WritePolicy				m_objWritePolicy;			//����д����

	SavePolicy				m_objSavePolicy;			//�������

	vector<SpacePolicy>		m_objSpacePolicyVector;		//���̿ռ����
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_LOCALRECORDSTORAGEPARAM_H_
