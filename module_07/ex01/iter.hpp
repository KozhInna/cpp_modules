#pragma once

#include <iostream>

template <typename T, typename F>
void iter(T* arr, const std::size_t len, F func) {
	for (std::size_t i = 0; i < len; i++)
		func(arr[i]);
}

template <typename T, typename F>
void iter(const T* arr, const std::size_t len, F func) {
	for (std::size_t i = 0; i < len; i++)
		func(arr[i]);
}

template <typename T>
void print(const T& c) {
	std::cout << c << std::endl;
}
