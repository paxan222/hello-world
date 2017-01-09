#ifndef _TIMEZONEPARAM_H_
#define _TIMEZONEPARAM_H_

#include "DomainConst.h"
#include "SNPlatOS.h"

#ifndef byte
typedef unsigned char byte;
#endif

/**********************************************************************/
//此处用于控制文件编译字节对齐，拷贝时两行注释间内容需一起拷贝，
//结束处的“#ifdef PRAGMA_PACK”部分也要一起拷贝，否则pragma pack入栈出栈不匹配
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

class SN_DLL_API TimeZoneParam
{
public:
	TimeZoneParam(void);
	~TimeZoneParam(void);

	TimeZoneParam(const TimeZoneParam& p_objTimeZoneParam);

public:

	/************************************************************************
	**概述：
	*		设置时区
	**输入：
	*		p_nTimeZone ：时区ID，具体ID值请查看文件末尾的对应表
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setTimeZone(const int p_nTimeZone);

	/************************************************************************
	**概述：
	*		获取时区
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		时区
	**功能：       
	*		
	************************************************************************/
	const int getTimeZone() const;


	/************************************************************************
	**概述：
	*		设置是否启用夏令时标志
	**输入：
	*		p_bDSTOpenFlag ：启用夏令时标志
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setDSTOpenFlag(const bool p_bDSTOpenFlag);

	/************************************************************************
	**概述：
	*		获取启用夏令时标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		启用夏令时标志
	**功能：       
	*		
	************************************************************************/
	const bool getDSTOpenFlag() const;


	/************************************************************************
	**概述：
	*		设置夏令时偏移（此接口预留，暂不支持）
	**输入：
	*		p_nDSTOffset ：夏令时偏移
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setDSTOffset(const int p_nDSTOffset);

	/************************************************************************
	**概述：
	*		获取夏令时偏移（此接口预留，暂不支持）
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		夏令时偏移
	**功能：       
	*		
	************************************************************************/
	const int getDSTOffset() const;


	/************************************************************************
	**概述：
	*		设置夏令时开始月份
	**输入：
	*		p_nBeginMonth ：夏令时开始月份
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setBeginMonth(const int p_nBeginMonth);

	/************************************************************************
	**概述：
	*		获取夏令时开始月份
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		夏令时开始月份
	**功能：       
	*		
	************************************************************************/
	const int getBeginMonth() const;


	/************************************************************************
	**概述：
	*		设置夏令时开始周
	**输入：
	*		p_nBeginWeekly ：夏令时开始周（一月中的第几周，5为最后一周）
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setBeginWeekly(const int p_nBeginWeekly);

	/************************************************************************
	**概述：
	*		获取夏令时开始周
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		夏令时开始周（一月中的第几周，5为最后一周）
	**功能：       
	*		
	************************************************************************/
	const int getBeginWeekly() const;


	/************************************************************************
	**概述：
	*		设置夏令时开始星期几
	**输入：
	*		p_nBeginWeekDays ：夏令时开始星期几（0-6,0为周日）
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setBeginWeekDays(const int p_nBeginWeekDays);

	/************************************************************************
	**概述：
	*		获取夏令时开始星期几
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		夏令时开始星期几（0-6,0为周日）
	**功能：       
	*		
	************************************************************************/
	const int getBeginWeekDays() const;


	/************************************************************************
	**概述：
	*		设置夏令时开始时间
	**输入：
	*		p_nBeginTime ：夏令时开始时间，从00:00开始到当前时间的分钟数，如10:30为630,单位：分(m)
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setBeginTime(const unsigned int p_nBeginTime);

	/************************************************************************
	**概述：
	*		获取夏令时开始时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		夏令时开始时间，从00:00开始到当前时间的分钟数，如10:30为630,单位：分(m)
	**功能：       
	*		
	************************************************************************/
	const unsigned int getBeginTime() const;


	/************************************************************************
	**概述：
	*		设置夏令时结束月
	**输入：
	*		p_nEndMonth ：夏令时结束月
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setEndMonth(const int p_nEndMonth);

	/************************************************************************
	**概述：
	*		获取夏令时结束月
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		夏令时结束月
	**功能：       
	*		
	************************************************************************/
	const int getEndMonth() const;


	/************************************************************************
	**概述：
	*		设置夏令时结束周
	**输入：
	*		p_nEndWeekly ：夏令时结束周（一月中的第几周，5为最后一周）
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setEndWeekly(const int p_nEndWeekly);

	/************************************************************************
	**概述：
	*		获取夏令时结束周
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		夏令时结束周（一月中的第几周，5为最后一周）
	**功能：       
	*		
	************************************************************************/
	const int getEndWeekly() const;


	/************************************************************************
	**概述：
	*		设置夏令时结束星期几
	**输入：
	*		p_nEndWeekDays ：夏令时结束星期几（0-6,0为周日）
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setEndWeekDays(const int p_nEndWeekDays);

	/************************************************************************
	**概述：
	*		获取夏令时结束星期几
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		夏令时结束星期几（0-6,0为周日）
	**功能：       
	*		
	************************************************************************/
	const int getEndWeekDays() const;


	/************************************************************************
	**概述：
	*		设置夏令时结束时间
	**输入：
	*		p_nEndTime：夏令时结束时间，从00:00开始到当前时间的分钟数，如10:30为630,单位：分(m)
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setEndTime(const unsigned int p_nEndTime);

	/************************************************************************
	**概述：
	*		获取夏令时结束时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		夏令时结束时间，从00:00开始到当前时间的分钟数，如10:30为630,单位：分(m)
	**功能：       
	*		
	************************************************************************/
	const unsigned int getEndTime() const;


	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objTimeZoneParam：设备主机网络信息
	**输出：
	*		无
	**返回值：
	*		设备主机网络信息
	**功能：
	************************************************************************/
	TimeZoneParam& operator =(const TimeZoneParam& p_objTimeZoneParam);

	static float getTimeZoneOffset(const int p_nTimeZoneID);

private:
	
	int				m_nTimeZone;												//时区

	bool			m_bDSTOpenFlag;												//夏令时开启标志

	int				m_nDSTOffset;												//夏令时偏移，以秒为单位

	int				m_nBeginMonth;												//夏令时开始月份
	int				m_nBeginWeekly;												//夏令时开始周（一月中的第几周，5为最后一周）
	int				m_nBeginWeekDays;											//星期几(0-6),0为周日
	unsigned int	m_nBeginTime;												//开始时间，从00:00开始到当前时间的分钟数，如01:30为90,单位：分(m)
	
	int				m_nEndMonth;												//夏令时结束月份
	int				m_nEndWeekly;												//夏令时结束周（一月中的第几周，5为最后一周）
	int				m_nEndWeekDays;												//星期几(0-6),0为周日
	unsigned int	m_nEndTime;													//结束时间，从00:00开始到当前时间的分钟数，如10:30为630,单位：分(m)

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_TIMEZONEPARAM_H_

/* setTimeZone()中入参对应表,TimeZoneId=""为具体的p_nTimeZone值

<ConfigItem TimeZoneId="0" name="(GMT-12:00)国际日期变更线西"/>
<ConfigItem TimeZoneId="1" name="(GMT-11:00) 中途岛，萨摩亚群岛"/>
<ConfigItem TimeZoneId="2" name="(GMT-10:00) 夏威夷"/>
<ConfigItem TimeZoneId="3" name="(GMT-09:00) 阿拉斯加"/>
<ConfigItem TimeZoneId="4" name="(GMT-08:00) 太平洋时间(美国和加拿大)"/>
<ConfigItem TimeZoneId="5" name="(GMT-08:00) 下加利福尼亚州"/>
<ConfigItem TimeZoneId="10" name="(GMT-07:00) 山地时间(美国和加拿大)"/>
<ConfigItem TimeZoneId="13" name="(GMT-07:00)奇瓦瓦，拉巴斯，马扎特兰"/>
<ConfigItem TimeZoneId="15" name="(GMT-07:00) 亚利桑那"/>
<ConfigItem TimeZoneId="20" name="(GMT-06:00) 中部时间(美国和加拿大)"/>
<ConfigItem TimeZoneId="25" name="(GMT-06:00) 萨斯喀彻温"/>
<ConfigItem TimeZoneId="30" name="(GMT-06:00)瓜达拉哈拉，墨西哥城，蒙特雷"/>
<ConfigItem TimeZoneId="33" name="(GMT-06:00) 中美洲"/>
<ConfigItem TimeZoneId="35" name="(GMT-05:00) 东部时间(美国和加拿大)"/>
<ConfigItem TimeZoneId="40" name="(GMT-05:00) 印地安那州(东部)"/>
<ConfigItem TimeZoneId="45" name="(GMT-05:00) 波哥大，利马，基多"/>
<ConfigItem TimeZoneId="50" name="(GMT-04:00) 大西洋时间(加拿大)"/>
<ConfigItem TimeZoneId="55" name="(GMT-04:30) 加拉加斯"/>
<ConfigItem TimeZoneId="56" name="(GMT-04:00) 圣地亚哥"/>
<ConfigItem TimeZoneId="60" name="(GMT-03:30) 纽芬兰"/>
<ConfigItem TimeZoneId="65" name="(GMT-03:00) 巴西利亚"/>
<ConfigItem TimeZoneId="70" name="(GMT-03:00) 布宜诺斯艾利斯"/>
<ConfigItem TimeZoneId="73" name="(GMT-03:00) 格陵兰"/>
<ConfigItem TimeZoneId="75" name="(GMT-02:00) 中大西洋"/>
<ConfigItem TimeZoneId="80" name="(GMT-01:00) 亚速尔群岛"/>
<ConfigItem TimeZoneId="83" name="(GMT-01:00) 佛得角群岛"/>
<ConfigItem TimeZoneId="85" name="(GMT) 格林威治标准时间: 都柏林, 爱丁堡, 伦敦, 里斯本"/>
<ConfigItem TimeZoneId="90" name="(GMT) 卡萨布兰卡，蒙罗维亚"/>
<ConfigItem TimeZoneId="95" name="(GMT+01:00) 贝尔格莱德，布拉迪斯拉发，布达佩斯，卢布尔雅那，布拉格"/>
<ConfigItem TimeZoneId="100" name="(GMT+01:00) 萨拉热窝，斯科普里，华沙，萨格勒布"/>
<ConfigItem TimeZoneId="105" name="(GMT+01:00) 布鲁塞尔，哥本哈根，马德里，巴黎"/>
<ConfigItem TimeZoneId="110" name="(GMT+01:00) 阿姆斯特丹，柏林，伯尔尼，罗马，斯德哥尔摩，维也纳"/>
<ConfigItem TimeZoneId="113" name="(GMT+01:00) 中非西部"/>
<ConfigItem TimeZoneId="115" name="(GMT+02:00) 布加勒斯特"/>
<ConfigItem TimeZoneId="120" name="(GMT+02:00) 开罗"/>
<ConfigItem TimeZoneId="125" name="(GMT+02:00) 赫尔辛基，基辅，里加，索非亚，塔林，维尔纽斯"/>
<ConfigItem TimeZoneId="130" name="(GMT+02:00) 雅典，贝鲁特，伊斯坦布尔，明斯克"/>
<ConfigItem TimeZoneId="135" name="(GMT+02:00) 耶路撒冷"/>
<ConfigItem TimeZoneId="140" name="(GMT+02:00) 哈拉雷，比勒陀利亚"/>
<ConfigItem TimeZoneId="145" name="(GMT+04:00) 莫斯科，圣彼得堡, 伏尔加格勒"/>
<ConfigItem TimeZoneId="150" name="(GMT+03:00) 科威特，利雅得"/>
<ConfigItem TimeZoneId="155" name="(GMT+03:00) 内罗毕"/>
<ConfigItem TimeZoneId="158" name="(GMT+03:00) 巴格达"/>
<ConfigItem TimeZoneId="160" name="(GMT+03:30) 德黑兰"/>
<ConfigItem TimeZoneId="165" name="(GMT+04:00) 阿布扎比，马斯喀特"/>
<ConfigItem TimeZoneId="170" name="(GMT+04:00) 巴库，第比利斯，埃里温"/>
<ConfigItem TimeZoneId="175" name="(GMT+04:30) 喀布尔"/>
<ConfigItem TimeZoneId="180" name="(GMT+06:00) 叶卡捷琳堡"/>
<ConfigItem TimeZoneId="185" name="(GMT+05:00) 伊斯兰堡，卡拉奇，塔什干"/>
<ConfigItem TimeZoneId="190" name="(GMT+05:30) 钦奈，加尔各答，孟买，新德里"/>
<ConfigItem TimeZoneId="193" name="(GMT+05:45) 加德满都"/>
<ConfigItem TimeZoneId="195" name="(GMT+06:00) 阿斯塔纳，达卡"/>
<ConfigItem TimeZoneId="200" name="(GMT+05:30) 斯里加亚渥登普拉"/>
<ConfigItem TimeZoneId="201" name="(GMT+08:00) 新西伯利亚"/>
<ConfigItem TimeZoneId="203" name="(GMT+06:30) 仰光"/>
<ConfigItem TimeZoneId="205" name="(GMT+07:00) 曼谷，河内，雅加达"/>
<ConfigItem TimeZoneId="207" name="(GMT+07:00) 克拉斯诺亚尔斯克"/>
<ConfigItem TimeZoneId="210" name="(GMT+08:00) 北京，重庆，香港特别行政区，乌鲁木齐"/>
<ConfigItem TimeZoneId="215" name="(GMT+08:00) 吉隆坡，新加坡"/>
<ConfigItem TimeZoneId="220" name="(GMT+08:00) 台北"/>
<ConfigItem TimeZoneId="225" name="(GMT+08:00) 珀斯"/>
<ConfigItem TimeZoneId="227" name="(GMT+09:00) 伊尔库茨克"/>
<ConfigItem TimeZoneId="230" name="(GMT+09:00) 汉城"/>
<ConfigItem TimeZoneId="235" name="(GMT+09:00) 大坂，札幌，东京"/>
<ConfigItem TimeZoneId="240" name="(GMT+09:00) 雅库茨克"/>
<ConfigItem TimeZoneId="245" name="(GMT+09:30) 达尔文"/>
<ConfigItem TimeZoneId="250" name="(GMT+09:30) 阿德莱德"/>
<ConfigItem TimeZoneId="255" name="(GMT+10:00) 堪培拉，墨尔本，悉尼"/>
<ConfigItem TimeZoneId="260" name="(GMT+10:00) 布里斯班"/>
<ConfigItem TimeZoneId="265" name="(GMT+10:00) 霍巴特"/>
<ConfigItem TimeZoneId="270" name="(GMT+11:00) 符拉迪沃斯托克"/>
<ConfigItem TimeZoneId="275" name="(GMT+10:00) 关岛，莫尔兹比港"/>
<ConfigItem TimeZoneId="280" name="(GMT+11:00) 所罗门群岛，新喀里多尼亚"/>
<ConfigItem TimeZoneId="285" name="(GMT+12:00) 斐济，堪察加半岛，马绍尔群岛"/>
<ConfigItem TimeZoneId="290" name="(GMT+12:00) 奥克兰，惠灵顿"/>
<ConfigItem TimeZoneId="300" name="(GMT+13:00) 努库阿洛法"/>
*/
