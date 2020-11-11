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

#endif