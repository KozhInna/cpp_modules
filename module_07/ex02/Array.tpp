#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array() : data_(nullptr), size_(0) {
    std::cout << "Default constructor called" << std::endl;
}
template <typename T>
Array<T>::Array(unsigned int n) : data_(nullptr), size_(n) {
    std::cout << "Parametarised constructor called" << std::endl;
    if (n > 0) {
        data_ = new T[n]();
    }
}

template <typename T>
Array<T>::Array(const Array &src) :  data_(nullptr), size_(src.size_) {
    std::cout << "Copy constructor called" << std::endl;
    if (size_ > 0) {
        data_ = new T[size_];
        for (unsigned int i = 0; i < size_; i++) {
            data_[i] = src.data_[i];
        }
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& src) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src) {
        delete[] data_;
        size_ = src.size_;
        data_ = nullptr;
        if (size_ > 0) {
            data_ = new T[src.size_];
            for (unsigned int i = 0; i < size_; i++) {
                data_[i] = src.data_[i];
            }
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    std::cout << "Destructor called" << std::endl;
    delete[] data_;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= size_)
        throw std::out_of_range("Array index out of bounds");
    return data_[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= size_)
        throw std::out_of_range("Array index out of bounds");
    return data_[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return size_;
}