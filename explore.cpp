#include <vector>
#include <iterator>
#include <iostream>
#include "vector.hpp"

int main()
{
    ft::vector<int> vec2;
    std::vector<int> vec3;
    for (int i = 0; i < 10; i++)
        vec3.push_back(i);
    vec2.push_back(1);
    vec2.push_back(9);
    vec2.push_back(9);
    ft::vector<int>::iterator it;
    ft::vector<int>::const_iterator ic;

    it = vec2.begin();
    vec2.insert(it + 2, vec3.begin(), vec3.end());
    vec2.erase(vec2.begin() + 3, vec2.end());
    it = vec2.begin();
    // for (ft::vector<std::string>::iterator it = vec2.begin(); it != vec2.end(); it++)
    for (ft::vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++)
    {
        std::cout << *it << std::endl;
    }

//     std::vector<int> vec2;
//     std::vector<int> vec3;
//     for (int i = 0; i < 10; i++)
//         vec3.push_back(i);
//      vec2.push_back(1);
//     vec2.push_back(9);
//     vec2.push_back(9);
//     std::vector<int>::iterator it;
//     std::vector<int>::const_iterator ic;

//     it = vec2.begin();
//     vec2.insert(it + 2, vec3.begin(), vec3.end());
//     // for (int j = 0; j < 10; j++)
//         vec2.erase(vec2.begin() + 3, vec2.end());
//     it = vec2.begin();
//     // for (ft::vector<std::string>::iterator it = vec2.begin(); it != vec2.end(); it++)
//     for (std::vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++)
//     {
//         std::cout << *it << std::endl;
//     }
}
