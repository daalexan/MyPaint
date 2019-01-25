#pragma once
#include "stdafx.h"

class BaseWindow
{
public:
	BaseWindow(HINSTANCE hInstance, LPCSTR dlgResName, HWND hWndParent);
	~BaseWindow();
	void Show(int iCmdShow);
protected:
	HWND hWindow;
	/* Override function which work before window show */
	virtual void OnCreate() = 0;
	void CreateDlg(HINSTANCE hInstance, LPCSTR dlgResName, HWND hWndParent);
	/* Override you own WndProc LRESULT RealDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) */
	virtual LRESULT RealDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
private:
	static LRESULT CALLBACK StDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void Cls_OnClose(HWND hwnd);
};

