#include "Span.hpp"
#include <vector>
#include <algorithm>
#include <stdexcept>

Span::Span(unsigned int N) : maxSize_(N) {
    data_.reserve(N);
}

Span::Span(const Span& src) : maxSize_(src.maxSize_), data_(src.data_) {}

Span& Span::operator=(const Span& src) {
    if (this != &src) {
        maxSize_ = src.maxSize_;
        data_ = src.data_;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(const int value) {
    if (data_.size() >= maxSize_)
        throw std::overflow_error("Span is full");
    data_.push_back(value);
}

size_t Span::shortestSpan() const {
    if (data_.size() < 2)
        throw std::runtime_error("No span can be found");

    std::vector<int> temp = data_;
    std::sort(temp.begin(), temp.end());

    size_t shortest = temp[1] - temp[0];
    for (size_t i = 1; i < temp.size() - 1; i++) {
        size_t dif = temp[i + 1] - temp[i];
        if (dif < shortest)
            shortest = dif;
    }
    return shortest;
}

size_t Span::longestSpan() const {
    if (data_.size() < 2)
        throw std::runtime_error("No span can be found");
    return *std::max_element(data_.begin(), data_.end()) - 
            *std::min_element(data_.begin(), data_.end());
}
