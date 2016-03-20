#include "a.h"
#include "b.h"
#include "core.h"

void destroyA(A* tmp)
{
    tmp->destroy();
}

int main()
{
//    A a(5);
//    B b(2,3);
//    A* pA = &b;
//    B* pB = (B*) &a;
    {
//        A* a1 = new A(5);
        std::shared_ptr<A> sh(new B(2,3), destroyA);
    }
//    A* ptr = new B(2,3);
//    ptr->destroy();


//    pA->show();
//    pB->show();

    return 0;
}

