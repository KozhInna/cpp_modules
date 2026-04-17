#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <numeric>
#include <stdexcept>

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try {
        Span sp2 = Span(10000);
        std::vector<int> v{1, 2, 3, 4, 5};
        sp2.addRange(v.begin(), v.end());

        std::deque<int> q{10, 20, 30, 40, 50};
        sp2.addRange(q.begin(), q.end());

        std::list<int> l{100, 200, 300, 400, 500};
        sp2.addRange(l.begin(), l.end());

        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Span sp3 = Span(3);
        std::vector<int> v{1, 2, 3, 4, 5};
        sp3.addRange(v.begin(), v.end());
    } catch (const std::exception& e) {
        std::cout << "Caught expected: " << e.what() << std::endl;
    }
    try {
        Span sp4 = Span(3);
        sp4.addNumber(6);
        sp4.addNumber(3);
        sp4.addNumber(17);
        sp4.addNumber(9);
    } catch (const std::exception& e) {
        std::cout << "Caught expected: " << e.what() << std::endl;
    }

    try {
        Span sp4 = Span(5);
        std::cout << sp4.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught expected: " << e.what() << std::endl;
    }
    try {
        Span sp5 = Span(3);
        sp5.addNumber(6);
        std::cout << sp5.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught expected: " << e.what() << std::endl;
    }

    {
        const unsigned int N = 10000;
        Span bigSpan(N);
        std::vector<int> bigVec(N);
        std::iota(bigVec.begin(), bigVec.end(), 0); 
        bigSpan.addRange(bigVec.begin(), bigVec.end());
        std::cout << "10k shortest: " << bigSpan.shortestSpan() << std::endl; 
        std::cout << "10k longest:  " << bigSpan.longestSpan() << std::endl;  
    }

    std::cout << std::endl;
    return 0;
}