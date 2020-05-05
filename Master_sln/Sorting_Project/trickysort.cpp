#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <functional>

template <typename T>
struct sorter :
    public std::binary_function<T, T, bool>
{
    bool operator() (const T& a, const T& b) const
    {
        T aa = a % 10, bb = b % 10;
        if (aa != bb)
            return aa < bb;
        else
            return a < b;
    }
};

int main()
{
    unsigned int size;
    std::cout << "Enter the N" << std::endl;
    std::cin >> size;

    std::vector<int> vector(size);

    std::cout << "Enter the vector" << std::endl;
    for (std::vector<int>::iterator i = vector.begin(), end = vector.end(); i != end; ++i)
        std::cin >> *i;

    std::sort(vector.begin(), vector.end(), sorter<int>());

    std::copy(vector.begin(), vector.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
