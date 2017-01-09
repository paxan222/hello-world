#ifndef PT_SPEED_TABLE_H
#define PT_SPEED_TABLE_H

#include <vector>
#include "SNPlatOS.h"
#include "MagnifyPTSpeedParam.h"

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

class SN_DLL_API PTSpeedTable
{
public:
	PTSpeedTable();
	~PTSpeedTable();

	//�����ٶ�����
	void setSpeedType(const int p_nSpeedType);
	//��ȡ�ٶ�����
	const int getSpeedType() const;
	//���ñ���,PT�ٶȱ�
	void setMagnifyPTSpeedParamList(std::vector<MagnifyPTSpeedParam> p_objMagnifyPTSpeedParamList);
	//��ȡ����,PT�ٶȱ�
	const std::vector<MagnifyPTSpeedParam> &getMagnifyPTSpeedParamList() const;

	PTSpeedTable& operator =(const PTSpeedTable& p_objPTSpeedTable);

private:
	int m_nSpeedType;			//���Ƶ��ٶ�����,Ϊ0����Ĭ�ϵ��ٶ��㷨,��Ϊ0������Ӧ�Ķ����ٶȱ�
	std::vector<MagnifyPTSpeedParam> m_objMagnifyPTSpeedParamList;
};

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/

#endif