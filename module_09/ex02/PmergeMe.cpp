#include"PmergeMe.hpp"
#include<iostream>
#include<chrono>
#include<algorithm>
#include<cmath>
#include<iomanip>


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
void PmergeMe::sortPairs(std::vector<int>& vec, int pairSize) {
    int size = static_cast<int>(vec.size());
    for (int i = 0; i + 2 * pairSize <= size; i += (pairSize * 2)) {
        if (vec[i + pairSize - 1] > vec[i + (2 * pairSize) - 1]) {
            std::swap_ranges(vec.begin() + i, 
                            vec.begin() + i + pairSize,
                            vec.begin() + i + pairSize);
        }
    }
}

void PmergeMe::buildMainAndPend(std::vector<int>& vec, int pairSize, std::vector<std::vector<int>>& mainChain,
    std::vector<std::vector<int>>& pendChain, std::vector<int>& bounds) {
    
    int size = static_cast<int>(vec.size());
    int groupIndex = 0;

    for (int i = 0; i + pairSize <= size; i += pairSize) {
        std::vector<int> pair(vec.begin() + i, vec.begin() + i + pairSize);
        if (groupIndex == 0) {
            mainChain.push_back(pair);
        }
        else if (groupIndex == 1) {
            mainChain.push_back(pair);
        }
        else if (groupIndex % 2 != 0) {
            mainChain.push_back(pair);
            bounds.push_back(static_cast<int>(mainChain.size()) - 1);
        }
        else {
            pendChain.push_back(pair);
        }
        groupIndex++;    
    }
}


int PmergeMe::getJacobNum(int n) {
    return (std::pow(2, n + 1) + std::pow(-1, n))/3;
}

void PmergeMe::resetBounds(std::vector<int>& bounds, int insertIndx) {
    for (int i = 0; i < static_cast<int>(bounds.size()); i++) {
        if (bounds[i] >= insertIndx) {
            bounds[i]++;
        }
    }
}

void PmergeMe::insertBinary(std::vector<std::vector<int>>& mainChain, 
                    std::vector<std::vector<int>>& pendChain, 
                    int bIndx, int aBoundIndx, std::vector<int>& bounds) {

    int low = 0;
    int high = aBoundIndx + 1;

    while (low < high) {
        int mid = (low + high) / 2;
        if (mainChain[mid].back() < pendChain[bIndx].back()) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    // low == high == insertion point
    mainChain.insert(mainChain.begin() + low, pendChain[bIndx]);
    resetBounds(bounds, low);
}

void PmergeMe::insertUsingJacobsthal(std::vector<std::vector<int>>& mainChain,
    std::vector<std::vector<int>>& pendChain, std::vector<int>& bounds) {
  
    int n = 2;
    int prevJ = 1;

    while(prevJ <= static_cast<int>(pendChain.size())) {
       
        int currJ = getJacobNum(n);

/*        std::cout <<  "BEFORE : " << std::endl;
            std::cout << "main: ";
        for (auto& g : mainChain) { 
            std::cout << "[";
            for (auto x : g) std::cout << x << " ";
            std::cout << "] "; 
        }
        std::cout << std::endl;
        
        std::cout << "pend: ";
        for (auto& g : pendChain) { 
            std::cout << "[";
            for (auto x : g) std::cout << x << " ";
            std::cout << "] "; 
        }
        std::cout << std::endl; */

        //is JacobNum exist in pend
        // pend starts at b2, so b_currJ exists if currJ <= pend.size() + 1
        if (!(currJ <= static_cast<int>(pendChain.size()) + 1) && static_cast<int>(pendChain.size()) >= prevJ) {
            for (int i = pendChain.size(); i >= prevJ; i--) {
                int aBoundIndx;
                if (i <= static_cast<int>(bounds.size())) {
                    aBoundIndx = bounds[i - 1];
                } else {
                    aBoundIndx = static_cast<int>(mainChain.size()) - 1;
                }
                int bIndx = i - 1;
                insertBinary(mainChain, pendChain, bIndx, aBoundIndx, bounds);    
            }
            return ;
        }

        //is JacobNum exist in main
        if (!(currJ <= static_cast<int>(bounds.size()) + 1)) {
            // a_x doesn't exist, search whole main
            for (int i = currJ; i > prevJ; i--) {
                int aBoundIndx = static_cast<int>(mainChain.size()) - 1;
                int bIndx = i - 2;
                insertBinary(mainChain, pendChain, bIndx, aBoundIndx, bounds);
            }
        } else {
            // a_x exists, use bounds[currJ-1]
            for (int i = 0; i < currJ - prevJ; i++) {
                int aBoundIndx = bounds[currJ - i - 2];
                int bIndx = currJ - i - 2;
                insertBinary(mainChain, pendChain, bIndx, aBoundIndx, bounds);
            }
        }
        n++;
        prevJ = currJ;
/*         std::cout <<  "AFTER: " ;
        std::cout << "main: ";
        for (auto& g : mainChain) { 
            std::cout << "[";
            for (auto x : g) std::cout << x << " ";
            std::cout << "] "; 
        }
        std::cout << std::endl;
        
        std::cout << "pend: ";
        for (auto& g : pendChain) { 
            std::cout << "[";
            for (auto x : g) std::cout << x << " ";
            std::cout << "] "; 
        }
        std::cout << std::endl; */
    }
}

void PmergeMe::fordJohnson(std::vector<int>& vec, int pairSize) {
    if (pairSize > static_cast<int>(vec.size()/2)) 
        return ;
    
    // DOWN: merge phase
    sortPairs(vec, pairSize);
    
    fordJohnson(vec, pairSize * 2);  // recurse
    
    // UP: insertion phase
    std::vector<std::vector<int>> mainChain;
    std::vector<std::vector<int>> pendChain;
    std::vector<int> bounds;

    // save leftover before building main/pend
    int size = static_cast<int>(vec.size());
    int remainder = size % pairSize;
    std::vector<int> leftover(vec.end() - remainder, vec.end());

    buildMainAndPend(vec, pairSize, mainChain, pendChain, bounds);
/*     for (auto pair : mainChain){
        for (auto it : pair) {
            std::cout << it << " ";
        }
        std::cout << " | ";
    }
    std::cout << std::endl;
    for (auto pair : pendChain){
        for (auto it : pair) {
            std::cout << it << " ";
        }
        std::cout << " | ";
    }
    std::cout << std::endl; */
    if (pendChain.empty()) return;
    insertUsingJacobsthal(mainChain, pendChain, bounds);

    vec.clear();
    for (auto& group : mainChain)
        vec.insert(vec.end(), group.begin(), group.end());
    
    vec.insert(vec.end(), leftover.begin(), leftover.end());
}

void PmergeMe::sortVector() {
    printBefore();

    auto start = std::chrono::high_resolution_clock::now();
    fordJohnson(vec_, 1);
    auto end = std::chrono::high_resolution_clock::now();
    vecTime_ = std::chrono::duration<double, std::micro>(end - start).count();

    start = std::chrono::high_resolution_clock::now();
    //fordJohnson(deq_, 1);
    end = std::chrono::high_resolution_clock::now();
    deqTime_ = std::chrono::duration<double, std::micro>(end - start).count();

    printAfter();
    printTime(vecTime_, deqTime_);
}