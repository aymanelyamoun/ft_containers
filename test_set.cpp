#include "set.hpp"
#include <set>
#include <iostream>
#ifndef FT
#define FT 1
#endif

#if !FT
    #define ft std
#endif
void test_ft_set1() {
    ft::set<int> mySet;

    // Test empty and size functions
    if (!mySet.empty() || mySet.size() != 0) {
        std::cout << "ERROR: empty or size functions not working correctly" << std::endl;
        return;
    }

    // Test insert function
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(20); // Should not insert a duplicate element

    // Test iterator and const_iterator types
    ft::set<int>::iterator it = mySet.begin();
    ft::set<int>::const_iterator cit = mySet.begin();

    // Test dereference operator on iterators
    if (*it != 10 || *cit != 10) {
        std::cout << "ERROR: iterator or const_iterator not working correctly" << std::endl;
        return;
    }

    // Test ++ operator on iterators
    ++it;
    ++cit;
    if (*it != 20 || *cit != 20) {
        std::cout << "ERROR: ++ operator on iterator or const_iterator not working correctly" << std::endl;
        return;
    }

    // Test -- operator on iterators
    --it;
    --cit;
    if (*it != 10 || *cit != 10) {
        std::cout << "ERROR: -- operator on iterator or const_iterator not working correctly" << std::endl;
        return;
    }

    // Test find function
    it = mySet.find(20);
    if (*it != 20) {
        std::cout << "ERROR: find function not working correctly" << std::endl;
        return;
    }

    // Test count function
    if (mySet.count(20) != 1 || mySet.count(40) != 0) {
        std::cout << "ERROR: count function not working correctly" << std::endl;
        return;
    }

    // Test erase function
    mySet.erase(20);
    if (mySet.size() != 2 || mySet.count(20) != 0) {
        std::cout << "ERROR: erase function not working correctly" << std::endl;
        return;
    }

    // Test clear function
    mySet.clear();
    if (!mySet.empty()) {
        std::cout << "ERROR: clear function not working correctly" << std::endl;
        return;
    }

    std::cout << "All functions tested successfully" << std::endl;
}

void test_set_insert()
{
    ft::set<int> mySet;

    // Insert single element
    ft::pair<ft::set<int>::iterator,bool> singleInsertResult = mySet.insert(10);
    if (singleInsertResult.second == true) {
        std::cout << "Inserted " << *singleInsertResult.first << " successfully.\n";
    } else {
        std::cout << "Failed to insert " << *singleInsertResult.first << ". Element already exists.\n";
    }

    // Insert duplicate element
    singleInsertResult = mySet.insert(10);
    if (singleInsertResult.second == true) {
        std::cout << "Inserted " << *singleInsertResult.first << " successfully.\n";
    } else {
        std::cout << "Failed to insert " << *singleInsertResult.first << ". Element already exists.\n";
    }

    // Insert range of elements
    int arr[] = {20, 30, 40};
    mySet.insert(arr, arr+3);
    std::cout << "Set after inserting range of elements:\n";
    for (ft::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Insert using hint
    ft::set<int>::iterator hint = mySet.find(30);
    ft::set<int>::iterator hintInsertResult = mySet.insert(hint, 25);
    std::cout << "Set after inserting using hint:\n";
    for (ft::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Insert using hint (duplicate)
    hint = mySet.find(30);
    hintInsertResult = mySet.insert(hint, 25);
    std::cout << "Set after inserting using hint (duplicate):\n";
    for (ft::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}
void test_set_erase()
{
    ft::set<int> mySet;
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(40);
    mySet.insert(50);
    mySet.insert(60);
    mySet.insert(70);

    // Erase single element
    std::size_t numErased = mySet.erase(30);
    std::cout << "Erased " << numErased << " element(s).\n";
    std::cout << "Set after erasing single element:\n";
    for (ft::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Erase non-existing element
    numErased = mySet.erase(80);
    std::cout << "Erased " << numErased << " element(s).\n";
    std::cout << "Set after erasing non-existing element:\n";
    for (ft::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Erase using iterator
    ft::set<int>::iterator it = mySet.find(50);
    ft::set<int>::iterator nextIt = mySet.erase(it);
    std::cout << "Set after erasing using iterator:\n";
    for (ft::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    if (nextIt != mySet.end()) {
        std::cout << "Next element after erasing is: " << *nextIt << "\n";
    } else {
        std::cout << "Erased last element in the set.\n";
    }

    // Erase range of elements
    it = mySet.find(20);
    nextIt = mySet.find(60);
    mySet.erase(it, nextIt);
    std::cout << "Set after erasing range of elements:\n";
    for (ft::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}


template <class Set>
void testModifiers(Set& mySet) {
    std::cout << "Testing modifiers..." << std::endl;

    // Test insert
    // typename Set::iterator it;
    ft::pair<typename Set::iterator,bool> it;

    it = mySet.insert(1);
    // if (*it != 1) {
    if (*(it.first) != 1 || it.second != true) {
        std::cerr << "Insertion failed (1)" << std::endl;
    }

    it = mySet.insert(3);
    // if (*it != 3) {
    if (*(it.first) != 3 || it.second != true) {
        std::cerr << "Insertion failed (3)" << std::endl;
    }

    it = mySet.insert(5);
    // if (*it != 5) {
    if (*(it.first) != 5 || it.second != true) {
        std::cerr << "Insertion failed (5)" << std::endl;
    }

    it = mySet.insert(2);
    // if (*it != 2) {
    if (*(it.first) != 2 || it.second != true) {
        std::cerr << "Insertion failed (2)" << std::endl;
    }

    it = mySet.insert(4);
    if (*(it.first) != 4 || it.second != true) {
        std::cerr << "Insertion failed (4)" << std::endl;
    }

    int arr[] = {6, 7, 8};
    mySet.insert(arr, arr+3);

    // Test clear
    mySet.clear();
    if (mySet.empty() != true) {
        std::cerr << "Clear failed" << std::endl;
    }

    // Test swap
    Set otherSet;
    otherSet.insert(2);
    otherSet.insert(3);
    otherSet.insert(4);

    mySet.swap(otherSet);
    if (mySet.size() != 3 || otherSet.empty() != true) {
        std::cerr << "Swap failed (mySet -> otherSet)" << std::endl;
    }

    otherSet.swap(mySet);
    if (otherSet.size() != 3 || mySet.empty() != true) {
        std::cerr << "Swap failed (otherSet -> mySet)" << std::endl;
    }

    std::cout << "Modifiers test complete." << std::endl;
}

void test_set_mod()
{
    ft::set<int> ftSet;
    testModifiers(ftSet);
}
    // Test modifiers for ft::set of strings
//     std::cout << "\nTesting modifiers of strings:\n";
//     ft::set<std::string> ftStringSet;
//     ftStringSet.insert("apple");
//     ftStringSet.insert("banana");
//     ftStringSet.insert("cherry");
//     testModifiers(ftStringSet); 
// }



int main()
{
    test_ft_set1();
    test_set_insert();
    test_set_erase();
    test_set_mod();
}