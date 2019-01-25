#include "Line.h"

Line::Line()
{
}

Line::Line(HPEN Pen, POINT First, POINT Last)
{
	hPen = Pen;
	mFirst = First;
	mLast = Last;
}


Line::~Line()
{
}

void Line::Draw(HDC hdc, POINT First, POINT Last)
{
	HPEN OldPen = (HPEN)SelectObject(hdc, hPen);
	MoveToEx(hdc, First.x, First.y, NULL);
	LineTo(hdc, Last.x, Last.y);
	SelectObject(hdc, OldPen);
}

void Line::ReDraw(HDC hdc)
{
	HPEN OldPen = (HPEN)SelectObject(hdc, hPen);
	MoveToEx(hdc, mFirst.x, mFirst.y, NULL);
	LineTo(hdc, mLast.x, mLast.y);
	SelectObject(hdc, OldPen);
}
