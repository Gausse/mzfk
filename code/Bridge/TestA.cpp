#include "TestA.h"

int TestA::mult(int a, int b)
{
   return a*b*10;
}

int TestAA::mult(int a, int b)
{
    return TestA::mult(a,b);
}
