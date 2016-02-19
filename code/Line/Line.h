#ifndef _LINE_
#define _LINE_

#include "core.h"

//int point
struct iPoint
{
    int x;
    int y;
    iPoint(int a, int b) : x(a), y(b){}
};

//float point
struct fPoint
{
    double x;
    double y;
    fPoint(double a, double b) : x(a), y(b){}
};

//int line
class iLine
{
    iPoint m_p1;
    iPoint m_p2;
public:
    iLine(int x1, int  y1, int x2, int y2);
    iLine(iPoint p1, iPoint p2);
    bool isParallel(iLine someLine);
    void makeParallel(iLine &someLine, int xShift);
};

//float line
class fLine
{
    fPoint m_p1;
    fPoint m_p2;
public:
    fLine(double x1, double y1, double x2, double y2);
    fLine(fPoint p1, fPoint p2);
    bool isParallel(fLine someLine);
    void makeParallel(fLine &someLine, double xShift);
};

#endif // _LINE_
