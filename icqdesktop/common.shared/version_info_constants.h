#ifndef __VERSION_INFO_CONSTANTS_H_
#define __VERSION_INFO_CONSTANTS_H_

#pragma once
#ifdef __linux__ //linux

#define VERSION_INFO_STR "10.0.3006"
#define VER_FILEVERSION 10,0,3006
#define VER_FILEVERSION_STR "10.0.3006"

#else

#ifdef __APPLE__ //mac

#define VERSION_INFO_STR "3.0.1234"
#define VER_FILEVERSION 3,0,1234
#define VER_FILEVERSION_STR "3.0.1234"

#else //windows

#define VERSION_INFO_STR "10.0.1999"
#define VER_FILEVERSION 10,0,1999
#define VER_FILEVERSION_STR "10.0.1999"

#endif //__APPLE__

#endif //__linux__

#endif // __VERSION_INFO_CONSTANTS_H_
