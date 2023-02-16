// #include <map>
// #include "map.hpp"


// #include <iostream>
// #include <map>

// struct MyCompare {
//   bool operator()(const int &a, const int &b) const {
//     return a < b;
//   }

//   void swap(MyCompare &other) {
//     std::cout << "swap was called\n";
//     // implementation of the swap function for MyCompare
//   }
// };

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
int main()
{
	std::map<int, int> m;
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
	for (std::map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        // m.insert(p);
		it->second = 100;
        std::cout << "( " << it->first << " " << it->second << " )";
    }
}