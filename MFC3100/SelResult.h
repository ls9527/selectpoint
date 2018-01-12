#pragma once

#include "Resource.h"
#include <Gdiplus.h>
#include <vector>

using namespace Gdiplus;
using namespace std;

#define IDD_MFCRESULT_DIALOG 1005H
// CSelResult �Ի���
typedef struct {
	RECT rect;//seal������
	HWND hWnd;//seal�ľ��id
}SealRect ,*LPSealRect;

class CSelResult : public CDialogEx
{
	DECLARE_DYNAMIC(CSelResult)

public:
	
	CSelResult(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSelResult();

	void GetPoints(vector<LPSealRect> &seal);

// �Ի�������
	enum { IDD = IDD_MFC3100_DIALOG };
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	

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
