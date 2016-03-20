#ifndef A_H
#define A_H

#include "core.h"

class A
{
    int ma;
public:
    A(int a): ma(a)
    {
        std::cout << "A constructor " << this << std::endl;
    }
    ~A()
    {
        std::cout << "A destructor " << this << std::endl;
    }
//    virtual void destroy() = 0;

    virtual void show();
};

#endif // A_H
