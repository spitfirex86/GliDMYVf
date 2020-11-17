#pragma once
#include "framework.h"

#ifdef _DEBUG

void DebugInit();
void DebugCleanup();
void DebugPrint(const char *fmt, ...);
void DebugModuleInfo(HMODULE hDllModule);

#define DebugFnPrint(fmt, ...) DebugPrint("[%s] "fmt, __func__, __VA_ARGS__)
#define DebugStub() DebugPrint("*** Stub called: %s()\n", __func__)
#define DebugEnter() DebugPrint("*** Entering %s()\n", __func__)
#define DebugLeave() DebugPrint("*** Leaving %s()\n", __func__)

#else

#define DebugInit()
#define DebugCleanup()
#define DebugPrint(fmt, ...)
#define DebugModuleInfo(hDllModule)

#define DebugFnPrint(fmt, ...)
#define DebugStub()
#define DebugEnter()
#define DebugLeave()

#endif