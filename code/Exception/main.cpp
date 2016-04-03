#include <iostream>
#include <string>
#include <stdio.h>

struct Obj
{
    int a;
    Obj() : a(0)
    {
        std::cout << "Obj const" << " This " << this << std::endl;
    }
    Obj(const Obj & ta) :a(ta.a)
    {
        std::cout << "Obj copy const" << " This " << this << " Original " << &ta << std::endl;
    }
    ~Obj()
    {
        std::cout << "Obj dest" << " This " << this << std::endl;
    }
};

int main()
{
//    int a;
//    try
//    {
//        while (true)
//        {
//            try
//            {
//                std::cin >> a;
//                if (a >= 5)
//                    throw a;
//                if (a <= 4)
//                    throw "ZERO";
//            }
//            catch (int exception)
//            {\
//                if (exception == 9)
//                {
//                    throw;
//                }
//                std::cout << "Exception " << exception << std::endl;
//            }
//            catch (const char* exception)
//            {
//                std::cout << "Exception " << exception << std::endl;
//            }
//            catch(...)
//            {
//                std::cout << "I cannot handle this shit." << std::endl;
//            }
//        }
//    }
//    catch (int some)
//    {
//        std::cout << "Last exception " << some << std::endl;
//    }

    try
    {
        Obj a;
        throw a;
    }
    catch(Obj& a)
    {
        std::cout << "Exception " << a.a << std::endl;
    }
    catch(...)
    {
        std::cout << "Some exception" << std::endl;
    }

    return 0;
}

