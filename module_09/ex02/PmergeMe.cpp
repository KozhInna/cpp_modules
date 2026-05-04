#include"PmergeMe.hpp"
#include<vector>
#include<deque>
#include<chrono>
#include<algorithm>

//vector sorting implementation
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

		//is JacobNum exist in pend
		// pend starts at b2, so b_currJ exists if currJ <= pend.size() + 1
		if (!(currJ <= static_cast<int>(pendChain.size()) + 1) && static_cast<int>(pendChain.size()) >= prevJ) {
			for (int i = pendChain.size(); i >= prevJ; i--) {
				int aBoundIndx = (i <= static_cast<int>(bounds.size())) ?
					bounds[i - 1] : static_cast<int>(mainChain.size()) - 1;
				int bIndx = i - 1;
				insertBinary(mainChain, pendChain, bIndx, aBoundIndx, bounds);
			}
			return ;
		}

		//is JacobNum exist in main
		if (!(currJ <= static_cast<int>(bounds.size()) + 1)) {
			// a_x doesn't exist, search whole main
			for (int i = currJ; i > prevJ; i--) {
				int aBoundIndx = (i <= static_cast<int>(bounds.size())) ?
					bounds[i - 1] : static_cast<int>(mainChain.size()) - 1;
				int bIndx = i - 2;
				insertBinary(mainChain, pendChain, bIndx, aBoundIndx, bounds);
			}
		} else {
			// a_x exists, use bounds[currJ - i - 2]
			for (int i = 0; i < currJ - prevJ; i++) {
				int aBoundIndx = bounds[currJ - i - 2];
				int bIndx = currJ - i - 2;
				insertBinary(mainChain, pendChain, bIndx, aBoundIndx, bounds);
			}
		}
		n++;
		prevJ = currJ;
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
	if (pendChain.empty()) return;
	insertUsingJacobsthal(mainChain, pendChain, bounds);

	vec.clear();
	for (auto& group : mainChain)
		vec.insert(vec.end(), group.begin(), group.end());

	vec.insert(vec.end(), leftover.begin(), leftover.end());
}

void PmergeMe::sort() {
	printBefore();

	auto start = std::chrono::high_resolution_clock::now();
	vec_ = std::vector<int>(parsed_.begin(), parsed_.end());
	fordJohnson(vec_, 1);

	auto end = std::chrono::high_resolution_clock::now();
	vecTime_ = std::chrono::duration<double, std::micro>(end - start).count();

	start = std::chrono::high_resolution_clock::now();
	deq_ = std::deque<int>(parsed_.begin(), parsed_.end());
	fordJohnson(deq_, 1);
	end = std::chrono::high_resolution_clock::now();
	deqTime_ = std::chrono::duration<double, std::micro>(end - start).count();

	printAfter();
	printTime(vecTime_, deqTime_);
}

//deque sorting implementation
void PmergeMe::fordJohnson(std::deque<int>& deq, int pairSize) {
	if (pairSize > static_cast<int>(deq.size()/2))
		return ;

	sortPairs(deq, pairSize);

	fordJohnson(deq, pairSize * 2);

	std::deque<std::deque<int>> mainChain;
	std::deque<std::deque<int>> pendChain;
	std::deque<int> bounds;

	int size = static_cast<int>(deq.size());
	int remainder = size % pairSize;
	std::deque<int> leftover(deq.end() - remainder, deq.end());

	buildMainAndPend(deq, pairSize, mainChain, pendChain, bounds);
	if (pendChain.empty()) return;
	insertUsingJacobsthal(mainChain, pendChain, bounds);

	deq.clear();
	for (auto& group : mainChain)
		deq.insert(deq.end(), group.begin(), group.end());

	deq.insert(deq.end(), leftover.begin(), leftover.end());
}

void PmergeMe::sortPairs(std::deque<int>& deq, int pairSize) {
	int size = static_cast<int>(deq.size());
	for (int i = 0; i + 2 * pairSize <= size; i += (pairSize * 2)) {
		if (deq[i + pairSize - 1] > deq[i + (2 * pairSize) - 1]) {
			std::swap_ranges(deq.begin() + i,
							deq.begin() + i + pairSize,
							deq.begin() + i + pairSize);
		}
	}
}

void PmergeMe::buildMainAndPend(std::deque<int>& deq, int pairSize, std::deque<std::deque<int>>& mainChain,
	std::deque<std::deque<int>>& pendChain, std::deque<int>& bounds) {

	int size = static_cast<int>(deq.size());
	int groupIndex = 0;

	for (int i = 0; i + pairSize <= size; i += pairSize) {
		std::deque<int> pair(deq.begin() + i, deq.begin() + i + pairSize);
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

void PmergeMe::insertUsingJacobsthal(std::deque<std::deque<int>>& mainChain,
	std::deque<std::deque<int>>& pendChain, std::deque<int>& bounds) {

	int n = 2;
	int prevJ = 1;

	while(prevJ <= static_cast<int>(pendChain.size())) {

		int currJ = getJacobNum(n);

		//is JacobNum exist in pend
		// pend starts at b2, so b_currJ exists if currJ <= pend.size() + 1
		if (!(currJ <= static_cast<int>(pendChain.size()) + 1) && static_cast<int>(pendChain.size()) >= prevJ) {
			for (int i = pendChain.size(); i >= prevJ; i--) {
				int aBoundIndx = (i <= static_cast<int>(bounds.size())) ?
					bounds[i - 1] : static_cast<int>(mainChain.size()) - 1;
				int bIndx = i - 1;
				insertBinary(mainChain, pendChain, bIndx, aBoundIndx, bounds);
			}
			return ;
		}

		//is JacobNum exist in main
		if (!(currJ <= static_cast<int>(bounds.size()) + 1)) {
			// a_x doesn't exist, search whole main
			for (int i = currJ; i > prevJ; i--) {
				int aBoundIndx = (i <= static_cast<int>(bounds.size())) ?
					bounds[i - 1] : static_cast<int>(mainChain.size()) - 1;
				int bIndx = i - 2;
				insertBinary(mainChain, pendChain, bIndx, aBoundIndx, bounds);
			}
		} else {
			// a_x exists, use bounds[currJ - i - 2]
			for (int i = 0; i < currJ - prevJ; i++) {
				int aBoundIndx = bounds[currJ - i - 2];
				int bIndx = currJ - i - 2;
				insertBinary(mainChain, pendChain, bIndx, aBoundIndx, bounds);
			}
		}
		n++;
		prevJ = currJ;
	}
}

void PmergeMe::insertBinary(std::deque<std::deque<int>>& mainChain,
					std::deque<std::deque<int>>& pendChain,
					int bIndx, int aBoundIndx, std::deque<int>& bounds) {

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

void PmergeMe::resetBounds(std::deque<int>& bounds, int insertIndx) {
	for (int i = 0; i < static_cast<int>(bounds.size()); i++) {
		if (bounds[i] >= insertIndx) {
			bounds[i]++;
		}
	}
}