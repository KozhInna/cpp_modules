#pragma once

#include <vector>
#include <iterator>
#include <stdexcept>
#include <cstddef>

class Span {
    private:
    unsigned int maxSize_;
    std::vector<int> data_;

    public:
        Span() = delete;
        Span(unsigned int n);
        Span(const Span& src);
        Span& operator=(const Span& src);
        ~Span();

        void addNumber(const int i);

        size_t shortestSpan() const;
        size_t longestSpan() const;

        template <typename AnyIterator>
        void addRange(AnyIterator begin, AnyIterator end) {
            if (data_.size() + (size_t)std::distance(begin, end) > maxSize_)
                throw std::overflow_error("There is no space left to store values");
            data_.insert(data_.end(), begin, end);
        }
};
