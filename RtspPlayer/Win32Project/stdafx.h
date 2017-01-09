// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#define _CRT_SECURE_NO_WARNINGS
//#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <tchar.h>
#include <stdio.h>


#include <memory>
#include <condition_variable>
#include <thread>
#include <cassert>
#include <iostream>
#include <atomic>
#include <string>

#define D3D_DEBUG_INFO

#include <d3dx9.h>
#include <D3dx9tex.h>

#include <SDL.h>

#undef main

extern "C" {
#include <libswresample/swresample.h>
#pragma comment(lib, "swresample")
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

}

// TODO: reference additional headers your program requires here
//#include "NativePlayer.h"
// TODO: reference additional headers your program requires here
