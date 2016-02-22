#ifndef _LINE_
#define _LINE_

#include "core.h"


//float point
struct fPoint
{
    double x;
    double y;
    fPoint(double a, double b) : x(a), y(b){}
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
