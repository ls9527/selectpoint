#pragma  once


#ifdef XX_DLL  
#define XXAPI __declspec(dllexport)  
#else  
#define XXAPI __declspec(dllimport)  
#endif

#include "stdafx.h"

#define SEAL_WIDTH 28
#define SEAL_HEIGHT 28

typedef struct {
	RECT rect;//seal������
	HWND hWnd;//seal�ľ��id
}SealRect ,*LPSealRect;
