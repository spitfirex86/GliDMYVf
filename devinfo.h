#pragma once
#include "framework.h"

//
// RENDERER INFO
//

extern const char *GLI_NAME;
extern const char *GLI_DESC;
extern const char *GLI_VERSION;
extern const int GLI_CODE;


//
// DEVICE CAPABILITIES
//

// Device capability flags
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
} DC_DEVICE;

// Texture capability flags
typedef enum
{
	TF_PALETTIZED = 1 << 0,
	TF_NONSQUARE = 1 << 1,
	TF_MIPMAP = 1 << 2,
	TF_MIRROR = 1 << 3
	// ...
} DC_TEXTURE;

//TODO: unknown struct members
typedef struct
{
	char _char0; // ?
	DC_DEVICE DeviceFlags;
	DC_TEXTURE TextureFlags;
	BYTE _gapC[8]; // ?
	DWORD TextureMaxSize;
	DWORD TextureMem;
	DWORD VideoMemLocal;
	DWORD VideoMemNonLocal;
	BYTE _byte24; // ?
	float _float28; // ?
} DEV_CAPS;


//
// FUNCTION POINTER TYPES
//

// GLI property set function, used in GLI_DRV_fn_lGetAllDisplayConfig
typedef int (*GliSet)(DWORD display, DWORD device, DWORD mode, const char *szAction, const void *value);

// Common function, used in GLI_DRV_lSetCommonFct
typedef int (*CommonFct)();


//
// GLISET ACTIONS
//

extern const char *GS_ADD_DISPLAY;
extern const char *GS_DISPLAY_NAME;
extern const char *GS_DISPLAY_DESC;

extern const char *GS_ADD_DEVICE;
extern const char *GS_DEVICE_NAME;
extern const char *GS_DEVICE_DESC;

extern const char *GS_ADD_MODE;
extern const char *GS_MODE_FULLSCREEN;
extern const char *GS_MODE_BITDEPTH;
extern const char *GS_MODE_WIDTH;
extern const char *GS_MODE_HEIGHT;
