#include "MainWindow.h"

MainWindow::MainWindow(HINSTANCE hInstance, LPCSTR dlgResName, HWND hWndParent) : BaseWindow(hInstance, dlgResName, hWndParent)
{
	OnCreate();
	rectColor.left = 480;
	rectColor.right = 520;
	rectColor.top = 5;
	rectColor.bottom = 35;
}

MainWindow::~MainWindow()
{
	if (mShape)
		delete mShape;
	if (!mField.empty())
	{
		for (std::vector<IShape*>::iterator it = mField.begin(); it != mField.end(); ++it)
		{
			delete *it;
		}
	}
}

void MainWindow::OnCreate()
{
}

BOOL MainWindow::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	SendDlgItemMessage(hwnd, IDC_SIZE, TBM_SETRANGE, TRUE, MAKELPARAM(0, 72));
	SendDlgItemMessage(hwnd, 1010, TBM_SETRANGE, TRUE, MAKELPARAM(0, 255));
	SendDlgItemMessage(hwnd, 1011, TBM_SETRANGE, TRUE, MAKELPARAM(0, 255));
	SendDlgItemMessage(hwnd, 1012, TBM_SETRANGE, TRUE, MAKELPARAM(0, 255));
	return TRUE;
}

void MainWindow::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	if (id == IDLINE)
	{
		if (mShape)
			delete mShape;
		mShape = new Line();
	}
	else if (id == IDRECTANGLE)
	{
		if (mShape)
			delete mShape;
		mShape = new RectangleShape();
	}
	else if (id == IDELIPSE)
	{
		if(mShape)
			delete mShape;
		mShape = new EllipseShape();
	}
	else if (id == IDC_UNDO)
	{
		if (!mField.empty())
		{
			IShape *del = mField.back();
			mField.pop_back();
			delete del;
		}
		InvalidateRect(hwnd, NULL, TRUE);
	}
}

void MainWindow::Cls_OnLButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
	isDraw = true;
	mFirts.x = x;
	mFirts.y = y;
}

void MainWindow::Cls_OnMouseMove(HWND hwnd, int x, int y, UINT keyFlags)
{
	if (isDraw)
	{
		mLast.x = x;
		mLast.y = y;
		InvalidateRect(hwnd, NULL, TRUE);
	}
}

void MainWindow::Cls_OnLButtonUp(HWND hwnd, int x, int y, UINT keyFlags)
{
	isDraw = false;
	if (mShape != NULL)
	{
		if (dynamic_cast<Line*>(mShape))
			mField.push_back(new Line(CreatePen(PS_SOLID, mWidth, RGB(R, G, B)), mFirts, mLast));
		else if (dynamic_cast<RectangleShape*>(mShape))
			mField.push_back(new RectangleShape(CreatePen(PS_SOLID, mWidth, RGB(R, G, B)), mFirts, mLast));
		else if (dynamic_cast<EllipseShape*>(mShape))
			mField.push_back(new EllipseShape(CreatePen(PS_SOLID, mWidth, RGB(R, G, B)), mFirts, mLast));
	}
}

void MainWindow::Cls_OnHScroll(HWND hwnd, HWND hwndCtl, UINT code, int pos)
{
	if (hwndCtl == GetDlgItem(hwnd, IDC_SIZE))
	{
		mWidth = SendDlgItemMessage(hwnd, IDC_SIZE, TBM_GETPOS, 0, 0);
	}
	else if (hwndCtl == GetDlgItem(hwnd, 1010))
	{
		R = SendDlgItemMessage(hwnd, 1010, TBM_GETPOS, 0, 0);
	}
	else if (hwndCtl == GetDlgItem(hwnd, 1011))
	{
		G = SendDlgItemMessage(hwnd, 1011, TBM_GETPOS, 0, 0);
	}
	else if (hwndCtl == GetDlgItem(hwnd, 1012))
	{
		B = SendDlgItemMessage(hwnd, 1012, TBM_GETPOS, 0, 0);
	}
	InvalidateRect(hwnd, NULL, TRUE);
}

void MainWindow::Cls_OnDestroy(HWND hwnd)
{
	PostQuitMessage(0);
}

void MainWindow::Cls_OnPaint(HWND hwnd)
{
	HDC hdc;
	PAINTSTRUCT ps;
	
	hdc = BeginPaint(hwnd, &ps);

	FillRect(hdc, &rectColor, (HBRUSH)(RGB(R, G, B)));
	HPEN OldPen = (HPEN)SelectObject(hdc, CreatePen(PS_SOLID, mWidth, RGB(R, G, B)));
	
	if (mShape != NULL)
		mShape->Draw(hdc, mFirts, mLast);

	SelectObject(hdc, OldPen);
	if (!mField.empty())
	{
		for (std::vector<IShape*>::iterator it = mField.begin(); it != mField.end(); ++it)
		{
			(*it)->ReDraw(hdc);
		}
	}

	EndPaint(hwnd, &ps);
}

LRESULT MainWindow::RealDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		HANDLE_MSG(hWnd, WM_INITDIALOG, Cls_OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, Cls_OnCommand);
		HANDLE_MSG(hWnd, WM_DESTROY, Cls_OnDestroy);
		HANDLE_MSG(hWnd, WM_PAINT, Cls_OnPaint);
		HANDLE_MSG(hWnd, WM_HSCROLL, Cls_OnHScroll);
		HANDLE_MSG(hWnd, WM_LBUTTONDOWN, Cls_OnLButtonDown);
		HANDLE_MSG(hWnd, WM_MOUSEMOVE, Cls_OnMouseMove);
		HANDLE_MSG(hWnd, WM_LBUTTONUP, Cls_OnLButtonUp);
	}
	return BaseWindow::RealDlgProc(hWnd, uMsg, wParam, lParam);
}
