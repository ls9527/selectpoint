// SelectPoint.h : SelectPoint DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSelectPointApp
// �йش���ʵ�ֵ���Ϣ������� SelectPoint.cpp
//

class CSelectPointApp : public CWinApp
{
public:
	CSelectPointApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
