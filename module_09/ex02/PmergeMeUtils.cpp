#include"PmergeMe.hpp"
#include<vector>
#include<deque>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<climits>
#include<cmath>

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
		parsed_.push_back(static_cast<int>(num));
	}
}

void PmergeMe::printTime(double vecTime, double deqTime) const {
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << vec_.size()
	<< " elements with std::vector : "
	<< vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << deq_.size()
	<< " elements with std::deque  : "
	<< deqTime << " us" << std::endl;
}

void PmergeMe::printBefore() {
	std::cout << "Before: ";
	for (int v : parsed_) {
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

int PmergeMe::getJacobNum(int n) {
	return (std::pow(2, n + 1) + std::pow(-1, n))/3;
}