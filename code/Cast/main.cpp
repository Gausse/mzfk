#include "classes.h"
#include <typeinfo>

void test(A* ptr)
{
    std::cout << typeid(*ptr).name() << std::endl;
    B* temp_B = dynamic_cast<B*> (ptr);
    if (temp_B != NULL)
    {
        temp_B->work();
        return;
    }


    C* temp_C = dynamic_cast<C*> (ptr);
    if (temp_C != NULL)
    {
        temp_C->foo();
        return;
    }
}

void testR(A& ptr)
{
    try
    {
        B& temp_B = dynamic_cast<B&> (ptr);
        temp_B.work();
    }
    catch(std::bad_cast bc)
    {
        std::cout << bc.what() << std::endl;
    }

    try
    {
        C& temp_C = dynamic_cast<C&> (ptr);
        temp_C.foo();
    }
    catch(std::bad_cast bc)
    {
        std::cout << bc.what() << std::endl;
    }
}

int main()
{
    C ptr;

    testR(ptr);

    A* bb = new A();


    B* cc = static_cast<B*>(bb);
    cc->work();
    std::cout << cc << std::endl;
    D dd(5);
    std::cout << (int)dd << std::endl;
    int temp = static_cast<int> (dd);
    std::cout << temp << std::endl;
    E* tt = reinterpret_cast<E*> (&dd);
    std::cout << tt->get() << std::endl;
    std::cout << (const char*)dd << std::endl;

    B tratata = static_cast<B> (dd);
    return 0;
}

