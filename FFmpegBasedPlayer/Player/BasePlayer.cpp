#include "stdafx.h"
#include "BasePlayer.h"
#include <gdiplus.h>
#include <fstream>
#include <cmath>
#include <atlbase.h>

#ifdef _DEBUG
#include <iostream>
#include <string>
using namespace std;
#endif

#define MIN_PLAYBACK_SPEED_STEP -4
#define MAX_PLAYBACK_SPEED_STEP 4
#define IFC(x) { hr = (x); if (FAILED(hr)) goto Cleanup; }

void SaveBMP(BYTE* pDataBuf, DWORD dwDataBufSize, long nWidth, long nHeight, char *pFileName)
{
	DWORD dwBmpOutSize = dwDataBufSize + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	BYTE* pBmpBuf = new BYTE[dwBmpOutSize];
	BITMAPFILEHEADER bmpFileHeader;   //BMPОДјюН·
	BITMAPINFOHEADER bmpInfoHeader;   //BMPРЕПўН·

	//ЙиЦГBMPОДјюН·
	bmpFileHeader.bfType = 0x4D42; // ОДјюН·АаРН 'BM'(42 4D)
	bmpFileHeader.bfSize = sizeof(bmpFileHeader) + sizeof(bmpInfoHeader) + nWidth * nHeight * 3; //ОДјюґуРЎ
	bmpFileHeader.bfReserved1 = 0; //±ЈБфЧЦ
	bmpFileHeader.bfReserved2 = 0; //±ЈБфЧЦ
	bmpFileHeader.bfOffBits = 54;  //О»НјПсЛШКэѕЭµДЖрКјО»ЦГ

	//ЙиЦГBMPРЕПўН·
	bmpInfoHeader.biSize = 40;     //РЕПўН·ЛщХјЧЦЅЪКэ
	bmpInfoHeader.biWidth = nWidth;   //О»Нјїн¶И
	bmpInfoHeader.biHeight = nHeight;  //О»НјёЯ¶И
	bmpInfoHeader.biPlanes = 1;    //О»НјЖЅГжКэ
	bmpInfoHeader.biBitCount = 24;  //ПсЛШО»Кэ
	bmpInfoHeader.biCompression = 0;  //С№ЛхАаРНЈ¬0 јґІ»С№Лх
	bmpInfoHeader.biSizeImage = 0;    //
	bmpInfoHeader.biXPelsPerMeter = 0; //
	bmpInfoHeader.biYPelsPerMeter = 0; //
	bmpInfoHeader.biClrUsed = 0;      //
	bmpInfoHeader.biClrImportant = 0;  //

	//РґИлBMPОДјюН·
	memcpy(pBmpBuf, &bmpFileHeader, sizeof(BITMAPFILEHEADER));

	//РґИлBMPРЕПўН·
	memcpy(pBmpBuf + sizeof(BITMAPFILEHEADER), &bmpInfoHeader, sizeof(BITMAPINFOHEADER));

	//getchar();
	memcpy((pBmpBuf + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)), pDataBuf, dwDataBufSize);
	std::ofstream ofs(pFileName, std::ios::binary | std::ios::out);
	ofs.write((char *)pBmpBuf, dwBmpOutSize);

	ofs.close();

}

bool CBasePlayer::dirExists(const wstring dirName_in)
{
	DWORD ftyp = GetFileAttributes(dirName_in.c_str());
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path!

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!

	return false;    // this is not a directory!
}

double CBasePlayer::GetCurrentBitrate()
{
	clock_t curTime = clock();
	double elapsed = static_cast<double>(curTime - m_lLastTime) / 1000; // sec
	if (elapsed >= 2)
	{
		m_prev_bitrate = static_cast<double>(m_lInBytes) / elapsed / 1024 * 8;//Kbps
		m_lInBytes = 0;
		m_lLastTime = curTime;
	}
	return m_prev_bitrate;
}

BOOL CBasePlayer::SetStretchMode(BOOL originalSapectRatio)
{
	return FALSE;
}

HRESULT CBasePlayer::GetGdiplusEncoderClsid(__in LPCWSTR pwszFormat, __out GUID *pGUID)
{
	HRESULT hr = E_FAIL;
	UINT  nEncoders = 0;          // number of image encoders
	UINT  nSize = 0;              // size of the image encoder array in bytes
	CAutoVectorPtr<BYTE> spData;
	Gdiplus::ImageCodecInfo* pImageCodecInfo = NULL;
	Gdiplus::Status status;
	bool fFound = false;

	// param check

	if ((pwszFormat == NULL) || (pwszFormat[0] == 0) || (pGUID == NULL))
	{
		return E_POINTER;
	}

	*pGUID = GUID_NULL;
	status = Gdiplus::GetImageEncodersSize(&nEncoders, &nSize);

	if ((status != Gdiplus::Ok) || (nSize == 0))
	{
		return E_FAIL;
	}

	spData.Allocate(nSize);

	if (spData == NULL)
	{
		return E_FAIL;
	}

	pImageCodecInfo = (Gdiplus::ImageCodecInfo*)(BYTE*)spData;

	status = Gdiplus::GetImageEncoders(nEncoders, nSize, pImageCodecInfo);

	if (status != Gdiplus::Ok)
	{
		return E_FAIL;
	}

	for (UINT j = 0; j < nEncoders; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, pwszFormat) == 0)
		{
			*pGUID = pImageCodecInfo[j].Clsid;
			fFound = true;
			break;
		}
	}

	hr = fFound ? S_OK : E_FAIL;

	return hr;
}

CBasePlayer::CBasePlayer(PCHAR pchFileName, FDecodeCallback fDecodeCallback, FFileEndCallback fFileEndCallback, FEndInitCallback fEndInitCallback, HWND hMainWindow)
{
	if (pchFileName != NULL)
	{
		m_strFileName = std::string(pchFileName);
	}
	b = 0;
	m_endInitCallback = fEndInitCallback;
	m_fDecodeCallback = fDecodeCallback;
	m_fFileEndCallback = fFileEndCallback;
	m_hMainWindow = hMainWindow;
	m_dwDecodedWidth = 0;
	m_dwDecodedHeight = 0;
	m_dwFrameCount = 0;
	m_StreamInfo = { 0 };
	m_saveSnapShoot = false;
	m_nInternalPlaybackSpeed = 0;
	m_lLastTime = 0;
	m_prev_bitrate = 0;
}

CBasePlayer::~CBasePlayer(void)
{
	/*
	if (g_pVB != NULL)
		g_pVB->Release();

	if (g_pd3dDevice != NULL)
		g_pd3dDevice->Release();

	if (g_pd3dDeviceEx != NULL)
		g_pd3dDeviceEx->Release();

	if (g_pD3D != NULL)
		g_pD3D->Release();

	if (g_pD3DEx != NULL)
		g_pD3DEx->Release();

	if (g_pd3dFullSizeSurface != NULL)
		g_pd3dFullSizeSurface->Release();


	if (g_pd3dRenderTargetSurface != NULL)
		g_pd3dRenderTargetSurface->Release();*/

	//m_strFileName = NULL;
	m_fDecodeCallback = NULL;
	m_fFileEndCallback = NULL;
	m_hMainWindow = NULL;

}

BOOL CBasePlayer::SetPlaybackPosition(DWORD dwMilliseconds)
{
	return TRUE;
}

DWORD CBasePlayer::GetPlaybackPosition()
{
	return 100;
}

DWORD CBasePlayer::GetAdjustedPlaybackPosition()
{
	return 0;
}

void CBasePlayer::SendInit(LONG nPort, LONG nWidth, LONG nHeight) {}

//void CBasePlayer::Convert_YUV_To_RGB24(BYTE *YBuf, BYTE *UBuf, BYTE *VBuf, LONG nWidth, LONG nHeight, DWORD dwTimeStampMilliseconds)
//{
//	int w = m_dwDecodedWidth;
//	int h = m_dwDecodedHeight;
//
//	if (w < 1)
//	{
//		w = nWidth;
//	}
//	if (h < 1)
//	{
//		h = nHeight;
//	}
//
//	//int srcW16 = nWidth + (16 - nWidth % 16); // выравнивание ширины входного изображения на 16 байт
//	int dstW16 = w + (16 - w % 16); // выравнивание ширины выходного изображения на 16 байт
//
//
//	SwsContext* sws_ctx = sws_getContext(nWidth, nHeight, AV_PIX_FMT_YUV420P, dstW16, h, AV_PIX_FMT_RGB24, SWS_FAST_BILINEAR, NULL, NULL, NULL);
//
//	if (sws_ctx == NULL) return;
//
//	AVPicture srcPic;
//	avpicture_alloc(&srcPic, AV_PIX_FMT_YUV420P, nWidth, nHeight);
//
//	AVPicture dstPic;
//	avpicture_alloc(&dstPic, AV_PIX_FMT_RGB24, dstW16, h);
//
//	// устанавливаем указатели на YUV плоскости кадра, декодированного dahua
//	memcpy(srcPic.data[0], YBuf, nWidth*nHeight);
//	memcpy(srcPic.data[1], UBuf, nWidth*nHeight / 4);
//	memcpy(srcPic.data[2], VBuf, nWidth*nHeight / 4);
//
//	// снимок
//	if (m_saveSnapShoot == true)
//	{
//		Gdiplus::GdiplusStartupInput gdiplusStartupInput;
//		Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
//		AVPixelFormat outPixFmt = AV_PIX_FMT_RGB32;
//		Gdiplus::PixelFormat gdioutPixFmt = PixelFormat32bppRGB;
//
//		SwsContext* sws_save_ctx = sws_getContext(nWidth, nHeight, AV_PIX_FMT_YUV420P, nWidth, nHeight, outPixFmt, SWS_FAST_BILINEAR, NULL, NULL, NULL);
//		if (sws_ctx == NULL) return;
//		AVPicture saveDstPic;
//		avpicture_alloc(&saveDstPic, outPixFmt, nWidth, nHeight);
//		sws_scale(sws_save_ctx, srcPic.data, srcPic.linesize, 0, nHeight, saveDstPic.data, saveDstPic.linesize);
//
//		m_SnapshootName.append(L".png");
//
//		Gdiplus::Bitmap* bmp = new Gdiplus::Bitmap((INT)nWidth, (INT)nHeight, saveDstPic.linesize[0], gdioutPixFmt, (BYTE*)saveDstPic.data[0]);
//
//		CLSID pngClsid;
//		int res = GetGdiplusEncoderClsid(L"image/png", &pngClsid);
//
//		bool exist = dirExists(m_SnapshootPath);
//		if (res != -1)
//		{
//			wstring fullPath = m_SnapshootPath + L"\\" + m_SnapshootName;
//			bmp->Save(fullPath.c_str(), &pngClsid, NULL);
//		}
//		delete bmp;
//		avpicture_free(&saveDstPic);
//		sws_freeContext(sws_save_ctx);
//		m_saveSnapShoot = false;
//		Gdiplus::GdiplusShutdown(gdiplusToken);
//		gdiplusToken = NULL;
//	}
//
//	// масштабирование изображения
//	sws_scale(sws_ctx, srcPic.data, srcPic.linesize, 0, nHeight, dstPic.data, dstPic.linesize);
//	OnDecodeCallback(dstPic.data[0], dstPic.linesize[0] * h, dstPic.linesize[0], dstW16, h, dwTimeStampMilliseconds);
//	sws_freeContext(sws_ctx);
//	avpicture_free(&srcPic);
//	avpicture_free(&dstPic);
//}

void CBasePlayer::OnDecodeCallback(BYTE* pRgbBuf, DWORD dwRgbBufSize, DWORD dwStride, DWORD width, DWORD height, DWORD dwTimeStampMilliseconds)
{
#ifdef _DEBUG
	//	SaveBMP(pRgbBuf, dwRgbBufSize, width, height, 
	//		(char *)("D:\\Temp\\Frames\\frame_" + std::to_string(++m_dwFrameCount) + ".bmp").c_str());
	//cout << "\tTS = " << dwTimeStampMilliseconds << endl;
#endif

	RECT srcRect;
	srcRect.left = 0;
	srcRect.top = 0;
	srcRect.right = width;
	srcRect.bottom = height;

	//if (g_pd3dFullSizeSurface != NULL)
	//	g_pd3dFullSizeSurface->Release();
	/*g_pd3dDevice->CreateOffscreenPlainSurface(width, height, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &g_pd3dFullSizeSurface, NULL);*/
	//if (SUCCEEDED(g_pd3dDevice->BeginScene()))
	//{
	//b += 2;
	//HRESULT res = g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(255, 0, b, 221), 1.0f, 0);
	//res = D3DXLoadSurfaceFromMemory(g_pd3dRenderTargetSurface, NULL, NULL, pRgbBuf, D3DFMT_R8G8B8, dwStride, NULL, &srcRect, D3DX_FILTER_NONE, 0xFF000000);
	/*D3DLOCKED_RECT* lockRect = new D3DLOCKED_RECT();
	RECT rect;
	D3DSURFACE_DESC desc;
	g_pd3dRenderTargetSurface->GetDesc(&desc);
	rect.left = 0;
	rect.top = 0;
	rect.right = 100;
	rect.bottom = 100;
	g_pd3dRenderTargetSurface->LockRect(lockRect, &rect, D3DLOCK_DISCARD);
	memset(lockRect->pBits, 100, (lockRect->Pitch) * 100);
	g_pd3dRenderTargetSurface->UnlockRect();*/

	/*if (FAILED(res))
	{
	auto err = GetLastError();
	}*/
	//g_pd3dDevice->EndScene();
	//}
	
	m_fDecodeCallback(pRgbBuf, dwRgbBufSize, dwStride, width, height, dwTimeStampMilliseconds);
}

DWORD CBasePlayer::CorrectFrameTimeStamp(DWORD dwTimeStampMilliseconds)
{
#ifdef _DEBUG
	//cout << "this = " << this << "TS = " << dwTimeStampMilliseconds << endl;
#endif
	return dwTimeStampMilliseconds;
}

//Попробовать ускорить воспроизведение и получить значение коэффициента воспроизведения
BOOL CBasePlayer::GetIncrementedPlaybackSpeedValue(float *pfPlaySpeed)
{
	if (m_nInternalPlaybackSpeed >= MAX_PLAYBACK_SPEED_STEP)
	{
		m_nInternalPlaybackSpeed = MAX_PLAYBACK_SPEED_STEP;
	}
	else
	{
		if (pfPlaySpeed != NULL)
		{
			++m_nInternalPlaybackSpeed;
			*pfPlaySpeed = pow(static_cast<float>(2), static_cast<float>(m_nInternalPlaybackSpeed));
			return TRUE;
		}
	}
	return FALSE;
}

//Попробовать замедлить воспроизведение и получить значение коэффициента воспроизведения
BOOL CBasePlayer::GetDecrementedPlaybackSpeedValue(float *pfPlaySpeed)
{
	if (m_nInternalPlaybackSpeed <= MIN_PLAYBACK_SPEED_STEP)
	{
		m_nInternalPlaybackSpeed = MIN_PLAYBACK_SPEED_STEP;
	}
	else
	{
		if (pfPlaySpeed != NULL)
		{
			--m_nInternalPlaybackSpeed;
			*pfPlaySpeed = pow(static_cast<float>(2), static_cast<float>(m_nInternalPlaybackSpeed));
			return TRUE;
		}
	}
	return FALSE;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	return 0;
}

BOOL CBasePlayer::Refresh(){ return TRUE; };

HWND CBasePlayer::CreateWnd(LPCWSTR szAppName)
{
	BOOL hr = TRUE;
	HWND hWnd = NULL;

	WNDCLASS wndclass;

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = NULL;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	if (!RegisterClass(&wndclass))
	{
		IFC(E_FAIL);
	}



	/*hWnd = CreateWindow(szAppName,
		szAppName,
		WS_OVERLAPPEDWINDOW | WS_EX_NOPARENTNOTIFY | WS_CHILD,
		0,                   // Initial X
		0,                   // Initial Y
		200,                   // Width
		200,                   // Height
		m_hMainWindow,
		NULL,
		NULL,
		NULL);*/

	hWnd = CreateWindowEx(WS_EX_NOPARENTNOTIFY, szAppName, szAppName, WS_OVERLAPPEDWINDOW | WS_CHILD, 0, 0, 200, 200, m_hMainWindow, NULL, NULL, NULL);

	ShowWindow(hWnd, SW_NORMAL);
	//ShowWindow(hWnd, SW_SHOW);
	return hWnd;
Cleanup:
	return NULL;
}

BOOL CBasePlayer::DestroyWnd(HWND hWnd)
{
	return DestroyWindow(hWnd);

	//SendMessage(hWnd, WM_QUIT, 0, 0);
	SendMessage(hWnd, WM_CLOSE, 0, 0);
	Sleep(200);
	//FindWindowEx(HWND_MESSAGE, )
	return TRUE;
}

BOOL CBasePlayer::SeekPositionByTime(DWORD dwMilliseconds, DWORD* pdwBytesOffset)
{
	return FALSE;
}