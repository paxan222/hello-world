// Win32Project.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Win32Project.h"
#include <gdiplus.h>
#pragma comment(lib,"gdiplus.lib")
#include "Record.h"
#include "Export.h"
#include <windows.h>
#include <psapi.h>
#include <stdio.h> 


class MemLog{

	FILE* m_pFile;
	FILE* m_pFile2;
	HANDLE hProcess;

public:
	MemLog(string _path, DWORD processID){
		string tmp = _path + "workingsetsize.txt";
		char * path = new char[tmp.size() + 1];
		std::copy(tmp.begin(), tmp.end(), path);
		path[tmp.size()] = '\0';

		m_pFile = fopen(path, "w");
		delete path;

		tmp = _path + "peakworkingsetsize.txt";
		path = new char[tmp.size() + 1];
		std::copy(tmp.begin(), tmp.end(), path);
		path[tmp.size()] = '\0';

		m_pFile2 = fopen(path, "w");
		delete path;
		hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
			PROCESS_VM_READ,
			FALSE, processID);
		if (NULL == hProcess)
			return;
		DWORD exitCode = 0;
		GetExitCodeProcess(hProcess, &exitCode);
		while (exitCode == STILL_ACTIVE){
			PrintMemoryInfo(hProcess);
			Sleep(1000 * 10);
		}
	}
	~MemLog(){
		fclose(m_pFile);
		CloseHandle(hProcess);
	}
	void PrintMemoryInfo(HANDLE _process)
	{
		PROCESS_MEMORY_COUNTERS pmc;

		if (GetProcessMemoryInfo(_process, &pmc, sizeof(pmc)))
		{
			//fprintf(m_pFile, "PageFaultCount: %d\n", pmc.PageFaultCount);
			fprintf(m_pFile2, "%d\n", pmc.PeakWorkingSetSize);
			fprintf(m_pFile, "%d\n", pmc.WorkingSetSize);
			/*fprintf(m_pFile, "QuotaPeakPagedPoolUsage: %d\n", pmc.QuotaPeakPagedPoolUsage);
			fprintf(m_pFile, "QuotaPagedPoolUsage: %d\n", pmc.QuotaPagedPoolUsage);
			fprintf(m_pFile, "QuotaPeakNonPagedPoolUsage: %d\n", pmc.QuotaPeakNonPagedPoolUsage);
			fprintf(m_pFile, "QuotaNonPagedPoolUsage: %d\n", pmc.QuotaNonPagedPoolUsage);
			fprintf(m_pFile, "PagefileUsage: %d\n", pmc.PagefileUsage);
			fprintf(m_pFile, "PeakPagefileUsage: %d\n", pmc.PeakPagefileUsage);*/
		}

	}
};

DWORD processID;
#include <direct.h>
#define GetCurrentDir _getcwd
//#include "vld.h"

#define MAX_LOADSTRING 100
// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
HWND hWnd;
// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProcMain(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

string				filenameInput{ NULL };
string				filenameInput2{ NULL };
string				filenameOutput{ NULL };
char				*pathInput;
char				*pathInput2;
char				*pathOutput;

CRecord		*recorder;
CExport		*exporter;
bool				switchsound;

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);


	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WIN32PROJECT, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	processID = GetCurrentProcessId();

	/*std::thread([] {
		MemLog* memLog = new MemLog("D:\\", processID);
	}).detach();*/

	filenameInput = "D:\\TestVideo\\test2.mkv";
	filenameInput2 = "D:\\TestVideo\\test1.mkv";
	/*filenameInput = "D:\\TestVideo\\test2.h264";
	filenameInput2 = "D:\\TestVideo\\test1.h264";*/
	//filenameInput = "rtsp://localhost:8554/test";
	//filenameInput = "rtsp://admin:admin@192.168.11.231:554/RVi/1/1";
	//filenameInput = "rtsp://admin:admin@192.168.11.183:554/cam/realmonitor?channel=1&subtype=0";
	//filenameInput = "rtsp://55555:55555@192.168.11.197:554/cam/realmonitor?channel=1&subtype=0";
	//filenameInput = "rtsp://admin:1q2w3e4r5t6y@192.168.11.108:554/Streaming/Channels/101?transportmode=unicast&profile=Profile_1";
	//filenameInput = "D:\\TestVideo\\big_buck_bunny_480p_h264.mov";
	//filenameInput = "D:\\TestVideo\\FromRtsp.mov";

	//filenameInput = "rtsp://55555:55555@192.168.11.178:554/cam/realmonitor?channel=1&subtype=0";
	//filenameInput = "rtsp://55555:55555@192.168.11.185:554/cam/realmonitor?channel=1&subtype=0";
	//filenameInput = "rtsp://55555:55555@192.168.11.183:554/cam/realmonitor?channel=1&subtype=0";
	//filenameInput = "rtsp://55555:55555@192.168.11.197:554/cam/realmonitor?channel=1&subtype=0";
	//filenameInput = "rtsp://55555:55555@192.168.11.198:554/cam/realmonitor?channel=1&subtype=0";
	//filenameInput = "rtsp://55555:55555@192.168.11.187:554/cam/realmonitor?channel=1&subtype=0";
	//filenameInput = "rtsp://55555:55555@192.168.11.219:554/cam/realmonitor?channel=1&subtype=0";
	//filenameInput = "rtsp://55555:55555@192.168.11.199:554/cam/realmonitor?channel=1&subtype=0";
	//filenameInput = "rtsp://55555:55555@192.168.11.112:554/cam/realmonitor?channel=1&subtype=01";
	//filenameInput = "rtsp://55555:Five55555@192.168.11.118:554/cam/realmonitor?channel=1&subtype=01";
	//filenameInput = "rtsp://55555:Five55555@192.168.11.108:554/cam/realmonitor?channel=1&subtype=01";
	//filenameInput = "rtsp://192.168.11.68:554/snl/live/1/1/B0601YE=-dBL3hYFJiG5Y";
	//filenameInput = "rtsp://192.168.11.180:553/snl/live/1/1/B0601YE=-dBL3hYFJiG5Y";
	filenameOutput = "D:\\TestVideo\\testMerge.mkv";
	/**/
	pathInput = new char[filenameInput.size() + 1];
	copy(filenameInput.begin(), filenameInput.end(), pathInput);
	pathInput[filenameInput.size()] = '\0'; 
	/**/
	pathInput2 = new char[filenameInput2.size() + 1];
	copy(filenameInput2.begin(), filenameInput2.end(), pathInput2);
	pathInput2[filenameInput2.size()] = '\0';
	/**/
	pathOutput = new char[filenameOutput.size() + 1];
	copy(filenameOutput.begin(), filenameOutput.end(), pathOutput);
	pathOutput[filenameOutput.size()] = '\0';
	/*
	recorder = new CRecord(pathInput, 10000, pathOutput);
	
	if (recorder->Open()){
		recorder->StartRecord();
	}
	*/
	exporter = new CExport();
	if (!exporter->Merge(pathInput, pathInput2, pathOutput)){
		return FALSE;
	}
	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	//player->Stop();

	return (int)msg.wParam;
}




//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProcMain;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(10);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_WIN32PROJECT);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{


	hInst = hInstance; // Store instance handle in our global variable

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProcMain(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProcMain(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_FILE_OPEN:
			if (!switchsound)
				switchsound = true;
			else
				switchsound = false;
			break;
		case ID_STOP:
			recorder->StopRecord();
			break;
		case ID_PLAY:
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;	
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
