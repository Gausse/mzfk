#include "Line.h"

iLine::iLine(int x1, int y1, int x2, int y2)
    : m_p1(iPoint(x1,y1)), m_p2(iPoint(x2,y2))
{

}

iLine::iLine(iPoint p1, iPoint p2) : m_p1(p1), m_p2(p2)
{

}

fLine::fLine(double x1, double y1, double x2, double y2)
    : m_p1(fPoint(x1,y1)), m_p2(fPoint(x2,y2))
{

}

fLine::fLine(fPoint p1, fPoint p2) : m_p1(p1), m_p2(p2)
{

}

bool iLine::isParallel(iLine someLine)
{
    int k1 = (this->m_p2.y - this->m_p1.y) / (this->m_p2.x - this->m_p1.x);
    int k2 = (someLine.m_p2.y - someLine.m_p1.y)
            / (someLine.m_p2.x - someLine.m_p1.x);
    return k1 == k2;
}

bool fLine::isParallel(fLine someLine)
{
    double k1 = (this->m_p2.y - this->m_p1.y) / (this->m_p2.x - this->m_p1.x);
    double k2 = (someLine.m_p2.y - someLine.m_p1.y)
            / (someLine.m_p2.x - someLine.m_p1.x);
    return k1 == k2;
}
