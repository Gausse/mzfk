#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <memory>

struct Params
{
    std::shared_ptr<int> sp;
    int mSize;
    int mult;
    HANDLE* mhandler;
    Params(std::shared_ptr<int> sh, int size, int multt, HANDLE* hand) : sp(sh), mSize(size), mult(multt), mhandler(hand){}
};

DWORD WINAPI ThF(void *pV)
{
    std::shared_ptr<Params> sh((Params*) pV);
    std::cout << "First thread" << std::endl;
    for(int i = 0; i < sh->mSize; ++i)
    {
        sh->sp.get()[i]*=sh->mult;
        std::cout << sh->sp.get()[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

int main()
{
//    std::cout << "Give me size: " << std::endl;
    int size = 10;
//    std::cin >> size;
    int* array = new int[size];
    for(int i = 0; i < size; ++i)
    {
        array[i] = rand() % 100;
    }

    for (int i = 0; i < size; ++i)
    {
        int l = 0;
        int r = 0;
        for (int index = i; index < size; ++index)
        {
            if (array[index] > 50)
            {
                l = index;
                break;
            }
        }
        for (int index = size - 1; index > 0; --index)
        {
            if (array[index] <= 50)
            {
                r = index;
                break;
            }
        }

        int buf = l;
        l = r;
        r = l;
    }

//    HANDLE my_thread = CreateThread(0, 0, ThF, new Params(sh, size, 10, NULL), 0, 0);
//    HANDLE my_thread1 = CreateThread(0, 0, ThF1, new Params(sh, size, 3, &my_thread), 0, 0);

//    WaitForSingleObject(my_thread1, INFINITE);

//    std::cout << "Main thread" << std::endl;
    for(int i = 0; i < size; ++i)
    {
        std::cout <<  array[i] << " ";
    }
    std::cout << std::endl;

//    CloseHandle(my_thread);
//    CloseHandle(my_thread1);
    return 0;
}

