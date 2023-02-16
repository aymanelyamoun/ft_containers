#include <vector>
#include "map.hpp"
#include <iterator>
#include <iostream>
// #include "vector.hpp"
#include <stack>
#include <map>
#include "pair.hpp"

class A
{
public:
  int a;
//   A(): a(100) {; std::cout << "A::A()" << std::endl; }
  A(const A&) { std::cout << "A::A(const A&)" << std::endl; }
  ~A() { std::cout << "A::~A()" << std::endl; }
};

#include <cassert>
#include <iostream>
#include <map>
 
// Example module 97 key compare function
struct ModCmp {
    bool operator()(const int lhs, const int rhs) const
    {
        return (lhs % 97) < (rhs % 97);
    }
};
#include <iostream>
#include <map>

// int main() {
//     ft::map<std::string, int> my_map;
//     my_map["foo"] = 42;
//     my_map["bar"] = 1337;
//     my_map["baz"] = 3;

//     // Find the iterator to the element with key "bar"
//     ft::map<std::string, int>::const_iterator it = my_map.find("bar");

//     if (it != my_map.end()) {
//         std::cout << "Found the element with key 'bar' and value " << it->second << std::endl;
//     } else {
//         std::cout << "Could not find the element with key 'bar'" << std::endl;
//     }

//     return 0;
// }


int main()
{
	ft::map<int, int> m;
	std::pair<int, int> p(50, 69);
    int input;

	while(1)
	{
		std::cin >> input;
		if (input == 1)
		{
			std::cin >> input;
			p = std::pair<const int, int>(input, input + 10);
			// m.insert(p);
			m.insert(m.begin(), p);
			// m.insert(p, 'a');
			// v.push_back(p);
			// pos = m.insert(pos,p);
			// m.print();
		}
		else if (input == 2)
		{
			for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
			{
				// m.insert(p);
				std::cout << "( " << it->first << " " << it->second << " ) ";
			}
            std::cout << std::endl;
			std::cin >> input;
			// std::cout << "next : " << m.erase(m.find(input))->first << std::endl;
			// m.delete_(p);
		}
		else if (input == 3)
			break;
	}
	std::cin >> input;

	ft::map<int, int>::const_iterator it = m.find(input);
	std::cout << it->first << it->second;
	for (ft::map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        // m.insert(p);
		// it->second = 100;
        std::cout << "( " << it->first << " " << it->second << " )";
    }
}
/*
int main()
{
    ft::map<int, int> m;
    std::map<int, int> m2;
	std::pair<int, int> p(50, 69);
    int input;

    while(1)
	{
		std::cin >> input;
		if (input == 1)
		{
			std::cin >> input;
			p = std::pair<const int, int>(input, input + 10);
			// m.insert(p);
			m.insert(m.begin(), p);
			// m.insert(p, 'a');
			// v.push_back(p);
			// pos = m.insert(pos,p);
			// m.print();
		}
		else if (input == 2)
		{
			for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
			{
				// m.insert(p);
				std::cout << "( " << it->first << " " << it->second << " ) ";
			}
            std::cout << std::endl;
			std::cin >> input;
			std::cout << "next : " << m.erase(m.find(input))->first << std::endl;
			// m.delete_(p);
		}
		else if (input == 3)
			break;
	}

	for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        // m.insert(p);
        std::cout << "( " << it->first << " " << it->second << " )";
    }

	std::cout <<std::endl << "m  : " << m.max_size() << std::endl;
	std::cout <<std::endl << "m2 : " << m2.max_size() << std::endl;
}
*/
/* swap

int main()
{
    ft::map<int, int> m;
    ft::map<int, int> m2;
	std::pair<int, int> p(50, 69);
    int input;

    while(1)
	{
		std::cin >> input;
		if (input == 1)
		{
			std::cin >> input;
			p = std::pair<const int, int>(input, input + 10);
			// m.insert(p);
			m.insert(m.begin(), p);
			// m.insert(p, 'a');
			// v.push_back(p);
			// pos = m.insert(pos,p);
			// m.print();
		}
		else if (input == 2)
		{
			for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
			{
				// m.insert(p);
				std::cout << "( " << it->first << " " << it->second << " ) ";
			}
            std::cout << std::endl;
			std::cin >> input;
			std::cout << "next : " << m.erase(m.find(input))->first << std::endl;
			// m.delete_(p);
		}
		else if (input == 3)
			break;
	}
    while(1)
	{
		std::cin >> input;
		if (input == 1)
		{
			std::cin >> input;
			p = std::pair<const int, int>(input, input + 10);
			// m.insert(p);
			m2.insert(m.begin(), p);
			// m.insert(p, 'a');
			// v.push_back(p);
			// pos = m.insert(pos,p);
			// m.print();
		}
		else if (input == 2)
		{
			for (ft::map<int, int>::iterator it = m2.begin(); it != m2.end(); it++)
			{
				// m.insert(p);
				std::cout << "( " << it->first << " " << it->second << " ) ";
			}
            std::cout << std::endl;
			std::cin >> input;
			std::cout << "next : " << m2.erase(m2.find(input))->first;
			// m.delete_(p);
		}
		else if (input == 3)
			break;
	}
    std::cout << "m  : ";
    m.print_add();
    std::cout << "m2 : ";
    m2.print_add();

    std::cout << "m  : ";
    m.print_add();
    std::cout << "m2 : ";
    m2.print_add();
    for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        // m.insert(p);
        std::cout << "( " << it->first << " " << it->second << " )";
    }
    std::cout << std::endl;
    for (ft::map<int, int>::iterator it = m2.begin(); it != m2.end(); it++)
    {
        // m.insert(p);
        std::cout << "( " << it->first << " " << it->second << " ) ";
	}
    m.swap(m2);

    std::cout << "m  : ";
    m.print_add();
    std::cout << "m2 : ";
    m2.print_add();
    for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        // m.insert(p);
        std::cout << "( " << it->first << " " << it->second << " )";
    }
    std::cout << std::endl;
    for (ft::map<int, int>::iterator it = m2.begin(); it != m2.end(); it++)
    {
        // m.insert(p);
        std::cout << "( " << it->first << " " << it->second << " ) ";
    }
}
*/
// int main()
// {
//     ft::map<int, char, ModCmp> cont;
//     const std::pair<const int, char> p;
//     // cont = { { 1, 'a' }, { 2, 'b' }, { 3, 'c' }, { 4, 'd' }, { 5, 'e' } };
// 	cont.insert(std::pair<const int, char>(1, 'a'));
// 	cont.insert(std::pair<const int, char>(2, 'b'));
// 	cont.insert(std::pair<const int, char>(3, 'c'));

//     ft::map<int, char, ModCmp>::value_compare comp_func = cont.value_comp();
 
//     std::pair<const int, char> val( 100, 'a' );
 
//     for (ft::map<int, char, ModCmp>::iterator it = cont.begin(); it != cont.end(); it++)
// 	{
//         bool before = comp_func(*it, val);
//         bool after = comp_func(val, *it);
 
//         std::cout << '(' << it->first << ',' << it->second;
//         if (!before && !after)
//             std::cout << ") equivalent to key " << val.first << '\n';
//         else if (before)
//             std::cout << ") goes before key " << val.first << '\n';
//         else if (after)
//             std::cout << ") goes after key " << val.first << '\n';
//         else
//             assert(0); // Cannot happen
//     }
// }

// int main()
// {
// 	ft::map<int, int> m;
// 	std::vector<std::pair<int, int> > v;
// 	std::pair<int, int> p(50, 69);
// 	ft::map<int, int>::value_type value(p);
// 	// value.first = 10;
// 	// value.second = 10;
// 	// for (int i =0; i < 10; i++)
// 	int input;
// 	ft::map<int, int>::iterator pos;
// 	// pos = m.insert(p, 'a');
// 	while(1)
// 	{
// 		std::cin >> input;
// 		if (input == 1)
// 		{
// 			std::cin >> input;
// 			p = std::pair<const int, int>(input, input + 10);
// 			// m.insert(p);
// 			pos = m.insert(m.begin(), p);
// 			// m.insert(p, 'a');
// 			// v.push_back(p);
// 			// pos = m.insert(pos,p);
// 			m.print();
// 		}
// 		else if (input == 2)
// 		{
// 			for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
// 			{
// 				// m.insert(p);
// 				std::cout << it->first << " " << it->second << std::endl;
// 			}
// 			std::cin >> input;
// 			std::cout << "next : " << m.erase(m.find(input))->first << std::endl;
// 			// m.delete_(p);
// 		}
// 		else if (input == 3)
// 			break;
// 	}
// 	// std::map<int, int> mm(v.begin(), v.end());
// 	// std::cout << "search: ";
// 	// int val;
// 	std::cin >> input;
// 	std::cout << m.lower_bound(input)->first << std::endl;
// 	std::cout << m.upper_bound(input)->first << std::endl;
// 	std::cout << m.equal_range(input).first->first << ' ' << m.equal_range(input).second->first << std::endl;
// 	std::cout << "++++\n";
// 	// std::cin >> val;
// 	// m[input] = val;
// 	// try
// 	// {
// 	// 	mm.at(input);
// 	// }
// 	// catch(std::exception &e)
// 	// {
// 	// 	std::cout << e.what();
// 	// };
// 	// ft::map<int, int> m(v.begin(), v.end());
// 	// ft::map<int, int> m2(m);
// 	// std::cout << "add aditional value\n";
// 	// std::cin >> input;
// 	// p = std::pair<const int, int>(input, input + 10);
// 	// m.insert(p);
// 	// m2 = m;
// 	// std::cout << "search for value\n";
// 	// std::cin >> input;
	
// 	// int &me = m2[input];
// 	// me = 159;
// 	// m.insert(v.begin(), v.end());
// 	for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
// 	{
// 		// m.insert(p);
// 		std::cout << it->first << " " << it->second << std::endl;
// 	}
// }

// int main ()
// {
//   std::vector<int> myvector;
//   // std::allocator<A> alloc;
//   // // ft::vector<A> myvector;

//   //   A* p = alloc.allocate(5);
//   //   alloc.construct(p, A());
//   //   A* pp = alloc.allocate(5);
//   //   pp[0] = p[0];
//   //   std::cout << pp[0].a << std::endl;

//   // set some initial content:
//   for (int i=1;i<10;i++) myvector.push_back(i);

//   myvector.resize(0);
//   myvector.resize(12);
//   myvector.resize(8, 100);
//   std::cout << "myvector capacity :" << myvector.capacity() << std::endl;

//   std::cout << "myvector contains:";
//   std::cout << myvector.size() << std::endl;
//   for (int i=0;i<myvector.size();i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   return 0;
// }

// int main()
// {
//     ft::vector<int> vec2;
//     std::vector<int> vec3;
//     for (int i = 0; i < 10; i++)
//         vec3.push_back(i);
//     vec2.push_back(1);
//     vec2.push_back(9);
//     vec2.push_back(9);
//     ft::vector<int>::iterator it;
//     ft::vector<int>::const_iterator ic;

//     it = vec2.begin();
//     vec2.insert(it + 2, vec3.begin(), vec3.end());
//     vec2.erase(vec2.begin() + 3, vec2.end());
//     it = vec2.begin();
//     // for (ft::vector<std::string>::iterator it = vec2.begin(); it != vec2.end(); it++)
//     for (ft::vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++)
//     {
//         std::cout << *it << std::endl;
//     }

// //     std::vector<int> vec2;
// //     std::vector<int> vec3;
// //     for (int i = 0; i < 10; i++)
// //         vec3.push_back(i);
// //      vec2.push_back(1);
// //     vec2.push_back(9);
// //     vec2.push_back(9);
// //     std::vector<int>::iterator it;
// //     std::vector<int>::const_iterator ic;

// //     it = vec2.begin();
// //     vec2.insert(it + 2, vec3.begin(), vec3.end());
// //     // for (int j = 0; j < 10; j++)
// //         vec2.erase(vec2.begin() + 3, vec2.end());
// //     it = vec2.begin();
// //     // for (ft::vector<std::string>::iterator it = vec2.begin(); it != vec2.end(); it++)
// //     for (std::vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++)
// //     {
// //         std::cout << *it << std::endl;
// //     }
// }
