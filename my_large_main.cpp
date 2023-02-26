
#include "vector.hpp"
#include <vector>

#include "map.hpp"
#include <map>

#include "set.hpp"
#include <set>

#include "stack.hpp"
#include <stack>

#include <algorithm>
#include <memory>

#ifndef CHOICE 
#define CHOICE 1
#endif
#if CHOICE
    #define vector ft::vector
    #define map ft::map
    #define set ft::set
    #define stack ft::stack
#else
    #define ft std
    #define vector std::vector
    #define map std::map
    #define set std::set
    #define stack std::stack
#endif

template<typename I_T, class con>
void print_it( con cont)
{
    for(I_T it = cont.begin(); it != cont.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}
template<typename R_T, class con>
void print_irt( con cont)
{
    for(R_T it = cont.rbegin(); it != cont.rend(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template<typename I_T, class con>
void mprint_it( con cont)
{
    for(I_T it = cont.begin(); it != cont.end(); it++)
        std::cout << "(" <<it->first << "," << it->second << ")" << " ";
    std::cout << std::endl;
}
template<typename R_T, class con>
void mprint_irt( con cont)
{
    for(R_T it = cont.rbegin(); it != cont.rend(); it++)
        std::cout << "(" <<it->first << "," << it->second << ")" << " ";
    std::cout << std::endl;
}

void vector_test()
{
    std::cout << "testing constructors: \n";
    vector<int> vec;
    std::allocator<int> alloc;
    vector<int> vec2(alloc);

    vec2.push_back(15);
    vec2.push_back(15);
    vec2.push_back(15);
    vec2.push_back(15);
    vec2.push_back(15);
    vec2.push_back(15);


    std::cout << "VEC  ::::" << "capacity : " << vec.capacity() << " size: " << vec.size() << " max_size: " << vec.max_size() << std::endl;
    std::cout << "VEC2 ::::" << "capacity : " << vec2.capacity() << " size: " << vec2.size() << " max_size: " << vec2.max_size() << std::endl;

    std::cout << "testing destructo: \n";

    vector<int> vec3(vec2.begin(), vec2.end());
    vector<int> vec4; vec4 = vec3;

    std::cout << "VEC3 ::::" << "capacity : " << vec3.capacity() << " size: " << vec3.size() << " max_size: " << vec3.max_size() << std::endl;
    std::cout << "VEC4 ::::" << "capacity : " << vec4.capacity() << " size: " << vec4.size() << " max_size: " << vec4.max_size() << std::endl;

    std::cout << "assigning : \n";
    vec.assign(10, 100);
    vec2.assign(20, 60);
    vec3.assign(vec2.begin(), vec2.end());

    std::cout << "VEC  ::::" << "capacity : " << vec.capacity() << " size: " << vec.size() << " max_size: " << vec.max_size() << std::endl;
    print_it<vector<int>::iterator, vector<int> >(vec);
    std::cout << "VEC2 ::::" << "capacity : " << vec2.capacity() << " size: " << vec2.size() << " max_size: " << vec2.max_size() << std::endl;
    print_it<vector<int>::iterator, vector<int> >(vec2);
    std::cout << "VEC3 ::::" << "capacity : " << vec3.capacity() << " size: " << vec3.size() << " max_size: " << vec3.max_size() << std::endl;
    print_it<vector<int>::iterator, vector<int> >(vec3);

    std::cout << "Element access: \n";
    std::cout << "at 5: " << vec2.at(5) << " "<< std::endl;;
    std::cout << "at 2: " << vec.at(2) << " "<< std::endl;;
    std::cout << "[" <<vec3[10] <<"]" << std::endl;;
    std::cout << "back: " << vec.back() << " "<< std::endl;;
    std::cout << "front: " << vec.front() << " "<< std::endl;;
    std::cout << "data at 2: " << vec.data()[2] << " "<< std::endl;;

    std::cout << "Iterators: \n";

    std::cout << "printing content using normal iterators\n";
    print_it<vector<int>::iterator, vector<int> >(vec2);

    std::cout << "printing content using reverse iterators\n";
    print_irt<vector<int>::reverse_iterator, vector<int> >(vec2);

    std::cout << "Capacity: ";
    {
        vector<int> test;
        std::cout << test.empty() << " ";
    }
    std::cout << vec.empty() << " " << vec.size() << " " << vec.capacity() << " " << vec.max_size() << std::endl;
    vec.reserve(100);
    std::cout << "after reverse: \n";
    std::cout << vec.empty() << " " << vec.size() << " " << vec.capacity() << " " << vec.max_size() << std::endl;
    std::cout << "clearing vec2: ";
    std::cout << vec2.empty() << " " << vec2.size() << " " << vec2.capacity() << " " << vec2.max_size() << std::endl;
    vec2.clear();
    std::cout << "after clearing: ";

    std::cout << "inserting: \n";
    vec2.insert(vec2.begin(), 99);
    vec2.insert(vec2.begin(), 5, 46);
    vec2.insert(vec2.begin(), vec3.begin(), vec3.end());

    print_it<vector<int>::iterator, vector<int> >(vec2);
    std::cout << "erasing: \n";
    vec2.erase(vec2.begin() + 2);
    print_it<vector<int>::iterator, vector<int> >(vec2);
    vec2.erase(vec2.begin(), vec2.end());
    std::cout << vec2.empty() << " " << vec2.size() << " " << vec2.capacity() << " " << vec2.max_size() << std::endl;
    std::cout << "poping back: \n";
    std::cout << "VEC3 ::::" << "capacity : " << vec3.capacity() << " size: " << vec3.size() << " max_size: " << vec3.max_size() << std::endl;
    vec3.pop_back();
    std::cout << "VEC3 ::::" << "capacity : " << vec3.capacity() << " size: " << vec3.size() << " max_size: " << vec3.max_size() << std::endl;
    std::cout << "resizing: \n";
    vec2.resize(1000);
    std::cout << vec2.empty() << " " << vec2.size() << " " << vec2.capacity() << " " << vec2.max_size() << std::endl;
    std::cout << "swaping: \n";
    std::cout << "VEC3 ::::" << "capacity : " << vec3.capacity() << " size: " << vec3.size() << " max_size: " << vec3.max_size() << std::endl;
    print_it<vector<int>::iterator, vector<int> >(vec3);
    std::cout << "VEC2 ::::" << "capacity : " << vec2.capacity() << " size: " << vec2.size() << " max_size: " << vec2.max_size() << std::endl;
    print_it<vector<int>::iterator, vector<int> >(vec2);
    vec2.swap(vec3);
    std::cout << "VEC3 ::::" << "capacity : " << vec3.capacity() << " size: " << vec3.size() << " max_size: " << vec3.max_size() << std::endl;
    print_it<vector<int>::iterator, vector<int> >(vec3);
    std::cout << "VEC2 ::::" << "capacity : " << vec2.capacity() << " size: " << vec2.size() << " max_size: " << vec2.max_size() << std::endl;
    print_it<vector<int>::iterator, vector<int> >(vec2);
    ft::swap(vec3, vec2);
    std::cout << "VEC3 ::::" << "capacity : " << vec3.capacity() << " size: " << vec3.size() << " max_size: " << vec3.max_size() << std::endl;
    print_it<vector<int>::iterator, vector<int> >(vec3);
    std::cout << "VEC2 ::::" << "capacity : " << vec2.capacity() << " size: " << vec2.size() << " max_size: " << vec2.max_size() << std::endl;
    print_it<vector<int>::iterator, vector<int> >(vec2);
    std::cout << "are equal : " << (vec == vec2) << " not equal: " << (vec3 != vec4) << " is greater:" << (vec > vec3) << " is lesser: " << (vec2 < vec4) << std::endl;
}
void map_test()
{
    map<int, int> m;
    vector<ft::pair<const int, int> > vec;
    for(int i = 0; i < 10; i++)
        vec.push_back(ft::make_pair(i, i+13));
    map<int, int> m2(vec.begin(), vec.end());
    map<int, int> m3(m2);
    std::cout << "m: ";
    mprint_it<map<int, int>::iterator, map<int, int> >(m);
    m = m3;
    std::cout << "m2: ";
    mprint_it<map<int, int>::iterator, map<int, int> >(m2);
    std::cout << "m3: ";
    mprint_it<map<int, int>::iterator, map<int, int> >(m3);
    std::cout << "m: ";
    mprint_it<map<int, int>::iterator, map<int, int> >(m);

    std::cout << "test at" << m.at(5) << std::endl;
    std::cout << "test at 2 [" << m[2]<<"]" << std::endl;

    std::cout << "Iterators: \n";
    std::cout << "printing using normal iterators: \n";
    mprint_it<map<int, int>::iterator, map<int, int> >(m);
    std::cout << "printing using reverse iterators: \n";
    mprint_irt<map<int, int>::reverse_iterator, map<int, int> >(m);

    std::cout << "Capacity: \n";
    std::cout << m.empty

}
int main()
{
    map_test();
}