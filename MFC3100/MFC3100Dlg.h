
// MFC3100Dlg.h : 头文件
//

#pragma once
#include <gdiplus.h>
#include <GdiplusInit.h>
#include "SealStatic.h"

#include <vector>
#include "SelResult.h"
#include "afxwin.h"
using namespace Gdiplus;
using namespace std;




// CMFC3100Dlg 对话框
class CMFC3100Dlg : public CDialogEx
{
// 构造
public:
	CMFC3100Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC3100_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


	
	
	// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonZhua();
	afx_msg void OnBnClickedButton2();
	

private:
	
	GdiplusStartupInput m_gsInput;
	CSealStatic m_sealStatic;
	
	vector<SealRect*> m_sealVector;
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButton1();
//	afx_msg void OnStnClickedStaticImg();
	afx_msg void OnStnClickedStaticImg();
	afx_msg void OnStnClickedStaticB();
	
	
	afx_msg void OnBnClickedButton4();
	
	
	CSelResult m_selResult;
	afx_msg void OnBnClickedButtonShow();
	CListBox m_listbox;
};
