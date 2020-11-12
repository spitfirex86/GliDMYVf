// dllmain.c : Defines the entry point for the DLL application.
#include "framework.h"
#include "debug.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    	DebugInit();
	    srand(time(0));
    	DebugModuleInfo(hModule);
    	break;
    	
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    	break;
    	
    case DLL_PROCESS_DETACH:
    	DebugCleanup();
        break;
    }
    return TRUE;
}

