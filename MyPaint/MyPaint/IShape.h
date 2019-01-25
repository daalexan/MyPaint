#pragma once
#include "stdafx.h"

class IShape
{
protected:
	POINT mFirst;
	POINT mLast;
	HPEN hPen;
public:
	virtual void Draw(HDC hdc, POINT First, POINT Last) = 0;
	virtual void ReDraw(HDC hdc) = 0;
	IShape();
	IShape(POINT First, POINT Last);
	virtual ~IShape();
};

