#pragma once

#include "Resource.h"
#include <Gdiplus.h>
#include <vector>

using namespace Gdiplus;
using namespace std;

#define IDD_MFCRESULT_DIALOG 1005H
// CSelResult 对话框
typedef struct {
	RECT rect;//seal的区域
	HWND hWnd;//seal的句柄id
}SealRect ,*LPSealRect;

class CSelResult : public CDialogEx
{
	DECLARE_DYNAMIC(CSelResult)

public:
	
	CSelResult(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSelResult();

	void GetPoints(vector<LPSealRect> &seal);

// 对话框数据
	enum { IDD = IDD_MFC3100_DIALOG };
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	

	BOOL RegisterWndClass();
	DECLARE_MESSAGE_MAP()
private:
	
	ULONG m_token;
	GdiplusStartupInput m_gdiInputA;
	vector<LPSealRect> m_sealVector;
protected:

	virtual void OnPaint();
	
	BOOL hasPoint(Point &point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	

	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

	virtual BOOL DestroyWindow();

};
