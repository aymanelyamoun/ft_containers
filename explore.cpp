#include <vector>
#include "map.hpp"
#include <iterator>
#include <iostream>
// #include "vector.hpp"
#include <stack>
#include <map>

class A
{
public:
  int a;
  A(): a(100) {; std::cout << "A::A()" << std::endl; }
  A(const A&) { std::cout << "A::A(const A&)" << std::endl; }
  ~A() { std::cout << "A::~A()" << std::endl; }
};


int main()
{
	// ft::map<int, int> m;
	std::vector<std::pair<int, int> > v;
	std::pair<int, int> p(10, 69);
	ft::map<int, int>::value_type value(p);

	// value.first = 10;
	// value.second = 10;
	// for (int i =0; i < 10; i++)
	int input;
	while(1)
	{
		std::cin >> input;
		if (input == 1)
		{
			std::cin >> input;
			p = std::pair<const int, int>(input, input + 10);
			v.push_back(p);
			// m.insert(p);
		}
		else if (input == 2)
		{
			std::cin >> input;
			p = std::pair<const int, int>(input, input + 10);
			// m.delete_(p);
		}
		else if (input == 3)
			break;
	}

	ft::map<int, int> m(v.begin(), v.end());
	// m.insert(v.begin(), v.end());
	for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		// m.insert(p);
		std::cout << it->first << " " << it->second << std::endl;
	}
}

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
