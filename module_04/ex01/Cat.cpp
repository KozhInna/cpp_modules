/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:31:34 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/10 12:17:31 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor" << std::endl;
	brain_ = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other), brain_(nullptr)
{
	std::cout << "Cat copy constructor" << std::endl;
	brain_ = new Brain(*other.brain_);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain_;
		brain_ = new Brain(*other.brain_);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
	delete brain_;
}

void Cat::makeSound() const
{
	std::cout << type_ << " is meowing" << std::endl;
}

Brain* Cat::getBrain() const
{
	return brain_;
}