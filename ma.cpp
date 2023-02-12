#include <vector>
// #include "map.hpp"
#include <iterator>
#include <iostream>
#include <stack>
#include <map>



int main()
{
	std::map<int, int> m;
	std::vector<std::pair<int, int> > v;
	std::pair<int, int> p(50, 69);
	std::map<int, int>::value_type value(p);

	int input;
	std::map<int, int>::iterator pos;
	while(1)
	{
		std::cin >> input;
		if (input == 1)
		{
			std::cin >> input;
			p = std::pair<const int, int>(input, input + 10);
			pos = m.insert(m.begin(), p);

			// m.print();
		}
		else if (input == 2)
		{
            for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
            {
                std::cout << it->first << " " << it->second << std::endl;
            }
			std::cin >> input;
			std::cout << "next : " << m.erase(m.find(input))->first << std::endl;
			// p = std::pair<const int, int>(input, input + 10);
			// m.delete_(p);
		}
		else if (input == 3)
			break;
	}
	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
}