#include "iter.hpp"
#include <iostream>

template <typename T>
void doubleValue(T& val) {
    val *= 2;
}

template <typename T>
void print(const T& c) {
	std::cout << c << std::endl;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    std::cout << "int before doubleValue:" << std::endl;
    iter(nums, 5, print<int>);
    iter(nums, 5, doubleValue<int>);
    std::cout << "int after doubleValue:" << std::endl;
    iter(nums, 5, print<int>);

    std::cout << std::endl;

    const double vals[] = {1.1, 2.2, 3.3};
    iter(vals, 3, print<double>);

    std::cout << std::endl;

    std::string words[] = {"hello", "world"};
    iter(words, 2, print<std::string>);

    return 0;
}