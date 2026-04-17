#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> q = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int found = 5;
    int nonFound = 12;

    std::cout << "=== vector ===" << std::endl;
    try {
        auto it = easyfind(v, found);
        std::cout << "Integer found: " << *it << std::endl;
        easyfind(v, nonFound);
    } catch (const std::exception& e) {
        std::cout << "Caught expected: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "=== list ===" << std::endl;
    try {
        auto it = easyfind(l, found);
        std::cout << "Integer found: " << *it << std::endl;
        easyfind(l, nonFound);
    } catch (const std::exception& e) {
        std::cout << "Caught expected: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "=== deque ===" << std::endl;
    try {
        auto it = easyfind(q, found);
        std::cout << "Integer found: " << *it << std::endl;
        easyfind(q, nonFound);
    } catch (const std::exception& e) {
        std::cout << "Caught expected: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== empty vector ===" << std::endl;
    std::vector<int> v2 = {};
    try {
        auto it = easyfind(v2, found);
        std::cout << "Integer found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught expected: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "=== duplicates in list ===" << std::endl;
    std::list<int> l2 = {1, 2, 3, 4, 5, 4, 7, 8, 5, 10};
    try {
        auto it = easyfind(l2, found);
        std::cout << "Integer found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught expected: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "=== find last one in deque ===" << std::endl;
    std::deque<int> q2 = {0, 10, 20};
    found = 20;
    try {
        auto it = easyfind(q2, found);
        std::cout << "Integer found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught expected: " << e.what() << std::endl;
    }
    

    return 0;
}