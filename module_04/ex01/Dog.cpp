/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:07:34 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/11 13:10:13 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

	Dog::Dog() : Animal("Dog"), brain_(new Brain())
	{
		std::cout << "Dog default constructor" << std::endl;
	}

	Dog::Dog(const Dog& other) : Animal(other), brain_(new Brain(*other.brain_))
	{
		std::cout << "Dog copy constructor" << std::endl;
	}

	Dog& Dog::operator=(const Dog& other)
	{
		std::cout << "Dog assignment operator" << std::endl;
		if (this != &other)
		{
			Animal::operator=(other);
			delete brain_;
			brain_ = new Brain(*other.brain_);
		}
		return *this;
	}
	Dog::~Dog()
	{
		std::cout << "Dog destructor" << std::endl;
		delete brain_;
	}

	void Dog::makeSound() const
	{
		std::cout << type_ << " is barking" << std::endl;
	}

	Brain& Dog::getBrain() const
	{
		return *brain_;
	}