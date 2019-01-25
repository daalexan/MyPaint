#include "EllipseShape.h"

EllipseShape::EllipseShape()
{
}

EllipseShape::EllipseShape(HPEN Pen, POINT First, POINT Last)
{
	hPen = Pen;
	mFirst = First;
	mLast = Last;
}


EllipseShape::~EllipseShape()
{
}

void EllipseShape::Draw(HDC hdc, POINT First, POINT Last)
{
	HPEN OldPen = (HPEN)SelectObject(hdc, hPen);
	Ellipse(hdc, mFirst.x, mFirst.y, mLast.x, mLast.y);
	SelectObject(hdc, OldPen);
}

void EllipseShape::ReDraw(HDC hdc)
{
	HPEN OldPen = (HPEN)SelectObject(hdc, hPen);
	Ellipse(hdc, mFirst.x, mFirst.y, mLast.x, mLast.y);
	SelectObject(hdc, OldPen);
}

