#include <vector>
#include <iterator>
#include <iostream>
#include "vector.hpp"

void f(volatile int &x)
{
    std::cout << x << " lvalue" << std::endl;
}

int main()
{
    int num;

    num = 100;
    f(num);
    // ft::vector<int> vec;
    // ft::vector<int>::iterator it;
    // std::vector<std::string> vec2;
    // std::vector<std::string>::iterator it2;
    // // ft::vector<std::string> vec2;
    // // ft::vector<std::string>::iterator it2;

    // vec.push_back(1);
    // vec.push_back(9);
    // vec.push_back(9);
    // vec.push_back(9);
    // vec.insert();

    // for (ft::vector<std::string>::iterator it = vec2.begin(); it != vec2.end(); it++)
    // for (std::vector<std::string>::iterator it = vec2.begin(); it != vec2.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }
}
