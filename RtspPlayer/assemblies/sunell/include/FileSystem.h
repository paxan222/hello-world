#ifndef _FILE_SYSTEM_
#define _FILE_SYSTEM_

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

class SN_DLL_API FileSystem
{
public:
	FileSystem();

	//�������캯��
	FileSystem(const FileSystem &p_objFileSystem);
	
	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objFileSystem     ϵͳ����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	FileSystem &operator =(const FileSystem &p_objFileSystem);

	~FileSystem();

	const char*   getFileSystemName() const;
	void	setFileSystemName(const char* p_szFileSystemName);
	const int			getFileSystemType() const;
	void	setFileSystemType(int p_SystemType);
private:
	int					m_FileSystemType;
	char				m_szFileSystemName[CONST_MAXLENGTH_FILESYSTEM_NAME+1];
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_FILE_SYSTEM_

