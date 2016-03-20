#ifndef _CLIENT_H
#define _CLIENT_H

#include "base.h"

class Client
{
protected:
    BaseMult* p_Mult;
public:
    Client(): p_Mult(nullptr){}
    ~Client() {}
    void SetMult(BaseMult* bm);
    int Work(int a, int b);
};

class Client2 : public Client
{
public:
    Client2(BaseMult* bm)
    {
        p_Mult = bm;
    }
};

#endif  //_CLIENT_H
