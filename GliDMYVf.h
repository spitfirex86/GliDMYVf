#pragma once
#include "framework.h"

#include "devinfo.h"
#include "texture.h"

#define EXPORT __declspec(dllexport)

//
// EXPORTED FUNCTIONS
//

// called by GliDetectDll from 0x100014E0
EXPORT BOOL GLI_DRV_lGetDllInfo(const char *szType, void *lpDst);
EXPORT BOOL GLI_DRV_fn_lGetAllDisplayConfig(GliSet gliSet);

// called by Rayman2.exe from LoadGLILibrary [0x00421880]
EXPORT BOOL GLI_DRV_lSetCommonData(const char *szName, void *value);
EXPORT BOOL GLI_DRV_lSetCommonFct(const char *szName, CommonFct lpFn);

// called by Rayman2.exe from InitDisplay [0x00422460]
EXPORT BOOL GLI_DRV_fnl_EnumModes(char *szDrvDspName /*lpContext*/, char *szDevName);


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
EXPORT int GLI_DRV_lGetSizeOfTexture(TEXTURE_DATA *a1);
EXPORT void GLI_DRV_vDoOpaqueTextureSelection(int a1);

EXPORT HANDLE /*HRESULT?*/ GLI_DRV_hChangeMode(BOOL bFullscreen, int xRight, int yBottom, int bitDepth);

EXPORT BOOL GLI_DRV_bWindowedModeIsOptimized();
EXPORT void GLI_DRV_vOptimizedWindowedMode();
EXPORT void GLI_DRV_vNonOptimizedWindowedMode();
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
