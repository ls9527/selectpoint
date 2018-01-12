#pragma once


#include <Gdiplus.h>
#include <vector>
#include "TagPoint.h"
using namespace Gdiplus;
using namespace std;



class XXAPI CSelResult : public CStatic
{
	DECLARE_DYNAMIC(CSelResult)

public:
	
	CSelResult();   // 标准构造函数
	~CSelResult();

	void GetPoints(vector<LPSealRect> &seal);

// 对话框数据

	//virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	

	BOOL RegisterWndClass();
	DECLARE_MESSAGE_MAP()
private:
	
	ULONG m_token;
	GdiplusStartupInput m_gdiInputA;
	vector<LPSealRect> m_sealVector;
protected:


	
	BOOL hasPoint(Point &point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	

	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

	virtual BOOL DestroyWindow();

	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

};
