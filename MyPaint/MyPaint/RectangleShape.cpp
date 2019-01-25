#include "RectangleShape.h"

RectangleShape::RectangleShape()
{
}

RectangleShape::RectangleShape(HPEN Pen, POINT First, POINT Last)
{
	hPen = Pen;
	mFirst = First;
	mLast = Last;
}


RectangleShape::~RectangleShape()
{
}

void RectangleShape::Draw(HDC hdc, POINT First, POINT Last)
{
	HPEN OldPen = (HPEN)SelectObject(hdc, hPen);
	Rectangle(hdc, mFirst.x, mFirst.y, mLast.x, mLast.y);
	SelectObject(hdc, OldPen);
}

void RectangleShape::ReDraw(HDC hdc)
{
	HPEN OldPen = (HPEN)SelectObject(hdc, hPen);
	Rectangle(hdc, mFirst.x, mFirst.y, mLast.x, mLast.y);
	SelectObject(hdc, OldPen);
}

