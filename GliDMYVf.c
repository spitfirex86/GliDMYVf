#include "GliDMYVf.h"
#include "debug.h"

// AddDisplayMode function pointer
int (*fnAddDiplayMode)(BOOL bFullscreen, int x, int y, int lBitDepth) = NULL;


int RandInt(int min, int max)
{
	return rand() % (max - min) + min;
}

void CopyString(char *dst, const char *src)
{
	DebugPrint("Copying string '%s' to address 0x%x\n", src, (int)dst);
	const size_t len = strlen(src) + 1;
	strcpy_s(dst, len, src);
}


//
// EXPORTED FUNCTIONS
//

// Copies renderer info (first listbox in GxSetup) to specified memory address
EXPORT BOOL GLI_DRV_lGetDllInfo(const char *szType, void *lpDst)
{
	DebugEnter();
	DebugPrint("Requested value '%s'\n", szType);

	if (strcmp(szType, "Name") == 0)
	{
		CopyString(lpDst, GLI_NAME);
	}
	else if (strcmp(szType, "Description") == 0)
	{
		CopyString(lpDst, GLI_DESC);
	}
	else if (strcmp(szType, "Version") == 0)
	{
		CopyString(lpDst, GLI_VERSION);
	}
	else if (strcmp(szType, "Code") == 0)
	{
		*(DWORD*)lpDst = GLI_CODE;
	}
	else
	{
		DebugPrint("Value '%s' unsupported, nothing returned\n", szType);
		return FALSE;
	}

	DebugLeave();
	return TRUE;
}

// Sets capability flags and populates displays, devices and resolutions
EXPORT BOOL GLI_DRV_fn_lGetAllDisplayConfig(GliSet gliSet)
{
	DebugEnter();

	int disp, dev, mode;
	DEV_CAPS caps = { 0 };

	// logo displayed at the bottom of the dialog
	// 1 - 3Dfx, 2 - DirectX, 3 - OpenGL, other - pirate head
	gliSet(0, 0, 0, "dll_bmp", 0);

	// display info
	disp = gliSet(0, 0, 0, GS_ADD_DISPLAY, NULL);
	gliSet(disp, 0, 0, GS_DISPLAY_NAME, "DispName");
	gliSet(disp, 0, 0, GS_DISPLAY_DESC, "Display Description");
	DebugPrint("Added display: %i\n", disp);

	// device info
	dev = gliSet(disp, 0, 0, GS_ADD_DEVICE, NULL);
	gliSet(disp, dev, 0, GS_DEVICE_NAME, "DevName");
	gliSet(disp, dev, 0, GS_DEVICE_DESC, "Device Description");
	DebugPrint("Added device: %i\n", dev);

	// display mode (resolution)
	mode = gliSet(disp, dev, 0, GS_ADD_MODE, NULL);
	gliSet(disp, dev, mode, GS_MODE_FULLSCREEN, 1);
	gliSet(disp, dev, mode, GS_MODE_BITDEPTH, 16);
	gliSet(disp, dev, mode, GS_MODE_WIDTH, 800);
	gliSet(disp, dev, mode, GS_MODE_HEIGHT, 600);
	DebugPrint("Added mode: %i\n", mode);

	// device capabilities
	caps.VideoMemLocal = 0x4000;
	caps.VideoMemNonLocal = 0x2000;
	caps.TextureMem = 0x8000;
	caps.TextureMaxSize = 0x400;

	// random flags just for fun
	// NOTE: rng is initialized in DllMain
	caps.DeviceFlags = RandInt(0, 1 << 6);
	caps.TextureFlags = RandInt(0, 1 << 4);

	gliSet(disp, dev, 0, "dev_caps", &caps);

	DebugLeave();
	return TRUE;
}


//
// FUNCTION STUBS FOR Rayman2.exe
//

EXPORT BOOL GLI_DRV_lSetCommonData(const char *szName, void *value)
{
	DebugFnPrint("Got value, name: '%s', hex value: 0x%x\n", szName, (int)value);
	return TRUE;
}

EXPORT BOOL GLI_DRV_lSetCommonFct(const char *szName, CommonFct lpFn)
{
	DebugFnPrint("Got function, name: '%s', address: 0x%x\n", szName, (int)lpFn);

	// temporary, needed for EnumModes
	if (!strcmp(szName, "AddDisplayMode"))
	{
		fnAddDiplayMode = lpFn;
	}
	
	return TRUE;
}

EXPORT BOOL GLI_DRV_fnl_EnumModes(char *szDrvDspName /*lpContext*/, char *szDevName)
{
	DebugStub();

	// temporary
	fnAddDiplayMode(TRUE, 800, 600, 16);

	return TRUE;
}