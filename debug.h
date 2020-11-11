#pragma once

#ifdef _DEBUG

extern FILE *fDebugLog;

void DebugInit();
void DebugCleanup();
void DebugModuleInfo(HMODULE hDllModule);

#define debug_print(format, ...) do { if (fDebugLog) fprintf(fDebugLog, format, __VA_ARGS__); } while (0)
#define debug_fnprint(format, ...) debug_print("[%s] "format, __func__, __VA_ARGS__)
#define debug_enter() debug_print("*** Entering %s()\n", __func__)
#define debug_leave() debug_print("*** Leaving %s()\n", __func__)

#else

#define DebugInit()
#define DebugCleanup()
#define DebugModuleInfo(hDllModule)

#define debug_print(format, ...)
#define debug_fnprint(format, ...)
#define debug_enter()
#define debug_leave()

#endif