#ifndef _CLASSES_H_
#define _CLASSES_H_

#include <iostream>

class A
{
public:
    virtual void show()
    {
        std::cout << "Base" << std::endl;
    }
};

class B : public A
{
public:
    void work()
    {
        std::cout << "Derived B" << std::endl;
    }
};

class C : public A
{
public:
    void foo()
    {
        std::cout << "Derived C" << std::endl;
    }
};

class D
{
    int m_d;
public:
    D(int d) : m_d(d){}
    operator int()
    {
        return m_d;
    }
    operator const char*()
    {
        return "Class D mzfk";
    }
    operator B()
    {
        return B();
    }
};

class E
{
    int m_d;
public:
    E(int d) : m_d(d){}
    operator int()
    {
        return m_d;
    }
    int get()
    {
        return m_d;
    }
};

#endif // _CLASSES_H_
