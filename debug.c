#include "framework.h"
#include "debug.h"

#ifdef _DEBUG

FILE *fDebugLog;
const char *szLogFile = "GliDMYLog.log";

void DebugInit()
{
	fopen_s(&fDebugLog, szLogFile, "w");
	if (fDebugLog)
	{
		setvbuf(fDebugLog, NULL, _IONBF, 0);
	}
}

void DebugCleanup()
{
	if (fDebugLog)
	{
		fclose(fDebugLog);
	}
}

void DebugPrintModuleNameAddress(HMODULE hModule)
{
	char szModuleName[MAX_PATH];
	char *pBaseName;

	GetModuleFileName(hModule, szModuleName, MAX_PATH);
	pBaseName = (strrchr(szModuleName, '\\') + 1);

	debug_print("\tModule name: %s\n\tBase address: 0x%x\n\n", pBaseName, (int)hModule);
}

void DebugModuleInfo(HMODULE hDllModule)
{
	HMODULE hMainModule = GetModuleHandle(NULL);
	
	debug_print("*** DLL module info:\n");
	DebugPrintModuleNameAddress(hDllModule);
	
	debug_print("*** Main module info:\n");
	DebugPrintModuleNameAddress(hMainModule);
}

#endif
