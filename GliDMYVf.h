#pragma once

#define EXPORT __declspec(dllexport)

typedef enum
{
	DF_HARDWARE_ACCEL = 1 << 0,
	DF_AGP_MEM = 1 << 1,
	DF_SYS_MEM = 1 << 2,
	DF_WINDOWED = 1 << 3,
	DF_ALPHA_TEST = 1 << 4,
	DF_READJUST_VIEWPORT = 1 << 5
	// ...
	// there's potentially more things here
} DEV_FLAGS;

typedef enum
{
	TF_PALETTIZED = 1 << 0,
	TF_NONSQUARE = 1 << 1,
	TF_MIPMAP = 1 << 2,
	TF_MIRROR = 1 << 3
	// ...
} TEXTURE_FLAGS;

//TODO: unknown struct members
typedef struct
{
	char _char0; // ?
	DEV_FLAGS DeviceFlags;
	TEXTURE_FLAGS TextureFlags;
	BYTE _gapC[8]; // ?
	DWORD TextureMaxSize;
	DWORD TextureMem;
	DWORD VideoMemLocal;
	DWORD VideoMemNonLocal;
	BYTE _byte24; // ?
	float _float28; // ?
} DEV_CAPS;

// Gli property set function, used in GLI_DRV_fn_lGetAllDisplayConfig
typedef int (*GliSet)(DWORD disp, DWORD dev, DWORD mode, const char *szAction, const void *value);

// Common function, used in GLI_DRV_lSetCommonFct
typedef int (*CommonFct)(void);


//
// EXPORTED FUNCTIONS
//

// called by GliDetectDll from 0x100014E0

EXPORT BOOL GLI_DRV_lGetDllInfo(const char *szType, void *lpDst);
EXPORT BOOL GLI_DRV_fn_lGetAllDisplayConfig(GliSet gliSet);

//
// FUNCTION STUBS FOR Rayman2.exe
//

// called by Rayman2.exe from InitDisplay_ActualInit (0x00421670)

EXPORT HRESULT GLI_DRV_xInitDriver(HWND hWnd, BOOL bFullscreen, int xRight, int yBottom, int lBitDepth);

// called by Rayman2.exe from LoadGLILibrary (0x00421880)

EXPORT BOOL GLI_DRV_lSetCommonData(const char *szName, void *value);
EXPORT BOOL GLI_DRV_lSetCommonFct(const char *szName, CommonFct lpFn);
