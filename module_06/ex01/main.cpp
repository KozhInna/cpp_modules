/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:09:16 by ikozhina          #+#    #+#             */
/*   Updated: 2026/04/13 12:14:35 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    Data item;
    item.index = 1;
    item.name = "box";
    
    std::cout << "Original pointer: " << &item << std::endl;

    uintptr_t raw = Serializer::serialize(&item);
    std::cout << "Serialized value: " << raw << std::endl;

    Data* result = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << result << std::endl;
    std::cout << "result->index: " << result->index << std::endl;
    std::cout << "result->name: " << result->name << std::endl;

    
    if (&item == result) {
        std::cout << "Pointers are equal" << std::endl;
    } else {
        std::cout << "Pointers are different" << std::endl;
    }
    
	return 0;
}