#include "Player.h"
#include "SdlPlayer.h"

PLAYER_API PVOID WINAPI StartPlayer(PCHAR filename, HWND hwnd)
{
	CPlayerSdl *player = new CPlayerSdl(filename, hwnd);
	if (!player->OpenStream()){
		delete player;
		return nullptr;
	}
	return player;
}

PLAYER_API BOOL WINAPI Play(PVOID player_pvoid)
{
	CPlayerSdl *player = static_cast<CPlayerSdl*>(player_pvoid);
	player->Play();
	return TRUE;
}

PLAYER_API BOOL WINAPI StopPlayer(PVOID player_pvoid)
{
	CPlayerSdl *player = static_cast<CPlayerSdl*>(player_pvoid);
	player->Stop();
	return TRUE;
}

PLAYER_API PVOID WINAPI OpenSdl(PCHAR filename, HWND hwnd)
{
	SdlPlayer *player = new SdlPlayer(filename, hwnd);
	if (!player->Open()){
		delete player;
		return nullptr;
	}
	return player;
}

PLAYER_API BOOL WINAPI PlaySdl(PVOID player_pvoid)
{
	SdlPlayer *player = static_cast<SdlPlayer*>(player_pvoid);
	player->Play();
	return TRUE;
}

PLAYER_API BOOL WINAPI StopSdl(PVOID player_pvoid)
{
	SdlPlayer *player = static_cast<SdlPlayer*>(player_pvoid);
	player->Stop();
	return TRUE;
}
