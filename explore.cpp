#include <vector>
#include <iterator>
#include <iostream>
#include "vector.hpp"

int main()
{

    // std::vector<int> vec2;
    // ft::vector<int> vec(vec2.begin(), vec2.end());
    // ft::vector<int> vec3(10, 5);
    // std::vector<std::string>::iterator it2;
    // // ft::vector<std::string> vec2;
    // // ft::vector<std::string>::iterator it2;

    // vec.push_back(1);
    // vec.push_back(9);
    // vec.push_back(9);
    // vec.push_back(9);
    // vec.insert();
    ft::vector<int> vec2;
    vec2.push_back(1);
    vec2.push_back(9);
    vec2.push_back(9);
    ft::vector<int>::iterator it;
    ft::vector<int>::const_iterator ic;

    it = vec2.begin();
    vec2.insert(it + 2, 5, 5);
    it = vec2.begin();
    // for (ft::vector<std::string>::iterator it = vec2.begin(); it != vec2.end(); it++)
    for (ft::vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}
