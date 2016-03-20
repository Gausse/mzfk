#ifndef B_H
#define B_H

#include "a.h"
#include "core.h"

class B : public A
{
    int mb;
public:
    B(int a, int b) : A(a), mb(b)
    {
        std::cout << "B constructor " << this << std::endl;
    }
    ~B()
    {
        std::cout << "B destructor " << this << std::endl;
    }

    void destroy()
    {
        std::cout << "destroy B" << std::endl;
        delete this;
    }

    void show();
};

#endif // B_H
