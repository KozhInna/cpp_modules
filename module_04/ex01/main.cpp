/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:09:16 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/11 11:10:29 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
	{
		const int size = 4;
		std::cout << "=== Creating array of 4 animals ===" << std::endl;
		Animal* batch[size];
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
	{
		std::cout << "\n=== Cat copy constructor test ===" << std::endl;
		Cat cat1;
		cat1.getBrain().setIdea(0, "Original idea");
		Cat cat2(cat1);

		std::cout << "\ncat1 brain: " << &(cat1.getBrain()) << " - " << cat1.getBrain().getIdea(0) << std::endl;
		std::cout << "cat2 brain: " << &(cat2.getBrain()) << " - " << cat2.getBrain().getIdea(0) << std::endl;

		cat1.getBrain().setIdea(0, "Modified idea");
		std::cout << "\ncat1 brain: " << &(cat1.getBrain()) << " - " << cat1.getBrain().getIdea(0) << std::endl;
		std::cout << "cat2 brain: " << &(cat2.getBrain()) << " - " << cat2.getBrain().getIdea(0) << std::endl;

		std::cout << ((&(cat1.getBrain()) != &(cat2.getBrain())) ?
			 "✅ Objects are independent - deep copy\n" :
			 "❌ Changes affect both - shallow copy\n") << std::endl;
	}
	{
		std::cout << "\n=== Cat assignment operator test===" << std::endl;
		Cat cat1, cat2;

		cat1.getBrain().setIdea(0, "CAT1 original idea");
		cat2.getBrain().setIdea(0, "cat2 original idea");

		std::cout << "\ncat1 brain before: " << &(cat1.getBrain()) << " - " << cat1.getBrain().getIdea(0) << std::endl;
		std::cout << "cat2 brain before: " << &(cat2.getBrain()) << " - " << cat2.getBrain().getIdea(0) << "\n" << std::endl;

		cat2 = cat1;

		std::cout << "\ncat1 after assignment: " << &(cat1.getBrain()) << " - " << cat1.getBrain().getIdea(0) << std::endl;
		std::cout << "cat2 after assignment: " << &(cat2.getBrain()) << " - " << cat2.getBrain().getIdea(0) << std::endl;

		cat1.getBrain().setIdea(0, "CAT1 MODIFIED idea");
		std::cout << "\ncat1 idea modified: " << &(cat1.getBrain()) << " - " << cat1.getBrain().getIdea(0) << std::endl;
		std::cout << "cat2 idea unchanged: " << &(cat2.getBrain()) << " - " << cat2.getBrain().getIdea(0) << std::endl;

		if (cat1.getBrain().getIdea(0) != cat2.getBrain().getIdea(0))
		{
			std::cout << "✅ Objects are independent - deep copy\n" << std::endl;
		} else {
			std::cout << "❌ Changes affect both - shallow copy\n" << std::endl;
		}
	}
	{
		std::cout << "\n=== Dog copy constructor test ===" << std::endl;
		Dog dog1;
		dog1.getBrain().setIdea(0, "Dog1 first idea");
		Dog dog2(dog1);

		dog1.getBrain().setIdea(0, "Dog1 second idea");
		if (dog1.getBrain().getIdea(0) != dog2.getBrain().getIdea(0))
			std::cout << "\n✅ Objects are independent - deep copy\n" << std::endl;

	}
	return 0;
}