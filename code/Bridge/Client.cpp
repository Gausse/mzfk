#include "Client.h"

void Client::SetMult(BaseMult *bm)
{
    p_Mult = bm;
}

int Client::Work(int a, int b)
{
    return p_Mult->mult(a,b);
}
