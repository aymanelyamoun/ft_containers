#include "red_black_tree2.hpp"
#include <iostream>

/*
#include <map>
#include "vector.hpp"
#include <fstream>
#include <vector>

struct test
{
    int k;

    test(int i){
        k = i;
    }
    bool operator<(const test & obj) const {
        return this->k < obj.k;
    }
};

int main()
{
    std::fstream file("old.hpp");


    std::vector<char> safasf((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
    std::cout << "---- File Content:  ----" << std::endl;
    for (std::size_t i = 0; i < safasf.size(); i++)
        std::cout << safasf[i];
    std::cout << safasf.size() << " " << safasf.capacity() << std::endl;
}*/

struct test
{
    int memeber1;
    int memeber2;

    test(): memeber1(63), memeber2(63) {}
    test(int num): memeber1(num), memeber2(num + 10){}
    bool operator<(test const &obj) const {return this->memeber1 < obj.memeber1;}
};

#include <string>
// #include <set>
    int main() 
    {
        RBTree<test> t;
        RBTree<test>::iterator it;
        RBTree<test>::reverse_iterator rit;
        int input;
        long long i = 0;
        while(1)
        {
            std::cin >> input;
            if (input == 1)
            {
                std::cin >> input;
                t.insert(test(input));
            }
            else if (input == 2)
            {
                std::cin >> input;
                t.delete_(test(input));
            }
            else if (input == 3)
                break;
            // t.inorderTraversal();
            i++;
            // t.printTree();
        }
        // RBTree<test>::const_iterator it;
        std::cout << "reverse iterating: \n";
        rit = t.rbegin();
        for (; rit != t.rend(); rit++)
            std::cout << rit->memeber1 << " " << rit->memeber2 << std::endl;
        std::cout << "end of reverse iterating; \n";
        it = t.begin();
        for (; it != t.end(); it++)
        {
            // it++;
            it->memeber1 = 63;
            std::cout << it->memeber1 << " " << it->memeber2 << std::endl;
        }
        std::cout << it->memeber1;
    }

// int main() {
// std::string name = "gklnrgk";
// //    RBTree<std::pair<char, int> > tree;
//    RBTree<std::pair<int, int> > tree2;
// //    std::cout << typeid(tree).name() << "\n";
//    std::cout << typeid(tree2).name() << "\n"; 
// //    tree.insert(std::make_pair(test(10), 10));
// }