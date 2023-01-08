#include "vector.hpp"
#include <iostream>
#include <vector>

int main()
{
//    std::vector<int> veto;

    ft::vector<int> vec(5);
    vec.push_back(10);
    vec.push_back(10);
    vec.push_back(10);

    std::cout << vec.size() << std::endl << vec.capacity() << std::endl;
}