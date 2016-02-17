#include <iostream>
#include <cstring>

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

void init(double* pDoubleArray, int nSize)
{
    for (int i = 0; i < nSize; ++i )
    {
        pDoubleArray[i] = fRand(0.0, 200.0);
    }
}

template <typename T>
void init(T* pArray, int nSize)
{
    for (int i = 0; i < nSize; ++i )
    {
        pArray[i] = rand() % 200 + 1;
    }
}

template <typename T>
void sort(T *pArr, int nSize, bool(*pFn)(T&, T&))
{
    T nMin;
    int iMinInd;
    for (int i = 0; i < nSize; ++i)
    {
        nMin = pArr[i];
        iMinInd = i;
        for (int j = i + 1; j < nSize; ++j)
        {
            if (pFn(pArr[j], nMin))
            {
                nMin = pArr[j];
                iMinInd = j;
            }

        }
        pArr[iMinInd] = pArr[i];
        pArr[i] = nMin;
    }
}

template <typename T>
void show(T *pArray, int Size) {
    for (int i = 0; i < Size; ++i)
        std::cout << pArray[i] << ' ';

    std::cout << std::endl;
}

template <typename T>
bool Asc(T &p1, T &p2)
{
    return p1 < p2;
}

template <typename T>
bool Desc(T &p1, T &p2)
{
    return p1 > p2;
}

int main()
{
    int iArrSize = 0;

    std::cout << "Enter size of Array: " << std::endl;
    std::cin >> iArrSize;

    int* pIntArr = new int[iArrSize];
    char* pCharArr = new char[iArrSize];
    double* pDoubleArr = new double[iArrSize];

    init(pIntArr, iArrSize);
    init(pCharArr, iArrSize);
    init(pDoubleArr, iArrSize);

    std::cout << "Int array" << std::endl;
    show(pIntArr, iArrSize);
    std::cout << "Char array" << std::endl;
    show(pCharArr, iArrSize);
    std::cout << "Double array" << std::endl;
    show(pDoubleArr, iArrSize);

    sort(pIntArr, iArrSize, Asc);
    sort(pCharArr, iArrSize, Asc);
    sort(pDoubleArr, iArrSize, Asc);

    std::cout << "Int array" << std::endl;
    show(pIntArr, iArrSize);
    std::cout << "Char array" << std::endl;
    show(pCharArr, iArrSize);
    std::cout << "Double array" << std::endl;
    show(pDoubleArr, iArrSize);

    return 0;
}
