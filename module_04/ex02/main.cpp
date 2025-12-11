/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:09:16 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/11 13:06:45 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
    //Cannot instantiate abstract class
    // Animal one;
    {
        std::cout << "=== Concrete classes ===" << std::endl;
        Cat cat;
        Dog dog;
        std::cout << std::endl;
        dog.makeSound();
        cat.makeSound();
        std::cout << std::endl;
    }
	{
		const int size = 4;
		std::cout << "\n=== Abstract class pointers ===" << std::endl;
		Animal* batch[size] = {nullptr};
		for (int i = 0; i < 2; i++)
		{
			batch[i] = new Cat();
		}
		for (int i = 2; i < 4; i++)
		{
			batch[i] = new Dog();
		}

		std::cout << "\n=== Making sound ===" << std::endl;
		for (int i = 0; i < 4; i++)
		{
			batch[i]->makeSound();
		}

		std::cout << "\n=== Deleting animals ===" << std::endl;
		for (int i = 0; i < 4; i++)
			delete batch[i];
	}
	return 0;
}