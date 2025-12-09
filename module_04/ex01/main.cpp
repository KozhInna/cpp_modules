/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:09:16 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/09 22:31:50 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;//should not create a leak
        delete i;

    }
    {
        std::cout << "\n=== Creating array of 4 animals ===" << std::endl;
        Animal* batch[4];
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
        std::cout << "\n=== Copy constructor test ===" << std::endl;
        Cat cat1;
        Cat cat2(cat1);
        Brain* cat1_brain = cat1.getBrain();
        Brain* cat2_brain = cat2.getBrain();
        
        std::cout << "\ncat1 brain: " << cat1_brain << std::endl;
        std::cout << "cat2 brain: " << cat2_brain << std::endl;

        std::cout << ((cat1.getBrain() != cat2.getBrain()) ?
             "✅ Different pointers - deep copy\n" : 
             "❌ The same pointer - shallow copy\n") << std::endl;
    }
    {
        std::cout << "\n=== Assignment operator ===" << std::endl;
        Cat cat1, cat2;
        
        Brain* cat1_brain_before = cat1.getBrain();
        Brain* cat2_brain_before = cat2.getBrain();
        
        std::cout << "\ncat1 brain before: " << cat1_brain_before << std::endl;
        std::cout << "cat2 brain before: " << cat2_brain_before << "\n" << std::endl;
        
        cat2 = cat1;
        
        Brain* cat1_brain_after = cat1.getBrain();
        Brain* cat2_brain_after = cat2.getBrain();
        
        std::cout << "\ncat1 brain after: " << cat1_brain_after << std::endl;
        std::cout << "cat2 brain after: " << cat2_brain_after << std::endl;
        
        // Check the correct conditions:
        if (cat2_brain_before != cat2_brain_after) 
        {
            std::cout << "✅ Different pointers - deep copy\n" << std::endl;
        } else {
            std::cout << "❌ The same pointer - shallow copy\n" << std::endl;
        }
    }
	return 0;
}