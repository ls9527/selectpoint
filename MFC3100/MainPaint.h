#pragma once
#include "stdafx.h"
class CMainPaint
{
public:
	CMainPaint(void);
	~CMainPaint(void);
	void Attach(HWND hWnd);
	void Detach();
private:
	HWND m_hwnd;
};

