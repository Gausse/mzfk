#ifndef _TESTA_H_
#define _TESTA_H_

#include "base.h"

class TestA : public BaseMult
{
public:
   virtual int mult(int a, int b);
//    int div(int a, int b);
//    int sum(int a, int b);
//    int sub(int a, int b);
};

class TestAA: public TestA
{
public:
    int mult(int a, int b);
};

#endif //_TESTA_H_
