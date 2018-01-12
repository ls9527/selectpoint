#include "stdafx.h"
#include "SealStatic.h"
#include <Gdiplus.h>
using namespace Gdiplus;

CSealStatic::CSealStatic(void)
{
}


CSealStatic::~CSealStatic(void)
{
}






LRESULT CSealStatic::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	if(message == BN_CLICKED){
		int a= 1;
	}
	return CStatic::WindowProc(message,wParam,lParam);
}

void CSealStatic::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	Graphics g1(lpDrawItemStruct->hwndItem);
	Image sealImage(_T("seal.png"));
	g1.DrawImage(&sealImage,0,0,28,28);
}

BEGIN_MESSAGE_MAP(CSealStatic,CStatic)

END_MESSAGE_MAP()