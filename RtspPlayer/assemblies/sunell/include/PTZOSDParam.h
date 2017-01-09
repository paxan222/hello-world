#ifndef _PTZOSDPARAM_H_
#define _PTZOSDPARAM_H_

#include "DomainConst.h"

#include <string.h>
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

class SN_DLL_API PTZOSDParam
{

public:

	enum OSDType
	{
		Version			= 1,   //�汾��Ϣ
		PTZStatus		= 2,  //PTZ����״̬
		KeeperStatus	= 3   //����λ
	};
	PTZOSDParam();
	~PTZOSDParam();

	PTZOSDParam(const PTZOSDParam& p_objPTZOSDParam);
	void setOSDType(const int p_nOSDType);
	const int getOSDType()const;
	void setShowTime(const int p_nShowTime);
	const int getShowTime()const;
	void setX(const int p_nX);
	const int getX()const;
	void setY(const int p_nY);
	const int getY()const;
public:
	PTZOSDParam& operator =(const PTZOSDParam& p_objPTZOSDParam);
	
	bool operator == (const PTZOSDParam& p_objPTZOSDParam) const;

private:
	int m_nOSDType;
	int m_nShowTime;
	int m_nX;
	int m_nY;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_PTZOSDPARAM_H_

