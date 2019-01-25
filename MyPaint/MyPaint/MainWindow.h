#pragma once

#include "BaseWindow.h"
#include "stdafx.h"
#include "IShape.h"
#include "Line.h"
#include "RectangleShape.h"
#include "EllipseShape.h"

class MainWindow : public BaseWindow
{
	int mWidth;
	POINT mFirts;
	POINT mLast;
	bool isDraw;
	std::vector<IShape*> mField;
	IShape *mShape;
	int R;
	int G;
	int B;
	RECT rectColor;
public:
	MainWindow(HINSTANCE hInstance, LPCSTR dlgResName, HWND hWndParent);
	~MainWindow();
	void OnCreate();
private:
	BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
	void Cls_OnLButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags);
	void Cls_OnMouseMove(HWND hwnd, int x, int y, UINT keyFlags);
	void Cls_OnLButtonUp(HWND hwnd, int x, int y, UINT keyFlags);
	void Cls_OnHScroll(HWND hwnd, HWND hwndCtl, UINT code, int pos);
	void Cls_OnDestroy(HWND hwnd);
	void Cls_OnPaint(HWND hwnd);
	LRESULT RealDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};

