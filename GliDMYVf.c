#include "framework.h"
#include "GliDMYVf.h"
#include "debug.h"

// Renderer info

const char *szName = "GLIDummy";
const char *szDesc = "Spitfire's GLI Driver Test";
const char *szVer = "1.0.0.0";
const int code = 5;

int RandInt(int min, int max)
{
	return rand() % (max - min) + min;
}


void CopyString(char *dst, const char *src)
{
	debug_print("Copying string '%s' to address 0x%x\n", src, (int)dst);
	const int len = strlen(src) + 1;
	strcpy_s(dst, len, src);
}


//
// EXPORTED FUNCTIONS
//

// Copies renderer info (first listbox in GxSetup) to specified memory address
EXPORT BOOL GLI_DRV_lGetDllInfo(const char *szType, void *lpDst)
{
	debug_enter();
	debug_print("Requested value '%s'\n", szType);

	if (strcmp(szType, "Name") == 0)
	{
		CopyString(lpDst, szName);
	}
	else if (strcmp(szType, "Description") == 0)
	{
		CopyString(lpDst, szDesc);
	}
	else if (strcmp(szType, "Version") == 0)
	{
		CopyString(lpDst, szVer);
	}
	else if (strcmp(szType, "Code") == 0)
	{
		*(DWORD*)lpDst = code;
	}
	else
	{
		debug_print("Value '%s' unsupported, nothing returned\n", szType);
		return FALSE;
	}

	debug_leave();
	return TRUE;
}

// Sets capability flags and populates displays, devices and resolutions
EXPORT BOOL GLI_DRV_fn_lGetAllDisplayConfig(GliSet gliSet)
{
	debug_enter();

	int disp, dev, mode;
	DEV_CAPS caps = { 0 };

	// logo displayed at the bottom of the dialog
	// 1 - 3Dfx, 2 - DirectX, 3 - OpenGL, other - pirate head
	gliSet(0, 0, 0, "dll_bmp", 0);

	// display info
	disp = gliSet(0, 0, 0, "dispadd", NULL);
	gliSet(disp, 0, 0, "dispname", "DispName");
	gliSet(disp, 0, 0, "dispdesc", "Display Description");
	debug_print("Added display: %i\n", disp);

	// device info
	dev = gliSet(disp, 0, 0, "dev_add", NULL);
	gliSet(disp, dev, 0, "dev_name", "DevName");
	gliSet(disp, dev, 0, "dev_desc", "Device Description");
	debug_print("Added device: %i\n", dev);

	// display mode (resolution)
	mode = gliSet(disp, dev, 0, "modeadd", NULL);
	gliSet(disp, dev, mode, "modefs", 1);
	gliSet(disp, dev, mode, "modebpp", 16);
	gliSet(disp, dev, mode, "modew", 1234);
	gliSet(disp, dev, mode, "modeh", 5678);
	debug_print("Added mode: %i\n", mode);

	// device capabilities
	caps.VideoMemLocal = 1415;
	caps.VideoMemNonLocal = 9265;
	caps.TextureMem = 3589;
	caps.TextureMaxSize = 7932;

	// random flags just for fun
	// NOTE: rng is initialized in DllMain
	caps.DeviceFlags = RandInt(0, 1 << 6);
	caps.TextureFlags = RandInt(0, 1 << 4);

	gliSet(disp, dev, 0, "dev_caps", &caps);

	debug_leave();
	return TRUE;
}


//
// FUNCTION STUBS FOR Rayman2.exe
//

EXPORT BOOL GLI_DRV_lSetCommonData(const char *szName, void *value)
{
	debug_fnprint("Got value, name: '%s', hex value: 0x%x\n", szName, (int)value);
	return TRUE;
}

EXPORT BOOL GLI_DRV_lSetCommonFct(const char *szName, CommonFct lpFn)
{
	debug_fnprint("Got function, name: '%s', address: 0x%x\n", szName, (int)lpFn);
	return TRUE;
}