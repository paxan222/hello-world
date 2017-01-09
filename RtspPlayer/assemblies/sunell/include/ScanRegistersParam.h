#ifndef _SCANREGISTERSPARAM_H_
#define _SCANREGISTERSPARAM_H_

#include "ExternInterface.h"
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

class SN_DLL_API ScanRegistersParam
{
public:
	ScanRegistersParam();
	~ScanRegistersParam();

public:
	/************************************************************************
	**������
	*		�����Ƿ�����ɨ���Ƿ���
	**���룺
	*		p_bEnableFlag������ɨ���Ƿ����״̬
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setEnableFlag(const bool p_bEnableFlag);

	/************************************************************************
	**������
	*		��ȡɨ���Ƿ���״̬
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		
	**���ܣ�
	*		
	*************************************************************************/
	const bool getEnableFlag() const;

	/************************************************************************
	**������
	*		����/��ȡOSD��X����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		
	**���ܣ�
	*		
	*************************************************************************/
	void setOSDTopX(int p_nOSDTopX);
	int getOSDTopX() const;

	/************************************************************************
	**������
	*		����/��ȡOSD��Y����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		
	**���ܣ�
	*		
	*************************************************************************/
	void setOSDTopY(int p_nOSDTopY);
	int getOSDTopY() const;

	//������ʾ����
	void setDisplayNum(int p_nDisplayNum);
	int getDisplayNum() const;

	void setOSDCameraList(const std::vector<int> & p_objOSDCameraList);
	const std::vector<int> & getOSDCameraList() const;

	void setExternInterface(const ExternInterface & p_objExternInterface);
	const ExternInterface & getExternInterface() const;

private:
	bool m_bEnableFlag; //�Ƿ�����ɨ����(true��������false��������)
	int m_nOSDTopX;
	int m_nOSDTopY;
	int m_nDisplayNum;
	std::vector<int> m_objOSDCameraList;
	ExternInterface m_objExternInterface;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_SCANREGISTERSPARAM_H_



