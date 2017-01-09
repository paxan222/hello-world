#ifndef _PTZTOURRX_H_
#define _PTZTOURRX_H_

#include "PTZTourPoint.h"
#include "DomainConst.h"
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

class SN_DLL_API PTZTourEx
{
public:
	PTZTourEx(void);
	~PTZTourEx(void);

	PTZTourEx(const PTZTourEx& p_objPTZTourEx);
	PTZTourEx& operator =(const PTZTourEx& p_objPTZTourEx);
public:
	void setTourID(const int p_nTourID);
	const int getTourID()const;

	bool setTourName(const char* p_pszTrackName);
	const char* getTourName() const;

	void setTourPointVec(const std::vector<PTZTourPoint>& p_objTourPointVec);
	void getTourPointVec(std::vector<PTZTourPoint>& p_objTourPointVec);

	void addTourPoint(const PTZTourPoint& p_objTourPoint);

private:
	int							m_nTourID;											//�켣���
	char						m_szTourName[CONST_MAXLENGTH_PTZ_TOUR_NAME + 1];	//��̨Ѳ�ε�����
	std::vector<PTZTourPoint>	m_objTourPointVec;									//��ɹ켣��Ԥ�õ㼯��
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif // _PTZTOURRX_H_


