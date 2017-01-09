#ifndef _CASHREGISTERSPARAM_H_
#define _CASHREGISTERSPARAM_H_

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

class SN_DLL_API CashRegistersParam
{
public:
	enum OSDLANGUAGE
	{
		CHINESE = 1,
		ENGLISH = 2
	};

public:
	CashRegistersParam();
	~CashRegistersParam();

public:
	/************************************************************************
	**������
	*		�����Ƿ����õ㳮������
	**���룺
	*		p_bEnableFlag�����õ㳮�������״̬
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
	*		��ȡ�Ƿ����õ㳮�������ʶ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�Ƿ����õ㳮�������ʶ
	**���ܣ�
	*		
	*************************************************************************/
	const bool getEnableFlag() const;

	void setOSDTopX(int p_nOSDTopX);
	int getOSDTopX() const;

	void setOSDTopY(int p_nOSDTopY);
	int getOSDTopY() const;

	void setOSDLanguage(int p_nOSDLanguage);
	int getOSDLanguage() const;

	void setModel(int p_nModel);
	int getModel() const;

	void setOSDCameraList(const std::vector<int> & p_objOSDCameraList);
	const std::vector<int> & getOSDCameraList() const;

	void setExternInterface(const ExternInterface & p_objExternInterface);
	const ExternInterface & getExternInterface() const;
private:
	bool m_bEnableFlag; //�Ƿ������㳮��(true��������false��������)
	int m_nOSDTopX;
	int m_nOSDTopY;
	int m_nOSDLanguage;
	int m_nModel;
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


#endif //_CashRegistersParam_H_
