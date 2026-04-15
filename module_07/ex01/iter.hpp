#pragma once

#include <cstddef>

template <typename T, typename F>
void iter(T* arr, const size_t size, F func) {
    if (!arr) return;
	for (std::size_t i = 0; i < size; i++)
		func(arr[i]);
}