#include "Player.h"

PLAYER_API PVOID WINAPI StartPlayer(PCHAR filename, HWND hwnd)
{
	CPlayerSdl *player = new CPlayerSdl(filename, hwnd);
	if (player->OpenStream())
		player->Play();
	else{
		delete player;
		return nullptr;
	}
	return player;
}

PLAYER_API BOOL WINAPI StopPlayer(PVOID player_pvoid)
{
	CPlayerSdl *player = static_cast<CPlayerSdl*>(player_pvoid);
	player->Stop();
	return TRUE;
}
