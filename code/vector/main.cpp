#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vi;
    for(int i = 0; i < 20; ++i)
    {
        vi.push_back(i);
    }

    for(auto i : vi)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    std::vector<int>::iterator it5, it17;

    it5 = std::find(vi.begin(), vi.end(), 5);

    std::cout << *it5 << std::endl;

    it17 = std::find(vi.begin(), vi.end(), 17);

    std::cout << *it17 << std::endl;

    std::vector<int> vi2(std::distance(it5, it17+1));

    std::copy(it5, it17+1, vi2.begin());

    for(auto i : vi2)
    {
        std::cout << i << " ";
    }

    return 0;
}

