#include "stdafx.h"
#include "DrawStruct.h"


DrawStruct::DrawStruct()
{
}


DrawStruct::~DrawStruct()
{
}

void DrawStruct::addFigure(Figure buf)
{
	this->m_fig.push_back(buf);
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