/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:09:16 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/08 14:45:14 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "=== Constructors ===" << std::endl;
		const Animal* meta = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		std::cout << "\n=== Make sound ===" << std::endl;
		std::cout << "Type > " << dog->getType() << " " << std::endl;
		dog->makeSound();

		std::cout << "Type > " << cat->getType() << " " << std::endl;
		cat->makeSound();

		std::cout << "Type > " << meta->getType() << " " << std::endl;
		meta->makeSound(); //generic sound

		std::cout << "\n=== Destructors ===" << std::endl;
		delete dog;
		delete cat;
		delete meta;
	}
	{
		std::cout << "\n=== Wrong animal ===" << std::endl;
		const WrongAnimal* wrongCat = new WrongCat();
		std::cout << wrongCat->getType() << std::endl;
		wrongCat->makeSound();
		delete wrongCat;
	}
	return 0;
}