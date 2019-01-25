#pragma once
#include "IShape.h"

class Line : public IShape
{
public:
	Line();
	Line(HPEN Pen, POINT First, POINT Last);
	~Line();
	void Draw(HDC hdc, POINT First, POINT Last);
	void ReDraw(HDC hdc);
};

