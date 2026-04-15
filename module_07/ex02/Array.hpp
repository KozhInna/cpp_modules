#pragma once

#include <iostream>

template <typename T>
class Array {
    private:
        T* data_;
        unsigned int size_;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& src);
        Array& operator=(const Array& src);
        ~Array();

        const T& operator[](unsigned int index) const;
        T& operator[](unsigned int index);
        unsigned int size() const;
};

#include "Array.tpp"