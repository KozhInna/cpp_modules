#include "iter.hpp"

int main() {
    // Test 1: int array
    int nums[] = {1, 2, 3, 4, 5};
    iter(nums, 5, print<int>);

    // Test 2: const array
    const double vals[] = {1.1, 2.2, 3.3};
    iter(vals, 3, print<double>);

    // Test 3: string array
    std::string words[] = {"hello", "world"};
    iter(words, 2, print<std::string>);

    return 0;
}