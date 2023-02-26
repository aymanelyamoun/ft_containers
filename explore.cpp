#include <vector>
#include "map.hpp"
#include "set.hpp"
#include <iterator>
#include <iostream>
#include "vector.hpp"
#include <stack>
#include <set>
// #include "pair.hpp"
#include <map>

// class A
// {
// public:
//   int a;
// //   A(): a(100) {; std::cout << "A::A()" << std::endl; }
//   A(const A&) { std::cout << "A::A(const A&)" << std::endl; }
//   ~A() { std::cout << "A::~A()" << std::endl; }
// };
 
// // Example module 97 key compare function
// struct ModCmp {
//     bool operator()(const int lhs, const int rhs) const
//     {
//         return (lhs % 97) < (rhs % 97);
//     }
// };

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

#include <iostream>
#define _make_pair ft::make_pair
#define _pair ft::pair
#define _map ft::map
#define _set ft::set
#define _vector ft::vector
#include <string>
#define _ratio 10000
using std::string;
#include <fstream>


// class SetBoolTest {
// public:
// 	std::set<int> s1, s2, s3, s4;
// 	std::set<string> s5, s6, s7, s8, s9;
// 	_set<int> st1, st2, st3, st4;
// 	_set<string> st5, st6, st7, st8, st9;

// 	SetBoolTest() {
// 		s1.insert(2); st1.insert(2);
// 		s2.insert(3); st2.insert(3);
// 		s3.insert(3); st3.insert(3);
// 		s4.insert(4); st4.insert(4);
// 		s4.insert(4); st4.insert(4);
// 		s5.insert("122"); st5.insert("122");
// 		s6.insert("123"); st6.insert("123");
// 		s7.insert("124"); st7.insert("124");
// 		s8.insert("12"); st8.insert("12");
// 		s9.insert("123"); st9.insert("123");
// 	}
// };
// bool set_equal_test() {
// 	std::vector<int> result, result2;
// 	SetBoolTest st;

// 	result.push_back(st.s1 == st.s1); result.push_back(st.s3 == st.s3); result.push_back(st.s5 == st.s9);
// 	result.push_back(st.s1 == st.s2); result.push_back(st.s3 == st.s4); result.push_back(st.s6 == st.s6);
// 	result.push_back(st.s1 == st.s3); result.push_back(st.s4 == st.s4); result.push_back(st.s6 == st.s7);
// 	result.push_back(st.s1 == st.s4); result.push_back(st.s5 == st.s5); result.push_back(st.s6 == st.s8);
// 	result.push_back(st.s2 == st.s2); result.push_back(st.s5 == st.s6); result.push_back(st.s6 == st.s9);
// 	result.push_back(st.s2 == st.s3); result.push_back(st.s5 == st.s7); result.push_back(st.s7 == st.s7);
// 	result.push_back(st.s2 == st.s4); result.push_back(st.s5 == st.s8); result.push_back(st.s7 == st.s8);
// 	result.push_back(st.s7 == st.s9); result.push_back(st.s8 == st.s8); result.push_back(st.s8 == st.s9);
// 	result.push_back(st.s9 == st.s9);

// 	result2.push_back(st.st1 == st.st1); result2.push_back(st.st3 == st.st3); result2.push_back(st.st5 == st.st9);
// 	result2.push_back(st.st1 == st.st2); result2.push_back(st.st3 == st.st4); result2.push_back(st.st6 == st.st6);
// 	result2.push_back(st.st1 == st.st3); result2.push_back(st.st4 == st.st4); result2.push_back(st.st6 == st.st7);
// 	result2.push_back(st.st1 == st.st4); result2.push_back(st.st5 == st.st5); result2.push_back(st.st6 == st.st8);
// 	result2.push_back(st.st2 == st.st2); result2.push_back(st.st5 == st.st6); result2.push_back(st.st6 == st.st9);
// 	result2.push_back(st.st2 == st.st3); result2.push_back(st.st5 == st.st7); result2.push_back(st.st7 == st.st7);
// 	result2.push_back(st.st2 == st.st4); result2.push_back(st.st5 == st.st8); result2.push_back(st.st7 == st.st8);
// 	result2.push_back(st.st7 == st.st9); result2.push_back(st.st8 == st.st8); result2.push_back(st.st8 == st.st9);
// 	result2.push_back(st.st9 == st.st9);

// 	return result == result2;
// }


// template <class T>
// std::vector<int> copy_constructor_test() {
// 	_set<T> st;
//     std::vector<int> v;

//     for (int i = 0; i < 30 * _ratio; ++i)
//         st.insert(i);
//     _set<int> st2(st.begin(), st.end());
//     _set<int>::iterator it = st2.begin();
//     for (int i = 0; i < 30 * _ratio; ++i, it++) {
//         v.push_back(*it);
//     }
//     return v;
// }

// template <typename T>
// std::vector<int> begin_test() {
// 	std::vector<T> vector;
//     std::vector<int> v;
//     vector.assign(1000, 1);
//     v.push_back(*vector.begin());
//     v.push_back(*++vector.begin());
//     return v;
// }

// template <typename T>
// std::vector<int> begin_test2() {
// 	_vector<T> vector;
//     std::vector<int> v;
//     vector.assign(1000, 1);
//     v.push_back(*vector.begin());
//     v.push_back(*++vector.begin());
//     return v;
// }

// template <typename T>
// std::vector<int> constructor_test() {
// 	std::vector<T> vector;
//     std::vector<int> v;
//     std::vector<int> tmp0(vector);
//     std::vector<int> tmp(1000 * _ratio, 4), tmp2(1000 * _ratio, 5);
//     tmp = tmp2;
//     std::vector<int> tmp3(tmp);
//     std::vector<int> tmp4(tmp.begin(), tmp.end());
//     v.push_back(tmp4.size());
//     v.push_back(tmp4.capacity());
//     v.push_back(tmp[2]);
//     v.push_back(tmp3[2]);
//     v.push_back(tmp4[2]);
//     try { std::vector<int> tmp5(-1, -1); }
//     catch (std::exception &e) { v.push_back(1); }
//     return v;
// }

// template <typename T>
// std::vector<int> constructor_test2() {
// 	_vector<T> vector;
//     std::vector<int> v;
// 	_vector<int> tmp0(vector);
//     _vector<int> tmp(1000 * _ratio, 4), tmp2(1000 * _ratio, 5);
//     tmp = tmp2;
//     _vector<int> tmp3(tmp);
//     _vector<int> tmp4(tmp.begin(), tmp.end());
//     v.push_back(tmp4.size());
//     v.push_back(tmp4.capacity());
//     v.push_back(tmp[2]);
//     v.push_back(tmp3[2]);
//     v.push_back(tmp4[2]);
//     try { _vector<int> tmp5(-1, -1); }
//     catch (std::exception &e) { v.push_back(1); }
// 	// while(1){};
//     return v;
// }

// template <typename T>
// std::vector<int> constructor_test() {
// 	std::vector<T> vector;
//     std::vector<int> v;
//     std::vector<int> tmp0(vector);
//     std::vector<int> tmp(1000 * _ratio, 4), tmp2(1000 * _ratio, 5);
//     tmp = tmp2;
//     std::vector<int> tmp3(tmp);
//     g_start1 = timer();
//     std::vector<int> tmp4(tmp.begin(), tmp.end());
//     g_end1 = timer();
//     v.push_back(tmp4.size());
//     v.push_back(tmp4.capacity());
//     v.push_back(tmp[2]);
//     v.push_back(tmp3[2]);
//     v.push_back(tmp4[2]);
//     try { std::vector<int> tmp5(-1, -1); }
//     catch (std::exception &e) { v.push_back(1); }
//     return v;
// }

// template <typename T>
// std::vector<int> constructor_test2() {
// 	_vector<T> vector;
//     std::vector<int> v;
// 	_vector<int> tmp0(vector);
//     _vector<int> tmp(1000 * _ratio, 4), tmp2(1000 * _ratio, 5);
//     tmp = tmp2;
//     _vector<int> tmp3(tmp);
//     g_start2 = timer();
//     _vector<int> tmp4(tmp.begin(), tmp.end());
//     g_end2 = timer();
//     v.push_back(tmp4.size());
//     v.push_back(tmp4.capacity());
//     v.push_back(tmp[2]);
//     v.push_back(tmp3[2]);
//     v.push_back(tmp4[2]);
//     try { _vector<int> tmp5(-1, -1); }
//     catch (std::exception &e) { v.push_back(1); }
//     return v;
// }
// int main()
// {
//     std::fstream file("ma.cpp");


//     std::vector<char> safasf((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
// 	// file.close();
//     std::cout << "---- File Content:  ----" << std::endl;
//     for (std::size_t i = 0; i < safasf.size(); i++)
//         std::cout << safasf[i];
//     std::cout << safasf.size() << " " << safasf.capacity() << std::endl;
// }
#include "stack.hpp"
#define _stack ft::stack
#define w_vec ft::vector

void test_v()
{
	w_vec<int> vec;
	w_vec<int>::iterator it;
	vec.reserve(20);
	for(int i = 1; i < 11; i++)
		vec.push_back(i);
		// std::cout << "cap : " << vec.capacity() << std::endl;
	vec.insert(vec.begin(), 5 , 42);
	for (it  = vec.begin() ; it != vec.end() ;it++){
		std::cout << "["  << *it << "]" ;
	}
}
int main()
{
	test_v();
	// std::cout << stack_equal_test();
	// std::cout << operator_equal_test() << std::endl;
	// std::vector<int> v2 = swap_test2<int>();
	// std::vector<int> v = pop_test<int>();
	// std::vector<int> v2 = pop_test2<int>();
	// std::vector<int> v = copy_constructor_test<int>();
	// std::vector<int> v = empty_test<int>();
	// std::vector<int> v2 = empty_test2<int>();

	// std::vector<int> v(5, 6);
	// v.push_back(15);
	// v.push_back(16);
	// v.push_back(17);
	// v.push_back(18);
	// v.push_back(19);
	// for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		// std::cout << *it << " ";
	// std::cout << std::endl;
	// v.insert(v.begin() - 50, 20, 25);
	// std::cout << v.capacity() << std::endl;

	// for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// while(1);
}


// struct explore
// {
// 	explore(){std::cout << "explore" << std::endl;}
// 	~explore(){std::cout << "explore destroyed" << std::endl;}
// };


// int main()
// {
// 	std::vector<explore> v;
// 	std::vector<explore> v2;
// 	explore e;

// 	// std::vector<int>::iterator it;
// 	v.push_back(e);
// 	v.push_back(e);
// 	v.push_back(e);
// 	v.push_back(e);
// 	v.push_back(e);
// 	v.push_back(e);
// 	v.push_back(e);
// 	v.push_back(e);
// 	v.push_back(e);
// 	v.push_back(e);
// 	v2.push_back(e);
// 	v2.push_back(e);
// 	v2.push_back(e);
// 	v2.push_back(e);
// 	v2.push_back(e);
// 	v.assign(v2.begin(), v2.end());
// 	while(1){}
// 	// for(std::vector<explore>::iterator it ; it != v.end(); it++);
// 		// std::cout << *it << " ";
// 	std::cout << std::endl;
// }

//insert

// template <class T, class V>
// std::vector<int> insert_test() {
// 	_map<T, V> mp;
//     std::vector<int> v;
//     _pair<_map<int, int>::iterator , bool> pair = mp.insert(_make_pair(7, 7));
//     _map<int, int>::iterator it = mp.begin();
//     v.push_back(it->first);
//     v.push_back(it->second);
//     v.push_back(pair.first->first);
//     v.push_back(pair.first->second);
//     v.push_back(pair.second);
//     mp.insert(_make_pair(9, 9));
//     _pair<_map<int, int>::iterator , bool> pair2 = mp.insert(_make_pair(9, 9));
//     _map<int, int>::iterator it2 = pair.first;
//     v.push_back(it2->first);
//     v.push_back(it2->second);
//     v.push_back(pair2.first->first);
//     v.push_back(pair2.first->second);
//     v.push_back(pair2.second);
//     // g_start2 = timer();
// 	// std::string in;
//     for (int i = 0, j = 0; i < 50 * 10000; ++i, ++j) {
// 		// std::cin >> in;
//         mp.insert(_make_pair(i, j));
// 		// std::cout << "-----------------------------------------------\n";
// 		// mp.print();

//     }
// 	// mp.print();
// 	// while(1){};
//     // g_end2 = timer();
//     typename _map<T, V>::iterator it3 = mp.begin();
// 	// int input;
//     for (; it3 != mp.end(); ++it3) {
// 		// std::cin >> input;
// 		// if (input == 1)
// 			// std::cout << it3->first << '\n';
// 		// else
// 			// mp.print();
//         v.push_back(it3->first);
//         v.push_back(it3->second);
//     }
//     v.push_back(mp.size());
// 	std::cout << mp.size() << " =============\n";
//     return v;
// }



// iterator end

// template <class T, class V>
// std::vector<int>    reverse_iterators_test_std2() {

// 	std::map<T, V> mp;
//     std::vector<int> v;

//     mp.insert(std::make_pair(5, 5));
//     mp.insert(std::make_pair(3, 3));
//     mp.insert(std::make_pair(7, 7));
//     typename std::map<T, V>::reverse_iterator rit = mp.rbegin();
//     typename std::map<T, V>::reverse_iterator rit2 = mp.rend();
//     v.push_back(rit->first);
//     rit++;
//     rit2--;
//     v.push_back(rit->first);
//     v.push_back(rit2->first);
//     rit++;
//     v.push_back(*rit == *rit2);
//     rit2--;
//     v.push_back(rit->first);
//     v.push_back(rit2->first);
//     v.push_back(*rit2 > *rit);
//     v.push_back(*rit2 < *rit);
//     v.push_back((--rit)->first);
//     v.push_back((++rit2)->first);
//     v.push_back((rit--)->first);
//     v.push_back((rit2++)->first);
//     return v;
// }



// template <class T, class V, class C>
// void fillMap(_map<T, V, C> &mp) {
// 	mp.insert(_make_pair(16, 3));
// 	mp.insert(_make_pair(8, 3));
// 	mp.insert(_make_pair(23, 3));
// 	mp.insert(_make_pair(7, 3));
// 	mp.insert(_make_pair(19, 3));
// 	mp.insert(_make_pair(29, 3));
// 	mp.insert(_make_pair(41, 3));
// 	mp.insert(_make_pair(4, 3));
// 	mp.insert(_make_pair(11, 3));
// }

// template <class T, class V>
// std::vector<int> reverse_iterators_test_ft() {
	
// 	_map<T, V> mp;
//     std::vector<int> v;

//     // g_start2 = g_end2 = timer();
//     mp.insert(_make_pair(5, 5));
//     mp.insert(_make_pair(3, 3));
//     mp.insert(_make_pair(7, 7));
//     typename _map<T, V>::reverse_iterator rit = mp.rbegin();
//     typename _map<T, V>::reverse_iterator rit2 = mp.rend();
//     v.push_back(rit->first);
//     rit++;
//     rit2--;
//     v.push_back(rit->first);
//     v.push_back(rit2->first);
//     rit++;
//     v.push_back(*rit == *rit2);
//     rit2--;
//     v.push_back(rit->first);
//     v.push_back(rit2->first);
//     v.push_back(*rit2 > *rit);
//     v.push_back(*rit2 < *rit);
//     v.push_back((--rit)->first);
//     v.push_back((++rit2)->first);
//     v.push_back((rit--)->first);
//     v.push_back((rit2++)->first);
//     return v;
// }



// template <class T, class V>
// std::vector<int> iterators_test() {
// 	_map<T, V> mp;
//     std::vector<int> v;
//     _map<T, V> mpp;
//     fillMap(mpp);
//     for (typename _map<T, V>::iterator it = mpp.begin(); it != mpp.end(); it++) { v.push_back(it->first); }
//     for (typename _map<T, V>::iterator it = --mpp.end(); it != mpp.begin(); it--) { v.push_back(it->first); }
// 	std::cout << "+++++++0\n";
//     _map<int, int> mp0;
//     _map<int, int>::iterator ii = mp0.insert(_make_pair(3, 3)).first;
//     ii++;
//     v.push_back((--ii)->first);
//     for (int i = 0, j = 10; i < 5; ++i, ++j)
//         mp.insert(_make_pair(i, j));
//     typename _map<T, V>::iterator it = mp.begin();
//     typename _map<T, V>::iterator it2 = mp.end();
//     v.push_back(it->first);
//     it++;
//     it++;
//     it++;
//     it++;
//     v.push_back(it->first);
//     it++;
//     it--;
//     v.push_back(it->first);
//     it2--;
//     v.push_back(it2->first);
//     v.push_back(it2 == it);
//     v.push_back((--it2)->first);
//     v.push_back((it2--)->first);
//     v.push_back((it2++)->first);
//     v.push_back((++it2)->first);
//     return v;
// }


// iterator end

// swap start


// template <class T, class V>
// std::vector<int> swap_test2() {
// 	std::map<T, V> mp;
//     std::vector<int> v;
//     for (int i = 0, j = 0; i < 25 * _ratio; ++i, ++j)
//         mp.insert(std::make_pair(i, j));
//     std::map<T, V> mp2;
//     for (int i = 25 * _ratio, j = 0; i < 35 * _ratio; ++i, --j)
//         mp.insert(std::make_pair(i, j));
//     long *adr1 = reinterpret_cast<long *>(&mp);
//     long *adr2 = reinterpret_cast<long *>(&mp2);
//     mp.swap(mp2);
//     if (reinterpret_cast<long *>(&mp) == adr1 && reinterpret_cast<long *>(&mp2) == adr2)
// 	{
//     	v.push_back(-5);
// 	}
//     v.push_back(mp2.size());
//     typename std::map<T, V>::iterator it = mp2.begin();
//     for (; it != mp2.end(); ++it) {
// 		// std::cout << it->first << " ";
//         v.push_back(it->first);
//         v.push_back(it->second);
//     }
//     std::swap(mp, mp2);
//     typename std::map<T, V>::iterator it2 = mp2.begin();
//     for (; it2 != mp2.end(); ++it2) {
// 		// std::cout << it2->first << " ";
//         v.push_back(it2->first);
//         v.push_back(it2->second);
//     }
//     return v;
// }


// template <class T, class V>
// std::vector<int> swap_test() {
// 	_map<T, V> mp;
//     std::vector<int> v;
//     for (int i = 0, j = 0; i < 25 * _ratio; ++i, ++j)
//         mp.insert(_make_pair(i, j));
//     _map<T, V> mp2;
//     for (int i = 25 * _ratio, j = 0; i < 35 * _ratio; ++i, --j)
//         mp.insert(_make_pair(i, j));
//     long *adr1 = reinterpret_cast<long *>(&mp);
//     long *adr2 = reinterpret_cast<long *>(&mp2);
//     mp.swap(mp2);
//     if (reinterpret_cast<long *>(&mp) == adr1 && reinterpret_cast<long *>(&mp2) == adr2)
// 	{
//     	v.push_back(-5);
// 	}
//     v.push_back(mp2.size());
//     typename _map<T, V>::iterator it = mp2.begin();
//     for (; it != mp2.end(); ++it) {
// 		// std::cout << it->first << " ";
//         v.push_back(it->first);
//         v.push_back(it->second);
//     }
// 	std::cout << "\n-----------------------------\n";
//     std::swap(mp, mp2);
//     typename _map<T, V>::iterator it2 = mp2.begin();
//     for (; it2 != mp2.end(); ++it2) {
// 		// std::cout << it2->first << " ";
//         v.push_back(it2->first);
//         v.push_back(it2->second);
//     }
//     return v;
// }


// swap end



// copy constructor start


// template <class T, class V>
// std::vector<int> copy_constructor_test() {
// 	_map<T, V> mp;
//     std::vector<int> v;

//     for (int i = 0, j = 10; i < 30 * _ratio; ++i, ++j) {
//         mp.insert(_make_pair(i, j));
//     }
//     _map<int, int> mp2(mp.begin(), mp.end());
//     _map<int, int>::iterator it = mp2.begin();
//     for (int i = 0; i < 30 * _ratio; ++i, it++) {
//         v.push_back(it->first);
//         v.push_back(it->second);
//     }
//     return v;
// }

// copy constructor end



// compare 

// template <class T, class V, class C>
// void fillMap(std::map<T, V, C> &mp) {
// 	mp.insert(std::make_pair(16, 3));
// 	// mp3.print();
// 	mp.insert(std::make_pair(8, 3));
// 	mp.insert(std::make_pair(23, 3));
// 	mp.insert(std::make_pair(7, 3));
// 	mp.insert(std::make_pair(19, 3));
// 	mp.insert(std::make_pair(29, 3));
// 	mp.insert(std::make_pair(41, 3));
// 	mp.insert(std::make_pair(4, 3));
// 	mp.insert(std::make_pair(11, 3));
// }


// template <class T, class V, class C>
// void fillMap(_map<T, V, C> &mp) {
// 	mp.insert(_make_pair(16, 3));
// 	mp.insert(_make_pair(8, 3));
// 	mp.insert(_make_pair(23, 3));
// 	mp.insert(_make_pair(7, 3));
// 	mp.insert(_make_pair(19, 3));
// 	mp.insert(_make_pair(29, 3));
// 	mp.insert(_make_pair(41, 3));
// 	mp.insert(_make_pair(4, 3));
// 	mp.insert(_make_pair(11, 3));
// }



// template <class T, class V>
// std::vector<int> comparator_test2() {
// 	std::map<T, V> mp;
//     std::vector<int> v;
//     fillMap(mp);
//     for (typename std::map<T, V>::iterator it = mp.begin(); it != mp.end(); it++) { v.push_back(it->first); }
//     for (typename std::map<T, V>::iterator it = --mp.end(); it != mp.begin(); it--) { v.push_back(it->first); }
//     std::map<int, int, std::greater<int> > mp1;
//     fillMap(mp1);
//     v.push_back(mp1.begin()->first);
//     mp1.erase(41);
//     v.push_back(mp1.begin()->first);
//     mp1.erase(29);
//     v.push_back(mp1.begin()->first);
//     std::map<int, int, std::greater<int> > mp2;
//     mp2.insert(std::make_pair(3, 3));
//     v.push_back(mp2.begin()->first);
//     mp2.erase(3);
//     if (mp2.begin() == mp2.end())
//         v.push_back(1);
// 	//start to get bad here
//     std::map<int, int, std::plus<int> > mp3;
//     fillMap(mp3);
//     for (typename std::map<T, V>::iterator it = mp3.begin(); it != mp3.end(); it++) { v.push_back(it->first); }
//     for (typename std::map<T, V>::iterator it = --mp3.end(); it != mp3.begin(); it--) { v.push_back(it->first); }
//     std::map<int, int, std::minus<int> > mp4;
//     fillMap(mp4);
//     for (typename std::map<T, V>::iterator it = mp4.begin(); it != mp4.end(); it++) { v.push_back(it->first); }
//     for (typename std::map<T, V>::iterator it = --mp4.end(); it != mp4.begin(); it--) { v.push_back(it->first); }
//     std::map<int, int, std::greater_equal<int> > mp5;
//     fillMap(mp5);
//     for (typename std::map<T, V>::iterator it = mp5.begin(); it != mp5.end(); it++) { v.push_back(it->first); }
//     for (typename std::map<T, V>::iterator it = --mp5.end(); it != mp5.begin(); it--) { v.push_back(it->first); }
//     std::map<int, int, std::multiplies<int> > mp6;
//     fillMap(mp6);
//     for (typename std::map<T, V>::iterator it = mp6.begin(); it != mp6.end(); it++) { v.push_back(it->first); }
//     for (typename std::map<T, V>::iterator it = --mp6.end(); it != mp6.begin(); it--) { v.push_back(it->first); }
//     std::map<int, int, std::bit_xor<int> > mp7;
//     fillMap(mp7);
//     for (typename std::map<T, V>::iterator it = mp7.begin(); it != mp7.end(); it++) { v.push_back(it->first); }
//     for (typename std::map<T, V>::iterator it = --mp7.end(); it != mp7.begin(); it--) { v.push_back(it->first); }
//     std::map<int, int, std::logical_and<int> > mp8;
//     fillMap(mp8);
//     for (typename std::map<T, V>::iterator it = mp8.begin(); it != mp8.end(); it++) { v.push_back(it->first); }
//     for (typename std::map<T, V>::iterator it = --mp8.end(); it != mp8.begin(); it--) { v.push_back(it->first); }
//     v.push_back(mp1.size());
//     return v;
// }





// template <class T, class V>
// std::vector<int> comparator_test() {
// 	_map<T, V> mp;
//     std::vector<int> v;
//     fillMap(mp);
//     for (typename _map<T, V>::iterator it = mp.begin(); it != mp.end(); it++) { v.push_back(it->first); }
//     for (typename _map<T, V>::iterator it = --mp.end(); it != mp.begin(); it--) { v.push_back(it->first); }
//     _map<int, int, std::greater<int> > mp1;
//     fillMap(mp1);
//     v.push_back(mp1.begin()->first);
//     mp1.erase(41);
//     v.push_back(mp1.begin()->first);
//     mp1.erase(29);
//     v.push_back(mp1.begin()->first);
//     _map<int, int, std::greater<int> > mp2;
//     mp2.insert(_make_pair(3, 3));
//     v.push_back(mp2.begin()->first);
//     mp2.erase(3);
//     if (mp2.begin() == mp2.end())
//         v.push_back(1);
//     _map<int, int, std::plus<int> > mp3;
//     fillMap(mp3);
//     for (typename _map<T, V>::iterator it = mp3.begin(); it != mp3.end(); it++) { v.push_back(it->first); }
//     for (typename _map<T, V>::iterator it = --mp3.end(); it != mp3.begin(); it--) { v.push_back(it->first); }
//     _map<int, int, std::minus<int> > mp4;
//     fillMap(mp4);
//     for (typename _map<T, V>::iterator it = mp4.begin(); it != mp4.end(); it++) { v.push_back(it->first); }
//     for (typename _map<T, V>::iterator it = --mp4.end(); it != mp4.begin(); it--) { v.push_back(it->first); }
//     _map<int, int, std::greater_equal<int> > mp5;
//     fillMap(mp5);
//     for (typename _map<T, V>::iterator it = mp5.begin(); it != mp5.end(); it++) { v.push_back(it->first); }
//     for (typename _map<T, V>::iterator it = --mp5.end(); it != mp5.begin(); it--) { v.push_back(it->first); }
//     _map<int, int, std::multiplies<int> > mp6;
//     fillMap(mp6);
//     for (typename _map<T, V>::iterator it = mp6.begin(); it != mp6.end(); it++) { v.push_back(it->first); }
//     for (typename _map<T, V>::iterator it = --mp6.end(); it != mp6.begin(); it--) { v.push_back(it->first); }
//     _map<int, int, std::bit_xor<int> > mp7;
//     fillMap(mp7);
//     for (typename _map<T, V>::iterator it = mp7.begin(); it != mp7.end(); it++) { v.push_back(it->first); }
//     for (typename _map<T, V>::iterator it = --mp7.end(); it != mp7.begin(); it--) { v.push_back(it->first); }
//     std::map<int, int, std::logical_and<int> > mp8;
//     fillMap(mp8);
//     for (typename std::map<T, V>::iterator it = mp8.begin(); it != mp8.end(); it++) { v.push_back(it->first); }
//     for (typename std::map<T, V>::iterator it = --mp8.end(); it != mp8.begin(); it--) { v.push_back(it->first); }
//     v.push_back(mp1.size());

//     return v;
// }

// template <class T, class V>
// std::vector<int> comparator_test_s() 
// {
//     std::map<int, int, std::plus<int> > mp3;
//     std::vector<int> v;
//     fillMap(mp3);
//     for (typename std::map<T, V>::iterator it = mp3.begin(); it != mp3.end(); it++) { v.push_back(it->first); }
//     for (typename std::map<T, V>::iterator it = --mp3.end(); it != mp3.begin(); it--) {v.push_back(it->first); }
// 	return v;
// }

// template <class T, class V>
// std::vector<int> comparator_test_ss() 
// {
//     _map<int, int, std::plus<int> > mp3;
//     std::vector<int> v;
//     fillMap(mp3);
//     for (typename _map<T, V>::iterator it = mp3.begin(); it != mp3.end(); it++) { std::cout << it->first << " ";v.push_back(it->first); }
//     for (typename _map<T, V>::iterator it = --mp3.end(); it != mp3.begin(); it--) { std::cout << it->first << " ";v.push_back(it->first); }
// 	std::cout << std::endl;
// 	return v;
// }

// // compare end
// // template <class T, class V>
// // std::vector<int> erase_test_3() {
// // 	_map<T, V> mp;
// //     std::vector<int> v;
// //     for (int i = 0, j = 0; i < 50 * _ratio; ++i, ++j)
// //         mp.insert(_make_pair(i, j));

// //     mp.erase(mp.begin(), --mp.end());
// //     v.push_back(mp.begin()->first);
// //     return v;
// // }


// int main()
// {
// 	// std::vector<int> v = erase_test_3<int, int>();
// 	std::vector<int> v = comparator_test_s<int, int>();
// 	std::cout << "\n=============================================\n";
// 	std::vector<int> v2 = comparator_test_ss<int, int>();
// 	// std::vector<int> v = copy_constructor_test<int, int>();
// 	// std::vector<int> v = swap_test<int, int>();
// 	// std::vector<int> v2 = swap_test2<int, int>();
// 	// std::vector<int> v = insert_test<int, int>();
// 	// std::vector<int> v = iterators_test<int, int>();
// 	// std::vector<int> v = reverse_iterators_test_ft<int, int>();
// 	// std::vector<int> v2 = reverse_iterators_test_std2<int, int>();

// 	// std::vector<int> v2 = insert_test2<int, int>();

// 	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// 	for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
// 		std::cout << *it << " ";
// 	// std::cout << std::endl;
// 	// while(1){};
// }


//erase key

// #define _make_pairs std::make_pair
// #define _maps std::map


// template <class T, class V>
// std::vector<int> erase_test_1() 
// {
// 	std::map<T, V> mp;
//     std::vector<int> v;
//     v.push_back(mp.erase(3));
//     for (int i = 0, j = 0; i < 30 * 10000; ++i, ++j)
//         mp.insert(_make_pairs(i, j));
//     typename _maps<T, V>::iterator it = mp.begin();
//     v.push_back(it->first);
//     v.push_back(mp.erase(-5));
//     v.push_back(mp.size());
//     v.push_back(mp.erase(0));
//     v.push_back(mp.size());
//     it = mp.begin();
//     v.push_back(it->first);
//     typename _maps<T, V>::iterator it4 = mp.begin();
//     // g_start2 = timer();
//     for (; it4 != mp.end(); it4 = mp.begin())
//         mp.erase(it4->first);
//     // g_end2 = timer();
	
//     v.push_back(mp.erase(30 * 10000 - 1));
//     v.push_back(mp.size());
//     _maps<int, int> mp2;
//     for (int i = 0, j = 0; i < 10 ; ++i, ++j)
//         mp2.insert(_make_pairs(i, j));
//     mp2.erase(2);
//     mp2.erase(7);
//     typename _maps<T, V>::iterator it3 = mp2.begin();
// 	// int i = 0;
//     for (; it3 != mp2.end(); ++it3) {
// 		// std::cout << "it: " << it3->first << " " << it3->second << std::endl;
//         v.push_back(it3->first);
//         v.push_back(it3->second);
//     }
// 	// while (1){};
	
//     return v;
// }

// #define _make_pair ft::make_pair
// #define _map ft::map

// template <class T, class V>
// std::vector<int> erase_test_2() 
// {
// 	ft::map<T, V> mp;
//     std::vector<int> v;
//     v.push_back(mp.erase(3));
//     for (int i = 0, j = 0; i < 30 * 10000; ++i, ++j)
//         mp.insert(_make_pair(i, j));
//     typename _map<T, V>::iterator it = mp.begin();
//     v.push_back(it->first);
//     v.push_back(mp.erase(-5));
//     v.push_back(mp.size());
//     v.push_back(mp.erase(0));
//     v.push_back(mp.size());
//     it = mp.begin();
//     v.push_back(it->first);
//     typename _map<T, V>::iterator it4 = mp.begin();
//     // g_start2 = timer();
//     for (; it4 != mp.end(); it4 = mp.begin())
//         mp.erase(it4->first);
//     // g_end2 = timer();
	
//     v.push_back(mp.erase(30 * 10000 - 1));
//     v.push_back(mp.size());
//     _map<int, int> mp2;
//     for (int i = 0, j = 0; i < 10 ; ++i, ++j)
//         mp2.insert(_make_pair(i, j));
//     mp2.erase(2);
//     mp2.erase(7);
//     typename _map<T, V>::iterator it3 = mp2.begin();
// 	// int i = 0;
//     for (; it3 != mp2.end(); ++it3) {
// 		// std::cout << "it: " << it3->first << " " << it3->second << std::endl;
//         v.push_back(it3->first);
//         v.push_back(it3->second);
//     }
// 	// while (1){};
	
//     return v;
// }
// int main()
// {
// 	// std::vector<int> v = erase_test_1<int, int>();
// 	// std::vector<int> v2 = erase_test_2<int, int>();

// 	// for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
// 	// 	std::cout << *it << " ";
// 	// std::cout << std::endl;
// 	// for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
// 	// 	std::cout << *it << " ";
// 	// std::cout << std::endl;
// }

// int main() {
//     ft::map<int, std::string, std::greater<int> > my_map;
//     std::map<int, std::string, std::greater<int> > _map;
//     // create and populate your map with some values

//     // test the various member functions of std::map / ft::map
//     my_map.clear();
//     my_map.insert(ft::make_pair(1, "one"));
//     my_map.insert(ft::make_pair(2, "two"));
//     my_map.insert(ft::make_pair(3, "three"));
//     my_map.insert(ft::make_pair(4, "four"));
//     my_map.insert(ft::make_pair(5, "five"));

//     std::cout << "size: " << my_map.size() << std::endl;

//     std::cout << "empty: " << my_map.empty() << std::endl;

//     std::cout << "contains 3: " << my_map.count(3) << std::endl;

//     std::cout << "at 3: " << my_map.at(3) << std::endl;

//     ft::map<int, std::string>::iterator it;

// 	it = my_map.upper_bound(3);
// 	my_map.erase(3);

//     std::cout << "lower_bound 3: " << my_map.lower_bound(3)->second << std::endl;

//     std::cout << "upper_bound 3: " << it->second << std::endl;

// 	my_map.erase(my_map.find(3));

//     std::cout << "size: " << my_map.size() << std::endl;
//     std::cout << "size: " << my_map.max_size() << std::endl;
//     std::cout << "size: " << _map.max_size() << std::endl;

//     my_map.clear();
//     std::cout << "size: " << my_map.size() << std::endl;

//     return 0;
// }



/*
int main()
{
	ft::map<int, int> m;
	ft::pair<int, int> p(50, 69);
    int input;

	while(1)
	{
		std::cin >> input;
		if (input == 1)
		{
			std::cin >> input;
			p = ft::pair<const int, int>(input, input + 10);
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
*/

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
