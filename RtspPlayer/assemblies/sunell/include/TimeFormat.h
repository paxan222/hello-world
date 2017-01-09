#ifndef _TIMEFORMAT_H_
#define _TIMEFORMAT_H_

#include <string>
namespace TimeFormat
{
	const std::string ERROR_FORMAT = ("ErrorFormat");
	const std::string TIME_FORMAT1 = ("YYYY-MM-DD hh:mm:ss");
	const std::string TIME_FORMAT2 = ("hh:mm:ss YYYY-MM-DD");
	const std::string TIME_FORMAT3 = ("MM/DD/YYYY hh:mm:ss");
	const std::string TIME_FORMAT4 = ("hh:mm:ss MM/DD/YYYY");
	const std::string TIME_FORMAT6 = ("weekday MM/DD/YYYY hh:mm:ss");

	/*enum FormatId
	{
		ErrorFomatId,
		FormatId1,
		FormatId2,
		FormatId3,
		FormatId4,
		FormatId5,
		FormatId6
	};

	std::string getFormatString(FormatId p_FormatId)
	{
		switch(p_FormatId)
		{
		case FormatId1:
			return TIME_FORMAT1;
		case FormatId2:
			return TIME_FORMAT2;
		case FormatId3:
			return TIME_FORMAT3;
		case FormatId4:
			return TIME_FORMAT4;
		case FormatId5:
			return TIME_FORMAT5;
		case FormatId6:
			return TIME_FORMAT6;
		default:
			return ERROR_FORMAT;
		}
	};

	FormatId getFormatString(const std::string &p_FormatString)
	{
		if(p_FormatString == TIME_FORMAT1)
			return FormatId1;
		if(p_FormatString == TIME_FORMAT2)
			return FormatId2;
		if(p_FormatString == TIME_FORMAT3)
			return FormatId3;
		if(p_FormatString == TIME_FORMAT4)
			return FormatId4;
		if(p_FormatString == TIME_FORMAT5)
			return FormatId5;
		if(p_FormatString == TIME_FORMAT6)
			return FormatId6;
		return ErrorFomatId;
	};*/
}
#endif //_TIMEFORMAT_H_


