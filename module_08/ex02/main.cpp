#include "MutantStack.hpp"

#include <iostream>
#include <list>

int main()
{
    std::cout << "=== Mutant test ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "=== List test ===" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << std::endl;

    std::cout << "=== const_iterator: forward traversal ===" << std::endl;
    std::cout << "Expected: 5 3 5 737 0" << std::endl;
    const MutantStack<int> cmstack = mstack;
    for (MutantStack<int>::const_iterator it = cmstack.begin(); it != cmstack.end(); ++it)
        std::cout << *it << std::endl;
    
    std::cout << "=== reverse_iterator: reverse traversal ===" << std::endl;
    std::cout << "Expected: 0 737 5 3 5" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << std::endl;
    
    std::cout << "=== const_reverse_iterator: reverse traversal ===" << std::endl;
    std::cout << "Expected: 0 737 5 3 5" << std::endl;
    for (MutantStack<int>::const_reverse_iterator rit = cmstack.rbegin(); rit != cmstack.rend(); ++rit)
        std::cout << *rit << std::endl;

    return 0;
}