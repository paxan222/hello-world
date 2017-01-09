#ifndef  _FILE_SYSTEM_ABILITY_
#define  _FILE_SYSTEM_ABILITY_
#include "FileSystem.h"
#include "DiskAttributeEx.h"
#include <vector>
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

class SN_DLL_API FileSystemAbility
{
public:
	FileSystemAbility();
	//�������캯��
	/************************************************************************
	**�����������豸ID
	*
	**���룺
	*		p_objFileSystemAbility
	**�����
	*		p_objFileSystemAbility
	**����ֵ��
	*		��
	**���ܣ�       
	*		���������ļ�ϵͳ����
	************************************************************************/
	FileSystemAbility(const FileSystemAbility &p_objFileSystemAbility);

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objFileSystemAbility
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	FileSystemAbility &operator =(const FileSystemAbility &p_objFileSystemAbility);
	~FileSystemAbility();
	const int  getDiskType() const;
	void	   setDiskType(const int p_DiskType);

	const std::vector<FileSystem>  getFileSystemList() const;
	void setFileSystemList(const std::vector<FileSystem> &p_FileSystemList);
	
	const std::vector<DiskAttributeEx>& getDiskAttributeList() const;
	void setDiskAttributeList(const std::vector<DiskAttributeEx> &p_DiskAttributeList);

private:
	int							m_DiskType;
	std::vector<FileSystem>		m_FileSystemList;
	std::vector<DiskAttributeEx>	m_DiskAttributeList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_FILE_SYSTEM_ABILITY_
