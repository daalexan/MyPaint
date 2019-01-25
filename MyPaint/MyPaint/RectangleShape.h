#pragma once
#include "IShape.h"

class RectangleShape : public IShape
{
public:
	RectangleShape();
	RectangleShape(HPEN Pen, POINT First, POINT Last);
	~RectangleShape();
	void Draw(HDC hdc, POINT First, POINT Last);
	void ReDraw(HDC hdc);

};

