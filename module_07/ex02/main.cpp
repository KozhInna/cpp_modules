#include "Array.hpp"
#include <iostream>

int main() {
    std::cout << std::endl << "=== Default constructor ===" << std::endl;
    Array<int> empty;
    std::cout << "empty.size() = " << empty.size() << std::endl;

    std::cout << std::endl << "=== Parametrised constructor ===" << std::endl;
    Array<int> arr(5);
    std::cout << "arr.size() = " << arr.size() << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = static_cast<int>(i * 10);

    std::cout << std::endl << "=== Copy constructor ===" << std::endl;
    Array<int> copy(arr);
    copy[0] = 999;
    std::cout << "arr[0] after modifying copy: " << arr[0] << " (expected 0)" << std::endl;
    std::cout << "copy[0]: " << copy[0] << " (expected 999)" << std::endl;

    std::cout << std::endl << "=== Assignment operator ===" << std::endl;
    Array<int> assigned;
    assigned = arr;
    arr[1] = 777;
    std::cout << "assigned[1] after modifying arr: " << assigned[1] << " (expected 10)" << std::endl;
    std::cout << "arr[1]: " << arr[1] << " (expected 777)" << std::endl;

    std::cout << std::endl << "=== Out-of-bounds ===" << std::endl;
    try {
        arr[100] = 0;
        std::cout << "ERROR: no exception thrown" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Out-of-bounds - empty array ===" << std::endl;
    try {
        empty[0] = 0;
        std::cout << "ERROR: no exception thrown on empty array" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught expected exception on empty: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== String type ===" << std::endl;
    Array<std::string> temp(4);
    temp[0] = "This";
    temp[1] = "is";
    temp[2] = "string";
    temp[3] = "!";
    const Array<std::string> strs(temp);
    for (unsigned int i = 0; i < strs.size(); i++)
        std::cout << strs[i] << " ";
    std::cout << std::endl;

    return 0;
}
