#include "PmergeMe.hpp"
#include<iostream>
#include <chrono>


PmergeMe::PmergeMe(int argc, char** argv) {
    if (argc < 2) {
        throw std::invalid_argument("Error: no input");
    }

  
    for (int i = 1; i < argc; i++) {
        char* end;
        long int num = strtol(argv[i], &end, 10);
        if (*end != '\0') {
            throw std::invalid_argument("Error: invalid input - not a number");
        }
        if (num <= 0) {
            throw std::invalid_argument("Error: invalid input - only positive integers");
        }
        if (num > INT_MAX) {
            throw std::invalid_argument("Error: invalid input - number too large");
        }
        vec_.push_back(static_cast<int>(num));
        deq_.push_back(static_cast<int>(num));
    }
}

void PmergeMe::printTime(clock_t vecTime, clock_t deqTime) const {
    std::cout << "Time to process a range of " << vec_.size()
    << " elements with std::vector : "
    << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << deq_.size()
    << " elements with std::deque  : "
    << deqTime << " us" << std::endl;
}

void PmergeMe::printBefore() {
    std::cout << "Before: ";
    for (int v : vec_) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printAfter() {
    std::cout << "After: ";
    for (int v : vec_) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::sortVector() {
    printBefore();

    auto start = std::chrono::high_resolution_clock::now();
    //fordJohnson(vec_, 1);
    auto end = std::chrono::high_resolution_clock::now();
    vecTime_ = std::chrono::duration<double, std::micro>(end - start).count();

    start = std::chrono::high_resolution_clock::now();
    //fordJohnson(deq_, 1);
    end = std::chrono::high_resolution_clock::now();
    deqTime_ = std::chrono::duration<double, std::micro>(end - start).count();

    printAfter();
    printTime(vecTime_, deqTime_);
}