#include"PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv){
    try {
        PmergeMe pm(argc, argv);
        pm.sort();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
