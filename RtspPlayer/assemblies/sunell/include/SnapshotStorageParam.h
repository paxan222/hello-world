#ifndef _SNAPSHOTSTORAGEPARAM_H_
#define _SNAPSHOTSTORAGEPARAM_H_

#include <string>
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

class SN_DLL_API SnapshotStorageParam
{
public:
	SnapshotStorageParam(void);
	~SnapshotStorageParam(void);

	enum ServerType
	{
		SERVERTYPE_FTP	= 1
	};

	/************************************************************************
	**������
	*		��÷�������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��������
	************************************************************************/
	const int getServerType() const;

	/************************************************************************
	**������
	*		���÷�������
	**���룺
	*		p_nServerType:  ��������
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setServerType(const int &p_nServerType);

	/************************************************************************
	**������
	*		��÷���·����ַ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����·����ַ
	************************************************************************/
	const std::string getServerAddress() const;

	/************************************************************************
	**������
	*		���÷���·����ַ
	**���룺
	*		p_ServerAddress ����·����ַ
	**�����
	*		��
	**����ֵ��
	*	    ��
	************************************************************************/
	void setServerAddress(const std::string &p_ServerAddress);

	SnapshotStorageParam& operator = (const SnapshotStorageParam &p_objSnapshotStorageParam);

private:
	int m_nServerType;				//����
	std::string  m_ServerAddress;      


}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif