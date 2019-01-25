#include "BaseWindow.h"

BaseWindow::BaseWindow(HINSTANCE hInstance, LPCSTR dlgResName, HWND hWndParent)
{
	CreateDlg(hInstance, dlgResName, hWndParent);
}

BaseWindow::~BaseWindow()
{
}

void BaseWindow::Show(int iCmdShow)
{
	ShowWindow(hWindow, iCmdShow);
	UpdateWindow(hWindow);
}

void BaseWindow::CreateDlg(HINSTANCE hInstance, LPCSTR dlgResName, HWND hWndParent)
{
	hWindow = CreateDialog(hInstance, dlgResName, hWndParent, (DLGPROC)StDlgProc);
	SetWindowLongPtr(hWindow, GWLP_USERDATA, (LONG_PTR)this);
}

LRESULT BaseWindow::RealDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		HANDLE_MSG(hWnd, WM_CLOSE, Cls_OnClose);
	}
	return 0;
}

LRESULT BaseWindow::StDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	BaseWindow *pOldBaseWindow = NULL;

	pOldBaseWindow = (BaseWindow*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
	if (pOldBaseWindow != NULL)
		return pOldBaseWindow->RealDlgProc(hWnd, uMsg, wParam, lParam);
	return 0;
}

void BaseWindow::Cls_OnClose(HWND hwnd)
{
	PostQuitMessage(0);
}
