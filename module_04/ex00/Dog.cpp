/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:07:34 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/08 11:25:34 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

	Dog::Dog() : Animal("Dog")
	{
		std::cout << "Dog default constructor" << std::endl;
	}

	Dog::Dog(const Dog& other) : Animal(other)
	{
		std::cout << "Dog copy constructor" << std::endl;
	}

	Dog& Dog::operator=(const Dog& other)
	{
		std::cout << "Dog assignment operator" << std::endl;
		if (this != &other)
			Animal::operator=(other);
		return *this;
	}
	Dog::~Dog()
	{
		std::cout << "Dog destructor" << std::endl;
	}

	void Dog::makeSound() const
	{
		std::cout << type_ << " is barking" << std::endl;
	}