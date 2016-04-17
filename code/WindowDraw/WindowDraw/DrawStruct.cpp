#include "stdafx.h"
#include "DrawStruct.h"


DrawStruct::DrawStruct()
{
}


DrawStruct::~DrawStruct()
{
}

void DrawStruct::destroy()
{
	delete this;
}

void DrawStruct::addData(Figure *data)
{
	m_fig.push_back(*data);
}

void DrawStruct::drawData(HDC& hDC)
{
	for (int index = 0; index < this->m_fig.size(); ++index)
	{
		Figure temp = m_fig[index];
		switch (temp.m_rDrawKind)
		{
		case E_RECTANGLE:
			{
				Rectangle(hDC, 
					temp.m_x - temp.nShift, 
					temp.m_y - temp.nShift, 
					temp.m_x + temp.nShift, 
					temp.m_y + temp.nShift);
			}
			break;
		}
	}
}


DrawStructV1::DrawStructV1()
{
}


DrawStructV1::~DrawStructV1()
{
}

void DrawStructV1::destroy()
{
	delete this;
}

void DrawStructV1::addData(Figure *data)
{
	m_fig.push_back(*((FigureV1*)data));
}

void DrawStructV1::drawData(HDC& hDC)
{
	for (int index = 0; index < m_fig.size(); ++index)
	{
		FigureV1 temp = m_fig[index];
		HBRUSH temp_brush = CreateSolidBrush(temp.brush);
		HPEN   temp_pen   = CreatePen(PS_SOLID, 2, temp.canvas);
		HBRUSH old_b = (HBRUSH)SelectObject(hDC, temp_brush);
		HPEN   old_p = (HPEN)  SelectObject(hDC, temp_pen);

		switch (temp.m_rDrawKind)
		{
		case E_RECTANGLE:
		{
			Rectangle(hDC,
				temp.m_x - temp.nShift,
				temp.m_y - temp.nShift,
				temp.m_x + temp.nShift,
				temp.m_y + temp.nShift);
		}
		break;
		}

		SelectObject(hDC, old_b);
		SelectObject(hDC, old_p);

		DeleteObject(temp_brush);
		DeleteObject(temp_pen);
	}
}