/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:09:16 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/08 19:40:18 by ikozhina         ###   ########.fr       */
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
        std::cout << "*** With virtual ***" << std::endl;
		std::cout << "=== Constructors ===" << std::endl;
		const Animal* meta = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		std::cout << "\n=== Make sound ===" << std::endl;
		std::cout << "Type > " << dog->getType() << " | ";
		dog->makeSound();

		std::cout << "Type > " << cat->getType() << " | ";
		cat->makeSound();

		std::cout << "Type > " << meta->getType() << " | ";
		meta->makeSound();

		std::cout << "\n=== Destructors ===" << std::endl;
		delete dog;
		delete cat;
		delete meta;
	}
	{
        std::cout << "\n*** Without virtual ***" << std::endl;
		std::cout << "=== Pointer to base class ===" << std::endl;
		const WrongAnimal* wrongCat1 = new WrongCat();
        const WrongAnimal* wrongCat2 = new WrongAnimal();
        
        std::cout << "\nType > " << wrongCat1->getType() << " | ";
		wrongCat1->makeSound();
        std::cout << "Type > " << wrongCat2->getType() << " | ";
		wrongCat2->makeSound();
        
        std::cout << std::endl;
		delete wrongCat1;
        delete wrongCat2;
	}
    {
        std::cout << "\n=== Direct object call ===" << std::endl;
        WrongCat directWrongCat;
        std::cout << "\nType > " << directWrongCat.getType() << " | ";
		directWrongCat.makeSound();
        std::cout << std::endl;
    }
	return 0;
}