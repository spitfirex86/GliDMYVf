#pragma once

typedef struct
{
	DWORD _dword0;
	WORD _word4;
	WORD _word6;
	void *lpTempBuffer;
	DWORD _dwordC;
	DWORD _dword10;
	
	DWORD dwFlags;
	
	WORD cyHeight;
	WORD cxWidth;
	WORD _cyHeight;
	WORD _cxWidth;
	
	DWORD currentScrollX;
	DWORD currentScrollY;
	
	BOOL bTextureScrolling;
	DWORD alphaMask;
	
	DWORD _dword30;
	DWORD _dword34;
	DWORD _dword38;
	DWORD _dword3C;
	DWORD _dword40;
	BYTE _byte44;
	
	BYTE cFlags;
	
	char szName[128];
	
} TEXTURE_DATA;