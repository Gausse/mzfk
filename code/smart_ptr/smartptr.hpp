#ifndef SMARTPTR_H
#define SMARTPTR_H

#include "core.h"

template <class T>
class SmartPtr
{
    int* count;
    T* addr;
public:
    SmartPtr() : count(NULL), addr(NULL)
    {
        std::cout << "Smart ptr without data " << this << std::endl;
    }
    SmartPtr(T* data) : count(NULL), addr(data)
    {
        count = new int;
        *count = 1;
        std::cout << "Smart ptr " << this << " with count " << *count << std::endl;
    }
    SmartPtr(SmartPtr &smrt_ptr) : count(smrt_ptr.count), addr(smrt_ptr.addr)
    {
        ++(*count);
        std::cout << "SmartPtr with addr " << addr
                  << " with count "
                  << *count << std::endl;
    }
    ~SmartPtr()
    {
        std::cout << "Destr SmartPtr " << this << std::endl;
        if ( count != NULL && addr != NULL )
            if (--(*count) == 0)
            {
                delete count;
                delete addr;
            }
    }
    T* operator->()
    {
        return addr;
    }
};

class A
{
    int num;
public:
    A()
    {
        std::cout << "A created" << std::endl;
        num = 0;
    }
    ~A()
    {
        std::cout << "A deleted" << std::endl;
    }
    void show()
    {
        std::cout << "ohoho" << std::endl;
    }
};

#endif // SMARTPTR_H
