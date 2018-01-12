// SelResult.cpp : 实现文件
//

#include "stdafx.h"

#include "SelResult.h"
#include "afxdialogex.h"
#include <vector>
#include "SealStatic.h"
//点击后的图标大小
#define SEAL_WIDTH 28
#define SEAL_HEIGHT 28

#define MYWNDCLASS _T("MyDrawPad")

// CSelResult 对话框

IMPLEMENT_DYNAMIC(CSelResult, CStatic)

	
CSelResult::CSelResult():CStatic()
{
	GdiplusStartup(&m_token,&m_gdiInputA,NULL);
}

CSelResult::~CSelResult()
{
	vector<SealRect*>::iterator it = m_sealVector.begin();
	BOOL isDelete = FALSE;
	while(it != m_sealVector.end()){
		delete *it;
		*it++;
	}
}


void CSelResult::GetPoints(vector<LPSealRect> &seal)
{
	seal = m_sealVector;
}

BOOL CSelResult::hasPoint(Point &point){
	vector<SealRect*>::iterator it = m_sealVector.begin();
	BOOL isDelete = FALSE;
	while(it != m_sealVector.end()){
		 RECT rect = (*it)->rect;
		Rect rectItem = Rect(rect.left,rect.top,rect.right-rect.left,rect.bottom - rect.top);

		//Rect rTmp = Rect(rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top);
		// rectItem.IntersectsWith(rTmp)
		//可以选择包含点Contains(Point)，或者是和另一个矩形有交集 IntersectsWith(Rect)
		if(rectItem.Contains(point)){
			CWnd* cWnd = CWnd::FromHandle((*it)->hWnd);
			cWnd->DestroyWindow();
			delete cWnd;
			it = m_sealVector.erase(it);
			isDelete = TRUE;
		}else{
			it++;
		}

	}
	return isDelete;
}
void CSelResult::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//CDialogEx::OnLButtonDown(nFlags, point);
	
	CStatic *img = this;
	// TODO: 在此添加控件通知处理程序代码
	DWORD pos = ::GetMessagePos();
	POINT p1 = {};
	GetCursorPos(&p1);
	POINT p2 = {};
	img->ScreenToClient(&p2);
	POINT p3={p1.x+p2.x,p1.y+p2.y};

	int width = SEAL_WIDTH/2,height = SEAL_WIDTH/2;
	RECT rect = {p3.x-width,p3.y-height,p3.x+height,p3.y+height};

	BOOL isDelete = hasPoint(Point(p3.x,p3.y));
	
	//如果删除了上一次添加的内容，这次就不添加了
	if(isDelete){
		return;
	}
	
	//画上去的点坐标
	
	CStatic *seal = new CSealStatic;
	
	seal->Create(_T("SEAL"),WS_CHILD|WS_VISIBLE|SS_OWNERDRAW,rect,img);
	
	SealRect* pSeal = new SealRect;
	pSeal->hWnd = seal->m_hWnd;

	
	pSeal->rect = rect;
	m_sealVector.push_back(pSeal);
	
	
}


LRESULT CSelResult::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	
	if(message==WM_PAINT){
		//画在底层

		PAINTSTRUCT ps = {};
		
		CDC *pDC = BeginPaint(&ps);

		Graphics g1(*pDC);
		Image sealImage(_T("t1.jpg"));
		g1.DrawImage(&sealImage,0,0);

		EndPaint(&ps);
	}
	if(message == WM_LBUTTONDOWN){
		int a = 1;
	}
	
	return CStatic::WindowProc(message,wParam,lParam);
}

BOOL CSelResult::DestroyWindow()
{
	//throw std::logic_error("The method or operation is not implemented.");
	GdiplusShutdown(m_token);
	return CStatic::DestroyWindow();
}

void CSelResult::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	/*
	PAINTSTRUCT ps = {};

	CDC *pDC = BeginPaint(&ps);

	Graphics g1(*pDC);
	Image sealImage(_T("t1.jpg"));
	g1.DrawImage(&sealImage,0,0);

	EndPaint(&ps);
	*/
}

BEGIN_MESSAGE_MAP(CSelResult, CStatic)
	
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CSelResult 消息处理程序
