#include <iostream>

#include "core.h"
#include "smartptr.hpp"

int main()
{
    SmartPtr<A> sh(new A());
    sh->show();
    SmartPtr<A> sh1(sh);
    sh1->show();
    SmartPtr<A> sh2;
    return 0;
}

