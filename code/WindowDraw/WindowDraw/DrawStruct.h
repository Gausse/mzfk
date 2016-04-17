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

struct FigureV1 : public Figure
{
	COLORREF brush;
	COLORREF canvas;
};

struct FigureV2 : public FigureV1
{
	int l_width;
};

class DrawBase
{
public:
	virtual void destroy() = 0;
	virtual void addData(Figure *data) = 0;
	virtual void drawData(HDC& hDC) = 0;
};

class DrawStruct : public DrawBase
{
	std::vector<Figure> m_fig;
public:
	DrawStruct();
	~DrawStruct();
	void destroy();
	void addData(Figure *data);
	void drawData(HDC& hDC);
};

class DrawStructV1 : public DrawBase
{
	std::vector<FigureV1> m_fig;
public:
	DrawStructV1();
	~DrawStructV1();
	void destroy();
	void addData(Figure *data);
	void drawData(HDC& hDC);
};