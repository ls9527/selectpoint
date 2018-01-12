#include "stdafx.h"
#include "MainPaint.h"
#include <Gdiplus.h>
using namespace Gdiplus;

ULONG m_gdiToken;
GdiplusStartupInput m_gsInput;
CMainPaint::CMainPaint(void)
{
	GdiplusStartup(&m_gdiToken,&m_gsInput,NULL);
}


CMainPaint::~CMainPaint(void)
{
	GdiplusShutdown(m_gdiToken);
}
WNDPROC m_oldProc;
LRESULT CALLBACK MainWindowProc(
	HWND hwnd,      // handle to window
	UINT uMsg,      // message identifier
	WPARAM wParam,  // first message parameter
	LPARAM lParam   // second message parameter
	){
		if(uMsg == WM_PAINT){
			PAINTSTRUCT ps;
			
			HDC pDC = BeginPaint(hwnd,&ps);
			
			
			Gdiplus::Graphics grap(pDC);
			Image image(L"t1.jpg");
			grap.DrawImage(&image,0,0);
			/*
			CString str("wwwqqqaaazzzxxx`12123123ÄãºÃÂð¹þ¹þ¹þ");
			TextOut(pDC,100,100,str,str.GetLength());
			*/
			EndPaint(hwnd,&ps);
		}
		
		return CallWindowProc(m_oldProc,hwnd,uMsg,wParam,lParam);
}
void CMainPaint::Attach(HWND hWnd)
{
	m_hwnd = hWnd;
	m_oldProc = (WNDPROC)SetWindowLong(hWnd,GWL_WNDPROC,(LONG)&MainWindowProc);
}

void CMainPaint::Detach()
{
	SetWindowLong(m_hwnd,GWL_WNDPROC,(LONG)m_oldProc);
}
