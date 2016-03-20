#include "core.h"
#include "Client.h"
#include "TestA.h"
#include "TestB.h"

int main()
{
    Client cl;
    TestA ta;

    Client2 cl2(&ta);
    TestB tb;
    TestAA taa;

    cl2.SetMult(&ta);
    std::cout << "Client use TestA " << cl2.Work(1,2) << std::endl;
    cl2.SetMult(&taa);
    std::cout << "Client use TestB " << cl2.Work(1,2) << std::endl;
    return 0;
}

