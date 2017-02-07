
#include "stdafx.h"
#include <windows.h>
#include <psapi.h>


/* Calling Example

std::thread([=] {
MemLog* memLog = new MemLog("D:\\", GetCurrentProcessId());
}).detach();

*/

class MemLog{

	FILE* m_pFile;
	FILE* m_pFile2;
	HANDLE hProcess;

public:
	MemLog(std::string _path, DWORD processID){
		std::string tmp = _path + "workingsetsize.txt";
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