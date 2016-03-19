#include "core.h"
#include "List.hpp"

bool compare(int a, int b)
{
    return a == b;
}

bool desc(int a, int b)
{
    return a > b;
}

void shower(int a)
{
    std::cout << a << " " << std::endl;
}

int main()
{
    List<int> lt;
    for(int index = 0; index < 10; ++index)
        lt.push_back(index);


    lt.insert(15, 5);

    lt.remove(5);

    lt.sort(desc);

    lt.show(shower);
    return 0;
}

