#include"PmergeMe.hpp"
#include <iostream>
#include <vector>

int main(int argc, char** argv){
    try {
        PmergeMe pm(argc, argv);
        pm.sortVector();
        //pm.sortDeque();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}




/* void sortPairs(std::vector<int>& arr, int pairSize) {
    (void) pairSize;
    for (auto& it : arr) {
        it *= 2;
        std::cout << it << " ";
    }
    std::cout <<  std::endl;
}

void buildMainAndPend(std::vector<int>& arr, int pairSize) {
    (void) pairSize;
    for (auto it : arr) {
        std::cout << it << " ";
    }
    std::cout <<  std::endl;
}

void fordJohnson(std::vector<int>& arr, int pairSize) {
    if (pairSize >= static_cast<int>(arr.size()/2)) 
        return ;
    
    // DOWN: merge phase
    sortPairs(arr, pairSize);
    
    fordJohnson(arr, pairSize * 2);  // recurse
    
    // UP: insertion phase
    buildMainAndPend(arr, pairSize);
    //insertUsingJacobsthal(main, pend);
}



int main() {
    std::vector<int> arr{7, 6, 5, 4, 3, 2, 1};
    fordJohnson(arr, 1);
    std::cout << std::endl;
} */