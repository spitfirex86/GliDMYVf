#include "GliDMYVf.h"
#include "debug.h"

//
// FUNCTION STUBS FOR Rayman2.exe
//

EXPORT DWORD /*HRESULT?*/ GLI_DRV_xInitDriver(HWND hWnd, BOOL bFullscreen, int xRight, int yBottom, int lBitDepth)
{
	DebugStub();
	return 0;
}

EXPORT void GLI_DRV_vCloseDriver()
{
	DebugStub();
}

EXPORT BOOL GLI_DRV_bBeginScene()
{
	DebugStub();
	return TRUE;
}

EXPORT BOOL GLI_DRV_bEndScene()
{
	DebugStub();
	return TRUE;
}

EXPORT BOOL GLI_DRV_bLockDevice(DWORD *a1, DWORD *a2)
{
	DebugStub();
	return TRUE;
}

EXPORT BOOL GLI_DRV_bUnlockDevice()
{
	DebugStub();
	return TRUE;
}

EXPORT void GLI_DRV_vClearDevice(int a1, int a2, int a3)
{
	DebugStub();
}

EXPORT void GLI_DRV_vFlipDevice()
{
	DebugStub();
}

EXPORT void GLI_DRV_vFlipDeviceWithSyncro()
{
	DebugStub();
}

EXPORT void GLI_DRV_vDownLoadTextures(int a1, int a2, int a3)
{
	DebugStub();
}

EXPORT void GLI_DRV_vUnLoadTextures()
{
	DebugStub();
}

EXPORT int GLI_DRV_lGetSizeOfTexture(TEXTURE_DATA *a1)
{
	DebugStub();
	return 0;
}

EXPORT void GLI_DRV_vDoOpaqueTextureSelection(int a1)
{
	DebugStub();
}

EXPORT HANDLE GLI_DRV_hChangeMode(BOOL bFullscreen, int xRight, int yBottom, int bitDepth)
{
	DebugStub();
	return NULL;
}

EXPORT BOOL GLI_DRV_bWindowedModeIsOptimized()
{
	DebugStub();
	return FALSE;
}

EXPORT void GLI_DRV_vOptimizedWindowedMode()
{
	DebugStub();
}

EXPORT void GLI_DRV_vNonOptimizedWindowedMode()
{
	DebugStub();
}

EXPORT BOOL GLI_DRV_bPrepareForGliWindowed(HWND hWnd)
{
	DebugStub();
	return TRUE;
}

EXPORT void GLI_DRV_vPrepareForGliFullScreen(HWND hWnd)
{
	DebugStub();
}

EXPORT void GLI_DRV_vActivateGli(HWND hWnd, BOOL a2)
{
	DebugStub();
}

EXPORT void GLI_DRV_vReadaptDisplay()
{
	DebugStub();
}

EXPORT void GLI_DRV_vAddBlackPolygon(int a1, int a2, int a3, int a4)
{
	DebugStub();
}

EXPORT void GLI_DRV_vNoBlackPolygon()
{
	DebugStub();
}

EXPORT void GLI_DRV_vSetZClip(float a1, int a2)
{
	DebugStub();
}

EXPORT void GLI_DRV_vSetClipWindow(float a1, int a2, int a3, int a4, int a5)
{
	DebugStub();
}

EXPORT void GLI_DRV_vSendSingleLineToClip(int a1, int a2, int a3, int a4, int a5)
{
	DebugStub();
}

EXPORT void GLI_DRV_vSendSpriteToClip(int a1, int a2, int a3, float a4, int a5)
{
	DebugStub();
}

EXPORT void GLI_DRV_vSendSpriteToClipWithColors(int a1, int a2, int a3, int a4, float a5, int a6)
{
	DebugStub();
}

EXPORT void GLI_DRV_vSendSpriteToClipWithUV(int a1, int a2, int a3, int a4, float a5, int a6)
{
	DebugStub();
}

EXPORT int GLI_DRV_xSendElementTIToClip_TRIANGLES(int a1, int a2)
{
	DebugStub();
	return 0;
}

EXPORT int GLI_DRV_xSendSingleTriangleToClip_TRIANGLES(int a1, int a2, int a3)
{
	DebugStub();
	return 0;
}

EXPORT DWORD GLI_DRV_xClearViewingList()
{
	DebugStub();
	return 0;
}

EXPORT DWORD GLI_DRV_xSendListToViewport()
{
	DebugStub();
	return 0;
}

EXPORT void GLI_DRV_vClearZBufferRegion()
{
	DebugStub();
}

EXPORT void GLI_DRV_vComputeFogEffect(int a1)
{
	DebugStub();
}

EXPORT void GLI_DRV_vWrite16bBitmapToBackBuffer(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
	DebugStub();
}
