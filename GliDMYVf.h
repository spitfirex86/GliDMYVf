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

// called by Rayman2.exe from LoadGLILibrary (0x00421880)

EXPORT BOOL GLI_DRV_lSetCommonData(const char *szName, void *value);
EXPORT BOOL GLI_DRV_lSetCommonFct(const char *szName, CommonFct lpFn);


//
// FUNCTION STUBS FOR Rayman2.exe
//

EXPORT DWORD /*HRESULT?*/ GLI_DRV_xInitDriver(HWND hWnd, BOOL bFullscreen, int xRight, int yBottom, int lBitDepth);
EXPORT void GLI_DRV_vCloseDriver();

EXPORT BOOL GLI_DRV_bBeginScene();
EXPORT BOOL GLI_DRV_bEndScene();

EXPORT BOOL GLI_DRV_bLockDevice(DWORD *a1, DWORD *a2);
EXPORT BOOL GLI_DRV_bUnlockDevice();
EXPORT void GLI_DRV_vClearDevice(int a1, int a2, int a3);
EXPORT void GLI_DRV_vFlipDevice();
EXPORT void GLI_DRV_vFlipDeviceWithSyncro();

EXPORT void GLI_DRV_vDownLoadTextures(int a1, int a2, int a3);
EXPORT void GLI_DRV_vUnLoadTextures();
EXPORT int GLI_DRV_lGetSizeOfTexture(void *a1);
EXPORT void GLI_DRV_vDoOpaqueTextureSelection(int a1);

EXPORT int GLI_DRV_fnl_EnumModes(char *szDrvDspName /*lpContext*/, char *szDevName);
EXPORT HANDLE /*HRESULT?*/ GLI_DRV_hChangeMode(int bFullscreen, int xRight, int yBottom, int bitDepth);

EXPORT BOOL GLI_DRV_bWindowedModeIsOptimized();
EXPORT void GLI_DRV_vOptimizedWindowedMode();
EXPORT BOOL GLI_DRV_bPrepareForGliWindowed(HWND hWnd);
EXPORT void GLI_DRV_vPrepareForGliFullScreen(HWND hWnd);
EXPORT void GLI_DRV_vActivateGli(HWND hWnd, BOOL a2);
EXPORT void GLI_DRV_vReadaptDisplay();

EXPORT void GLI_DRV_vAddBlackPolygon(int a1, int a2, int a3, int a4);
EXPORT void GLI_DRV_vNoBlackPolygon();

EXPORT void GLI_DRV_vSetZClip(float a1, int a2);
EXPORT void GLI_DRV_vSetClipWindow(float a1, int a2, int a3, int a4, int a5);
EXPORT void GLI_DRV_vSendSingleLineToClip(int a1, int a2, int a3, int a4, int a5);
EXPORT void /*__fastcall*/ GLI_DRV_vSendSpriteToClip(int a1, int a2, int a3, float a4, int a5);
EXPORT void /*__fastcall*/ GLI_DRV_vSendSpriteToClipWithColors(int a1, int a2, int a3, int a4, float a5, int a6);
EXPORT void /*__fastcall*/ GLI_DRV_vSendSpriteToClipWithUV(int a1, int a2, int a3, int a4, float a5, int a6);
EXPORT int GLI_DRV_xSendElementTIToClip_TRIANGLES(int a1, int a2);
EXPORT int GLI_DRV_xSendSingleTriangleToClip_TRIANGLES(int a1, int a2, int a3);

EXPORT DWORD GLI_DRV_xClearViewingList();
EXPORT DWORD GLI_DRV_xSendListToViewport();

EXPORT void GLI_DRV_vClearZBufferRegion();
EXPORT void GLI_DRV_vComputeFogEffect(int a1);
EXPORT void GLI_DRV_vWrite16bBitmapToBackBuffer(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
