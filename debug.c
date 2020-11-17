#ifdef _DEBUG

#include "framework.h"
#include "debug.h"

FILE *fDebugLog;
const char *szLogFile = "GliDMYLog.log";

void DebugInit()
{
	fopen_s(&fDebugLog, szLogFile, "w");
	if (fDebugLog)
	{
		setvbuf(fDebugLog, NULL, _IONBF, 0);
	}

	if (AllocConsole())
	{
		FILE *fDummy;
		freopen_s(&fDummy, "CONIN$", "r", stdin);
		freopen_s(&fDummy, "CONOUT$", "w", stderr);
		freopen_s(&fDummy, "CONOUT$", "w", stdout);
	}

	MessageBox(NULL, "If you want to attach a debugger, do it now.\nPress OK to continue.", "Spitfire's Advice", MB_OK | MB_ICONASTERISK);
}

void DebugCleanup()
{
	if (fDebugLog)
	{
		fclose(fDebugLog);
	}
	
	FreeConsole();
}

void DebugPrint(const char *fmt, ...)
{
	va_list args;
	
	if (fDebugLog)
	{
		// print to file
		va_start(args, fmt);
		vfprintf(fDebugLog, fmt, args);
		va_end(args);
	}

	// print to console
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);
}

void DebugPrintModuleNameAddress(HMODULE hModule)
{
	char szModuleName[MAX_PATH];
	char *pBaseName;

	GetModuleFileName(hModule, szModuleName, MAX_PATH);
	pBaseName = (strrchr(szModuleName, '\\') + 1);

	DebugPrint("\tModule name: %s\n\tBase address: 0x%x\n\n", pBaseName, (int)hModule);
}

void DebugModuleInfo(HMODULE hDllModule)
{
	HMODULE hMainModule = GetModuleHandle(NULL);
	
	DebugPrint("*** DLL module info:\n");
	DebugPrintModuleNameAddress(hDllModule);
	
	DebugPrint("*** Main module info:\n");
	DebugPrintModuleNameAddress(hMainModule);
}

#endif
