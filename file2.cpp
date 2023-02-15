// #include <map>
// #include "map.hpp"


#include <iostream>
#include <map>

struct MyCompare {
  bool operator()(const int &a, const int &b) const {
    return a < b;
  }

  void swap(MyCompare &other) {
    std::cout << "swap was called\n";
    // implementation of the swap function for MyCompare
  }
};

int main() {
  std::map<int, int, MyCompare> map1;
  std::map<int, int, MyCompare> map2;

  // insert some elements into map1 and map2
std::cout << "+++\n";
  map1.swap(map2); // this will exchange the contents of map1 and map2
std::cout << "+++\n";

  // iterate over the elements of the maps and print them
  return 0;
}