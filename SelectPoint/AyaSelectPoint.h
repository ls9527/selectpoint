#pragma once
#include <Gdiplus.h>
#include <vector>
#include "TagPoint.h"


using namespace Gdiplus;
using namespace std;

// AyaSelectPoint �Ի���

class AyaSelectPoint : public CDialogEx
{
	DECLARE_DYNAMIC(AyaSelectPoint)

public:
	AyaSelectPoint(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AyaSelectPoint();

// �Ի�������
	enum { IDD = IDD_DIALOG1_SEL_POINT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
};
