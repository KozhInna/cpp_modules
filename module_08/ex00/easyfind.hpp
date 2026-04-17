#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& a, int b) {
    auto it = std::find(a.begin(), a.end(), b);
    if (it == a.end()) {
        throw std::runtime_error("Integer wasn't found");
    }
    return it;
}