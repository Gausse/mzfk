#include"Line.h"

#include <iostream>

int main()
{

    iLine l1(1,2,3,4);
    iLine l2(2,7,15,7);
    std::cout << l1.isParallel(l2) << std::endl;

    return 0;
}
