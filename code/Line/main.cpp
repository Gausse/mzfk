#include"Line.h"

#include <iostream>

int main()
{
    fLine l1(1.0, 2.0, 3.0, 4.0);
    fLine l2(5.0, 3.0, 1.0, 7.0);

    if (!l1.isParallel(l2))
        l1.makeParallel(l2, 5);
    return 0;
}
