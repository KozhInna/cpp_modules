/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:31:34 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/05 14:11:59 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat calls default constructor" << std::endl;
}

Cat::Cat(const std::string &type) : Animal(type)
{
	std::cout << "Cat calls param constructor" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat calls copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat calls copy assignment operator" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat calls destructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat is meowing" << std::endl;
}