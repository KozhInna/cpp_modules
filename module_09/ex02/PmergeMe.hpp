#pragma once

#include<vector>
#include<deque>

class PmergeMe {
    private:
        std::vector<int> vec_;
        std::deque<int>  deq_;
        double vecTime_;
        double deqTime_;
    
        // vector implementation
        void fordJohnson(std::vector<int>& arr, int pairSize);
        void sortPairs(std::vector<int>& arr, int pairSize);
        void insertJacobsthal(std::vector<int>& main, std::vector<int>& pend);
        void buildMainAndPend(std::vector<int>& arr, int pairSize,
                              std::vector<int>& main,
                              std::vector<int>& pend);
    
        // print helpers
        void printBefore();
        void printAfter();
        void printTime(clock_t vecTime, clock_t deqTime) const;
    
    public:
        PmergeMe() = delete;
        PmergeMe(int argc, char** argv);
        PmergeMe(const PmergeMe& src) = default;
        PmergeMe& operator=(const PmergeMe& src) = default;
        ~PmergeMe() = default;

        void sortVector(); 
        void sortDeque(); 
};