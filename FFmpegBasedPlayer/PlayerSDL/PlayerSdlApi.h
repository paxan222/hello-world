#pragma once

#ifdef PLAYER_EXPORTS
#define PLAYER_API __declspec(dllexport) 
#else
#define PLAYER_API __declspec(dllimport) 
#endif

#ifndef __cplusplus
#define __cplusplus
#endif

#ifdef __cplusplus
extern "C"
{
#endif
	PLAYER_API PVOID WINAPI StartPlayer(PCHAR filename, HWND hwnd);
	PLAYER_API BOOL WINAPI Play(PVOID player_pvoid);
	PLAYER_API BOOL WINAPI StopPlayer(PCHAR filename, HWND hwnd);
	PLAYER_API PVOID WINAPI OpenSdl(PCHAR filename, HWND hwnd);
	PLAYER_API BOOL WINAPI PlaySdl(PVOID player_pvoid);
	PLAYER_API BOOL WINAPI StopSdl(PVOID player_pvoid);

#ifdef __cplusplus
}
#endif