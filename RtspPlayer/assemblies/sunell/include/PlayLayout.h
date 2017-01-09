#ifndef _PLAY_LAYOUT_H_
#define _PLAY_LAYOUT_H_

#include "DomainConst.h"
#include "LayoutWndInfo.h"

#include <vector>
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

class SN_DLL_API PlayLayout
{
public:
	PlayLayout(void);
	~PlayLayout(void);

	//�������캯��
	PlayLayout(const PlayLayout& p_objPlayLayout);

public:

	/************************************************************************
	**������
	*		���û�����Ŀ
	**���룺
	*		p_nPicNum ��������Ŀ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*    ���û�����Ŀ
	************************************************************************/
	void setPictureNum(const int p_nPicNum);

	/************************************************************************
	**������
	*		��ȡ������Ŀ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������Ŀ
	**���ܣ�
	*     ��ȡ������Ŀ
	**************************************************************************/
	const int getPictureNum() const ;

	/************************************************************************
	**������
	*		������ʾ��ID
	**���룺
	*		p_nScreenId ��������ʾ��ID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*    ������ʾ��ID
	************************************************************************/
	void setScreenId(const int p_nScreenId);

	/************************************************************************
	**������
	*		��ȡ��ʾ��ID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��ʾ��ID
	**���ܣ�
	*     ��ȡ��ʾ��ID
	**************************************************************************/
	const int getScreenId() const ;

	/************************************************************************
	**������
	*		���ò��ִ�����Ϣ�б�
	**���룺
	*		p_objLayoutWndInfoList �����ִ�����Ϣ�б�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*    
	************************************************************************/
	void setLayoutWndInfoList(const std::vector<LayoutWndInfo>& p_objLayoutWndInfoList);

	/************************************************************************
	**������
	*		��ȡ���ִ�����Ϣ�б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���ִ�����Ϣ�б�
	**���ܣ�
	*     
	**************************************************************************/
	const std::vector<LayoutWndInfo>& getLayoutWndInfoList() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objRecordBackupParam ��¼�񱸷ݲ�������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	**************************************************************************/
	PlayLayout& operator = (const PlayLayout& p_objPlayLayout);

private:

	int m_nPictureNum;

	int m_nScreenId;

	vector<LayoutWndInfo> m_objLayoutWndInfoList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_PLAY_LAYOUT_H_
