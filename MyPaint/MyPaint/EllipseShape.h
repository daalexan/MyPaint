#pragma once
#include "IShape.h"

class EllipseShape : public IShape
{
public:
	EllipseShape();
	EllipseShape(HPEN Pen, POINT First, POINT Last);
	~EllipseShape();
	void Draw(HDC hdc, POINT First, POINT Last);
	void ReDraw(HDC hdc);
};

