#include "framework.h"
#include "GliDMYVf.h"
#include "debug.h"

//
// FUNCTION STUBS FOR Rayman2.exe
//

EXPORT DWORD /*HRESULT?*/ GLI_DRV_xInitDriver(HWND hWnd, BOOL bFullscreen, int xRight, int yBottom, int lBitDepth)
{
	debug_stub();
	return 0;
}

EXPORT void GLI_DRV_vCloseDriver()
{
	debug_stub();
}

EXPORT BOOL GLI_DRV_bBeginScene()
{
	debug_stub();
	return TRUE;
}

EXPORT BOOL GLI_DRV_bEndScene()
{
	debug_stub();
	return TRUE;
}

EXPORT BOOL GLI_DRV_bLockDevice(DWORD *a1, DWORD *a2)
{
	debug_stub();
	return TRUE;
}

EXPORT BOOL GLI_DRV_bUnlockDevice()
{
	debug_stub();
	return TRUE;
}

EXPORT void GLI_DRV_vClearDevice(int a1, int a2, int a3)
{
	debug_stub();
}

EXPORT void GLI_DRV_vFlipDevice()
{
	debug_stub();
}

EXPORT void GLI_DRV_vFlipDeviceWithSyncro()
{
	debug_stub();
}

EXPORT void GLI_DRV_vDownLoadTextures(int a1, int a2, int a3)
{
	debug_stub();
}

EXPORT void GLI_DRV_vUnLoadTextures()
{
	debug_stub();
}

EXPORT int GLI_DRV_lGetSizeOfTexture(void *a1)
{
	debug_stub();
	return 0;
}

EXPORT void GLI_DRV_vDoOpaqueTextureSelection(int a1)
{
	debug_stub();
}

EXPORT HANDLE GLI_DRV_hChangeMode(BOOL bFullscreen, int xRight, int yBottom, int bitDepth)
{
	debug_stub();
	return NULL;
}

EXPORT BOOL GLI_DRV_bWindowedModeIsOptimized()
{
	debug_stub();
	return FALSE;
}

EXPORT void GLI_DRV_vOptimizedWindowedMode()
{
	debug_stub();
}

EXPORT BOOL GLI_DRV_bPrepareForGliWindowed(HWND hWnd)
{
	debug_stub();
	return TRUE;
}

EXPORT void GLI_DRV_vPrepareForGliFullScreen(HWND hWnd)
{
	debug_stub();
}

EXPORT void GLI_DRV_vActivateGli(HWND hWnd, BOOL a2)
{
	debug_stub();
}

EXPORT void GLI_DRV_vReadaptDisplay()
{
	debug_stub();
}

EXPORT void GLI_DRV_vAddBlackPolygon(int a1, int a2, int a3, int a4)
{
	debug_stub();
}

EXPORT void GLI_DRV_vNoBlackPolygon()
{
	debug_stub();
}

EXPORT void GLI_DRV_vSetZClip(float a1, int a2)
{
	debug_stub();
}

EXPORT void GLI_DRV_vSetClipWindow(float a1, int a2, int a3, int a4, int a5)
{
	debug_stub();
}

EXPORT void GLI_DRV_vSendSingleLineToClip(int a1, int a2, int a3, int a4, int a5)
{
	debug_stub();
}

EXPORT void GLI_DRV_vSendSpriteToClip(int a1, int a2, int a3, float a4, int a5)
{
	debug_stub();
}

EXPORT void GLI_DRV_vSendSpriteToClipWithColors(int a1, int a2, int a3, int a4, float a5, int a6)
{
	debug_stub();
}

EXPORT void GLI_DRV_vSendSpriteToClipWithUV(int a1, int a2, int a3, int a4, float a5, int a6)
{
	debug_stub();
}

EXPORT int GLI_DRV_xSendElementTIToClip_TRIANGLES(int a1, int a2)
{
	debug_stub();
	return 0;
}

EXPORT int GLI_DRV_xSendSingleTriangleToClip_TRIANGLES(int a1, int a2, int a3)
{
	debug_stub();
	return 0;
}

EXPORT DWORD GLI_DRV_xClearViewingList()
{
	debug_stub();
	return 0;
}

EXPORT DWORD GLI_DRV_xSendListToViewport()
{
	debug_stub();
	return 0;
}

EXPORT void GLI_DRV_vClearZBufferRegion()
{
	debug_stub();
}

EXPORT void GLI_DRV_vComputeFogEffect(int a1)
{
	debug_stub();
}

EXPORT void GLI_DRV_vWrite16bBitmapToBackBuffer(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
	debug_stub();
}
