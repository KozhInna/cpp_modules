#pragma once

#include<vector>
#include<deque>

class PmergeMe {
    private:
        std::vector<int> vec_;
        std::deque<int>  deq_;
		std::vector<int> parsed_;
        double vecTime_;
        double deqTime_;

        // vector implementation
        void fordJohnson(std::vector<int>& arr, int pairSize);
        void sortPairs(std::vector<int>& arr, int pairSize);
        void buildMainAndPend(std::vector<int>& arr, int pairSize,
                                std::vector<std::vector<int>>& mainChain,
                                std::vector<std::vector<int>>& pendChain,
                                std::vector<int>& bounds);
        void insertUsingJacobsthal(std::vector<std::vector<int>>& mainChain,
                                    std::vector<std::vector<int>>& pendChain,
                                    std::vector<int>& bounds);
        void insertBinary(std::vector<std::vector<int>>& mainChain,
                                std::vector<std::vector<int>>& pendChain,
                                int currJ, int aBoundIndx, std::vector<int>& bounds);
        void resetBounds( std::vector<int>& bounds, int aBoundIndx);

		// deque implementation
        void fordJohnson(std::deque<int>& arr, int pairSize);
        void sortPairs(std::deque<int>& arr, int pairSize);
        void buildMainAndPend(std::deque<int>& arr, int pairSize,
                                std::deque<std::deque<int>>& mainChain,
                                std::deque<std::deque<int>>& pendChain,
                                std::deque<int>& bounds);
        void insertUsingJacobsthal(std::deque<std::deque<int>>& mainChain,
                                    std::deque<std::deque<int>>& pendChain,
                                    std::deque<int>& bounds);
        void insertBinary(std::deque<std::deque<int>>& mainChain,
                                std::deque<std::deque<int>>& pendChain,
                                int currJ, int aBoundIndx, std::deque<int>& bounds);
        void resetBounds( std::deque<int>& bounds, int aBoundIndx);

        // print helpers
        void printBefore();
        void printAfter();
        void printTime(double vecTime, double deqTime) const;

        static int getJacobNum(int n);

    public:
        PmergeMe() = delete;
        PmergeMe(int argc, char** argv);
        PmergeMe(const PmergeMe& src) = default;
        PmergeMe& operator=(const PmergeMe& src) = default;
        ~PmergeMe() = default;

        void sort();
};