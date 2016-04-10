#pragma once
#include "stdafx.h"
//#include "WindowDraw.h"

enum SHAPE
{
	E_RECTANGLE = 0
};

struct Figure
{
	int m_x;
	int m_y;
	int nShift;
	SHAPE m_rDrawKind;
};

class DrawStruct
{
	std::vector<Figure> m_fig;
public:
	DrawStruct();
	~DrawStruct();
	void addFigure(Figure buf);
	void drawData(HDC& hDC);
};

